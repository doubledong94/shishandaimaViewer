
// Generated from AIDLParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  AIDLParser : public antlr4::Parser {
public:
  enum {
    ABSTRACT = 1, CONST = 2, ENUM = 3, EXTENDS = 4, IMPLEMENTS = 5, IMPORT = 6, 
    INTERFACE = 7, PACKAGE = 8, PRIVATE = 9, PROTECTED = 10, PUBLIC = 11, 
    RETURN = 12, STATIC = 13, VOID = 14, PARCELABLE = 15, IN = 16, OUT = 17, 
    INOUT = 18, ONEWAY = 19, CPP_HEADER = 20, NDK_HEADER = 21, RUST_TYPE = 22, 
    ANNOTATION = 23, UNION = 24, VAR = 25, YIELD = 26, RECORD = 27, SEALED = 28, 
    PERMITS = 29, NON_SEALED = 30, INTVALUE = 31, HEXVALUE = 32, OCT_LITERAL = 33, 
    BINARY_LITERAL = 34, FLOATVALUE = 35, HEX_FLOAT_LITERAL = 36, TRUE_LITERAL = 37, 
    FALSE_LITERAL = 38, CHARVALUE = 39, C_STR = 40, TEXT_BLOCK = 41, NULL_LITERAL = 42, 
    LPAREN = 43, RPAREN = 44, LBRACE = 45, RBRACE = 46, LBRACK = 47, RBRACK = 48, 
    SEMI = 49, COMMA = 50, DOT = 51, ASSIGN = 52, GT = 53, LT = 54, BANG = 55, 
    TILDE = 56, QUESTION = 57, COLON = 58, EQUALITY = 59, LEQ = 60, GEQ = 61, 
    NEQ = 62, LOGICAL_AND = 63, LOGICAL_OR = 64, UNARY_PLUS = 65, UNARY_MINUS = 66, 
    ADD = 67, SUB = 68, MUL = 69, DIV = 70, BITAND = 71, BITOR = 72, CARET = 73, 
    MOD = 74, LSHIFT = 75, RSHIFT = 76, ADD_ASSIGN = 77, SUB_ASSIGN = 78, 
    MUL_ASSIGN = 79, DIV_ASSIGN = 80, AND_ASSIGN = 81, OR_ASSIGN = 82, XOR_ASSIGN = 83, 
    MOD_ASSIGN = 84, LSHIFT_ASSIGN = 85, RSHIFT_ASSIGN = 86, URSHIFT_ASSIGN = 87, 
    ARROW = 88, COLONCOLON = 89, ELLIPSIS = 90, WS = 91, COMMENT = 92, LINE_COMMENT = 93, 
    IDENTIFIER = 94
  };

  enum {
    RuleCompilationUnit = 0, RuleIdentifier = 1, RuleOptional_package = 2, 
    RuleImports = 3, RuleImportI = 4, RuleQualified_name = 5, RuleDecls = 6, 
    RuleDecl = 7, RuleUnannotated_decl = 8, RuleType_params = 9, RuleOptional_type_params = 10, 
    RuleOptional_unstructured_headers = 11, RuleParcelable_decl = 12, RuleParcelable_members = 13, 
    RuleVariable_decl = 14, RuleInterface_decl = 15, RuleInterface_members = 16, 
    RuleConst_expr = 17, RuleConstant_value_list = 18, RuleConstant_value_non_empty_list = 19, 
    RuleConstant_decl = 20, RuleEnumerator = 21, RuleEnumerators = 22, RuleEnum_decl_body = 23, 
    RuleEnum_decl = 24, RuleUnion_decl = 25, RuleMethod_decl = 26, RuleArg_non_empty_list = 27, 
    RuleArg = 28, RuleNon_array_type = 29, RuleType = 30, RuleType_args = 31, 
    RuleAnnotation_list = 32, RuleParameter = 33, RuleParameter_non_empty_list = 34, 
    RuleAnnotation = 35, RuleDirection = 36
  };

  explicit AIDLParser(antlr4::TokenStream *input);

  AIDLParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~AIDLParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class CompilationUnitContext;
  class IdentifierContext;
  class Optional_packageContext;
  class ImportsContext;
  class ImportIContext;
  class Qualified_nameContext;
  class DeclsContext;
  class DeclContext;
  class Unannotated_declContext;
  class Type_paramsContext;
  class Optional_type_paramsContext;
  class Optional_unstructured_headersContext;
  class Parcelable_declContext;
  class Parcelable_membersContext;
  class Variable_declContext;
  class Interface_declContext;
  class Interface_membersContext;
  class Const_exprContext;
  class Constant_value_listContext;
  class Constant_value_non_empty_listContext;
  class Constant_declContext;
  class EnumeratorContext;
  class EnumeratorsContext;
  class Enum_decl_bodyContext;
  class Enum_declContext;
  class Union_declContext;
  class Method_declContext;
  class Arg_non_empty_listContext;
  class ArgContext;
  class Non_array_typeContext;
  class TypeContext;
  class Type_argsContext;
  class Annotation_listContext;
  class ParameterContext;
  class Parameter_non_empty_listContext;
  class AnnotationContext;
  class DirectionContext; 

  class  CompilationUnitContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclsContext *decls();
    Optional_packageContext *optional_package();
    ImportsContext *imports();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompilationUnitContext* compilationUnit();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *CPP_HEADER();
    antlr4::tree::TerminalNode *NDK_HEADER();
    antlr4::tree::TerminalNode *RUST_TYPE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  Optional_packageContext : public antlr4::ParserRuleContext {
  public:
    Optional_packageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    Qualified_nameContext *qualified_name();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Optional_packageContext* optional_package();

  class  ImportsContext : public antlr4::ParserRuleContext {
  public:
    ImportsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ImportIContext *> importI();
    ImportIContext* importI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportsContext* imports();

  class  ImportIContext : public antlr4::ParserRuleContext {
  public:
    ImportIContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    Qualified_nameContext *qualified_name();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportIContext* importI();

  class  Qualified_nameContext : public antlr4::ParserRuleContext {
  public:
    Qualified_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Qualified_nameContext* qualified_name();

  class  DeclsContext : public antlr4::ParserRuleContext {
  public:
    DeclsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclsContext* decls();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Annotation_listContext *annotation_list();
    Unannotated_declContext *unannotated_decl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclContext* decl();

  class  Unannotated_declContext : public antlr4::ParserRuleContext {
  public:
    Unannotated_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parcelable_declContext *parcelable_decl();
    Interface_declContext *interface_decl();
    Enum_declContext *enum_decl();
    Union_declContext *union_decl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unannotated_declContext* unannotated_decl();

  class  Type_paramsContext : public antlr4::ParserRuleContext {
  public:
    Type_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_paramsContext* type_params();

  class  Optional_type_paramsContext : public antlr4::ParserRuleContext {
  public:
    Optional_type_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    Type_paramsContext *type_params();
    antlr4::tree::TerminalNode *GT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Optional_type_paramsContext* optional_type_params();

  class  Optional_unstructured_headersContext : public antlr4::ParserRuleContext {
  public:
    Optional_unstructured_headersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CPP_HEADER();
    antlr4::tree::TerminalNode* CPP_HEADER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> C_STR();
    antlr4::tree::TerminalNode* C_STR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NDK_HEADER();
    antlr4::tree::TerminalNode* NDK_HEADER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RUST_TYPE();
    antlr4::tree::TerminalNode* RUST_TYPE(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Optional_unstructured_headersContext* optional_unstructured_headers();

  class  Parcelable_declContext : public antlr4::ParserRuleContext {
  public:
    Parcelable_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARCELABLE();
    Qualified_nameContext *qualified_name();
    Optional_type_paramsContext *optional_type_params();
    Optional_unstructured_headersContext *optional_unstructured_headers();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *LBRACE();
    Parcelable_membersContext *parcelable_members();
    antlr4::tree::TerminalNode *RBRACE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parcelable_declContext* parcelable_decl();

  class  Parcelable_membersContext : public antlr4::ParserRuleContext {
  public:
    Parcelable_membersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_declContext *> variable_decl();
    Variable_declContext* variable_decl(size_t i);
    std::vector<Constant_declContext *> constant_decl();
    Constant_declContext* constant_decl(size_t i);
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parcelable_membersContext* parcelable_members();

  class  Variable_declContext : public antlr4::ParserRuleContext {
  public:
    Variable_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *ASSIGN();
    Const_exprContext *const_expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_declContext* variable_decl();

  class  Interface_declContext : public antlr4::ParserRuleContext {
  public:
    Interface_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERFACE();
    Qualified_nameContext *qualified_name();
    antlr4::tree::TerminalNode *ONEWAY();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *LBRACE();
    Interface_membersContext *interface_members();
    antlr4::tree::TerminalNode *RBRACE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_declContext* interface_decl();

  class  Interface_membersContext : public antlr4::ParserRuleContext {
  public:
    Interface_membersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Method_declContext *> method_decl();
    Method_declContext* method_decl(size_t i);
    std::vector<Constant_declContext *> constant_decl();
    Constant_declContext* constant_decl(size_t i);
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_membersContext* interface_members();

  class  Const_exprContext : public antlr4::ParserRuleContext {
  public:
    Const_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE_LITERAL();
    antlr4::tree::TerminalNode *FALSE_LITERAL();
    antlr4::tree::TerminalNode *CHARVALUE();
    antlr4::tree::TerminalNode *INTVALUE();
    antlr4::tree::TerminalNode *FLOATVALUE();
    antlr4::tree::TerminalNode *HEXVALUE();
    antlr4::tree::TerminalNode *C_STR();
    Qualified_nameContext *qualified_name();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    Constant_value_listContext *constant_value_list();
    antlr4::tree::TerminalNode *ADD();
    std::vector<Const_exprContext *> const_expr();
    Const_exprContext* const_expr(size_t i);
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *BANG();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *LOGICAL_OR();
    antlr4::tree::TerminalNode *LOGICAL_AND();
    antlr4::tree::TerminalNode *BITOR();
    antlr4::tree::TerminalNode *CARET();
    antlr4::tree::TerminalNode *BITAND();
    antlr4::tree::TerminalNode *EQUALITY();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *GEQ();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_exprContext* const_expr();
  Const_exprContext* const_expr(int precedence);
  class  Constant_value_listContext : public antlr4::ParserRuleContext {
  public:
    Constant_value_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_value_non_empty_listContext *constant_value_non_empty_list();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_value_listContext* constant_value_list();

  class  Constant_value_non_empty_listContext : public antlr4::ParserRuleContext {
  public:
    Constant_value_non_empty_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Const_exprContext *> const_expr();
    Const_exprContext* const_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_value_non_empty_listContext* constant_value_non_empty_list();

  class  Constant_declContext : public antlr4::ParserRuleContext {
  public:
    Constant_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Annotation_listContext *annotation_list();
    antlr4::tree::TerminalNode *CONST();
    TypeContext *type();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    Const_exprContext *const_expr();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_declContext* constant_decl();

  class  EnumeratorContext : public antlr4::ParserRuleContext {
  public:
    EnumeratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    Const_exprContext *const_expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumeratorContext* enumerator();

  class  EnumeratorsContext : public antlr4::ParserRuleContext {
  public:
    EnumeratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EnumeratorContext *> enumerator();
    EnumeratorContext* enumerator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumeratorsContext* enumerators();

  class  Enum_decl_bodyContext : public antlr4::ParserRuleContext {
  public:
    Enum_decl_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    EnumeratorsContext *enumerators();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_decl_bodyContext* enum_decl_body();

  class  Enum_declContext : public antlr4::ParserRuleContext {
  public:
    Enum_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENUM();
    Qualified_nameContext *qualified_name();
    Enum_decl_bodyContext *enum_decl_body();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_declContext* enum_decl();

  class  Union_declContext : public antlr4::ParserRuleContext {
  public:
    Union_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNION();
    Qualified_nameContext *qualified_name();
    antlr4::tree::TerminalNode *LBRACE();
    Parcelable_membersContext *parcelable_members();
    antlr4::tree::TerminalNode *RBRACE();
    Optional_type_paramsContext *optional_type_params();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Union_declContext* union_decl();

  class  Method_declContext : public antlr4::ParserRuleContext {
  public:
    Method_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Annotation_listContext *annotation_list();
    TypeContext *type();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *ONEWAY();
    Arg_non_empty_listContext *arg_non_empty_list();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *INTVALUE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_declContext* method_decl();

  class  Arg_non_empty_listContext : public antlr4::ParserRuleContext {
  public:
    Arg_non_empty_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgContext *> arg();
    ArgContext* arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arg_non_empty_listContext* arg_non_empty_list();

  class  ArgContext : public antlr4::ParserRuleContext {
  public:
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    IdentifierContext *identifier();
    DirectionContext *direction();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgContext* arg();

  class  Non_array_typeContext : public antlr4::ParserRuleContext {
  public:
    Non_array_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Annotation_listContext *annotation_list();
    Qualified_nameContext *qualified_name();
    std::vector<antlr4::tree::TerminalNode *> LT();
    antlr4::tree::TerminalNode* LT(size_t i);
    std::vector<Type_argsContext *> type_args();
    Type_argsContext* type_args(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GT();
    antlr4::tree::TerminalNode* GT(size_t i);
    std::vector<Non_array_typeContext *> non_array_type();
    Non_array_typeContext* non_array_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RSHIFT();
    antlr4::tree::TerminalNode* RSHIFT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Non_array_typeContext* non_array_type();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Non_array_typeContext *non_array_type();
    std::vector<Annotation_listContext *> annotation_list();
    Annotation_listContext* annotation_list(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LBRACK();
    antlr4::tree::TerminalNode* LBRACK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RBRACK();
    antlr4::tree::TerminalNode* RBRACK(size_t i);
    std::vector<Const_exprContext *> const_expr();
    Const_exprContext* const_expr(size_t i);
    antlr4::tree::TerminalNode *VOID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  Type_argsContext : public antlr4::ParserRuleContext {
  public:
    Type_argsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_argsContext* type_args();

  class  Annotation_listContext : public antlr4::ParserRuleContext {
  public:
    Annotation_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Annotation_listContext* annotation_list();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    Const_exprContext *const_expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  Parameter_non_empty_listContext : public antlr4::ParserRuleContext {
  public:
    Parameter_non_empty_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_non_empty_listContext* parameter_non_empty_list();

  class  AnnotationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANNOTATION();
    antlr4::tree::TerminalNode *LPAREN();
    Const_exprContext *const_expr();
    antlr4::tree::TerminalNode *RPAREN();
    Parameter_non_empty_listContext *parameter_non_empty_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationContext* annotation();

  class  DirectionContext : public antlr4::ParserRuleContext {
  public:
    DirectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *OUT();
    antlr4::tree::TerminalNode *INOUT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectionContext* direction();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool const_exprSempred(Const_exprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

