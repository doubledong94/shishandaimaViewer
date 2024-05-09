
// Generated from JavaLexer.g4 by ANTLR 4.13.1


#include "JavaLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct JavaLexerStaticData final {
  JavaLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  JavaLexerStaticData(const JavaLexerStaticData&) = delete;
  JavaLexerStaticData(JavaLexerStaticData&&) = delete;
  JavaLexerStaticData& operator=(const JavaLexerStaticData&) = delete;
  JavaLexerStaticData& operator=(JavaLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag javalexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
JavaLexerStaticData *javalexerLexerStaticData = nullptr;

void javalexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (javalexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(javalexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<JavaLexerStaticData>(
    std::vector<std::string>{
      "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH", 
      "CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", 
      "ENUM", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO", 
      "IMPLEMENTS", "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LONG", 
      "NATIVE", "NEW", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", 
      "SHORT", "STATIC", "STRICTFP", "SUPER", "SWITCH", "SYNCHRONIZED", 
      "THIS", "THROW", "THROWS", "TRANSIENT", "TRY", "VOID", "VOLATILE", 
      "WHILE", "MODULE", "OPEN", "REQUIRES", "EXPORTS", "OPENS", "TO", "USES", 
      "PROVIDES", "WITH", "TRANSITIVE", "VAR", "YIELD", "RECORD", "SEALED", 
      "PERMITS", "NON_SEALED", "DECIMAL_LITERAL", "HEX_LITERAL", "OCT_LITERAL", 
      "BINARY_LITERAL", "FLOAT_LITERAL", "HEX_FLOAT_LITERAL", "BOOL_LITERAL", 
      "CHAR_LITERAL", "STRING_LITERAL", "TEXT_BLOCK", "NULL_LITERAL", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
      "DOT", "ASSIGN", "GT", "LT", "BANG", "TILDE", "QUESTION", "COLON", 
      "EQUAL", "LE", "GE", "NOTEQUAL", "AND", "OR", "INC", "DEC", "ADD", 
      "SUB", "MUL", "DIV", "BITAND", "BITOR", "CARET", "MOD", "ADD_ASSIGN", 
      "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", 
      "XOR_ASSIGN", "MOD_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "URSHIFT_ASSIGN", 
      "ARROW", "COLONCOLON", "AT", "ELLIPSIS", "WS", "COMMENT", "LINE_COMMENT", 
      "IDENTIFIER", "ExponentPart", "EscapeSequence", "HexDigits", "HexDigit", 
      "Digits", "LetterOrDigit", "Letter"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'abstract'", "'assert'", "'boolean'", "'break'", "'byte'", "'case'", 
      "'catch'", "'char'", "'class'", "'const'", "'continue'", "'default'", 
      "'do'", "'double'", "'else'", "'enum'", "'extends'", "'final'", "'finally'", 
      "'float'", "'for'", "'if'", "'goto'", "'implements'", "'import'", 
      "'instanceof'", "'int'", "'interface'", "'long'", "'native'", "'new'", 
      "'package'", "'private'", "'protected'", "'public'", "'return'", "'short'", 
      "'static'", "'strictfp'", "'super'", "'switch'", "'synchronized'", 
      "'this'", "'throw'", "'throws'", "'transient'", "'try'", "'void'", 
      "'volatile'", "'while'", "'module'", "'open'", "'requires'", "'exports'", 
      "'opens'", "'to'", "'uses'", "'provides'", "'with'", "'transitive'", 
      "'var'", "'yield'", "'record'", "'sealed'", "'permits'", "'non-sealed'", 
      "", "", "", "", "", "", "", "", "", "", "'null'", "'('", "')'", "'{'", 
      "'}'", "'['", "']'", "';'", "','", "'.'", "'='", "'>'", "'<'", "'!'", 
      "'~'", "'\\u003F'", "':'", "'=='", "'<='", "'>='", "'!='", "'&&'", 
      "'||'", "'++'", "'--'", "'+'", "'-'", "'*'", "'/'", "'&'", "'|'", 
      "'^'", "'%'", "'+='", "'-='", "'*='", "'/='", "'&='", "'|='", "'^='", 
      "'%='", "'<<='", "'>>='", "'>>>='", "'->'", "'::'", "'@'", "'...'"
    },
    std::vector<std::string>{
      "", "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH", 
      "CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", 
      "ENUM", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO", 
      "IMPLEMENTS", "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LONG", 
      "NATIVE", "NEW", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", 
      "SHORT", "STATIC", "STRICTFP", "SUPER", "SWITCH", "SYNCHRONIZED", 
      "THIS", "THROW", "THROWS", "TRANSIENT", "TRY", "VOID", "VOLATILE", 
      "WHILE", "MODULE", "OPEN", "REQUIRES", "EXPORTS", "OPENS", "TO", "USES", 
      "PROVIDES", "WITH", "TRANSITIVE", "VAR", "YIELD", "RECORD", "SEALED", 
      "PERMITS", "NON_SEALED", "DECIMAL_LITERAL", "HEX_LITERAL", "OCT_LITERAL", 
      "BINARY_LITERAL", "FLOAT_LITERAL", "HEX_FLOAT_LITERAL", "BOOL_LITERAL", 
      "CHAR_LITERAL", "STRING_LITERAL", "TEXT_BLOCK", "NULL_LITERAL", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", 
      "DOT", "ASSIGN", "GT", "LT", "BANG", "TILDE", "QUESTION", "COLON", 
      "EQUAL", "LE", "GE", "NOTEQUAL", "AND", "OR", "INC", "DEC", "ADD", 
      "SUB", "MUL", "DIV", "BITAND", "BITOR", "CARET", "MOD", "ADD_ASSIGN", 
      "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", 
      "XOR_ASSIGN", "MOD_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "URSHIFT_ASSIGN", 
      "ARROW", "COLONCOLON", "AT", "ELLIPSIS", "WS", "COMMENT", "LINE_COMMENT", 
      "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,128,1112,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,
  	7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,
  	14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,
  	21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,
  	28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,
  	35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,
  	42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,
  	49,7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,
  	56,7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,
  	63,7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,
  	70,7,70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,2,75,7,75,2,76,7,76,2,
  	77,7,77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,2,83,7,83,2,
  	84,7,84,2,85,7,85,2,86,7,86,2,87,7,87,2,88,7,88,2,89,7,89,2,90,7,90,2,
  	91,7,91,2,92,7,92,2,93,7,93,2,94,7,94,2,95,7,95,2,96,7,96,2,97,7,97,2,
  	98,7,98,2,99,7,99,2,100,7,100,2,101,7,101,2,102,7,102,2,103,7,103,2,104,
  	7,104,2,105,7,105,2,106,7,106,2,107,7,107,2,108,7,108,2,109,7,109,2,110,
  	7,110,2,111,7,111,2,112,7,112,2,113,7,113,2,114,7,114,2,115,7,115,2,116,
  	7,116,2,117,7,117,2,118,7,118,2,119,7,119,2,120,7,120,2,121,7,121,2,122,
  	7,122,2,123,7,123,2,124,7,124,2,125,7,125,2,126,7,126,2,127,7,127,2,128,
  	7,128,2,129,7,129,2,130,7,130,2,131,7,131,2,132,7,132,2,133,7,133,2,134,
  	7,134,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,
  	4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,
  	12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,
  	15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,
  	22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	24,1,24,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,
  	25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,
  	29,1,29,1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,
  	32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,
  	33,1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,35,1,35,1,35,1,
  	35,1,35,1,35,1,35,1,36,1,36,1,36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,
  	37,1,37,1,37,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,
  	39,1,39,1,39,1,39,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,
  	41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,42,1,42,1,42,1,42,1,
  	42,1,43,1,43,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,1,44,1,44,1,44,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,46,1,46,1,46,1,46,1,
  	47,1,47,1,47,1,47,1,47,1,48,1,48,1,48,1,48,1,48,1,48,1,48,1,48,1,48,1,
  	49,1,49,1,49,1,49,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,51,1,
  	51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,53,1,
  	53,1,53,1,53,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,54,1,54,1,54,1,55,1,
  	55,1,55,1,56,1,56,1,56,1,56,1,56,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,
  	57,1,57,1,58,1,58,1,58,1,58,1,58,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,
  	59,1,59,1,59,1,59,1,60,1,60,1,60,1,60,1,61,1,61,1,61,1,61,1,61,1,61,1,
  	62,1,62,1,62,1,62,1,62,1,62,1,62,1,63,1,63,1,63,1,63,1,63,1,63,1,63,1,
  	64,1,64,1,64,1,64,1,64,1,64,1,64,1,64,1,65,1,65,1,65,1,65,1,65,1,65,1,
  	65,1,65,1,65,1,65,1,65,1,66,1,66,1,66,3,66,725,8,66,1,66,4,66,728,8,66,
  	11,66,12,66,729,1,66,3,66,733,8,66,3,66,735,8,66,1,66,3,66,738,8,66,1,
  	67,1,67,1,67,1,67,5,67,744,8,67,10,67,12,67,747,9,67,1,67,3,67,750,8,
  	67,1,67,3,67,753,8,67,1,68,1,68,5,68,757,8,68,10,68,12,68,760,9,68,1,
  	68,1,68,5,68,764,8,68,10,68,12,68,767,9,68,1,68,3,68,770,8,68,1,68,3,
  	68,773,8,68,1,69,1,69,1,69,1,69,5,69,779,8,69,10,69,12,69,782,9,69,1,
  	69,3,69,785,8,69,1,69,3,69,788,8,69,1,70,1,70,1,70,3,70,793,8,70,1,70,
  	1,70,3,70,797,8,70,1,70,3,70,800,8,70,1,70,3,70,803,8,70,1,70,1,70,1,
  	70,3,70,808,8,70,1,70,3,70,811,8,70,3,70,813,8,70,1,71,1,71,1,71,1,71,
  	3,71,819,8,71,1,71,3,71,822,8,71,1,71,1,71,3,71,826,8,71,1,71,1,71,3,
  	71,830,8,71,1,71,1,71,3,71,834,8,71,1,72,1,72,1,72,1,72,1,72,1,72,1,72,
  	1,72,1,72,3,72,845,8,72,1,73,1,73,1,73,3,73,850,8,73,1,73,1,73,1,74,1,
  	74,1,74,5,74,857,8,74,10,74,12,74,860,9,74,1,74,1,74,1,75,1,75,1,75,1,
  	75,1,75,5,75,869,8,75,10,75,12,75,872,9,75,1,75,1,75,1,75,5,75,877,8,
  	75,10,75,12,75,880,9,75,1,75,1,75,1,75,1,75,1,76,1,76,1,76,1,76,1,76,
  	1,77,1,77,1,78,1,78,1,79,1,79,1,80,1,80,1,81,1,81,1,82,1,82,1,83,1,83,
  	1,84,1,84,1,85,1,85,1,86,1,86,1,87,1,87,1,88,1,88,1,89,1,89,1,90,1,90,
  	1,91,1,91,1,92,1,92,1,93,1,93,1,93,1,94,1,94,1,94,1,95,1,95,1,95,1,96,
  	1,96,1,96,1,97,1,97,1,97,1,98,1,98,1,98,1,99,1,99,1,99,1,100,1,100,1,
  	100,1,101,1,101,1,102,1,102,1,103,1,103,1,104,1,104,1,105,1,105,1,106,
  	1,106,1,107,1,107,1,108,1,108,1,109,1,109,1,109,1,110,1,110,1,110,1,111,
  	1,111,1,111,1,112,1,112,1,112,1,113,1,113,1,113,1,114,1,114,1,114,1,115,
  	1,115,1,115,1,116,1,116,1,116,1,117,1,117,1,117,1,117,1,118,1,118,1,118,
  	1,118,1,119,1,119,1,119,1,119,1,119,1,120,1,120,1,120,1,121,1,121,1,121,
  	1,122,1,122,1,123,1,123,1,123,1,123,1,124,4,124,1013,8,124,11,124,12,
  	124,1014,1,124,1,124,1,125,1,125,1,125,1,125,5,125,1023,8,125,10,125,
  	12,125,1026,9,125,1,125,1,125,1,125,1,125,1,125,1,126,1,126,1,126,1,126,
  	5,126,1037,8,126,10,126,12,126,1040,9,126,1,126,1,126,1,127,1,127,5,127,
  	1046,8,127,10,127,12,127,1049,9,127,1,128,1,128,3,128,1053,8,128,1,128,
  	1,128,1,129,1,129,1,129,1,129,3,129,1061,8,129,1,129,3,129,1064,8,129,
  	1,129,1,129,1,129,4,129,1069,8,129,11,129,12,129,1070,1,129,1,129,1,129,
  	1,129,1,129,3,129,1078,8,129,1,130,1,130,1,130,5,130,1083,8,130,10,130,
  	12,130,1086,9,130,1,130,3,130,1089,8,130,1,131,1,131,1,132,1,132,5,132,
  	1095,8,132,10,132,12,132,1098,9,132,1,132,3,132,1101,8,132,1,133,1,133,
  	3,133,1105,8,133,1,134,1,134,1,134,1,134,3,134,1111,8,134,2,878,1024,
  	0,135,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,
  	25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,
  	73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,46,93,47,95,
  	48,97,49,99,50,101,51,103,52,105,53,107,54,109,55,111,56,113,57,115,58,
  	117,59,119,60,121,61,123,62,125,63,127,64,129,65,131,66,133,67,135,68,
  	137,69,139,70,141,71,143,72,145,73,147,74,149,75,151,76,153,77,155,78,
  	157,79,159,80,161,81,163,82,165,83,167,84,169,85,171,86,173,87,175,88,
  	177,89,179,90,181,91,183,92,185,93,187,94,189,95,191,96,193,97,195,98,
  	197,99,199,100,201,101,203,102,205,103,207,104,209,105,211,106,213,107,
  	215,108,217,109,219,110,221,111,223,112,225,113,227,114,229,115,231,116,
  	233,117,235,118,237,119,239,120,241,121,243,122,245,123,247,124,249,125,
  	251,126,253,127,255,128,257,0,259,0,261,0,263,0,265,0,267,0,269,0,1,0,
  	27,1,0,49,57,2,0,76,76,108,108,2,0,88,88,120,120,3,0,48,57,65,70,97,102,
  	4,0,48,57,65,70,95,95,97,102,1,0,48,55,2,0,48,55,95,95,2,0,66,66,98,98,
  	1,0,48,49,2,0,48,49,95,95,4,0,68,68,70,70,100,100,102,102,2,0,80,80,112,
  	112,2,0,43,43,45,45,4,0,10,10,13,13,39,39,92,92,4,0,10,10,13,13,34,34,
  	92,92,2,0,9,9,32,32,2,0,10,10,13,13,3,0,9,10,12,13,32,32,2,0,69,69,101,
  	101,8,0,34,34,39,39,92,92,98,98,102,102,110,110,114,114,116,116,1,0,48,
  	51,1,0,48,57,2,0,48,57,95,95,4,0,36,36,65,90,95,95,97,122,2,0,0,127,55296,
  	56319,1,0,55296,56319,1,0,56320,57343,1156,0,1,1,0,0,0,0,3,1,0,0,0,0,
  	5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,
  	0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,
  	0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,
  	1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,
  	0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,
  	0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,
  	1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,
  	0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,
  	0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,
  	1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,
  	1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,
  	1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,0,131,
  	1,0,0,0,0,133,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,0,141,
  	1,0,0,0,0,143,1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,149,1,0,0,0,0,151,
  	1,0,0,0,0,153,1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,159,1,0,0,0,0,161,
  	1,0,0,0,0,163,1,0,0,0,0,165,1,0,0,0,0,167,1,0,0,0,0,169,1,0,0,0,0,171,
  	1,0,0,0,0,173,1,0,0,0,0,175,1,0,0,0,0,177,1,0,0,0,0,179,1,0,0,0,0,181,
  	1,0,0,0,0,183,1,0,0,0,0,185,1,0,0,0,0,187,1,0,0,0,0,189,1,0,0,0,0,191,
  	1,0,0,0,0,193,1,0,0,0,0,195,1,0,0,0,0,197,1,0,0,0,0,199,1,0,0,0,0,201,
  	1,0,0,0,0,203,1,0,0,0,0,205,1,0,0,0,0,207,1,0,0,0,0,209,1,0,0,0,0,211,
  	1,0,0,0,0,213,1,0,0,0,0,215,1,0,0,0,0,217,1,0,0,0,0,219,1,0,0,0,0,221,
  	1,0,0,0,0,223,1,0,0,0,0,225,1,0,0,0,0,227,1,0,0,0,0,229,1,0,0,0,0,231,
  	1,0,0,0,0,233,1,0,0,0,0,235,1,0,0,0,0,237,1,0,0,0,0,239,1,0,0,0,0,241,
  	1,0,0,0,0,243,1,0,0,0,0,245,1,0,0,0,0,247,1,0,0,0,0,249,1,0,0,0,0,251,
  	1,0,0,0,0,253,1,0,0,0,0,255,1,0,0,0,1,271,1,0,0,0,3,280,1,0,0,0,5,287,
  	1,0,0,0,7,295,1,0,0,0,9,301,1,0,0,0,11,306,1,0,0,0,13,311,1,0,0,0,15,
  	317,1,0,0,0,17,322,1,0,0,0,19,328,1,0,0,0,21,334,1,0,0,0,23,343,1,0,0,
  	0,25,351,1,0,0,0,27,354,1,0,0,0,29,361,1,0,0,0,31,366,1,0,0,0,33,371,
  	1,0,0,0,35,379,1,0,0,0,37,385,1,0,0,0,39,393,1,0,0,0,41,399,1,0,0,0,43,
  	403,1,0,0,0,45,406,1,0,0,0,47,411,1,0,0,0,49,422,1,0,0,0,51,429,1,0,0,
  	0,53,440,1,0,0,0,55,444,1,0,0,0,57,454,1,0,0,0,59,459,1,0,0,0,61,466,
  	1,0,0,0,63,470,1,0,0,0,65,478,1,0,0,0,67,486,1,0,0,0,69,496,1,0,0,0,71,
  	503,1,0,0,0,73,510,1,0,0,0,75,516,1,0,0,0,77,523,1,0,0,0,79,532,1,0,0,
  	0,81,538,1,0,0,0,83,545,1,0,0,0,85,558,1,0,0,0,87,563,1,0,0,0,89,569,
  	1,0,0,0,91,576,1,0,0,0,93,586,1,0,0,0,95,590,1,0,0,0,97,595,1,0,0,0,99,
  	604,1,0,0,0,101,610,1,0,0,0,103,617,1,0,0,0,105,622,1,0,0,0,107,631,1,
  	0,0,0,109,639,1,0,0,0,111,645,1,0,0,0,113,648,1,0,0,0,115,653,1,0,0,0,
  	117,662,1,0,0,0,119,667,1,0,0,0,121,678,1,0,0,0,123,682,1,0,0,0,125,688,
  	1,0,0,0,127,695,1,0,0,0,129,702,1,0,0,0,131,710,1,0,0,0,133,734,1,0,0,
  	0,135,739,1,0,0,0,137,754,1,0,0,0,139,774,1,0,0,0,141,812,1,0,0,0,143,
  	814,1,0,0,0,145,844,1,0,0,0,147,846,1,0,0,0,149,853,1,0,0,0,151,863,1,
  	0,0,0,153,885,1,0,0,0,155,890,1,0,0,0,157,892,1,0,0,0,159,894,1,0,0,0,
  	161,896,1,0,0,0,163,898,1,0,0,0,165,900,1,0,0,0,167,902,1,0,0,0,169,904,
  	1,0,0,0,171,906,1,0,0,0,173,908,1,0,0,0,175,910,1,0,0,0,177,912,1,0,0,
  	0,179,914,1,0,0,0,181,916,1,0,0,0,183,918,1,0,0,0,185,920,1,0,0,0,187,
  	922,1,0,0,0,189,925,1,0,0,0,191,928,1,0,0,0,193,931,1,0,0,0,195,934,1,
  	0,0,0,197,937,1,0,0,0,199,940,1,0,0,0,201,943,1,0,0,0,203,946,1,0,0,0,
  	205,948,1,0,0,0,207,950,1,0,0,0,209,952,1,0,0,0,211,954,1,0,0,0,213,956,
  	1,0,0,0,215,958,1,0,0,0,217,960,1,0,0,0,219,962,1,0,0,0,221,965,1,0,0,
  	0,223,968,1,0,0,0,225,971,1,0,0,0,227,974,1,0,0,0,229,977,1,0,0,0,231,
  	980,1,0,0,0,233,983,1,0,0,0,235,986,1,0,0,0,237,990,1,0,0,0,239,994,1,
  	0,0,0,241,999,1,0,0,0,243,1002,1,0,0,0,245,1005,1,0,0,0,247,1007,1,0,
  	0,0,249,1012,1,0,0,0,251,1018,1,0,0,0,253,1032,1,0,0,0,255,1043,1,0,0,
  	0,257,1050,1,0,0,0,259,1077,1,0,0,0,261,1079,1,0,0,0,263,1090,1,0,0,0,
  	265,1092,1,0,0,0,267,1104,1,0,0,0,269,1110,1,0,0,0,271,272,5,97,0,0,272,
  	273,5,98,0,0,273,274,5,115,0,0,274,275,5,116,0,0,275,276,5,114,0,0,276,
  	277,5,97,0,0,277,278,5,99,0,0,278,279,5,116,0,0,279,2,1,0,0,0,280,281,
  	5,97,0,0,281,282,5,115,0,0,282,283,5,115,0,0,283,284,5,101,0,0,284,285,
  	5,114,0,0,285,286,5,116,0,0,286,4,1,0,0,0,287,288,5,98,0,0,288,289,5,
  	111,0,0,289,290,5,111,0,0,290,291,5,108,0,0,291,292,5,101,0,0,292,293,
  	5,97,0,0,293,294,5,110,0,0,294,6,1,0,0,0,295,296,5,98,0,0,296,297,5,114,
  	0,0,297,298,5,101,0,0,298,299,5,97,0,0,299,300,5,107,0,0,300,8,1,0,0,
  	0,301,302,5,98,0,0,302,303,5,121,0,0,303,304,5,116,0,0,304,305,5,101,
  	0,0,305,10,1,0,0,0,306,307,5,99,0,0,307,308,5,97,0,0,308,309,5,115,0,
  	0,309,310,5,101,0,0,310,12,1,0,0,0,311,312,5,99,0,0,312,313,5,97,0,0,
  	313,314,5,116,0,0,314,315,5,99,0,0,315,316,5,104,0,0,316,14,1,0,0,0,317,
  	318,5,99,0,0,318,319,5,104,0,0,319,320,5,97,0,0,320,321,5,114,0,0,321,
  	16,1,0,0,0,322,323,5,99,0,0,323,324,5,108,0,0,324,325,5,97,0,0,325,326,
  	5,115,0,0,326,327,5,115,0,0,327,18,1,0,0,0,328,329,5,99,0,0,329,330,5,
  	111,0,0,330,331,5,110,0,0,331,332,5,115,0,0,332,333,5,116,0,0,333,20,
  	1,0,0,0,334,335,5,99,0,0,335,336,5,111,0,0,336,337,5,110,0,0,337,338,
  	5,116,0,0,338,339,5,105,0,0,339,340,5,110,0,0,340,341,5,117,0,0,341,342,
  	5,101,0,0,342,22,1,0,0,0,343,344,5,100,0,0,344,345,5,101,0,0,345,346,
  	5,102,0,0,346,347,5,97,0,0,347,348,5,117,0,0,348,349,5,108,0,0,349,350,
  	5,116,0,0,350,24,1,0,0,0,351,352,5,100,0,0,352,353,5,111,0,0,353,26,1,
  	0,0,0,354,355,5,100,0,0,355,356,5,111,0,0,356,357,5,117,0,0,357,358,5,
  	98,0,0,358,359,5,108,0,0,359,360,5,101,0,0,360,28,1,0,0,0,361,362,5,101,
  	0,0,362,363,5,108,0,0,363,364,5,115,0,0,364,365,5,101,0,0,365,30,1,0,
  	0,0,366,367,5,101,0,0,367,368,5,110,0,0,368,369,5,117,0,0,369,370,5,109,
  	0,0,370,32,1,0,0,0,371,372,5,101,0,0,372,373,5,120,0,0,373,374,5,116,
  	0,0,374,375,5,101,0,0,375,376,5,110,0,0,376,377,5,100,0,0,377,378,5,115,
  	0,0,378,34,1,0,0,0,379,380,5,102,0,0,380,381,5,105,0,0,381,382,5,110,
  	0,0,382,383,5,97,0,0,383,384,5,108,0,0,384,36,1,0,0,0,385,386,5,102,0,
  	0,386,387,5,105,0,0,387,388,5,110,0,0,388,389,5,97,0,0,389,390,5,108,
  	0,0,390,391,5,108,0,0,391,392,5,121,0,0,392,38,1,0,0,0,393,394,5,102,
  	0,0,394,395,5,108,0,0,395,396,5,111,0,0,396,397,5,97,0,0,397,398,5,116,
  	0,0,398,40,1,0,0,0,399,400,5,102,0,0,400,401,5,111,0,0,401,402,5,114,
  	0,0,402,42,1,0,0,0,403,404,5,105,0,0,404,405,5,102,0,0,405,44,1,0,0,0,
  	406,407,5,103,0,0,407,408,5,111,0,0,408,409,5,116,0,0,409,410,5,111,0,
  	0,410,46,1,0,0,0,411,412,5,105,0,0,412,413,5,109,0,0,413,414,5,112,0,
  	0,414,415,5,108,0,0,415,416,5,101,0,0,416,417,5,109,0,0,417,418,5,101,
  	0,0,418,419,5,110,0,0,419,420,5,116,0,0,420,421,5,115,0,0,421,48,1,0,
  	0,0,422,423,5,105,0,0,423,424,5,109,0,0,424,425,5,112,0,0,425,426,5,111,
  	0,0,426,427,5,114,0,0,427,428,5,116,0,0,428,50,1,0,0,0,429,430,5,105,
  	0,0,430,431,5,110,0,0,431,432,5,115,0,0,432,433,5,116,0,0,433,434,5,97,
  	0,0,434,435,5,110,0,0,435,436,5,99,0,0,436,437,5,101,0,0,437,438,5,111,
  	0,0,438,439,5,102,0,0,439,52,1,0,0,0,440,441,5,105,0,0,441,442,5,110,
  	0,0,442,443,5,116,0,0,443,54,1,0,0,0,444,445,5,105,0,0,445,446,5,110,
  	0,0,446,447,5,116,0,0,447,448,5,101,0,0,448,449,5,114,0,0,449,450,5,102,
  	0,0,450,451,5,97,0,0,451,452,5,99,0,0,452,453,5,101,0,0,453,56,1,0,0,
  	0,454,455,5,108,0,0,455,456,5,111,0,0,456,457,5,110,0,0,457,458,5,103,
  	0,0,458,58,1,0,0,0,459,460,5,110,0,0,460,461,5,97,0,0,461,462,5,116,0,
  	0,462,463,5,105,0,0,463,464,5,118,0,0,464,465,5,101,0,0,465,60,1,0,0,
  	0,466,467,5,110,0,0,467,468,5,101,0,0,468,469,5,119,0,0,469,62,1,0,0,
  	0,470,471,5,112,0,0,471,472,5,97,0,0,472,473,5,99,0,0,473,474,5,107,0,
  	0,474,475,5,97,0,0,475,476,5,103,0,0,476,477,5,101,0,0,477,64,1,0,0,0,
  	478,479,5,112,0,0,479,480,5,114,0,0,480,481,5,105,0,0,481,482,5,118,0,
  	0,482,483,5,97,0,0,483,484,5,116,0,0,484,485,5,101,0,0,485,66,1,0,0,0,
  	486,487,5,112,0,0,487,488,5,114,0,0,488,489,5,111,0,0,489,490,5,116,0,
  	0,490,491,5,101,0,0,491,492,5,99,0,0,492,493,5,116,0,0,493,494,5,101,
  	0,0,494,495,5,100,0,0,495,68,1,0,0,0,496,497,5,112,0,0,497,498,5,117,
  	0,0,498,499,5,98,0,0,499,500,5,108,0,0,500,501,5,105,0,0,501,502,5,99,
  	0,0,502,70,1,0,0,0,503,504,5,114,0,0,504,505,5,101,0,0,505,506,5,116,
  	0,0,506,507,5,117,0,0,507,508,5,114,0,0,508,509,5,110,0,0,509,72,1,0,
  	0,0,510,511,5,115,0,0,511,512,5,104,0,0,512,513,5,111,0,0,513,514,5,114,
  	0,0,514,515,5,116,0,0,515,74,1,0,0,0,516,517,5,115,0,0,517,518,5,116,
  	0,0,518,519,5,97,0,0,519,520,5,116,0,0,520,521,5,105,0,0,521,522,5,99,
  	0,0,522,76,1,0,0,0,523,524,5,115,0,0,524,525,5,116,0,0,525,526,5,114,
  	0,0,526,527,5,105,0,0,527,528,5,99,0,0,528,529,5,116,0,0,529,530,5,102,
  	0,0,530,531,5,112,0,0,531,78,1,0,0,0,532,533,5,115,0,0,533,534,5,117,
  	0,0,534,535,5,112,0,0,535,536,5,101,0,0,536,537,5,114,0,0,537,80,1,0,
  	0,0,538,539,5,115,0,0,539,540,5,119,0,0,540,541,5,105,0,0,541,542,5,116,
  	0,0,542,543,5,99,0,0,543,544,5,104,0,0,544,82,1,0,0,0,545,546,5,115,0,
  	0,546,547,5,121,0,0,547,548,5,110,0,0,548,549,5,99,0,0,549,550,5,104,
  	0,0,550,551,5,114,0,0,551,552,5,111,0,0,552,553,5,110,0,0,553,554,5,105,
  	0,0,554,555,5,122,0,0,555,556,5,101,0,0,556,557,5,100,0,0,557,84,1,0,
  	0,0,558,559,5,116,0,0,559,560,5,104,0,0,560,561,5,105,0,0,561,562,5,115,
  	0,0,562,86,1,0,0,0,563,564,5,116,0,0,564,565,5,104,0,0,565,566,5,114,
  	0,0,566,567,5,111,0,0,567,568,5,119,0,0,568,88,1,0,0,0,569,570,5,116,
  	0,0,570,571,5,104,0,0,571,572,5,114,0,0,572,573,5,111,0,0,573,574,5,119,
  	0,0,574,575,5,115,0,0,575,90,1,0,0,0,576,577,5,116,0,0,577,578,5,114,
  	0,0,578,579,5,97,0,0,579,580,5,110,0,0,580,581,5,115,0,0,581,582,5,105,
  	0,0,582,583,5,101,0,0,583,584,5,110,0,0,584,585,5,116,0,0,585,92,1,0,
  	0,0,586,587,5,116,0,0,587,588,5,114,0,0,588,589,5,121,0,0,589,94,1,0,
  	0,0,590,591,5,118,0,0,591,592,5,111,0,0,592,593,5,105,0,0,593,594,5,100,
  	0,0,594,96,1,0,0,0,595,596,5,118,0,0,596,597,5,111,0,0,597,598,5,108,
  	0,0,598,599,5,97,0,0,599,600,5,116,0,0,600,601,5,105,0,0,601,602,5,108,
  	0,0,602,603,5,101,0,0,603,98,1,0,0,0,604,605,5,119,0,0,605,606,5,104,
  	0,0,606,607,5,105,0,0,607,608,5,108,0,0,608,609,5,101,0,0,609,100,1,0,
  	0,0,610,611,5,109,0,0,611,612,5,111,0,0,612,613,5,100,0,0,613,614,5,117,
  	0,0,614,615,5,108,0,0,615,616,5,101,0,0,616,102,1,0,0,0,617,618,5,111,
  	0,0,618,619,5,112,0,0,619,620,5,101,0,0,620,621,5,110,0,0,621,104,1,0,
  	0,0,622,623,5,114,0,0,623,624,5,101,0,0,624,625,5,113,0,0,625,626,5,117,
  	0,0,626,627,5,105,0,0,627,628,5,114,0,0,628,629,5,101,0,0,629,630,5,115,
  	0,0,630,106,1,0,0,0,631,632,5,101,0,0,632,633,5,120,0,0,633,634,5,112,
  	0,0,634,635,5,111,0,0,635,636,5,114,0,0,636,637,5,116,0,0,637,638,5,115,
  	0,0,638,108,1,0,0,0,639,640,5,111,0,0,640,641,5,112,0,0,641,642,5,101,
  	0,0,642,643,5,110,0,0,643,644,5,115,0,0,644,110,1,0,0,0,645,646,5,116,
  	0,0,646,647,5,111,0,0,647,112,1,0,0,0,648,649,5,117,0,0,649,650,5,115,
  	0,0,650,651,5,101,0,0,651,652,5,115,0,0,652,114,1,0,0,0,653,654,5,112,
  	0,0,654,655,5,114,0,0,655,656,5,111,0,0,656,657,5,118,0,0,657,658,5,105,
  	0,0,658,659,5,100,0,0,659,660,5,101,0,0,660,661,5,115,0,0,661,116,1,0,
  	0,0,662,663,5,119,0,0,663,664,5,105,0,0,664,665,5,116,0,0,665,666,5,104,
  	0,0,666,118,1,0,0,0,667,668,5,116,0,0,668,669,5,114,0,0,669,670,5,97,
  	0,0,670,671,5,110,0,0,671,672,5,115,0,0,672,673,5,105,0,0,673,674,5,116,
  	0,0,674,675,5,105,0,0,675,676,5,118,0,0,676,677,5,101,0,0,677,120,1,0,
  	0,0,678,679,5,118,0,0,679,680,5,97,0,0,680,681,5,114,0,0,681,122,1,0,
  	0,0,682,683,5,121,0,0,683,684,5,105,0,0,684,685,5,101,0,0,685,686,5,108,
  	0,0,686,687,5,100,0,0,687,124,1,0,0,0,688,689,5,114,0,0,689,690,5,101,
  	0,0,690,691,5,99,0,0,691,692,5,111,0,0,692,693,5,114,0,0,693,694,5,100,
  	0,0,694,126,1,0,0,0,695,696,5,115,0,0,696,697,5,101,0,0,697,698,5,97,
  	0,0,698,699,5,108,0,0,699,700,5,101,0,0,700,701,5,100,0,0,701,128,1,0,
  	0,0,702,703,5,112,0,0,703,704,5,101,0,0,704,705,5,114,0,0,705,706,5,109,
  	0,0,706,707,5,105,0,0,707,708,5,116,0,0,708,709,5,115,0,0,709,130,1,0,
  	0,0,710,711,5,110,0,0,711,712,5,111,0,0,712,713,5,110,0,0,713,714,5,45,
  	0,0,714,715,5,115,0,0,715,716,5,101,0,0,716,717,5,97,0,0,717,718,5,108,
  	0,0,718,719,5,101,0,0,719,720,5,100,0,0,720,132,1,0,0,0,721,735,5,48,
  	0,0,722,732,7,0,0,0,723,725,3,265,132,0,724,723,1,0,0,0,724,725,1,0,0,
  	0,725,733,1,0,0,0,726,728,5,95,0,0,727,726,1,0,0,0,728,729,1,0,0,0,729,
  	727,1,0,0,0,729,730,1,0,0,0,730,731,1,0,0,0,731,733,3,265,132,0,732,724,
  	1,0,0,0,732,727,1,0,0,0,733,735,1,0,0,0,734,721,1,0,0,0,734,722,1,0,0,
  	0,735,737,1,0,0,0,736,738,7,1,0,0,737,736,1,0,0,0,737,738,1,0,0,0,738,
  	134,1,0,0,0,739,740,5,48,0,0,740,741,7,2,0,0,741,749,7,3,0,0,742,744,
  	7,4,0,0,743,742,1,0,0,0,744,747,1,0,0,0,745,743,1,0,0,0,745,746,1,0,0,
  	0,746,748,1,0,0,0,747,745,1,0,0,0,748,750,7,3,0,0,749,745,1,0,0,0,749,
  	750,1,0,0,0,750,752,1,0,0,0,751,753,7,1,0,0,752,751,1,0,0,0,752,753,1,
  	0,0,0,753,136,1,0,0,0,754,758,5,48,0,0,755,757,5,95,0,0,756,755,1,0,0,
  	0,757,760,1,0,0,0,758,756,1,0,0,0,758,759,1,0,0,0,759,761,1,0,0,0,760,
  	758,1,0,0,0,761,769,7,5,0,0,762,764,7,6,0,0,763,762,1,0,0,0,764,767,1,
  	0,0,0,765,763,1,0,0,0,765,766,1,0,0,0,766,768,1,0,0,0,767,765,1,0,0,0,
  	768,770,7,5,0,0,769,765,1,0,0,0,769,770,1,0,0,0,770,772,1,0,0,0,771,773,
  	7,1,0,0,772,771,1,0,0,0,772,773,1,0,0,0,773,138,1,0,0,0,774,775,5,48,
  	0,0,775,776,7,7,0,0,776,784,7,8,0,0,777,779,7,9,0,0,778,777,1,0,0,0,779,
  	782,1,0,0,0,780,778,1,0,0,0,780,781,1,0,0,0,781,783,1,0,0,0,782,780,1,
  	0,0,0,783,785,7,8,0,0,784,780,1,0,0,0,784,785,1,0,0,0,785,787,1,0,0,0,
  	786,788,7,1,0,0,787,786,1,0,0,0,787,788,1,0,0,0,788,140,1,0,0,0,789,790,
  	3,265,132,0,790,792,5,46,0,0,791,793,3,265,132,0,792,791,1,0,0,0,792,
  	793,1,0,0,0,793,797,1,0,0,0,794,795,5,46,0,0,795,797,3,265,132,0,796,
  	789,1,0,0,0,796,794,1,0,0,0,797,799,1,0,0,0,798,800,3,257,128,0,799,798,
  	1,0,0,0,799,800,1,0,0,0,800,802,1,0,0,0,801,803,7,10,0,0,802,801,1,0,
  	0,0,802,803,1,0,0,0,803,813,1,0,0,0,804,810,3,265,132,0,805,807,3,257,
  	128,0,806,808,7,10,0,0,807,806,1,0,0,0,807,808,1,0,0,0,808,811,1,0,0,
  	0,809,811,7,10,0,0,810,805,1,0,0,0,810,809,1,0,0,0,811,813,1,0,0,0,812,
  	796,1,0,0,0,812,804,1,0,0,0,813,142,1,0,0,0,814,815,5,48,0,0,815,825,
  	7,2,0,0,816,818,3,261,130,0,817,819,5,46,0,0,818,817,1,0,0,0,818,819,
  	1,0,0,0,819,826,1,0,0,0,820,822,3,261,130,0,821,820,1,0,0,0,821,822,1,
  	0,0,0,822,823,1,0,0,0,823,824,5,46,0,0,824,826,3,261,130,0,825,816,1,
  	0,0,0,825,821,1,0,0,0,826,827,1,0,0,0,827,829,7,11,0,0,828,830,7,12,0,
  	0,829,828,1,0,0,0,829,830,1,0,0,0,830,831,1,0,0,0,831,833,3,265,132,0,
  	832,834,7,10,0,0,833,832,1,0,0,0,833,834,1,0,0,0,834,144,1,0,0,0,835,
  	836,5,116,0,0,836,837,5,114,0,0,837,838,5,117,0,0,838,845,5,101,0,0,839,
  	840,5,102,0,0,840,841,5,97,0,0,841,842,5,108,0,0,842,843,5,115,0,0,843,
  	845,5,101,0,0,844,835,1,0,0,0,844,839,1,0,0,0,845,146,1,0,0,0,846,849,
  	5,39,0,0,847,850,8,13,0,0,848,850,3,259,129,0,849,847,1,0,0,0,849,848,
  	1,0,0,0,850,851,1,0,0,0,851,852,5,39,0,0,852,148,1,0,0,0,853,858,5,34,
  	0,0,854,857,8,14,0,0,855,857,3,259,129,0,856,854,1,0,0,0,856,855,1,0,
  	0,0,857,860,1,0,0,0,858,856,1,0,0,0,858,859,1,0,0,0,859,861,1,0,0,0,860,
  	858,1,0,0,0,861,862,5,34,0,0,862,150,1,0,0,0,863,864,5,34,0,0,864,865,
  	5,34,0,0,865,866,5,34,0,0,866,870,1,0,0,0,867,869,7,15,0,0,868,867,1,
  	0,0,0,869,872,1,0,0,0,870,868,1,0,0,0,870,871,1,0,0,0,871,873,1,0,0,0,
  	872,870,1,0,0,0,873,878,7,16,0,0,874,877,9,0,0,0,875,877,3,259,129,0,
  	876,874,1,0,0,0,876,875,1,0,0,0,877,880,1,0,0,0,878,879,1,0,0,0,878,876,
  	1,0,0,0,879,881,1,0,0,0,880,878,1,0,0,0,881,882,5,34,0,0,882,883,5,34,
  	0,0,883,884,5,34,0,0,884,152,1,0,0,0,885,886,5,110,0,0,886,887,5,117,
  	0,0,887,888,5,108,0,0,888,889,5,108,0,0,889,154,1,0,0,0,890,891,5,40,
  	0,0,891,156,1,0,0,0,892,893,5,41,0,0,893,158,1,0,0,0,894,895,5,123,0,
  	0,895,160,1,0,0,0,896,897,5,125,0,0,897,162,1,0,0,0,898,899,5,91,0,0,
  	899,164,1,0,0,0,900,901,5,93,0,0,901,166,1,0,0,0,902,903,5,59,0,0,903,
  	168,1,0,0,0,904,905,5,44,0,0,905,170,1,0,0,0,906,907,5,46,0,0,907,172,
  	1,0,0,0,908,909,5,61,0,0,909,174,1,0,0,0,910,911,5,62,0,0,911,176,1,0,
  	0,0,912,913,5,60,0,0,913,178,1,0,0,0,914,915,5,33,0,0,915,180,1,0,0,0,
  	916,917,5,126,0,0,917,182,1,0,0,0,918,919,5,63,0,0,919,184,1,0,0,0,920,
  	921,5,58,0,0,921,186,1,0,0,0,922,923,5,61,0,0,923,924,5,61,0,0,924,188,
  	1,0,0,0,925,926,5,60,0,0,926,927,5,61,0,0,927,190,1,0,0,0,928,929,5,62,
  	0,0,929,930,5,61,0,0,930,192,1,0,0,0,931,932,5,33,0,0,932,933,5,61,0,
  	0,933,194,1,0,0,0,934,935,5,38,0,0,935,936,5,38,0,0,936,196,1,0,0,0,937,
  	938,5,124,0,0,938,939,5,124,0,0,939,198,1,0,0,0,940,941,5,43,0,0,941,
  	942,5,43,0,0,942,200,1,0,0,0,943,944,5,45,0,0,944,945,5,45,0,0,945,202,
  	1,0,0,0,946,947,5,43,0,0,947,204,1,0,0,0,948,949,5,45,0,0,949,206,1,0,
  	0,0,950,951,5,42,0,0,951,208,1,0,0,0,952,953,5,47,0,0,953,210,1,0,0,0,
  	954,955,5,38,0,0,955,212,1,0,0,0,956,957,5,124,0,0,957,214,1,0,0,0,958,
  	959,5,94,0,0,959,216,1,0,0,0,960,961,5,37,0,0,961,218,1,0,0,0,962,963,
  	5,43,0,0,963,964,5,61,0,0,964,220,1,0,0,0,965,966,5,45,0,0,966,967,5,
  	61,0,0,967,222,1,0,0,0,968,969,5,42,0,0,969,970,5,61,0,0,970,224,1,0,
  	0,0,971,972,5,47,0,0,972,973,5,61,0,0,973,226,1,0,0,0,974,975,5,38,0,
  	0,975,976,5,61,0,0,976,228,1,0,0,0,977,978,5,124,0,0,978,979,5,61,0,0,
  	979,230,1,0,0,0,980,981,5,94,0,0,981,982,5,61,0,0,982,232,1,0,0,0,983,
  	984,5,37,0,0,984,985,5,61,0,0,985,234,1,0,0,0,986,987,5,60,0,0,987,988,
  	5,60,0,0,988,989,5,61,0,0,989,236,1,0,0,0,990,991,5,62,0,0,991,992,5,
  	62,0,0,992,993,5,61,0,0,993,238,1,0,0,0,994,995,5,62,0,0,995,996,5,62,
  	0,0,996,997,5,62,0,0,997,998,5,61,0,0,998,240,1,0,0,0,999,1000,5,45,0,
  	0,1000,1001,5,62,0,0,1001,242,1,0,0,0,1002,1003,5,58,0,0,1003,1004,5,
  	58,0,0,1004,244,1,0,0,0,1005,1006,5,64,0,0,1006,246,1,0,0,0,1007,1008,
  	5,46,0,0,1008,1009,5,46,0,0,1009,1010,5,46,0,0,1010,248,1,0,0,0,1011,
  	1013,7,17,0,0,1012,1011,1,0,0,0,1013,1014,1,0,0,0,1014,1012,1,0,0,0,1014,
  	1015,1,0,0,0,1015,1016,1,0,0,0,1016,1017,6,124,0,0,1017,250,1,0,0,0,1018,
  	1019,5,47,0,0,1019,1020,5,42,0,0,1020,1024,1,0,0,0,1021,1023,9,0,0,0,
  	1022,1021,1,0,0,0,1023,1026,1,0,0,0,1024,1025,1,0,0,0,1024,1022,1,0,0,
  	0,1025,1027,1,0,0,0,1026,1024,1,0,0,0,1027,1028,5,42,0,0,1028,1029,5,
  	47,0,0,1029,1030,1,0,0,0,1030,1031,6,125,0,0,1031,252,1,0,0,0,1032,1033,
  	5,47,0,0,1033,1034,5,47,0,0,1034,1038,1,0,0,0,1035,1037,8,16,0,0,1036,
  	1035,1,0,0,0,1037,1040,1,0,0,0,1038,1036,1,0,0,0,1038,1039,1,0,0,0,1039,
  	1041,1,0,0,0,1040,1038,1,0,0,0,1041,1042,6,126,0,0,1042,254,1,0,0,0,1043,
  	1047,3,269,134,0,1044,1046,3,267,133,0,1045,1044,1,0,0,0,1046,1049,1,
  	0,0,0,1047,1045,1,0,0,0,1047,1048,1,0,0,0,1048,256,1,0,0,0,1049,1047,
  	1,0,0,0,1050,1052,7,18,0,0,1051,1053,7,12,0,0,1052,1051,1,0,0,0,1052,
  	1053,1,0,0,0,1053,1054,1,0,0,0,1054,1055,3,265,132,0,1055,258,1,0,0,0,
  	1056,1057,5,92,0,0,1057,1078,7,19,0,0,1058,1063,5,92,0,0,1059,1061,7,
  	20,0,0,1060,1059,1,0,0,0,1060,1061,1,0,0,0,1061,1062,1,0,0,0,1062,1064,
  	7,5,0,0,1063,1060,1,0,0,0,1063,1064,1,0,0,0,1064,1065,1,0,0,0,1065,1078,
  	7,5,0,0,1066,1068,5,92,0,0,1067,1069,5,117,0,0,1068,1067,1,0,0,0,1069,
  	1070,1,0,0,0,1070,1068,1,0,0,0,1070,1071,1,0,0,0,1071,1072,1,0,0,0,1072,
  	1073,3,263,131,0,1073,1074,3,263,131,0,1074,1075,3,263,131,0,1075,1076,
  	3,263,131,0,1076,1078,1,0,0,0,1077,1056,1,0,0,0,1077,1058,1,0,0,0,1077,
  	1066,1,0,0,0,1078,260,1,0,0,0,1079,1088,3,263,131,0,1080,1083,3,263,131,
  	0,1081,1083,5,95,0,0,1082,1080,1,0,0,0,1082,1081,1,0,0,0,1083,1086,1,
  	0,0,0,1084,1082,1,0,0,0,1084,1085,1,0,0,0,1085,1087,1,0,0,0,1086,1084,
  	1,0,0,0,1087,1089,3,263,131,0,1088,1084,1,0,0,0,1088,1089,1,0,0,0,1089,
  	262,1,0,0,0,1090,1091,7,3,0,0,1091,264,1,0,0,0,1092,1100,7,21,0,0,1093,
  	1095,7,22,0,0,1094,1093,1,0,0,0,1095,1098,1,0,0,0,1096,1094,1,0,0,0,1096,
  	1097,1,0,0,0,1097,1099,1,0,0,0,1098,1096,1,0,0,0,1099,1101,7,21,0,0,1100,
  	1096,1,0,0,0,1100,1101,1,0,0,0,1101,266,1,0,0,0,1102,1105,3,269,134,0,
  	1103,1105,7,21,0,0,1104,1102,1,0,0,0,1104,1103,1,0,0,0,1105,268,1,0,0,
  	0,1106,1111,7,23,0,0,1107,1111,8,24,0,0,1108,1109,7,25,0,0,1109,1111,
  	7,26,0,0,1110,1106,1,0,0,0,1110,1107,1,0,0,0,1110,1108,1,0,0,0,1111,270,
  	1,0,0,0,51,0,724,729,732,734,737,745,749,752,758,765,769,772,780,784,
  	787,792,796,799,802,807,810,812,818,821,825,829,833,844,849,856,858,870,
  	876,878,1014,1024,1038,1047,1052,1060,1063,1070,1077,1082,1084,1088,1096,
  	1100,1104,1110,1,0,1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  javalexerLexerStaticData = staticData.release();
}

}

JavaLexer::JavaLexer(CharStream *input) : Lexer(input) {
  JavaLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *javalexerLexerStaticData->atn, javalexerLexerStaticData->decisionToDFA, javalexerLexerStaticData->sharedContextCache);
}

JavaLexer::~JavaLexer() {
  delete _interpreter;
}

std::string JavaLexer::getGrammarFileName() const {
  return "JavaLexer.g4";
}

const std::vector<std::string>& JavaLexer::getRuleNames() const {
  return javalexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& JavaLexer::getChannelNames() const {
  return javalexerLexerStaticData->channelNames;
}

const std::vector<std::string>& JavaLexer::getModeNames() const {
  return javalexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& JavaLexer::getVocabulary() const {
  return javalexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView JavaLexer::getSerializedATN() const {
  return javalexerLexerStaticData->serializedATN;
}

const atn::ATN& JavaLexer::getATN() const {
  return *javalexerLexerStaticData->atn;
}




void JavaLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  javalexerLexerInitialize();
#else
  ::antlr4::internal::call_once(javalexerLexerOnceFlag, javalexerLexerInitialize);
#endif
}
