#include "../util/util.h"
#include "../addressableInfo/GlobalInfo.h"
#include "../antlr/syntaxObject/JavaHeaderFile.h"
#include "../addressableInfo/AddressableInfo.h"
#include "codestructure/CodeStructure.h"
#include "codestructure/Relation.h"
#include "codestructure/Sentence.h"
#include "codestructure/CodeBlock.h"
#include "codestructure/SplitCodeBlocks.h"
#include "type/TypeCheckAndInference.h"
#include "ScopeAndEnv.h"
#include "../error/ErrorManager.h"
#include "../antlr/syntaxObject/Modifier.h"

map<string, PackageScopeAndEnv*> PackageScopeAndEnv::package2scopeAndEnv;
map<string, FileScopeAndEnv*> FileScopeAndEnv::filePath2scopeAndEnv;

const string PackageScopeAndEnv::langPackage = "java.lang";

void PackageScopeAndEnv::addScopeAndEnvForAllPackage() {
    for (auto& package2typeKeys : GlobalInfo::NAME_FILE_TO(package2typeKeys)) {
        for (auto& item : package2typeKeys.second) {
            PackageScopeAndEnv::package2scopeAndEnv[item.first] = new PackageScopeAndEnv(item.first);
        }
    }
    for (auto& item : AddressableInfo::typeKey2typeInfo) {
        auto* typeInfo = item.second;
        if (typeInfo->outerTypeInfo == NULL) {
            auto* pPackageScopeAndEnv = PackageScopeAndEnv::package2scopeAndEnv[typeInfo->package];
            if (pPackageScopeAndEnv) {
                if (not typeInfo->isTypeParam) {
                    pPackageScopeAndEnv->name2typeInPackage[typeInfo->simpletypeName] = typeInfo;
                }
            } else {
                spdlog::get(ErrorManager::DebugTag)->warn("did not find package: {}", typeInfo->package);
            }
        }
    }
}

PackageScopeAndEnv::PackageScopeAndEnv(const string& package) {
    this->package = package;
}

void PackageScopeAndEnv::release() {
    for (auto& packageAndScopeEnv : package2scopeAndEnv) {
        if (packageAndScopeEnv.second != nullptr) {
            packageAndScopeEnv.second->name2typeInPackage.clear();
            delete packageAndScopeEnv.second;
        }
    }
    package2scopeAndEnv.clear();
}

void FileScopeAndEnv::addImportedTypeNameScopeAndEnvForAllFile() {
    map<string, set<string>> package2typeKeys;
    for (auto& fileAndPackgeAndTypeKeys : GlobalInfo::NAME_FILE_TO(package2typeKeys)) {
        for (auto& packageAndTypeKeys : fileAndPackgeAndTypeKeys.second) {
            if (not package2typeKeys.count(packageAndTypeKeys.first)) {
                package2typeKeys[packageAndTypeKeys.first] = set<string>();
            }
            for (auto& typeKey : packageAndTypeKeys.second) {
                package2typeKeys[packageAndTypeKeys.first].insert(typeKey);
            }
        }
    }
    for (auto& file : AddressableInfo::filePath2compilationUnits) {
        filePath2scopeAndEnv[file.first] = new FileScopeAndEnv(file.first);
        auto& pFileScopeAndEnv = filePath2scopeAndEnv[file.first];
        for (auto& importedType : file.second->importedTypes) {
            if (AddressableInfo::typeKey2typeInfo.count(importedType) > 0) {
                TypeInfo*& pTypeInfo = AddressableInfo::typeKey2typeInfo[importedType];
                pFileScopeAndEnv->name2nameImportedType[pTypeInfo->simpletypeName] = pTypeInfo;
            }
        }
        for (auto& importedPackageOrType : file.second->importedPackageOrType) {
            if (package2typeKeys.count(importedPackageOrType)) {
                for (auto& importedType : package2typeKeys[importedPackageOrType]) {
                    if (AddressableInfo::typeKey2typeInfo.count(importedType)) {
                        auto*& pTypeInfo = AddressableInfo::typeKey2typeInfo[importedType];
                        if (pTypeInfo->outerTypeInfo == NULL) {
                            pFileScopeAndEnv->name2starImportedType[pTypeInfo->simpletypeName] = pTypeInfo;
                        }
                    }
                }
            }
            if (AddressableInfo::typeKey2typeInfo.count(importedPackageOrType)) {
                auto*& typeInfo = AddressableInfo::typeKey2typeInfo[importedPackageOrType];
                for (auto& innerTypeInfo : typeInfo->innerTypeInfos) {
                    if (Modifier::isStatic(innerTypeInfo->flag) && not Modifier::isPrivate(innerTypeInfo->flag)) {
                        pFileScopeAndEnv->name2nameImportedType[innerTypeInfo->simpletypeName] = innerTypeInfo;
                    }
                }
            }
        }
        // static import static inner class
        for (auto& innerTypeKey : file.second->staticImported) {
            if (AddressableInfo::typeKey2typeInfo.count(innerTypeKey)) {
                auto*& innerTypeInfo = AddressableInfo::typeKey2typeInfo[innerTypeKey];
                pFileScopeAndEnv->name2nameImportedType[innerTypeInfo->simpletypeName] = innerTypeInfo;
            }
        }
        // static import static inner class
        for (auto& importedTypeKey : file.second->starStaticImported) {
            if (AddressableInfo::typeKey2typeInfo.count(importedTypeKey)) {
                auto*& typeInfo = AddressableInfo::typeKey2typeInfo[importedTypeKey];
                for (auto& innerTypeInfo : typeInfo->innerTypeInfos) {
                    if (Modifier::isStatic(innerTypeInfo->flag) && not Modifier::isPrivate(innerTypeInfo->flag)) {
                        pFileScopeAndEnv->name2nameImportedType[innerTypeInfo->simpletypeName] = innerTypeInfo;
                    }
                }
            }
        }
    }
}

void FileScopeAndEnv::addImportedFieldAndMethodNameScopeAndEnvForAllFile() {
    for (auto& file : AddressableInfo::filePath2compilationUnits) {
        auto& pFileScopeAndEnv = filePath2scopeAndEnv[file.first];
        for (auto& memberKey : file.second->staticImported) {
            if (AddressableInfo::fieldKey2fieldInfo.count(memberKey)) {
                // static import static field
                auto* fieldInfo = AddressableInfo::fieldKey2fieldInfo[memberKey];
                if (Modifier::isStatic(fieldInfo->flag)) {
                    pFileScopeAndEnv->name2nameImportedField[fieldInfo->name] = fieldInfo;
                }
            }
            list<string> maybeMethod;
            splitStr(memberKey, ".", maybeMethod);
            string methodName = maybeMethod.back();
            maybeMethod.pop_back();
            string typeKey = joinList(maybeMethod, ".");
            if (AddressableInfo::typeKey2typeInfo.count(typeKey)) {
                TypeInfo* typeInfo = AddressableInfo::typeKey2typeInfo[typeKey];
                if (typeInfo->classScopeAndEnv->name2method.count(methodName)) {
                    // static import static method
                    pFileScopeAndEnv->name2nameImportedMethod[methodName] = list<MethodInfo*>();
                    for (auto*& methodInfo : typeInfo->classScopeAndEnv->name2method[methodName]) {
                        if (Modifier::isStatic(methodInfo->flag)) {
                            pFileScopeAndEnv->name2nameImportedMethod[methodInfo->name].push_back(methodInfo);
                        }
                    }
                }
            }
        }
        for (auto& importedTypeKey : file.second->starStaticImported) {
            if (AddressableInfo::typeKey2typeInfo.count(importedTypeKey)) {
                auto*& typeInfo = AddressableInfo::typeKey2typeInfo[importedTypeKey];
                for (auto& fieldInfo : typeInfo->classScopeAndEnv->name2fieldInfo) {
                    if (Modifier::isStatic(fieldInfo.second->flag) && not Modifier::isPrivate(fieldInfo.second->flag)) {
                        pFileScopeAndEnv->name2starImportField[fieldInfo.first] = fieldInfo.second;
                    }
                }
                for (auto& methodInfos : typeInfo->classScopeAndEnv->name2method) {
                    for (auto& methodInfo : methodInfos.second) {
                        if (Modifier::isStatic(methodInfo->flag) && not Modifier::isPrivate(methodInfo->flag)) {
                            if (pFileScopeAndEnv->name2starImportedMethod.count(methodInfos.first) == 0) {
                                pFileScopeAndEnv->name2starImportedMethod[methodInfos.first] = list<MethodInfo*>();
                            }
                            pFileScopeAndEnv->name2starImportedMethod[methodInfos.first].push_back(methodInfo);
                        }
                    }
                }
            }
        }
    }
}

FileScopeAndEnv::FileScopeAndEnv(const string& filePath) {
    this->filePath = filePath;
}

void FileScopeAndEnv::release() {
    for (auto& filePathAndScopeEnv : filePath2scopeAndEnv) {
        if (filePathAndScopeEnv.second != nullptr) {
            filePathAndScopeEnv.second->name2nameImportedType.clear();
            filePathAndScopeEnv.second->name2starImportedType.clear();
            filePathAndScopeEnv.second->name2nameImportedField.clear();
            filePathAndScopeEnv.second->name2starImportField.clear();
            filePathAndScopeEnv.second->name2nameImportedMethod.clear();
            filePathAndScopeEnv.second->name2starImportedMethod.clear();
            delete filePathAndScopeEnv.second;
        }
    }
    filePath2scopeAndEnv.clear();
}

TypeInfo* OuterScopeAndEnv::getTypeInfoRecurOuterScope(const string& typeName) {
    if (outerScopeAndEnv) {
        TypeInfo* sofar = outerScopeAndEnv->getTypeInfoFromSelf(typeName);
        if (not sofar) {
            sofar = outerScopeAndEnv->getTypeInfoRecurOuterScope(typeName);
        }
        return sofar;
    }
    return NULL;
}

FieldInfo* OuterScopeAndEnv::getFieldInfoRecurOuterScope(const string& fieldName) {
    if (outerScopeAndEnv) {
        FieldInfo* sofar = outerScopeAndEnv->getFieldInfoFromSelf(fieldName);
        if (not sofar) {
            sofar = outerScopeAndEnv->getFieldInfoRecurOuterScope(fieldName);
        }
        return sofar;
    }
    return NULL;
}

void OuterScopeAndEnv::getMethodInfoRecurOuterScope(const string& name, int paramCount, list<MethodInfo*>& methodInfos) {
    if (outerScopeAndEnv) {
        outerScopeAndEnv->getMethodInfoFromSelf(name, paramCount, methodInfos);
        outerScopeAndEnv->getMethodInfoRecurOuterScope(name, paramCount, methodInfos);
    }
}

bool OuterScopeAndEnv::findIdRecurOuterScope(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, MethodScopeAndEnv* runtimeMethod, map<TypeInfo*, TypeInfo*>* typeArgs) {
    if (outerScopeAndEnv) {
        if (outerScopeAndEnv->findIdFromSelf(name, key, typeInfo, keyType, runtimeMethod, typeArgs)) {
            return true;
        }
        if (outerScopeAndEnv->findIdRecurOuterScope(name, key, typeInfo, keyType, runtimeMethod, typeArgs)) {
            return true;
        }
    }
    return false;
}


ClassScopeAndEnv::ClassScopeAndEnv(TypeInfo* typeInfo) {
    this->typeInfo = typeInfo;
}

MethodInfo* ClassScopeAndEnv::findOverrideMethod(MethodInfo* methodInfo) {
    if (methodInfo->isConstructor) {
        return NULL;
    }
    list<MethodInfo*> methodInfos;
    for (auto* superScopeAndEnv : superScopeAndEnvs) {
        superScopeAndEnv->getMethodInfoFromSelf(methodInfo->name, methodInfo->parameterInfos.size(), methodInfos);
    }
    for (auto& superMethodInfo : methodInfos) {
        if (not methodInfo->isVariableParameter ^ superMethodInfo->isVariableParameter and methodInfo->parameterInfos.size() == superMethodInfo->parameterInfos.size()) {
            bool found = true;
            for (int paramIndex = 0;paramIndex < methodInfo->parameterInfos.size();paramIndex++) {
                if (methodInfo->parameterInfos[paramIndex]->typeInfo != superMethodInfo->parameterInfos[paramIndex]->typeInfo or
                    methodInfo->parameterInfos[paramIndex]->dim != superMethodInfo->parameterInfos[paramIndex]->dim) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return superMethodInfo;
            }
        }
    }
    return nullptr;
}

void ClassScopeAndEnv::addClassScopeAndEnvForAllTypes() {
    PackageScopeAndEnv* langPackageScopeAndEnv = nullptr;
    if (PackageScopeAndEnv::package2scopeAndEnv.count(PackageScopeAndEnv::langPackage) > 0) {
        langPackageScopeAndEnv = PackageScopeAndEnv::package2scopeAndEnv[PackageScopeAndEnv::langPackage];
    }
    for (auto& item : AddressableInfo::typeKey2typeInfo) {
        auto& typeInfo = item.second;
        typeInfo->classScopeAndEnv = new ClassScopeAndEnv(typeInfo);
        // "class" field
        auto* classFieldInfo = new FieldInfo;
        classFieldInfo->name = "class";
        classFieldInfo->fieldKey = typeInfo->typeKey + ".class";
        classFieldInfo->typeInfo = AddressableInfo::classTypeInfo;
        classFieldInfo->typeParam2typeArg[AddressableInfo::classTypeParamInfo] = typeInfo;
        classFieldInfo->flag = Modifier::PUBLIC;
        AddressableInfo::fieldKey2fieldInfo[classFieldInfo->fieldKey] = classFieldInfo;
        typeInfo->fieldInfos.insert(classFieldInfo);
    }
    for (auto& item : AddressableInfo::typeKey2typeInfo) {
        TypeInfo* typeInfo = item.second;
        auto* classScopeAndEnv = typeInfo->classScopeAndEnv;
        classScopeAndEnv->langPackageScopeAndEnv = langPackageScopeAndEnv;
        if (PackageScopeAndEnv::package2scopeAndEnv.count(typeInfo->package) > 0) {
            classScopeAndEnv->packageScopeAndEnv = PackageScopeAndEnv::package2scopeAndEnv[typeInfo->package];
        }
        if (FileScopeAndEnv::filePath2scopeAndEnv.count(typeInfo->filePath) > 0) {
            classScopeAndEnv->fileScopeAndEnv = FileScopeAndEnv::filePath2scopeAndEnv[typeInfo->filePath];
        }
        for (auto& innerTypeInfo : typeInfo->innerTypeInfos) {
            innerTypeInfo->classScopeAndEnv->outerScopeAndEnv = classScopeAndEnv;
            classScopeAndEnv->name2typeInfo[innerTypeInfo->simpletypeName] = innerTypeInfo;
        }
        for (auto& typeParamInfo : typeInfo->typeParamInfos) {
            classScopeAndEnv->name2typeParamInfo[typeParamInfo->simpletypeName] = typeParamInfo;
        }
        classScopeAndEnv->name2typeInfo[typeInfo->simpletypeName] = typeInfo;
    }
    AddressableInfo::primitive_boolTypeInfo->classScopeAndEnv = AddressableInfo::boolTypeInfo->classScopeAndEnv;
    AddressableInfo::primitive_charTypeInfo->classScopeAndEnv = AddressableInfo::charTypeInfo->classScopeAndEnv;
    AddressableInfo::primitive_intTypeInfo->classScopeAndEnv = AddressableInfo::intTypeInfo->classScopeAndEnv;
    AddressableInfo::primitive_floatTypeInfo->classScopeAndEnv = AddressableInfo::floatTypeInfo->classScopeAndEnv;
    AddressableInfo::primitive_byteTypeInfo->classScopeAndEnv = AddressableInfo::byteTypeInfo->classScopeAndEnv;
    AddressableInfo::primitive_shortTypeInfo->classScopeAndEnv = AddressableInfo::shortTypeInfo->classScopeAndEnv;
    AddressableInfo::primitive_longTypeInfo->classScopeAndEnv = AddressableInfo::longTypeInfo->classScopeAndEnv;
    AddressableInfo::primitive_doubleTypeInfo->classScopeAndEnv = AddressableInfo::doubleTypeInfo->classScopeAndEnv;
    AddressableInfo::primitive_enumTypeInfo->classScopeAndEnv = AddressableInfo::enumTypeInfo->classScopeAndEnv;
}

void ClassScopeAndEnv::linkSuperScopeAndEnv(TypeInfo* typeInfo, TypeInfo* superTypeInfo) {
    if (not Modifier::isInterfaceType(superTypeInfo->flag)) {
        auto* superFieldInfo = new FieldInfo;
        superFieldInfo->name = "super";
        superFieldInfo->fieldKey = typeInfo->typeKey + ".super";
        superFieldInfo->typeInfo = superTypeInfo;
        superFieldInfo->flag = Modifier::PUBLIC;
        AddressableInfo::fieldKey2fieldInfo[superFieldInfo->fieldKey] = superFieldInfo;
        typeInfo->fieldInfos.insert(superFieldInfo);
    }
    typeInfo->classScopeAndEnv->superScopeAndEnvs.push_back(superTypeInfo->classScopeAndEnv);
}

void ClassScopeAndEnv::addFieldAndMethodNamesForAllTypes() {
    for (auto& item : AddressableInfo::typeKey2typeInfo) {
        auto*& classScopeAndEnv = item.second->classScopeAndEnv;
        for (auto& fieldInfo : item.second->fieldInfos) {
            classScopeAndEnv->name2fieldInfo[fieldInfo->name] = fieldInfo;
        }
        for (auto& methodInfo : item.second->methodInfos) {
            if (not classScopeAndEnv->name2method.count(methodInfo->name)) {
                classScopeAndEnv->name2method[methodInfo->name] = list<MethodInfo*>();
            }
            classScopeAndEnv->name2method[methodInfo->name].push_back(methodInfo);
        }
    }
}

PackageScopeAndEnv* ClassScopeAndEnv::getPackageScope() {
    return packageScopeAndEnv;
}

FileScopeAndEnv* ClassScopeAndEnv::getFileScope() {
    return fileScopeAndEnv;
}

TypeInfo* ClassScopeAndEnv::getTypeInfoWithFileScope(const list<string>& typeNames) {
    TypeInfo* typeInfoSoFar = nullptr;
    ClassScopeAndEnv* scopeAndEnv = this;
    bool firstTypeName = true;
    for (auto& typeName : typeNames) {
        // inner class and super class
        typeInfoSoFar = scopeAndEnv->getTypeInfoFromSelf(typeName);
        // outer class
        if (firstTypeName and not typeInfoSoFar) {
            typeInfoSoFar = getTypeInfoRecurOuterScope(typeName);
        }
        // imported class
        if (firstTypeName && not typeInfoSoFar) {
            typeInfoSoFar = getTypeInfoFromImports(typeName);
        }
        // after resolve one of type names, change scopeAndEnv
        if (typeInfoSoFar != nullptr) {
            scopeAndEnv = typeInfoSoFar->classScopeAndEnv;
        } else {
            break;
        }
        firstTypeName = false;
    }
    if (not typeInfoSoFar) {
        // type name is actually full path
        string maybeFullPath = joinList(typeNames, ".");
        if (AddressableInfo::typeKey2typeInfo.count(maybeFullPath)) {
            return AddressableInfo::typeKey2typeInfo[maybeFullPath];
        }
    }
    return typeInfoSoFar;
}

void ClassScopeAndEnv::getMethodInfoWithFileScope(const list<string>& names, int paramCount, list<MethodInfo*>& methodInfos, bool creator) {
    if (creator) {
        auto* typeInfo = getTypeInfoWithFileScope(names);
        if (not typeInfo) {
            return;
        }
        typeInfo->classScopeAndEnv->getMethodInfoFromSelf(names.back(), paramCount, methodInfos);
    } else {
        if (names.size() == 1) {
            getMethodInfoFromSelf(names.back(), paramCount, methodInfos);
            getMethodInfoRecurOuterScope(names.back(), paramCount, methodInfos);
            getMethodInfoFromImports(names.back(), paramCount, methodInfos);
        } else {
            spdlog::get(ErrorManager::DebugTag)->error("did not find getMethodInfo: {}", joinList(names, "."));
            // the case for names.size() > 1 should not exist
        }
    }
}

bool ClassScopeAndEnv::findIdFromSelf(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, MethodScopeAndEnv* runtimeMethod, map<TypeInfo*, TypeInfo*>* typeArgs) {
    auto* fieldInfo = getFieldInfoFromSelf(name);
    if (fieldInfo != nullptr) {
        key = fieldInfo->fieldKey;
        typeInfo = fieldInfo->typeInfo;
        keyType = GlobalInfo::KEY_TYPE_FIELD;
        runtimeMethod->addUsage(fieldInfo);
        return true;
    }
    TypeInfo* pTypeInfo = getTypeInfoFromSelf(name);
    if (pTypeInfo != nullptr) {
        key = pTypeInfo->typeKey;
        typeInfo = pTypeInfo;
        keyType = GlobalInfo::KEY_TYPE_CLASS;
        return true;
    }
    if (name == AddressableInfo::arrayLengthdFieldInfo->name) {
        key = AddressableInfo::arrayLengthdFieldInfo->fieldKey;
        typeInfo = AddressableInfo::arrayLengthdFieldInfo->typeInfo;
        keyType = GlobalInfo::KEY_TYPE_FIELD;
        return true;
    }
    return false;
}

TypeInfo* ClassScopeAndEnv::getTypeInfoFromSelf(const string& typeName) {
    TypeInfo* typeInfoSoFar = nullptr;
    // first: this class and inner class of this class
    if (name2typeInfo.count(typeName)) {
        typeInfoSoFar = name2typeInfo[typeName];
    }
    // second: type parameter
    if (not typeInfoSoFar and name2typeParamInfo.count(typeName)) {
        typeInfoSoFar = name2typeParamInfo[typeName];
    }
    // third: super class and inner class of super class
    if (not typeInfoSoFar) {
        for (auto* superScopeAndEnv : superScopeAndEnvs) {
            typeInfoSoFar = superScopeAndEnv->getTypeInfoFromSelf(typeName);
            if (typeInfoSoFar and (
                Modifier::isPrivate(typeInfoSoFar->flag) or
                typeInfoSoFar->isTypeParam or
                typeInfoSoFar == superScopeAndEnv->typeInfo)) {
                typeInfoSoFar = NULL;
            }
            if (typeInfoSoFar) {
                break;
            }
        }
    }
    return typeInfoSoFar;
}

FieldInfo* ClassScopeAndEnv::getFieldInfoFromSelf(const string& fieldName) {
    FieldInfo* fieldInfoSoFar = nullptr;
    // field of this class
    if (name2fieldInfo.count(fieldName) > 0) {
        fieldInfoSoFar = name2fieldInfo[fieldName];
    }
    // field of super class
    if (fieldInfoSoFar == nullptr) {
        for (auto* superScopeAndEnv : superScopeAndEnvs) {
            fieldInfoSoFar = superScopeAndEnv->getFieldInfoFromSelf(fieldName);
            if (fieldInfoSoFar != nullptr) {
                break;
            }
        }
    }
    return fieldInfoSoFar;
}

void ClassScopeAndEnv::getMethodInfoFromSelf(const string& name, int paramCount, list<MethodInfo*>& methodInfos) {
    if (name2method.count(name) > 0) {
        list<MethodInfo*>& pMethodInfoList = name2method[name];
        for (auto& pMethodInfo : pMethodInfoList) {
            if (TypeCheckAndInference::methodParamCountCheck(pMethodInfo, paramCount)) {
                methodInfos.push_back(pMethodInfo);
            }
        }
    }
    for (auto* superScopeAndEnv : superScopeAndEnvs) {
        superScopeAndEnv->getMethodInfoFromSelf(name, paramCount, methodInfos);
    }
}

TypeInfo* ClassScopeAndEnv::getTypeInfoFromImports(const string& typeName) {
    TypeInfo* typeKeySoFar = nullptr;
    // primitive type
    if (AddressableInfo::primitiveType2TypeInfo.count(typeName) > 0) {
        typeKeySoFar = AddressableInfo::primitiveType2TypeInfo[typeName];
    }
    // name imported type
    if (fileScopeAndEnv != nullptr && fileScopeAndEnv->name2nameImportedType.count(typeName) > 0) {
        typeKeySoFar = fileScopeAndEnv->name2nameImportedType[typeName];
    }
    // type from same package
    if (typeKeySoFar == nullptr && packageScopeAndEnv != nullptr && packageScopeAndEnv->name2typeInPackage.count(typeName) > 0) {
        typeKeySoFar = packageScopeAndEnv->name2typeInPackage[typeName];
    }
    // start imported type
    if (typeKeySoFar == nullptr && fileScopeAndEnv != nullptr && fileScopeAndEnv->name2starImportedType.count(typeName) > 0) {
        typeKeySoFar = fileScopeAndEnv->name2starImportedType[typeName];
    }
    // type in lang package
    if (typeKeySoFar == nullptr && langPackageScopeAndEnv != nullptr && langPackageScopeAndEnv->name2typeInPackage.count(typeName) > 0) {
        typeKeySoFar = langPackageScopeAndEnv->name2typeInPackage[typeName];
    }
    // void
    if (typeKeySoFar == nullptr and typeName == AddressableInfo::voidTypeInfo->typeName) {
        typeKeySoFar = AddressableInfo::voidTypeInfo;
    }
    return typeKeySoFar;
}

FieldInfo* ClassScopeAndEnv::getFieldInfoFromImports(const string& fieldName) {
    FieldInfo* fieldKeySorFar = nullptr;
    if (fileScopeAndEnv != nullptr && fileScopeAndEnv->name2nameImportedField.count(fieldName) > 0) {
        fieldKeySorFar = fileScopeAndEnv->name2nameImportedField[fieldName];
    }
    if (fieldKeySorFar == nullptr && fileScopeAndEnv != nullptr && fileScopeAndEnv->name2starImportField.count(fieldName) > 0) {
        fieldKeySorFar = fileScopeAndEnv->name2nameImportedField[fieldName];
    }
    return fieldKeySorFar;
}

void ClassScopeAndEnv::getMethodInfoFromImports(const string& name, int paramCount, list<MethodInfo*>& methodInfos) {
    if (fileScopeAndEnv != nullptr) {
        if (fileScopeAndEnv->name2nameImportedMethod.count(name) > 0) {
            for (auto*& pMethodInfo : fileScopeAndEnv->name2nameImportedMethod[name]) {
                if (TypeCheckAndInference::methodParamCountCheck(pMethodInfo, paramCount)) {
                    methodInfos.push_back(pMethodInfo);
                }
            }
        }
        if (fileScopeAndEnv->name2starImportedMethod.count(name) > 0) {
            for (auto*& pMethodInfo : fileScopeAndEnv->name2starImportedMethod[name]) {
                if (TypeCheckAndInference::methodParamCountCheck(pMethodInfo, paramCount)) {
                    methodInfos.push_back(pMethodInfo);
                }
            }
        }
    }

}

void ClassScopeAndEnv::release(ClassScopeAndEnv* toBeReleased) {
    delete toBeReleased;
}

const string MethodScopeAndEnv::rootStructureKey = "0,0,0";
const char MethodScopeAndEnv::structureKeySeparator = ':';

MethodScopeAndEnv* MethodScopeAndEnv::createMethodScopeAndEnv(const string& methodKey, ClassScopeAndEnv* classScopeAndEnv) {
    auto* pMethodScopeAndEnv = new MethodScopeAndEnv();
    pMethodScopeAndEnv->methodKey = methodKey;
    pMethodScopeAndEnv->methodIfKey = AddressableInfo::makeMethodIfKey(methodKey);
    pMethodScopeAndEnv->methodElseKey = AddressableInfo::makeMethodElseKey(methodKey);
    pMethodScopeAndEnv->methodForKey = AddressableInfo::makeMethodForKey(methodKey);
    pMethodScopeAndEnv->methodWhileKey = AddressableInfo::makeMethodWhileKey(methodKey);
    pMethodScopeAndEnv->methodCaseKey = AddressableInfo::makeMethodCaseKey(methodKey);
    pMethodScopeAndEnv->methodForEachKey = AddressableInfo::makeMethodForEachKey(methodKey);
    pMethodScopeAndEnv->methodTryKey = AddressableInfo::makeMethodTryKey(methodKey);
    pMethodScopeAndEnv->methodCatchKey = AddressableInfo::makeMethodCatchKey(methodKey);
    pMethodScopeAndEnv->methodFinallyKey = AddressableInfo::makeMethodFinallyKey(methodKey);
    pMethodScopeAndEnv->outerScopeAndEnv = classScopeAndEnv;
    auto* methodInfo = AddressableInfo::methodKey2MethodInfo[methodKey];
    for (auto& paramInfo : methodInfo->parameterInfos) {
        pMethodScopeAndEnv->name2paramInfo[paramInfo->name] = paramInfo;
    }
    for (auto& typeParamInfo : methodInfo->typeParamInfos) {
        pMethodScopeAndEnv->name2typeParamInfo[typeParamInfo->simpletypeName] = typeParamInfo;
    }
    pMethodScopeAndEnv->returnFieldInfo = AddressableInfo::fieldKey2fieldInfo[AddressableInfo::makeReturnKey(methodKey)];
    pMethodScopeAndEnv->methodInfo = methodInfo;
    return pMethodScopeAndEnv;
}

bool MethodScopeAndEnv::findIdWithFileScope(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, MethodScopeAndEnv* runtimeMethod, map<TypeInfo*, TypeInfo*>* typeArgs) {
    // found in this method
    if (findIdFromSelf(name, key, typeInfo, keyType, runtimeMethod, typeArgs)) {
        return true;
    }
    // found in outer scope
    if (findIdRecurOuterScope(name, key, typeInfo, keyType, runtimeMethod, typeArgs)) {
        return true;
    }
    // found in imported
    auto classScopeAndEnv = dynamic_cast<ClassScopeAndEnv*>(outerScopeAndEnv);
    auto* pTypeInfo = classScopeAndEnv->getTypeInfoFromImports(name);
    if (pTypeInfo) {
        key = pTypeInfo->typeKey;
        typeInfo = pTypeInfo;
        keyType = GlobalInfo::KEY_TYPE_CLASS;
        return true;
    }
    auto* fieldInfo = classScopeAndEnv->getFieldInfoFromImports(name);
    if (fieldInfo) {
        key = fieldInfo->fieldKey;
        typeInfo = fieldInfo->typeInfo;
        keyType = GlobalInfo::KEY_TYPE_FIELD;
        addUsage(fieldInfo);
        return true;
    }
    return false;
}

bool MethodScopeAndEnv::findIdFromSelf(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, MethodScopeAndEnv* runtimeMethod, map<TypeInfo*, TypeInfo*>* typeArgs) {
    for (CodeBlockScopeAndEnv* codeBlockScopeAndEnv : codeBlockScopeAndEnvs) {
        if (key.empty() && codeBlockScopeAndEnv->LVName2LVKey.count(name) > 0) {
            key = codeBlockScopeAndEnv->LVName2LVKey[name];
        }
    }
    if (!key.empty()) {
        typeInfo = LVKey2LVTypeInfo[key];
        keyType = GlobalInfo::KEY_TYPE_LOCAL_VARIABLE;
        if (typeArgs and lv2typeParam2typeArg.count(key)) {
            (*typeArgs) = lv2typeParam2typeArg[key];
        }
        return true;
    }
    if (name2paramInfo.count(name) > 0) {
        FieldInfo*& pInfo = name2paramInfo[name];
        key = pInfo->fieldKey;
        typeInfo = pInfo->typeInfo;
        keyType = GlobalInfo::KEY_TYPE_METHOD_PARAMETER;
        return true;
    }
    return false;
}

TypeInfo* MethodScopeAndEnv::getTypeInfoWithFileScope(const list<string>& typeNames) {
    if (typeNames.size() == 1 and name2typeParamInfo.count(typeNames.back())) {
        return name2typeParamInfo[typeNames.back()];
    } else {
        auto classScopeAndEnv = dynamic_cast<ClassScopeAndEnv*>(outerScopeAndEnv);
        return classScopeAndEnv->getTypeInfoWithFileScope(typeNames);
    }
}

PackageScopeAndEnv* MethodScopeAndEnv::getPackageScope() {
    return outerScopeAndEnv->getPackageScope();
}

FileScopeAndEnv* MethodScopeAndEnv::getFileScope() {
    return outerScopeAndEnv->getFileScope();
}

TypeInfo* MethodScopeAndEnv::getTypeInfoFromSelf(const string& typeName) {
    return NULL;
}

FieldInfo* MethodScopeAndEnv::getFieldInfoFromSelf(const string& fieldName) {
    return NULL;
}

void MethodScopeAndEnv::getMethodInfoFromSelf(const string& name, int paramCount, list<MethodInfo*>& methodInfos) {

}

string MethodScopeAndEnv::putLocalVariable(const string& name, TypeInfo* typeInfo, const string& structureKey) {
    string lvShortKey = structureKey + "-" + name;
    codeBlockScopeAndEnvs.front()->LVName2LVKey[name] = lvShortKey;
    LVKey2LVTypeInfo[lvShortKey] = typeInfo;
    return lvShortKey;
}

void MethodScopeAndEnv::addUsage(MethodInfo* usedMethodInfo) {
    GlobalInfo::addUsageLock.lock();
    GlobalInfo::NAME_FILE_TO(MethodUseMethods)[getFileScope()->filePath][methodKey].insert(usedMethodInfo->methodKey);
    GlobalInfo::addUsageLock.unlock();
}

void MethodScopeAndEnv::addUsage(FieldInfo* usedFieldInfo) {
    GlobalInfo::addUsageLock.lock();
    GlobalInfo::NAME_FILE_TO(MethodUseFields)[getFileScope()->filePath][methodKey].insert(usedFieldInfo->fieldKey);
    GlobalInfo::addUsageLock.unlock();
}

string MethodScopeAndEnv::getSupStructureKey(const string& structureKey) {
    int splitPos = structureKey.rfind(structureKeySeparator);
    return structureKey.substr(0, splitPos);
}

void TypeUnification::resolveTypeParam(TypeInfo* typeParam, set<TypeInfo*>& done) {
    if (immediateTypeArgs.count(typeParam)) {
        return;
    }
    if (done.count(typeParam)) {
        return;
    }
    done.insert(typeParam);
    if (intermediateTypeArgs.count(typeParam)) {
        auto& mapped = intermediateTypeArgs[typeParam];
        for (auto& mappedI : mapped) {
            resolveTypeParam(mappedI, done);
            if (immediateTypeArgs.count(mappedI)) {
                immediateTypeArgs[typeParam] = immediateTypeArgs[mappedI];
            }
        }
    }
}

TypeInfo* TypeUnification::getTypeArgFromTypeParam(TypeInfo* typeParam) {
    set<TypeInfo*> done;
    resolveTypeParam(typeParam, done);
    if (immediateTypeArgs.count(typeParam)) {
        return immediateTypeArgs[typeParam];
    } else {
        done.clear();
        auto ret = getTyepBoundForTypeParam(typeParam, done);
        if (ret) {
            return ret;
        }
    }
    return AddressableInfo::objectTypeInfo;
}

TypeInfo* TypeUnification::getTyepBoundForTypeParam(TypeInfo* typeParam, set<TypeInfo*>& done) {
    if (done.count(typeParam)) {
        return NULL;
    }
    done.insert(typeParam);
    if (typeParam->boundNameForTypeParam and not typeParam->boundInfoForTypeParam) {
        typeParam->boundInfoForTypeParam = typeParam->scopeTypeInfo->classScopeAndEnv->getTypeInfoWithFileScope(typeParam->boundNameForTypeParam->typeName);
    }
    if (typeParam->boundInfoForTypeParam) {
        return typeParam->boundInfoForTypeParam;
    }
    if (intermediateTypeArgs.count(typeParam)) {
        for (auto& I : intermediateTypeArgs[typeParam]) {
            auto ret = getTyepBoundForTypeParam(I, done);
            if (ret) {
                return ret;
            }
        }
    }
    return nullptr;
}

void TypeUnification::addTypeMap(TypeInfo* from, TypeInfo* to) {
    if (not from or not to) {
        return;
    }
    // simple circle check
    if (from == to) {
        return;
    }
    if (to->isTypeParam) {
        if (not intermediateTypeArgs.count(from)) {
            intermediateTypeArgs[from] = set<TypeInfo*>();
        }
        if (not intermediateTypeArgs.count(to)) {
            intermediateTypeArgs[to] = set<TypeInfo*>();
        }
        intermediateTypeArgs[from].insert(to);
        intermediateTypeArgs[to].insert(from);
    } else {
        immediateTypeArgs[from] = to;
    }
    if (from->isTypeParam) {
        if (not from->scopeTypeInfo->typeArgNamesForSuper.empty() and from->scopeTypeInfo->typeArgInfosForSuper.empty()) {
            for (auto& typeArgName : from->scopeTypeInfo->typeArgNamesForSuper) {
                from->scopeTypeInfo->typeArgInfosForSuper[typeArgName.first] =
                    from->scopeTypeInfo->classScopeAndEnv->getTypeInfoWithFileScope(typeArgName.second->typeName);
            }
        }
        for (auto& superTypeArg : from->scopeTypeInfo->typeArgInfosForSuper) {
            if (superTypeArg.second == from) {
                addTypeMap(superTypeArg.first, from);
            }
        }
    }
    // if (to->isTypeParam) {
    //     if (not to->scopeTypeInfo->typeArgNamesForSuper.empty() and to->scopeTypeInfo->typeArgInfosForSuper.empty()) {
    //         for (auto& typeArgName : to->scopeTypeInfo->typeArgNamesForSuper) {
    //             to->scopeTypeInfo->typeArgInfosForSuper[typeArgName.first] =
    //                 to->scopeTypeInfo->classScopeAndEnv->getTypeInfoWithFileScope(typeArgName.second->typeName);
    //         }
    //     }
    //     for (auto& superTypeArg : to->scopeTypeInfo->typeArgInfosForSuper) {
    //         if (superTypeArg.second == to) {
    //             addTypeMap(superTypeArg.first, to);
    //         }
    //     }
    // }
}

void TypeUnification::clear() {
    immediateTypeArgs.clear();
    intermediateTypeArgs.clear();
}

void TypeUnification::copyFrom(TypeUnification* copied) {
    immediateTypeArgs = copied->immediateTypeArgs;
    intermediateTypeArgs = copied->intermediateTypeArgs;
}
