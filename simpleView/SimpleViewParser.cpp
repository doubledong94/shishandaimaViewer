
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
      "compilationUnit", "styleAttr", "basicStyleAttr", "styleAttrList", 
      "glueAttr", "classScopeExp", "nodeExp", "paramList", "lineExp", "lineSegOrNodeExp", 
      "lineArgumentList", "graphElement", "graphBody", "pointInLine", "intersectionPoint", 
      "declaration", "showCommand"
    },
    std::vector<std::string>{
      "", "';'", "':'", "'['", "','", "']'", "'('", "')'", "'|'", "'&'", 
      "'-'", "'->'", "'{'", "'}'", "'\\u003F'", "'*'", "'+'", "'<'", "'>'", 
      "'='", "'\"simple\"'", "'\"full\"'", "'nodeColor'", "'nodeScale'", 
      "'labelColor'", "'labelScale'", "'labelDetailLevel'", "'positionZ'", 
      "'basicNodeSize'", "'basicLabelSize'", "'basicPositionZ'", "'Any'", 
      "'FieldOf'", "'InstanceOf'", "'MethodOf'", "'CreatorOf'", "'ParameterOf'", 
      "'ReturnOf'", "'CalledParamOf'", "'CalledReturnOf'", "'CalledMethodOf'", 
      "'read'", "'write'", "'inPackage'", "'usedBy'", "'use'", "'classOf'", 
      "'superOf'", "'subOf'", "'Style'", "'DefaultStyle'", "'BasicStyle'", 
      "'ClassScope'", "'Node'", "'Reference'", "'Condition'", "'Step'", 
      "'Seg'", "'Line'", "'LineInstance'", "'Glue'", "'GlueRuntime'", "'GlueMemberOf'", 
      "'GlueInstanceOf'", "'GlueOverride'", "'GlueHierarchy'", "'Graph'", 
      "'GraphInstance'", "'CodeOrder'", "'show'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "LABEL_DETAIL_LEVEL_SIMPLE", "LABEL_DETAIL_LEVEL_FULL", 
      "NODE_COLOR", "NODE_SCALE", "LABEL_COLOR", "LABEL_SCALE", "LABEL_DETAIL_LEVEL", 
      "POSITION_Z", "BASIC_NODE_SIZE", "BASIC_LABEL_SIZE", "BASIC_POSITION_Z", 
      "ANY", "FIELD_OF", "INSTANCE_OF", "METHOD_OF", "CREATOR", "PARAMETER_OF", 
      "RETURN_OF", "CALLED_PARAM_OF", "CALLED_RETURN_OF", "CALLED_METHOD_OF", 
      "READ", "WRITE", "IN_PACKAGE", "USED_BY", "USE", "CLASS_OF", "SUPER", 
      "SUB", "STYLE", "DEFAULT_STYLE", "BASIC_STYLE", "CLASS_SCOPE", "NODE", 
      "REFERENCE", "CONDITION", "STEP", "SEGMENT", "LINE", "LINE_INSTANCE", 
      "GLUE", "GLUE_RUNTIME", "GLULE_MEMBER_OF", "GLUE_INSTANCE_OF", "GLUE_OVERRIDE", 
      "GLUE_HIERARCHY", "GRAPH", "GRAPH_INSTANCE", "CODE_ORDER", "SHOW", 
      "STRING", "IDENTIFIER", "FLOAT", "INT", "WS", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,75,444,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,1,0,1,0,1,0,4,0,38,8,0,11,0,12,0,39,1,0,1,0,1,
  	0,5,0,45,8,0,10,0,12,0,48,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,74,8,1,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,88,8,2,1,3,4,3,91,8,
  	3,11,3,12,3,92,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,120,8,4,1,5,1,5,1,5,
  	1,5,1,5,1,5,5,5,128,8,5,10,5,12,5,131,9,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,3,5,163,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	5,5,174,8,5,10,5,12,5,177,9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,5,6,194,8,6,10,6,12,6,197,9,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,266,8,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,5,6,277,8,6,10,6,12,6,280,9,6,1,7,1,7,1,7,1,7,5,7,286,
  	8,7,10,7,12,7,289,9,7,1,7,1,7,1,8,1,8,1,8,4,8,296,8,8,11,8,12,8,297,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,307,8,9,1,9,3,9,310,8,9,3,9,312,8,9,1,9,
  	3,9,315,8,9,1,10,1,10,1,10,1,10,5,10,321,8,10,10,10,12,10,324,9,10,1,
  	10,1,10,1,11,1,11,3,11,330,8,11,1,12,1,12,1,12,5,12,335,8,12,10,12,12,
  	12,338,9,12,1,13,1,13,1,13,1,13,5,13,344,8,13,10,13,12,13,347,9,13,1,
  	13,1,13,1,13,3,13,352,8,13,1,14,1,14,1,14,1,14,5,14,358,8,14,10,14,12,
  	14,361,9,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,4,15,384,8,15,11,15,12,
  	15,385,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,3,15,401,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,5,15,410,8,15,10,
  	15,12,15,413,9,15,1,15,1,15,1,15,1,15,3,15,419,8,15,1,15,1,15,1,15,4,
  	15,424,8,15,11,15,12,15,425,1,15,1,15,1,15,1,15,1,15,3,15,433,8,15,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,0,2,10,12,17,0,2,4,6,
  	8,10,12,14,16,18,20,22,24,26,28,30,32,0,4,1,0,20,21,1,0,14,16,2,0,57,
  	58,68,68,2,0,59,59,67,67,499,0,37,1,0,0,0,2,73,1,0,0,0,4,87,1,0,0,0,6,
  	90,1,0,0,0,8,119,1,0,0,0,10,162,1,0,0,0,12,265,1,0,0,0,14,281,1,0,0,0,
  	16,292,1,0,0,0,18,311,1,0,0,0,20,316,1,0,0,0,22,327,1,0,0,0,24,331,1,
  	0,0,0,26,351,1,0,0,0,28,353,1,0,0,0,30,432,1,0,0,0,32,434,1,0,0,0,34,
  	35,3,30,15,0,35,36,5,1,0,0,36,38,1,0,0,0,37,34,1,0,0,0,38,39,1,0,0,0,
  	39,37,1,0,0,0,39,40,1,0,0,0,40,46,1,0,0,0,41,42,3,32,16,0,42,43,5,1,0,
  	0,43,45,1,0,0,0,44,41,1,0,0,0,45,48,1,0,0,0,46,44,1,0,0,0,46,47,1,0,0,
  	0,47,1,1,0,0,0,48,46,1,0,0,0,49,50,5,22,0,0,50,51,5,2,0,0,51,52,5,70,
  	0,0,52,74,5,1,0,0,53,54,5,23,0,0,54,55,5,2,0,0,55,56,5,72,0,0,56,74,5,
  	1,0,0,57,58,5,24,0,0,58,59,5,2,0,0,59,60,5,70,0,0,60,74,5,1,0,0,61,62,
  	5,25,0,0,62,63,5,2,0,0,63,64,5,72,0,0,64,74,5,1,0,0,65,66,5,26,0,0,66,
  	67,5,2,0,0,67,68,7,0,0,0,68,74,5,1,0,0,69,70,5,27,0,0,70,71,5,2,0,0,71,
  	72,5,72,0,0,72,74,5,1,0,0,73,49,1,0,0,0,73,53,1,0,0,0,73,57,1,0,0,0,73,
  	61,1,0,0,0,73,65,1,0,0,0,73,69,1,0,0,0,74,3,1,0,0,0,75,76,5,28,0,0,76,
  	77,5,2,0,0,77,78,5,72,0,0,78,88,5,1,0,0,79,80,5,29,0,0,80,81,5,2,0,0,
  	81,82,5,72,0,0,82,88,5,1,0,0,83,84,5,30,0,0,84,85,5,2,0,0,85,86,5,72,
  	0,0,86,88,5,1,0,0,87,75,1,0,0,0,87,79,1,0,0,0,87,83,1,0,0,0,88,5,1,0,
  	0,0,89,91,3,2,1,0,90,89,1,0,0,0,91,92,1,0,0,0,92,90,1,0,0,0,92,93,1,0,
  	0,0,93,7,1,0,0,0,94,95,5,61,0,0,95,96,5,2,0,0,96,97,3,12,6,0,97,98,5,
  	1,0,0,98,120,1,0,0,0,99,100,5,62,0,0,100,101,5,2,0,0,101,102,3,10,5,0,
  	102,103,5,1,0,0,103,120,1,0,0,0,104,105,5,63,0,0,105,106,5,2,0,0,106,
  	107,3,10,5,0,107,108,5,1,0,0,108,120,1,0,0,0,109,110,5,64,0,0,110,111,
  	5,2,0,0,111,112,3,12,6,0,112,113,5,1,0,0,113,120,1,0,0,0,114,115,5,65,
  	0,0,115,116,5,2,0,0,116,117,3,10,5,0,117,118,5,1,0,0,118,120,1,0,0,0,
  	119,94,1,0,0,0,119,99,1,0,0,0,119,104,1,0,0,0,119,109,1,0,0,0,119,114,
  	1,0,0,0,120,9,1,0,0,0,121,122,6,5,-1,0,122,163,5,70,0,0,123,124,5,3,0,
  	0,124,129,5,70,0,0,125,126,5,4,0,0,126,128,5,70,0,0,127,125,1,0,0,0,128,
  	131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,132,1,0,0,0,131,129,1,
  	0,0,0,132,163,5,5,0,0,133,134,5,43,0,0,134,135,5,6,0,0,135,136,5,70,0,
  	0,136,163,5,7,0,0,137,138,5,44,0,0,138,139,5,6,0,0,139,140,3,10,5,0,140,
  	141,5,7,0,0,141,163,1,0,0,0,142,143,5,45,0,0,143,144,5,6,0,0,144,145,
  	3,10,5,0,145,146,5,7,0,0,146,163,1,0,0,0,147,148,5,47,0,0,148,149,5,6,
  	0,0,149,150,3,10,5,0,150,151,5,7,0,0,151,163,1,0,0,0,152,153,5,48,0,0,
  	153,154,5,6,0,0,154,155,3,10,5,0,155,156,5,7,0,0,156,163,1,0,0,0,157,
  	158,5,6,0,0,158,159,3,10,5,0,159,160,5,7,0,0,160,163,1,0,0,0,161,163,
  	5,71,0,0,162,121,1,0,0,0,162,123,1,0,0,0,162,133,1,0,0,0,162,137,1,0,
  	0,0,162,142,1,0,0,0,162,147,1,0,0,0,162,152,1,0,0,0,162,157,1,0,0,0,162,
  	161,1,0,0,0,163,175,1,0,0,0,164,165,10,5,0,0,165,166,5,8,0,0,166,174,
  	3,10,5,6,167,168,10,4,0,0,168,169,5,9,0,0,169,174,3,10,5,5,170,171,10,
  	3,0,0,171,172,5,10,0,0,172,174,3,10,5,4,173,164,1,0,0,0,173,167,1,0,0,
  	0,173,170,1,0,0,0,174,177,1,0,0,0,175,173,1,0,0,0,175,176,1,0,0,0,176,
  	11,1,0,0,0,177,175,1,0,0,0,178,179,6,6,-1,0,179,180,5,70,0,0,180,181,
  	5,6,0,0,181,182,5,70,0,0,182,266,5,7,0,0,183,184,5,3,0,0,184,185,5,70,
  	0,0,185,186,5,6,0,0,186,187,5,70,0,0,187,195,5,7,0,0,188,189,5,4,0,0,
  	189,190,5,70,0,0,190,191,5,6,0,0,191,192,5,70,0,0,192,194,5,7,0,0,193,
  	188,1,0,0,0,194,197,1,0,0,0,195,193,1,0,0,0,195,196,1,0,0,0,196,198,1,
  	0,0,0,197,195,1,0,0,0,198,266,5,5,0,0,199,200,5,32,0,0,200,201,5,6,0,
  	0,201,202,3,10,5,0,202,203,5,7,0,0,203,266,1,0,0,0,204,205,5,34,0,0,205,
  	206,5,6,0,0,206,207,3,10,5,0,207,208,5,7,0,0,208,266,1,0,0,0,209,210,
  	5,36,0,0,210,211,5,6,0,0,211,212,3,12,6,0,212,213,5,7,0,0,213,266,1,0,
  	0,0,214,215,5,37,0,0,215,216,5,6,0,0,216,217,3,12,6,0,217,218,5,7,0,0,
  	218,266,1,0,0,0,219,220,5,33,0,0,220,221,5,6,0,0,221,222,3,10,5,0,222,
  	223,5,4,0,0,223,224,3,10,5,0,224,225,5,7,0,0,225,266,1,0,0,0,226,227,
  	5,35,0,0,227,228,5,6,0,0,228,229,3,10,5,0,229,230,5,7,0,0,230,266,1,0,
  	0,0,231,232,5,40,0,0,232,233,5,6,0,0,233,234,3,12,6,0,234,235,5,7,0,0,
  	235,266,1,0,0,0,236,237,5,38,0,0,237,238,5,6,0,0,238,239,3,12,6,0,239,
  	240,5,7,0,0,240,266,1,0,0,0,241,242,5,39,0,0,242,243,5,6,0,0,243,244,
  	3,12,6,0,244,245,5,7,0,0,245,266,1,0,0,0,246,247,5,41,0,0,247,248,5,6,
  	0,0,248,249,3,12,6,0,249,250,5,7,0,0,250,266,1,0,0,0,251,252,5,42,0,0,
  	252,253,5,6,0,0,253,254,3,12,6,0,254,255,5,7,0,0,255,266,1,0,0,0,256,
  	266,5,31,0,0,257,266,5,54,0,0,258,266,5,55,0,0,259,266,5,56,0,0,260,261,
  	5,6,0,0,261,262,3,12,6,0,262,263,5,7,0,0,263,266,1,0,0,0,264,266,5,71,
  	0,0,265,178,1,0,0,0,265,183,1,0,0,0,265,199,1,0,0,0,265,204,1,0,0,0,265,
  	209,1,0,0,0,265,214,1,0,0,0,265,219,1,0,0,0,265,226,1,0,0,0,265,231,1,
  	0,0,0,265,236,1,0,0,0,265,241,1,0,0,0,265,246,1,0,0,0,265,251,1,0,0,0,
  	265,256,1,0,0,0,265,257,1,0,0,0,265,258,1,0,0,0,265,259,1,0,0,0,265,260,
  	1,0,0,0,265,264,1,0,0,0,266,278,1,0,0,0,267,268,10,11,0,0,268,269,5,9,
  	0,0,269,277,3,12,6,12,270,271,10,10,0,0,271,272,5,8,0,0,272,277,3,12,
  	6,11,273,274,10,9,0,0,274,275,5,10,0,0,275,277,3,12,6,10,276,267,1,0,
  	0,0,276,270,1,0,0,0,276,273,1,0,0,0,277,280,1,0,0,0,278,276,1,0,0,0,278,
  	279,1,0,0,0,279,13,1,0,0,0,280,278,1,0,0,0,281,282,5,6,0,0,282,287,5,
  	71,0,0,283,284,5,4,0,0,284,286,5,71,0,0,285,283,1,0,0,0,286,289,1,0,0,
  	0,287,285,1,0,0,0,287,288,1,0,0,0,288,290,1,0,0,0,289,287,1,0,0,0,290,
  	291,5,7,0,0,291,15,1,0,0,0,292,295,3,18,9,0,293,294,5,11,0,0,294,296,
  	3,18,9,0,295,293,1,0,0,0,296,297,1,0,0,0,297,295,1,0,0,0,297,298,1,0,
  	0,0,298,17,1,0,0,0,299,300,5,3,0,0,300,301,5,71,0,0,301,312,5,5,0,0,302,
  	309,3,12,6,0,303,306,5,12,0,0,304,307,5,71,0,0,305,307,3,6,3,0,306,304,
  	1,0,0,0,306,305,1,0,0,0,307,308,1,0,0,0,308,310,5,13,0,0,309,303,1,0,
  	0,0,309,310,1,0,0,0,310,312,1,0,0,0,311,299,1,0,0,0,311,302,1,0,0,0,312,
  	314,1,0,0,0,313,315,7,1,0,0,314,313,1,0,0,0,314,315,1,0,0,0,315,19,1,
  	0,0,0,316,317,5,6,0,0,317,322,5,71,0,0,318,319,5,4,0,0,319,321,5,71,0,
  	0,320,318,1,0,0,0,321,324,1,0,0,0,322,320,1,0,0,0,322,323,1,0,0,0,323,
  	325,1,0,0,0,324,322,1,0,0,0,325,326,5,7,0,0,326,21,1,0,0,0,327,329,5,
  	71,0,0,328,330,3,20,10,0,329,328,1,0,0,0,329,330,1,0,0,0,330,23,1,0,0,
  	0,331,336,3,22,11,0,332,333,5,4,0,0,333,335,3,22,11,0,334,332,1,0,0,0,
  	335,338,1,0,0,0,336,334,1,0,0,0,336,337,1,0,0,0,337,25,1,0,0,0,338,336,
  	1,0,0,0,339,340,5,3,0,0,340,345,3,26,13,0,341,342,5,4,0,0,342,344,3,26,
  	13,0,343,341,1,0,0,0,344,347,1,0,0,0,345,343,1,0,0,0,345,346,1,0,0,0,
  	346,348,1,0,0,0,347,345,1,0,0,0,348,349,5,5,0,0,349,352,1,0,0,0,350,352,
  	5,73,0,0,351,339,1,0,0,0,351,350,1,0,0,0,352,27,1,0,0,0,353,354,5,17,
  	0,0,354,359,3,26,13,0,355,356,5,4,0,0,356,358,3,26,13,0,357,355,1,0,0,
  	0,358,361,1,0,0,0,359,357,1,0,0,0,359,360,1,0,0,0,360,362,1,0,0,0,361,
  	359,1,0,0,0,362,363,5,18,0,0,363,29,1,0,0,0,364,365,5,49,0,0,365,366,
  	5,71,0,0,366,367,5,19,0,0,367,368,5,12,0,0,368,369,3,6,3,0,369,370,5,
  	13,0,0,370,433,1,0,0,0,371,372,5,50,0,0,372,373,5,71,0,0,373,374,5,19,
  	0,0,374,375,5,12,0,0,375,376,3,6,3,0,376,377,5,13,0,0,377,433,1,0,0,0,
  	378,379,5,51,0,0,379,380,5,71,0,0,380,381,5,19,0,0,381,383,5,12,0,0,382,
  	384,3,4,2,0,383,382,1,0,0,0,384,385,1,0,0,0,385,383,1,0,0,0,385,386,1,
  	0,0,0,386,387,1,0,0,0,387,388,5,13,0,0,388,433,1,0,0,0,389,390,5,52,0,
  	0,390,391,5,71,0,0,391,392,5,19,0,0,392,433,3,10,5,0,393,394,5,53,0,0,
  	394,395,5,71,0,0,395,396,5,19,0,0,396,433,3,12,6,0,397,398,7,2,0,0,398,
  	400,5,71,0,0,399,401,3,14,7,0,400,399,1,0,0,0,400,401,1,0,0,0,401,402,
  	1,0,0,0,402,403,5,19,0,0,403,433,3,16,8,0,404,405,5,60,0,0,405,406,5,
  	71,0,0,406,407,5,19,0,0,407,411,5,12,0,0,408,410,3,8,4,0,409,408,1,0,
  	0,0,410,413,1,0,0,0,411,409,1,0,0,0,411,412,1,0,0,0,412,414,1,0,0,0,413,
  	411,1,0,0,0,414,433,5,13,0,0,415,416,5,66,0,0,416,418,5,71,0,0,417,419,
  	3,14,7,0,418,417,1,0,0,0,418,419,1,0,0,0,419,420,1,0,0,0,420,421,5,19,
  	0,0,421,423,3,24,12,0,422,424,3,28,14,0,423,422,1,0,0,0,424,425,1,0,0,
  	0,425,423,1,0,0,0,425,426,1,0,0,0,426,433,1,0,0,0,427,428,7,3,0,0,428,
  	429,5,71,0,0,429,430,5,19,0,0,430,431,5,71,0,0,431,433,3,20,10,0,432,
  	364,1,0,0,0,432,371,1,0,0,0,432,378,1,0,0,0,432,389,1,0,0,0,432,393,1,
  	0,0,0,432,397,1,0,0,0,432,404,1,0,0,0,432,415,1,0,0,0,432,427,1,0,0,0,
  	433,31,1,0,0,0,434,435,5,69,0,0,435,436,5,6,0,0,436,437,5,71,0,0,437,
  	438,5,4,0,0,438,439,5,71,0,0,439,440,5,4,0,0,440,441,5,71,0,0,441,442,
  	5,7,0,0,442,33,1,0,0,0,32,39,46,73,87,92,119,129,162,173,175,195,265,
  	276,278,287,297,306,309,311,314,322,329,336,345,351,359,385,400,411,418,
  	425,432
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
    setState(37); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(34);
      declaration();
      setState(35);
      match(SimpleViewParser::T__0);
      setState(39); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 49) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 49)) & 921375) != 0));
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::SHOW) {
      setState(41);
      showCommand();
      setState(42);
      match(SimpleViewParser::T__0);
      setState(48);
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

//----------------- StyleAttrContext ------------------------------------------------------------------

SimpleViewParser::StyleAttrContext::StyleAttrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::NODE_COLOR() {
  return getToken(SimpleViewParser::NODE_COLOR, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::STRING() {
  return getToken(SimpleViewParser::STRING, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::NODE_SCALE() {
  return getToken(SimpleViewParser::NODE_SCALE, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::FLOAT() {
  return getToken(SimpleViewParser::FLOAT, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::LABEL_COLOR() {
  return getToken(SimpleViewParser::LABEL_COLOR, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::LABEL_SCALE() {
  return getToken(SimpleViewParser::LABEL_SCALE, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::LABEL_DETAIL_LEVEL() {
  return getToken(SimpleViewParser::LABEL_DETAIL_LEVEL, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::LABEL_DETAIL_LEVEL_SIMPLE() {
  return getToken(SimpleViewParser::LABEL_DETAIL_LEVEL_SIMPLE, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::LABEL_DETAIL_LEVEL_FULL() {
  return getToken(SimpleViewParser::LABEL_DETAIL_LEVEL_FULL, 0);
}

tree::TerminalNode* SimpleViewParser::StyleAttrContext::POSITION_Z() {
  return getToken(SimpleViewParser::POSITION_Z, 0);
}


size_t SimpleViewParser::StyleAttrContext::getRuleIndex() const {
  return SimpleViewParser::RuleStyleAttr;
}


std::any SimpleViewParser::StyleAttrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitStyleAttr(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::StyleAttrContext* SimpleViewParser::styleAttr() {
  StyleAttrContext *_localctx = _tracker.createInstance<StyleAttrContext>(_ctx, getState());
  enterRule(_localctx, 2, SimpleViewParser::RuleStyleAttr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::NODE_COLOR: {
        enterOuterAlt(_localctx, 1);
        setState(49);
        match(SimpleViewParser::NODE_COLOR);
        setState(50);
        match(SimpleViewParser::T__1);
        setState(51);
        match(SimpleViewParser::STRING);
        setState(52);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::NODE_SCALE: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        match(SimpleViewParser::NODE_SCALE);
        setState(54);
        match(SimpleViewParser::T__1);
        setState(55);
        match(SimpleViewParser::FLOAT);
        setState(56);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::LABEL_COLOR: {
        enterOuterAlt(_localctx, 3);
        setState(57);
        match(SimpleViewParser::LABEL_COLOR);
        setState(58);
        match(SimpleViewParser::T__1);
        setState(59);
        match(SimpleViewParser::STRING);
        setState(60);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::LABEL_SCALE: {
        enterOuterAlt(_localctx, 4);
        setState(61);
        match(SimpleViewParser::LABEL_SCALE);
        setState(62);
        match(SimpleViewParser::T__1);
        setState(63);
        match(SimpleViewParser::FLOAT);
        setState(64);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::LABEL_DETAIL_LEVEL: {
        enterOuterAlt(_localctx, 5);
        setState(65);
        match(SimpleViewParser::LABEL_DETAIL_LEVEL);
        setState(66);
        match(SimpleViewParser::T__1);
        setState(67);
        _la = _input->LA(1);
        if (!(_la == SimpleViewParser::LABEL_DETAIL_LEVEL_SIMPLE

        || _la == SimpleViewParser::LABEL_DETAIL_LEVEL_FULL)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(68);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::POSITION_Z: {
        enterOuterAlt(_localctx, 6);
        setState(69);
        match(SimpleViewParser::POSITION_Z);
        setState(70);
        match(SimpleViewParser::T__1);
        setState(71);
        match(SimpleViewParser::FLOAT);
        setState(72);
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

//----------------- BasicStyleAttrContext ------------------------------------------------------------------

SimpleViewParser::BasicStyleAttrContext::BasicStyleAttrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SimpleViewParser::BasicStyleAttrContext::BASIC_NODE_SIZE() {
  return getToken(SimpleViewParser::BASIC_NODE_SIZE, 0);
}

tree::TerminalNode* SimpleViewParser::BasicStyleAttrContext::FLOAT() {
  return getToken(SimpleViewParser::FLOAT, 0);
}

tree::TerminalNode* SimpleViewParser::BasicStyleAttrContext::BASIC_LABEL_SIZE() {
  return getToken(SimpleViewParser::BASIC_LABEL_SIZE, 0);
}

tree::TerminalNode* SimpleViewParser::BasicStyleAttrContext::BASIC_POSITION_Z() {
  return getToken(SimpleViewParser::BASIC_POSITION_Z, 0);
}


size_t SimpleViewParser::BasicStyleAttrContext::getRuleIndex() const {
  return SimpleViewParser::RuleBasicStyleAttr;
}


std::any SimpleViewParser::BasicStyleAttrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitBasicStyleAttr(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::BasicStyleAttrContext* SimpleViewParser::basicStyleAttr() {
  BasicStyleAttrContext *_localctx = _tracker.createInstance<BasicStyleAttrContext>(_ctx, getState());
  enterRule(_localctx, 4, SimpleViewParser::RuleBasicStyleAttr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::BASIC_NODE_SIZE: {
        enterOuterAlt(_localctx, 1);
        setState(75);
        match(SimpleViewParser::BASIC_NODE_SIZE);
        setState(76);
        match(SimpleViewParser::T__1);
        setState(77);
        match(SimpleViewParser::FLOAT);
        setState(78);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::BASIC_LABEL_SIZE: {
        enterOuterAlt(_localctx, 2);
        setState(79);
        match(SimpleViewParser::BASIC_LABEL_SIZE);
        setState(80);
        match(SimpleViewParser::T__1);
        setState(81);
        match(SimpleViewParser::FLOAT);
        setState(82);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::BASIC_POSITION_Z: {
        enterOuterAlt(_localctx, 3);
        setState(83);
        match(SimpleViewParser::BASIC_POSITION_Z);
        setState(84);
        match(SimpleViewParser::T__1);
        setState(85);
        match(SimpleViewParser::FLOAT);
        setState(86);
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

//----------------- StyleAttrListContext ------------------------------------------------------------------

SimpleViewParser::StyleAttrListContext::StyleAttrListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SimpleViewParser::StyleAttrContext *> SimpleViewParser::StyleAttrListContext::styleAttr() {
  return getRuleContexts<SimpleViewParser::StyleAttrContext>();
}

SimpleViewParser::StyleAttrContext* SimpleViewParser::StyleAttrListContext::styleAttr(size_t i) {
  return getRuleContext<SimpleViewParser::StyleAttrContext>(i);
}


size_t SimpleViewParser::StyleAttrListContext::getRuleIndex() const {
  return SimpleViewParser::RuleStyleAttrList;
}


std::any SimpleViewParser::StyleAttrListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitStyleAttrList(this);
  else
    return visitor->visitChildren(this);
}

SimpleViewParser::StyleAttrListContext* SimpleViewParser::styleAttrList() {
  StyleAttrListContext *_localctx = _tracker.createInstance<StyleAttrListContext>(_ctx, getState());
  enterRule(_localctx, 6, SimpleViewParser::RuleStyleAttrList);
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
    setState(90); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(89);
      styleAttr();
      setState(92); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 264241152) != 0));
   
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
  enterRule(_localctx, 8, SimpleViewParser::RuleGlueAttr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::GLUE_RUNTIME: {
        enterOuterAlt(_localctx, 1);
        setState(94);
        match(SimpleViewParser::GLUE_RUNTIME);
        setState(95);
        match(SimpleViewParser::T__1);
        setState(96);
        nodeExp(0);
        setState(97);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::GLULE_MEMBER_OF: {
        enterOuterAlt(_localctx, 2);
        setState(99);
        match(SimpleViewParser::GLULE_MEMBER_OF);
        setState(100);
        match(SimpleViewParser::T__1);
        setState(101);
        classScopeExp(0);
        setState(102);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::GLUE_INSTANCE_OF: {
        enterOuterAlt(_localctx, 3);
        setState(104);
        match(SimpleViewParser::GLUE_INSTANCE_OF);
        setState(105);
        match(SimpleViewParser::T__1);
        setState(106);
        classScopeExp(0);
        setState(107);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::GLUE_OVERRIDE: {
        enterOuterAlt(_localctx, 4);
        setState(109);
        match(SimpleViewParser::GLUE_OVERRIDE);
        setState(110);
        match(SimpleViewParser::T__1);
        setState(111);
        nodeExp(0);
        setState(112);
        match(SimpleViewParser::T__0);
        break;
      }

      case SimpleViewParser::GLUE_HIERARCHY: {
        enterOuterAlt(_localctx, 5);
        setState(114);
        match(SimpleViewParser::GLUE_HIERARCHY);
        setState(115);
        match(SimpleViewParser::T__1);
        setState(116);
        classScopeExp(0);
        setState(117);
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
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, SimpleViewParser::RuleClassScopeExp, precedence);

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
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STRING: {
        setState(122);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKey = match(SimpleViewParser::STRING);
        break;
      }

      case SimpleViewParser::T__2: {
        setState(123);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->classKeyList = match(SimpleViewParser::T__2);
        setState(124);
        match(SimpleViewParser::STRING);
        setState(129);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__3) {
          setState(125);
          match(SimpleViewParser::T__3);
          setState(126);
          match(SimpleViewParser::STRING);
          setState(131);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(132);
        match(SimpleViewParser::T__4);
        break;
      }

      case SimpleViewParser::IN_PACKAGE: {
        setState(133);
        match(SimpleViewParser::IN_PACKAGE);
        setState(134);
        match(SimpleViewParser::T__5);
        setState(135);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->packageStr = match(SimpleViewParser::STRING);
        setState(136);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::USED_BY: {
        setState(137);
        match(SimpleViewParser::USED_BY);
        setState(138);
        match(SimpleViewParser::T__5);
        setState(139);
        classScopeExp(0);
        setState(140);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::USE: {
        setState(142);
        match(SimpleViewParser::USE);
        setState(143);
        match(SimpleViewParser::T__5);
        setState(144);
        classScopeExp(0);
        setState(145);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::SUPER: {
        setState(147);
        match(SimpleViewParser::SUPER);
        setState(148);
        match(SimpleViewParser::T__5);
        setState(149);
        classScopeExp(0);
        setState(150);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::SUB: {
        setState(152);
        match(SimpleViewParser::SUB);
        setState(153);
        match(SimpleViewParser::T__5);
        setState(154);
        classScopeExp(0);
        setState(155);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::T__5: {
        setState(157);
        match(SimpleViewParser::T__5);
        setState(158);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->bracket = classScopeExp(0);
        setState(159);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::IDENTIFIER: {
        setState(161);
        antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->refOtherScope = match(SimpleViewParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(175);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(173);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(164);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(165);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__7);
          setState(166);
          classScopeExp(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(167);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(168);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__8);
          setState(169);
          classScopeExp(5);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ClassScopeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleClassScopeExp);
          setState(170);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(171);
          antlrcpp::downCast<ClassScopeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__9);
          setState(172);
          classScopeExp(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(177);
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

tree::TerminalNode* SimpleViewParser::NodeExpContext::STEP() {
  return getToken(SimpleViewParser::STEP, 0);
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
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, SimpleViewParser::RuleNodeExp, precedence);

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
    setState(265);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STRING: {
        setState(179);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKey = match(SimpleViewParser::STRING);
        setState(180);
        match(SimpleViewParser::T__5);
        setState(181);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->typeKey = match(SimpleViewParser::STRING);
        setState(182);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::T__2: {
        setState(183);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->nodeKeyList = match(SimpleViewParser::T__2);
        setState(184);
        match(SimpleViewParser::STRING);
        setState(185);
        match(SimpleViewParser::T__5);
        setState(186);
        match(SimpleViewParser::STRING);
        setState(187);
        match(SimpleViewParser::T__6);
        setState(195);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__3) {
          setState(188);
          match(SimpleViewParser::T__3);
          setState(189);
          match(SimpleViewParser::STRING);
          setState(190);
          match(SimpleViewParser::T__5);
          setState(191);
          match(SimpleViewParser::STRING);
          setState(192);
          match(SimpleViewParser::T__6);
          setState(197);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(198);
        match(SimpleViewParser::T__4);
        break;
      }

      case SimpleViewParser::FIELD_OF: {
        setState(199);
        match(SimpleViewParser::FIELD_OF);
        setState(200);
        match(SimpleViewParser::T__5);
        setState(201);
        classScopeExp(0);
        setState(202);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::METHOD_OF: {
        setState(204);
        match(SimpleViewParser::METHOD_OF);
        setState(205);
        match(SimpleViewParser::T__5);
        setState(206);
        classScopeExp(0);
        setState(207);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::PARAMETER_OF: {
        setState(209);
        match(SimpleViewParser::PARAMETER_OF);
        setState(210);
        match(SimpleViewParser::T__5);
        setState(211);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(212);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::RETURN_OF: {
        setState(214);
        match(SimpleViewParser::RETURN_OF);
        setState(215);
        match(SimpleViewParser::T__5);
        setState(216);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(217);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::INSTANCE_OF: {
        setState(219);
        match(SimpleViewParser::INSTANCE_OF);
        setState(220);
        match(SimpleViewParser::T__5);
        setState(221);
        classScopeExp(0);
        setState(222);
        match(SimpleViewParser::T__3);
        setState(223);
        classScopeExp(0);
        setState(224);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::CREATOR: {
        setState(226);
        match(SimpleViewParser::CREATOR);
        setState(227);
        match(SimpleViewParser::T__5);
        setState(228);
        classScopeExp(0);
        setState(229);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::CALLED_METHOD_OF: {
        setState(231);
        match(SimpleViewParser::CALLED_METHOD_OF);
        setState(232);
        match(SimpleViewParser::T__5);
        setState(233);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->methodNode = nodeExp(0);
        setState(234);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::CALLED_PARAM_OF: {
        setState(236);
        match(SimpleViewParser::CALLED_PARAM_OF);
        setState(237);
        match(SimpleViewParser::T__5);
        setState(238);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->paramNode = nodeExp(0);
        setState(239);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::CALLED_RETURN_OF: {
        setState(241);
        match(SimpleViewParser::CALLED_RETURN_OF);
        setState(242);
        match(SimpleViewParser::T__5);
        setState(243);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->returnNode = nodeExp(0);
        setState(244);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::READ: {
        setState(246);
        match(SimpleViewParser::READ);
        setState(247);
        match(SimpleViewParser::T__5);
        setState(248);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->read = nodeExp(0);
        setState(249);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::WRITE: {
        setState(251);
        match(SimpleViewParser::WRITE);
        setState(252);
        match(SimpleViewParser::T__5);
        setState(253);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->write = nodeExp(0);
        setState(254);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::ANY: {
        setState(256);
        match(SimpleViewParser::ANY);
        break;
      }

      case SimpleViewParser::REFERENCE: {
        setState(257);
        match(SimpleViewParser::REFERENCE);
        break;
      }

      case SimpleViewParser::CONDITION: {
        setState(258);
        match(SimpleViewParser::CONDITION);
        break;
      }

      case SimpleViewParser::STEP: {
        setState(259);
        match(SimpleViewParser::STEP);
        break;
      }

      case SimpleViewParser::T__5: {
        setState(260);
        match(SimpleViewParser::T__5);
        setState(261);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->bracket = nodeExp(0);
        setState(262);
        match(SimpleViewParser::T__6);
        break;
      }

      case SimpleViewParser::IDENTIFIER: {
        setState(264);
        antlrcpp::downCast<NodeExpContext *>(_localctx)->refOtherNode = match(SimpleViewParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(278);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(276);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(267);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(268);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->intersection = match(SimpleViewParser::T__8);
          setState(269);
          nodeExp(12);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(270);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(271);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->union_ = match(SimpleViewParser::T__7);
          setState(272);
          nodeExp(11);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<NodeExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNodeExp);
          setState(273);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(274);
          antlrcpp::downCast<NodeExpContext *>(_localctx)->difference = match(SimpleViewParser::T__9);
          setState(275);
          nodeExp(10);
          break;
        }

        default:
          break;
        } 
      }
      setState(280);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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
  enterRule(_localctx, 14, SimpleViewParser::RuleParamList);
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
    setState(281);
    match(SimpleViewParser::T__5);
    setState(282);
    match(SimpleViewParser::IDENTIFIER);
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__3) {
      setState(283);
      match(SimpleViewParser::T__3);
      setState(284);
      match(SimpleViewParser::IDENTIFIER);
      setState(289);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(290);
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
  enterRule(_localctx, 16, SimpleViewParser::RuleLineExp);
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
    lineSegOrNodeExp();
    setState(295); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(293);
      match(SimpleViewParser::T__10);
      setState(294);
      lineSegOrNodeExp();
      setState(297); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SimpleViewParser::T__10);
   
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

SimpleViewParser::StyleAttrListContext* SimpleViewParser::LineSegOrNodeExpContext::styleAttrList() {
  return getRuleContext<SimpleViewParser::StyleAttrListContext>(0);
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
  enterRule(_localctx, 18, SimpleViewParser::RuleLineSegOrNodeExp);
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
    setState(311);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(299);
      match(SimpleViewParser::T__2);
      setState(300);
      antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->segName = match(SimpleViewParser::IDENTIFIER);
      setState(301);
      match(SimpleViewParser::T__4);
      break;
    }

    case 2: {
      setState(302);
      nodeExp(0);
      setState(309);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SimpleViewParser::T__11) {
        setState(303);
        match(SimpleViewParser::T__11);
        setState(306);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SimpleViewParser::IDENTIFIER: {
            setState(304);
            antlrcpp::downCast<LineSegOrNodeExpContext *>(_localctx)->styleName = match(SimpleViewParser::IDENTIFIER);
            break;
          }

          case SimpleViewParser::NODE_COLOR:
          case SimpleViewParser::NODE_SCALE:
          case SimpleViewParser::LABEL_COLOR:
          case SimpleViewParser::LABEL_SCALE:
          case SimpleViewParser::LABEL_DETAIL_LEVEL:
          case SimpleViewParser::POSITION_Z: {
            setState(305);
            styleAttrList();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(308);
        match(SimpleViewParser::T__12);
      }
      break;
    }

    default:
      break;
    }
    setState(314);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0)) {
      setState(313);
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
  enterRule(_localctx, 20, SimpleViewParser::RuleLineArgumentList);
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
    match(SimpleViewParser::T__5);
    setState(317);
    match(SimpleViewParser::IDENTIFIER);
    setState(322);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__3) {
      setState(318);
      match(SimpleViewParser::T__3);
      setState(319);
      match(SimpleViewParser::IDENTIFIER);
      setState(324);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(325);
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
  enterRule(_localctx, 22, SimpleViewParser::RuleGraphElement);
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
    setState(327);
    antlrcpp::downCast<GraphElementContext *>(_localctx)->lineName = match(SimpleViewParser::IDENTIFIER);
    setState(329);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SimpleViewParser::T__5) {
      setState(328);
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
  enterRule(_localctx, 24, SimpleViewParser::RuleGraphBody);
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
    setState(331);
    graphElement();
    setState(336);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__3) {
      setState(332);
      match(SimpleViewParser::T__3);
      setState(333);
      graphElement();
      setState(338);
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
  enterRule(_localctx, 26, SimpleViewParser::RulePointInLine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(351);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(339);
        match(SimpleViewParser::T__2);
        setState(340);
        pointInLine();
        setState(345);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SimpleViewParser::T__3) {
          setState(341);
          match(SimpleViewParser::T__3);
          setState(342);
          pointInLine();
          setState(347);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(348);
        match(SimpleViewParser::T__4);
        break;
      }

      case SimpleViewParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(350);
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
  enterRule(_localctx, 28, SimpleViewParser::RuleIntersectionPoint);
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
    setState(353);
    match(SimpleViewParser::T__16);
    setState(354);
    pointInLine();
    setState(359);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SimpleViewParser::T__3) {
      setState(355);
      match(SimpleViewParser::T__3);
      setState(356);
      pointInLine();
      setState(361);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(362);
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
//----------------- DefaultStyleDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* SimpleViewParser::DefaultStyleDeclarationContext::DEFAULT_STYLE() {
  return getToken(SimpleViewParser::DEFAULT_STYLE, 0);
}

tree::TerminalNode* SimpleViewParser::DefaultStyleDeclarationContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

SimpleViewParser::StyleAttrListContext* SimpleViewParser::DefaultStyleDeclarationContext::styleAttrList() {
  return getRuleContext<SimpleViewParser::StyleAttrListContext>(0);
}

SimpleViewParser::DefaultStyleDeclarationContext::DefaultStyleDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::DefaultStyleDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitDefaultStyleDeclaration(this);
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
//----------------- StyleDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* SimpleViewParser::StyleDeclarationContext::STYLE() {
  return getToken(SimpleViewParser::STYLE, 0);
}

tree::TerminalNode* SimpleViewParser::StyleDeclarationContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

SimpleViewParser::StyleAttrListContext* SimpleViewParser::StyleDeclarationContext::styleAttrList() {
  return getRuleContext<SimpleViewParser::StyleAttrListContext>(0);
}

SimpleViewParser::StyleDeclarationContext::StyleDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::StyleDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitStyleDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BasicStyleDeclarationContext ------------------------------------------------------------------

tree::TerminalNode* SimpleViewParser::BasicStyleDeclarationContext::BASIC_STYLE() {
  return getToken(SimpleViewParser::BASIC_STYLE, 0);
}

tree::TerminalNode* SimpleViewParser::BasicStyleDeclarationContext::IDENTIFIER() {
  return getToken(SimpleViewParser::IDENTIFIER, 0);
}

std::vector<SimpleViewParser::BasicStyleAttrContext *> SimpleViewParser::BasicStyleDeclarationContext::basicStyleAttr() {
  return getRuleContexts<SimpleViewParser::BasicStyleAttrContext>();
}

SimpleViewParser::BasicStyleAttrContext* SimpleViewParser::BasicStyleDeclarationContext::basicStyleAttr(size_t i) {
  return getRuleContext<SimpleViewParser::BasicStyleAttrContext>(i);
}

SimpleViewParser::BasicStyleDeclarationContext::BasicStyleDeclarationContext(DeclarationContext *ctx) { copyFrom(ctx); }


std::any SimpleViewParser::BasicStyleDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SimpleViewVisitor*>(visitor))
    return parserVisitor->visitBasicStyleDeclaration(this);
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
  enterRule(_localctx, 30, SimpleViewParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(432);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SimpleViewParser::STYLE: {
        _localctx = _tracker.createInstance<SimpleViewParser::StyleDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(364);
        match(SimpleViewParser::STYLE);
        setState(365);
        match(SimpleViewParser::IDENTIFIER);
        setState(366);
        match(SimpleViewParser::T__18);
        setState(367);
        match(SimpleViewParser::T__11);
        setState(368);
        styleAttrList();
        setState(369);
        match(SimpleViewParser::T__12);
        break;
      }

      case SimpleViewParser::DEFAULT_STYLE: {
        _localctx = _tracker.createInstance<SimpleViewParser::DefaultStyleDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(371);
        match(SimpleViewParser::DEFAULT_STYLE);
        setState(372);
        match(SimpleViewParser::IDENTIFIER);
        setState(373);
        match(SimpleViewParser::T__18);
        setState(374);
        match(SimpleViewParser::T__11);
        setState(375);
        styleAttrList();
        setState(376);
        match(SimpleViewParser::T__12);
        break;
      }

      case SimpleViewParser::BASIC_STYLE: {
        _localctx = _tracker.createInstance<SimpleViewParser::BasicStyleDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(378);
        match(SimpleViewParser::BASIC_STYLE);
        setState(379);
        match(SimpleViewParser::IDENTIFIER);
        setState(380);
        match(SimpleViewParser::T__18);
        setState(381);
        match(SimpleViewParser::T__11);
        setState(383); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(382);
          basicStyleAttr();
          setState(385); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1879048192) != 0));
        setState(387);
        match(SimpleViewParser::T__12);
        break;
      }

      case SimpleViewParser::CLASS_SCOPE: {
        _localctx = _tracker.createInstance<SimpleViewParser::ClassScopeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(389);
        match(SimpleViewParser::CLASS_SCOPE);
        setState(390);
        match(SimpleViewParser::IDENTIFIER);
        setState(391);
        match(SimpleViewParser::T__18);
        setState(392);
        classScopeExp(0);
        break;
      }

      case SimpleViewParser::NODE: {
        _localctx = _tracker.createInstance<SimpleViewParser::NodeDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(393);
        match(SimpleViewParser::NODE);
        setState(394);
        match(SimpleViewParser::IDENTIFIER);
        setState(395);
        match(SimpleViewParser::T__18);
        setState(396);
        nodeExp(0);
        break;
      }

      case SimpleViewParser::SEGMENT:
      case SimpleViewParser::LINE:
      case SimpleViewParser::CODE_ORDER: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(397);
        _la = _input->LA(1);
        if (!(((((_la - 57) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 57)) & 2051) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(398);
        match(SimpleViewParser::IDENTIFIER);
        setState(400);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__5) {
          setState(399);
          paramList();
        }
        setState(402);
        match(SimpleViewParser::T__18);
        setState(403);
        lineExp();
        break;
      }

      case SimpleViewParser::GLUE: {
        _localctx = _tracker.createInstance<SimpleViewParser::GlueDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(404);
        match(SimpleViewParser::GLUE);
        setState(405);
        match(SimpleViewParser::IDENTIFIER);
        setState(406);
        match(SimpleViewParser::T__18);
        setState(407);
        match(SimpleViewParser::T__11);
        setState(411);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 61) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 61)) & 31) != 0)) {
          setState(408);
          glueAttr();
          setState(413);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(414);
        match(SimpleViewParser::T__12);
        break;
      }

      case SimpleViewParser::GRAPH: {
        _localctx = _tracker.createInstance<SimpleViewParser::GraphDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(415);
        match(SimpleViewParser::GRAPH);
        setState(416);
        antlrcpp::downCast<GraphDeclarationContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
        setState(418);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SimpleViewParser::T__5) {
          setState(417);
          paramList();
        }
        setState(420);
        match(SimpleViewParser::T__18);
        setState(421);
        graphBody();
        setState(423); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(422);
          intersectionPoint();
          setState(425); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SimpleViewParser::T__16);
        break;
      }

      case SimpleViewParser::LINE_INSTANCE:
      case SimpleViewParser::GRAPH_INSTANCE: {
        _localctx = _tracker.createInstance<SimpleViewParser::LineAndGraphInstanceContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(427);
        _la = _input->LA(1);
        if (!(_la == SimpleViewParser::LINE_INSTANCE

        || _la == SimpleViewParser::GRAPH_INSTANCE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(428);
        match(SimpleViewParser::IDENTIFIER);
        setState(429);
        match(SimpleViewParser::T__18);
        setState(430);
        match(SimpleViewParser::IDENTIFIER);
        setState(431);
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
  enterRule(_localctx, 32, SimpleViewParser::RuleShowCommand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    match(SimpleViewParser::SHOW);
    setState(435);
    match(SimpleViewParser::T__5);
    setState(436);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->graphName = match(SimpleViewParser::IDENTIFIER);
    setState(437);
    match(SimpleViewParser::T__3);
    setState(438);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->defaultStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(439);
    match(SimpleViewParser::T__3);
    setState(440);
    antlrcpp::downCast<ShowCommandContext *>(_localctx)->basicStyleName = match(SimpleViewParser::IDENTIFIER);
    setState(441);
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
    case 5: return classScopeExpSempred(antlrcpp::downCast<ClassScopeExpContext *>(context), predicateIndex);
    case 6: return nodeExpSempred(antlrcpp::downCast<NodeExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SimpleViewParser::classScopeExpSempred(ClassScopeExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool SimpleViewParser::nodeExpSempred(NodeExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);

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
