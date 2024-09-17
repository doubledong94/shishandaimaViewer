// Generated from /home/ydd/shishandaimaViewer/antlr/aidlParser/AIDLParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class AIDLParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ABSTRACT=1, CONST=2, ENUM=3, EXTENDS=4, IMPLEMENTS=5, IMPORT=6, INTERFACE=7, 
		PACKAGE=8, PRIVATE=9, PROTECTED=10, PUBLIC=11, RETURN=12, STATIC=13, VOID=14, 
		PARCELABLE=15, IN=16, OUT=17, INOUT=18, ONEWAY=19, CPP_HEADER=20, NDK_HEADER=21, 
		RUST_TYPE=22, ANNOTATION=23, UNION=24, VAR=25, YIELD=26, RECORD=27, SEALED=28, 
		PERMITS=29, NON_SEALED=30, INTVALUE=31, HEXVALUE=32, OCT_LITERAL=33, BINARY_LITERAL=34, 
		FLOATVALUE=35, HEX_FLOAT_LITERAL=36, TRUE_LITERAL=37, FALSE_LITERAL=38, 
		CHARVALUE=39, C_STR=40, TEXT_BLOCK=41, NULL_LITERAL=42, LPAREN=43, RPAREN=44, 
		LBRACE=45, RBRACE=46, LBRACK=47, RBRACK=48, SEMI=49, COMMA=50, DOT=51, 
		ASSIGN=52, GT=53, LT=54, BANG=55, TILDE=56, QUESTION=57, COLON=58, EQUALITY=59, 
		LEQ=60, GEQ=61, NEQ=62, LOGICAL_AND=63, LOGICAL_OR=64, UNARY_PLUS=65, 
		UNARY_MINUS=66, ADD=67, SUB=68, MUL=69, DIV=70, BITAND=71, BITOR=72, CARET=73, 
		MOD=74, LSHIFT=75, RSHIFT=76, ADD_ASSIGN=77, SUB_ASSIGN=78, MUL_ASSIGN=79, 
		DIV_ASSIGN=80, AND_ASSIGN=81, OR_ASSIGN=82, XOR_ASSIGN=83, MOD_ASSIGN=84, 
		LSHIFT_ASSIGN=85, RSHIFT_ASSIGN=86, URSHIFT_ASSIGN=87, ARROW=88, COLONCOLON=89, 
		ELLIPSIS=90, WS=91, COMMENT=92, LINE_COMMENT=93, IDENTIFIER=94;
	public static final int
		RULE_compilationUnit = 0, RULE_identifier = 1, RULE_optional_package = 2, 
		RULE_imports = 3, RULE_importI = 4, RULE_qualified_name = 5, RULE_decls = 6, 
		RULE_decl = 7, RULE_unannotated_decl = 8, RULE_type_params = 9, RULE_optional_type_params = 10, 
		RULE_optional_unstructured_headers = 11, RULE_parcelable_decl = 12, RULE_parcelable_members = 13, 
		RULE_variable_decl = 14, RULE_interface_decl = 15, RULE_interface_members = 16, 
		RULE_const_expr = 17, RULE_constant_value_list = 18, RULE_constant_value_non_empty_list = 19, 
		RULE_constant_decl = 20, RULE_enumerator = 21, RULE_enumerators = 22, 
		RULE_enum_decl_body = 23, RULE_enum_decl = 24, RULE_union_decl = 25, RULE_method_decl = 26, 
		RULE_arg_non_empty_list = 27, RULE_arg = 28, RULE_non_array_type = 29, 
		RULE_type = 30, RULE_type_args = 31, RULE_annotation_list = 32, RULE_parameter = 33, 
		RULE_parameter_non_empty_list = 34, RULE_annotation = 35, RULE_direction = 36;
	private static String[] makeRuleNames() {
		return new String[] {
			"compilationUnit", "identifier", "optional_package", "imports", "importI", 
			"qualified_name", "decls", "decl", "unannotated_decl", "type_params", 
			"optional_type_params", "optional_unstructured_headers", "parcelable_decl", 
			"parcelable_members", "variable_decl", "interface_decl", "interface_members", 
			"const_expr", "constant_value_list", "constant_value_non_empty_list", 
			"constant_decl", "enumerator", "enumerators", "enum_decl_body", "enum_decl", 
			"union_decl", "method_decl", "arg_non_empty_list", "arg", "non_array_type", 
			"type", "type_args", "annotation_list", "parameter", "parameter_non_empty_list", 
			"annotation", "direction"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'abstract'", "'const'", "'enum'", "'extends'", "'implements'", 
			"'import'", "'interface'", "'package'", "'private'", "'protected'", "'public'", 
			"'return'", "'static'", "'void'", "'parcelable'", "'in'", "'out'", "'inout'", 
			"'oneway'", "'cpp_header'", "'ndk_header'", "'rust_type'", null, "'union'", 
			"'var'", "'yield'", "'record'", "'sealed'", "'permits'", "'non-sealed'", 
			null, null, null, null, null, null, "'true'", "'false'", null, null, 
			null, "'null'", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "','", 
			"'.'", "'='", "'>'", "'<'", "'!'", "'~'", "'?'", "':'", "'=='", "'<='", 
			"'>='", "'!='", "'&&'", "'||'", "'++'", "'--'", "'+'", "'-'", "'*'", 
			"'/'", "'&'", "'|'", "'^'", "'%'", "'<<'", "'>>'", "'+='", "'-='", "'*='", 
			"'/='", "'&='", "'|='", "'^='", "'%='", "'<<='", "'>>='", "'>>>='", "'->'", 
			"'::'", "'...'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "ABSTRACT", "CONST", "ENUM", "EXTENDS", "IMPLEMENTS", "IMPORT", 
			"INTERFACE", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "STATIC", 
			"VOID", "PARCELABLE", "IN", "OUT", "INOUT", "ONEWAY", "CPP_HEADER", "NDK_HEADER", 
			"RUST_TYPE", "ANNOTATION", "UNION", "VAR", "YIELD", "RECORD", "SEALED", 
			"PERMITS", "NON_SEALED", "INTVALUE", "HEXVALUE", "OCT_LITERAL", "BINARY_LITERAL", 
			"FLOATVALUE", "HEX_FLOAT_LITERAL", "TRUE_LITERAL", "FALSE_LITERAL", "CHARVALUE", 
			"C_STR", "TEXT_BLOCK", "NULL_LITERAL", "LPAREN", "RPAREN", "LBRACE", 
			"RBRACE", "LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", "ASSIGN", "GT", 
			"LT", "BANG", "TILDE", "QUESTION", "COLON", "EQUALITY", "LEQ", "GEQ", 
			"NEQ", "LOGICAL_AND", "LOGICAL_OR", "UNARY_PLUS", "UNARY_MINUS", "ADD", 
			"SUB", "MUL", "DIV", "BITAND", "BITOR", "CARET", "MOD", "LSHIFT", "RSHIFT", 
			"ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "AND_ASSIGN", 
			"OR_ASSIGN", "XOR_ASSIGN", "MOD_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", 
			"URSHIFT_ASSIGN", "ARROW", "COLONCOLON", "ELLIPSIS", "WS", "COMMENT", 
			"LINE_COMMENT", "IDENTIFIER"
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
	public String getGrammarFileName() { return "AIDLParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public AIDLParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CompilationUnitContext extends ParserRuleContext {
		public DeclsContext decls() {
			return getRuleContext(DeclsContext.class,0);
		}
		public Optional_packageContext optional_package() {
			return getRuleContext(Optional_packageContext.class,0);
		}
		public ImportsContext imports() {
			return getRuleContext(ImportsContext.class,0);
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
			setState(75);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PACKAGE) {
				{
				setState(74);
				optional_package();
				}
			}

			setState(78);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IMPORT) {
				{
				setState(77);
				imports();
				}
			}

			setState(80);
			decls();
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
	public static class IdentifierContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(AIDLParser.IDENTIFIER, 0); }
		public TerminalNode CPP_HEADER() { return getToken(AIDLParser.CPP_HEADER, 0); }
		public TerminalNode NDK_HEADER() { return getToken(AIDLParser.NDK_HEADER, 0); }
		public TerminalNode RUST_TYPE() { return getToken(AIDLParser.RUST_TYPE, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 7340032L) != 0) || _la==IDENTIFIER) ) {
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
	public static class Optional_packageContext extends ParserRuleContext {
		public TerminalNode PACKAGE() { return getToken(AIDLParser.PACKAGE, 0); }
		public Qualified_nameContext qualified_name() {
			return getRuleContext(Qualified_nameContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(AIDLParser.SEMI, 0); }
		public Optional_packageContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_optional_package; }
	}

	public final Optional_packageContext optional_package() throws RecognitionException {
		Optional_packageContext _localctx = new Optional_packageContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_optional_package);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(84);
			match(PACKAGE);
			setState(85);
			qualified_name();
			setState(86);
			match(SEMI);
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
	public static class ImportsContext extends ParserRuleContext {
		public List<ImportIContext> importI() {
			return getRuleContexts(ImportIContext.class);
		}
		public ImportIContext importI(int i) {
			return getRuleContext(ImportIContext.class,i);
		}
		public ImportsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_imports; }
	}

	public final ImportsContext imports() throws RecognitionException {
		ImportsContext _localctx = new ImportsContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_imports);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(89); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(88);
				importI();
				}
				}
				setState(91); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==IMPORT );
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
	public static class ImportIContext extends ParserRuleContext {
		public TerminalNode IMPORT() { return getToken(AIDLParser.IMPORT, 0); }
		public Qualified_nameContext qualified_name() {
			return getRuleContext(Qualified_nameContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(AIDLParser.SEMI, 0); }
		public ImportIContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_importI; }
	}

	public final ImportIContext importI() throws RecognitionException {
		ImportIContext _localctx = new ImportIContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_importI);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			match(IMPORT);
			setState(94);
			qualified_name();
			setState(95);
			match(SEMI);
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
	public static class Qualified_nameContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> DOT() { return getTokens(AIDLParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(AIDLParser.DOT, i);
		}
		public Qualified_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_qualified_name; }
	}

	public final Qualified_nameContext qualified_name() throws RecognitionException {
		Qualified_nameContext _localctx = new Qualified_nameContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_qualified_name);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(97);
			identifier();
			setState(102);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(98);
					match(DOT);
					setState(99);
					identifier();
					}
					} 
				}
				setState(104);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
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
	public static class DeclsContext extends ParserRuleContext {
		public List<DeclContext> decl() {
			return getRuleContexts(DeclContext.class);
		}
		public DeclContext decl(int i) {
			return getRuleContext(DeclContext.class,i);
		}
		public DeclsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decls; }
	}

	public final DeclsContext decls() throws RecognitionException {
		DeclsContext _localctx = new DeclsContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_decls);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(106); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(105);
				decl();
				}
				}
				setState(108); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & 25723016L) != 0) );
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
	public static class DeclContext extends ParserRuleContext {
		public Annotation_listContext annotation_list() {
			return getRuleContext(Annotation_listContext.class,0);
		}
		public Unannotated_declContext unannotated_decl() {
			return getRuleContext(Unannotated_declContext.class,0);
		}
		public DeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl; }
	}

	public final DeclContext decl() throws RecognitionException {
		DeclContext _localctx = new DeclContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			annotation_list();
			setState(111);
			unannotated_decl();
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
	public static class Unannotated_declContext extends ParserRuleContext {
		public Parcelable_declContext parcelable_decl() {
			return getRuleContext(Parcelable_declContext.class,0);
		}
		public Interface_declContext interface_decl() {
			return getRuleContext(Interface_declContext.class,0);
		}
		public Enum_declContext enum_decl() {
			return getRuleContext(Enum_declContext.class,0);
		}
		public Union_declContext union_decl() {
			return getRuleContext(Union_declContext.class,0);
		}
		public Unannotated_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unannotated_decl; }
	}

	public final Unannotated_declContext unannotated_decl() throws RecognitionException {
		Unannotated_declContext _localctx = new Unannotated_declContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_unannotated_decl);
		try {
			setState(117);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case PARCELABLE:
				enterOuterAlt(_localctx, 1);
				{
				setState(113);
				parcelable_decl();
				}
				break;
			case INTERFACE:
			case ONEWAY:
				enterOuterAlt(_localctx, 2);
				{
				setState(114);
				interface_decl();
				}
				break;
			case ENUM:
				enterOuterAlt(_localctx, 3);
				{
				setState(115);
				enum_decl();
				}
				break;
			case UNION:
				enterOuterAlt(_localctx, 4);
				{
				setState(116);
				union_decl();
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
	public static class Type_paramsContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AIDLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AIDLParser.COMMA, i);
		}
		public Type_paramsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_params; }
	}

	public final Type_paramsContext type_params() throws RecognitionException {
		Type_paramsContext _localctx = new Type_paramsContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type_params);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(119);
			identifier();
			setState(124);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(120);
				match(COMMA);
				setState(121);
				identifier();
				}
				}
				setState(126);
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
	public static class Optional_type_paramsContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(AIDLParser.LT, 0); }
		public Type_paramsContext type_params() {
			return getRuleContext(Type_paramsContext.class,0);
		}
		public TerminalNode GT() { return getToken(AIDLParser.GT, 0); }
		public Optional_type_paramsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_optional_type_params; }
	}

	public final Optional_type_paramsContext optional_type_params() throws RecognitionException {
		Optional_type_paramsContext _localctx = new Optional_type_paramsContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_optional_type_params);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(127);
			match(LT);
			setState(128);
			type_params();
			setState(129);
			match(GT);
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
	public static class Optional_unstructured_headersContext extends ParserRuleContext {
		public List<TerminalNode> CPP_HEADER() { return getTokens(AIDLParser.CPP_HEADER); }
		public TerminalNode CPP_HEADER(int i) {
			return getToken(AIDLParser.CPP_HEADER, i);
		}
		public List<TerminalNode> C_STR() { return getTokens(AIDLParser.C_STR); }
		public TerminalNode C_STR(int i) {
			return getToken(AIDLParser.C_STR, i);
		}
		public List<TerminalNode> NDK_HEADER() { return getTokens(AIDLParser.NDK_HEADER); }
		public TerminalNode NDK_HEADER(int i) {
			return getToken(AIDLParser.NDK_HEADER, i);
		}
		public List<TerminalNode> RUST_TYPE() { return getTokens(AIDLParser.RUST_TYPE); }
		public TerminalNode RUST_TYPE(int i) {
			return getToken(AIDLParser.RUST_TYPE, i);
		}
		public Optional_unstructured_headersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_optional_unstructured_headers; }
	}

	public final Optional_unstructured_headersContext optional_unstructured_headers() throws RecognitionException {
		Optional_unstructured_headersContext _localctx = new Optional_unstructured_headersContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_optional_unstructured_headers);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(139);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 7340032L) != 0)) {
				{
				setState(137);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case CPP_HEADER:
					{
					{
					setState(131);
					match(CPP_HEADER);
					setState(132);
					match(C_STR);
					}
					}
					break;
				case NDK_HEADER:
					{
					{
					setState(133);
					match(NDK_HEADER);
					setState(134);
					match(C_STR);
					}
					}
					break;
				case RUST_TYPE:
					{
					{
					setState(135);
					match(RUST_TYPE);
					setState(136);
					match(C_STR);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(141);
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
	public static class Parcelable_declContext extends ParserRuleContext {
		public TerminalNode PARCELABLE() { return getToken(AIDLParser.PARCELABLE, 0); }
		public Qualified_nameContext qualified_name() {
			return getRuleContext(Qualified_nameContext.class,0);
		}
		public Optional_type_paramsContext optional_type_params() {
			return getRuleContext(Optional_type_paramsContext.class,0);
		}
		public Optional_unstructured_headersContext optional_unstructured_headers() {
			return getRuleContext(Optional_unstructured_headersContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(AIDLParser.SEMI, 0); }
		public TerminalNode LBRACE() { return getToken(AIDLParser.LBRACE, 0); }
		public Parcelable_membersContext parcelable_members() {
			return getRuleContext(Parcelable_membersContext.class,0);
		}
		public TerminalNode RBRACE() { return getToken(AIDLParser.RBRACE, 0); }
		public Parcelable_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parcelable_decl; }
	}

	public final Parcelable_declContext parcelable_decl() throws RecognitionException {
		Parcelable_declContext _localctx = new Parcelable_declContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_parcelable_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(142);
			match(PARCELABLE);
			setState(143);
			qualified_name();
			setState(145);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(144);
				optional_type_params();
				}
			}

			setState(154);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CPP_HEADER:
			case NDK_HEADER:
			case RUST_TYPE:
			case SEMI:
				{
				{
				setState(147);
				optional_unstructured_headers();
				setState(148);
				match(SEMI);
				}
				}
				break;
			case LBRACE:
				{
				{
				setState(150);
				match(LBRACE);
				setState(151);
				parcelable_members();
				setState(152);
				match(RBRACE);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
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
	public static class Parcelable_membersContext extends ParserRuleContext {
		public List<Variable_declContext> variable_decl() {
			return getRuleContexts(Variable_declContext.class);
		}
		public Variable_declContext variable_decl(int i) {
			return getRuleContext(Variable_declContext.class,i);
		}
		public List<Constant_declContext> constant_decl() {
			return getRuleContexts(Constant_declContext.class);
		}
		public Constant_declContext constant_decl(int i) {
			return getRuleContext(Constant_declContext.class,i);
		}
		public List<DeclContext> decl() {
			return getRuleContexts(DeclContext.class);
		}
		public DeclContext decl(int i) {
			return getRuleContext(DeclContext.class,i);
		}
		public Parcelable_membersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parcelable_members; }
	}

	public final Parcelable_membersContext parcelable_members() throws RecognitionException {
		Parcelable_membersContext _localctx = new Parcelable_membersContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_parcelable_members);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(161);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 33079436L) != 0) || _la==IDENTIFIER) {
				{
				setState(159);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
				case 1:
					{
					setState(156);
					variable_decl();
					}
					break;
				case 2:
					{
					setState(157);
					constant_decl();
					}
					break;
				case 3:
					{
					setState(158);
					decl();
					}
					break;
				}
				}
				setState(163);
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
	public static class Variable_declContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(AIDLParser.SEMI, 0); }
		public TerminalNode ASSIGN() { return getToken(AIDLParser.ASSIGN, 0); }
		public Const_exprContext const_expr() {
			return getRuleContext(Const_exprContext.class,0);
		}
		public Variable_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable_decl; }
	}

	public final Variable_declContext variable_decl() throws RecognitionException {
		Variable_declContext _localctx = new Variable_declContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_variable_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(164);
			type();
			setState(165);
			identifier();
			setState(168);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGN) {
				{
				setState(166);
				match(ASSIGN);
				setState(167);
				const_expr(0);
				}
			}

			setState(170);
			match(SEMI);
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
	public static class Interface_declContext extends ParserRuleContext {
		public TerminalNode INTERFACE() { return getToken(AIDLParser.INTERFACE, 0); }
		public Qualified_nameContext qualified_name() {
			return getRuleContext(Qualified_nameContext.class,0);
		}
		public TerminalNode ONEWAY() { return getToken(AIDLParser.ONEWAY, 0); }
		public TerminalNode SEMI() { return getToken(AIDLParser.SEMI, 0); }
		public TerminalNode LBRACE() { return getToken(AIDLParser.LBRACE, 0); }
		public Interface_membersContext interface_members() {
			return getRuleContext(Interface_membersContext.class,0);
		}
		public TerminalNode RBRACE() { return getToken(AIDLParser.RBRACE, 0); }
		public Interface_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_decl; }
	}

	public final Interface_declContext interface_decl() throws RecognitionException {
		Interface_declContext _localctx = new Interface_declContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_interface_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(173);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ONEWAY) {
				{
				setState(172);
				match(ONEWAY);
				}
			}

			setState(175);
			match(INTERFACE);
			setState(176);
			qualified_name();
			setState(182);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMI:
				{
				{
				setState(177);
				match(SEMI);
				}
				}
				break;
			case LBRACE:
				{
				{
				setState(178);
				match(LBRACE);
				setState(179);
				interface_members();
				setState(180);
				match(RBRACE);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
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
	public static class Interface_membersContext extends ParserRuleContext {
		public List<Method_declContext> method_decl() {
			return getRuleContexts(Method_declContext.class);
		}
		public Method_declContext method_decl(int i) {
			return getRuleContext(Method_declContext.class,i);
		}
		public List<Constant_declContext> constant_decl() {
			return getRuleContexts(Constant_declContext.class);
		}
		public Constant_declContext constant_decl(int i) {
			return getRuleContext(Constant_declContext.class,i);
		}
		public List<DeclContext> decl() {
			return getRuleContexts(DeclContext.class);
		}
		public DeclContext decl(int i) {
			return getRuleContext(DeclContext.class,i);
		}
		public Interface_membersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interface_members; }
	}

	public final Interface_membersContext interface_members() throws RecognitionException {
		Interface_membersContext _localctx = new Interface_membersContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_interface_members);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(189);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 33079436L) != 0) || _la==IDENTIFIER) {
				{
				setState(187);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
				case 1:
					{
					setState(184);
					method_decl();
					}
					break;
				case 2:
					{
					setState(185);
					constant_decl();
					}
					break;
				case 3:
					{
					setState(186);
					decl();
					}
					break;
				}
				}
				setState(191);
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
	public static class Const_exprContext extends ParserRuleContext {
		public TerminalNode TRUE_LITERAL() { return getToken(AIDLParser.TRUE_LITERAL, 0); }
		public TerminalNode FALSE_LITERAL() { return getToken(AIDLParser.FALSE_LITERAL, 0); }
		public TerminalNode CHARVALUE() { return getToken(AIDLParser.CHARVALUE, 0); }
		public TerminalNode INTVALUE() { return getToken(AIDLParser.INTVALUE, 0); }
		public TerminalNode FLOATVALUE() { return getToken(AIDLParser.FLOATVALUE, 0); }
		public TerminalNode HEXVALUE() { return getToken(AIDLParser.HEXVALUE, 0); }
		public TerminalNode C_STR() { return getToken(AIDLParser.C_STR, 0); }
		public Qualified_nameContext qualified_name() {
			return getRuleContext(Qualified_nameContext.class,0);
		}
		public TerminalNode LBRACE() { return getToken(AIDLParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(AIDLParser.RBRACE, 0); }
		public Constant_value_listContext constant_value_list() {
			return getRuleContext(Constant_value_listContext.class,0);
		}
		public TerminalNode ADD() { return getToken(AIDLParser.ADD, 0); }
		public List<Const_exprContext> const_expr() {
			return getRuleContexts(Const_exprContext.class);
		}
		public Const_exprContext const_expr(int i) {
			return getRuleContext(Const_exprContext.class,i);
		}
		public TerminalNode SUB() { return getToken(AIDLParser.SUB, 0); }
		public TerminalNode BANG() { return getToken(AIDLParser.BANG, 0); }
		public TerminalNode TILDE() { return getToken(AIDLParser.TILDE, 0); }
		public TerminalNode LPAREN() { return getToken(AIDLParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(AIDLParser.RPAREN, 0); }
		public TerminalNode LOGICAL_OR() { return getToken(AIDLParser.LOGICAL_OR, 0); }
		public TerminalNode LOGICAL_AND() { return getToken(AIDLParser.LOGICAL_AND, 0); }
		public TerminalNode BITOR() { return getToken(AIDLParser.BITOR, 0); }
		public TerminalNode CARET() { return getToken(AIDLParser.CARET, 0); }
		public TerminalNode BITAND() { return getToken(AIDLParser.BITAND, 0); }
		public TerminalNode EQUALITY() { return getToken(AIDLParser.EQUALITY, 0); }
		public TerminalNode NEQ() { return getToken(AIDLParser.NEQ, 0); }
		public TerminalNode LT() { return getToken(AIDLParser.LT, 0); }
		public TerminalNode GT() { return getToken(AIDLParser.GT, 0); }
		public TerminalNode LEQ() { return getToken(AIDLParser.LEQ, 0); }
		public TerminalNode GEQ() { return getToken(AIDLParser.GEQ, 0); }
		public TerminalNode LSHIFT() { return getToken(AIDLParser.LSHIFT, 0); }
		public TerminalNode RSHIFT() { return getToken(AIDLParser.RSHIFT, 0); }
		public TerminalNode MUL() { return getToken(AIDLParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(AIDLParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(AIDLParser.MOD, 0); }
		public Const_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_const_expr; }
	}

	public final Const_exprContext const_expr() throws RecognitionException {
		return const_expr(0);
	}

	private Const_exprContext const_expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Const_exprContext _localctx = new Const_exprContext(_ctx, _parentState);
		Const_exprContext _prevctx = _localctx;
		int _startState = 34;
		enterRecursionRule(_localctx, 34, RULE_const_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(218);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE_LITERAL:
				{
				setState(193);
				match(TRUE_LITERAL);
				}
				break;
			case FALSE_LITERAL:
				{
				setState(194);
				match(FALSE_LITERAL);
				}
				break;
			case CHARVALUE:
				{
				setState(195);
				match(CHARVALUE);
				}
				break;
			case INTVALUE:
				{
				setState(196);
				match(INTVALUE);
				}
				break;
			case FLOATVALUE:
				{
				setState(197);
				match(FLOATVALUE);
				}
				break;
			case HEXVALUE:
				{
				setState(198);
				match(HEXVALUE);
				}
				break;
			case C_STR:
				{
				setState(199);
				match(C_STR);
				}
				break;
			case CPP_HEADER:
			case NDK_HEADER:
			case RUST_TYPE:
			case IDENTIFIER:
				{
				setState(200);
				qualified_name();
				}
				break;
			case LBRACE:
				{
				setState(201);
				match(LBRACE);
				setState(203);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 108132473915834368L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 134217731L) != 0)) {
					{
					setState(202);
					constant_value_list();
					}
				}

				setState(205);
				match(RBRACE);
				}
				break;
			case ADD:
				{
				setState(206);
				match(ADD);
				setState(207);
				const_expr(5);
				}
				break;
			case SUB:
				{
				setState(208);
				match(SUB);
				setState(209);
				const_expr(4);
				}
				break;
			case BANG:
				{
				setState(210);
				match(BANG);
				setState(211);
				const_expr(3);
				}
				break;
			case TILDE:
				{
				setState(212);
				match(TILDE);
				setState(213);
				const_expr(2);
				}
				break;
			case LPAREN:
				{
				setState(214);
				match(LPAREN);
				setState(215);
				const_expr(0);
				setState(216);
				match(RPAREN);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(276);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(274);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
					case 1:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(220);
						if (!(precpred(_ctx, 23))) throw new FailedPredicateException(this, "precpred(_ctx, 23)");
						setState(221);
						match(LOGICAL_OR);
						setState(222);
						const_expr(24);
						}
						break;
					case 2:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(223);
						if (!(precpred(_ctx, 22))) throw new FailedPredicateException(this, "precpred(_ctx, 22)");
						setState(224);
						match(LOGICAL_AND);
						setState(225);
						const_expr(23);
						}
						break;
					case 3:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(226);
						if (!(precpred(_ctx, 21))) throw new FailedPredicateException(this, "precpred(_ctx, 21)");
						setState(227);
						match(BITOR);
						setState(228);
						const_expr(22);
						}
						break;
					case 4:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(229);
						if (!(precpred(_ctx, 20))) throw new FailedPredicateException(this, "precpred(_ctx, 20)");
						setState(230);
						match(CARET);
						setState(231);
						const_expr(21);
						}
						break;
					case 5:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(232);
						if (!(precpred(_ctx, 19))) throw new FailedPredicateException(this, "precpred(_ctx, 19)");
						setState(233);
						match(BITAND);
						setState(234);
						const_expr(20);
						}
						break;
					case 6:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(235);
						if (!(precpred(_ctx, 18))) throw new FailedPredicateException(this, "precpred(_ctx, 18)");
						setState(236);
						match(EQUALITY);
						setState(237);
						const_expr(19);
						}
						break;
					case 7:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(238);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(239);
						match(NEQ);
						setState(240);
						const_expr(18);
						}
						break;
					case 8:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(241);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(242);
						match(LT);
						setState(243);
						const_expr(17);
						}
						break;
					case 9:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(244);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(245);
						match(GT);
						setState(246);
						const_expr(16);
						}
						break;
					case 10:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(247);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(248);
						match(LEQ);
						setState(249);
						const_expr(15);
						}
						break;
					case 11:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(250);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(251);
						match(GEQ);
						setState(252);
						const_expr(14);
						}
						break;
					case 12:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(253);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(254);
						match(LSHIFT);
						setState(255);
						const_expr(13);
						}
						break;
					case 13:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(256);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(257);
						match(RSHIFT);
						setState(258);
						const_expr(12);
						}
						break;
					case 14:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(259);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(260);
						match(ADD);
						setState(261);
						const_expr(11);
						}
						break;
					case 15:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(262);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(263);
						match(SUB);
						setState(264);
						const_expr(10);
						}
						break;
					case 16:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(265);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(266);
						match(MUL);
						setState(267);
						const_expr(9);
						}
						break;
					case 17:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(268);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(269);
						match(DIV);
						setState(270);
						const_expr(8);
						}
						break;
					case 18:
						{
						_localctx = new Const_exprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_const_expr);
						setState(271);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(272);
						match(MOD);
						setState(273);
						const_expr(7);
						}
						break;
					}
					} 
				}
				setState(278);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Constant_value_listContext extends ParserRuleContext {
		public Constant_value_non_empty_listContext constant_value_non_empty_list() {
			return getRuleContext(Constant_value_non_empty_listContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(AIDLParser.COMMA, 0); }
		public Constant_value_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_value_list; }
	}

	public final Constant_value_listContext constant_value_list() throws RecognitionException {
		Constant_value_listContext _localctx = new Constant_value_listContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_constant_value_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(279);
			constant_value_non_empty_list();
			setState(281);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(280);
				match(COMMA);
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
	public static class Constant_value_non_empty_listContext extends ParserRuleContext {
		public List<Const_exprContext> const_expr() {
			return getRuleContexts(Const_exprContext.class);
		}
		public Const_exprContext const_expr(int i) {
			return getRuleContext(Const_exprContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AIDLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AIDLParser.COMMA, i);
		}
		public Constant_value_non_empty_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_value_non_empty_list; }
	}

	public final Constant_value_non_empty_listContext constant_value_non_empty_list() throws RecognitionException {
		Constant_value_non_empty_listContext _localctx = new Constant_value_non_empty_listContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_constant_value_non_empty_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(283);
			const_expr(0);
			setState(288);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(284);
					match(COMMA);
					setState(285);
					const_expr(0);
					}
					} 
				}
				setState(290);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
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
	public static class Constant_declContext extends ParserRuleContext {
		public Annotation_listContext annotation_list() {
			return getRuleContext(Annotation_listContext.class,0);
		}
		public TerminalNode CONST() { return getToken(AIDLParser.CONST, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(AIDLParser.ASSIGN, 0); }
		public Const_exprContext const_expr() {
			return getRuleContext(Const_exprContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(AIDLParser.SEMI, 0); }
		public Constant_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_decl; }
	}

	public final Constant_declContext constant_decl() throws RecognitionException {
		Constant_declContext _localctx = new Constant_declContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_constant_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(291);
			annotation_list();
			setState(292);
			match(CONST);
			setState(293);
			type();
			setState(294);
			identifier();
			setState(295);
			match(ASSIGN);
			setState(296);
			const_expr(0);
			setState(297);
			match(SEMI);
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
	public static class EnumeratorContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(AIDLParser.ASSIGN, 0); }
		public Const_exprContext const_expr() {
			return getRuleContext(Const_exprContext.class,0);
		}
		public EnumeratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumerator; }
	}

	public final EnumeratorContext enumerator() throws RecognitionException {
		EnumeratorContext _localctx = new EnumeratorContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_enumerator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(299);
			identifier();
			setState(302);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGN) {
				{
				setState(300);
				match(ASSIGN);
				setState(301);
				const_expr(0);
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
	public static class EnumeratorsContext extends ParserRuleContext {
		public List<EnumeratorContext> enumerator() {
			return getRuleContexts(EnumeratorContext.class);
		}
		public EnumeratorContext enumerator(int i) {
			return getRuleContext(EnumeratorContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AIDLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AIDLParser.COMMA, i);
		}
		public EnumeratorsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumerators; }
	}

	public final EnumeratorsContext enumerators() throws RecognitionException {
		EnumeratorsContext _localctx = new EnumeratorsContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_enumerators);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(304);
			enumerator();
			setState(309);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(305);
					match(COMMA);
					setState(306);
					enumerator();
					}
					} 
				}
				setState(311);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
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
	public static class Enum_decl_bodyContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(AIDLParser.LBRACE, 0); }
		public EnumeratorsContext enumerators() {
			return getRuleContext(EnumeratorsContext.class,0);
		}
		public TerminalNode RBRACE() { return getToken(AIDLParser.RBRACE, 0); }
		public TerminalNode COMMA() { return getToken(AIDLParser.COMMA, 0); }
		public Enum_decl_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enum_decl_body; }
	}

	public final Enum_decl_bodyContext enum_decl_body() throws RecognitionException {
		Enum_decl_bodyContext _localctx = new Enum_decl_bodyContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_enum_decl_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(312);
			match(LBRACE);
			setState(313);
			enumerators();
			setState(315);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(314);
				match(COMMA);
				}
			}

			setState(317);
			match(RBRACE);
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
	public static class Enum_declContext extends ParserRuleContext {
		public TerminalNode ENUM() { return getToken(AIDLParser.ENUM, 0); }
		public Qualified_nameContext qualified_name() {
			return getRuleContext(Qualified_nameContext.class,0);
		}
		public Enum_decl_bodyContext enum_decl_body() {
			return getRuleContext(Enum_decl_bodyContext.class,0);
		}
		public Enum_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enum_decl; }
	}

	public final Enum_declContext enum_decl() throws RecognitionException {
		Enum_declContext _localctx = new Enum_declContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_enum_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(319);
			match(ENUM);
			setState(320);
			qualified_name();
			setState(321);
			enum_decl_body();
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
	public static class Union_declContext extends ParserRuleContext {
		public TerminalNode UNION() { return getToken(AIDLParser.UNION, 0); }
		public Qualified_nameContext qualified_name() {
			return getRuleContext(Qualified_nameContext.class,0);
		}
		public TerminalNode LBRACE() { return getToken(AIDLParser.LBRACE, 0); }
		public Parcelable_membersContext parcelable_members() {
			return getRuleContext(Parcelable_membersContext.class,0);
		}
		public TerminalNode RBRACE() { return getToken(AIDLParser.RBRACE, 0); }
		public Optional_type_paramsContext optional_type_params() {
			return getRuleContext(Optional_type_paramsContext.class,0);
		}
		public Union_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_union_decl; }
	}

	public final Union_declContext union_decl() throws RecognitionException {
		Union_declContext _localctx = new Union_declContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_union_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(323);
			match(UNION);
			setState(324);
			qualified_name();
			setState(326);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(325);
				optional_type_params();
				}
			}

			setState(328);
			match(LBRACE);
			setState(329);
			parcelable_members();
			setState(330);
			match(RBRACE);
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
	public static class Method_declContext extends ParserRuleContext {
		public Annotation_listContext annotation_list() {
			return getRuleContext(Annotation_listContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(AIDLParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(AIDLParser.RPAREN, 0); }
		public TerminalNode SEMI() { return getToken(AIDLParser.SEMI, 0); }
		public TerminalNode ONEWAY() { return getToken(AIDLParser.ONEWAY, 0); }
		public Arg_non_empty_listContext arg_non_empty_list() {
			return getRuleContext(Arg_non_empty_listContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(AIDLParser.ASSIGN, 0); }
		public TerminalNode INTVALUE() { return getToken(AIDLParser.INTVALUE, 0); }
		public Method_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_method_decl; }
	}

	public final Method_declContext method_decl() throws RecognitionException {
		Method_declContext _localctx = new Method_declContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_method_decl);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(332);
			annotation_list();
			setState(334);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ONEWAY) {
				{
				setState(333);
				match(ONEWAY);
				}
			}

			setState(336);
			type();
			setState(337);
			identifier();
			setState(338);
			match(LPAREN);
			setState(340);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 16203776L) != 0) || _la==IDENTIFIER) {
				{
				setState(339);
				arg_non_empty_list();
				}
			}

			setState(342);
			match(RPAREN);
			setState(345);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGN) {
				{
				setState(343);
				match(ASSIGN);
				setState(344);
				match(INTVALUE);
				}
			}

			setState(347);
			match(SEMI);
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
	public static class Arg_non_empty_listContext extends ParserRuleContext {
		public List<ArgContext> arg() {
			return getRuleContexts(ArgContext.class);
		}
		public ArgContext arg(int i) {
			return getRuleContext(ArgContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AIDLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AIDLParser.COMMA, i);
		}
		public Arg_non_empty_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arg_non_empty_list; }
	}

	public final Arg_non_empty_listContext arg_non_empty_list() throws RecognitionException {
		Arg_non_empty_listContext _localctx = new Arg_non_empty_listContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_arg_non_empty_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(349);
			arg();
			setState(354);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(350);
				match(COMMA);
				setState(351);
				arg();
				}
				}
				setState(356);
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
	public static class ArgContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public DirectionContext direction() {
			return getRuleContext(DirectionContext.class,0);
		}
		public ArgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arg; }
	}

	public final ArgContext arg() throws RecognitionException {
		ArgContext _localctx = new ArgContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_arg);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(358);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 458752L) != 0)) {
				{
				setState(357);
				direction();
				}
			}

			setState(360);
			type();
			setState(361);
			identifier();
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
	public static class Non_array_typeContext extends ParserRuleContext {
		public Annotation_listContext annotation_list() {
			return getRuleContext(Annotation_listContext.class,0);
		}
		public Qualified_nameContext qualified_name() {
			return getRuleContext(Qualified_nameContext.class,0);
		}
		public List<TerminalNode> LT() { return getTokens(AIDLParser.LT); }
		public TerminalNode LT(int i) {
			return getToken(AIDLParser.LT, i);
		}
		public List<Type_argsContext> type_args() {
			return getRuleContexts(Type_argsContext.class);
		}
		public Type_argsContext type_args(int i) {
			return getRuleContext(Type_argsContext.class,i);
		}
		public List<TerminalNode> GT() { return getTokens(AIDLParser.GT); }
		public TerminalNode GT(int i) {
			return getToken(AIDLParser.GT, i);
		}
		public List<Non_array_typeContext> non_array_type() {
			return getRuleContexts(Non_array_typeContext.class);
		}
		public Non_array_typeContext non_array_type(int i) {
			return getRuleContext(Non_array_typeContext.class,i);
		}
		public List<TerminalNode> RSHIFT() { return getTokens(AIDLParser.RSHIFT); }
		public TerminalNode RSHIFT(int i) {
			return getToken(AIDLParser.RSHIFT, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AIDLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AIDLParser.COMMA, i);
		}
		public Non_array_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_non_array_type; }
	}

	public final Non_array_typeContext non_array_type() throws RecognitionException {
		Non_array_typeContext _localctx = new Non_array_typeContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_non_array_type);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(363);
			annotation_list();
			setState(364);
			qualified_name();
			setState(385);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					setState(383);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,33,_ctx) ) {
					case 1:
						{
						{
						setState(365);
						match(LT);
						setState(366);
						type_args();
						setState(367);
						match(GT);
						}
						}
						break;
					case 2:
						{
						{
						setState(369);
						match(LT);
						setState(370);
						non_array_type();
						setState(371);
						match(LT);
						setState(372);
						type_args();
						setState(373);
						match(RSHIFT);
						}
						}
						break;
					case 3:
						{
						{
						setState(375);
						match(LT);
						setState(376);
						type_args();
						setState(377);
						match(COMMA);
						setState(378);
						non_array_type();
						setState(379);
						match(LT);
						setState(380);
						type_args();
						setState(381);
						match(RSHIFT);
						}
						}
						break;
					}
					} 
				}
				setState(387);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,34,_ctx);
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
	public static class TypeContext extends ParserRuleContext {
		public Non_array_typeContext non_array_type() {
			return getRuleContext(Non_array_typeContext.class,0);
		}
		public List<Annotation_listContext> annotation_list() {
			return getRuleContexts(Annotation_listContext.class);
		}
		public Annotation_listContext annotation_list(int i) {
			return getRuleContext(Annotation_listContext.class,i);
		}
		public List<TerminalNode> LBRACK() { return getTokens(AIDLParser.LBRACK); }
		public TerminalNode LBRACK(int i) {
			return getToken(AIDLParser.LBRACK, i);
		}
		public List<TerminalNode> RBRACK() { return getTokens(AIDLParser.RBRACK); }
		public TerminalNode RBRACK(int i) {
			return getToken(AIDLParser.RBRACK, i);
		}
		public List<Const_exprContext> const_expr() {
			return getRuleContexts(Const_exprContext.class);
		}
		public Const_exprContext const_expr(int i) {
			return getRuleContext(Const_exprContext.class,i);
		}
		public TerminalNode VOID() { return getToken(AIDLParser.VOID, 0); }
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_type);
		int _la;
		try {
			setState(404);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CPP_HEADER:
			case NDK_HEADER:
			case RUST_TYPE:
			case ANNOTATION:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(388);
				non_array_type();
				setState(400);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==ANNOTATION || _la==LBRACK) {
					{
					setState(398);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,35,_ctx) ) {
					case 1:
						{
						{
						setState(389);
						annotation_list();
						setState(390);
						match(LBRACK);
						setState(391);
						match(RBRACK);
						}
						}
						break;
					case 2:
						{
						{
						setState(393);
						annotation_list();
						setState(394);
						match(LBRACK);
						setState(395);
						const_expr(0);
						setState(396);
						match(RBRACK);
						}
						}
						break;
					}
					}
					setState(402);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 2);
				{
				setState(403);
				match(VOID);
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
	public static class Type_argsContext extends ParserRuleContext {
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AIDLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AIDLParser.COMMA, i);
		}
		public Type_argsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_args; }
	}

	public final Type_argsContext type_args() throws RecognitionException {
		Type_argsContext _localctx = new Type_argsContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_type_args);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(406);
			type();
			setState(411);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(407);
					match(COMMA);
					setState(408);
					type();
					}
					} 
				}
				setState(413);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
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
	public static class Annotation_listContext extends ParserRuleContext {
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public Annotation_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotation_list; }
	}

	public final Annotation_listContext annotation_list() throws RecognitionException {
		Annotation_listContext _localctx = new Annotation_listContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_annotation_list);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(417);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,39,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(414);
					annotation();
					}
					} 
				}
				setState(419);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,39,_ctx);
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
	public static class ParameterContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(AIDLParser.ASSIGN, 0); }
		public Const_exprContext const_expr() {
			return getRuleContext(Const_exprContext.class,0);
		}
		public ParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter; }
	}

	public final ParameterContext parameter() throws RecognitionException {
		ParameterContext _localctx = new ParameterContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_parameter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(420);
			identifier();
			setState(421);
			match(ASSIGN);
			setState(422);
			const_expr(0);
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
	public static class Parameter_non_empty_listContext extends ParserRuleContext {
		public List<ParameterContext> parameter() {
			return getRuleContexts(ParameterContext.class);
		}
		public ParameterContext parameter(int i) {
			return getRuleContext(ParameterContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AIDLParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AIDLParser.COMMA, i);
		}
		public Parameter_non_empty_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_non_empty_list; }
	}

	public final Parameter_non_empty_listContext parameter_non_empty_list() throws RecognitionException {
		Parameter_non_empty_listContext _localctx = new Parameter_non_empty_listContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_parameter_non_empty_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(424);
			parameter();
			setState(429);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(425);
				match(COMMA);
				setState(426);
				parameter();
				}
				}
				setState(431);
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
	public static class AnnotationContext extends ParserRuleContext {
		public TerminalNode ANNOTATION() { return getToken(AIDLParser.ANNOTATION, 0); }
		public TerminalNode LPAREN() { return getToken(AIDLParser.LPAREN, 0); }
		public Const_exprContext const_expr() {
			return getRuleContext(Const_exprContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(AIDLParser.RPAREN, 0); }
		public Parameter_non_empty_listContext parameter_non_empty_list() {
			return getRuleContext(Parameter_non_empty_listContext.class,0);
		}
		public AnnotationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotation; }
	}

	public final AnnotationContext annotation() throws RecognitionException {
		AnnotationContext _localctx = new AnnotationContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_annotation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(432);
			match(ANNOTATION);
			setState(442);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,42,_ctx) ) {
			case 1:
				{
				{
				setState(433);
				match(LPAREN);
				setState(434);
				const_expr(0);
				setState(435);
				match(RPAREN);
				}
				}
				break;
			case 2:
				{
				{
				setState(437);
				match(LPAREN);
				setState(439);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 7340032L) != 0) || _la==IDENTIFIER) {
					{
					setState(438);
					parameter_non_empty_list();
					}
				}

				setState(441);
				match(RPAREN);
				}
				}
				break;
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
	public static class DirectionContext extends ParserRuleContext {
		public TerminalNode IN() { return getToken(AIDLParser.IN, 0); }
		public TerminalNode OUT() { return getToken(AIDLParser.OUT, 0); }
		public TerminalNode INOUT() { return getToken(AIDLParser.INOUT, 0); }
		public DirectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_direction; }
	}

	public final DirectionContext direction() throws RecognitionException {
		DirectionContext _localctx = new DirectionContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_direction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(444);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 458752L) != 0)) ) {
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 17:
			return const_expr_sempred((Const_exprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean const_expr_sempred(Const_exprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 23);
		case 1:
			return precpred(_ctx, 22);
		case 2:
			return precpred(_ctx, 21);
		case 3:
			return precpred(_ctx, 20);
		case 4:
			return precpred(_ctx, 19);
		case 5:
			return precpred(_ctx, 18);
		case 6:
			return precpred(_ctx, 17);
		case 7:
			return precpred(_ctx, 16);
		case 8:
			return precpred(_ctx, 15);
		case 9:
			return precpred(_ctx, 14);
		case 10:
			return precpred(_ctx, 13);
		case 11:
			return precpred(_ctx, 12);
		case 12:
			return precpred(_ctx, 11);
		case 13:
			return precpred(_ctx, 10);
		case 14:
			return precpred(_ctx, 9);
		case 15:
			return precpred(_ctx, 8);
		case 16:
			return precpred(_ctx, 7);
		case 17:
			return precpred(_ctx, 6);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001^\u01bf\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002\u001e\u0007\u001e"+
		"\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007!\u0002\"\u0007\"\u0002"+
		"#\u0007#\u0002$\u0007$\u0001\u0000\u0003\u0000L\b\u0000\u0001\u0000\u0003"+
		"\u0000O\b\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0004\u0003Z\b"+
		"\u0003\u000b\u0003\f\u0003[\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005e\b\u0005\n\u0005"+
		"\f\u0005h\t\u0005\u0001\u0006\u0004\u0006k\b\u0006\u000b\u0006\f\u0006"+
		"l\u0001\u0007\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001\b"+
		"\u0003\bv\b\b\u0001\t\u0001\t\u0001\t\u0005\t{\b\t\n\t\f\t~\t\t\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0005\u000b\u008a\b\u000b\n\u000b\f\u000b\u008d"+
		"\t\u000b\u0001\f\u0001\f\u0001\f\u0003\f\u0092\b\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003\f\u009b\b\f\u0001\r\u0001\r\u0001"+
		"\r\u0005\r\u00a0\b\r\n\r\f\r\u00a3\t\r\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0003\u000e\u00a9\b\u000e\u0001\u000e\u0001\u000e\u0001\u000f"+
		"\u0003\u000f\u00ae\b\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u00b7\b\u000f\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0005\u0010\u00bc\b\u0010\n\u0010\f\u0010\u00bf"+
		"\t\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0003"+
		"\u0011\u00cc\b\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u00db\b\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0005\u0011\u0113"+
		"\b\u0011\n\u0011\f\u0011\u0116\t\u0011\u0001\u0012\u0001\u0012\u0003\u0012"+
		"\u011a\b\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0005\u0013\u011f\b"+
		"\u0013\n\u0013\f\u0013\u0122\t\u0013\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0003\u0015\u012f\b\u0015\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0005\u0016\u0134\b\u0016\n\u0016\f\u0016\u0137\t\u0016\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0003\u0017\u013c\b\u0017\u0001\u0017\u0001"+
		"\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0003\u0019\u0147\b\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u0019\u0001\u001a\u0001\u001a\u0003\u001a\u014f\b\u001a\u0001"+
		"\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0003\u001a\u0155\b\u001a\u0001"+
		"\u001a\u0001\u001a\u0001\u001a\u0003\u001a\u015a\b\u001a\u0001\u001a\u0001"+
		"\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0005\u001b\u0161\b\u001b\n"+
		"\u001b\f\u001b\u0164\t\u001b\u0001\u001c\u0003\u001c\u0167\b\u001c\u0001"+
		"\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0001\u001d\u0005\u001d\u0180"+
		"\b\u001d\n\u001d\f\u001d\u0183\t\u001d\u0001\u001e\u0001\u001e\u0001\u001e"+
		"\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e"+
		"\u0001\u001e\u0005\u001e\u018f\b\u001e\n\u001e\f\u001e\u0192\t\u001e\u0001"+
		"\u001e\u0003\u001e\u0195\b\u001e\u0001\u001f\u0001\u001f\u0001\u001f\u0005"+
		"\u001f\u019a\b\u001f\n\u001f\f\u001f\u019d\t\u001f\u0001 \u0005 \u01a0"+
		"\b \n \f \u01a3\t \u0001!\u0001!\u0001!\u0001!\u0001\"\u0001\"\u0001\""+
		"\u0005\"\u01ac\b\"\n\"\f\"\u01af\t\"\u0001#\u0001#\u0001#\u0001#\u0001"+
		"#\u0001#\u0001#\u0003#\u01b8\b#\u0001#\u0003#\u01bb\b#\u0001$\u0001$\u0001"+
		"$\u0000\u0001\"%\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014"+
		"\u0016\u0018\u001a\u001c\u001e \"$&(*,.02468:<>@BDFH\u0000\u0002\u0002"+
		"\u0000\u0014\u0016^^\u0001\u0000\u0010\u0012\u01e7\u0000K\u0001\u0000"+
		"\u0000\u0000\u0002R\u0001\u0000\u0000\u0000\u0004T\u0001\u0000\u0000\u0000"+
		"\u0006Y\u0001\u0000\u0000\u0000\b]\u0001\u0000\u0000\u0000\na\u0001\u0000"+
		"\u0000\u0000\fj\u0001\u0000\u0000\u0000\u000en\u0001\u0000\u0000\u0000"+
		"\u0010u\u0001\u0000\u0000\u0000\u0012w\u0001\u0000\u0000\u0000\u0014\u007f"+
		"\u0001\u0000\u0000\u0000\u0016\u008b\u0001\u0000\u0000\u0000\u0018\u008e"+
		"\u0001\u0000\u0000\u0000\u001a\u00a1\u0001\u0000\u0000\u0000\u001c\u00a4"+
		"\u0001\u0000\u0000\u0000\u001e\u00ad\u0001\u0000\u0000\u0000 \u00bd\u0001"+
		"\u0000\u0000\u0000\"\u00da\u0001\u0000\u0000\u0000$\u0117\u0001\u0000"+
		"\u0000\u0000&\u011b\u0001\u0000\u0000\u0000(\u0123\u0001\u0000\u0000\u0000"+
		"*\u012b\u0001\u0000\u0000\u0000,\u0130\u0001\u0000\u0000\u0000.\u0138"+
		"\u0001\u0000\u0000\u00000\u013f\u0001\u0000\u0000\u00002\u0143\u0001\u0000"+
		"\u0000\u00004\u014c\u0001\u0000\u0000\u00006\u015d\u0001\u0000\u0000\u0000"+
		"8\u0166\u0001\u0000\u0000\u0000:\u016b\u0001\u0000\u0000\u0000<\u0194"+
		"\u0001\u0000\u0000\u0000>\u0196\u0001\u0000\u0000\u0000@\u01a1\u0001\u0000"+
		"\u0000\u0000B\u01a4\u0001\u0000\u0000\u0000D\u01a8\u0001\u0000\u0000\u0000"+
		"F\u01b0\u0001\u0000\u0000\u0000H\u01bc\u0001\u0000\u0000\u0000JL\u0003"+
		"\u0004\u0002\u0000KJ\u0001\u0000\u0000\u0000KL\u0001\u0000\u0000\u0000"+
		"LN\u0001\u0000\u0000\u0000MO\u0003\u0006\u0003\u0000NM\u0001\u0000\u0000"+
		"\u0000NO\u0001\u0000\u0000\u0000OP\u0001\u0000\u0000\u0000PQ\u0003\f\u0006"+
		"\u0000Q\u0001\u0001\u0000\u0000\u0000RS\u0007\u0000\u0000\u0000S\u0003"+
		"\u0001\u0000\u0000\u0000TU\u0005\b\u0000\u0000UV\u0003\n\u0005\u0000V"+
		"W\u00051\u0000\u0000W\u0005\u0001\u0000\u0000\u0000XZ\u0003\b\u0004\u0000"+
		"YX\u0001\u0000\u0000\u0000Z[\u0001\u0000\u0000\u0000[Y\u0001\u0000\u0000"+
		"\u0000[\\\u0001\u0000\u0000\u0000\\\u0007\u0001\u0000\u0000\u0000]^\u0005"+
		"\u0006\u0000\u0000^_\u0003\n\u0005\u0000_`\u00051\u0000\u0000`\t\u0001"+
		"\u0000\u0000\u0000af\u0003\u0002\u0001\u0000bc\u00053\u0000\u0000ce\u0003"+
		"\u0002\u0001\u0000db\u0001\u0000\u0000\u0000eh\u0001\u0000\u0000\u0000"+
		"fd\u0001\u0000\u0000\u0000fg\u0001\u0000\u0000\u0000g\u000b\u0001\u0000"+
		"\u0000\u0000hf\u0001\u0000\u0000\u0000ik\u0003\u000e\u0007\u0000ji\u0001"+
		"\u0000\u0000\u0000kl\u0001\u0000\u0000\u0000lj\u0001\u0000\u0000\u0000"+
		"lm\u0001\u0000\u0000\u0000m\r\u0001\u0000\u0000\u0000no\u0003@ \u0000"+
		"op\u0003\u0010\b\u0000p\u000f\u0001\u0000\u0000\u0000qv\u0003\u0018\f"+
		"\u0000rv\u0003\u001e\u000f\u0000sv\u00030\u0018\u0000tv\u00032\u0019\u0000"+
		"uq\u0001\u0000\u0000\u0000ur\u0001\u0000\u0000\u0000us\u0001\u0000\u0000"+
		"\u0000ut\u0001\u0000\u0000\u0000v\u0011\u0001\u0000\u0000\u0000w|\u0003"+
		"\u0002\u0001\u0000xy\u00052\u0000\u0000y{\u0003\u0002\u0001\u0000zx\u0001"+
		"\u0000\u0000\u0000{~\u0001\u0000\u0000\u0000|z\u0001\u0000\u0000\u0000"+
		"|}\u0001\u0000\u0000\u0000}\u0013\u0001\u0000\u0000\u0000~|\u0001\u0000"+
		"\u0000\u0000\u007f\u0080\u00056\u0000\u0000\u0080\u0081\u0003\u0012\t"+
		"\u0000\u0081\u0082\u00055\u0000\u0000\u0082\u0015\u0001\u0000\u0000\u0000"+
		"\u0083\u0084\u0005\u0014\u0000\u0000\u0084\u008a\u0005(\u0000\u0000\u0085"+
		"\u0086\u0005\u0015\u0000\u0000\u0086\u008a\u0005(\u0000\u0000\u0087\u0088"+
		"\u0005\u0016\u0000\u0000\u0088\u008a\u0005(\u0000\u0000\u0089\u0083\u0001"+
		"\u0000\u0000\u0000\u0089\u0085\u0001\u0000\u0000\u0000\u0089\u0087\u0001"+
		"\u0000\u0000\u0000\u008a\u008d\u0001\u0000\u0000\u0000\u008b\u0089\u0001"+
		"\u0000\u0000\u0000\u008b\u008c\u0001\u0000\u0000\u0000\u008c\u0017\u0001"+
		"\u0000\u0000\u0000\u008d\u008b\u0001\u0000\u0000\u0000\u008e\u008f\u0005"+
		"\u000f\u0000\u0000\u008f\u0091\u0003\n\u0005\u0000\u0090\u0092\u0003\u0014"+
		"\n\u0000\u0091\u0090\u0001\u0000\u0000\u0000\u0091\u0092\u0001\u0000\u0000"+
		"\u0000\u0092\u009a\u0001\u0000\u0000\u0000\u0093\u0094\u0003\u0016\u000b"+
		"\u0000\u0094\u0095\u00051\u0000\u0000\u0095\u009b\u0001\u0000\u0000\u0000"+
		"\u0096\u0097\u0005-\u0000\u0000\u0097\u0098\u0003\u001a\r\u0000\u0098"+
		"\u0099\u0005.\u0000\u0000\u0099\u009b\u0001\u0000\u0000\u0000\u009a\u0093"+
		"\u0001\u0000\u0000\u0000\u009a\u0096\u0001\u0000\u0000\u0000\u009b\u0019"+
		"\u0001\u0000\u0000\u0000\u009c\u00a0\u0003\u001c\u000e\u0000\u009d\u00a0"+
		"\u0003(\u0014\u0000\u009e\u00a0\u0003\u000e\u0007\u0000\u009f\u009c\u0001"+
		"\u0000\u0000\u0000\u009f\u009d\u0001\u0000\u0000\u0000\u009f\u009e\u0001"+
		"\u0000\u0000\u0000\u00a0\u00a3\u0001\u0000\u0000\u0000\u00a1\u009f\u0001"+
		"\u0000\u0000\u0000\u00a1\u00a2\u0001\u0000\u0000\u0000\u00a2\u001b\u0001"+
		"\u0000\u0000\u0000\u00a3\u00a1\u0001\u0000\u0000\u0000\u00a4\u00a5\u0003"+
		"<\u001e\u0000\u00a5\u00a8\u0003\u0002\u0001\u0000\u00a6\u00a7\u00054\u0000"+
		"\u0000\u00a7\u00a9\u0003\"\u0011\u0000\u00a8\u00a6\u0001\u0000\u0000\u0000"+
		"\u00a8\u00a9\u0001\u0000\u0000\u0000\u00a9\u00aa\u0001\u0000\u0000\u0000"+
		"\u00aa\u00ab\u00051\u0000\u0000\u00ab\u001d\u0001\u0000\u0000\u0000\u00ac"+
		"\u00ae\u0005\u0013\u0000\u0000\u00ad\u00ac\u0001\u0000\u0000\u0000\u00ad"+
		"\u00ae\u0001\u0000\u0000\u0000\u00ae\u00af\u0001\u0000\u0000\u0000\u00af"+
		"\u00b0\u0005\u0007\u0000\u0000\u00b0\u00b6\u0003\n\u0005\u0000\u00b1\u00b7"+
		"\u00051\u0000\u0000\u00b2\u00b3\u0005-\u0000\u0000\u00b3\u00b4\u0003 "+
		"\u0010\u0000\u00b4\u00b5\u0005.\u0000\u0000\u00b5\u00b7\u0001\u0000\u0000"+
		"\u0000\u00b6\u00b1\u0001\u0000\u0000\u0000\u00b6\u00b2\u0001\u0000\u0000"+
		"\u0000\u00b7\u001f\u0001\u0000\u0000\u0000\u00b8\u00bc\u00034\u001a\u0000"+
		"\u00b9\u00bc\u0003(\u0014\u0000\u00ba\u00bc\u0003\u000e\u0007\u0000\u00bb"+
		"\u00b8\u0001\u0000\u0000\u0000\u00bb\u00b9\u0001\u0000\u0000\u0000\u00bb"+
		"\u00ba\u0001\u0000\u0000\u0000\u00bc\u00bf\u0001\u0000\u0000\u0000\u00bd"+
		"\u00bb\u0001\u0000\u0000\u0000\u00bd\u00be\u0001\u0000\u0000\u0000\u00be"+
		"!\u0001\u0000\u0000\u0000\u00bf\u00bd\u0001\u0000\u0000\u0000\u00c0\u00c1"+
		"\u0006\u0011\uffff\uffff\u0000\u00c1\u00db\u0005%\u0000\u0000\u00c2\u00db"+
		"\u0005&\u0000\u0000\u00c3\u00db\u0005\'\u0000\u0000\u00c4\u00db\u0005"+
		"\u001f\u0000\u0000\u00c5\u00db\u0005#\u0000\u0000\u00c6\u00db\u0005 \u0000"+
		"\u0000\u00c7\u00db\u0005(\u0000\u0000\u00c8\u00db\u0003\n\u0005\u0000"+
		"\u00c9\u00cb\u0005-\u0000\u0000\u00ca\u00cc\u0003$\u0012\u0000\u00cb\u00ca"+
		"\u0001\u0000\u0000\u0000\u00cb\u00cc\u0001\u0000\u0000\u0000\u00cc\u00cd"+
		"\u0001\u0000\u0000\u0000\u00cd\u00db\u0005.\u0000\u0000\u00ce\u00cf\u0005"+
		"C\u0000\u0000\u00cf\u00db\u0003\"\u0011\u0005\u00d0\u00d1\u0005D\u0000"+
		"\u0000\u00d1\u00db\u0003\"\u0011\u0004\u00d2\u00d3\u00057\u0000\u0000"+
		"\u00d3\u00db\u0003\"\u0011\u0003\u00d4\u00d5\u00058\u0000\u0000\u00d5"+
		"\u00db\u0003\"\u0011\u0002\u00d6\u00d7\u0005+\u0000\u0000\u00d7\u00d8"+
		"\u0003\"\u0011\u0000\u00d8\u00d9\u0005,\u0000\u0000\u00d9\u00db\u0001"+
		"\u0000\u0000\u0000\u00da\u00c0\u0001\u0000\u0000\u0000\u00da\u00c2\u0001"+
		"\u0000\u0000\u0000\u00da\u00c3\u0001\u0000\u0000\u0000\u00da\u00c4\u0001"+
		"\u0000\u0000\u0000\u00da\u00c5\u0001\u0000\u0000\u0000\u00da\u00c6\u0001"+
		"\u0000\u0000\u0000\u00da\u00c7\u0001\u0000\u0000\u0000\u00da\u00c8\u0001"+
		"\u0000\u0000\u0000\u00da\u00c9\u0001\u0000\u0000\u0000\u00da\u00ce\u0001"+
		"\u0000\u0000\u0000\u00da\u00d0\u0001\u0000\u0000\u0000\u00da\u00d2\u0001"+
		"\u0000\u0000\u0000\u00da\u00d4\u0001\u0000\u0000\u0000\u00da\u00d6\u0001"+
		"\u0000\u0000\u0000\u00db\u0114\u0001\u0000\u0000\u0000\u00dc\u00dd\n\u0017"+
		"\u0000\u0000\u00dd\u00de\u0005@\u0000\u0000\u00de\u0113\u0003\"\u0011"+
		"\u0018\u00df\u00e0\n\u0016\u0000\u0000\u00e0\u00e1\u0005?\u0000\u0000"+
		"\u00e1\u0113\u0003\"\u0011\u0017\u00e2\u00e3\n\u0015\u0000\u0000\u00e3"+
		"\u00e4\u0005H\u0000\u0000\u00e4\u0113\u0003\"\u0011\u0016\u00e5\u00e6"+
		"\n\u0014\u0000\u0000\u00e6\u00e7\u0005I\u0000\u0000\u00e7\u0113\u0003"+
		"\"\u0011\u0015\u00e8\u00e9\n\u0013\u0000\u0000\u00e9\u00ea\u0005G\u0000"+
		"\u0000\u00ea\u0113\u0003\"\u0011\u0014\u00eb\u00ec\n\u0012\u0000\u0000"+
		"\u00ec\u00ed\u0005;\u0000\u0000\u00ed\u0113\u0003\"\u0011\u0013\u00ee"+
		"\u00ef\n\u0011\u0000\u0000\u00ef\u00f0\u0005>\u0000\u0000\u00f0\u0113"+
		"\u0003\"\u0011\u0012\u00f1\u00f2\n\u0010\u0000\u0000\u00f2\u00f3\u0005"+
		"6\u0000\u0000\u00f3\u0113\u0003\"\u0011\u0011\u00f4\u00f5\n\u000f\u0000"+
		"\u0000\u00f5\u00f6\u00055\u0000\u0000\u00f6\u0113\u0003\"\u0011\u0010"+
		"\u00f7\u00f8\n\u000e\u0000\u0000\u00f8\u00f9\u0005<\u0000\u0000\u00f9"+
		"\u0113\u0003\"\u0011\u000f\u00fa\u00fb\n\r\u0000\u0000\u00fb\u00fc\u0005"+
		"=\u0000\u0000\u00fc\u0113\u0003\"\u0011\u000e\u00fd\u00fe\n\f\u0000\u0000"+
		"\u00fe\u00ff\u0005K\u0000\u0000\u00ff\u0113\u0003\"\u0011\r\u0100\u0101"+
		"\n\u000b\u0000\u0000\u0101\u0102\u0005L\u0000\u0000\u0102\u0113\u0003"+
		"\"\u0011\f\u0103\u0104\n\n\u0000\u0000\u0104\u0105\u0005C\u0000\u0000"+
		"\u0105\u0113\u0003\"\u0011\u000b\u0106\u0107\n\t\u0000\u0000\u0107\u0108"+
		"\u0005D\u0000\u0000\u0108\u0113\u0003\"\u0011\n\u0109\u010a\n\b\u0000"+
		"\u0000\u010a\u010b\u0005E\u0000\u0000\u010b\u0113\u0003\"\u0011\t\u010c"+
		"\u010d\n\u0007\u0000\u0000\u010d\u010e\u0005F\u0000\u0000\u010e\u0113"+
		"\u0003\"\u0011\b\u010f\u0110\n\u0006\u0000\u0000\u0110\u0111\u0005J\u0000"+
		"\u0000\u0111\u0113\u0003\"\u0011\u0007\u0112\u00dc\u0001\u0000\u0000\u0000"+
		"\u0112\u00df\u0001\u0000\u0000\u0000\u0112\u00e2\u0001\u0000\u0000\u0000"+
		"\u0112\u00e5\u0001\u0000\u0000\u0000\u0112\u00e8\u0001\u0000\u0000\u0000"+
		"\u0112\u00eb\u0001\u0000\u0000\u0000\u0112\u00ee\u0001\u0000\u0000\u0000"+
		"\u0112\u00f1\u0001\u0000\u0000\u0000\u0112\u00f4\u0001\u0000\u0000\u0000"+
		"\u0112\u00f7\u0001\u0000\u0000\u0000\u0112\u00fa\u0001\u0000\u0000\u0000"+
		"\u0112\u00fd\u0001\u0000\u0000\u0000\u0112\u0100\u0001\u0000\u0000\u0000"+
		"\u0112\u0103\u0001\u0000\u0000\u0000\u0112\u0106\u0001\u0000\u0000\u0000"+
		"\u0112\u0109\u0001\u0000\u0000\u0000\u0112\u010c\u0001\u0000\u0000\u0000"+
		"\u0112\u010f\u0001\u0000\u0000\u0000\u0113\u0116\u0001\u0000\u0000\u0000"+
		"\u0114\u0112\u0001\u0000\u0000\u0000\u0114\u0115\u0001\u0000\u0000\u0000"+
		"\u0115#\u0001\u0000\u0000\u0000\u0116\u0114\u0001\u0000\u0000\u0000\u0117"+
		"\u0119\u0003&\u0013\u0000\u0118\u011a\u00052\u0000\u0000\u0119\u0118\u0001"+
		"\u0000\u0000\u0000\u0119\u011a\u0001\u0000\u0000\u0000\u011a%\u0001\u0000"+
		"\u0000\u0000\u011b\u0120\u0003\"\u0011\u0000\u011c\u011d\u00052\u0000"+
		"\u0000\u011d\u011f\u0003\"\u0011\u0000\u011e\u011c\u0001\u0000\u0000\u0000"+
		"\u011f\u0122\u0001\u0000\u0000\u0000\u0120\u011e\u0001\u0000\u0000\u0000"+
		"\u0120\u0121\u0001\u0000\u0000\u0000\u0121\'\u0001\u0000\u0000\u0000\u0122"+
		"\u0120\u0001\u0000\u0000\u0000\u0123\u0124\u0003@ \u0000\u0124\u0125\u0005"+
		"\u0002\u0000\u0000\u0125\u0126\u0003<\u001e\u0000\u0126\u0127\u0003\u0002"+
		"\u0001\u0000\u0127\u0128\u00054\u0000\u0000\u0128\u0129\u0003\"\u0011"+
		"\u0000\u0129\u012a\u00051\u0000\u0000\u012a)\u0001\u0000\u0000\u0000\u012b"+
		"\u012e\u0003\u0002\u0001\u0000\u012c\u012d\u00054\u0000\u0000\u012d\u012f"+
		"\u0003\"\u0011\u0000\u012e\u012c\u0001\u0000\u0000\u0000\u012e\u012f\u0001"+
		"\u0000\u0000\u0000\u012f+\u0001\u0000\u0000\u0000\u0130\u0135\u0003*\u0015"+
		"\u0000\u0131\u0132\u00052\u0000\u0000\u0132\u0134\u0003*\u0015\u0000\u0133"+
		"\u0131\u0001\u0000\u0000\u0000\u0134\u0137\u0001\u0000\u0000\u0000\u0135"+
		"\u0133\u0001\u0000\u0000\u0000\u0135\u0136\u0001\u0000\u0000\u0000\u0136"+
		"-\u0001\u0000\u0000\u0000\u0137\u0135\u0001\u0000\u0000\u0000\u0138\u0139"+
		"\u0005-\u0000\u0000\u0139\u013b\u0003,\u0016\u0000\u013a\u013c\u00052"+
		"\u0000\u0000\u013b\u013a\u0001\u0000\u0000\u0000\u013b\u013c\u0001\u0000"+
		"\u0000\u0000\u013c\u013d\u0001\u0000\u0000\u0000\u013d\u013e\u0005.\u0000"+
		"\u0000\u013e/\u0001\u0000\u0000\u0000\u013f\u0140\u0005\u0003\u0000\u0000"+
		"\u0140\u0141\u0003\n\u0005\u0000\u0141\u0142\u0003.\u0017\u0000\u0142"+
		"1\u0001\u0000\u0000\u0000\u0143\u0144\u0005\u0018\u0000\u0000\u0144\u0146"+
		"\u0003\n\u0005\u0000\u0145\u0147\u0003\u0014\n\u0000\u0146\u0145\u0001"+
		"\u0000\u0000\u0000\u0146\u0147\u0001\u0000\u0000\u0000\u0147\u0148\u0001"+
		"\u0000\u0000\u0000\u0148\u0149\u0005-\u0000\u0000\u0149\u014a\u0003\u001a"+
		"\r\u0000\u014a\u014b\u0005.\u0000\u0000\u014b3\u0001\u0000\u0000\u0000"+
		"\u014c\u014e\u0003@ \u0000\u014d\u014f\u0005\u0013\u0000\u0000\u014e\u014d"+
		"\u0001\u0000\u0000\u0000\u014e\u014f\u0001\u0000\u0000\u0000\u014f\u0150"+
		"\u0001\u0000\u0000\u0000\u0150\u0151\u0003<\u001e\u0000\u0151\u0152\u0003"+
		"\u0002\u0001\u0000\u0152\u0154\u0005+\u0000\u0000\u0153\u0155\u00036\u001b"+
		"\u0000\u0154\u0153\u0001\u0000\u0000\u0000\u0154\u0155\u0001\u0000\u0000"+
		"\u0000\u0155\u0156\u0001\u0000\u0000\u0000\u0156\u0159\u0005,\u0000\u0000"+
		"\u0157\u0158\u00054\u0000\u0000\u0158\u015a\u0005\u001f\u0000\u0000\u0159"+
		"\u0157\u0001\u0000\u0000\u0000\u0159\u015a\u0001\u0000\u0000\u0000\u015a"+
		"\u015b\u0001\u0000\u0000\u0000\u015b\u015c\u00051\u0000\u0000\u015c5\u0001"+
		"\u0000\u0000\u0000\u015d\u0162\u00038\u001c\u0000\u015e\u015f\u00052\u0000"+
		"\u0000\u015f\u0161\u00038\u001c\u0000\u0160\u015e\u0001\u0000\u0000\u0000"+
		"\u0161\u0164\u0001\u0000\u0000\u0000\u0162\u0160\u0001\u0000\u0000\u0000"+
		"\u0162\u0163\u0001\u0000\u0000\u0000\u01637\u0001\u0000\u0000\u0000\u0164"+
		"\u0162\u0001\u0000\u0000\u0000\u0165\u0167\u0003H$\u0000\u0166\u0165\u0001"+
		"\u0000\u0000\u0000\u0166\u0167\u0001\u0000\u0000\u0000\u0167\u0168\u0001"+
		"\u0000\u0000\u0000\u0168\u0169\u0003<\u001e\u0000\u0169\u016a\u0003\u0002"+
		"\u0001\u0000\u016a9\u0001\u0000\u0000\u0000\u016b\u016c\u0003@ \u0000"+
		"\u016c\u0181\u0003\n\u0005\u0000\u016d\u016e\u00056\u0000\u0000\u016e"+
		"\u016f\u0003>\u001f\u0000\u016f\u0170\u00055\u0000\u0000\u0170\u0180\u0001"+
		"\u0000\u0000\u0000\u0171\u0172\u00056\u0000\u0000\u0172\u0173\u0003:\u001d"+
		"\u0000\u0173\u0174\u00056\u0000\u0000\u0174\u0175\u0003>\u001f\u0000\u0175"+
		"\u0176\u0005L\u0000\u0000\u0176\u0180\u0001\u0000\u0000\u0000\u0177\u0178"+
		"\u00056\u0000\u0000\u0178\u0179\u0003>\u001f\u0000\u0179\u017a\u00052"+
		"\u0000\u0000\u017a\u017b\u0003:\u001d\u0000\u017b\u017c\u00056\u0000\u0000"+
		"\u017c\u017d\u0003>\u001f\u0000\u017d\u017e\u0005L\u0000\u0000\u017e\u0180"+
		"\u0001\u0000\u0000\u0000\u017f\u016d\u0001\u0000\u0000\u0000\u017f\u0171"+
		"\u0001\u0000\u0000\u0000\u017f\u0177\u0001\u0000\u0000\u0000\u0180\u0183"+
		"\u0001\u0000\u0000\u0000\u0181\u017f\u0001\u0000\u0000\u0000\u0181\u0182"+
		"\u0001\u0000\u0000\u0000\u0182;\u0001\u0000\u0000\u0000\u0183\u0181\u0001"+
		"\u0000\u0000\u0000\u0184\u0190\u0003:\u001d\u0000\u0185\u0186\u0003@ "+
		"\u0000\u0186\u0187\u0005/\u0000\u0000\u0187\u0188\u00050\u0000\u0000\u0188"+
		"\u018f\u0001\u0000\u0000\u0000\u0189\u018a\u0003@ \u0000\u018a\u018b\u0005"+
		"/\u0000\u0000\u018b\u018c\u0003\"\u0011\u0000\u018c\u018d\u00050\u0000"+
		"\u0000\u018d\u018f\u0001\u0000\u0000\u0000\u018e\u0185\u0001\u0000\u0000"+
		"\u0000\u018e\u0189\u0001\u0000\u0000\u0000\u018f\u0192\u0001\u0000\u0000"+
		"\u0000\u0190\u018e\u0001\u0000\u0000\u0000\u0190\u0191\u0001\u0000\u0000"+
		"\u0000\u0191\u0195\u0001\u0000\u0000\u0000\u0192\u0190\u0001\u0000\u0000"+
		"\u0000\u0193\u0195\u0005\u000e\u0000\u0000\u0194\u0184\u0001\u0000\u0000"+
		"\u0000\u0194\u0193\u0001\u0000\u0000\u0000\u0195=\u0001\u0000\u0000\u0000"+
		"\u0196\u019b\u0003<\u001e\u0000\u0197\u0198\u00052\u0000\u0000\u0198\u019a"+
		"\u0003<\u001e\u0000\u0199\u0197\u0001\u0000\u0000\u0000\u019a\u019d\u0001"+
		"\u0000\u0000\u0000\u019b\u0199\u0001\u0000\u0000\u0000\u019b\u019c\u0001"+
		"\u0000\u0000\u0000\u019c?\u0001\u0000\u0000\u0000\u019d\u019b\u0001\u0000"+
		"\u0000\u0000\u019e\u01a0\u0003F#\u0000\u019f\u019e\u0001\u0000\u0000\u0000"+
		"\u01a0\u01a3\u0001\u0000\u0000\u0000\u01a1\u019f\u0001\u0000\u0000\u0000"+
		"\u01a1\u01a2\u0001\u0000\u0000\u0000\u01a2A\u0001\u0000\u0000\u0000\u01a3"+
		"\u01a1\u0001\u0000\u0000\u0000\u01a4\u01a5\u0003\u0002\u0001\u0000\u01a5"+
		"\u01a6\u00054\u0000\u0000\u01a6\u01a7\u0003\"\u0011\u0000\u01a7C\u0001"+
		"\u0000\u0000\u0000\u01a8\u01ad\u0003B!\u0000\u01a9\u01aa\u00052\u0000"+
		"\u0000\u01aa\u01ac\u0003B!\u0000\u01ab\u01a9\u0001\u0000\u0000\u0000\u01ac"+
		"\u01af\u0001\u0000\u0000\u0000\u01ad\u01ab\u0001\u0000\u0000\u0000\u01ad"+
		"\u01ae\u0001\u0000\u0000\u0000\u01aeE\u0001\u0000\u0000\u0000\u01af\u01ad"+
		"\u0001\u0000\u0000\u0000\u01b0\u01ba\u0005\u0017\u0000\u0000\u01b1\u01b2"+
		"\u0005+\u0000\u0000\u01b2\u01b3\u0003\"\u0011\u0000\u01b3\u01b4\u0005"+
		",\u0000\u0000\u01b4\u01bb\u0001\u0000\u0000\u0000\u01b5\u01b7\u0005+\u0000"+
		"\u0000\u01b6\u01b8\u0003D\"\u0000\u01b7\u01b6\u0001\u0000\u0000\u0000"+
		"\u01b7\u01b8\u0001\u0000\u0000\u0000\u01b8\u01b9\u0001\u0000\u0000\u0000"+
		"\u01b9\u01bb\u0005,\u0000\u0000\u01ba\u01b1\u0001\u0000\u0000\u0000\u01ba"+
		"\u01b5\u0001\u0000\u0000\u0000\u01ba\u01bb\u0001\u0000\u0000\u0000\u01bb"+
		"G\u0001\u0000\u0000\u0000\u01bc\u01bd\u0007\u0001\u0000\u0000\u01bdI\u0001"+
		"\u0000\u0000\u0000+KN[flu|\u0089\u008b\u0091\u009a\u009f\u00a1\u00a8\u00ad"+
		"\u00b6\u00bb\u00bd\u00cb\u00da\u0112\u0114\u0119\u0120\u012e\u0135\u013b"+
		"\u0146\u014e\u0154\u0159\u0162\u0166\u017f\u0181\u018e\u0190\u0194\u019b"+
		"\u01a1\u01ad\u01b7\u01ba";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}