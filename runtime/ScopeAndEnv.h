/**
 * kinds of runtime env info:
 *  1. local variables, parameters, field of this type and super type
 *  2. inner and outer types from self type and super types
 *  3. named imports
 *  4. types from same package
 *  5. star import
 *  6. lang package
 */

class PackageScopeAndEnv {
public:
    const static string langPackage;

    static map<string, PackageScopeAndEnv*> package2scopeAndEnv;

    /** build up */
    static void addScopeAndEnvForAllPackage();

    map<string, TypeInfo*> name2typeInPackage;

    string package;

    PackageScopeAndEnv(const string& package);

    static void release();
};

// this env is provided only for classes within that file
class FileScopeAndEnv {
public:
    static map<string, FileScopeAndEnv*> filePath2scopeAndEnv;

    /** build up */
    static void addImportedTypeNameScopeAndEnvForAllFile();

    /** build up */
    static void addImportedFieldAndMethodNameScopeAndEnvForAllFile();

    map<string, TypeInfo*> name2nameImportedType;
    map<string, TypeInfo*> name2starImportedType;
    map<string, FieldInfo*> name2nameImportedField;
    map<string, FieldInfo*> name2starImportField;
    map<string, list<MethodInfo*>> name2nameImportedMethod;
    map<string, list<MethodInfo*>> name2starImportedMethod;

    string filePath;

    FileScopeAndEnv(const string& filePath);

    static void release();
};


class OuterScopeAndEnv {
public:

    OuterScopeAndEnv* outerScopeAndEnv = nullptr;

    map<string, TypeInfo*> name2typeParamInfo;

    virtual TypeInfo* getTypeInfoFromSelf(const string& typeName) { return NULL; };

    virtual FieldInfo* getFieldInfoFromSelf(const string& fieldName) { return NULL; };

    virtual void getMethodInfoFromSelf(const string& name, int paramCount, list<MethodInfo*>& methodInfos) {};

    virtual bool findIdFromSelf(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, map<TypeInfo*, TypeInfo*>* typeArgs = NULL) { return false; };

    TypeInfo* getTypeInfoRecurOuterScope(const string& typeName);

    FieldInfo* getFieldInfoRecurOuterScope(const string& fieldName);

    void getMethodInfoRecurOuterScope(const string& name, int paramCount, list<MethodInfo*>& methodInfos);

    bool findIdRecurOuterScope(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, map<TypeInfo*, TypeInfo*>* typeArgs = NULL);

    virtual PackageScopeAndEnv* getPackageScope() { return NULL; };

    virtual FileScopeAndEnv* getFileScope() { return NULL; };
};


// this env is provided also for classes from other file
class ClassScopeAndEnv : public OuterScopeAndEnv {
public:
    ClassScopeAndEnv(TypeInfo* typeInfo);

    PackageScopeAndEnv* langPackageScopeAndEnv = nullptr;

    PackageScopeAndEnv* packageScopeAndEnv = nullptr;

    FileScopeAndEnv* fileScopeAndEnv = nullptr;

    list<ClassScopeAndEnv*> superScopeAndEnvs;

    TypeInfo* typeInfo = NULL;

    map<string, TypeInfo*> name2typeInfo;
    map<string, FieldInfo*> name2fieldInfo;
    map<string, list<MethodInfo*>> name2method;

    /** build up */
    void static addClassScopeAndEnvForAllTypes();

    /** build up */
    void static linkSuperScopeAndEnv(TypeInfo* typeInfo, TypeInfo* superTypeInfo);

    /** build up */
    void static addFieldAndMethodNamesForAllTypes();

    PackageScopeAndEnv* getPackageScope() override;

    FileScopeAndEnv* getFileScope() override;

    TypeInfo* getTypeInfoWithFileScope(const list<string>& typeNames);

    void getMethodInfoWithFileScope(const list<string>& names, int paramCount, list<MethodInfo*>& methodInfos, bool creator = false);

    bool findIdFromSelf(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, map<TypeInfo*, TypeInfo*>* typeArgs = NULL) override;

    TypeInfo* getTypeInfoFromSelf(const string& typeName) override;

    FieldInfo* getFieldInfoFromSelf(const string& fieldName) override;

    void getMethodInfoFromSelf(const string& name, int paramCount, list<MethodInfo*>& methodInfos) override;

    TypeInfo* getTypeInfoFromImports(const string& typeName);

    FieldInfo* getFieldInfoFromImports(const string& fieldName);

    void getMethodInfoFromImports(const string& name, int paramCount, list<MethodInfo*>& methodInfos);

    void addUsage(const string& usedTypeKey);

    static void release(ClassScopeAndEnv* toBeReleased);
};

class CodeBlockScopeAndEnv {

public:
    map<string, string> LVName2LVKey;
};

class MethodScopeAndEnv : public OuterScopeAndEnv {
public:
    /** build up */
    static MethodScopeAndEnv* createMethodScopeAndEnv(const string& methodKey, ClassScopeAndEnv* classScopeAndEnv);

    string methodKey;
    string methodIfKey;
    string methodElseKey;
    string methodForKey;
    string methodWhileKey;
    string methodCaseKey;
    string methodForEachKey;
    string methodTryKey;
    string methodCatchKey;
    string methodFinallyKey;

    map<string, FieldInfo*> name2paramInfo;
    FieldInfo* returnFieldInfo;
    list<CodeBlockScopeAndEnv*> codeBlockScopeAndEnvs;
    map<string, map<TypeInfo*, TypeInfo*>> lv2typeParam2typeArg;

    map<string, TypeInfo*> LVKey2LVTypeInfo;

    PackageScopeAndEnv* getPackageScope() override;

    FileScopeAndEnv* getFileScope() override;

    TypeInfo* getTypeInfoFromSelf(const string& typeName) override;

    FieldInfo* getFieldInfoFromSelf(const string& fieldName) override;

    void getMethodInfoFromSelf(const string& name, int paramCount, list<MethodInfo*>& methodInfos) override;

    bool findIdWithFileScope(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, map<TypeInfo*, TypeInfo*>* typeArgs = NULL);

    bool findIdFromSelf(const string& name, string& key, TypeInfo*& typeInfo, int& keyType, map<TypeInfo*, TypeInfo*>* typeArgs = NULL) override;

    TypeInfo* getTypeInfoWithFileScope(const list<string>& typeNames);

    string putLocalVariable(const string& name, TypeInfo* typeInfo, const string& structureKey);

    const static string rootStructureKey;
    const static char structureKeySeparator;

    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^code structure usage^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    static string getSupStructureKey(const string& structureKey);

};

class TypeUnification {
public:
    map<TypeInfo*, TypeInfo*> immediateTypeArgs;
    map<TypeInfo*, set<TypeInfo*>> intermediateTypeArgs;
    void resolveTypeParam(TypeInfo* typeParam, set<TypeInfo*>& done);
    TypeInfo* getTypeArgFromTypeParam(TypeInfo* typeParam);
    TypeInfo* getTyepBoundForTypeParam(TypeInfo* typeParam, set<TypeInfo*>& done);
    void addTypeMap(TypeInfo* from, TypeInfo* to);
    void clear();
    void copyFrom(TypeUnification* copied);
};



