
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
    ANY = 32, FINAL = 33, FIELD_OF = 34, INSTANCE_OF = 35, METHOD_OF = 36, 
    CREATOR = 37, PARAMETER_OF = 38, RETURN_OF = 39, CALLED_PARAM_OF = 40, 
    CALLED_RETURN_OF = 41, CALLED_METHOD_OF = 42, READ = 43, WRITE = 44, 
    IN_PACKAGE = 45, USED_BY = 46, USE = 47, CLASS_OF = 48, SUPER = 49, 
    SUB = 50, STYLE = 51, DEFAULT_STYLE = 52, BASIC_STYLE = 53, CLASS_SCOPE = 54, 
    NODE = 55, REFERENCE = 56, CONDITION = 57, ELSE = 58, DATA_STEP = 59, 
    TIMING_STEP = 60, DATA_OVERRIDE = 61, TIMING_OVERRIDE = 62, FIELD = 63, 
    METHOD = 64, CONSTRUCTOR = 65, CALLED_METHOD = 66, PARAMETER = 67, CALLED_PARAMETER = 68, 
    RETURN = 69, CALLED_RETURN = 70, INDEX = 71, SEGMENT = 72, LINE = 73, 
    LINE_INSTANCE = 74, GLUE = 75, GLUE_RUNTIME = 76, GLULE_MEMBER_OF = 77, 
    GLUE_INSTANCE_OF = 78, GLUE_OVERRIDE = 79, GLUE_HIERARCHY = 80, GRAPH = 81, 
    GRAPH_INSTANCE = 82, CODE_ORDER = 83, SHOW = 84, STRING = 85, IDENTIFIER = 86, 
    FLOAT = 87, INT = 88, WS = 89, LINE_COMMENT = 90
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

