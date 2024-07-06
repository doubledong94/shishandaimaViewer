#include "../util/util.h"
#include "GlobalInfo.h"
#include "../file/FileManager.h"
#include "../antlr/syntaxObject/JavaHeaderFile.h"
#include "AddressableInfo.h"
#include "SWI-cpp2.h"
#include "../prolog/PrologConstructor.h"

map<string, list<TypeInfo*>> GlobalInfo::filePath2typeInfos;

TYPE_MAP_MAP(string) GlobalInfo::NAME_FILE_TO(typeKey2filePath);
TYPE_MAP_MAP(set<string>) GlobalInfo::NAME_FILE_TO(package2typeKeys);
TYPE_MAP_MAP(set<string>) GlobalInfo::NAME_FILE_TO(typeKey2subTypeKeys);
TYPE_MAP_MAP(set<string>) GlobalInfo::NAME_FILE_TO(override);
TYPE_MAP_MAP(set<string>) GlobalInfo::NAME_FILE_TO(MethodUseMethods);
TYPE_MAP_MAP(set<string>) GlobalInfo::NAME_FILE_TO(MethodUseFields);

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


void GlobalInfo::saveGlobalInfo() {
    SAVE_GLOBAL_PROLOG(typeKey2filePath,
        lines.push_back(CompoundTerm::getTypeToPLFileFact(item2.first, FileManager::convertFilePath2PrologFile(item2.second)));
        );
    SAVE_GLOBAL_PROLOG(package2typeKeys,
        for (auto& item3 : item2.second) {
            lines.push_back(CompoundTerm::getPackageFact(item2.first, item3));
        }
            );
    SAVE_GLOBAL_PROLOG(typeKey2subTypeKeys,
        for (auto& item3 : item2.second) {
            lines.push_back(CompoundTerm::getSubTypeFact(item2.first, item3));
        }
            );
    SAVE_GLOBAL_PROLOG(override,
        for (auto& item3 : item2.second) {
            lines.push_back(CompoundTerm::getOverrideFact(item2.first, item3));
        }
            );
    SAVE_GLOBAL_PROLOG(MethodUseMethods,
        for (auto& item3 : item2.second) {
            lines.push_back(CompoundTerm::getMethodUseMethodFact(item2.first, item3));
        }
            );
    SAVE_GLOBAL_PROLOG(MethodUseFields,
        for (auto& item3 : item2.second) {
            lines.push_back(CompoundTerm::getMethodUseFieldFact(item2.first, item3));
        }
            );
    list<string> lines;
    for (auto& typeInfo : AddressableInfo::typeKey2typeInfo) {
        for (auto& methodInfo : typeInfo.second->methodInfos) {
            lines.push_back(CompoundTerm::getMethodFact(typeInfo.first,methodInfo->methodKey));
        }
    }
    PrologConstructor::writeToPrologFile(FileManager::GLOBAL_PL_FILE_PATH(TypeKey2Methods), lines);
    lines.clear();
    for (auto& typeInfo : AddressableInfo::typeKey2typeInfo) {
        for (auto& fieldInfo : typeInfo.second->fieldInfos) {
            lines.push_back(CompoundTerm::getFieldFact(typeInfo.first,fieldInfo->fieldKey));
        }
    }
    PrologConstructor::writeToPrologFile(FileManager::GLOBAL_PL_FILE_PATH(TypeKey2Fields), lines);
}

void GlobalInfo::serializeGlobalInfo() {
    serialize(NAME_FILE_TO(typeKey2filePath), FileManager::NAME_SERIALIZE(typeKey2filePath));
    serialize(NAME_FILE_TO(package2typeKeys), FileManager::NAME_SERIALIZE(package2typeKeys));
    serialize(NAME_FILE_TO(typeKey2subTypeKeys), FileManager::NAME_SERIALIZE(typeKey2subTypeKeys));
    serialize(NAME_FILE_TO(override), FileManager::NAME_SERIALIZE(override));
    serialize(NAME_FILE_TO(MethodUseMethods), FileManager::NAME_SERIALIZE(MethodUseMethods));
    serialize(NAME_FILE_TO(MethodUseFields), FileManager::NAME_SERIALIZE(MethodUseFields));
}

bool GlobalInfo::isOptrKeyType(int keyType) {
    return keyType > KEY_TYPE_OPTR_START and keyType < KEY_TYPE_OPTR_END;
}

void GlobalInfo::release() {
    filePath2typeInfos.clear();
    NAME_FILE_TO(package2typeKeys).clear();
    NAME_FILE_TO(typeKey2subTypeKeys).clear();
    NAME_FILE_TO(override).clear();
    NAME_FILE_TO(typeKey2filePath).clear();
    NAME_FILE_TO(MethodUseMethods).clear();
    NAME_FILE_TO(MethodUseFields).clear();
}

void GlobalInfo::serialize(TYPE_MAP_MAP(string)& data, string& filePath) {
    ofstream f;
    f.open(filePath);
    f << data.size() << "\n";
    for (auto& item1 : data) {
        f << item1.first << "\n";
        f << item1.second.size() << "\n";
        for (auto& item2 : item1.second) {
            f << item2.first << "\n";
            f << item2.second << "\n";
        }
    }
    f.close();
}

void GlobalInfo::serialize(TYPE_MAP_MAP(set<string>)& data, string& filePath) {
    ofstream f;
    f.open(filePath);
    f << data.size() << "\n";
    for (auto& item1 : data) {
        f << item1.first << "\n";
        f << item1.second.size() << "\n";
        for (auto& item2 : item1.second) {
            f << item2.first << "\n";
            f << item2.second.size() << "\n";
            for (auto& item3 : item2.second) {
                f << item3 << "\n";
            }
        }
    }
    f.close();
}

void GlobalInfo::deserialize() {
    deserialize(NAME_FILE_TO(typeKey2filePath), FileManager::NAME_SERIALIZE(typeKey2filePath));
    deserialize(NAME_FILE_TO(package2typeKeys), FileManager::NAME_SERIALIZE(package2typeKeys));
    deserialize(NAME_FILE_TO(typeKey2subTypeKeys), FileManager::NAME_SERIALIZE(typeKey2subTypeKeys));
    deserialize(NAME_FILE_TO(override), FileManager::NAME_SERIALIZE(override));
    deserialize(NAME_FILE_TO(MethodUseMethods), FileManager::NAME_SERIALIZE(MethodUseMethods));
    deserialize(NAME_FILE_TO(MethodUseFields), FileManager::NAME_SERIALIZE(MethodUseFields));
}

void GlobalInfo::deserialize(TYPE_MAP_MAP(string)& data, string& filePath) {
    ifstream f;
    f.open(filePath);
    if (not f.is_open()) {
        return;
    }
    int fileCount = Serializable::getInt(f);
    for (int fileIndex = 0;fileIndex < fileCount;fileIndex++) {
        string filePath;
        getline(f, filePath);
        int count = Serializable::getInt(f);
        map<string, string> m;
        for (int i = 0;i < count;i++) {
            string key;
            getline(f, key);
            string s;
            getline(f, s);
            m[key] = s;
        }
        if (FileManager::shouldRestore(filePath)) {
            data[filePath] = m;
        }
    }
    f.close();
}

/**
    oldData	    allFiles	updatedFiles				                restore	    parse
    1	        1	        1		        updated		                0	        1
    1	        1	        0		        unchanged		            1	        0
    1	        0	        1		        impossible
    1	        0	        0		        delete file                 0 	        0
                                            parse dir changed           1           0
    0	        1	        1		        new file from same dir      0	        1
                                            different dir               0           1
    0	        1	        0		        impossible
    0	        0	        1		        impossible
    0	        0	        0		        not issue
*/
void GlobalInfo::deserialize(TYPE_MAP_MAP(set<string>)& data, string& filePath) {
    ifstream f;
    f.open(filePath);
    if (not f.is_open()) {
        return;
    }
    int fileCount = Serializable::getInt(f);
    for (int fileIndex = 0;fileIndex < fileCount;fileIndex++) {
        string filePath;
        getline(f, filePath);
        int count1 = Serializable::getInt(f);
        map<string, set<string>> m;
        for (int i = 0;i < count1;i++) {
            string key;
            getline(f, key);
            int count2 = Serializable::getInt(f);
            set<string> item;
            for (int j = 0;j < count2;j++) {
                string s;
                getline(f, s);
                item.insert(s);
            }
            m[key] = item;
        }
        if (FileManager::shouldRestore(filePath)) {
            data[filePath] = m;
        }
    }
    f.close();
}

void GlobalInfo::initGlobalInfoWhichIsUpdatedAndNotRestored() {
    for (auto& updatedFile : FileManager::updatedFiles) {
        NAME_FILE_TO(typeKey2filePath)[updatedFile] = map<string, string>();
        NAME_FILE_TO(package2typeKeys)[updatedFile] = map<string, set<string>>();
        NAME_FILE_TO(typeKey2subTypeKeys)[updatedFile] = map<string, set<string>>();
        NAME_FILE_TO(override)[updatedFile] = map<string, set<string>>();
        NAME_FILE_TO(MethodUseMethods)[updatedFile] = map<string, set<string>>();
        NAME_FILE_TO(MethodUseFields)[updatedFile] = map<string, set<string>>();
    }
}

