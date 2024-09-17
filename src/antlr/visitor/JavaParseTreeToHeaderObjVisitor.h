class JavaParseTreeToHeaderObjVisitor : public JavaParserBaseVisitor, public ParseTreeToHeaderObjVisitor {
public:
    any visitCompilationUnit(JavaParser::CompilationUnitContext* ctx) override;

    any visitImportDeclaration(JavaParser::ImportDeclarationContext* ctx) override;

    any visitTypeDeclaration(JavaParser::TypeDeclarationContext* ctx) override;

    any visitClassDeclaration(JavaParser::ClassDeclarationContext* ctx) override;

    any visitClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext* ctx) override;

    any visitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext* ctx) override;

    any visitInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext* ctx) override;

    any visitEnumDeclaration(JavaParser::EnumDeclarationContext* ctx) override;

};
