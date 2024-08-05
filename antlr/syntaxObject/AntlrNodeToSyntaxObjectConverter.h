#ifndef JPARSER_ANTLRNODETOSYNTAXOBJECTCONVERTER_H
#define JPARSER_ANTLRNODETOSYNTAXOBJECTCONVERTER_H

struct NameAndRelatedExp {
    list<string> name;
    int dim = 0;
    JavaParser::ExpressionListContext* arguments = nullptr;
    JavaParser::ExpressionContext* initExpression = nullptr;
    JavaParser::ArrayInitializerContext* arrayInitValues = nullptr;
};

struct VariableDeclaration {
    unsigned int flag = 0;
    TypeName typeType;
    list<NameAndRelatedExp> nameAndValueCount;
};

class AntlrNodeToSyntaxObjectConverter {
public:

    static void convertTypeTypeOrVoid(JavaParser::TypeTypeOrVoidContext*, TypeName*);

    static void convertTypeType(JavaParser::TypeTypeContext*, TypeName*, vector<JavaParser::VariableModifierContext*> variableModivierCtxs = {});

    static void convertClassOrInterfaceType(JavaParser::ClassOrInterfaceTypeContext*, TypeName*);

    static void convertExplicitGenericInvocationSuffix(JavaParser::ExplicitGenericInvocationSuffixContext*, NameAndRelatedExp*);

    static void convertSuperSuffix(JavaParser::SuperSuffixContext*, NameAndRelatedExp*);

    static void convertArguments(JavaParser::ArgumentsContext*, NameAndRelatedExp*);

    static void convertMethodCall(JavaParser::MethodCallContext*, NameAndRelatedExp*);

    static void convertInnerCreator(JavaParser::InnerCreatorContext*, NameAndRelatedExp*);

    static void convertCreator(JavaParser::CreatorContext*, NameAndRelatedExp*);

    static void convertCreatedName(JavaParser::CreatedNameContext*, NameAndRelatedExp*);

    static void convertArrayInitializerNoRecur(JavaParser::ArrayInitializerContext*, NameAndRelatedExp*);

    static void convertArrayInitializerRecurForDim(JavaParser::ArrayInitializerContext*, NameAndRelatedExp*);

    static void convertVariableInitializerNoRecur(JavaParser::VariableInitializerContext*, NameAndRelatedExp*);

    static void convertLocalVariableDeclaration(JavaParser::LocalVariableDeclarationContext*, VariableDeclaration*);

    static void convertLocalVariableFromResource(JavaParser::ResourceContext*, VariableDeclaration*);

    static void convertClassOrInterfaceModifier(JavaParser::ClassOrInterfaceModifierContext* ctx, unsigned int* flag);

    static void convertClassOrInterfaceModifiers(const std::vector<JavaParser::ClassOrInterfaceModifierContext*>& ctx, unsigned int* flag);

    static void convertModifier(JavaParser::ModifierContext* ctx, unsigned int* flag);

    static void convertModifiers(const std::vector<JavaParser::ModifierContext*>& ctx, unsigned int* flag);

    static void convertTypeDeclaration(JavaParser::TypeDeclarationContext* ctx, Type*);

    static void convertTypeParam(JavaParser::TypeParameterContext* ctx, TypeParam* typeParam);

    static void convertClassDeclaration(JavaParser::ClassDeclarationContext*, Type*);

    static void convertEnumDeclaration(JavaParser::EnumDeclarationContext*, Type*);

    static void convertInterfaceDeclaration(JavaParser::InterfaceDeclarationContext*, Type*);

    static void convertFieldDeclaration(JavaParser::FieldDeclarationContext*, VariableDeclaration*);

    static void convertMethodDeclaration(JavaParser::MethodDeclarationContext*, Method*);

    static void convertConstructorDeclaration(JavaParser::ConstructorDeclarationContext*, Method*);

    static void convertInterfaceMethodDeclaration(JavaParser::InterfaceMethodDeclarationContext*, Method*);

    static void convertInterfaceMethodModifier(JavaParser::InterfaceMethodDeclarationContext*, Method*);

    static void convertConstDeclaration(JavaParser::ConstDeclarationContext*, VariableDeclaration*);

    static void convertConstDeclarator(JavaParser::ConstantDeclaratorContext*, NameAndRelatedExp*);

    static void convertMethodCallWithExplicitTypeArgument(JavaParser::PrimaryMethodCallWithExplicitTypeArgumentContext* ctx, NameAndRelatedExp* methodCall);

    static void convertClassBodyDeclarationField(JavaParser::ClassBodyDeclarationContext* ctx, VariableDeclaration* variableDeclaration);

    static void convertClassBodyDeclarationMethod(JavaParser::ClassBodyDeclarationContext* ctx, Method* method);

    static void convertClassBodyDeclarationType(JavaParser::ClassBodyDeclarationContext* ctx, Type* type);

    static void convertInterfaceBodyDeclarationConst(JavaParser::InterfaceBodyDeclarationContext* ctx, VariableDeclaration* variableDeclaration);

    static void convertInterfaceBodyDeclarationMethod(JavaParser::InterfaceBodyDeclarationContext* ctx, Method* method);

    static void convertInterfaceBodyDeclarationType(JavaParser::InterfaceBodyDeclarationContext* ctx, Type* type);

    static void convertVariableDeclarators(JavaParser::VariableDeclaratorsContext* ctx, VariableDeclaration* variableDeclarator);

    static bool convertFormalParameters(JavaParser::FormalParametersContext* ctx, list<FieldOrParameter*>& parameters);

    static void convertTypeParameters(JavaParser::TypeParametersContext* ctx, list<TypeParam*>& typeParameters);

    static void convertTypeArguments(JavaParser::TypeArgumentsContext* ctx, vector<TypeName*>& typeArguments);

    static void convertFormalParameter(JavaParser::FormalParameterContext* ctx, FieldOrParameter* parameter);

    static void convertLastFormalParameter(JavaParser::LastFormalParameterContext* ctx, FieldOrParameter* parameter);

    static void convertLambdaParameters(JavaParser::LambdaParametersContext* ctx, list<string>& paramName);

};

#endif //JPARSER_ANTLRNODETOSYNTAXOBJECTCONVERTER_H
