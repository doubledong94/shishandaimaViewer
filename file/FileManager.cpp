#include "../util/util.h"
#include "FileManager.h"
#include "../error/ErrorManager.h"
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

set<string> FileManager::allFiles;
set<string> FileManager::updatedFiles;

void FileManager::filterUpdatedFilePath() {
    for (auto& file_path : allFiles) {
        if (hasBeenChangedSinceLastTimeParsing(file_path)) {
            updatedFiles.insert(file_path);
        }
    }
}

void FileManager::getFiles(const std::string& dir_name, const string& postfix) {
    allFiles.clear();
    updatedFiles.clear();
    getAllFiles(dir_name, postfix);
    filterUpdatedFilePath();
}

void FileManager::getAllFiles(const std::string& dir_name, const string& postfix) {
    DIR* dir;
    dirent* entry;
    struct stat info {};
    dir = opendir(dir_name.data());
    if (!dir) {
        printf("directory %s was not found", dir_name.data());
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            string path = dir_name + "/" + string(entry->d_name);
            stat(path.data(), &info);
            if (S_ISDIR(info.st_mode)) {
                getAllFiles(path, postfix);
            } else {
                if (path.find(postfix) == path.size() - postfix.size()) {
                    allFiles.insert(path);
                }
            }
        }
    }
    closedir(dir);
}

string FileManager::baseFolder = "";
string baseDataFolder = "";

string FileManager::prologBaseDir = baseDataFolder + "prolog/";
string FileManager::prologAddressableFileDir = prologBaseDir + "addressable/";
string FileManager::prologUnaddressableFileDir = prologBaseDir + "unaddressable/";

string FileManager::prologGlobalInfo_typeKey2AddressableFilePath = prologBaseDir + "typeKey2addressableFilePath.pl";
string FileManager::prologGlobalInfo_typeKey2UnaddressableFilePath = prologBaseDir + "typeKey2unaddressableFilePath.pl";
string FileManager::prologGlobalInfo_package2typeKey = prologBaseDir + "package2typeKey.pl";
string FileManager::prologGlobalInfo_typeKey2subTypeKeys = prologBaseDir + "typeKey2subTypeKeys.pl";
string FileManager::prologGlobalInfo_typeKey2itUseTypeKeys = prologBaseDir + "typeKey2itUseTypeKeys.pl";
string FileManager::prologGlobalInfo_filePath2TypeKey2itUseTypeKeys = baseDataFolder + "filePath2TypeKey2itUseTypeKeys.txt";
string FileManager::prologGlobalInfo_filePath2typeKey2FilePath = baseDataFolder + "filePath2typeKey2FilePath.txt";
string FileManager::prologGlobalInfo_filePath2package2typeKey = baseDataFolder + "filePath2package2typeKey.txt";
string FileManager::prologGlobalInfo_filePath2typeKey2subTypeKeys = baseDataFolder + "filePath2typeKey2subTypeKeys.txt";
string FileManager::prologGlobalInfo_baseRuleFile = "";
string FileManager::configBaseDir = "";
string FileManager::imguiIniFile = "";
string FileManager::hotkeyConfig = "";
string FileManager::simpleViewConfig = "";
string FileManager::srcPathConfig = "";
string FileManager::srcPath = "";
string FileManager::resourceBaseDir = "";
string FileManager::alphabetIconAndPath = "";
string FileManager::alphabetIconPlusPath = "";
string FileManager::alphabetIconMinusPath = "";
string FileManager::alphabetIconAPath = "";
string FileManager::alphabetIconCPath = "";
string FileManager::alphabetIconFPath = "";
string FileManager::alphabetIconGPath = "";
string FileManager::alphabetIconIPath = "";
string FileManager::alphabetIconKPath = "";
string FileManager::alphabetIconLPath = "";
string FileManager::alphabetIconMPath = "";
string FileManager::alphabetIconNPath = "";
string FileManager::alphabetIconOPath = "";
string FileManager::alphabetIconPPath = "";
string FileManager::alphabetIconRPath = "";
string FileManager::alphabetIconSPath = "";
string FileManager::alphabetIconUPath = "";
string FileManager::alphabetIconWPath = "";


void FileManager::initCurrentDir() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    baseFolder = string(result, (count > 0) ? count - 22 : 0);
    baseDataFolder = baseFolder + "data/";
    srcjsonBaseDir = baseDataFolder + "srcjson/";
    headerSerializationFile = baseDataFolder + "header.txt";
    prologBaseDir = baseDataFolder + "prolog/";
    prologAddressableFileDir = prologBaseDir + "addressable/";
    prologUnaddressableFileDir = prologBaseDir + "unaddressable/";
    prologGlobalInfo_typeKey2AddressableFilePath = prologBaseDir + "typeKey2addressableFilePath.pl";
    prologGlobalInfo_typeKey2UnaddressableFilePath = prologBaseDir + "typeKey2unaddressableFilePath.pl";
    prologGlobalInfo_package2typeKey = prologBaseDir + "package2typeKey.pl";
    prologGlobalInfo_typeKey2subTypeKeys = prologBaseDir + "typeKey2subTypeKeys.pl";
    prologGlobalInfo_typeKey2itUseTypeKeys = prologBaseDir + "typeKey2itUseTypeKeys.pl";
    prologGlobalInfo_filePath2TypeKey2itUseTypeKeys = baseDataFolder + "filePath2TypeKey2itUseTypeKeys.txt";
    prologGlobalInfo_filePath2typeKey2FilePath = baseDataFolder + "filePath2typeKey2FilePath.txt";
    prologGlobalInfo_filePath2package2typeKey = baseDataFolder + "filePath2package2typeKey.txt";
    prologGlobalInfo_filePath2typeKey2subTypeKeys = baseDataFolder + "filePath2typeKey2subTypeKeys.txt";
    fontBaseDir = baseFolder + "fonts/";
    fontFilePath = fontBaseDir + "optimer_regular.typeface.json";
    fontFileOTFPath = fontBaseDir + "SourceHanSansSC-Normal.otf";
    fontFileTTFPath = fontBaseDir + "SourceHanSansSC-Normal.ttf";
    configBaseDir = baseFolder + "config/";
    prologGlobalInfo_baseRuleFile = configBaseDir + "base_rules.pl";
    imguiIniFile = configBaseDir + "imgui.ini";
    hotkeyConfig = configBaseDir + "hotkey.config";
    simpleViewConfig = configBaseDir + "simpleView.config";
    srcPathConfig = configBaseDir + "srcPath.txt";
    resourceBaseDir = baseFolder + "resource/";
    alphabetIconAndPath = resourceBaseDir + "alphabetIconAnd.png";
    alphabetIconPlusPath = resourceBaseDir + "alphabetIconPlus.png";
    alphabetIconMinusPath = resourceBaseDir + "alphabetIconMinus.png";
    alphabetIconAPath = resourceBaseDir + "alphabetIconA.png";
    alphabetIconCPath = resourceBaseDir + "alphabetIconC.png";
    alphabetIconFPath = resourceBaseDir + "alphabetIconF.png";
    alphabetIconGPath = resourceBaseDir + "alphabetIconG.png";
    alphabetIconIPath = resourceBaseDir + "alphabetIconI.png";
    alphabetIconKPath = resourceBaseDir + "alphabetIconK.png";
    alphabetIconLPath = resourceBaseDir + "alphabetIconL.png";
    alphabetIconMPath = resourceBaseDir + "alphabetIconM.png";
    alphabetIconNPath = resourceBaseDir + "alphabetIconN.png";
    alphabetIconOPath = resourceBaseDir + "alphabetIconO.png";
    alphabetIconPPath = resourceBaseDir + "alphabetIconP.png";
    alphabetIconRPath = resourceBaseDir + "alphabetIconR.png";
    alphabetIconSPath = resourceBaseDir + "alphabetIconS.png";
    alphabetIconUPath = resourceBaseDir + "alphabetIconU.png";
    alphabetIconWPath = resourceBaseDir + "alphabetIconW.png";
    ifstream f;
    f.open(srcPathConfig);
    if (f.is_open()) {
        getline(f, srcPath);
        if (not srcPath.empty() and srcPath.back() == '/') {
            srcPath.pop_back();
        }
    }
    f.close();
}

string FileManager::srcjsonBaseDir = baseDataFolder + "srcjson/";
string FileManager::headerSerializationFile = "";

string FileManager::fontBaseDir = "";
string FileManager::fontFilePath = "";
string FileManager::fontFileOTFPath = "";
string FileManager::fontFileTTFPath = "";

string FileManager::convertFilePath2srcjson(const char* filePath) {
    return srcjsonBaseDir + replace_all_distinct(filePath, "/", ",") + ".json";
}

string FileManager::convertFilePath2PrologFile(const string& filePath) {
    return replace_all_distinct(filePath, "/", ",") + ".pl";
}

bool FileManager::hasBeenChangedSinceLastTimeParsing(const string& filePath) {
    string filePathToBeCompared = prologAddressableFileDir + convertFilePath2PrologFile(filePath.data());
    return (access(filePathToBeCompared.data(), W_OK) != 0 || compareFileEditTime(filePath, filePathToBeCompared));
}

bool FileManager::compareFileEditTime(const string& filePath1, const string& filePath2) {
    FILE* fp;
    int fd;
    struct stat buf;

    fp = fopen(filePath1.data(), "r");
    fd = fileno(fp);
    fstat(fd, &buf);
    long time1 = buf.st_mtime;
    fclose(fp);
    fp = fopen(filePath2.data(), "r");
    fd = fileno(fp);
    fstat(fd, &buf);
    long time2 = buf.st_mtime;
    fclose(fp);
    bool fileOneIsNewer = time1 > time2;
    return fileOneIsNewer;
}


