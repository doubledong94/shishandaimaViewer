
// Generated from SimpleView.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SimpleViewLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, LABEL_DETAIL_LEVEL_SIMPLE = 20, 
    LABEL_DETAIL_LEVEL_FULL = 21, NODE_COLOR = 22, NODE_SCALE = 23, LABEL_COLOR = 24, 
    LABEL_SCALE = 25, LABEL_DETAIL_LEVEL = 26, POSITION_Z = 27, BASIC_NODE_SIZE = 28, 
    BASIC_LABEL_SIZE = 29, BASIC_POSITION_Z = 30, ANY = 31, FINAL = 32, 
    CLASS = 33, FIELD_OF = 34, INSTANCE_OF = 35, METHOD_OF = 36, CREATOR = 37, 
    PARAMETER_OF = 38, RETURN_OF = 39, CALLED_PARAM_OF = 40, CALLED_RETURN_OF = 41, 
    CALLED_METHOD_OF = 42, METHOD_USED_BY = 43, FIELD_USED_BY = 44, METHOD_USE = 45, 
    READ = 46, WRITE = 47, IN_PACKAGE = 48, CLASS_OF = 49, SUPER = 50, SUB = 51, 
    STYLE = 52, DEFAULT_STYLE = 53, BASIC_STYLE = 54, CLASS_SCOPE = 55, 
    NODE = 56, REFERENCE = 57, VOID_REF = 58, CONDITION = 59, ELSE = 60, 
    DATA_STEP = 61, TIMING_STEP = 62, DATA_OVERRIDE = 63, TIMING_OVERRIDE = 64, 
    LV = 65, FIELD = 66, METHOD = 67, CONSTRUCTOR = 68, CALLED_METHOD = 69, 
    PARAMETER = 70, CALLED_PARAMETER = 71, RETURN = 72, CALLED_RETURN = 73, 
    INDEX = 74, ERROR = 75, FIELD_CONNECTION = 76, SEGMENT = 77, LINE = 78, 
    LINE_INSTANCE = 79, GRAPH = 80, GRAPH_INSTANCE = 81, CODE_ORDER = 82, 
    NULL_ = 83, SHOW = 84, STRING = 85, IDENTIFIER = 86, FLOAT = 87, INT = 88, 
    WS = 89, LINE_COMMENT = 90
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

