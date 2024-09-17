
// Generated from AIDLLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  AIDLLexer : public antlr4::Lexer {
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

  explicit AIDLLexer(antlr4::CharStream *input);

  ~AIDLLexer() override;


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

