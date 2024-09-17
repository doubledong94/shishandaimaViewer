class Serializable {
public:
    virtual void toFile(ofstream& f) {};
    virtual void fromFile(ifstream& f) {};
    static int getInt(ifstream& f);
    static unsigned getUInt(ifstream& f);
};

struct TypeName :public Serializable {
    int dim = 0;
    list<string> typeName;
    vector<TypeName*> typeArgs;
    void toFile(ofstream& f) override;
    void fromFile(ifstream& f) override;
    void copy(TypeName* origin);
};

class FieldOrParameter :public Serializable {
public:
    unsigned int flag = 0;
    string name;
    TypeName* typeName = NULL;
    void toFile(ofstream& f) override;
    void fromFile(ifstream& f) override;
};

class TypeParam :public Serializable {
public:
    string name;
    list<TypeName*> bounds;
    void toFile(ofstream& f) override;
    void fromFile(ifstream& f) override;
};

class Method :public Serializable {
public:
    unsigned int flag = 0;
    string name;
    TypeName* returnTypeName = NULL;
    list<FieldOrParameter*> parameters;
    list<TypeParam*> typeParams;
    bool isVariableParameter = false;
    void toFile(ofstream& f) override;
    void fromFile(ifstream& f) override;
};

class Type :public Serializable {
public:
    unsigned int flag = 0;
    string name;
    list<TypeName*> extendsTypeNames;
    list<TypeName*> implementsTypeNames;
    list<FieldOrParameter*> fields;
    list<Method*> constructors;
    list<Method*> methods;
    list<Type*> innerTypes;
    list<TypeParam*> typeParams;
    list<string> enumConstants;

    void toFile(ofstream& f) override;
    void fromFile(ifstream& f) override;
};

class CompilationUnit :public Serializable {
public:
    string package;

    list<string> importedTypes;
    list<string> importedPackageOrType;
    list<string> staticImported;
    list<string> starStaticImported;

    list<Type*> types;
    void toFile(ofstream& f) override;
    void fromFile(ifstream& f) override;
};