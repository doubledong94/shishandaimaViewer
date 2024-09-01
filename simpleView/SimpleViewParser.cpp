
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
      "lineSegOrNodeExp", "lineArgumentList", "graphElement", "graphBody", 
      "pointInLine", "intersectionPoint", "declaration", "showCommand"
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
      "'CodeOrder'", "'show'"
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
      "GRAPH_INSTANCE", "CODE_ORDER", "SHOW", "STRING", "IDENTIFIER", "FLOAT", 
      "INT", "WS", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,89,369,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,1,0,1,0,4,0,30,
  	8,0,11,0,12,0,31,1,0,1,0,1,0,5,0,37,8,0,10,0,12,0,40,9,0,1,1,1,1,1,1,
  	1,1,1,1,1,1,5,1,48,8,1,10,1,12,1,51,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,76,
  	8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,87,8,1,10,1,12,1,90,9,1,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,107,8,2,
  	10,2,12,2,110,9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,226,8,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,237,8,2,10,2,12,2,240,9,2,1,3,1,3,
  	1,3,1,3,5,3,246,8,3,10,3,12,3,249,9,3,1,3,1,3,1,4,1,4,1,4,4,4,256,8,4,
  	11,4,12,4,257,1,4,1,4,1,4,4,4,263,8,4,11,4,12,4,264,3,4,267,8,4,1,5,1,
  	5,1,5,1,5,3,5,273,8,5,1,5,3,5,276,8,5,1,6,1,6,1,6,1,6,5,6,282,8,6,10,
  	6,12,6,285,9,6,1,6,1,6,1,7,1,7,3,7,291,8,7,1,8,1,8,1,8,5,8,296,8,8,10,
  	8,12,8,299,9,8,1,9,1,9,1,9,1,9,5,9,305,8,9,10,9,12,9,308,9,9,1,9,1,9,
  	1,9,3,9,313,8,9,1,10,1,10,1,10,1,10,5,10,319,8,10,10,10,12,10,322,9,10,
  	1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,
  	337,8,11,1,11,1,11,1,11,1,11,1,11,3,11,344,8,11,1,11,1,11,1,11,4,11,349,
  	8,11,11,11,12,11,350,1,11,1,11,1,11,1,11,1,11,3,11,358,8,11,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,0,2,2,4,13,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,0,3,1,0,14,16,2,0,77,78,82,82,2,0,79,79,81,81,434,0,29,
  	1,0,0,0,2,75,1,0,0,0,4,225,1,0,0,0,6,241,1,0,0,0,8,266,1,0,0,0,10,272,
  	1,0,0,0,12,277,1,0,0,0,14,288,1,0,0,0,16,292,1,0,0,0,18,312,1,0,0,0,20,
  	314,1,0,0,0,22,357,1,0,0,0,24,359,1,0,0,0,26,27,3,22,11,0,27,28,5,1,0,
  	0,28,30,1,0,0,0,29,26,1,0,0,0,30,31,1,0,0,0,31,29,1,0,0,0,31,32,1,0,0,
  	0,32,38,1,0,0,0,33,34,3,24,12,0,34,35,5,1,0,0,35,37,1,0,0,0,36,33,1,0,
  	0,0,37,40,1,0,0,0,38,36,1,0,0,0,38,39,1,0,0,0,39,1,1,0,0,0,40,38,1,0,
  	0,0,41,42,6,1,-1,0,42,76,5,84,0,0,43,44,5,2,0,0,44,49,5,84,0,0,45,46,
  	5,3,0,0,46,48,5,84,0,0,47,45,1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,
  	1,0,0,0,50,52,1,0,0,0,51,49,1,0,0,0,52,76,5,4,0,0,53,54,5,48,0,0,54,55,
  	5,5,0,0,55,56,5,84,0,0,56,76,5,6,0,0,57,58,5,50,0,0,58,59,5,5,0,0,59,
  	60,3,2,1,0,60,61,5,6,0,0,61,76,1,0,0,0,62,63,5,51,0,0,63,64,5,5,0,0,64,
  	65,3,2,1,0,65,66,5,6,0,0,66,76,1,0,0,0,67,68,5,5,0,0,68,69,3,2,1,0,69,
  	70,5,6,0,0,70,76,1,0,0,0,71,76,5,85,0,0,72,73,5,10,0,0,73,74,5,85,0,0,
  	74,76,5,11,0,0,75,41,1,0,0,0,75,43,1,0,0,0,75,53,1,0,0,0,75,57,1,0,0,
  	0,75,62,1,0,0,0,75,67,1,0,0,0,75,71,1,0,0,0,75,72,1,0,0,0,76,88,1,0,0,
  	0,77,78,10,6,0,0,78,79,5,7,0,0,79,87,3,2,1,7,80,81,10,5,0,0,81,82,5,8,
  	0,0,82,87,3,2,1,6,83,84,10,4,0,0,84,85,5,9,0,0,85,87,3,2,1,5,86,77,1,
  	0,0,0,86,80,1,0,0,0,86,83,1,0,0,0,87,90,1,0,0,0,88,86,1,0,0,0,88,89,1,
  	0,0,0,89,3,1,0,0,0,90,88,1,0,0,0,91,92,6,2,-1,0,92,93,5,84,0,0,93,94,
  	5,5,0,0,94,95,5,84,0,0,95,226,5,6,0,0,96,97,5,2,0,0,97,98,5,84,0,0,98,
  	99,5,5,0,0,99,100,5,84,0,0,100,108,5,6,0,0,101,102,5,3,0,0,102,103,5,
  	84,0,0,103,104,5,5,0,0,104,105,5,84,0,0,105,107,5,6,0,0,106,101,1,0,0,
  	0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,111,1,0,0,0,110,
  	108,1,0,0,0,111,226,5,4,0,0,112,113,5,34,0,0,113,114,5,5,0,0,114,115,
  	3,2,1,0,115,116,5,6,0,0,116,226,1,0,0,0,117,118,5,36,0,0,118,119,5,5,
  	0,0,119,120,3,2,1,0,120,121,5,6,0,0,121,226,1,0,0,0,122,123,5,38,0,0,
  	123,124,5,5,0,0,124,125,3,4,2,0,125,126,5,6,0,0,126,226,1,0,0,0,127,128,
  	5,39,0,0,128,129,5,5,0,0,129,130,3,4,2,0,130,131,5,6,0,0,131,226,1,0,
  	0,0,132,133,5,35,0,0,133,134,5,5,0,0,134,135,3,2,1,0,135,136,5,3,0,0,
  	136,137,3,2,1,0,137,138,5,6,0,0,138,226,1,0,0,0,139,140,5,37,0,0,140,
  	141,5,5,0,0,141,142,3,2,1,0,142,143,5,6,0,0,143,226,1,0,0,0,144,145,5,
  	50,0,0,145,146,5,5,0,0,146,147,3,4,2,0,147,148,5,6,0,0,148,226,1,0,0,
  	0,149,150,5,51,0,0,150,151,5,5,0,0,151,152,3,4,2,0,152,153,5,6,0,0,153,
  	226,1,0,0,0,154,155,5,42,0,0,155,156,5,5,0,0,156,157,3,4,2,0,157,158,
  	5,6,0,0,158,226,1,0,0,0,159,160,5,40,0,0,160,161,5,5,0,0,161,162,3,4,
  	2,0,162,163,5,6,0,0,163,226,1,0,0,0,164,165,5,41,0,0,165,166,5,5,0,0,
  	166,167,3,4,2,0,167,168,5,6,0,0,168,226,1,0,0,0,169,170,5,43,0,0,170,
  	171,5,5,0,0,171,172,3,4,2,0,172,173,5,6,0,0,173,226,1,0,0,0,174,175,5,
  	44,0,0,175,176,5,5,0,0,176,177,3,4,2,0,177,178,5,6,0,0,178,226,1,0,0,
  	0,179,180,5,45,0,0,180,181,5,5,0,0,181,182,3,4,2,0,182,183,5,6,0,0,183,
  	226,1,0,0,0,184,185,5,46,0,0,185,186,5,5,0,0,186,187,3,4,2,0,187,188,
  	5,6,0,0,188,226,1,0,0,0,189,190,5,47,0,0,190,191,5,5,0,0,191,192,3,4,
  	2,0,192,193,5,6,0,0,193,226,1,0,0,0,194,226,5,31,0,0,195,226,5,32,0,0,
  	196,226,5,33,0,0,197,226,5,57,0,0,198,226,5,58,0,0,199,226,5,59,0,0,200,
  	226,5,60,0,0,201,226,5,61,0,0,202,226,5,62,0,0,203,226,5,63,0,0,204,226,
  	5,64,0,0,205,226,5,65,0,0,206,226,5,66,0,0,207,226,5,67,0,0,208,226,5,
  	68,0,0,209,226,5,69,0,0,210,226,5,70,0,0,211,226,5,71,0,0,212,226,5,72,
  	0,0,213,226,5,73,0,0,214,226,5,74,0,0,215,226,5,75,0,0,216,226,5,76,0,
  	0,217,218,5,5,0,0,218,219,3,4,2,0,219,220,5,6,0,0,220,226,1,0,0,0,221,
  	226,5,85,0,0,222,223,5,10,0,0,223,224,5,85,0,0,224,226,5,11,0,0,225,91,
  	1,0,0,0,225,96,1,0,0,0,225,112,1,0,0,0,225,117,1,0,0,0,225,122,1,0,0,
  	0,225,127,1,0,0,0,225,132,1,0,0,0,225,139,1,0,0,0,225,144,1,0,0,0,225,
  	149,1,0,0,0,225,154,1,0,0,0,225,159,1,0,0,0,225,164,1,0,0,0,225,169,1,
  	0,0,0,225,174,1,0,0,0,225,179,1,0,0,0,225,184,1,0,0,0,225,189,1,0,0,0,
  	225,194,1,0,0,0,225,195,1,0,0,0,225,196,1,0,0,0,225,197,1,0,0,0,225,198,
  	1,0,0,0,225,199,1,0,0,0,225,200,1,0,0,0,225,201,1,0,0,0,225,202,1,0,0,
  	0,225,203,1,0,0,0,225,204,1,0,0,0,225,205,1,0,0,0,225,206,1,0,0,0,225,
  	207,1,0,0,0,225,208,1,0,0,0,225,209,1,0,0,0,225,210,1,0,0,0,225,211,1,
  	0,0,0,225,212,1,0,0,0,225,213,1,0,0,0,225,214,1,0,0,0,225,215,1,0,0,0,
  	225,216,1,0,0,0,225,217,1,0,0,0,225,221,1,0,0,0,225,222,1,0,0,0,226,238,
  	1,0,0,0,227,228,10,31,0,0,228,229,5,8,0,0,229,237,3,4,2,32,230,231,10,
  	30,0,0,231,232,5,7,0,0,232,237,3,4,2,31,233,234,10,29,0,0,234,235,5,9,
  	0,0,235,237,3,4,2,30,236,227,1,0,0,0,236,230,1,0,0,0,236,233,1,0,0,0,
  	237,240,1,0,0,0,238,236,1,0,0,0,238,239,1,0,0,0,239,5,1,0,0,0,240,238,
  	1,0,0,0,241,242,5,5,0,0,242,247,5,85,0,0,243,244,5,3,0,0,244,246,5,85,
  	0,0,245,243,1,0,0,0,246,249,1,0,0,0,247,245,1,0,0,0,247,248,1,0,0,0,248,
  	250,1,0,0,0,249,247,1,0,0,0,250,251,5,6,0,0,251,7,1,0,0,0,252,255,3,10,
  	5,0,253,254,5,12,0,0,254,256,3,10,5,0,255,253,1,0,0,0,256,257,1,0,0,0,
  	257,255,1,0,0,0,257,258,1,0,0,0,258,267,1,0,0,0,259,262,3,10,5,0,260,
  	261,5,13,0,0,261,263,3,10,5,0,262,260,1,0,0,0,263,264,1,0,0,0,264,262,
  	1,0,0,0,264,265,1,0,0,0,265,267,1,0,0,0,266,252,1,0,0,0,266,259,1,0,0,
  	0,267,9,1,0,0,0,268,269,5,2,0,0,269,270,5,85,0,0,270,273,5,4,0,0,271,
  	273,3,4,2,0,272,268,1,0,0,0,272,271,1,0,0,0,273,275,1,0,0,0,274,276,7,
  	0,0,0,275,274,1,0,0,0,275,276,1,0,0,0,276,11,1,0,0,0,277,278,5,5,0,0,
  	278,283,5,85,0,0,279,280,5,3,0,0,280,282,5,85,0,0,281,279,1,0,0,0,282,
  	285,1,0,0,0,283,281,1,0,0,0,283,284,1,0,0,0,284,286,1,0,0,0,285,283,1,
  	0,0,0,286,287,5,6,0,0,287,13,1,0,0,0,288,290,5,85,0,0,289,291,3,12,6,
  	0,290,289,1,0,0,0,290,291,1,0,0,0,291,15,1,0,0,0,292,297,3,14,7,0,293,
  	294,5,3,0,0,294,296,3,14,7,0,295,293,1,0,0,0,296,299,1,0,0,0,297,295,
  	1,0,0,0,297,298,1,0,0,0,298,17,1,0,0,0,299,297,1,0,0,0,300,301,5,2,0,
  	0,301,306,3,18,9,0,302,303,5,3,0,0,303,305,3,18,9,0,304,302,1,0,0,0,305,
  	308,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,0,307,309,1,0,0,0,308,306,1,
  	0,0,0,309,310,5,4,0,0,310,313,1,0,0,0,311,313,5,87,0,0,312,300,1,0,0,
  	0,312,311,1,0,0,0,313,19,1,0,0,0,314,315,5,17,0,0,315,320,3,18,9,0,316,
  	317,5,3,0,0,317,319,3,18,9,0,318,316,1,0,0,0,319,322,1,0,0,0,320,318,
  	1,0,0,0,320,321,1,0,0,0,321,323,1,0,0,0,322,320,1,0,0,0,323,324,5,18,
  	0,0,324,21,1,0,0,0,325,326,5,55,0,0,326,327,5,85,0,0,327,328,5,19,0,0,
  	328,358,3,2,1,0,329,330,5,56,0,0,330,331,5,85,0,0,331,332,5,19,0,0,332,
  	358,3,4,2,0,333,334,7,1,0,0,334,336,5,85,0,0,335,337,3,6,3,0,336,335,
  	1,0,0,0,336,337,1,0,0,0,337,338,1,0,0,0,338,339,5,19,0,0,339,358,3,8,
  	4,0,340,341,5,80,0,0,341,343,5,85,0,0,342,344,3,6,3,0,343,342,1,0,0,0,
  	343,344,1,0,0,0,344,345,1,0,0,0,345,346,5,19,0,0,346,348,3,16,8,0,347,
  	349,3,20,10,0,348,347,1,0,0,0,349,350,1,0,0,0,350,348,1,0,0,0,350,351,
  	1,0,0,0,351,358,1,0,0,0,352,353,7,2,0,0,353,354,5,85,0,0,354,355,5,19,
  	0,0,355,356,5,85,0,0,356,358,3,12,6,0,357,325,1,0,0,0,357,329,1,0,0,0,
  	357,333,1,0,0,0,357,340,1,0,0,0,357,352,1,0,0,0,358,23,1,0,0,0,359,360,
  	5,83,0,0,360,361,5,5,0,0,361,362,5,85,0,0,362,363,5,3,0,0,363,364,5,85,
  	0,0,364,365,5,3,0,0,365,366,5,85,0,0,366,367,5,6,0,0,367,25,1,0,0,0,26,
  	31,38,49,75,86,88,108,225,236,238,247,257,264,266,272,275,283,290,297,
  	306,312,320,336,343,350,357
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
    setState(29); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      declaration();
      setState(27);
      match(SimpleViewParser::T__0);
      setState(31); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 55) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 55)) & 264241155) != 0));
    setState(38);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::SHOW) {
      setState(33);
      showCommand();
      setState(34);
      match(SimpleViewParser::T__0);
      setState(40);
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
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STRING: {
        setState(42);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKey = match(SimpleViewParser::STRING);
        break;
      }

      case SimpleViewParser::T__1: {
        setState(43);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKeyList = match(SimpleViewParser::T__1);
        setState(44);
        match(SimpleViewParser::STRING);
        setState(49);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__2) {
          setState(45);
          match(SimpleViewParser::T__2);
          setState(46);
          match(SimpleViewParser::STRING);
          setState(51);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(52);
        match(SimpleViewParser::T__3);
        break;
      }

      case SimpleViewParser::IN_PACKAGE: {
        setState(53);
        match(SimpleViewParser::IN_PACKAGE);
        setState(54);
        match(SimpleViewParser::T__4);
        setState(55);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->packageStr = match(SimpleViewParser::STRING);
        setState(56);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::SUPER: {
        setState(57);
        match(SimpleViewParser::SUPER);
        setState(58);
        match(SimpleViewParser::T__4);
        setState(59);
        classScopeExp(0);
        setState(60);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::SUB: {
        setState(62);
        match(SimpleViewParser::SUB);
        setState(63);
        match(SimpleViewParser::T__4);
        setState(64);
        classScopeExp(0);
        setState(65);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::T__4: {
        setState(67);
        match(SimpleViewParser::T__4);
        setState(68);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->bracket = classScopeExp(0);
        setState(69);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::IDENTIFIER: {
        setState(71);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->refOtherScope = match(SimpleViewParser::IDENTIFIER);
        break;
      }

      case SimpleViewParser::T__9: {
        setState(72);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->varClass = match(SimpleViewParser::T__9);
        setState(73);
        match(SimpleViewParser::IDENTIFIER);
        setState(74);
        match(SimpleViewParser::T__10);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(88);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(86);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(77);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(78);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__6);
          setState(79);
          classScopeExp(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(80);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(81);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__7);
          setState(82);
          classScopeExp(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(83);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(84);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__8);
          setState(85);
          classScopeExp(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(90);
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
    setState(225);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STRING: {
        setState(92);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKey = match(SimpleViewParser::STRING);
        setState(93);
        match(SimpleViewParser::T__4);
        setState(94);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->typeKey = match(SimpleViewParser::STRING);
        setState(95);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::T__1: {
        setState(96);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKeyList = match(SimpleViewParser::T__1);
        setState(97);
        match(SimpleViewParser::STRING);
        setState(98);
        match(SimpleViewParser::T__4);
        setState(99);
        match(SimpleViewParser::STRING);
        setState(100);
        match(SimpleViewParser::T__5);
        setState(108);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__2) {
          setState(101);
          match(SimpleViewParser::T__2);
          setState(102);
          match(SimpleViewParser::STRING);
          setState(103);
          match(SimpleViewParser::T__4);
          setState(104);
          match(SimpleViewParser::STRING);
          setState(105);
          match(SimpleViewParser::T__5);
          setState(110);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(111);
        match(SimpleViewParser::T__3);
        break;
      }

      case SimpleViewParser::FIELD_OF: {
        setState(112);
        match(SimpleViewParser::FIELD_OF);
        setState(113);
        match(SimpleViewParser::T__4);
        setState(114);
        classScopeExp(0);
        setState(115);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::METHOD_OF: {
        setState(117);
        match(SimpleViewParser::METHOD_OF);
        setState(118);
        match(SimpleViewParser::T__4);
        setState(119);
        classScopeExp(0);
        setState(120);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::PARAMETER_OF: {
        setState(122);
        match(SimpleViewParser::PARAMETER_OF);
        setState(123);
        match(SimpleViewParser::T__4);
        setState(124);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(125);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::RETURN_OF: {
        setState(127);
        match(SimpleViewParser::RETURN_OF);
        setState(128);
        match(SimpleViewParser::T__4);
        setState(129);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(130);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::INSTANCE_OF: {
        setState(132);
        match(SimpleViewParser::INSTANCE_OF);
        setState(133);
        match(SimpleViewParser::T__4);
        setState(134);
        classScopeExp(0);
        setState(135);
        match(SimpleViewParser::T__2);
        setState(136);
        classScopeExp(0);
        setState(137);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::CREATOR: {
        setState(139);
        match(SimpleViewParser::CREATOR);
        setState(140);
        match(SimpleViewParser::T__4);
        setState(141);
        classScopeExp(0);
        setState(142);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::SUPER: {
        setState(144);
        match(SimpleViewParser::SUPER);
        setState(145);
        match(SimpleViewParser::T__4);
        setState(146);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(147);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::SUB: {
        setState(149);
        match(SimpleViewParser::SUB);
        setState(150);
        match(SimpleViewParser::T__4);
        setState(151);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(152);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::CALLED_METHOD_OF: {
        setState(154);
        match(SimpleViewParser::CALLED_METHOD_OF);
        setState(155);
        match(SimpleViewParser::T__4);
        setState(156);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(157);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::CALLED_PARAM_OF: {
        setState(159);
        match(SimpleViewParser::CALLED_PARAM_OF);
        setState(160);
        match(SimpleViewParser::T__4);
        setState(161);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->paramNode = nodeExp(0);
        setState(162);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::CALLED_RETURN_OF: {
        setState(164);
        match(SimpleViewParser::CALLED_RETURN_OF);
        setState(165);
        match(SimpleViewParser::T__4);
        setState(166);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->returnNode = nodeExp(0);
        setState(167);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::METHOD_USED_BY: {
        setState(169);
        match(SimpleViewParser::METHOD_USED_BY);
        setState(170);
        match(SimpleViewParser::T__4);
        setState(171);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(172);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::FIELD_USED_BY: {
        setState(174);
        match(SimpleViewParser::FIELD_USED_BY);
        setState(175);
        match(SimpleViewParser::T__4);
        setState(176);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(177);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::METHOD_USE: {
        setState(179);
        match(SimpleViewParser::METHOD_USE);
        setState(180);
        match(SimpleViewParser::T__4);
        setState(181);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->node = nodeExp(0);
        setState(182);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::READ: {
        setState(184);
        match(SimpleViewParser::READ);
        setState(185);
        match(SimpleViewParser::T__4);
        setState(186);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->read = nodeExp(0);
        setState(187);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::WRITE: {
        setState(189);
        match(SimpleViewParser::WRITE);
        setState(190);
        match(SimpleViewParser::T__4);
        setState(191);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->write = nodeExp(0);
        setState(192);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::ANY: {
        setState(194);
        match(SimpleViewParser::ANY);
        break;
      }

      case SimpleViewParser::FINAL: {
        setState(195);
        match(SimpleViewParser::FINAL);
        break;
      }

      case SimpleViewParser::CLASS: {
        setState(196);
        match(SimpleViewParser::CLASS);
        break;
      }

      case SimpleViewParser::REFERENCE: {
        setState(197);
        match(SimpleViewParser::REFERENCE);
        break;
      }

      case SimpleViewParser::VOID_REF: {
        setState(198);
        match(SimpleViewParser::VOID_REF);
        break;
      }

      case SimpleViewParser::CONDITION: {
        setState(199);
        match(SimpleViewParser::CONDITION);
        break;
      }

      case SimpleViewParser::ELSE: {
        setState(200);
        match(SimpleViewParser::ELSE);
        break;
      }

      case SimpleViewParser::DATA_STEP: {
        setState(201);
        match(SimpleViewParser::DATA_STEP);
        break;
      }

      case SimpleViewParser::TIMING_STEP: {
        setState(202);
        match(SimpleViewParser::TIMING_STEP);
        break;
      }

      case SimpleViewParser::DATA_OVERRIDE: {
        setState(203);
        match(SimpleViewParser::DATA_OVERRIDE);
        break;
      }

      case SimpleViewParser::TIMING_OVERRIDE: {
        setState(204);
        match(SimpleViewParser::TIMING_OVERRIDE);
        break;
      }

      case SimpleViewParser::LV: {
        setState(205);
        match(SimpleViewParser::LV);
        break;
      }

      case SimpleViewParser::FIELD: {
        setState(206);
        match(SimpleViewParser::FIELD);
        break;
      }

      case SimpleViewParser::METHOD: {
        setState(207);
        match(SimpleViewParser::METHOD);
        break;
      }

      case SimpleViewParser::CONSTRUCTOR: {
        setState(208);
        match(SimpleViewParser::CONSTRUCTOR);
        break;
      }

      case SimpleViewParser::CALLED_METHOD: {
        setState(209);
        match(SimpleViewParser::CALLED_METHOD);
        break;
      }

      case SimpleViewParser::PARAMETER: {
        setState(210);
        match(SimpleViewParser::PARAMETER);
        break;
      }

      case SimpleViewParser::CALLED_PARAMETER: {
        setState(211);
        match(SimpleViewParser::CALLED_PARAMETER);
        break;
      }

      case SimpleViewParser::RETURN: {
        setState(212);
        match(SimpleViewParser::RETURN);
        break;
      }

      case SimpleViewParser::CALLED_RETURN: {
        setState(213);
        match(SimpleViewParser::CALLED_RETURN);
        break;
      }

      case SimpleViewParser::INDEX: {
        setState(214);
        match(SimpleViewParser::INDEX);
        break;
      }

      case SimpleViewParser::ERROR: {
        setState(215);
        match(SimpleViewParser::ERROR);
        break;
      }

      case SimpleViewParser::FIELD_CONNECTION: {
        setState(216);
        match(SimpleViewParser::FIELD_CONNECTION);
        break;
      }

      case SimpleViewParser::T__4: {
        setState(217);
        match(SimpleViewParser::T__4);
        setState(218);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->bracket = nodeExp(0);
        setState(219);
        match(SimpleViewParser::T__5);
        break;
      }

      case SimpleViewParser::IDENTIFIER: {
        setState(221);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->refOtherNode = match(SimpleViewParser::IDENTIFIER);
        break;
      }

      case SimpleViewParser::T__9: {
        setState(222);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->varNode = match(SimpleViewParser::T__9);
        setState(223);
        match(SimpleViewParser::IDENTIFIER);
        setState(224);
        match(SimpleViewParser::T__10);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(238);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(236);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(227);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(228);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__7);
          setState(229);
          nodeExp(32);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(230);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(231);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__6);
          setState(232);
          nodeExp(31);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(233);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(234);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__8);
          setState(235);
          nodeExp(30);
          break;
        }

        default:
          break;
        } 
      }
      setState(240);
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
    setState(241);
    match(SimpleViewParser::T__4);
    setState(242);
    match(SimpleViewParser::IDENTIFIER);
    setState(247);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(243);
      match(SimpleViewParser::T__2);
      setState(244);
      match(SimpleViewParser::IDENTIFIER);
      setState(249);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(250);
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
    setState(266);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(252);
      lineSegOrNodeExp();
      setState(255); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(253);
        antlrcpp::downCast<LineExpContext *>(_localctx)->seq = match(SimpleViewParser::T__11);
        setState(254);
        lineSegOrNodeExp();
        setState(257); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__11);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(259);
      lineSegOrNodeExp();
      setState(262); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(260);
        antlrcpp::downCast<LineExpContext *>(_localctx)->alt = match(SimpleViewParser::T__12);
        setState(261);
        lineSegOrNodeExp();
        setState(264); 
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
  enterRule(_localctx, 10, SimpleViewParser::RuleLineSegOrNodeExp);
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
    setState(272);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(268);
      match(SimpleViewParser::T__1);
      setState(269);
      antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->segName = match(SimpleViewParser::IDENTIFIER);
      setState(270);
      match(SimpleViewParser::T__3);
      break;
    }

    case 2: {
      setState(271);
      nodeExp(0);
      break;
    }

    default:
      break;
    }
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0)) {
      setState(274);
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
  enterRule(_localctx, 12, SimpleViewParser::RuleLineArgumentList);
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
    setState(277);
    match(SimpleViewParser::T__4);
    setState(278);
    match(SimpleViewParser::IDENTIFIER);
    setState(283);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(279);
      match(SimpleViewParser::T__2);
      setState(280);
      match(SimpleViewParser::IDENTIFIER);
      setState(285);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(286);
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
  enterRule(_localctx, 14, SimpleViewParser::RuleGraphElement);
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
    antlrcpp::downCast<GraphElementContext *>(_localctx)->lineName = match(SimpleViewParser::IDENTIFIER);
    setState(290);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleViewParser::T__4) {
      setState(289);
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
  enterRule(_localctx, 16, SimpleViewParser::RuleGraphBody);
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
    setState(292);
    graphElement();
    setState(297);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(293);
      match(SimpleViewParser::T__2);
      setState(294);
      graphElement();
      setState(299);
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
  enterRule(_localctx, 18, SimpleViewParser::RulePointInLine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(312);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(300);
        match(SimpleViewParser::T__1);
        setState(301);
        pointInLine();
        setState(306);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__2) {
          setState(302);
          match(SimpleViewParser::T__2);
          setState(303);
          pointInLine();
          setState(308);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(309);
        match(SimpleViewParser::T__3);
        break;
      }

      case SimpleViewParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(311);
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
  enterRule(_localctx, 20, SimpleViewParser::RuleIntersectionPoint);
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
    setState(314);
    match(SimpleViewParser::T__16);
    setState(315);
    pointInLine();
    setState(320);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__2) {
      setState(316);
      match(SimpleViewParser::T__2);
      setState(317);
      pointInLine();
      setState(322);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(323);
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
  enterRule(_localctx, 22, SimpleViewParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(357);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::CLASS_SCOPE: {
        _localctx = _tracker.createInstance<SimpleViewParser::ClassScopeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(325);
        match(SimpleViewParser::CLASS_SCOPE);
        setState(326);
        match(SimpleViewParser::IDENTIFIER);
        setState(327);
        match(SimpleViewParser::T__18);
        setState(328);
        classScopeExp(0);
        break;
      }

      case SimpleViewParser::NODE: {
        _localctx = _tracker.createInstance<SimpleViewParser::NodeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(329);
        match(SimpleViewParser::NODE);
        setState(330);
        match(SimpleViewParser::IDENTIFIER);
        setState(331);
        match(SimpleViewParser::T__18);
        setState(332);
        nodeExp(0);
        break;
      }

      case SimpleViewParser::SEGMENT:
      case SimpleViewParser::LINE:
      case SimpleViewParser::CODE_ORDER: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(333);
        _la = _input->LA(1);
        if (!(((((_la - 77) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 77)) & 35) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(334);
        match(SimpleViewParser::IDENTIFIER);
        setState(336);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__4) {
          setState(335);
          paramList();
        }
        setState(338);
        match(SimpleViewParser::T__18);
        setState(339);
        lineExp();
        break;
      }

      case SimpleViewParser::GRAPH: {
        _localctx = _tracker.createInstance<SimpleViewParser::GraphDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(340);
        match(SimpleViewParser::GRAPH);
        setState(341);
        antlrcpp::downCast<GraphDeclarationContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
        setState(343);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__4) {
          setState(342);
          paramList();
        }
        setState(345);
        match(SimpleViewParser::T__18);
        setState(346);
        graphBody();
        setState(348); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(347);
          intersectionPoint();
          setState(350); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SimpleViewParser::T__16);
        break;
      }

      case SimpleViewParser::LINE_INSTANCE:
      case SimpleViewParser::GRAPH_INSTANCE: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineAndGraphInstanceContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(352);
        _la = _input->LA(1);
        if (!(_la == SimpleViewParser::LINE_INSTANCE

        || _la == SimpleViewParser::GRAPH_INSTANCE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(353);
        match(SimpleViewParser::IDENTIFIER);
        setState(354);
        match(SimpleViewParser::T__18);
        setState(355);
        match(SimpleViewParser::IDENTIFIER);
        setState(356);
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
  enterRule(_localctx, 24, SimpleViewParser::RuleShowCommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    match(SimpleViewParser::SHOW);
    setState(360);
    match(SimpleViewParser::T__4);
    setState(361);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
    setState(362);
    match(SimpleViewParser::T__2);
    setState(363);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->defaultStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(364);
    match(SimpleViewParser::T__2);
    setState(365);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->basicStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(366);
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
