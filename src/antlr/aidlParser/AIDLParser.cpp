
// Generated from AIDLParser.g4 by ANTLR 4.13.1


#include "AIDLParserVisitor.h"

#include "AIDLParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct AIDLParserStaticData final {
  AIDLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AIDLParserStaticData(const AIDLParserStaticData&) = delete;
  AIDLParserStaticData(AIDLParserStaticData&&) = delete;
  AIDLParserStaticData& operator=(const AIDLParserStaticData&) = delete;
  AIDLParserStaticData& operator=(AIDLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag aidlparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
AIDLParserStaticData *aidlparserParserStaticData = nullptr;

void aidlparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (aidlparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(aidlparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AIDLParserStaticData>(
    std::vector<std::string>{
      "compilationUnit", "identifier", "optional_package", "imports", "importI", 
      "qualified_name", "decls", "decl", "unannotated_decl", "type_params", 
      "optional_type_params", "optional_unstructured_headers", "parcelable_decl", 
      "parcelable_members", "variable_decl", "interface_decl", "interface_members", 
      "const_expr", "constant_value_list", "constant_value_non_empty_list", 
      "constant_decl", "enumerator", "enumerators", "enum_decl_body", "enum_decl", 
      "union_decl", "method_decl", "arg_non_empty_list", "arg", "non_array_type", 
      "type", "type_args", "annotation_list", "parameter", "parameter_non_empty_list", 
      "annotation", "direction"
    },
    std::vector<std::string>{
      "", "'abstract'", "'const'", "'enum'", "'extends'", "'implements'", 
      "'import'", "'interface'", "'package'", "'private'", "'protected'", 
      "'public'", "'return'", "'static'", "'void'", "'parcelable'", "'in'", 
      "'out'", "'inout'", "'oneway'", "'cpp_header'", "'ndk_header'", "'rust_type'", 
      "", "'union'", "'var'", "'yield'", "'record'", "'sealed'", "'permits'", 
      "'non-sealed'", "", "", "", "", "", "", "'true'", "'false'", "", "", 
      "", "'null'", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", 
      "'.'", "'='", "'>'", "'<'", "'!'", "'~'", "'\\u003F'", "':'", "'=='", 
      "'<='", "'>='", "'!='", "'&&'", "'||'", "'++'", "'--'", "'+'", "'-'", 
      "'*'", "'/'", "'&'", "'|'", "'^'", "'%'", "'<<'", "'>>'", "'+='", 
      "'-='", "'*='", "'/='", "'&='", "'|='", "'^='", "'%='", "'<<='", "'>>='", 
      "'>>>='", "'->'", "'::'", "'...'"
    },
    std::vector<std::string>{
      "", "ABSTRACT", "CONST", "ENUM", "EXTENDS", "IMPLEMENTS", "IMPORT", 
      "INTERFACE", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", 
      "STATIC", "VOID", "PARCELABLE", "IN", "OUT", "INOUT", "ONEWAY", "CPP_HEADER", 
      "NDK_HEADER", "RUST_TYPE", "ANNOTATION", "UNION", "VAR", "YIELD", 
      "RECORD", "SEALED", "PERMITS", "NON_SEALED", "INTVALUE", "HEXVALUE", 
      "OCT_LITERAL", "BINARY_LITERAL", "FLOATVALUE", "HEX_FLOAT_LITERAL", 
      "TRUE_LITERAL", "FALSE_LITERAL", "CHARVALUE", "C_STR", "TEXT_BLOCK", 
      "NULL_LITERAL", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", 
      "RBRACK", "SEMI", "COMMA", "DOT", "ASSIGN", "GT", "LT", "BANG", "TILDE", 
      "QUESTION", "COLON", "EQUALITY", "LEQ", "GEQ", "NEQ", "LOGICAL_AND", 
      "LOGICAL_OR", "UNARY_PLUS", "UNARY_MINUS", "ADD", "SUB", "MUL", "DIV", 
      "BITAND", "BITOR", "CARET", "MOD", "LSHIFT", "RSHIFT", "ADD_ASSIGN", 
      "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", 
      "XOR_ASSIGN", "MOD_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "URSHIFT_ASSIGN", 
      "ARROW", "COLONCOLON", "ELLIPSIS", "WS", "COMMENT", "LINE_COMMENT", 
      "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,94,447,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,1,0,3,0,76,8,0,1,0,3,0,79,8,0,1,0,1,0,1,1,1,1,1,2,1,2,1,
  	2,1,2,1,3,4,3,90,8,3,11,3,12,3,91,1,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,101,
  	8,5,10,5,12,5,104,9,5,1,6,4,6,107,8,6,11,6,12,6,108,1,7,1,7,1,7,1,8,1,
  	8,1,8,1,8,3,8,118,8,8,1,9,1,9,1,9,5,9,123,8,9,10,9,12,9,126,9,9,1,10,
  	1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,5,11,138,8,11,10,11,12,11,
  	141,9,11,1,12,1,12,1,12,3,12,146,8,12,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	12,3,12,155,8,12,1,13,1,13,1,13,5,13,160,8,13,10,13,12,13,163,9,13,1,
  	14,1,14,1,14,1,14,3,14,169,8,14,1,14,1,14,1,15,3,15,174,8,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,3,15,183,8,15,1,16,1,16,1,16,5,16,188,8,16,10,
  	16,12,16,191,9,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,3,17,204,8,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,3,17,219,8,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,5,17,275,8,17,10,17,12,17,278,9,17,1,18,1,18,3,18,282,
  	8,18,1,19,1,19,1,19,5,19,287,8,19,10,19,12,19,290,9,19,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,3,21,303,8,21,1,22,1,22,1,22,
  	5,22,308,8,22,10,22,12,22,311,9,22,1,23,1,23,1,23,3,23,316,8,23,1,23,
  	1,23,1,24,1,24,1,24,1,24,1,25,1,25,1,25,3,25,327,8,25,1,25,1,25,1,25,
  	1,25,1,26,1,26,3,26,335,8,26,1,26,1,26,1,26,1,26,3,26,341,8,26,1,26,1,
  	26,1,26,3,26,346,8,26,1,26,1,26,1,27,1,27,1,27,5,27,353,8,27,10,27,12,
  	27,356,9,27,1,28,3,28,359,8,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,5,29,384,8,29,10,29,12,29,387,9,29,1,30,1,30,1,30,1,30,1,30,1,30,
  	1,30,1,30,1,30,1,30,5,30,399,8,30,10,30,12,30,402,9,30,1,30,3,30,405,
  	8,30,1,31,1,31,1,31,5,31,410,8,31,10,31,12,31,413,9,31,1,32,5,32,416,
  	8,32,10,32,12,32,419,9,32,1,33,1,33,1,33,1,33,1,34,1,34,1,34,5,34,428,
  	8,34,10,34,12,34,431,9,34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,3,35,440,
  	8,35,1,35,3,35,443,8,35,1,36,1,36,1,36,0,1,34,37,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,
  	64,66,68,70,72,0,2,2,0,20,22,94,94,1,0,16,18,487,0,75,1,0,0,0,2,82,1,
  	0,0,0,4,84,1,0,0,0,6,89,1,0,0,0,8,93,1,0,0,0,10,97,1,0,0,0,12,106,1,0,
  	0,0,14,110,1,0,0,0,16,117,1,0,0,0,18,119,1,0,0,0,20,127,1,0,0,0,22,139,
  	1,0,0,0,24,142,1,0,0,0,26,161,1,0,0,0,28,164,1,0,0,0,30,173,1,0,0,0,32,
  	189,1,0,0,0,34,218,1,0,0,0,36,279,1,0,0,0,38,283,1,0,0,0,40,291,1,0,0,
  	0,42,299,1,0,0,0,44,304,1,0,0,0,46,312,1,0,0,0,48,319,1,0,0,0,50,323,
  	1,0,0,0,52,332,1,0,0,0,54,349,1,0,0,0,56,358,1,0,0,0,58,363,1,0,0,0,60,
  	404,1,0,0,0,62,406,1,0,0,0,64,417,1,0,0,0,66,420,1,0,0,0,68,424,1,0,0,
  	0,70,432,1,0,0,0,72,444,1,0,0,0,74,76,3,4,2,0,75,74,1,0,0,0,75,76,1,0,
  	0,0,76,78,1,0,0,0,77,79,3,6,3,0,78,77,1,0,0,0,78,79,1,0,0,0,79,80,1,0,
  	0,0,80,81,3,12,6,0,81,1,1,0,0,0,82,83,7,0,0,0,83,3,1,0,0,0,84,85,5,8,
  	0,0,85,86,3,10,5,0,86,87,5,49,0,0,87,5,1,0,0,0,88,90,3,8,4,0,89,88,1,
  	0,0,0,90,91,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,7,1,0,0,0,93,94,5,
  	6,0,0,94,95,3,10,5,0,95,96,5,49,0,0,96,9,1,0,0,0,97,102,3,2,1,0,98,99,
  	5,51,0,0,99,101,3,2,1,0,100,98,1,0,0,0,101,104,1,0,0,0,102,100,1,0,0,
  	0,102,103,1,0,0,0,103,11,1,0,0,0,104,102,1,0,0,0,105,107,3,14,7,0,106,
  	105,1,0,0,0,107,108,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,13,1,
  	0,0,0,110,111,3,64,32,0,111,112,3,16,8,0,112,15,1,0,0,0,113,118,3,24,
  	12,0,114,118,3,30,15,0,115,118,3,48,24,0,116,118,3,50,25,0,117,113,1,
  	0,0,0,117,114,1,0,0,0,117,115,1,0,0,0,117,116,1,0,0,0,118,17,1,0,0,0,
  	119,124,3,2,1,0,120,121,5,50,0,0,121,123,3,2,1,0,122,120,1,0,0,0,123,
  	126,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,19,1,0,0,0,126,124,1,
  	0,0,0,127,128,5,54,0,0,128,129,3,18,9,0,129,130,5,53,0,0,130,21,1,0,0,
  	0,131,132,5,20,0,0,132,138,5,40,0,0,133,134,5,21,0,0,134,138,5,40,0,0,
  	135,136,5,22,0,0,136,138,5,40,0,0,137,131,1,0,0,0,137,133,1,0,0,0,137,
  	135,1,0,0,0,138,141,1,0,0,0,139,137,1,0,0,0,139,140,1,0,0,0,140,23,1,
  	0,0,0,141,139,1,0,0,0,142,143,5,15,0,0,143,145,3,10,5,0,144,146,3,20,
  	10,0,145,144,1,0,0,0,145,146,1,0,0,0,146,154,1,0,0,0,147,148,3,22,11,
  	0,148,149,5,49,0,0,149,155,1,0,0,0,150,151,5,45,0,0,151,152,3,26,13,0,
  	152,153,5,46,0,0,153,155,1,0,0,0,154,147,1,0,0,0,154,150,1,0,0,0,155,
  	25,1,0,0,0,156,160,3,28,14,0,157,160,3,40,20,0,158,160,3,14,7,0,159,156,
  	1,0,0,0,159,157,1,0,0,0,159,158,1,0,0,0,160,163,1,0,0,0,161,159,1,0,0,
  	0,161,162,1,0,0,0,162,27,1,0,0,0,163,161,1,0,0,0,164,165,3,60,30,0,165,
  	168,3,2,1,0,166,167,5,52,0,0,167,169,3,34,17,0,168,166,1,0,0,0,168,169,
  	1,0,0,0,169,170,1,0,0,0,170,171,5,49,0,0,171,29,1,0,0,0,172,174,5,19,
  	0,0,173,172,1,0,0,0,173,174,1,0,0,0,174,175,1,0,0,0,175,176,5,7,0,0,176,
  	182,3,10,5,0,177,183,5,49,0,0,178,179,5,45,0,0,179,180,3,32,16,0,180,
  	181,5,46,0,0,181,183,1,0,0,0,182,177,1,0,0,0,182,178,1,0,0,0,183,31,1,
  	0,0,0,184,188,3,52,26,0,185,188,3,40,20,0,186,188,3,14,7,0,187,184,1,
  	0,0,0,187,185,1,0,0,0,187,186,1,0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,
  	189,190,1,0,0,0,190,33,1,0,0,0,191,189,1,0,0,0,192,193,6,17,-1,0,193,
  	219,5,37,0,0,194,219,5,38,0,0,195,219,5,39,0,0,196,219,5,31,0,0,197,219,
  	5,35,0,0,198,219,5,32,0,0,199,219,5,40,0,0,200,219,3,10,5,0,201,203,5,
  	45,0,0,202,204,3,36,18,0,203,202,1,0,0,0,203,204,1,0,0,0,204,205,1,0,
  	0,0,205,219,5,46,0,0,206,207,5,67,0,0,207,219,3,34,17,5,208,209,5,68,
  	0,0,209,219,3,34,17,4,210,211,5,55,0,0,211,219,3,34,17,3,212,213,5,56,
  	0,0,213,219,3,34,17,2,214,215,5,43,0,0,215,216,3,34,17,0,216,217,5,44,
  	0,0,217,219,1,0,0,0,218,192,1,0,0,0,218,194,1,0,0,0,218,195,1,0,0,0,218,
  	196,1,0,0,0,218,197,1,0,0,0,218,198,1,0,0,0,218,199,1,0,0,0,218,200,1,
  	0,0,0,218,201,1,0,0,0,218,206,1,0,0,0,218,208,1,0,0,0,218,210,1,0,0,0,
  	218,212,1,0,0,0,218,214,1,0,0,0,219,276,1,0,0,0,220,221,10,23,0,0,221,
  	222,5,64,0,0,222,275,3,34,17,24,223,224,10,22,0,0,224,225,5,63,0,0,225,
  	275,3,34,17,23,226,227,10,21,0,0,227,228,5,72,0,0,228,275,3,34,17,22,
  	229,230,10,20,0,0,230,231,5,73,0,0,231,275,3,34,17,21,232,233,10,19,0,
  	0,233,234,5,71,0,0,234,275,3,34,17,20,235,236,10,18,0,0,236,237,5,59,
  	0,0,237,275,3,34,17,19,238,239,10,17,0,0,239,240,5,62,0,0,240,275,3,34,
  	17,18,241,242,10,16,0,0,242,243,5,54,0,0,243,275,3,34,17,17,244,245,10,
  	15,0,0,245,246,5,53,0,0,246,275,3,34,17,16,247,248,10,14,0,0,248,249,
  	5,60,0,0,249,275,3,34,17,15,250,251,10,13,0,0,251,252,5,61,0,0,252,275,
  	3,34,17,14,253,254,10,12,0,0,254,255,5,75,0,0,255,275,3,34,17,13,256,
  	257,10,11,0,0,257,258,5,76,0,0,258,275,3,34,17,12,259,260,10,10,0,0,260,
  	261,5,67,0,0,261,275,3,34,17,11,262,263,10,9,0,0,263,264,5,68,0,0,264,
  	275,3,34,17,10,265,266,10,8,0,0,266,267,5,69,0,0,267,275,3,34,17,9,268,
  	269,10,7,0,0,269,270,5,70,0,0,270,275,3,34,17,8,271,272,10,6,0,0,272,
  	273,5,74,0,0,273,275,3,34,17,7,274,220,1,0,0,0,274,223,1,0,0,0,274,226,
  	1,0,0,0,274,229,1,0,0,0,274,232,1,0,0,0,274,235,1,0,0,0,274,238,1,0,0,
  	0,274,241,1,0,0,0,274,244,1,0,0,0,274,247,1,0,0,0,274,250,1,0,0,0,274,
  	253,1,0,0,0,274,256,1,0,0,0,274,259,1,0,0,0,274,262,1,0,0,0,274,265,1,
  	0,0,0,274,268,1,0,0,0,274,271,1,0,0,0,275,278,1,0,0,0,276,274,1,0,0,0,
  	276,277,1,0,0,0,277,35,1,0,0,0,278,276,1,0,0,0,279,281,3,38,19,0,280,
  	282,5,50,0,0,281,280,1,0,0,0,281,282,1,0,0,0,282,37,1,0,0,0,283,288,3,
  	34,17,0,284,285,5,50,0,0,285,287,3,34,17,0,286,284,1,0,0,0,287,290,1,
  	0,0,0,288,286,1,0,0,0,288,289,1,0,0,0,289,39,1,0,0,0,290,288,1,0,0,0,
  	291,292,3,64,32,0,292,293,5,2,0,0,293,294,3,60,30,0,294,295,3,2,1,0,295,
  	296,5,52,0,0,296,297,3,34,17,0,297,298,5,49,0,0,298,41,1,0,0,0,299,302,
  	3,2,1,0,300,301,5,52,0,0,301,303,3,34,17,0,302,300,1,0,0,0,302,303,1,
  	0,0,0,303,43,1,0,0,0,304,309,3,42,21,0,305,306,5,50,0,0,306,308,3,42,
  	21,0,307,305,1,0,0,0,308,311,1,0,0,0,309,307,1,0,0,0,309,310,1,0,0,0,
  	310,45,1,0,0,0,311,309,1,0,0,0,312,313,5,45,0,0,313,315,3,44,22,0,314,
  	316,5,50,0,0,315,314,1,0,0,0,315,316,1,0,0,0,316,317,1,0,0,0,317,318,
  	5,46,0,0,318,47,1,0,0,0,319,320,5,3,0,0,320,321,3,10,5,0,321,322,3,46,
  	23,0,322,49,1,0,0,0,323,324,5,24,0,0,324,326,3,10,5,0,325,327,3,20,10,
  	0,326,325,1,0,0,0,326,327,1,0,0,0,327,328,1,0,0,0,328,329,5,45,0,0,329,
  	330,3,26,13,0,330,331,5,46,0,0,331,51,1,0,0,0,332,334,3,64,32,0,333,335,
  	5,19,0,0,334,333,1,0,0,0,334,335,1,0,0,0,335,336,1,0,0,0,336,337,3,60,
  	30,0,337,338,3,2,1,0,338,340,5,43,0,0,339,341,3,54,27,0,340,339,1,0,0,
  	0,340,341,1,0,0,0,341,342,1,0,0,0,342,345,5,44,0,0,343,344,5,52,0,0,344,
  	346,5,31,0,0,345,343,1,0,0,0,345,346,1,0,0,0,346,347,1,0,0,0,347,348,
  	5,49,0,0,348,53,1,0,0,0,349,354,3,56,28,0,350,351,5,50,0,0,351,353,3,
  	56,28,0,352,350,1,0,0,0,353,356,1,0,0,0,354,352,1,0,0,0,354,355,1,0,0,
  	0,355,55,1,0,0,0,356,354,1,0,0,0,357,359,3,72,36,0,358,357,1,0,0,0,358,
  	359,1,0,0,0,359,360,1,0,0,0,360,361,3,60,30,0,361,362,3,2,1,0,362,57,
  	1,0,0,0,363,364,3,64,32,0,364,385,3,10,5,0,365,366,5,54,0,0,366,367,3,
  	62,31,0,367,368,5,53,0,0,368,384,1,0,0,0,369,370,5,54,0,0,370,371,3,58,
  	29,0,371,372,5,54,0,0,372,373,3,62,31,0,373,374,5,76,0,0,374,384,1,0,
  	0,0,375,376,5,54,0,0,376,377,3,62,31,0,377,378,5,50,0,0,378,379,3,58,
  	29,0,379,380,5,54,0,0,380,381,3,62,31,0,381,382,5,76,0,0,382,384,1,0,
  	0,0,383,365,1,0,0,0,383,369,1,0,0,0,383,375,1,0,0,0,384,387,1,0,0,0,385,
  	383,1,0,0,0,385,386,1,0,0,0,386,59,1,0,0,0,387,385,1,0,0,0,388,400,3,
  	58,29,0,389,390,3,64,32,0,390,391,5,47,0,0,391,392,5,48,0,0,392,399,1,
  	0,0,0,393,394,3,64,32,0,394,395,5,47,0,0,395,396,3,34,17,0,396,397,5,
  	48,0,0,397,399,1,0,0,0,398,389,1,0,0,0,398,393,1,0,0,0,399,402,1,0,0,
  	0,400,398,1,0,0,0,400,401,1,0,0,0,401,405,1,0,0,0,402,400,1,0,0,0,403,
  	405,5,14,0,0,404,388,1,0,0,0,404,403,1,0,0,0,405,61,1,0,0,0,406,411,3,
  	60,30,0,407,408,5,50,0,0,408,410,3,60,30,0,409,407,1,0,0,0,410,413,1,
  	0,0,0,411,409,1,0,0,0,411,412,1,0,0,0,412,63,1,0,0,0,413,411,1,0,0,0,
  	414,416,3,70,35,0,415,414,1,0,0,0,416,419,1,0,0,0,417,415,1,0,0,0,417,
  	418,1,0,0,0,418,65,1,0,0,0,419,417,1,0,0,0,420,421,3,2,1,0,421,422,5,
  	52,0,0,422,423,3,34,17,0,423,67,1,0,0,0,424,429,3,66,33,0,425,426,5,50,
  	0,0,426,428,3,66,33,0,427,425,1,0,0,0,428,431,1,0,0,0,429,427,1,0,0,0,
  	429,430,1,0,0,0,430,69,1,0,0,0,431,429,1,0,0,0,432,442,5,23,0,0,433,434,
  	5,43,0,0,434,435,3,34,17,0,435,436,5,44,0,0,436,443,1,0,0,0,437,439,5,
  	43,0,0,438,440,3,68,34,0,439,438,1,0,0,0,439,440,1,0,0,0,440,441,1,0,
  	0,0,441,443,5,44,0,0,442,433,1,0,0,0,442,437,1,0,0,0,442,443,1,0,0,0,
  	443,71,1,0,0,0,444,445,7,1,0,0,445,73,1,0,0,0,43,75,78,91,102,108,117,
  	124,137,139,145,154,159,161,168,173,182,187,189,203,218,274,276,281,288,
  	302,309,315,326,334,340,345,354,358,383,385,398,400,404,411,417,429,439,
  	442
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  aidlparserParserStaticData = staticData.release();
}

}

AIDLParser::AIDLParser(TokenStream *input) : AIDLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

AIDLParser::AIDLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  AIDLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *aidlparserParserStaticData->atn, aidlparserParserStaticData->decisionToDFA, aidlparserParserStaticData->sharedContextCache, options);
}

AIDLParser::~AIDLParser() {
  delete _interpreter;
}

const atn::ATN& AIDLParser::getATN() const {
  return *aidlparserParserStaticData->atn;
}

std::string AIDLParser::getGrammarFileName() const {
  return "AIDLParser.g4";
}

const std::vector<std::string>& AIDLParser::getRuleNames() const {
  return aidlparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& AIDLParser::getVocabulary() const {
  return aidlparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AIDLParser::getSerializedATN() const {
  return aidlparserParserStaticData->serializedATN;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

AIDLParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::DeclsContext* AIDLParser::CompilationUnitContext::decls() {
  return getRuleContext<AIDLParser::DeclsContext>(0);
}

AIDLParser::Optional_packageContext* AIDLParser::CompilationUnitContext::optional_package() {
  return getRuleContext<AIDLParser::Optional_packageContext>(0);
}

AIDLParser::ImportsContext* AIDLParser::CompilationUnitContext::imports() {
  return getRuleContext<AIDLParser::ImportsContext>(0);
}


size_t AIDLParser::CompilationUnitContext::getRuleIndex() const {
  return AIDLParser::RuleCompilationUnit;
}


std::any AIDLParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::CompilationUnitContext* AIDLParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, AIDLParser::RuleCompilationUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::PACKAGE) {
      setState(74);
      optional_package();
    }
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::IMPORT) {
      setState(77);
      imports();
    }
    setState(80);
    decls();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

AIDLParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::IdentifierContext::IDENTIFIER() {
  return getToken(AIDLParser::IDENTIFIER, 0);
}

tree::TerminalNode* AIDLParser::IdentifierContext::CPP_HEADER() {
  return getToken(AIDLParser::CPP_HEADER, 0);
}

tree::TerminalNode* AIDLParser::IdentifierContext::NDK_HEADER() {
  return getToken(AIDLParser::NDK_HEADER, 0);
}

tree::TerminalNode* AIDLParser::IdentifierContext::RUST_TYPE() {
  return getToken(AIDLParser::RUST_TYPE, 0);
}


size_t AIDLParser::IdentifierContext::getRuleIndex() const {
  return AIDLParser::RuleIdentifier;
}


std::any AIDLParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::IdentifierContext* AIDLParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 2, AIDLParser::RuleIdentifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7340032) != 0) || _la == AIDLParser::IDENTIFIER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Optional_packageContext ------------------------------------------------------------------

AIDLParser::Optional_packageContext::Optional_packageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::Optional_packageContext::PACKAGE() {
  return getToken(AIDLParser::PACKAGE, 0);
}

AIDLParser::Qualified_nameContext* AIDLParser::Optional_packageContext::qualified_name() {
  return getRuleContext<AIDLParser::Qualified_nameContext>(0);
}

tree::TerminalNode* AIDLParser::Optional_packageContext::SEMI() {
  return getToken(AIDLParser::SEMI, 0);
}


size_t AIDLParser::Optional_packageContext::getRuleIndex() const {
  return AIDLParser::RuleOptional_package;
}


std::any AIDLParser::Optional_packageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitOptional_package(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Optional_packageContext* AIDLParser::optional_package() {
  Optional_packageContext *_localctx = _tracker.createInstance<Optional_packageContext>(_ctx, getState());
  enterRule(_localctx, 4, AIDLParser::RuleOptional_package);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(AIDLParser::PACKAGE);
    setState(85);
    qualified_name();
    setState(86);
    match(AIDLParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportsContext ------------------------------------------------------------------

AIDLParser::ImportsContext::ImportsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::ImportIContext *> AIDLParser::ImportsContext::importI() {
  return getRuleContexts<AIDLParser::ImportIContext>();
}

AIDLParser::ImportIContext* AIDLParser::ImportsContext::importI(size_t i) {
  return getRuleContext<AIDLParser::ImportIContext>(i);
}


size_t AIDLParser::ImportsContext::getRuleIndex() const {
  return AIDLParser::RuleImports;
}


std::any AIDLParser::ImportsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitImports(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::ImportsContext* AIDLParser::imports() {
  ImportsContext *_localctx = _tracker.createInstance<ImportsContext>(_ctx, getState());
  enterRule(_localctx, 6, AIDLParser::RuleImports);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(88);
      importI();
      setState(91); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AIDLParser::IMPORT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportIContext ------------------------------------------------------------------

AIDLParser::ImportIContext::ImportIContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::ImportIContext::IMPORT() {
  return getToken(AIDLParser::IMPORT, 0);
}

AIDLParser::Qualified_nameContext* AIDLParser::ImportIContext::qualified_name() {
  return getRuleContext<AIDLParser::Qualified_nameContext>(0);
}

tree::TerminalNode* AIDLParser::ImportIContext::SEMI() {
  return getToken(AIDLParser::SEMI, 0);
}


size_t AIDLParser::ImportIContext::getRuleIndex() const {
  return AIDLParser::RuleImportI;
}


std::any AIDLParser::ImportIContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitImportI(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::ImportIContext* AIDLParser::importI() {
  ImportIContext *_localctx = _tracker.createInstance<ImportIContext>(_ctx, getState());
  enterRule(_localctx, 8, AIDLParser::RuleImportI);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(AIDLParser::IMPORT);
    setState(94);
    qualified_name();
    setState(95);
    match(AIDLParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_nameContext ------------------------------------------------------------------

AIDLParser::Qualified_nameContext::Qualified_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::IdentifierContext *> AIDLParser::Qualified_nameContext::identifier() {
  return getRuleContexts<AIDLParser::IdentifierContext>();
}

AIDLParser::IdentifierContext* AIDLParser::Qualified_nameContext::identifier(size_t i) {
  return getRuleContext<AIDLParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::Qualified_nameContext::DOT() {
  return getTokens(AIDLParser::DOT);
}

tree::TerminalNode* AIDLParser::Qualified_nameContext::DOT(size_t i) {
  return getToken(AIDLParser::DOT, i);
}


size_t AIDLParser::Qualified_nameContext::getRuleIndex() const {
  return AIDLParser::RuleQualified_name;
}


std::any AIDLParser::Qualified_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitQualified_name(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Qualified_nameContext* AIDLParser::qualified_name() {
  Qualified_nameContext *_localctx = _tracker.createInstance<Qualified_nameContext>(_ctx, getState());
  enterRule(_localctx, 10, AIDLParser::RuleQualified_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(97);
    identifier();
    setState(102);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(98);
        match(AIDLParser::DOT);
        setState(99);
        identifier(); 
      }
      setState(104);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclsContext ------------------------------------------------------------------

AIDLParser::DeclsContext::DeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::DeclContext *> AIDLParser::DeclsContext::decl() {
  return getRuleContexts<AIDLParser::DeclContext>();
}

AIDLParser::DeclContext* AIDLParser::DeclsContext::decl(size_t i) {
  return getRuleContext<AIDLParser::DeclContext>(i);
}


size_t AIDLParser::DeclsContext::getRuleIndex() const {
  return AIDLParser::RuleDecls;
}


std::any AIDLParser::DeclsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitDecls(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::DeclsContext* AIDLParser::decls() {
  DeclsContext *_localctx = _tracker.createInstance<DeclsContext>(_ctx, getState());
  enterRule(_localctx, 12, AIDLParser::RuleDecls);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(105);
      decl();
      setState(108); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 25723016) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

AIDLParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::Annotation_listContext* AIDLParser::DeclContext::annotation_list() {
  return getRuleContext<AIDLParser::Annotation_listContext>(0);
}

AIDLParser::Unannotated_declContext* AIDLParser::DeclContext::unannotated_decl() {
  return getRuleContext<AIDLParser::Unannotated_declContext>(0);
}


size_t AIDLParser::DeclContext::getRuleIndex() const {
  return AIDLParser::RuleDecl;
}


std::any AIDLParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::DeclContext* AIDLParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 14, AIDLParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    annotation_list();
    setState(111);
    unannotated_decl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unannotated_declContext ------------------------------------------------------------------

AIDLParser::Unannotated_declContext::Unannotated_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::Parcelable_declContext* AIDLParser::Unannotated_declContext::parcelable_decl() {
  return getRuleContext<AIDLParser::Parcelable_declContext>(0);
}

AIDLParser::Interface_declContext* AIDLParser::Unannotated_declContext::interface_decl() {
  return getRuleContext<AIDLParser::Interface_declContext>(0);
}

AIDLParser::Enum_declContext* AIDLParser::Unannotated_declContext::enum_decl() {
  return getRuleContext<AIDLParser::Enum_declContext>(0);
}

AIDLParser::Union_declContext* AIDLParser::Unannotated_declContext::union_decl() {
  return getRuleContext<AIDLParser::Union_declContext>(0);
}


size_t AIDLParser::Unannotated_declContext::getRuleIndex() const {
  return AIDLParser::RuleUnannotated_decl;
}


std::any AIDLParser::Unannotated_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitUnannotated_decl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Unannotated_declContext* AIDLParser::unannotated_decl() {
  Unannotated_declContext *_localctx = _tracker.createInstance<Unannotated_declContext>(_ctx, getState());
  enterRule(_localctx, 16, AIDLParser::RuleUnannotated_decl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AIDLParser::PARCELABLE: {
        enterOuterAlt(_localctx, 1);
        setState(113);
        parcelable_decl();
        break;
      }

      case AIDLParser::INTERFACE:
      case AIDLParser::ONEWAY: {
        enterOuterAlt(_localctx, 2);
        setState(114);
        interface_decl();
        break;
      }

      case AIDLParser::ENUM: {
        enterOuterAlt(_localctx, 3);
        setState(115);
        enum_decl();
        break;
      }

      case AIDLParser::UNION: {
        enterOuterAlt(_localctx, 4);
        setState(116);
        union_decl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_paramsContext ------------------------------------------------------------------

AIDLParser::Type_paramsContext::Type_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::IdentifierContext *> AIDLParser::Type_paramsContext::identifier() {
  return getRuleContexts<AIDLParser::IdentifierContext>();
}

AIDLParser::IdentifierContext* AIDLParser::Type_paramsContext::identifier(size_t i) {
  return getRuleContext<AIDLParser::IdentifierContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::Type_paramsContext::COMMA() {
  return getTokens(AIDLParser::COMMA);
}

tree::TerminalNode* AIDLParser::Type_paramsContext::COMMA(size_t i) {
  return getToken(AIDLParser::COMMA, i);
}


size_t AIDLParser::Type_paramsContext::getRuleIndex() const {
  return AIDLParser::RuleType_params;
}


std::any AIDLParser::Type_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitType_params(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Type_paramsContext* AIDLParser::type_params() {
  Type_paramsContext *_localctx = _tracker.createInstance<Type_paramsContext>(_ctx, getState());
  enterRule(_localctx, 18, AIDLParser::RuleType_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    identifier();
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AIDLParser::COMMA) {
      setState(120);
      match(AIDLParser::COMMA);
      setState(121);
      identifier();
      setState(126);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Optional_type_paramsContext ------------------------------------------------------------------

AIDLParser::Optional_type_paramsContext::Optional_type_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::Optional_type_paramsContext::LT() {
  return getToken(AIDLParser::LT, 0);
}

AIDLParser::Type_paramsContext* AIDLParser::Optional_type_paramsContext::type_params() {
  return getRuleContext<AIDLParser::Type_paramsContext>(0);
}

tree::TerminalNode* AIDLParser::Optional_type_paramsContext::GT() {
  return getToken(AIDLParser::GT, 0);
}


size_t AIDLParser::Optional_type_paramsContext::getRuleIndex() const {
  return AIDLParser::RuleOptional_type_params;
}


std::any AIDLParser::Optional_type_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitOptional_type_params(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Optional_type_paramsContext* AIDLParser::optional_type_params() {
  Optional_type_paramsContext *_localctx = _tracker.createInstance<Optional_type_paramsContext>(_ctx, getState());
  enterRule(_localctx, 20, AIDLParser::RuleOptional_type_params);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(AIDLParser::LT);
    setState(128);
    type_params();
    setState(129);
    match(AIDLParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Optional_unstructured_headersContext ------------------------------------------------------------------

AIDLParser::Optional_unstructured_headersContext::Optional_unstructured_headersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AIDLParser::Optional_unstructured_headersContext::CPP_HEADER() {
  return getTokens(AIDLParser::CPP_HEADER);
}

tree::TerminalNode* AIDLParser::Optional_unstructured_headersContext::CPP_HEADER(size_t i) {
  return getToken(AIDLParser::CPP_HEADER, i);
}

std::vector<tree::TerminalNode *> AIDLParser::Optional_unstructured_headersContext::C_STR() {
  return getTokens(AIDLParser::C_STR);
}

tree::TerminalNode* AIDLParser::Optional_unstructured_headersContext::C_STR(size_t i) {
  return getToken(AIDLParser::C_STR, i);
}

std::vector<tree::TerminalNode *> AIDLParser::Optional_unstructured_headersContext::NDK_HEADER() {
  return getTokens(AIDLParser::NDK_HEADER);
}

tree::TerminalNode* AIDLParser::Optional_unstructured_headersContext::NDK_HEADER(size_t i) {
  return getToken(AIDLParser::NDK_HEADER, i);
}

std::vector<tree::TerminalNode *> AIDLParser::Optional_unstructured_headersContext::RUST_TYPE() {
  return getTokens(AIDLParser::RUST_TYPE);
}

tree::TerminalNode* AIDLParser::Optional_unstructured_headersContext::RUST_TYPE(size_t i) {
  return getToken(AIDLParser::RUST_TYPE, i);
}


size_t AIDLParser::Optional_unstructured_headersContext::getRuleIndex() const {
  return AIDLParser::RuleOptional_unstructured_headers;
}


std::any AIDLParser::Optional_unstructured_headersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitOptional_unstructured_headers(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Optional_unstructured_headersContext* AIDLParser::optional_unstructured_headers() {
  Optional_unstructured_headersContext *_localctx = _tracker.createInstance<Optional_unstructured_headersContext>(_ctx, getState());
  enterRule(_localctx, 22, AIDLParser::RuleOptional_unstructured_headers);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7340032) != 0)) {
      setState(137);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AIDLParser::CPP_HEADER: {
          setState(131);
          match(AIDLParser::CPP_HEADER);
          setState(132);
          match(AIDLParser::C_STR);
          break;
        }

        case AIDLParser::NDK_HEADER: {
          setState(133);
          match(AIDLParser::NDK_HEADER);
          setState(134);
          match(AIDLParser::C_STR);
          break;
        }

        case AIDLParser::RUST_TYPE: {
          setState(135);
          match(AIDLParser::RUST_TYPE);
          setState(136);
          match(AIDLParser::C_STR);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parcelable_declContext ------------------------------------------------------------------

AIDLParser::Parcelable_declContext::Parcelable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::Parcelable_declContext::PARCELABLE() {
  return getToken(AIDLParser::PARCELABLE, 0);
}

AIDLParser::Qualified_nameContext* AIDLParser::Parcelable_declContext::qualified_name() {
  return getRuleContext<AIDLParser::Qualified_nameContext>(0);
}

AIDLParser::Optional_type_paramsContext* AIDLParser::Parcelable_declContext::optional_type_params() {
  return getRuleContext<AIDLParser::Optional_type_paramsContext>(0);
}

AIDLParser::Optional_unstructured_headersContext* AIDLParser::Parcelable_declContext::optional_unstructured_headers() {
  return getRuleContext<AIDLParser::Optional_unstructured_headersContext>(0);
}

tree::TerminalNode* AIDLParser::Parcelable_declContext::SEMI() {
  return getToken(AIDLParser::SEMI, 0);
}

tree::TerminalNode* AIDLParser::Parcelable_declContext::LBRACE() {
  return getToken(AIDLParser::LBRACE, 0);
}

AIDLParser::Parcelable_membersContext* AIDLParser::Parcelable_declContext::parcelable_members() {
  return getRuleContext<AIDLParser::Parcelable_membersContext>(0);
}

tree::TerminalNode* AIDLParser::Parcelable_declContext::RBRACE() {
  return getToken(AIDLParser::RBRACE, 0);
}


size_t AIDLParser::Parcelable_declContext::getRuleIndex() const {
  return AIDLParser::RuleParcelable_decl;
}


std::any AIDLParser::Parcelable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitParcelable_decl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Parcelable_declContext* AIDLParser::parcelable_decl() {
  Parcelable_declContext *_localctx = _tracker.createInstance<Parcelable_declContext>(_ctx, getState());
  enterRule(_localctx, 24, AIDLParser::RuleParcelable_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(AIDLParser::PARCELABLE);
    setState(143);
    qualified_name();
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::LT) {
      setState(144);
      optional_type_params();
    }
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AIDLParser::CPP_HEADER:
      case AIDLParser::NDK_HEADER:
      case AIDLParser::RUST_TYPE:
      case AIDLParser::SEMI: {
        setState(147);
        optional_unstructured_headers();
        setState(148);
        match(AIDLParser::SEMI);
        break;
      }

      case AIDLParser::LBRACE: {
        setState(150);
        match(AIDLParser::LBRACE);
        setState(151);
        parcelable_members();
        setState(152);
        match(AIDLParser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parcelable_membersContext ------------------------------------------------------------------

AIDLParser::Parcelable_membersContext::Parcelable_membersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::Variable_declContext *> AIDLParser::Parcelable_membersContext::variable_decl() {
  return getRuleContexts<AIDLParser::Variable_declContext>();
}

AIDLParser::Variable_declContext* AIDLParser::Parcelable_membersContext::variable_decl(size_t i) {
  return getRuleContext<AIDLParser::Variable_declContext>(i);
}

std::vector<AIDLParser::Constant_declContext *> AIDLParser::Parcelable_membersContext::constant_decl() {
  return getRuleContexts<AIDLParser::Constant_declContext>();
}

AIDLParser::Constant_declContext* AIDLParser::Parcelable_membersContext::constant_decl(size_t i) {
  return getRuleContext<AIDLParser::Constant_declContext>(i);
}

std::vector<AIDLParser::DeclContext *> AIDLParser::Parcelable_membersContext::decl() {
  return getRuleContexts<AIDLParser::DeclContext>();
}

AIDLParser::DeclContext* AIDLParser::Parcelable_membersContext::decl(size_t i) {
  return getRuleContext<AIDLParser::DeclContext>(i);
}


size_t AIDLParser::Parcelable_membersContext::getRuleIndex() const {
  return AIDLParser::RuleParcelable_members;
}


std::any AIDLParser::Parcelable_membersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitParcelable_members(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Parcelable_membersContext* AIDLParser::parcelable_members() {
  Parcelable_membersContext *_localctx = _tracker.createInstance<Parcelable_membersContext>(_ctx, getState());
  enterRule(_localctx, 26, AIDLParser::RuleParcelable_members);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 33079436) != 0) || _la == AIDLParser::IDENTIFIER) {
      setState(159);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
      case 1: {
        setState(156);
        variable_decl();
        break;
      }

      case 2: {
        setState(157);
        constant_decl();
        break;
      }

      case 3: {
        setState(158);
        decl();
        break;
      }

      default:
        break;
      }
      setState(163);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AIDLParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::TypeContext* AIDLParser::Variable_declContext::type() {
  return getRuleContext<AIDLParser::TypeContext>(0);
}

AIDLParser::IdentifierContext* AIDLParser::Variable_declContext::identifier() {
  return getRuleContext<AIDLParser::IdentifierContext>(0);
}

tree::TerminalNode* AIDLParser::Variable_declContext::SEMI() {
  return getToken(AIDLParser::SEMI, 0);
}

tree::TerminalNode* AIDLParser::Variable_declContext::ASSIGN() {
  return getToken(AIDLParser::ASSIGN, 0);
}

AIDLParser::Const_exprContext* AIDLParser::Variable_declContext::const_expr() {
  return getRuleContext<AIDLParser::Const_exprContext>(0);
}


size_t AIDLParser::Variable_declContext::getRuleIndex() const {
  return AIDLParser::RuleVariable_decl;
}


std::any AIDLParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Variable_declContext* AIDLParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 28, AIDLParser::RuleVariable_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    type();
    setState(165);
    identifier();
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::ASSIGN) {
      setState(166);
      match(AIDLParser::ASSIGN);
      setState(167);
      const_expr(0);
    }
    setState(170);
    match(AIDLParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_declContext ------------------------------------------------------------------

AIDLParser::Interface_declContext::Interface_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::Interface_declContext::INTERFACE() {
  return getToken(AIDLParser::INTERFACE, 0);
}

AIDLParser::Qualified_nameContext* AIDLParser::Interface_declContext::qualified_name() {
  return getRuleContext<AIDLParser::Qualified_nameContext>(0);
}

tree::TerminalNode* AIDLParser::Interface_declContext::ONEWAY() {
  return getToken(AIDLParser::ONEWAY, 0);
}

tree::TerminalNode* AIDLParser::Interface_declContext::SEMI() {
  return getToken(AIDLParser::SEMI, 0);
}

tree::TerminalNode* AIDLParser::Interface_declContext::LBRACE() {
  return getToken(AIDLParser::LBRACE, 0);
}

AIDLParser::Interface_membersContext* AIDLParser::Interface_declContext::interface_members() {
  return getRuleContext<AIDLParser::Interface_membersContext>(0);
}

tree::TerminalNode* AIDLParser::Interface_declContext::RBRACE() {
  return getToken(AIDLParser::RBRACE, 0);
}


size_t AIDLParser::Interface_declContext::getRuleIndex() const {
  return AIDLParser::RuleInterface_decl;
}


std::any AIDLParser::Interface_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitInterface_decl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Interface_declContext* AIDLParser::interface_decl() {
  Interface_declContext *_localctx = _tracker.createInstance<Interface_declContext>(_ctx, getState());
  enterRule(_localctx, 30, AIDLParser::RuleInterface_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::ONEWAY) {
      setState(172);
      match(AIDLParser::ONEWAY);
    }
    setState(175);
    match(AIDLParser::INTERFACE);
    setState(176);
    qualified_name();
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AIDLParser::SEMI: {
        setState(177);
        match(AIDLParser::SEMI);
        break;
      }

      case AIDLParser::LBRACE: {
        setState(178);
        match(AIDLParser::LBRACE);
        setState(179);
        interface_members();
        setState(180);
        match(AIDLParser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_membersContext ------------------------------------------------------------------

AIDLParser::Interface_membersContext::Interface_membersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::Method_declContext *> AIDLParser::Interface_membersContext::method_decl() {
  return getRuleContexts<AIDLParser::Method_declContext>();
}

AIDLParser::Method_declContext* AIDLParser::Interface_membersContext::method_decl(size_t i) {
  return getRuleContext<AIDLParser::Method_declContext>(i);
}

std::vector<AIDLParser::Constant_declContext *> AIDLParser::Interface_membersContext::constant_decl() {
  return getRuleContexts<AIDLParser::Constant_declContext>();
}

AIDLParser::Constant_declContext* AIDLParser::Interface_membersContext::constant_decl(size_t i) {
  return getRuleContext<AIDLParser::Constant_declContext>(i);
}

std::vector<AIDLParser::DeclContext *> AIDLParser::Interface_membersContext::decl() {
  return getRuleContexts<AIDLParser::DeclContext>();
}

AIDLParser::DeclContext* AIDLParser::Interface_membersContext::decl(size_t i) {
  return getRuleContext<AIDLParser::DeclContext>(i);
}


size_t AIDLParser::Interface_membersContext::getRuleIndex() const {
  return AIDLParser::RuleInterface_members;
}


std::any AIDLParser::Interface_membersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitInterface_members(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Interface_membersContext* AIDLParser::interface_members() {
  Interface_membersContext *_localctx = _tracker.createInstance<Interface_membersContext>(_ctx, getState());
  enterRule(_localctx, 32, AIDLParser::RuleInterface_members);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 33079436) != 0) || _la == AIDLParser::IDENTIFIER) {
      setState(187);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(184);
        method_decl();
        break;
      }

      case 2: {
        setState(185);
        constant_decl();
        break;
      }

      case 3: {
        setState(186);
        decl();
        break;
      }

      default:
        break;
      }
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_exprContext ------------------------------------------------------------------

AIDLParser::Const_exprContext::Const_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::Const_exprContext::TRUE_LITERAL() {
  return getToken(AIDLParser::TRUE_LITERAL, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::FALSE_LITERAL() {
  return getToken(AIDLParser::FALSE_LITERAL, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::CHARVALUE() {
  return getToken(AIDLParser::CHARVALUE, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::INTVALUE() {
  return getToken(AIDLParser::INTVALUE, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::FLOATVALUE() {
  return getToken(AIDLParser::FLOATVALUE, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::HEXVALUE() {
  return getToken(AIDLParser::HEXVALUE, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::C_STR() {
  return getToken(AIDLParser::C_STR, 0);
}

AIDLParser::Qualified_nameContext* AIDLParser::Const_exprContext::qualified_name() {
  return getRuleContext<AIDLParser::Qualified_nameContext>(0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::LBRACE() {
  return getToken(AIDLParser::LBRACE, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::RBRACE() {
  return getToken(AIDLParser::RBRACE, 0);
}

AIDLParser::Constant_value_listContext* AIDLParser::Const_exprContext::constant_value_list() {
  return getRuleContext<AIDLParser::Constant_value_listContext>(0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::ADD() {
  return getToken(AIDLParser::ADD, 0);
}

std::vector<AIDLParser::Const_exprContext *> AIDLParser::Const_exprContext::const_expr() {
  return getRuleContexts<AIDLParser::Const_exprContext>();
}

AIDLParser::Const_exprContext* AIDLParser::Const_exprContext::const_expr(size_t i) {
  return getRuleContext<AIDLParser::Const_exprContext>(i);
}

tree::TerminalNode* AIDLParser::Const_exprContext::SUB() {
  return getToken(AIDLParser::SUB, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::BANG() {
  return getToken(AIDLParser::BANG, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::TILDE() {
  return getToken(AIDLParser::TILDE, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::LPAREN() {
  return getToken(AIDLParser::LPAREN, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::RPAREN() {
  return getToken(AIDLParser::RPAREN, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::LOGICAL_OR() {
  return getToken(AIDLParser::LOGICAL_OR, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::LOGICAL_AND() {
  return getToken(AIDLParser::LOGICAL_AND, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::BITOR() {
  return getToken(AIDLParser::BITOR, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::CARET() {
  return getToken(AIDLParser::CARET, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::BITAND() {
  return getToken(AIDLParser::BITAND, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::EQUALITY() {
  return getToken(AIDLParser::EQUALITY, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::NEQ() {
  return getToken(AIDLParser::NEQ, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::LT() {
  return getToken(AIDLParser::LT, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::GT() {
  return getToken(AIDLParser::GT, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::LEQ() {
  return getToken(AIDLParser::LEQ, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::GEQ() {
  return getToken(AIDLParser::GEQ, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::LSHIFT() {
  return getToken(AIDLParser::LSHIFT, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::RSHIFT() {
  return getToken(AIDLParser::RSHIFT, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::MUL() {
  return getToken(AIDLParser::MUL, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::DIV() {
  return getToken(AIDLParser::DIV, 0);
}

tree::TerminalNode* AIDLParser::Const_exprContext::MOD() {
  return getToken(AIDLParser::MOD, 0);
}


size_t AIDLParser::Const_exprContext::getRuleIndex() const {
  return AIDLParser::RuleConst_expr;
}


std::any AIDLParser::Const_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitConst_expr(this);
  else
    return visitor->visitChildren(this);
}


AIDLParser::Const_exprContext* AIDLParser::const_expr() {
   return const_expr(0);
}

AIDLParser::Const_exprContext* AIDLParser::const_expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AIDLParser::Const_exprContext *_localctx = _tracker.createInstance<Const_exprContext>(_ctx, parentState);
  AIDLParser::Const_exprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, AIDLParser::RuleConst_expr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(218);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AIDLParser::TRUE_LITERAL: {
        setState(193);
        match(AIDLParser::TRUE_LITERAL);
        break;
      }

      case AIDLParser::FALSE_LITERAL: {
        setState(194);
        match(AIDLParser::FALSE_LITERAL);
        break;
      }

      case AIDLParser::CHARVALUE: {
        setState(195);
        match(AIDLParser::CHARVALUE);
        break;
      }

      case AIDLParser::INTVALUE: {
        setState(196);
        match(AIDLParser::INTVALUE);
        break;
      }

      case AIDLParser::FLOATVALUE: {
        setState(197);
        match(AIDLParser::FLOATVALUE);
        break;
      }

      case AIDLParser::HEXVALUE: {
        setState(198);
        match(AIDLParser::HEXVALUE);
        break;
      }

      case AIDLParser::C_STR: {
        setState(199);
        match(AIDLParser::C_STR);
        break;
      }

      case AIDLParser::CPP_HEADER:
      case AIDLParser::NDK_HEADER:
      case AIDLParser::RUST_TYPE:
      case AIDLParser::IDENTIFIER: {
        setState(200);
        qualified_name();
        break;
      }

      case AIDLParser::LBRACE: {
        setState(201);
        match(AIDLParser::LBRACE);
        setState(203);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 108132473915834368) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & 134217731) != 0)) {
          setState(202);
          constant_value_list();
        }
        setState(205);
        match(AIDLParser::RBRACE);
        break;
      }

      case AIDLParser::ADD: {
        setState(206);
        match(AIDLParser::ADD);
        setState(207);
        const_expr(5);
        break;
      }

      case AIDLParser::SUB: {
        setState(208);
        match(AIDLParser::SUB);
        setState(209);
        const_expr(4);
        break;
      }

      case AIDLParser::BANG: {
        setState(210);
        match(AIDLParser::BANG);
        setState(211);
        const_expr(3);
        break;
      }

      case AIDLParser::TILDE: {
        setState(212);
        match(AIDLParser::TILDE);
        setState(213);
        const_expr(2);
        break;
      }

      case AIDLParser::LPAREN: {
        setState(214);
        match(AIDLParser::LPAREN);
        setState(215);
        const_expr(0);
        setState(216);
        match(AIDLParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(276);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(274);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(220);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(221);
          match(AIDLParser::LOGICAL_OR);
          setState(222);
          const_expr(24);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(223);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(224);
          match(AIDLParser::LOGICAL_AND);
          setState(225);
          const_expr(23);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(226);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(227);
          match(AIDLParser::BITOR);
          setState(228);
          const_expr(22);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(229);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(230);
          match(AIDLParser::CARET);
          setState(231);
          const_expr(21);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(232);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(233);
          match(AIDLParser::BITAND);
          setState(234);
          const_expr(20);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(235);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(236);
          match(AIDLParser::EQUALITY);
          setState(237);
          const_expr(19);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(238);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(239);
          match(AIDLParser::NEQ);
          setState(240);
          const_expr(18);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(241);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(242);
          match(AIDLParser::LT);
          setState(243);
          const_expr(17);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(244);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(245);
          match(AIDLParser::GT);
          setState(246);
          const_expr(16);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(247);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(248);
          match(AIDLParser::LEQ);
          setState(249);
          const_expr(15);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(250);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(251);
          match(AIDLParser::GEQ);
          setState(252);
          const_expr(14);
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(253);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(254);
          match(AIDLParser::LSHIFT);
          setState(255);
          const_expr(13);
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(256);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(257);
          match(AIDLParser::RSHIFT);
          setState(258);
          const_expr(12);
          break;
        }

        case 14: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(259);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(260);
          match(AIDLParser::ADD);
          setState(261);
          const_expr(11);
          break;
        }

        case 15: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(262);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(263);
          match(AIDLParser::SUB);
          setState(264);
          const_expr(10);
          break;
        }

        case 16: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(265);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(266);
          match(AIDLParser::MUL);
          setState(267);
          const_expr(9);
          break;
        }

        case 17: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(268);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(269);
          match(AIDLParser::DIV);
          setState(270);
          const_expr(8);
          break;
        }

        case 18: {
          _localctx = _tracker.createInstance<Const_exprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleConst_expr);
          setState(271);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(272);
          match(AIDLParser::MOD);
          setState(273);
          const_expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(278);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Constant_value_listContext ------------------------------------------------------------------

AIDLParser::Constant_value_listContext::Constant_value_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::Constant_value_non_empty_listContext* AIDLParser::Constant_value_listContext::constant_value_non_empty_list() {
  return getRuleContext<AIDLParser::Constant_value_non_empty_listContext>(0);
}

tree::TerminalNode* AIDLParser::Constant_value_listContext::COMMA() {
  return getToken(AIDLParser::COMMA, 0);
}


size_t AIDLParser::Constant_value_listContext::getRuleIndex() const {
  return AIDLParser::RuleConstant_value_list;
}


std::any AIDLParser::Constant_value_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitConstant_value_list(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Constant_value_listContext* AIDLParser::constant_value_list() {
  Constant_value_listContext *_localctx = _tracker.createInstance<Constant_value_listContext>(_ctx, getState());
  enterRule(_localctx, 36, AIDLParser::RuleConstant_value_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    constant_value_non_empty_list();
    setState(281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::COMMA) {
      setState(280);
      match(AIDLParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_value_non_empty_listContext ------------------------------------------------------------------

AIDLParser::Constant_value_non_empty_listContext::Constant_value_non_empty_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::Const_exprContext *> AIDLParser::Constant_value_non_empty_listContext::const_expr() {
  return getRuleContexts<AIDLParser::Const_exprContext>();
}

AIDLParser::Const_exprContext* AIDLParser::Constant_value_non_empty_listContext::const_expr(size_t i) {
  return getRuleContext<AIDLParser::Const_exprContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::Constant_value_non_empty_listContext::COMMA() {
  return getTokens(AIDLParser::COMMA);
}

tree::TerminalNode* AIDLParser::Constant_value_non_empty_listContext::COMMA(size_t i) {
  return getToken(AIDLParser::COMMA, i);
}


size_t AIDLParser::Constant_value_non_empty_listContext::getRuleIndex() const {
  return AIDLParser::RuleConstant_value_non_empty_list;
}


std::any AIDLParser::Constant_value_non_empty_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitConstant_value_non_empty_list(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Constant_value_non_empty_listContext* AIDLParser::constant_value_non_empty_list() {
  Constant_value_non_empty_listContext *_localctx = _tracker.createInstance<Constant_value_non_empty_listContext>(_ctx, getState());
  enterRule(_localctx, 38, AIDLParser::RuleConstant_value_non_empty_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(283);
    const_expr(0);
    setState(288);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(284);
        match(AIDLParser::COMMA);
        setState(285);
        const_expr(0); 
      }
      setState(290);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_declContext ------------------------------------------------------------------

AIDLParser::Constant_declContext::Constant_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::Annotation_listContext* AIDLParser::Constant_declContext::annotation_list() {
  return getRuleContext<AIDLParser::Annotation_listContext>(0);
}

tree::TerminalNode* AIDLParser::Constant_declContext::CONST() {
  return getToken(AIDLParser::CONST, 0);
}

AIDLParser::TypeContext* AIDLParser::Constant_declContext::type() {
  return getRuleContext<AIDLParser::TypeContext>(0);
}

AIDLParser::IdentifierContext* AIDLParser::Constant_declContext::identifier() {
  return getRuleContext<AIDLParser::IdentifierContext>(0);
}

tree::TerminalNode* AIDLParser::Constant_declContext::ASSIGN() {
  return getToken(AIDLParser::ASSIGN, 0);
}

AIDLParser::Const_exprContext* AIDLParser::Constant_declContext::const_expr() {
  return getRuleContext<AIDLParser::Const_exprContext>(0);
}

tree::TerminalNode* AIDLParser::Constant_declContext::SEMI() {
  return getToken(AIDLParser::SEMI, 0);
}


size_t AIDLParser::Constant_declContext::getRuleIndex() const {
  return AIDLParser::RuleConstant_decl;
}


std::any AIDLParser::Constant_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitConstant_decl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Constant_declContext* AIDLParser::constant_decl() {
  Constant_declContext *_localctx = _tracker.createInstance<Constant_declContext>(_ctx, getState());
  enterRule(_localctx, 40, AIDLParser::RuleConstant_decl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    annotation_list();
    setState(292);
    match(AIDLParser::CONST);
    setState(293);
    type();
    setState(294);
    identifier();
    setState(295);
    match(AIDLParser::ASSIGN);
    setState(296);
    const_expr(0);
    setState(297);
    match(AIDLParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumeratorContext ------------------------------------------------------------------

AIDLParser::EnumeratorContext::EnumeratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::IdentifierContext* AIDLParser::EnumeratorContext::identifier() {
  return getRuleContext<AIDLParser::IdentifierContext>(0);
}

tree::TerminalNode* AIDLParser::EnumeratorContext::ASSIGN() {
  return getToken(AIDLParser::ASSIGN, 0);
}

AIDLParser::Const_exprContext* AIDLParser::EnumeratorContext::const_expr() {
  return getRuleContext<AIDLParser::Const_exprContext>(0);
}


size_t AIDLParser::EnumeratorContext::getRuleIndex() const {
  return AIDLParser::RuleEnumerator;
}


std::any AIDLParser::EnumeratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitEnumerator(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::EnumeratorContext* AIDLParser::enumerator() {
  EnumeratorContext *_localctx = _tracker.createInstance<EnumeratorContext>(_ctx, getState());
  enterRule(_localctx, 42, AIDLParser::RuleEnumerator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    identifier();
    setState(302);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::ASSIGN) {
      setState(300);
      match(AIDLParser::ASSIGN);
      setState(301);
      const_expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumeratorsContext ------------------------------------------------------------------

AIDLParser::EnumeratorsContext::EnumeratorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::EnumeratorContext *> AIDLParser::EnumeratorsContext::enumerator() {
  return getRuleContexts<AIDLParser::EnumeratorContext>();
}

AIDLParser::EnumeratorContext* AIDLParser::EnumeratorsContext::enumerator(size_t i) {
  return getRuleContext<AIDLParser::EnumeratorContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::EnumeratorsContext::COMMA() {
  return getTokens(AIDLParser::COMMA);
}

tree::TerminalNode* AIDLParser::EnumeratorsContext::COMMA(size_t i) {
  return getToken(AIDLParser::COMMA, i);
}


size_t AIDLParser::EnumeratorsContext::getRuleIndex() const {
  return AIDLParser::RuleEnumerators;
}


std::any AIDLParser::EnumeratorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitEnumerators(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::EnumeratorsContext* AIDLParser::enumerators() {
  EnumeratorsContext *_localctx = _tracker.createInstance<EnumeratorsContext>(_ctx, getState());
  enterRule(_localctx, 44, AIDLParser::RuleEnumerators);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(304);
    enumerator();
    setState(309);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(305);
        match(AIDLParser::COMMA);
        setState(306);
        enumerator(); 
      }
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_decl_bodyContext ------------------------------------------------------------------

AIDLParser::Enum_decl_bodyContext::Enum_decl_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::Enum_decl_bodyContext::LBRACE() {
  return getToken(AIDLParser::LBRACE, 0);
}

AIDLParser::EnumeratorsContext* AIDLParser::Enum_decl_bodyContext::enumerators() {
  return getRuleContext<AIDLParser::EnumeratorsContext>(0);
}

tree::TerminalNode* AIDLParser::Enum_decl_bodyContext::RBRACE() {
  return getToken(AIDLParser::RBRACE, 0);
}

tree::TerminalNode* AIDLParser::Enum_decl_bodyContext::COMMA() {
  return getToken(AIDLParser::COMMA, 0);
}


size_t AIDLParser::Enum_decl_bodyContext::getRuleIndex() const {
  return AIDLParser::RuleEnum_decl_body;
}


std::any AIDLParser::Enum_decl_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitEnum_decl_body(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Enum_decl_bodyContext* AIDLParser::enum_decl_body() {
  Enum_decl_bodyContext *_localctx = _tracker.createInstance<Enum_decl_bodyContext>(_ctx, getState());
  enterRule(_localctx, 46, AIDLParser::RuleEnum_decl_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(AIDLParser::LBRACE);
    setState(313);
    enumerators();
    setState(315);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::COMMA) {
      setState(314);
      match(AIDLParser::COMMA);
    }
    setState(317);
    match(AIDLParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_declContext ------------------------------------------------------------------

AIDLParser::Enum_declContext::Enum_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::Enum_declContext::ENUM() {
  return getToken(AIDLParser::ENUM, 0);
}

AIDLParser::Qualified_nameContext* AIDLParser::Enum_declContext::qualified_name() {
  return getRuleContext<AIDLParser::Qualified_nameContext>(0);
}

AIDLParser::Enum_decl_bodyContext* AIDLParser::Enum_declContext::enum_decl_body() {
  return getRuleContext<AIDLParser::Enum_decl_bodyContext>(0);
}


size_t AIDLParser::Enum_declContext::getRuleIndex() const {
  return AIDLParser::RuleEnum_decl;
}


std::any AIDLParser::Enum_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitEnum_decl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Enum_declContext* AIDLParser::enum_decl() {
  Enum_declContext *_localctx = _tracker.createInstance<Enum_declContext>(_ctx, getState());
  enterRule(_localctx, 48, AIDLParser::RuleEnum_decl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(AIDLParser::ENUM);
    setState(320);
    qualified_name();
    setState(321);
    enum_decl_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Union_declContext ------------------------------------------------------------------

AIDLParser::Union_declContext::Union_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::Union_declContext::UNION() {
  return getToken(AIDLParser::UNION, 0);
}

AIDLParser::Qualified_nameContext* AIDLParser::Union_declContext::qualified_name() {
  return getRuleContext<AIDLParser::Qualified_nameContext>(0);
}

tree::TerminalNode* AIDLParser::Union_declContext::LBRACE() {
  return getToken(AIDLParser::LBRACE, 0);
}

AIDLParser::Parcelable_membersContext* AIDLParser::Union_declContext::parcelable_members() {
  return getRuleContext<AIDLParser::Parcelable_membersContext>(0);
}

tree::TerminalNode* AIDLParser::Union_declContext::RBRACE() {
  return getToken(AIDLParser::RBRACE, 0);
}

AIDLParser::Optional_type_paramsContext* AIDLParser::Union_declContext::optional_type_params() {
  return getRuleContext<AIDLParser::Optional_type_paramsContext>(0);
}


size_t AIDLParser::Union_declContext::getRuleIndex() const {
  return AIDLParser::RuleUnion_decl;
}


std::any AIDLParser::Union_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitUnion_decl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Union_declContext* AIDLParser::union_decl() {
  Union_declContext *_localctx = _tracker.createInstance<Union_declContext>(_ctx, getState());
  enterRule(_localctx, 50, AIDLParser::RuleUnion_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    match(AIDLParser::UNION);
    setState(324);
    qualified_name();
    setState(326);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::LT) {
      setState(325);
      optional_type_params();
    }
    setState(328);
    match(AIDLParser::LBRACE);
    setState(329);
    parcelable_members();
    setState(330);
    match(AIDLParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_declContext ------------------------------------------------------------------

AIDLParser::Method_declContext::Method_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::Annotation_listContext* AIDLParser::Method_declContext::annotation_list() {
  return getRuleContext<AIDLParser::Annotation_listContext>(0);
}

AIDLParser::TypeContext* AIDLParser::Method_declContext::type() {
  return getRuleContext<AIDLParser::TypeContext>(0);
}

AIDLParser::IdentifierContext* AIDLParser::Method_declContext::identifier() {
  return getRuleContext<AIDLParser::IdentifierContext>(0);
}

tree::TerminalNode* AIDLParser::Method_declContext::LPAREN() {
  return getToken(AIDLParser::LPAREN, 0);
}

tree::TerminalNode* AIDLParser::Method_declContext::RPAREN() {
  return getToken(AIDLParser::RPAREN, 0);
}

tree::TerminalNode* AIDLParser::Method_declContext::SEMI() {
  return getToken(AIDLParser::SEMI, 0);
}

tree::TerminalNode* AIDLParser::Method_declContext::ONEWAY() {
  return getToken(AIDLParser::ONEWAY, 0);
}

AIDLParser::Arg_non_empty_listContext* AIDLParser::Method_declContext::arg_non_empty_list() {
  return getRuleContext<AIDLParser::Arg_non_empty_listContext>(0);
}

tree::TerminalNode* AIDLParser::Method_declContext::ASSIGN() {
  return getToken(AIDLParser::ASSIGN, 0);
}

tree::TerminalNode* AIDLParser::Method_declContext::INTVALUE() {
  return getToken(AIDLParser::INTVALUE, 0);
}


size_t AIDLParser::Method_declContext::getRuleIndex() const {
  return AIDLParser::RuleMethod_decl;
}


std::any AIDLParser::Method_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitMethod_decl(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Method_declContext* AIDLParser::method_decl() {
  Method_declContext *_localctx = _tracker.createInstance<Method_declContext>(_ctx, getState());
  enterRule(_localctx, 52, AIDLParser::RuleMethod_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    annotation_list();
    setState(334);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::ONEWAY) {
      setState(333);
      match(AIDLParser::ONEWAY);
    }
    setState(336);
    type();
    setState(337);
    identifier();
    setState(338);
    match(AIDLParser::LPAREN);
    setState(340);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16203776) != 0) || _la == AIDLParser::IDENTIFIER) {
      setState(339);
      arg_non_empty_list();
    }
    setState(342);
    match(AIDLParser::RPAREN);
    setState(345);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AIDLParser::ASSIGN) {
      setState(343);
      match(AIDLParser::ASSIGN);
      setState(344);
      match(AIDLParser::INTVALUE);
    }
    setState(347);
    match(AIDLParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arg_non_empty_listContext ------------------------------------------------------------------

AIDLParser::Arg_non_empty_listContext::Arg_non_empty_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::ArgContext *> AIDLParser::Arg_non_empty_listContext::arg() {
  return getRuleContexts<AIDLParser::ArgContext>();
}

AIDLParser::ArgContext* AIDLParser::Arg_non_empty_listContext::arg(size_t i) {
  return getRuleContext<AIDLParser::ArgContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::Arg_non_empty_listContext::COMMA() {
  return getTokens(AIDLParser::COMMA);
}

tree::TerminalNode* AIDLParser::Arg_non_empty_listContext::COMMA(size_t i) {
  return getToken(AIDLParser::COMMA, i);
}


size_t AIDLParser::Arg_non_empty_listContext::getRuleIndex() const {
  return AIDLParser::RuleArg_non_empty_list;
}


std::any AIDLParser::Arg_non_empty_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitArg_non_empty_list(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Arg_non_empty_listContext* AIDLParser::arg_non_empty_list() {
  Arg_non_empty_listContext *_localctx = _tracker.createInstance<Arg_non_empty_listContext>(_ctx, getState());
  enterRule(_localctx, 54, AIDLParser::RuleArg_non_empty_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    arg();
    setState(354);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AIDLParser::COMMA) {
      setState(350);
      match(AIDLParser::COMMA);
      setState(351);
      arg();
      setState(356);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

AIDLParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::TypeContext* AIDLParser::ArgContext::type() {
  return getRuleContext<AIDLParser::TypeContext>(0);
}

AIDLParser::IdentifierContext* AIDLParser::ArgContext::identifier() {
  return getRuleContext<AIDLParser::IdentifierContext>(0);
}

AIDLParser::DirectionContext* AIDLParser::ArgContext::direction() {
  return getRuleContext<AIDLParser::DirectionContext>(0);
}


size_t AIDLParser::ArgContext::getRuleIndex() const {
  return AIDLParser::RuleArg;
}


std::any AIDLParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::ArgContext* AIDLParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 56, AIDLParser::RuleArg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 458752) != 0)) {
      setState(357);
      direction();
    }
    setState(360);
    type();
    setState(361);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Non_array_typeContext ------------------------------------------------------------------

AIDLParser::Non_array_typeContext::Non_array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::Annotation_listContext* AIDLParser::Non_array_typeContext::annotation_list() {
  return getRuleContext<AIDLParser::Annotation_listContext>(0);
}

AIDLParser::Qualified_nameContext* AIDLParser::Non_array_typeContext::qualified_name() {
  return getRuleContext<AIDLParser::Qualified_nameContext>(0);
}

std::vector<tree::TerminalNode *> AIDLParser::Non_array_typeContext::LT() {
  return getTokens(AIDLParser::LT);
}

tree::TerminalNode* AIDLParser::Non_array_typeContext::LT(size_t i) {
  return getToken(AIDLParser::LT, i);
}

std::vector<AIDLParser::Type_argsContext *> AIDLParser::Non_array_typeContext::type_args() {
  return getRuleContexts<AIDLParser::Type_argsContext>();
}

AIDLParser::Type_argsContext* AIDLParser::Non_array_typeContext::type_args(size_t i) {
  return getRuleContext<AIDLParser::Type_argsContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::Non_array_typeContext::GT() {
  return getTokens(AIDLParser::GT);
}

tree::TerminalNode* AIDLParser::Non_array_typeContext::GT(size_t i) {
  return getToken(AIDLParser::GT, i);
}

std::vector<AIDLParser::Non_array_typeContext *> AIDLParser::Non_array_typeContext::non_array_type() {
  return getRuleContexts<AIDLParser::Non_array_typeContext>();
}

AIDLParser::Non_array_typeContext* AIDLParser::Non_array_typeContext::non_array_type(size_t i) {
  return getRuleContext<AIDLParser::Non_array_typeContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::Non_array_typeContext::RSHIFT() {
  return getTokens(AIDLParser::RSHIFT);
}

tree::TerminalNode* AIDLParser::Non_array_typeContext::RSHIFT(size_t i) {
  return getToken(AIDLParser::RSHIFT, i);
}

std::vector<tree::TerminalNode *> AIDLParser::Non_array_typeContext::COMMA() {
  return getTokens(AIDLParser::COMMA);
}

tree::TerminalNode* AIDLParser::Non_array_typeContext::COMMA(size_t i) {
  return getToken(AIDLParser::COMMA, i);
}


size_t AIDLParser::Non_array_typeContext::getRuleIndex() const {
  return AIDLParser::RuleNon_array_type;
}


std::any AIDLParser::Non_array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitNon_array_type(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Non_array_typeContext* AIDLParser::non_array_type() {
  Non_array_typeContext *_localctx = _tracker.createInstance<Non_array_typeContext>(_ctx, getState());
  enterRule(_localctx, 58, AIDLParser::RuleNon_array_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(363);
    annotation_list();
    setState(364);
    qualified_name();
    setState(385);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(383);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
        case 1: {
          setState(365);
          match(AIDLParser::LT);
          setState(366);
          type_args();
          setState(367);
          match(AIDLParser::GT);
          break;
        }

        case 2: {
          setState(369);
          match(AIDLParser::LT);
          setState(370);
          non_array_type();
          setState(371);
          match(AIDLParser::LT);
          setState(372);
          type_args();
          setState(373);
          match(AIDLParser::RSHIFT);
          break;
        }

        case 3: {
          setState(375);
          match(AIDLParser::LT);
          setState(376);
          type_args();
          setState(377);
          match(AIDLParser::COMMA);
          setState(378);
          non_array_type();
          setState(379);
          match(AIDLParser::LT);
          setState(380);
          type_args();
          setState(381);
          match(AIDLParser::RSHIFT);
          break;
        }

        default:
          break;
        } 
      }
      setState(387);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AIDLParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::Non_array_typeContext* AIDLParser::TypeContext::non_array_type() {
  return getRuleContext<AIDLParser::Non_array_typeContext>(0);
}

std::vector<AIDLParser::Annotation_listContext *> AIDLParser::TypeContext::annotation_list() {
  return getRuleContexts<AIDLParser::Annotation_listContext>();
}

AIDLParser::Annotation_listContext* AIDLParser::TypeContext::annotation_list(size_t i) {
  return getRuleContext<AIDLParser::Annotation_listContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::TypeContext::LBRACK() {
  return getTokens(AIDLParser::LBRACK);
}

tree::TerminalNode* AIDLParser::TypeContext::LBRACK(size_t i) {
  return getToken(AIDLParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> AIDLParser::TypeContext::RBRACK() {
  return getTokens(AIDLParser::RBRACK);
}

tree::TerminalNode* AIDLParser::TypeContext::RBRACK(size_t i) {
  return getToken(AIDLParser::RBRACK, i);
}

std::vector<AIDLParser::Const_exprContext *> AIDLParser::TypeContext::const_expr() {
  return getRuleContexts<AIDLParser::Const_exprContext>();
}

AIDLParser::Const_exprContext* AIDLParser::TypeContext::const_expr(size_t i) {
  return getRuleContext<AIDLParser::Const_exprContext>(i);
}

tree::TerminalNode* AIDLParser::TypeContext::VOID() {
  return getToken(AIDLParser::VOID, 0);
}


size_t AIDLParser::TypeContext::getRuleIndex() const {
  return AIDLParser::RuleType;
}


std::any AIDLParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::TypeContext* AIDLParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 60, AIDLParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(404);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AIDLParser::CPP_HEADER:
      case AIDLParser::NDK_HEADER:
      case AIDLParser::RUST_TYPE:
      case AIDLParser::ANNOTATION:
      case AIDLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(388);
        non_array_type();
        setState(400);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AIDLParser::ANNOTATION

        || _la == AIDLParser::LBRACK) {
          setState(398);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
          case 1: {
            setState(389);
            annotation_list();
            setState(390);
            match(AIDLParser::LBRACK);
            setState(391);
            match(AIDLParser::RBRACK);
            break;
          }

          case 2: {
            setState(393);
            annotation_list();
            setState(394);
            match(AIDLParser::LBRACK);
            setState(395);
            const_expr(0);
            setState(396);
            match(AIDLParser::RBRACK);
            break;
          }

          default:
            break;
          }
          setState(402);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case AIDLParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(403);
        match(AIDLParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_argsContext ------------------------------------------------------------------

AIDLParser::Type_argsContext::Type_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::TypeContext *> AIDLParser::Type_argsContext::type() {
  return getRuleContexts<AIDLParser::TypeContext>();
}

AIDLParser::TypeContext* AIDLParser::Type_argsContext::type(size_t i) {
  return getRuleContext<AIDLParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::Type_argsContext::COMMA() {
  return getTokens(AIDLParser::COMMA);
}

tree::TerminalNode* AIDLParser::Type_argsContext::COMMA(size_t i) {
  return getToken(AIDLParser::COMMA, i);
}


size_t AIDLParser::Type_argsContext::getRuleIndex() const {
  return AIDLParser::RuleType_args;
}


std::any AIDLParser::Type_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitType_args(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Type_argsContext* AIDLParser::type_args() {
  Type_argsContext *_localctx = _tracker.createInstance<Type_argsContext>(_ctx, getState());
  enterRule(_localctx, 62, AIDLParser::RuleType_args);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(406);
    type();
    setState(411);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(407);
        match(AIDLParser::COMMA);
        setState(408);
        type(); 
      }
      setState(413);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Annotation_listContext ------------------------------------------------------------------

AIDLParser::Annotation_listContext::Annotation_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::AnnotationContext *> AIDLParser::Annotation_listContext::annotation() {
  return getRuleContexts<AIDLParser::AnnotationContext>();
}

AIDLParser::AnnotationContext* AIDLParser::Annotation_listContext::annotation(size_t i) {
  return getRuleContext<AIDLParser::AnnotationContext>(i);
}


size_t AIDLParser::Annotation_listContext::getRuleIndex() const {
  return AIDLParser::RuleAnnotation_list;
}


std::any AIDLParser::Annotation_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitAnnotation_list(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Annotation_listContext* AIDLParser::annotation_list() {
  Annotation_listContext *_localctx = _tracker.createInstance<Annotation_listContext>(_ctx, getState());
  enterRule(_localctx, 64, AIDLParser::RuleAnnotation_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(417);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(414);
        annotation(); 
      }
      setState(419);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

AIDLParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AIDLParser::IdentifierContext* AIDLParser::ParameterContext::identifier() {
  return getRuleContext<AIDLParser::IdentifierContext>(0);
}

tree::TerminalNode* AIDLParser::ParameterContext::ASSIGN() {
  return getToken(AIDLParser::ASSIGN, 0);
}

AIDLParser::Const_exprContext* AIDLParser::ParameterContext::const_expr() {
  return getRuleContext<AIDLParser::Const_exprContext>(0);
}


size_t AIDLParser::ParameterContext::getRuleIndex() const {
  return AIDLParser::RuleParameter;
}


std::any AIDLParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::ParameterContext* AIDLParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 66, AIDLParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(420);
    identifier();
    setState(421);
    match(AIDLParser::ASSIGN);
    setState(422);
    const_expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_non_empty_listContext ------------------------------------------------------------------

AIDLParser::Parameter_non_empty_listContext::Parameter_non_empty_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AIDLParser::ParameterContext *> AIDLParser::Parameter_non_empty_listContext::parameter() {
  return getRuleContexts<AIDLParser::ParameterContext>();
}

AIDLParser::ParameterContext* AIDLParser::Parameter_non_empty_listContext::parameter(size_t i) {
  return getRuleContext<AIDLParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> AIDLParser::Parameter_non_empty_listContext::COMMA() {
  return getTokens(AIDLParser::COMMA);
}

tree::TerminalNode* AIDLParser::Parameter_non_empty_listContext::COMMA(size_t i) {
  return getToken(AIDLParser::COMMA, i);
}


size_t AIDLParser::Parameter_non_empty_listContext::getRuleIndex() const {
  return AIDLParser::RuleParameter_non_empty_list;
}


std::any AIDLParser::Parameter_non_empty_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitParameter_non_empty_list(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::Parameter_non_empty_listContext* AIDLParser::parameter_non_empty_list() {
  Parameter_non_empty_listContext *_localctx = _tracker.createInstance<Parameter_non_empty_listContext>(_ctx, getState());
  enterRule(_localctx, 68, AIDLParser::RuleParameter_non_empty_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    parameter();
    setState(429);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AIDLParser::COMMA) {
      setState(425);
      match(AIDLParser::COMMA);
      setState(426);
      parameter();
      setState(431);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationContext ------------------------------------------------------------------

AIDLParser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::AnnotationContext::ANNOTATION() {
  return getToken(AIDLParser::ANNOTATION, 0);
}

tree::TerminalNode* AIDLParser::AnnotationContext::LPAREN() {
  return getToken(AIDLParser::LPAREN, 0);
}

AIDLParser::Const_exprContext* AIDLParser::AnnotationContext::const_expr() {
  return getRuleContext<AIDLParser::Const_exprContext>(0);
}

tree::TerminalNode* AIDLParser::AnnotationContext::RPAREN() {
  return getToken(AIDLParser::RPAREN, 0);
}

AIDLParser::Parameter_non_empty_listContext* AIDLParser::AnnotationContext::parameter_non_empty_list() {
  return getRuleContext<AIDLParser::Parameter_non_empty_listContext>(0);
}


size_t AIDLParser::AnnotationContext::getRuleIndex() const {
  return AIDLParser::RuleAnnotation;
}


std::any AIDLParser::AnnotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitAnnotation(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::AnnotationContext* AIDLParser::annotation() {
  AnnotationContext *_localctx = _tracker.createInstance<AnnotationContext>(_ctx, getState());
  enterRule(_localctx, 70, AIDLParser::RuleAnnotation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(AIDLParser::ANNOTATION);
    setState(442);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      setState(433);
      match(AIDLParser::LPAREN);
      setState(434);
      const_expr(0);
      setState(435);
      match(AIDLParser::RPAREN);
      break;
    }

    case 2: {
      setState(437);
      match(AIDLParser::LPAREN);
      setState(439);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 7340032) != 0) || _la == AIDLParser::IDENTIFIER) {
        setState(438);
        parameter_non_empty_list();
      }
      setState(441);
      match(AIDLParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectionContext ------------------------------------------------------------------

AIDLParser::DirectionContext::DirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AIDLParser::DirectionContext::IN() {
  return getToken(AIDLParser::IN, 0);
}

tree::TerminalNode* AIDLParser::DirectionContext::OUT() {
  return getToken(AIDLParser::OUT, 0);
}

tree::TerminalNode* AIDLParser::DirectionContext::INOUT() {
  return getToken(AIDLParser::INOUT, 0);
}


size_t AIDLParser::DirectionContext::getRuleIndex() const {
  return AIDLParser::RuleDirection;
}


std::any AIDLParser::DirectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AIDLParserVisitor*>(visitor))
    return parserVisitor->visitDirection(this);
  else
    return visitor->visitChildren(this);
}

AIDLParser::DirectionContext* AIDLParser::direction() {
  DirectionContext *_localctx = _tracker.createInstance<DirectionContext>(_ctx, getState());
  enterRule(_localctx, 72, AIDLParser::RuleDirection);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 458752) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AIDLParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 17: return const_exprSempred(antlrcpp::downCast<Const_exprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AIDLParser::const_exprSempred(Const_exprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 23);
    case 1: return precpred(_ctx, 22);
    case 2: return precpred(_ctx, 21);
    case 3: return precpred(_ctx, 20);
    case 4: return precpred(_ctx, 19);
    case 5: return precpred(_ctx, 18);
    case 6: return precpred(_ctx, 17);
    case 7: return precpred(_ctx, 16);
    case 8: return precpred(_ctx, 15);
    case 9: return precpred(_ctx, 14);
    case 10: return precpred(_ctx, 13);
    case 11: return precpred(_ctx, 12);
    case 12: return precpred(_ctx, 11);
    case 13: return precpred(_ctx, 10);
    case 14: return precpred(_ctx, 9);
    case 15: return precpred(_ctx, 8);
    case 16: return precpred(_ctx, 7);
    case 17: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

void AIDLParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  aidlparserParserInitialize();
#else
  ::antlr4::internal::call_once(aidlparserParserOnceFlag, aidlparserParserInitialize);
#endif
}
