
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
      "compilationUnit", "glueAttr", "classScopeExp", "nodeExp", "paramList", 
      "lineExp", "lineSegOrNodeExp", "lineArgumentList", "graphElement", 
      "graphBody", "pointInLine", "intersectionPoint", "declaration", "showCommand"
    },
    std::vector<std::string>{
      "", "';'", "':'", "'['", "','", "']'", "'('", "')'", "'|'", "'&'", 
      "'-'", "'{'", "'}'", "'->'", "'||'", "'\\u003F'", "'*'", "'+'", "'<'", 
      "'>'", "'='", "'\"simple\"'", "'\"full\"'", "'nodeColor'", "'nodeScale'", 
      "'labelColor'", "'labelScale'", "'labelDetailLevel'", "'positionZ'", 
      "'basicNodeSize'", "'basicLabelSize'", "'basicPositionZ'", "'Any'", 
      "'FieldOf'", "'InstanceOf'", "'MethodOf'", "'CreatorOf'", "'ParameterOf'", 
      "'ReturnOf'", "'CalledParamOf'", "'CalledReturnOf'", "'CalledMethodOf'", 
      "'read'", "'write'", "'inPackage'", "'usedBy'", "'use'", "'classOf'", 
      "'superOf'", "'subOf'", "'Style'", "'DefaultStyle'", "'BasicStyle'", 
      "'ClassScope'", "'Node'", "'Reference'", "'Condition'", "'Else'", 
      "'DataStep'", "'TimingStep'", "'DataOverride'", "'TimingOverride'", 
      "'Field'", "'Method'", "'Constructor'", "'CalledMethod'", "'Parameter'", 
      "'CalledParameter'", "'Return'", "'CalledReturn'", "'Index'", "'Seg'", 
      "'Line'", "'LineInstance'", "'Glue'", "'GlueRuntime'", "'GlueMemberOf'", 
      "'GlueInstanceOf'", "'GlueOverride'", "'GlueHierarchy'", "'Graph'", 
      "'GraphInstance'", "'CodeOrder'", "'show'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "LABEL_DETAIL_LEVEL_SIMPLE", "LABEL_DETAIL_LEVEL_FULL", 
      "NODE_COLOR", "NODE_SCALE", "LABEL_COLOR", "LABEL_SCALE", "LABEL_DETAIL_LEVEL", 
      "POSITION_Z", "BASIC_NODE_SIZE", "BASIC_LABEL_SIZE", "BASIC_POSITION_Z", 
      "ANY", "FIELD_OF", "INSTANCE_OF", "METHOD_OF", "CREATOR", "PARAMETER_OF", 
      "RETURN_OF", "CALLED_PARAM_OF", "CALLED_RETURN_OF", "CALLED_METHOD_OF", 
      "READ", "WRITE", "IN_PACKAGE", "USED_BY", "USE", "CLASS_OF", "SUPER", 
      "SUB", "STYLE", "DEFAULT_STYLE", "BASIC_STYLE", "CLASS_SCOPE", "NODE", 
      "REFERENCE", "CONDITION", "ELSE", "DATA_STEP", "TIMING_STEP", "DATA_OVERRIDE", 
      "TIMING_OVERRIDE", "FIELD", "METHOD", "CONSTRUCTOR", "CALLED_METHOD", 
      "PARAMETER", "CALLED_PARAMETER", "RETURN", "CALLED_RETURN", "INDEX", 
      "SEGMENT", "LINE", "LINE_INSTANCE", "GLUE", "GLUE_RUNTIME", "GLULE_MEMBER_OF", 
      "GLUE_INSTANCE_OF", "GLUE_OVERRIDE", "GLUE_HIERARCHY", "GRAPH", "GRAPH_INSTANCE", 
      "CODE_ORDER", "SHOW", "STRING", "IDENTIFIER", "FLOAT", "INT", "WS", 
      "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,89,388,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,1,0,
  	1,0,4,0,32,8,0,11,0,12,0,33,1,0,1,0,1,0,5,0,39,8,0,10,0,12,0,42,9,0,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,69,8,1,1,2,1,2,1,2,1,2,1,2,1,2,5,2,77,
  	8,2,10,2,12,2,80,9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,3,2,115,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,126,
  	8,2,10,2,12,2,129,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,5,3,146,8,3,10,3,12,3,149,9,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,3,3,234,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,5,3,245,8,3,10,3,12,3,248,9,3,1,4,1,4,1,4,1,4,5,4,254,8,4,10,4,12,4,
  	257,9,4,1,4,1,4,1,5,1,5,1,5,4,5,264,8,5,11,5,12,5,265,1,5,1,5,1,5,4,5,
  	271,8,5,11,5,12,5,272,3,5,275,8,5,1,6,1,6,1,6,1,6,3,6,281,8,6,1,6,3,6,
  	284,8,6,1,7,1,7,1,7,1,7,5,7,290,8,7,10,7,12,7,293,9,7,1,7,1,7,1,8,1,8,
  	3,8,299,8,8,1,9,1,9,1,9,5,9,304,8,9,10,9,12,9,307,9,9,1,10,1,10,1,10,
  	1,10,5,10,313,8,10,10,10,12,10,316,9,10,1,10,1,10,1,10,3,10,321,8,10,
  	1,11,1,11,1,11,1,11,5,11,327,8,11,10,11,12,11,330,9,11,1,11,1,11,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,345,8,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,5,12,354,8,12,10,12,12,12,357,9,12,1,12,
  	1,12,1,12,1,12,3,12,363,8,12,1,12,1,12,1,12,4,12,368,8,12,11,12,12,12,
  	369,1,12,1,12,1,12,1,12,1,12,3,12,377,8,12,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,0,2,4,6,14,0,2,4,6,8,10,12,14,16,18,20,22,24,26,
  	0,3,1,0,15,17,2,0,71,72,82,82,2,0,73,73,81,81,449,0,31,1,0,0,0,2,68,1,
  	0,0,0,4,114,1,0,0,0,6,233,1,0,0,0,8,249,1,0,0,0,10,274,1,0,0,0,12,280,
  	1,0,0,0,14,285,1,0,0,0,16,296,1,0,0,0,18,300,1,0,0,0,20,320,1,0,0,0,22,
  	322,1,0,0,0,24,376,1,0,0,0,26,378,1,0,0,0,28,29,3,24,12,0,29,30,5,1,0,
  	0,30,32,1,0,0,0,31,28,1,0,0,0,32,33,1,0,0,0,33,31,1,0,0,0,33,34,1,0,0,
  	0,34,40,1,0,0,0,35,36,3,26,13,0,36,37,5,1,0,0,37,39,1,0,0,0,38,35,1,0,
  	0,0,39,42,1,0,0,0,40,38,1,0,0,0,40,41,1,0,0,0,41,1,1,0,0,0,42,40,1,0,
  	0,0,43,44,5,75,0,0,44,45,5,2,0,0,45,46,3,6,3,0,46,47,5,1,0,0,47,69,1,
  	0,0,0,48,49,5,76,0,0,49,50,5,2,0,0,50,51,3,4,2,0,51,52,5,1,0,0,52,69,
  	1,0,0,0,53,54,5,77,0,0,54,55,5,2,0,0,55,56,3,4,2,0,56,57,5,1,0,0,57,69,
  	1,0,0,0,58,59,5,78,0,0,59,60,5,2,0,0,60,61,3,6,3,0,61,62,5,1,0,0,62,69,
  	1,0,0,0,63,64,5,79,0,0,64,65,5,2,0,0,65,66,3,4,2,0,66,67,5,1,0,0,67,69,
  	1,0,0,0,68,43,1,0,0,0,68,48,1,0,0,0,68,53,1,0,0,0,68,58,1,0,0,0,68,63,
  	1,0,0,0,69,3,1,0,0,0,70,71,6,2,-1,0,71,115,5,84,0,0,72,73,5,3,0,0,73,
  	78,5,84,0,0,74,75,5,4,0,0,75,77,5,84,0,0,76,74,1,0,0,0,77,80,1,0,0,0,
  	78,76,1,0,0,0,78,79,1,0,0,0,79,81,1,0,0,0,80,78,1,0,0,0,81,115,5,5,0,
  	0,82,83,5,44,0,0,83,84,5,6,0,0,84,85,5,84,0,0,85,115,5,7,0,0,86,87,5,
  	45,0,0,87,88,5,6,0,0,88,89,3,4,2,0,89,90,5,7,0,0,90,115,1,0,0,0,91,92,
  	5,46,0,0,92,93,5,6,0,0,93,94,3,4,2,0,94,95,5,7,0,0,95,115,1,0,0,0,96,
  	97,5,48,0,0,97,98,5,6,0,0,98,99,3,4,2,0,99,100,5,7,0,0,100,115,1,0,0,
  	0,101,102,5,49,0,0,102,103,5,6,0,0,103,104,3,4,2,0,104,105,5,7,0,0,105,
  	115,1,0,0,0,106,107,5,6,0,0,107,108,3,4,2,0,108,109,5,7,0,0,109,115,1,
  	0,0,0,110,115,5,85,0,0,111,112,5,11,0,0,112,113,5,85,0,0,113,115,5,12,
  	0,0,114,70,1,0,0,0,114,72,1,0,0,0,114,82,1,0,0,0,114,86,1,0,0,0,114,91,
  	1,0,0,0,114,96,1,0,0,0,114,101,1,0,0,0,114,106,1,0,0,0,114,110,1,0,0,
  	0,114,111,1,0,0,0,115,127,1,0,0,0,116,117,10,6,0,0,117,118,5,8,0,0,118,
  	126,3,4,2,7,119,120,10,5,0,0,120,121,5,9,0,0,121,126,3,4,2,6,122,123,
  	10,4,0,0,123,124,5,10,0,0,124,126,3,4,2,5,125,116,1,0,0,0,125,119,1,0,
  	0,0,125,122,1,0,0,0,126,129,1,0,0,0,127,125,1,0,0,0,127,128,1,0,0,0,128,
  	5,1,0,0,0,129,127,1,0,0,0,130,131,6,3,-1,0,131,132,5,84,0,0,132,133,5,
  	6,0,0,133,134,5,84,0,0,134,234,5,7,0,0,135,136,5,3,0,0,136,137,5,84,0,
  	0,137,138,5,6,0,0,138,139,5,84,0,0,139,147,5,7,0,0,140,141,5,4,0,0,141,
  	142,5,84,0,0,142,143,5,6,0,0,143,144,5,84,0,0,144,146,5,7,0,0,145,140,
  	1,0,0,0,146,149,1,0,0,0,147,145,1,0,0,0,147,148,1,0,0,0,148,150,1,0,0,
  	0,149,147,1,0,0,0,150,234,5,5,0,0,151,152,5,33,0,0,152,153,5,6,0,0,153,
  	154,3,4,2,0,154,155,5,7,0,0,155,234,1,0,0,0,156,157,5,35,0,0,157,158,
  	5,6,0,0,158,159,3,4,2,0,159,160,5,7,0,0,160,234,1,0,0,0,161,162,5,37,
  	0,0,162,163,5,6,0,0,163,164,3,6,3,0,164,165,5,7,0,0,165,234,1,0,0,0,166,
  	167,5,38,0,0,167,168,5,6,0,0,168,169,3,6,3,0,169,170,5,7,0,0,170,234,
  	1,0,0,0,171,172,5,34,0,0,172,173,5,6,0,0,173,174,3,4,2,0,174,175,5,4,
  	0,0,175,176,3,4,2,0,176,177,5,7,0,0,177,234,1,0,0,0,178,179,5,36,0,0,
  	179,180,5,6,0,0,180,181,3,4,2,0,181,182,5,7,0,0,182,234,1,0,0,0,183,184,
  	5,41,0,0,184,185,5,6,0,0,185,186,3,6,3,0,186,187,5,7,0,0,187,234,1,0,
  	0,0,188,189,5,39,0,0,189,190,5,6,0,0,190,191,3,6,3,0,191,192,5,7,0,0,
  	192,234,1,0,0,0,193,194,5,40,0,0,194,195,5,6,0,0,195,196,3,6,3,0,196,
  	197,5,7,0,0,197,234,1,0,0,0,198,199,5,42,0,0,199,200,5,6,0,0,200,201,
  	3,6,3,0,201,202,5,7,0,0,202,234,1,0,0,0,203,204,5,43,0,0,204,205,5,6,
  	0,0,205,206,3,6,3,0,206,207,5,7,0,0,207,234,1,0,0,0,208,234,5,32,0,0,
  	209,234,5,55,0,0,210,234,5,56,0,0,211,234,5,57,0,0,212,234,5,58,0,0,213,
  	234,5,59,0,0,214,234,5,60,0,0,215,234,5,61,0,0,216,234,5,62,0,0,217,234,
  	5,63,0,0,218,234,5,64,0,0,219,234,5,65,0,0,220,234,5,66,0,0,221,234,5,
  	67,0,0,222,234,5,68,0,0,223,234,5,69,0,0,224,234,5,70,0,0,225,226,5,6,
  	0,0,226,227,3,6,3,0,227,228,5,7,0,0,228,234,1,0,0,0,229,234,5,85,0,0,
  	230,231,5,11,0,0,231,232,5,85,0,0,232,234,5,12,0,0,233,130,1,0,0,0,233,
  	135,1,0,0,0,233,151,1,0,0,0,233,156,1,0,0,0,233,161,1,0,0,0,233,166,1,
  	0,0,0,233,171,1,0,0,0,233,178,1,0,0,0,233,183,1,0,0,0,233,188,1,0,0,0,
  	233,193,1,0,0,0,233,198,1,0,0,0,233,203,1,0,0,0,233,208,1,0,0,0,233,209,
  	1,0,0,0,233,210,1,0,0,0,233,211,1,0,0,0,233,212,1,0,0,0,233,213,1,0,0,
  	0,233,214,1,0,0,0,233,215,1,0,0,0,233,216,1,0,0,0,233,217,1,0,0,0,233,
  	218,1,0,0,0,233,219,1,0,0,0,233,220,1,0,0,0,233,221,1,0,0,0,233,222,1,
  	0,0,0,233,223,1,0,0,0,233,224,1,0,0,0,233,225,1,0,0,0,233,229,1,0,0,0,
  	233,230,1,0,0,0,234,246,1,0,0,0,235,236,10,25,0,0,236,237,5,9,0,0,237,
  	245,3,6,3,26,238,239,10,24,0,0,239,240,5,8,0,0,240,245,3,6,3,25,241,242,
  	10,23,0,0,242,243,5,10,0,0,243,245,3,6,3,24,244,235,1,0,0,0,244,238,1,
  	0,0,0,244,241,1,0,0,0,245,248,1,0,0,0,246,244,1,0,0,0,246,247,1,0,0,0,
  	247,7,1,0,0,0,248,246,1,0,0,0,249,250,5,6,0,0,250,255,5,85,0,0,251,252,
  	5,4,0,0,252,254,5,85,0,0,253,251,1,0,0,0,254,257,1,0,0,0,255,253,1,0,
  	0,0,255,256,1,0,0,0,256,258,1,0,0,0,257,255,1,0,0,0,258,259,5,7,0,0,259,
  	9,1,0,0,0,260,263,3,12,6,0,261,262,5,13,0,0,262,264,3,12,6,0,263,261,
  	1,0,0,0,264,265,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,275,1,0,0,
  	0,267,270,3,12,6,0,268,269,5,14,0,0,269,271,3,12,6,0,270,268,1,0,0,0,
  	271,272,1,0,0,0,272,270,1,0,0,0,272,273,1,0,0,0,273,275,1,0,0,0,274,260,
  	1,0,0,0,274,267,1,0,0,0,275,11,1,0,0,0,276,277,5,3,0,0,277,278,5,85,0,
  	0,278,281,5,5,0,0,279,281,3,6,3,0,280,276,1,0,0,0,280,279,1,0,0,0,281,
  	283,1,0,0,0,282,284,7,0,0,0,283,282,1,0,0,0,283,284,1,0,0,0,284,13,1,
  	0,0,0,285,286,5,6,0,0,286,291,5,85,0,0,287,288,5,4,0,0,288,290,5,85,0,
  	0,289,287,1,0,0,0,290,293,1,0,0,0,291,289,1,0,0,0,291,292,1,0,0,0,292,
  	294,1,0,0,0,293,291,1,0,0,0,294,295,5,7,0,0,295,15,1,0,0,0,296,298,5,
  	85,0,0,297,299,3,14,7,0,298,297,1,0,0,0,298,299,1,0,0,0,299,17,1,0,0,
  	0,300,305,3,16,8,0,301,302,5,4,0,0,302,304,3,16,8,0,303,301,1,0,0,0,304,
  	307,1,0,0,0,305,303,1,0,0,0,305,306,1,0,0,0,306,19,1,0,0,0,307,305,1,
  	0,0,0,308,309,5,3,0,0,309,314,3,20,10,0,310,311,5,4,0,0,311,313,3,20,
  	10,0,312,310,1,0,0,0,313,316,1,0,0,0,314,312,1,0,0,0,314,315,1,0,0,0,
  	315,317,1,0,0,0,316,314,1,0,0,0,317,318,5,5,0,0,318,321,1,0,0,0,319,321,
  	5,87,0,0,320,308,1,0,0,0,320,319,1,0,0,0,321,21,1,0,0,0,322,323,5,18,
  	0,0,323,328,3,20,10,0,324,325,5,4,0,0,325,327,3,20,10,0,326,324,1,0,0,
  	0,327,330,1,0,0,0,328,326,1,0,0,0,328,329,1,0,0,0,329,331,1,0,0,0,330,
  	328,1,0,0,0,331,332,5,19,0,0,332,23,1,0,0,0,333,334,5,53,0,0,334,335,
  	5,85,0,0,335,336,5,20,0,0,336,377,3,4,2,0,337,338,5,54,0,0,338,339,5,
  	85,0,0,339,340,5,20,0,0,340,377,3,6,3,0,341,342,7,1,0,0,342,344,5,85,
  	0,0,343,345,3,8,4,0,344,343,1,0,0,0,344,345,1,0,0,0,345,346,1,0,0,0,346,
  	347,5,20,0,0,347,377,3,10,5,0,348,349,5,74,0,0,349,350,5,85,0,0,350,351,
  	5,20,0,0,351,355,5,11,0,0,352,354,3,2,1,0,353,352,1,0,0,0,354,357,1,0,
  	0,0,355,353,1,0,0,0,355,356,1,0,0,0,356,358,1,0,0,0,357,355,1,0,0,0,358,
  	377,5,12,0,0,359,360,5,80,0,0,360,362,5,85,0,0,361,363,3,8,4,0,362,361,
  	1,0,0,0,362,363,1,0,0,0,363,364,1,0,0,0,364,365,5,20,0,0,365,367,3,18,
  	9,0,366,368,3,22,11,0,367,366,1,0,0,0,368,369,1,0,0,0,369,367,1,0,0,0,
  	369,370,1,0,0,0,370,377,1,0,0,0,371,372,7,2,0,0,372,373,5,85,0,0,373,
  	374,5,20,0,0,374,375,5,85,0,0,375,377,3,14,7,0,376,333,1,0,0,0,376,337,
  	1,0,0,0,376,341,1,0,0,0,376,348,1,0,0,0,376,359,1,0,0,0,376,371,1,0,0,
  	0,377,25,1,0,0,0,378,379,5,83,0,0,379,380,5,6,0,0,380,381,5,85,0,0,381,
  	382,5,4,0,0,382,383,5,85,0,0,383,384,5,4,0,0,384,385,5,85,0,0,385,386,
  	5,7,0,0,386,27,1,0,0,0,28,33,40,68,78,114,125,127,147,233,244,246,255,
  	265,272,274,280,283,291,298,305,314,320,328,344,355,362,369,376
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
    } while (((((_la - 53) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 53)) & 943456259) != 0));
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

//----------------- GlueAttrContext ------------------------------------------------------------------

SimpleViewParser::GlueAttrContext::GlueAttrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleViewParser::GlueAttrContext::GLUE_RUNTIME() {
  return getToken(SimpleViewParser::GLUE_RUNTIME, 0);
}

SimpleViewParser::NodeExpContext* SimpleViewParser::GlueAttrContext::nodeExp() {
  return getRuleContext<SimpleViewParser::NodeExpContext>(0);
}

tree::TerminalNode* SimpleViewParser::GlueAttrContext::GLULE_MEMBER_OF() {
  return getToken(SimpleViewParser::GLULE_MEMBER_OF, 0);
}

SimpleViewParser::ClassScopeExpContext* SimpleViewParser::GlueAttrContext::classScopeExp() {
  return getRuleContext<SimpleViewParser::ClassScopeExpContext>(0);
}

tree::TerminalNode* SimpleViewParser::GlueAttrContext::GLUE_INSTANCE_OF() {
  return getToken(SimpleViewParser::GLUE_INSTANCE_OF, 0);
}

tree::TerminalNode* SimpleViewParser::GlueAttrContext::GLUE_OVERRIDE() {
  return getToken(SimpleViewParser::GLUE_OVERRIDE, 0);
}

tree::TerminalNode* SimpleViewParser::GlueAttrContext::GLUE_HIERARCHY() {
  return getToken(SimpleViewParser::GLUE_HIERARCHY, 0);
}


size_t SimpleViewParser::GlueAttrContext::getRuleIndex() const {
  return SimpleViewParser::RuleGlueAttr;
}


std::any SimpleViewParser::GlueAttrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitGlueAttr(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::GlueAttrContext* SimpleViewParser::glueAttr() {
  GlueAttrContext *_localctx = _tracker.createInstance<GlueAttrContext>(_ctx, getState());
  enterRule(_localctx, 2, SimpleViewParser::RuleGlueAttr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::GLUE_RUNTIME: {
        enterOuterAlt(_localctx, 1);
        setState(43);
        match(SimpleViewParser::GLUE_RUNTIME);
        setState(44);
        match(SimpleViewParser::T__1);
        setState(45);
        nodeExp(0);
        setState(46);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::GLULE_MEMBER_OF: {
        enterOuterAlt(_localctx, 2);
        setState(48);
        match(SimpleViewParser::GLULE_MEMBER_OF);
        setState(49);
        match(SimpleViewParser::T__1);
        setState(50);
        classScopeExp(0);
        setState(51);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::GLUE_INSTANCE_OF: {
        enterOuterAlt(_localctx, 3);
        setState(53);
        match(SimpleViewParser::GLUE_INSTANCE_OF);
        setState(54);
        match(SimpleViewParser::T__1);
        setState(55);
        classScopeExp(0);
        setState(56);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::GLUE_OVERRIDE: {
        enterOuterAlt(_localctx, 4);
        setState(58);
        match(SimpleViewParser::GLUE_OVERRIDE);
        setState(59);
        match(SimpleViewParser::T__1);
        setState(60);
        nodeExp(0);
        setState(61);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::GLUE_HIERARCHY: {
        enterOuterAlt(_localctx, 5);
        setState(63);
        match(SimpleViewParser::GLUE_HIERARCHY);
        setState(64);
        match(SimpleViewParser::T__1);
        setState(65);
        classScopeExp(0);
        setState(66);
        match(SimpleViewParser::T__0);
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

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::USED_BY() {
  return getToken(SimpleViewParser::USED_BY, 0);
}

std::vector<SimpleViewParser::ClassScopeExpContext *> SimpleViewParser::ClassScopeExpContext::classScopeExp() {
  return getRuleContexts<SimpleViewParser::ClassScopeExpContext>();
}

SimpleViewParser::ClassScopeExpContext* SimpleViewParser::ClassScopeExpContext::classScopeExp(size_t i) {
  return getRuleContext<SimpleViewParser::ClassScopeExpContext>(i);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::USE() {
  return getToken(SimpleViewParser::USE, 0);
}

tree::TerminalNode* SimpleViewParser::ClassScopeExpContext::SUPER() {
  return getToken(SimpleViewParser::SUPER, 0);
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
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, SimpleViewParser::RuleClassScopeExp, precedence);

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
    setState(114);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STRING: {
        setState(71);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKey = match(SimpleViewParser::STRING);
        break;
      }

      case SimpleViewParser::T__2: {
        setState(72);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKeyList = match(SimpleViewParser::T__2);
        setState(73);
        match(SimpleViewParser::STRING);
        setState(78);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__3) {
          setState(74);
          match(SimpleViewParser::T__3);
          setState(75);
          match(SimpleViewParser::STRING);
          setState(80);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(81);
        match(SimpleViewParser::T__4);
        break;
      }

      case SimpleViewParser::IN_PACKAGE: {
        setState(82);
        match(SimpleViewParser::IN_PACKAGE);
        setState(83);
        match(SimpleViewParser::T__5);
        setState(84);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->packageStr = match(SimpleViewParser::STRING);
        setState(85);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::USED_BY: {
        setState(86);
        match(SimpleViewParser::USED_BY);
        setState(87);
        match(SimpleViewParser::T__5);
        setState(88);
        classScopeExp(0);
        setState(89);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::USE: {
        setState(91);
        match(SimpleViewParser::USE);
        setState(92);
        match(SimpleViewParser::T__5);
        setState(93);
        classScopeExp(0);
        setState(94);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::SUPER: {
        setState(96);
        match(SimpleViewParser::SUPER);
        setState(97);
        match(SimpleViewParser::T__5);
        setState(98);
        classScopeExp(0);
        setState(99);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::SUB: {
        setState(101);
        match(SimpleViewParser::SUB);
        setState(102);
        match(SimpleViewParser::T__5);
        setState(103);
        classScopeExp(0);
        setState(104);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::T__5: {
        setState(106);
        match(SimpleViewParser::T__5);
        setState(107);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->bracket = classScopeExp(0);
        setState(108);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::IDENTIFIER: {
        setState(110);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->refOtherScope = match(SimpleViewParser::IDENTIFIER);
        break;
      }

      case SimpleViewParser::T__10: {
        setState(111);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->varClass = match(SimpleViewParser::T__10);
        setState(112);
        match(SimpleViewParser::IDENTIFIER);
        setState(113);
        match(SimpleViewParser::T__11);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(127);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(125);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(116);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(117);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__7);
          setState(118);
          classScopeExp(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(119);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(120);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__8);
          setState(121);
          classScopeExp(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(122);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(123);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__9);
          setState(124);
          classScopeExp(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(129);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
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

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_METHOD_OF() {
  return getToken(SimpleViewParser::CALLED_METHOD_OF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_PARAM_OF() {
  return getToken(SimpleViewParser::CALLED_PARAM_OF, 0);
}

tree::TerminalNode* SimpleViewParser::NodeExpContext::CALLED_RETURN_OF() {
  return getToken(SimpleViewParser::CALLED_RETURN_OF, 0);
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

tree::TerminalNode* SimpleViewParser::NodeExpContext::REFERENCE() {
  return getToken(SimpleViewParser::REFERENCE, 0);
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
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, SimpleViewParser::RuleNodeExp, precedence);

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
    setState(233);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STRING: {
        setState(131);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKey = match(SimpleViewParser::STRING);
        setState(132);
        match(SimpleViewParser::T__5);
        setState(133);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->typeKey = match(SimpleViewParser::STRING);
        setState(134);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::T__2: {
        setState(135);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKeyList = match(SimpleViewParser::T__2);
        setState(136);
        match(SimpleViewParser::STRING);
        setState(137);
        match(SimpleViewParser::T__5);
        setState(138);
        match(SimpleViewParser::STRING);
        setState(139);
        match(SimpleViewParser::T__6);
        setState(147);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__3) {
          setState(140);
          match(SimpleViewParser::T__3);
          setState(141);
          match(SimpleViewParser::STRING);
          setState(142);
          match(SimpleViewParser::T__5);
          setState(143);
          match(SimpleViewParser::STRING);
          setState(144);
          match(SimpleViewParser::T__6);
          setState(149);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(150);
        match(SimpleViewParser::T__4);
        break;
      }

      case SimpleViewParser::FIELD_OF: {
        setState(151);
        match(SimpleViewParser::FIELD_OF);
        setState(152);
        match(SimpleViewParser::T__5);
        setState(153);
        classScopeExp(0);
        setState(154);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::METHOD_OF: {
        setState(156);
        match(SimpleViewParser::METHOD_OF);
        setState(157);
        match(SimpleViewParser::T__5);
        setState(158);
        classScopeExp(0);
        setState(159);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::PARAMETER_OF: {
        setState(161);
        match(SimpleViewParser::PARAMETER_OF);
        setState(162);
        match(SimpleViewParser::T__5);
        setState(163);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(164);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::RETURN_OF: {
        setState(166);
        match(SimpleViewParser::RETURN_OF);
        setState(167);
        match(SimpleViewParser::T__5);
        setState(168);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(169);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::INSTANCE_OF: {
        setState(171);
        match(SimpleViewParser::INSTANCE_OF);
        setState(172);
        match(SimpleViewParser::T__5);
        setState(173);
        classScopeExp(0);
        setState(174);
        match(SimpleViewParser::T__3);
        setState(175);
        classScopeExp(0);
        setState(176);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::CREATOR: {
        setState(178);
        match(SimpleViewParser::CREATOR);
        setState(179);
        match(SimpleViewParser::T__5);
        setState(180);
        classScopeExp(0);
        setState(181);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::CALLED_METHOD_OF: {
        setState(183);
        match(SimpleViewParser::CALLED_METHOD_OF);
        setState(184);
        match(SimpleViewParser::T__5);
        setState(185);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(186);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::CALLED_PARAM_OF: {
        setState(188);
        match(SimpleViewParser::CALLED_PARAM_OF);
        setState(189);
        match(SimpleViewParser::T__5);
        setState(190);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->paramNode = nodeExp(0);
        setState(191);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::CALLED_RETURN_OF: {
        setState(193);
        match(SimpleViewParser::CALLED_RETURN_OF);
        setState(194);
        match(SimpleViewParser::T__5);
        setState(195);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->returnNode = nodeExp(0);
        setState(196);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::READ: {
        setState(198);
        match(SimpleViewParser::READ);
        setState(199);
        match(SimpleViewParser::T__5);
        setState(200);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->read = nodeExp(0);
        setState(201);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::WRITE: {
        setState(203);
        match(SimpleViewParser::WRITE);
        setState(204);
        match(SimpleViewParser::T__5);
        setState(205);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->write = nodeExp(0);
        setState(206);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::ANY: {
        setState(208);
        match(SimpleViewParser::ANY);
        break;
      }

      case SimpleViewParser::REFERENCE: {
        setState(209);
        match(SimpleViewParser::REFERENCE);
        break;
      }

      case SimpleViewParser::CONDITION: {
        setState(210);
        match(SimpleViewParser::CONDITION);
        break;
      }

      case SimpleViewParser::ELSE: {
        setState(211);
        match(SimpleViewParser::ELSE);
        break;
      }

      case SimpleViewParser::DATA_STEP: {
        setState(212);
        match(SimpleViewParser::DATA_STEP);
        break;
      }

      case SimpleViewParser::TIMING_STEP: {
        setState(213);
        match(SimpleViewParser::TIMING_STEP);
        break;
      }

      case SimpleViewParser::DATA_OVERRIDE: {
        setState(214);
        match(SimpleViewParser::DATA_OVERRIDE);
        break;
      }

      case SimpleViewParser::TIMING_OVERRIDE: {
        setState(215);
        match(SimpleViewParser::TIMING_OVERRIDE);
        break;
      }

      case SimpleViewParser::FIELD: {
        setState(216);
        match(SimpleViewParser::FIELD);
        break;
      }

      case SimpleViewParser::METHOD: {
        setState(217);
        match(SimpleViewParser::METHOD);
        break;
      }

      case SimpleViewParser::CONSTRUCTOR: {
        setState(218);
        match(SimpleViewParser::CONSTRUCTOR);
        break;
      }

      case SimpleViewParser::CALLED_METHOD: {
        setState(219);
        match(SimpleViewParser::CALLED_METHOD);
        break;
      }

      case SimpleViewParser::PARAMETER: {
        setState(220);
        match(SimpleViewParser::PARAMETER);
        break;
      }

      case SimpleViewParser::CALLED_PARAMETER: {
        setState(221);
        match(SimpleViewParser::CALLED_PARAMETER);
        break;
      }

      case SimpleViewParser::RETURN: {
        setState(222);
        match(SimpleViewParser::RETURN);
        break;
      }

      case SimpleViewParser::CALLED_RETURN: {
        setState(223);
        match(SimpleViewParser::CALLED_RETURN);
        break;
      }

      case SimpleViewParser::INDEX: {
        setState(224);
        match(SimpleViewParser::INDEX);
        break;
      }

      case SimpleViewParser::T__5: {
        setState(225);
        match(SimpleViewParser::T__5);
        setState(226);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->bracket = nodeExp(0);
        setState(227);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::IDENTIFIER: {
        setState(229);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->refOtherNode = match(SimpleViewParser::IDENTIFIER);
        break;
      }

      case SimpleViewParser::T__10: {
        setState(230);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->varNode = match(SimpleViewParser::T__10);
        setState(231);
        match(SimpleViewParser::IDENTIFIER);
        setState(232);
        match(SimpleViewParser::T__11);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(246);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(244);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(235);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(236);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__8);
          setState(237);
          nodeExp(26);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(238);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(239);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__7);
          setState(240);
          nodeExp(25);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(241);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(242);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__9);
          setState(243);
          nodeExp(24);
          break;
        }

        default:
          break;
        } 
      }
      setState(248);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
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
  enterRule(_localctx, 8, SimpleViewParser::RuleParamList);
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
    setState(249);
    match(SimpleViewParser::T__5);
    setState(250);
    match(SimpleViewParser::IDENTIFIER);
    setState(255);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__3) {
      setState(251);
      match(SimpleViewParser::T__3);
      setState(252);
      match(SimpleViewParser::IDENTIFIER);
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(258);
    match(SimpleViewParser::T__6);
   
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
  enterRule(_localctx, 10, SimpleViewParser::RuleLineExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(274);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(260);
      lineSegOrNodeExp();
      setState(263); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(261);
        antlrcpp::downCast<LineExpContext *>(_localctx)->seq = match(SimpleViewParser::T__12);
        setState(262);
        lineSegOrNodeExp();
        setState(265); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__12);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(267);
      lineSegOrNodeExp();
      setState(270); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(268);
        antlrcpp::downCast<LineExpContext *>(_localctx)->alt = match(SimpleViewParser::T__13);
        setState(269);
        lineSegOrNodeExp();
        setState(272); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SimpleViewParser::T__13);
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
    setState(280);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(276);
      match(SimpleViewParser::T__2);
      setState(277);
      antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->segName = match(SimpleViewParser::IDENTIFIER);
      setState(278);
      match(SimpleViewParser::T__4);
      break;
    }

    case 2: {
      setState(279);
      nodeExp(0);
      break;
    }

    default:
      break;
    }
    setState(283);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 229376) != 0)) {
      setState(282);
      antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->wildcard = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 229376) != 0))) {
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
    setState(285);
    match(SimpleViewParser::T__5);
    setState(286);
    match(SimpleViewParser::IDENTIFIER);
    setState(291);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__3) {
      setState(287);
      match(SimpleViewParser::T__3);
      setState(288);
      match(SimpleViewParser::IDENTIFIER);
      setState(293);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(294);
    match(SimpleViewParser::T__6);
   
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
    setState(296);
    antlrcpp::downCast<GraphElementContext *>(_localctx)->lineName = match(SimpleViewParser::IDENTIFIER);
    setState(298);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleViewParser::T__5) {
      setState(297);
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
    setState(300);
    graphElement();
    setState(305);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__3) {
      setState(301);
      match(SimpleViewParser::T__3);
      setState(302);
      graphElement();
      setState(307);
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
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(308);
        match(SimpleViewParser::T__2);
        setState(309);
        pointInLine();
        setState(314);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__3) {
          setState(310);
          match(SimpleViewParser::T__3);
          setState(311);
          pointInLine();
          setState(316);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(317);
        match(SimpleViewParser::T__4);
        break;
      }

      case SimpleViewParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(319);
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
    setState(322);
    match(SimpleViewParser::T__17);
    setState(323);
    pointInLine();
    setState(328);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__3) {
      setState(324);
      match(SimpleViewParser::T__3);
      setState(325);
      pointInLine();
      setState(330);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(331);
    match(SimpleViewParser::T__18);
   
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
//----------------- GlueDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* SimpleViewParser::GlueDeclarationContext::GLUE() {
  return getToken(SimpleViewParser::GLUE, 0);
}

tree::TerminalNode* SimpleViewParser::GlueDeclarationContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

std::vector<SimpleViewParser::GlueAttrContext *> SimpleViewParser::GlueDeclarationContext::glueAttr() {
  return getRuleContexts<SimpleViewParser::GlueAttrContext>();
}

SimpleViewParser::GlueAttrContext* SimpleViewParser::GlueDeclarationContext::glueAttr(size_t i) {
  return getRuleContext<SimpleViewParser::GlueAttrContext>(i);
}

SimpleViewParser::GlueDeclarationContext::GlueDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::GlueDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitGlueDeclaration(this);
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
    setState(376);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::CLASS_SCOPE: {
        _localctx = _tracker.createInstance<SimpleViewParser::ClassScopeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(333);
        match(SimpleViewParser::CLASS_SCOPE);
        setState(334);
        match(SimpleViewParser::IDENTIFIER);
        setState(335);
        match(SimpleViewParser::T__19);
        setState(336);
        classScopeExp(0);
        break;
      }

      case SimpleViewParser::NODE: {
        _localctx = _tracker.createInstance<SimpleViewParser::NodeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(337);
        match(SimpleViewParser::NODE);
        setState(338);
        match(SimpleViewParser::IDENTIFIER);
        setState(339);
        match(SimpleViewParser::T__19);
        setState(340);
        nodeExp(0);
        break;
      }

      case SimpleViewParser::SEGMENT:
      case SimpleViewParser::LINE:
      case SimpleViewParser::CODE_ORDER: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(341);
        _la = _input->LA(1);
        if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 71)) & 2051) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(342);
        match(SimpleViewParser::IDENTIFIER);
        setState(344);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__5) {
          setState(343);
          paramList();
        }
        setState(346);
        match(SimpleViewParser::T__19);
        setState(347);
        lineExp();
        break;
      }

      case SimpleViewParser::GLUE: {
        _localctx = _tracker.createInstance<SimpleViewParser::GlueDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(348);
        match(SimpleViewParser::GLUE);
        setState(349);
        match(SimpleViewParser::IDENTIFIER);
        setState(350);
        match(SimpleViewParser::T__19);
        setState(351);
        match(SimpleViewParser::T__10);
        setState(355);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 75) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 75)) & 31) != 0)) {
          setState(352);
          glueAttr();
          setState(357);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(358);
        match(SimpleViewParser::T__11);
        break;
      }

      case SimpleViewParser::GRAPH: {
        _localctx = _tracker.createInstance<SimpleViewParser::GraphDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(359);
        match(SimpleViewParser::GRAPH);
        setState(360);
        antlrcpp::downCast<GraphDeclarationContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
        setState(362);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__5) {
          setState(361);
          paramList();
        }
        setState(364);
        match(SimpleViewParser::T__19);
        setState(365);
        graphBody();
        setState(367); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(366);
          intersectionPoint();
          setState(369); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SimpleViewParser::T__17);
        break;
      }

      case SimpleViewParser::LINE_INSTANCE:
      case SimpleViewParser::GRAPH_INSTANCE: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineAndGraphInstanceContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(371);
        _la = _input->LA(1);
        if (!(_la == SimpleViewParser::LINE_INSTANCE

        || _la == SimpleViewParser::GRAPH_INSTANCE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(372);
        match(SimpleViewParser::IDENTIFIER);
        setState(373);
        match(SimpleViewParser::T__19);
        setState(374);
        match(SimpleViewParser::IDENTIFIER);
        setState(375);
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
    setState(378);
    match(SimpleViewParser::SHOW);
    setState(379);
    match(SimpleViewParser::T__5);
    setState(380);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
    setState(381);
    match(SimpleViewParser::T__3);
    setState(382);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->defaultStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(383);
    match(SimpleViewParser::T__3);
    setState(384);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->basicStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(385);
    match(SimpleViewParser::T__6);
   
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
    case 2: return classScopeExpSempred(antlrcpp::downCast<ClassScopeExpContext *>(context), predicateIndex);
    case 3: return nodeExpSempred(antlrcpp::downCast<NodeExpContext *>(context), predicateIndex);

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
    case 3: return precpred(_ctx, 25);
    case 4: return precpred(_ctx, 24);
    case 5: return precpred(_ctx, 23);

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
