
// Generated from SimpleView.g4 by ANTLR 4.13.1


#include "SimpleViewLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct SimpleViewLexerStaticData final {
  SimpleViewLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SimpleViewLexerStaticData(const SimpleViewLexerStaticData&) = delete;
  SimpleViewLexerStaticData(SimpleViewLexerStaticData&&) = delete;
  SimpleViewLexerStaticData& operator=(const SimpleViewLexerStaticData&) = delete;
  SimpleViewLexerStaticData& operator=(SimpleViewLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag simpleviewlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
SimpleViewLexerStaticData *simpleviewlexerLexerStaticData = nullptr;

void simpleviewlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (simpleviewlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(simpleviewlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SimpleViewLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "LABEL_DETAIL_LEVEL_SIMPLE", "LABEL_DETAIL_LEVEL_FULL", 
      "NODE_COLOR", "NODE_SCALE", "LABEL_COLOR", "LABEL_SCALE", "LABEL_DETAIL_LEVEL", 
      "POSITION_Z", "BASIC_NODE_SIZE", "BASIC_LABEL_SIZE", "BASIC_POSITION_Z", 
      "ANY", "FINAL", "CLASS", "FIELD_OF", "INSTANCE_OF", "METHOD_OF", "CREATOR", 
      "PARAMETER_OF", "RETURN_OF", "CALLED_PARAM_OF", "CALLED_RETURN_OF", 
      "CALLED_METHOD_OF", "READ", "WRITE", "IN_PACKAGE", "USED_BY", "USE", 
      "CLASS_OF", "SUPER", "SUB", "STYLE", "DEFAULT_STYLE", "BASIC_STYLE", 
      "CLASS_SCOPE", "NODE", "REFERENCE", "CONDITION", "ELSE", "DATA_STEP", 
      "TIMING_STEP", "DATA_OVERRIDE", "TIMING_OVERRIDE", "FIELD", "METHOD", 
      "CONSTRUCTOR", "CALLED_METHOD", "PARAMETER", "CALLED_PARAMETER", "RETURN", 
      "CALLED_RETURN", "INDEX", "ERROR", "SEGMENT", "LINE", "LINE_INSTANCE", 
      "GLUE", "GLUE_RUNTIME", "GLULE_MEMBER_OF", "GLUE_INSTANCE_OF", "GLUE_OVERRIDE", 
      "GLUE_HIERARCHY", "GRAPH", "GRAPH_INSTANCE", "CODE_ORDER", "SHOW", 
      "STRING", "ESC", "UNICODE", "HEX", "IDENTIFIER", "LetterOrDigit", 
      "Letter", "SAFECODEPOINT", "FLOAT", "INT", "WS", "LINE_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "';'", "':'", "'['", "','", "']'", "'('", "')'", "'|'", "'&'", 
      "'-'", "'{'", "'}'", "'->'", "'||'", "'\\u003F'", "'*'", "'+'", "'<'", 
      "'>'", "'='", "'\"simple\"'", "'\"full\"'", "'nodeColor'", "'nodeScale'", 
      "'labelColor'", "'labelScale'", "'labelDetailLevel'", "'positionZ'", 
      "'basicNodeSize'", "'basicLabelSize'", "'basicPositionZ'", "'Any'", 
      "'Final'", "'Class'", "'FieldOf'", "'InstanceOf'", "'MethodOf'", "'CreatorOf'", 
      "'ParameterOf'", "'ReturnOf'", "'CalledParamOf'", "'CalledReturnOf'", 
      "'CalledMethodOf'", "'read'", "'write'", "'inPackage'", "'usedBy'", 
      "'use'", "'classOf'", "'superOf'", "'subOf'", "'Style'", "'DefaultStyle'", 
      "'BasicStyle'", "'ClassScope'", "'Node'", "'Reference'", "'Condition'", 
      "'Else'", "'DataStep'", "'TimingStep'", "'DataOverride'", "'TimingOverride'", 
      "'Field'", "'Method'", "'Constructor'", "'CalledMethod'", "'Parameter'", 
      "'CalledParameter'", "'Return'", "'CalledReturn'", "'Index'", "'Error'", 
      "'Seg'", "'Line'", "'LineInstance'", "'Glue'", "'GlueRuntime'", "'GlueMemberOf'", 
      "'GlueInstanceOf'", "'GlueOverride'", "'GlueHierarchy'", "'Graph'", 
      "'GraphInstance'", "'CodeOrder'", "'show'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "LABEL_DETAIL_LEVEL_SIMPLE", "LABEL_DETAIL_LEVEL_FULL", 
      "NODE_COLOR", "NODE_SCALE", "LABEL_COLOR", "LABEL_SCALE", "LABEL_DETAIL_LEVEL", 
      "POSITION_Z", "BASIC_NODE_SIZE", "BASIC_LABEL_SIZE", "BASIC_POSITION_Z", 
      "ANY", "FINAL", "CLASS", "FIELD_OF", "INSTANCE_OF", "METHOD_OF", "CREATOR", 
      "PARAMETER_OF", "RETURN_OF", "CALLED_PARAM_OF", "CALLED_RETURN_OF", 
      "CALLED_METHOD_OF", "READ", "WRITE", "IN_PACKAGE", "USED_BY", "USE", 
      "CLASS_OF", "SUPER", "SUB", "STYLE", "DEFAULT_STYLE", "BASIC_STYLE", 
      "CLASS_SCOPE", "NODE", "REFERENCE", "CONDITION", "ELSE", "DATA_STEP", 
      "TIMING_STEP", "DATA_OVERRIDE", "TIMING_OVERRIDE", "FIELD", "METHOD", 
      "CONSTRUCTOR", "CALLED_METHOD", "PARAMETER", "CALLED_PARAMETER", "RETURN", 
      "CALLED_RETURN", "INDEX", "ERROR", "SEGMENT", "LINE", "LINE_INSTANCE", 
      "GLUE", "GLUE_RUNTIME", "GLULE_MEMBER_OF", "GLUE_INSTANCE_OF", "GLUE_OVERRIDE", 
      "GLUE_HIERARCHY", "GRAPH", "GRAPH_INSTANCE", "CODE_ORDER", "SHOW", 
      "STRING", "IDENTIFIER", "FLOAT", "INT", "WS", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,92,966,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,70,
  	7,70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,2,75,7,75,2,76,7,76,2,77,
  	7,77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,2,83,7,83,2,84,
  	7,84,2,85,7,85,2,86,7,86,2,87,7,87,2,88,7,88,2,89,7,89,2,90,7,90,2,91,
  	7,91,2,92,7,92,2,93,7,93,2,94,7,94,2,95,7,95,2,96,7,96,2,97,7,97,1,0,
  	1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,
  	9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,15,
  	1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,30,1,30,1,30,
  	1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,31,1,31,
  	1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,
  	1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,35,
  	1,35,1,35,1,35,1,35,1,35,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,38,
  	1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,1,39,1,39,1,39,
  	1,39,1,39,1,39,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,
  	1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,
  	1,41,1,41,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,1,42,
  	1,42,1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,
  	1,44,1,44,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,46,1,46,
  	1,46,1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,47,1,48,1,48,1,48,1,48,1,48,
  	1,48,1,48,1,48,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,50,1,50,1,50,
  	1,50,1,50,1,50,1,51,1,51,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,
  	1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,53,1,53,1,53,1,53,1,53,1,53,
  	1,53,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,54,1,54,1,54,1,54,1,54,1,54,
  	1,54,1,54,1,55,1,55,1,55,1,55,1,55,1,56,1,56,1,56,1,56,1,56,1,56,1,56,
  	1,56,1,56,1,56,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,58,
  	1,58,1,58,1,58,1,58,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,60,
  	1,60,1,60,1,60,1,60,1,60,1,60,1,60,1,60,1,60,1,60,1,61,1,61,1,61,1,61,
  	1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,62,1,62,1,62,1,62,1,62,
  	1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,63,1,63,1,63,1,63,
  	1,63,1,63,1,64,1,64,1,64,1,64,1,64,1,64,1,64,1,65,1,65,1,65,1,65,1,65,
  	1,65,1,65,1,65,1,65,1,65,1,65,1,65,1,66,1,66,1,66,1,66,1,66,1,66,1,66,
  	1,66,1,66,1,66,1,66,1,66,1,66,1,67,1,67,1,67,1,67,1,67,1,67,1,67,1,67,
  	1,67,1,67,1,68,1,68,1,68,1,68,1,68,1,68,1,68,1,68,1,68,1,68,1,68,1,68,
  	1,68,1,68,1,68,1,68,1,69,1,69,1,69,1,69,1,69,1,69,1,69,1,70,1,70,1,70,
  	1,70,1,70,1,70,1,70,1,70,1,70,1,70,1,70,1,70,1,70,1,71,1,71,1,71,1,71,
  	1,71,1,71,1,72,1,72,1,72,1,72,1,72,1,72,1,73,1,73,1,73,1,73,1,74,1,74,
  	1,74,1,74,1,74,1,75,1,75,1,75,1,75,1,75,1,75,1,75,1,75,1,75,1,75,1,75,
  	1,75,1,75,1,76,1,76,1,76,1,76,1,76,1,77,1,77,1,77,1,77,1,77,1,77,1,77,
  	1,77,1,77,1,77,1,77,1,77,1,78,1,78,1,78,1,78,1,78,1,78,1,78,1,78,1,78,
  	1,78,1,78,1,78,1,78,1,79,1,79,1,79,1,79,1,79,1,79,1,79,1,79,1,79,1,79,
  	1,79,1,79,1,79,1,79,1,79,1,80,1,80,1,80,1,80,1,80,1,80,1,80,1,80,1,80,
  	1,80,1,80,1,80,1,80,1,81,1,81,1,81,1,81,1,81,1,81,1,81,1,81,1,81,1,81,
  	1,81,1,81,1,81,1,81,1,82,1,82,1,82,1,82,1,82,1,82,1,83,1,83,1,83,1,83,
  	1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,83,1,84,1,84,1,84,1,84,
  	1,84,1,84,1,84,1,84,1,84,1,84,1,85,1,85,1,85,1,85,1,85,1,86,1,86,1,86,
  	5,86,889,8,86,10,86,12,86,892,9,86,1,86,1,86,1,87,1,87,1,87,3,87,899,
  	8,87,1,88,1,88,1,88,1,88,1,88,1,88,1,89,1,89,1,90,1,90,5,90,911,8,90,
  	10,90,12,90,914,9,90,1,91,1,91,3,91,918,8,91,1,92,1,92,1,92,1,92,3,92,
  	924,8,92,1,93,1,93,1,94,4,94,929,8,94,11,94,12,94,930,1,94,1,94,4,94,
  	935,8,94,11,94,12,94,936,1,95,1,95,1,95,5,95,942,8,95,10,95,12,95,945,
  	9,95,3,95,947,8,95,1,96,4,96,950,8,96,11,96,12,96,951,1,96,1,96,1,97,
  	1,97,1,97,1,97,5,97,960,8,97,10,97,12,97,963,9,97,1,97,1,97,0,0,98,1,
  	1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,
  	15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,
  	53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,
  	38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,46,93,47,95,48,97,49,
  	99,50,101,51,103,52,105,53,107,54,109,55,111,56,113,57,115,58,117,59,
  	119,60,121,61,123,62,125,63,127,64,129,65,131,66,133,67,135,68,137,69,
  	139,70,141,71,143,72,145,73,147,74,149,75,151,76,153,77,155,78,157,79,
  	159,80,161,81,163,82,165,83,167,84,169,85,171,86,173,87,175,0,177,0,179,
  	0,181,88,183,0,185,0,187,0,189,89,191,90,193,91,195,92,1,0,11,8,0,34,
  	34,47,47,92,92,98,98,102,102,110,110,114,114,116,116,3,0,48,57,65,70,
  	97,102,1,0,48,57,4,0,36,36,65,90,95,95,97,122,2,0,0,127,55296,56319,1,
  	0,55296,56319,1,0,56320,57343,3,0,0,31,34,34,92,92,1,0,49,57,3,0,9,10,
  	13,13,32,32,2,0,10,10,13,13,972,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,
  	7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,
  	0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,
  	0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,
  	1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,
  	0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,
  	0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,
  	1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,
  	0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,
  	0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,
  	1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,0,113,
  	1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,0,123,
  	1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,0,131,1,0,0,0,0,133,
  	1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,0,141,1,0,0,0,0,143,
  	1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,149,1,0,0,0,0,151,1,0,0,0,0,153,
  	1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,159,1,0,0,0,0,161,1,0,0,0,0,163,
  	1,0,0,0,0,165,1,0,0,0,0,167,1,0,0,0,0,169,1,0,0,0,0,171,1,0,0,0,0,173,
  	1,0,0,0,0,181,1,0,0,0,0,189,1,0,0,0,0,191,1,0,0,0,0,193,1,0,0,0,0,195,
  	1,0,0,0,1,197,1,0,0,0,3,199,1,0,0,0,5,201,1,0,0,0,7,203,1,0,0,0,9,205,
  	1,0,0,0,11,207,1,0,0,0,13,209,1,0,0,0,15,211,1,0,0,0,17,213,1,0,0,0,19,
  	215,1,0,0,0,21,217,1,0,0,0,23,219,1,0,0,0,25,221,1,0,0,0,27,224,1,0,0,
  	0,29,227,1,0,0,0,31,229,1,0,0,0,33,231,1,0,0,0,35,233,1,0,0,0,37,235,
  	1,0,0,0,39,237,1,0,0,0,41,239,1,0,0,0,43,248,1,0,0,0,45,255,1,0,0,0,47,
  	265,1,0,0,0,49,275,1,0,0,0,51,286,1,0,0,0,53,297,1,0,0,0,55,314,1,0,0,
  	0,57,324,1,0,0,0,59,338,1,0,0,0,61,353,1,0,0,0,63,368,1,0,0,0,65,372,
  	1,0,0,0,67,378,1,0,0,0,69,384,1,0,0,0,71,392,1,0,0,0,73,403,1,0,0,0,75,
  	412,1,0,0,0,77,422,1,0,0,0,79,434,1,0,0,0,81,443,1,0,0,0,83,457,1,0,0,
  	0,85,472,1,0,0,0,87,487,1,0,0,0,89,492,1,0,0,0,91,498,1,0,0,0,93,508,
  	1,0,0,0,95,515,1,0,0,0,97,519,1,0,0,0,99,527,1,0,0,0,101,535,1,0,0,0,
  	103,541,1,0,0,0,105,547,1,0,0,0,107,560,1,0,0,0,109,571,1,0,0,0,111,582,
  	1,0,0,0,113,587,1,0,0,0,115,597,1,0,0,0,117,607,1,0,0,0,119,612,1,0,0,
  	0,121,621,1,0,0,0,123,632,1,0,0,0,125,645,1,0,0,0,127,660,1,0,0,0,129,
  	666,1,0,0,0,131,673,1,0,0,0,133,685,1,0,0,0,135,698,1,0,0,0,137,708,1,
  	0,0,0,139,724,1,0,0,0,141,731,1,0,0,0,143,744,1,0,0,0,145,750,1,0,0,0,
  	147,756,1,0,0,0,149,760,1,0,0,0,151,765,1,0,0,0,153,778,1,0,0,0,155,783,
  	1,0,0,0,157,795,1,0,0,0,159,808,1,0,0,0,161,823,1,0,0,0,163,836,1,0,0,
  	0,165,850,1,0,0,0,167,856,1,0,0,0,169,870,1,0,0,0,171,880,1,0,0,0,173,
  	885,1,0,0,0,175,895,1,0,0,0,177,900,1,0,0,0,179,906,1,0,0,0,181,908,1,
  	0,0,0,183,917,1,0,0,0,185,923,1,0,0,0,187,925,1,0,0,0,189,928,1,0,0,0,
  	191,946,1,0,0,0,193,949,1,0,0,0,195,955,1,0,0,0,197,198,5,59,0,0,198,
  	2,1,0,0,0,199,200,5,58,0,0,200,4,1,0,0,0,201,202,5,91,0,0,202,6,1,0,0,
  	0,203,204,5,44,0,0,204,8,1,0,0,0,205,206,5,93,0,0,206,10,1,0,0,0,207,
  	208,5,40,0,0,208,12,1,0,0,0,209,210,5,41,0,0,210,14,1,0,0,0,211,212,5,
  	124,0,0,212,16,1,0,0,0,213,214,5,38,0,0,214,18,1,0,0,0,215,216,5,45,0,
  	0,216,20,1,0,0,0,217,218,5,123,0,0,218,22,1,0,0,0,219,220,5,125,0,0,220,
  	24,1,0,0,0,221,222,5,45,0,0,222,223,5,62,0,0,223,26,1,0,0,0,224,225,5,
  	124,0,0,225,226,5,124,0,0,226,28,1,0,0,0,227,228,5,63,0,0,228,30,1,0,
  	0,0,229,230,5,42,0,0,230,32,1,0,0,0,231,232,5,43,0,0,232,34,1,0,0,0,233,
  	234,5,60,0,0,234,36,1,0,0,0,235,236,5,62,0,0,236,38,1,0,0,0,237,238,5,
  	61,0,0,238,40,1,0,0,0,239,240,5,34,0,0,240,241,5,115,0,0,241,242,5,105,
  	0,0,242,243,5,109,0,0,243,244,5,112,0,0,244,245,5,108,0,0,245,246,5,101,
  	0,0,246,247,5,34,0,0,247,42,1,0,0,0,248,249,5,34,0,0,249,250,5,102,0,
  	0,250,251,5,117,0,0,251,252,5,108,0,0,252,253,5,108,0,0,253,254,5,34,
  	0,0,254,44,1,0,0,0,255,256,5,110,0,0,256,257,5,111,0,0,257,258,5,100,
  	0,0,258,259,5,101,0,0,259,260,5,67,0,0,260,261,5,111,0,0,261,262,5,108,
  	0,0,262,263,5,111,0,0,263,264,5,114,0,0,264,46,1,0,0,0,265,266,5,110,
  	0,0,266,267,5,111,0,0,267,268,5,100,0,0,268,269,5,101,0,0,269,270,5,83,
  	0,0,270,271,5,99,0,0,271,272,5,97,0,0,272,273,5,108,0,0,273,274,5,101,
  	0,0,274,48,1,0,0,0,275,276,5,108,0,0,276,277,5,97,0,0,277,278,5,98,0,
  	0,278,279,5,101,0,0,279,280,5,108,0,0,280,281,5,67,0,0,281,282,5,111,
  	0,0,282,283,5,108,0,0,283,284,5,111,0,0,284,285,5,114,0,0,285,50,1,0,
  	0,0,286,287,5,108,0,0,287,288,5,97,0,0,288,289,5,98,0,0,289,290,5,101,
  	0,0,290,291,5,108,0,0,291,292,5,83,0,0,292,293,5,99,0,0,293,294,5,97,
  	0,0,294,295,5,108,0,0,295,296,5,101,0,0,296,52,1,0,0,0,297,298,5,108,
  	0,0,298,299,5,97,0,0,299,300,5,98,0,0,300,301,5,101,0,0,301,302,5,108,
  	0,0,302,303,5,68,0,0,303,304,5,101,0,0,304,305,5,116,0,0,305,306,5,97,
  	0,0,306,307,5,105,0,0,307,308,5,108,0,0,308,309,5,76,0,0,309,310,5,101,
  	0,0,310,311,5,118,0,0,311,312,5,101,0,0,312,313,5,108,0,0,313,54,1,0,
  	0,0,314,315,5,112,0,0,315,316,5,111,0,0,316,317,5,115,0,0,317,318,5,105,
  	0,0,318,319,5,116,0,0,319,320,5,105,0,0,320,321,5,111,0,0,321,322,5,110,
  	0,0,322,323,5,90,0,0,323,56,1,0,0,0,324,325,5,98,0,0,325,326,5,97,0,0,
  	326,327,5,115,0,0,327,328,5,105,0,0,328,329,5,99,0,0,329,330,5,78,0,0,
  	330,331,5,111,0,0,331,332,5,100,0,0,332,333,5,101,0,0,333,334,5,83,0,
  	0,334,335,5,105,0,0,335,336,5,122,0,0,336,337,5,101,0,0,337,58,1,0,0,
  	0,338,339,5,98,0,0,339,340,5,97,0,0,340,341,5,115,0,0,341,342,5,105,0,
  	0,342,343,5,99,0,0,343,344,5,76,0,0,344,345,5,97,0,0,345,346,5,98,0,0,
  	346,347,5,101,0,0,347,348,5,108,0,0,348,349,5,83,0,0,349,350,5,105,0,
  	0,350,351,5,122,0,0,351,352,5,101,0,0,352,60,1,0,0,0,353,354,5,98,0,0,
  	354,355,5,97,0,0,355,356,5,115,0,0,356,357,5,105,0,0,357,358,5,99,0,0,
  	358,359,5,80,0,0,359,360,5,111,0,0,360,361,5,115,0,0,361,362,5,105,0,
  	0,362,363,5,116,0,0,363,364,5,105,0,0,364,365,5,111,0,0,365,366,5,110,
  	0,0,366,367,5,90,0,0,367,62,1,0,0,0,368,369,5,65,0,0,369,370,5,110,0,
  	0,370,371,5,121,0,0,371,64,1,0,0,0,372,373,5,70,0,0,373,374,5,105,0,0,
  	374,375,5,110,0,0,375,376,5,97,0,0,376,377,5,108,0,0,377,66,1,0,0,0,378,
  	379,5,67,0,0,379,380,5,108,0,0,380,381,5,97,0,0,381,382,5,115,0,0,382,
  	383,5,115,0,0,383,68,1,0,0,0,384,385,5,70,0,0,385,386,5,105,0,0,386,387,
  	5,101,0,0,387,388,5,108,0,0,388,389,5,100,0,0,389,390,5,79,0,0,390,391,
  	5,102,0,0,391,70,1,0,0,0,392,393,5,73,0,0,393,394,5,110,0,0,394,395,5,
  	115,0,0,395,396,5,116,0,0,396,397,5,97,0,0,397,398,5,110,0,0,398,399,
  	5,99,0,0,399,400,5,101,0,0,400,401,5,79,0,0,401,402,5,102,0,0,402,72,
  	1,0,0,0,403,404,5,77,0,0,404,405,5,101,0,0,405,406,5,116,0,0,406,407,
  	5,104,0,0,407,408,5,111,0,0,408,409,5,100,0,0,409,410,5,79,0,0,410,411,
  	5,102,0,0,411,74,1,0,0,0,412,413,5,67,0,0,413,414,5,114,0,0,414,415,5,
  	101,0,0,415,416,5,97,0,0,416,417,5,116,0,0,417,418,5,111,0,0,418,419,
  	5,114,0,0,419,420,5,79,0,0,420,421,5,102,0,0,421,76,1,0,0,0,422,423,5,
  	80,0,0,423,424,5,97,0,0,424,425,5,114,0,0,425,426,5,97,0,0,426,427,5,
  	109,0,0,427,428,5,101,0,0,428,429,5,116,0,0,429,430,5,101,0,0,430,431,
  	5,114,0,0,431,432,5,79,0,0,432,433,5,102,0,0,433,78,1,0,0,0,434,435,5,
  	82,0,0,435,436,5,101,0,0,436,437,5,116,0,0,437,438,5,117,0,0,438,439,
  	5,114,0,0,439,440,5,110,0,0,440,441,5,79,0,0,441,442,5,102,0,0,442,80,
  	1,0,0,0,443,444,5,67,0,0,444,445,5,97,0,0,445,446,5,108,0,0,446,447,5,
  	108,0,0,447,448,5,101,0,0,448,449,5,100,0,0,449,450,5,80,0,0,450,451,
  	5,97,0,0,451,452,5,114,0,0,452,453,5,97,0,0,453,454,5,109,0,0,454,455,
  	5,79,0,0,455,456,5,102,0,0,456,82,1,0,0,0,457,458,5,67,0,0,458,459,5,
  	97,0,0,459,460,5,108,0,0,460,461,5,108,0,0,461,462,5,101,0,0,462,463,
  	5,100,0,0,463,464,5,82,0,0,464,465,5,101,0,0,465,466,5,116,0,0,466,467,
  	5,117,0,0,467,468,5,114,0,0,468,469,5,110,0,0,469,470,5,79,0,0,470,471,
  	5,102,0,0,471,84,1,0,0,0,472,473,5,67,0,0,473,474,5,97,0,0,474,475,5,
  	108,0,0,475,476,5,108,0,0,476,477,5,101,0,0,477,478,5,100,0,0,478,479,
  	5,77,0,0,479,480,5,101,0,0,480,481,5,116,0,0,481,482,5,104,0,0,482,483,
  	5,111,0,0,483,484,5,100,0,0,484,485,5,79,0,0,485,486,5,102,0,0,486,86,
  	1,0,0,0,487,488,5,114,0,0,488,489,5,101,0,0,489,490,5,97,0,0,490,491,
  	5,100,0,0,491,88,1,0,0,0,492,493,5,119,0,0,493,494,5,114,0,0,494,495,
  	5,105,0,0,495,496,5,116,0,0,496,497,5,101,0,0,497,90,1,0,0,0,498,499,
  	5,105,0,0,499,500,5,110,0,0,500,501,5,80,0,0,501,502,5,97,0,0,502,503,
  	5,99,0,0,503,504,5,107,0,0,504,505,5,97,0,0,505,506,5,103,0,0,506,507,
  	5,101,0,0,507,92,1,0,0,0,508,509,5,117,0,0,509,510,5,115,0,0,510,511,
  	5,101,0,0,511,512,5,100,0,0,512,513,5,66,0,0,513,514,5,121,0,0,514,94,
  	1,0,0,0,515,516,5,117,0,0,516,517,5,115,0,0,517,518,5,101,0,0,518,96,
  	1,0,0,0,519,520,5,99,0,0,520,521,5,108,0,0,521,522,5,97,0,0,522,523,5,
  	115,0,0,523,524,5,115,0,0,524,525,5,79,0,0,525,526,5,102,0,0,526,98,1,
  	0,0,0,527,528,5,115,0,0,528,529,5,117,0,0,529,530,5,112,0,0,530,531,5,
  	101,0,0,531,532,5,114,0,0,532,533,5,79,0,0,533,534,5,102,0,0,534,100,
  	1,0,0,0,535,536,5,115,0,0,536,537,5,117,0,0,537,538,5,98,0,0,538,539,
  	5,79,0,0,539,540,5,102,0,0,540,102,1,0,0,0,541,542,5,83,0,0,542,543,5,
  	116,0,0,543,544,5,121,0,0,544,545,5,108,0,0,545,546,5,101,0,0,546,104,
  	1,0,0,0,547,548,5,68,0,0,548,549,5,101,0,0,549,550,5,102,0,0,550,551,
  	5,97,0,0,551,552,5,117,0,0,552,553,5,108,0,0,553,554,5,116,0,0,554,555,
  	5,83,0,0,555,556,5,116,0,0,556,557,5,121,0,0,557,558,5,108,0,0,558,559,
  	5,101,0,0,559,106,1,0,0,0,560,561,5,66,0,0,561,562,5,97,0,0,562,563,5,
  	115,0,0,563,564,5,105,0,0,564,565,5,99,0,0,565,566,5,83,0,0,566,567,5,
  	116,0,0,567,568,5,121,0,0,568,569,5,108,0,0,569,570,5,101,0,0,570,108,
  	1,0,0,0,571,572,5,67,0,0,572,573,5,108,0,0,573,574,5,97,0,0,574,575,5,
  	115,0,0,575,576,5,115,0,0,576,577,5,83,0,0,577,578,5,99,0,0,578,579,5,
  	111,0,0,579,580,5,112,0,0,580,581,5,101,0,0,581,110,1,0,0,0,582,583,5,
  	78,0,0,583,584,5,111,0,0,584,585,5,100,0,0,585,586,5,101,0,0,586,112,
  	1,0,0,0,587,588,5,82,0,0,588,589,5,101,0,0,589,590,5,102,0,0,590,591,
  	5,101,0,0,591,592,5,114,0,0,592,593,5,101,0,0,593,594,5,110,0,0,594,595,
  	5,99,0,0,595,596,5,101,0,0,596,114,1,0,0,0,597,598,5,67,0,0,598,599,5,
  	111,0,0,599,600,5,110,0,0,600,601,5,100,0,0,601,602,5,105,0,0,602,603,
  	5,116,0,0,603,604,5,105,0,0,604,605,5,111,0,0,605,606,5,110,0,0,606,116,
  	1,0,0,0,607,608,5,69,0,0,608,609,5,108,0,0,609,610,5,115,0,0,610,611,
  	5,101,0,0,611,118,1,0,0,0,612,613,5,68,0,0,613,614,5,97,0,0,614,615,5,
  	116,0,0,615,616,5,97,0,0,616,617,5,83,0,0,617,618,5,116,0,0,618,619,5,
  	101,0,0,619,620,5,112,0,0,620,120,1,0,0,0,621,622,5,84,0,0,622,623,5,
  	105,0,0,623,624,5,109,0,0,624,625,5,105,0,0,625,626,5,110,0,0,626,627,
  	5,103,0,0,627,628,5,83,0,0,628,629,5,116,0,0,629,630,5,101,0,0,630,631,
  	5,112,0,0,631,122,1,0,0,0,632,633,5,68,0,0,633,634,5,97,0,0,634,635,5,
  	116,0,0,635,636,5,97,0,0,636,637,5,79,0,0,637,638,5,118,0,0,638,639,5,
  	101,0,0,639,640,5,114,0,0,640,641,5,114,0,0,641,642,5,105,0,0,642,643,
  	5,100,0,0,643,644,5,101,0,0,644,124,1,0,0,0,645,646,5,84,0,0,646,647,
  	5,105,0,0,647,648,5,109,0,0,648,649,5,105,0,0,649,650,5,110,0,0,650,651,
  	5,103,0,0,651,652,5,79,0,0,652,653,5,118,0,0,653,654,5,101,0,0,654,655,
  	5,114,0,0,655,656,5,114,0,0,656,657,5,105,0,0,657,658,5,100,0,0,658,659,
  	5,101,0,0,659,126,1,0,0,0,660,661,5,70,0,0,661,662,5,105,0,0,662,663,
  	5,101,0,0,663,664,5,108,0,0,664,665,5,100,0,0,665,128,1,0,0,0,666,667,
  	5,77,0,0,667,668,5,101,0,0,668,669,5,116,0,0,669,670,5,104,0,0,670,671,
  	5,111,0,0,671,672,5,100,0,0,672,130,1,0,0,0,673,674,5,67,0,0,674,675,
  	5,111,0,0,675,676,5,110,0,0,676,677,5,115,0,0,677,678,5,116,0,0,678,679,
  	5,114,0,0,679,680,5,117,0,0,680,681,5,99,0,0,681,682,5,116,0,0,682,683,
  	5,111,0,0,683,684,5,114,0,0,684,132,1,0,0,0,685,686,5,67,0,0,686,687,
  	5,97,0,0,687,688,5,108,0,0,688,689,5,108,0,0,689,690,5,101,0,0,690,691,
  	5,100,0,0,691,692,5,77,0,0,692,693,5,101,0,0,693,694,5,116,0,0,694,695,
  	5,104,0,0,695,696,5,111,0,0,696,697,5,100,0,0,697,134,1,0,0,0,698,699,
  	5,80,0,0,699,700,5,97,0,0,700,701,5,114,0,0,701,702,5,97,0,0,702,703,
  	5,109,0,0,703,704,5,101,0,0,704,705,5,116,0,0,705,706,5,101,0,0,706,707,
  	5,114,0,0,707,136,1,0,0,0,708,709,5,67,0,0,709,710,5,97,0,0,710,711,5,
  	108,0,0,711,712,5,108,0,0,712,713,5,101,0,0,713,714,5,100,0,0,714,715,
  	5,80,0,0,715,716,5,97,0,0,716,717,5,114,0,0,717,718,5,97,0,0,718,719,
  	5,109,0,0,719,720,5,101,0,0,720,721,5,116,0,0,721,722,5,101,0,0,722,723,
  	5,114,0,0,723,138,1,0,0,0,724,725,5,82,0,0,725,726,5,101,0,0,726,727,
  	5,116,0,0,727,728,5,117,0,0,728,729,5,114,0,0,729,730,5,110,0,0,730,140,
  	1,0,0,0,731,732,5,67,0,0,732,733,5,97,0,0,733,734,5,108,0,0,734,735,5,
  	108,0,0,735,736,5,101,0,0,736,737,5,100,0,0,737,738,5,82,0,0,738,739,
  	5,101,0,0,739,740,5,116,0,0,740,741,5,117,0,0,741,742,5,114,0,0,742,743,
  	5,110,0,0,743,142,1,0,0,0,744,745,5,73,0,0,745,746,5,110,0,0,746,747,
  	5,100,0,0,747,748,5,101,0,0,748,749,5,120,0,0,749,144,1,0,0,0,750,751,
  	5,69,0,0,751,752,5,114,0,0,752,753,5,114,0,0,753,754,5,111,0,0,754,755,
  	5,114,0,0,755,146,1,0,0,0,756,757,5,83,0,0,757,758,5,101,0,0,758,759,
  	5,103,0,0,759,148,1,0,0,0,760,761,5,76,0,0,761,762,5,105,0,0,762,763,
  	5,110,0,0,763,764,5,101,0,0,764,150,1,0,0,0,765,766,5,76,0,0,766,767,
  	5,105,0,0,767,768,5,110,0,0,768,769,5,101,0,0,769,770,5,73,0,0,770,771,
  	5,110,0,0,771,772,5,115,0,0,772,773,5,116,0,0,773,774,5,97,0,0,774,775,
  	5,110,0,0,775,776,5,99,0,0,776,777,5,101,0,0,777,152,1,0,0,0,778,779,
  	5,71,0,0,779,780,5,108,0,0,780,781,5,117,0,0,781,782,5,101,0,0,782,154,
  	1,0,0,0,783,784,5,71,0,0,784,785,5,108,0,0,785,786,5,117,0,0,786,787,
  	5,101,0,0,787,788,5,82,0,0,788,789,5,117,0,0,789,790,5,110,0,0,790,791,
  	5,116,0,0,791,792,5,105,0,0,792,793,5,109,0,0,793,794,5,101,0,0,794,156,
  	1,0,0,0,795,796,5,71,0,0,796,797,5,108,0,0,797,798,5,117,0,0,798,799,
  	5,101,0,0,799,800,5,77,0,0,800,801,5,101,0,0,801,802,5,109,0,0,802,803,
  	5,98,0,0,803,804,5,101,0,0,804,805,5,114,0,0,805,806,5,79,0,0,806,807,
  	5,102,0,0,807,158,1,0,0,0,808,809,5,71,0,0,809,810,5,108,0,0,810,811,
  	5,117,0,0,811,812,5,101,0,0,812,813,5,73,0,0,813,814,5,110,0,0,814,815,
  	5,115,0,0,815,816,5,116,0,0,816,817,5,97,0,0,817,818,5,110,0,0,818,819,
  	5,99,0,0,819,820,5,101,0,0,820,821,5,79,0,0,821,822,5,102,0,0,822,160,
  	1,0,0,0,823,824,5,71,0,0,824,825,5,108,0,0,825,826,5,117,0,0,826,827,
  	5,101,0,0,827,828,5,79,0,0,828,829,5,118,0,0,829,830,5,101,0,0,830,831,
  	5,114,0,0,831,832,5,114,0,0,832,833,5,105,0,0,833,834,5,100,0,0,834,835,
  	5,101,0,0,835,162,1,0,0,0,836,837,5,71,0,0,837,838,5,108,0,0,838,839,
  	5,117,0,0,839,840,5,101,0,0,840,841,5,72,0,0,841,842,5,105,0,0,842,843,
  	5,101,0,0,843,844,5,114,0,0,844,845,5,97,0,0,845,846,5,114,0,0,846,847,
  	5,99,0,0,847,848,5,104,0,0,848,849,5,121,0,0,849,164,1,0,0,0,850,851,
  	5,71,0,0,851,852,5,114,0,0,852,853,5,97,0,0,853,854,5,112,0,0,854,855,
  	5,104,0,0,855,166,1,0,0,0,856,857,5,71,0,0,857,858,5,114,0,0,858,859,
  	5,97,0,0,859,860,5,112,0,0,860,861,5,104,0,0,861,862,5,73,0,0,862,863,
  	5,110,0,0,863,864,5,115,0,0,864,865,5,116,0,0,865,866,5,97,0,0,866,867,
  	5,110,0,0,867,868,5,99,0,0,868,869,5,101,0,0,869,168,1,0,0,0,870,871,
  	5,67,0,0,871,872,5,111,0,0,872,873,5,100,0,0,873,874,5,101,0,0,874,875,
  	5,79,0,0,875,876,5,114,0,0,876,877,5,100,0,0,877,878,5,101,0,0,878,879,
  	5,114,0,0,879,170,1,0,0,0,880,881,5,115,0,0,881,882,5,104,0,0,882,883,
  	5,111,0,0,883,884,5,119,0,0,884,172,1,0,0,0,885,890,5,34,0,0,886,889,
  	3,175,87,0,887,889,3,187,93,0,888,886,1,0,0,0,888,887,1,0,0,0,889,892,
  	1,0,0,0,890,888,1,0,0,0,890,891,1,0,0,0,891,893,1,0,0,0,892,890,1,0,0,
  	0,893,894,5,34,0,0,894,174,1,0,0,0,895,898,5,92,0,0,896,899,7,0,0,0,897,
  	899,3,177,88,0,898,896,1,0,0,0,898,897,1,0,0,0,899,176,1,0,0,0,900,901,
  	5,117,0,0,901,902,3,179,89,0,902,903,3,179,89,0,903,904,3,179,89,0,904,
  	905,3,179,89,0,905,178,1,0,0,0,906,907,7,1,0,0,907,180,1,0,0,0,908,912,
  	3,185,92,0,909,911,3,183,91,0,910,909,1,0,0,0,911,914,1,0,0,0,912,910,
  	1,0,0,0,912,913,1,0,0,0,913,182,1,0,0,0,914,912,1,0,0,0,915,918,3,185,
  	92,0,916,918,7,2,0,0,917,915,1,0,0,0,917,916,1,0,0,0,918,184,1,0,0,0,
  	919,924,7,3,0,0,920,924,8,4,0,0,921,922,7,5,0,0,922,924,7,6,0,0,923,919,
  	1,0,0,0,923,920,1,0,0,0,923,921,1,0,0,0,924,186,1,0,0,0,925,926,8,7,0,
  	0,926,188,1,0,0,0,927,929,7,2,0,0,928,927,1,0,0,0,929,930,1,0,0,0,930,
  	928,1,0,0,0,930,931,1,0,0,0,931,932,1,0,0,0,932,934,5,46,0,0,933,935,
  	7,2,0,0,934,933,1,0,0,0,935,936,1,0,0,0,936,934,1,0,0,0,936,937,1,0,0,
  	0,937,190,1,0,0,0,938,947,5,48,0,0,939,943,7,8,0,0,940,942,7,2,0,0,941,
  	940,1,0,0,0,942,945,1,0,0,0,943,941,1,0,0,0,943,944,1,0,0,0,944,947,1,
  	0,0,0,945,943,1,0,0,0,946,938,1,0,0,0,946,939,1,0,0,0,947,192,1,0,0,0,
  	948,950,7,9,0,0,949,948,1,0,0,0,950,951,1,0,0,0,951,949,1,0,0,0,951,952,
  	1,0,0,0,952,953,1,0,0,0,953,954,6,96,0,0,954,194,1,0,0,0,955,956,5,47,
  	0,0,956,957,5,47,0,0,957,961,1,0,0,0,958,960,8,10,0,0,959,958,1,0,0,0,
  	960,963,1,0,0,0,961,959,1,0,0,0,961,962,1,0,0,0,962,964,1,0,0,0,963,961,
  	1,0,0,0,964,965,6,97,0,0,965,196,1,0,0,0,13,0,888,890,898,912,917,923,
  	930,936,943,946,951,961,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  simpleviewlexerLexerStaticData = staticData.release();
}

}

SimpleViewLexer::SimpleViewLexer(CharStream *input) : Lexer(input) {
  SimpleViewLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *simpleviewlexerLexerStaticData->atn, simpleviewlexerLexerStaticData->decisionToDFA, simpleviewlexerLexerStaticData->sharedContextCache);
}

SimpleViewLexer::~SimpleViewLexer() {
  delete _interpreter;
}

std::string SimpleViewLexer::getGrammarFileName() const {
  return "SimpleView.g4";
}

const std::vector<std::string>& SimpleViewLexer::getRuleNames() const {
  return simpleviewlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& SimpleViewLexer::getChannelNames() const {
  return simpleviewlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& SimpleViewLexer::getModeNames() const {
  return simpleviewlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& SimpleViewLexer::getVocabulary() const {
  return simpleviewlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SimpleViewLexer::getSerializedATN() const {
  return simpleviewlexerLexerStaticData->serializedATN;
}

const atn::ATN& SimpleViewLexer::getATN() const {
  return *simpleviewlexerLexerStaticData->atn;
}




void SimpleViewLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  simpleviewlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(simpleviewlexerLexerOnceFlag, simpleviewlexerLexerInitialize);
#endif
}
