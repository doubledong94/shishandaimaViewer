
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
      "'read'", "'write'", "'Anonymous'", "'inPackage'", "'classOf'", "'superOf'", 
      "'subOf'", "'Style'", "'DefaultStyle'", "'BasicStyle'", "'ClassScope'", 
      "'Node'", "'Reference'", "'VoidRef'", "'Condition'", "'Else'", "'DataStep'", 
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
      "READ", "WRITE", "ANONYMOUS", "IN_PACKAGE", "CLASS_OF", "SUPER", "SUB", 
      "STYLE", "DEFAULT_STYLE", "BASIC_STYLE", "CLASS_SCOPE", "NODE", "REFERENCE", 
      "VOID_REF", "CONDITION", "ELSE", "DATA_STEP", "TIMING_STEP", "DATA_OVERRIDE", 
      "TIMING_OVERRIDE", "LV", "FIELD", "METHOD", "CONSTRUCTOR", "CALLED_METHOD", 
      "PARAMETER", "CALLED_PARAMETER", "RETURN", "CALLED_RETURN", "INDEX", 
      "ERROR", "FIELD_CONNECTION", "SEGMENT", "LINE", "LINE_INSTANCE", "GRAPH", 
      "GRAPH_INSTANCE", "CODE_ORDER", "NULL", "SHOW", "STRING", "IDENTIFIER", 
      "FLOAT", "INT", "WS", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,91,393,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,1,0,
  	1,0,4,0,32,8,0,11,0,12,0,33,1,0,1,0,1,0,5,0,39,8,0,10,0,12,0,42,9,0,1,
  	1,1,1,1,1,1,1,1,1,5,1,49,8,1,10,1,12,1,52,9,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1,72,8,1,11,1,12,1,
  	73,1,1,1,1,1,1,4,1,79,8,1,11,1,12,1,80,1,1,1,1,1,1,4,1,86,8,1,11,1,12,
  	1,87,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,98,8,1,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,114,8,2,10,2,12,2,117,9,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,4,2,195,8,2,11,2,12,2,196,1,2,1,2,1,2,4,2,202,8,2,11,
  	2,12,2,203,1,2,1,2,1,2,4,2,209,8,2,11,2,12,2,210,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,3,2,255,8,2,1,3,1,3,1,3,1,3,5,3,261,8,3,10,3,12,3,264,9,3,1,3,
  	1,3,1,4,1,4,1,4,4,4,271,8,4,11,4,12,4,272,1,4,1,4,1,4,4,4,278,8,4,11,
  	4,12,4,279,3,4,282,8,4,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,
  	6,295,8,6,3,6,297,8,6,1,6,3,6,300,8,6,1,7,1,7,1,7,1,7,5,7,306,8,7,10,
  	7,12,7,309,9,7,1,7,1,7,1,8,1,8,3,8,315,8,8,1,9,1,9,1,9,5,9,320,8,9,10,
  	9,12,9,323,9,9,1,10,1,10,1,10,1,10,5,10,329,8,10,10,10,12,10,332,9,10,
  	1,10,1,10,1,10,3,10,337,8,10,1,11,1,11,1,11,1,11,5,11,343,8,11,10,11,
  	12,11,346,9,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,3,12,361,8,12,1,12,1,12,1,12,1,12,1,12,3,12,368,8,12,1,12,1,
  	12,1,12,4,12,373,8,12,11,12,12,12,374,1,12,1,12,1,12,1,12,1,12,3,12,382,
  	8,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,0,0,14,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,0,4,2,0,84,84,87,87,1,0,14,16,2,0,78,79,
  	83,83,2,0,80,80,82,82,465,0,31,1,0,0,0,2,97,1,0,0,0,4,254,1,0,0,0,6,256,
  	1,0,0,0,8,281,1,0,0,0,10,283,1,0,0,0,12,296,1,0,0,0,14,301,1,0,0,0,16,
  	312,1,0,0,0,18,316,1,0,0,0,20,336,1,0,0,0,22,338,1,0,0,0,24,381,1,0,0,
  	0,26,383,1,0,0,0,28,29,3,24,12,0,29,30,5,1,0,0,30,32,1,0,0,0,31,28,1,
  	0,0,0,32,33,1,0,0,0,33,31,1,0,0,0,33,34,1,0,0,0,34,40,1,0,0,0,35,36,3,
  	26,13,0,36,37,5,1,0,0,37,39,1,0,0,0,38,35,1,0,0,0,39,42,1,0,0,0,40,38,
  	1,0,0,0,40,41,1,0,0,0,41,1,1,0,0,0,42,40,1,0,0,0,43,98,5,86,0,0,44,45,
  	5,2,0,0,45,50,5,86,0,0,46,47,5,3,0,0,47,49,5,86,0,0,48,46,1,0,0,0,49,
  	52,1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,53,1,0,0,0,52,50,1,0,0,0,53,
  	98,5,4,0,0,54,55,5,49,0,0,55,56,5,5,0,0,56,57,5,86,0,0,57,98,5,6,0,0,
  	58,59,5,51,0,0,59,60,5,5,0,0,60,61,3,2,1,0,61,62,5,6,0,0,62,98,1,0,0,
  	0,63,64,5,52,0,0,64,65,5,5,0,0,65,66,3,2,1,0,66,67,5,6,0,0,67,98,1,0,
  	0,0,68,71,5,87,0,0,69,70,5,7,0,0,70,72,5,87,0,0,71,69,1,0,0,0,72,73,1,
  	0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,98,1,0,0,0,75,78,5,87,0,0,76,77,
  	5,8,0,0,77,79,5,87,0,0,78,76,1,0,0,0,79,80,1,0,0,0,80,78,1,0,0,0,80,81,
  	1,0,0,0,81,98,1,0,0,0,82,85,5,87,0,0,83,84,5,9,0,0,84,86,5,87,0,0,85,
  	83,1,0,0,0,86,87,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,98,1,0,0,0,89,
  	90,5,5,0,0,90,91,3,2,1,0,91,92,5,6,0,0,92,98,1,0,0,0,93,98,5,87,0,0,94,
  	95,5,10,0,0,95,96,5,87,0,0,96,98,5,11,0,0,97,43,1,0,0,0,97,44,1,0,0,0,
  	97,54,1,0,0,0,97,58,1,0,0,0,97,63,1,0,0,0,97,68,1,0,0,0,97,75,1,0,0,0,
  	97,82,1,0,0,0,97,89,1,0,0,0,97,93,1,0,0,0,97,94,1,0,0,0,98,3,1,0,0,0,
  	99,100,5,86,0,0,100,101,5,5,0,0,101,102,5,86,0,0,102,255,5,6,0,0,103,
  	104,5,2,0,0,104,105,5,86,0,0,105,106,5,5,0,0,106,107,5,86,0,0,107,115,
  	5,6,0,0,108,109,5,3,0,0,109,110,5,86,0,0,110,111,5,5,0,0,111,112,5,86,
  	0,0,112,114,5,6,0,0,113,108,1,0,0,0,114,117,1,0,0,0,115,113,1,0,0,0,115,
  	116,1,0,0,0,116,118,1,0,0,0,117,115,1,0,0,0,118,255,5,4,0,0,119,120,5,
  	34,0,0,120,121,5,5,0,0,121,122,3,2,1,0,122,123,5,6,0,0,123,255,1,0,0,
  	0,124,125,5,36,0,0,125,126,5,5,0,0,126,127,3,2,1,0,127,128,5,6,0,0,128,
  	255,1,0,0,0,129,130,5,38,0,0,130,131,5,5,0,0,131,132,3,4,2,0,132,133,
  	5,6,0,0,133,255,1,0,0,0,134,135,5,39,0,0,135,136,5,5,0,0,136,137,3,4,
  	2,0,137,138,5,6,0,0,138,255,1,0,0,0,139,140,5,35,0,0,140,141,5,5,0,0,
  	141,142,3,2,1,0,142,143,5,3,0,0,143,144,3,2,1,0,144,145,5,6,0,0,145,255,
  	1,0,0,0,146,147,5,37,0,0,147,148,5,5,0,0,148,149,3,2,1,0,149,150,5,6,
  	0,0,150,255,1,0,0,0,151,152,5,51,0,0,152,153,5,5,0,0,153,154,3,4,2,0,
  	154,155,5,6,0,0,155,255,1,0,0,0,156,157,5,52,0,0,157,158,5,5,0,0,158,
  	159,3,4,2,0,159,160,5,6,0,0,160,255,1,0,0,0,161,162,5,42,0,0,162,163,
  	5,5,0,0,163,164,3,4,2,0,164,165,5,6,0,0,165,255,1,0,0,0,166,167,5,40,
  	0,0,167,168,5,5,0,0,168,169,3,4,2,0,169,170,5,6,0,0,170,255,1,0,0,0,171,
  	172,5,41,0,0,172,173,5,5,0,0,173,174,3,4,2,0,174,175,5,6,0,0,175,255,
  	1,0,0,0,176,177,5,43,0,0,177,178,5,5,0,0,178,179,3,4,2,0,179,180,5,6,
  	0,0,180,255,1,0,0,0,181,182,5,44,0,0,182,183,5,5,0,0,183,184,3,4,2,0,
  	184,185,5,6,0,0,185,255,1,0,0,0,186,187,5,45,0,0,187,188,5,5,0,0,188,
  	189,3,4,2,0,189,190,5,6,0,0,190,255,1,0,0,0,191,194,5,87,0,0,192,193,
  	5,8,0,0,193,195,5,87,0,0,194,192,1,0,0,0,195,196,1,0,0,0,196,194,1,0,
  	0,0,196,197,1,0,0,0,197,255,1,0,0,0,198,201,5,87,0,0,199,200,5,7,0,0,
  	200,202,5,87,0,0,201,199,1,0,0,0,202,203,1,0,0,0,203,201,1,0,0,0,203,
  	204,1,0,0,0,204,255,1,0,0,0,205,208,5,87,0,0,206,207,5,9,0,0,207,209,
  	5,87,0,0,208,206,1,0,0,0,209,210,1,0,0,0,210,208,1,0,0,0,210,211,1,0,
  	0,0,211,255,1,0,0,0,212,213,5,46,0,0,213,214,5,5,0,0,214,215,3,4,2,0,
  	215,216,5,6,0,0,216,255,1,0,0,0,217,218,5,47,0,0,218,219,5,5,0,0,219,
  	220,3,4,2,0,220,221,5,6,0,0,221,255,1,0,0,0,222,255,5,31,0,0,223,255,
  	5,32,0,0,224,255,5,33,0,0,225,255,5,58,0,0,226,255,5,59,0,0,227,255,5,
  	60,0,0,228,255,5,61,0,0,229,255,5,62,0,0,230,255,5,63,0,0,231,255,5,64,
  	0,0,232,255,5,65,0,0,233,255,5,66,0,0,234,255,5,67,0,0,235,255,5,68,0,
  	0,236,255,5,69,0,0,237,255,5,70,0,0,238,255,5,71,0,0,239,255,5,72,0,0,
  	240,255,5,73,0,0,241,255,5,74,0,0,242,255,5,75,0,0,243,255,5,48,0,0,244,
  	255,5,76,0,0,245,255,5,77,0,0,246,247,5,5,0,0,247,248,3,4,2,0,248,249,
  	5,6,0,0,249,255,1,0,0,0,250,255,5,87,0,0,251,252,5,10,0,0,252,253,5,87,
  	0,0,253,255,5,11,0,0,254,99,1,0,0,0,254,103,1,0,0,0,254,119,1,0,0,0,254,
  	124,1,0,0,0,254,129,1,0,0,0,254,134,1,0,0,0,254,139,1,0,0,0,254,146,1,
  	0,0,0,254,151,1,0,0,0,254,156,1,0,0,0,254,161,1,0,0,0,254,166,1,0,0,0,
  	254,171,1,0,0,0,254,176,1,0,0,0,254,181,1,0,0,0,254,186,1,0,0,0,254,191,
  	1,0,0,0,254,198,1,0,0,0,254,205,1,0,0,0,254,212,1,0,0,0,254,217,1,0,0,
  	0,254,222,1,0,0,0,254,223,1,0,0,0,254,224,1,0,0,0,254,225,1,0,0,0,254,
  	226,1,0,0,0,254,227,1,0,0,0,254,228,1,0,0,0,254,229,1,0,0,0,254,230,1,
  	0,0,0,254,231,1,0,0,0,254,232,1,0,0,0,254,233,1,0,0,0,254,234,1,0,0,0,
  	254,235,1,0,0,0,254,236,1,0,0,0,254,237,1,0,0,0,254,238,1,0,0,0,254,239,
  	1,0,0,0,254,240,1,0,0,0,254,241,1,0,0,0,254,242,1,0,0,0,254,243,1,0,0,
  	0,254,244,1,0,0,0,254,245,1,0,0,0,254,246,1,0,0,0,254,250,1,0,0,0,254,
  	251,1,0,0,0,255,5,1,0,0,0,256,257,5,5,0,0,257,262,5,87,0,0,258,259,5,
  	3,0,0,259,261,5,87,0,0,260,258,1,0,0,0,261,264,1,0,0,0,262,260,1,0,0,
  	0,262,263,1,0,0,0,263,265,1,0,0,0,264,262,1,0,0,0,265,266,5,6,0,0,266,
  	7,1,0,0,0,267,270,3,12,6,0,268,269,5,12,0,0,269,271,3,12,6,0,270,268,
  	1,0,0,0,271,272,1,0,0,0,272,270,1,0,0,0,272,273,1,0,0,0,273,282,1,0,0,
  	0,274,277,3,12,6,0,275,276,5,13,0,0,276,278,3,12,6,0,277,275,1,0,0,0,
  	278,279,1,0,0,0,279,277,1,0,0,0,279,280,1,0,0,0,280,282,1,0,0,0,281,267,
  	1,0,0,0,281,274,1,0,0,0,282,9,1,0,0,0,283,284,7,0,0,0,284,11,1,0,0,0,
  	285,286,5,2,0,0,286,287,5,87,0,0,287,297,5,4,0,0,288,294,3,4,2,0,289,
  	290,5,10,0,0,290,291,3,10,5,0,291,292,3,10,5,0,292,293,5,11,0,0,293,295,
  	1,0,0,0,294,289,1,0,0,0,294,295,1,0,0,0,295,297,1,0,0,0,296,285,1,0,0,
  	0,296,288,1,0,0,0,297,299,1,0,0,0,298,300,7,1,0,0,299,298,1,0,0,0,299,
  	300,1,0,0,0,300,13,1,0,0,0,301,302,5,5,0,0,302,307,5,87,0,0,303,304,5,
  	3,0,0,304,306,5,87,0,0,305,303,1,0,0,0,306,309,1,0,0,0,307,305,1,0,0,
  	0,307,308,1,0,0,0,308,310,1,0,0,0,309,307,1,0,0,0,310,311,5,6,0,0,311,
  	15,1,0,0,0,312,314,5,87,0,0,313,315,3,14,7,0,314,313,1,0,0,0,314,315,
  	1,0,0,0,315,17,1,0,0,0,316,321,3,16,8,0,317,318,5,3,0,0,318,320,3,16,
  	8,0,319,317,1,0,0,0,320,323,1,0,0,0,321,319,1,0,0,0,321,322,1,0,0,0,322,
  	19,1,0,0,0,323,321,1,0,0,0,324,325,5,2,0,0,325,330,3,20,10,0,326,327,
  	5,3,0,0,327,329,3,20,10,0,328,326,1,0,0,0,329,332,1,0,0,0,330,328,1,0,
  	0,0,330,331,1,0,0,0,331,333,1,0,0,0,332,330,1,0,0,0,333,334,5,4,0,0,334,
  	337,1,0,0,0,335,337,5,89,0,0,336,324,1,0,0,0,336,335,1,0,0,0,337,21,1,
  	0,0,0,338,339,5,17,0,0,339,344,3,20,10,0,340,341,5,3,0,0,341,343,3,20,
  	10,0,342,340,1,0,0,0,343,346,1,0,0,0,344,342,1,0,0,0,344,345,1,0,0,0,
  	345,347,1,0,0,0,346,344,1,0,0,0,347,348,5,18,0,0,348,23,1,0,0,0,349,350,
  	5,56,0,0,350,351,5,87,0,0,351,352,5,19,0,0,352,382,3,2,1,0,353,354,5,
  	57,0,0,354,355,5,87,0,0,355,356,5,19,0,0,356,382,3,4,2,0,357,358,7,2,
  	0,0,358,360,5,87,0,0,359,361,3,6,3,0,360,359,1,0,0,0,360,361,1,0,0,0,
  	361,362,1,0,0,0,362,363,5,19,0,0,363,382,3,8,4,0,364,365,5,81,0,0,365,
  	367,5,87,0,0,366,368,3,6,3,0,367,366,1,0,0,0,367,368,1,0,0,0,368,369,
  	1,0,0,0,369,370,5,19,0,0,370,372,3,18,9,0,371,373,3,22,11,0,372,371,1,
  	0,0,0,373,374,1,0,0,0,374,372,1,0,0,0,374,375,1,0,0,0,375,382,1,0,0,0,
  	376,377,7,3,0,0,377,378,5,87,0,0,378,379,5,19,0,0,379,380,5,87,0,0,380,
  	382,3,14,7,0,381,349,1,0,0,0,381,353,1,0,0,0,381,357,1,0,0,0,381,364,
  	1,0,0,0,381,376,1,0,0,0,382,25,1,0,0,0,383,384,5,85,0,0,384,385,5,5,0,
  	0,385,386,5,87,0,0,386,387,5,3,0,0,387,388,5,87,0,0,388,389,5,3,0,0,389,
  	390,5,87,0,0,390,391,5,6,0,0,391,27,1,0,0,0,29,33,40,50,73,80,87,97,115,
  	196,203,210,254,262,272,279,281,294,296,299,307,314,321,330,336,344,360,
  	367,374,381
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
    } while (((((_la - 56) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 56)) & 264241155) != 0));
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

SimpleViewParser::ClassScopeExpContext* SimpleViewParser::ClassScopeExpContext::classScopeExp() {
  return getRuleContext<SimpleViewParser::ClassScopeExpContext>(0);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::SUB() {
  return getToken(SimpleViewParser::SUB, 0);
}

std::vector<tree::TerminalNode *> SimpleViewParser::ClassScopeExpContext::IDENTIFIER() {
  return getTokens(SimpleViewParser::IDENTIFIER);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::IDENTIFIER(size_t i) {
  return getToken(SimpleViewParser::IDENTIFIER, i);
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
  ClassScopeExpContext *_localctx = _tracker.createInstance<ClassScopeExpContext>(_ctx, getState());
  enterRule(_localctx, 2, SimpleViewParser::RuleClassScopeExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(43);
      antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKey = match(SimpleViewParser::STRING);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(44);
      antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKeyList = match(SimpleViewParser::T__1);
      setState(45);
      match(SimpleViewParser::STRING);
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SimpleViewParser::T__2) {
        setState(46);
        match(SimpleViewParser::T__2);
        setState(47);
        match(SimpleViewParser::STRING);
        setState(52);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(53);
      match(SimpleViewParser::T__3);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(54);
      match(SimpleViewParser::IN_PACKAGE);
      setState(55);
      match(SimpleViewParser::T__4);
      setState(56);
      antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->packageStr = match(SimpleViewParser::STRING);
      setState(57);
      match(SimpleViewParser::T__5);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(58);
      match(SimpleViewParser::SUPER);
      setState(59);
      match(SimpleViewParser::T__4);
      setState(60);
      classScopeExp();
      setState(61);
      match(SimpleViewParser::T__5);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(63);
      match(SimpleViewParser::SUB);
      setState(64);
      match(SimpleViewParser::T__4);
      setState(65);
      classScopeExp();
      setState(66);
      match(SimpleViewParser::T__5);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(68);
      match(SimpleViewParser::IDENTIFIER);
      setState(71); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(69);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__6);
        setState(70);
        match(SimpleViewParser::IDENTIFIER);
        setState(73); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__6);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(75);
      match(SimpleViewParser::IDENTIFIER);
      setState(78); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(76);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__7);
        setState(77);
        match(SimpleViewParser::IDENTIFIER);
        setState(80); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__7);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(82);
      match(SimpleViewParser::IDENTIFIER);
      setState(85); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(83);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__8);
        setState(84);
        match(SimpleViewParser::IDENTIFIER);
        setState(87); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__8);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(89);
      match(SimpleViewParser::T__4);
      setState(90);
      antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->bracket = classScopeExp();
      setState(91);
      match(SimpleViewParser::T__5);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(93);
      antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->refOtherScope = match(SimpleViewParser::IDENTIFIER);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(94);
      antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->varClass = match(SimpleViewParser::T__9);
      setState(95);
      match(SimpleViewParser::IDENTIFIER);
      setState(96);
      match(SimpleViewParser::T__10);
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

SimpleViewParser::NodeExpContext* SimpleViewParser::NodeExpContext::nodeExp() {
  return getRuleContext<SimpleViewParser::NodeExpContext>(0);
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

std::vector<tree::TerminalNode *> SimpleViewParser::NodeExpContext::IDENTIFIER() {
  return getTokens(SimpleViewParser::IDENTIFIER);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::IDENTIFIER(size_t i) {
  return getToken(SimpleViewParser::IDENTIFIER, i);
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

tree::TerminalNode* SimpleViewParser::NodeExpContext::ANONYMOUS() {
  return getToken(SimpleViewParser::ANONYMOUS, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::ERROR() {
  return getToken(SimpleViewParser::ERROR, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::FIELD_CONNECTION() {
  return getToken(SimpleViewParser::FIELD_CONNECTION, 0);
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
  NodeExpContext *_localctx = _tracker.createInstance<NodeExpContext>(_ctx, getState());
  enterRule(_localctx, 4, SimpleViewParser::RuleNodeExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(254);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(99);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKey = match(SimpleViewParser::STRING);
      setState(100);
      match(SimpleViewParser::T__4);
      setState(101);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->typeKey = match(SimpleViewParser::STRING);
      setState(102);
      match(SimpleViewParser::T__5);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKeyList = match(SimpleViewParser::T__1);
      setState(104);
      match(SimpleViewParser::STRING);
      setState(105);
      match(SimpleViewParser::T__4);
      setState(106);
      match(SimpleViewParser::STRING);
      setState(107);
      match(SimpleViewParser::T__5);
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SimpleViewParser::T__2) {
        setState(108);
        match(SimpleViewParser::T__2);
        setState(109);
        match(SimpleViewParser::STRING);
        setState(110);
        match(SimpleViewParser::T__4);
        setState(111);
        match(SimpleViewParser::STRING);
        setState(112);
        match(SimpleViewParser::T__5);
        setState(117);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(118);
      match(SimpleViewParser::T__3);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(119);
      match(SimpleViewParser::FIELD_OF);
      setState(120);
      match(SimpleViewParser::T__4);
      setState(121);
      classScopeExp();
      setState(122);
      match(SimpleViewParser::T__5);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      match(SimpleViewParser::METHOD_OF);
      setState(125);
      match(SimpleViewParser::T__4);
      setState(126);
      classScopeExp();
      setState(127);
      match(SimpleViewParser::T__5);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(129);
      match(SimpleViewParser::PARAMETER_OF);
      setState(130);
      match(SimpleViewParser::T__4);
      setState(131);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp();
      setState(132);
      match(SimpleViewParser::T__5);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(134);
      match(SimpleViewParser::RETURN_OF);
      setState(135);
      match(SimpleViewParser::T__4);
      setState(136);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp();
      setState(137);
      match(SimpleViewParser::T__5);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(139);
      match(SimpleViewParser::INSTANCE_OF);
      setState(140);
      match(SimpleViewParser::T__4);
      setState(141);
      classScopeExp();
      setState(142);
      match(SimpleViewParser::T__2);
      setState(143);
      classScopeExp();
      setState(144);
      match(SimpleViewParser::T__5);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(146);
      match(SimpleViewParser::CREATOR);
      setState(147);
      match(SimpleViewParser::T__4);
      setState(148);
      classScopeExp();
      setState(149);
      match(SimpleViewParser::T__5);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(151);
      match(SimpleViewParser::SUPER);
      setState(152);
      match(SimpleViewParser::T__4);
      setState(153);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp();
      setState(154);
      match(SimpleViewParser::T__5);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(156);
      match(SimpleViewParser::SUB);
      setState(157);
      match(SimpleViewParser::T__4);
      setState(158);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp();
      setState(159);
      match(SimpleViewParser::T__5);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(161);
      match(SimpleViewParser::CALLED_METHOD_OF);
      setState(162);
      match(SimpleViewParser::T__4);
      setState(163);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp();
      setState(164);
      match(SimpleViewParser::T__5);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(166);
      match(SimpleViewParser::CALLED_PARAM_OF);
      setState(167);
      match(SimpleViewParser::T__4);
      setState(168);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->paramNode = nodeExp();
      setState(169);
      match(SimpleViewParser::T__5);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(171);
      match(SimpleViewParser::CALLED_RETURN_OF);
      setState(172);
      match(SimpleViewParser::T__4);
      setState(173);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->returnNode = nodeExp();
      setState(174);
      match(SimpleViewParser::T__5);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(176);
      match(SimpleViewParser::METHOD_USED_BY);
      setState(177);
      match(SimpleViewParser::T__4);
      setState(178);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp();
      setState(179);
      match(SimpleViewParser::T__5);
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(181);
      match(SimpleViewParser::FIELD_USED_BY);
      setState(182);
      match(SimpleViewParser::T__4);
      setState(183);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp();
      setState(184);
      match(SimpleViewParser::T__5);
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(186);
      match(SimpleViewParser::METHOD_USE);
      setState(187);
      match(SimpleViewParser::T__4);
      setState(188);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp();
      setState(189);
      match(SimpleViewParser::T__5);
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(191);
      match(SimpleViewParser::IDENTIFIER);
      setState(194); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(192);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__7);
        setState(193);
        match(SimpleViewParser::IDENTIFIER);
        setState(196); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__7);
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(198);
      match(SimpleViewParser::IDENTIFIER);
      setState(201); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(199);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__6);
        setState(200);
        match(SimpleViewParser::IDENTIFIER);
        setState(203); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__6);
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(205);
      match(SimpleViewParser::IDENTIFIER);
      setState(208); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(206);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__8);
        setState(207);
        match(SimpleViewParser::IDENTIFIER);
        setState(210); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__8);
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(212);
      match(SimpleViewParser::READ);
      setState(213);
      match(SimpleViewParser::T__4);
      setState(214);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->read = nodeExp();
      setState(215);
      match(SimpleViewParser::T__5);
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(217);
      match(SimpleViewParser::WRITE);
      setState(218);
      match(SimpleViewParser::T__4);
      setState(219);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->write = nodeExp();
      setState(220);
      match(SimpleViewParser::T__5);
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(222);
      match(SimpleViewParser::ANY);
      break;
    }

    case 23: {
      enterOuterAlt(_localctx, 23);
      setState(223);
      match(SimpleViewParser::FINAL);
      break;
    }

    case 24: {
      enterOuterAlt(_localctx, 24);
      setState(224);
      match(SimpleViewParser::CLASS);
      break;
    }

    case 25: {
      enterOuterAlt(_localctx, 25);
      setState(225);
      match(SimpleViewParser::REFERENCE);
      break;
    }

    case 26: {
      enterOuterAlt(_localctx, 26);
      setState(226);
      match(SimpleViewParser::VOID_REF);
      break;
    }

    case 27: {
      enterOuterAlt(_localctx, 27);
      setState(227);
      match(SimpleViewParser::CONDITION);
      break;
    }

    case 28: {
      enterOuterAlt(_localctx, 28);
      setState(228);
      match(SimpleViewParser::ELSE);
      break;
    }

    case 29: {
      enterOuterAlt(_localctx, 29);
      setState(229);
      match(SimpleViewParser::DATA_STEP);
      break;
    }

    case 30: {
      enterOuterAlt(_localctx, 30);
      setState(230);
      match(SimpleViewParser::TIMING_STEP);
      break;
    }

    case 31: {
      enterOuterAlt(_localctx, 31);
      setState(231);
      match(SimpleViewParser::DATA_OVERRIDE);
      break;
    }

    case 32: {
      enterOuterAlt(_localctx, 32);
      setState(232);
      match(SimpleViewParser::TIMING_OVERRIDE);
      break;
    }

    case 33: {
      enterOuterAlt(_localctx, 33);
      setState(233);
      match(SimpleViewParser::LV);
      break;
    }

    case 34: {
      enterOuterAlt(_localctx, 34);
      setState(234);
      match(SimpleViewParser::FIELD);
      break;
    }

    case 35: {
      enterOuterAlt(_localctx, 35);
      setState(235);
      match(SimpleViewParser::METHOD);
      break;
    }

    case 36: {
      enterOuterAlt(_localctx, 36);
      setState(236);
      match(SimpleViewParser::CONSTRUCTOR);
      break;
    }

    case 37: {
      enterOuterAlt(_localctx, 37);
      setState(237);
      match(SimpleViewParser::CALLED_METHOD);
      break;
    }

    case 38: {
      enterOuterAlt(_localctx, 38);
      setState(238);
      match(SimpleViewParser::PARAMETER);
      break;
    }

    case 39: {
      enterOuterAlt(_localctx, 39);
      setState(239);
      match(SimpleViewParser::CALLED_PARAMETER);
      break;
    }

    case 40: {
      enterOuterAlt(_localctx, 40);
      setState(240);
      match(SimpleViewParser::RETURN);
      break;
    }

    case 41: {
      enterOuterAlt(_localctx, 41);
      setState(241);
      match(SimpleViewParser::CALLED_RETURN);
      break;
    }

    case 42: {
      enterOuterAlt(_localctx, 42);
      setState(242);
      match(SimpleViewParser::INDEX);
      break;
    }

    case 43: {
      enterOuterAlt(_localctx, 43);
      setState(243);
      match(SimpleViewParser::ANONYMOUS);
      break;
    }

    case 44: {
      enterOuterAlt(_localctx, 44);
      setState(244);
      match(SimpleViewParser::ERROR);
      break;
    }

    case 45: {
      enterOuterAlt(_localctx, 45);
      setState(245);
      match(SimpleViewParser::FIELD_CONNECTION);
      break;
    }

    case 46: {
      enterOuterAlt(_localctx, 46);
      setState(246);
      match(SimpleViewParser::T__4);
      setState(247);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->bracket = nodeExp();
      setState(248);
      match(SimpleViewParser::T__5);
      break;
    }

    case 47: {
      enterOuterAlt(_localctx, 47);
      setState(250);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->refOtherNode = match(SimpleViewParser::IDENTIFIER);
      break;
    }

    case 48: {
      enterOuterAlt(_localctx, 48);
      setState(251);
      antlrcpp::downCast<NodeExpContext *>(_localctx)->varNode = match(SimpleViewParser::T__9);
      setState(252);
      match(SimpleViewParser::IDENTIFIER);
      setState(253);
      match(SimpleViewParser::T__10);
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
    setState(256);
    match(SimpleViewParser::T__4);
    setState(257);
    match(SimpleViewParser::IDENTIFIER);
    setState(262);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(258);
      match(SimpleViewParser::T__2);
      setState(259);
      match(SimpleViewParser::IDENTIFIER);
      setState(264);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(265);
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
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(267);
      lineSegOrNodeExp();
      setState(270); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(268);
        antlrcpp::downCast<LineExpContext *>(_localctx)->seq = match(SimpleViewParser::T__11);
        setState(269);
        lineSegOrNodeExp();
        setState(272); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__11);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(274);
      lineSegOrNodeExp();
      setState(277); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(275);
        antlrcpp::downCast<LineExpContext *>(_localctx)->alt = match(SimpleViewParser::T__12);
        setState(276);
        lineSegOrNodeExp();
        setState(279); 
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
    setState(283);
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
    setState(296);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(285);
      match(SimpleViewParser::T__1);
      setState(286);
      antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->segName = match(SimpleViewParser::IDENTIFIER);
      setState(287);
      match(SimpleViewParser::T__3);
      break;
    }

    case 2: {
      setState(288);
      nodeExp();
      setState(294);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SimpleViewParser::T__9) {
        setState(289);
        match(SimpleViewParser::T__9);
        setState(290);
        antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->backward = idOrNull();
        setState(291);
        antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->forward = idOrNull();
        setState(292);
        match(SimpleViewParser::T__10);
      }
      break;
    }

    default:
      break;
    }
    setState(299);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0)) {
      setState(298);
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
    setState(301);
    match(SimpleViewParser::T__4);
    setState(302);
    match(SimpleViewParser::IDENTIFIER);
    setState(307);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(303);
      match(SimpleViewParser::T__2);
      setState(304);
      match(SimpleViewParser::IDENTIFIER);
      setState(309);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(310);
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
    setState(312);
    antlrcpp::downCast<GraphElementContext *>(_localctx)->lineName = match(SimpleViewParser::IDENTIFIER);
    setState(314);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleViewParser::T__4) {
      setState(313);
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
    setState(316);
    graphElement();
    setState(321);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(317);
      match(SimpleViewParser::T__2);
      setState(318);
      graphElement();
      setState(323);
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
    setState(336);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(324);
        match(SimpleViewParser::T__1);
        setState(325);
        pointInLine();
        setState(330);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__2) {
          setState(326);
          match(SimpleViewParser::T__2);
          setState(327);
          pointInLine();
          setState(332);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(333);
        match(SimpleViewParser::T__3);
        break;
      }

      case SimpleViewParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(335);
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
    setState(338);
    match(SimpleViewParser::T__16);
    setState(339);
    pointInLine();
    setState(344);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(340);
      match(SimpleViewParser::T__2);
      setState(341);
      pointInLine();
      setState(346);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(347);
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
    setState(381);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::CLASS_SCOPE: {
        _localctx = _tracker.createInstance<SimpleViewParser::ClassScopeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(349);
        match(SimpleViewParser::CLASS_SCOPE);
        setState(350);
        match(SimpleViewParser::IDENTIFIER);
        setState(351);
        match(SimpleViewParser::T__18);
        setState(352);
        classScopeExp();
        break;
      }

      case SimpleViewParser::NODE: {
        _localctx = _tracker.createInstance<SimpleViewParser::NodeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(353);
        match(SimpleViewParser::NODE);
        setState(354);
        match(SimpleViewParser::IDENTIFIER);
        setState(355);
        match(SimpleViewParser::T__18);
        setState(356);
        nodeExp();
        break;
      }

      case SimpleViewParser::SEGMENT:
      case SimpleViewParser::LINE:
      case SimpleViewParser::CODE_ORDER: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(357);
        _la = _input->LA(1);
        if (!(((((_la - 78) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 78)) & 35) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(358);
        match(SimpleViewParser::IDENTIFIER);
        setState(360);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__4) {
          setState(359);
          paramList();
        }
        setState(362);
        match(SimpleViewParser::T__18);
        setState(363);
        lineExp();
        break;
      }

      case SimpleViewParser::GRAPH: {
        _localctx = _tracker.createInstance<SimpleViewParser::GraphDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(364);
        match(SimpleViewParser::GRAPH);
        setState(365);
        antlrcpp::downCast<GraphDeclarationContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
        setState(367);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__4) {
          setState(366);
          paramList();
        }
        setState(369);
        match(SimpleViewParser::T__18);
        setState(370);
        graphBody();
        setState(372); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(371);
          intersectionPoint();
          setState(374); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SimpleViewParser::T__16);
        break;
      }

      case SimpleViewParser::LINE_INSTANCE:
      case SimpleViewParser::GRAPH_INSTANCE: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineAndGraphInstanceContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(376);
        _la = _input->LA(1);
        if (!(_la == SimpleViewParser::LINE_INSTANCE

        || _la == SimpleViewParser::GRAPH_INSTANCE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(377);
        match(SimpleViewParser::IDENTIFIER);
        setState(378);
        match(SimpleViewParser::T__18);
        setState(379);
        match(SimpleViewParser::IDENTIFIER);
        setState(380);
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
    setState(383);
    match(SimpleViewParser::SHOW);
    setState(384);
    match(SimpleViewParser::T__4);
    setState(385);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
    setState(386);
    match(SimpleViewParser::T__2);
    setState(387);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->defaultStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(388);
    match(SimpleViewParser::T__2);
    setState(389);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->basicStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(390);
    match(SimpleViewParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void SimpleViewParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  simpleviewParserInitialize();
#else
  ::antlr4::internal::call_once(simpleviewParserOnceFlag, simpleviewParserInitialize);
#endif
}
