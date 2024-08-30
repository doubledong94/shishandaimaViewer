class AIDLParseTreeToHeaderObjVisitor : public AIDLParserBaseVisitor, public ParseTreeToHeaderObjVisitor {
    std::any visitCompilationUnit(AIDLParser::CompilationUnitContext* ctx) override;
    std::any visitImportI(AIDLParser::ImportIContext* ctx) override;
    std::any visitInterface_decl(AIDLParser::Interface_declContext* ctx) override;
    std::any visitMethod_decl(AIDLParser::Method_declContext* ctx) override;
    void addGeneratedClass(Type* type);
};