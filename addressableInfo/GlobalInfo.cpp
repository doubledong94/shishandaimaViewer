#include "../util/util.h"
#include "GlobalInfo.h"
#include "../file/FileManager.h"
#include "../antlr/syntaxObject/JavaHeaderFile.h"
#include "AddressableInfo.h"
#include "SWI-cpp2.h"
#include "../prolog/PrologConstructor.h"

map<string, map<string, set<string>>> GlobalInfo::filePath2package2typeKeys;
map<string, map<string, set<string>>> GlobalInfo::filePath2typeKey2subTypeKeys;

map<string, map<string, string>> GlobalInfo::filePath2typeKey2filePath;
map<string, list<TypeInfo*>> GlobalInfo::filePath2typeInfos;
map<string, map<string, set<string>>> GlobalInfo::filePath2TypeKey2itUseTypeKeys;

std::mutex GlobalInfo::addUsageLock;

const string GlobalInfo::type_key_array = "[Array]";

string GlobalInfo::logicalOptr = "logicalOptr:";
string GlobalInfo::relationalOptr = "relationalOptr:";
string GlobalInfo::conditionalOptr = "conditionalOptr:";
string GlobalInfo::arithmeticalOptr = "arithmeticalOptr:";
string GlobalInfo::unaryOptr = "unaryOptr:";
string GlobalInfo::selfAssignOptr = "selfAssignOptr:";
string GlobalInfo::instanceof = "instanceof:";
string GlobalInfo::indexOptr = "indexOptr:";
string GlobalInfo::GLOBAL_KEY_ARRAY_INIT = "[ArrayInit]";
string GlobalInfo::GLOBAL_KEY_ERROR = "[ERROR]";

const string GlobalInfo::GLOBAL_KEY_DEFAULT_VALUE = "0defaultValue";
const string GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_RETURN = GlobalInfo::arithmeticalOptr + "return";
const string GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_PARAMETER1 = GlobalInfo::arithmeticalOptr + "param1";
const string GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_PARAMETER2 = GlobalInfo::arithmeticalOptr + "param2";
const string GlobalInfo::GLOBAL_KEY_OPTR_SELF_ASSIGN_RETURN = GlobalInfo::selfAssignOptr + "return";
const string GlobalInfo::GLOBAL_KEY_OPTR_SELF_ASSIGN_PARAMETER1 = GlobalInfo::selfAssignOptr + "param1";
const string GlobalInfo::GLOBAL_KEY_OPTR_UNARY_RETURN = GlobalInfo::unaryOptr + "return";
const string GlobalInfo::GLOBAL_KEY_OPTR_UNARY_PARAMETER1 = GlobalInfo::unaryOptr + "param1";
const string GlobalInfo::GLOBAL_KEY_OPTR_LOGIC_RETURN = GlobalInfo::logicalOptr + "return";
const string GlobalInfo::GLOBAL_KEY_OPTR_LOGIC_PARAMETER1 = GlobalInfo::logicalOptr + "param1";
const string GlobalInfo::GLOBAL_KEY_OPTR_LOGIC_PARAMETER2 = GlobalInfo::logicalOptr + "param2";
const string GlobalInfo::GLOBAL_KEY_OPTR_RELATION_RETURN = GlobalInfo::relationalOptr + "return";
const string GlobalInfo::GLOBAL_KEY_OPTR_RELATION_PARAMETER1 = GlobalInfo::relationalOptr + "param1";
const string GlobalInfo::GLOBAL_KEY_OPTR_RELATION_PARAMETER2 = GlobalInfo::relationalOptr + "param2";
const string GlobalInfo::GLOBAL_KEY_OPTR_CONDITIONAL_RETURN = GlobalInfo::conditionalOptr + "return";
const string GlobalInfo::GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER1 = GlobalInfo::conditionalOptr + "param1";
const string GlobalInfo::GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER2 = GlobalInfo::conditionalOptr + "param2";
const string GlobalInfo::GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER3 = GlobalInfo::conditionalOptr + "param3";
const string GlobalInfo::GLOBAL_KEY_OPTR_INSTANCE_OF_RETURN = GlobalInfo::instanceof + "return";
const string GlobalInfo::GLOBAL_KEY_OPTR_INSTANCE_OF_PARAMETER1 = GlobalInfo::instanceof + "param1";
const string GlobalInfo::GLOBAL_KEY_OPTR_INSTANCE_OF_PARAMETER2 = GlobalInfo::instanceof + "param2";
const string GlobalInfo::GLOBAL_KEY_OPTR_INDEX_RETURN = GlobalInfo::indexOptr + "return";
const string GlobalInfo::GLOBAL_KEY_OPTR_INDEX_PARAMETER1 = GlobalInfo::indexOptr + "param1";
const string GlobalInfo::GLOBAL_KEY_OPTR_INDEX_PARAMETER2 = GlobalInfo::indexOptr + "param2";


void GlobalInfo::saveGlobalInfo() {
    PrologConstructor::savePrologFilePath(filePath2typeKey2filePath);
    PrologConstructor::savePrologPackage(filePath2package2typeKeys);
    PrologConstructor::savePrologSubTypes(filePath2typeKey2subTypeKeys);
    PrologConstructor::savePrologRelatedType(filePath2TypeKey2itUseTypeKeys);
    serializeUseRelation();
    serializeFilePath();
    serializePackage2typeKey();
    serializeSubType();
}

bool GlobalInfo::isOptrKeyType(int keyType) {
    return keyType > KEY_TYPE_OPTR_START and keyType < KEY_TYPE_OPTR_END;
}

void GlobalInfo::release() {
    filePath2package2typeKeys.clear();
    filePath2typeKey2subTypeKeys.clear();
    filePath2typeKey2filePath.clear();
    filePath2typeInfos.clear();
    filePath2TypeKey2itUseTypeKeys.clear();
}

void GlobalInfo::beforeParseAll() {
    deserializeUseRelation();
    deserializeFilePath();
    deserializePackage2typeKey();
    deserializeSubType();
}

void GlobalInfo::serializeUseRelation() {
    ofstream f;
    f.open(FileManager::prologGlobalInfo_filePath2TypeKey2itUseTypeKeys);
    f << filePath2TypeKey2itUseTypeKeys.size() << "\n";
    for (auto& fileAndType : filePath2TypeKey2itUseTypeKeys) {
        f << fileAndType.first << "\n";
        f << fileAndType.second.size() << "\n";
        for (auto& typeAndItUseTypes : fileAndType.second) {
            f << typeAndItUseTypes.first << "\n";
            f << typeAndItUseTypes.second.size() << "\n";
            for (auto& type : typeAndItUseTypes.second) {
                f << type << "\n";
            }
        }
    }
}

void GlobalInfo::deserializeUseRelation() {
    ifstream f;
    f.open(FileManager::prologGlobalInfo_filePath2TypeKey2itUseTypeKeys);
    if (not f.is_open()) {
        return;
    }
    int fileCount = Serializable::getInt(f);
    for (int fileIndex = 0;fileIndex < fileCount;fileIndex++) {
        string filePath;
        getline(f, filePath);
        int typeCount = Serializable::getInt(f);
        map<string, set<string>> typeKey2itUseTypeKeys;
        for (int typeIndex = 0;typeIndex < typeCount;typeIndex++) {
            string typeKey;
            getline(f, typeKey);
            int usedTypeCount = Serializable::getInt(f);
            set<string> usedTypeKeys;
            for (int typeIndex = 0;typeIndex < usedTypeCount;typeIndex++) {
                string usedTypeKey;
                getline(f, usedTypeKey);
                usedTypeKeys.insert(usedTypeKey);
            }
            typeKey2itUseTypeKeys[typeKey] = usedTypeKeys;
        }
        if (FileManager::shouldRestore(filePath)) {
            filePath2TypeKey2itUseTypeKeys[filePath] = typeKey2itUseTypeKeys;
        }
    }
}

void GlobalInfo::serializeFilePath() {
    ofstream f;
    f.open(FileManager::prologGlobalInfo_filePath2typeKey2FilePath);
    f << filePath2typeKey2filePath.size() << "\n";
    for (auto& typeKey2filePath : filePath2typeKey2filePath) {
        f << typeKey2filePath.first << "\n";
        f << typeKey2filePath.second.size() << "\n";
        for (auto& typeKeyAndfilePath : typeKey2filePath.second) {
            f << typeKeyAndfilePath.first << "\n";
            f << typeKeyAndfilePath.second << "\n";
        }
    }
}

void GlobalInfo::deserializeFilePath() {
    ifstream f;
    f.open(FileManager::prologGlobalInfo_filePath2typeKey2FilePath);
    if (not f.is_open()) {
        return;
    }
    int fileCount = Serializable::getInt(f);
    for (int fileIndex = 0;fileIndex < fileCount;fileIndex++) {
        string filePath;
        getline(f, filePath);
        int typeCount = Serializable::getInt(f);
        map<string, string> typeKey2filePath;
        for (int typeIndex = 0;typeIndex < typeCount;typeIndex++) {
            string typeKey;
            getline(f, typeKey);
            string filePath;
            getline(f, filePath);
            typeKey2filePath[typeKey] = filePath;
        }
        if (FileManager::shouldRestore(filePath)) {
            filePath2typeKey2filePath[filePath] = typeKey2filePath;
        }
    }
}

void GlobalInfo::serializePackage2typeKey() {
    ofstream f;
    f.open(FileManager::prologGlobalInfo_filePath2package2typeKey);
    f << filePath2package2typeKeys.size() << "\n";
    for (auto& fileAndPackage : filePath2package2typeKeys) {
        f << fileAndPackage.first << "\n";
        f << fileAndPackage.second.size() << "\n";
        for (auto& packageAndTypeKeys : fileAndPackage.second) {
            f << packageAndTypeKeys.first << "\n";
            f << packageAndTypeKeys.second.size() << "\n";
            for (auto& typeKey : packageAndTypeKeys.second) {
                f << typeKey << "\n";
            }
        }
    }
}

void GlobalInfo::deserializePackage2typeKey() {
    ifstream f;
    f.open(FileManager::prologGlobalInfo_filePath2package2typeKey);
    if (not f.is_open()) {
        return;
    }
    int fileCount = Serializable::getInt(f);
    for (int fileIndex = 0;fileIndex < fileCount;fileIndex++) {
        string filePath;
        getline(f, filePath);
        int packageCount = Serializable::getInt(f);
        map<string, set<string>> package2typeKeys;
        for (int packageIndex = 0;packageIndex < packageCount;packageIndex++) {
            string p;
            getline(f, p);
            int typeCount = Serializable::getInt(f);
            set<string> typeKeys;
            for (int typeIndex = 0;typeIndex < typeCount;typeIndex++) {
                string s;
                getline(f, s);
                typeKeys.insert(s);
            }
            package2typeKeys[p] = typeKeys;
        }
        if (FileManager::shouldRestore(filePath)) {
            filePath2package2typeKeys[filePath] = package2typeKeys;
        }
    }
}

void GlobalInfo::serializeSubType() {
    ofstream f;
    f.open(FileManager::prologGlobalInfo_filePath2typeKey2subTypeKeys);
    f << filePath2typeKey2subTypeKeys.size() << "\n";
    for (auto& typeKey2subTypeKyes : filePath2typeKey2subTypeKeys) {
        f << typeKey2subTypeKyes.first << "\n";
        f << typeKey2subTypeKyes.second.size() << "\n";
        for (auto& typeKeyAndsubTypeKey : typeKey2subTypeKyes.second) {
            f << typeKeyAndsubTypeKey.first << "\n";
            f << typeKeyAndsubTypeKey.second.size() << "\n";
            for (auto& sub : typeKeyAndsubTypeKey.second) {
                f << sub << "\n";
            }
        }
    }
}

void GlobalInfo::deserializeSubType() {
    ifstream f;
    f.open(FileManager::prologGlobalInfo_filePath2typeKey2subTypeKeys);
    if (not f.is_open()) {
        return;
    }
    int fileCount = Serializable::getInt(f);
    for (int fileIndex = 0;fileIndex < fileCount;fileIndex++) {
        string filePath;
        getline(f, filePath);
        int typeCount = Serializable::getInt(f);
        map<string, set<string>> typeAndSubType;
        for (int typeIndex = 0;typeIndex < typeCount;typeIndex++) {
            string sup;
            getline(f, sup);
            int subCount = Serializable::getInt(f);
            set<string> subs;
            for (int subTypeIndex = 0;subTypeIndex < subCount;subTypeIndex++) {
                string sub;
                getline(f, sub);
                subs.insert(sub);
            }
            typeAndSubType[sup] = subs;
        }
        if (FileManager::shouldRestore(filePath)) {
            filePath2typeKey2subTypeKeys[filePath] = typeAndSubType;
        }
    }
}
