class ParseTreeToHeaderObjVisitor {
protected:
    CompilationUnit* header = new CompilationUnit();

    list<list<Type*>*> typeStack;
    list<list<string>*> enumStack;
    list<list<FieldOrParameter*>*> fieldStack;
    list<list<Method*>*> constructorStack;
    list<list<Method*>*> methodStack;

public:
    void setSrcFilePath(const string& filePath);

    void pushStackForType(Type* type);

    void popStack();

};
