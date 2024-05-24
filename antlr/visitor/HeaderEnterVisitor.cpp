#include "../../util/util.h"
#include "../syntaxObject/Modifier.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "../../addressableInfo/GlobalInfo.h"
#include "../../runtime/ScopeAndEnv.h"
#include "HeaderEnterVisitor.h"
#include "../../error/ErrorManager.h"

void Header::PhaseBaseClass::visitCompilationUnit(CompilationUnit* compilationUnit) {
    package = compilationUnit->package;
    for (auto& type : compilationUnit->types) {
        visitType(type);
    }
}

void Header::PhaseBaseClass::visitType(Type* type) {

}

void Header::PhaseBaseClass::pushTypeStack(const string& typeName) {
    typeNameStack.push_back(typeName);
    typeKeyStack.push_back(package + '.' + joinList(typeNameStack, "."));
}

void Header::PhaseBaseClass::popTypeStack() {
    typeKeyStack.pop_back();
    typeNameStack.pop_back();
}

void Header::PhaseBaseClass::recurVisitInnerType(Type* type) {
    for (auto& innerType : type->innerTypes) {
        visitType(innerType);
    }
}

void Header::PhaseBaseClass::reset() {
    currentFilePath.clear();
    package.clear();
    typeNameStack.clear();
    typeKeyStack.clear();
}

void Header::EnterClassPhase::run() {
    for (auto& compileUnit : AddressableInfo::filePath2compilationUnits) {
        reset();
        currentFilePath = compileUnit.first;
        if (not GlobalInfo::filePath2package2typeKeys.count(currentFilePath)) {
            GlobalInfo::filePath2package2typeKeys[currentFilePath] = map<string, set<string>>();
        }
        if (not GlobalInfo::filePath2package2typeKeys[currentFilePath].count(compileUnit.second->package)) {
            GlobalInfo::filePath2package2typeKeys[currentFilePath][compileUnit.second->package] = set<string>();
        }
        if (not GlobalInfo::filePath2typeKey2subTypeKeys.count(currentFilePath)) {
            GlobalInfo::filePath2typeKey2subTypeKeys[currentFilePath] = map<string, set<string>>();
        }
        if (not GlobalInfo::filePath2typeKey2filePath.count(currentFilePath)) {
            GlobalInfo::filePath2typeKey2filePath[currentFilePath] = map<string, string>();
        }
        GlobalInfo::filePath2typeInfos[currentFilePath] = list<TypeInfo*>();
        visitCompilationUnit(compileUnit.second);
    }
    for (auto& filePath : duplicateTypeFile) {
        AddressableInfo::filePath2compilationUnits.erase(filePath);
        GlobalInfo::filePath2package2typeKeys.erase(filePath);
        GlobalInfo::filePath2typeKey2subTypeKeys.erase(filePath);
        GlobalInfo::filePath2typeKey2filePath.erase(filePath);
    }
}

void Header::EnterClassPhase::visitType(Type* type) {
    pushTypeStack(type->name);
    if (AddressableInfo::typeKey2typeInfo.count(typeKeyStack.back())) {
        duplicateTypeFile.insert(currentFilePath);
        popTypeStack();
        return;
    }

    GlobalInfo::filePath2package2typeKeys[currentFilePath][package].insert(typeKeyStack.back());
    GlobalInfo::filePath2typeKey2filePath[currentFilePath][typeKeyStack.back()] = currentFilePath;
    auto* pTypeInfo = new TypeInfo;
    AddressableInfo::typeKey2typeInfo[typeKeyStack.back()] = pTypeInfo;
    GlobalInfo::filePath2typeInfos[currentFilePath].push_back(pTypeInfo);
    pTypeInfo->flag = type->flag;
    pTypeInfo->typeKey = typeKeyStack.back();
    pTypeInfo->filePath = currentFilePath;
    pTypeInfo->package = package;
    pTypeInfo->simpletypeName = typeNameStack.back();
    pTypeInfo->typeName = joinList(typeNameStack, ".");
    if (typeKeyStack.size() > 1) {
        auto outerTypeKeyIter = typeKeyStack.end();
        outerTypeKeyIter--;
        outerTypeKeyIter--;
        auto outerTypeInfo = AddressableInfo::typeKey2typeInfo[*outerTypeKeyIter];
        outerTypeInfo->innerTypeInfos.insert(pTypeInfo);
        pTypeInfo->outerTypeInfo = outerTypeInfo;
    }
    // "this" field
    auto* thisFieldInfo = new FieldInfo;
    thisFieldInfo->name = "this";
    thisFieldInfo->fieldKey = pTypeInfo->typeKey + ".this";
    thisFieldInfo->typeInfo = pTypeInfo;
    thisFieldInfo->flag = Modifier::PUBLIC;
    AddressableInfo::fieldKey2fieldInfo[thisFieldInfo->fieldKey] = thisFieldInfo;
    pTypeInfo->fieldInfos.insert(thisFieldInfo);

    // type parameter starts
    if (not type->typeParams.empty()) {
        for (auto& typeParam : type->typeParams) {
            string typeParamKey = AddressableInfo::makeTypeParameterKey(typeKeyStack.back(), typeParam->name);
            auto* typeParamInfo = new TypeInfo();
            typeParamInfo->isTypeParam = true;
            typeParamInfo->scopeTypeInfo = pTypeInfo;
            typeParamInfo->typeKey = typeParamKey;
            typeParamInfo->typeName = typeParam->name;
            typeParamInfo->simpletypeName = typeParam->name;
            pTypeInfo->typeParamInfos.push_back(typeParamInfo);
            typeParamInfo->package = package;
            AddressableInfo::typeKey2typeInfo[typeParamKey] = typeParamInfo;
            if (not typeParam->bounds.empty()) {
                typeParamInfo->boundNameForTypeParam = typeParam->bounds.front();
            }
        }
    }
    // type parameter ends
    if (Modifier::isEnumType(type->flag)) {
        SuperRelationUnresolved* superRelationUnresolved = new SuperRelationUnresolved();
        superRelationUnresolved->type = 1;
        superRelationUnresolved->typeInfo = pTypeInfo;
        superRelationUnresolved->superTypeName = AddressableInfo::enumTypeName;
        Header::HierarchyPhase::superRelationUnresolved.insert(superRelationUnresolved);
    } else if (type->extendsTypeNames.empty() and pTypeInfo->typeKey != "java.lang.Object") {
        SuperRelationUnresolved* superRelationUnresolved = new SuperRelationUnresolved();
        superRelationUnresolved->type = 1;
        superRelationUnresolved->typeInfo = pTypeInfo;
        superRelationUnresolved->superTypeName = AddressableInfo::objectTypeName;
        Header::HierarchyPhase::superRelationUnresolved.insert(superRelationUnresolved);
    } else {
        for (auto& ext : type->extendsTypeNames) {
            SuperRelationUnresolved* superRelationUnresolved = new SuperRelationUnresolved();
            superRelationUnresolved->type = 1;
            superRelationUnresolved->typeInfo = pTypeInfo;
            superRelationUnresolved->superTypeName = ext;
            Header::HierarchyPhase::superRelationUnresolved.insert(superRelationUnresolved);
        }
    }
    for (auto& impl : type->implementsTypeNames) {
        SuperRelationUnresolved* superRelationUnresolved = new SuperRelationUnresolved();
        superRelationUnresolved->type = 2;
        superRelationUnresolved->typeInfo = pTypeInfo;
        superRelationUnresolved->superTypeName = impl;
        Header::HierarchyPhase::superRelationUnresolved.insert(superRelationUnresolved);
    }

    recurVisitInnerType(type);

    popTypeStack();
}

set<Header::SuperRelationUnresolved*> Header::HierarchyPhase::superRelationUnresolved;

bool Header::HierarchyPhase::finishUnresolved() {
    set<SuperRelationUnresolved*> resolved;
    for (auto& superRelationUnresolvedI : superRelationUnresolved) {
        auto& pTypeInfo = superRelationUnresolvedI->typeInfo;
        TypeInfo* superTypeInfo = pTypeInfo->classScopeAndEnv->getTypeInfoWithFileScope(superRelationUnresolvedI->superTypeName->typeName);
        if (superTypeInfo) {
            if (superRelationUnresolvedI->type == 1) {
                pTypeInfo->superTypeInfos.insert(superTypeInfo);
            } else {
                pTypeInfo->interfaceInfos.insert(superTypeInfo);
            }
            if (superRelationUnresolvedI->superTypeName->typeArgs.size() == superTypeInfo->typeParamInfos.size()) {
                for (int i = 0;i < superRelationUnresolvedI->superTypeName->typeArgs.size();i++) {
                    pTypeInfo->typeArgNamesForSuper[superTypeInfo->typeParamInfos[i]] =
                        superRelationUnresolvedI->superTypeName->typeArgs[i];
                }
            }
            ClassScopeAndEnv::linkSuperScopeAndEnv(pTypeInfo, superTypeInfo);
            if (not GlobalInfo::filePath2typeKey2subTypeKeys[pTypeInfo->filePath].count(superTypeInfo->typeKey)) {
                GlobalInfo::filePath2typeKey2subTypeKeys[pTypeInfo->filePath][superTypeInfo->typeKey] = set<string>();
            }
            GlobalInfo::filePath2typeKey2subTypeKeys[pTypeInfo->filePath][superTypeInfo->typeKey].insert(pTypeInfo->typeKey);
            resolved.insert(superRelationUnresolvedI);
        }
    }
    FOR_EACH_ITEM(resolved, superRelationUnresolved.erase(item););
    return not resolved.empty();
}

void Header::HierarchyPhase::resolveHierarchy() {
    while (not superRelationUnresolved.empty() and finishUnresolved()) {}
    for (auto& superRelationUnresolvedI : superRelationUnresolved) {
        if (superRelationUnresolvedI->type == 1) {
            spdlog::get(ErrorManager::DebugTag)->warn(
                "HierarchyPhase::resolveHierarchy: did not find super name <{}> for type <{}>", joinList(superRelationUnresolvedI->superTypeName->typeName, "."), superRelationUnresolvedI->typeInfo->typeKey);
        } else {
            spdlog::get(ErrorManager::DebugTag)->warn(
                "HierarchyPhase::resolveHierarchy: did not find implement name <{}> for type <{}>", joinList(superRelationUnresolvedI->superTypeName->typeName, "."), superRelationUnresolvedI->typeInfo->typeKey);
        }
    }
    spdlog::get(ErrorManager::DebugTag)->warn(
        "HierarchyPhase::resolveHierarchy: did not find super and implement name in total: {}", superRelationUnresolved.size());
}


void Header::MemeberPhase::run() {
    for (auto& compileUnit : AddressableInfo::filePath2compilationUnits) {
        reset();
        typeInfoStack.clear();
        currentFilePath = compileUnit.first;
        visitCompilationUnit(compileUnit.second);
    }
}

void Header::MemeberPhase::visitType(Type* type) {
    pushTypeStack(type->name);
    auto*& typeInfo = AddressableInfo::typeKey2typeInfo[typeKeyStack.back()];
    typeInfoStack.push_back(typeInfo);
    recurVisitInnerType(type);
    for (auto& field : type->fields) {
        addFieldInfo(field);
    }
    for (auto& enumConst : type->enumConstants) {
        visitEnum(typeInfo, enumConst);
    }
    if (type->constructors.empty()) {
        // default constructor
        Method method;
        method.flag = Modifier::PUBLIC;
        method.name = type->name;
        method.returnTypeName = new TypeName();
        method.returnTypeName->typeName.push_back(type->name);
        addMethodInfo(&method, true);
    } else {
        for (auto& method : type->constructors) {
            addMethodInfo(method, true);
        }
    }
    for (auto& method : type->methods) {
        addMethodInfo(method, false);
    }
    typeInfoStack.pop_back();
    popTypeStack();
}

void Header::MemeberPhase::visitEnum(TypeInfo* typeInfo, string& enumConst) {
    auto* fieldInfo = new FieldInfo();
    typeInfo->fieldInfos.insert(fieldInfo);
    fieldInfo->name = enumConst;
    fieldInfo->fieldKey = typeKeyStack.back() + "." + enumConst;
    fieldInfo->typeInfo = typeInfo;
    fieldInfo->flag = Modifier::PUBLIC | Modifier::STATIC | Modifier::FINAL | Modifier::ENUM;
    AddressableInfo::fieldKey2fieldInfo[fieldInfo->fieldKey] = fieldInfo;
}

void Header::MemeberPhase::addFieldInfo(FieldOrParameter* field) {
    TypeInfo* typeInfo = typeInfoStack.back();
    std::list<std::string> typeName;
    TypeInfo* fieldTypeInfo = typeInfo->classScopeAndEnv->getTypeInfoWithFileScope(field->typeName->typeName);
    // error handle
    if (fieldTypeInfo == nullptr) {
        fieldTypeInfo = new TypeInfo;
        fieldTypeInfo->typeName = joinList(field->typeName->typeName, ".");
        fieldTypeInfo->typeKey = fieldTypeInfo->typeName;
        spdlog::get(ErrorManager::DebugTag)->warn(
            "MemeberPhase::addFieldInfo: did not find type name: <{}> for field: {} in type: {}", fieldTypeInfo->typeName, field->name, typeInfo->typeKey);
    }
    auto* fieldInfo = new FieldInfo();
    typeInfo->fieldInfos.insert(fieldInfo);
    fieldInfo->name = field->name;
    fieldInfo->fieldKey = typeKeyStack.back() + "." + field->name;
    fieldInfo->typeInfo = fieldTypeInfo;
    fieldInfo->flag = field->flag;
    if (fieldTypeInfo->typeParamInfos.size() == field->typeName->typeArgs.size()) {
        for (int i = 0;i < field->typeName->typeArgs.size();i++) {
            TypeInfo* typeArgTypeInfo = typeInfo->classScopeAndEnv->getTypeInfoWithFileScope(field->typeName->typeArgs[i]->typeName);
            if (typeArgTypeInfo) {
                fieldInfo->typeParam2typeArg[fieldTypeInfo->typeParamInfos[i]] = typeArgTypeInfo;
            }
        }
    }
    AddressableInfo::fieldKey2fieldInfo[fieldInfo->fieldKey] = fieldInfo;
    // int dim = field->dim;
}

void Header::MemeberPhase::addMethodInfo(Method* method, bool isConstructor) {
    TypeInfo* typeInfo = typeInfoStack.back();
    // method info
    auto* methodInfo = new MethodInfo();
    methodInfo->isVariableParameter = method->isVariableParameter;
    // type parameter name starts
    map<string, TypeInfo*> typeParamName2TypeInfo;
    FOR_EACH_ITEM(method->typeParams,
        TypeInfo * typeParamInfo = new TypeInfo();
    typeParamInfo->simpletypeName = item->name;
    typeParamInfo->typeName = item->name;
    typeParamInfo->isTypeParam = true;
    typeParamInfo->scopeTypeInfo = typeInfo;
    typeParamName2TypeInfo[item->name] = typeParamInfo;
    if (not item->bounds.empty()) {
        typeParamInfo->boundNameForTypeParam = item->bounds.front();
        typeParamInfo->boundInfoForTypeParam = typeInfo->classScopeAndEnv->getTypeInfoWithFileScope(typeParamInfo->boundNameForTypeParam->typeName);
    }
    );
    // type parameter name ends

    // return type starts
    TypeInfo* returnTypeInfo = typeInfo->classScopeAndEnv->getTypeInfoWithFileScope(method->returnTypeName->typeName);
    if (not returnTypeInfo and method->returnTypeName->typeName.size() == 1 and typeParamName2TypeInfo.count(method->returnTypeName->typeName.back())) {
        returnTypeInfo = typeParamName2TypeInfo[method->returnTypeName->typeName.back()];
    }
    // error handle
    if (returnTypeInfo == nullptr) {
        // make fake type info
        returnTypeInfo = new TypeInfo;
        returnTypeInfo->typeName = joinList(method->returnTypeName->typeName, ".");
        returnTypeInfo->typeKey = returnTypeInfo->typeName;
        spdlog::get(ErrorManager::DebugTag)->warn(
            "MemeberPhase::addMethodInfo: did not find return type name: <{}> for method name: {} in type: {}", returnTypeInfo->typeName, method->name, typeInfo->typeKey);
    }
    // return type ends

    list<pair<string, FieldInfo*>> parameterInfos;
    for (auto& parameter : method->parameters) {
        TypeInfo* parameterTypeInfo = typeInfo->classScopeAndEnv->getTypeInfoWithFileScope(parameter->typeName->typeName);
        if (not parameterTypeInfo and parameter->typeName->typeName.size() == 1 and typeParamName2TypeInfo.count(parameter->typeName->typeName.back())) {
            parameterTypeInfo = typeParamName2TypeInfo[parameter->typeName->typeName.back()];
        }
        // error handle
        if (parameterTypeInfo == nullptr) {
            // make fake type info
            parameterTypeInfo = new TypeInfo;
            parameterTypeInfo->typeName = joinList(parameter->typeName->typeName, ".");
            parameterTypeInfo->typeKey = parameterTypeInfo->typeName;
            spdlog::get(ErrorManager::DebugTag)->warn(
                "MemeberPhase::addMethodInfo: did not find parameter type name: <{}> for method name: {} in type: {}", parameterTypeInfo->typeName, method->name, typeInfo->typeKey);
        }
        auto parameterInfo = new FieldInfo();
        parameterInfo->name = parameter->name;
        parameterInfo->typeInfo = parameterTypeInfo;
        methodInfo->parameterInfos.push_back(parameterInfo);
        parameterInfos.push_back({ parameter->name ,parameterInfo });
        if (parameterTypeInfo->typeParamInfos.size() == parameter->typeName->typeArgs.size()) {
            for (int i = 0;i < parameter->typeName->typeArgs.size();i++) {
                TypeInfo* typeArgTypeInfo = typeInfo->classScopeAndEnv->getTypeInfoWithFileScope(parameter->typeName->typeArgs[i]->typeName);
                if (not typeArgTypeInfo and parameter->typeName->typeArgs[i]->typeName.size() == 1 and
                    typeParamName2TypeInfo.count(parameter->typeName->typeArgs[i]->typeName.back())) {
                    typeArgTypeInfo = typeParamName2TypeInfo[parameter->typeName->typeArgs[i]->typeName.back()];
                }
                if (typeArgTypeInfo) {
                    parameterInfo->typeParam2typeArg[parameterTypeInfo->typeParamInfos[i]] = typeArgTypeInfo;
                }
            }
        }
    }
    string paramPartOfKey = methodInfo->getParamPartOfKey();
    methodInfo->name = method->name;
    methodInfo->methodKey = AddressableInfo::makeMethodKey(typeKeyStack.back(), method->name, paramPartOfKey);
    methodInfo->calledMethodKey = AddressableInfo::makeCalledKey(methodInfo->methodKey);
    methodInfo->isConstructor = isConstructor;
    methodInfo->flag = method->flag;
    AddressableInfo::methodKey2MethodInfo[methodInfo->methodKey] = methodInfo;
    // type parameter key starts
    FOR_EACH_ITEM(typeParamName2TypeInfo,
        string typeParamKey = AddressableInfo::makeTypeParameterKey(methodInfo->methodKey, item.first);
    item.second->typeKey = typeParamKey;
    item.second->package = package;
    AddressableInfo::typeKey2typeInfo[typeParamKey] = item.second;
    methodInfo->typeParamInfos.push_back(item.second);
    );
    // type parameter key ends
    // type info
    typeInfo->methodInfos.insert(methodInfo);
    // parameter and return field info
    for (auto& parameter : parameterInfos) {
        auto* parameterInfo = parameter.second;
        parameterInfo->fieldKey = AddressableInfo::makeParamKey(methodInfo->methodKey, parameter.first);
        AddressableInfo::fieldKey2fieldInfo[parameterInfo->fieldKey] = parameterInfo;
        auto* calledParamInfo = new FieldInfo();
        methodInfo->calledParamInfos.push_back(calledParamInfo);
        calledParamInfo->name = AddressableInfo::makeCalledKey(parameterInfo->name);
        calledParamInfo->fieldKey = AddressableInfo::makeCalledKey(parameterInfo->fieldKey);
        calledParamInfo->typeInfo = parameterInfo->typeInfo;
        AddressableInfo::fieldKey2fieldInfo[calledParamInfo->fieldKey] = calledParamInfo;
    }
    auto* returnFieldInfo = new FieldInfo();
    methodInfo->returnInfo = returnFieldInfo;
    returnFieldInfo->name = "return";
    returnFieldInfo->fieldKey = AddressableInfo::makeReturnKey(methodInfo->methodKey);
    returnFieldInfo->typeInfo = returnTypeInfo;
    AddressableInfo::fieldKey2fieldInfo[returnFieldInfo->fieldKey] = returnFieldInfo;
    auto* calledReturnFieldInfo = new FieldInfo();
    methodInfo->calledReturnInfo = calledReturnFieldInfo;
    calledReturnFieldInfo->name = AddressableInfo::makeCalledKey("return");
    calledReturnFieldInfo->fieldKey = AddressableInfo::makeCalledKey(returnFieldInfo->fieldKey);
    calledReturnFieldInfo->typeInfo = returnTypeInfo;
    AddressableInfo::fieldKey2fieldInfo[calledReturnFieldInfo->fieldKey] = calledReturnFieldInfo;
    if (returnTypeInfo->typeParamInfos.size() == method->returnTypeName->typeArgs.size()) {
        for (int i = 0;i < method->returnTypeName->typeArgs.size();i++) {
            TypeInfo* typeArg = typeInfo->classScopeAndEnv->getTypeInfoWithFileScope(method->returnTypeName->typeArgs[i]->typeName);
            if (not typeArg and method->returnTypeName->typeArgs[i]->typeName.size() == 1 and
                typeParamName2TypeInfo.count(method->returnTypeName->typeArgs[i]->typeName.back())) {
                typeArg = typeParamName2TypeInfo[method->returnTypeName->typeArgs[i]->typeName.back()];
            }
            if (typeArg) {
                calledReturnFieldInfo->typeParam2typeArg[returnTypeInfo->typeParamInfos[i]] = typeArg;
            }
        }
    }
}
