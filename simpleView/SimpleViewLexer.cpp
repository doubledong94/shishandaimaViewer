
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
      "T__17", "T__18", "LABEL_DETAIL_LEVEL_SIMPLE", "LABEL_DETAIL_LEVEL_FULL", 
      "NODE_COLOR", "NODE_SCALE", "LABEL_COLOR", "LABEL_SCALE", "LABEL_DETAIL_LEVEL", 
      "POSITION_Z", "BASIC_NODE_SIZE", "BASIC_LABEL_SIZE", "BASIC_POSITION_Z", 
      "ANY", "FIELD_OF", "INSTANCE_OF", "METHOD_OF", "CREATOR", "PARAMETER_OF", 
      "RETURN_OF", "CALLED_PARAM_OF", "CALLED_RETURN_OF", "CALLED_METHOD_OF", 
      "READ", "WRITE", "IN_PACKAGE", "USED_BY", "USE", "CLASS_OF", "SUPER", 
      "SUB", "STYLE", "DEFAULT_STYLE", "BASIC_STYLE", "CLASS_SCOPE", "NODE", 
      "REFERENCE", "CONDITION", "STEP", "SEGMENT", "LINE", "LINE_INSTANCE", 
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
  	4,0,75,773,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
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
  	7,77,2,78,7,78,2,79,7,79,2,80,7,80,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,10,1,11,1,11,
  	1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,
  	1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,
  	1,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,31,1,31,
  	1,31,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,33,1,33,
  	1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,
  	1,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,
  	1,35,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,38,1,38,1,38,1,38,
  	1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,
  	1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,40,1,40,
  	1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,41,1,42,1,42,1,42,1,42,1,42,
  	1,42,1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,44,1,44,
  	1,44,1,44,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,46,1,46,1,46,1,46,
  	1,46,1,46,1,46,1,46,1,47,1,47,1,47,1,47,1,47,1,47,1,48,1,48,1,48,1,48,
  	1,48,1,48,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,
  	1,49,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,51,1,51,
  	1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,
  	1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,54,
  	1,54,1,54,1,54,1,54,1,54,1,54,1,55,1,55,1,55,1,55,1,55,1,56,1,56,1,56,
  	1,56,1,57,1,57,1,57,1,57,1,57,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,
  	1,58,1,58,1,58,1,58,1,58,1,59,1,59,1,59,1,59,1,59,1,60,1,60,1,60,1,60,
  	1,60,1,60,1,60,1,60,1,60,1,60,1,60,1,60,1,61,1,61,1,61,1,61,1,61,1,61,
  	1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,62,1,62,1,62,1,62,1,62,1,62,1,62,
  	1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,63,1,63,1,63,1,63,1,63,1,63,
  	1,63,1,63,1,63,1,63,1,63,1,63,1,63,1,64,1,64,1,64,1,64,1,64,1,64,1,64,
  	1,64,1,64,1,64,1,64,1,64,1,64,1,64,1,65,1,65,1,65,1,65,1,65,1,65,1,66,
  	1,66,1,66,1,66,1,66,1,66,1,66,1,66,1,66,1,66,1,66,1,66,1,66,1,66,1,67,
  	1,67,1,67,1,67,1,67,1,67,1,67,1,67,1,67,1,67,1,68,1,68,1,68,1,68,1,68,
  	1,69,1,69,1,69,5,69,696,8,69,10,69,12,69,699,9,69,1,69,1,69,1,70,1,70,
  	1,70,3,70,706,8,70,1,71,1,71,1,71,1,71,1,71,1,71,1,72,1,72,1,73,1,73,
  	5,73,718,8,73,10,73,12,73,721,9,73,1,74,1,74,3,74,725,8,74,1,75,1,75,
  	1,75,1,75,3,75,731,8,75,1,76,1,76,1,77,4,77,736,8,77,11,77,12,77,737,
  	1,77,1,77,4,77,742,8,77,11,77,12,77,743,1,78,1,78,1,78,5,78,749,8,78,
  	10,78,12,78,752,9,78,3,78,754,8,78,1,79,4,79,757,8,79,11,79,12,79,758,
  	1,79,1,79,1,80,1,80,1,80,1,80,5,80,767,8,80,10,80,12,80,770,9,80,1,80,
  	1,80,0,0,81,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,
  	25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,
  	24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,
  	71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,46,93,
  	47,95,48,97,49,99,50,101,51,103,52,105,53,107,54,109,55,111,56,113,57,
  	115,58,117,59,119,60,121,61,123,62,125,63,127,64,129,65,131,66,133,67,
  	135,68,137,69,139,70,141,0,143,0,145,0,147,71,149,0,151,0,153,0,155,72,
  	157,73,159,74,161,75,1,0,11,8,0,34,34,47,47,92,92,98,98,102,102,110,110,
  	114,114,116,116,3,0,48,57,65,70,97,102,1,0,48,57,4,0,36,36,65,90,95,95,
  	97,122,2,0,0,127,55296,56319,1,0,55296,56319,1,0,56320,57343,3,0,0,31,
  	34,34,92,92,1,0,49,57,3,0,9,10,13,13,32,32,2,0,10,10,13,13,779,0,1,1,
  	0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,
  	13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,
  	0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,
  	0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,
  	45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,
  	0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,
  	0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,
  	77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,
  	0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,
  	0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,
  	0,0,109,1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,
  	0,0,119,1,0,0,0,0,121,1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,
  	0,0,129,1,0,0,0,0,131,1,0,0,0,0,133,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,
  	0,0,139,1,0,0,0,0,147,1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,159,1,0,0,
  	0,0,161,1,0,0,0,1,163,1,0,0,0,3,165,1,0,0,0,5,167,1,0,0,0,7,169,1,0,0,
  	0,9,171,1,0,0,0,11,173,1,0,0,0,13,175,1,0,0,0,15,177,1,0,0,0,17,179,1,
  	0,0,0,19,181,1,0,0,0,21,183,1,0,0,0,23,186,1,0,0,0,25,188,1,0,0,0,27,
  	190,1,0,0,0,29,192,1,0,0,0,31,194,1,0,0,0,33,196,1,0,0,0,35,198,1,0,0,
  	0,37,200,1,0,0,0,39,202,1,0,0,0,41,211,1,0,0,0,43,218,1,0,0,0,45,228,
  	1,0,0,0,47,238,1,0,0,0,49,249,1,0,0,0,51,260,1,0,0,0,53,277,1,0,0,0,55,
  	287,1,0,0,0,57,301,1,0,0,0,59,316,1,0,0,0,61,331,1,0,0,0,63,335,1,0,0,
  	0,65,343,1,0,0,0,67,354,1,0,0,0,69,363,1,0,0,0,71,373,1,0,0,0,73,385,
  	1,0,0,0,75,394,1,0,0,0,77,408,1,0,0,0,79,423,1,0,0,0,81,438,1,0,0,0,83,
  	443,1,0,0,0,85,449,1,0,0,0,87,459,1,0,0,0,89,466,1,0,0,0,91,470,1,0,0,
  	0,93,478,1,0,0,0,95,486,1,0,0,0,97,492,1,0,0,0,99,498,1,0,0,0,101,511,
  	1,0,0,0,103,522,1,0,0,0,105,533,1,0,0,0,107,538,1,0,0,0,109,548,1,0,0,
  	0,111,558,1,0,0,0,113,563,1,0,0,0,115,567,1,0,0,0,117,572,1,0,0,0,119,
  	585,1,0,0,0,121,590,1,0,0,0,123,602,1,0,0,0,125,615,1,0,0,0,127,630,1,
  	0,0,0,129,643,1,0,0,0,131,657,1,0,0,0,133,663,1,0,0,0,135,677,1,0,0,0,
  	137,687,1,0,0,0,139,692,1,0,0,0,141,702,1,0,0,0,143,707,1,0,0,0,145,713,
  	1,0,0,0,147,715,1,0,0,0,149,724,1,0,0,0,151,730,1,0,0,0,153,732,1,0,0,
  	0,155,735,1,0,0,0,157,753,1,0,0,0,159,756,1,0,0,0,161,762,1,0,0,0,163,
  	164,5,59,0,0,164,2,1,0,0,0,165,166,5,58,0,0,166,4,1,0,0,0,167,168,5,91,
  	0,0,168,6,1,0,0,0,169,170,5,44,0,0,170,8,1,0,0,0,171,172,5,93,0,0,172,
  	10,1,0,0,0,173,174,5,40,0,0,174,12,1,0,0,0,175,176,5,41,0,0,176,14,1,
  	0,0,0,177,178,5,124,0,0,178,16,1,0,0,0,179,180,5,38,0,0,180,18,1,0,0,
  	0,181,182,5,45,0,0,182,20,1,0,0,0,183,184,5,45,0,0,184,185,5,62,0,0,185,
  	22,1,0,0,0,186,187,5,123,0,0,187,24,1,0,0,0,188,189,5,125,0,0,189,26,
  	1,0,0,0,190,191,5,63,0,0,191,28,1,0,0,0,192,193,5,42,0,0,193,30,1,0,0,
  	0,194,195,5,43,0,0,195,32,1,0,0,0,196,197,5,60,0,0,197,34,1,0,0,0,198,
  	199,5,62,0,0,199,36,1,0,0,0,200,201,5,61,0,0,201,38,1,0,0,0,202,203,5,
  	34,0,0,203,204,5,115,0,0,204,205,5,105,0,0,205,206,5,109,0,0,206,207,
  	5,112,0,0,207,208,5,108,0,0,208,209,5,101,0,0,209,210,5,34,0,0,210,40,
  	1,0,0,0,211,212,5,34,0,0,212,213,5,102,0,0,213,214,5,117,0,0,214,215,
  	5,108,0,0,215,216,5,108,0,0,216,217,5,34,0,0,217,42,1,0,0,0,218,219,5,
  	110,0,0,219,220,5,111,0,0,220,221,5,100,0,0,221,222,5,101,0,0,222,223,
  	5,67,0,0,223,224,5,111,0,0,224,225,5,108,0,0,225,226,5,111,0,0,226,227,
  	5,114,0,0,227,44,1,0,0,0,228,229,5,110,0,0,229,230,5,111,0,0,230,231,
  	5,100,0,0,231,232,5,101,0,0,232,233,5,83,0,0,233,234,5,99,0,0,234,235,
  	5,97,0,0,235,236,5,108,0,0,236,237,5,101,0,0,237,46,1,0,0,0,238,239,5,
  	108,0,0,239,240,5,97,0,0,240,241,5,98,0,0,241,242,5,101,0,0,242,243,5,
  	108,0,0,243,244,5,67,0,0,244,245,5,111,0,0,245,246,5,108,0,0,246,247,
  	5,111,0,0,247,248,5,114,0,0,248,48,1,0,0,0,249,250,5,108,0,0,250,251,
  	5,97,0,0,251,252,5,98,0,0,252,253,5,101,0,0,253,254,5,108,0,0,254,255,
  	5,83,0,0,255,256,5,99,0,0,256,257,5,97,0,0,257,258,5,108,0,0,258,259,
  	5,101,0,0,259,50,1,0,0,0,260,261,5,108,0,0,261,262,5,97,0,0,262,263,5,
  	98,0,0,263,264,5,101,0,0,264,265,5,108,0,0,265,266,5,68,0,0,266,267,5,
  	101,0,0,267,268,5,116,0,0,268,269,5,97,0,0,269,270,5,105,0,0,270,271,
  	5,108,0,0,271,272,5,76,0,0,272,273,5,101,0,0,273,274,5,118,0,0,274,275,
  	5,101,0,0,275,276,5,108,0,0,276,52,1,0,0,0,277,278,5,112,0,0,278,279,
  	5,111,0,0,279,280,5,115,0,0,280,281,5,105,0,0,281,282,5,116,0,0,282,283,
  	5,105,0,0,283,284,5,111,0,0,284,285,5,110,0,0,285,286,5,90,0,0,286,54,
  	1,0,0,0,287,288,5,98,0,0,288,289,5,97,0,0,289,290,5,115,0,0,290,291,5,
  	105,0,0,291,292,5,99,0,0,292,293,5,78,0,0,293,294,5,111,0,0,294,295,5,
  	100,0,0,295,296,5,101,0,0,296,297,5,83,0,0,297,298,5,105,0,0,298,299,
  	5,122,0,0,299,300,5,101,0,0,300,56,1,0,0,0,301,302,5,98,0,0,302,303,5,
  	97,0,0,303,304,5,115,0,0,304,305,5,105,0,0,305,306,5,99,0,0,306,307,5,
  	76,0,0,307,308,5,97,0,0,308,309,5,98,0,0,309,310,5,101,0,0,310,311,5,
  	108,0,0,311,312,5,83,0,0,312,313,5,105,0,0,313,314,5,122,0,0,314,315,
  	5,101,0,0,315,58,1,0,0,0,316,317,5,98,0,0,317,318,5,97,0,0,318,319,5,
  	115,0,0,319,320,5,105,0,0,320,321,5,99,0,0,321,322,5,80,0,0,322,323,5,
  	111,0,0,323,324,5,115,0,0,324,325,5,105,0,0,325,326,5,116,0,0,326,327,
  	5,105,0,0,327,328,5,111,0,0,328,329,5,110,0,0,329,330,5,90,0,0,330,60,
  	1,0,0,0,331,332,5,65,0,0,332,333,5,110,0,0,333,334,5,121,0,0,334,62,1,
  	0,0,0,335,336,5,70,0,0,336,337,5,105,0,0,337,338,5,101,0,0,338,339,5,
  	108,0,0,339,340,5,100,0,0,340,341,5,79,0,0,341,342,5,102,0,0,342,64,1,
  	0,0,0,343,344,5,73,0,0,344,345,5,110,0,0,345,346,5,115,0,0,346,347,5,
  	116,0,0,347,348,5,97,0,0,348,349,5,110,0,0,349,350,5,99,0,0,350,351,5,
  	101,0,0,351,352,5,79,0,0,352,353,5,102,0,0,353,66,1,0,0,0,354,355,5,77,
  	0,0,355,356,5,101,0,0,356,357,5,116,0,0,357,358,5,104,0,0,358,359,5,111,
  	0,0,359,360,5,100,0,0,360,361,5,79,0,0,361,362,5,102,0,0,362,68,1,0,0,
  	0,363,364,5,67,0,0,364,365,5,114,0,0,365,366,5,101,0,0,366,367,5,97,0,
  	0,367,368,5,116,0,0,368,369,5,111,0,0,369,370,5,114,0,0,370,371,5,79,
  	0,0,371,372,5,102,0,0,372,70,1,0,0,0,373,374,5,80,0,0,374,375,5,97,0,
  	0,375,376,5,114,0,0,376,377,5,97,0,0,377,378,5,109,0,0,378,379,5,101,
  	0,0,379,380,5,116,0,0,380,381,5,101,0,0,381,382,5,114,0,0,382,383,5,79,
  	0,0,383,384,5,102,0,0,384,72,1,0,0,0,385,386,5,82,0,0,386,387,5,101,0,
  	0,387,388,5,116,0,0,388,389,5,117,0,0,389,390,5,114,0,0,390,391,5,110,
  	0,0,391,392,5,79,0,0,392,393,5,102,0,0,393,74,1,0,0,0,394,395,5,67,0,
  	0,395,396,5,97,0,0,396,397,5,108,0,0,397,398,5,108,0,0,398,399,5,101,
  	0,0,399,400,5,100,0,0,400,401,5,80,0,0,401,402,5,97,0,0,402,403,5,114,
  	0,0,403,404,5,97,0,0,404,405,5,109,0,0,405,406,5,79,0,0,406,407,5,102,
  	0,0,407,76,1,0,0,0,408,409,5,67,0,0,409,410,5,97,0,0,410,411,5,108,0,
  	0,411,412,5,108,0,0,412,413,5,101,0,0,413,414,5,100,0,0,414,415,5,82,
  	0,0,415,416,5,101,0,0,416,417,5,116,0,0,417,418,5,117,0,0,418,419,5,114,
  	0,0,419,420,5,110,0,0,420,421,5,79,0,0,421,422,5,102,0,0,422,78,1,0,0,
  	0,423,424,5,67,0,0,424,425,5,97,0,0,425,426,5,108,0,0,426,427,5,108,0,
  	0,427,428,5,101,0,0,428,429,5,100,0,0,429,430,5,77,0,0,430,431,5,101,
  	0,0,431,432,5,116,0,0,432,433,5,104,0,0,433,434,5,111,0,0,434,435,5,100,
  	0,0,435,436,5,79,0,0,436,437,5,102,0,0,437,80,1,0,0,0,438,439,5,114,0,
  	0,439,440,5,101,0,0,440,441,5,97,0,0,441,442,5,100,0,0,442,82,1,0,0,0,
  	443,444,5,119,0,0,444,445,5,114,0,0,445,446,5,105,0,0,446,447,5,116,0,
  	0,447,448,5,101,0,0,448,84,1,0,0,0,449,450,5,105,0,0,450,451,5,110,0,
  	0,451,452,5,80,0,0,452,453,5,97,0,0,453,454,5,99,0,0,454,455,5,107,0,
  	0,455,456,5,97,0,0,456,457,5,103,0,0,457,458,5,101,0,0,458,86,1,0,0,0,
  	459,460,5,117,0,0,460,461,5,115,0,0,461,462,5,101,0,0,462,463,5,100,0,
  	0,463,464,5,66,0,0,464,465,5,121,0,0,465,88,1,0,0,0,466,467,5,117,0,0,
  	467,468,5,115,0,0,468,469,5,101,0,0,469,90,1,0,0,0,470,471,5,99,0,0,471,
  	472,5,108,0,0,472,473,5,97,0,0,473,474,5,115,0,0,474,475,5,115,0,0,475,
  	476,5,79,0,0,476,477,5,102,0,0,477,92,1,0,0,0,478,479,5,115,0,0,479,480,
  	5,117,0,0,480,481,5,112,0,0,481,482,5,101,0,0,482,483,5,114,0,0,483,484,
  	5,79,0,0,484,485,5,102,0,0,485,94,1,0,0,0,486,487,5,115,0,0,487,488,5,
  	117,0,0,488,489,5,98,0,0,489,490,5,79,0,0,490,491,5,102,0,0,491,96,1,
  	0,0,0,492,493,5,83,0,0,493,494,5,116,0,0,494,495,5,121,0,0,495,496,5,
  	108,0,0,496,497,5,101,0,0,497,98,1,0,0,0,498,499,5,68,0,0,499,500,5,101,
  	0,0,500,501,5,102,0,0,501,502,5,97,0,0,502,503,5,117,0,0,503,504,5,108,
  	0,0,504,505,5,116,0,0,505,506,5,83,0,0,506,507,5,116,0,0,507,508,5,121,
  	0,0,508,509,5,108,0,0,509,510,5,101,0,0,510,100,1,0,0,0,511,512,5,66,
  	0,0,512,513,5,97,0,0,513,514,5,115,0,0,514,515,5,105,0,0,515,516,5,99,
  	0,0,516,517,5,83,0,0,517,518,5,116,0,0,518,519,5,121,0,0,519,520,5,108,
  	0,0,520,521,5,101,0,0,521,102,1,0,0,0,522,523,5,67,0,0,523,524,5,108,
  	0,0,524,525,5,97,0,0,525,526,5,115,0,0,526,527,5,115,0,0,527,528,5,83,
  	0,0,528,529,5,99,0,0,529,530,5,111,0,0,530,531,5,112,0,0,531,532,5,101,
  	0,0,532,104,1,0,0,0,533,534,5,78,0,0,534,535,5,111,0,0,535,536,5,100,
  	0,0,536,537,5,101,0,0,537,106,1,0,0,0,538,539,5,82,0,0,539,540,5,101,
  	0,0,540,541,5,102,0,0,541,542,5,101,0,0,542,543,5,114,0,0,543,544,5,101,
  	0,0,544,545,5,110,0,0,545,546,5,99,0,0,546,547,5,101,0,0,547,108,1,0,
  	0,0,548,549,5,67,0,0,549,550,5,111,0,0,550,551,5,110,0,0,551,552,5,100,
  	0,0,552,553,5,105,0,0,553,554,5,116,0,0,554,555,5,105,0,0,555,556,5,111,
  	0,0,556,557,5,110,0,0,557,110,1,0,0,0,558,559,5,83,0,0,559,560,5,116,
  	0,0,560,561,5,101,0,0,561,562,5,112,0,0,562,112,1,0,0,0,563,564,5,83,
  	0,0,564,565,5,101,0,0,565,566,5,103,0,0,566,114,1,0,0,0,567,568,5,76,
  	0,0,568,569,5,105,0,0,569,570,5,110,0,0,570,571,5,101,0,0,571,116,1,0,
  	0,0,572,573,5,76,0,0,573,574,5,105,0,0,574,575,5,110,0,0,575,576,5,101,
  	0,0,576,577,5,73,0,0,577,578,5,110,0,0,578,579,5,115,0,0,579,580,5,116,
  	0,0,580,581,5,97,0,0,581,582,5,110,0,0,582,583,5,99,0,0,583,584,5,101,
  	0,0,584,118,1,0,0,0,585,586,5,71,0,0,586,587,5,108,0,0,587,588,5,117,
  	0,0,588,589,5,101,0,0,589,120,1,0,0,0,590,591,5,71,0,0,591,592,5,108,
  	0,0,592,593,5,117,0,0,593,594,5,101,0,0,594,595,5,82,0,0,595,596,5,117,
  	0,0,596,597,5,110,0,0,597,598,5,116,0,0,598,599,5,105,0,0,599,600,5,109,
  	0,0,600,601,5,101,0,0,601,122,1,0,0,0,602,603,5,71,0,0,603,604,5,108,
  	0,0,604,605,5,117,0,0,605,606,5,101,0,0,606,607,5,77,0,0,607,608,5,101,
  	0,0,608,609,5,109,0,0,609,610,5,98,0,0,610,611,5,101,0,0,611,612,5,114,
  	0,0,612,613,5,79,0,0,613,614,5,102,0,0,614,124,1,0,0,0,615,616,5,71,0,
  	0,616,617,5,108,0,0,617,618,5,117,0,0,618,619,5,101,0,0,619,620,5,73,
  	0,0,620,621,5,110,0,0,621,622,5,115,0,0,622,623,5,116,0,0,623,624,5,97,
  	0,0,624,625,5,110,0,0,625,626,5,99,0,0,626,627,5,101,0,0,627,628,5,79,
  	0,0,628,629,5,102,0,0,629,126,1,0,0,0,630,631,5,71,0,0,631,632,5,108,
  	0,0,632,633,5,117,0,0,633,634,5,101,0,0,634,635,5,79,0,0,635,636,5,118,
  	0,0,636,637,5,101,0,0,637,638,5,114,0,0,638,639,5,114,0,0,639,640,5,105,
  	0,0,640,641,5,100,0,0,641,642,5,101,0,0,642,128,1,0,0,0,643,644,5,71,
  	0,0,644,645,5,108,0,0,645,646,5,117,0,0,646,647,5,101,0,0,647,648,5,72,
  	0,0,648,649,5,105,0,0,649,650,5,101,0,0,650,651,5,114,0,0,651,652,5,97,
  	0,0,652,653,5,114,0,0,653,654,5,99,0,0,654,655,5,104,0,0,655,656,5,121,
  	0,0,656,130,1,0,0,0,657,658,5,71,0,0,658,659,5,114,0,0,659,660,5,97,0,
  	0,660,661,5,112,0,0,661,662,5,104,0,0,662,132,1,0,0,0,663,664,5,71,0,
  	0,664,665,5,114,0,0,665,666,5,97,0,0,666,667,5,112,0,0,667,668,5,104,
  	0,0,668,669,5,73,0,0,669,670,5,110,0,0,670,671,5,115,0,0,671,672,5,116,
  	0,0,672,673,5,97,0,0,673,674,5,110,0,0,674,675,5,99,0,0,675,676,5,101,
  	0,0,676,134,1,0,0,0,677,678,5,67,0,0,678,679,5,111,0,0,679,680,5,100,
  	0,0,680,681,5,101,0,0,681,682,5,79,0,0,682,683,5,114,0,0,683,684,5,100,
  	0,0,684,685,5,101,0,0,685,686,5,114,0,0,686,136,1,0,0,0,687,688,5,115,
  	0,0,688,689,5,104,0,0,689,690,5,111,0,0,690,691,5,119,0,0,691,138,1,0,
  	0,0,692,697,5,34,0,0,693,696,3,141,70,0,694,696,3,153,76,0,695,693,1,
  	0,0,0,695,694,1,0,0,0,696,699,1,0,0,0,697,695,1,0,0,0,697,698,1,0,0,0,
  	698,700,1,0,0,0,699,697,1,0,0,0,700,701,5,34,0,0,701,140,1,0,0,0,702,
  	705,5,92,0,0,703,706,7,0,0,0,704,706,3,143,71,0,705,703,1,0,0,0,705,704,
  	1,0,0,0,706,142,1,0,0,0,707,708,5,117,0,0,708,709,3,145,72,0,709,710,
  	3,145,72,0,710,711,3,145,72,0,711,712,3,145,72,0,712,144,1,0,0,0,713,
  	714,7,1,0,0,714,146,1,0,0,0,715,719,3,151,75,0,716,718,3,149,74,0,717,
  	716,1,0,0,0,718,721,1,0,0,0,719,717,1,0,0,0,719,720,1,0,0,0,720,148,1,
  	0,0,0,721,719,1,0,0,0,722,725,3,151,75,0,723,725,7,2,0,0,724,722,1,0,
  	0,0,724,723,1,0,0,0,725,150,1,0,0,0,726,731,7,3,0,0,727,731,8,4,0,0,728,
  	729,7,5,0,0,729,731,7,6,0,0,730,726,1,0,0,0,730,727,1,0,0,0,730,728,1,
  	0,0,0,731,152,1,0,0,0,732,733,8,7,0,0,733,154,1,0,0,0,734,736,7,2,0,0,
  	735,734,1,0,0,0,736,737,1,0,0,0,737,735,1,0,0,0,737,738,1,0,0,0,738,739,
  	1,0,0,0,739,741,5,46,0,0,740,742,7,2,0,0,741,740,1,0,0,0,742,743,1,0,
  	0,0,743,741,1,0,0,0,743,744,1,0,0,0,744,156,1,0,0,0,745,754,5,48,0,0,
  	746,750,7,8,0,0,747,749,7,2,0,0,748,747,1,0,0,0,749,752,1,0,0,0,750,748,
  	1,0,0,0,750,751,1,0,0,0,751,754,1,0,0,0,752,750,1,0,0,0,753,745,1,0,0,
  	0,753,746,1,0,0,0,754,158,1,0,0,0,755,757,7,9,0,0,756,755,1,0,0,0,757,
  	758,1,0,0,0,758,756,1,0,0,0,758,759,1,0,0,0,759,760,1,0,0,0,760,761,6,
  	79,0,0,761,160,1,0,0,0,762,763,5,47,0,0,763,764,5,47,0,0,764,768,1,0,
  	0,0,765,767,8,10,0,0,766,765,1,0,0,0,767,770,1,0,0,0,768,766,1,0,0,0,
  	768,769,1,0,0,0,769,771,1,0,0,0,770,768,1,0,0,0,771,772,6,80,0,0,772,
  	162,1,0,0,0,13,0,695,697,705,719,724,730,737,743,750,753,758,768,1,6,
  	0,0
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
