#include "../util/util.h"
#include "SWI-cpp2.h"
#include "../GraphAttributes.h"
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
    saveVocabulary(lexer, SimpleViewLexer::STEP);
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
                {SimpleView::Node::NODE_TYPE_STEP,Images::stepIconId},
                {SimpleView::Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH,Images::parameterIconId},
                {SimpleView::Node::NODE_TYPE_VAR,Images::varIconId},
    };
    vector<Term*> retList;
    PrologWrapper::queryList(CompoundTerm::getPackageTerm(Term::getVar("A"), Term::getVar("B")), retList);
    int count = retList.size() / 2;
    for (int i = 0;i < count;i++) {
        typeKeyInOrder.push_back(retList[i * 2 + 1]->atomOrVar);
        typeToPackage[retList[i * 2 + 1]->atomOrVar] = retList[i * 2]->atomOrVar;
    }
    typeKeyInOrder.sort();

    PrologWrapper::declareFun(HEAD_RUNTIME_KEY->atomOrVar, 4);
    PrologWrapper::declareFun(HEAD_DATA_FLOW->atomOrVar, 3);
    PrologWrapper::declareFun(HEAD_STEP->atomOrVar, 5);
    PrologWrapper::declareFun(HEAD_RUNTIME_READ->atomOrVar, 3);
    PrologWrapper::declareFun(HEAD_RUNTIME_WRITE->atomOrVar, 3);
    PrologWrapper::declareFun(HEAD_CODE_ORDER->atomOrVar, 3);
    SimpleView::declareClassResolveRules();
    SimpleView::declareNodeResolveRules();

    spdlog::get(ErrorManager::TimerTag)->info("simple init started.");
    std::ifstream stream(FileManager::simpleViewConfig);
    antlr4::ANTLRInputStream inputStream(stream);
    SimpleViewLexer lexer(&inputStream);
    saveVocabulary(lexer);
    SimpleView::Node::NODE_ANY = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_ANY);
    SimpleView::Node::NODE_REFERENCE = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_REFERENCE);
    SimpleView::Node::NODE_CONDITION = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_CONDITION);
    SimpleView::Node::NODE_ELSE = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_ELSE);
    SimpleView::Node::NODE_STEP = SimpleView::Node::getSpecialNode(SimpleView::Node::NODE_TYPE_STEP);

    antlr4::CommonTokenStream tokenStream(&lexer);
    SimpleViewParser parser(&tokenStream);
    SimpleView::SimpleViewErrorListener e;
    parser.removeErrorListeners();
    parser.addErrorListener(&e);
    SimpleView::SimpleViewToGraphConverter visitor;
    parser.compilationUnit()->accept(&visitor);
    spdlog::get(ErrorManager::TimerTag)->info("simple init finished.");
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
        vector<Term*> retList;
        PrologWrapper::queryList(CompoundTerm::getFieldTerm(Term::getStr(classKey), Term::getVar("A")), retList);
        FOR_EACH_ITEM(retList, classToField[classKey].push_back(item->atomOrVar););
    }
    if (not classToMethod.count(classKey)) {
        classToMethod[classKey] = list<string>();
        vector<Term*> retList;
        PrologWrapper::queryList(CompoundTerm::getMethodTerm(Term::getStr(classKey), Term::getVar("A")), retList);
        FOR_EACH_ITEM(retList, classToMethod[classKey].push_back(item->atomOrVar););
        retList.clear();
        PrologWrapper::queryList(CompoundTerm::getConstructorTerm(Term::getStr(classKey), Term::getVar("A")), retList);
        FOR_EACH_ITEM(retList, classToMethod[classKey].push_back(item->atomOrVar););
    }
    if (not classToParameter.count(classKey)) {
        classToParameter[classKey] = list<string>();
        vector<Term*> retList;
        PrologWrapper::queryList(CompoundTerm::getParameterOfClassTerm(Term::getStr(classKey), Term::getVar("A")), retList);
        FOR_EACH_ITEM(retList, classToParameter[classKey].push_back(item->atomOrVar););
    }
    if (not classToReturn.count(classKey)) {
        classToReturn[classKey] = list<string>();
        vector<Term*> retList;
        PrologWrapper::queryList(CompoundTerm::getReturnOfClassTerm(Term::getStr(classKey), Term::getVar("A")), retList);
        FOR_EACH_ITEM(retList, classToReturn[classKey].push_back(item->atomOrVar););
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
    vector<Term*> termListForQuery;
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
            )->toString()
        );
    } else {
        FOR_EACH_ITEM(termListForQuery, resolvedList.insert(item->atomOrVar););
        int c = 0;
        FOR_EACH_ITEM(resolvedList, c++;if (update) (*update)(c, resolvedList.size(), item.data());PrologWrapper::loadTypeKeyAddressable(item););
        if (update) (*update)(resolvedList.size() + 1, resolvedList.size(), "");
        FOR_EACH_ITEM(resolvedList, PrologWrapper::addFact(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getStr(item))->toString()););
    }
    resolved = true;
}

void SimpleView::ClassScope::resolveForRuntime(std::function<void(int, int, const char*)>* update) {
    resolve(update);
    set<string> usedBy;
    for (auto& typeKey : resolvedList) {
        vector<Term*> retList;
        PrologWrapper::queryList(CompoundTerm::getRelatedTypeTerm(Term::getStr(typeKey), Term::getVar("U")), retList);
        for (auto& ret : retList) {
            usedBy.insert(ret->atomOrVar);
        }
    }
    int c = 0;
    FOR_EACH_ITEM(usedBy, c++;if (update) (*update)(c, usedBy.size(), item.data());PrologWrapper::loadTypeKeyAddressable(item););
    if (update) (*update)(usedBy.size() + 1, usedBy.size(), "");
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
            PrologWrapper::retractSingleFact(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getStr(item))->toString());
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
SimpleView::Node* SimpleView::Node::NODE_STEP = NULL;

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
    case Node::NODE_TYPE_STEP:
        node->displayName = EasierSimpleView::vocabularySymbolToLiteral[SimpleViewLexer::STEP];
        node->iconId = Images::stepIconId;
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
    vector<Term*> termListForQuery;
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
            }))->toString());
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
            )->toString()
        );
    } else if (nodeType == NODE_TYPE_RUNTIME) {
        for (auto& runtimeNode : runtimeNodeList) {
            auto resolveRuntime = CompoundTerm::getResolveRuntimeTerm(
                Term::getStr(innerValName), Term::getIgnoredVar(),
                Term::getStr(std::get<0>(runtimeNode)), Term::getStr(std::get<1>(runtimeNode)),
                Term::getStr(std::get<2>(runtimeNode)), Term::getInt(std::get<3>(runtimeNode))
            );
            PrologWrapper::addFact(resolveRuntime->toString());
        }
    } else {
        int c = 0;
        FOR_EACH_ITEM(classToLoad, c++;if (update) (*update)(c, classToLoad.size(), item.data());PrologWrapper::loadTypeKeyAddressable(item););
        if (update) (*update)(classToLoad.size() + 1, classToLoad.size(), "");

        FOR_EACH_ITEM(termListForQuery, resolvedList.insert(item->atomOrVar););
        FOR_EACH_ITEM(resolvedList, PrologWrapper::addFact(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getStr(item))->toString()););
    }
    resolved = true;
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
            PrologWrapper::retractSingleFact(CompoundTerm::getResolveTerm(Term::getStr(innerValName), Term::getStr(item))->toString());
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
    case NODE_TYPE_STEP:
        return voc[SimpleViewLexer::STEP];
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
        and nodeType != NODE_TYPE_PARAM_OF_LINE_AND_GRAPH
        and nodeType != NODE_TYPE_STEP;
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
        FOR_EACH_ITEM(nodeList, values.push_back(item.first.data()););
        break;
    case NODE_TYPE_FIELD_OF:
    case NODE_TYPE_METHOD_OF:
    case NODE_TYPE_CREATOR:
        values.push_back(classScope->displayName.data());
        break;
    case NODE_TYPE_PARAMETER_OF:
    case NODE_TYPE_RETURN_OF:
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
        + voc[SimpleViewLexer::LABEL_DETAIL_LEVEL] + ":" + (labelDetailLevel == LABEL_DETAIL_LEVEL_SIMPLE ? voc[SimpleViewLexer::LABEL_DETAIL_LEVEL_SIMPLE] : voc[SimpleViewLexer::LABEL_DETAIL_LEVEL_FULL]) + "; "
        + voc[SimpleViewLexer::POSITION_Z] + ":" + to_string(positionZ) + ";}";
}

bool SimpleView::NodeAndRepeatType::isParamNode() {
    return node and node->nodeType == Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH;
}

int SimpleView::NodeAndRepeatType::encode(int charIndex, map<char, NodeAndRepeatType*>& charToNode, RegexTree* outputRegex) {
    int currentCharIndex = charIndex;
    if (seg != NULL) {
        for (int i = 0; i < seg->nodeAndRepeatType.size(); ++i) {
            auto* subRegexI = new RegexTree();
            outputRegex->subStructure.push_back(subRegexI);
            currentCharIndex = seg->nodeAndRepeatType[i]->encode(currentCharIndex, charToNode, subRegexI);
        }
    } else {
        char encodeChar = ALPHABET_FOR_NODE_ENCODING[currentCharIndex];
        charToNode[encodeChar] = this;
        outputRegex->encodeChar = encodeChar;
        currentCharIndex++;
    }
    // no matter if it is a segment, it always has a repeat type
    outputRegex->repeatString = getRepeatTypeString();
    return currentCharIndex;
}

string SimpleView::NodeAndRepeatType::getRepeatTypeString() {
    int maxRecurDepth = -1;
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

// todo countResolved:-findall(X,resolved(5,X),L),length(L,N).
int SimpleView::NodeAndRepeatType::countForMin(map<Node*, int> nodeToRuntimeCount, ClassScope* classScope, map<string, string>& paramNameToArgName) {
    if (repeatType != LineTemplate::REPEAT_TYPE_ONE) {
        return INT_MAX;
    }
    if (seg) {
        vector<int> nodeCounts;
        FOR_EACH_ITEM(seg->nodeAndRepeatType, nodeCounts.push_back(item->countForMin(nodeToRuntimeCount, classScope, paramNameToArgName)););
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
                return PrologWrapper::queryCount(CompoundTerm::getCountTerm(CompoundTerm::getResolveRuntimeTerm(
                    Term::getStr(innerName),
                    Term::getStr(classScope->innerValName),
                    Term::getIgnoredVar(),
                    Term::getVar("RuntimeNode"),
                    Term::getIgnoredVar(), Term::getIgnoredVar()), Term::getVar("C")));
            } else {
                return INT_MAX;
            }
        }
    }
}

// backwardFlg: 0 for undecided(split position is undecided), 1 for forward, 2 for backward
void SimpleView::NodeAndRepeatType::markSplitByRuntimeCount(RegexTree* splitPoint, int backwardFlg, ClassScope* classScope, map<string, string>& paramNameToArgName) {
    splitPoint->isSplitPosition = not backwardFlg;
    splitPoint->isBackward = backwardFlg == 2;
    if (seg) {
        if (splitPoint->isSplitPosition) {
            vector<int> nodeCounts;
            map<Node*, int> nodeToRuntimeCount;
            spdlog::get(ErrorManager::TimerTag)->info("start count for min");
            FOR_EACH_ITEM(seg->nodeAndRepeatType, nodeCounts.push_back(item->countForMin(nodeToRuntimeCount, classScope, paramNameToArgName)););
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
                seg->nodeAndRepeatType[i]->markSplitByRuntimeCount(splitPoint->subStructure[i], backwardFlgI, classScope, paramNameToArgName);
            }
        } else {
            for (int i = 0;i < seg->nodeAndRepeatType.size();i++) {
                seg->nodeAndRepeatType[i]->markSplitByRuntimeCount(splitPoint->subStructure[i], backwardFlg, classScope, paramNameToArgName);
            }
        }
    }
}

string SimpleView::RegexTree::getRegex(bool isBackward, int* charCount) {
    string regex;
    if (encodeChar == 0) {
        if (not repeatString.empty()) {
            regex += "(";
        }
        if (isBackward) {
            for (int i = subStructure.size() - 1; i > -1; i--) {
                if (subStructure[i]->isBackward or subStructure[i]->isSplitPosition) {
                    regex += subStructure[i]->getRegex(true, charCount);
                }
            }
        } else {
            for (int i = 0; i < subStructure.size();i++) {
                if (not subStructure[i]->isBackward or subStructure[i]->isSplitPosition) {
                    regex += subStructure[i]->getRegex(false, charCount);
                }
            }
        }
        if (not repeatString.empty()) {
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
    ret->repeatString = repeatString;
    FOR_EACH_ITEM(subStructure, ret->subStructure.push_back(item->copy()););
    ret->isBackward = isBackward;
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
        ret += "->";
    }
    ret.pop_back();
    ret.pop_back();
    return ret;
}

void SimpleView::LineTemplate::encode() {
    int charIndex = 0;
    regexTree = new RegexTree();
    for (int i = 0; i < nodeAndRepeatType.size(); ++i) {
        auto subTree = new RegexTree();
        charIndex = nodeAndRepeatType[i]->encode(charIndex, charToNodeTemplate, subTree);
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
            and nodeAndRepeatTypeI->node != SimpleView::Node::NODE_STEP
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
            if (repeatTypeIsOnce
                and node != SimpleView::Node::NODE_ANY
                and node != SimpleView::Node::NODE_REFERENCE
                and node != SimpleView::Node::NODE_CONDITION
                and node != SimpleView::Node::NODE_ELSE
                and node != SimpleView::Node::NODE_STEP) {
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

bool SimpleView::LineTemplate::resetValue(const char* name, int type, vector<const char*>& values, vector<int>& repeatTypes) {
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

void SimpleView::LineInstance::findSplitPoint(ClassScope* classScope) {
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
    FOR_EACH_ITEM(lineTemplate->nodeAndRepeatType, nodeCounts.push_back(item->countForMin(nodeToRuntimeCount, classScope, paramNameToArgName)););
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
        lineTemplate->nodeAndRepeatType[i]->markSplitByRuntimeCount(splitPoint->subStructure[i], backwardFlgI, classScope, paramNameToArgName);
    }
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

void SimpleView::LineInstance::dispatchOutput(Term* term) {
    Tail* tail = dynamic_cast<Tail*>(term);
    int outputIndex = 0;
    if (forwardLine != nullptr) {
        forwardLine->dispatchOutput(tail->headElements[outputIndex]);
        outputIndex++;
    }
    if (backwardLine != nullptr) {
        backwardLine->dispatchOutput(tail->headElements[outputIndex]);
        outputIndex++;
    }
}

void SimpleView::LineInstance::collectNodeAttrs(list<NodeAttr*>& nodeAttrsWithDup) {
    if (forwardLine != nullptr) {
        forwardLine->collectNodeAttrs(nodeAttrsWithDup);
    }
    if (backwardLine != nullptr) {
        backwardLine->collectNodeAttrs(nodeAttrsWithDup);
    }
}

void SimpleView::LineInstance::addDistinctEdge(vector<NodeAttr*>& nodeAttrs, list<pair<int, int>>& pairGraph) {
    if (forwardLine != nullptr) {
        forwardLine->addDistinctEdge(nodeAttrs, pairGraph);
    }
    if (backwardLine != nullptr) {
        backwardLine->addDistinctEdge(nodeAttrs, pairGraph);
    }
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

void SimpleView::LineInstance::addRuntimeNode(list<tuple<string, string, string, int>>& runtimeNodes, bool downward) {
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
    if (downward) {
        lineTemplate->nodeAndRepeatType.erase(lineTemplate->nodeAndRepeatType.begin());
    } else {
        lineTemplate->nodeAndRepeatType.pop_back();
    }
    lineTemplate->encode();
}

// only execute once for each LineInstance obj
void SimpleView::LineInstance::prepareQuery(ClassScope* classScope, std::function<void(int, int, const char*)>* updateAddressable) {
    resolve(updateAddressable);
    // declare fa rule for forward and backward line
    findSplitPoint(classScope);
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
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getLineTerm(lineInstanceValNameTerm, classScopeTerm, intersectionTerms, Tail::getInstanceByElements(outputTerm)), ruleBody))->toString());
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
    CompoundTerm::retractAllTransitionTerm(false, intersectionCount);
    CompoundTerm::retractAllTransitionTerm(true, intersectionCount);
}

CompoundTerm* SimpleView::LineInstance::getQueryTerm(ClassScope* classScope) {
    return getTerm(Term::getStr(classScope->innerValName), {}, Term::getVar("A"));
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
                splitTerm,  // next point = split point or split point = next point
                Tail::getInstanceByElements({}),
                Term::getIgnoredVar(),
                Term::getIgnoredVar(),
                intersection,
                outputTerm, isBackward),
            CompoundTerm::getFaTerm(
                lineInstanceValNameTerm, classScopeTerm,
                nextStateTerm,
                splitTerm,
                Tail::getInstanceByElements({}),
                Term::getIgnoredVar(),
                intersection,
                outputTailTerm,
                Tail::getInstanceByElements({splitTerm}), isBackward),
                // debug purpose
                #ifdef DEBUG_PROLOG
                CompoundTerm::getToFileTerm(Term::getStr("-----------------------------"), Term::getStr("a.txt")),
                CompoundTerm::getToFileTerm(Tail::getTailInstance(outputTerm, outputTailTerm), Term::getStr("a.txt")),
                #endif
        }))->toString());
}

void SimpleView::HalfLineTheFA::declareFaRules() {
    Term* classScopeTerm = Term::getVar("ClassScope");
    Term* lineInstanceValNameTerm = Term::getStr(lineInstance->innerValName);
    auto& intersection = lineInstance->intersectionTerms;

    // rule 1 end of recursive
    Term* acceptingState = Term::getVar("AcceptingState");
    Term* discardedTerm = Term::getIgnoredVar();
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getFaTerm(
        lineInstanceValNameTerm, classScopeTerm,
        acceptingState,
        discardedTerm,
        discardedTerm,
        discardedTerm,
        intersection,
        Tail::getInstanceByElements({}),
        discardedTerm, isBackward), {
            CompoundTerm::getEndingTransitionTerm(
                lineInstanceValNameTerm, classScopeTerm,
                acceptingState,
                discardedTerm, isBackward) }))->toString());

    // rule 2 the recursive
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
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getFaTerm(
        lineInstanceValNameTerm, classScopeTerm,
        currentStateTerm,
        currentPoint,
        currentStepsTerm,
        currentExpectingPoint,
        intersection,
        Tail::getTailInstance(outputItemTerm, outputTailTerm),
        history, isBackward), {
            CompoundTerm::getTransitionTerm(
                lineInstanceValNameTerm, classScopeTerm,
                currentStateTerm,
                nextStateTerm,
                Term::getIgnoredVar(),
                currentPoint,
                currentStepsTerm,
                nextPoint,
                nextStepsTerm,
                currentExpectingPoint,
                nextExpectingPoint,
                intersection,
                outputItemTerm, isBackward),
                // debug purpose
                #ifdef DEBUG_PROLOG
                CompoundTerm::getLengthTerm(history,Term::getVar("L")),
                CompoundTerm::getToFileTerm(Term::getVar("L"), Term::getStr("a.txt")),
                #endif
                    new NegationTerm(CompoundTerm::getMemberTerm(nextPoint,history)),
                    CompoundTerm::getFaTerm(
                        lineInstanceValNameTerm, classScopeTerm,
                        nextStateTerm,
                        nextPoint,
                        nextStepsTerm,
                        nextExpectingPoint,
                        intersection,
                        outputTailTerm,
                        Tail::getTailInstance(nextPoint, history), isBackward),
        }))->toString());
}

void SimpleView::HalfLineTheFA::declareTransitionRules() {
    // transition code (char code) a can enable a transition from state A to state B
    // for each transition code (char code)
    for (auto& charCodeAndTransitions : charCodeToStateTransition) {
        if (not charCodeToChars[charCodeAndTransitions.first].empty()) {
            // for each regex char corresponding to this transition code
            for (auto& regexChar : charCodeToChars[charCodeAndTransitions.first]) {
                // for each transition which is enabled by this transition code(regex char)
                for (auto& transition : charCodeAndTransitions.second) {
                    if (transition.first == 0) {
                        declareStartingTransitionRuleI(transition.first, transition.second, regexChar);
                    } else {
                        declareTransitionRuleI(transition.first, transition.second, regexChar);
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
                    isBackward)->toString());
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
            ruleBody.push_back(CompoundTerm::getResolveRuntimeTerm(Term::getStr(node->innerValName), classScopeTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType));
        }
    } else {
        // split point value is specified, the consuming(unification) is done by HalfLineTerm
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, outputKeyType));
    }
    // unification with intersetion point if it is one
    if (isIntersection and not isSpecifiedIntersection) {
        ruleBody.push_back(Unification::getUnificationInstance(nextPoint, lineInstance->intersectionTerms[intersectionIndex]));
    }
    if ((prolog_debug_flags & prolog_debug_flag_transition) != 0) {
        addTimeCountToRuleBody(ruleBody, isBackward ? "backward transition" : "foreward transition");
    }
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getTransitionTerm(
        lineInstanceValNameTerm, classScopeTerm,
        currentStateTerm, nextStateTerm, regexCharTerm, // state transition from init state
        Term::getIgnoredVar(), Term::getIgnoredVar(), // current value
        nextPoint, Tail::getInstanceByElements({}), // next value
        Term::getIgnoredVar(),
        Term::getIgnoredVar(),
        lineInstance->intersectionTerms, // intersections
        getOutputItem(regexCharTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType), // output
        isBackward), ruleBody))->toString());
}

// todo add a param to transition rule: expectingNextPoint, generated by step
void SimpleView::HalfLineTheFA::declareTransitionRuleI(int currentState, int nextState, string& regexChar) {
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
    Term* nextExpectingPoint = Term::getVar("NextExpectingPoint");
    Term* outputAddressableKey = Term::getVar("OutputAddressableKey");
    Term* outputKeyType = Term::getVar("OutputKeyType");
    // generate value by dataflow term
    if (isBackward) {
        ruleBody.push_back(CompoundTerm::getDataFlowTerm(currentMethodKeyTerm, nextKeyTerm, currentKeyTerm));
    } else {
        ruleBody.push_back(CompoundTerm::getDataFlowTerm(currentMethodKeyTerm, currentKeyTerm, nextKeyTerm));
    }
    int nodeType = node->nodeType;
    // generate the next method key and next steps
    if (nodeType == Node::NODE_TYPE_STEP) {
        if (isBackward) {
            ruleBody.push_back(CompoundTerm::getStepTerm(nextExpectingPoint, nextKeyTerm, currentPoint, nextStepsTerm, currentStepsTerm));
        } else {
            ruleBody.push_back(CompoundTerm::getStepTerm(currentPoint, nextKeyTerm, nextExpectingPoint, currentStepsTerm, nextStepsTerm));
        }
        ruleBody.push_back(Unification::getUnificationInstance(nextExpectingPoint, Tail::getTailInstance(nextMethodKeyTerm, Term::getIgnoredVar())));
    } else {
        ruleBody.push_back(Unification::getUnificationInstance(currentMethodKeyTerm, nextMethodKeyTerm));
        ruleBody.push_back(Unification::getUnificationInstance(currentStepsTerm, nextStepsTerm));
    }
    // value check node type/node inner name and output addressable key and key type
    switch (nodeType) {
    case Node::NODE_TYPE_ANY:
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, outputKeyType));
        ruleBody.push_back(new NegationTerm(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_REFERENCE))));
        ruleBody.push_back(new NegationTerm(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_CONDITION))));
        ruleBody.push_back(new NegationTerm(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_ELSE))));
        ruleBody.push_back(new NegationTerm(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_STEP))));
        break;
    case Node::NODE_TYPE_REFERENCE:
        ruleBody.push_back(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_REFERENCE)));
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, Term::getInt(GlobalInfo::KEY_TYPE_REFERENCE)));
        break;
    case Node::NODE_TYPE_CONDITION:
        ruleBody.push_back(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_CONDITION)));
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, Term::getInt(GlobalInfo::KEY_TYPE_CONDITION)));
        break;
    case Node::NODE_TYPE_ELSE:
        ruleBody.push_back(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_ELSE)));
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(nextMethodKeyTerm, outputAddressableKey, nextKeyTerm, Term::getInt(GlobalInfo::KEY_TYPE_ELSE)));
        break;
    case Node::NODE_TYPE_STEP:
        // this type node is checked by getStepTerm
        ruleBody.push_back(Unification::getUnificationInstance(outputAddressableKey, nextKeyTerm));
        ruleBody.push_back(Unification::getUnificationInstance(outputKeyType, Term::getInt(GlobalInfo::KEY_TYPE_STEP)));
        break;
    default:
        // check by node inner name
        ruleBody.push_back(CompoundTerm::getResolveRuntimeCheckTerm(nodeValNameTerm, classScopeTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType));
        break;
    }
    if (isIntersection) {
        // output to intersection or checked by intersection
        ruleBody.push_back(Unification::getUnificationInstance(lineInstance->intersectionTerms[intersectionIndex], nextPoint));
    }
    // debug purpose
#ifdef DEBUG_PROLOG
    ruleBody.push_back(CompoundTerm::getToFileTerm(getOutputItem(regexCharTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType), Term::getStr("a.txt")));
#endif
    PrologWrapper::addRule((Rule::getRuleInstance(CompoundTerm::getTransitionTerm(
        lineInstanceValNameTerm, classScopeTerm,
        currentStateTerm,
        nextStateTerm,
        regexCharTerm,
        currentPoint,
        currentStepsTerm,
        nextPoint,
        nextStepsTerm,
        nextPoint,
        nextExpectingPoint,
        lineInstance->intersectionTerms,
        getOutputItem(regexCharTerm, nextMethodKeyTerm, nextKeyTerm, outputAddressableKey, outputKeyType), isBackward
    ), ruleBody))->toString());
}

void SimpleView::HalfLineTheFA::applyStyle(list<NodeAttr*>& nodeAttrs) {
    for (auto* nodeAttr : nodeAttrs) {
        auto* nodeStyle = lineTemplate->charToNodeTemplate[nodeAttr->regexChar.front()]->nodeStyleSpec;
        if (nodeStyle == nullptr) {
            nodeStyle = defaultStyle;
        }
        nodeAttr->nodeColor = nodeStyle->nodeColor;
        nodeAttr->labelColor = nodeStyle->labelColor;
        nodeAttr->nodeSize = nodeStyle->nodeScale * basicStyle->basicNodeSize;
        nodeAttr->labelSize = nodeStyle->labelScale * basicStyle->basicLabelSize;
        nodeAttr->labelDetailLevel = nodeStyle->labelDetailLevel;
    }
}

void SimpleView::HalfLineTheFA::collectNodeAttrs(list<NodeAttr*>& nodeAttrsWithDup) {
    FOR_EACH_ITEM(linesOfNode, for (auto& i : item) nodeAttrsWithDup.push_back(i););
}

void SimpleView::HalfLineTheFA::addDistinctEdge(vector<NodeAttr*>& nodeAttrs, list<pair<int, int>>& pairGraph) {
    for (auto& line : linesOfNode) {
        NodeAttr* previousNode = nullptr;
        for (auto& currentNode : line) {
            if (previousNode != nullptr) {
                int fromId;
                int toId;
                if (isBackward) {
                    fromId = currentNode->nodeId;
                    toId = previousNode->nodeId;
                } else {
                    fromId = previousNode->nodeId;
                    toId = currentNode->nodeId;
                }
                if (not edgeExists(fromId, toId, pairGraph)) {
                    pairGraph.push_back({ fromId, toId });
                }
            }
            previousNode = currentNode;
        }
    }
}

void SimpleView::HalfLineTheFA::dispatchOutput(Term* term) {
    Tail* l = dynamic_cast<Tail*>(term);
    list<NodeAttr*> lineOfNode;
    for (auto* node : l->headElements) {
        lineOfNode.push_back(convertTermToNodeAttr(node));
    }
    applyStyle(lineOfNode);
    linesOfNode.push_back(lineOfNode);
}

Tail* SimpleView::HalfLineTheFA::getOutputItem(Term* regexCharTerm, Term* nextMethodKeyTerm, Term* nextKeyTerm, Term* outputAddressableKey, Term* keyType) {
    Term* detailedRegexTerm = Term::getStr(regexCharTerm->atomOrVar + ": " + lineTemplate->charToNodeTemplate[regexCharTerm->atomOrVar[0]]->node->displayName);
    return Tail::getInstanceByElements({
        Term::getStr(to_string(lineInstance->indexInsideGraph) + ": " + lineInstance->valName),
        detailedRegexTerm,
        nextMethodKeyTerm,
        nextKeyTerm,
        outputAddressableKey,
        keyType });
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

void SimpleView::GraphTemplate::dispatchOutput(Term* term) {
    Tail* tail = dynamic_cast<Tail*>(term);
    for (int i = 0; i < lineInstances.size(); ++i) {
        lineInstances[i]->dispatchOutput(tail->headElements[i]);
    }
}

void SimpleView::GraphTemplate::collectNodeAttrs(list<NodeAttr*>& nodeAttrsWithDup) {
    FOR_EACH_ITEM(lineInstances, item->collectNodeAttrs(nodeAttrsWithDup););
}

void SimpleView::GraphTemplate::addDistinctEdge(vector<NodeAttr*>& nodeAttrs, list<pair<int, int>>& pairGraph) {
    FOR_EACH_ITEM(lineInstances, item->addDistinctEdge(nodeAttrs, pairGraph););
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
        if (strcmp(lineInstance->lineTemplate->name.data(), lineName.data()) == 0) {
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

void SimpleView::GraphInstance::prepareQuery(ClassScope* classScope, std::function<void(int, int, const char*)>* updateAddressable) {
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
        intersectionTerms.push_back(Term::getVar("Intersectin" + to_string(i)));
    }
    FOR_EACH_ITEM(lineInstances, item->intersectionTerms = intersectionTerms;);
    FOR_EACH_ITEM(lineInstances, item->prepareQuery(classScope, updateAddressable););

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
    PrologWrapper::addRule((Rule::getRuleInstance(getTerm(classScopeTerm, Tail::getInstanceByElements(outputList)), ruleBody))->toString());
}

void SimpleView::GraphInstance::onQueryFinished() {
    CompoundTerm::retractAllGraphTerm();
    for (auto& lineInstance : lineInstances) {
        LineInstance::retractAllLineInstanceRule(lineInstance->intersectionTerms.size());
    }
    CompoundTerm::retractAllResolveTerm();
    unResolve();
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
    resolved = false;
}

CompoundTerm* SimpleView::GraphInstance::getQueryTerm(ClassScope* classScope) {
    return getTerm(Term::getStr(classScope->innerValName), Term::getVar("A"));
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
    classScope->unResolve();
    onQueryFinished();
    classScope->resolveForRuntime(updateAddressable);
    classScope->loadRuntime(updateUnaddressable);
    prepareQuery(classScope, updateAddressable);
    plQueries[classScope] = PrologWrapper::makeQuery(getQueryTerm(classScope), result, outputIndex);
}

vector<Tail*> SimpleView::Searcher::queryNext(ClassScope* classScope) {
    if (plQueries.count(classScope)) {
        if (plQueries[classScope]->next_solution()) {
            PlTerm plT = (*result)[outputIndex];
            return flatenResult(convertPlTermToTerm(&plT));
        }
    }
    return {};
}

void SimpleView::Searcher::endSearching(ClassScope* classScope) {
    classScope->unResolve();
    if (plQueries.count(classScope)) {
        delete plQueries[classScope];
        plQueries.erase(classScope);
    }
    onQueryFinished();
}
