class FileManager {
public:

    static set<string> allFiles;
    static set<string> updatedFiles;

    static void getFiles(const string &dir_name, const string &postfix);

    static void getAllFiles(const string &dir_name, const string &postfix);

    static void getFileNameInDir(const string& dirPath, list<string> &fileNames);

    static void deleteFile(const string& filePath);

    static void filterUpdatedFilePath();

    static string srcjsonBaseDir;

    static string headerSerializationFile;

    static string allTypeKeysFilePath;

    static string convertFilePath2srcjson(const char *filePath);

    static string convertFilePath2methodGraph(const string &filePath);

    static string convertFilePath2PrologFile(const string &filePath);

    static bool hasBeenChangedSinceLastTimeParsing(const string &filePath);

    static bool compareFileEditTime(const string &filePath1, const string &filePath2);

    static void initCurrentDir();

    static bool shouldRestore(const string& filePath);

    static string baseFolder;
    static string prologBaseDir;
    static string prologAddressableFileDir;
    static string prologUnaddressableFileDir;

    static string GLOBAL_PL_FILE_PATH(baseRuleFile);

    static string GLOBAL_PL_FILE_PATH(typeKey2filePath);
    static string GLOBAL_PL_FILE_PATH(package2typeKeys);
    static string GLOBAL_PL_FILE_PATH(typeKey2subTypeKeys);
    static string GLOBAL_PL_FILE_PATH(override);
    static string GLOBAL_PL_FILE_PATH(MethodUseMethods);
    static string GLOBAL_PL_FILE_PATH(MethodUseFields);
    static string GLOBAL_PL_FILE_PATH(TypeKey2Methods);
    static string GLOBAL_PL_FILE_PATH(TypeKey2Fields);

    static string NAME_SERIALIZE(typeKey2filePath);
    static string NAME_SERIALIZE(package2typeKeys);
    static string NAME_SERIALIZE(typeKey2subTypeKeys);
    static string NAME_SERIALIZE(override);
    static string NAME_SERIALIZE(MethodUseMethods);
    static string NAME_SERIALIZE(MethodUseFields);

    static string fontBaseDir;
    static string fontFilePath;
    static string fontFileOTFPath;
    static string fontFileTTFPath;
    static string configBaseDir;
    static string imguiIniFile;
    static string hotkeyConfig;
    static string simpleViewConfig;
    static string dimControlConfig;
    static string excludePackageConfig;
    static string excludeClassConfig;
    static string srcPathConfig;
    static string srcPath;
    static string resourceBaseDir;
    static string alphabetIconAndPath;
    static string alphabetIconPlusPath;
    static string alphabetIconMinusPath;
    static string alphabetIconAPath;
    static string alphabetIconCPath;
    static string alphabetIconEPath;
    static string alphabetIconFPath;
    static string alphabetIconGPath;
    static string alphabetIconIPath;
    static string alphabetIconKPath;
    static string alphabetIconLPath;
    static string alphabetIconMPath;
    static string alphabetIconNPath;
    static string alphabetIconOPath;
    static string alphabetIconPPath;
    static string alphabetIconRPath;
    static string alphabetIconSPath;
    static string alphabetIconUPath;
    static string alphabetIconVPath;
    static string alphabetIconWPath;
    static string graphSaveAndRestorePath;
    static string boundFrameDragIconPath;
    static string boundFrameResizeIconPath;
    static string appIconPath;
};

