
// Generated from SimpleView.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SimpleViewLexer : public antlr4::Lexer {
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
    CALLED_RETURN_OF = 42, CALLED_METHOD_OF = 43, METHOD_USED_BY = 44, FIELD_USED_BY = 45, 
    METHOD_USE = 46, READ = 47, WRITE = 48, IN_PACKAGE = 49, CLASS_OF = 50, 
    SUPER = 51, SUB = 52, STYLE = 53, DEFAULT_STYLE = 54, BASIC_STYLE = 55, 
    CLASS_SCOPE = 56, NODE = 57, REFERENCE = 58, VOID_REF = 59, CONDITION = 60, 
    ELSE = 61, DATA_STEP = 62, TIMING_STEP = 63, DATA_OVERRIDE = 64, TIMING_OVERRIDE = 65, 
    LV = 66, FIELD = 67, METHOD = 68, CONSTRUCTOR = 69, CALLED_METHOD = 70, 
    PARAMETER = 71, CALLED_PARAMETER = 72, RETURN = 73, CALLED_RETURN = 74, 
    INDEX = 75, ERROR = 76, SEGMENT = 77, LINE = 78, LINE_INSTANCE = 79, 
    GLUE = 80, GLUE_RUNTIME = 81, GLULE_MEMBER_OF = 82, GLUE_INSTANCE_OF = 83, 
    GLUE_OVERRIDE = 84, GLUE_HIERARCHY = 85, GRAPH = 86, GRAPH_INSTANCE = 87, 
    CODE_ORDER = 88, SHOW = 89, STRING = 90, IDENTIFIER = 91, FLOAT = 92, 
    INT = 93, WS = 94, LINE_COMMENT = 95
  };

  explicit SimpleViewLexer(antlr4::CharStream *input);

  ~SimpleViewLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

