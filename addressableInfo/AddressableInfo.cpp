#include "../util/util.h"
#include "GlobalInfo.h"
#include "../antlr/syntaxObject/JavaHeaderFile.h"
#include "AddressableInfo.h"
#include "../file/FileManager.h"
#include "SWI-cpp2.h"
#include "../GraphAttributes.h"
#include "../prolog/PrologConstructor.h"
#include "../antlr/syntaxObject/Modifier.h"

unordered_map<string, TypeInfo*> AddressableInfo::typeKey2typeInfo;

unordered_map<string, FieldInfo*> AddressableInfo::fieldKey2fieldInfo;

unordered_map<string, MethodInfo*> AddressableInfo::methodKey2MethodInfo;

map<string, CompilationUnit*> AddressableInfo::filePath2compilationUnits;

std::mutex AddressableInfo::addcompilationUnitLock;

string AddressableInfo::makeShortMethodName(const string& methodName, const string& parameterPartOfKey) {
    return methodName + "::" + parameterPartOfKey + ":";
}

string AddressableInfo::makeMethodKey(const string& typeKey, const string& methodName, const string& parameterPartOfKey) {
    return typeKey + "." + methodName + "::" + parameterPartOfKey + ":";
}

string AddressableInfo::makeParamKey(const string& methodKey, const string& paramName) {
    return methodKey + paramName;
}

string AddressableInfo::makeReturnKey(const string& methodKey) {
    return methodKey + "return";
}

string AddressableInfo::makeCalledKey(const string& key) {
    return key + "#";
}

string AddressableInfo::makeStepKey(const string& calledKey) {
    return calledKey + "-step";
}

string AddressableInfo::makeMethodIfKey(const string& methodKey) {
    return "if";
}

string AddressableInfo::makeMethodElseKey(const string& methodKey) {
    return "else";
}

string AddressableInfo::makeMethodForKey(const string& methodKey) {
    return "for";
}

string AddressableInfo::makeMethodWhileKey(const string& methodKey) {
    return "while";
}

string AddressableInfo::makeMethodCaseKey(const string& methodKey) {
    return "case";
}

string AddressableInfo::makeMethodSwitchKey(const string& methodKey) {
    return "switch";
}

string AddressableInfo::makeTypeParameterKey(const string& typeKey, const string& typeParamName) {
    return "<" + typeParamName + ">" + typeKey;
}

string AddressableInfo::makeMethodForEachKey(const string& methodKey) {
    return "each";
}

string AddressableInfo::makeMethodTryKey(const string& methodKey) {
    return "try";
}

string AddressableInfo::makeMethodCatchKey(const string& methodKey) {
    return "catch";
}

string AddressableInfo::makeMethodFinallyKey(const string& methodKey) {
    return "finally";
}

string AddressableInfo::makeAnonymousKey(const string& anonymousTypeName, const string& positionKey) {
    return anonymousTypeName + "(" + positionKey + ")";
}

void AddressableInfo::saveAddressableInfo() {
    for (auto& filePathAndTypeInfos : GlobalInfo::filePath2typeInfos) {
        PrologConstructor::saveAddressableInfo(filePathAndTypeInfos.first, filePathAndTypeInfos.second);
    }
}

void AddressableInfo::serializeHeader() {
    ofstream f;
    f.open(FileManager::headerSerializationFile);
    f << filePath2compilationUnits.size() << "\n";
    for (auto& compilationUnit : filePath2compilationUnits) {
        f << compilationUnit.first << "\n";
        compilationUnit.second->toFile(f);
    }
    f.close();
}

// will not restore if it is in updated file, or it is not in all file 
// this method will also add file to updated file list if it is not in the filePath2compilationUnits
void AddressableInfo::deserializeHeader() {
    ifstream f;
    f.open(FileManager::headerSerializationFile);
    if (not f.is_open()) {
        return;
    }
    int count = Serializable::getInt(f);
    for (int i = 0;i < count;i++) {
        string filePath;
        std::getline(f, filePath);
        CompilationUnit* compilationUnit = new CompilationUnit();
        compilationUnit->fromFile(f);
        if (FileManager::updatedFiles.count(filePath) or not FileManager::allFiles.count(filePath)) {
            continue;
        }
        filePath2compilationUnits[filePath] = compilationUnit;
    }
    f.close();
    for (auto& filePath : FileManager::allFiles) {
        if (not filePath2compilationUnits.count(filePath)) {
            FileManager::updatedFiles.insert(filePath);
        }
    }
}

TypeInfo* AddressableInfo::voidTypeInfo = NULL;
TypeInfo* AddressableInfo::nullTypeInfo = NULL;
TypeInfo* AddressableInfo::defaultValueTypeInfo = NULL;
TypeInfo* AddressableInfo::errorTypeInfo = NULL;
// the following type infos are assigned after first round
TypeInfo* AddressableInfo::iterableTypeInfo = NULL;
TypeInfo* AddressableInfo::iterableTypeParamInfo = NULL;
TypeInfo* AddressableInfo::classTypeParamInfo = NULL;
TypeInfo* AddressableInfo::stringTypeInfo = NULL;
TypeInfo* AddressableInfo::classTypeInfo = NULL;
TypeInfo* AddressableInfo::boolTypeInfo = NULL;
TypeInfo* AddressableInfo::charTypeInfo = NULL;
TypeInfo* AddressableInfo::intTypeInfo = NULL;
TypeInfo* AddressableInfo::floatTypeInfo = NULL;
TypeInfo* AddressableInfo::byteTypeInfo = NULL;
TypeInfo* AddressableInfo::shortTypeInfo = NULL;
TypeInfo* AddressableInfo::longTypeInfo = NULL;
TypeInfo* AddressableInfo::doubleTypeInfo = NULL;
map<string, TypeInfo*> AddressableInfo::primitiveType2TypeInfo;
TypeInfo* AddressableInfo::objectTypeInfo = NULL;
TypeInfo* AddressableInfo::enumTypeInfo = NULL;
set<TypeInfo*> AddressableInfo::numberTypes;

FieldInfo* AddressableInfo::arrayLengthdFieldInfo = NULL;

TypeName* AddressableInfo::enumTypeName = NULL;
TypeName* AddressableInfo::objectTypeName = NULL;

void AddressableInfo::beforeParseAll() {
    nullTypeInfo = new TypeInfo();
    nullTypeInfo->typeKey = "[NullType]";
    nullTypeInfo->typeName = "[NullType]";
    nullTypeInfo->simpletypeName = "[NullType]";

    defaultValueTypeInfo = new TypeInfo();
    defaultValueTypeInfo->typeKey = "[DefaultType]";
    defaultValueTypeInfo->typeName = "[DefaultType]";
    defaultValueTypeInfo->simpletypeName = "[DefaultType]";

    errorTypeInfo = new TypeInfo();
    errorTypeInfo->typeKey = "[ErrorType]";
    errorTypeInfo->typeName = "[ErrorType]";
    errorTypeInfo->simpletypeName = "[ErrorType]";

    voidTypeInfo = new TypeInfo();
    voidTypeInfo->typeKey = "void";
    voidTypeInfo->simpletypeName = "void";
    voidTypeInfo->typeName = "void";

    enumTypeName = new TypeName();
    enumTypeName->typeName = { "Enum" };
    objectTypeName = new TypeName();
    objectTypeName->typeName = { "Object" };

    deserializeHeader();
}

void AddressableInfo::afterFirstRound() {
    iterableTypeInfo = typeKey2typeInfo["java.lang.Iterable"];
    iterableTypeParamInfo = typeKey2typeInfo[makeTypeParameterKey("java.lang.Iterable", "T")];
    classTypeParamInfo = typeKey2typeInfo[makeTypeParameterKey("java.lang.Class", "T")];
    stringTypeInfo = typeKey2typeInfo["java.lang.String"];
    classTypeInfo = typeKey2typeInfo["java.lang.Class"];
    boolTypeInfo = typeKey2typeInfo["java.lang.Boolean"];
    charTypeInfo = typeKey2typeInfo["java.lang.Character"];
    intTypeInfo = typeKey2typeInfo["java.lang.Integer"];
    floatTypeInfo = typeKey2typeInfo["java.lang.Float"];
    byteTypeInfo = typeKey2typeInfo["java.lang.Byte"];
    shortTypeInfo = typeKey2typeInfo["java.lang.Short"];
    longTypeInfo = typeKey2typeInfo["java.lang.Long"];
    doubleTypeInfo = typeKey2typeInfo["java.lang.Double"];
    objectTypeInfo = typeKey2typeInfo["java.lang.Object"];
    enumTypeInfo = typeKey2typeInfo["java.lang.Enum"];

    primitiveType2TypeInfo["class"] = classTypeInfo;
    primitiveType2TypeInfo["boolean"] = boolTypeInfo;
    primitiveType2TypeInfo["char"] = charTypeInfo;
    primitiveType2TypeInfo["int"] = intTypeInfo;
    primitiveType2TypeInfo["float"] = floatTypeInfo;
    primitiveType2TypeInfo["byte"] = byteTypeInfo;
    primitiveType2TypeInfo["short"] = shortTypeInfo;
    primitiveType2TypeInfo["long"] = longTypeInfo;
    primitiveType2TypeInfo["double"] = doubleTypeInfo;
    primitiveType2TypeInfo["enum"] = enumTypeInfo;

    numberTypes.insert(intTypeInfo);
    numberTypes.insert(floatTypeInfo);
    numberTypes.insert(shortTypeInfo);
    numberTypes.insert(longTypeInfo);
    numberTypes.insert(doubleTypeInfo);

    arrayLengthdFieldInfo = new FieldInfo();
    arrayLengthdFieldInfo->name = "length";
    arrayLengthdFieldInfo->fieldKey = GlobalInfo::type_key_array + ".length";;
    arrayLengthdFieldInfo->typeInfo = intTypeInfo;
    fieldKey2fieldInfo[arrayLengthdFieldInfo->fieldKey] = arrayLengthdFieldInfo;

    auto* arrayTypeInfo = new TypeInfo();
    arrayTypeInfo->fieldInfos.insert(arrayLengthdFieldInfo);
    arrayTypeInfo->typeKey = GlobalInfo::type_key_array;
    arrayTypeInfo->simpletypeName = GlobalInfo::type_key_array;
    arrayTypeInfo->typeName = GlobalInfo::type_key_array;
    typeKey2typeInfo[GlobalInfo::type_key_array] = arrayTypeInfo;
}

void AddressableInfo::release() {
    for (auto& typeAndTypeInfo : typeKey2typeInfo) {
        delete typeAndTypeInfo.second;
    }
    for (auto& fieldAndMethodInfo : fieldKey2fieldInfo) {
        delete fieldAndMethodInfo.second;
    }
    for (auto& methodAndMethodInfo : methodKey2MethodInfo) {
        delete methodAndMethodInfo.second;
    }
    typeKey2typeInfo.clear();
    fieldKey2fieldInfo.clear();
    methodKey2MethodInfo.clear();
}

string MethodInfo::getParamPartOfKey() {
    list<string> paramNames;
    for (auto& paramInfo : parameterInfos) {
        paramNames.push_back(paramInfo->typeInfo->typeName);
    }
    return joinList(paramNames, ",");
}

list<MethodInfo*> TypeInfo::getConstructor(int paramCount) {
    list<MethodInfo*> ret;
    for (auto& constructorI : methodInfos) {
        if (constructorI->isConstructor and constructorI->parameterInfos.size() == paramCount) {
            ret.push_back(constructorI);
        }
    }
    return ret;
}

MethodInfo* TypeInfo::getOnlyMethodFromInterface() {
    int methodCount = 0;
    MethodInfo* m = NULL;
    for (MethodInfo* methodInfo : methodInfos) {
        if (not methodInfo->isConstructor and
            not Modifier::isDefault(methodInfo->flag) and
            not Modifier::isStatic(methodInfo->flag)) {
            methodCount++;
            m = methodInfo;
        }
    }
    if (methodCount == 1) {
        return m;
    }
    return nullptr;
}
