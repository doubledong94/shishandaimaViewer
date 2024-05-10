
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
    BASIC_LABEL_SIZE = 29, BASIC_POSITION_Z = 30, ANY = 31, FIELD_OF = 32, 
    INSTANCE_OF = 33, METHOD_OF = 34, CREATOR = 35, PARAMETER_OF = 36, RETURN_OF = 37, 
    CALLED_PARAM_OF = 38, CALLED_RETURN_OF = 39, CALLED_METHOD_OF = 40, 
    READ = 41, WRITE = 42, IN_PACKAGE = 43, USED_BY = 44, USE = 45, CLASS_OF = 46, 
    SUPER = 47, SUB = 48, STYLE = 49, DEFAULT_STYLE = 50, BASIC_STYLE = 51, 
    CLASS_SCOPE = 52, NODE = 53, REFERENCE = 54, CONDITION = 55, ELSE = 56, 
    STEP = 57, SEGMENT = 58, LINE = 59, LINE_INSTANCE = 60, GLUE = 61, GLUE_RUNTIME = 62, 
    GLULE_MEMBER_OF = 63, GLUE_INSTANCE_OF = 64, GLUE_OVERRIDE = 65, GLUE_HIERARCHY = 66, 
    GRAPH = 67, GRAPH_INSTANCE = 68, CODE_ORDER = 69, SHOW = 70, STRING = 71, 
    IDENTIFIER = 72, FLOAT = 73, INT = 74, WS = 75, LINE_COMMENT = 76
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

