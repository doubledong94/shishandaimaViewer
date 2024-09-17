// Generated from /home/ydd/shishandaimaViewer/simpleView/SimpleView.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class SimpleViewParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, LABEL_DETAIL_LEVEL_SIMPLE=20, LABEL_DETAIL_LEVEL_FULL=21, 
		NODE_COLOR=22, NODE_SCALE=23, LABEL_COLOR=24, LABEL_SCALE=25, LABEL_DETAIL_LEVEL=26, 
		POSITION_Z=27, BASIC_NODE_SIZE=28, BASIC_LABEL_SIZE=29, BASIC_POSITION_Z=30, 
		ANY=31, FINAL=32, CLASS=33, FIELD_OF=34, INSTANCE_OF=35, METHOD_OF=36, 
		CREATOR=37, PARAMETER_OF=38, RETURN_OF=39, CALLED_PARAM_OF=40, CALLED_RETURN_OF=41, 
		CALLED_METHOD_OF=42, METHOD_USED_BY=43, FIELD_USED_BY=44, METHOD_USE=45, 
		READ=46, WRITE=47, ANONYMOUS=48, IN_PACKAGE=49, CLASS_OF=50, SUPER=51, 
		SUB=52, STYLE=53, DEFAULT_STYLE=54, BASIC_STYLE=55, CLASS_SCOPE=56, NODE=57, 
		REFERENCE=58, VOID_REF=59, CONDITION=60, ELSE=61, DATA_STEP=62, TIMING_STEP=63, 
		DATA_OVERRIDE=64, TIMING_OVERRIDE=65, LV=66, FIELD=67, METHOD=68, CONSTRUCTOR=69, 
		CALLED_METHOD=70, PARAMETER=71, CALLED_PARAMETER=72, RETURN=73, CALLED_RETURN=74, 
		INDEX=75, ERROR=76, FIELD_CONNECTION=77, SEGMENT=78, LINE=79, LINE_INSTANCE=80, 
		GRAPH=81, GRAPH_INSTANCE=82, CODE_ORDER=83, NULL=84, SHOW=85, STRING=86, 
		IDENTIFIER=87, FLOAT=88, INT=89, WS=90, LINE_COMMENT=91;
	public static final int
		RULE_compilationUnit = 0, RULE_classScopeExp = 1, RULE_nodeExp = 2, RULE_paramList = 3, 
		RULE_lineExp = 4, RULE_idOrNull = 5, RULE_lineSegOrNodeExp = 6, RULE_lineArgumentList = 7, 
		RULE_graphElement = 8, RULE_graphBody = 9, RULE_pointInLine = 10, RULE_intersectionPoint = 11, 
		RULE_declaration = 12, RULE_showCommand = 13;
	private static String[] makeRuleNames() {
		return new String[] {
			"compilationUnit", "classScopeExp", "nodeExp", "paramList", "lineExp", 
			"idOrNull", "lineSegOrNodeExp", "lineArgumentList", "graphElement", "graphBody", 
			"pointInLine", "intersectionPoint", "declaration", "showCommand"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'['", "','", "']'", "'('", "')'", "'|'", "'&'", "'-'", 
			"'{'", "'}'", "'->'", "'||'", "'?'", "'*'", "'+'", "'<'", "'>'", "'='", 
			"'\"simple\"'", "'\"full\"'", "'nodeColor'", "'nodeScale'", "'labelColor'", 
			"'labelScale'", "'labelDetailLevel'", "'positionZ'", "'basicNodeSize'", 
			"'basicLabelSize'", "'basicPositionZ'", "'Any'", "'Final'", "'Class'", 
			"'FieldOf'", "'InstanceOf'", "'MethodOf'", "'CreatorOf'", "'ParameterOf'", 
			"'ReturnOf'", "'CalledParamOf'", "'CalledReturnOf'", "'CalledMethodOf'", 
			"'methodUsedBy'", "'fieldUsedBy'", "'methodUse'", "'read'", "'write'", 
			"'Anonymous'", "'inPackage'", "'classOf'", "'superOf'", "'subOf'", "'Style'", 
			"'DefaultStyle'", "'BasicStyle'", "'ClassScope'", "'Node'", "'Reference'", 
			"'VoidRef'", "'Condition'", "'Else'", "'DataStep'", "'TimingStep'", "'DataOverride'", 
			"'TimingOverride'", "'LV'", "'Field'", "'Method'", "'Constructor'", "'CalledMethod'", 
			"'Parameter'", "'CalledParameter'", "'Return'", "'CalledReturn'", "'Index'", 
			"'Error'", "'FieldConnection'", "'Seg'", "'Line'", "'LineInstance'", 
			"'Graph'", "'GraphInstance'", "'CodeOrder'", "'NULL'", "'show'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, "LABEL_DETAIL_LEVEL_SIMPLE", 
			"LABEL_DETAIL_LEVEL_FULL", "NODE_COLOR", "NODE_SCALE", "LABEL_COLOR", 
			"LABEL_SCALE", "LABEL_DETAIL_LEVEL", "POSITION_Z", "BASIC_NODE_SIZE", 
			"BASIC_LABEL_SIZE", "BASIC_POSITION_Z", "ANY", "FINAL", "CLASS", "FIELD_OF", 
			"INSTANCE_OF", "METHOD_OF", "CREATOR", "PARAMETER_OF", "RETURN_OF", "CALLED_PARAM_OF", 
			"CALLED_RETURN_OF", "CALLED_METHOD_OF", "METHOD_USED_BY", "FIELD_USED_BY", 
			"METHOD_USE", "READ", "WRITE", "ANONYMOUS", "IN_PACKAGE", "CLASS_OF", 
			"SUPER", "SUB", "STYLE", "DEFAULT_STYLE", "BASIC_STYLE", "CLASS_SCOPE", 
			"NODE", "REFERENCE", "VOID_REF", "CONDITION", "ELSE", "DATA_STEP", "TIMING_STEP", 
			"DATA_OVERRIDE", "TIMING_OVERRIDE", "LV", "FIELD", "METHOD", "CONSTRUCTOR", 
			"CALLED_METHOD", "PARAMETER", "CALLED_PARAMETER", "RETURN", "CALLED_RETURN", 
			"INDEX", "ERROR", "FIELD_CONNECTION", "SEGMENT", "LINE", "LINE_INSTANCE", 
			"GRAPH", "GRAPH_INSTANCE", "CODE_ORDER", "NULL", "SHOW", "STRING", "IDENTIFIER", 
			"FLOAT", "INT", "WS", "LINE_COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "SimpleView.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public SimpleViewParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CompilationUnitContext extends ParserRuleContext {
		public List<DeclarationContext> declaration() {
			return getRuleContexts(DeclarationContext.class);
		}
		public DeclarationContext declaration(int i) {
			return getRuleContext(DeclarationContext.class,i);
		}
		public List<ShowCommandContext> showCommand() {
			return getRuleContexts(ShowCommandContext.class);
		}
		public ShowCommandContext showCommand(int i) {
			return getRuleContext(ShowCommandContext.class,i);
		}
		public CompilationUnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compilationUnit; }
	}

	public final CompilationUnitContext compilationUnit() throws RecognitionException {
		CompilationUnitContext _localctx = new CompilationUnitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_compilationUnit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(31); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(28);
				declaration();
				setState(29);
				match(T__0);
				}
				}
				setState(33); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( ((((_la - 56)) & ~0x3f) == 0 && ((1L << (_la - 56)) & 264241155L) != 0) );
			setState(40);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==SHOW) {
				{
				{
				setState(35);
				showCommand();
				setState(36);
				match(T__0);
				}
				}
				setState(42);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ClassScopeExpContext extends ParserRuleContext {
		public Token classKey;
		public Token classKeyList;
		public Token packageStr;
		public Token union;
		public Token intersection;
		public Token difference;
		public ClassScopeExpContext bracket;
		public Token refOtherScope;
		public Token varClass;
		public List<TerminalNode> STRING() { return getTokens(SimpleViewParser.STRING); }
		public TerminalNode STRING(int i) {
			return getToken(SimpleViewParser.STRING, i);
		}
		public TerminalNode IN_PACKAGE() { return getToken(SimpleViewParser.IN_PACKAGE, 0); }
		public TerminalNode SUPER() { return getToken(SimpleViewParser.SUPER, 0); }
		public ClassScopeExpContext classScopeExp() {
			return getRuleContext(ClassScopeExpContext.class,0);
		}
		public TerminalNode SUB() { return getToken(SimpleViewParser.SUB, 0); }
		public List<TerminalNode> IDENTIFIER() { return getTokens(SimpleViewParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(SimpleViewParser.IDENTIFIER, i);
		}
		public ClassScopeExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classScopeExp; }
	}

	public final ClassScopeExpContext classScopeExp() throws RecognitionException {
		ClassScopeExpContext _localctx = new ClassScopeExpContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_classScopeExp);
		int _la;
		try {
			setState(97);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(43);
				((ClassScopeExpContext)_localctx).classKey = match(STRING);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(44);
				((ClassScopeExpContext)_localctx).classKeyList = match(T__1);
				setState(45);
				match(STRING);
				setState(50);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(46);
					match(T__2);
					setState(47);
					match(STRING);
					}
					}
					setState(52);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(53);
				match(T__3);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(54);
				match(IN_PACKAGE);
				setState(55);
				match(T__4);
				setState(56);
				((ClassScopeExpContext)_localctx).packageStr = match(STRING);
				setState(57);
				match(T__5);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(58);
				match(SUPER);
				setState(59);
				match(T__4);
				setState(60);
				classScopeExp();
				setState(61);
				match(T__5);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(63);
				match(SUB);
				setState(64);
				match(T__4);
				setState(65);
				classScopeExp();
				setState(66);
				match(T__5);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(68);
				match(IDENTIFIER);
				setState(71); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(69);
					((ClassScopeExpContext)_localctx).union = match(T__6);
					setState(70);
					match(IDENTIFIER);
					}
					}
					setState(73); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__6 );
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(75);
				match(IDENTIFIER);
				setState(78); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(76);
					((ClassScopeExpContext)_localctx).intersection = match(T__7);
					setState(77);
					match(IDENTIFIER);
					}
					}
					setState(80); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__7 );
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(82);
				match(IDENTIFIER);
				setState(85); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(83);
					((ClassScopeExpContext)_localctx).difference = match(T__8);
					setState(84);
					match(IDENTIFIER);
					}
					}
					setState(87); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__8 );
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(89);
				match(T__4);
				setState(90);
				((ClassScopeExpContext)_localctx).bracket = classScopeExp();
				setState(91);
				match(T__5);
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(93);
				((ClassScopeExpContext)_localctx).refOtherScope = match(IDENTIFIER);
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(94);
				((ClassScopeExpContext)_localctx).varClass = match(T__9);
				setState(95);
				match(IDENTIFIER);
				setState(96);
				match(T__10);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NodeExpContext extends ParserRuleContext {
		public Token nodeKey;
		public Token typeKey;
		public Token nodeKeyList;
		public NodeExpContext methodNode;
		public NodeExpContext node;
		public NodeExpContext paramNode;
		public NodeExpContext returnNode;
		public Token intersection;
		public Token union;
		public Token difference;
		public NodeExpContext read;
		public NodeExpContext write;
		public NodeExpContext bracket;
		public Token refOtherNode;
		public Token varNode;
		public List<TerminalNode> STRING() { return getTokens(SimpleViewParser.STRING); }
		public TerminalNode STRING(int i) {
			return getToken(SimpleViewParser.STRING, i);
		}
		public TerminalNode FIELD_OF() { return getToken(SimpleViewParser.FIELD_OF, 0); }
		public List<ClassScopeExpContext> classScopeExp() {
			return getRuleContexts(ClassScopeExpContext.class);
		}
		public ClassScopeExpContext classScopeExp(int i) {
			return getRuleContext(ClassScopeExpContext.class,i);
		}
		public TerminalNode METHOD_OF() { return getToken(SimpleViewParser.METHOD_OF, 0); }
		public TerminalNode PARAMETER_OF() { return getToken(SimpleViewParser.PARAMETER_OF, 0); }
		public NodeExpContext nodeExp() {
			return getRuleContext(NodeExpContext.class,0);
		}
		public TerminalNode RETURN_OF() { return getToken(SimpleViewParser.RETURN_OF, 0); }
		public TerminalNode INSTANCE_OF() { return getToken(SimpleViewParser.INSTANCE_OF, 0); }
		public TerminalNode CREATOR() { return getToken(SimpleViewParser.CREATOR, 0); }
		public TerminalNode SUPER() { return getToken(SimpleViewParser.SUPER, 0); }
		public TerminalNode SUB() { return getToken(SimpleViewParser.SUB, 0); }
		public TerminalNode CALLED_METHOD_OF() { return getToken(SimpleViewParser.CALLED_METHOD_OF, 0); }
		public TerminalNode CALLED_PARAM_OF() { return getToken(SimpleViewParser.CALLED_PARAM_OF, 0); }
		public TerminalNode CALLED_RETURN_OF() { return getToken(SimpleViewParser.CALLED_RETURN_OF, 0); }
		public TerminalNode METHOD_USED_BY() { return getToken(SimpleViewParser.METHOD_USED_BY, 0); }
		public TerminalNode FIELD_USED_BY() { return getToken(SimpleViewParser.FIELD_USED_BY, 0); }
		public TerminalNode METHOD_USE() { return getToken(SimpleViewParser.METHOD_USE, 0); }
		public List<TerminalNode> IDENTIFIER() { return getTokens(SimpleViewParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(SimpleViewParser.IDENTIFIER, i);
		}
		public TerminalNode READ() { return getToken(SimpleViewParser.READ, 0); }
		public TerminalNode WRITE() { return getToken(SimpleViewParser.WRITE, 0); }
		public TerminalNode ANY() { return getToken(SimpleViewParser.ANY, 0); }
		public TerminalNode FINAL() { return getToken(SimpleViewParser.FINAL, 0); }
		public TerminalNode CLASS() { return getToken(SimpleViewParser.CLASS, 0); }
		public TerminalNode REFERENCE() { return getToken(SimpleViewParser.REFERENCE, 0); }
		public TerminalNode VOID_REF() { return getToken(SimpleViewParser.VOID_REF, 0); }
		public TerminalNode CONDITION() { return getToken(SimpleViewParser.CONDITION, 0); }
		public TerminalNode ELSE() { return getToken(SimpleViewParser.ELSE, 0); }
		public TerminalNode DATA_STEP() { return getToken(SimpleViewParser.DATA_STEP, 0); }
		public TerminalNode TIMING_STEP() { return getToken(SimpleViewParser.TIMING_STEP, 0); }
		public TerminalNode DATA_OVERRIDE() { return getToken(SimpleViewParser.DATA_OVERRIDE, 0); }
		public TerminalNode TIMING_OVERRIDE() { return getToken(SimpleViewParser.TIMING_OVERRIDE, 0); }
		public TerminalNode LV() { return getToken(SimpleViewParser.LV, 0); }
		public TerminalNode FIELD() { return getToken(SimpleViewParser.FIELD, 0); }
		public TerminalNode METHOD() { return getToken(SimpleViewParser.METHOD, 0); }
		public TerminalNode CONSTRUCTOR() { return getToken(SimpleViewParser.CONSTRUCTOR, 0); }
		public TerminalNode CALLED_METHOD() { return getToken(SimpleViewParser.CALLED_METHOD, 0); }
		public TerminalNode PARAMETER() { return getToken(SimpleViewParser.PARAMETER, 0); }
		public TerminalNode CALLED_PARAMETER() { return getToken(SimpleViewParser.CALLED_PARAMETER, 0); }
		public TerminalNode RETURN() { return getToken(SimpleViewParser.RETURN, 0); }
		public TerminalNode CALLED_RETURN() { return getToken(SimpleViewParser.CALLED_RETURN, 0); }
		public TerminalNode INDEX() { return getToken(SimpleViewParser.INDEX, 0); }
		public TerminalNode ANONYMOUS() { return getToken(SimpleViewParser.ANONYMOUS, 0); }
		public TerminalNode ERROR() { return getToken(SimpleViewParser.ERROR, 0); }
		public TerminalNode FIELD_CONNECTION() { return getToken(SimpleViewParser.FIELD_CONNECTION, 0); }
		public NodeExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nodeExp; }
	}

	public final NodeExpContext nodeExp() throws RecognitionException {
		NodeExpContext _localctx = new NodeExpContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_nodeExp);
		int _la;
		try {
			setState(254);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(99);
				((NodeExpContext)_localctx).nodeKey = match(STRING);
				setState(100);
				match(T__4);
				setState(101);
				((NodeExpContext)_localctx).typeKey = match(STRING);
				setState(102);
				match(T__5);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(103);
				((NodeExpContext)_localctx).nodeKeyList = match(T__1);
				setState(104);
				match(STRING);
				setState(105);
				match(T__4);
				setState(106);
				match(STRING);
				setState(107);
				match(T__5);
				setState(115);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(108);
					match(T__2);
					setState(109);
					match(STRING);
					setState(110);
					match(T__4);
					setState(111);
					match(STRING);
					setState(112);
					match(T__5);
					}
					}
					setState(117);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(118);
				match(T__3);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(119);
				match(FIELD_OF);
				setState(120);
				match(T__4);
				setState(121);
				classScopeExp();
				setState(122);
				match(T__5);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(124);
				match(METHOD_OF);
				setState(125);
				match(T__4);
				setState(126);
				classScopeExp();
				setState(127);
				match(T__5);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(129);
				match(PARAMETER_OF);
				setState(130);
				match(T__4);
				setState(131);
				((NodeExpContext)_localctx).methodNode = nodeExp();
				setState(132);
				match(T__5);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(134);
				match(RETURN_OF);
				setState(135);
				match(T__4);
				setState(136);
				((NodeExpContext)_localctx).methodNode = nodeExp();
				setState(137);
				match(T__5);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(139);
				match(INSTANCE_OF);
				setState(140);
				match(T__4);
				setState(141);
				classScopeExp();
				setState(142);
				match(T__2);
				setState(143);
				classScopeExp();
				setState(144);
				match(T__5);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(146);
				match(CREATOR);
				setState(147);
				match(T__4);
				setState(148);
				classScopeExp();
				setState(149);
				match(T__5);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(151);
				match(SUPER);
				setState(152);
				match(T__4);
				setState(153);
				((NodeExpContext)_localctx).node = nodeExp();
				setState(154);
				match(T__5);
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(156);
				match(SUB);
				setState(157);
				match(T__4);
				setState(158);
				((NodeExpContext)_localctx).node = nodeExp();
				setState(159);
				match(T__5);
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(161);
				match(CALLED_METHOD_OF);
				setState(162);
				match(T__4);
				setState(163);
				((NodeExpContext)_localctx).methodNode = nodeExp();
				setState(164);
				match(T__5);
				}
				break;
			case 12:
				enterOuterAlt(_localctx, 12);
				{
				setState(166);
				match(CALLED_PARAM_OF);
				setState(167);
				match(T__4);
				setState(168);
				((NodeExpContext)_localctx).paramNode = nodeExp();
				setState(169);
				match(T__5);
				}
				break;
			case 13:
				enterOuterAlt(_localctx, 13);
				{
				setState(171);
				match(CALLED_RETURN_OF);
				setState(172);
				match(T__4);
				setState(173);
				((NodeExpContext)_localctx).returnNode = nodeExp();
				setState(174);
				match(T__5);
				}
				break;
			case 14:
				enterOuterAlt(_localctx, 14);
				{
				setState(176);
				match(METHOD_USED_BY);
				setState(177);
				match(T__4);
				setState(178);
				((NodeExpContext)_localctx).node = nodeExp();
				setState(179);
				match(T__5);
				}
				break;
			case 15:
				enterOuterAlt(_localctx, 15);
				{
				setState(181);
				match(FIELD_USED_BY);
				setState(182);
				match(T__4);
				setState(183);
				((NodeExpContext)_localctx).node = nodeExp();
				setState(184);
				match(T__5);
				}
				break;
			case 16:
				enterOuterAlt(_localctx, 16);
				{
				setState(186);
				match(METHOD_USE);
				setState(187);
				match(T__4);
				setState(188);
				((NodeExpContext)_localctx).node = nodeExp();
				setState(189);
				match(T__5);
				}
				break;
			case 17:
				enterOuterAlt(_localctx, 17);
				{
				setState(191);
				match(IDENTIFIER);
				setState(194); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(192);
					((NodeExpContext)_localctx).intersection = match(T__7);
					setState(193);
					match(IDENTIFIER);
					}
					}
					setState(196); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__7 );
				}
				break;
			case 18:
				enterOuterAlt(_localctx, 18);
				{
				setState(198);
				match(IDENTIFIER);
				setState(201); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(199);
					((NodeExpContext)_localctx).union = match(T__6);
					setState(200);
					match(IDENTIFIER);
					}
					}
					setState(203); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__6 );
				}
				break;
			case 19:
				enterOuterAlt(_localctx, 19);
				{
				setState(205);
				match(IDENTIFIER);
				setState(208); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(206);
					((NodeExpContext)_localctx).difference = match(T__8);
					setState(207);
					match(IDENTIFIER);
					}
					}
					setState(210); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__8 );
				}
				break;
			case 20:
				enterOuterAlt(_localctx, 20);
				{
				setState(212);
				match(READ);
				setState(213);
				match(T__4);
				setState(214);
				((NodeExpContext)_localctx).read = nodeExp();
				setState(215);
				match(T__5);
				}
				break;
			case 21:
				enterOuterAlt(_localctx, 21);
				{
				setState(217);
				match(WRITE);
				setState(218);
				match(T__4);
				setState(219);
				((NodeExpContext)_localctx).write = nodeExp();
				setState(220);
				match(T__5);
				}
				break;
			case 22:
				enterOuterAlt(_localctx, 22);
				{
				setState(222);
				match(ANY);
				}
				break;
			case 23:
				enterOuterAlt(_localctx, 23);
				{
				setState(223);
				match(FINAL);
				}
				break;
			case 24:
				enterOuterAlt(_localctx, 24);
				{
				setState(224);
				match(CLASS);
				}
				break;
			case 25:
				enterOuterAlt(_localctx, 25);
				{
				setState(225);
				match(REFERENCE);
				}
				break;
			case 26:
				enterOuterAlt(_localctx, 26);
				{
				setState(226);
				match(VOID_REF);
				}
				break;
			case 27:
				enterOuterAlt(_localctx, 27);
				{
				setState(227);
				match(CONDITION);
				}
				break;
			case 28:
				enterOuterAlt(_localctx, 28);
				{
				setState(228);
				match(ELSE);
				}
				break;
			case 29:
				enterOuterAlt(_localctx, 29);
				{
				setState(229);
				match(DATA_STEP);
				}
				break;
			case 30:
				enterOuterAlt(_localctx, 30);
				{
				setState(230);
				match(TIMING_STEP);
				}
				break;
			case 31:
				enterOuterAlt(_localctx, 31);
				{
				setState(231);
				match(DATA_OVERRIDE);
				}
				break;
			case 32:
				enterOuterAlt(_localctx, 32);
				{
				setState(232);
				match(TIMING_OVERRIDE);
				}
				break;
			case 33:
				enterOuterAlt(_localctx, 33);
				{
				setState(233);
				match(LV);
				}
				break;
			case 34:
				enterOuterAlt(_localctx, 34);
				{
				setState(234);
				match(FIELD);
				}
				break;
			case 35:
				enterOuterAlt(_localctx, 35);
				{
				setState(235);
				match(METHOD);
				}
				break;
			case 36:
				enterOuterAlt(_localctx, 36);
				{
				setState(236);
				match(CONSTRUCTOR);
				}
				break;
			case 37:
				enterOuterAlt(_localctx, 37);
				{
				setState(237);
				match(CALLED_METHOD);
				}
				break;
			case 38:
				enterOuterAlt(_localctx, 38);
				{
				setState(238);
				match(PARAMETER);
				}
				break;
			case 39:
				enterOuterAlt(_localctx, 39);
				{
				setState(239);
				match(CALLED_PARAMETER);
				}
				break;
			case 40:
				enterOuterAlt(_localctx, 40);
				{
				setState(240);
				match(RETURN);
				}
				break;
			case 41:
				enterOuterAlt(_localctx, 41);
				{
				setState(241);
				match(CALLED_RETURN);
				}
				break;
			case 42:
				enterOuterAlt(_localctx, 42);
				{
				setState(242);
				match(INDEX);
				}
				break;
			case 43:
				enterOuterAlt(_localctx, 43);
				{
				setState(243);
				match(ANONYMOUS);
				}
				break;
			case 44:
				enterOuterAlt(_localctx, 44);
				{
				setState(244);
				match(ERROR);
				}
				break;
			case 45:
				enterOuterAlt(_localctx, 45);
				{
				setState(245);
				match(FIELD_CONNECTION);
				}
				break;
			case 46:
				enterOuterAlt(_localctx, 46);
				{
				setState(246);
				match(T__4);
				setState(247);
				((NodeExpContext)_localctx).bracket = nodeExp();
				setState(248);
				match(T__5);
				}
				break;
			case 47:
				enterOuterAlt(_localctx, 47);
				{
				setState(250);
				((NodeExpContext)_localctx).refOtherNode = match(IDENTIFIER);
				}
				break;
			case 48:
				enterOuterAlt(_localctx, 48);
				{
				setState(251);
				((NodeExpContext)_localctx).varNode = match(T__9);
				setState(252);
				match(IDENTIFIER);
				setState(253);
				match(T__10);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParamListContext extends ParserRuleContext {
		public List<TerminalNode> IDENTIFIER() { return getTokens(SimpleViewParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(SimpleViewParser.IDENTIFIER, i);
		}
		public ParamListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_paramList; }
	}

	public final ParamListContext paramList() throws RecognitionException {
		ParamListContext _localctx = new ParamListContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_paramList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(256);
			match(T__4);
			setState(257);
			match(IDENTIFIER);
			setState(262);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2) {
				{
				{
				setState(258);
				match(T__2);
				setState(259);
				match(IDENTIFIER);
				}
				}
				setState(264);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(265);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LineExpContext extends ParserRuleContext {
		public Token seq;
		public Token alt;
		public List<LineSegOrNodeExpContext> lineSegOrNodeExp() {
			return getRuleContexts(LineSegOrNodeExpContext.class);
		}
		public LineSegOrNodeExpContext lineSegOrNodeExp(int i) {
			return getRuleContext(LineSegOrNodeExpContext.class,i);
		}
		public LineExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lineExp; }
	}

	public final LineExpContext lineExp() throws RecognitionException {
		LineExpContext _localctx = new LineExpContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_lineExp);
		int _la;
		try {
			setState(281);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(267);
				lineSegOrNodeExp();
				setState(270); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(268);
					((LineExpContext)_localctx).seq = match(T__11);
					setState(269);
					lineSegOrNodeExp();
					}
					}
					setState(272); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__11 );
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(274);
				lineSegOrNodeExp();
				setState(277); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(275);
					((LineExpContext)_localctx).alt = match(T__12);
					setState(276);
					lineSegOrNodeExp();
					}
					}
					setState(279); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__12 );
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IdOrNullContext extends ParserRuleContext {
		public TerminalNode NULL() { return getToken(SimpleViewParser.NULL, 0); }
		public TerminalNode IDENTIFIER() { return getToken(SimpleViewParser.IDENTIFIER, 0); }
		public IdOrNullContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_idOrNull; }
	}

	public final IdOrNullContext idOrNull() throws RecognitionException {
		IdOrNullContext _localctx = new IdOrNullContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_idOrNull);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(283);
			_la = _input.LA(1);
			if ( !(_la==NULL || _la==IDENTIFIER) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LineSegOrNodeExpContext extends ParserRuleContext {
		public Token segName;
		public IdOrNullContext backward;
		public IdOrNullContext forward;
		public Token wildcard;
		public NodeExpContext nodeExp() {
			return getRuleContext(NodeExpContext.class,0);
		}
		public TerminalNode IDENTIFIER() { return getToken(SimpleViewParser.IDENTIFIER, 0); }
		public List<IdOrNullContext> idOrNull() {
			return getRuleContexts(IdOrNullContext.class);
		}
		public IdOrNullContext idOrNull(int i) {
			return getRuleContext(IdOrNullContext.class,i);
		}
		public LineSegOrNodeExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lineSegOrNodeExp; }
	}

	public final LineSegOrNodeExpContext lineSegOrNodeExp() throws RecognitionException {
		LineSegOrNodeExpContext _localctx = new LineSegOrNodeExpContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_lineSegOrNodeExp);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(296);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				{
				{
				setState(285);
				match(T__1);
				setState(286);
				((LineSegOrNodeExpContext)_localctx).segName = match(IDENTIFIER);
				setState(287);
				match(T__3);
				}
				}
				break;
			case 2:
				{
				{
				setState(288);
				nodeExp();
				setState(294);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__9) {
					{
					setState(289);
					match(T__9);
					setState(290);
					((LineSegOrNodeExpContext)_localctx).backward = idOrNull();
					setState(291);
					((LineSegOrNodeExpContext)_localctx).forward = idOrNull();
					setState(292);
					match(T__10);
					}
				}

				}
				}
				break;
			}
			setState(299);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 114688L) != 0)) {
				{
				setState(298);
				((LineSegOrNodeExpContext)_localctx).wildcard = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 114688L) != 0)) ) {
					((LineSegOrNodeExpContext)_localctx).wildcard = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LineArgumentListContext extends ParserRuleContext {
		public List<TerminalNode> IDENTIFIER() { return getTokens(SimpleViewParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(SimpleViewParser.IDENTIFIER, i);
		}
		public LineArgumentListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lineArgumentList; }
	}

	public final LineArgumentListContext lineArgumentList() throws RecognitionException {
		LineArgumentListContext _localctx = new LineArgumentListContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_lineArgumentList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(301);
			match(T__4);
			setState(302);
			match(IDENTIFIER);
			setState(307);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2) {
				{
				{
				setState(303);
				match(T__2);
				setState(304);
				match(IDENTIFIER);
				}
				}
				setState(309);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(310);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class GraphElementContext extends ParserRuleContext {
		public Token lineName;
		public TerminalNode IDENTIFIER() { return getToken(SimpleViewParser.IDENTIFIER, 0); }
		public LineArgumentListContext lineArgumentList() {
			return getRuleContext(LineArgumentListContext.class,0);
		}
		public GraphElementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_graphElement; }
	}

	public final GraphElementContext graphElement() throws RecognitionException {
		GraphElementContext _localctx = new GraphElementContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_graphElement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(312);
			((GraphElementContext)_localctx).lineName = match(IDENTIFIER);
			setState(314);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__4) {
				{
				setState(313);
				lineArgumentList();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class GraphBodyContext extends ParserRuleContext {
		public List<GraphElementContext> graphElement() {
			return getRuleContexts(GraphElementContext.class);
		}
		public GraphElementContext graphElement(int i) {
			return getRuleContext(GraphElementContext.class,i);
		}
		public GraphBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_graphBody; }
	}

	public final GraphBodyContext graphBody() throws RecognitionException {
		GraphBodyContext _localctx = new GraphBodyContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_graphBody);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(316);
			graphElement();
			setState(321);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2) {
				{
				{
				setState(317);
				match(T__2);
				setState(318);
				graphElement();
				}
				}
				setState(323);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PointInLineContext extends ParserRuleContext {
		public List<PointInLineContext> pointInLine() {
			return getRuleContexts(PointInLineContext.class);
		}
		public PointInLineContext pointInLine(int i) {
			return getRuleContext(PointInLineContext.class,i);
		}
		public TerminalNode INT() { return getToken(SimpleViewParser.INT, 0); }
		public PointInLineContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pointInLine; }
	}

	public final PointInLineContext pointInLine() throws RecognitionException {
		PointInLineContext _localctx = new PointInLineContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_pointInLine);
		int _la;
		try {
			setState(336);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
				enterOuterAlt(_localctx, 1);
				{
				setState(324);
				match(T__1);
				setState(325);
				pointInLine();
				setState(330);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__2) {
					{
					{
					setState(326);
					match(T__2);
					setState(327);
					pointInLine();
					}
					}
					setState(332);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(333);
				match(T__3);
				}
				break;
			case INT:
				enterOuterAlt(_localctx, 2);
				{
				setState(335);
				match(INT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IntersectionPointContext extends ParserRuleContext {
		public List<PointInLineContext> pointInLine() {
			return getRuleContexts(PointInLineContext.class);
		}
		public PointInLineContext pointInLine(int i) {
			return getRuleContext(PointInLineContext.class,i);
		}
		public IntersectionPointContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_intersectionPoint; }
	}

	public final IntersectionPointContext intersectionPoint() throws RecognitionException {
		IntersectionPointContext _localctx = new IntersectionPointContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_intersectionPoint);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(338);
			match(T__16);
			setState(339);
			pointInLine();
			setState(344);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2) {
				{
				{
				setState(340);
				match(T__2);
				setState(341);
				pointInLine();
				}
				}
				setState(346);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(347);
			match(T__17);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationContext extends ParserRuleContext {
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	 
		public DeclarationContext() { }
		public void copyFrom(DeclarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class GraphDeclarationContext extends DeclarationContext {
		public Token graphName;
		public TerminalNode GRAPH() { return getToken(SimpleViewParser.GRAPH, 0); }
		public GraphBodyContext graphBody() {
			return getRuleContext(GraphBodyContext.class,0);
		}
		public TerminalNode IDENTIFIER() { return getToken(SimpleViewParser.IDENTIFIER, 0); }
		public ParamListContext paramList() {
			return getRuleContext(ParamListContext.class,0);
		}
		public List<IntersectionPointContext> intersectionPoint() {
			return getRuleContexts(IntersectionPointContext.class);
		}
		public IntersectionPointContext intersectionPoint(int i) {
			return getRuleContext(IntersectionPointContext.class,i);
		}
		public GraphDeclarationContext(DeclarationContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ClassScopeDeclarationContext extends DeclarationContext {
		public TerminalNode CLASS_SCOPE() { return getToken(SimpleViewParser.CLASS_SCOPE, 0); }
		public TerminalNode IDENTIFIER() { return getToken(SimpleViewParser.IDENTIFIER, 0); }
		public ClassScopeExpContext classScopeExp() {
			return getRuleContext(ClassScopeExpContext.class,0);
		}
		public ClassScopeDeclarationContext(DeclarationContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LineAndGraphInstanceContext extends DeclarationContext {
		public List<TerminalNode> IDENTIFIER() { return getTokens(SimpleViewParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(SimpleViewParser.IDENTIFIER, i);
		}
		public LineArgumentListContext lineArgumentList() {
			return getRuleContext(LineArgumentListContext.class,0);
		}
		public TerminalNode LINE_INSTANCE() { return getToken(SimpleViewParser.LINE_INSTANCE, 0); }
		public TerminalNode GRAPH_INSTANCE() { return getToken(SimpleViewParser.GRAPH_INSTANCE, 0); }
		public LineAndGraphInstanceContext(DeclarationContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LineDeclarationContext extends DeclarationContext {
		public TerminalNode IDENTIFIER() { return getToken(SimpleViewParser.IDENTIFIER, 0); }
		public LineExpContext lineExp() {
			return getRuleContext(LineExpContext.class,0);
		}
		public TerminalNode LINE() { return getToken(SimpleViewParser.LINE, 0); }
		public TerminalNode CODE_ORDER() { return getToken(SimpleViewParser.CODE_ORDER, 0); }
		public TerminalNode SEGMENT() { return getToken(SimpleViewParser.SEGMENT, 0); }
		public ParamListContext paramList() {
			return getRuleContext(ParamListContext.class,0);
		}
		public LineDeclarationContext(DeclarationContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NodeDeclarationContext extends DeclarationContext {
		public TerminalNode NODE() { return getToken(SimpleViewParser.NODE, 0); }
		public TerminalNode IDENTIFIER() { return getToken(SimpleViewParser.IDENTIFIER, 0); }
		public NodeExpContext nodeExp() {
			return getRuleContext(NodeExpContext.class,0);
		}
		public NodeDeclarationContext(DeclarationContext ctx) { copyFrom(ctx); }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_declaration);
		int _la;
		try {
			setState(381);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CLASS_SCOPE:
				_localctx = new ClassScopeDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(349);
				match(CLASS_SCOPE);
				setState(350);
				match(IDENTIFIER);
				setState(351);
				match(T__18);
				setState(352);
				classScopeExp();
				}
				break;
			case NODE:
				_localctx = new NodeDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(353);
				match(NODE);
				setState(354);
				match(IDENTIFIER);
				setState(355);
				match(T__18);
				setState(356);
				nodeExp();
				}
				break;
			case SEGMENT:
			case LINE:
			case CODE_ORDER:
				_localctx = new LineDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(357);
				_la = _input.LA(1);
				if ( !(((((_la - 78)) & ~0x3f) == 0 && ((1L << (_la - 78)) & 35L) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(358);
				match(IDENTIFIER);
				setState(360);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__4) {
					{
					setState(359);
					paramList();
					}
				}

				setState(362);
				match(T__18);
				setState(363);
				lineExp();
				}
				break;
			case GRAPH:
				_localctx = new GraphDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(364);
				match(GRAPH);
				setState(365);
				((GraphDeclarationContext)_localctx).graphName = match(IDENTIFIER);
				setState(367);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__4) {
					{
					setState(366);
					paramList();
					}
				}

				setState(369);
				match(T__18);
				setState(370);
				graphBody();
				setState(372); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(371);
					intersectionPoint();
					}
					}
					setState(374); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==T__16 );
				}
				break;
			case LINE_INSTANCE:
			case GRAPH_INSTANCE:
				_localctx = new LineAndGraphInstanceContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(376);
				_la = _input.LA(1);
				if ( !(_la==LINE_INSTANCE || _la==GRAPH_INSTANCE) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(377);
				match(IDENTIFIER);
				setState(378);
				match(T__18);
				setState(379);
				match(IDENTIFIER);
				setState(380);
				lineArgumentList();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ShowCommandContext extends ParserRuleContext {
		public Token graphName;
		public Token defaultStyleName;
		public Token basicStyleName;
		public TerminalNode SHOW() { return getToken(SimpleViewParser.SHOW, 0); }
		public List<TerminalNode> IDENTIFIER() { return getTokens(SimpleViewParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(SimpleViewParser.IDENTIFIER, i);
		}
		public ShowCommandContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_showCommand; }
	}

	public final ShowCommandContext showCommand() throws RecognitionException {
		ShowCommandContext _localctx = new ShowCommandContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_showCommand);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(383);
			match(SHOW);
			setState(384);
			match(T__4);
			setState(385);
			((ShowCommandContext)_localctx).graphName = match(IDENTIFIER);
			setState(386);
			match(T__2);
			setState(387);
			((ShowCommandContext)_localctx).defaultStyleName = match(IDENTIFIER);
			setState(388);
			match(T__2);
			setState(389);
			((ShowCommandContext)_localctx).basicStyleName = match(IDENTIFIER);
			setState(390);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001[\u0189\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0001\u0000\u0001\u0000\u0001\u0000\u0004\u0000"+
		" \b\u0000\u000b\u0000\f\u0000!\u0001\u0000\u0001\u0000\u0001\u0000\u0005"+
		"\u0000\'\b\u0000\n\u0000\f\u0000*\t\u0000\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0005\u00011\b\u0001\n\u0001\f\u00014\t"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0004\u0001H\b\u0001\u000b\u0001\f\u0001I\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0004\u0001O\b\u0001\u000b\u0001\f\u0001P\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0004\u0001V\b\u0001\u000b\u0001\f\u0001W\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0003\u0001b\b\u0001\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002"+
		"r\b\u0002\n\u0002\f\u0002u\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0004\u0002\u00c3\b\u0002\u000b\u0002\f\u0002\u00c4\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0004\u0002\u00ca\b\u0002\u000b\u0002\f"+
		"\u0002\u00cb\u0001\u0002\u0001\u0002\u0001\u0002\u0004\u0002\u00d1\b\u0002"+
		"\u000b\u0002\f\u0002\u00d2\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0003\u0002\u00ff\b\u0002\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0005\u0003\u0105\b\u0003\n\u0003\f\u0003\u0108"+
		"\t\u0003\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0004"+
		"\u0004\u010f\b\u0004\u000b\u0004\f\u0004\u0110\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0004\u0004\u0116\b\u0004\u000b\u0004\f\u0004\u0117\u0003"+
		"\u0004\u011a\b\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0003\u0006\u0127\b\u0006\u0003\u0006\u0129\b\u0006\u0001\u0006"+
		"\u0003\u0006\u012c\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0005\u0007\u0132\b\u0007\n\u0007\f\u0007\u0135\t\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\b\u0001\b\u0003\b\u013b\b\b\u0001\t\u0001\t\u0001\t\u0005"+
		"\t\u0140\b\t\n\t\f\t\u0143\t\t\u0001\n\u0001\n\u0001\n\u0001\n\u0005\n"+
		"\u0149\b\n\n\n\f\n\u014c\t\n\u0001\n\u0001\n\u0001\n\u0003\n\u0151\b\n"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b\u0157\b\u000b"+
		"\n\u000b\f\u000b\u015a\t\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001\f"+
		"\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0003\f\u0169\b\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003\f\u0170"+
		"\b\f\u0001\f\u0001\f\u0001\f\u0004\f\u0175\b\f\u000b\f\f\f\u0176\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003\f\u017e\b\f\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0000\u0000"+
		"\u000e\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018"+
		"\u001a\u0000\u0004\u0002\u0000TTWW\u0001\u0000\u000e\u0010\u0002\u0000"+
		"NOSS\u0002\u0000PPRR\u01d1\u0000\u001f\u0001\u0000\u0000\u0000\u0002a"+
		"\u0001\u0000\u0000\u0000\u0004\u00fe\u0001\u0000\u0000\u0000\u0006\u0100"+
		"\u0001\u0000\u0000\u0000\b\u0119\u0001\u0000\u0000\u0000\n\u011b\u0001"+
		"\u0000\u0000\u0000\f\u0128\u0001\u0000\u0000\u0000\u000e\u012d\u0001\u0000"+
		"\u0000\u0000\u0010\u0138\u0001\u0000\u0000\u0000\u0012\u013c\u0001\u0000"+
		"\u0000\u0000\u0014\u0150\u0001\u0000\u0000\u0000\u0016\u0152\u0001\u0000"+
		"\u0000\u0000\u0018\u017d\u0001\u0000\u0000\u0000\u001a\u017f\u0001\u0000"+
		"\u0000\u0000\u001c\u001d\u0003\u0018\f\u0000\u001d\u001e\u0005\u0001\u0000"+
		"\u0000\u001e \u0001\u0000\u0000\u0000\u001f\u001c\u0001\u0000\u0000\u0000"+
		" !\u0001\u0000\u0000\u0000!\u001f\u0001\u0000\u0000\u0000!\"\u0001\u0000"+
		"\u0000\u0000\"(\u0001\u0000\u0000\u0000#$\u0003\u001a\r\u0000$%\u0005"+
		"\u0001\u0000\u0000%\'\u0001\u0000\u0000\u0000&#\u0001\u0000\u0000\u0000"+
		"\'*\u0001\u0000\u0000\u0000(&\u0001\u0000\u0000\u0000()\u0001\u0000\u0000"+
		"\u0000)\u0001\u0001\u0000\u0000\u0000*(\u0001\u0000\u0000\u0000+b\u0005"+
		"V\u0000\u0000,-\u0005\u0002\u0000\u0000-2\u0005V\u0000\u0000./\u0005\u0003"+
		"\u0000\u0000/1\u0005V\u0000\u00000.\u0001\u0000\u0000\u000014\u0001\u0000"+
		"\u0000\u000020\u0001\u0000\u0000\u000023\u0001\u0000\u0000\u000035\u0001"+
		"\u0000\u0000\u000042\u0001\u0000\u0000\u00005b\u0005\u0004\u0000\u0000"+
		"67\u00051\u0000\u000078\u0005\u0005\u0000\u000089\u0005V\u0000\u00009"+
		"b\u0005\u0006\u0000\u0000:;\u00053\u0000\u0000;<\u0005\u0005\u0000\u0000"+
		"<=\u0003\u0002\u0001\u0000=>\u0005\u0006\u0000\u0000>b\u0001\u0000\u0000"+
		"\u0000?@\u00054\u0000\u0000@A\u0005\u0005\u0000\u0000AB\u0003\u0002\u0001"+
		"\u0000BC\u0005\u0006\u0000\u0000Cb\u0001\u0000\u0000\u0000DG\u0005W\u0000"+
		"\u0000EF\u0005\u0007\u0000\u0000FH\u0005W\u0000\u0000GE\u0001\u0000\u0000"+
		"\u0000HI\u0001\u0000\u0000\u0000IG\u0001\u0000\u0000\u0000IJ\u0001\u0000"+
		"\u0000\u0000Jb\u0001\u0000\u0000\u0000KN\u0005W\u0000\u0000LM\u0005\b"+
		"\u0000\u0000MO\u0005W\u0000\u0000NL\u0001\u0000\u0000\u0000OP\u0001\u0000"+
		"\u0000\u0000PN\u0001\u0000\u0000\u0000PQ\u0001\u0000\u0000\u0000Qb\u0001"+
		"\u0000\u0000\u0000RU\u0005W\u0000\u0000ST\u0005\t\u0000\u0000TV\u0005"+
		"W\u0000\u0000US\u0001\u0000\u0000\u0000VW\u0001\u0000\u0000\u0000WU\u0001"+
		"\u0000\u0000\u0000WX\u0001\u0000\u0000\u0000Xb\u0001\u0000\u0000\u0000"+
		"YZ\u0005\u0005\u0000\u0000Z[\u0003\u0002\u0001\u0000[\\\u0005\u0006\u0000"+
		"\u0000\\b\u0001\u0000\u0000\u0000]b\u0005W\u0000\u0000^_\u0005\n\u0000"+
		"\u0000_`\u0005W\u0000\u0000`b\u0005\u000b\u0000\u0000a+\u0001\u0000\u0000"+
		"\u0000a,\u0001\u0000\u0000\u0000a6\u0001\u0000\u0000\u0000a:\u0001\u0000"+
		"\u0000\u0000a?\u0001\u0000\u0000\u0000aD\u0001\u0000\u0000\u0000aK\u0001"+
		"\u0000\u0000\u0000aR\u0001\u0000\u0000\u0000aY\u0001\u0000\u0000\u0000"+
		"a]\u0001\u0000\u0000\u0000a^\u0001\u0000\u0000\u0000b\u0003\u0001\u0000"+
		"\u0000\u0000cd\u0005V\u0000\u0000de\u0005\u0005\u0000\u0000ef\u0005V\u0000"+
		"\u0000f\u00ff\u0005\u0006\u0000\u0000gh\u0005\u0002\u0000\u0000hi\u0005"+
		"V\u0000\u0000ij\u0005\u0005\u0000\u0000jk\u0005V\u0000\u0000ks\u0005\u0006"+
		"\u0000\u0000lm\u0005\u0003\u0000\u0000mn\u0005V\u0000\u0000no\u0005\u0005"+
		"\u0000\u0000op\u0005V\u0000\u0000pr\u0005\u0006\u0000\u0000ql\u0001\u0000"+
		"\u0000\u0000ru\u0001\u0000\u0000\u0000sq\u0001\u0000\u0000\u0000st\u0001"+
		"\u0000\u0000\u0000tv\u0001\u0000\u0000\u0000us\u0001\u0000\u0000\u0000"+
		"v\u00ff\u0005\u0004\u0000\u0000wx\u0005\"\u0000\u0000xy\u0005\u0005\u0000"+
		"\u0000yz\u0003\u0002\u0001\u0000z{\u0005\u0006\u0000\u0000{\u00ff\u0001"+
		"\u0000\u0000\u0000|}\u0005$\u0000\u0000}~\u0005\u0005\u0000\u0000~\u007f"+
		"\u0003\u0002\u0001\u0000\u007f\u0080\u0005\u0006\u0000\u0000\u0080\u00ff"+
		"\u0001\u0000\u0000\u0000\u0081\u0082\u0005&\u0000\u0000\u0082\u0083\u0005"+
		"\u0005\u0000\u0000\u0083\u0084\u0003\u0004\u0002\u0000\u0084\u0085\u0005"+
		"\u0006\u0000\u0000\u0085\u00ff\u0001\u0000\u0000\u0000\u0086\u0087\u0005"+
		"\'\u0000\u0000\u0087\u0088\u0005\u0005\u0000\u0000\u0088\u0089\u0003\u0004"+
		"\u0002\u0000\u0089\u008a\u0005\u0006\u0000\u0000\u008a\u00ff\u0001\u0000"+
		"\u0000\u0000\u008b\u008c\u0005#\u0000\u0000\u008c\u008d\u0005\u0005\u0000"+
		"\u0000\u008d\u008e\u0003\u0002\u0001\u0000\u008e\u008f\u0005\u0003\u0000"+
		"\u0000\u008f\u0090\u0003\u0002\u0001\u0000\u0090\u0091\u0005\u0006\u0000"+
		"\u0000\u0091\u00ff\u0001\u0000\u0000\u0000\u0092\u0093\u0005%\u0000\u0000"+
		"\u0093\u0094\u0005\u0005\u0000\u0000\u0094\u0095\u0003\u0002\u0001\u0000"+
		"\u0095\u0096\u0005\u0006\u0000\u0000\u0096\u00ff\u0001\u0000\u0000\u0000"+
		"\u0097\u0098\u00053\u0000\u0000\u0098\u0099\u0005\u0005\u0000\u0000\u0099"+
		"\u009a\u0003\u0004\u0002\u0000\u009a\u009b\u0005\u0006\u0000\u0000\u009b"+
		"\u00ff\u0001\u0000\u0000\u0000\u009c\u009d\u00054\u0000\u0000\u009d\u009e"+
		"\u0005\u0005\u0000\u0000\u009e\u009f\u0003\u0004\u0002\u0000\u009f\u00a0"+
		"\u0005\u0006\u0000\u0000\u00a0\u00ff\u0001\u0000\u0000\u0000\u00a1\u00a2"+
		"\u0005*\u0000\u0000\u00a2\u00a3\u0005\u0005\u0000\u0000\u00a3\u00a4\u0003"+
		"\u0004\u0002\u0000\u00a4\u00a5\u0005\u0006\u0000\u0000\u00a5\u00ff\u0001"+
		"\u0000\u0000\u0000\u00a6\u00a7\u0005(\u0000\u0000\u00a7\u00a8\u0005\u0005"+
		"\u0000\u0000\u00a8\u00a9\u0003\u0004\u0002\u0000\u00a9\u00aa\u0005\u0006"+
		"\u0000\u0000\u00aa\u00ff\u0001\u0000\u0000\u0000\u00ab\u00ac\u0005)\u0000"+
		"\u0000\u00ac\u00ad\u0005\u0005\u0000\u0000\u00ad\u00ae\u0003\u0004\u0002"+
		"\u0000\u00ae\u00af\u0005\u0006\u0000\u0000\u00af\u00ff\u0001\u0000\u0000"+
		"\u0000\u00b0\u00b1\u0005+\u0000\u0000\u00b1\u00b2\u0005\u0005\u0000\u0000"+
		"\u00b2\u00b3\u0003\u0004\u0002\u0000\u00b3\u00b4\u0005\u0006\u0000\u0000"+
		"\u00b4\u00ff\u0001\u0000\u0000\u0000\u00b5\u00b6\u0005,\u0000\u0000\u00b6"+
		"\u00b7\u0005\u0005\u0000\u0000\u00b7\u00b8\u0003\u0004\u0002\u0000\u00b8"+
		"\u00b9\u0005\u0006\u0000\u0000\u00b9\u00ff\u0001\u0000\u0000\u0000\u00ba"+
		"\u00bb\u0005-\u0000\u0000\u00bb\u00bc\u0005\u0005\u0000\u0000\u00bc\u00bd"+
		"\u0003\u0004\u0002\u0000\u00bd\u00be\u0005\u0006\u0000\u0000\u00be\u00ff"+
		"\u0001\u0000\u0000\u0000\u00bf\u00c2\u0005W\u0000\u0000\u00c0\u00c1\u0005"+
		"\b\u0000\u0000\u00c1\u00c3\u0005W\u0000\u0000\u00c2\u00c0\u0001\u0000"+
		"\u0000\u0000\u00c3\u00c4\u0001\u0000\u0000\u0000\u00c4\u00c2\u0001\u0000"+
		"\u0000\u0000\u00c4\u00c5\u0001\u0000\u0000\u0000\u00c5\u00ff\u0001\u0000"+
		"\u0000\u0000\u00c6\u00c9\u0005W\u0000\u0000\u00c7\u00c8\u0005\u0007\u0000"+
		"\u0000\u00c8\u00ca\u0005W\u0000\u0000\u00c9\u00c7\u0001\u0000\u0000\u0000"+
		"\u00ca\u00cb\u0001\u0000\u0000\u0000\u00cb\u00c9\u0001\u0000\u0000\u0000"+
		"\u00cb\u00cc\u0001\u0000\u0000\u0000\u00cc\u00ff\u0001\u0000\u0000\u0000"+
		"\u00cd\u00d0\u0005W\u0000\u0000\u00ce\u00cf\u0005\t\u0000\u0000\u00cf"+
		"\u00d1\u0005W\u0000\u0000\u00d0\u00ce\u0001\u0000\u0000\u0000\u00d1\u00d2"+
		"\u0001\u0000\u0000\u0000\u00d2\u00d0\u0001\u0000\u0000\u0000\u00d2\u00d3"+
		"\u0001\u0000\u0000\u0000\u00d3\u00ff\u0001\u0000\u0000\u0000\u00d4\u00d5"+
		"\u0005.\u0000\u0000\u00d5\u00d6\u0005\u0005\u0000\u0000\u00d6\u00d7\u0003"+
		"\u0004\u0002\u0000\u00d7\u00d8\u0005\u0006\u0000\u0000\u00d8\u00ff\u0001"+
		"\u0000\u0000\u0000\u00d9\u00da\u0005/\u0000\u0000\u00da\u00db\u0005\u0005"+
		"\u0000\u0000\u00db\u00dc\u0003\u0004\u0002\u0000\u00dc\u00dd\u0005\u0006"+
		"\u0000\u0000\u00dd\u00ff\u0001\u0000\u0000\u0000\u00de\u00ff\u0005\u001f"+
		"\u0000\u0000\u00df\u00ff\u0005 \u0000\u0000\u00e0\u00ff\u0005!\u0000\u0000"+
		"\u00e1\u00ff\u0005:\u0000\u0000\u00e2\u00ff\u0005;\u0000\u0000\u00e3\u00ff"+
		"\u0005<\u0000\u0000\u00e4\u00ff\u0005=\u0000\u0000\u00e5\u00ff\u0005>"+
		"\u0000\u0000\u00e6\u00ff\u0005?\u0000\u0000\u00e7\u00ff\u0005@\u0000\u0000"+
		"\u00e8\u00ff\u0005A\u0000\u0000\u00e9\u00ff\u0005B\u0000\u0000\u00ea\u00ff"+
		"\u0005C\u0000\u0000\u00eb\u00ff\u0005D\u0000\u0000\u00ec\u00ff\u0005E"+
		"\u0000\u0000\u00ed\u00ff\u0005F\u0000\u0000\u00ee\u00ff\u0005G\u0000\u0000"+
		"\u00ef\u00ff\u0005H\u0000\u0000\u00f0\u00ff\u0005I\u0000\u0000\u00f1\u00ff"+
		"\u0005J\u0000\u0000\u00f2\u00ff\u0005K\u0000\u0000\u00f3\u00ff\u00050"+
		"\u0000\u0000\u00f4\u00ff\u0005L\u0000\u0000\u00f5\u00ff\u0005M\u0000\u0000"+
		"\u00f6\u00f7\u0005\u0005\u0000\u0000\u00f7\u00f8\u0003\u0004\u0002\u0000"+
		"\u00f8\u00f9\u0005\u0006\u0000\u0000\u00f9\u00ff\u0001\u0000\u0000\u0000"+
		"\u00fa\u00ff\u0005W\u0000\u0000\u00fb\u00fc\u0005\n\u0000\u0000\u00fc"+
		"\u00fd\u0005W\u0000\u0000\u00fd\u00ff\u0005\u000b\u0000\u0000\u00fec\u0001"+
		"\u0000\u0000\u0000\u00feg\u0001\u0000\u0000\u0000\u00few\u0001\u0000\u0000"+
		"\u0000\u00fe|\u0001\u0000\u0000\u0000\u00fe\u0081\u0001\u0000\u0000\u0000"+
		"\u00fe\u0086\u0001\u0000\u0000\u0000\u00fe\u008b\u0001\u0000\u0000\u0000"+
		"\u00fe\u0092\u0001\u0000\u0000\u0000\u00fe\u0097\u0001\u0000\u0000\u0000"+
		"\u00fe\u009c\u0001\u0000\u0000\u0000\u00fe\u00a1\u0001\u0000\u0000\u0000"+
		"\u00fe\u00a6\u0001\u0000\u0000\u0000\u00fe\u00ab\u0001\u0000\u0000\u0000"+
		"\u00fe\u00b0\u0001\u0000\u0000\u0000\u00fe\u00b5\u0001\u0000\u0000\u0000"+
		"\u00fe\u00ba\u0001\u0000\u0000\u0000\u00fe\u00bf\u0001\u0000\u0000\u0000"+
		"\u00fe\u00c6\u0001\u0000\u0000\u0000\u00fe\u00cd\u0001\u0000\u0000\u0000"+
		"\u00fe\u00d4\u0001\u0000\u0000\u0000\u00fe\u00d9\u0001\u0000\u0000\u0000"+
		"\u00fe\u00de\u0001\u0000\u0000\u0000\u00fe\u00df\u0001\u0000\u0000\u0000"+
		"\u00fe\u00e0\u0001\u0000\u0000\u0000\u00fe\u00e1\u0001\u0000\u0000\u0000"+
		"\u00fe\u00e2\u0001\u0000\u0000\u0000\u00fe\u00e3\u0001\u0000\u0000\u0000"+
		"\u00fe\u00e4\u0001\u0000\u0000\u0000\u00fe\u00e5\u0001\u0000\u0000\u0000"+
		"\u00fe\u00e6\u0001\u0000\u0000\u0000\u00fe\u00e7\u0001\u0000\u0000\u0000"+
		"\u00fe\u00e8\u0001\u0000\u0000\u0000\u00fe\u00e9\u0001\u0000\u0000\u0000"+
		"\u00fe\u00ea\u0001\u0000\u0000\u0000\u00fe\u00eb\u0001\u0000\u0000\u0000"+
		"\u00fe\u00ec\u0001\u0000\u0000\u0000\u00fe\u00ed\u0001\u0000\u0000\u0000"+
		"\u00fe\u00ee\u0001\u0000\u0000\u0000\u00fe\u00ef\u0001\u0000\u0000\u0000"+
		"\u00fe\u00f0\u0001\u0000\u0000\u0000\u00fe\u00f1\u0001\u0000\u0000\u0000"+
		"\u00fe\u00f2\u0001\u0000\u0000\u0000\u00fe\u00f3\u0001\u0000\u0000\u0000"+
		"\u00fe\u00f4\u0001\u0000\u0000\u0000\u00fe\u00f5\u0001\u0000\u0000\u0000"+
		"\u00fe\u00f6\u0001\u0000\u0000\u0000\u00fe\u00fa\u0001\u0000\u0000\u0000"+
		"\u00fe\u00fb\u0001\u0000\u0000\u0000\u00ff\u0005\u0001\u0000\u0000\u0000"+
		"\u0100\u0101\u0005\u0005\u0000\u0000\u0101\u0106\u0005W\u0000\u0000\u0102"+
		"\u0103\u0005\u0003\u0000\u0000\u0103\u0105\u0005W\u0000\u0000\u0104\u0102"+
		"\u0001\u0000\u0000\u0000\u0105\u0108\u0001\u0000\u0000\u0000\u0106\u0104"+
		"\u0001\u0000\u0000\u0000\u0106\u0107\u0001\u0000\u0000\u0000\u0107\u0109"+
		"\u0001\u0000\u0000\u0000\u0108\u0106\u0001\u0000\u0000\u0000\u0109\u010a"+
		"\u0005\u0006\u0000\u0000\u010a\u0007\u0001\u0000\u0000\u0000\u010b\u010e"+
		"\u0003\f\u0006\u0000\u010c\u010d\u0005\f\u0000\u0000\u010d\u010f\u0003"+
		"\f\u0006\u0000\u010e\u010c\u0001\u0000\u0000\u0000\u010f\u0110\u0001\u0000"+
		"\u0000\u0000\u0110\u010e\u0001\u0000\u0000\u0000\u0110\u0111\u0001\u0000"+
		"\u0000\u0000\u0111\u011a\u0001\u0000\u0000\u0000\u0112\u0115\u0003\f\u0006"+
		"\u0000\u0113\u0114\u0005\r\u0000\u0000\u0114\u0116\u0003\f\u0006\u0000"+
		"\u0115\u0113\u0001\u0000\u0000\u0000\u0116\u0117\u0001\u0000\u0000\u0000"+
		"\u0117\u0115\u0001\u0000\u0000\u0000\u0117\u0118\u0001\u0000\u0000\u0000"+
		"\u0118\u011a\u0001\u0000\u0000\u0000\u0119\u010b\u0001\u0000\u0000\u0000"+
		"\u0119\u0112\u0001\u0000\u0000\u0000\u011a\t\u0001\u0000\u0000\u0000\u011b"+
		"\u011c\u0007\u0000\u0000\u0000\u011c\u000b\u0001\u0000\u0000\u0000\u011d"+
		"\u011e\u0005\u0002\u0000\u0000\u011e\u011f\u0005W\u0000\u0000\u011f\u0129"+
		"\u0005\u0004\u0000\u0000\u0120\u0126\u0003\u0004\u0002\u0000\u0121\u0122"+
		"\u0005\n\u0000\u0000\u0122\u0123\u0003\n\u0005\u0000\u0123\u0124\u0003"+
		"\n\u0005\u0000\u0124\u0125\u0005\u000b\u0000\u0000\u0125\u0127\u0001\u0000"+
		"\u0000\u0000\u0126\u0121\u0001\u0000\u0000\u0000\u0126\u0127\u0001\u0000"+
		"\u0000\u0000\u0127\u0129\u0001\u0000\u0000\u0000\u0128\u011d\u0001\u0000"+
		"\u0000\u0000\u0128\u0120\u0001\u0000\u0000\u0000\u0129\u012b\u0001\u0000"+
		"\u0000\u0000\u012a\u012c\u0007\u0001\u0000\u0000\u012b\u012a\u0001\u0000"+
		"\u0000\u0000\u012b\u012c\u0001\u0000\u0000\u0000\u012c\r\u0001\u0000\u0000"+
		"\u0000\u012d\u012e\u0005\u0005\u0000\u0000\u012e\u0133\u0005W\u0000\u0000"+
		"\u012f\u0130\u0005\u0003\u0000\u0000\u0130\u0132\u0005W\u0000\u0000\u0131"+
		"\u012f\u0001\u0000\u0000\u0000\u0132\u0135\u0001\u0000\u0000\u0000\u0133"+
		"\u0131\u0001\u0000\u0000\u0000\u0133\u0134\u0001\u0000\u0000\u0000\u0134"+
		"\u0136\u0001\u0000\u0000\u0000\u0135\u0133\u0001\u0000\u0000\u0000\u0136"+
		"\u0137\u0005\u0006\u0000\u0000\u0137\u000f\u0001\u0000\u0000\u0000\u0138"+
		"\u013a\u0005W\u0000\u0000\u0139\u013b\u0003\u000e\u0007\u0000\u013a\u0139"+
		"\u0001\u0000\u0000\u0000\u013a\u013b\u0001\u0000\u0000\u0000\u013b\u0011"+
		"\u0001\u0000\u0000\u0000\u013c\u0141\u0003\u0010\b\u0000\u013d\u013e\u0005"+
		"\u0003\u0000\u0000\u013e\u0140\u0003\u0010\b\u0000\u013f\u013d\u0001\u0000"+
		"\u0000\u0000\u0140\u0143\u0001\u0000\u0000\u0000\u0141\u013f\u0001\u0000"+
		"\u0000\u0000\u0141\u0142\u0001\u0000\u0000\u0000\u0142\u0013\u0001\u0000"+
		"\u0000\u0000\u0143\u0141\u0001\u0000\u0000\u0000\u0144\u0145\u0005\u0002"+
		"\u0000\u0000\u0145\u014a\u0003\u0014\n\u0000\u0146\u0147\u0005\u0003\u0000"+
		"\u0000\u0147\u0149\u0003\u0014\n\u0000\u0148\u0146\u0001\u0000\u0000\u0000"+
		"\u0149\u014c\u0001\u0000\u0000\u0000\u014a\u0148\u0001\u0000\u0000\u0000"+
		"\u014a\u014b\u0001\u0000\u0000\u0000\u014b\u014d\u0001\u0000\u0000\u0000"+
		"\u014c\u014a\u0001\u0000\u0000\u0000\u014d\u014e\u0005\u0004\u0000\u0000"+
		"\u014e\u0151\u0001\u0000\u0000\u0000\u014f\u0151\u0005Y\u0000\u0000\u0150"+
		"\u0144\u0001\u0000\u0000\u0000\u0150\u014f\u0001\u0000\u0000\u0000\u0151"+
		"\u0015\u0001\u0000\u0000\u0000\u0152\u0153\u0005\u0011\u0000\u0000\u0153"+
		"\u0158\u0003\u0014\n\u0000\u0154\u0155\u0005\u0003\u0000\u0000\u0155\u0157"+
		"\u0003\u0014\n\u0000\u0156\u0154\u0001\u0000\u0000\u0000\u0157\u015a\u0001"+
		"\u0000\u0000\u0000\u0158\u0156\u0001\u0000\u0000\u0000\u0158\u0159\u0001"+
		"\u0000\u0000\u0000\u0159\u015b\u0001\u0000\u0000\u0000\u015a\u0158\u0001"+
		"\u0000\u0000\u0000\u015b\u015c\u0005\u0012\u0000\u0000\u015c\u0017\u0001"+
		"\u0000\u0000\u0000\u015d\u015e\u00058\u0000\u0000\u015e\u015f\u0005W\u0000"+
		"\u0000\u015f\u0160\u0005\u0013\u0000\u0000\u0160\u017e\u0003\u0002\u0001"+
		"\u0000\u0161\u0162\u00059\u0000\u0000\u0162\u0163\u0005W\u0000\u0000\u0163"+
		"\u0164\u0005\u0013\u0000\u0000\u0164\u017e\u0003\u0004\u0002\u0000\u0165"+
		"\u0166\u0007\u0002\u0000\u0000\u0166\u0168\u0005W\u0000\u0000\u0167\u0169"+
		"\u0003\u0006\u0003\u0000\u0168\u0167\u0001\u0000\u0000\u0000\u0168\u0169"+
		"\u0001\u0000\u0000\u0000\u0169\u016a\u0001\u0000\u0000\u0000\u016a\u016b"+
		"\u0005\u0013\u0000\u0000\u016b\u017e\u0003\b\u0004\u0000\u016c\u016d\u0005"+
		"Q\u0000\u0000\u016d\u016f\u0005W\u0000\u0000\u016e\u0170\u0003\u0006\u0003"+
		"\u0000\u016f\u016e\u0001\u0000\u0000\u0000\u016f\u0170\u0001\u0000\u0000"+
		"\u0000\u0170\u0171\u0001\u0000\u0000\u0000\u0171\u0172\u0005\u0013\u0000"+
		"\u0000\u0172\u0174\u0003\u0012\t\u0000\u0173\u0175\u0003\u0016\u000b\u0000"+
		"\u0174\u0173\u0001\u0000\u0000\u0000\u0175\u0176\u0001\u0000\u0000\u0000"+
		"\u0176\u0174\u0001\u0000\u0000\u0000\u0176\u0177\u0001\u0000\u0000\u0000"+
		"\u0177\u017e\u0001\u0000\u0000\u0000\u0178\u0179\u0007\u0003\u0000\u0000"+
		"\u0179\u017a\u0005W\u0000\u0000\u017a\u017b\u0005\u0013\u0000\u0000\u017b"+
		"\u017c\u0005W\u0000\u0000\u017c\u017e\u0003\u000e\u0007\u0000\u017d\u015d"+
		"\u0001\u0000\u0000\u0000\u017d\u0161\u0001\u0000\u0000\u0000\u017d\u0165"+
		"\u0001\u0000\u0000\u0000\u017d\u016c\u0001\u0000\u0000\u0000\u017d\u0178"+
		"\u0001\u0000\u0000\u0000\u017e\u0019\u0001\u0000\u0000\u0000\u017f\u0180"+
		"\u0005U\u0000\u0000\u0180\u0181\u0005\u0005\u0000\u0000\u0181\u0182\u0005"+
		"W\u0000\u0000\u0182\u0183\u0005\u0003\u0000\u0000\u0183\u0184\u0005W\u0000"+
		"\u0000\u0184\u0185\u0005\u0003\u0000\u0000\u0185\u0186\u0005W\u0000\u0000"+
		"\u0186\u0187\u0005\u0006\u0000\u0000\u0187\u001b\u0001\u0000\u0000\u0000"+
		"\u001d!(2IPWas\u00c4\u00cb\u00d2\u00fe\u0106\u0110\u0117\u0119\u0126\u0128"+
		"\u012b\u0133\u013a\u0141\u014a\u0150\u0158\u0168\u016f\u0176\u017d";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}