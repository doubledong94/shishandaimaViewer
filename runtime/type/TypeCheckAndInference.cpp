#include "util/util.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "addressableInfo/AddressableInfo.h"
#include "runtime/codestructure/CodeStructure.h"
#include "runtime/codestructure/Relation.h"
#include "runtime/type/TypeCheckAndInference.h"
#include "error/ErrorManager.h"

bool TypeCheckAndInference::isAssignable(TypeInfo* typeInfo, TypeInfo* superTypeInfo) {
    if (not typeInfo or not superTypeInfo) {
        return false;
    }
    if (typeInfo == AddressableInfo::nullTypeInfo) {//所有类型都是null的父类
        return true;
    }
    if (superTypeInfo == AddressableInfo::objectTypeInfo) {
        return true;
    }
    if (typeInfo == superTypeInfo) {
        return true;
    }
    // numeric types
    if (AddressableInfo::numberTypes.count(typeInfo) and AddressableInfo::numberTypes.count(superTypeInfo)) {
        return isNumberAssignable(typeInfo, superTypeInfo);
    }

    for (auto& superTypeInfoI : typeInfo->superTypeInfos) {
        if (isAssignable(superTypeInfoI, superTypeInfo)) {
            return true;
        }
    }
    for (auto& interfaceInfo : typeInfo->interfaceInfos) {
        if (isAssignable(interfaceInfo, superTypeInfo)) {
            return true;
        }
    }
    return false;
}

bool TypeCheckAndInference::isNumberAssignable(TypeInfo* typeInfo, TypeInfo* superTypeInfo) {
    bool biggerThanDouble = superTypeInfo == AddressableInfo::doubleTypeInfo or superTypeInfo == AddressableInfo::primitive_doubleTypeInfo;
    bool biggerThanFloat = biggerThanDouble or superTypeInfo == AddressableInfo::floatTypeInfo or superTypeInfo == AddressableInfo::primitive_floatTypeInfo;
    bool biggerThanLong = biggerThanFloat or superTypeInfo == AddressableInfo::longTypeInfo or superTypeInfo == AddressableInfo::primitive_longTypeInfo;
    bool biggerThanInt = biggerThanLong or superTypeInfo == AddressableInfo::intTypeInfo or superTypeInfo == AddressableInfo::primitive_intTypeInfo;
    bool biggerThanShort = biggerThanInt or superTypeInfo == AddressableInfo::shortTypeInfo or superTypeInfo == AddressableInfo::primitive_shortTypeInfo;
    if (typeInfo == AddressableInfo::shortTypeInfo or typeInfo == AddressableInfo::primitive_shortTypeInfo) {
        return biggerThanShort;
    }
    if (typeInfo == AddressableInfo::intTypeInfo or typeInfo == AddressableInfo::primitive_intTypeInfo) {
        return biggerThanInt;
    }
    if (typeInfo == AddressableInfo::longTypeInfo or typeInfo == AddressableInfo::primitive_longTypeInfo) {
        return biggerThanLong;
    }
    if (typeInfo == AddressableInfo::floatTypeInfo or typeInfo == AddressableInfo::primitive_floatTypeInfo) {
        return biggerThanFloat;
    }
    if (typeInfo == AddressableInfo::doubleTypeInfo or typeInfo == AddressableInfo::primitive_doubleTypeInfo) {
        return biggerThanDouble;
    }
    return false;
}

bool TypeCheckAndInference::methodParamCountCheck(MethodInfo* methodInfo, int paramCount) {
    return methodInfo->parameterInfos.size() == paramCount or (methodInfo->isVariableParameter and paramCount >= methodInfo->parameterInfos.size() - 1);
}


MethodInfo* TypeCheckAndInference::findBestMethod(list<MethodInfo*>& methodInfos, vector<ResolvingItem*>& arguments) {
    MethodInfo* bestMethod = NULL;
    for (MethodInfo* methodInfo : methodInfos) {
        bool notAssignable = false;
        for (int i = 0;i < arguments.size();i++) {
            TypeInfo* paramTypeInfo = (i >= methodInfo->parameterInfos.size())
                ? methodInfo->parameterInfos.back()->typeInfo
                : methodInfo->parameterInfos[i]->typeInfo;
            if (not isAssignable(arguments[i]->typeInfo, paramTypeInfo)) {
                notAssignable = true;
                break;
            }
        }
        if (not notAssignable) {
            bestMethod = methodInfo;
            break;
        }
    }
    if (bestMethod) {
        return bestMethod;
    } else {
        // spdlog::get(ErrorManager::DebugTag)->warn("findBestMethod: error for method {}", methodInfos.front()->methodKey);
        return methodInfos.front();
    }
}
