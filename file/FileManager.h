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
    static string prologGlobalInfo_typeKey2AddressableFilePath;
    static string prologGlobalInfo_typeKey2UnaddressableFilePath;
    static string prologGlobalInfo_package2typeKey;
    static string prologGlobalInfo_typeKey2subTypeKeys;
    static string prologGlobalInfo_typeKey2itUseTypeKeys;
    static string prologGlobalInfo_filePath2typeKey2FilePath;
    static string prologGlobalInfo_filePath2package2typeKey;
    static string prologGlobalInfo_filePath2typeKey2subTypeKeys;
    static string prologGlobalInfo_filePath2TypeKey2itUseTypeKeys;
    static string prologGlobalInfo_baseRuleFile;

    static string fontBaseDir;
    static string fontFilePath;
    static string fontFileOTFPath;
    static string fontFileTTFPath;
    static string configBaseDir;
    static string imguiIniFile;
    static string hotkeyConfig;
    static string simpleViewConfig;
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
};

