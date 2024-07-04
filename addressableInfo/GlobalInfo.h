
struct TypeInfo;

class GlobalInfo {
public:
    const static string type_key_array;

    static TYPE_MAP_MAP(string) NAME_FILE_TO(typeKey2filePath);
    static TYPE_MAP_MAP(set<string>) NAME_FILE_TO(package2typeKeys);
    static TYPE_MAP_MAP(set<string>) NAME_FILE_TO(typeKey2subTypeKeys);
    static TYPE_MAP_MAP(set<string>) NAME_FILE_TO(override);
    // todo to be deleted TypeKey2itUseTypeKeys
    static TYPE_MAP_MAP(set<string>) NAME_FILE_TO(TypeKey2itUseTypeKeys);
    // todo to be deleted TypeKey2itUseMethods
    static TYPE_MAP_MAP(set<string>) NAME_FILE_TO(TypeKey2itUseMethods);
    static TYPE_MAP_MAP(set<string>) NAME_FILE_TO(MethodUseMethods);
    static TYPE_MAP_MAP(set<string>) NAME_FILE_TO(MethodUseFields);

    static map<string, list<TypeInfo*>> filePath2typeInfos;

    static std::mutex addUsageLock;

    static string logicalOptr;
    static string relationalOptr;
    static string conditionalOptr;
    static string arithmeticalOptr;
    static string unaryOptr;
    static string selfAssignOptr;
    static string instanceof;
    static string indexOptr;
    static string GLOBAL_KEY_ARRAY_INIT;
    static string GLOBAL_KEY_ERROR;
    const static string GLOBAL_KEY_DEFAULT_VALUE;
    const static string GLOBAL_KEY_OPTR_ARITHMETIC_RETURN;
    const static string GLOBAL_KEY_OPTR_ARITHMETIC_PARAMETER1;
    const static string GLOBAL_KEY_OPTR_ARITHMETIC_PARAMETER2;
    const static string GLOBAL_KEY_OPTR_SELF_ASSIGN_RETURN;
    const static string GLOBAL_KEY_OPTR_SELF_ASSIGN_PARAMETER1;
    const static string GLOBAL_KEY_OPTR_UNARY_RETURN;
    const static string GLOBAL_KEY_OPTR_UNARY_PARAMETER1;
    const static string GLOBAL_KEY_OPTR_LOGIC_RETURN;
    const static string GLOBAL_KEY_OPTR_LOGIC_PARAMETER1;
    const static string GLOBAL_KEY_OPTR_LOGIC_PARAMETER2;
    const static string GLOBAL_KEY_OPTR_RELATION_RETURN;
    const static string GLOBAL_KEY_OPTR_RELATION_PARAMETER1;
    const static string GLOBAL_KEY_OPTR_RELATION_PARAMETER2;
    const static string GLOBAL_KEY_OPTR_CONDITIONAL_RETURN;
    const static string GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER1;
    const static string GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER2;
    const static string GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER3;
    const static string GLOBAL_KEY_OPTR_INSTANCE_OF_RETURN;
    const static string GLOBAL_KEY_OPTR_INSTANCE_OF_PARAMETER1;
    const static string GLOBAL_KEY_OPTR_INSTANCE_OF_PARAMETER2;
    const static string GLOBAL_KEY_OPTR_INDEX_RETURN;

    static void saveGlobalInfo();

    static void serializeGlobalInfo();

    //  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Key Type^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    enum {
        // value keys
        KEY_TYPE_CLASS = 0,
        KEY_TYPE_FIELD,
        KEY_TYPE_CONSTRUCTOR,
        KEY_TYPE_METHOD,
        KEY_TYPE_METHOD_PARAMETER,
        KEY_TYPE_METHOD_RETURN,
        KEY_TYPE_CALLED_METHOD,
        KEY_TYPE_CALLED_PARAMETER,
        KEY_TYPE_CALLED_RETURN,
        KEY_TYPE_CONDITION,
        KEY_TYPE_ELSE,
        KEY_TYPE_REFERENCE,
        KEY_TYPE_DATA_STEP,
        KEY_TYPE_TIMING_STEP,
        KEY_TYPE_DATA_OVERRIDE,
        KEY_TYPE_TIMING_OVERRIDE,
        KEY_TYPE_INDEX,

        KEY_TYPE_LOCAL_VARIABLE,
        KEY_TYPE_FINAL,
        KEY_TYPE_DEFAULT_VALUE,
        KEY_TYPE_KEY_WORD_VALUE, // null, true, false
        KEY_TYPE_ANONYMOUS_CLASS, // todo what is the simple name for this
        KEY_TYPE_METHOD_REFERENCE, // todo what is the simple name for this
        KEY_TYPE_ENUM_INSTANCE,
        KEY_TYPE_ARRAY_INIT, // todo what is the simple name for this

        // OPTR keys
        KEY_TYPE_OPTR_START,
        KEY_TYPE_OPTR_ARITHMETIC_RETURN,
        KEY_TYPE_OPTR_ARITHMETIC_PARAMETER1,
        KEY_TYPE_OPTR_ARITHMETIC_PARAMETER2,

        KEY_TYPE_OPTR_SELF_ASSIGN_RETURN,
        KEY_TYPE_OPTR_SELF_ASSIGN_PARAMETER1,

        KEY_TYPE_OPTR_UNARY_RETURN,
        KEY_TYPE_OPTR_UNARY_PARAMETER1,

        KEY_TYPE_OPTR_LOGIC_RETURN,
        KEY_TYPE_OPTR_LOGIC_PARAMETER1,
        KEY_TYPE_OPTR_LOGIC_PARAMETER2,

        KEY_TYPE_OPTR_RELATION_RETURN,
        KEY_TYPE_OPTR_RELATION_PARAMETER1,
        KEY_TYPE_OPTR_RELATION_PARAMETER2,

        KEY_TYPE_OPTR_CONDITIONAL_RETURN,
        KEY_TYPE_OPTR_CONDITIONAL_PARAMETER1,
        KEY_TYPE_OPTR_CONDITIONAL_PARAMETER2,
        KEY_TYPE_OPTR_CONDITIONAL_PARAMETER3,

        KEY_TYPE_OPTR_INSTANCE_OF_RETURN,
        KEY_TYPE_OPTR_INSTANCE_OF_PARAMETER1,
        KEY_TYPE_OPTR_INSTANCE_OF_PARAMETER2,

        KEY_TYPE_OPTR_END,
        // OPTR keys ends

        // error keys
        KEY_TYPE_ERROR,
    };

    static bool isOptrKeyType(int keyType);

    static void release();

    static void serialize(TYPE_MAP_MAP(string)&, string&);

    static void serialize(TYPE_MAP_MAP(set<string>)&, string&);

    static void deserialize();

    static void deserialize(TYPE_MAP_MAP(string)&, string&);

    static void deserialize(TYPE_MAP_MAP(set<string>)&, string&);

    static void initGlobalInfoWhichIsUpdatedAndNotRestored();

};

