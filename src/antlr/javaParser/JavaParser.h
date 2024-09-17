
// Generated from JavaParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  JavaParser : public antlr4::Parser {
public:
  enum {
    ABSTRACT = 1, ASSERT = 2, BOOLEAN = 3, BREAK = 4, BYTE = 5, CASE = 6, 
    CATCH = 7, CHAR = 8, CLASS = 9, CONST = 10, CONTINUE = 11, DEFAULT = 12, 
    DO = 13, DOUBLE = 14, ELSE = 15, ENUM = 16, EXTENDS = 17, FINAL = 18, 
    FINALLY = 19, FLOAT = 20, FOR = 21, IF = 22, GOTO = 23, IMPLEMENTS = 24, 
    IMPORT = 25, INSTANCEOF = 26, INT = 27, INTERFACE = 28, LONG = 29, NATIVE = 30, 
    NEW = 31, PACKAGE = 32, PRIVATE = 33, PROTECTED = 34, PUBLIC = 35, RETURN = 36, 
    SHORT = 37, STATIC = 38, STRICTFP = 39, SUPER = 40, SWITCH = 41, SYNCHRONIZED = 42, 
    THIS = 43, THROW = 44, THROWS = 45, TRANSIENT = 46, TRY = 47, VOID = 48, 
    VOLATILE = 49, WHILE = 50, MODULE = 51, OPEN = 52, REQUIRES = 53, EXPORTS = 54, 
    OPENS = 55, TO = 56, USES = 57, PROVIDES = 58, WITH = 59, TRANSITIVE = 60, 
    VAR = 61, YIELD = 62, RECORD = 63, SEALED = 64, PERMITS = 65, NON_SEALED = 66, 
    DECIMAL_LITERAL = 67, HEX_LITERAL = 68, OCT_LITERAL = 69, BINARY_LITERAL = 70, 
    FLOAT_LITERAL = 71, HEX_FLOAT_LITERAL = 72, BOOL_LITERAL = 73, CHAR_LITERAL = 74, 
    STRING_LITERAL = 75, TEXT_BLOCK = 76, NULL_LITERAL = 77, LPAREN = 78, 
    RPAREN = 79, LBRACE = 80, RBRACE = 81, LBRACK = 82, RBRACK = 83, SEMI = 84, 
    COMMA = 85, DOT = 86, ASSIGN = 87, GT = 88, LT = 89, BANG = 90, TILDE = 91, 
    QUESTION = 92, COLON = 93, EQUAL = 94, LE = 95, GE = 96, NOTEQUAL = 97, 
    AND = 98, OR = 99, INC = 100, DEC = 101, ADD = 102, SUB = 103, MUL = 104, 
    DIV = 105, BITAND = 106, BITOR = 107, CARET = 108, MOD = 109, ADD_ASSIGN = 110, 
    SUB_ASSIGN = 111, MUL_ASSIGN = 112, DIV_ASSIGN = 113, AND_ASSIGN = 114, 
    OR_ASSIGN = 115, XOR_ASSIGN = 116, MOD_ASSIGN = 117, LSHIFT_ASSIGN = 118, 
    RSHIFT_ASSIGN = 119, URSHIFT_ASSIGN = 120, ARROW = 121, COLONCOLON = 122, 
    AT = 123, ELLIPSIS = 124, WS = 125, COMMENT = 126, LINE_COMMENT = 127, 
    IDENTIFIER = 128
  };

  enum {
    RuleCompilationUnit = 0, RulePackageDeclaration = 1, RuleImportDeclaration = 2, 
    RuleTypeDeclaration = 3, RuleModifier = 4, RuleClassOrInterfaceModifier = 5, 
    RuleVariableModifier = 6, RuleClassDeclaration = 7, RuleTypeParameters = 8, 
    RuleTypeParameter = 9, RuleTypeBound = 10, RuleEnumDeclaration = 11, 
    RuleEnumConstants = 12, RuleEnumConstant = 13, RuleEnumBodyDeclarations = 14, 
    RuleInterfaceDeclaration = 15, RuleClassBody = 16, RuleInterfaceBody = 17, 
    RuleClassBodyDeclaration = 18, RuleMemberDeclaration = 19, RuleMethodDeclaration = 20, 
    RuleMethodBody = 21, RuleTypeTypeOrVoid = 22, RuleConstructorDeclaration = 23, 
    RuleFieldDeclaration = 24, RuleInterfaceBodyDeclaration = 25, RuleInterfaceMemberDeclaration = 26, 
    RuleConstDeclaration = 27, RuleConstantDeclarator = 28, RuleInterfaceMethodDeclaration = 29, 
    RuleInterfaceMethodModifier = 30, RuleInterfaceCommonBodyDeclaration = 31, 
    RuleVariableDeclarators = 32, RuleVariableDeclarator = 33, RuleVariableDeclaratorId = 34, 
    RuleVariableInitializer = 35, RuleArrayInitializer = 36, RuleClassOrInterfaceType = 37, 
    RuleTypeArgument = 38, RuleQualifiedNameList = 39, RuleFormalParameters = 40, 
    RuleReceiverParameter = 41, RuleFormalParameterList = 42, RuleFormalParameter = 43, 
    RuleLastFormalParameter = 44, RuleLambdaLVTIList = 45, RuleLambdaLVTIParameter = 46, 
    RuleQualifiedName = 47, RuleLiteral = 48, RuleIntegerLiteral = 49, RuleFloatLiteral = 50, 
    RuleAltAnnotationQualifiedName = 51, RuleAnnotation = 52, RuleElementValuePairs = 53, 
    RuleElementValuePair = 54, RuleElementValue = 55, RuleElementValueArrayInitializer = 56, 
    RuleAnnotationTypeDeclaration = 57, RuleAnnotationTypeBody = 58, RuleAnnotationTypeElementDeclaration = 59, 
    RuleAnnotationTypeElementRest = 60, RuleAnnotationMethodOrConstantRest = 61, 
    RuleAnnotationMethodRest = 62, RuleAnnotationConstantRest = 63, RuleDefaultValue = 64, 
    RuleModuleDeclaration = 65, RuleModuleBody = 66, RuleModuleDirective = 67, 
    RuleRequiresModifier = 68, RuleRecordDeclaration = 69, RuleRecordHeader = 70, 
    RuleRecordComponentList = 71, RuleRecordComponent = 72, RuleRecordBody = 73, 
    RuleBlock = 74, RuleBlockStatement = 75, RuleLocalVariableDeclaration = 76, 
    RuleIdentifier = 77, RuleLocalTypeDeclaration = 78, RuleStatement = 79, 
    RuleCatchClause = 80, RuleCatchType = 81, RuleFinallyBlock = 82, RuleResourceSpecification = 83, 
    RuleResources = 84, RuleResource = 85, RuleSwitchBlockStatementGroup = 86, 
    RuleSwitchLabel = 87, RuleForControl = 88, RuleForInit = 89, RuleForCondition = 90, 
    RuleForUpdate = 91, RuleEnhancedForControl = 92, RuleParExpression = 93, 
    RuleExpressionList = 94, RuleMethodCall = 95, RuleExpression = 96, RulePattern = 97, 
    RuleLambdaExpression = 98, RuleLambdaParameters = 99, RuleLambdaBody = 100, 
    RulePrimary = 101, RuleSwitchExpression = 102, RuleSwitchLabeledRule = 103, 
    RuleGuardedPattern = 104, RuleSwitchRuleOutcome = 105, RuleClassType = 106, 
    RuleCreator = 107, RuleCreatedName = 108, RuleInnerCreator = 109, RuleArrayCreatorRest = 110, 
    RuleClassCreatorRest = 111, RuleExplicitGenericInvocation = 112, RuleTypeArgumentsOrDiamond = 113, 
    RuleNonWildcardTypeArgumentsOrDiamond = 114, RuleNonWildcardTypeArguments = 115, 
    RuleTypeList = 116, RuleTypeType = 117, RulePrimitiveType = 118, RuleTypeArguments = 119, 
    RuleSuperSuffix = 120, RuleExplicitGenericInvocationSuffix = 121, RuleArguments = 122
  };

  explicit JavaParser(antlr4::TokenStream *input);

  JavaParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~JavaParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class CompilationUnitContext;
  class PackageDeclarationContext;
  class ImportDeclarationContext;
  class TypeDeclarationContext;
  class ModifierContext;
  class ClassOrInterfaceModifierContext;
  class VariableModifierContext;
  class ClassDeclarationContext;
  class TypeParametersContext;
  class TypeParameterContext;
  class TypeBoundContext;
  class EnumDeclarationContext;
  class EnumConstantsContext;
  class EnumConstantContext;
  class EnumBodyDeclarationsContext;
  class InterfaceDeclarationContext;
  class ClassBodyContext;
  class InterfaceBodyContext;
  class ClassBodyDeclarationContext;
  class MemberDeclarationContext;
  class MethodDeclarationContext;
  class MethodBodyContext;
  class TypeTypeOrVoidContext;
  class ConstructorDeclarationContext;
  class FieldDeclarationContext;
  class InterfaceBodyDeclarationContext;
  class InterfaceMemberDeclarationContext;
  class ConstDeclarationContext;
  class ConstantDeclaratorContext;
  class InterfaceMethodDeclarationContext;
  class InterfaceMethodModifierContext;
  class InterfaceCommonBodyDeclarationContext;
  class VariableDeclaratorsContext;
  class VariableDeclaratorContext;
  class VariableDeclaratorIdContext;
  class VariableInitializerContext;
  class ArrayInitializerContext;
  class ClassOrInterfaceTypeContext;
  class TypeArgumentContext;
  class QualifiedNameListContext;
  class FormalParametersContext;
  class ReceiverParameterContext;
  class FormalParameterListContext;
  class FormalParameterContext;
  class LastFormalParameterContext;
  class LambdaLVTIListContext;
  class LambdaLVTIParameterContext;
  class QualifiedNameContext;
  class LiteralContext;
  class IntegerLiteralContext;
  class FloatLiteralContext;
  class AltAnnotationQualifiedNameContext;
  class AnnotationContext;
  class ElementValuePairsContext;
  class ElementValuePairContext;
  class ElementValueContext;
  class ElementValueArrayInitializerContext;
  class AnnotationTypeDeclarationContext;
  class AnnotationTypeBodyContext;
  class AnnotationTypeElementDeclarationContext;
  class AnnotationTypeElementRestContext;
  class AnnotationMethodOrConstantRestContext;
  class AnnotationMethodRestContext;
  class AnnotationConstantRestContext;
  class DefaultValueContext;
  class ModuleDeclarationContext;
  class ModuleBodyContext;
  class ModuleDirectiveContext;
  class RequiresModifierContext;
  class RecordDeclarationContext;
  class RecordHeaderContext;
  class RecordComponentListContext;
  class RecordComponentContext;
  class RecordBodyContext;
  class BlockContext;
  class BlockStatementContext;
  class LocalVariableDeclarationContext;
  class IdentifierContext;
  class LocalTypeDeclarationContext;
  class StatementContext;
  class CatchClauseContext;
  class CatchTypeContext;
  class FinallyBlockContext;
  class ResourceSpecificationContext;
  class ResourcesContext;
  class ResourceContext;
  class SwitchBlockStatementGroupContext;
  class SwitchLabelContext;
  class ForControlContext;
  class ForInitContext;
  class ForConditionContext;
  class ForUpdateContext;
  class EnhancedForControlContext;
  class ParExpressionContext;
  class ExpressionListContext;
  class MethodCallContext;
  class ExpressionContext;
  class PatternContext;
  class LambdaExpressionContext;
  class LambdaParametersContext;
  class LambdaBodyContext;
  class PrimaryContext;
  class SwitchExpressionContext;
  class SwitchLabeledRuleContext;
  class GuardedPatternContext;
  class SwitchRuleOutcomeContext;
  class ClassTypeContext;
  class CreatorContext;
  class CreatedNameContext;
  class InnerCreatorContext;
  class ArrayCreatorRestContext;
  class ClassCreatorRestContext;
  class ExplicitGenericInvocationContext;
  class TypeArgumentsOrDiamondContext;
  class NonWildcardTypeArgumentsOrDiamondContext;
  class NonWildcardTypeArgumentsContext;
  class TypeListContext;
  class TypeTypeContext;
  class PrimitiveTypeContext;
  class TypeArgumentsContext;
  class SuperSuffixContext;
  class ExplicitGenericInvocationSuffixContext;
  class ArgumentsContext; 

  class  CompilationUnitContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PackageDeclarationContext *packageDeclaration();
    std::vector<ImportDeclarationContext *> importDeclaration();
    ImportDeclarationContext* importDeclaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    std::vector<TypeDeclarationContext *> typeDeclaration();
    TypeDeclarationContext* typeDeclaration(size_t i);
    ModuleDeclarationContext *moduleDeclaration();
    antlr4::tree::TerminalNode *EOF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompilationUnitContext* compilationUnit();

  class  PackageDeclarationContext : public antlr4::ParserRuleContext {
  public:
    PackageDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PackageDeclarationContext* packageDeclaration();

  class  ImportDeclarationContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *importAll = nullptr;
    ImportDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *STATIC();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *MUL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportDeclarationContext* importDeclaration();

  class  TypeDeclarationContext : public antlr4::ParserRuleContext {
  public:
    TypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassDeclarationContext *classDeclaration();
    EnumDeclarationContext *enumDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    AnnotationTypeDeclarationContext *annotationTypeDeclaration();
    RecordDeclarationContext *recordDeclaration();
    std::vector<ClassOrInterfaceModifierContext *> classOrInterfaceModifier();
    ClassOrInterfaceModifierContext* classOrInterfaceModifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDeclarationContext* typeDeclaration();

  class  ModifierContext : public antlr4::ParserRuleContext {
  public:
    ModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassOrInterfaceModifierContext *classOrInterfaceModifier();
    antlr4::tree::TerminalNode *NATIVE();
    antlr4::tree::TerminalNode *SYNCHRONIZED();
    antlr4::tree::TerminalNode *TRANSIENT();
    antlr4::tree::TerminalNode *VOLATILE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModifierContext* modifier();

  class  ClassOrInterfaceModifierContext : public antlr4::ParserRuleContext {
  public:
    ClassOrInterfaceModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationContext *annotation();
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *STATIC();
    antlr4::tree::TerminalNode *ABSTRACT();
    antlr4::tree::TerminalNode *FINAL();
    antlr4::tree::TerminalNode *STRICTFP();
    antlr4::tree::TerminalNode *SEALED();
    antlr4::tree::TerminalNode *NON_SEALED();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassOrInterfaceModifierContext* classOrInterfaceModifier();

  class  VariableModifierContext : public antlr4::ParserRuleContext {
  public:
    VariableModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FINAL();
    AnnotationContext *annotation();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableModifierContext* variableModifier();

  class  ClassDeclarationContext : public antlr4::ParserRuleContext {
  public:
    JavaParser::TypeTypeContext *super = nullptr;
    JavaParser::TypeListContext *interface = nullptr;
    ClassDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    IdentifierContext *identifier();
    ClassBodyContext *classBody();
    TypeParametersContext *typeParameters();
    antlr4::tree::TerminalNode *EXTENDS();
    antlr4::tree::TerminalNode *IMPLEMENTS();
    antlr4::tree::TerminalNode *PERMITS();
    std::vector<TypeListContext *> typeList();
    TypeListContext* typeList(size_t i);
    TypeTypeContext *typeType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDeclarationContext* classDeclaration();

  class  TypeParametersContext : public antlr4::ParserRuleContext {
  public:
    TypeParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    std::vector<TypeParameterContext *> typeParameter();
    TypeParameterContext* typeParameter(size_t i);
    antlr4::tree::TerminalNode *GT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeParametersContext* typeParameters();

  class  TypeParameterContext : public antlr4::ParserRuleContext {
  public:
    TypeParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    antlr4::tree::TerminalNode *EXTENDS();
    TypeBoundContext *typeBound();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeParameterContext* typeParameter();

  class  TypeBoundContext : public antlr4::ParserRuleContext {
  public:
    TypeBoundContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeTypeContext *> typeType();
    TypeTypeContext* typeType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BITAND();
    antlr4::tree::TerminalNode* BITAND(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeBoundContext* typeBound();

  class  EnumDeclarationContext : public antlr4::ParserRuleContext {
  public:
    JavaParser::TypeListContext *interface = nullptr;
    EnumDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *IMPLEMENTS();
    EnumConstantsContext *enumConstants();
    antlr4::tree::TerminalNode *COMMA();
    EnumBodyDeclarationsContext *enumBodyDeclarations();
    TypeListContext *typeList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumDeclarationContext* enumDeclaration();

  class  EnumConstantsContext : public antlr4::ParserRuleContext {
  public:
    EnumConstantsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EnumConstantContext *> enumConstant();
    EnumConstantContext* enumConstant(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumConstantsContext* enumConstants();

  class  EnumConstantContext : public antlr4::ParserRuleContext {
  public:
    EnumConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    ArgumentsContext *arguments();
    ClassBodyContext *classBody();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumConstantContext* enumConstant();

  class  EnumBodyDeclarationsContext : public antlr4::ParserRuleContext {
  public:
    EnumBodyDeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    std::vector<ClassBodyDeclarationContext *> classBodyDeclaration();
    ClassBodyDeclarationContext* classBodyDeclaration(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumBodyDeclarationsContext* enumBodyDeclarations();

  class  InterfaceDeclarationContext : public antlr4::ParserRuleContext {
  public:
    JavaParser::TypeListContext *super = nullptr;
    InterfaceDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERFACE();
    IdentifierContext *identifier();
    InterfaceBodyContext *interfaceBody();
    TypeParametersContext *typeParameters();
    antlr4::tree::TerminalNode *EXTENDS();
    antlr4::tree::TerminalNode *PERMITS();
    std::vector<TypeListContext *> typeList();
    TypeListContext* typeList(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceDeclarationContext* interfaceDeclaration();

  class  ClassBodyContext : public antlr4::ParserRuleContext {
  public:
    ClassBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ClassBodyDeclarationContext *> classBodyDeclaration();
    ClassBodyDeclarationContext* classBodyDeclaration(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassBodyContext* classBody();

  class  InterfaceBodyContext : public antlr4::ParserRuleContext {
  public:
    InterfaceBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<InterfaceBodyDeclarationContext *> interfaceBodyDeclaration();
    InterfaceBodyDeclarationContext* interfaceBodyDeclaration(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceBodyContext* interfaceBody();

  class  ClassBodyDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ClassBodyDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    BlockContext *block();
    antlr4::tree::TerminalNode *STATIC();
    MemberDeclarationContext *memberDeclaration();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassBodyDeclarationContext* classBodyDeclaration();

  class  MemberDeclarationContext : public antlr4::ParserRuleContext {
  public:
    MemberDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RecordDeclarationContext *recordDeclaration();
    MethodDeclarationContext *methodDeclaration();
    FieldDeclarationContext *fieldDeclaration();
    ConstructorDeclarationContext *constructorDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    AnnotationTypeDeclarationContext *annotationTypeDeclaration();
    ClassDeclarationContext *classDeclaration();
    EnumDeclarationContext *enumDeclaration();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MemberDeclarationContext* memberDeclaration();

  class  MethodDeclarationContext : public antlr4::ParserRuleContext {
  public:
    MethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeOrVoidContext *typeTypeOrVoid();
    IdentifierContext *identifier();
    FormalParametersContext *formalParameters();
    MethodBodyContext *methodBody();
    TypeParametersContext *typeParameters();
    std::vector<antlr4::tree::TerminalNode *> LBRACK();
    antlr4::tree::TerminalNode* LBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);
    antlr4::tree::TerminalNode *THROWS();
    QualifiedNameListContext *qualifiedNameList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodDeclarationContext* methodDeclaration();

  class  MethodBodyContext : public antlr4::ParserRuleContext {
  public:
    MethodBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodBodyContext* methodBody();

  class  TypeTypeOrVoidContext : public antlr4::ParserRuleContext {
  public:
    TypeTypeOrVoidContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    antlr4::tree::TerminalNode *VOID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeTypeOrVoidContext* typeTypeOrVoid();

  class  ConstructorDeclarationContext : public antlr4::ParserRuleContext {
  public:
    JavaParser::BlockContext *constructorBody = nullptr;
    ConstructorDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    FormalParametersContext *formalParameters();
    BlockContext *block();
    TypeParametersContext *typeParameters();
    antlr4::tree::TerminalNode *THROWS();
    QualifiedNameListContext *qualifiedNameList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructorDeclarationContext* constructorDeclaration();

  class  FieldDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FieldDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    VariableDeclaratorsContext *variableDeclarators();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldDeclarationContext* fieldDeclaration();

  class  InterfaceBodyDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InterfaceBodyDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InterfaceMemberDeclarationContext *interfaceMemberDeclaration();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceBodyDeclarationContext* interfaceBodyDeclaration();

  class  InterfaceMemberDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InterfaceMemberDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclarationContext *constDeclaration();
    InterfaceMethodDeclarationContext *interfaceMethodDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    AnnotationTypeDeclarationContext *annotationTypeDeclaration();
    ClassDeclarationContext *classDeclaration();
    EnumDeclarationContext *enumDeclaration();
    RecordDeclarationContext *recordDeclaration();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceMemberDeclarationContext* interfaceMemberDeclaration();

  class  ConstDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    std::vector<ConstantDeclaratorContext *> constantDeclarator();
    ConstantDeclaratorContext* constantDeclarator(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclarationContext* constDeclaration();

  class  ConstantDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    ConstantDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    VariableInitializerContext *variableInitializer();
    std::vector<antlr4::tree::TerminalNode *> LBRACK();
    antlr4::tree::TerminalNode* LBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantDeclaratorContext* constantDeclarator();

  class  InterfaceMethodDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InterfaceMethodDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InterfaceCommonBodyDeclarationContext *interfaceCommonBodyDeclaration();
    std::vector<InterfaceMethodModifierContext *> interfaceMethodModifier();
    InterfaceMethodModifierContext* interfaceMethodModifier(size_t i);
    TypeParametersContext *typeParameters();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceMethodDeclarationContext* interfaceMethodDeclaration();

  class  InterfaceMethodModifierContext : public antlr4::ParserRuleContext {
  public:
    InterfaceMethodModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationContext *annotation();
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *ABSTRACT();
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *STATIC();
    antlr4::tree::TerminalNode *STRICTFP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceMethodModifierContext* interfaceMethodModifier();

  class  InterfaceCommonBodyDeclarationContext : public antlr4::ParserRuleContext {
  public:
    InterfaceCommonBodyDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeOrVoidContext *typeTypeOrVoid();
    IdentifierContext *identifier();
    FormalParametersContext *formalParameters();
    MethodBodyContext *methodBody();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LBRACK();
    antlr4::tree::TerminalNode* LBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);
    antlr4::tree::TerminalNode *THROWS();
    QualifiedNameListContext *qualifiedNameList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceCommonBodyDeclarationContext* interfaceCommonBodyDeclaration();

  class  VariableDeclaratorsContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclaratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableDeclaratorContext *> variableDeclarator();
    VariableDeclaratorContext* variableDeclarator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclaratorsContext* variableDeclarators();

  class  VariableDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclaratorIdContext *variableDeclaratorId();
    antlr4::tree::TerminalNode *ASSIGN();
    VariableInitializerContext *variableInitializer();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclaratorContext* variableDeclarator();

  class  VariableDeclaratorIdContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclaratorIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    std::vector<antlr4::tree::TerminalNode *> LBRACK();
    antlr4::tree::TerminalNode* LBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclaratorIdContext* variableDeclaratorId();

  class  VariableInitializerContext : public antlr4::ParserRuleContext {
  public:
    VariableInitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayInitializerContext *arrayInitializer();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableInitializerContext* variableInitializer();

  class  ArrayInitializerContext : public antlr4::ParserRuleContext {
  public:
    ArrayInitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<VariableInitializerContext *> variableInitializer();
    VariableInitializerContext* variableInitializer(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayInitializerContext* arrayInitializer();

  class  ClassOrInterfaceTypeContext : public antlr4::ParserRuleContext {
  public:
    ClassOrInterfaceTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<TypeArgumentsContext *> typeArguments();
    TypeArgumentsContext* typeArguments(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassOrInterfaceTypeContext* classOrInterfaceType();

  class  TypeArgumentContext : public antlr4::ParserRuleContext {
  public:
    TypeArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    antlr4::tree::TerminalNode *QUESTION();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    antlr4::tree::TerminalNode *EXTENDS();
    antlr4::tree::TerminalNode *SUPER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeArgumentContext* typeArgument();

  class  QualifiedNameListContext : public antlr4::ParserRuleContext {
  public:
    QualifiedNameListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QualifiedNameContext *> qualifiedName();
    QualifiedNameContext* qualifiedName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualifiedNameListContext* qualifiedNameList();

  class  FormalParametersContext : public antlr4::ParserRuleContext {
  public:
    FormalParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ReceiverParameterContext *receiverParameter();
    antlr4::tree::TerminalNode *COMMA();
    FormalParameterListContext *formalParameterList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParametersContext* formalParameters();

  class  ReceiverParameterContext : public antlr4::ParserRuleContext {
  public:
    ReceiverParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    antlr4::tree::TerminalNode *THIS();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReceiverParameterContext* receiverParameter();

  class  FormalParameterListContext : public antlr4::ParserRuleContext {
  public:
    FormalParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FormalParameterContext *> formalParameter();
    FormalParameterContext* formalParameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    LastFormalParameterContext *lastFormalParameter();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParameterListContext* formalParameterList();

  class  FormalParameterContext : public antlr4::ParserRuleContext {
  public:
    FormalParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    VariableDeclaratorIdContext *variableDeclaratorId();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormalParameterContext* formalParameter();

  class  LastFormalParameterContext : public antlr4::ParserRuleContext {
  public:
    LastFormalParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    antlr4::tree::TerminalNode *ELLIPSIS();
    VariableDeclaratorIdContext *variableDeclaratorId();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LastFormalParameterContext* lastFormalParameter();

  class  LambdaLVTIListContext : public antlr4::ParserRuleContext {
  public:
    LambdaLVTIListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LambdaLVTIParameterContext *> lambdaLVTIParameter();
    LambdaLVTIParameterContext* lambdaLVTIParameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaLVTIListContext* lambdaLVTIList();

  class  LambdaLVTIParameterContext : public antlr4::ParserRuleContext {
  public:
    LambdaLVTIParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    IdentifierContext *identifier();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaLVTIParameterContext* lambdaLVTIParameter();

  class  QualifiedNameContext : public antlr4::ParserRuleContext {
  public:
    QualifiedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualifiedNameContext* qualifiedName();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerLiteralContext *integerLiteral();
    FloatLiteralContext *floatLiteral();
    antlr4::tree::TerminalNode *CHAR_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *BOOL_LITERAL();
    antlr4::tree::TerminalNode *NULL_LITERAL();
    antlr4::tree::TerminalNode *TEXT_BLOCK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  IntegerLiteralContext : public antlr4::ParserRuleContext {
  public:
    IntegerLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECIMAL_LITERAL();
    antlr4::tree::TerminalNode *HEX_LITERAL();
    antlr4::tree::TerminalNode *OCT_LITERAL();
    antlr4::tree::TerminalNode *BINARY_LITERAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntegerLiteralContext* integerLiteral();

  class  FloatLiteralContext : public antlr4::ParserRuleContext {
  public:
    FloatLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    antlr4::tree::TerminalNode *HEX_FLOAT_LITERAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FloatLiteralContext* floatLiteral();

  class  AltAnnotationQualifiedNameContext : public antlr4::ParserRuleContext {
  public:
    AltAnnotationQualifiedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AltAnnotationQualifiedNameContext* altAnnotationQualifiedName();

  class  AnnotationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    QualifiedNameContext *qualifiedName();
    AltAnnotationQualifiedNameContext *altAnnotationQualifiedName();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ElementValuePairsContext *elementValuePairs();
    ElementValueContext *elementValue();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationContext* annotation();

  class  ElementValuePairsContext : public antlr4::ParserRuleContext {
  public:
    ElementValuePairsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ElementValuePairContext *> elementValuePair();
    ElementValuePairContext* elementValuePair(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementValuePairsContext* elementValuePairs();

  class  ElementValuePairContext : public antlr4::ParserRuleContext {
  public:
    ElementValuePairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    ElementValueContext *elementValue();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementValuePairContext* elementValuePair();

  class  ElementValueContext : public antlr4::ParserRuleContext {
  public:
    ElementValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    AnnotationContext *annotation();
    ElementValueArrayInitializerContext *elementValueArrayInitializer();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementValueContext* elementValue();

  class  ElementValueArrayInitializerContext : public antlr4::ParserRuleContext {
  public:
    ElementValueArrayInitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ElementValueContext *> elementValue();
    ElementValueContext* elementValue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementValueArrayInitializerContext* elementValueArrayInitializer();

  class  AnnotationTypeDeclarationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationTypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *INTERFACE();
    IdentifierContext *identifier();
    AnnotationTypeBodyContext *annotationTypeBody();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationTypeDeclarationContext* annotationTypeDeclaration();

  class  AnnotationTypeBodyContext : public antlr4::ParserRuleContext {
  public:
    AnnotationTypeBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<AnnotationTypeElementDeclarationContext *> annotationTypeElementDeclaration();
    AnnotationTypeElementDeclarationContext* annotationTypeElementDeclaration(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationTypeBodyContext* annotationTypeBody();

  class  AnnotationTypeElementDeclarationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationTypeElementDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationTypeElementRestContext *annotationTypeElementRest();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationTypeElementDeclarationContext* annotationTypeElementDeclaration();

  class  AnnotationTypeElementRestContext : public antlr4::ParserRuleContext {
  public:
    AnnotationTypeElementRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    AnnotationMethodOrConstantRestContext *annotationMethodOrConstantRest();
    antlr4::tree::TerminalNode *SEMI();
    ClassDeclarationContext *classDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    EnumDeclarationContext *enumDeclaration();
    AnnotationTypeDeclarationContext *annotationTypeDeclaration();
    RecordDeclarationContext *recordDeclaration();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationTypeElementRestContext* annotationTypeElementRest();

  class  AnnotationMethodOrConstantRestContext : public antlr4::ParserRuleContext {
  public:
    AnnotationMethodOrConstantRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AnnotationMethodRestContext *annotationMethodRest();
    AnnotationConstantRestContext *annotationConstantRest();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationMethodOrConstantRestContext* annotationMethodOrConstantRest();

  class  AnnotationMethodRestContext : public antlr4::ParserRuleContext {
  public:
    AnnotationMethodRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    DefaultValueContext *defaultValue();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationMethodRestContext* annotationMethodRest();

  class  AnnotationConstantRestContext : public antlr4::ParserRuleContext {
  public:
    AnnotationConstantRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclaratorsContext *variableDeclarators();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationConstantRestContext* annotationConstantRest();

  class  DefaultValueContext : public antlr4::ParserRuleContext {
  public:
    DefaultValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULT();
    ElementValueContext *elementValue();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefaultValueContext* defaultValue();

  class  ModuleDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ModuleDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MODULE();
    QualifiedNameContext *qualifiedName();
    ModuleBodyContext *moduleBody();
    antlr4::tree::TerminalNode *OPEN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleDeclarationContext* moduleDeclaration();

  class  ModuleBodyContext : public antlr4::ParserRuleContext {
  public:
    ModuleBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ModuleDirectiveContext *> moduleDirective();
    ModuleDirectiveContext* moduleDirective(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleBodyContext* moduleBody();

  class  ModuleDirectiveContext : public antlr4::ParserRuleContext {
  public:
    ModuleDirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REQUIRES();
    std::vector<QualifiedNameContext *> qualifiedName();
    QualifiedNameContext* qualifiedName(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    std::vector<RequiresModifierContext *> requiresModifier();
    RequiresModifierContext* requiresModifier(size_t i);
    antlr4::tree::TerminalNode *EXPORTS();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *OPENS();
    antlr4::tree::TerminalNode *USES();
    antlr4::tree::TerminalNode *PROVIDES();
    antlr4::tree::TerminalNode *WITH();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleDirectiveContext* moduleDirective();

  class  RequiresModifierContext : public antlr4::ParserRuleContext {
  public:
    RequiresModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRANSITIVE();
    antlr4::tree::TerminalNode *STATIC();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RequiresModifierContext* requiresModifier();

  class  RecordDeclarationContext : public antlr4::ParserRuleContext {
  public:
    RecordDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RECORD();
    IdentifierContext *identifier();
    RecordHeaderContext *recordHeader();
    RecordBodyContext *recordBody();
    TypeParametersContext *typeParameters();
    antlr4::tree::TerminalNode *IMPLEMENTS();
    TypeListContext *typeList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordDeclarationContext* recordDeclaration();

  class  RecordHeaderContext : public antlr4::ParserRuleContext {
  public:
    RecordHeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    RecordComponentListContext *recordComponentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordHeaderContext* recordHeader();

  class  RecordComponentListContext : public antlr4::ParserRuleContext {
  public:
    RecordComponentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RecordComponentContext *> recordComponent();
    RecordComponentContext* recordComponent(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordComponentListContext* recordComponentList();

  class  RecordComponentContext : public antlr4::ParserRuleContext {
  public:
    RecordComponentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    IdentifierContext *identifier();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordComponentContext* recordComponent();

  class  RecordBodyContext : public antlr4::ParserRuleContext {
  public:
    RecordBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ClassBodyDeclarationContext *> classBodyDeclaration();
    ClassBodyDeclarationContext* classBodyDeclaration(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordBodyContext* recordBody();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<BlockStatementContext *> blockStatement();
    BlockStatementContext* blockStatement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  BlockStatementContext : public antlr4::ParserRuleContext {
  public:
    BlockStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LocalVariableDeclarationContext *localVariableDeclaration();
    antlr4::tree::TerminalNode *SEMI();
    LocalTypeDeclarationContext *localTypeDeclaration();
    StatementContext *statement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockStatementContext* blockStatement();

  class  LocalVariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    LocalVariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    TypeTypeContext *typeType();
    VariableDeclaratorsContext *variableDeclarators();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocalVariableDeclarationContext* localVariableDeclaration();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *MODULE();
    antlr4::tree::TerminalNode *OPEN();
    antlr4::tree::TerminalNode *REQUIRES();
    antlr4::tree::TerminalNode *EXPORTS();
    antlr4::tree::TerminalNode *OPENS();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *USES();
    antlr4::tree::TerminalNode *PROVIDES();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *TRANSITIVE();
    antlr4::tree::TerminalNode *YIELD();
    antlr4::tree::TerminalNode *SEALED();
    antlr4::tree::TerminalNode *PERMITS();
    antlr4::tree::TerminalNode *RECORD();
    antlr4::tree::TerminalNode *VAR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  LocalTypeDeclarationContext : public antlr4::ParserRuleContext {
  public:
    LocalTypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassDeclarationContext *classDeclaration();
    InterfaceDeclarationContext *interfaceDeclaration();
    RecordDeclarationContext *recordDeclaration();
    std::vector<ClassOrInterfaceModifierContext *> classOrInterfaceModifier();
    ClassOrInterfaceModifierContext* classOrInterfaceModifier(size_t i);
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocalTypeDeclarationContext* localTypeDeclaration();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StatementThrowContext : public StatementContext {
  public:
    StatementThrowContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *THROW();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementContinueContext : public StatementContext {
  public:
    StatementContinueContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CONTINUE();
    antlr4::tree::TerminalNode *SEMI();
    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementSemiContext : public StatementContext {
  public:
    StatementSemiContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementReturnContext : public StatementContext {
  public:
    StatementReturnContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMI();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementSwitchExpContext : public StatementContext {
  public:
    StatementSwitchExpContext(StatementContext *ctx);

    SwitchExpressionContext *switchExpression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementForContext : public StatementContext {
  public:
    StatementForContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    ForControlContext *forControl();
    antlr4::tree::TerminalNode *RPAREN();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementYieldContext : public StatementContext {
  public:
    StatementYieldContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *YIELD();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementLabelContext : public StatementContext {
  public:
    StatementLabelContext(StatementContext *ctx);

    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *COLON();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementBlockContext : public StatementContext {
  public:
    StatementBlockContext(StatementContext *ctx);

    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementAssertContext : public StatementContext {
  public:
    StatementAssertContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *ASSERT();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *COLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementSwitchContext : public StatementContext {
  public:
    StatementSwitchContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SWITCH();
    ParExpressionContext *parExpression();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<SwitchBlockStatementGroupContext *> switchBlockStatementGroup();
    SwitchBlockStatementGroupContext* switchBlockStatementGroup(size_t i);
    std::vector<SwitchLabelContext *> switchLabel();
    SwitchLabelContext* switchLabel(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementBreakContext : public StatementContext {
  public:
    StatementBreakContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *SEMI();
    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementDoWhileContext : public StatementContext {
  public:
    StatementDoWhileContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();
    antlr4::tree::TerminalNode *WHILE();
    ParExpressionContext *parExpression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementExpContext : public StatementContext {
  public:
    StatementExpContext(StatementContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementTryContext : public StatementContext {
  public:
    StatementTryContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *TRY();
    BlockContext *block();
    FinallyBlockContext *finallyBlock();
    std::vector<CatchClauseContext *> catchClause();
    CatchClauseContext* catchClause(size_t i);
    ResourceSpecificationContext *resourceSpecification();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementSyncContext : public StatementContext {
  public:
    StatementSyncContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SYNCHRONIZED();
    ParExpressionContext *parExpression();
    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementWhileContext : public StatementContext {
  public:
    StatementWhileContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    ParExpressionContext *parExpression();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementIfContext : public StatementContext {
  public:
    StatementIfContext(StatementContext *ctx);

    JavaParser::StatementContext *ifState = nullptr;
    JavaParser::StatementContext *elseState = nullptr;
    antlr4::tree::TerminalNode *IF();
    ParExpressionContext *parExpression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  CatchClauseContext : public antlr4::ParserRuleContext {
  public:
    CatchClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CATCH();
    antlr4::tree::TerminalNode *LPAREN();
    CatchTypeContext *catchType();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *RPAREN();
    BlockContext *block();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatchClauseContext* catchClause();

  class  CatchTypeContext : public antlr4::ParserRuleContext {
  public:
    CatchTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QualifiedNameContext *> qualifiedName();
    QualifiedNameContext* qualifiedName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BITOR();
    antlr4::tree::TerminalNode* BITOR(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatchTypeContext* catchType();

  class  FinallyBlockContext : public antlr4::ParserRuleContext {
  public:
    FinallyBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FINALLY();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FinallyBlockContext* finallyBlock();

  class  ResourceSpecificationContext : public antlr4::ParserRuleContext {
  public:
    ResourceSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ResourcesContext *resources();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResourceSpecificationContext* resourceSpecification();

  class  ResourcesContext : public antlr4::ParserRuleContext {
  public:
    ResourcesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ResourceContext *> resource();
    ResourceContext* resource(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResourcesContext* resources();

  class  ResourceContext : public antlr4::ParserRuleContext {
  public:
    ResourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    ClassOrInterfaceTypeContext *classOrInterfaceType();
    VariableDeclaratorIdContext *variableDeclaratorId();
    antlr4::tree::TerminalNode *VAR();
    IdentifierContext *identifier();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResourceContext* resource();

  class  SwitchBlockStatementGroupContext : public antlr4::ParserRuleContext {
  public:
    SwitchBlockStatementGroupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SwitchLabelContext *> switchLabel();
    SwitchLabelContext* switchLabel(size_t i);
    std::vector<BlockStatementContext *> blockStatement();
    BlockStatementContext* blockStatement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchBlockStatementGroupContext* switchBlockStatementGroup();

  class  SwitchLabelContext : public antlr4::ParserRuleContext {
  public:
    SwitchLabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *DEFAULT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchLabelContext* switchLabel();

  class  ForControlContext : public antlr4::ParserRuleContext {
  public:
    ForControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EnhancedForControlContext *enhancedForControl();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    ForInitContext *forInit();
    ForConditionContext *forCondition();
    ForUpdateContext *forUpdate();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForControlContext* forControl();

  class  ForInitContext : public antlr4::ParserRuleContext {
  public:
    ForInitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LocalVariableDeclarationContext *localVariableDeclaration();
    ExpressionListContext *expressionList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForInitContext* forInit();

  class  ForConditionContext : public antlr4::ParserRuleContext {
  public:
    ForConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForConditionContext* forCondition();

  class  ForUpdateContext : public antlr4::ParserRuleContext {
  public:
    ForUpdateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionListContext *expressionList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForUpdateContext* forUpdate();

  class  EnhancedForControlContext : public antlr4::ParserRuleContext {
  public:
    EnhancedForControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclaratorIdContext *variableDeclaratorId();
    antlr4::tree::TerminalNode *COLON();
    ExpressionContext *expression();
    TypeTypeContext *typeType();
    antlr4::tree::TerminalNode *VAR();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnhancedForControlContext* enhancedForControl();

  class  ParExpressionContext : public antlr4::ParserRuleContext {
  public:
    ParExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParExpressionContext* parExpression();

  class  ExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionListContext* expressionList();

  class  MethodCallContext : public antlr4::ParserRuleContext {
  public:
    MethodCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *THIS();
    antlr4::tree::TerminalNode *SUPER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MethodCallContext* methodCall();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExpressionNewContext : public ExpressionContext {
  public:
    ExpressionNewContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *NEW();
    CreatorContext *creator();
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionPosNegSignContext : public ExpressionContext {
  public:
    ExpressionPosNegSignContext(ExpressionContext *ctx);

    antlr4::Token *prefix = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionReferenceContext : public ExpressionContext {
  public:
    ExpressionReferenceContext(ExpressionContext *ctx);

    antlr4::Token *bop = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DOT();
    IdentifierContext *identifier();
    MethodCallContext *methodCall();
    antlr4::tree::TerminalNode *THIS();
    antlr4::tree::TerminalNode *NEW();
    InnerCreatorContext *innerCreator();
    antlr4::tree::TerminalNode *SUPER();
    SuperSuffixContext *superSuffix();
    ExplicitGenericInvocationContext *explicitGenericInvocation();
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionMethodReferenceContext : public ExpressionContext {
  public:
    ExpressionMethodReferenceContext(ExpressionContext *ctx);

    TypeTypeContext *typeType();
    antlr4::tree::TerminalNode *COLONCOLON();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *NEW();
    TypeArgumentsContext *typeArguments();
    ClassTypeContext *classType();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionInstanceOfContext : public ExpressionContext {
  public:
    ExpressionInstanceOfContext(ExpressionContext *ctx);

    antlr4::Token *bop = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *INSTANCEOF();
    TypeTypeContext *typeType();
    PatternContext *pattern();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionAssignContext : public ExpressionContext {
  public:
    ExpressionAssignContext(ExpressionContext *ctx);

    JavaParser::ExpressionContext *e1 = nullptr;
    antlr4::Token *bop = nullptr;
    JavaParser::ExpressionContext *e2 = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *ADD_ASSIGN();
    antlr4::tree::TerminalNode *SUB_ASSIGN();
    antlr4::tree::TerminalNode *MUL_ASSIGN();
    antlr4::tree::TerminalNode *DIV_ASSIGN();
    antlr4::tree::TerminalNode *AND_ASSIGN();
    antlr4::tree::TerminalNode *OR_ASSIGN();
    antlr4::tree::TerminalNode *XOR_ASSIGN();
    antlr4::tree::TerminalNode *RSHIFT_ASSIGN();
    antlr4::tree::TerminalNode *URSHIFT_ASSIGN();
    antlr4::tree::TerminalNode *LSHIFT_ASSIGN();
    antlr4::tree::TerminalNode *MOD_ASSIGN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionUnaryLogicalContext : public ExpressionContext {
  public:
    ExpressionUnaryLogicalContext(ExpressionContext *ctx);

    antlr4::Token *prefix = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *BANG();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionLambdaContext : public ExpressionContext {
  public:
    ExpressionLambdaContext(ExpressionContext *ctx);

    LambdaExpressionContext *lambdaExpression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionPrimaryContext : public ExpressionContext {
  public:
    ExpressionPrimaryContext(ExpressionContext *ctx);

    PrimaryContext *primary();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionArithmeticalContext : public ExpressionContext {
  public:
    ExpressionArithmeticalContext(ExpressionContext *ctx);

    JavaParser::ExpressionContext *e1 = nullptr;
    antlr4::Token *bop = nullptr;
    JavaParser::ExpressionContext *e2 = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionSwitchContext : public ExpressionContext {
  public:
    ExpressionSwitchContext(ExpressionContext *ctx);

    SwitchExpressionContext *switchExpression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionConditionalContext : public ExpressionContext {
  public:
    ExpressionConditionalContext(ExpressionContext *ctx);

    JavaParser::ExpressionContext *e1 = nullptr;
    antlr4::Token *bop = nullptr;
    JavaParser::ExpressionContext *e2 = nullptr;
    JavaParser::ExpressionContext *e3 = nullptr;
    antlr4::tree::TerminalNode *COLON();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *QUESTION();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionCastContext : public ExpressionContext {
  public:
    ExpressionCastContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    std::vector<TypeTypeContext *> typeType();
    TypeTypeContext* typeType(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BITAND();
    antlr4::tree::TerminalNode* BITAND(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionShiftContext : public ExpressionContext {
  public:
    ExpressionShiftContext(ExpressionContext *ctx);

    JavaParser::ExpressionContext *e1 = nullptr;
    antlr4::Token *bop1 = nullptr;
    antlr4::Token *bop2 = nullptr;
    antlr4::Token *bop3 = nullptr;
    JavaParser::ExpressionContext *e2 = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LT();
    antlr4::tree::TerminalNode* LT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GT();
    antlr4::tree::TerminalNode* GT(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionRelationalContext : public ExpressionContext {
  public:
    ExpressionRelationalContext(ExpressionContext *ctx);

    JavaParser::ExpressionContext *e1 = nullptr;
    antlr4::Token *bop = nullptr;
    JavaParser::ExpressionContext *e2 = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NOTEQUAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionArrayAccessContext : public ExpressionContext {
  public:
    ExpressionArrayAccessContext(ExpressionContext *ctx);

    JavaParser::ExpressionContext *e1 = nullptr;
    JavaParser::ExpressionContext *e2 = nullptr;
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionIncDecContext : public ExpressionContext {
  public:
    ExpressionIncDecContext(ExpressionContext *ctx);

    antlr4::Token *prefix = nullptr;
    antlr4::Token *postfix = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *INC();
    antlr4::tree::TerminalNode *DEC();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionMethodCallContext : public ExpressionContext {
  public:
    ExpressionMethodCallContext(ExpressionContext *ctx);

    MethodCallContext *methodCall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionLogicalContext : public ExpressionContext {
  public:
    ExpressionLogicalContext(ExpressionContext *ctx);

    JavaParser::ExpressionContext *e1 = nullptr;
    antlr4::Token *bop = nullptr;
    JavaParser::ExpressionContext *e2 = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *BITAND();
    antlr4::tree::TerminalNode *CARET();
    antlr4::tree::TerminalNode *BITOR();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  PatternContext : public antlr4::ParserRuleContext {
  public:
    PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeTypeContext *typeType();
    IdentifierContext *identifier();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternContext* pattern();

  class  LambdaExpressionContext : public antlr4::ParserRuleContext {
  public:
    LambdaExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LambdaParametersContext *lambdaParameters();
    antlr4::tree::TerminalNode *ARROW();
    LambdaBodyContext *lambdaBody();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaExpressionContext* lambdaExpression();

  class  LambdaParametersContext : public antlr4::ParserRuleContext {
  public:
    LambdaParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    FormalParameterListContext *formalParameterList();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    LambdaLVTIListContext *lambdaLVTIList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaParametersContext* lambdaParameters();

  class  LambdaBodyContext : public antlr4::ParserRuleContext {
  public:
    LambdaBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaBodyContext* lambdaBody();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryContext() = default;
    void copyFrom(PrimaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrimarySuperContext : public PrimaryContext {
  public:
    PrimarySuperContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *SUPER();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimaryExpContext : public PrimaryContext {
  public:
    PrimaryExpContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimaryThisContext : public PrimaryContext {
  public:
    PrimaryThisContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *THIS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimaryMethodCallWithExplicitTypeArgumentContext : public PrimaryContext {
  public:
    PrimaryMethodCallWithExplicitTypeArgumentContext(PrimaryContext *ctx);

    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();
    ExplicitGenericInvocationSuffixContext *explicitGenericInvocationSuffix();
    antlr4::tree::TerminalNode *THIS();
    ArgumentsContext *arguments();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimaryIdentifierContext : public PrimaryContext {
  public:
    PrimaryIdentifierContext(PrimaryContext *ctx);

    IdentifierContext *identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimaryClassContext : public PrimaryContext {
  public:
    PrimaryClassContext(PrimaryContext *ctx);

    TypeTypeOrVoidContext *typeTypeOrVoid();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *CLASS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimaryLiteralContext : public PrimaryContext {
  public:
    PrimaryLiteralContext(PrimaryContext *ctx);

    LiteralContext *literal();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrimaryContext* primary();

  class  SwitchExpressionContext : public antlr4::ParserRuleContext {
  public:
    SwitchExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWITCH();
    ParExpressionContext *parExpression();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<SwitchLabeledRuleContext *> switchLabeledRule();
    SwitchLabeledRuleContext* switchLabeledRule(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchExpressionContext* switchExpression();

  class  SwitchLabeledRuleContext : public antlr4::ParserRuleContext {
  public:
    SwitchLabeledRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    SwitchRuleOutcomeContext *switchRuleOutcome();
    antlr4::tree::TerminalNode *ARROW();
    antlr4::tree::TerminalNode *COLON();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *NULL_LITERAL();
    GuardedPatternContext *guardedPattern();
    antlr4::tree::TerminalNode *DEFAULT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchLabeledRuleContext* switchLabeledRule();

  class  GuardedPatternContext : public antlr4::ParserRuleContext {
  public:
    GuardedPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    GuardedPatternContext *guardedPattern();
    antlr4::tree::TerminalNode *RPAREN();
    TypeTypeContext *typeType();
    IdentifierContext *identifier();
    std::vector<VariableModifierContext *> variableModifier();
    VariableModifierContext* variableModifier(size_t i);
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GuardedPatternContext* guardedPattern();
  GuardedPatternContext* guardedPattern(int precedence);
  class  SwitchRuleOutcomeContext : public antlr4::ParserRuleContext {
  public:
    SwitchRuleOutcomeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    std::vector<BlockStatementContext *> blockStatement();
    BlockStatementContext* blockStatement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchRuleOutcomeContext* switchRuleOutcome();

  class  ClassTypeContext : public antlr4::ParserRuleContext {
  public:
    ClassTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    ClassOrInterfaceTypeContext *classOrInterfaceType();
    antlr4::tree::TerminalNode *DOT();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    TypeArgumentsContext *typeArguments();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassTypeContext* classType();

  class  CreatorContext : public antlr4::ParserRuleContext {
  public:
    CreatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CreatedNameContext *createdName();
    ArrayCreatorRestContext *arrayCreatorRest();
    ClassCreatorRestContext *classCreatorRest();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CreatorContext* creator();

  class  CreatedNameContext : public antlr4::ParserRuleContext {
  public:
    CreatedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<TypeArgumentsOrDiamondContext *> typeArgumentsOrDiamond();
    TypeArgumentsOrDiamondContext* typeArgumentsOrDiamond(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    PrimitiveTypeContext *primitiveType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CreatedNameContext* createdName();

  class  InnerCreatorContext : public antlr4::ParserRuleContext {
  public:
    InnerCreatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    ClassCreatorRestContext *classCreatorRest();
    NonWildcardTypeArgumentsOrDiamondContext *nonWildcardTypeArgumentsOrDiamond();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InnerCreatorContext* innerCreator();

  class  ArrayCreatorRestContext : public antlr4::ParserRuleContext {
  public:
    ArrayCreatorRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LBRACK();
    antlr4::tree::TerminalNode* LBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);
    ArrayInitializerContext *arrayInitializer();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayCreatorRestContext* arrayCreatorRest();

  class  ClassCreatorRestContext : public antlr4::ParserRuleContext {
  public:
    ClassCreatorRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();
    ClassBodyContext *classBody();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassCreatorRestContext* classCreatorRest();

  class  ExplicitGenericInvocationContext : public antlr4::ParserRuleContext {
  public:
    ExplicitGenericInvocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();
    ExplicitGenericInvocationSuffixContext *explicitGenericInvocationSuffix();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExplicitGenericInvocationContext* explicitGenericInvocation();

  class  TypeArgumentsOrDiamondContext : public antlr4::ParserRuleContext {
  public:
    TypeArgumentsOrDiamondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    TypeArgumentsContext *typeArguments();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeArgumentsOrDiamondContext* typeArgumentsOrDiamond();

  class  NonWildcardTypeArgumentsOrDiamondContext : public antlr4::ParserRuleContext {
  public:
    NonWildcardTypeArgumentsOrDiamondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    NonWildcardTypeArgumentsContext *nonWildcardTypeArguments();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonWildcardTypeArgumentsOrDiamondContext* nonWildcardTypeArgumentsOrDiamond();

  class  NonWildcardTypeArgumentsContext : public antlr4::ParserRuleContext {
  public:
    NonWildcardTypeArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    TypeListContext *typeList();
    antlr4::tree::TerminalNode *GT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonWildcardTypeArgumentsContext* nonWildcardTypeArguments();

  class  TypeListContext : public antlr4::ParserRuleContext {
  public:
    TypeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeTypeContext *> typeType();
    TypeTypeContext* typeType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeListContext* typeList();

  class  TypeTypeContext : public antlr4::ParserRuleContext {
  public:
    TypeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassOrInterfaceTypeContext *classOrInterfaceType();
    PrimitiveTypeContext *primitiveType();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LBRACK();
    antlr4::tree::TerminalNode* LBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeTypeContext* typeType();

  class  PrimitiveTypeContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *BYTE();
    antlr4::tree::TerminalNode *SHORT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *LONG();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *DOUBLE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveTypeContext* primitiveType();

  class  TypeArgumentsContext : public antlr4::ParserRuleContext {
  public:
    TypeArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    std::vector<TypeArgumentContext *> typeArgument();
    TypeArgumentContext* typeArgument(size_t i);
    antlr4::tree::TerminalNode *GT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeArgumentsContext* typeArguments();

  class  SuperSuffixContext : public antlr4::ParserRuleContext {
  public:
    SuperSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *DOT();
    IdentifierContext *identifier();
    TypeArgumentsContext *typeArguments();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SuperSuffixContext* superSuffix();

  class  ExplicitGenericInvocationSuffixContext : public antlr4::ParserRuleContext {
  public:
    ExplicitGenericInvocationSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUPER();
    SuperSuffixContext *superSuffix();
    IdentifierContext *identifier();
    ArgumentsContext *arguments();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExplicitGenericInvocationSuffixContext* explicitGenericInvocationSuffix();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionListContext *expressionList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool guardedPatternSempred(GuardedPatternContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

