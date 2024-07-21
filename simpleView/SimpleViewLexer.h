
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
    CALLED_RETURN_OF = 42, CALLED_METHOD_OF = 43, READ = 44, WRITE = 45, 
    IN_PACKAGE = 46, USED_BY = 47, USE = 48, CLASS_OF = 49, SUPER = 50, 
    SUB = 51, STYLE = 52, DEFAULT_STYLE = 53, BASIC_STYLE = 54, CLASS_SCOPE = 55, 
    NODE = 56, REFERENCE = 57, CONDITION = 58, ELSE = 59, DATA_STEP = 60, 
    TIMING_STEP = 61, DATA_OVERRIDE = 62, TIMING_OVERRIDE = 63, LV = 64, 
    FIELD = 65, METHOD = 66, CONSTRUCTOR = 67, CALLED_METHOD = 68, PARAMETER = 69, 
    CALLED_PARAMETER = 70, RETURN = 71, CALLED_RETURN = 72, INDEX = 73, 
    ERROR = 74, SEGMENT = 75, LINE = 76, LINE_INSTANCE = 77, GLUE = 78, 
    GLUE_RUNTIME = 79, GLULE_MEMBER_OF = 80, GLUE_INSTANCE_OF = 81, GLUE_OVERRIDE = 82, 
    GLUE_HIERARCHY = 83, GRAPH = 84, GRAPH_INSTANCE = 85, CODE_ORDER = 86, 
    SHOW = 87, STRING = 88, IDENTIFIER = 89, FLOAT = 90, INT = 91, WS = 92, 
    LINE_COMMENT = 93
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

