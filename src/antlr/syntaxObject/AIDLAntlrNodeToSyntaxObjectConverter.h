class AIDLAntlrNodeToSyntaxObjectConverter {
public:

    static void convertInterfaceDeclaration(AIDLParser::Interface_declContext* ctx, Type* type);
    static void convertMethodDeclaration(AIDLParser::Method_declContext* ctx, Method* method);
    static void convertTypeName(AIDLParser::TypeContext* ctx, TypeName* typeName);
    static void convertParameters(AIDLParser::Arg_non_empty_listContext* ctx, list<FieldOrParameter*>& parameters);
};
