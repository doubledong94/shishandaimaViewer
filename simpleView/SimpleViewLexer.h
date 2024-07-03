
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
    PARAMETER_OF = 37, RETURN_OF = 38, READ = 39, WRITE = 40, IN_PACKAGE = 41, 
    USED_BY = 42, USE = 43, CLASS_OF = 44, SUPER = 45, SUB = 46, STYLE = 47, 
    DEFAULT_STYLE = 48, BASIC_STYLE = 49, CLASS_SCOPE = 50, NODE = 51, REFERENCE = 52, 
    CONDITION = 53, ELSE = 54, DATA_STEP = 55, TIMING_STEP = 56, DATA_OVERRIDE = 57, 
    TIMING_OVERRIDE = 58, FIELD = 59, METHOD = 60, CONSTRUCTOR = 61, CALLED_METHOD = 62, 
    PARAMETER = 63, CALLED_PARAMETER = 64, RETURN = 65, CALLED_RETURN = 66, 
    INDEX = 67, SEGMENT = 68, LINE = 69, LINE_INSTANCE = 70, GLUE = 71, 
    GLUE_RUNTIME = 72, GLULE_MEMBER_OF = 73, GLUE_INSTANCE_OF = 74, GLUE_OVERRIDE = 75, 
    GLUE_HIERARCHY = 76, GRAPH = 77, GRAPH_INSTANCE = 78, CODE_ORDER = 79, 
    SHOW = 80, STRING = 81, IDENTIFIER = 82, FLOAT = 83, INT = 84, WS = 85, 
    LINE_COMMENT = 86
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

