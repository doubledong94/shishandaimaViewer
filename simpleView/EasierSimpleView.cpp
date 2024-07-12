#include "../util/util.h"
#include "SWI-cpp2.h"
#include "../antlr/syntaxObject/JavaHeaderFile.h"
#include "../addressableInfo/AddressableInfo.h"
#include "../prolog/PrologConstructor.h"
#include "../prolog/PrologWrapper.h"
#include "SimpleViewLexer.h"
#include "SimpleViewBaseVisitor.h"
#include "../error/ErrorManager.h"
#include "EasierSimpleView.h"
#include "visitor/SimpleViewToGraphConverter.h"
#include "../file/FileManager.h"
#include <regex>
#include "re2/prog.h"
#include "re2/re2.h"
#include "re2/regexp.h"
#include "../res/Images.h"
#include "../addressableInfo/GlobalInfo.h"

// #define DEBUG_PROLOG

list<string> EasierSimpleView::typeKeyInOrder;
map<string, string> EasierSimpleView::typeToPackage;
map<string, list<string>> EasierSimpleView::classToField;
map<string, list<string>> EasierSimpleView::classToMethod;
map<string, list<string>> EasierSimpleView::classToParameter;
map<string, list<string>> EasierSimpleView::classToReturn;

map<int, string> EasierSimpleView::vocabularySymbolToLiteral;

void EasierSimpleView::saveVocabulary(SimpleViewLexer& lexer, int symbol) {
    string_view sv = lexer.getVocabulary().getLiteralName(symbol);
    string s = { sv.begin() + 1, sv.end() - 1 };
    vocabularySymbolToLiteral[symbol] = s;
}

void EasierSimpleView::saveVocabulary(SimpleViewLexer& lexer) {
    // basic style
    saveVocabulary(lexer, SimpleViewLexer::BASIC_STYLE);
    saveVocabulary(lexer, SimpleViewLexer::BASIC_NODE_SIZE);
    saveVocabulary(lexer, SimpleViewLexer::BASIC_LABEL_SIZE);
    saveVocabulary(lexer, SimpleViewLexer::BASIC_POSITION_Z);

    // default style
    saveVocabulary(lexer, SimpleViewLexer::DEFAULT_STYLE);

    // style
    saveVocabulary(lexer, SimpleViewLexer::STYLE);
    saveVocabulary(lexer, SimpleViewLexer::NODE_COLOR);
    saveVocabulary(lexer, SimpleViewLexer::NODE_SCALE);
    saveVocabulary(lexer, SimpleViewLexer::LABEL_COLOR);
    saveVocabulary(lexer, SimpleViewLexer::LABEL_SCALE);
    saveVocabulary(lexer, SimpleViewLexer::LABEL_DETAIL_LEVEL);
    saveVocabulary(lexer, SimpleViewLexer::LABEL_DETAIL_LEVEL_SIMPLE);
    saveVocabulary(lexer, SimpleViewLexer::LABEL_DETAIL_LEVEL_FULL);
    saveVocabulary(lexer, SimpleViewLexer::POSITION_Z);
    // class scope
    saveVocabulary(lexer, SimpleViewLexer::CLASS_SCOPE);
    saveVocabulary(lexer, SimpleViewLexer::IN_PACKAGE);
    saveVocabulary(lexer, SimpleViewLexer::USED_BY);
    saveVocabulary(lexer, SimpleViewLexer::USE);
    saveVocabulary(lexer, SimpleViewLexer::SUPER);
    saveVocabulary(lexer, SimpleViewLexer::SUB);
    saveVocabulary(lexer, SimpleViewLexer::CLASS_OF);
    // node
    saveVocabulary(lexer, SimpleViewLexer::NODE);
    saveVocabulary(lexer, SimpleViewLexer::ANY);
    saveVocabulary(lexer, SimpleViewLexer::FIELD_OF);
    saveVocabulary(lexer, SimpleViewLexer::INSTANCE_OF);
    saveVocabulary(lexer, SimpleViewLexer::CREATOR);
    saveVocabulary(lexer, SimpleViewLexer::METHOD_OF);
    saveVocabulary(lexer, SimpleViewLexer::PARAMETER_OF);
    saveVocabulary(lexer, SimpleViewLexer::RETURN_OF);
    saveVocabulary(lexer, SimpleViewLexer::CALLED_METHOD_OF);
    saveVocabulary(lexer, SimpleViewLexer::CALLED_PARAM_OF);
    saveVocabulary(lexer, SimpleViewLexer::CALLED_RETURN_OF);
    saveVocabulary(lexer, SimpleViewLexer::READ);
    saveVocabulary(lexer, SimpleViewLexer::WRITE);
    saveVocabulary(lexer, SimpleViewLexer::REFERENCE);
    saveVocabulary(lexer, SimpleViewLexer::CONDITION);
    saveVocabulary(lexer, SimpleViewLexer::ELSE);
    saveVocabulary(lexer, SimpleViewLexer::DATA_STEP);
    saveVocabulary(lexer, SimpleViewLexer::TIMING_STEP);
    saveVocabulary(lexer, SimpleViewLexer::FIELD);
    saveVocabulary(lexer, SimpleViewLexer::METHOD);
    saveVocabulary(lexer, SimpleViewLexer::CONSTRUCTOR);
    saveVocabulary(lexer, SimpleViewLexer::CALLED_METHOD);
    saveVocabulary(lexer, SimpleViewLexer::PARAMETER);
    saveVocabulary(lexer, SimpleViewLexer::CALLED_PARAMETER);
    saveVocabulary(lexer, SimpleViewLexer::RETURN);
    saveVocabulary(lexer, SimpleViewLexer::CALLED_RETURN);
    saveVocabulary(lexer, SimpleViewLexer::INDEX);
    saveVocabulary(lexer, SimpleViewLexer::DATA_OVERRIDE);
    saveVocabulary(lexer, SimpleViewLexer::TIMING_OVERRIDE);
    // line
    saveVocabulary(lexer, SimpleViewLexer::LINE);
    saveVocabulary(lexer, SimpleViewLexer::CODE_ORDER);
    saveVocabulary(lexer, SimpleViewLexer::SEGMENT);
    // glue
    saveVocabulary(lexer, SimpleViewLexer::GLUE);
    saveVocabulary(lexer, SimpleViewLexer::GLUE_RUNTIME);
    saveVocabulary(lexer, SimpleViewLexer::GLULE_MEMBER_OF);
    saveVocabulary(lexer, SimpleViewLexer::GLUE_INSTANCE_OF);
    saveVocabulary(lexer, SimpleViewLexer::GLUE_OVERRIDE);
    saveVocabulary(lexer, SimpleViewLexer::GLUE_HIERARCHY);
    // graph
    saveVocabulary(lexer, SimpleViewLexer::GRAPH);
    saveVocabulary(lexer, SimpleViewLexer::LINE_INSTANCE);
    saveVocabulary(lexer, SimpleViewLexer::GRAPH_INSTANCE);
    // command
    saveVocabulary(lexer, SimpleViewLexer::SHOW);

}

map<int, int> SimpleView::ClassScope::classTypeToIconId;
map<int, int> SimpleView::Node::nodeTypeToIconId;

void EasierSimpleView::init() {
    SimpleView::ClassScope::classTypeToIconId = {
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_KEY,Images::keyIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_LIST,Images::listIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_IN_PACKAGE,Images::inPackageIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_USED_BY,Images::useIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_USE,Images::useIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_SUPER,Images::superAndSubIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_SUB,Images::superAndSubIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_INTERSECTION,Images::intersectionIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_UNION,Images::unionIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_DIFFERENCE,Images::differenceIconId},
            {SimpleView::ClassScope::CLASS_SCOPE_TYPE_VAR,Images::varIconId},
    };
    SimpleView::Node::nodeTypeToIconId = {
                {SimpleView::Node::NODE_TYPE_KEY,Images::keyIconId},
                {SimpleView::Node::NODE_TYPE_LIST,Images::listIconId},
                {SimpleView::Node::NODE_TYPE_FIELD_OF,Images::fieldIconId},
                {SimpleView::Node::NODE_TYPE_METHOD_OF,Images::methodIconId},
                {SimpleView::Node::NODE_TYPE_CREATOR,Images::creatorIconId},
                {SimpleView::Node::NODE_TYPE_PARAMETER_OF,Images::parameterIconId},
                {SimpleView::Node::NODE_TYPE_RETURN_OF,Images::returnIconId},
                {SimpleView::Node::NODE_TYPE_INSTANCE_OF,Images::instanceOfIconId},
                {SimpleView::Node::NODE_TYPE_SUPER,Images::superAndSubIconId},
                {SimpleView::Node::NODE_TYPE_SUB,Images::superAndSubIconId},
                {SimpleView::Node::NODE_TYPE_CALLED_METHOD_OF,Images::methodIconId},
                {SimpleView::Node::NODE_TYPE_CALLED_PARAMETER_OF,Images::parameterIconId},
                {SimpleView::Node::NODE_TYPE_CALLED_RETURN_OF,Images::returnIconId},
                {SimpleView::Node::NODE_TYPE_INTERSECTION,Images::anyIconId},
                {SimpleView::Node::NODE_TYPE_UNION,Images::unionIconId},
                {SimpleView::Node::NODE_TYPE_DIFFERENCE,Images::differenceIconId},
                {SimpleView::Node::NODE_TYPE_READ,Images::readIconId},
                {SimpleView::Node::NODE_TYPE_WRITE,Images::writeIconId},
                {SimpleView::Node::NODE_TYPE_ANY,Images::anyIconId},
                {SimpleView::Node::NODE_TYPE_REFERENCE,Images::referenceIconId},
                {SimpleView::Node::NODE_TYPE_CONDITION,Images::conditionIconId},
                {SimpleView::Node::NODE_TYPE_ELSE,Images::elseIconId},
                {SimpleView::Node::NODE_TYPE_DATA_STEP,Images::stepIconId},
                {SimpleView::Node::NODE_TYPE_TIMING_STEP,Images::stepIconId},
                {SimpleView::Node::NODE_TYPE_DATA_OVERRIDE,Images::overrideIcondId},
                {SimpleView::Node::NODE_TYPE_TIMING_OVERRIDE,Images::overrideIcondId},
                {SimpleView::Node::NODE_TYPE_FIELD,Images::fieldIconId},
                {SimpleView::Node::NODE_TYPE_METHOD,Images::methodIconId},
                {SimpleView::Node::NODE_TYPE_CONSTRUCTOR,Images::creatorIconId},
                {SimpleView::Node::NODE_TYPE_CALLED_METHOD,Images::methodIconId},
                {SimpleView::Node::NODE_TYPE_PARAMETER,Images::parameterIconId},
                {SimpleView::Node::NODE_TYPE_CALLED_PARAMETER,Images::parameterIconId},
                {SimpleView::Node::NODE_TYPE_RETURN,Images::returnIconId},
                {SimpleView::Node::NODE_TYPE_CALLED_RETURN,Images::returnIconId},
                {SimpleView::Node::NODE_TYPE_INDEX,Images::indexIcon},
                {SimpleView::Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH,Images::parameterIconId},
                {SimpleView::Node::NODE_TYPE_VAR,Images::varIconId},
    };
    PrologWrapper::queryList(CompoundTerm::getPackageTerm(Term::getVar("A"), Term::getVar("B")), [&](vector<Term*>& retList) {
        typeKeyInOrder.push_back(retList[1]->atomOrVar);
        typeToPackage[retList[1]->atomOrVar] = retList[0]->atomOrVar;
        });
    typeKeyInOrder.sort();

    PrologWrapper::declareFun(HEAD_ADDRESSABLE_LOADED->atomOrVar, 1);
    PrologWrapper::declareFun(HEAD_UNADDRESSABLE_LOADED->atomOrVar, 1);
    PrologWrapper::declareFun(HEAD_RUNTIME_KEY->atomOrVar, 4);
    PrologWrapper::declareFun(HEAD_DATA_FLOW->atomOrVar, 3);
    PrologWrapper::declareFun(HEAD_STEP_KEY->atomOrVar, 2);
    PrologWrapper::declareFun(HEAD_OVERRIDE_KEY->atomOrVar, 2);
    PrologWrapper::declareFun(HEAD_RUNTIME_READ->atomOrVar, 3);
    PrologWrapper::declareFun(HEAD_RUNTIME_WRITE->atomOrVar, 3);
    PrologWrapper::declareFun(HEAD_CODE_ORDER->atomOrVar, 3);
    declareKeyConvertion();
    declareClassResolveRules();
    declareNodeResolveRules();
    declareLoadWhileSearching();
    declareStepRules();
    declareOverrideRules();

    spdlog::get(ErrorManager::TimerTag)->info("simple init started.");
    std::ifstream stream(FileManager::simpleViewConfig);
    antlr4::ANTLRInputStream inputStream(stream);
    SimpleViewLexer lexer(&inputStream);
    saveVocabulary(lexer);
    SimpleView::Node::NODE_ANY = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_ANY);
    SimpleView::Node::NODE_REFERENCE = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_REFERENCE);
    SimpleView::Node::NODE_CONDITION = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_CONDITION);
    SimpleView::Node::NODE_ELSE = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_ELSE);
    SimpleView::Node::NODE_DATA_STEP = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_DATA_STEP);
    SimpleView::Node::NODE_TIMING_STEP = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_TIMING_STEP);
    SimpleView::Node::NODE_DATA_OVERRIDE = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_DATA_OVERRIDE);
    SimpleView::Node::NODE_TIMING_OVERRIDE = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_TIMING_OVERRIDE);
    SimpleView::Node::NODE_FIELD = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_FIELD);
    SimpleView::Node::NODE_METHOD = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_METHOD);
    SimpleView::Node::NODE_CONSTRUCTOR = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_CONSTRUCTOR);
    SimpleView::Node::NODE_CALLED_METHOD = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_CALLED_METHOD);
    SimpleView::Node::NODE_PARAMETER = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_PARAMETER);
    SimpleView::Node::NODE_CALLED_PARAMETER = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_CALLED_PARAMETER);
    SimpleView::Node::NODE_RETURN = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_RETURN);
    SimpleView::Node::NODE_CALLED_RETURN = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_CALLED_RETURN);
    SimpleView::Node::NODE_INDEX = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_INDEX);

    antlr4::CommonTokenStream tokenStream(&lexer);
    SimpleViewParser parser(&tokenStream);
    SimpleView::SimpleViewErrorListener e;
    parser.removeErrorListeners();
    parser.addErrorListener(&e);
    SimpleView::SimpleViewToGraphConverter visitor;
    parser.compilationUnit()->accept(&visitor);
    spdlog::get(ErrorManager::TimerTag)->info("simple init finished.");
}

void EasierSimpleView::declareKeyConvertion() {
    vector<Rule*> rules;
    Term* key = Term::getVar("Key");
    Term* calledKey = Term::getVar("CalledKey");
    Term* stepKey = Term::getVar("StepKey");
    Term* overrideKey = Term::getVar("OverrideKey");
    Term* calledSuffix = Term::getStr("#");
    Term* stepSuffix = Term::getStr("-step");
    Term* overrideSuffix = Term::getStr("-override");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getCalledKeyTerm(key, calledKey), {
        CompoundTerm::getStringConcatTerm(key,calledSuffix,calledKey)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getStepKeyTerm(key, stepKey), {
        CompoundTerm::getStringConcatTerm(key,stepSuffix,stepKey)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getOverrideKeyTerm(key, overrideKey), {
        CompoundTerm::getStringConcatTerm(key,overrideSuffix,overrideKey)
        }));
    Term* fieldOrMethod = Term::getVar("FieldOrMethod");
    Term* classKey = Term::getVar("ClassKey");
    Term* methodThatUseIt = Term::getVar("MethodThatUseIt");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassThatUseMethodAndFieldTerm(fieldOrMethod, classKey), {
        CompoundTerm::getMethodUseMethodTerm(methodThatUseIt,fieldOrMethod), CompoundTerm::getMethodTerm(classKey,methodThatUseIt)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassThatUseMethodAndFieldTerm(fieldOrMethod, classKey), {
        CompoundTerm::getMethodUseFieldTerm(methodThatUseIt,fieldOrMethod), CompoundTerm::getMethodTerm(classKey,methodThatUseIt)
        }));
    for (auto& rule : rules) {
        PrologWrapper::addRule(rule->toString());
    }
    for (auto& rule : rules) {
        rule->returnThisToPool();
    }
}

void EasierSimpleView::declareClassResolveRules() {
    Term* ClassToBeResolved = Term::getVar("ClassToBeResolved");
    Term* ClassScopeName1 = Term::getVar("ClassScopeName1");
    Term* ClassScopeName2 = Term::getVar("ClassScopeName2");
    Term* ResolvedClass = Term::getVar("ResolvedClass");
    vector<Rule*> rules;
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassScopeUsedBy(ClassScopeName1, ClassToBeResolved), {
            CompoundTerm::getResolveTerm(ClassScopeName1, ResolvedClass), CompoundTerm::getRelatedTypeTerm(ResolvedClass, ClassToBeResolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassScopeUse(ClassScopeName1, ClassToBeResolved), {
            CompoundTerm::getResolveTerm(ClassScopeName1, ResolvedClass), CompoundTerm::getRelatedTypeTerm(ClassToBeResolved, ResolvedClass)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassScopeSuper(ClassScopeName1, ClassToBeResolved), {
            CompoundTerm::getResolveTerm(ClassScopeName1, ResolvedClass), CompoundTerm::getSubTypeUpRecurTerm(ClassToBeResolved, ResolvedClass)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassScopeSub(ClassScopeName1, ClassToBeResolved), {
            CompoundTerm::getResolveTerm(ClassScopeName1, ResolvedClass), CompoundTerm::getSubTypeDownRecurTerm(ResolvedClass, ClassToBeResolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassScopeUnionTerm(ClassScopeName1, ClassScopeName2, ClassToBeResolved), {
            DisjunctionTerm::getDisjunctionInstance(CompoundTerm::getResolveTerm(ClassScopeName1, ClassToBeResolved), CompoundTerm::getResolveTerm(ClassScopeName2, ClassToBeResolved))
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassScopeIntersectionTerm(ClassScopeName1, ClassScopeName2, ClassToBeResolved), {
            CompoundTerm::getResolveTerm(ClassScopeName1, ClassToBeResolved), CompoundTerm::getResolveTerm(ClassScopeName2, ClassToBeResolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getClassScopeDifferenceTerm(ClassScopeName1, ClassScopeName2, ClassToBeResolved), {
            CompoundTerm::getResolveTerm(ClassScopeName1, ClassToBeResolved), NegationTerm::getNegInstance(CompoundTerm::getResolveTerm(ClassScopeName2, ClassToBeResolved))
        }));

    Term* typeKey = Term::getVar("TypeKey");
    Term* typeKeyTemp = Term::getVar("TypeKeyTemp");
    Term* subTypeKey = Term::getVar("SubTypeKey");
    Term* superTypeKey = Term::getVar("SuperTypeKey");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getSubTypeDownRecurTerm(typeKey, subTypeKey), {
        CompoundTerm::getSubTypeTerm(typeKey,subTypeKey)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getSubTypeDownRecurTerm(typeKey, subTypeKey), {
        CompoundTerm::getSubTypeTerm(typeKey,typeKeyTemp),CompoundTerm::getSubTypeDownRecurTerm(typeKeyTemp,subTypeKey)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getSubTypeUpRecurTerm(superTypeKey, typeKey), {
        CompoundTerm::getSubTypeTerm(superTypeKey,typeKey)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getSubTypeUpRecurTerm(superTypeKey, typeKey), {
        CompoundTerm::getSubTypeTerm(typeKeyTemp,typeKey),CompoundTerm::getSubTypeUpRecurTerm(superTypeKey,typeKeyTemp)
        }));

    for (auto& rule : rules) {
        PrologWrapper::addRule(rule->toString());
    }
    for (auto& rule : rules) {
        rule->returnThisToPool();
    }
}

void EasierSimpleView::declareNodeResolveRules() {
    Term* Resolved = Term::getVar("Resolved");
    Term* ClassScopeValName = Term::getVar("ClassScopeValName");
    Term* Class = Term::getVar("Class");
    Term* ClassValName = Term::getVar("ClassValName");
    Term* ClassType = Term::getVar("ClassType");
    Term* MethodValName = Term::getVar("MethodValName");
    Term* Method = Term::getVar("Method");
    Term* ParamValName = Term::getVar("ParamValName");
    Term* Param = Term::getVar("Param");
    Term* ReturnValName = Term::getVar("ReturnValName");
    Term* Return = Term::getVar("Return");
    Term* Node1 = Term::getVar("Node1");
    Term* Node2 = Term::getVar("Node2");
    Term* RuntimeKey = Term::getVar("RuntimeKey");
    Term* nodeValName = Term::getVar("NodeValName");
    Term* node = Term::getVar("Node");
    Term* keyType = Term::getVar("KeyType");
    vector<Rule*> rules;

    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeFieldOfTerm(ClassScopeValName, Resolved), {
            CompoundTerm::getResolveTerm(ClassScopeValName, Class), CompoundTerm::getFieldTerm(Class, Resolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeMethodOfTerm(ClassScopeValName, Resolved), {
            CompoundTerm::getResolveTerm(ClassScopeValName, Class), CompoundTerm::getMethodTerm(Class, Resolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeConstructorOfTerm(ClassScopeValName, Resolved), {
            CompoundTerm::getResolveTerm(ClassScopeValName, Class), CompoundTerm::getConstructorTerm(Class, Resolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeInstanceOf(ClassScopeValName, ClassValName, Resolved), {
            CompoundTerm::getResolveTerm(ClassScopeValName, Class),
            CompoundTerm::getResolveTerm(ClassValName, ClassType),
            CompoundTerm::getFieldTerm(Class,Resolved),
            CompoundTerm::getInstanceOfTerm(Resolved, ClassType)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeParameterOf(MethodValName, Resolved), {
            CompoundTerm::getResolveTerm(MethodValName, Method), CompoundTerm::getParameterTerm(Method, Resolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeReturnOf(MethodValName, Resolved), {
            CompoundTerm::getResolveTerm(MethodValName, Method), CompoundTerm::getReturnTerm(Method, Resolved)
        }));

    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeCalledMethodOf(MethodValName, Resolved), {
            CompoundTerm::getResolveTerm(MethodValName, Method),CompoundTerm::getMethodTerm(Term::getIgnoredVar(),Method), CompoundTerm::getCalledKeyTerm(Method, Resolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeCalledParameterOf(ParamValName, Resolved), {
            CompoundTerm::getResolveTerm(ParamValName, Param),CompoundTerm::getParameterTerm(Term::getIgnoredVar(),Param), CompoundTerm::getCalledKeyTerm(Param, Resolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeCalledReturnOf(ReturnValName, Resolved), {
            CompoundTerm::getResolveTerm(ReturnValName, Return),CompoundTerm::getReturnTerm(Term::getIgnoredVar(),Return), CompoundTerm::getCalledKeyTerm(Return, Resolved)
        }));
    Term* superValName = Term::getVar("SuperValName");
    Term* superNode = Term::getVar("SuperNode");
    Term* subValName = Term::getVar("SubValName");
    Term* subNode = Term::getVar("SubNode");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeSuperOf(subValName, Resolved), {
            CompoundTerm::getResolveTerm(subValName, subNode), CompoundTerm::getOverrideOutRecurTerm(Resolved, subNode)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeSubOf(superValName, Resolved), {
            CompoundTerm::getResolveTerm(superValName, superNode), CompoundTerm::getOverrideInRecurTerm(superNode, Resolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeUnion(Node1, Node2, Resolved), {
            DisjunctionTerm::getDisjunctionInstance(CompoundTerm::getResolveTerm(Node1, Resolved), CompoundTerm::getResolveTerm(Node2, Resolved))
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeIntersection(Node1, Node2, Resolved), {
            CompoundTerm::getResolveTerm(Node1, Resolved), CompoundTerm::getResolveTerm(Node2, Resolved)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getNodeDifference(Node1, Node2, Resolved), {
            CompoundTerm::getResolveTerm(Node1, Resolved), NegationTerm::getNegInstance(CompoundTerm::getResolveTerm(Node2, Resolved))
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getResolveRuntimeTerm(nodeValName, ClassScopeValName, Method, RuntimeKey, node, keyType), {
            CompoundTerm::getResolveTerm(nodeValName, node),
            CompoundTerm::getRuntimeTerm(Method, node, RuntimeKey, keyType)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getResolveRuntimeCheckTerm(nodeValName, Method, RuntimeKey, node, keyType), {
            CompoundTerm::getRuntimeTerm(Method, node, RuntimeKey, keyType),
            CompoundTerm::getResolveTerm(nodeValName, node),
        }));

    for (auto& rule : rules) {
        PrologWrapper::addRule(rule->toString());
    }
    for (auto& rule : rules) {
        rule->returnThisToPool();
    }
}

// if it is increase steps: called key -> key
// if it is decrease steps: key -> called key
/**
__________________________________________________________________________________________________________
__________|  increase steps	          |  decrease steps(has history)    |   decrease steps(no history)
forward	  |  called method → method   |  return → called return 	    |   return → called return
__________|  called param  → param	  |                                 |
backward  |  called return → return	  |  method → called method         |   method → called method
          |                           |  param  → called param	        |   param  → called param
__________________________________________________________________________________________________________
*/

void EasierSimpleView::declareStepRules() {
    Term* runtimeMethod = Term::getVar("RuntimeMethod");
    Term* calledParam = Term::getVar("CalledParam");
    Term* calledMethod = Term::getVar("CalledMethod");
    Term* calledReturn = Term::getVar("CalledReturn");
    Term* point = Term::getVar("Point");
    Term* nextStepKey = Term::getVar("NextStep");
    Term* currentSteps = Term::getVar("CurrentSteps");
    Term* nextSteps = Term::getVar("NextSteps");
    Term* method = Term::getVar("MethodKey");
    Term* param = Term::getVar("ParamKey");
    Term* returnKey = Term::getVar("ReturnKey");
    Term* innerMethod = Term::getVar("InnerMethodKey");
    Term* outerMethod = Term::getVar("OuterMethodKey");
    Term* step = Term::getVar("Step");
    vector<Rule*> rules;

    rules.push_back(Rule::getRuleInstance(CompoundTerm::getCalledMethodToCalledReturnTerm(runtimeMethod, calledMethod, calledReturn), {
        CompoundTerm::getDataFlowTerm(runtimeMethod,calledMethod,calledReturn),
        CompoundTerm::getRuntimeTerm(runtimeMethod,Term::getIgnoredVar(),calledReturn,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_RETURN)),
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getCalledParamToCalledReturnTerm(runtimeMethod, calledParam, calledReturn), {
        CompoundTerm::getDataFlowTerm(runtimeMethod,calledParam,calledMethod),
        CompoundTerm::getRuntimeTerm(runtimeMethod,Term::getIgnoredVar(),calledMethod,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_METHOD)),
        CompoundTerm::getCalledMethodToCalledReturnTerm(runtimeMethod,calledMethod,calledReturn),
        }));

    rules.push_back(Rule::getRuleInstance(CompoundTerm::getCalledReturnToCalledMethod(runtimeMethod, calledReturn, calledMethod), {
        CompoundTerm::getDataFlowTerm(runtimeMethod,calledMethod,calledReturn),
        CompoundTerm::getRuntimeTerm(runtimeMethod,Term::getIgnoredVar(),calledMethod,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_METHOD)),
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getCalledReturnToCalledParam(runtimeMethod, calledReturn, calledParam), {
        CompoundTerm::getCalledReturnToCalledMethod(runtimeMethod,calledReturn,calledMethod),
        CompoundTerm::getDataFlowTerm(runtimeMethod,calledParam,calledMethod),
        CompoundTerm::getRuntimeTerm(runtimeMethod,Term::getIgnoredVar(),calledParam,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_PARAMETER)),
        }));

    // forward -----------------------------------------------------------------------------------------------------------------------------------------------
    // called method -> step -> step -> method (increase steps)
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getForwardTimingStepTerm(outerMethod, point, innerMethod, nextStepKey, currentSteps, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), currentSteps)), {
        // step out point
        CompoundTerm::getCalledMethodToCalledReturnTerm(outerMethod, point, calledReturn),
        // get addressable key and restore called key to normal key
        CompoundTerm::getRuntimeTerm(outerMethod,calledMethod,point,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_METHOD)),
        CompoundTerm::getCalledKeyTerm(innerMethod,calledMethod),
        // load
        CompoundTerm::getLoadStepInRuntimeTerm(innerMethod),
        // normal key to its step key and to its runtime key
        CompoundTerm::getStepKeyTerm(innerMethod,step),
        CompoundTerm::getRuntimeTerm(innerMethod,step,nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_TIMING_STEP)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(innerMethod),
        }));
    // called param -> step -> step -> param (increase steps)
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getForwardDataStepTerm(outerMethod, point, innerMethod, nextStepKey, currentSteps, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), currentSteps)), {
        // step out point
        CompoundTerm::getCalledParamToCalledReturnTerm(outerMethod, point, calledReturn),
        // get addressable key and restore called key to normal key
        CompoundTerm::getRuntimeTerm(outerMethod,calledParam,point,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_PARAMETER)),
        CompoundTerm::getCalledKeyTerm(param,calledParam),
        // load
        CompoundTerm::getParameterTerm(innerMethod,param),
        CompoundTerm::getLoadStepInRuntimeTerm(innerMethod),
        // normal key to its step key and to its runtime key
        CompoundTerm::getStepKeyTerm(param,step),
        CompoundTerm::getRuntimeTerm(innerMethod,step,nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(innerMethod),
        }));
    // return -> step -> step -> called return (current steps != [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getForwardDataStepTerm(innerMethod, point, outerMethod, nextStepKey, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), nextSteps), nextSteps), {
        CompoundTerm::getDataFlowTerm(outerMethod,nextStepKey,calledReturn),
        CompoundTerm::getRuntimeTerm(outerMethod,Term::getIgnoredVar(),nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP))
        }));
    // return -> step -> step -> called return (current steps == [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getForwardDataStepTerm(innerMethod, point, outerMethod, nextStepKey, Tail::getInstanceByElements({}), Tail::getInstanceByElements({})), {
        // load
        CompoundTerm::getLoadUseMethodRuntimeTerm(innerMethod),
        // get addressable key
        CompoundTerm::getRuntimeTerm(innerMethod,returnKey,point,Term::getInt(GlobalInfo::KEY_TYPE_METHOD_RETURN)),
        // to called key and to step key and to runtime key
        CompoundTerm::getCalledKeyTerm(returnKey,calledReturn),
        CompoundTerm::getStepKeyTerm(calledReturn,step),
        CompoundTerm::getRuntimeTerm(outerMethod,step,nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(outerMethod),
        }));
    // backward -----------------------------------------------------------------------------------------------------------------------------------------------
    // method -> step -> step -> called method (current steps != [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardTimingStepTerm(innerMethod, point, outerMethod, nextStepKey, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), nextSteps), nextSteps), {
        CompoundTerm::getCalledReturnToCalledMethod(outerMethod,calledReturn,calledMethod),
        CompoundTerm::getDataFlowTerm(outerMethod,calledMethod,nextStepKey),
        CompoundTerm::getRuntimeTerm(outerMethod,Term::getIgnoredVar(),nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_TIMING_STEP))
        }));
    // method -> step -> step -> called method (current steps == [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardTimingStepTerm(innerMethod, point, outerMethod, nextStepKey, Tail::getInstanceByElements({}), Tail::getInstanceByElements({})), {
        // load
        CompoundTerm::getLoadUseMethodRuntimeTerm(innerMethod),
        // get addressable key 
        CompoundTerm::getRuntimeTerm(innerMethod,method,point,Term::getInt(GlobalInfo::KEY_TYPE_METHOD)),
        // to called key and to step key and to runtime key
        CompoundTerm::getCalledKeyTerm(method,calledMethod),
        CompoundTerm::getStepKeyTerm(calledMethod,step),
        CompoundTerm::getRuntimeTerm(outerMethod,step,nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_TIMING_STEP)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(outerMethod),
        }));
    // param -> step -> step -> called param (current steps != [])
    Term* calledParamAddressable = Term::getVar("CalledParamAddressable");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardDataStepTerm(innerMethod, point, outerMethod, nextStepKey, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), nextSteps), nextSteps), {
        // restore step out point
        CompoundTerm::getCalledReturnToCalledParam(outerMethod,calledReturn,calledParam),
        // check the right parameter
        CompoundTerm::getRuntimeTerm(innerMethod,param,point,Term::getInt(GlobalInfo::KEY_TYPE_METHOD_PARAMETER)),
        CompoundTerm::getCalledKeyTerm(param,calledParamAddressable),
        CompoundTerm::getRuntimeTerm(outerMethod,calledParamAddressable,calledParam,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_PARAMETER)),
        // get the step key
        CompoundTerm::getDataFlowTerm(outerMethod,calledParam,nextStepKey),
        CompoundTerm::getRuntimeTerm(outerMethod,Term::getIgnoredVar(),nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP))
        }));
    // param -> step -> step -> called param (current steps == [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardDataStepTerm(innerMethod, point, outerMethod, nextStepKey, Tail::getInstanceByElements({}), Tail::getInstanceByElements({})), {
        // load
        CompoundTerm::getLoadUseMethodRuntimeTerm(innerMethod),
        // get addressable key 
        CompoundTerm::getRuntimeTerm(innerMethod,param,point,Term::getInt(GlobalInfo::KEY_TYPE_METHOD_PARAMETER)),
        // runtime step
        CompoundTerm::getCalledKeyTerm(param,calledParam),
        CompoundTerm::getStepKeyTerm(calledParam,step),
        CompoundTerm::getRuntimeTerm(outerMethod,step,nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(outerMethod),
        }));
    // called return -> step -> step -> return (increase steps)
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardDataStepTerm(outerMethod, point, innerMethod, nextStepKey, currentSteps, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, point }), currentSteps)), {
        // get addressable key and restore called key to normal key
        CompoundTerm::getRuntimeTerm(outerMethod,calledReturn,point,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_RETURN)),
        CompoundTerm::getCalledKeyTerm(returnKey,calledReturn),
        // load
        CompoundTerm::getReturnTerm(innerMethod,returnKey),
        CompoundTerm::getLoadStepInRuntimeTerm(innerMethod),
        // normal key to its step key and to its runtime key
        CompoundTerm::getStepKeyTerm(returnKey,step),
        CompoundTerm::getRuntimeTerm(innerMethod,step,nextStepKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(innerMethod),
        }));

    for (auto& rule : rules) {
        PrologWrapper::addRule(rule->toString());
    }
    for (auto& rule : rules) {
        rule->returnThisToPool();
    }
}

// if it is increase steps: called key -> key
// if it is decrease steps: key -> called key
/**
__________________________________________________________________________________________________________
__________|  increase steps	          |  decrease steps(has history)    |   decrease steps(no history)
forward	  |  called method → method   |  return → called return 	    |   return → called return
__________|  called param  → param	  |                                 |
backward  |  called return → return	  |  method → called method         |   method → called method
          |                           |  param  → called param	        |   param  → called param
__________________________________________________________________________________________________________
*/

void EasierSimpleView::declareOverrideRules() {
    Term* runtimeMethod = Term::getVar("RuntimeMethod");
    Term* calledParam = Term::getVar("CalledParam");
    Term* calledMethod = Term::getVar("CalledMethod");
    Term* calledReturn = Term::getVar("CalledReturn");
    Term* point = Term::getVar("Point");
    Term* nextOverrideKey = Term::getVar("NextOverride");
    Term* currentSteps = Term::getVar("CurrentSteps");
    Term* nextSteps = Term::getVar("NextSteps");
    Term* param = Term::getVar("ParamKey");
    Term* paramTemp = Term::getVar("ParamKeyTemp");
    Term* returnKey = Term::getVar("ReturnKey");
    Term* returnKeyTemp = Term::getVar("ReturnKeyTemp");
    Term* innerMethod = Term::getVar("InnerMethodKey");
    Term* innerMethodTemp = Term::getVar("InnerMethodKeyTemp");
    Term* outerMethod = Term::getVar("OuterMethodKey");
    Term* outerMethodTemp = Term::getVar("OuterMethodKeyTemp");
    Term* overrideKey = Term::getVar("Override");
    Term* method = Term::getVar("Method");
    Term* methodOverride = Term::getVar("MethodOverride");
    Term* calledMethodOverride = Term::getVar("CalledMethodOverride");
    Term* returnOverride = Term::getVar("ReturnOverride");
    Term* calledReturnOverride = Term::getVar("CalledReturnOverride");
    Term* paramOverride = Term::getVar("ParamOverride");
    Term* calledParamOverride = Term::getVar("CalledParamOverride");
    vector<Rule*> rules;

    // forward -----------------------------------------------------------------------------------------------------------------------------------------------
    // called method -> override -> override -> method (increase steps)
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getForwardTimingOverrideTerm(outerMethod, point, innerMethod, nextOverrideKey, currentSteps, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), currentSteps)), {
        // step out point
        CompoundTerm::getCalledMethodToCalledReturnTerm(outerMethod, point, calledReturn),
        // get addressable key and restore called key to normal key
        CompoundTerm::getRuntimeTerm(outerMethod,calledMethod,point,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_METHOD)),
        CompoundTerm::getCalledKeyTerm(innerMethodTemp,calledMethod),
        // load
        CompoundTerm::getLoadOverrideInRuntimeTerm(innerMethodTemp),
        // override recur
        CompoundTerm::getOverrideInRecurTerm(innerMethodTemp,innerMethod),
        // normal key to its override key and to its runtime key (nextOverrideKey)
        CompoundTerm::getOverrideKeyTerm(innerMethod,overrideKey),
        CompoundTerm::getRuntimeTerm(innerMethod,overrideKey,nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_TIMING_OVERRIDE)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(innerMethod),
        }));
    // called param -> override -> override -> param (increase steps)
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getForwardDataOverrideTerm(outerMethod, point, innerMethod, nextOverrideKey, currentSteps, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), currentSteps)), {
        // step out point
        CompoundTerm::getCalledParamToCalledReturnTerm(outerMethod, point, calledReturn),
        // get addressable key and restore called key to normal key
        CompoundTerm::getRuntimeTerm(outerMethod,calledParam,point,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_PARAMETER)),
        CompoundTerm::getCalledKeyTerm(paramTemp,calledParam),
        // load
        CompoundTerm::getParameterTerm(innerMethodTemp,paramTemp),
        CompoundTerm::getLoadOverrideInRuntimeTerm(innerMethodTemp),
        // override recur
        CompoundTerm::getOverrideInRecurTerm(paramTemp,param),
        // normal key to its override key and to its runtime key (nextOverrideKey)
        CompoundTerm::getOverrideKeyTerm(param,overrideKey),
        CompoundTerm::getParameterTerm(innerMethod,param),
        CompoundTerm::getRuntimeTerm(innerMethod,overrideKey,nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_OVERRIDE)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(innerMethod),
        }));
    // return -> override -> override -> called return (current steps != [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getForwardDataOverrideTerm(innerMethod, point, outerMethod, nextOverrideKey, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), nextSteps), nextSteps), {
        CompoundTerm::getDataFlowTerm(outerMethod,nextOverrideKey,calledReturn),
        CompoundTerm::getRuntimeTerm(outerMethod,Term::getIgnoredVar(),nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_OVERRIDE))
        }));
    // return -> override -> override -> called return (current steps == [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getForwardDataOverrideTerm(innerMethod, point, outerMethod, nextOverrideKey, Tail::getInstanceByElements({}), Tail::getInstanceByElements({})), {
        // load
        CompoundTerm::getLoadUseOverrideMethodRuntimeTerm(innerMethod),
        // get addressable key 
        CompoundTerm::getRuntimeTerm(innerMethod,returnKeyTemp,point,Term::getInt(GlobalInfo::KEY_TYPE_METHOD_RETURN)),
        // override out recur
        CompoundTerm::getOverrideOutRecurTerm(returnKey,returnKeyTemp),
        // to called key and to override key and to runtime key
        CompoundTerm::getCalledKeyTerm(returnKey,calledReturn),
        CompoundTerm::getOverrideKeyTerm(calledReturn,overrideKey),
        CompoundTerm::getRuntimeTerm(outerMethod,overrideKey,nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_OVERRIDE)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(outerMethod),
        }));
    // backward -----------------------------------------------------------------------------------------------------------------------------------------------
    // method -> override -> override -> called method (current steps != [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardTimingOverrideTerm(innerMethod, point, outerMethod, nextOverrideKey, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), nextSteps), nextSteps), {
        CompoundTerm::getCalledReturnToCalledMethod(outerMethod,calledReturn,calledMethod),
        CompoundTerm::getDataFlowTerm(outerMethod,calledMethod,nextOverrideKey),
        CompoundTerm::getRuntimeTerm(outerMethod,Term::getIgnoredVar(),nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_TIMING_OVERRIDE))
        }));
    // method -> override -> override -> called method (current steps == [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardTimingOverrideTerm(innerMethod, point, outerMethod, nextOverrideKey, Tail::getInstanceByElements({}), Tail::getInstanceByElements({})), {
        // load
        CompoundTerm::getLoadUseOverrideMethodRuntimeTerm(innerMethod),
        // get addressable key 
        CompoundTerm::getRuntimeTerm(innerMethod,innerMethodTemp,point,Term::getInt(GlobalInfo::KEY_TYPE_METHOD)),
        // override out recur
        CompoundTerm::getOverrideOutRecurTerm(method,innerMethodTemp),
        // to called key and to override key and to runtime key
        CompoundTerm::getCalledKeyTerm(method,calledMethod),
        CompoundTerm::getOverrideKeyTerm(calledMethod,overrideKey),
        CompoundTerm::getRuntimeTerm(outerMethod,overrideKey,nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_TIMING_OVERRIDE)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(outerMethod),
        }));
    // param -> overrideKey -> overrideKey -> called param (current steps != [])
    Term* calledParamAddressable = Term::getVar("CalledParamAddressable");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardDataOverrideTerm(innerMethod, point, outerMethod, nextOverrideKey, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, calledReturn }), nextSteps), nextSteps), {
        // restore step out point
        CompoundTerm::getCalledReturnToCalledParam(outerMethod,calledReturn,calledParam),
        // check the right parameter
        CompoundTerm::getRuntimeTerm(innerMethod,paramTemp,point,Term::getInt(GlobalInfo::KEY_TYPE_METHOD_PARAMETER)),
        CompoundTerm::getOverrideOutRecurTerm(param,paramTemp),
        CompoundTerm::getCalledKeyTerm(param,calledParamAddressable),
        CompoundTerm::getRuntimeTerm(outerMethod,calledParamAddressable,calledParam,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_PARAMETER)),
        // get the step key
        CompoundTerm::getDataFlowTerm(outerMethod,calledParam,nextOverrideKey),
        CompoundTerm::getRuntimeTerm(outerMethod,Term::getIgnoredVar(),nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_OVERRIDE))
        }));
    // param -> overrideKey -> overrideKey -> called param (current steps == [])
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardDataOverrideTerm(innerMethod, point, outerMethod, nextOverrideKey, Tail::getInstanceByElements({}), Tail::getInstanceByElements({})), {
        // load
        CompoundTerm::getLoadUseOverrideMethodRuntimeTerm(innerMethod),
        // get addressable key 
        CompoundTerm::getRuntimeTerm(innerMethod,paramTemp,point,Term::getInt(GlobalInfo::KEY_TYPE_METHOD_PARAMETER)),
        // override out recur
        CompoundTerm::getOverrideOutRecurTerm(param,paramTemp),
        // to called key and to override key and to runtime key
        CompoundTerm::getCalledKeyTerm(param,calledParam),
        CompoundTerm::getOverrideKeyTerm(calledParam,overrideKey),
        CompoundTerm::getRuntimeTerm(outerMethod,overrideKey,nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_OVERRIDE)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(outerMethod),
        }));
    // called return -> overrideKey -> overrideKey -> return (increase steps)
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getBackwardDataOverrideTerm(outerMethod, point, innerMethod, nextOverrideKey, currentSteps, Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod, point }), currentSteps)), {
        // get addressable key and restore called key to normal key
        CompoundTerm::getRuntimeTerm(outerMethod,calledReturn,point,Term::getInt(GlobalInfo::KEY_TYPE_CALLED_RETURN)),
        CompoundTerm::getCalledKeyTerm(returnKeyTemp,calledReturn),
        // load
        CompoundTerm::getReturnTerm(innerMethodTemp,returnKeyTemp),
        CompoundTerm::getLoadOverrideInRuntimeTerm(innerMethodTemp),
        // override in recur
        CompoundTerm::getOverrideInRecurTerm(returnKeyTemp,returnKey),
        // normal key to its override key and to its runtime key (nextOverrideKey)
        CompoundTerm::getOverrideKeyTerm(returnKey,overrideKey),
        CompoundTerm::getReturnTerm(innerMethod,returnKey),
        CompoundTerm::getRuntimeTerm(innerMethod,overrideKey,nextOverrideKey,Term::getInt(GlobalInfo::KEY_TYPE_DATA_OVERRIDE)),
        // load
        CompoundTerm::getLoadMethodUseAddressableTerm(innerMethod),
        }));

    for (auto& rule : rules) {
        PrologWrapper::addRule(rule->toString());
    }
    for (auto& rule : rules) {
        rule->returnThisToPool();
    }
}

void EasierSimpleView::declareLoadWhileSearching() {
    vector<Rule*> rules;

    Term* classKey = Term::getVar("ClassKey");
    Term* allClassKey = Term::getVar("AllClassKey");
    Term* fileName = Term::getVar("FileName");
    Term* filePath = Term::getVar("FilePath");
    Term* addressableDir = Term::getStr(FileManager::prologAddressableFileDir);
    Term* unaddressableDir = Term::getStr(FileManager::prologUnaddressableFileDir);
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getLoadAddressableTerm(classKey), {
        NegationTerm::getNegInstance(ConjunctionTerm::getConjunctionInstance({
            NegationTerm::getNegInstance(CompoundTerm::getAddressableLoadedTerm(classKey)),
            CompoundTerm::getTypeToPLFileTerm(classKey,fileName),
            CompoundTerm::getStringConcatTerm(addressableDir,fileName,filePath),
            EnsureLoadedTerm::getEnsureLoadedInstance(filePath),
            CompoundTerm::getTypeToPLFileTerm(allClassKey,fileName),
            AssertTerm::getAssertInstance(CompoundTerm::getAddressableLoadedTerm(allClassKey)),
            Term::getAtom("fail"),
        }))
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getLoadRuntimeTerm(classKey), {
        NegationTerm::getNegInstance(ConjunctionTerm::getConjunctionInstance({
            NegationTerm::getNegInstance(CompoundTerm::getUnaddressableLoadedTerm(classKey)),
            CompoundTerm::getTypeToPLFileTerm(classKey,fileName),
            CompoundTerm::getStringConcatTerm(unaddressableDir,fileName,filePath),
            EnsureLoadedTerm::getEnsureLoadedInstance(filePath),
            CompoundTerm::getTypeToPLFileTerm(allClassKey,fileName),
            AssertTerm::getAssertInstance(CompoundTerm::getUnaddressableLoadedTerm(allClassKey)),
            Term::getAtom("fail"),
        }))
        }));

    // method use addressable
    Term* method = Term::getVar("Method");
    Term* usedMethod = Term::getVar("UsedMethod");
    Term* usedField = Term::getVar("UsedField");
    Term* failTerm = Term::getAtom("fail");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getLoadMethodUseAddressableTerm(method), {
        NegationTerm::getNegInstance(ConjunctionTerm::getConjunctionInstance({
            CompoundTerm::getMethodUseMethodTerm(method,usedMethod),
            CompoundTerm::getMethodTerm(classKey,usedMethod),
            CompoundTerm::getLoadAddressableTerm(classKey),
            failTerm,
        }))
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getLoadMethodUseAddressableTerm(method), {
        NegationTerm::getNegInstance(ConjunctionTerm::getConjunctionInstance({
            CompoundTerm::getMethodUseFieldTerm(method,usedField),
            CompoundTerm::getFieldTerm(classKey,usedField),
            CompoundTerm::getLoadAddressableTerm(classKey),
            failTerm,
        }))
        }));
    // step in runtime
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getLoadStepInRuntimeTerm(method), {
        CompoundTerm::getMethodTerm(classKey,method),
        CompoundTerm::getLoadAddressableTerm(classKey),
        CompoundTerm::getLoadRuntimeTerm(classKey),
        }));
    // step out runtime
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getLoadUseMethodRuntimeTerm(usedMethod), {
        NegationTerm::getNegInstance(ConjunctionTerm::getConjunctionInstance({
            CompoundTerm::getMethodUseMethodTerm(method,usedMethod),
            CompoundTerm::getMethodTerm(classKey,method),
            CompoundTerm::getLoadAddressableTerm(classKey),
            CompoundTerm::getLoadRuntimeTerm(classKey),
            failTerm
        }))
        }));
    // override
    Term* key = Term::getVar("Key");
    Term* keyTemp = Term::getVar("KeyTemp");
    Term* superKey = Term::getVar("SuperKey");
    Term* subKey = Term::getVar("SubKey");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getOverrideInRecurTerm(key, subKey), {
        CompoundTerm::getOverrideTerm(key, subKey)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getOverrideInRecurTerm(key, subKey), {
        CompoundTerm::getOverrideTerm(key,keyTemp),CompoundTerm::getOverrideInRecurTerm(keyTemp,subKey)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getOverrideOutRecurTerm(superKey, key), {
        CompoundTerm::getOverrideTerm(superKey, key)
        }));
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getOverrideOutRecurTerm(superKey, key), {
        CompoundTerm::getOverrideTerm(keyTemp,key),CompoundTerm::getOverrideOutRecurTerm(superKey,keyTemp)
        }));
    // override in runtime
    Term* subMethod = Term::getVar("SubMethod");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getLoadOverrideInRuntimeTerm(method), {
        NegationTerm::getNegInstance(ConjunctionTerm::getConjunctionInstance({
            CompoundTerm::getOverrideInRecurTerm(method,subMethod),
            CompoundTerm::getLoadStepInRuntimeTerm(subMethod),
            failTerm,
        }))
        }));
    // override out runtime
    Term* superMethod = Term::getVar("SuperMethod");
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getLoadUseOverrideMethodRuntimeTerm(method), {
        NegationTerm::getNegInstance(ConjunctionTerm::getConjunctionInstance({
            CompoundTerm::getOverrideOutRecurTerm(superMethod,method),
            CompoundTerm::getLoadUseMethodRuntimeTerm(superMethod),
            failTerm,
        }))
        }));
    for (auto& rule : rules) {
        PrologWrapper::addRule(rule->toString());
    }
    for (auto& rule : rules) {
        rule->returnThisToPool();
    }
}

void EasierSimpleView::searchClass(char* searchStr, vector<const char*>& searchResult) {
    searchResult.clear();
    if (searchStr[0] == 0) {
        return;
    }
    try {
        std::regex reg(searchStr, std::regex_constants::icase);
        for (auto& typeKey : typeKeyInOrder) {
            if (std::regex_search(typeKey, reg)) {
                searchResult.push_back(typeKey.data());
            }
        }
    } catch (std::regex_error e) {
        spdlog::get(ErrorManager::DebugTag)->error("wrong regex: {}!", searchStr);
    }
}

void EasierSimpleView::searchNode(const char* classKey, vector<const char*>& searchResult) {
    if (not typeToPackage.count(classKey)) {
        return;
    }
    PrologWrapper::loadTypeKeyAddressable(classKey);
    if (not classToField.count(classKey)) {
        classToField[classKey] = list<string>();
        PrologWrapper::queryList(CompoundTerm::getFieldTerm(Term::getStr(classKey), Term::getVar("A")), [&](vector<Term*>& retList) {
            classToField[classKey].push_back(retList[0]->atomOrVar);
            });
    }
    if (not classToMethod.count(classKey)) {
        classToMethod[classKey] = list<string>();
        PrologWrapper::queryList(CompoundTerm::getMethodTerm(Term::getStr(classKey), Term::getVar("A")), [&](vector<Term*>& retList) {
            classToMethod[classKey].push_back(retList[0]->atomOrVar);
            });
    }
    if (not classToParameter.count(classKey)) {
        classToParameter[classKey] = list<string>();
        vector<Term*> retList;
        PrologWrapper::queryList(CompoundTerm::getParameterOfClassTerm(Term::getStr(classKey), Term::getVar("A")), [&](vector<Term*>& retList) {
            classToParameter[classKey].push_back(retList[0]->atomOrVar);
            });
    }
    if (not classToReturn.count(classKey)) {
        classToReturn[classKey] = list<string>();
        vector<Term*> retList;
        PrologWrapper::queryList(CompoundTerm::getReturnOfClassTerm(Term::getStr(classKey), Term::getVar("A")), [&](vector<Term*>& retList) {
            classToReturn[classKey].push_back(retList[0]->atomOrVar);
            });
    }
    searchResult.clear();
    FOR_EACH_ITEM(classToField[classKey], searchResult.push_back(item.data()););
    FOR_EACH_ITEM(classToMethod[classKey], searchResult.push_back(item.data()););
    FOR_EACH_ITEM(classToParameter[classKey], searchResult.push_back(item.data()););
    FOR_EACH_ITEM(classToReturn[classKey], searchResult.push_back(item.data()););
}

void EasierSimpleView::filterSearchResults(char* searchStr, vector<const char*>& searchResult) {
    if (searchStr[0] == 0) {
        searchResult.clear();
        return;
    }
    try {
        std::regex reg(searchStr, std::regex_constants::icase);
        vector<const char*> filtered;
        for (auto& searched : searchResult) {
            if (std::regex_search(searched, reg)) {
                filtered.push_back(searched);
            }
        }
        searchResult.clear();
        FOR_EACH_ITEM(filtered, searchResult.push_back(item););
    } catch (std::regex_error e) {
        searchResult.clear();
        spdlog::get(ErrorManager::DebugTag)->error("wrong regex: {}!", searchStr);
    }
}

void EasierSimpleView::getDependencyBoundsForClassScope(int classScopeIndex,
    list<int>& classScopeDependencyLower,
    list<int>& classScopeDependencyHigher,
    list<int>& nodeDependencyHigher) {
    auto* classScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[
        SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[classScopeIndex]
    ];
    for (int i = 0;i < classScopeIndex;i++) {
        string& classScopeName = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[i];
        auto* classScopeI = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopeName];
        if (classScope->referenceClassScope == classScopeI or
            classScope->operandForSetOperation.first == classScopeI or
            classScope->operandForSetOperation.second == classScopeI) {
            classScopeDependencyLower.push_back(i);
        }
    }
    for (int i = classScopeIndex + 1;i < SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.size();i++) {
        string& classScopeName = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[i];
        auto* classScopeI = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopeName];
        if (classScope == classScopeI->referenceClassScope or
            classScope == classScopeI->operandForSetOperation.first or
            classScope == classScopeI->operandForSetOperation.second) {
            classScopeDependencyHigher.push_back(i);
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size();i++) {
        string& nodeName = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i];
        auto* nodeI = SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeName];
        if (classScope == nodeI->classScope) {
            nodeDependencyHigher.push_back(i);
        }
        if (classScope == nodeI->classScope2) {
            nodeDependencyHigher.push_back(i);
        }
    }
}

void EasierSimpleView::getDependencyBoundsForNode(int nodeIndex,
    list<int>& classScopeDependencyLower,
    list<int>& nodeDependencyLower,
    list<int>& nodeDependencyHigher,
    list<int>& lineDependencyHigher,
    list<int>& graphDependencyHigher,
    list<int>& lineFinalInstanceDependencyHigher,
    list<int>& graphInstanceDependencyHigher) {
    auto* node = SimpleView::SimpleViewToGraphConverter::valNameToNode[
        SimpleView::SimpleViewToGraphConverter::nodeNameOrder[nodeIndex]
    ];
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.size();i++) {
        string& classScopeName = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[i];
        auto* classScopeI = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopeName];
        if (node->classScope == classScopeI) {
            classScopeDependencyLower.push_back(i);
        }
    }
    for (int i = 0;i < nodeIndex;i++) {
        string& nodeName = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i];
        auto* nodeI = SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeName];
        if (node->referenceNode == nodeI or
            node->operandForSetOperation.first == nodeI or
            node->operandForSetOperation.second == nodeI) {
            nodeDependencyLower.push_back(i);
        }
    }
    for (int i = nodeIndex + 1;i < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size();i++) {
        string& nodeName = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i];
        auto* nodeI = SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeName];
        if (node == nodeI->referenceNode or
            node == nodeI->operandForSetOperation.first or
            node == nodeI->operandForSetOperation.second) {
            nodeDependencyHigher.push_back(i);
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineNameOrder.size();i++) {
        string& lineName = SimpleView::SimpleViewToGraphConverter::lineNameOrder[i];
        auto* lineI = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineName];
        if (lineI->containNode(node)) {
            lineDependencyHigher.push_back(i);
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphNameOrder.size();i++) {
        string& graphName = SimpleView::SimpleViewToGraphConverter::graphNameOrder[i];
        auto* graphI = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphName];
        if (graphI->hasNodeAsArgument(node)) {
            graphDependencyHigher.push_back(i);
        }
    }
    string& nodeName = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[nodeIndex];
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.size();i++) {
        auto& lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[
            SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[i]
        ];
        for (auto& paramAndArg : lineInstance->paramNameToArgName) {
            if (strcmp(nodeName.data(), paramAndArg.second.data()) == 0) {
                lineFinalInstanceDependencyHigher.push_back(i);
                break;
            }
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.size();i++) {
        auto& graphInstance = SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[
            SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[i]
        ];
        for (auto& paramAndArg : graphInstance->paramNameToArgName) {
            if (strcmp(nodeName.data(), paramAndArg.second.data()) == 0) {
                graphInstanceDependencyHigher.push_back(i);
                break;
            }
        }

    }
}

void EasierSimpleView::getDependencyBoundsForLine(int lineIndex,
    list<int>& nodeDependencyLower,
    list<int>& lineDependencyLower,
    list<int>& lineDependencyHigher,
    list<int>& graphDependencyHigher,
    list<int>& lineFinalInstanceDependencyHigher
) {
    string& lineName = SimpleView::SimpleViewToGraphConverter::lineNameOrder[lineIndex];
    auto*& line = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineName];
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size();i++) {
        string& nodeName = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i];
        auto*& nodeI = SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeName];
        if (line->containNode(nodeI)) {
            nodeDependencyLower.push_back(i);
        }
    }
    for (int i = 0;i < lineIndex;i++) {
        string& lineNameI = SimpleView::SimpleViewToGraphConverter::lineNameOrder[i];
        if (line->containLineName(lineNameI)) {
            lineDependencyLower.push_back(i);
        }
    }
    for (int i = lineIndex + 1;i < SimpleView::SimpleViewToGraphConverter::lineNameOrder.size();i++) {
        string& lineNameI = SimpleView::SimpleViewToGraphConverter::lineNameOrder[i];
        auto*& lineI = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineNameI];
        if (lineI->containLineName(lineName)) {
            lineDependencyHigher.push_back(i);
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphNameOrder.size();i++) {
        string& graphName = SimpleView::SimpleViewToGraphConverter::graphNameOrder[i];
        auto* graphI = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphName];
        if (graphI->hasLineAsLineInstance(lineName)) {
            graphDependencyHigher.push_back(i);
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.size();i++) {
        auto& lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[
            SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[i]
        ];
        if (strcmp(lineName.data(), lineInstance->lineTemplate->name.data()) == 0) {
            lineFinalInstanceDependencyHigher.push_back(i);
        }
    }
}

void EasierSimpleView::getDependencyBoundsForGraph(int graphIndex,
    list<int>& nodeDependencyLower,
    list<int>& lineDependencyLower,
    list<int>& graphInstanceDependencyHigher) {
    string& graphName = SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphIndex];
    auto*& graph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphName];
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size();i++) {
        string& nodeName = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i];
        auto* nodeI = SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeName];
        if (graph->hasNodeAsArgument(nodeI)) {
            nodeDependencyLower.push_back(i);
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineNameOrder.size();i++) {
        string& lineName = SimpleView::SimpleViewToGraphConverter::lineNameOrder[i];
        if (graph->hasLineAsLineInstance(lineName)) {
            lineDependencyLower.push_back(i);
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.size();i++) {
        auto& graphInstance = SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[
            SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[i]
        ];
        if (strcmp(graphName.data(), graphInstance->graphTemplate->valName.data()) == 0) {
            graphInstanceDependencyHigher.push_back(i);
        }
    }
}

void EasierSimpleView::getDependencyBoundsForLineInstance(int lineInstanceIndex,
    list<int>& nodeDependencyLower,
    list<int>& lineDependencyLower) {
    auto& lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[
        SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[lineInstanceIndex]
    ];
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size();i++) {
        auto& nodeName = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i];
        for (auto& paramAndArg : lineInstance->paramNameToArgName) {
            if (strcmp(nodeName.data(), paramAndArg.second.data()) == 0) {
                nodeDependencyLower.push_back(i);
                break;
            }
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineNameOrder.size();i++) {
        auto& lineName = SimpleView::SimpleViewToGraphConverter::lineNameOrder[i];
        if (strcmp(lineName.data(), lineInstance->lineTemplate->name.data()) == 0) {
            lineDependencyLower.push_back(i);
        }
    }
}

void EasierSimpleView::getDependencyBoundsForGraphInstance(int graphInstanceIndex,
    list<int>& nodeDependencyLower,
    list<int>& graphDependencyLower) {
    auto& graphInstance = SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[
        SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[graphInstanceIndex]
    ];
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size();i++) {
        auto& nodeName = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i];
        for (auto& paramAndArg : graphInstance->paramNameToArgName) {
            if (strcmp(nodeName.data(), paramAndArg.second.data()) == 0) {
                nodeDependencyLower.push_back(i);
                break;
            }
        }
    }
    for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphNameOrder.size();i++) {
        auto& graphName = SimpleView::SimpleViewToGraphConverter::graphNameOrder[i];
        if (strcmp(graphName.data(), graphInstance->graphTemplate->valName.data()) == 0) {
            graphDependencyLower.push_back(i);
        }
    }
}

void EasierSimpleView::saveToFile() {
    ofstream f;
    f.open(FileManager::simpleViewConfig);
    for (auto& nameAndBasicStyle : SimpleView::SimpleViewToGraphConverter::valNameToBasicNodeStyle) {
        f << vocabularySymbolToLiteral[SimpleViewLexer::BASIC_STYLE] << " "
            << nameAndBasicStyle.first
            << " = "
            << nameAndBasicStyle.second->toString(vocabularySymbolToLiteral)
            << ";\n";
    }
    for (auto& nameAndStyle : SimpleView::SimpleViewToGraphConverter::valNameToNodeStyle) {
        f << vocabularySymbolToLiteral[SimpleViewLexer::STYLE] << " "
            << nameAndStyle.first
            << " = "
            << nameAndStyle.second->toString(vocabularySymbolToLiteral)
            << ";\n";
    }
    for (auto& classScopName : SimpleView::SimpleViewToGraphConverter::classScopeNameOrder) {
        if (SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopName]->editingNew) {
            continue;
        }
        f << vocabularySymbolToLiteral[SimpleViewLexer::CLASS_SCOPE] << " "
            << classScopName
            << " = "
            << SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopName]->toString(vocabularySymbolToLiteral)
            << ";\n";
    }
    for (auto& nodeName : SimpleView::SimpleViewToGraphConverter::nodeNameOrder) {
        if (SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeName]->editingNew) {
            continue;
        }
        f << vocabularySymbolToLiteral[SimpleViewLexer::NODE] << " "
            << nodeName
            << " = "
            << SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeName]->toString(vocabularySymbolToLiteral)
            << ";\n";
    }
    for (auto& lineName : SimpleView::SimpleViewToGraphConverter::lineNameOrder) {
        auto*& line = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineName];
        if (line->editingNew) {
            continue;
        }
        string lineType = "";
        switch (line->lineType) {
        case SimpleView::LineTemplate::LINE_TYPE_CODE_ORDER:
            lineType = vocabularySymbolToLiteral[SimpleViewLexer::CODE_ORDER];
            break;
        case SimpleView::LineTemplate::LINE_TYPE_DATA_FLOW:
            lineType = vocabularySymbolToLiteral[SimpleViewLexer::LINE];
            break;
        case SimpleView::LineTemplate::LINE_TYPE_SEGMENT:
            lineType = vocabularySymbolToLiteral[SimpleViewLexer::SEGMENT];
            break;
        }
        f << lineType << " "
            << line->displayName
            << " = "
            << line->toString(vocabularySymbolToLiteral)
            << ";\n";
    }
    for (auto& graphName : SimpleView::SimpleViewToGraphConverter::graphNameOrder) {
        auto& graph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphName];
        if (graph->editingNew) {
            continue;
        }
        f << vocabularySymbolToLiteral[SimpleViewLexer::GRAPH] << " "
            << graph->displayName
            << " = "
            << graph->toString(vocabularySymbolToLiteral)
            << ";\n";
    }
    for (auto& lineInstanceName : SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder) {
        auto& lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[lineInstanceName];
        if (lineInstance->editingNew) {
            continue;
        }
        lineInstance->updateDisplayName();
        f << vocabularySymbolToLiteral[SimpleViewLexer::LINE_INSTANCE] << " "
            << lineInstance->valName
            << " = "
            << lineInstance->displayName
            << ";\n";
    }
    for (auto& graphInstanceName : SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder) {
        auto& graphInstance = SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[graphInstanceName];
        if (graphInstance->editingNew) {
            continue;
        }
        graphInstance->updateDisplayName();
        f << vocabularySymbolToLiteral[SimpleViewLexer::GRAPH_INSTANCE] << " "
            << graphInstance->valName
            << " = "
            << graphInstance->displayName
            << ";\n";
    }

    f.close();
}

int SimpleView::ToBeResolved::nameCount = 1;

SimpleView::ToBeResolved::ToBeResolved() {
    innerValName = to_string(nameCount);
    nameCount++;
}

string SimpleView::ClassScope::toString(map<int, string>& voc) const {
    switch (classScopeType) {
    case CLASS_SCOPE_TYPE_KEY:
        return "\"" + extraStr + "\"";
    case CLASS_SCOPE_TYPE_LIST:
    {
        string ret = "[";
        for (auto& s : classList) {
            ret += "\"" + s + "\",";
        }
        ret.pop_back();
        ret.push_back(']');
        return ret;
    }
    case CLASS_SCOPE_TYPE_IN_PACKAGE:
        return voc[SimpleViewLexer::IN_PACKAGE] + " ( \"" + extraStr + "\" )";
    case CLASS_SCOPE_TYPE_USED_BY:
        if (referenceClassScope->displayName.empty()) {
            return voc[SimpleViewLexer::USED_BY] + " ( " + referenceClassScope->toString(voc) + " )";
        } else {
            return voc[SimpleViewLexer::USED_BY] + " ( " + referenceClassScope->displayName + " )";
        }
    case CLASS_SCOPE_TYPE_USE:
        if (referenceClassScope->displayName.empty()) {
            return voc[SimpleViewLexer::USE] + " ( " + referenceClassScope->toString(voc) + " )";
        } else {
            return voc[SimpleViewLexer::USE] + " ( " + referenceClassScope->displayName + " )";
        }
    case CLASS_SCOPE_TYPE_SUPER:
        if (referenceClassScope->displayName.empty()) {
            return voc[SimpleViewLexer::SUPER] + " ( " + referenceClassScope->toString(voc) + " )";
        } else {
            return voc[SimpleViewLexer::SUPER] + " ( " + referenceClassScope->displayName + " )";
        }
    case CLASS_SCOPE_TYPE_SUB:
        if (referenceClassScope->displayName.empty()) {
            return voc[SimpleViewLexer::SUB] + " ( " + referenceClassScope->toString(voc) + " )";
        } else {
            return voc[SimpleViewLexer::SUB] + " ( " + referenceClassScope->displayName + " )";
        }
    case CLASS_SCOPE_TYPE_INTERSECTION:
    {
        string firstText = operandForSetOperation.first->displayName.empty() ?
            operandForSetOperation.first->toString(voc) : operandForSetOperation.first->displayName;
        string secondText = operandForSetOperation.second->displayName.empty() ?
            operandForSetOperation.second->toString(voc) : operandForSetOperation.second->displayName;
        return firstText + " & " + secondText;
    }
    case CLASS_SCOPE_TYPE_UNION:
    {
        string firstText = operandForSetOperation.first->displayName.empty() ?
            operandForSetOperation.first->toString(voc) : operandForSetOperation.first->displayName;
        string secondText = operandForSetOperation.second->displayName.empty() ?
            operandForSetOperation.second->toString(voc) : operandForSetOperation.second->displayName;
        return firstText + " | " + secondText;
    }
    case CLASS_SCOPE_TYPE_DIFFERENCE:
    {
        string firstText = operandForSetOperation.first->displayName.empty() ?
            operandForSetOperation.first->toString(voc) : operandForSetOperation.first->displayName;
        string secondText = operandForSetOperation.second->displayName.empty() ?
            operandForSetOperation.second->toString(voc) : operandForSetOperation.second->displayName;
        return firstText + " - " + secondText;
    }
    case CLASS_SCOPE_TYPE_VAR:
    {
        return "{ " + referenceClassScope->displayName + " }";
    }
    }
    return "error: wrong class scope type.";
}

void SimpleView::ClassScope::resolve(std::function<void(int, int, const char*)>* update) {
    if (resolved) {
        return;
    }
    spdlog::get(ErrorManager::DebugTag)->info("resolve class scope: {}; {}", displayName.data(), innerValName.data());
    resolvedList.clear();
    std::function<void(vector<Term*>&)> termListForQuery = [&](vector<Term*>& retList) {resolvedList.insert(retList[0]->atomOrVar);};
    switch (classScopeType) {
    case CLASS_SCOPE_TYPE_KEY:
        resolvedList.insert(extraStr);
        break;
    case CLASS_SCOPE_TYPE_LIST:
        FOR_EACH_ITEM(classList, resolvedList.insert(item););
        break;
    case CLASS_SCOPE_TYPE_IN_PACKAGE:
        PrologWrapper::queryList(CompoundTerm::getPackageTerm(Term::getStr(extraStr), Term::getVar("C")), termListForQuery);
        break;
    case CLASS_SCOPE_TYPE_USED_BY:
        referenceClassScope->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getClassScopeUsedBy(
            Term::getStr(referenceClassScope->innerValName), Term::getVar("C")), termListForQuery);
        break;
    case CLASS_SCOPE_TYPE_USE:
        referenceClassScope->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getClassScopeUse(
            Term::getStr(referenceClassScope->innerValName), Term::getVar("C")), termListForQuery);
        break;
    case CLASS_SCOPE_TYPE_SUPER:
        referenceClassScope->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getClassScopeSuper(
            Term::getStr(referenceClassScope->innerValName), Term::getVar("C")), termListForQuery);
        break;
    case CLASS_SCOPE_TYPE_SUB:
        referenceClassScope->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getClassScopeSub(
            Term::getStr(referenceClassScope->innerValName), Term::getVar("C")), termListForQuery);
        break;
    case CLASS_SCOPE_TYPE_UNION:
        operandForSetOperation.first->resolve(update);
        operandForSetOperation.second->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getClassScopeUnionTerm(
            Term::getStr(operandForSetOperation.first->innerValName),
            Term::getStr(operandForSetOperation.second->innerValName),
            Term::getVar("C")), termListForQuery);
        break;
    case CLASS_SCOPE_TYPE_INTERSECTION:
        operandForSetOperation.first->resolve(update);
        operandForSetOperation.second->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getClassScopeIntersectionTerm(
            Term::getStr(operandForSetOperation.first->innerValName),
            Term::getStr(operandForSetOperation.second->innerValName),
            Term::getVar("C")), termListForQuery);
        break;
    case CLASS_SCOPE_TYPE_DIFFERENCE:
        operandForSetOperation.first->resolve(update);
        operandForSetOperation.second->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getClassScopeDifferenceTerm(
            Term::getStr(operandForSetOperation.first->innerValName),
            Term::getStr(operandForSetOperation.second->innerValName),
            Term::getVar("C")), termListForQuery);
        break;
    }
    if (classScopeType == CLASS_SCOPE_TYPE_VAR) {
        referenceClassScope->resolve(update);
        resolvedList = referenceClassScope->resolvedList;
        Term* keyTerm = Term::getVar("K");
        PrologWrapper::addRule(
            Rule::getRuleInstance(CompoundTerm::getResolveTerm(Term::getStr(innerValName), keyTerm),
                { CompoundTerm::getResolveTerm(Term::getStr(referenceClassScope->innerValName),keyTerm) }
            )->toString(true)
        );
    } else {
        int c = 0;
        FOR_EACH_ITEM(resolvedList, c++;if (update) (*update)(c, resolvedList.size(), item.data());PrologWrapper::loadTypeKeyAddressable(item););
        if (update) (*update)(resolvedList.size() + 1, resolvedList.size(), "");
        FOR_EACH_ITEM(resolvedList, PrologWrapper::addFact(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getStr(item))->toString(true)););
    }
    resolved = true;
}

void SimpleView::ClassScope::unResolve(bool retract) {
    spdlog::get(ErrorManager::DebugTag)->info("unresolve class scope: {}; {}", displayName.data(), innerValName.data());
    if (referenceClassScope) {
        referenceClassScope->unResolve();
    }
    switch (classScopeType) {
    case CLASS_SCOPE_TYPE_UNION:
    case CLASS_SCOPE_TYPE_INTERSECTION:
    case CLASS_SCOPE_TYPE_DIFFERENCE:
        operandForSetOperation.first->unResolve();
        operandForSetOperation.second->unResolve();
    }
    if (retract) {
        FOR_EACH_ITEM(resolvedList,
            PrologWrapper::retractSingleFact(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getStr(item))->toString(true));
            );
    }
    resolved = false;
}

int SimpleView::ClassScope::getClassType() {
    return ToBeResolved::CLASS_TYPE_CLASS_SCOPE;
}

void SimpleView::ClassScope::listTerm(vector<const char*>& ret) {
    ret.clear();
    for (auto& s : resolvedList) {
        ret.push_back(s.data());
    }
}

void SimpleView::ClassScope::loadValueToUI(vector<const char*>& values) {
    switch (classScopeType) {
    case CLASS_SCOPE_TYPE_KEY:
    case CLASS_SCOPE_TYPE_IN_PACKAGE:
        values.push_back(extraStr.data());
        break;
    case CLASS_SCOPE_TYPE_LIST:
        FOR_EACH_ITEM(classList, values.push_back(item.data()););
        break;
    case CLASS_SCOPE_TYPE_USED_BY:
    case CLASS_SCOPE_TYPE_USE:
    case CLASS_SCOPE_TYPE_SUPER:
    case CLASS_SCOPE_TYPE_SUB:
        values.push_back(referenceClassScope->displayName.data());
        break;
    case CLASS_SCOPE_TYPE_INTERSECTION:
    case CLASS_SCOPE_TYPE_UNION:
    case CLASS_SCOPE_TYPE_DIFFERENCE:
        values.push_back(operandForSetOperation.first->displayName.data());
        values.push_back(operandForSetOperation.second->displayName.data());
        break;
    case CLASS_SCOPE_TYPE_VAR:
        values.push_back(referenceClassScope->displayName.data());
        break;
    }
}

void SimpleView::ClassScope::resetValue(const char* name, int type, vector<const char*>& values) {
    this->classScopeType = type;
    this->displayName = name;
    switch (type) {
    case CLASS_SCOPE_TYPE_KEY:
    case CLASS_SCOPE_TYPE_IN_PACKAGE:
        this->extraStr = values[0];
        break;
    case CLASS_SCOPE_TYPE_LIST:
    {
        list<string> movedClassList;
        FOR_EACH_ITEM(classList, movedClassList.push_back(std::move(item)););
        classList.clear();
        FOR_EACH_ITEM(values, classList.push_back(item););
        break;
    }
    case CLASS_SCOPE_TYPE_USED_BY:
    case CLASS_SCOPE_TYPE_USE:
    case CLASS_SCOPE_TYPE_SUPER:
    case CLASS_SCOPE_TYPE_SUB:
        referenceClassScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[values[0]];
        break;
    case CLASS_SCOPE_TYPE_INTERSECTION:
    case CLASS_SCOPE_TYPE_UNION:
    case CLASS_SCOPE_TYPE_DIFFERENCE:
        operandForSetOperation = {
            SimpleView::SimpleViewToGraphConverter::valNameToClassScope[values[0]],
            SimpleView::SimpleViewToGraphConverter::valNameToClassScope[values[1]]
        };
        break;
    case CLASS_SCOPE_TYPE_VAR:
        referenceClassScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[values[0]];
        break;
    }

    if (not editingNew) {
        for (auto& nameAndClassScpoe : SimpleView::SimpleViewToGraphConverter::valNameToClassScope) {
            nameAndClassScpoe.second->unResolve(true);
            nameAndClassScpoe.second->updateDisplayText();
        }
        for (auto& nameAndNode : SimpleView::SimpleViewToGraphConverter::valNameToNode) {
            nameAndNode.second->unResolve(true);
            nameAndNode.second->updateDisplayText();
        }
        for (auto& nameAndLine : SimpleView::SimpleViewToGraphConverter::valNameToLine) {
            nameAndLine.second->resolved = false;
        }
    } else {
        updateDisplayText();
    }
    iconId = SimpleView::ClassScope::classTypeToIconId[classScopeType];
}

void SimpleView::ClassScope::updateDisplayText() {
    displayText = displayName + " : " + toString(EasierSimpleView::vocabularySymbolToLiteral);
}

void SimpleView::ClassScope::loadRuntime(std::function<void(int, int, const char*)>* loadRuntimeUpdate) {
    int c = 0;
    FOR_EACH_ITEM(resolvedList, c++;if (loadRuntimeUpdate) (*loadRuntimeUpdate)(c, resolvedList.size(), item.data());PrologWrapper::loadTypeKeyUnaddressable(item););
    if (loadRuntimeUpdate) (*loadRuntimeUpdate)(resolvedList.size() + 1, resolvedList.size(), "");
}

SimpleView::Node* SimpleView::Node::NODE_ANY = NULL;
SimpleView::Node* SimpleView::Node::NODE_REFERENCE = NULL;
SimpleView::Node* SimpleView::Node::NODE_CONDITION = NULL;
SimpleView::Node* SimpleView::Node::NODE_ELSE = NULL;
SimpleView::Node* SimpleView::Node::NODE_DATA_STEP = NULL;
SimpleView::Node* SimpleView::Node::NODE_TIMING_STEP = NULL;

SimpleView::Node* SimpleView::Node::NODE_FIELD = NULL;
SimpleView::Node* SimpleView::Node::NODE_METHOD = NULL;
SimpleView::Node* SimpleView::Node::NODE_CONSTRUCTOR = NULL;
SimpleView::Node* SimpleView::Node::NODE_CALLED_METHOD = NULL;
SimpleView::Node* SimpleView::Node::NODE_PARAMETER = NULL;
SimpleView::Node* SimpleView::Node::NODE_CALLED_PARAMETER = NULL;
SimpleView::Node* SimpleView::Node::NODE_RETURN = NULL;
SimpleView::Node* SimpleView::Node::NODE_CALLED_RETURN = NULL;
SimpleView::Node* SimpleView::Node::NODE_INDEX = NULL;
SimpleView::Node* SimpleView::Node::NODE_DATA_OVERRIDE = NULL;
SimpleView::Node* SimpleView::Node::NODE_TIMING_OVERRIDE = NULL;

SimpleView::Node* SimpleView::Node::getSpecialNode(int nodeType) {
    auto* node = new Node();
    node->nodeType = nodeType;
    switch (nodeType) {
    case Node::NODE_TYPE_ANY:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::ANY];
        node->iconId = Images::anyIconId;
        break;
    case Node::NODE_TYPE_REFERENCE:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::REFERENCE];
        node->iconId = Images::referenceIconId;
        break;
    case Node::NODE_TYPE_CONDITION:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::CONDITION];
        node->iconId = Images::conditionIconId;
        break;
    case Node::NODE_TYPE_ELSE:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::ELSE];
        node->iconId = Images::elseIconId;
        break;
    case Node::NODE_TYPE_DATA_STEP:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::DATA_STEP];
        node->iconId = Images::stepIconId;
        break;
    case Node::NODE_TYPE_TIMING_STEP:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::TIMING_STEP];
        node->iconId = Images::stepIconId;
        break;
    case Node::NODE_TYPE_DATA_OVERRIDE:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::DATA_OVERRIDE];
        node->iconId = Images::overrideIcondId;
        break;
    case Node::NODE_TYPE_TIMING_OVERRIDE:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::TIMING_OVERRIDE];
        node->iconId = Images::overrideIcondId;
        break;
    case Node::NODE_TYPE_FIELD:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::FIELD];
        node->iconId = Images::fieldIconId;
        break;
    case Node::NODE_TYPE_METHOD:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::METHOD];
        node->iconId = Images::methodIconId;
        break;
    case Node::NODE_TYPE_CONSTRUCTOR:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::CONSTRUCTOR];
        node->iconId = Images::creatorIconId;
        break;
    case Node::NODE_TYPE_CALLED_METHOD:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::CALLED_METHOD];
        node->iconId = Images::methodIconId;
        break;
    case Node::NODE_TYPE_PARAMETER:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::PARAMETER];
        node->iconId = Images::parameterIconId;
        break;
    case Node::NODE_TYPE_CALLED_PARAMETER:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::CALLED_PARAMETER];
        node->iconId = Images::parameterIconId;
        break;
    case Node::NODE_TYPE_RETURN:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::RETURN];
        node->iconId = Images::returnIconId;
        break;
    case Node::NODE_TYPE_CALLED_RETURN:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::CALLED_RETURN];
        node->iconId = Images::returnIconId;
        break;
    case Node::NODE_TYPE_INDEX:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::INDEX];
        node->iconId = Images::indexIcon;
        break;
    default:
        break;
    }
    SimpleViewToGraphConverter::valNameToNode[node->displayName] = node;
    return node;
}

/**
 * function: add two functors according to node type
 * resolve functor and nodeType functor
 */
void SimpleView::Node::resolve(std::function<void(int, int, const char*)>* update) {
    if (resolved) {
        return;
    }
    spdlog::get(ErrorManager::DebugTag)->info("resolve node: {}; {}", displayName.data(), innerValName.data());
    resolvedList.clear();
    std::function<void(vector<Term*>&)> termListForQuery = [&](vector<Term*>& retList) {resolvedList.insert(retList[0]->atomOrVar);};
    set<string> classToLoad;
    switch (nodeType) {
    case NODE_TYPE_KEY:
        resolvedList.insert(nodeKey.first);
        classToLoad.insert(nodeKey.second);
        break;
    case NODE_TYPE_LIST:
        FOR_EACH_ITEM(nodeList, resolvedList.insert(item.first);classToLoad.insert(item.second););
        break;
    case NODE_TYPE_FIELD_OF:
        classScope->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeFieldOfTerm(Term::getStr(classScope->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_METHOD_OF:
        classScope->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeMethodOfTerm(Term::getStr(classScope->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_CREATOR:
        classScope->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeConstructorOfTerm(Term::getStr(classScope->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_INSTANCE_OF:
        classScope->resolve(update);
        classScope2->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeInstanceOf(Term::getStr(classScope->innerValName), Term::getStr(classScope2->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_PARAMETER_OF:
        referenceNode->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeParameterOf(Term::getStr(referenceNode->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_RETURN_OF:
        referenceNode->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeReturnOf(Term::getStr(referenceNode->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_SUPER:
        referenceNode->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeSuperOf(Term::getStr(referenceNode->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_SUB:
        referenceNode->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeSubOf(Term::getStr(referenceNode->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_CALLED_METHOD_OF:
        referenceNode->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeCalledMethodOf(Term::getStr(referenceNode->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_CALLED_PARAMETER_OF:
        referenceNode->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeCalledParameterOf(Term::getStr(referenceNode->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_CALLED_RETURN_OF:
        referenceNode->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeCalledReturnOf(Term::getStr(referenceNode->innerValName), Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_READ:
    case NODE_TYPE_WRITE:
        // read and write key word can only be the outermost layer
        referenceNode->resolve(update);
        PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getVar("N")), {
                CompoundTerm::getResolveTerm(Term::getStr(referenceNode->innerValName), Term::getVar("N"))
            }))->toString(true));
        break;
    case NODE_TYPE_UNION:
        operandForSetOperation.first->resolve(update);
        operandForSetOperation.second->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeUnion(
            Term::getStr(operandForSetOperation.first->innerValName),
            Term::getStr(operandForSetOperation.second->innerValName),
            Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_INTERSECTION:
        operandForSetOperation.first->resolve(update);
        operandForSetOperation.second->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeIntersection(
            Term::getStr(operandForSetOperation.first->innerValName),
            Term::getStr(operandForSetOperation.second->innerValName),
            Term::getVar("N")), termListForQuery);
        break;
    case NODE_TYPE_DIFFERENCE:
        operandForSetOperation.first->resolve(update);
        operandForSetOperation.second->resolve(update);
        PrologWrapper::queryList(CompoundTerm::getNodeDifference(
            Term::getStr(operandForSetOperation.first->innerValName),
            Term::getStr(operandForSetOperation.second->innerValName),
            Term::getVar("N")), termListForQuery);
        break;
    }
    if (nodeType == NODE_TYPE_VAR) {
        referenceNode->resolve(update);
        resolvedList = referenceNode->resolvedList;
        Term* keyTerm = Term::getVar("K");
        PrologWrapper::addRule(
            Rule::getRuleInstance(CompoundTerm::getResolveTerm(Term::getStr(innerValName), keyTerm),
                { CompoundTerm::getResolveTerm(Term::getStr(referenceNode->innerValName),keyTerm) }
            )->toString(true)
        );
    } else if (nodeType == NODE_TYPE_RUNTIME) {
        for (auto& runtimeNode : runtimeNodeList) {
            auto resolveRuntime = CompoundTerm::getResolveRuntimeTerm(
                Term::getStr(innerValName), Term::getIgnoredVar(),
                Term::getStr(std::get<0>(runtimeNode)), Term::getStr(std::get<1>(runtimeNode)),
                Term::getStr(std::get<2>(runtimeNode)), Term::getInt(std::get<3>(runtimeNode))
            );
            PrologWrapper::plCall(CompoundTerm::getLoadMethodUseAddressableTerm(Term::getStr(std::get<0>(runtimeNode)))->toString(true));
            PrologWrapper::plCall(CompoundTerm::getLoadAddressableTerm(Term::getStr(std::get<4>(runtimeNode)))->toString(true));
            PrologWrapper::plCall(CompoundTerm::getLoadRuntimeTerm(Term::getStr(std::get<4>(runtimeNode)))->toString(true));
            PrologWrapper::addFact(resolveRuntime->toString(true));
        }
    } else {
        int c = 0;
        FOR_EACH_ITEM(classToLoad, c++;if (update) (*update)(c, classToLoad.size(), item.data());PrologWrapper::loadTypeKeyAddressable(item););
        if (update) (*update)(classToLoad.size() + 1, classToLoad.size(), "");

        FOR_EACH_ITEM(resolvedList, PrologWrapper::addFact(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getStr(item))->toString(true)););
    }
    resolved = true;
}

SimpleView::ClassScope* SimpleView::Node::runtimeScopeThatUseIt() {
    if (nodeType == NODE_TYPE_VAR) {
        return referenceNode->runtimeScopeThatUseIt();
    }
    set<string> paramAndReturnKeys;
    set<string> fieldAndMethods;
    switch (nodeType) {
    case NODE_TYPE_RUNTIME:
    case NODE_TYPE_READ:
    case NODE_TYPE_WRITE:
        break;
    case NODE_TYPE_KEY:
    case NODE_TYPE_LIST:
    case NODE_TYPE_SUPER:
    case NODE_TYPE_SUB:
    case NODE_TYPE_UNION:
    case NODE_TYPE_INTERSECTION:
    case NODE_TYPE_DIFFERENCE:
        for (auto& key : resolvedList) {
            if (key[key.size() - 1] == ':') {
                fieldAndMethods.insert(key);
            } else if (key.rfind(':') != string::npos) {
                paramAndReturnKeys.insert(key);
            } else {
                fieldAndMethods.insert(key);
            }
        }
        break;
    case NODE_TYPE_PARAMETER_OF:
    case NODE_TYPE_RETURN_OF:
        paramAndReturnKeys.insert(resolvedList.begin(), resolvedList.end());
        break;
    case NODE_TYPE_CALLED_METHOD_OF:
        for (auto& key : resolvedList) {
            fieldAndMethods.insert(key.substr(0, key.size() - 1));
        }
        break;
    case NODE_TYPE_CALLED_PARAMETER_OF:
    case NODE_TYPE_CALLED_RETURN_OF:
        for (auto& key : resolvedList) {
            paramAndReturnKeys.insert(key.substr(0, key.size() - 1));
        }
        break;
    default:
        fieldAndMethods.insert(resolvedList.begin(), resolvedList.end());
    }
    for (auto& key : paramAndReturnKeys) {
        int pos = key.rfind(':');
        string mk = key.substr(0, pos + 1);
        fieldAndMethods.insert(mk);
    }
    set<string> classThatUseIt;
    for (auto& fieldOrMethod : fieldAndMethods) {
        PrologWrapper::queryList(CompoundTerm::getClassThatUseMethodAndFieldTerm(Term::getStr(fieldOrMethod), Term::getVar("C")),
            [&](vector<Term*>& retList) {classThatUseIt.insert(retList[0]->atomOrVar);}
        );
        PrologWrapper::queryList(CompoundTerm::getMethodTerm(Term::getVar("C"), Term::getStr(fieldOrMethod)),
            [&](vector<Term*>& retList) {classThatUseIt.insert(retList[0]->atomOrVar);}
        );
        PrologWrapper::queryList(CompoundTerm::getFieldTerm(Term::getVar("C"), Term::getStr(fieldOrMethod)),
            [&](vector<Term*>& retList) {classThatUseIt.insert(retList[0]->atomOrVar);}
        );
    }
    auto ret = new ClassScope();
    ret->classScopeType = ClassScope::CLASS_SCOPE_TYPE_LIST;
    FOR_EACH_ITEM(classThatUseIt, ret->classList.push_back(item););
    return ret;
}

void SimpleView::Node::unResolve(bool retract) {
    spdlog::get(ErrorManager::DebugTag)->info("unresolve node: {}; {}", displayName.data(), innerValName.data());
    if (classScope) {
        classScope->unResolve(retract);
    }
    if (classScope2) {
        classScope2->unResolve(retract);
    }
    if (referenceNode) {
        referenceNode->unResolve(retract);
    }
    switch (nodeType) {
    case NODE_TYPE_UNION:
    case NODE_TYPE_INTERSECTION:
    case NODE_TYPE_DIFFERENCE:
        operandForSetOperation.first->unResolve(retract);
        operandForSetOperation.second->unResolve(retract);
    }
    if (retract) {
        FOR_EACH_ITEM(resolvedList,
            PrologWrapper::retractSingleFact(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getStr(item))->toString(true));
            );
    }
    this->resolved = false;
}

string SimpleView::Node::toString(map<int, string>& voc) {
    switch (nodeType) {
    case NODE_TYPE_KEY:
        return "\"" + nodeKey.first + "\"" + " (\"" + nodeKey.second + "\")";
    case NODE_TYPE_LIST:
    {
        string ret = "[";
        for (auto& s : nodeList) {
            ret += "\"" + s.first + "\"" + " (\"" + s.second + "\"),";
        }
        ret.pop_back();
        ret.push_back(']');
        return ret;
    }
    case NODE_TYPE_ANY:
        return voc[SimpleViewLexer::ANY];
    case NODE_TYPE_FIELD_OF:
        return voc[SimpleViewLexer::FIELD_OF] + " ( " + classScope->displayName + " )";
    case NODE_TYPE_INSTANCE_OF:
        return voc[SimpleViewLexer::INSTANCE_OF] + " ( " + classScope->displayName + "," + classScope2->displayName + " )";
    case NODE_TYPE_CREATOR:
        return voc[SimpleViewLexer::CREATOR] + " ( " + classScope->displayName + " )";
    case NODE_TYPE_METHOD_OF:
        return voc[SimpleViewLexer::METHOD_OF] + " ( " + classScope->displayName + " )";
    case NODE_TYPE_PARAMETER_OF:
        return voc[SimpleViewLexer::PARAMETER_OF] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_RETURN_OF:
        return voc[SimpleViewLexer::RETURN_OF] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_SUPER:
        return voc[SimpleViewLexer::SUPER] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_SUB:
        return voc[SimpleViewLexer::SUB] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_CALLED_METHOD_OF:
        return voc[SimpleViewLexer::CALLED_METHOD_OF] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_CALLED_PARAMETER_OF:
        return voc[SimpleViewLexer::CALLED_PARAM_OF] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_CALLED_RETURN_OF:
        return voc[SimpleViewLexer::CALLED_RETURN_OF] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_READ:
        return voc[SimpleViewLexer::READ] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_WRITE:
        return voc[SimpleViewLexer::WRITE] + " ( " + referenceNode->displayName + " )";
    case NODE_TYPE_REFERENCE:
        return voc[SimpleViewLexer::REFERENCE];
    case NODE_TYPE_CONDITION:
        return voc[SimpleViewLexer::CONDITION];
    case NODE_TYPE_ELSE:
        return voc[SimpleViewLexer::ELSE];
    case NODE_TYPE_DATA_STEP:
        return voc[SimpleViewLexer::DATA_STEP];
    case NODE_TYPE_TIMING_STEP:
        return voc[SimpleViewLexer::TIMING_STEP];
    case NODE_TYPE_DATA_OVERRIDE:
        return voc[SimpleViewLexer::DATA_OVERRIDE];
    case NODE_TYPE_TIMING_OVERRIDE:
        return voc[SimpleViewLexer::TIMING_OVERRIDE];
    case NODE_TYPE_FIELD:
        return voc[SimpleViewLexer::FIELD];
    case NODE_TYPE_METHOD:
        return voc[SimpleViewLexer::METHOD];
    case NODE_TYPE_CONSTRUCTOR:
        return voc[SimpleViewLexer::CONSTRUCTOR];
    case NODE_TYPE_CALLED_METHOD:
        return voc[SimpleViewLexer::CALLED_METHOD];
    case NODE_TYPE_PARAMETER:
        return voc[SimpleViewLexer::PARAMETER];
    case NODE_TYPE_CALLED_PARAMETER:
        return voc[SimpleViewLexer::CALLED_PARAMETER];
    case NODE_TYPE_RETURN:
        return voc[SimpleViewLexer::RETURN];
    case NODE_TYPE_CALLED_RETURN:
        return voc[SimpleViewLexer::CALLED_RETURN];
    case NODE_TYPE_INDEX:
        return voc[SimpleViewLexer::INDEX];
    case NODE_TYPE_INTERSECTION:
        return operandForSetOperation.first->displayName + " & " + operandForSetOperation.second->displayName;
    case NODE_TYPE_UNION:
        return operandForSetOperation.first->displayName + " | " + operandForSetOperation.second->displayName;
    case NODE_TYPE_DIFFERENCE:
        return operandForSetOperation.first->displayName + " - " + operandForSetOperation.second->displayName;
    case NODE_TYPE_PARAM_OF_LINE_AND_GRAPH:
        return "NODE_TYPE_PARAM_OF_LINE_AND_GRAPH";
    case NODE_TYPE_VAR:
        return "{ " + referenceNode->displayName + " }";
    }
    return "(" + to_string(nodeType) + ")";
}

bool SimpleView::Node::isLimitedCount() {
    return nodeType != NODE_TYPE_ANY
        and nodeType != NODE_TYPE_REFERENCE
        and nodeType != NODE_TYPE_CONDITION
        and nodeType != NODE_TYPE_ELSE
        and nodeType != NODE_TYPE_DATA_STEP
        and nodeType != NODE_TYPE_TIMING_STEP
        and nodeType != NODE_TYPE_DATA_OVERRIDE
        and nodeType != NODE_TYPE_TIMING_OVERRIDE
        and nodeType != NODE_TYPE_FIELD
        and nodeType != NODE_TYPE_METHOD
        and nodeType != NODE_TYPE_CONSTRUCTOR
        and nodeType != NODE_TYPE_CALLED_METHOD
        and nodeType != NODE_TYPE_PARAMETER
        and nodeType != NODE_TYPE_CALLED_PARAMETER
        and nodeType != NODE_TYPE_RETURN
        and nodeType != NODE_TYPE_CALLED_RETURN
        and nodeType != NODE_TYPE_INDEX;
}

void SimpleView::Node::release() {

}

int SimpleView::Node::getClassType() {
    return ToBeResolved::CLASS_TYPE_NODE;
}

void SimpleView::Node::listTerm(vector<const char*>& ret) {
    ret.clear();
    for (auto& s : resolvedList) {
        ret.push_back(s.data());
    }
}

void SimpleView::Node::loadValueToUI(vector<const char*>& values, vector<const char*>& typeKeyForNodeKey) {
    switch (nodeType) {
    case NODE_TYPE_KEY:
        values.push_back(nodeKey.first.data());
        typeKeyForNodeKey.push_back(nodeKey.second.data());
        break;
    case NODE_TYPE_LIST:
        FOR_EACH_ITEM(nodeList, values.push_back(item.first.data());
        typeKeyForNodeKey.push_back(item.second.data()););
        break;
    case NODE_TYPE_FIELD_OF:
    case NODE_TYPE_METHOD_OF:
    case NODE_TYPE_CREATOR:
        values.push_back(classScope->displayName.data());
        break;
    case NODE_TYPE_PARAMETER_OF:
    case NODE_TYPE_RETURN_OF:
    case NODE_TYPE_SUPER:
    case NODE_TYPE_SUB:
    case NODE_TYPE_CALLED_METHOD_OF:
    case NODE_TYPE_CALLED_PARAMETER_OF:
    case NODE_TYPE_CALLED_RETURN_OF:
        values.push_back(referenceNode->displayName.data());
        break;
    case NODE_TYPE_INSTANCE_OF:
        values.push_back(classScope->displayName.data());
        values.push_back(classScope2->displayName.data());
        break;
    case NODE_TYPE_INTERSECTION:
    case NODE_TYPE_UNION:
    case NODE_TYPE_DIFFERENCE:
        values.push_back(operandForSetOperation.first->displayName.data());
        values.push_back(operandForSetOperation.second->displayName.data());
        break;
    case NODE_TYPE_VAR:
        values.push_back(referenceNode->displayName.data());
        break;
    }
}

void SimpleView::Node::resetValue(const char* name, int type, vector<const char*>& values, vector<const char*>& typeKeyForNodeKey) {
    string oldName = this->displayName;
    this->nodeType = type;
    this->displayName = name;
    switch (type) {
    case NODE_TYPE_KEY:
        this->nodeKey = { values[0],typeKeyForNodeKey[0] };
        break;
    case NODE_TYPE_LIST:
    {
        list<pair<string, string>> movedClassList;
        FOR_EACH_ITEM(nodeList, movedClassList.push_back(std::move(item)););
        nodeList.clear();
        for (int i = 0;i < values.size();i++) {
            nodeList.push_back({ values[i],typeKeyForNodeKey[i] });
        }
        break;
    }
    case NODE_TYPE_FIELD_OF:
    case NODE_TYPE_METHOD_OF:
    case NODE_TYPE_CREATOR:
        this->classScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[values[0]];
        break;
    case NODE_TYPE_PARAMETER_OF:
    case NODE_TYPE_RETURN_OF:
    case NODE_TYPE_SUPER:
    case NODE_TYPE_SUB:
    case NODE_TYPE_CALLED_METHOD_OF:
    case NODE_TYPE_CALLED_PARAMETER_OF:
    case NODE_TYPE_CALLED_RETURN_OF:
        this->referenceNode = SimpleViewToGraphConverter::valNameToNode[values[0]];
        break;
    case NODE_TYPE_INSTANCE_OF:
        this->classScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[values[0]];
        this->classScope2 = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[values[1]];
        break;
    case NODE_TYPE_INTERSECTION:
    case NODE_TYPE_UNION:
    case NODE_TYPE_DIFFERENCE:
        operandForSetOperation = {
            SimpleView::SimpleViewToGraphConverter::valNameToNode[values[0]],
            SimpleView::SimpleViewToGraphConverter::valNameToNode[values[1]]
        };
        break;
    case NODE_TYPE_VAR:
        referenceNode = SimpleViewToGraphConverter::valNameToNode[values[0]];
        break;
    }
    if (not editingNew) {
        for (auto& nameAndNode : SimpleView::SimpleViewToGraphConverter::valNameToNode) {
            nameAndNode.second->unResolve(true);
            nameAndNode.second->updateDisplayText();
        }
        for (auto& nameAndLine : SimpleView::SimpleViewToGraphConverter::valNameToLine) {
            nameAndLine.second->resolved = false;
            nameAndLine.second->updateDisplayText();
        }
        for (auto& lineInstance : SimpleView::SimpleViewToGraphConverter::valNameToLineInstance) {
            for (auto& paramAndArg : lineInstance.second->paramNameToArgName) {
                if (strcmp(paramAndArg.second.data(), oldName.data()) == 0) {
                    lineInstance.second->paramNameToArgName[paramAndArg.first] = this->displayName;
                    lineInstance.second->updateDisplayName();
                }
            }
        }
        for (auto& nameAndGraph : SimpleView::SimpleViewToGraphConverter::valNameToGraph) {
            for (auto& lineInstance : nameAndGraph.second->lineInstances) {
                for (auto& paramAndArg : lineInstance->paramNameToArgName) {
                    if (strcmp(paramAndArg.second.data(), oldName.data()) == 0) {
                        lineInstance->paramNameToArgName[paramAndArg.first] = this->displayName;
                        lineInstance->updateDisplayName();
                    }
                }
            }
        }
    } else {
        updateDisplayText();
    }
    iconId = SimpleView::Node::nodeTypeToIconId[nodeType];
}

void SimpleView::Node::updateDisplayText() {
    displayText = displayName + " : " + toString(EasierSimpleView::vocabularySymbolToLiteral);
}

string SimpleView::BasicStyle::toString(map<int, string>& voc) const {
    return "{" + voc[SimpleViewLexer::BASIC_NODE_SIZE] + ":" + to_string(basicNodeSize) + "; "
        + voc[SimpleViewLexer::BASIC_LABEL_SIZE] + ":" + to_string(basicLabelSize) + "; "
        + voc[SimpleViewLexer::BASIC_POSITION_Z] + ":" + to_string(basicPositionZ) + ";}";
}

string SimpleView::NodeStyle::toString(map<int, string>& voc) const {
    return "{" + voc[SimpleViewLexer::NODE_COLOR] + ":\"" + nodeColor + "\"; "
        + voc[SimpleViewLexer::NODE_SCALE] + ":" + to_string(nodeScale) + "; "
        + voc[SimpleViewLexer::LABEL_COLOR] + ":\"" + labelColor + "\"; "
        + voc[SimpleViewLexer::LABEL_SCALE] + ":" + to_string(labelScale) + "; "
        + voc[SimpleViewLexer::POSITION_Z] + ":" + to_string(positionZ) + ";}";
}

bool SimpleView::NodeAndRepeatType::isParamNode() {
    return node and node->nodeType == Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH;
}

int SimpleView::NodeAndRepeatType::encode(int charIndex, map<char, NodeAndRepeatType*>& charToNode, RegexTree* outputRegex, bool isRepeatTypeOne, map<Node*, char>& nodeToChar) {
    int currentCharIndex = charIndex;
    if (seg != NULL) {
        outputRegex->encodeChar = 0;
        outputRegex->isAlt = seg->isAlternation;
        for (int i = 0; i < seg->nodeAndRepeatType.size(); ++i) {
            auto* subRegexI = new RegexTree();
            outputRegex->subStructure.push_back(subRegexI);
            currentCharIndex = seg->nodeAndRepeatType[i]->encode(currentCharIndex, charToNode, subRegexI, isRepeatTypeOne and seg->nodeAndRepeatType[i]->repeatType == LineTemplate::REPEAT_TYPE_ONE, nodeToChar);
        }
    } else {
        if (isRepeatTypeOne or not nodeToChar.count(node)) {
            char encodeChar = ALPHABET_FOR_NODE_ENCODING[currentCharIndex];
            charToNode[encodeChar] = this;
            outputRegex->encodeChar = encodeChar;
            currentCharIndex++;
            if (not isRepeatTypeOne) {
                nodeToChar[node] = encodeChar;
            }
        } else {
            outputRegex->encodeChar = nodeToChar[node];
        }
    }
    // no matter if it is a segment, it always has a repeat type
    outputRegex->repeatType = repeatType;
    return currentCharIndex;
}

string SimpleView::RegexTree::getRepeatTypeString() {
    string repeatString = "";
    switch (repeatType) {
    case LineTemplate::REPEAT_TYPE_ZERO_OR_ONE:
        repeatString.push_back('?');
        break;
    case LineTemplate::REPEAT_TYPE_ZERO_OR_MORE:
        if (maxRecurDepth > 0) {
            repeatString += "{0," + to_string(maxRecurDepth) + "}";
        } else {
            repeatString += "*";
        }
        break;
    case LineTemplate::REPEAT_TYPE_ONE_OR_MORE:
        if (maxRecurDepth > 0) {
            repeatString += "{1," + to_string(maxRecurDepth) + "}";
        } else {
            repeatString += "+";
        }
        break;
    case LineTemplate::REPEAT_TYPE_ONE:
    default:
        break;
    }
    return repeatString;
}

int SimpleView::NodeAndRepeatType::countForMin(map<Node*, int>& nodeToRuntimeCount, map<string, string>& paramNameToArgName) {
    if (repeatType != LineTemplate::REPEAT_TYPE_ONE) {
        return INT_MAX;
    }
    if (seg) {
        vector<int> nodeCounts;
        FOR_EACH_ITEM(seg->nodeAndRepeatType, nodeCounts.push_back(item->countForMin(nodeToRuntimeCount, paramNameToArgName)););
        return *(std::min_element(std::begin(nodeCounts), std::end(nodeCounts)));
    } else {
        if (node->nodeType == Node::NODE_TYPE_RUNTIME) {
            return -1;
        }
        if (nodeToRuntimeCount.count(node)) {
            return nodeToRuntimeCount[node];
        } else {
            if (node->isLimitedCount()) {
                string innerName = node->innerValName;
                if (node->nodeType == SimpleView::Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH) {
                    innerName = SimpleView::SimpleViewToGraphConverter::valNameToNode[paramNameToArgName[node->displayName]]->innerValName;
                }
                int ret = PrologWrapper::queryCount(CompoundTerm::getCountTerm(CompoundTerm::getResolveTerm(Term::getStr(innerName), Term::getVar("Node")), Term::getVar("C")));
                nodeToRuntimeCount[node] = ret;
                return ret;
            } else {
                return INT_MAX;
            }
        }
    }
}

// backwardFlg: 0 for undecided(split position is undecided), 1 for forward, 2 for backward
void SimpleView::NodeAndRepeatType::markSplitByRuntimeCount(RegexTree* splitPoint, int backwardFlg, map<string, string>& paramNameToArgName) {
    splitPoint->isSplitPosition = not backwardFlg;
    splitPoint->isBackward = backwardFlg == 2;
    if (seg) {
        if (splitPoint->isSplitPosition) {
            vector<int> nodeCounts;
            map<Node*, int> nodeToRuntimeCount;
            spdlog::get(ErrorManager::TimerTag)->info("start count for min");
            FOR_EACH_ITEM(seg->nodeAndRepeatType, nodeCounts.push_back(item->countForMin(nodeToRuntimeCount, paramNameToArgName)););
            spdlog::get(ErrorManager::TimerTag)->info("end count for min");
            auto minIndex = std::distance(std::begin(nodeCounts), std::min_element(std::begin(nodeCounts), std::end(nodeCounts)));
            for (int i = 0;i < seg->nodeAndRepeatType.size();i++) {
                int backwardFlgI = 0;
                if (i == minIndex) {
                    backwardFlgI = 0;
                } else {
                    if (i < minIndex) {
                        backwardFlgI = 2;
                    } else {
                        backwardFlgI = 1;
                    }
                }
                seg->nodeAndRepeatType[i]->markSplitByRuntimeCount(splitPoint->subStructure[i], backwardFlgI, paramNameToArgName);
            }
        } else {
            for (int i = 0;i < seg->nodeAndRepeatType.size();i++) {
                seg->nodeAndRepeatType[i]->markSplitByRuntimeCount(splitPoint->subStructure[i], backwardFlg, paramNameToArgName);
            }
        }
    }
}

SimpleView::Node* SimpleView::NodeAndRepeatType::getSplitPoint(RegexTree* splitPoint, map<string, string>& paramNameToArgName) {
    if (seg) {
        for (int i = 0;i < seg->nodeAndRepeatType.size();i++) {
            if (splitPoint->subStructure[i]->isSplitPosition) {
                return seg->nodeAndRepeatType[i]->getSplitPoint(splitPoint->subStructure[i], paramNameToArgName);
            }
        }
    } else {
        if (node->nodeType == SimpleView::Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH) {
            return SimpleView::SimpleViewToGraphConverter::valNameToNode[paramNameToArgName[node->displayName]];
        } else {
            return node;
        }
    }
    return nullptr;
}

int SimpleView::RegexTree::maxRecurDepth = -1;
string SimpleView::RegexTree::maxRecurDepthStr = "*";

void SimpleView::RegexTree::changeMaxRecurDepth() {
    if (maxRecurDepth == -1) {
        maxRecurDepth = 10;
        maxRecurDepthStr = "10";
    } else if (maxRecurDepth == 10) {
        maxRecurDepth = 20;
        maxRecurDepthStr = "20";
    } else if (maxRecurDepth == 20) {
        maxRecurDepth = -1;
        maxRecurDepthStr = "*";
    }
}

string SimpleView::RegexTree::getRegex(bool isBackward, int* charCount) {
    string regex;
    string repeatString = getRepeatTypeString();
    if (encodeChar == 0) {
        if (not repeatString.empty() or isAlt) {
            regex += "(";
        }
        if (isBackward) {
            for (int i = subStructure.size() - 1; i > -1; i--) {
                if (subStructure[i]->isBackward or subStructure[i]->isSplitPosition) {
                    if (isAlt) {
                        regex += "(" + subStructure[i]->getRegex(true, charCount) + ")|";
                    } else {
                        regex += subStructure[i]->getRegex(true, charCount);
                    }
                }
            }
            if (isAlt) {
                regex.pop_back();
            }
        } else {
            for (int i = 0; i < subStructure.size();i++) {
                if (not subStructure[i]->isBackward or subStructure[i]->isSplitPosition) {
                    if (isAlt) {
                        regex += "(" + subStructure[i]->getRegex(false, charCount) + ")|";
                    } else {
                        regex += subStructure[i]->getRegex(false, charCount);
                    }
                }
            }
            if (isAlt) {
                regex.pop_back();
            }
        }
        if (not repeatString.empty() or isAlt) {
            regex += ")";
        }
    } else {
        regex.push_back(encodeChar);
        (*charCount)++;
    }
    return regex.empty() ? regex : regex + repeatString;
}

SimpleView::RegexTree* SimpleView::RegexTree::copy() {
    auto ret = new RegexTree();
    ret->encodeChar = encodeChar;
    ret->repeatType = repeatType;
    FOR_EACH_ITEM(subStructure, ret->subStructure.push_back(item->copy()););
    ret->isBackward = isBackward;
    ret->isAlt = isAlt;
    return ret;
}

void SimpleView::NodeAndRepeatType::resolve(std::function<void(int, int, const char*)>* update) {
    if (seg != NULL) {
        FOR_EACH_ITEM(seg->nodeAndRepeatType, item->resolve(update););
    } else {
        node->resolve(update);
    }
}

void SimpleView::NodeAndRepeatType::unResolve(bool retract) {
    if (seg != NULL) {
        FOR_EACH_ITEM(seg->nodeAndRepeatType, item->unResolve(););
    } else {
        node->unResolve();
    }
}

SimpleView::LineInstance* SimpleView::LineTemplate::getNoneParamInstance() {
    if (not noneParamInstance) {
        noneParamInstance = new LineInstance(this, {});
        noneParamInstance->valName = name;
    }
    return noneParamInstance;
}

SimpleView::LineTemplate::LineTemplate(const string& name, int lineType) : ToBeResolved() {
    this->name = name;
    this->lineType = lineType;
}

bool SimpleView::LineTemplate::containNode(Node* node) {
    for (auto*& nodeAndRepeatTypeI : nodeAndRepeatType) {
        if (nodeAndRepeatTypeI->node != NULL and nodeAndRepeatTypeI->node == node) {
            return true;
        }
    }
    return false;
}

bool SimpleView::LineTemplate::containLineName(string& lineName) {
    for (auto& nodeAndRepeatTypeI : nodeAndRepeatType) {
        if (nodeAndRepeatTypeI->seg != NULL and nodeAndRepeatTypeI->seg->name == lineName) {
            return true;
        }
    }
    return false;
}

bool SimpleView::LineTemplate::containLineNameRecursive(string& lineName) {
    for (auto& nodeAndRepeatTypeI : nodeAndRepeatType) {
        if (nodeAndRepeatTypeI->seg != NULL) {
            if (nodeAndRepeatTypeI->seg->name == lineName
                or nodeAndRepeatTypeI->seg->containLineNameRecursive(lineName)) {
                return true;
            }
        }
    }
    return false;
}

string SimpleView::LineTemplate::toString(map<int, string>& voc) {
    string ret = "";
    for (auto& nodeAndRepeatTypeI : nodeAndRepeatType) {
        if (nodeAndRepeatTypeI->seg != NULL) {
            ret += "[" + nodeAndRepeatTypeI->seg->name + "]";
        } else {
            ret += nodeAndRepeatTypeI->node->displayName;
        }
        if (nodeAndRepeatTypeI->nodeStyleSpec != nullptr) {
            ret += "{" + nodeAndRepeatTypeI->nodeStyleSpec->displayName + "}";
        }
        switch (nodeAndRepeatTypeI->repeatType) {
        case REPEAT_TYPE_ZERO_OR_ONE:
            ret.push_back('?');
            break;
        case REPEAT_TYPE_ZERO_OR_MORE:
            ret.push_back('*');
            break;
        case REPEAT_TYPE_ONE_OR_MORE:
            ret.push_back('+');
            break;
        }
        if (isAlternation) {
            ret += " || ";
        } else {
            ret += "->";
        }
    }
    ret.pop_back();
    ret.pop_back();
    if (isAlternation) {
        ret.pop_back();
        ret.pop_back();
    }
    return ret;
}

void SimpleView::LineTemplate::encode() {
    int charIndex = 0;
    regexTree = new RegexTree();
    regexTree->isAlt = isAlternation;
    charToNodeTemplate.clear();
    map<Node*, char> nodeToChar;
    for (int i = 0; i < nodeAndRepeatType.size(); ++i) {
        auto subTree = new RegexTree();
        charIndex = nodeAndRepeatType[i]->encode(charIndex, charToNodeTemplate, subTree, nodeAndRepeatType[i]->repeatType == REPEAT_TYPE_ONE, nodeToChar);
        regexTree->subStructure.push_back(subTree);
    }
}

void SimpleView::LineTemplate::updateDisplayText() {
    displayText = displayName + " : " + toString(EasierSimpleView::vocabularySymbolToLiteral);
}

void SimpleView::LineTemplate::updateIconId() {
    iconId = getIconId(lineType);
}

int SimpleView::LineTemplate::getIconId(int type) {
    switch (type) {
    case LINE_TYPE_SEGMENT:
        return Images::segmentLineIconId;
    case LINE_TYPE_DATA_FLOW:
        return Images::lineIconId;
    case LINE_TYPE_CODE_ORDER:
        return Images::orderLineIconId;
    }
}

bool SimpleView::LineTemplate::hasRepeatOnceNodeExceptFor(const string& exceptionSegName) {
    bool foundRepeatTypeOnce = false;
    for (auto& nodeAndRepeatTypeI : nodeAndRepeatType) {
        if (nodeAndRepeatTypeI->node != NULL
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_ANY
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_CONDITION
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_ELSE
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_REFERENCE
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_DATA_STEP
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_TIMING_STEP
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_DATA_OVERRIDE
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_TIMING_OVERRIDE
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_FIELD
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_METHOD
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_CONSTRUCTOR
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_CALLED_METHOD
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_PARAMETER
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_CALLED_PARAMETER
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_RETURN
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_CALLED_RETURN
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_INDEX
            and nodeAndRepeatTypeI->repeatType == SimpleView::LineTemplate::REPEAT_TYPE_ONE) {
            foundRepeatTypeOnce = true;
            break;
        } else if (nodeAndRepeatTypeI->seg != NULL
            and nodeAndRepeatTypeI->seg->name != exceptionSegName
            and nodeAndRepeatTypeI->seg->hasRepeatOnceNodeExceptFor(exceptionSegName)) {
            foundRepeatTypeOnce = true;
            break;
        }
    }
    return foundRepeatTypeOnce;
}

bool SimpleView::LineTemplate::checkValidation(vector<const char*>& values, vector<int>& repeatTypes) {
    bool foundRepeatTypeOnce = false;
    for (int i = 0;i < values.size();i++) {
        bool repeatTypeIsOnce = repeatTypes[i] == SimpleView::LineTemplate::REPEAT_TYPE_ONE;
        auto& valueI = values[i];
        if (SimpleView::SimpleViewToGraphConverter::valNameToLine.count(valueI)) {
            if (repeatTypeIsOnce and SimpleView::SimpleViewToGraphConverter::valNameToLine[valueI]->hasRepeatOnceNodeExceptFor("")) {
                foundRepeatTypeOnce = true;
                break;
            }
        } else if (SimpleView::SimpleViewToGraphConverter::valNameToNode.count(valueI)) {
            auto& node = SimpleView::SimpleViewToGraphConverter::valNameToNode[valueI];
            if (repeatTypeIsOnce and node->isLimitedCount()) {
                foundRepeatTypeOnce = true;
                break;
            }
        } else if (repeatTypeIsOnce) { // it is a paramter
            foundRepeatTypeOnce = true;
            break;
        }
    }
    return foundRepeatTypeOnce;
}

bool SimpleView::LineTemplate::resetValue(const char* name, int type, vector<const char*>& values, vector<int>& repeatTypes, bool isAlt) {
    if (type == LINE_TYPE_DATA_FLOW and not checkValidation(values, repeatTypes)) {
        return false;
    }
    if (type == LINE_TYPE_SEGMENT and not checkValidation(values, repeatTypes)) {
        // check if the lines that dependent on this segment have repeat type once node
        for (auto& l : SimpleView::SimpleViewToGraphConverter::valNameToLine) {
            if (l.second->lineType == LINE_TYPE_DATA_FLOW
                and l.second->containLineNameRecursive(this->name)
                and not l.second->hasRepeatOnceNodeExceptFor(this->name)) {
                return false;
            }
        }
    }
    this->isAlternation = isAlt and type == LINE_TYPE_SEGMENT;
    this->name = name;
    this->lineType = type;
    orderedParamName.clear();
    for (int i = 0;i < values.size();i++) {
        if (not SimpleView::SimpleViewToGraphConverter::valNameToLine.count(values[i]) and
            not SimpleView::SimpleViewToGraphConverter::valNameToNode.count(values[i])) {
            Node* paramNode = new Node();
            paramNode->iconId = Images::parameterIconId;
            paramNode->displayName = values[i];
            paramNode->nodeType = Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH;
            paramNode->extraStr = values[i];
            SimpleView::SimpleViewToGraphConverter::valNameToNode[values[i]] = paramNode;
        }
        if (SimpleView::SimpleViewToGraphConverter::valNameToNode.count(values[i])
            and SimpleView::SimpleViewToGraphConverter::valNameToNode[values[i]]->nodeType == Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH) {
            if (std::find(orderedParamName.begin(), orderedParamName.end(), values[i]) == orderedParamName.end()) {
                orderedParamName.push_back(values[i]);
            }
        }
    }
    this->displayName = name + (orderedParamName.empty() ? "" : "(" + joinVector(orderedParamName, ",") + ")");
    nodeAndRepeatType.clear();
    for (int i = 0;i < values.size();i++) {
        auto* nodeAndRepeatTypeI = new NodeAndRepeatType();
        nodeAndRepeatTypeI->repeatType = repeatTypes[i];
        if (SimpleView::SimpleViewToGraphConverter::valNameToNode.count(values[i])) {
            nodeAndRepeatTypeI->node = SimpleView::SimpleViewToGraphConverter::valNameToNode[values[i]];
        } else {
            nodeAndRepeatTypeI->seg = SimpleView::SimpleViewToGraphConverter::valNameToLine[values[i]];
        }
        nodeAndRepeatType.push_back(nodeAndRepeatTypeI);
    }
    updateIconId();
    encode();
    if (not editingNew and lineType == LINE_TYPE_SEGMENT) {
        for (auto& nameAndLine : SimpleView::SimpleViewToGraphConverter::valNameToLine) {
            nameAndLine.second->resolved = false;
            nameAndLine.second->updateDisplayText();
            nameAndLine.second->encode();
        }
    } else {
        updateDisplayText();
    }
    if (not editingNew) {
        for (auto& nameAndGraph : SimpleView::SimpleViewToGraphConverter::valNameToGraph) {
            nameAndGraph.second->applyIntersectionEditing();
            for (auto& lineInstance : nameAndGraph.second->lineInstances) {
                if (lineInstance->lineTemplate == this) {
                    lineInstance->updateDisplayName();
                }
            }
        }
    }
    return true;
}

void SimpleView::LineTemplate::loadValueToUI(vector<const char*>& values, vector<int>& repeatTypes) {
    for (auto& nodeAndRepeatTypeI : nodeAndRepeatType) {
        if (nodeAndRepeatTypeI->node != NULL) {
            values.push_back(nodeAndRepeatTypeI->node->displayName.data());
            repeatTypes.push_back(nodeAndRepeatTypeI->repeatType);
        } else {
            values.push_back(nodeAndRepeatTypeI->seg->displayName.data());
            repeatTypes.push_back(nodeAndRepeatTypeI->repeatType);
        }
    }
}

SimpleView::IntersectionPointInLine* SimpleView::LineTemplate::getPointInLine() {
    auto ret = new IntersectionPointInLine();
    ret->isSeg = true;
    for (auto& nodeAndRepeatTypeI : nodeAndRepeatType) {
        if (nodeAndRepeatTypeI->seg) {
            ret->seg.push_back(nodeAndRepeatTypeI->seg->getPointInLine());
        } else {
            ret->seg.push_back(new IntersectionPointInLine());
        }
    }
    return ret;
}

void SimpleView::LineTemplate::resolve(std::function<void(int, int, const char*)>* update) {
    if (resolved) {
        return;
    }
    spdlog::get(ErrorManager::DebugTag)->info("resolve line template: {}; {}", name.data(), innerValName.data());
    FOR_EACH_ITEM(nodeAndRepeatType, item->resolve(update););
    resolved = true;
}

void SimpleView::LineTemplate::unResolve(bool retract) {
    spdlog::get(ErrorManager::DebugTag)->info("unresolve line template: {}; {}", name.data(), innerValName.data());
    FOR_EACH_ITEM(nodeAndRepeatType, item->unResolve(););
    resolved = false;
}

int SimpleView::LineTemplate::getClassType() {
    return ToBeResolved::CLASS_TYPE_GRAPH;
}

SimpleView::LineInstance::LineInstance(LineTemplate* templateLine, const vector<string>& argumentNameForEachParam) : ToBeResolved() {
    this->lineTemplate = templateLine;
    for (int i = 0;i < argumentNameForEachParam.size();i++) {
        paramNameToArgName[lineTemplate->orderedParamName[i]] = argumentNameForEachParam[i];
    }
    updateDisplayName();
}

void SimpleView::LineInstance::findSplitPoint() {
    splitPoint = lineTemplate->regexTree->copy();
    splitPoint->isSplitPosition = true;
    splitPoint->isBackward = false;
    // split point by intersection point
    for (auto& intersection : intersectionInfo) {
        if (not intersectionInfoIsFirstPoint[intersection]) {
            intersection->markSplitByIntersection(splitPoint, 0);
            return;
        }
    }
    // split point by runtime count
    vector<int> nodeCounts;
    map<Node*, int> nodeToRuntimeCount;
    spdlog::get(ErrorManager::TimerTag)->info("start count for min");
    FOR_EACH_ITEM(lineTemplate->nodeAndRepeatType, nodeCounts.push_back(item->countForMin(nodeToRuntimeCount, paramNameToArgName)););
    spdlog::get(ErrorManager::TimerTag)->info("end count for min");
    auto minIndex = std::distance(std::begin(nodeCounts), std::min_element(std::begin(nodeCounts), std::end(nodeCounts)));
    for (int i = 0;i < lineTemplate->nodeAndRepeatType.size();i++) {
        int backwardFlgI = 0;
        if (i == minIndex) {
            backwardFlgI = 0;
        } else {
            if (i < minIndex) {
                backwardFlgI = 2;
            } else {
                backwardFlgI = 1;
            }
        }
        lineTemplate->nodeAndRepeatType[i]->markSplitByRuntimeCount(splitPoint->subStructure[i], backwardFlgI, paramNameToArgName);
    }
}

SimpleView::Node* SimpleView::LineInstance::getSplitPoint() {
    for (int i = 0;i < lineTemplate->nodeAndRepeatType.size();i++) {
        if (splitPoint->subStructure[i]->isSplitPosition) {
            return lineTemplate->nodeAndRepeatType[i]->getSplitPoint(splitPoint->subStructure[i], paramNameToArgName);
        }
    }
    return nullptr;
}

void SimpleView::LineInstance::resolve(std::function<void(int, int, const char*)>* updateAddressable) {
    if (resolved) {
        return;
    }
    spdlog::get(ErrorManager::DebugTag)->info("resolve line instance: {}; {}", valName.data(), innerValName.data());
    FOR_EACH_ITEM(paramNameToArgName, SimpleViewToGraphConverter::valNameToNode[item.second]->resolve(updateAddressable););
    lineTemplate->resolve(updateAddressable);
    resolved = true;
}

void SimpleView::LineInstance::unResolve(bool retract) {
    spdlog::get(ErrorManager::DebugTag)->info("unresolve line instance: {}; {}", valName.data(), innerValName.data());
    FOR_EACH_ITEM(paramNameToArgName, SimpleViewToGraphConverter::valNameToNode[item.second]->unResolve(););
    lineTemplate->unResolve();
    resolved = false;
}

void SimpleView::LineInstance::updateDisplayName() {
    vector<string> orderedArgNames;
    for (auto& paraName : lineTemplate->orderedParamName) {
        orderedArgNames.push_back(paramNameToArgName[paraName]);
    }
    displayName = lineTemplate->name + (orderedArgNames.empty() ? "" : "(" + joinVector(orderedArgNames, ",") + ")");
}

SimpleView::LineInstance* SimpleView::LineInstance::copy() {
    vector<string> arguments;
    for (auto& paramName : lineTemplate->orderedParamName) {
        arguments.push_back(paramNameToArgName[paramName]);
    }
    auto ret = new SimpleView::LineInstance(lineTemplate, arguments);
    ret->valName = valName;
    ret->indexInsideGraph = indexInsideGraph;
    return ret;
}

SimpleView::Node* SimpleView::LineInstance::turnParamNodeToArgNode(Node* param) {
    if (param->nodeType == SimpleView::Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH) {
        return SimpleViewToGraphConverter::valNameToNode[paramNameToArgName[param->displayName]];
    }
    return param;
}

int SimpleView::LineInstance::findIntersectionIndexByChar(char c) {
    for (int i = 0;i < intersectionInfo.size();i++) {
        if (findIntersectionIndexByChar(intersectionInfo[i], lineTemplate->regexTree, c)) {
            return i;
        }
    }
    return -1;
}

bool SimpleView::LineInstance::findIntersectionIndexByChar(IntersectionPointInLine* intersection, RegexTree* regexTree, char c) {
    if (intersection->isSeg) {
        for (int i = 0;i < intersection->seg.size();i++) {
            if (findIntersectionIndexByChar(intersection->seg[i], regexTree->subStructure[i], c)) {
                return true;
            }
        }
    } else {
        return regexTree->encodeChar == c and intersection->isIntersection;
    }
    return false;
}

void SimpleView::LineInstance::addRuntimeNode(list<tuple<string, string, string, int, string>>& runtimeNodes, bool downward) {
    isLineDownOrLineUp = true;
    Node* node = new Node();
    node->nodeType = Node::NODE_TYPE_RUNTIME;
    node->displayName = node->innerValName;
    node->runtimeNodeList = runtimeNodes;
    NodeAndRepeatType* nodeAndRepeatType = new NodeAndRepeatType();
    nodeAndRepeatType->node = node;
    nodeAndRepeatType->repeatType = LineTemplate::REPEAT_TYPE_ONE;
    if (downward) {
        lineTemplate->nodeAndRepeatType.insert(lineTemplate->nodeAndRepeatType.begin(), nodeAndRepeatType);
    } else {
        lineTemplate->nodeAndRepeatType.push_back(nodeAndRepeatType);
    }
    lineTemplate->encode();
}

void SimpleView::LineInstance::removeRuntimeNode(bool downward) {
    isLineDownOrLineUp = false;
    if (downward) {
        lineTemplate->nodeAndRepeatType.erase(lineTemplate->nodeAndRepeatType.begin());
    } else {
        lineTemplate->nodeAndRepeatType.pop_back();
    }
    lineTemplate->encode();
}

// only execute once for each LineInstance obj
void SimpleView::LineInstance::prepareQuery(std::function<void(int, int, const char*)>* updateAddressable, std::function<void(int, int, const char*)>* updateUnaddressable, SimpleView::ClassScope* classScope) {
    resolve(updateAddressable);
    // declare fa rule for forward and backward line
    findSplitPoint();
    bool findClassThatUseSplitPoint = not isLineDownOrLineUp and not classScope and indexInsideGraph == 0;
    if (findClassThatUseSplitPoint) {
        classScope = getSplitPoint()->runtimeScopeThatUseIt();
        classScope->resolve(updateAddressable);
        classScope->loadRuntime(updateUnaddressable);
    }
    forwardLine = new HalfLineTheFA(this, HalfLineTheFA::HALF_LINE_TYPE_FORWARD);
    backwardLine = new HalfLineTheFA(this, HalfLineTheFA::HALF_LINE_TYPE_BACKWARD);
    forwardLine->declareHalfLineAndFaRules();
    backwardLine->declareHalfLineAndFaRules();

    // declare line term
    auto classScopeTerm = Term::getVar("ClassScope");
    auto lineInstanceValNameTerm = Term::getStr(innerValName);
    Term* splitTerm = Term::getVar("Split");
    Term* outputTermF = Term::getVar("ForwardOutput");
    Term* outputTermB = Term::getVar("BackwardOutput");
    vector<Term*> ruleBody;
    vector<Term*> outputTerm = { Tail::getInstanceByElements({}),Tail::getInstanceByElements({}) };
    if (not forwardLine->isEmpty) {
        ruleBody.push_back(CompoundTerm::getHalfLineTerm(lineInstanceValNameTerm, classScopeTerm, splitTerm, intersectionTerms, outputTermF, false));
        outputTerm[0] = outputTermF;
    }
    if (not backwardLine->isEmpty) {
        ruleBody.push_back(CompoundTerm::getHalfLineTerm(lineInstanceValNameTerm, classScopeTerm, splitTerm, intersectionTerms, outputTermB, true));
        outputTerm[1] = outputTermB;
    }
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getLineTerm(lineInstanceValNameTerm, classScopeTerm, intersectionTerms, Tail::getInstanceByElements(outputTerm)), ruleBody))->toString(true));
}

void SimpleView::LineInstance::onQueryFinished() {
    retractAllLineInstanceRule(0);
    CompoundTerm::retractAllResolveTerm();
    unResolve();
}

void SimpleView::LineInstance::retractAllLineInstanceRule(int intersectionCount) {
    CompoundTerm::retractAllLineTerm(intersectionCount);
    CompoundTerm::retractAllHalfLineTerm(false, intersectionCount);
    CompoundTerm::retractAllHalfLineTerm(true, intersectionCount);
    CompoundTerm::retractAllFaTerm(false, intersectionCount);
    CompoundTerm::retractAllFaTerm(true, intersectionCount);
    CompoundTerm::retractAllFaImplTerm(false, intersectionCount);
    CompoundTerm::retractAllFaImplTerm(true, intersectionCount);
    CompoundTerm::retractAllCacheFaTerm(false, intersectionCount);
    CompoundTerm::retractAllCacheFaTerm(true, intersectionCount);
    CompoundTerm::retractAllFaCacheTerm(false);
    CompoundTerm::retractAllFaCacheTerm(true);
    CompoundTerm::retractAllFaDoneTerm(false);
    CompoundTerm::retractAllFaDoneTerm(true);
    CompoundTerm::retractAllTransitionTerm(false, intersectionCount);
    CompoundTerm::retractAllTransitionTerm(true, intersectionCount);
}

CompoundTerm* SimpleView::LineInstance::getQueryTerm(ClassScope* classScope) {
    if (classScope) {
        return getTerm(Term::getStr(classScope->innerValName), {}, Term::getVar("A"));
    } else {
        return getTerm(Term::getVar("Class"), {}, Term::getVar("A"));
    }
}

vector<Tail*> SimpleView::LineInstance::flatenResult(Term* result) {
    Tail* flatRes = new Tail();
    Tail* towHalfLine = dynamic_cast<Tail*>(result);
    Tail* backwardHalfLine = dynamic_cast<Tail*>(towHalfLine->headElements[1]);
    if (not backwardHalfLine->headElements.empty()) {
        backwardHalfLine->reverse();
        FOR_EACH_ITEM(backwardHalfLine->headElements, flatRes->addElement(item););
    }
    Tail* forwardHalfLine = dynamic_cast<Tail*>(towHalfLine->headElements[0]);
    if (not forwardHalfLine->headElements.empty() and not backwardHalfLine->headElements.empty()) {
        flatRes->headElements.pop_back();
    }
    FOR_EACH_ITEM(forwardHalfLine->headElements, flatRes->addElement(item););
    return { flatRes };
}

CompoundTerm* SimpleView::LineInstance::getTerm(Term* classScopeTerm, const vector<Term*>& intersections, Term* output) {
    return CompoundTerm::getLineTerm(Term::getStr(innerValName), classScopeTerm, intersections, output);
}

SimpleView::HalfLineTheFA::HalfLineTheFA(SimpleView::LineInstance* line, int halfLineType) {
    this->lineInstance = line;
    this->lineTemplate = line->lineTemplate;
    this->halfLineType = halfLineType;
    this->isBackward = halfLineType == HALF_LINE_TYPE_BACKWARD;
    this->splitTerm = Term::getVar("Split");
    this->defaultStyle = lineInstance->defaultStyle;
    this->basicStyle = lineInstance->basicStyle;
}

void SimpleView::HalfLineTheFA::declareHalfLineAndFaRules() {
    makeFa();
    if (isEmpty) {
        return;
    } else {
        declareTransitionRules();
        declareFaRules();
        declareHalfLine();
    }
}

void SimpleView::HalfLineTheFA::makeFa() {
    int charCount = 0;
    string regexContent = lineInstance->splitPoint->getRegex(isBackward, &charCount);
    spdlog::get(ErrorManager::DebugTag)->info("regex: {}", regexContent);
    isEmpty = charCount <= 1;
    if (isEmpty) {
        return;
    }
    string regex = "\\A" + regexContent + "\\z";
    re2::Regexp* re = re2::Regexp::Parse(regex, re2::Regexp::LikePerl, NULL);
    re2::Prog* prog = re->CompileToProg(0);
    int stateCount = 0;
    prog->BuildEntireDFA(re2::Prog::kLongestMatch, [&](const int* next, bool match) {
        if (match) {
            acceptingStates.insert(stateCount);
        }
        for (int b = 0; b < prog->bytemap_range() + 1; b++) {
            int toState = next[b];
            if (toState >= 0) {
                charCodeToStateTransition[b].push_back({ stateCount, toState });
            }
        }
        stateCount++;
        });
    for (const auto& item : ALPHABET_FOR_NODE_ENCODING) {
        int code = prog->bytemap()[item];
        string regexChar;
        regexChar.push_back(item);
        if (code > 0) {
            charToCharCode[regexChar] = code;
            charCodeToChars[code].push_back(regexChar);
        }
    }
}

void SimpleView::HalfLineTheFA::declareHalfLine() {
    for (auto& charCodeAndTransitions : charCodeToStateTransition) {
        if (not charCodeToChars[charCodeAndTransitions.first].empty()) {
            // for each regex char corresponding to this transition code
            for (auto& regexChar : charCodeToChars[charCodeAndTransitions.first]) {
                // for each transition which is enabled by this transition code(regex char)
                for (auto& transition : charCodeAndTransitions.second) {
                    // starting transition
                    if (transition.first == 0) {
                        declareHalfLineI(transition.first, transition.second, regexChar);
                    }
                }
            }
        }
    }
}

// theNextState actually coresponds to the first char, the init state corresponds to nothing, so does the accepting state
void SimpleView::HalfLineTheFA::declareHalfLineI(int initState, int theNextState, string& regexChar) {
    auto lineInstanceValNameTerm = Term::getStr(lineInstance->innerValName);
    auto classScopeTerm = Term::getVar("ClassScope");
    auto initStateTerm = Term::getInt(initState);
    auto nextStateTerm = Term::getInt(theNextState);
    auto regexCharTerm = Term::getStr(regexChar);
    auto outputTerm = Term::getVar("OutputItem");
    auto outputTailTerm = Term::getVar("OutputTail");
    auto nextMethodKeyTerm = Term::getVar("NextMethodKey");
    auto nextKeyTerm = Term::getVar("NextKey");
    auto splitTerm = Tail::getInstanceByElements({ nextMethodKeyTerm, nextKeyTerm });
    auto& intersection = lineInstance->intersectionTerms;
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getHalfLineTerm(
        lineInstanceValNameTerm, classScopeTerm,
        splitTerm,
        intersection,
        Tail::getTailInstance(outputTerm, outputTailTerm), isBackward), {
            CompoundTerm::getTransitionTerm(
                lineInstanceValNameTerm, classScopeTerm,
                initStateTerm,  // 0
                nextStateTerm,  // whatever directed from 0
                regexCharTerm,  // the first char
                Term::getIgnoredVar(), // the current point of init state has no value
                Term::getIgnoredVar(), // the current step of init state has no value
                Term::getIgnoredVar(),
                splitTerm,  // next point = split point or split point = next point
                Tail::getInstanceByElements({}),
                intersection,
                outputTerm, isBackward),
            CompoundTerm::getFaTerm(
                lineInstanceValNameTerm, classScopeTerm,
                nextStateTerm,
                splitTerm,
                Tail::getInstanceByElements({}),
                intersection,
                outputTailTerm,
                Tail::getInstanceByElements({splitTerm}), isBackward),
                // debug purpose
                #ifdef DEBUG_PROLOG
                CompoundTerm::getToFileTerm(Term::getStr("-----------------------------"), Term::getStr("a.txt")),
                CompoundTerm::getToFileTerm(Tail::getTailInstance(outputTerm, outputTailTerm), Term::getStr("a.txt")),
                #endif
        }))->toString(true));
    lineInstanceValNameTerm->returnThisToPool();
    classScopeTerm->returnThisToPool();
    initStateTerm->returnThisToPool();
    nextStateTerm->returnThisToPool();
    regexCharTerm->returnThisToPool();
    outputTerm->returnThisToPool();
    outputTailTerm->returnThisToPool();
    nextMethodKeyTerm->returnThisToPool();
    nextKeyTerm->returnThisToPool();
    splitTerm->returnThisToPool();
}

void SimpleView::HalfLineTheFA::declareFaRules() {
    auto& intersection = lineInstance->intersectionTerms;
    Term* classScopeTerm = Term::getVar("ClassScope");
    Term* lineInstanceValNameTerm = Term::getStr(lineInstance->innerValName);
    Term* acceptingState = Term::getVar("AcceptingState");
    Term* discardedTerm = Term::getIgnoredVar();
    Term* currentStateTerm = Term::getVar("CurrentState");
    Term* nextStateTerm = Term::getVar("NextState");
    Term* currentMethodKeyTerm = Term::getVar("CurrentMethodKey");
    Term* currentKeyTerm = Term::getVar("CurrentKey");
    Term* currentPoint = Tail::getInstanceByElements({ currentMethodKeyTerm, currentKeyTerm });
    Term* currentStepsTerm = Term::getVar("CurrentSteps");
    Term* nextMethodKeyTerm = Term::getVar("NextMethodKey");
    Term* nextKeyTerm = Term::getVar("NextKey");
    Term* nextPoint = Tail::getInstanceByElements({ nextMethodKeyTerm, nextKeyTerm });
    Term* nextStepsTerm = Term::getVar("NextSteps");
    Term* outputItemTerm = Term::getVar("OutputItem");
    Term* outputTailTerm = Term::getVar("OutputTail");
    Term* currentExpectingPoint = Term::getVar("CurrentExpectingPoint");
    Term* nextExpectingPoint = Term::getVar("NextExpectingPoint");
    Term* history = Term::getVar("History");
    Term* faOutput = Term::getVar("FaOutput");
    Term* expectingNextKeyTerm = Term::getVar("ExpectingNextKey");
    Term* flowTerm = NULL;
    // rule 1 end of recursive
    vector<Rule*> rules;
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getFaTerm(
        lineInstanceValNameTerm, classScopeTerm,
        acceptingState,
        discardedTerm,
        discardedTerm,
        intersection,
        Tail::getInstanceByElements({}),
        discardedTerm, isBackward), {
            CompoundTerm::getEndingTransitionTerm(
                lineInstanceValNameTerm, classScopeTerm,
                acceptingState,
                discardedTerm, isBackward) }));

    // rule 2 the recursive
    if (isBackward) {
        flowTerm = CompoundTerm::getDataFlowTerm(currentMethodKeyTerm, expectingNextKeyTerm, currentKeyTerm);
    } else {
        flowTerm = CompoundTerm::getDataFlowTerm(currentMethodKeyTerm, currentKeyTerm, expectingNextKeyTerm);
    }
    // fa impl
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getFaImplTerm(
        lineInstanceValNameTerm, classScopeTerm,
        currentStateTerm,
        currentPoint,
        currentStepsTerm,
        intersection,
        Tail::getTailInstance(outputItemTerm, outputTailTerm),
        history, isBackward), {
            flowTerm,
            CompoundTerm::getTransitionTerm(
                lineInstanceValNameTerm, classScopeTerm,
                currentStateTerm,
                nextStateTerm,
                Term::getIgnoredVar(),
                currentPoint,
                currentStepsTerm,
                expectingNextKeyTerm,
                nextPoint,
                nextStepsTerm,
                intersection,
                outputItemTerm, isBackward),
        // debug purpose
        #ifdef DEBUG_PROLOG
        CompoundTerm::getLengthTerm(history,Term::getVar("L")),
        CompoundTerm::getToFileTerm(Term::getVar("L"), Term::getStr("a.txt")),
        #endif
            DisjunctionTerm::getDisjunctionInstance(
                ConjunctionTerm::getConjunctionInstance({
                    CompoundTerm::getMemberTerm(nextPoint,history),
                    Unification::getUnificationInstance(outputTailTerm,Tail::getInstanceByElements({}))
                }),
                ConjunctionTerm::getConjunctionInstance({
                    NegationTerm::getNegInstance(CompoundTerm::getMemberTerm(nextPoint,history)),
                    CompoundTerm::getFaTerm(
                        lineInstanceValNameTerm, classScopeTerm,
                        nextStateTerm,
                        nextPoint,
                        nextStepsTerm,
                        intersection,
                        outputTailTerm,
                        Tail::getTailInstance(nextPoint, history), isBackward),
                        })
            )
        }));

    // // make cache
    // rules.push_back(Rule::getRuleInstance(CompoundTerm::getCacheFaTerm(
    //     lineInstanceValNameTerm, classScopeTerm,
    //     currentStateTerm,
    //     currentPoint,
    //     currentStepsTerm,
    //     intersection,
    //     faOutput,
    //     history, isBackward), {
    //         CompoundTerm::getFaImplTerm(
    //             lineInstanceValNameTerm, classScopeTerm,
    //             currentStateTerm,
    //             currentPoint,
    //             currentStepsTerm,
    //             intersection,
    //             faOutput,
    //             history, isBackward),
    //         AssertTerm::getAssertInstance(CompoundTerm::getFaCacheTerm(
    //             lineInstanceValNameTerm, classScopeTerm,
    //             currentStateTerm,
    //             currentPoint,
    //             currentStepsTerm,
    //             faOutput,
    //             isBackward)),
    //             #ifdef DEBUG_PROLOG
    //             CompoundTerm::getToFileTerm(
    //                 CompoundTerm::getFaCacheTerm(
    //                 lineInstanceValNameTerm, classScopeTerm,
    //                 currentStateTerm,
    //                 currentPoint,
    //                 currentStepsTerm,
    //                 faOutput,
    //                 isBackward),
    //             Term::getStr("a.txt")),
    //             #endif
    //         Term::getAtom("fail"),
    //     }));

    // // use cache
    // rules.push_back(Rule::getRuleInstance(CompoundTerm::getFaTerm(
    //     lineInstanceValNameTerm, classScopeTerm,
    //     currentStateTerm,
    //     currentPoint,
    //     currentStepsTerm,
    //     intersection,
    //     faOutput,
    //     history, isBackward), { CompoundTerm::getFaCacheTerm(
    //             lineInstanceValNameTerm, classScopeTerm,
    //             currentStateTerm,
    //             currentPoint,
    //             currentStepsTerm,
    //             faOutput,
    //             isBackward)
    //     }));

    // there is no cache, if it is not called parameter nor return, just run the fa
    rules.push_back(Rule::getRuleInstance(CompoundTerm::getFaTerm(
        lineInstanceValNameTerm, classScopeTerm,
        currentStateTerm,
        currentPoint,
        currentStepsTerm,
        intersection,
        faOutput,
        history, isBackward), {
            // // type check
            // NegationTerm::getNegInstance(CompoundTerm::getRuntimeTerm(currentMethodKeyTerm, Term::getIgnoredVar(), currentKeyTerm, Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP))),
            // NegationTerm::getNegInstance(CompoundTerm::getRuntimeTerm(currentMethodKeyTerm, Term::getIgnoredVar(), currentKeyTerm, Term::getInt(GlobalInfo::KEY_TYPE_TIMING_STEP))),
            CompoundTerm::getFaImplTerm(
                lineInstanceValNameTerm, classScopeTerm,
                currentStateTerm,
                currentPoint,
                currentStepsTerm,
                intersection,
                faOutput,
                history, isBackward),
        }));

    // // there is no cache, if it is called parameter or return, make cache and use cache
    // rules.push_back(Rule::getRuleInstance(CompoundTerm::getFaTerm(
    //     lineInstanceValNameTerm, classScopeTerm,
    //     currentStateTerm,
    //     currentPoint,
    //     currentStepsTerm,
    //     intersection,
    //     faOutput,
    //     history, isBackward), {
    //         // type check
    //         DisjunctionTerm::getDisjunctionInstance(
    //             CompoundTerm::getRuntimeTerm(currentMethodKeyTerm, Term::getIgnoredVar(), currentKeyTerm, Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP)),
    //             CompoundTerm::getRuntimeTerm(currentMethodKeyTerm, Term::getIgnoredVar(), currentKeyTerm, Term::getInt(GlobalInfo::KEY_TYPE_TIMING_STEP))
    //         ),
    //             // no cache yet
    //             NegationTerm::getNegInstance(CompoundTerm::getFaDoneTerm(
    //                 lineInstanceValNameTerm, classScopeTerm,
    //                 currentStateTerm,
    //                 currentPoint,
    //                 currentStepsTerm,
    //                 isBackward)),
    //             // mark done
    //         AssertTerm::getAssertInstance(CompoundTerm::getFaDoneTerm(
    //             lineInstanceValNameTerm, classScopeTerm,
    //             currentStateTerm,
    //             currentPoint,
    //             currentStepsTerm,
    //             isBackward)),
    //         #ifdef DEBUG_PROLOG
    //         CompoundTerm::getToFileTerm(CompoundTerm::getFaDoneTerm(
    //             lineInstanceValNameTerm, classScopeTerm,
    //             currentStateTerm,
    //             currentPoint,
    //             currentStepsTerm,
    //             isBackward),
    //             Term::getStr("a.txt")),
    //         #endif
    //             // make cache
    //             NegationTerm::getNegInstance(
    //             CompoundTerm::getCacheFaTerm(
    //                 lineInstanceValNameTerm, classScopeTerm,
    //                 currentStateTerm,
    //                 currentPoint,
    //                 currentStepsTerm,
    //                 intersection,
    //                 faOutput,
    //                 history, isBackward)
    //             ),
    //             // use cache
    //             CompoundTerm::getFaCacheTerm(
    //                 lineInstanceValNameTerm, classScopeTerm,
    //                 currentStateTerm,
    //                 currentPoint,
    //                 currentStepsTerm,
    //                 faOutput,
    //                 isBackward),
    //     }));

    for (auto& rule : rules) {
        PrologWrapper::addRule(rule->toString());
    }
    for (auto& rule : rules) {
        rule->returnThisToPool();
    }
    classScopeTerm->returnThisToPool();
    lineInstanceValNameTerm->returnThisToPool();
    acceptingState->returnThisToPool();
    discardedTerm->returnThisToPool();
    currentStateTerm->returnThisToPool();
    nextStateTerm->returnThisToPool();
    currentMethodKeyTerm->returnThisToPool();
    currentKeyTerm->returnThisToPool();
    currentPoint->returnThisToPool();
    currentStepsTerm->returnThisToPool();
    nextMethodKeyTerm->returnThisToPool();
    nextKeyTerm->returnThisToPool();
    nextPoint->returnThisToPool();
    nextStepsTerm->returnThisToPool();
    outputItemTerm->returnThisToPool();
    outputTailTerm->returnThisToPool();
    currentExpectingPoint->returnThisToPool();
    nextExpectingPoint->returnThisToPool();
    history->returnThisToPool();
    faOutput->returnThisToPool();
    expectingNextKeyTerm->returnThisToPool();
    flowTerm->returnThisToPool();

}

void SimpleView::HalfLineTheFA::declareTransitionRules() {
    // transition code (char code) a can enable a transition from state A to state B
    // for each transition code (char code)
    set<int> endingStates;
    for (auto& charCodeAndTransitions : charCodeToStateTransition) {
        if (not charCodeToChars.count(charCodeAndTransitions.first) or charCodeToChars[charCodeAndTransitions.first].empty()) {
            for (auto& endingTransition : charCodeAndTransitions.second) {
                endingStates.insert(endingTransition.first);
            }
        }
    }
    for (auto& charCodeAndTransitions : charCodeToStateTransition) {
        if (not charCodeToChars[charCodeAndTransitions.first].empty()) {
            // for each regex char corresponding to this transition code
            for (auto& regexChar : charCodeToChars[charCodeAndTransitions.first]) {
                // for each transition which is enabled by this transition code(regex char)
                for (auto& transition : charCodeAndTransitions.second) {
                    if (transition.first == 0) {
                        declareStartingTransitionRuleI(transition.first, transition.second, regexChar);
                    } else {
                        declareTransitionRuleI(transition.first, transition.second, regexChar, endingStates.count(transition.second));
                    }
                }
            }
        } else {
            // if transition code is not corresponding to a char, it means this code enables a transition ending with accepting states
            // ending transition
            for (auto& endingTransition : charCodeAndTransitions.second) {
                PrologWrapper::addFact(CompoundTerm::getEndingTransitionTerm(
                    Term::getStr(lineInstance->innerValName), Term::getVar("ClassScope"),
                    Term::getInt(endingTransition.first),
                    Term::getInt(endingTransition.second),
                    isBackward)->toString(true));
            }
        }
    }
}

// forward line is searched first, so forward line is outputing to split point
// if forward line is empty, then backward is also outputing to split point
void SimpleView::HalfLineTheFA::declareStartingTransitionRuleI(int currentState, int nextState, string& regexChar) {
    Node* node = lineInstance->turnParamNodeToArgNode(lineTemplate->charToNodeTemplate[regexChar.front()]->node);
    Term* lineInstanceValNameTerm = Term::getStr(lineInstance->innerValName);
    Term* classScopeTerm = Term::getVar("ClassScope");
    Term* currentStateTerm = Term::getInt(currentState);
    Term* nextStateTerm = Term::getInt(nextState);
    Term* regexCharTerm = Term::getStr(regexChar);
    Term* nextMethodKeyTerm = Term::getVar("NextMethodKey");
    Term* nextKeyTerm = Term::getVar("NextRuntimeKey");
    Term* nextPoint = Tail::getInstanceByElements({ nextMethodKeyTerm, nextKeyTerm });
    Term* outputAddressableKey = Term::getVar("OutputAddressableKey");
    Term* outputKeyType = Term::getVar("OutputKeyType");
    Term* nodeValNameTerm = Term::getStr(node->innerValName);
    vector<Term*> ruleBody;
    int intersectionIndex = lineInstance->findIntersectionIndexByChar(regexChar[0]);
    bool isIntersection = intersectionIndex > -1;
    bool isSpecifiedIntersection = isIntersection and not lineInstance->intersectionInfoIsFirstPoint[lineInstance->intersectionInfo[intersectionIndex]];
    if (not isBackward or lineInstance->forwardLine->isEmpty) {
        // split point value is not specified
        // outputing to split point is done by HalfLineTerm
        if (isIntersection and isSpecifiedIntersection) {
            // consuming intersection point
            ruleBody.push_back(Unification::getUnificationInstance(lineInstance->intersectionTerms[intersectionIndex], nextPoint));
            ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, outputKeyType));
        } else {
            // no specified value, generate with node val name
            ruleBody.push_back(CompoundTerm::getResolveRuntimeTerm(nodeValNameTerm, classScopeTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType));
        }
    } else {
        // split point value is specified, the consuming(unification) is done by HalfLineTerm
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, outputKeyType));
    }
    // unification with intersetion point if it is one
    if (isIntersection and not isSpecifiedIntersection) {
        ruleBody.push_back(Unification::getUnificationInstance(nextPoint, lineInstance->intersectionTerms[intersectionIndex]));
    }
    ruleBody.push_back(CompoundTerm::getLoadMethodUseAddressableTerm(nextMethodKeyTerm));
    if ((prolog_debug_flags & prolog_debug_flag_transition) != 0) {
        addTimeCountToRuleBody(ruleBody, isBackward ? "backward transition" : "foreward transition");
    }
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getTransitionTerm(
        lineInstanceValNameTerm, classScopeTerm,
        currentStateTerm, nextStateTerm, regexCharTerm, // state transition from init state
        Term::getIgnoredVar(), Term::getIgnoredVar(), // current value
        Term::getIgnoredVar(),
        nextPoint, Tail::getInstanceByElements({}), // next value
        lineInstance->intersectionTerms, // intersections
        getOutputItem(regexCharTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType, Term::getInt(0)), // output
        isBackward), ruleBody))->toString(true));
    lineInstanceValNameTerm->returnThisToPool();
    classScopeTerm->returnThisToPool();
    currentStateTerm->returnThisToPool();
    nextStateTerm->returnThisToPool();
    regexCharTerm->returnThisToPool();
    nextMethodKeyTerm->returnThisToPool();
    nextKeyTerm->returnThisToPool();
    nextPoint->returnThisToPool();
    outputAddressableKey->returnThisToPool();
    outputKeyType->returnThisToPool();
    nodeValNameTerm->returnThisToPool();
}

void SimpleView::HalfLineTheFA::declareTransitionRuleI(int currentState, int nextState, string& regexChar, bool lastTransition) {
    Node* node = lineInstance->turnParamNodeToArgNode(lineTemplate->charToNodeTemplate[regexChar[0]]->node);
    int intersectionIndex = lineInstance->findIntersectionIndexByChar(regexChar[0]);
    bool isIntersection = intersectionIndex > -1;
    auto classScopeTerm = Term::getVar("ClassScope");
    auto lineInstanceValNameTerm = Term::getStr(lineInstance->innerValName);
    auto currentStateTerm = Term::getInt(currentState);
    auto nextStateTerm = Term::getInt(nextState);
    auto regexCharTerm = Term::getStr(regexChar);
    auto nodeValNameTerm = Term::getStr(node->innerValName);

    vector<Term*> ruleBody;
    Term* currentMethodKeyTerm = Term::getVar("CurrentMethodKey");
    Term* currentKeyTerm = Term::getVar("CurrentRuntimeKey");
    Term* currentPoint = Tail::getInstanceByElements({ currentMethodKeyTerm, currentKeyTerm });
    Term* currentStepsTerm = Term::getVar("CurrentSteps");
    Term* nextMethodKeyTerm = Term::getVar("NextMethodKey");
    Term* nextKeyTerm = Term::getVar("NextRuntimeKey");
    Term* nextPoint = Tail::getInstanceByElements({ nextMethodKeyTerm, nextKeyTerm });
    Term* nextStepsTerm = Term::getVar("NextStepsTerm");
    Term* outputAddressableKey = Term::getVar("OutputAddressableKey");
    Term* outputKeyType = Term::getVar("OutputKeyType");
    Term* expectingNextKeyTerm = Term::getVar("ExpectingNextKey");
    int nodeType = node->nodeType;
    bool isStep = nodeType == Node::NODE_TYPE_DATA_STEP or nodeType == Node::NODE_TYPE_TIMING_STEP
        or nodeType == Node::NODE_TYPE_DATA_OVERRIDE or nodeType == Node::NODE_TYPE_TIMING_OVERRIDE;
    int specialKeyType = -1;
    switch (nodeType) {
    case Node::NODE_TYPE_REFERENCE:
        specialKeyType = GlobalInfo::KEY_TYPE_REFERENCE;
        break;
    case Node::NODE_TYPE_CONDITION:
        specialKeyType = GlobalInfo::KEY_TYPE_CONDITION;
        break;
    case Node::NODE_TYPE_ELSE:
        specialKeyType = GlobalInfo::KEY_TYPE_ELSE;
        break;
    case Node::NODE_TYPE_DATA_STEP:
        specialKeyType = GlobalInfo::KEY_TYPE_DATA_STEP;
        break;
    case Node::NODE_TYPE_TIMING_STEP:
        specialKeyType = GlobalInfo::KEY_TYPE_TIMING_STEP;
        break;
    case Node::NODE_TYPE_DATA_OVERRIDE:
        specialKeyType = GlobalInfo::KEY_TYPE_DATA_OVERRIDE;
        break;
    case Node::NODE_TYPE_TIMING_OVERRIDE:
        specialKeyType = GlobalInfo::KEY_TYPE_TIMING_OVERRIDE;
        break;
    case Node::NODE_TYPE_FIELD:
        specialKeyType = GlobalInfo::KEY_TYPE_FIELD;
        break;
    case Node::NODE_TYPE_METHOD:
        specialKeyType = GlobalInfo::KEY_TYPE_METHOD;
        break;
    case Node::NODE_TYPE_CONSTRUCTOR:
        specialKeyType = GlobalInfo::KEY_TYPE_CONSTRUCTOR;
        break;
    case Node::NODE_TYPE_CALLED_METHOD:
        specialKeyType = GlobalInfo::KEY_TYPE_CALLED_METHOD;
        break;
    case Node::NODE_TYPE_PARAMETER:
        specialKeyType = GlobalInfo::KEY_TYPE_METHOD_PARAMETER;
        break;
    case Node::NODE_TYPE_CALLED_PARAMETER:
        specialKeyType = GlobalInfo::KEY_TYPE_CALLED_PARAMETER;
        break;
    case Node::NODE_TYPE_RETURN:
        specialKeyType = GlobalInfo::KEY_TYPE_METHOD_RETURN;
        break;
    case Node::NODE_TYPE_CALLED_RETURN:
        specialKeyType = GlobalInfo::KEY_TYPE_CALLED_RETURN;
        break;
    case Node::NODE_TYPE_INDEX:
        specialKeyType = GlobalInfo::KEY_TYPE_INDEX;
        break;
    }
    // generate nextKeyTerm by dataflow term
    if (isStep) {
        Term* midStepTermRuntime = Term::getVar("MidStepRuntime");
        ruleBody.push_back(Unification::getUnificationInstance(midStepTermRuntime, expectingNextKeyTerm));
        Term* stepAddressable = Term::getVar("StepAddressable");
        // check type
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(currentMethodKeyTerm, stepAddressable, midStepTermRuntime, Term::getInt(specialKeyType)));
        // generate the next method key and next steps
        if (nodeType == Node::NODE_TYPE_DATA_STEP) {
            if (isBackward) {
                ruleBody.push_back(CompoundTerm::getBackwardDataStepTerm(currentMethodKeyTerm, currentKeyTerm, nextMethodKeyTerm, nextKeyTerm, currentStepsTerm, nextStepsTerm));
            } else {
                ruleBody.push_back(CompoundTerm::getForwardDataStepTerm(currentMethodKeyTerm, currentKeyTerm, nextMethodKeyTerm, nextKeyTerm, currentStepsTerm, nextStepsTerm));
            }
        } else if (nodeType == Node::NODE_TYPE_TIMING_STEP) {
            if (isBackward) {
                ruleBody.push_back(CompoundTerm::getBackwardTimingStepTerm(currentMethodKeyTerm, currentKeyTerm, nextMethodKeyTerm, nextKeyTerm, currentStepsTerm, nextStepsTerm));
            } else {
                ruleBody.push_back(CompoundTerm::getForwardTimingStepTerm(currentMethodKeyTerm, currentKeyTerm, nextMethodKeyTerm, nextKeyTerm, currentStepsTerm, nextStepsTerm));
            }
        } else if (nodeType == Node::NODE_TYPE_DATA_OVERRIDE) {
            if (isBackward) {
                ruleBody.push_back(CompoundTerm::getBackwardDataOverrideTerm(currentMethodKeyTerm, currentKeyTerm, nextMethodKeyTerm, nextKeyTerm, currentStepsTerm, nextStepsTerm));
            } else {
                ruleBody.push_back(CompoundTerm::getForwardDataOverrideTerm(currentMethodKeyTerm, currentKeyTerm, nextMethodKeyTerm, nextKeyTerm, currentStepsTerm, nextStepsTerm));
            }
        } else if (nodeType == Node::NODE_TYPE_TIMING_OVERRIDE) {
            if (isBackward) {
                ruleBody.push_back(CompoundTerm::getBackwardTimingOverrideTerm(currentMethodKeyTerm, currentKeyTerm, nextMethodKeyTerm, nextKeyTerm, currentStepsTerm, nextStepsTerm));
            } else {
                ruleBody.push_back(CompoundTerm::getForwardTimingOverrideTerm(currentMethodKeyTerm, currentKeyTerm, nextMethodKeyTerm, nextKeyTerm, currentStepsTerm, nextStepsTerm));
            }
        }

    } else {
        ruleBody.push_back(Unification::getUnificationInstance(nextKeyTerm, expectingNextKeyTerm));
    }
    // value check node type/node inner name and output addressable key and key type
    switch (nodeType) {
    case Node::NODE_TYPE_ANY:
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, outputKeyType));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_REFERENCE))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_CONDITION))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_ELSE))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_DATA_STEP))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_TIMING_STEP))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_DATA_OVERRIDE))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_TIMING_OVERRIDE))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_METHOD))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_CONSTRUCTOR))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_FIELD))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_METHOD_PARAMETER))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_METHOD_RETURN))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_CALLED_METHOD))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_CALLED_PARAMETER))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_CALLED_RETURN))));
        ruleBody.push_back(NegationTerm::getNegInstance(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_INDEX))));
        break;
    case Node::NODE_TYPE_REFERENCE:
    case Node::NODE_TYPE_CONDITION:
    case Node::NODE_TYPE_ELSE:
    case Node::NODE_TYPE_DATA_STEP:
    case Node::NODE_TYPE_TIMING_STEP:
    case Node::NODE_TYPE_DATA_OVERRIDE:
    case Node::NODE_TYPE_TIMING_OVERRIDE:
    case Node::NODE_TYPE_FIELD:
    case Node::NODE_TYPE_METHOD:
    case Node::NODE_TYPE_CONSTRUCTOR:
    case Node::NODE_TYPE_CALLED_METHOD:
    case Node::NODE_TYPE_PARAMETER:
    case Node::NODE_TYPE_CALLED_PARAMETER:
    case Node::NODE_TYPE_RETURN:
    case Node::NODE_TYPE_CALLED_RETURN:
    case Node::NODE_TYPE_INDEX:
        // check by node type
        ruleBody.push_back(Unification::getUnificationInstance(outputKeyType, Term::getInt(specialKeyType)));
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, outputKeyType));
        break;
    default:
        // check by node inner name
        ruleBody.push_back(CompoundTerm::getResolveRuntimeCheckTerm(nodeValNameTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType));
        break;
    }
    if (isIntersection) {
        // output to intersection or checked by intersection
        ruleBody.push_back(Unification::getUnificationInstance(lineInstance->intersectionTerms[intersectionIndex], nextPoint));
    }
    // generate the next method key and next steps
    if (not isStep) {
        ruleBody.push_back(Unification::getUnificationInstance(currentMethodKeyTerm, nextMethodKeyTerm));
        ruleBody.push_back(Unification::getUnificationInstance(currentStepsTerm, nextStepsTerm));
    }
    Term* depth = Term::getVar("Depth");
    ruleBody.push_back(CompoundTerm::getLengthTerm(currentStepsTerm, depth));
    // debug purpose
#ifdef DEBUG_PROLOG
    ruleBody.push_back(CompoundTerm::getToFileTerm(getOutputItem(regexCharTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType, depth), Term::getStr("a.txt")));
#endif
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getTransitionTerm(
        lineInstanceValNameTerm, classScopeTerm,
        currentStateTerm,
        nextStateTerm,
        regexCharTerm,
        currentPoint,
        currentStepsTerm,
        expectingNextKeyTerm,
        nextPoint,
        nextStepsTerm,
        lineInstance->intersectionTerms,
        getOutputItem(regexCharTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType, depth), isBackward
    ), ruleBody))->toString(true));
    currentMethodKeyTerm->returnThisToPool();
    currentKeyTerm->returnThisToPool();
    currentPoint->returnThisToPool();
    currentStepsTerm->returnThisToPool();
    nextMethodKeyTerm->returnThisToPool();
    nextKeyTerm->returnThisToPool();
    nextPoint->returnThisToPool();
    nextStepsTerm->returnThisToPool();
    outputAddressableKey->returnThisToPool();
    outputKeyType->returnThisToPool();
    expectingNextKeyTerm->returnThisToPool();
}

Tail* SimpleView::HalfLineTheFA::getOutputItem(Term* regexCharTerm, Term* nextMethodKeyTerm, Term* nextKeyTerm, Term* outputAddressableKey, Term* keyType, Term* depth) {
    Term* detailedRegexTerm = Term::getStr(regexCharTerm->atomOrVar + ": " + lineTemplate->charToNodeTemplate[regexCharTerm->atomOrVar[0]]->node->displayName);
    return Tail::getInstanceByElements({
        Term::getStr(to_string(lineInstance->indexInsideGraph) + ": " + lineInstance->valName),
        detailedRegexTerm,
        nextMethodKeyTerm,
        nextKeyTerm,
        outputAddressableKey,
        keyType,
        depth });
}

void SimpleView::HalfLineTheFA::printCharToCharCode(const string& regex) {
    string byteMap = regex + " bytemap:\n";
    for (const auto& item : charToCharCode) {
        byteMap += item.first;
        byteMap += " -> " + to_string(item.second);
        byteMap.push_back('\n');
    }
    byteMap += "------------\n";
    for (const auto& item : charCodeToChars) {
        byteMap += to_string(item.first) + " -> ";
        for (const auto& charI : item.second) {
            byteMap += charI;
            byteMap.push_back(' ');
        }
        byteMap.push_back('\n');
    }
    easyPrint(byteMap);
}

SimpleView::GraphInstance* SimpleView::GraphTemplate::getNoneParamInstance() {
    if (not noneParamInstance) {
        noneParamInstance = new GraphInstance(this, {});
        noneParamInstance->valName = valName;
    }
    return noneParamInstance;
}

void SimpleView::GraphTemplate::reorderLineInstance(int i, int j) {
    SWAP_ELEMENT(lineInstances, i, j);
    FOR_EACH_ITEM(intersectionPointsInLine, SWAP_ELEMENT(item, i, j));
}

SimpleView::GraphTemplate::GraphTemplate(const string& valName) {
    this->valName = valName;
}

void SimpleView::GraphTemplate::setDefaultAndBasicStyle(SimpleView::NodeStyle* defaultStyle, SimpleView::BasicStyle* basicStyle) {
    this->defaultStyle = defaultStyle;
    this->basicStyle = basicStyle;
    FOR_EACH_ITEM(lineInstances, item->defaultStyle = defaultStyle;item->basicStyle = basicStyle;);
}

void SimpleView::GraphTemplate::resolve(std::function<void(int, int, const char*)>* updateAddressable) {
    if (resolved) {
        return;
    }
    spdlog::get(ErrorManager::DebugTag)->info("resolve graph template: {}; {}", valName.data(), innerValName.data());
    FOR_EACH_ITEM(lineInstances, item->resolve(updateAddressable););
    resolved = true;
}

void SimpleView::GraphTemplate::unResolve(bool retract) {
    spdlog::get(ErrorManager::DebugTag)->info("unresolve graph template: {}; {}", valName.data(), innerValName.data());
    FOR_EACH_ITEM(lineInstances, item->unResolve(););
    resolved = false;
}

string SimpleView::GraphTemplate::toString(map<int, string>& voc) {
    string ret = "";
    for (int i = 0;i < lineInstances.size();i++) {
        auto& lineIntance = lineInstances[i];
        vector<string> orderedArgNames;
        for (auto& paraName : lineIntance->lineTemplate->orderedParamName) {
            orderedArgNames.push_back(lineIntance->paramNameToArgName[paraName]);
        }
        ret += lineInstances[i]->lineTemplate->name + (orderedArgNames.empty() ? "" : "(" + joinVector(orderedArgNames, ",") + ")");
        ret.push_back(',');
    }
    ret.pop_back();
    for (auto& intersectionPoint : intersectionPointsInLine) {
        vector<string> point;
        for (auto& intersectionPointI : intersectionPoint) {
            point.push_back(intersectionPointI->toString());
        }
        ret += "<" + joinVector(point, ",") + ">";
    }
    return ret;
}

int SimpleView::GraphTemplate::countPointInLineOfIntersection(int intersectionIndex) {
    int count = 0;
    for (auto& pI : intersectionPointsInLine[intersectionIndex]) {
        count += pI->countPointInLineOfIntersection();
    }
    return count;
}

void SimpleView::GraphTemplate::resetLineInstanceArgument(int lineIndex, vector<const char*>& args) {
    for (auto& arg : args) {
        if (not SimpleView::SimpleViewToGraphConverter::valNameToNode.count(arg)) {
            Node* paramNode = new Node();
            paramNode->iconId = Images::parameterIconId;
            paramNode->displayName = arg;
            paramNode->nodeType = Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH;
            paramNode->extraStr = arg;
            SimpleView::SimpleViewToGraphConverter::valNameToNode[arg] = paramNode;
        }
    }
    for (int i = 0;i < args.size();i++) {
        auto& lineInstance = lineInstances[lineIndex];
        lineInstance->paramNameToArgName[lineInstance->lineTemplate->orderedParamName[i]] = args[i];
        lineInstance->updateDisplayName();
    }
    updateOrderedParam();
    updateDisplayName();
}

void SimpleView::GraphTemplate::updateOrderedParam() {
    orderedParamName.clear();
    for (auto& lineInstanceI : lineInstances) {
        for (auto& param : lineInstanceI->lineTemplate->orderedParamName) {
            auto& arg = lineInstanceI->paramNameToArgName[param];
            if (SimpleView::SimpleViewToGraphConverter::valNameToNode[arg]->nodeType == Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH) {
                if (std::find(orderedParamName.begin(), orderedParamName.end(), arg) == orderedParamName.end()) {
                    orderedParamName.push_back(arg);
                }
            }
        }
    }
}

void SimpleView::GraphTemplate::updateDisplayName() {
    displayName = valName + (orderedParamName.empty() ? "" : "(" + joinVector(orderedParamName, ",") + ")");
}

bool SimpleView::GraphTemplate::hasLineAsLineInstance(string& lineName) {
    for (auto& lineInstance : lineInstances) {
        if (strcmp(lineInstance->valName.data(), lineName.data()) == 0) {
            return true;
        }
    }
    return false;
}

bool SimpleView::GraphTemplate::hasNodeAsArgument(Node* node) {
    for (auto& lineInstance : lineInstances) {
        for (auto& paramNameAndArgName : lineInstance->paramNameToArgName) {
            if (strcmp(node->displayName.data(), paramNameAndArgName.second.data()) == 0) {
                return true;
            }
        }
    }
    return false;
}

void SimpleView::GraphTemplate::applyIntersectionEditing() {
    for (auto& intersectionPoint : intersectionPointsInLine) {
        for (auto& pointsInLine : intersectionPoint) {
            pointsInLine->applyEditing();
        }
    }
}

void SimpleView::GraphTemplate::clearIntersectionEditing() {
    for (auto& intersectionPoint : intersectionPointsInLine) {
        for (auto& pointsInLine : intersectionPoint) {
            pointsInLine->clearEditingRecursively();
        }
    }
}

void SimpleView::GraphTemplate::addNewLine(LineTemplate* lineTemplate, int index) {
    vector<string> argumentNames;
    FOR_EACH_ITEM(lineTemplate->orderedParamName, argumentNames.push_back(item););
    auto pLineInstance = new SimpleView::LineInstance(lineTemplate, argumentNames);
    pLineInstance->valName = lineTemplate->name;
    lineInstances.insert(lineInstances.begin() + index, pLineInstance);
    for (auto& intersectionPointsInLineI : intersectionPointsInLine) {
        intersectionPointsInLineI.insert(intersectionPointsInLineI.begin() + index, pLineInstance->lineTemplate->getPointInLine());
    }
    updateOrderedParam();
    updateDisplayName();
}

void SimpleView::GraphTemplate::addNewLine(LineInstance* lineInstance, int index) {
    lineInstances.insert(lineInstances.begin() + index, lineInstance);
    for (auto& intersectionPointsInLineI : intersectionPointsInLine) {
        intersectionPointsInLineI.insert(intersectionPointsInLineI.begin() + index, lineInstance->lineTemplate->getPointInLine());
    }
    updateDisplayName();
}

SimpleView::GraphTemplate* SimpleView::GraphTemplate::copy(const string& name) {
    auto ret = new SimpleView::GraphTemplate(name);
    for (auto& lineInstance : lineInstances) {
        ret->lineInstances.push_back(lineInstance->copy());
    }
    for (auto& pI : intersectionPointsInLine) {
        vector<IntersectionPointInLine*> pIInLine;
        for (auto& pII : pI) {
            pIInLine.push_back(pII->copy());
        }
        ret->intersectionPointsInLine.push_back(pIInLine);
    }
    FOR_EACH_ITEM(orderedParamName, ret->orderedParamName.push_back(item););
    ret->updateDisplayName();
    return ret;
}

void SimpleView::GraphTemplate::swapIntersectionForLineTemplate(const char* lineName, int i, int j) {
    for (auto& intersectionPoint : intersectionPointsInLine) {
        for (int pointInLineIndex = 0;pointInLineIndex < lineInstances.size();pointInLineIndex++) {
            auto& lineInstance = lineInstances[pointInLineIndex];
            auto& pointsInLine = intersectionPoint[pointInLineIndex];
            swapIntersectionForLineTemplateRecursively(lineName, i, j, lineInstance->lineTemplate, pointsInLine);
        }
    }
}

void SimpleView::GraphTemplate::swapIntersectionForLineTemplateRecursively(const char* lineName, int i, int j, LineTemplate* lineTemplate, IntersectionPointInLine* pointsInline) {
    if (strcmp(lineTemplate->name.data(), lineName) == 0) {
        if (not pointsInline->editingItem) {
            pointsInline->editingItem = pointsInline->copy();
        }
        SWAP_ELEMENT(pointsInline->editingItem->seg, i, j);
    } else {
        for (int pointInLineIndex = 0;pointInLineIndex < lineTemplate->nodeAndRepeatType.size();pointInLineIndex++) {
            auto& nodeAndRepeatTypeI = lineTemplate->nodeAndRepeatType[pointInLineIndex];
            auto& pointInline = pointsInline->seg[pointInLineIndex];
            if (nodeAndRepeatTypeI->seg) {
                swapIntersectionForLineTemplateRecursively(lineName, i, j, nodeAndRepeatTypeI->seg, pointInline);
            }
        }
    }
}

void SimpleView::GraphTemplate::insertPointInLineTemplate(const char* lineName, const char* insertedName, bool isInsertedSeg, int i) {
    for (auto& intersectionPoint : intersectionPointsInLine) {
        for (int pointInLineIndex = 0;pointInLineIndex < lineInstances.size();pointInLineIndex++) {
            auto& lineInstance = lineInstances[pointInLineIndex];
            auto& pointsInLine = intersectionPoint[pointInLineIndex];
            insertPointInLineTemplateRecursively(lineName, insertedName, isInsertedSeg, i, lineInstance->lineTemplate, pointsInLine);
        }
    }
}

void SimpleView::GraphTemplate::insertPointInLineTemplateRecursively(const char* lineName, const char* insertedName, bool isInsertedSeg, int i, LineTemplate* lineTemplate, IntersectionPointInLine* pointsInline) {
    if (strcmp(lineTemplate->name.data(), lineName) == 0) {
        if (not pointsInline->editingItem) {
            pointsInline->editingItem = pointsInline->copy();
        }
        IntersectionPointInLine* inserted = NULL;
        if (isInsertedSeg) {
            inserted = SimpleViewToGraphConverter::valNameToLine[insertedName]->getPointInLine();
        } else {
            inserted = new IntersectionPointInLine();
        }
        pointsInline->editingItem->seg.insert(pointsInline->editingItem->seg.begin() + i, inserted);
    } else {
        for (int pointInLineIndex = 0;pointInLineIndex < lineTemplate->nodeAndRepeatType.size();pointInLineIndex++) {
            auto& nodeAndRepeatTypeI = lineTemplate->nodeAndRepeatType[pointInLineIndex];
            auto& pointInline = pointsInline->seg[pointInLineIndex];
            if (nodeAndRepeatTypeI->seg) {
                insertPointInLineTemplateRecursively(lineName, insertedName, isInsertedSeg, i, nodeAndRepeatTypeI->seg, pointInline);
            }
        }
    }
}

bool SimpleView::GraphTemplate::removePointInLineTemplate(const char* lineName, int i) {
    bool ret = true;
    for (auto& intersectionPoint : intersectionPointsInLine) {
        for (int pointInLineIndex = 0;pointInLineIndex < lineInstances.size();pointInLineIndex++) {
            auto& lineInstance = lineInstances[pointInLineIndex];
            auto& pointsInLine = intersectionPoint[pointInLineIndex];
            ret = ret and removePointInLineTemplateRecursively(lineName, i, lineInstance->lineTemplate, pointsInLine);
        }
    }
    return ret;
}

bool SimpleView::GraphTemplate::removePointInLineTemplateRecursively(const char* lineName, int i, LineTemplate* lineTemplate, IntersectionPointInLine* pointsInline) {
    bool ret = true;
    if (strcmp(lineTemplate->name.data(), lineName) == 0) {
        if (not pointsInline->editingItem) {
            pointsInline->editingItem = pointsInline->copy();
        }
        if (pointsInline->editingItem->seg[i]->findIntersection()) {
            return false;
        } else {
            pointsInline->editingItem->seg.erase(pointsInline->editingItem->seg.begin() + i);
        }
    } else {
        for (int pointInLineIndex = 0;pointInLineIndex < lineTemplate->nodeAndRepeatType.size();pointInLineIndex++) {
            auto& nodeAndRepeatTypeI = lineTemplate->nodeAndRepeatType[pointInLineIndex];
            auto& pointInline = pointsInline->seg[pointInLineIndex];
            if (nodeAndRepeatTypeI->seg) {
                ret = ret and removePointInLineTemplateRecursively(lineName, i, nodeAndRepeatTypeI->seg, pointInline);
            }
        }
    }
    return ret;
}

string SimpleView::IntersectionPointInLine::toString() {
    if (isSeg) {
        vector<string> ss;
        FOR_EACH_ITEM(seg, ss.push_back(item->toString()););
        return "[" + joinVector(ss, ",") + "]";
    } else {
        return to_string(isIntersection ? 1 : 0);
    }
}

bool SimpleView::IntersectionPointInLine::findIntersection() {
    if (isSeg) {
        FOR_EACH_ITEM(seg, if (item->findIntersection()) { return true; });
    } else {
        return isIntersection;
    }
    return false;
}

// backwardFlg: 0 for undecided(split position is undecided), 1 for forward, 2 for backward
void SimpleView::IntersectionPointInLine::markSplitByIntersection(RegexTree* splitPoint, int backwardFlg) {
    splitPoint->isSplitPosition = not backwardFlg;
    splitPoint->isBackward = backwardFlg == 2;
    if (isSeg) {
        bool specifiedPointFoundInPrevisous = false;
        for (int i = 0;i < seg.size();i++) {
            int backwardFlgI = 0;//undecided
            // is super structure is specified, be same with super structure
            if (backwardFlg) {
                backwardFlgI = backwardFlg;
            } else {
                // nodes are forward after split point
                if (specifiedPointFoundInPrevisous) {
                    backwardFlgI = 1;// forward
                } else {
                    if (seg[i]->findIntersection()) {
                        backwardFlgI = 0;// undecided, split position is undecided
                        specifiedPointFoundInPrevisous = true;
                    } else {
                        // nodes are backward before split point
                        backwardFlgI = 2;// backward
                    }
                }
            }
            seg[i]->markSplitByIntersection(splitPoint->subStructure[i], backwardFlgI);
        }
    }
}

int SimpleView::IntersectionPointInLine::countPointInLineOfIntersection() {
    int count = 0;
    if (isSeg) {
        for (auto& pI : seg) {
            count += pI->countPointInLineOfIntersection();
        }
    } else {
        if (isIntersection) {
            count++;
        }
    }
    return count;
}

SimpleView::IntersectionPointInLine* SimpleView::IntersectionPointInLine::copy() {
    auto c = new IntersectionPointInLine();
    c->isSeg = isSeg;
    c->isIntersection = isIntersection;
    for (auto& segI : seg) {
        c->seg.push_back(segI->copy());
    }
    return c;
}

/**
 * editingItem will not be set to null after applying editing
 * it will be set to null recursively before editing
*/
void SimpleView::IntersectionPointInLine::applyEditing() {
    if (not editingItem) {
        // this is not to recusively apply editing, this is to recursively find the edited item, then apply edit to the found item
        for (auto& item : seg) {
            item->applyEditing();
        }
        return;
    }
    /**
     * applying editing do not need to be recursive because only one line template edit is allowed at a time
     * and the line template dependency graph is a dag with no loop, so the edited line template will not appear in its sub segments
     * to sum up, there is no mutiple line template editing, and the edited line template will not repeat in hierachical manner
     *
    */
    isSeg = editingItem->isSeg;
    isIntersection = editingItem->isIntersection;
    seg.clear();
    for (auto& item : editingItem->seg) {
        seg.push_back(item);
    }
}

void SimpleView::IntersectionPointInLine::clearEditingRecursively() {
    editingItem = NULL;
    for (auto& item : seg) {
        item->clearEditingRecursively();
    }
}

SimpleView::GraphInstance::GraphInstance(GraphTemplate* templateGraph, const vector<string>& argumentNameForEachParam) {
    this->graphTemplate = templateGraph;
    for (int i = 0;i < argumentNameForEachParam.size();i++) {
        paramNameToArgName[graphTemplate->orderedParamName[i]] = argumentNameForEachParam[i];
    }
}

void SimpleView::GraphInstance::updateDisplayName() {
    vector<string> orderedArgNames;
    for (auto& paraName : graphTemplate->orderedParamName) {
        orderedArgNames.push_back(paramNameToArgName[paraName]);
    }
    displayName = graphTemplate->valName + (orderedArgNames.empty() ? "" : "(" + joinVector(orderedArgNames, ",") + ")");
}

void SimpleView::GraphInstance::prepareQuery(std::function<void(int, int, const char*)>* updateAddressable, std::function<void(int, int, const char*)>* updateUnaddressable, SimpleView::ClassScope* classScope) {
    resolve(updateAddressable);
    // copy line instance from graph template and replace arg of line instance with arg of graph instance
    FOR_EACH_ITEM(graphTemplate->lineInstances, lineInstances.push_back(item->copy()););
    for (auto& lineInstance : lineInstances) {
        for (auto& paramToArg : lineInstance->paramNameToArgName) {
            if (paramNameToArgName.count(paramToArg.second)) {
                paramToArg.second = paramNameToArgName[paramToArg.first];
            }
        }
    }

    // init the "is first point"
    vector<bool> isFirstPointInIntersection;
    for (int i = 0; i < graphTemplate->intersectionPointsInLine.size();i++) {
        isFirstPointInIntersection.push_back(true);
    }
    // set intersection info
    int lineCount = 0;
    for (auto& lineInstance : lineInstances) {
        int intersectionCount = 0;
        for (auto& intersectionInLines : graphTemplate->intersectionPointsInLine) {
            auto& intersection = intersectionInLines[lineCount];
            lineInstance->intersectionInfoIsFirstPoint[intersection] = isFirstPointInIntersection[intersectionCount];
            lineInstance->intersectionInfo.push_back(intersection);
            isFirstPointInIntersection[intersectionCount] = isFirstPointInIntersection[intersectionCount] and not intersection->findIntersection();
            intersectionCount++;
        }
        lineInstance->indexInsideGraph = lineCount;
        lineCount++;
    }
    // declare line rule in prolog
    vector<Term*> intersectionTerms;
    // index starting from 1
    for (int i = 1;i < graphTemplate->intersectionPointsInLine.size() + 1;i++) {
        intersectionTerms.push_back(Term::getVar("Intersection" + to_string(i)));
        intersectionTerms.back()->isInPool = true;
    }
    FOR_EACH_ITEM(lineInstances, item->intersectionTerms = intersectionTerms;);
    FOR_EACH_ITEM(lineInstances, item->prepareQuery(updateAddressable, updateUnaddressable, classScope););

    // declare graph rule in prolog
    auto classScopeTerm = Term::getVar("ClassScope");
    vector<Term*> outputList;
    vector<Term*> ruleBody;
    lineCount = 1;
    for (auto& lineInstance : lineInstances) {
        Term* outputItem = Term::getVar("LineOutput" + to_string(lineCount));
        ruleBody.push_back(lineInstance->getTerm(classScopeTerm, intersectionTerms, outputItem));
        outputList.push_back(outputItem);
        lineCount++;
    }
    PrologWrapper::addRule((Rule::getRuleInstance(getTerm(classScopeTerm, Tail::getInstanceByElements(outputList)), ruleBody))->toString(true));
}

void SimpleView::GraphInstance::onQueryFinished() {
    CompoundTerm::retractAllGraphTerm();
    for (auto& lineInstance : lineInstances) {
        LineInstance::retractAllLineInstanceRule(lineInstance->intersectionTerms.size());
    }
    CompoundTerm::retractAllResolveTerm();
    unResolve();
    lineInstances.clear();
}

void SimpleView::GraphInstance::resolve(std::function<void(int, int, const char*)>* updateAddressable) {
    if (resolved) {
        return;
    }
    spdlog::get(ErrorManager::DebugTag)->info("resolve graph instance: {}; {}", valName.data(), innerValName.data());
    FOR_EACH_ITEM(paramNameToArgName, SimpleViewToGraphConverter::valNameToNode[item.second]->resolve(updateAddressable););
    graphTemplate->resolve(updateAddressable);
    resolved = true;
}

void SimpleView::GraphInstance::unResolve(bool retract) {
    spdlog::get(ErrorManager::DebugTag)->info("unresolve graph instance: {}; {}", valName.data(), innerValName.data());
    FOR_EACH_ITEM(paramNameToArgName, SimpleViewToGraphConverter::valNameToNode[item.second]->unResolve(););
    graphTemplate->unResolve();
    FOR_EACH_ITEM(lineInstances, item->unResolve(retract););
    resolved = false;
}

CompoundTerm* SimpleView::GraphInstance::getQueryTerm(ClassScope* classScope) {
    if (classScope) {
        return getTerm(Term::getStr(classScope->innerValName), Term::getVar("A"));
    } else {
        return getTerm(Term::getVar("Class"), Term::getVar("A"));
    }
}

vector<Tail*> SimpleView::GraphInstance::flatenResult(Term* result) {
    vector<Tail*> ret;
    Tail* lines = dynamic_cast<Tail*>(result);
    for (auto& line : lines->headElements) {
        vector<Tail*> retI = lineInstances[0]->flatenResult(line);
        FOR_EACH_ITEM(retI, ret.push_back(item););
    }
    return ret;
}

CompoundTerm* SimpleView::GraphInstance::getTerm(Term* classScopeValName, Term* output) {
    return CompoundTerm::getGraphTerm(Term::getStr(innerValName), classScopeValName, output);
}

void SimpleView::Searcher::startSearching(ClassScope* classScope, std::function<void(int, int, const char*)>* updateAddressable, std::function<void(int, int, const char*)>* updateUnaddressable) {
    if (classScope) {
        classScope->unResolve();
    }
    onQueryFinished();
    if (classScope) {
        classScope->resolve(updateAddressable);
        classScope->loadRuntime(updateUnaddressable);
    }
    prepareQuery(updateAddressable, updateUnaddressable, classScope);
    plQuerie = PrologWrapper::makeQuery(getQueryTerm(classScope), result, outputIndex);
}

vector<Tail*> SimpleView::Searcher::queryNext(ClassScope* classScope) {
    if (plQuerie) {
        if (plQuerie->next_solution()) {
            PlTerm plT = (*result)[outputIndex];
            return flatenResult(convertPlTermToTerm(&plT));
        }
    }
    return {};
}

void SimpleView::Searcher::endSearching(ClassScope* classScope) {
    if (classScope) {
        classScope->unResolve();
    }
    if (plQuerie) {
        delete plQuerie;
        plQuerie = NULL;
    }
    onQueryFinished();
}
