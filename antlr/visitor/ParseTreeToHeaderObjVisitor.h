class ParseTreeToHeaderObjVisitor : public JavaParserBaseVisitor {
    CompilationUnit* header = new CompilationUnit();

    list<list<Type*>*> typeStack;
    list<list<string>*> enumStack;
    list<list<FieldOrParameter*>*> fieldStack;
    list<list<Method*>*> constructorStack;
    list<list<Method*>*> methodStack;

public:
    void setSrcFilePath(const string& filePath);

    list<FieldOrParameter*> convertVariableObj(VariableDeclaration* variableDeclaration);

    void pushStackForType(Type* type);

    void popStack();

    any visitCompilationUnit(JavaParser::CompilationUnitContext* ctx) override;

    any visitImportDeclaration(JavaParser::ImportDeclarationContext* ctx) override;

    any visitTypeDeclaration(JavaParser::TypeDeclarationContext* ctx) override;

    any visitClassDeclaration(JavaParser::ClassDeclarationContext* ctx) override;

    any visitClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext* ctx) override;

    any visitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext* ctx) override;

    any visitInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext* ctx) override;

    any visitEnumDeclaration(JavaParser::EnumDeclarationContext* ctx) override;
};
