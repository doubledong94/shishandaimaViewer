#include "../util/util.h"
#include "../../addressableInfo/GlobalInfo.h"
#include "../GraphAttributes.h"
#include "../file/FileManager.h"
#include "../antlr/syntaxObject/JavaHeaderFile.h"
#include "../addressableInfo/AddressableInfo.h"
#include "../runtime/codestructure/CodeStructure.h"
#include "../runtime/codestructure/Relation.h"
#include "SWI-cpp2.h"
#include "PrologConstructor.h"
#include "../simpleView/SimpleViewLexer.h"
#include "../error/ErrorManager.h"
#include "../simpleView/EasierSimpleView.h"
#include "PrologWrapper.h"
#include "../antlr/syntaxObject/Modifier.h"


void PrologConstructor::init() {
    //    prolog_debug_flags |= prolog_debug_flag_backward_transition;
}

void PrologConstructor::beforeParseAll() {
    addressableMultiFileFunctorName2ArgCount[HEAD_METHOD] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_CONSTRUCTOR] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_PARAMETER] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_RETURN] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_CALLED_METHOD] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_CALLED_PARAMETER] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_CALLED_RETURN] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_FIELD] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_INSTANCE_OF] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_SIMPLE_NAME] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_IS_FINAL] = 1;
}

void PrologConstructor::writeToPrologFile(const string& filePath, list<string>& lines) {
    if (lines.empty()) {
        return;
    }
    ofstream f;
    f.open(filePath);
    for (auto& line : lines) {
        f << line << "\n";
    }
    f.close();
}

void PrologConstructor::savePrologFilePath(map<string, map<string, string>>& filePath2typeKey2FilePath) {
    list<string> addressableLines;
    list<string> unaddressableLines;
    for (auto& typeKey2FilePath : filePath2typeKey2FilePath) {
        for (auto& item : typeKey2FilePath.second) {
            const string& prologFile = FileManager::convertFilePath2PrologFile(item.second);
            addressableLines.push_back(CompoundTerm::getAddressableFileFact(item.first, FileManager::prologAddressableFileDir + prologFile));
            unaddressableLines.push_back(CompoundTerm::getUnaddressableFileFact(item.first, FileManager::prologUnaddressableFileDir + prologFile));
        }
    }
    writeToPrologFile(FileManager::prologGlobalInfo_typeKey2AddressableFilePath, addressableLines);
    writeToPrologFile(FileManager::prologGlobalInfo_typeKey2UnaddressableFilePath, unaddressableLines);
    deleteAllTermInstance();
}

void PrologConstructor::savePrologPackage(map<string, map<string, set<string>>>& filePath2package2TypeKeys) {
    list<string> lines;
    for (auto& package2TypeKeys : filePath2package2TypeKeys) {
        FOR_EACH_EACH_ITEM(package2TypeKeys.second, lines.push_back(CompoundTerm::getPackageFact(item1.first, item2)););
    }
    writeToPrologFile(FileManager::prologGlobalInfo_package2typeKey, lines);
    deleteAllTermInstance();
}

void PrologConstructor::savePrologSubTypes(map<string, map<string, set<string>>>& filePath2typeKey2subTypeKeys) {
    list<string> lines;
    for (auto& typeKey2subTypeKeys : filePath2typeKey2subTypeKeys) {
        for (auto& typeKeyAndsubTypeKeys : typeKey2subTypeKeys.second) {
            FOR_EACH_ITEM(typeKeyAndsubTypeKeys.second, lines.push_back(CompoundTerm::getSubTypeFact(typeKeyAndsubTypeKeys.first, item)););
        }
    }
    writeToPrologFile(FileManager::prologGlobalInfo_typeKey2subTypeKeys, lines);
    deleteAllTermInstance();
}

void PrologConstructor::savePrologRelatedType(map<string, map<string, set<string>>>& filePath2TypeKey2itUseTypeKeys) {
    list<string> lines;
    for (auto& fileAndItem : filePath2TypeKey2itUseTypeKeys) {
        for (auto& item : fileAndItem.second) {
            for (auto& typeKeyItUsed : item.second) {
                lines.push_back(CompoundTerm::getRelatedTypeFact(item.first, typeKeyItUsed));
            }
        }
    }
    writeToPrologFile(FileManager::prologGlobalInfo_typeKey2itUseTypeKeys, lines);
    deleteAllTermInstance();
}

void PrologConstructor::saveAddressableInfo(const string& filePath, const list<TypeInfo*>& typeInfos) {
    list<string> lines;
    FOR_EACH_ITEM(addressableMultiFileFunctorName2ArgCount, lines.push_back(getMultiFileDirective(item.first->toString(), to_string(item.second))););
    for (auto& typeInfo : typeInfos) {
        for (auto& fieldInfo : typeInfo->fieldInfos) {
            string& fieldKey = fieldInfo->fieldKey;
            lines.push_back(CompoundTerm::getFieldFact(typeInfo->typeKey, fieldKey));
            lines.push_back(CompoundTerm::getInstanceOfFact(fieldKey, fieldInfo->typeInfo->typeKey));
            lines.push_back(CompoundTerm::getSimpleNameFact(fieldKey, fieldInfo->name));
            if (Modifier::isFinal(fieldInfo->flag)) {
                lines.push_back(CompoundTerm::getIsFinalFact(fieldKey));
            }
        }
        for (auto& methodInfo : typeInfo->methodInfos) {
            string methodSimpleName = AddressableInfo::makeShortMethodName(methodInfo->name, methodInfo->getParamPartOfKey());
            string& methodKey = methodInfo->methodKey;
            string& returnKey = methodInfo->returnInfo->fieldKey;
            string& calledReturnKey = methodInfo->calledReturnInfo->fieldKey;
            if (methodInfo->isConstructor) {
                lines.push_back(CompoundTerm::getConstructorFact(typeInfo->typeKey, methodKey));
            } else {
                lines.push_back(CompoundTerm::getMethodFact(typeInfo->typeKey, methodKey));
            }
            lines.push_back(CompoundTerm::getCalledMethodFact(methodKey, methodInfo->calledMethodKey));
            lines.push_back(CompoundTerm::getReturnFact(methodKey, returnKey));
            lines.push_back(CompoundTerm::getCalledReturnFact(returnKey, calledReturnKey));
            lines.push_back(CompoundTerm::getInstanceOfFact(returnKey, methodInfo->returnInfo->typeInfo->typeKey));
            lines.push_back(CompoundTerm::getSimpleNameFact(methodKey, methodSimpleName));
            lines.push_back(CompoundTerm::getSimpleNameFact(methodInfo->calledMethodKey, AddressableInfo::makeCalledKey(methodSimpleName)));
            lines.push_back(CompoundTerm::getSimpleNameFact(returnKey, methodInfo->returnInfo->name));
            lines.push_back(CompoundTerm::getSimpleNameFact(calledReturnKey, methodInfo->calledReturnInfo->name));
            for (int paramIndex = 0; paramIndex < methodInfo->parameterInfos.size();paramIndex++) {
                auto& paramInfo = methodInfo->parameterInfos[paramIndex];
                auto& calledParamInfo = methodInfo->calledParamInfos[paramIndex];
                string& paramKey = paramInfo->fieldKey;
                string& calledParamKey = calledParamInfo->fieldKey;
                lines.push_back(CompoundTerm::getParameterFact(methodKey, paramKey));
                lines.push_back(CompoundTerm::getCalledParamFact(paramKey, calledParamKey));
                lines.push_back(CompoundTerm::getSimpleNameFact(paramKey, paramInfo->name));
                lines.push_back(CompoundTerm::getSimpleNameFact(calledParamKey, calledParamInfo->name));
                lines.push_back(CompoundTerm::getInstanceOfFact(paramKey, paramInfo->typeInfo->typeKey));
            }
        }
    }
    lines.sort();
    writeToPrologFile(FileManager::prologAddressableFileDir + FileManager::convertFilePath2PrologFile(filePath), lines);
    deleteAllTermInstance();
}

void PrologConstructor::deleteAllTermInstance() {
    PooledItem<Term>::deleteAll();
    PooledItem<CompoundTerm>::deleteAll();
    PooledItem<Tail>::deleteAll();
    PooledItem<Unification>::deleteAll();
    PooledItem<Rule>::deleteAll();
}

string termToString(const Term* term) {
    return term->toString();
}

string getMultiFileDirective(const string& functorName, const string& arityCount) {
    return ":- multifile " + functorName + "/" + arityCount + ".";
}

MinusTerm::MinusTerm(Term* remainderTerm, Term* minuendTerm, Term* subtrahend) {
    this->remainderTerm = remainderTerm;
    this->minuendTerm = minuendTerm;
    this->subtrahend = subtrahend;
}

string MinusTerm::toString() const {
    return remainderTerm->toString() + " is " + minuendTerm->toString() + " - " + subtrahend->toString();
}


NegationTerm::NegationTerm(Term* t) {
    term = t;
}

string NegationTerm::toString() const {
    return "\\+" + term->toString();
}

Term::Term() {
}

Term::Term(const string& s, int termType) {
    atomOrVar = s;
    this->termType = termType;
}

Term* Term::ignoredVar;

Term* Term::getIgnoredVar() {
    if (not ignoredVar) {
        ignoredVar = new Term("_", Term::TERM_TYPE_VAR);
    }
    return ignoredVar;
}

Term* Term::getInt(int integer) {
    Term* ret = getInstance();
    ret->integer = integer;
    ret->termType = TERM_TYPE_INTEGER;
    return ret;
}

Term* Term::getVar(const string& s) {
    Term* ret = getInstance();
    ret->atomOrVar = s;
    ret->termType = TERM_TYPE_VAR;
    return ret;
}

Term* Term::getStr(const string& s) {
    Term* ret = getInstance();
    ret->atomOrVar = s;
    ret->termType = TERM_TYPE_STRING;
    return ret;
}

Term* Term::getStrByChar(const char& c) {
    Term* ret = getInstance();
    ret->atomOrVar.push_back(c);
    ret->termType = TERM_TYPE_STRING;
    return ret;
}

Term* Term::getAtom(const string& s) {
    Term* ret = getInstance();
    ret->atomOrVar = s;
    ret->termType = TERM_TYPE_ATOM;
    return ret;
}

PlTerm* Term::toPlTerm() {
    if (termType == TERM_TYPE_VAR) {
        return new PlTerm_var();
    } else if (termType == TERM_TYPE_ATOM) {
        return new PlTerm_atom(atomOrVar);
    } else if (termType == TERM_TYPE_STRING) {
        return new PlTerm_string(atomOrVar);
    } else if (termType == TERM_TYPE_INTEGER) {
        return new PlTerm_integer(integer);
    }
    return nullptr;
}

void Term::reset() {
    atomOrVar.clear();
    integer = 0;
    termType = 0;
}

string Term::toString() const {
    if (termType == TERM_TYPE_VAR) {
        return atomOrVar;
    } else if (termType == TERM_TYPE_ATOM) {
        return atomOrVar;
    } else if (termType == TERM_TYPE_STRING) {
        string ret = "\"";
        ret += atomOrVar;
        ret += "\"";
        return ret;
    } else if (termType == TERM_TYPE_INTEGER) {
        return to_string(integer);
    }
    return "";
}

string CompoundTerm::toString() const {
    string ret = head->toString();
    ret.push_back('(');
    ret += joinVector(args, ",", termToString);
    ret.push_back(')');
    return ret;
}

void CompoundTerm::reset() {
    head = nullptr;
    args.clear();
}

CompoundTerm* CompoundTerm::makeTerm(Term* head, Term* arg1) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = head;
    ret->addArg(arg1);
    return ret;
}

CompoundTerm* CompoundTerm::makeTerm(Term* head, Term* arg1, Term* arg2) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = head;
    ret->addArg(arg1);
    ret->addArg(arg2);
    return ret;
}

CompoundTerm* CompoundTerm::makeTerm(Term* head, Term* arg1, Term* arg2, Term* arg3) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = head;
    ret->addArg(arg1);
    ret->addArg(arg2);
    ret->addArg(arg3);
    return ret;
}

CompoundTerm* CompoundTerm::makeTerm(Term* head, Term* arg1, Term* arg2, Term* arg3, Term* arg4) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = head;
    ret->addArg(arg1);
    ret->addArg(arg2);
    ret->addArg(arg3);
    ret->addArg(arg4);
    return ret;
}

CompoundTerm* CompoundTerm::makeTerm(Term* head, Term* arg1, Term* arg2, Term* arg3, Term* arg4, Term* arg5, Term* arg6) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = head;
    ret->addArg(arg1);
    ret->addArg(arg2);
    ret->addArg(arg3);
    ret->addArg(arg4);
    ret->addArg(arg5);
    ret->addArg(arg6);
    return ret;
}

CompoundTerm* CompoundTerm::getDataFlowTerm(Term* mk, Term* src, Term* dst) {
    return makeTerm(HEAD_DATA_FLOW, mk, src, dst);
}

string CompoundTerm::getDataFlowFact(const string& mk, const string& src, const string& dst) {
    string ret = getDataFlowTerm(Term::getStr(mk), Term::getStr(src), Term::getStr(dst))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getCodeOrderTerm(Term* mk, Term* src, Term* dst) {
    return makeTerm(HEAD_CODE_ORDER, mk, src, dst);
}

CompoundTerm* CompoundTerm::getMemberTerm(Term* m, Term* l) {
    return makeTerm(HEAD_MEMBER, m, l);
}

CompoundTerm* CompoundTerm::getLengthTerm(Term* list_, Term* length) {
    return makeTerm(HEAD_LENGTH, list_, length);
}

string CompoundTerm::getCodeOrderFact(const string& mk, const string& src, const string& dst) {
    string ret = getCodeOrderTerm(Term::getStr(mk), Term::getStr(src), Term::getStr(dst))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getRuntimeReadTerm(Term* mk, Term* variable, Term* runtimeReadKey) {
    return makeTerm(HEAD_RUNTIME_READ, mk, variable, runtimeReadKey);
}

string CompoundTerm::getRuntimeReadFact(const string& mk, const string& variable, const string& runtimeReadKey) {
    string ret = getRuntimeReadTerm(Term::getStr(mk), Term::getStr(variable), Term::getStr(runtimeReadKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getRuntimeWriteTerm(Term* mk, Term* variable, Term* runtimeWriteKey) {
    return makeTerm(HEAD_RUNTIME_WRITE, mk, variable, runtimeWriteKey);
}

string CompoundTerm::getRuntimeWriteFact(const string& mk, const string& variable, const string& runtimeWriteKey) {
    string ret = getRuntimeWriteTerm(Term::getStr(mk), Term::getStr(variable), Term::getStr(runtimeWriteKey))->toString();
    ret.push_back('.');
    return ret;
}

string CompoundTerm::getAddressableFileFact(const string& typeKey, const string& filePath) {
    string ret = makeTerm(HEAD_ADDRESSABLE_FILE, Term::getStr(typeKey), Term::getStr(filePath))->toString();
    ret.push_back('.');
    return ret;
}

string CompoundTerm::getUnaddressableFileFact(const string& typeKey, const string& filePath) {
    string ret = makeTerm(HEAD_UNADDRESSABLE_FILE, Term::getStr(typeKey), Term::getStr(filePath))->toString();
    ret.push_back('.');
    return ret;
}

string CompoundTerm::getPackageFact(const string& package, const string& typeKey) {
    string ret = getPackageTerm(Term::getStr(package), Term::getStr(typeKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getPackageTerm(Term* package, Term* typeKey) {
    return makeTerm(HEAD_PACKAGE, package, typeKey);
}

CompoundTerm* CompoundTerm::getSubTypeTerm(Term* typeKey, Term* subTypeKey) {
    return makeTerm(HEAD_SUB_TYPE, typeKey, subTypeKey);
}

string CompoundTerm::getSubTypeFact(const string& typeKey, const string& subTypeKey) {
    string ret = getSubTypeTerm(Term::getStr(typeKey), Term::getStr(subTypeKey))->toString();
    ret.push_back('.');
    return ret;
}

string CompoundTerm::getRelatedTypeFact(const string& typeKey, const string& typeKeyItUsed) {
    string ret = getRelatedTypeTerm(Term::getStr(typeKey), Term::getStr(typeKeyItUsed))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getRelatedTypeTerm(Term* typeKey, Term* typeKeyUsedByFirstParam) {
    return makeTerm(HEAD_RELATED_TYPE, typeKey, typeKeyUsedByFirstParam);
}

string CompoundTerm::getMethodFact(const string& typeKey, const string& methodKey) {
    string ret = getMethodTerm(Term::getStr(typeKey), Term::getStr(methodKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getMethodTerm(Term* typeKey, Term* methodKey) {
    return makeTerm(HEAD_METHOD, typeKey, methodKey);
}

string CompoundTerm::getConstructorFact(const string& typeKey, const string& constructorKey) {
    string ret = getConstructorTerm(Term::getStr(typeKey), Term::getStr(constructorKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getConstructorTerm(Term* typeKey, Term* constructorKey) {
    return makeTerm(HEAD_CONSTRUCTOR, typeKey, constructorKey);
}

string CompoundTerm::getParameterFact(const string& methodKey, const string& parameterKey) {
    string ret = getParameterTerm(Term::getStr(methodKey), Term::getStr(parameterKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getParameterTerm(Term* methodKey, Term* parameterKey) {
    return makeTerm(HEAD_PARAMETER, methodKey, parameterKey);
}

string CompoundTerm::getReturnFact(const string& methodKey, const string& returnKey) {
    string ret = getReturnTerm(Term::getStr(methodKey), Term::getStr(returnKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getReturnTerm(Term* methodKey, Term* returnKey) {
    return makeTerm(HEAD_RETURN, methodKey, returnKey);
}

CompoundTerm* CompoundTerm::getParameterOfClassTerm(Term* classKey, Term* paramter) {
    return makeTerm(HEAD_PARAMETER_OF_CLASS, classKey, paramter);
}

CompoundTerm* CompoundTerm::getReturnOfClassTerm(Term* classKey, Term* returnKey) {
    return makeTerm(HEAD_RETURN_OF_CLASS, classKey, returnKey);
}

string CompoundTerm::getCalledMethodFact(const string& methodKey, const string& calledMethodKey) {
    string ret = getCalledMethodTerm(Term::getStr(methodKey), Term::getStr(calledMethodKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getCalledMethodTerm(Term* methodKey, Term* calledMethodKey) {
    return makeTerm(HEAD_CALLED_METHOD, methodKey, calledMethodKey);
}

CompoundTerm* CompoundTerm::getCalledParamTerm(Term* paramKey, Term* calledParameterKey) {
    return makeTerm(HEAD_CALLED_PARAMETER, paramKey, calledParameterKey);
}

string CompoundTerm::getCalledParamFact(const string& paramKey, const string& calledParameterKey) {
    string ret = getCalledParamTerm(Term::getStr(paramKey), Term::getStr(calledParameterKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getCalledReturnTerm(Term* returnKey, Term* calledReturnKey) {
    return makeTerm(HEAD_CALLED_RETURN, returnKey, calledReturnKey);
}

string CompoundTerm::getCalledReturnFact(const string& returnKey, const string& calledReturnKey) {
    string ret = getCalledReturnTerm(Term::getStr(returnKey), Term::getStr(calledReturnKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getStepTerm(Term* point1, Term* step, Term* point2, Term* setps1, Term* setps2) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_STEP;
    ret->addArg(point1);
    ret->addArg(step);
    ret->addArg(point2);
    ret->addArg(setps1);
    ret->addArg(setps2);
    return ret;
}

CompoundTerm* CompoundTerm::getVarTerm(Term* t) {
    return makeTerm(HEAD_VAR, t);
}

string CompoundTerm::getFieldFact(const string& typeKey, const string& fieldKey) {
    string ret = getFieldTerm(Term::getStr(typeKey), Term::getStr(fieldKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getFieldTerm(Term* typeKey, Term* fieldKey) {
    return makeTerm(HEAD_FIELD, typeKey, fieldKey);
}

string CompoundTerm::getInstanceOfFact(const string& instanceKey, const string& typeKey) {
    string ret = getInstanceOfTerm(Term::getStr(instanceKey), Term::getStr(typeKey))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getInstanceOfTerm(Term* instanceKey, Term* typeKey) {
    return makeTerm(HEAD_INSTANCE_OF, instanceKey, typeKey);
}

CompoundTerm* CompoundTerm::getCalledParamInstanceOfTerm(Term* instanceKey, Term* typeKey) {
    return makeTerm(HEAD_CALLED_PARAMETER_INSTANCE_OF, instanceKey, typeKey);
}

CompoundTerm* CompoundTerm::getCalledReturnInstanceOfTerm(Term* instanceKey, Term* typeKey) {
    return makeTerm(HEAD_CALLED_RETURN_INSTANCE_OF, instanceKey, typeKey);
}

string CompoundTerm::getSimpleNameFact(const string& key, const string& simpleName) {
    string ret = getSimpleNameTerm(Term::getStr(key), Term::getStr(simpleName))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getSimpleNameTerm(Term* key, Term* simpleName) {
    return makeTerm(HEAD_SIMPLE_NAME, key, simpleName);
}

string CompoundTerm::getIsFinalFact(const string& key) {
    string ret = getIsFinalTerm(Term::getStr(key))->toString();
    ret.push_back('.');
    return ret;
}

Term* CompoundTerm::getIsFinalTerm(Term* key) {
    return makeTerm(HEAD_IS_FINAL, key);
}

string CompoundTerm::getRuntimeFact(const string& methodKey, const string& key, const string& runtimeKey, int keyType) {
    string ret = getRuntimeTerm(Term::getStr(methodKey), Term::getStr(key), Term::getStr(runtimeKey), Term::getInt(keyType))->toString();
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getRuntimeTerm(Term* methodKey, Term* key, Term* runtimeKey, Term* keyType) {
    return makeTerm(HEAD_RUNTIME_KEY, methodKey, key, runtimeKey, keyType);
}

CompoundTerm* CompoundTerm::getGraphTerm(Term* graphValName, Term* classScopeValName, Term* output) {
    return makeTerm(HEAD_GRAPH, graphValName, classScopeValName, output);
}

CompoundTerm* CompoundTerm::getCountTerm(Term* term, Term* count) {
    return makeTerm(HEAD_COUNT, term, count);
}

void CompoundTerm::retractAllGraphTerm() {
    PrologWrapper::retractAllFact(HEAD_GRAPH->toString(), 3);
}

CompoundTerm* CompoundTerm::getLineTerm(Term* lineInstanceValName, Term* classScopeValName, const vector<Term*>& intersections, Term* output) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_LINE;
    ret->addArg(lineInstanceValName);
    ret->addArg(classScopeValName);
    FOR_EACH_ITEM(intersections, ret->addArg(item););
    ret->addArg(output);
    return ret;
}

void CompoundTerm::retractAllLineTerm(int intersectionCount) {
    PrologWrapper::retractAllFact(HEAD_LINE->toString(), 3 + intersectionCount);
}

Term* CompoundTerm::getHalfLineTerm(
    Term* lineInstanceValName,
    Term* classScopeValName,
    Term* splitTerm,
    const vector<Term*>& intersections,
    Term* output,
    bool isBackward) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = isBackward ? HEAD_BACKWARD_HALF_LINE : HEAD_FORWARD_HALF_LINE;
    ret->addArg(lineInstanceValName);
    ret->addArg(classScopeValName);
    ret->addArg(splitTerm);
    FOR_EACH_ITEM(intersections, ret->addArg(item););
    ret->addArg(output);
    return ret;
}

void CompoundTerm::retractAllHalfLineTerm(bool isBackward, int intersectionCount) {
    if (isBackward) {
        PrologWrapper::retractAllFact(HEAD_BACKWARD_HALF_LINE->toString(), 4 + intersectionCount);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_HALF_LINE->toString(), 4 + intersectionCount);
    }
}

Term* CompoundTerm::getFaTerm(
    Term* lineInstanceValName,
    Term* classScopeValName,
    Term* currentState,
    Term* currentPoint,
    Term* currentSteps,
    Term* expectingNextPoint,
    const vector<Term*>& intersections,
    Term* output,
    Term* history,
    bool isBackward) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = isBackward ? HEAD_BACKWARD_FA : HEAD_FORWARD_FA;
    ret->addArg(lineInstanceValName);
    ret->addArg(classScopeValName);
    ret->addArg(currentState);
    ret->addArg(currentPoint);
    ret->addArg(currentSteps);
    FOR_EACH_ITEM(intersections, ret->addArg(item););
    ret->addArg(output);
    ret->addArg(history);
    return ret;
}

void CompoundTerm::retractAllFaTerm(bool isBackward, int intersectionCount) {
    if (isBackward) {
        PrologWrapper::retractAllFact(HEAD_BACKWARD_FA->toString(), 7 + intersectionCount);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_FA->toString(), 7 + intersectionCount);
    }
}

Term* CompoundTerm::getTransitionTerm(
    Term* lineInstanceValName,
    Term* classScopeValName,
    Term* currentState,
    Term* nextState,
    Term* regexChar,
    Term* currentPoint,
    Term* currentSteps,
    Term* nextPoint,
    Term* nextSteps,
    Term* currentExpectingPoint,
    Term* nextExpectingPoint,
    const vector<Term*>& intersections,
    Term* outputItem,
    bool isBackward) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = isBackward ? HEAD_BACKWARD_TRANSITION : HEAD_FORWARD_TRANSITION;
    ret->addArg(lineInstanceValName);
    ret->addArg(classScopeValName);
    ret->addArg(currentState);
    ret->addArg(nextState);
    ret->addArg(regexChar);
    ret->addArg(currentPoint);
    ret->addArg(currentSteps);
    ret->addArg(nextPoint);
    ret->addArg(nextSteps);
    FOR_EACH_ITEM(intersections, ret->addArg(item););
    ret->addArg(outputItem);
    return ret;
}

CompoundTerm* CompoundTerm::getEndingTransitionTerm(
    Term* lineInstanceValName,
    Term* classScopeValName,
    Term* currentState, Term* endState,
    bool isBackward) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = isBackward ? HEAD_BACKWARD_ENDING_TRANSITION : HEAD_FORWARD_ENDING_TRANSITION;
    ret->addArg(lineInstanceValName);
    ret->addArg(classScopeValName);
    ret->addArg(currentState);
    ret->addArg(endState);
    return ret;
}

void CompoundTerm::retractAllTransitionTerm(bool isBackward, int intersectionCount) {
    if (isBackward) {
        PrologWrapper::retractAllFact(HEAD_BACKWARD_TRANSITION->toString(), 10 + intersectionCount);
        PrologWrapper::retractAllFact(HEAD_BACKWARD_ENDING_TRANSITION->toString(), 4);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_TRANSITION->toString(), 10 + intersectionCount);
        PrologWrapper::retractAllFact(HEAD_FORWARD_ENDING_TRANSITION->toString(), 4);
    }
}

CompoundTerm* CompoundTerm::getClassScopeUsedBy(Term* typeKey, Term* typeKeyUsedByFirstParam) {
    return makeTerm(HEAD_CLASS_SCOPE_USED_BY, typeKey, typeKeyUsedByFirstParam);
}

CompoundTerm* CompoundTerm::getClassScopeUse(Term* typeKeyUsedBySecondParam, Term* typeKey) {
    return makeTerm(HEAD_CLASS_SCOPE_USE, typeKeyUsedBySecondParam, typeKey);
}

CompoundTerm* CompoundTerm::getClassScopeSuper(Term* typeKey, Term* superTypeKey) {
    return makeTerm(HEAD_CLASS_SCOPE_SUPER, typeKey, superTypeKey);
}

CompoundTerm* CompoundTerm::getClassScopeSub(Term* typeKey, Term* subTypeKey) {
    return makeTerm(HEAD_CLASS_SCOPE_SUB, typeKey, subTypeKey);
}

CompoundTerm* CompoundTerm::getClassScopeUnionTerm(Term* Class1, Term* Class2, Term* UnionClass) {
    return makeTerm(HEAD_CLASS_SCOPE_UNION, Class1, Class2, UnionClass);
}

CompoundTerm* CompoundTerm::getClassScopeIntersectionTerm(Term* Class1, Term* Class2, Term* IntersectClass) {
    return makeTerm(HEAD_CLASS_SCOPE_INTERSECTION, Class1, Class2, IntersectClass);
}

CompoundTerm* CompoundTerm::getClassScopeDifferenceTerm(Term* Class1, Term* Class2, Term* DifferenceClass) {
    return makeTerm(HEAD_CLASS_SCOPE_DIFFERENCE, Class1, Class2, DifferenceClass);
}

CompoundTerm* CompoundTerm::getNodeFieldOfTerm(Term* ClassScopeValName, Term* Field) {
    return makeTerm(HEAD_NODE_FIELD_OF, ClassScopeValName, Field);
}

CompoundTerm* CompoundTerm::getNodeMethodOfTerm(Term* ClassScopeValName, Term* Method) {
    return makeTerm(HEAD_NODE_METHOD_OF, ClassScopeValName, Method);
}

CompoundTerm* CompoundTerm::getNodeConstructorOfTerm(Term* ClassScopeValName, Term* Constructor) {
    return makeTerm(HEAD_NODE_CONSTRUCTOR_OF, ClassScopeValName, Constructor);
}

CompoundTerm* CompoundTerm::getNodeInstanceOf(Term* ClassScopeValName, Term* ClassValName, Term* Instance) {
    return makeTerm(HEAD_NODE_INSTANCE_OF, ClassScopeValName, ClassValName, Instance);
}

CompoundTerm* CompoundTerm::getNodeParameterOf(Term* MethodNodeValName, Term* Param) {
    return makeTerm(HEAD_NODE_PARAMETER_OF, MethodNodeValName, Param);
}

CompoundTerm* CompoundTerm::getNodeReturnOf(Term* MethodNodeValName, Term* Return) {
    return makeTerm(HEAD_NODE_RETURN_OF, MethodNodeValName, Return);
}

CompoundTerm* CompoundTerm::getNodeCalledMethodOf(Term* MethodNodeValName, Term* CalledMethod) {
    return makeTerm(HEAD_NODE_CALLED_METHOD_OF, MethodNodeValName, CalledMethod);
}

CompoundTerm* CompoundTerm::getNodeCalledParameterOf(Term* ParamNodeValName, Term* CalledParam) {
    return makeTerm(HEAD_NODE_CALLED_PARAMETER_OF, ParamNodeValName, CalledParam);
}

CompoundTerm* CompoundTerm::getNodeCalledReturnOf(Term* ReturnNodeValName, Term* CalledReturn) {
    return makeTerm(HEAD_NODE_CALLED_RETURN_OF, ReturnNodeValName, CalledReturn);
}

CompoundTerm* CompoundTerm::getNodeUnion(Term* Node1, Term* Node2, Term* Node) {
    return makeTerm(HEAD_NODE_UNION, Node1, Node2, Node);
}

CompoundTerm* CompoundTerm::getNodeIntersection(Term* Node1, Term* Node2, Term* Node) {
    return makeTerm(HEAD_NODE_INTERSECTION, Node1, Node2, Node);
}

CompoundTerm* CompoundTerm::getNodeDifference(Term* Node1, Term* Node2, Term* Node) {
    return makeTerm(HEAD_NODE_DIFFERENCE, Node1, Node2, Node);
}

CompoundTerm* CompoundTerm::getResolveTerm(Term* valName, Term* key) {
    return makeTerm(HEAD_RESOLVE, valName, key);
}

void CompoundTerm::retractAllResolveTerm() {
    PrologWrapper::retractAllFact(HEAD_RESOLVE->toString(), 2);
}

CompoundTerm* CompoundTerm::getResolveRuntimeTerm(Term* nodeValName, Term* classValName, Term* methodKey, Term* runtimeNode, Term* key, Term* keyType) {
    return makeTerm(HEAD_RESOLVE_RUNTIME, nodeValName, classValName, methodKey, runtimeNode, key, keyType);
}

CompoundTerm* CompoundTerm::getResolveRuntimeCheckTerm(Term* nodeValName, Term* classValName, Term* methodKey, Term* runtimeNode, Term* key, Term* keyType) {
    return makeTerm(HEAD_RESOLVE_RUNTIME_CHECK, nodeValName, classValName, methodKey, runtimeNode, key, keyType);
}

CompoundTerm* CompoundTerm::getPrintTerm(Term* p) {
    return makeTerm(HEAD_PRINT, p);
}

CompoundTerm* CompoundTerm::getToFileTerm(Term* content, Term* fileTerm) {
    return makeTerm(HEAD_TO_FILE, content, fileTerm);
}

CompoundTerm* CompoundTerm::getStatisticsTerm(Term* startOrStop) {
    return makeTerm(HEAD_STATISTICS, Term::getAtom("runtime"), Tail::getTailInstance(startOrStop, Term::getIgnoredVar()));
}

CompoundTerm* CompoundTerm::getIsCalledMethodReturnVoid(Term* MethodScope, Term* CalledMethod) {
    return makeTerm(TERM_IS_CALLED_METHD_RETURN_VOID, MethodScope, CalledMethod);
}

void CompoundTerm::addArg(Term* arg) {
    args.push_back(arg);
}

void CompoundTerm::addVarTermArg() {
    args.push_back(Term::getVar("A" + to_string(args.size() + 1)));
}

CompoundTerm::CompoundTerm() {

}

CompoundTerm::CompoundTerm(const string& head) {
    this->head = Term::getAtom(head);
}

CompoundTerm::CompoundTerm(Term* h) : Term() {
    head = h;
}

PlTerm* CompoundTerm::toPlTerm() {
    PlTermv plTermv(args.size());
    for (int i = 0; i < args.size(); ++i) {
        plTermv[i].unify_term(*args[i]->toPlTerm());
    }
    return new PlCompound(head->toString(), plTermv);
}

Unification::Unification() {

}

Unification::Unification(Term* first, Term* second) {
    firstTerm = first;
    secondTerm = second;
}

Unification* Unification::getUnificationInstance(Term* first, Term* second) {
    auto* ret = PooledItem<Unification>::getInstance();
    ret->firstTerm = first;
    ret->secondTerm = second;
    return ret;
}

string Unification::toString() const {
    string ret = firstTerm->toString();
    ret.push_back('=');
    ret += secondTerm->toString();
    return ret;
}

void Unification::reset() {
    this->firstTerm = nullptr;
    this->secondTerm = nullptr;
}

Tail::Tail() {

}

Tail::Tail(Term* h, Term* tail) {
    headElements.push_back(h);
    this->tail = tail;
}

Tail::Tail(Term* h1, Term* h2, Term* tail) {
    headElements.push_back(h1);
    headElements.push_back(h2);
    this->tail = tail;
}

Tail* Tail::getTailInstance(Term* h, Term* tail) {
    auto* ret = PooledItem<Tail>::getInstance();
    ret->headElements.push_back(h);
    ret->tail = tail;
    return ret;
}

Tail* Tail::getTailInstance(Term* h1, Term* h2, Term* tail) {
    auto* ret = PooledItem<Tail>::getInstance();
    ret->headElements.push_back(h1);
    ret->headElements.push_back(h2);
    ret->tail = tail;
    return ret;
}

Tail* Tail::getInstanceByElements(const vector<Term*>& elements) {
    Tail* ret = PooledItem<Tail>::getInstance();
    FOR_EACH_ITEM(elements, ret->headElements.push_back(item););
    return ret;
}

Tail* Tail::getFaOutputList(Term* regexChar, Term* methodKeyVar, Term* runtimeKeyVar) {
    Tail* ret = PooledItem<Tail>::getInstance();
    ret->addElement(regexChar);
    ret->addElement(methodKeyVar);
    ret->addElement(runtimeKeyVar);
    return ret;
}

Tail* Tail::getCompleteOutputList(Term* regexChar, Term* nodeType, Term* nodeLabel, Term* keyVar, Term* runtimeKeyVar, Term* methodKeyVar, Term* classKeyVar, Term* packageKeyVar) {
    Tail* ret = PooledItem<Tail>::getInstance();
    ret->addElement(regexChar);
    ret->addElement(nodeType);
    ret->addElement(nodeLabel);
    ret->addElement(keyVar);
    ret->addElement(runtimeKeyVar);
    ret->addElement(methodKeyVar);
    ret->addElement(classKeyVar);
    ret->addElement(packageKeyVar);
    return ret;
}

string Tail::toString() const {
    if (tail == nullptr) {
        if (headElements.empty()) {
            return "[]";
        } else {
            return "[" + joinVector(headElements, ",", termToString) + "]";
        }
    } else {
        if (headElements.empty()) {
            easyPrint("error: head elements and tail are all empty");
            return "";
        } else {
            return "[" + joinVector(headElements, ",", termToString) + "|" + tail->toString() + "]";
        }
    }
}

PlTerm* Tail::toPlTerm() {
    PlTerm_var* listVar = new PlTerm_var();
    PlTerm_tail l(*listVar);
    for (auto& headElement : headElements) {
        l.append(*headElement->toPlTerm());
    }
    l.close();
    return listVar;
}

void Tail::addElement(Term* term) {
    headElements.push_back(term);
}

void Tail::reset() {
    this->tail = nullptr;
    this->headElements.clear();
}

void Tail::reverse() {
    std::reverse(headElements.begin(), headElements.end());
}

NodeAttr* convertTermToNodeAttr(Term* term) {
    Tail* nodeInfo = dynamic_cast<Tail*>(term);
    auto* nodeAttr = NodeAttr::getInstance();
    nodeAttr->regexChar = nodeInfo->headElements[NODE_ATTR_INDEX_CHAR]->atomOrVar;
    nodeAttr->nodeType = nodeInfo->headElements[NODE_ATTR_INDEX_NODE_TYPE]->integer;
    nodeAttr->nodeLabel = nodeInfo->headElements[NODE_ATTR_INDEX_NODE_LABEL]->atomOrVar;
    nodeAttr->nodeKey = nodeInfo->headElements[NODE_ATTR_INDEX_NODE_KEY]->atomOrVar;
    nodeAttr->nodeRuntimeKey = nodeInfo->headElements[NODE_ATTR_INDEX_NODE_RUNTIME_KEY]->atomOrVar;
    nodeAttr->methodKey = nodeInfo->headElements[NODE_ATTR_INDEX_METHOD_KEY]->atomOrVar;
    nodeAttr->classKey = nodeInfo->headElements[NODE_ATTR_INDEX_CLASS_KEY]->atomOrVar;
    nodeAttr->packageKey = nodeInfo->headElements[NODE_ATTR_INDEX_PACKAGE]->atomOrVar;
    return nodeAttr;
}

void addTimeCountToRuleBody(vector<Term*>& ruleBody, const string& ruleName) {
    Term* start = Term::getVar("Start");
    Term* stop = Term::getVar("Stop");
    Term* runtime = Term::getVar("Runtime");
    ruleBody.insert(ruleBody.begin(), CompoundTerm::getStatisticsTerm(start));
    ruleBody.insert(ruleBody.begin(), CompoundTerm::getPrintTerm(Term::getStr(ruleName + " start")));
    ruleBody.insert(ruleBody.begin(), TERM_NEXT_LINE);
    ruleBody.push_back(CompoundTerm::getStatisticsTerm(stop));
    ruleBody.push_back(new MinusTerm(runtime, stop, start));
    ruleBody.push_back(TERM_NEXT_LINE);
    ruleBody.push_back(CompoundTerm::getPrintTerm(Term::getStr(ruleName + " stop")));
    ruleBody.push_back(TERM_NEXT_LINE);
    ruleBody.push_back(CompoundTerm::getPrintTerm(Tail::getInstanceByElements({ runtime })));
}

Term* convertPlTermToTerm(PlTerm* plTerm) {
    if (plTerm->is_atom()) {
        return Term::getAtom(plTerm->as_atom().as_string());
    } else if (plTerm->is_string()) {
        return Term::getStr(plTerm->as_string());
    } else if (plTerm->is_integer()) {
        return Term::getInt(plTerm->as_int());
    } else if (plTerm->is_variable()) {
        return Term::getVar("A");
    } else if (plTerm->is_list()) {
        auto* term = PooledItem<Tail>::getInstance();
        PlTerm_tail tail(*plTerm);
        PlTerm_var e;
        while (tail.next(e)) {
            term->addElement(convertPlTermToTerm(&e));
        }
        return term;
    } else if (plTerm->is_compound()) {
        auto* term = PooledItem<CompoundTerm>::getInstance();
        term->head = Term::getAtom((plTerm->name().as_string()));
        for (int i = 1; i <= plTerm->arity(); ++i) {
            PlTerm argTerm = (*plTerm)[i];
            term->addArg(convertPlTermToTerm(&argTerm));
        }
        return term;
    }
    return nullptr;
}

Rule::Rule() {

}

Rule::Rule(Term* head, const vector<Term*>& conditions) {
    this->head = head;
    FOR_EACH_ITEM(conditions, this->conditions.push_back(item););
}

Rule* Rule::getRuleInstance(Term* head, const vector<Term*>& conditions) {
    auto* ret = getInstance();
    ret->head = head;
    FOR_EACH_ITEM(conditions, ret->conditions.push_back(item););
    return ret;
}

void Rule::reset() {
    this->head = nullptr;
    this->conditions.clear();
}

string Rule::toString() const {
    string ret = head->toString();
    ret += ":- (";
    ret += joinVector(conditions, ",", termToString);
    ret.push_back(')');
    return ret;
}

/**
 * used in forward line and backward line
 * in forward line:
 *      steps1 has value, (this shorter steps)
 *      steps2 is varaible, (this longer steps)
 *      outermethod and calledKey has value,
 *      inner method and return term is varialbe,
 * in backward line:
 *      steps1 is varialbe, (this shorter steps)
 *      steps2 has value, (this longer steps)
 *      outermethod and calledKey is varialbe,
 *      inner method and return term has value,
*/
// reorder parameter: outermethod, calledparameter, step, innermethod, parameter
Rule* Rule::getStepInTerm(Term* outerMethod, Term* innerMethod, Term* calledParameterOrCalledMethod, Term* step, Term* parameterOrMethod, bool isParam) {
    Term* runtimeParameterOrMethod = Term::getVar(isParam ? "RuntimeParam" : "RuntimeMethod");
    Term* steps = Term::getVar("Steps");
    Term* calledReturnTerm = Term::getVar("CalledReturn");
    vector<Term*> ruleBody;
    ruleBody.push_back(CompoundTerm::getRuntimeTerm(innerMethod, parameterOrMethod, runtimeParameterOrMethod, Term::getInt(isParam ? GlobalInfo::KEY_TYPE_METHOD_PARAMETER : GlobalInfo::KEY_TYPE_METHOD)));
    if (isParam) {
        Term* calledMethod = Term::getVar("CalledMethod");
        ruleBody.push_back(CompoundTerm::getDataFlowTerm(outerMethod, calledParameterOrCalledMethod, calledMethod));
        ruleBody.push_back(CompoundTerm::getRuntimeTerm(outerMethod, Term::getIgnoredVar(), calledMethod, Term::getInt(GlobalInfo::KEY_TYPE_CALLED_METHOD)));
        ruleBody.push_back(new DisjunctionTerm(
            new ConjunctionTerm({ 
                new NegationTerm(CompoundTerm::getIsCalledMethodReturnVoid(outerMethod, calledMethod)), 
                CompoundTerm::getDataFlowTerm(outerMethod, calledMethod, calledReturnTerm) }),
            new ConjunctionTerm({ 
                CompoundTerm::getIsCalledMethodReturnVoid(outerMethod, calledMethod), 
                Unification::getUnificationInstance(calledReturnTerm, Term::getStr("void")) })
        ));
    } else {
        ruleBody.push_back(new DisjunctionTerm(
            new ConjunctionTerm({ 
                new NegationTerm(CompoundTerm::getIsCalledMethodReturnVoid(outerMethod, calledParameterOrCalledMethod)), 
                CompoundTerm::getDataFlowTerm(outerMethod, calledParameterOrCalledMethod, calledReturnTerm) }),
            new ConjunctionTerm({ 
                CompoundTerm::getIsCalledMethodReturnVoid(outerMethod, calledParameterOrCalledMethod), 
                Unification::getUnificationInstance(calledReturnTerm, Term::getStr("void")) })
        ));
    }
    ruleBody.push_back(new NegationTerm(CompoundTerm::getRuntimeTerm(outerMethod, Term::getIgnoredVar(), calledReturnTerm, Term::getInt(GlobalInfo::KEY_TYPE_STEP))));
    return Rule::getRuleInstance(CompoundTerm::getStepTerm(
        Tail::getInstanceByElements({ outerMethod,calledParameterOrCalledMethod }),
        step,
        Tail::getInstanceByElements({ innerMethod,runtimeParameterOrMethod }),
        steps,
        Tail::getTailInstance(Tail::getInstanceByElements({ outerMethod,calledReturnTerm }), steps)
    ), ruleBody);
}

/**
 * used only in backward line, steps2 has a value and it is empty
*/
Rule* Rule::getStepInTermOutOfSteps(Term* outerMethod, Term* innerMethod, Term* calledParameterOrCalledMethod, Term* step, Term* parameterOrMethod, bool isParam) {
    Term* runtimeParameterOrMethod = Term::getVar("RuntimeParameterOrMethod");
    Term* shorterSteps = Term::getVar("ShorterSteps");
    Term* longerSteps = Term::getVar("LongerSteps");
    return Rule::getRuleInstance(CompoundTerm::getStepTerm(
        Tail::getInstanceByElements({ outerMethod,calledParameterOrCalledMethod }),
        step,
        Tail::getInstanceByElements({ innerMethod,runtimeParameterOrMethod }),
        shorterSteps,
        longerSteps
    ), {
        new NegationTerm(CompoundTerm::getVarTerm(longerSteps)),
        Unification::getUnificationInstance(longerSteps, Tail::getInstanceByElements({})),
        CompoundTerm::getRuntimeTerm(innerMethod, parameterOrMethod, runtimeParameterOrMethod,Term::getInt(isParam ? GlobalInfo::KEY_TYPE_METHOD_PARAMETER : GlobalInfo::KEY_TYPE_METHOD)),
        Unification::getUnificationInstance(shorterSteps, Tail::getInstanceByElements({}))
        });
}

/**
 * used in forward line and backward line
 * in forward line:
 *      steps1 has value, not empty, (this longer steps)
 *      steps2 is varaible, (this shorter steps)
 *      inner method and return term has value,
 *      outermethod and calledReturn is varialbe,
 * in backward line:
 *      steps1 is varialbe, (this longer steps)
 *      steps2 has value, maybe empty, (this shorter steps)
 *      inner method and return term is varialbe,
 *      outermethod and calledReturn has value,
*/
//todo reorder paremter: innermethod, return, step, outermethod, called return
Rule* Rule::getStepOutTerm(Term* innerMethod, Term* outerMethod, Term* returnTerm, Term* step, Term* calledReturn) {
    Term* runtimeReturn = Term::getVar("RuntimeReturn");
    Term* steps = Term::getVar("Steps");
    Term* point2 = Tail::getInstanceByElements({ outerMethod,calledReturn });
    return Rule::getRuleInstance(CompoundTerm::getStepTerm(
        Tail::getInstanceByElements({ innerMethod,runtimeReturn }),
        step,
        point2,
        Tail::getTailInstance(point2, steps),
        steps
    ), {
        CompoundTerm::getRuntimeTerm(innerMethod, returnTerm, runtimeReturn,Term::getInt(GlobalInfo::KEY_TYPE_METHOD_RETURN))
        });
}

/**
 * used only in forward line, steps1 has a value and it is empty
*/
Rule* Rule::getStepOutTermOutOfSteps(Term* innerMethod, Term* outerMethod, Term* returnTerm, Term* step, Term* calledReturn) {
    Term* runtimeReturn = Term::getVar("Runtime");
    Term* shorterSteps = Term::getVar("ShorterSteps");
    Term* longerSteps = Term::getVar("LongerSteps");
    return Rule::getRuleInstance(CompoundTerm::getStepTerm(
        Tail::getInstanceByElements({ innerMethod,runtimeReturn }),
        step,
        Tail::getInstanceByElements({ outerMethod,calledReturn }),
        longerSteps,
        shorterSteps
    ), {
        // the LongerSteps has a value, because this predicate is used in a forward line
        // backward line will not use this predicate
        new NegationTerm(CompoundTerm::getVarTerm(longerSteps)),
        Unification::getUnificationInstance(longerSteps, Tail::getInstanceByElements({})),
        CompoundTerm::getRuntimeTerm(innerMethod, returnTerm, runtimeReturn,Term::getInt(GlobalInfo::KEY_TYPE_METHOD_RETURN)),
        Unification::getUnificationInstance(shorterSteps, Tail::getInstanceByElements({}))
        });
}

string Rule::getStepInRule(const string& outerMethod, const string& innerMethod, const string& calledParameterOrCalledMethod, const string& step, const string& parameterOrMethod, bool isParam) {
    return getStepInTerm(Term::getStr(outerMethod), Term::getStr(innerMethod), Term::getStr(calledParameterOrCalledMethod), Term::getStr(step), Term::getStr(parameterOrMethod), isParam)->toString() + ".";
}

string Rule::getStepInRuleOutOfSteps(const string& outerMethod, const string& innerMethod, const string& calledParameterOrCalledMethod, const string& step, const string& parameterOrMethod, bool isParam) {
    return getStepInTermOutOfSteps(Term::getStr(outerMethod), Term::getStr(innerMethod), Term::getStr(calledParameterOrCalledMethod), Term::getStr(step), Term::getStr(parameterOrMethod), isParam)->toString() + ".";
}

string Rule::getStepOutRule(const string& innerMethod, const string& outerMethod, const string& returnTerm, const string& step, const string& calledReturn) {
    return getStepOutTerm(Term::getStr(innerMethod), Term::getStr(outerMethod), Term::getStr(returnTerm), Term::getStr(step), Term::getStr(calledReturn))->toString() + ".";
}

string Rule::getStepOutRuleOutOfSteps(const string& innerMethod, const string& outerMethod, const string& returnTerm, const string& step, const string& calledReturn) {
    return getStepOutTermOutOfSteps(Term::getStr(innerMethod), Term::getStr(outerMethod), Term::getStr(returnTerm), Term::getStr(step), Term::getStr(calledReturn))->toString() + ".";
}

DisjunctionTerm::DisjunctionTerm(Term* t1, Term* t2) {
    term1 = t1;
    term2 = t2;
}

string DisjunctionTerm::toString() const {
    return "(" + term1->toString() + "; " + term2->toString() + ")";
}

ConjunctionTerm::ConjunctionTerm(const vector<Term*>& terms) {
    FOR_EACH_ITEM(terms, this->terms.push_back(item););
}

string ConjunctionTerm::toString() const {
    string ret = "(";
    ret += joinVector(terms, ",", termToString);
    ret.push_back(')');
    return ret;
}
