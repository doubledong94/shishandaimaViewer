class ClassScopeAndEnv;

struct FieldInfo;

struct MethodInfo;

struct TypeInfo {
    // first round
    unsigned int flag = 0;
    string filePath;
    string package;
    string typeKey;
    string simpletypeName;
    string typeName;
    set<TypeInfo*> innerTypeInfos;
    TypeInfo* outerTypeInfo = NULL;
    ClassScopeAndEnv* classScopeAndEnv = nullptr;
    // second round
    set<TypeInfo*> superTypeInfos;
    set<TypeInfo*> interfaceInfos;
    map<TypeInfo*, TypeName*> typeArgNamesForSuper;
    map<TypeInfo*, TypeInfo*> typeArgInfosForSuper;
    set<FieldInfo*> fieldInfos;
    set<MethodInfo*> methodInfos;

    bool isTypeParam = false;
    vector<TypeInfo*> typeParamInfos;
    TypeName* boundNameForTypeParam = NULL;
    TypeInfo* boundInfoForTypeParam = NULL;
    TypeInfo* scopeTypeInfo = NULL;

    list<MethodInfo*> getConstructor(int paramCount);
    MethodInfo* getOnlyMethodFromInterface();
};

struct FieldInfo {
    unsigned int flag = 0;
    string fieldKey;
    string name;
    TypeInfo* typeInfo = NULL;
    set<string> initValue;
    map<TypeInfo*, TypeInfo*> typeParam2typeArg;
    src_loc srcLoc;
};

struct MethodInfo {
    unsigned int flag = 0;
    string name;
    string methodKey;
    string calledMethodKey;
    FieldInfo* returnInfo = NULL;
    FieldInfo* calledReturnInfo = NULL;
    vector<FieldInfo*> parameterInfos;
    vector<FieldInfo*> calledParamInfos;
    vector<TypeInfo*> typeParamInfos;

    bool isVariableParameter = false;
    bool isConstructor = false;

    string getParamPartOfKey();

    src_loc srcLoc;
};


class AddressableInfo {

public:
    static unordered_map<string, TypeInfo*> typeKey2typeInfo;
    static unordered_map<string, FieldInfo*> fieldKey2fieldInfo;
    static unordered_map<string, MethodInfo*> methodKey2MethodInfo;
    static map<string, CompilationUnit*> filePath2compilationUnits;
    static std::mutex addcompilationUnitLock;

    static TypeInfo* voidTypeInfo;
    static TypeInfo* nullTypeInfo;
    static TypeInfo* defaultValueTypeInfo;
    static TypeInfo* errorTypeInfo;
    // the following type infos are assigned after first round
    static TypeInfo* iterableTypeInfo;
    static TypeInfo* iterableTypeParamInfo;
    static TypeInfo* classTypeParamInfo;
    static TypeInfo* stringTypeInfo;
    static TypeInfo* classTypeInfo;
    static TypeInfo* boolTypeInfo;
    static TypeInfo* charTypeInfo;
    static TypeInfo* intTypeInfo;
    static TypeInfo* floatTypeInfo;
    static TypeInfo* byteTypeInfo;
    static TypeInfo* shortTypeInfo;
    static TypeInfo* longTypeInfo;
    static TypeInfo* doubleTypeInfo;
    static map<string, TypeInfo*> primitiveType2TypeInfo;
    static TypeInfo* objectTypeInfo;
    static TypeInfo* enumTypeInfo;
    static set<TypeInfo*> numberTypes;
    static TypeName* enumTypeName;
    static TypeName* objectTypeName;

    static FieldInfo* arrayLengthdFieldInfo;

    static string makeShortMethodName(const string& methodName, const string& parameterPartOfKey);

    static string makeMethodKey(const string& typeKey, const string& methodName, const string& parameterPartOfKey);

    static string makeParamKey(const string& methodKey, const string& paramName);

    static string makeReturnKey(const string& methodKey);

    static string makeCalledKey(const string& key);

    static string makeStepKey(const string& calledKey);

    static string makeMethodIfKey(const string& methodKey);

    static string makeMethodElseKey(const string& methodKey);

    static string makeMethodForKey(const string& methodKey);

    static string makeMethodWhileKey(const string& methodKey);

    static string makeMethodCaseKey(const string& methodKey);

    static string makeMethodSwitchKey(const string& methodKey);

    static string makeMethodForEachKey(const string& methodKey);

    static string makeMethodTryKey(const string& methodKey);

    static string makeMethodCatchKey(const string& methodKey);

    static string makeMethodFinallyKey(const string& methodKey);

    static string makeTypeParameterKey(const string& typeKey, const string& typeParamName);

    static string makeAnonymousKey(const string& anonymousTypeName, const string& positionKey);

    static void serializeHeader();

    static void deserializeHeader();

    static void beforeParseAll();

    static void afterFirstRound();

    static void saveAddressableInfo();

    static void release();

};

