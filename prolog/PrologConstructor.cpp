#include "../util/util.h"
#include "../../addressableInfo/GlobalInfo.h"
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

void PrologConstructor::saveAddressableInfo(const string& filePath, const list<TypeInfo*>& typeInfos) {
    list<string> lines;
    map<Term*, int> addressableMultiFileFunctorName2ArgCount;
    addressableMultiFileFunctorName2ArgCount[HEAD_METHOD] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_CONSTRUCTOR] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_PARAMETER] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_RETURN] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_FIELD] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_STEP_KEY] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_OVERRIDE_KEY] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_INSTANCE_OF] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_SIMPLE_NAME] = 2;
    addressableMultiFileFunctorName2ArgCount[HEAD_IS_FINAL] = 1;
    FOR_EACH_ITEM(addressableMultiFileFunctorName2ArgCount, lines.push_back(getMultiFileDirective(item.first->toString(), to_string(item.second))););
    for (auto& typeInfo : typeInfos) {
        for (auto& fieldInfo : typeInfo->fieldInfos) {
            string& fieldKey = fieldInfo->fieldKey;
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
            }
            lines.push_back(CompoundTerm::getReturnFact(methodKey, returnKey));
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
                lines.push_back(CompoundTerm::getSimpleNameFact(paramKey, paramInfo->name));
                lines.push_back(CompoundTerm::getSimpleNameFact(calledParamKey, calledParamInfo->name));
                lines.push_back(CompoundTerm::getInstanceOfFact(paramKey, paramInfo->typeInfo->typeKey));
            }
        }
    }
    lines.sort();
    writeToPrologFile(FileManager::prologAddressableFileDir + FileManager::convertFilePath2PrologFile(filePath), lines);
}

string termToString(Term* term) {
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

string MinusTerm::toString(bool returnToPool) {
    return remainderTerm->toString() + " is " + minuendTerm->toString() + " - " + subtrahend->toString();
}


NegationTerm* NegationTerm::getNegInstance(Term* t) {
    NegationTerm* ret = PooledItem<NegationTerm>::getInstance();
    ret->term = t;
    return ret;
}

void NegationTerm::reset() {
    term = NULL;
}

string NegationTerm::toString(bool returnToPool) {
    return "\\+(" + term->toString() + ")";
}

Term::Term() {
}

Term::Term(const string& s, int termType) {
    atomOrVar = s;
    this->termType = termType;
}

Term* Term::getIgnoredVar() {
    return Term::getVar("_");
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

void Term::returnThisToPool() {
    PooledItem<Term>::returnToPool(this);
}

void Term::reset() {
    atomOrVar.clear();
    integer = 0;
    termType = 0;
}

string Term::toString(bool returnToPool) {
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

string CompoundTerm::toString(bool returnToPool) {
    string ret = head->toString();
    ret.push_back('(');
    ret += joinVector(args, ",", termToString);
    ret.push_back(')');
    if (returnToPool) {
        returnThisToPool();
    }
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

CompoundTerm* CompoundTerm::makeTerm(Term* head, Term* arg1, Term* arg2, Term* arg3, Term* arg4, Term* arg5) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = head;
    ret->addArg(arg1);
    ret->addArg(arg2);
    ret->addArg(arg3);
    ret->addArg(arg4);
    ret->addArg(arg5);
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

CompoundTerm* CompoundTerm::getClassThatUseMethodAndFieldTerm(Term* methodOrField, Term* classKey) {
    return makeTerm(HEAD_CLASS_THAT_USE_METHOD_AND_FIELD, methodOrField, classKey);
}

CompoundTerm* CompoundTerm::getLoadStepInRuntimeTerm(Term* addressable) {
    return makeTerm(HEAD_LOAD_STEP_IN_RUNTIME, addressable);
}

CompoundTerm* CompoundTerm::getLoadOverrideInRuntimeTerm(Term* addressable) {
    return makeTerm(HEAD_LOAD_OVERRIDE_IN_RUNTIME, addressable);
}

CompoundTerm* CompoundTerm::getCalledKeyTerm(Term* key, Term* calledKey) {
    return makeTerm(HEAD_CALLED_KEY, key, calledKey);
}

CompoundTerm* CompoundTerm::getLoadMethodUseAddressableTerm(Term* method) {
    return makeTerm(HEAD_LOAD_METHOD_USE_ADDRESSABLE, method);
}

CompoundTerm* CompoundTerm::getLoadUseMethodRuntimeTerm(Term* method) {
    return makeTerm(HEAD_LOAD_USE_METHOD_RUNTIME, method);
}

CompoundTerm* CompoundTerm::getLoadUseOverrideMethodRuntimeTerm(Term* method) {
    return makeTerm(HEAD_LOAD_USE_OVERRIDE_METHOD_RUNTIME, method);
}

CompoundTerm* CompoundTerm::getLoadRuntimeTerm(Term* classKey) {
    return makeTerm(HEAD_LOAD_RUNTIME, classKey);
}

CompoundTerm* CompoundTerm::getLoadAddressableTerm(Term* classKey) {
    return makeTerm(HEAD_LOAD_ADDRESSABLE, classKey);
}

CompoundTerm* CompoundTerm::getDataFlowTerm(Term* mk, Term* src, Term* dst) {
    return makeTerm(HEAD_DATA_FLOW, mk, src, dst);
}

string CompoundTerm::getDataFlowFact(const string& mk, const string& src, const string& dst) {
    string ret = getDataFlowTerm(Term::getStr(mk), Term::getStr(src), Term::getStr(dst))->toString(true);
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
    string ret = getCodeOrderTerm(Term::getStr(mk), Term::getStr(src), Term::getStr(dst))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getRuntimeReadTerm(Term* mk, Term* variable, Term* runtimeReadKey) {
    return makeTerm(HEAD_RUNTIME_READ, mk, variable, runtimeReadKey);
}

string CompoundTerm::getRuntimeReadFact(const string& mk, const string& variable, const string& runtimeReadKey) {
    string ret = getRuntimeReadTerm(Term::getStr(mk), Term::getStr(variable), Term::getStr(runtimeReadKey))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getRuntimeWriteTerm(Term* mk, Term* variable, Term* runtimeWriteKey) {
    return makeTerm(HEAD_RUNTIME_WRITE, mk, variable, runtimeWriteKey);
}

string CompoundTerm::getRuntimeWriteFact(const string& mk, const string& variable, const string& runtimeWriteKey) {
    string ret = getRuntimeWriteTerm(Term::getStr(mk), Term::getStr(variable), Term::getStr(runtimeWriteKey))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getTypeToPLFileTerm(Term* typeKey, Term* filePath) {
    return makeTerm(HEAD_TYPE_TO_PL_FILE, typeKey, filePath);
}

string CompoundTerm::getTypeToPLFileFact(const string& typeKey, const string& filePath) {
    string ret = getTypeToPLFileTerm(Term::getStr(typeKey), Term::getStr(filePath))->toString(true);
    ret.push_back('.');
    return ret;
}

string CompoundTerm::getPackageFact(const string& package, const string& typeKey) {
    string ret = getPackageTerm(Term::getStr(package), Term::getStr(typeKey))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getPackageTerm(Term* package, Term* typeKey) {
    return makeTerm(HEAD_PACKAGE, package, typeKey);
}

CompoundTerm* CompoundTerm::getSubTypeTerm(Term* typeKey, Term* subTypeKey) {
    return makeTerm(HEAD_SUB_TYPE, typeKey, subTypeKey);
}

CompoundTerm* CompoundTerm::getSubTypeDownRecurTerm(Term* typeKey, Term* subTypeKey) {
    return makeTerm(HEAD_SUB_TYPE_DOWN_RECUR, typeKey, subTypeKey);
}

CompoundTerm* CompoundTerm::getSubTypeUpRecurTerm(Term* typeKey, Term* subTypeKey) {
    return makeTerm(HEAD_SUB_TYPE_UP_RECUR, typeKey, subTypeKey);
}

string CompoundTerm::getSubTypeFact(const string& typeKey, const string& subTypeKey) {
    string ret = getSubTypeTerm(Term::getStr(typeKey), Term::getStr(subTypeKey))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getOverrideTerm(Term* key, Term* subKey) {
    return makeTerm(HEAD_OVERRIDE, key, subKey);
}

CompoundTerm* CompoundTerm::getOverrideInRecurTerm(Term* key, Term* subKey) {
    return makeTerm(HEAD_OVERRIDE_IN_RECUR, key, subKey);
}

CompoundTerm* CompoundTerm::getOverrideOutRecurTerm(Term* superKey, Term* key) {
    return makeTerm(HEAD_OVERRIDE_OUT_RECUR, superKey, key);
}

string CompoundTerm::getOverrideFact(const string& key, const string& subKey) {
    string ret = getOverrideTerm(Term::getStr(key), Term::getStr(subKey))->toString(true);
    ret.push_back('.');
    return ret;
}

string CompoundTerm::getRelatedTypeFact(const string& typeKey, const string& typeKeyItUsed) {
    string ret = getRelatedTypeTerm(Term::getStr(typeKey), Term::getStr(typeKeyItUsed))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getRelatedTypeTerm(Term* typeKey, Term* typeKeyUsedByFirstParam) {
    return makeTerm(HEAD_RELATED_TYPE, typeKey, typeKeyUsedByFirstParam);
}

string CompoundTerm::getRelatedTypeAndMethodFact(const string& typeKey, const string& methodKeyItUsed) {
    string ret = getRelatedTypeAndMethodTerm(Term::getStr(typeKey), Term::getStr(methodKeyItUsed))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getRelatedTypeAndMethodTerm(Term* typeKey, Term* methodKeyUsedByFirstParam) {
    return makeTerm(HEAD_RELATED_TYPE_AND_METHOD, typeKey, methodKeyUsedByFirstParam);
}

string CompoundTerm::getMethodUseMethodFact(const string& mk, const string& usedMk) {
    string ret = getMethodUseMethodTerm(Term::getStr(mk), Term::getStr(usedMk))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getMethodUseMethodTerm(Term* mk, Term* usedMk) {
    return makeTerm(HEAD_METHOD_USE_METHOD, mk, usedMk);
}

string CompoundTerm::getMethodUseFieldFact(const string& mk, const string& usedF) {
    string ret = getMethodUseFieldTerm(Term::getStr(mk), Term::getStr(usedF))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getMethodUseFieldTerm(Term* mk, Term* usedF) {
    return makeTerm(HEAD_METHOD_USE_FIELD, mk, usedF);
}

string CompoundTerm::getMethodFact(const string& typeKey, const string& methodKey) {
    string ret = getMethodTerm(Term::getStr(typeKey), Term::getStr(methodKey))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getMethodTerm(Term* typeKey, Term* methodKey) {
    return makeTerm(HEAD_METHOD, typeKey, methodKey);
}

string CompoundTerm::getConstructorFact(const string& typeKey, const string& constructorKey) {
    string ret = getConstructorTerm(Term::getStr(typeKey), Term::getStr(constructorKey))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getConstructorTerm(Term* typeKey, Term* constructorKey) {
    return makeTerm(HEAD_CONSTRUCTOR, typeKey, constructorKey);
}

string CompoundTerm::getParameterFact(const string& methodKey, const string& parameterKey) {
    string ret = getParameterTerm(Term::getStr(methodKey), Term::getStr(parameterKey))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getParameterTerm(Term* methodKey, Term* parameterKey) {
    return makeTerm(HEAD_PARAMETER, methodKey, parameterKey);
}

string CompoundTerm::getReturnFact(const string& methodKey, const string& returnKey) {
    string ret = getReturnTerm(Term::getStr(methodKey), Term::getStr(returnKey))->toString(true);
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

CompoundTerm* CompoundTerm::getStepKeyTerm(Term* key, Term* stepKey) {
    return makeTerm(HEAD_STEP_KEY, key, stepKey);
}

CompoundTerm* CompoundTerm::getOverrideKeyTerm(Term* key, Term* overrideKey) {
    return makeTerm(HEAD_OVERRIDE_KEY, key, overrideKey);
}

CompoundTerm* CompoundTerm::getVarTerm(Term* t) {
    return makeTerm(HEAD_VAR, t);
}

string CompoundTerm::getFieldFact(const string& typeKey, const string& fieldKey) {
    string ret = getFieldTerm(Term::getStr(typeKey), Term::getStr(fieldKey))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getFieldTerm(Term* typeKey, Term* fieldKey) {
    return makeTerm(HEAD_FIELD, typeKey, fieldKey);
}

string CompoundTerm::getInstanceOfFact(const string& instanceKey, const string& typeKey) {
    string ret = getInstanceOfTerm(Term::getStr(instanceKey), Term::getStr(typeKey))->toString(true);
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
    string ret = getSimpleNameTerm(Term::getStr(key), Term::getStr(simpleName))->toString(true);
    ret.push_back('.');
    return ret;
}

CompoundTerm* CompoundTerm::getSimpleNameTerm(Term* key, Term* simpleName) {
    return makeTerm(HEAD_SIMPLE_NAME, key, simpleName);
}

string CompoundTerm::getIsFinalFact(const string& key) {
    string ret = getIsFinalTerm(Term::getStr(key))->toString(true);
    ret.push_back('.');
    return ret;
}

Term* CompoundTerm::getIsFinalTerm(Term* key) {
    return makeTerm(HEAD_IS_FINAL, key);
}

string CompoundTerm::getRuntimeFact(const string& methodKey, const string& key, const string& runtimeKey, int keyType) {
    string ret = getRuntimeTerm(Term::getStr(methodKey), Term::getStr(key), Term::getStr(runtimeKey), Term::getInt(keyType))->toString(true);
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

Term* CompoundTerm::getFaImplTerm(
    Term* lineInstanceValName,
    Term* classScopeValName,
    Term* currentState,
    Term* currentPoint,
    Term* currentSteps,
    const vector<Term*>& intersections,
    Term* output,
    Term* history,
    bool isBackward) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = isBackward ? HEAD_BACKWARD_FA_IMPL : HEAD_FORWARD_FA_IMPL;
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

Term* CompoundTerm::getCacheFaTerm(
    Term* lineInstanceValName,
    Term* classScopeValName,
    Term* currentState,
    Term* currentPoint,
    Term* currentSteps,
    const vector<Term*>& intersections,
    Term* output,
    Term* history,
    bool isBackward) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = isBackward ? HEAD_BACKWARD_CACHE_FA : HEAD_FORWARD_CACHE_FA;
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

Term* CompoundTerm::getFaCacheTerm(
    Term* lineInstanceValName,
    Term* classScopeValName,
    Term* currentState,
    Term* currentPoint,
    Term* currentSteps,
    Term* output,
    bool isBackward) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = isBackward ? HEAD_BACKWARD_FA_CACHE : HEAD_FORWARD_FA_CACHE;
    ret->addArg(lineInstanceValName);
    ret->addArg(classScopeValName);
    ret->addArg(currentState);
    ret->addArg(currentPoint);
    ret->addArg(currentSteps);
    ret->addArg(output);
    return ret;
}

Term* CompoundTerm::getFaDoneTerm(
    Term* lineInstanceValName,
    Term* classScopeValName,
    Term* currentState,
    Term* currentPoint,
    Term* currentSteps,
    bool isBackward) {
    auto ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = isBackward ? HEAD_BACKWARD_FA_DONE : HEAD_FORWARD_FA_DONE;
    ret->addArg(lineInstanceValName);
    ret->addArg(classScopeValName);
    ret->addArg(currentState);
    ret->addArg(currentPoint);
    ret->addArg(currentSteps);
    return ret;
}

void CompoundTerm::retractAllFaTerm(bool isBackward, int intersectionCount) {
    if (isBackward) {
        PrologWrapper::retractAllFact(HEAD_BACKWARD_FA->toString(), 7 + intersectionCount);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_FA->toString(), 7 + intersectionCount);
    }
}

void CompoundTerm::retractAllFaImplTerm(bool isBackward, int intersectionCount) {
    if (isBackward) {
        PrologWrapper::retractAllFact(HEAD_BACKWARD_FA_IMPL->toString(), 7 + intersectionCount);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_FA_IMPL->toString(), 7 + intersectionCount);
    }
}

void CompoundTerm::retractAllCacheFaTerm(bool isBackward, int intersectionCount) {
    if (isBackward) {
        PrologWrapper::retractAllFact(HEAD_BACKWARD_CACHE_FA->toString(), 7 + intersectionCount);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_CACHE_FA->toString(), 7 + intersectionCount);
    }
}

void CompoundTerm::retractAllFaCacheTerm(bool isBackward) {
    if (isBackward) {
        PrologWrapper::retractAllFact(HEAD_BACKWARD_FA_CACHE->toString(), 6);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_FA_CACHE->toString(), 6);
    }
}

void CompoundTerm::retractAllFaDoneTerm(bool isBackward) {
    if (isBackward) {
        PrologWrapper::retractAllFact(HEAD_BACKWARD_FA_DONE->toString(), 5);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_FA_DONE->toString(), 5);
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
    Term* expectingNextKey,
    Term* nextPoint,
    Term* nextSteps,
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
    ret->addArg(expectingNextKey);
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
        PrologWrapper::retractAllFact(HEAD_BACKWARD_TRANSITION->toString(), 11 + intersectionCount);
        PrologWrapper::retractAllFact(HEAD_BACKWARD_ENDING_TRANSITION->toString(), 4);
    } else {
        PrologWrapper::retractAllFact(HEAD_FORWARD_TRANSITION->toString(), 11 + intersectionCount);
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

CompoundTerm* CompoundTerm::getNodeSuperOf(Term* superNode, Term* subNode) {
    return makeTerm(HEAD_NODE_SUPER_OF, superNode, subNode);
}

CompoundTerm* CompoundTerm::getNodeSubOf(Term* superNode, Term* subNode) {
    return makeTerm(HEAD_NODE_SUB_OF, superNode, subNode);
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

CompoundTerm* CompoundTerm::getResolveRuntimeCheckTerm(Term* nodeValName, Term* methodKey, Term* runtimeNode, Term* key, Term* keyType) {
    return makeTerm(HEAD_RESOLVE_RUNTIME_CHECK, nodeValName, methodKey, runtimeNode, key, keyType);
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

void CompoundTerm::addArg(Term* arg) {
    args.push_back(arg);
}

void CompoundTerm::addVarTermArg() {
    args.push_back(Term::getVar("A" + to_string(args.size() + 1)));
}

PlTerm* CompoundTerm::toPlTerm() {
    PlTermv plTermv(args.size());
    for (int i = 0; i < args.size(); ++i) {
        plTermv[i].unify_term(*args[i]->toPlTerm());
    }
    return new PlCompound(head->toString(), plTermv);
}

Unification* Unification::getUnificationInstance(Term* first, Term* second) {
    auto* ret = PooledItem<Unification>::getInstance();
    ret->firstTerm = first;
    ret->secondTerm = second;
    return ret;
}

string Unification::toString(bool returnToPool) {
    string ret = firstTerm->toString();
    ret.push_back('=');
    ret += secondTerm->toString();
    return ret;
}

void Unification::reset() {
    this->firstTerm = nullptr;
    this->secondTerm = nullptr;
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

string Tail::toString(bool returnToPool) {
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

string Rule::toString(bool returnToPool) {
    string ret = head->toString();
    ret += ":- (";
    ret += joinVector(conditions, ",", termToString);
    ret.push_back(')');
    if (returnToPool) {
        returnThisToPool();
    }
    return ret;
}

DisjunctionTerm* DisjunctionTerm::getDisjunctionInstance(Term* t1, Term* t2) {
    DisjunctionTerm* ret = PooledItem<DisjunctionTerm>::getInstance();
    ret->term1 = t1;
    ret->term2 = t2;
    return ret;
}

void DisjunctionTerm::reset() {
    term1 = NULL;
    term2 = NULL;
}

string DisjunctionTerm::toString(bool returnToPool) {
    return "(" + term1->toString() + "; " + term2->toString() + ")";
}

ConjunctionTerm* ConjunctionTerm::getConjunctionInstance(const vector<Term*>& terms) {
    ConjunctionTerm* ret = PooledItem<ConjunctionTerm>::getInstance();
    FOR_EACH_ITEM(terms, ret->terms.push_back(item););
    return ret;
}

void ConjunctionTerm::reset() {
    terms.clear();
}

string ConjunctionTerm::toString(bool returnToPool) {
    string ret = "(";
    ret += joinVector(terms, ",", termToString);
    ret.push_back(')');
    return ret;
}

AssertTerm* AssertTerm::getAssertInstance(Term* term) {
    AssertTerm* ret = PooledItem<AssertTerm>::getInstance();
    ret->term = term;
    return ret;
}

void AssertTerm::reset() {
    term = NULL;
}

string AssertTerm::toString(bool returnToPool) {
    return HEAD_ASSERTZ->toString() + "((" + term->toString() + "))";
}

EnsureLoadedTerm* EnsureLoadedTerm::getEnsureLoadedInstance(Term* term) {
    EnsureLoadedTerm* ret = PooledItem<EnsureLoadedTerm>::getInstance();
    ret->term = term;
    return ret;
}

void EnsureLoadedTerm::reset() {
    term = NULL;
}

string EnsureLoadedTerm::toString(bool returnToPool) {
    return "ensure_loaded([" + term->toString() + "])";
}

void EnsureLoadedTerm::returnThisToPool() {
    term->returnThisToPool();
    PooledItem<EnsureLoadedTerm>::returnToPool(this);
}

CompoundTerm* CompoundTerm::getForwardDataStepTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextStepKey, Term* currentSetps, Term* nextSetps) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_FORWARD_DATA_STEP;
    ret->addArg(runtimeMethod);
    ret->addArg(point);
    ret->addArg(nextRuntimeMethod);
    ret->addArg(nextStepKey);
    ret->addArg(currentSetps);
    ret->addArg(nextSetps);
    return ret;
}

CompoundTerm* CompoundTerm::getBackwardDataStepTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextStepKey, Term* currentSetps, Term* nextSetps) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_BACKWARD_DATA_STEP;
    ret->addArg(runtimeMethod);
    ret->addArg(point);
    ret->addArg(nextRuntimeMethod);
    ret->addArg(nextStepKey);
    ret->addArg(currentSetps);
    ret->addArg(nextSetps);
    return ret;
}

CompoundTerm* CompoundTerm::getForwardTimingStepTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextStepKey, Term* currentSetps, Term* nextSetps) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_FORWARD_TIMING_STEP;
    ret->addArg(runtimeMethod);
    ret->addArg(point);
    ret->addArg(nextRuntimeMethod);
    ret->addArg(nextStepKey);
    ret->addArg(currentSetps);
    ret->addArg(nextSetps);
    return ret;
}

CompoundTerm* CompoundTerm::getBackwardTimingStepTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextStepKey, Term* currentSetps, Term* nextSetps) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_BACKWARD_TIMING_STEP;
    ret->addArg(runtimeMethod);
    ret->addArg(point);
    ret->addArg(nextRuntimeMethod);
    ret->addArg(nextStepKey);
    ret->addArg(currentSetps);
    ret->addArg(nextSetps);
    return ret;
}

CompoundTerm* CompoundTerm::getForwardDataOverrideTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextOverrideKey, Term* currentSetps, Term* nextSetps) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_FORWARD_DATA_OVERRIDE;
    ret->addArg(runtimeMethod);
    ret->addArg(point);
    ret->addArg(nextRuntimeMethod);
    ret->addArg(nextOverrideKey);
    ret->addArg(currentSetps);
    ret->addArg(nextSetps);
    return ret;
}

CompoundTerm* CompoundTerm::getBackwardDataOverrideTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextOverrideKey, Term* currentSetps, Term* nextSetps) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_BACKWARD_DATA_OVERRIDE;
    ret->addArg(runtimeMethod);
    ret->addArg(point);
    ret->addArg(nextRuntimeMethod);
    ret->addArg(nextOverrideKey);
    ret->addArg(currentSetps);
    ret->addArg(nextSetps);
    return ret;
}

CompoundTerm* CompoundTerm::getForwardTimingOverrideTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextOverrideKey, Term* currentSetps, Term* nextSetps) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_FORWARD_TIMING_OVERRIDE;
    ret->addArg(runtimeMethod);
    ret->addArg(point);
    ret->addArg(nextRuntimeMethod);
    ret->addArg(nextOverrideKey);
    ret->addArg(currentSetps);
    ret->addArg(nextSetps);
    return ret;
}

CompoundTerm* CompoundTerm::getBackwardTimingOverrideTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextOverrideKey, Term* currentSetps, Term* nextSetps) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_BACKWARD_TIMING_OVERRIDE;
    ret->addArg(runtimeMethod);
    ret->addArg(point);
    ret->addArg(nextRuntimeMethod);
    ret->addArg(nextOverrideKey);
    ret->addArg(currentSetps);
    ret->addArg(nextSetps);
    return ret;
}

CompoundTerm* CompoundTerm::getCalledParamToCalledReturnTerm(Term* runtimeMethodKey, Term* calledParam, Term* calledReturn) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_CALLED_PARAM_TO_CALLED_RETURN;
    ret->addArg(runtimeMethodKey);
    ret->addArg(calledParam);
    ret->addArg(calledReturn);
    return ret;
}

CompoundTerm* CompoundTerm::getCalledMethodToCalledReturnTerm(Term* runtimeMethodKey, Term* calledMethod, Term* calledReturn) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_CALLED_METHOD_TO_CALLED_RETURN;
    ret->addArg(runtimeMethodKey);
    ret->addArg(calledMethod);
    ret->addArg(calledReturn);
    return ret;
}

CompoundTerm* CompoundTerm::getCalledReturnToCalledParam(Term* runtimeMethodKey, Term* calledReturn, Term* calledParam) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_CALLED_RETURN_TO_CALLED_PARAM;
    ret->addArg(runtimeMethodKey);
    ret->addArg(calledReturn);
    ret->addArg(calledParam);
    return ret;
}

CompoundTerm* CompoundTerm::getCalledReturnToCalledMethod(Term* runtimeMethodKey, Term* calledReturn, Term* calledMethod) {
    auto* ret = PooledItem<CompoundTerm>::getInstance();
    ret->head = HEAD_CALLED_RETURN_TO_CALLED_METHOD;
    ret->addArg(runtimeMethodKey);
    ret->addArg(calledReturn);
    ret->addArg(calledMethod);
    return ret;
}

void CompoundTerm::returnThisToPool() {
    for (auto& item : args) {
        item->returnThisToPool();
    }
    PooledItem<CompoundTerm>::returnToPool(this);
}

void Tail::returnThisToPool() {
    for (auto& item : headElements) {
        item->returnThisToPool();
    }
    if (tail) {
        tail->returnThisToPool();
    }
    PooledItem<Tail>::returnToPool(this);
}

void MinusTerm::returnThisToPool() {
    remainderTerm->returnThisToPool();
    minuendTerm->returnThisToPool();
    subtrahend->returnThisToPool();
}

void NegationTerm::returnThisToPool() {
    term->returnThisToPool();
    PooledItem<NegationTerm>::returnToPool(this);
}

void DisjunctionTerm::returnThisToPool() {
    term1->returnThisToPool();
    term2->returnThisToPool();
    PooledItem<DisjunctionTerm>::returnToPool(this);
}

void ConjunctionTerm::returnThisToPool() {
    for (auto& t : terms) {
        t->returnThisToPool();
    }
    PooledItem<ConjunctionTerm>::returnToPool(this);
}

void Unification::returnThisToPool() {
    firstTerm->returnThisToPool();
    secondTerm->returnThisToPool();
    PooledItem<Unification>::returnToPool(this);
}

void AssertTerm::returnThisToPool() {
    term->returnThisToPool();
    PooledItem<AssertTerm>::returnToPool(this);
}

void Rule::returnThisToPool() {
    head->returnThisToPool();
    for (auto& c : conditions) {
        c->returnThisToPool();
    }
    PooledItem<Rule>::returnToPool(this);
}

CompoundTerm* CompoundTerm::getAddressableLoadedTerm(Term* addressable) {
    return makeTerm(HEAD_ADDRESSABLE_LOADED, addressable);
}

CompoundTerm* CompoundTerm::getUnaddressableLoadedTerm(Term* unaddressable) {
    return makeTerm(HEAD_UNADDRESSABLE_LOADED, unaddressable);
}

CompoundTerm* CompoundTerm::getStringConcatTerm(Term* term1, Term* term2, Term* term) {
    return makeTerm(HEAD_STRING_CONCAT, term1, term2, term);
}
