
// Generated from SimpleView.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SimpleViewParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    LABEL_DETAIL_LEVEL_SIMPLE = 21, LABEL_DETAIL_LEVEL_FULL = 22, NODE_COLOR = 23, 
    NODE_SCALE = 24, LABEL_COLOR = 25, LABEL_SCALE = 26, LABEL_DETAIL_LEVEL = 27, 
    POSITION_Z = 28, BASIC_NODE_SIZE = 29, BASIC_LABEL_SIZE = 30, BASIC_POSITION_Z = 31, 
    ANY = 32, FINAL = 33, CLASS = 34, FIELD_OF = 35, INSTANCE_OF = 36, METHOD_OF = 37, 
    CREATOR = 38, PARAMETER_OF = 39, RETURN_OF = 40, CALLED_PARAM_OF = 41, 
    CALLED_RETURN_OF = 42, CALLED_METHOD_OF = 43, READ = 44, WRITE = 45, 
    IN_PACKAGE = 46, USED_BY = 47, USE = 48, CLASS_OF = 49, SUPER = 50, 
    SUB = 51, STYLE = 52, DEFAULT_STYLE = 53, BASIC_STYLE = 54, CLASS_SCOPE = 55, 
    NODE = 56, REFERENCE = 57, CONDITION = 58, ELSE = 59, DATA_STEP = 60, 
    TIMING_STEP = 61, DATA_OVERRIDE = 62, TIMING_OVERRIDE = 63, FIELD = 64, 
    METHOD = 65, CONSTRUCTOR = 66, CALLED_METHOD = 67, PARAMETER = 68, CALLED_PARAMETER = 69, 
    RETURN = 70, CALLED_RETURN = 71, INDEX = 72, SEGMENT = 73, LINE = 74, 
    LINE_INSTANCE = 75, GLUE = 76, GLUE_RUNTIME = 77, GLULE_MEMBER_OF = 78, 
    GLUE_INSTANCE_OF = 79, GLUE_OVERRIDE = 80, GLUE_HIERARCHY = 81, GRAPH = 82, 
    GRAPH_INSTANCE = 83, CODE_ORDER = 84, SHOW = 85, STRING = 86, IDENTIFIER = 87, 
    FLOAT = 88, INT = 89, WS = 90, LINE_COMMENT = 91
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
    SimpleViewParser::NodeExpContext *node = nullptr;
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
    antlr4::tree::TerminalNode *SUPER();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *CALLED_METHOD_OF();
    antlr4::tree::TerminalNode *CALLED_PARAM_OF();
    antlr4::tree::TerminalNode *CALLED_RETURN_OF();
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *WRITE();
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *FINAL();
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *REFERENCE();
    antlr4::tree::TerminalNode *CONDITION();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *DATA_STEP();
    antlr4::tree::TerminalNode *TIMING_STEP();
    antlr4::tree::TerminalNode *DATA_OVERRIDE();
    antlr4::tree::TerminalNode *TIMING_OVERRIDE();
    antlr4::tree::TerminalNode *FIELD();
    antlr4::tree::TerminalNode *METHOD();
    antlr4::tree::TerminalNode *CONSTRUCTOR();
    antlr4::tree::TerminalNode *CALLED_METHOD();
    antlr4::tree::TerminalNode *PARAMETER();
    antlr4::tree::TerminalNode *CALLED_PARAMETER();
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *CALLED_RETURN();
    antlr4::tree::TerminalNode *INDEX();
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
    antlr4::Token *seq = nullptr;
    antlr4::Token *alt = nullptr;
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

