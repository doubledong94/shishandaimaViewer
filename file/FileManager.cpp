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

void FileManager::getFileNameInDir(const string& dirPath, list<string>& fileNames) {
    fileNames.clear();
    DIR* dir;
    dirent* entry;
    struct stat info {};
    dir = opendir(dirPath.data());
    if (!dir) {
        printf("directory %s was not found", dirPath.data());
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            string path = dirPath + "/" + string(entry->d_name);
            stat(path.data(), &info);
            if (not S_ISDIR(info.st_mode)) {
                fileNames.push_back(entry->d_name);
            }
        }
    }
    fileNames.sort();
}

void FileManager::deleteFile(const string& filePath) {
    std::remove(filePath.data());
}

string FileManager::baseFolder = "";
string baseDataFolder = "";

string FileManager::prologBaseDir = "";
string FileManager::prologAddressableFileDir = "";
string FileManager::prologUnaddressableFileDir = "";

string FileManager::GLOBAL_PL_FILE_PATH(baseRuleFile) = "";

string FileManager::GLOBAL_PL_FILE_PATH(typeKey2filePath) = "";
string FileManager::GLOBAL_PL_FILE_PATH(package2typeKeys) = "";
string FileManager::GLOBAL_PL_FILE_PATH(typeKey2subTypeKeys) = "";
string FileManager::GLOBAL_PL_FILE_PATH(override) = "";
string FileManager::GLOBAL_PL_FILE_PATH(MethodUseMethods) = "";
string FileManager::GLOBAL_PL_FILE_PATH(MethodUseFields) = "";
string FileManager::GLOBAL_PL_FILE_PATH(TypeKey2Methods) = "";
string FileManager::GLOBAL_PL_FILE_PATH(TypeKey2Fields) = "";

string FileManager::NAME_SERIALIZE(typeKey2filePath) = "";
string FileManager::NAME_SERIALIZE(package2typeKeys) = "";
string FileManager::NAME_SERIALIZE(typeKey2subTypeKeys) = "";
string FileManager::NAME_SERIALIZE(override) = "";
string FileManager::NAME_SERIALIZE(MethodUseMethods) = "";
string FileManager::NAME_SERIALIZE(MethodUseFields) = "";

string FileManager::configBaseDir = "";
string FileManager::imguiIniFile = "";
string FileManager::hotkeyConfig = "";
string FileManager::simpleViewConfig = "";
string FileManager::dimControlConfig = "";
string FileManager::srcPathConfig = "";
string FileManager::srcPath = "";
string FileManager::resourceBaseDir = "";
string FileManager::alphabetIconAndPath = "";
string FileManager::alphabetIconPlusPath = "";
string FileManager::alphabetIconMinusPath = "";
string FileManager::alphabetIconAPath = "";
string FileManager::alphabetIconCPath = "";
string FileManager::alphabetIconEPath = "";
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
string FileManager::alphabetIconVPath = "";
string FileManager::alphabetIconWPath = "";
string FileManager::graphSaveAndRestorePath = "";
string FileManager::boundFrameDragIconPath = "";
string FileManager::boundFrameResizeIconPath = "";


void FileManager::initCurrentDir() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    baseFolder = string(result, (count > 0) ? count - 22 : 0);
    baseDataFolder = baseFolder + "data/";
    srcjsonBaseDir = baseDataFolder + "srcjson/";
    configBaseDir = baseFolder + "config/";
    headerSerializationFile = baseDataFolder + "header.txt";
    prologBaseDir = baseDataFolder + "prolog/";
    prologAddressableFileDir = prologBaseDir + "addressable/";
    prologUnaddressableFileDir = prologBaseDir + "unaddressable/";

    GLOBAL_PL_FILE_PATH(baseRuleFile) = configBaseDir + "base_rules.pl";

    GLOBAL_PL_FILE_PATH(typeKey2filePath) = prologBaseDir + "typeKey2PLFilePath.pl";
    GLOBAL_PL_FILE_PATH(package2typeKeys) = prologBaseDir + "package2typeKey.pl";
    GLOBAL_PL_FILE_PATH(typeKey2subTypeKeys) = prologBaseDir + "typeKey2subTypeKeys.pl";
    GLOBAL_PL_FILE_PATH(override) = prologBaseDir + "override.pl";
    GLOBAL_PL_FILE_PATH(MethodUseMethods) = prologBaseDir + "MethodUseMethods.pl";
    GLOBAL_PL_FILE_PATH(MethodUseFields) = prologBaseDir + "MethodUseFields.pl";
    GLOBAL_PL_FILE_PATH(TypeKey2Methods) = prologBaseDir + "TypeKey2Methods.pl";
    GLOBAL_PL_FILE_PATH(TypeKey2Fields) = prologBaseDir + "TypeKey2Fields.pl";

    NAME_SERIALIZE(typeKey2filePath) = baseDataFolder + "filePath2typeKey2FilePath.txt";
    NAME_SERIALIZE(package2typeKeys) = baseDataFolder + "filePath2package2typeKey.txt";
    NAME_SERIALIZE(typeKey2subTypeKeys) = baseDataFolder + "filePath2typeKey2subTypeKeys.txt";
    NAME_SERIALIZE(override) = baseDataFolder + "filePath2override.txt";
    NAME_SERIALIZE(MethodUseMethods) = baseDataFolder + "filePath2MethodUseMethods.txt";
    NAME_SERIALIZE(MethodUseFields) = baseDataFolder + "filePath2MethodUseFields.txt";
    fontBaseDir = baseFolder + "fonts/";
    fontFilePath = fontBaseDir + "optimer_regular.typeface.json";
    fontFileOTFPath = fontBaseDir + "SourceHanSansSC-Normal.otf";
    fontFileTTFPath = fontBaseDir + "SourceHanSansSC-Normal.ttf";
    imguiIniFile = configBaseDir + "imgui.ini";
    hotkeyConfig = configBaseDir + "hotkey.config";
    simpleViewConfig = configBaseDir + "simpleView.config";
    dimControlConfig = configBaseDir + "dimControl.config";
    srcPathConfig = configBaseDir + "srcPath.txt";
    resourceBaseDir = baseFolder + "resource/";
    graphSaveAndRestorePath = baseFolder + "graph/";
    alphabetIconAndPath = resourceBaseDir + "alphabetIconAnd.png";
    alphabetIconPlusPath = resourceBaseDir + "alphabetIconPlus.png";
    alphabetIconMinusPath = resourceBaseDir + "alphabetIconMinus.png";
    alphabetIconAPath = resourceBaseDir + "alphabetIconA.png";
    alphabetIconCPath = resourceBaseDir + "alphabetIconC.png";
    alphabetIconEPath = resourceBaseDir + "alphabetIconE.png";
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
    alphabetIconVPath = resourceBaseDir + "alphabetIconV.png";
    alphabetIconWPath = resourceBaseDir + "alphabetIconW.png";
    boundFrameDragIconPath = resourceBaseDir + "drag.png";
    boundFrameResizeIconPath = resourceBaseDir + "resize.png";

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

bool FileManager::shouldRestore(const string& filePath) {
    bool isInSrcPath = filePath.find(srcPath) == 0;
    return not isInSrcPath or (FileManager::allFiles.count(filePath) and not FileManager::updatedFiles.count(filePath));
}

string FileManager::srcjsonBaseDir = "";
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
    string oldDataFile = prologAddressableFileDir + convertFilePath2PrologFile(filePath.data());
    bool fileNotExist = access(oldDataFile.data(), F_OK) != 0;
    return (fileNotExist || compareFileEditTime(filePath, oldDataFile));
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


