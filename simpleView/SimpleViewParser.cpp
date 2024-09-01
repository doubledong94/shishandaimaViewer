
// Generated from SimpleView.g4 by ANTLR 4.13.1


#include "SimpleViewVisitor.h"

#include "SimpleViewParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SimpleViewParserStaticData final {
  SimpleViewParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SimpleViewParserStaticData(const SimpleViewParserStaticData&) = delete;
  SimpleViewParserStaticData(SimpleViewParserStaticData&&) = delete;
  SimpleViewParserStaticData& operator=(const SimpleViewParserStaticData&) = delete;
  SimpleViewParserStaticData& operator=(SimpleViewParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag simpleviewParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
SimpleViewParserStaticData *simpleviewParserStaticData = nullptr;

void simpleviewParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (simpleviewParserStaticData != nullptr) {
    return;
  }
#else
  assert(simpleviewParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SimpleViewParserStaticData>(
    std::vector<std::string>{
      "compilationUnit", "classScopeExp", "nodeExp", "paramList", "lineExp", 
      "idOrNull", "lineSegOrNodeExp", "lineArgumentList", "graphElement", 
      "graphBody", "pointInLine", "intersectionPoint", "declaration", "showCommand"
    },
    std::vector<std::string>{
      "", "';'", "'['", "','", "']'", "'('", "')'", "'|'", "'&'", "'-'", 
      "'{'", "'}'", "'->'", "'||'", "'\\u003F'", "'*'", "'+'", "'<'", "'>'", 
      "'='", "'\"simple\"'", "'\"full\"'", "'nodeColor'", "'nodeScale'", 
      "'labelColor'", "'labelScale'", "'labelDetailLevel'", "'positionZ'", 
      "'basicNodeSize'", "'basicLabelSize'", "'basicPositionZ'", "'Any'", 
      "'Final'", "'Class'", "'FieldOf'", "'InstanceOf'", "'MethodOf'", "'CreatorOf'", 
      "'ParameterOf'", "'ReturnOf'", "'CalledParamOf'", "'CalledReturnOf'", 
      "'CalledMethodOf'", "'methodUsedBy'", "'fieldUsedBy'", "'methodUse'", 
      "'read'", "'write'", "'inPackage'", "'classOf'", "'superOf'", "'subOf'", 
      "'Style'", "'DefaultStyle'", "'BasicStyle'", "'ClassScope'", "'Node'", 
      "'Reference'", "'VoidRef'", "'Condition'", "'Else'", "'DataStep'", 
      "'TimingStep'", "'DataOverride'", "'TimingOverride'", "'LV'", "'Field'", 
      "'Method'", "'Constructor'", "'CalledMethod'", "'Parameter'", "'CalledParameter'", 
      "'Return'", "'CalledReturn'", "'Index'", "'Error'", "'FieldConnection'", 
      "'Seg'", "'Line'", "'LineInstance'", "'Graph'", "'GraphInstance'", 
      "'CodeOrder'", "'NULL'", "'show'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "LABEL_DETAIL_LEVEL_SIMPLE", "LABEL_DETAIL_LEVEL_FULL", 
      "NODE_COLOR", "NODE_SCALE", "LABEL_COLOR", "LABEL_SCALE", "LABEL_DETAIL_LEVEL", 
      "POSITION_Z", "BASIC_NODE_SIZE", "BASIC_LABEL_SIZE", "BASIC_POSITION_Z", 
      "ANY", "FINAL", "CLASS", "FIELD_OF", "INSTANCE_OF", "METHOD_OF", "CREATOR", 
      "PARAMETER_OF", "RETURN_OF", "CALLED_PARAM_OF", "CALLED_RETURN_OF", 
      "CALLED_METHOD_OF", "METHOD_USED_BY", "FIELD_USED_BY", "METHOD_USE", 
      "READ", "WRITE", "IN_PACKAGE", "CLASS_OF", "SUPER", "SUB", "STYLE", 
      "DEFAULT_STYLE", "BASIC_STYLE", "CLASS_SCOPE", "NODE", "REFERENCE", 
      "VOID_REF", "CONDITION", "ELSE", "DATA_STEP", "TIMING_STEP", "DATA_OVERRIDE", 
      "TIMING_OVERRIDE", "LV", "FIELD", "METHOD", "CONSTRUCTOR", "CALLED_METHOD", 
      "PARAMETER", "CALLED_PARAMETER", "RETURN", "CALLED_RETURN", "INDEX", 
      "ERROR", "FIELD_CONNECTION", "SEGMENT", "LINE", "LINE_INSTANCE", "GRAPH", 
      "GRAPH_INSTANCE", "CODE_ORDER", "NULL", "SHOW", "STRING", "IDENTIFIER", 
      "FLOAT", "INT", "WS", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,90,380,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,1,0,
  	1,0,4,0,32,8,0,11,0,12,0,33,1,0,1,0,1,0,5,0,39,8,0,10,0,12,0,42,9,0,1,
  	1,1,1,1,1,1,1,1,1,1,1,5,1,50,8,1,10,1,12,1,53,9,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,3,1,78,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,89,8,1,10,1,12,1,
  	92,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,
  	2,109,8,2,10,2,12,2,112,9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,228,
  	8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,239,8,2,10,2,12,2,242,9,2,
  	1,3,1,3,1,3,1,3,5,3,248,8,3,10,3,12,3,251,9,3,1,3,1,3,1,4,1,4,1,4,4,4,
  	258,8,4,11,4,12,4,259,1,4,1,4,1,4,4,4,265,8,4,11,4,12,4,266,3,4,269,8,
  	4,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,282,8,6,3,6,284,8,6,
  	1,6,3,6,287,8,6,1,7,1,7,1,7,1,7,5,7,293,8,7,10,7,12,7,296,9,7,1,7,1,7,
  	1,8,1,8,3,8,302,8,8,1,9,1,9,1,9,5,9,307,8,9,10,9,12,9,310,9,9,1,10,1,
  	10,1,10,1,10,5,10,316,8,10,10,10,12,10,319,9,10,1,10,1,10,1,10,3,10,324,
  	8,10,1,11,1,11,1,11,1,11,5,11,330,8,11,10,11,12,11,333,9,11,1,11,1,11,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,348,8,12,
  	1,12,1,12,1,12,1,12,1,12,3,12,355,8,12,1,12,1,12,1,12,4,12,360,8,12,11,
  	12,12,12,361,1,12,1,12,1,12,1,12,1,12,3,12,369,8,12,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,0,2,2,4,14,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,0,4,2,0,83,83,86,86,1,0,14,16,2,0,77,78,82,82,2,0,79,79,81,
  	81,445,0,31,1,0,0,0,2,77,1,0,0,0,4,227,1,0,0,0,6,243,1,0,0,0,8,268,1,
  	0,0,0,10,270,1,0,0,0,12,283,1,0,0,0,14,288,1,0,0,0,16,299,1,0,0,0,18,
  	303,1,0,0,0,20,323,1,0,0,0,22,325,1,0,0,0,24,368,1,0,0,0,26,370,1,0,0,
  	0,28,29,3,24,12,0,29,30,5,1,0,0,30,32,1,0,0,0,31,28,1,0,0,0,32,33,1,0,
  	0,0,33,31,1,0,0,0,33,34,1,0,0,0,34,40,1,0,0,0,35,36,3,26,13,0,36,37,5,
  	1,0,0,37,39,1,0,0,0,38,35,1,0,0,0,39,42,1,0,0,0,40,38,1,0,0,0,40,41,1,
  	0,0,0,41,1,1,0,0,0,42,40,1,0,0,0,43,44,6,1,-1,0,44,78,5,85,0,0,45,46,
  	5,2,0,0,46,51,5,85,0,0,47,48,5,3,0,0,48,50,5,85,0,0,49,47,1,0,0,0,50,
  	53,1,0,0,0,51,49,1,0,0,0,51,52,1,0,0,0,52,54,1,0,0,0,53,51,1,0,0,0,54,
  	78,5,4,0,0,55,56,5,48,0,0,56,57,5,5,0,0,57,58,5,85,0,0,58,78,5,6,0,0,
  	59,60,5,50,0,0,60,61,5,5,0,0,61,62,3,2,1,0,62,63,5,6,0,0,63,78,1,0,0,
  	0,64,65,5,51,0,0,65,66,5,5,0,0,66,67,3,2,1,0,67,68,5,6,0,0,68,78,1,0,
  	0,0,69,70,5,5,0,0,70,71,3,2,1,0,71,72,5,6,0,0,72,78,1,0,0,0,73,78,5,86,
  	0,0,74,75,5,10,0,0,75,76,5,86,0,0,76,78,5,11,0,0,77,43,1,0,0,0,77,45,
  	1,0,0,0,77,55,1,0,0,0,77,59,1,0,0,0,77,64,1,0,0,0,77,69,1,0,0,0,77,73,
  	1,0,0,0,77,74,1,0,0,0,78,90,1,0,0,0,79,80,10,6,0,0,80,81,5,7,0,0,81,89,
  	3,2,1,7,82,83,10,5,0,0,83,84,5,8,0,0,84,89,3,2,1,6,85,86,10,4,0,0,86,
  	87,5,9,0,0,87,89,3,2,1,5,88,79,1,0,0,0,88,82,1,0,0,0,88,85,1,0,0,0,89,
  	92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,3,1,0,0,0,92,90,1,0,0,0,93,
  	94,6,2,-1,0,94,95,5,85,0,0,95,96,5,5,0,0,96,97,5,85,0,0,97,228,5,6,0,
  	0,98,99,5,2,0,0,99,100,5,85,0,0,100,101,5,5,0,0,101,102,5,85,0,0,102,
  	110,5,6,0,0,103,104,5,3,0,0,104,105,5,85,0,0,105,106,5,5,0,0,106,107,
  	5,85,0,0,107,109,5,6,0,0,108,103,1,0,0,0,109,112,1,0,0,0,110,108,1,0,
  	0,0,110,111,1,0,0,0,111,113,1,0,0,0,112,110,1,0,0,0,113,228,5,4,0,0,114,
  	115,5,34,0,0,115,116,5,5,0,0,116,117,3,2,1,0,117,118,5,6,0,0,118,228,
  	1,0,0,0,119,120,5,36,0,0,120,121,5,5,0,0,121,122,3,2,1,0,122,123,5,6,
  	0,0,123,228,1,0,0,0,124,125,5,38,0,0,125,126,5,5,0,0,126,127,3,4,2,0,
  	127,128,5,6,0,0,128,228,1,0,0,0,129,130,5,39,0,0,130,131,5,5,0,0,131,
  	132,3,4,2,0,132,133,5,6,0,0,133,228,1,0,0,0,134,135,5,35,0,0,135,136,
  	5,5,0,0,136,137,3,2,1,0,137,138,5,3,0,0,138,139,3,2,1,0,139,140,5,6,0,
  	0,140,228,1,0,0,0,141,142,5,37,0,0,142,143,5,5,0,0,143,144,3,2,1,0,144,
  	145,5,6,0,0,145,228,1,0,0,0,146,147,5,50,0,0,147,148,5,5,0,0,148,149,
  	3,4,2,0,149,150,5,6,0,0,150,228,1,0,0,0,151,152,5,51,0,0,152,153,5,5,
  	0,0,153,154,3,4,2,0,154,155,5,6,0,0,155,228,1,0,0,0,156,157,5,42,0,0,
  	157,158,5,5,0,0,158,159,3,4,2,0,159,160,5,6,0,0,160,228,1,0,0,0,161,162,
  	5,40,0,0,162,163,5,5,0,0,163,164,3,4,2,0,164,165,5,6,0,0,165,228,1,0,
  	0,0,166,167,5,41,0,0,167,168,5,5,0,0,168,169,3,4,2,0,169,170,5,6,0,0,
  	170,228,1,0,0,0,171,172,5,43,0,0,172,173,5,5,0,0,173,174,3,4,2,0,174,
  	175,5,6,0,0,175,228,1,0,0,0,176,177,5,44,0,0,177,178,5,5,0,0,178,179,
  	3,4,2,0,179,180,5,6,0,0,180,228,1,0,0,0,181,182,5,45,0,0,182,183,5,5,
  	0,0,183,184,3,4,2,0,184,185,5,6,0,0,185,228,1,0,0,0,186,187,5,46,0,0,
  	187,188,5,5,0,0,188,189,3,4,2,0,189,190,5,6,0,0,190,228,1,0,0,0,191,192,
  	5,47,0,0,192,193,5,5,0,0,193,194,3,4,2,0,194,195,5,6,0,0,195,228,1,0,
  	0,0,196,228,5,31,0,0,197,228,5,32,0,0,198,228,5,33,0,0,199,228,5,57,0,
  	0,200,228,5,58,0,0,201,228,5,59,0,0,202,228,5,60,0,0,203,228,5,61,0,0,
  	204,228,5,62,0,0,205,228,5,63,0,0,206,228,5,64,0,0,207,228,5,65,0,0,208,
  	228,5,66,0,0,209,228,5,67,0,0,210,228,5,68,0,0,211,228,5,69,0,0,212,228,
  	5,70,0,0,213,228,5,71,0,0,214,228,5,72,0,0,215,228,5,73,0,0,216,228,5,
  	74,0,0,217,228,5,75,0,0,218,228,5,76,0,0,219,220,5,5,0,0,220,221,3,4,
  	2,0,221,222,5,6,0,0,222,228,1,0,0,0,223,228,5,86,0,0,224,225,5,10,0,0,
  	225,226,5,86,0,0,226,228,5,11,0,0,227,93,1,0,0,0,227,98,1,0,0,0,227,114,
  	1,0,0,0,227,119,1,0,0,0,227,124,1,0,0,0,227,129,1,0,0,0,227,134,1,0,0,
  	0,227,141,1,0,0,0,227,146,1,0,0,0,227,151,1,0,0,0,227,156,1,0,0,0,227,
  	161,1,0,0,0,227,166,1,0,0,0,227,171,1,0,0,0,227,176,1,0,0,0,227,181,1,
  	0,0,0,227,186,1,0,0,0,227,191,1,0,0,0,227,196,1,0,0,0,227,197,1,0,0,0,
  	227,198,1,0,0,0,227,199,1,0,0,0,227,200,1,0,0,0,227,201,1,0,0,0,227,202,
  	1,0,0,0,227,203,1,0,0,0,227,204,1,0,0,0,227,205,1,0,0,0,227,206,1,0,0,
  	0,227,207,1,0,0,0,227,208,1,0,0,0,227,209,1,0,0,0,227,210,1,0,0,0,227,
  	211,1,0,0,0,227,212,1,0,0,0,227,213,1,0,0,0,227,214,1,0,0,0,227,215,1,
  	0,0,0,227,216,1,0,0,0,227,217,1,0,0,0,227,218,1,0,0,0,227,219,1,0,0,0,
  	227,223,1,0,0,0,227,224,1,0,0,0,228,240,1,0,0,0,229,230,10,31,0,0,230,
  	231,5,8,0,0,231,239,3,4,2,32,232,233,10,30,0,0,233,234,5,7,0,0,234,239,
  	3,4,2,31,235,236,10,29,0,0,236,237,5,9,0,0,237,239,3,4,2,30,238,229,1,
  	0,0,0,238,232,1,0,0,0,238,235,1,0,0,0,239,242,1,0,0,0,240,238,1,0,0,0,
  	240,241,1,0,0,0,241,5,1,0,0,0,242,240,1,0,0,0,243,244,5,5,0,0,244,249,
  	5,86,0,0,245,246,5,3,0,0,246,248,5,86,0,0,247,245,1,0,0,0,248,251,1,0,
  	0,0,249,247,1,0,0,0,249,250,1,0,0,0,250,252,1,0,0,0,251,249,1,0,0,0,252,
  	253,5,6,0,0,253,7,1,0,0,0,254,257,3,12,6,0,255,256,5,12,0,0,256,258,3,
  	12,6,0,257,255,1,0,0,0,258,259,1,0,0,0,259,257,1,0,0,0,259,260,1,0,0,
  	0,260,269,1,0,0,0,261,264,3,12,6,0,262,263,5,13,0,0,263,265,3,12,6,0,
  	264,262,1,0,0,0,265,266,1,0,0,0,266,264,1,0,0,0,266,267,1,0,0,0,267,269,
  	1,0,0,0,268,254,1,0,0,0,268,261,1,0,0,0,269,9,1,0,0,0,270,271,7,0,0,0,
  	271,11,1,0,0,0,272,273,5,2,0,0,273,274,5,86,0,0,274,284,5,4,0,0,275,281,
  	3,4,2,0,276,277,5,10,0,0,277,278,3,10,5,0,278,279,3,10,5,0,279,280,5,
  	11,0,0,280,282,1,0,0,0,281,276,1,0,0,0,281,282,1,0,0,0,282,284,1,0,0,
  	0,283,272,1,0,0,0,283,275,1,0,0,0,284,286,1,0,0,0,285,287,7,1,0,0,286,
  	285,1,0,0,0,286,287,1,0,0,0,287,13,1,0,0,0,288,289,5,5,0,0,289,294,5,
  	86,0,0,290,291,5,3,0,0,291,293,5,86,0,0,292,290,1,0,0,0,293,296,1,0,0,
  	0,294,292,1,0,0,0,294,295,1,0,0,0,295,297,1,0,0,0,296,294,1,0,0,0,297,
  	298,5,6,0,0,298,15,1,0,0,0,299,301,5,86,0,0,300,302,3,14,7,0,301,300,
  	1,0,0,0,301,302,1,0,0,0,302,17,1,0,0,0,303,308,3,16,8,0,304,305,5,3,0,
  	0,305,307,3,16,8,0,306,304,1,0,0,0,307,310,1,0,0,0,308,306,1,0,0,0,308,
  	309,1,0,0,0,309,19,1,0,0,0,310,308,1,0,0,0,311,312,5,2,0,0,312,317,3,
  	20,10,0,313,314,5,3,0,0,314,316,3,20,10,0,315,313,1,0,0,0,316,319,1,0,
  	0,0,317,315,1,0,0,0,317,318,1,0,0,0,318,320,1,0,0,0,319,317,1,0,0,0,320,
  	321,5,4,0,0,321,324,1,0,0,0,322,324,5,88,0,0,323,311,1,0,0,0,323,322,
  	1,0,0,0,324,21,1,0,0,0,325,326,5,17,0,0,326,331,3,20,10,0,327,328,5,3,
  	0,0,328,330,3,20,10,0,329,327,1,0,0,0,330,333,1,0,0,0,331,329,1,0,0,0,
  	331,332,1,0,0,0,332,334,1,0,0,0,333,331,1,0,0,0,334,335,5,18,0,0,335,
  	23,1,0,0,0,336,337,5,55,0,0,337,338,5,86,0,0,338,339,5,19,0,0,339,369,
  	3,2,1,0,340,341,5,56,0,0,341,342,5,86,0,0,342,343,5,19,0,0,343,369,3,
  	4,2,0,344,345,7,2,0,0,345,347,5,86,0,0,346,348,3,6,3,0,347,346,1,0,0,
  	0,347,348,1,0,0,0,348,349,1,0,0,0,349,350,5,19,0,0,350,369,3,8,4,0,351,
  	352,5,80,0,0,352,354,5,86,0,0,353,355,3,6,3,0,354,353,1,0,0,0,354,355,
  	1,0,0,0,355,356,1,0,0,0,356,357,5,19,0,0,357,359,3,18,9,0,358,360,3,22,
  	11,0,359,358,1,0,0,0,360,361,1,0,0,0,361,359,1,0,0,0,361,362,1,0,0,0,
  	362,369,1,0,0,0,363,364,7,3,0,0,364,365,5,86,0,0,365,366,5,19,0,0,366,
  	367,5,86,0,0,367,369,3,14,7,0,368,336,1,0,0,0,368,340,1,0,0,0,368,344,
  	1,0,0,0,368,351,1,0,0,0,368,363,1,0,0,0,369,25,1,0,0,0,370,371,5,84,0,
  	0,371,372,5,5,0,0,372,373,5,86,0,0,373,374,5,3,0,0,374,375,5,86,0,0,375,
  	376,5,3,0,0,376,377,5,86,0,0,377,378,5,6,0,0,378,27,1,0,0,0,27,33,40,
  	51,77,88,90,110,227,238,240,249,259,266,268,281,283,286,294,301,308,317,
  	323,331,347,354,361,368
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  simpleviewParserStaticData = staticData.release();
}

}

SimpleViewParser::SimpleViewParser(TokenStream *input) : SimpleViewParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SimpleViewParser::SimpleViewParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SimpleViewParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *simpleviewParserStaticData->atn, simpleviewParserStaticData->decisionToDFA, simpleviewParserStaticData->sharedContextCache, options);
}

SimpleViewParser::~SimpleViewParser() {
  delete _interpreter;
}

const atn::ATN& SimpleViewParser::getATN() const {
  return *simpleviewParserStaticData->atn;
}

std::string SimpleViewParser::getGrammarFileName() const {
  return "SimpleView.g4";
}

const std::vector<std::string>& SimpleViewParser::getRuleNames() const {
  return simpleviewParserStaticData->ruleNames;
}

const dfa::Vocabulary& SimpleViewParser::getVocabulary() const {
  return simpleviewParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SimpleViewParser::getSerializedATN() const {
  return simpleviewParserStaticData->serializedATN;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

SimpleViewParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleViewParser::DeclarationContext *> SimpleViewParser::CompilationUnitContext::declaration() {
  return getRuleContexts<SimpleViewParser::DeclarationContext>();
}

SimpleViewParser::DeclarationContext* SimpleViewParser::CompilationUnitContext::declaration(size_t i) {
  return getRuleContext<SimpleViewParser::DeclarationContext>(i);
}

std::vector<SimpleViewParser::ShowCommandContext *> SimpleViewParser::CompilationUnitContext::showCommand() {
  return getRuleContexts<SimpleViewParser::ShowCommandContext>();
}

SimpleViewParser::ShowCommandContext* SimpleViewParser::CompilationUnitContext::showCommand(size_t i) {
  return getRuleContext<SimpleViewParser::ShowCommandContext>(i);
}


size_t SimpleViewParser::CompilationUnitContext::getRuleIndex() const {
  return SimpleViewParser::RuleCompilationUnit;
}


std::any SimpleViewParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::CompilationUnitContext* SimpleViewParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, SimpleViewParser::RuleCompilationUnit);
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
    setState(31); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(28);
      declaration();
      setState(29);
      match(SimpleViewParser::T__0);
      setState(33); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 55) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 55)) & 264241155) != 0));
    setState(40);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::SHOW) {
      setState(35);
      showCommand();
      setState(36);
      match(SimpleViewParser::T__0);
      setState(42);
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

//----------------- ClassScopeExpContext ------------------------------------------------------------------

SimpleViewParser::ClassScopeExpContext::ClassScopeExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SimpleViewParser::ClassScopeExpContext::STRING() {
  return getTokens(SimpleViewParser::STRING);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::STRING(size_t i) {
  return getToken(SimpleViewParser::STRING, i);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::IN_PACKAGE() {
  return getToken(SimpleViewParser::IN_PACKAGE, 0);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::SUPER() {
  return getToken(SimpleViewParser::SUPER, 0);
}

std::vector<SimpleViewParser::ClassScopeExpContext *> SimpleViewParser::ClassScopeExpContext::classScopeExp() {
  return getRuleContexts<SimpleViewParser::ClassScopeExpContext>();
}

SimpleViewParser::ClassScopeExpContext* SimpleViewParser::ClassScopeExpContext::classScopeExp(size_t i) {
  return getRuleContext<SimpleViewParser::ClassScopeExpContext>(i);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::SUB() {
  return getToken(SimpleViewParser::SUB, 0);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}


size_t SimpleViewParser::ClassScopeExpContext::getRuleIndex() const {
  return SimpleViewParser::RuleClassScopeExp;
}


std::any SimpleViewParser::ClassScopeExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitClassScopeExp(this);
  else
    return visitor->visitChildren(this);
}


SimpleViewParser::ClassScopeExpContext* SimpleViewParser::classScopeExp() {
   return classScopeExp(0);
}

SimpleViewParser::ClassScopeExpContext* SimpleViewParser::classScopeExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleViewParser::ClassScopeExpContext *_localctx = _tracker.createInstance<ClassScopeExpContext>(_ctx, parentState);
  SimpleViewParser::ClassScopeExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, SimpleViewParser::RuleClassScopeExp, precedence);

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
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STRING: {
        setState(44);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKey = match(SimpleViewParser::STRING);
        break;
      }

      case SimpleViewParser::T__1: {
        setState(45);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKeyList = match(SimpleViewParser::T__1);
        setState(46);
        match(SimpleViewParser::STRING);
        setState(51);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__2) {
          setState(47);
          match(SimpleViewParser::T__2);
          setState(48);
          match(SimpleViewParser::STRING);
          setState(53);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(54);
        match(SimpleViewParser::T__3);
        break;
      }

      case SimpleViewParser::IN_PACKAGE: {
        setState(55);
        match(SimpleViewParser::IN_PACKAGE);
        setState(56);
        match(SimpleViewParser::T__4);
        setState(57);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->packageStr = match(SimpleViewParser::STRING);
        setState(58);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::SUPER: {
        setState(59);
        match(SimpleViewParser::SUPER);
        setState(60);
        match(SimpleViewParser::T__4);
        setState(61);
        classScopeExp(0);
        setState(62);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::SUB: {
        setState(64);
        match(SimpleViewParser::SUB);
        setState(65);
        match(SimpleViewParser::T__4);
        setState(66);
        classScopeExp(0);
        setState(67);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::T__4: {
        setState(69);
        match(SimpleViewParser::T__4);
        setState(70);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->bracket = classScopeExp(0);
        setState(71);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::IDENTIFIER: {
        setState(73);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->refOtherScope = match(SimpleViewParser::IDENTIFIER);
        break;
      }

      case SimpleViewParser::T__9: {
        setState(74);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->varClass = match(SimpleViewParser::T__9);
        setState(75);
        match(SimpleViewParser::IDENTIFIER);
        setState(76);
        match(SimpleViewParser::T__10);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(90);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(88);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(79);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(80);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__6);
          setState(81);
          classScopeExp(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(82);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(83);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__7);
          setState(84);
          classScopeExp(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(85);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(86);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__8);
          setState(87);
          classScopeExp(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(92);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NodeExpContext ------------------------------------------------------------------

SimpleViewParser::NodeExpContext::NodeExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SimpleViewParser::NodeExpContext::STRING() {
  return getTokens(SimpleViewParser::STRING);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::STRING(size_t i) {
  return getToken(SimpleViewParser::STRING, i);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::FIELD_OF() {
  return getToken(SimpleViewParser::FIELD_OF, 0);
}

std::vector<SimpleViewParser::ClassScopeExpContext *> SimpleViewParser::NodeExpContext::classScopeExp() {
  return getRuleContexts<SimpleViewParser::ClassScopeExpContext>();
}

SimpleViewParser::ClassScopeExpContext* SimpleViewParser::NodeExpContext::classScopeExp(size_t i) {
  return getRuleContext<SimpleViewParser::ClassScopeExpContext>(i);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::METHOD_OF() {
  return getToken(SimpleViewParser::METHOD_OF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::PARAMETER_OF() {
  return getToken(SimpleViewParser::PARAMETER_OF, 0);
}

std::vector<SimpleViewParser::NodeExpContext *> SimpleViewParser::NodeExpContext::nodeExp() {
  return getRuleContexts<SimpleViewParser::NodeExpContext>();
}

SimpleViewParser::NodeExpContext* SimpleViewParser::NodeExpContext::nodeExp(size_t i) {
  return getRuleContext<SimpleViewParser::NodeExpContext>(i);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::RETURN_OF() {
  return getToken(SimpleViewParser::RETURN_OF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::INSTANCE_OF() {
  return getToken(SimpleViewParser::INSTANCE_OF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CREATOR() {
  return getToken(SimpleViewParser::CREATOR, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::SUPER() {
  return getToken(SimpleViewParser::SUPER, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::SUB() {
  return getToken(SimpleViewParser::SUB, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_METHOD_OF() {
  return getToken(SimpleViewParser::CALLED_METHOD_OF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_PARAM_OF() {
  return getToken(SimpleViewParser::CALLED_PARAM_OF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_RETURN_OF() {
  return getToken(SimpleViewParser::CALLED_RETURN_OF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::METHOD_USED_BY() {
  return getToken(SimpleViewParser::METHOD_USED_BY, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::FIELD_USED_BY() {
  return getToken(SimpleViewParser::FIELD_USED_BY, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::METHOD_USE() {
  return getToken(SimpleViewParser::METHOD_USE, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::READ() {
  return getToken(SimpleViewParser::READ, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::WRITE() {
  return getToken(SimpleViewParser::WRITE, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::ANY() {
  return getToken(SimpleViewParser::ANY, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::FINAL() {
  return getToken(SimpleViewParser::FINAL, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CLASS() {
  return getToken(SimpleViewParser::CLASS, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::REFERENCE() {
  return getToken(SimpleViewParser::REFERENCE, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::VOID_REF() {
  return getToken(SimpleViewParser::VOID_REF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CONDITION() {
  return getToken(SimpleViewParser::CONDITION, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::ELSE() {
  return getToken(SimpleViewParser::ELSE, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::DATA_STEP() {
  return getToken(SimpleViewParser::DATA_STEP, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::TIMING_STEP() {
  return getToken(SimpleViewParser::TIMING_STEP, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::DATA_OVERRIDE() {
  return getToken(SimpleViewParser::DATA_OVERRIDE, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::TIMING_OVERRIDE() {
  return getToken(SimpleViewParser::TIMING_OVERRIDE, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::LV() {
  return getToken(SimpleViewParser::LV, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::FIELD() {
  return getToken(SimpleViewParser::FIELD, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::METHOD() {
  return getToken(SimpleViewParser::METHOD, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CONSTRUCTOR() {
  return getToken(SimpleViewParser::CONSTRUCTOR, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_METHOD() {
  return getToken(SimpleViewParser::CALLED_METHOD, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::PARAMETER() {
  return getToken(SimpleViewParser::PARAMETER, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_PARAMETER() {
  return getToken(SimpleViewParser::CALLED_PARAMETER, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::RETURN() {
  return getToken(SimpleViewParser::RETURN, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_RETURN() {
  return getToken(SimpleViewParser::CALLED_RETURN, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::INDEX() {
  return getToken(SimpleViewParser::INDEX, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::ERROR() {
  return getToken(SimpleViewParser::ERROR, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::FIELD_CONNECTION() {
  return getToken(SimpleViewParser::FIELD_CONNECTION, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}


size_t SimpleViewParser::NodeExpContext::getRuleIndex() const {
  return SimpleViewParser::RuleNodeExp;
}


std::any SimpleViewParser::NodeExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitNodeExp(this);
  else
    return visitor->visitChildren(this);
}


SimpleViewParser::NodeExpContext* SimpleViewParser::nodeExp() {
   return nodeExp(0);
}

SimpleViewParser::NodeExpContext* SimpleViewParser::nodeExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SimpleViewParser::NodeExpContext *_localctx = _tracker.createInstance<NodeExpContext>(_ctx, parentState);
  SimpleViewParser::NodeExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, SimpleViewParser::RuleNodeExp, precedence);

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
    setState(227);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STRING: {
        setState(94);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKey = match(SimpleViewParser::STRING);
        setState(95);
        match(SimpleViewParser::T__4);
        setState(96);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->typeKey = match(SimpleViewParser::STRING);
        setState(97);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::T__1: {
        setState(98);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKeyList = match(SimpleViewParser::T__1);
        setState(99);
        match(SimpleViewParser::STRING);
        setState(100);
        match(SimpleViewParser::T__4);
        setState(101);
        match(SimpleViewParser::STRING);
        setState(102);
        match(SimpleViewParser::T__5);
        setState(110);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__2) {
          setState(103);
          match(SimpleViewParser::T__2);
          setState(104);
          match(SimpleViewParser::STRING);
          setState(105);
          match(SimpleViewParser::T__4);
          setState(106);
          match(SimpleViewParser::STRING);
          setState(107);
          match(SimpleViewParser::T__5);
          setState(112);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(113);
        match(SimpleViewParser::T__3);
        break;
      }

      case SimpleViewParser::FIELD_OF: {
        setState(114);
        match(SimpleViewParser::FIELD_OF);
        setState(115);
        match(SimpleViewParser::T__4);
        setState(116);
        classScopeExp(0);
        setState(117);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::METHOD_OF: {
        setState(119);
        match(SimpleViewParser::METHOD_OF);
        setState(120);
        match(SimpleViewParser::T__4);
        setState(121);
        classScopeExp(0);
        setState(122);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::PARAMETER_OF: {
        setState(124);
        match(SimpleViewParser::PARAMETER_OF);
        setState(125);
        match(SimpleViewParser::T__4);
        setState(126);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(127);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::RETURN_OF: {
        setState(129);
        match(SimpleViewParser::RETURN_OF);
        setState(130);
        match(SimpleViewParser::T__4);
        setState(131);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(132);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::INSTANCE_OF: {
        setState(134);
        match(SimpleViewParser::INSTANCE_OF);
        setState(135);
        match(SimpleViewParser::T__4);
        setState(136);
        classScopeExp(0);
        setState(137);
        match(SimpleViewParser::T__2);
        setState(138);
        classScopeExp(0);
        setState(139);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::CREATOR: {
        setState(141);
        match(SimpleViewParser::CREATOR);
        setState(142);
        match(SimpleViewParser::T__4);
        setState(143);
        classScopeExp(0);
        setState(144);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::SUPER: {
        setState(146);
        match(SimpleViewParser::SUPER);
        setState(147);
        match(SimpleViewParser::T__4);
        setState(148);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(149);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::SUB: {
        setState(151);
        match(SimpleViewParser::SUB);
        setState(152);
        match(SimpleViewParser::T__4);
        setState(153);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(154);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::CALLED_METHOD_OF: {
        setState(156);
        match(SimpleViewParser::CALLED_METHOD_OF);
        setState(157);
        match(SimpleViewParser::T__4);
        setState(158);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(159);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::CALLED_PARAM_OF: {
        setState(161);
        match(SimpleViewParser::CALLED_PARAM_OF);
        setState(162);
        match(SimpleViewParser::T__4);
        setState(163);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->paramNode = nodeExp(0);
        setState(164);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::CALLED_RETURN_OF: {
        setState(166);
        match(SimpleViewParser::CALLED_RETURN_OF);
        setState(167);
        match(SimpleViewParser::T__4);
        setState(168);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->returnNode = nodeExp(0);
        setState(169);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::METHOD_USED_BY: {
        setState(171);
        match(SimpleViewParser::METHOD_USED_BY);
        setState(172);
        match(SimpleViewParser::T__4);
        setState(173);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(174);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::FIELD_USED_BY: {
        setState(176);
        match(SimpleViewParser::FIELD_USED_BY);
        setState(177);
        match(SimpleViewParser::T__4);
        setState(178);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(179);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::METHOD_USE: {
        setState(181);
        match(SimpleViewParser::METHOD_USE);
        setState(182);
        match(SimpleViewParser::T__4);
        setState(183);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(184);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::READ: {
        setState(186);
        match(SimpleViewParser::READ);
        setState(187);
        match(SimpleViewParser::T__4);
        setState(188);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->read = nodeExp(0);
        setState(189);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::WRITE: {
        setState(191);
        match(SimpleViewParser::WRITE);
        setState(192);
        match(SimpleViewParser::T__4);
        setState(193);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->write = nodeExp(0);
        setState(194);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::ANY: {
        setState(196);
        match(SimpleViewParser::ANY);
        break;
      }

      case SimpleViewParser::FINAL: {
        setState(197);
        match(SimpleViewParser::FINAL);
        break;
      }

      case SimpleViewParser::CLASS: {
        setState(198);
        match(SimpleViewParser::CLASS);
        break;
      }

      case SimpleViewParser::REFERENCE: {
        setState(199);
        match(SimpleViewParser::REFERENCE);
        break;
      }

      case SimpleViewParser::VOID_REF: {
        setState(200);
        match(SimpleViewParser::VOID_REF);
        break;
      }

      case SimpleViewParser::CONDITION: {
        setState(201);
        match(SimpleViewParser::CONDITION);
        break;
      }

      case SimpleViewParser::ELSE: {
        setState(202);
        match(SimpleViewParser::ELSE);
        break;
      }

      case SimpleViewParser::DATA_STEP: {
        setState(203);
        match(SimpleViewParser::DATA_STEP);
        break;
      }

      case SimpleViewParser::TIMING_STEP: {
        setState(204);
        match(SimpleViewParser::TIMING_STEP);
        break;
      }

      case SimpleViewParser::DATA_OVERRIDE: {
        setState(205);
        match(SimpleViewParser::DATA_OVERRIDE);
        break;
      }

      case SimpleViewParser::TIMING_OVERRIDE: {
        setState(206);
        match(SimpleViewParser::TIMING_OVERRIDE);
        break;
      }

      case SimpleViewParser::LV: {
        setState(207);
        match(SimpleViewParser::LV);
        break;
      }

      case SimpleViewParser::FIELD: {
        setState(208);
        match(SimpleViewParser::FIELD);
        break;
      }

      case SimpleViewParser::METHOD: {
        setState(209);
        match(SimpleViewParser::METHOD);
        break;
      }

      case SimpleViewParser::CONSTRUCTOR: {
        setState(210);
        match(SimpleViewParser::CONSTRUCTOR);
        break;
      }

      case SimpleViewParser::CALLED_METHOD: {
        setState(211);
        match(SimpleViewParser::CALLED_METHOD);
        break;
      }

      case SimpleViewParser::PARAMETER: {
        setState(212);
        match(SimpleViewParser::PARAMETER);
        break;
      }

      case SimpleViewParser::CALLED_PARAMETER: {
        setState(213);
        match(SimpleViewParser::CALLED_PARAMETER);
        break;
      }

      case SimpleViewParser::RETURN: {
        setState(214);
        match(SimpleViewParser::RETURN);
        break;
      }

      case SimpleViewParser::CALLED_RETURN: {
        setState(215);
        match(SimpleViewParser::CALLED_RETURN);
        break;
      }

      case SimpleViewParser::INDEX: {
        setState(216);
        match(SimpleViewParser::INDEX);
        break;
      }

      case SimpleViewParser::ERROR: {
        setState(217);
        match(SimpleViewParser::ERROR);
        break;
      }

      case SimpleViewParser::FIELD_CONNECTION: {
        setState(218);
        match(SimpleViewParser::FIELD_CONNECTION);
        break;
      }

      case SimpleViewParser::T__4: {
        setState(219);
        match(SimpleViewParser::T__4);
        setState(220);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->bracket = nodeExp(0);
        setState(221);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::IDENTIFIER: {
        setState(223);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->refOtherNode = match(SimpleViewParser::IDENTIFIER);
        break;
      }

      case SimpleViewParser::T__9: {
        setState(224);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->varNode = match(SimpleViewParser::T__9);
        setState(225);
        match(SimpleViewParser::IDENTIFIER);
        setState(226);
        match(SimpleViewParser::T__10);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(238);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(229);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(230);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__7);
          setState(231);
          nodeExp(32);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(232);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(233);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__6);
          setState(234);
          nodeExp(31);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(235);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(236);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__8);
          setState(237);
          nodeExp(30);
          break;
        }

        default:
          break;
        } 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

SimpleViewParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SimpleViewParser::ParamListContext::IDENTIFIER() {
  return getTokens(SimpleViewParser::IDENTIFIER);
}

tree::TerminalNode* SimpleViewParser::ParamListContext::IDENTIFIER(size_t i) {
  return getToken(SimpleViewParser::IDENTIFIER, i);
}


size_t SimpleViewParser::ParamListContext::getRuleIndex() const {
  return SimpleViewParser::RuleParamList;
}


std::any SimpleViewParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::ParamListContext* SimpleViewParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 6, SimpleViewParser::RuleParamList);
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
    setState(243);
    match(SimpleViewParser::T__4);
    setState(244);
    match(SimpleViewParser::IDENTIFIER);
    setState(249);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(245);
      match(SimpleViewParser::T__2);
      setState(246);
      match(SimpleViewParser::IDENTIFIER);
      setState(251);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(252);
    match(SimpleViewParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineExpContext ------------------------------------------------------------------

SimpleViewParser::LineExpContext::LineExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleViewParser::LineSegOrNodeExpContext *> SimpleViewParser::LineExpContext::lineSegOrNodeExp() {
  return getRuleContexts<SimpleViewParser::LineSegOrNodeExpContext>();
}

SimpleViewParser::LineSegOrNodeExpContext* SimpleViewParser::LineExpContext::lineSegOrNodeExp(size_t i) {
  return getRuleContext<SimpleViewParser::LineSegOrNodeExpContext>(i);
}


size_t SimpleViewParser::LineExpContext::getRuleIndex() const {
  return SimpleViewParser::RuleLineExp;
}


std::any SimpleViewParser::LineExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitLineExp(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::LineExpContext* SimpleViewParser::lineExp() {
  LineExpContext *_localctx = _tracker.createInstance<LineExpContext>(_ctx, getState());
  enterRule(_localctx, 8, SimpleViewParser::RuleLineExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(268);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(254);
      lineSegOrNodeExp();
      setState(257); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(255);
        antlrcpp::downCast<LineExpContext *>(_localctx)->seq = match(SimpleViewParser::T__11);
        setState(256);
        lineSegOrNodeExp();
        setState(259); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__11);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(261);
      lineSegOrNodeExp();
      setState(264); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(262);
        antlrcpp::downCast<LineExpContext *>(_localctx)->alt = match(SimpleViewParser::T__12);
        setState(263);
        lineSegOrNodeExp();
        setState(266); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__12);
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

//----------------- IdOrNullContext ------------------------------------------------------------------

SimpleViewParser::IdOrNullContext::IdOrNullContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleViewParser::IdOrNullContext::NULL_() {
  return getToken(SimpleViewParser::NULL_, 0);
}

tree::TerminalNode* SimpleViewParser::IdOrNullContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}


size_t SimpleViewParser::IdOrNullContext::getRuleIndex() const {
  return SimpleViewParser::RuleIdOrNull;
}


std::any SimpleViewParser::IdOrNullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitIdOrNull(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::IdOrNullContext* SimpleViewParser::idOrNull() {
  IdOrNullContext *_localctx = _tracker.createInstance<IdOrNullContext>(_ctx, getState());
  enterRule(_localctx, 10, SimpleViewParser::RuleIdOrNull);
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
    setState(270);
    _la = _input->LA(1);
    if (!(_la == SimpleViewParser::NULL_

    || _la == SimpleViewParser::IDENTIFIER)) {
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

//----------------- LineSegOrNodeExpContext ------------------------------------------------------------------

SimpleViewParser::LineSegOrNodeExpContext::LineSegOrNodeExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SimpleViewParser::NodeExpContext* SimpleViewParser::LineSegOrNodeExpContext::nodeExp() {
  return getRuleContext<SimpleViewParser::NodeExpContext>(0);
}

tree::TerminalNode* SimpleViewParser::LineSegOrNodeExpContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

std::vector<SimpleViewParser::IdOrNullContext *> SimpleViewParser::LineSegOrNodeExpContext::idOrNull() {
  return getRuleContexts<SimpleViewParser::IdOrNullContext>();
}

SimpleViewParser::IdOrNullContext* SimpleViewParser::LineSegOrNodeExpContext::idOrNull(size_t i) {
  return getRuleContext<SimpleViewParser::IdOrNullContext>(i);
}


size_t SimpleViewParser::LineSegOrNodeExpContext::getRuleIndex() const {
  return SimpleViewParser::RuleLineSegOrNodeExp;
}


std::any SimpleViewParser::LineSegOrNodeExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitLineSegOrNodeExp(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::LineSegOrNodeExpContext* SimpleViewParser::lineSegOrNodeExp() {
  LineSegOrNodeExpContext *_localctx = _tracker.createInstance<LineSegOrNodeExpContext>(_ctx, getState());
  enterRule(_localctx, 12, SimpleViewParser::RuleLineSegOrNodeExp);
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
    setState(283);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(272);
      match(SimpleViewParser::T__1);
      setState(273);
      antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->segName = match(SimpleViewParser::IDENTIFIER);
      setState(274);
      match(SimpleViewParser::T__3);
      break;
    }

    case 2: {
      setState(275);
      nodeExp(0);
      setState(281);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SimpleViewParser::T__9) {
        setState(276);
        match(SimpleViewParser::T__9);
        setState(277);
        antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->backward = idOrNull();
        setState(278);
        antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->forward = idOrNull();
        setState(279);
        match(SimpleViewParser::T__10);
      }
      break;
    }

    default:
      break;
    }
    setState(286);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0)) {
      setState(285);
      antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->wildcard = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 114688) != 0))) {
        antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->wildcard = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineArgumentListContext ------------------------------------------------------------------

SimpleViewParser::LineArgumentListContext::LineArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SimpleViewParser::LineArgumentListContext::IDENTIFIER() {
  return getTokens(SimpleViewParser::IDENTIFIER);
}

tree::TerminalNode* SimpleViewParser::LineArgumentListContext::IDENTIFIER(size_t i) {
  return getToken(SimpleViewParser::IDENTIFIER, i);
}


size_t SimpleViewParser::LineArgumentListContext::getRuleIndex() const {
  return SimpleViewParser::RuleLineArgumentList;
}


std::any SimpleViewParser::LineArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitLineArgumentList(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::LineArgumentListContext* SimpleViewParser::lineArgumentList() {
  LineArgumentListContext *_localctx = _tracker.createInstance<LineArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 14, SimpleViewParser::RuleLineArgumentList);
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
    setState(288);
    match(SimpleViewParser::T__4);
    setState(289);
    match(SimpleViewParser::IDENTIFIER);
    setState(294);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(290);
      match(SimpleViewParser::T__2);
      setState(291);
      match(SimpleViewParser::IDENTIFIER);
      setState(296);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(297);
    match(SimpleViewParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GraphElementContext ------------------------------------------------------------------

SimpleViewParser::GraphElementContext::GraphElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleViewParser::GraphElementContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

SimpleViewParser::LineArgumentListContext* SimpleViewParser::GraphElementContext::lineArgumentList() {
  return getRuleContext<SimpleViewParser::LineArgumentListContext>(0);
}


size_t SimpleViewParser::GraphElementContext::getRuleIndex() const {
  return SimpleViewParser::RuleGraphElement;
}


std::any SimpleViewParser::GraphElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitGraphElement(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::GraphElementContext* SimpleViewParser::graphElement() {
  GraphElementContext *_localctx = _tracker.createInstance<GraphElementContext>(_ctx, getState());
  enterRule(_localctx, 16, SimpleViewParser::RuleGraphElement);
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
    antlrcpp::downCast<GraphElementContext *>(_localctx)->lineName = match(SimpleViewParser::IDENTIFIER);
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleViewParser::T__4) {
      setState(300);
      lineArgumentList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GraphBodyContext ------------------------------------------------------------------

SimpleViewParser::GraphBodyContext::GraphBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleViewParser::GraphElementContext *> SimpleViewParser::GraphBodyContext::graphElement() {
  return getRuleContexts<SimpleViewParser::GraphElementContext>();
}

SimpleViewParser::GraphElementContext* SimpleViewParser::GraphBodyContext::graphElement(size_t i) {
  return getRuleContext<SimpleViewParser::GraphElementContext>(i);
}


size_t SimpleViewParser::GraphBodyContext::getRuleIndex() const {
  return SimpleViewParser::RuleGraphBody;
}


std::any SimpleViewParser::GraphBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitGraphBody(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::GraphBodyContext* SimpleViewParser::graphBody() {
  GraphBodyContext *_localctx = _tracker.createInstance<GraphBodyContext>(_ctx, getState());
  enterRule(_localctx, 18, SimpleViewParser::RuleGraphBody);
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
    setState(303);
    graphElement();
    setState(308);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(304);
      match(SimpleViewParser::T__2);
      setState(305);
      graphElement();
      setState(310);
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

//----------------- PointInLineContext ------------------------------------------------------------------

SimpleViewParser::PointInLineContext::PointInLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleViewParser::PointInLineContext *> SimpleViewParser::PointInLineContext::pointInLine() {
  return getRuleContexts<SimpleViewParser::PointInLineContext>();
}

SimpleViewParser::PointInLineContext* SimpleViewParser::PointInLineContext::pointInLine(size_t i) {
  return getRuleContext<SimpleViewParser::PointInLineContext>(i);
}

tree::TerminalNode* SimpleViewParser::PointInLineContext::INT() {
  return getToken(SimpleViewParser::INT, 0);
}


size_t SimpleViewParser::PointInLineContext::getRuleIndex() const {
  return SimpleViewParser::RulePointInLine;
}


std::any SimpleViewParser::PointInLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitPointInLine(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::PointInLineContext* SimpleViewParser::pointInLine() {
  PointInLineContext *_localctx = _tracker.createInstance<PointInLineContext>(_ctx, getState());
  enterRule(_localctx, 20, SimpleViewParser::RulePointInLine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(311);
        match(SimpleViewParser::T__1);
        setState(312);
        pointInLine();
        setState(317);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__2) {
          setState(313);
          match(SimpleViewParser::T__2);
          setState(314);
          pointInLine();
          setState(319);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(320);
        match(SimpleViewParser::T__3);
        break;
      }

      case SimpleViewParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(322);
        match(SimpleViewParser::INT);
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

//----------------- IntersectionPointContext ------------------------------------------------------------------

SimpleViewParser::IntersectionPointContext::IntersectionPointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleViewParser::PointInLineContext *> SimpleViewParser::IntersectionPointContext::pointInLine() {
  return getRuleContexts<SimpleViewParser::PointInLineContext>();
}

SimpleViewParser::PointInLineContext* SimpleViewParser::IntersectionPointContext::pointInLine(size_t i) {
  return getRuleContext<SimpleViewParser::PointInLineContext>(i);
}


size_t SimpleViewParser::IntersectionPointContext::getRuleIndex() const {
  return SimpleViewParser::RuleIntersectionPoint;
}


std::any SimpleViewParser::IntersectionPointContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitIntersectionPoint(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::IntersectionPointContext* SimpleViewParser::intersectionPoint() {
  IntersectionPointContext *_localctx = _tracker.createInstance<IntersectionPointContext>(_ctx, getState());
  enterRule(_localctx, 22, SimpleViewParser::RuleIntersectionPoint);
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
    setState(325);
    match(SimpleViewParser::T__16);
    setState(326);
    pointInLine();
    setState(331);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(327);
      match(SimpleViewParser::T__2);
      setState(328);
      pointInLine();
      setState(333);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(334);
    match(SimpleViewParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

SimpleViewParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SimpleViewParser::DeclarationContext::getRuleIndex() const {
  return SimpleViewParser::RuleDeclaration;
}

void SimpleViewParser::DeclarationContext::copyFrom(DeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- GraphDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* SimpleViewParser::GraphDeclarationContext::GRAPH() {
  return getToken(SimpleViewParser::GRAPH, 0);
}

SimpleViewParser::GraphBodyContext* SimpleViewParser::GraphDeclarationContext::graphBody() {
  return getRuleContext<SimpleViewParser::GraphBodyContext>(0);
}

tree::TerminalNode* SimpleViewParser::GraphDeclarationContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

SimpleViewParser::ParamListContext* SimpleViewParser::GraphDeclarationContext::paramList() {
  return getRuleContext<SimpleViewParser::ParamListContext>(0);
}

std::vector<SimpleViewParser::IntersectionPointContext *> SimpleViewParser::GraphDeclarationContext::intersectionPoint() {
  return getRuleContexts<SimpleViewParser::IntersectionPointContext>();
}

SimpleViewParser::IntersectionPointContext* SimpleViewParser::GraphDeclarationContext::intersectionPoint(size_t i) {
  return getRuleContext<SimpleViewParser::IntersectionPointContext>(i);
}

SimpleViewParser::GraphDeclarationContext::GraphDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::GraphDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitGraphDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassScopeDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* SimpleViewParser::ClassScopeDeclarationContext::CLASS_SCOPE() {
  return getToken(SimpleViewParser::CLASS_SCOPE, 0);
}

tree::TerminalNode* SimpleViewParser::ClassScopeDeclarationContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

SimpleViewParser::ClassScopeExpContext* SimpleViewParser::ClassScopeDeclarationContext::classScopeExp() {
  return getRuleContext<SimpleViewParser::ClassScopeExpContext>(0);
}

SimpleViewParser::ClassScopeDeclarationContext::ClassScopeDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::ClassScopeDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitClassScopeDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LineAndGraphInstanceContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> SimpleViewParser::LineAndGraphInstanceContext::IDENTIFIER() {
  return getTokens(SimpleViewParser::IDENTIFIER);
}

tree::TerminalNode* SimpleViewParser::LineAndGraphInstanceContext::IDENTIFIER(size_t i) {
  return getToken(SimpleViewParser::IDENTIFIER, i);
}

SimpleViewParser::LineArgumentListContext* SimpleViewParser::LineAndGraphInstanceContext::lineArgumentList() {
  return getRuleContext<SimpleViewParser::LineArgumentListContext>(0);
}

tree::TerminalNode* SimpleViewParser::LineAndGraphInstanceContext::LINE_INSTANCE() {
  return getToken(SimpleViewParser::LINE_INSTANCE, 0);
}

tree::TerminalNode* SimpleViewParser::LineAndGraphInstanceContext::GRAPH_INSTANCE() {
  return getToken(SimpleViewParser::GRAPH_INSTANCE, 0);
}

SimpleViewParser::LineAndGraphInstanceContext::LineAndGraphInstanceContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::LineAndGraphInstanceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitLineAndGraphInstance(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LineDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* SimpleViewParser::LineDeclarationContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

SimpleViewParser::LineExpContext* SimpleViewParser::LineDeclarationContext::lineExp() {
  return getRuleContext<SimpleViewParser::LineExpContext>(0);
}

tree::TerminalNode* SimpleViewParser::LineDeclarationContext::LINE() {
  return getToken(SimpleViewParser::LINE, 0);
}

tree::TerminalNode* SimpleViewParser::LineDeclarationContext::CODE_ORDER() {
  return getToken(SimpleViewParser::CODE_ORDER, 0);
}

tree::TerminalNode* SimpleViewParser::LineDeclarationContext::SEGMENT() {
  return getToken(SimpleViewParser::SEGMENT, 0);
}

SimpleViewParser::ParamListContext* SimpleViewParser::LineDeclarationContext::paramList() {
  return getRuleContext<SimpleViewParser::ParamListContext>(0);
}

SimpleViewParser::LineDeclarationContext::LineDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::LineDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitLineDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NodeDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* SimpleViewParser::NodeDeclarationContext::NODE() {
  return getToken(SimpleViewParser::NODE, 0);
}

tree::TerminalNode* SimpleViewParser::NodeDeclarationContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

SimpleViewParser::NodeExpContext* SimpleViewParser::NodeDeclarationContext::nodeExp() {
  return getRuleContext<SimpleViewParser::NodeExpContext>(0);
}

SimpleViewParser::NodeDeclarationContext::NodeDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::NodeDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitNodeDeclaration(this);
  else
    return visitor->visitChildren(this);
}
SimpleViewParser::DeclarationContext* SimpleViewParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 24, SimpleViewParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(368);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::CLASS_SCOPE: {
        _localctx = _tracker.createInstance<SimpleViewParser::ClassScopeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(336);
        match(SimpleViewParser::CLASS_SCOPE);
        setState(337);
        match(SimpleViewParser::IDENTIFIER);
        setState(338);
        match(SimpleViewParser::T__18);
        setState(339);
        classScopeExp(0);
        break;
      }

      case SimpleViewParser::NODE: {
        _localctx = _tracker.createInstance<SimpleViewParser::NodeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(340);
        match(SimpleViewParser::NODE);
        setState(341);
        match(SimpleViewParser::IDENTIFIER);
        setState(342);
        match(SimpleViewParser::T__18);
        setState(343);
        nodeExp(0);
        break;
      }

      case SimpleViewParser::SEGMENT:
      case SimpleViewParser::LINE:
      case SimpleViewParser::CODE_ORDER: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(344);
        _la = _input->LA(1);
        if (!(((((_la - 77) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 77)) & 35) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(345);
        match(SimpleViewParser::IDENTIFIER);
        setState(347);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__4) {
          setState(346);
          paramList();
        }
        setState(349);
        match(SimpleViewParser::T__18);
        setState(350);
        lineExp();
        break;
      }

      case SimpleViewParser::GRAPH: {
        _localctx = _tracker.createInstance<SimpleViewParser::GraphDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(351);
        match(SimpleViewParser::GRAPH);
        setState(352);
        antlrcpp::downCast<GraphDeclarationContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
        setState(354);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__4) {
          setState(353);
          paramList();
        }
        setState(356);
        match(SimpleViewParser::T__18);
        setState(357);
        graphBody();
        setState(359); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(358);
          intersectionPoint();
          setState(361); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SimpleViewParser::T__16);
        break;
      }

      case SimpleViewParser::LINE_INSTANCE:
      case SimpleViewParser::GRAPH_INSTANCE: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineAndGraphInstanceContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(363);
        _la = _input->LA(1);
        if (!(_la == SimpleViewParser::LINE_INSTANCE

        || _la == SimpleViewParser::GRAPH_INSTANCE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(364);
        match(SimpleViewParser::IDENTIFIER);
        setState(365);
        match(SimpleViewParser::T__18);
        setState(366);
        match(SimpleViewParser::IDENTIFIER);
        setState(367);
        lineArgumentList();
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

//----------------- ShowCommandContext ------------------------------------------------------------------

SimpleViewParser::ShowCommandContext::ShowCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleViewParser::ShowCommandContext::SHOW() {
  return getToken(SimpleViewParser::SHOW, 0);
}

std::vector<tree::TerminalNode *> SimpleViewParser::ShowCommandContext::IDENTIFIER() {
  return getTokens(SimpleViewParser::IDENTIFIER);
}

tree::TerminalNode* SimpleViewParser::ShowCommandContext::IDENTIFIER(size_t i) {
  return getToken(SimpleViewParser::IDENTIFIER, i);
}


size_t SimpleViewParser::ShowCommandContext::getRuleIndex() const {
  return SimpleViewParser::RuleShowCommand;
}


std::any SimpleViewParser::ShowCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitShowCommand(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::ShowCommandContext* SimpleViewParser::showCommand() {
  ShowCommandContext *_localctx = _tracker.createInstance<ShowCommandContext>(_ctx, getState());
  enterRule(_localctx, 26, SimpleViewParser::RuleShowCommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    match(SimpleViewParser::SHOW);
    setState(371);
    match(SimpleViewParser::T__4);
    setState(372);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
    setState(373);
    match(SimpleViewParser::T__2);
    setState(374);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->defaultStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(375);
    match(SimpleViewParser::T__2);
    setState(376);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->basicStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(377);
    match(SimpleViewParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SimpleViewParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return classScopeExpSempred(antlrcpp::downCast<ClassScopeExpContext *>(context), predicateIndex);
    case 2: return nodeExpSempred(antlrcpp::downCast<NodeExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SimpleViewParser::classScopeExpSempred(ClassScopeExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool SimpleViewParser::nodeExpSempred(NodeExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 31);
    case 4: return precpred(_ctx, 30);
    case 5: return precpred(_ctx, 29);

  default:
    break;
  }
  return true;
}

void SimpleViewParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  simpleviewParserInitialize();
#else
  ::antlr4::internal::call_once(simpleviewParserOnceFlag, simpleviewParserInitialize);
#endif
}
