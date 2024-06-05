
// Generated from SimpleView.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SimpleViewParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, LABEL_DETAIL_LEVEL_SIMPLE = 20, 
    LABEL_DETAIL_LEVEL_FULL = 21, NODE_COLOR = 22, NODE_SCALE = 23, LABEL_COLOR = 24, 
    LABEL_SCALE = 25, LABEL_DETAIL_LEVEL = 26, POSITION_Z = 27, BASIC_NODE_SIZE = 28, 
    BASIC_LABEL_SIZE = 29, BASIC_POSITION_Z = 30, ANY = 31, FIELD_OF = 32, 
    INSTANCE_OF = 33, METHOD_OF = 34, CREATOR = 35, PARAMETER_OF = 36, RETURN_OF = 37, 
    CALLED_PARAM_OF = 38, CALLED_RETURN_OF = 39, CALLED_METHOD_OF = 40, 
    READ = 41, WRITE = 42, IN_PACKAGE = 43, USED_BY = 44, USE = 45, CLASS_OF = 46, 
    SUPER = 47, SUB = 48, STYLE = 49, DEFAULT_STYLE = 50, BASIC_STYLE = 51, 
    CLASS_SCOPE = 52, NODE = 53, REFERENCE = 54, CONDITION = 55, ELSE = 56, 
    DATA_STEP = 57, TIMING_STEP = 58, FIELD = 59, METHOD = 60, CONSTRUCTOR = 61, 
    CALLED_METHOD = 62, PARAMETER = 63, CALLED_PARAMETER = 64, RETURN = 65, 
    CALLED_RETURN = 66, SEGMENT = 67, LINE = 68, LINE_INSTANCE = 69, GLUE = 70, 
    GLUE_RUNTIME = 71, GLULE_MEMBER_OF = 72, GLUE_INSTANCE_OF = 73, GLUE_OVERRIDE = 74, 
    GLUE_HIERARCHY = 75, GRAPH = 76, GRAPH_INSTANCE = 77, CODE_ORDER = 78, 
    SHOW = 79, STRING = 80, IDENTIFIER = 81, FLOAT = 82, INT = 83, WS = 84, 
    LINE_COMMENT = 85
  };

  enum {
    RuleCompilationUnit = 0, RuleGlueAttr = 1, RuleClassScopeExp = 2, RuleNodeExp = 3, 
    RuleParamList = 4, RuleLineExp = 5, RuleLineSegOrNodeExp = 6, RuleLineArgumentList = 7, 
    RuleGraphElement = 8, RuleGraphBody = 9, RulePointInLine = 10, RuleIntersectionPoint = 11, 
    RuleDeclaration = 12, RuleShowCommand = 13
  };

  explicit SimpleViewParser(antlr4::TokenStream *input);

  SimpleViewParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~SimpleViewParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class CompilationUnitContext;
  class GlueAttrContext;
  class ClassScopeExpContext;
  class NodeExpContext;
  class ParamListContext;
  class LineExpContext;
  class LineSegOrNodeExpContext;
  class LineArgumentListContext;
  class GraphElementContext;
  class GraphBodyContext;
  class PointInLineContext;
  class IntersectionPointContext;
  class DeclarationContext;
  class ShowCommandContext; 

  class  CompilationUnitContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);
    std::vector<ShowCommandContext *> showCommand();
    ShowCommandContext* showCommand(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompilationUnitContext* compilationUnit();

  class  GlueAttrContext : public antlr4::ParserRuleContext {
  public:
    GlueAttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GLUE_RUNTIME();
    NodeExpContext *nodeExp();
    antlr4::tree::TerminalNode *GLULE_MEMBER_OF();
    ClassScopeExpContext *classScopeExp();
    antlr4::tree::TerminalNode *GLUE_INSTANCE_OF();
    antlr4::tree::TerminalNode *GLUE_OVERRIDE();
    antlr4::tree::TerminalNode *GLUE_HIERARCHY();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlueAttrContext* glueAttr();

  class  ClassScopeExpContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *classKey = nullptr;
    antlr4::Token *classKeyList = nullptr;
    antlr4::Token *packageStr = nullptr;
    SimpleViewParser::ClassScopeExpContext *bracket = nullptr;
    antlr4::Token *refOtherScope = nullptr;
    antlr4::Token *varClass = nullptr;
    antlr4::Token *union_ = nullptr;
    antlr4::Token *intersection = nullptr;
    antlr4::Token *difference = nullptr;
    ClassScopeExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> STRING();
    antlr4::tree::TerminalNode* STRING(size_t i);
    antlr4::tree::TerminalNode *IN_PACKAGE();
    antlr4::tree::TerminalNode *USED_BY();
    std::vector<ClassScopeExpContext *> classScopeExp();
    ClassScopeExpContext* classScopeExp(size_t i);
    antlr4::tree::TerminalNode *USE();
    antlr4::tree::TerminalNode *SUPER();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassScopeExpContext* classScopeExp();
  ClassScopeExpContext* classScopeExp(int precedence);
  class  NodeExpContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *nodeKey = nullptr;
    antlr4::Token *typeKey = nullptr;
    antlr4::Token *nodeKeyList = nullptr;
    SimpleViewParser::NodeExpContext *methodNode = nullptr;
    SimpleViewParser::NodeExpContext *paramNode = nullptr;
    SimpleViewParser::NodeExpContext *returnNode = nullptr;
    SimpleViewParser::NodeExpContext *read = nullptr;
    SimpleViewParser::NodeExpContext *write = nullptr;
    SimpleViewParser::NodeExpContext *bracket = nullptr;
    antlr4::Token *refOtherNode = nullptr;
    antlr4::Token *varNode = nullptr;
    antlr4::Token *intersection = nullptr;
    antlr4::Token *union_ = nullptr;
    antlr4::Token *difference = nullptr;
    NodeExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> STRING();
    antlr4::tree::TerminalNode* STRING(size_t i);
    antlr4::tree::TerminalNode *FIELD_OF();
    std::vector<ClassScopeExpContext *> classScopeExp();
    ClassScopeExpContext* classScopeExp(size_t i);
    antlr4::tree::TerminalNode *METHOD_OF();
    antlr4::tree::TerminalNode *PARAMETER_OF();
    std::vector<NodeExpContext *> nodeExp();
    NodeExpContext* nodeExp(size_t i);
    antlr4::tree::TerminalNode *RETURN_OF();
    antlr4::tree::TerminalNode *INSTANCE_OF();
    antlr4::tree::TerminalNode *CREATOR();
    antlr4::tree::TerminalNode *CALLED_METHOD_OF();
    antlr4::tree::TerminalNode *CALLED_PARAM_OF();
    antlr4::tree::TerminalNode *CALLED_RETURN_OF();
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *WRITE();
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *REFERENCE();
    antlr4::tree::TerminalNode *CONDITION();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *DATA_STEP();
    antlr4::tree::TerminalNode *TIMING_STEP();
    antlr4::tree::TerminalNode *FIELD();
    antlr4::tree::TerminalNode *METHOD();
    antlr4::tree::TerminalNode *CONSTRUCTOR();
    antlr4::tree::TerminalNode *CALLED_METHOD();
    antlr4::tree::TerminalNode *PARAMETER();
    antlr4::tree::TerminalNode *CALLED_PARAMETER();
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *CALLED_RETURN();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeExpContext* nodeExp();
  NodeExpContext* nodeExp(int precedence);
  class  ParamListContext : public antlr4::ParserRuleContext {
  public:
    ParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamListContext* paramList();

  class  LineExpContext : public antlr4::ParserRuleContext {
  public:
    LineExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LineSegOrNodeExpContext *> lineSegOrNodeExp();
    LineSegOrNodeExpContext* lineSegOrNodeExp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineExpContext* lineExp();

  class  LineSegOrNodeExpContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *segName = nullptr;
    antlr4::Token *wildcard = nullptr;
    LineSegOrNodeExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NodeExpContext *nodeExp();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineSegOrNodeExpContext* lineSegOrNodeExp();

  class  LineArgumentListContext : public antlr4::ParserRuleContext {
  public:
    LineArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineArgumentListContext* lineArgumentList();

  class  GraphElementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *lineName = nullptr;
    GraphElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    LineArgumentListContext *lineArgumentList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphElementContext* graphElement();

  class  GraphBodyContext : public antlr4::ParserRuleContext {
  public:
    GraphBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<GraphElementContext *> graphElement();
    GraphElementContext* graphElement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphBodyContext* graphBody();

  class  PointInLineContext : public antlr4::ParserRuleContext {
  public:
    PointInLineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PointInLineContext *> pointInLine();
    PointInLineContext* pointInLine(size_t i);
    antlr4::tree::TerminalNode *INT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PointInLineContext* pointInLine();

  class  IntersectionPointContext : public antlr4::ParserRuleContext {
  public:
    IntersectionPointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PointInLineContext *> pointInLine();
    PointInLineContext* pointInLine(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntersectionPointContext* intersectionPoint();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeclarationContext() = default;
    void copyFrom(DeclarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  GraphDeclarationContext : public DeclarationContext {
  public:
    GraphDeclarationContext(DeclarationContext *ctx);

    antlr4::Token *graphName = nullptr;
    antlr4::tree::TerminalNode *GRAPH();
    GraphBodyContext *graphBody();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ParamListContext *paramList();
    std::vector<IntersectionPointContext *> intersectionPoint();
    IntersectionPointContext* intersectionPoint(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ClassScopeDeclarationContext : public DeclarationContext {
  public:
    ClassScopeDeclarationContext(DeclarationContext *ctx);

    antlr4::tree::TerminalNode *CLASS_SCOPE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ClassScopeExpContext *classScopeExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GlueDeclarationContext : public DeclarationContext {
  public:
    GlueDeclarationContext(DeclarationContext *ctx);

    antlr4::tree::TerminalNode *GLUE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<GlueAttrContext *> glueAttr();
    GlueAttrContext* glueAttr(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LineAndGraphInstanceContext : public DeclarationContext {
  public:
    LineAndGraphInstanceContext(DeclarationContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    LineArgumentListContext *lineArgumentList();
    antlr4::tree::TerminalNode *LINE_INSTANCE();
    antlr4::tree::TerminalNode *GRAPH_INSTANCE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LineDeclarationContext : public DeclarationContext {
  public:
    LineDeclarationContext(DeclarationContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    LineExpContext *lineExp();
    antlr4::tree::TerminalNode *LINE();
    antlr4::tree::TerminalNode *CODE_ORDER();
    antlr4::tree::TerminalNode *SEGMENT();
    ParamListContext *paramList();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NodeDeclarationContext : public DeclarationContext {
  public:
    NodeDeclarationContext(DeclarationContext *ctx);

    antlr4::tree::TerminalNode *NODE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    NodeExpContext *nodeExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclarationContext* declaration();

  class  ShowCommandContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *graphName = nullptr;
    antlr4::Token *defaultStyleName = nullptr;
    antlr4::Token *basicStyleName = nullptr;
    ShowCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHOW();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShowCommandContext* showCommand();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool classScopeExpSempred(ClassScopeExpContext *_localctx, size_t predicateIndex);
  bool nodeExpSempred(NodeExpContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

