
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
    ANY = 32, FIELD_OF = 33, INSTANCE_OF = 34, METHOD_OF = 35, CREATOR = 36, 
    PARAMETER_OF = 37, RETURN_OF = 38, CALLED_PARAM_OF = 39, CALLED_RETURN_OF = 40, 
    CALLED_METHOD_OF = 41, READ = 42, WRITE = 43, IN_PACKAGE = 44, USED_BY = 45, 
    USE = 46, CLASS_OF = 47, SUPER = 48, SUB = 49, STYLE = 50, DEFAULT_STYLE = 51, 
    BASIC_STYLE = 52, CLASS_SCOPE = 53, NODE = 54, REFERENCE = 55, CONDITION = 56, 
    ELSE = 57, DATA_STEP = 58, TIMING_STEP = 59, FIELD = 60, METHOD = 61, 
    CONSTRUCTOR = 62, CALLED_METHOD = 63, PARAMETER = 64, CALLED_PARAMETER = 65, 
    RETURN = 66, CALLED_RETURN = 67, INDEX = 68, SEGMENT = 69, LINE = 70, 
    LINE_INSTANCE = 71, GLUE = 72, GLUE_RUNTIME = 73, GLULE_MEMBER_OF = 74, 
    GLUE_INSTANCE_OF = 75, GLUE_OVERRIDE = 76, GLUE_HIERARCHY = 77, GRAPH = 78, 
    GRAPH_INSTANCE = 79, CODE_ORDER = 80, SHOW = 81, STRING = 82, IDENTIFIER = 83, 
    FLOAT = 84, INT = 85, WS = 86, LINE_COMMENT = 87
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

