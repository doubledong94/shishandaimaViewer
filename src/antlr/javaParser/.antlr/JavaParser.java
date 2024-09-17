// Generated from /home/ydd/shishandaimaViewer/antlr/javaParser/JavaParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class JavaParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		ABSTRACT=1, ASSERT=2, BOOLEAN=3, BREAK=4, BYTE=5, CASE=6, CATCH=7, CHAR=8, 
		CLASS=9, CONST=10, CONTINUE=11, DEFAULT=12, DO=13, DOUBLE=14, ELSE=15, 
		ENUM=16, EXTENDS=17, FINAL=18, FINALLY=19, FLOAT=20, FOR=21, IF=22, GOTO=23, 
		IMPLEMENTS=24, IMPORT=25, INSTANCEOF=26, INT=27, INTERFACE=28, LONG=29, 
		NATIVE=30, NEW=31, PACKAGE=32, PRIVATE=33, PROTECTED=34, PUBLIC=35, RETURN=36, 
		SHORT=37, STATIC=38, STRICTFP=39, SUPER=40, SWITCH=41, SYNCHRONIZED=42, 
		THIS=43, THROW=44, THROWS=45, TRANSIENT=46, TRY=47, VOID=48, VOLATILE=49, 
		WHILE=50, MODULE=51, OPEN=52, REQUIRES=53, EXPORTS=54, OPENS=55, TO=56, 
		USES=57, PROVIDES=58, WITH=59, TRANSITIVE=60, VAR=61, YIELD=62, RECORD=63, 
		SEALED=64, PERMITS=65, NON_SEALED=66, DECIMAL_LITERAL=67, HEX_LITERAL=68, 
		OCT_LITERAL=69, BINARY_LITERAL=70, FLOAT_LITERAL=71, HEX_FLOAT_LITERAL=72, 
		BOOL_LITERAL=73, CHAR_LITERAL=74, STRING_LITERAL=75, TEXT_BLOCK=76, NULL_LITERAL=77, 
		LPAREN=78, RPAREN=79, LBRACE=80, RBRACE=81, LBRACK=82, RBRACK=83, SEMI=84, 
		COMMA=85, DOT=86, ASSIGN=87, GT=88, LT=89, BANG=90, TILDE=91, QUESTION=92, 
		COLON=93, EQUAL=94, LE=95, GE=96, NOTEQUAL=97, AND=98, OR=99, INC=100, 
		DEC=101, ADD=102, SUB=103, MUL=104, DIV=105, BITAND=106, BITOR=107, CARET=108, 
		MOD=109, ADD_ASSIGN=110, SUB_ASSIGN=111, MUL_ASSIGN=112, DIV_ASSIGN=113, 
		AND_ASSIGN=114, OR_ASSIGN=115, XOR_ASSIGN=116, MOD_ASSIGN=117, LSHIFT_ASSIGN=118, 
		RSHIFT_ASSIGN=119, URSHIFT_ASSIGN=120, ARROW=121, COLONCOLON=122, AT=123, 
		ELLIPSIS=124, WS=125, COMMENT=126, LINE_COMMENT=127, IDENTIFIER=128;
	public static final int
		RULE_compilationUnit = 0, RULE_packageDeclaration = 1, RULE_importDeclaration = 2, 
		RULE_typeDeclaration = 3, RULE_modifier = 4, RULE_classOrInterfaceModifier = 5, 
		RULE_variableModifier = 6, RULE_classDeclaration = 7, RULE_typeParameters = 8, 
		RULE_typeParameter = 9, RULE_typeBound = 10, RULE_enumDeclaration = 11, 
		RULE_enumConstants = 12, RULE_enumConstant = 13, RULE_enumBodyDeclarations = 14, 
		RULE_interfaceDeclaration = 15, RULE_classBody = 16, RULE_interfaceBody = 17, 
		RULE_classBodyDeclaration = 18, RULE_memberDeclaration = 19, RULE_methodDeclaration = 20, 
		RULE_methodBody = 21, RULE_typeTypeOrVoid = 22, RULE_constructorDeclaration = 23, 
		RULE_fieldDeclaration = 24, RULE_interfaceBodyDeclaration = 25, RULE_interfaceMemberDeclaration = 26, 
		RULE_constDeclaration = 27, RULE_constantDeclarator = 28, RULE_interfaceMethodDeclaration = 29, 
		RULE_interfaceMethodModifier = 30, RULE_interfaceCommonBodyDeclaration = 31, 
		RULE_variableDeclarators = 32, RULE_variableDeclarator = 33, RULE_variableDeclaratorId = 34, 
		RULE_variableInitializer = 35, RULE_arrayInitializer = 36, RULE_classOrInterfaceType = 37, 
		RULE_typeArgument = 38, RULE_qualifiedNameList = 39, RULE_formalParameters = 40, 
		RULE_receiverParameter = 41, RULE_formalParameterList = 42, RULE_formalParameter = 43, 
		RULE_lastFormalParameter = 44, RULE_lambdaLVTIList = 45, RULE_lambdaLVTIParameter = 46, 
		RULE_qualifiedName = 47, RULE_literal = 48, RULE_integerLiteral = 49, 
		RULE_floatLiteral = 50, RULE_altAnnotationQualifiedName = 51, RULE_annotation = 52, 
		RULE_elementValuePairs = 53, RULE_elementValuePair = 54, RULE_elementValue = 55, 
		RULE_elementValueArrayInitializer = 56, RULE_annotationTypeDeclaration = 57, 
		RULE_annotationTypeBody = 58, RULE_annotationTypeElementDeclaration = 59, 
		RULE_annotationTypeElementRest = 60, RULE_annotationMethodOrConstantRest = 61, 
		RULE_annotationMethodRest = 62, RULE_annotationConstantRest = 63, RULE_defaultValue = 64, 
		RULE_moduleDeclaration = 65, RULE_moduleBody = 66, RULE_moduleDirective = 67, 
		RULE_requiresModifier = 68, RULE_recordDeclaration = 69, RULE_recordHeader = 70, 
		RULE_recordComponentList = 71, RULE_recordComponent = 72, RULE_recordBody = 73, 
		RULE_block = 74, RULE_blockStatement = 75, RULE_localVariableDeclaration = 76, 
		RULE_identifier = 77, RULE_localTypeDeclaration = 78, RULE_statement = 79, 
		RULE_catchClause = 80, RULE_catchType = 81, RULE_finallyBlock = 82, RULE_resourceSpecification = 83, 
		RULE_resources = 84, RULE_resource = 85, RULE_switchBlockStatementGroup = 86, 
		RULE_switchLabel = 87, RULE_forControl = 88, RULE_forInit = 89, RULE_forCondition = 90, 
		RULE_forUpdate = 91, RULE_enhancedForControl = 92, RULE_parExpression = 93, 
		RULE_expressionList = 94, RULE_methodCall = 95, RULE_expression = 96, 
		RULE_pattern = 97, RULE_lambdaExpression = 98, RULE_lambdaParameters = 99, 
		RULE_lambdaBody = 100, RULE_primary = 101, RULE_switchExpression = 102, 
		RULE_switchLabeledRule = 103, RULE_guardedPattern = 104, RULE_switchRuleOutcome = 105, 
		RULE_classType = 106, RULE_creator = 107, RULE_createdName = 108, RULE_innerCreator = 109, 
		RULE_arrayCreatorRest = 110, RULE_classCreatorRest = 111, RULE_explicitGenericInvocation = 112, 
		RULE_typeArgumentsOrDiamond = 113, RULE_nonWildcardTypeArgumentsOrDiamond = 114, 
		RULE_nonWildcardTypeArguments = 115, RULE_typeList = 116, RULE_typeType = 117, 
		RULE_primitiveType = 118, RULE_typeArguments = 119, RULE_superSuffix = 120, 
		RULE_explicitGenericInvocationSuffix = 121, RULE_arguments = 122;
	private static String[] makeRuleNames() {
		return new String[] {
			"compilationUnit", "packageDeclaration", "importDeclaration", "typeDeclaration", 
			"modifier", "classOrInterfaceModifier", "variableModifier", "classDeclaration", 
			"typeParameters", "typeParameter", "typeBound", "enumDeclaration", "enumConstants", 
			"enumConstant", "enumBodyDeclarations", "interfaceDeclaration", "classBody", 
			"interfaceBody", "classBodyDeclaration", "memberDeclaration", "methodDeclaration", 
			"methodBody", "typeTypeOrVoid", "constructorDeclaration", "fieldDeclaration", 
			"interfaceBodyDeclaration", "interfaceMemberDeclaration", "constDeclaration", 
			"constantDeclarator", "interfaceMethodDeclaration", "interfaceMethodModifier", 
			"interfaceCommonBodyDeclaration", "variableDeclarators", "variableDeclarator", 
			"variableDeclaratorId", "variableInitializer", "arrayInitializer", "classOrInterfaceType", 
			"typeArgument", "qualifiedNameList", "formalParameters", "receiverParameter", 
			"formalParameterList", "formalParameter", "lastFormalParameter", "lambdaLVTIList", 
			"lambdaLVTIParameter", "qualifiedName", "literal", "integerLiteral", 
			"floatLiteral", "altAnnotationQualifiedName", "annotation", "elementValuePairs", 
			"elementValuePair", "elementValue", "elementValueArrayInitializer", "annotationTypeDeclaration", 
			"annotationTypeBody", "annotationTypeElementDeclaration", "annotationTypeElementRest", 
			"annotationMethodOrConstantRest", "annotationMethodRest", "annotationConstantRest", 
			"defaultValue", "moduleDeclaration", "moduleBody", "moduleDirective", 
			"requiresModifier", "recordDeclaration", "recordHeader", "recordComponentList", 
			"recordComponent", "recordBody", "block", "blockStatement", "localVariableDeclaration", 
			"identifier", "localTypeDeclaration", "statement", "catchClause", "catchType", 
			"finallyBlock", "resourceSpecification", "resources", "resource", "switchBlockStatementGroup", 
			"switchLabel", "forControl", "forInit", "forCondition", "forUpdate", 
			"enhancedForControl", "parExpression", "expressionList", "methodCall", 
			"expression", "pattern", "lambdaExpression", "lambdaParameters", "lambdaBody", 
			"primary", "switchExpression", "switchLabeledRule", "guardedPattern", 
			"switchRuleOutcome", "classType", "creator", "createdName", "innerCreator", 
			"arrayCreatorRest", "classCreatorRest", "explicitGenericInvocation", 
			"typeArgumentsOrDiamond", "nonWildcardTypeArgumentsOrDiamond", "nonWildcardTypeArguments", 
			"typeList", "typeType", "primitiveType", "typeArguments", "superSuffix", 
			"explicitGenericInvocationSuffix", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'abstract'", "'assert'", "'boolean'", "'break'", "'byte'", "'case'", 
			"'catch'", "'char'", "'class'", "'const'", "'continue'", "'default'", 
			"'do'", "'double'", "'else'", "'enum'", "'extends'", "'final'", "'finally'", 
			"'float'", "'for'", "'if'", "'goto'", "'implements'", "'import'", "'instanceof'", 
			"'int'", "'interface'", "'long'", "'native'", "'new'", "'package'", "'private'", 
			"'protected'", "'public'", "'return'", "'short'", "'static'", "'strictfp'", 
			"'super'", "'switch'", "'synchronized'", "'this'", "'throw'", "'throws'", 
			"'transient'", "'try'", "'void'", "'volatile'", "'while'", "'module'", 
			"'open'", "'requires'", "'exports'", "'opens'", "'to'", "'uses'", "'provides'", 
			"'with'", "'transitive'", "'var'", "'yield'", "'record'", "'sealed'", 
			"'permits'", "'non-sealed'", null, null, null, null, null, null, null, 
			null, null, null, "'null'", "'('", "')'", "'{'", "'}'", "'['", "']'", 
			"';'", "','", "'.'", "'='", "'>'", "'<'", "'!'", "'~'", "'?'", "':'", 
			"'=='", "'<='", "'>='", "'!='", "'&&'", "'||'", "'++'", "'--'", "'+'", 
			"'-'", "'*'", "'/'", "'&'", "'|'", "'^'", "'%'", "'+='", "'-='", "'*='", 
			"'/='", "'&='", "'|='", "'^='", "'%='", "'<<='", "'>>='", "'>>>='", "'->'", 
			"'::'", "'@'", "'...'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CATCH", 
			"CHAR", "CLASS", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", 
			"ENUM", "EXTENDS", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "GOTO", 
			"IMPLEMENTS", "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LONG", "NATIVE", 
			"NEW", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "SHORT", 
			"STATIC", "STRICTFP", "SUPER", "SWITCH", "SYNCHRONIZED", "THIS", "THROW", 
			"THROWS", "TRANSIENT", "TRY", "VOID", "VOLATILE", "WHILE", "MODULE", 
			"OPEN", "REQUIRES", "EXPORTS", "OPENS", "TO", "USES", "PROVIDES", "WITH", 
			"TRANSITIVE", "VAR", "YIELD", "RECORD", "SEALED", "PERMITS", "NON_SEALED", 
			"DECIMAL_LITERAL", "HEX_LITERAL", "OCT_LITERAL", "BINARY_LITERAL", "FLOAT_LITERAL", 
			"HEX_FLOAT_LITERAL", "BOOL_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", 
			"TEXT_BLOCK", "NULL_LITERAL", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
			"LBRACK", "RBRACK", "SEMI", "COMMA", "DOT", "ASSIGN", "GT", "LT", "BANG", 
			"TILDE", "QUESTION", "COLON", "EQUAL", "LE", "GE", "NOTEQUAL", "AND", 
			"OR", "INC", "DEC", "ADD", "SUB", "MUL", "DIV", "BITAND", "BITOR", "CARET", 
			"MOD", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "AND_ASSIGN", 
			"OR_ASSIGN", "XOR_ASSIGN", "MOD_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", 
			"URSHIFT_ASSIGN", "ARROW", "COLONCOLON", "AT", "ELLIPSIS", "WS", "COMMENT", 
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
	public String getGrammarFileName() { return "JavaParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public JavaParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CompilationUnitContext extends ParserRuleContext {
		public PackageDeclarationContext packageDeclaration() {
			return getRuleContext(PackageDeclarationContext.class,0);
		}
		public List<ImportDeclarationContext> importDeclaration() {
			return getRuleContexts(ImportDeclarationContext.class);
		}
		public ImportDeclarationContext importDeclaration(int i) {
			return getRuleContext(ImportDeclarationContext.class,i);
		}
		public List<TerminalNode> SEMI() { return getTokens(JavaParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(JavaParser.SEMI, i);
		}
		public List<TypeDeclarationContext> typeDeclaration() {
			return getRuleContexts(TypeDeclarationContext.class);
		}
		public TypeDeclarationContext typeDeclaration(int i) {
			return getRuleContext(TypeDeclarationContext.class,i);
		}
		public ModuleDeclarationContext moduleDeclaration() {
			return getRuleContext(ModuleDeclarationContext.class,0);
		}
		public TerminalNode EOF() { return getToken(JavaParser.EOF, 0); }
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
			int _alt;
			setState(266);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(247);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
				case 1:
					{
					setState(246);
					packageDeclaration();
					}
					break;
				}
				setState(253);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						setState(251);
						_errHandler.sync(this);
						switch (_input.LA(1)) {
						case IMPORT:
							{
							setState(249);
							importDeclaration();
							}
							break;
						case SEMI:
							{
							setState(250);
							match(SEMI);
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						} 
					}
					setState(255);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
				}
				setState(260);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -1125457390829311L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141660702539773L) != 0)) {
					{
					setState(258);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case ABSTRACT:
					case CLASS:
					case ENUM:
					case FINAL:
					case INTERFACE:
					case PRIVATE:
					case PROTECTED:
					case PUBLIC:
					case STATIC:
					case STRICTFP:
					case MODULE:
					case OPEN:
					case REQUIRES:
					case EXPORTS:
					case OPENS:
					case TO:
					case USES:
					case PROVIDES:
					case WITH:
					case TRANSITIVE:
					case VAR:
					case YIELD:
					case RECORD:
					case SEALED:
					case PERMITS:
					case NON_SEALED:
					case AT:
					case IDENTIFIER:
						{
						setState(256);
						typeDeclaration();
						}
						break;
					case SEMI:
						{
						setState(257);
						match(SEMI);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					setState(262);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(263);
				moduleDeclaration();
				setState(264);
				match(EOF);
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
	public static class PackageDeclarationContext extends ParserRuleContext {
		public TerminalNode PACKAGE() { return getToken(JavaParser.PACKAGE, 0); }
		public QualifiedNameContext qualifiedName() {
			return getRuleContext(QualifiedNameContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public PackageDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_packageDeclaration; }
	}

	public final PackageDeclarationContext packageDeclaration() throws RecognitionException {
		PackageDeclarationContext _localctx = new PackageDeclarationContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_packageDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(271);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==AT || _la==IDENTIFIER) {
				{
				{
				setState(268);
				annotation();
				}
				}
				setState(273);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(274);
			match(PACKAGE);
			setState(275);
			qualifiedName();
			setState(276);
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
	public static class ImportDeclarationContext extends ParserRuleContext {
		public Token importAll;
		public TerminalNode IMPORT() { return getToken(JavaParser.IMPORT, 0); }
		public QualifiedNameContext qualifiedName() {
			return getRuleContext(QualifiedNameContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public TerminalNode STATIC() { return getToken(JavaParser.STATIC, 0); }
		public TerminalNode DOT() { return getToken(JavaParser.DOT, 0); }
		public TerminalNode MUL() { return getToken(JavaParser.MUL, 0); }
		public ImportDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_importDeclaration; }
	}

	public final ImportDeclarationContext importDeclaration() throws RecognitionException {
		ImportDeclarationContext _localctx = new ImportDeclarationContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_importDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(278);
			match(IMPORT);
			setState(280);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==STATIC) {
				{
				setState(279);
				match(STATIC);
				}
			}

			setState(282);
			qualifiedName();
			setState(285);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==DOT) {
				{
				setState(283);
				match(DOT);
				setState(284);
				((ImportDeclarationContext)_localctx).importAll = match(MUL);
				}
			}

			setState(287);
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
	public static class TypeDeclarationContext extends ParserRuleContext {
		public ClassDeclarationContext classDeclaration() {
			return getRuleContext(ClassDeclarationContext.class,0);
		}
		public EnumDeclarationContext enumDeclaration() {
			return getRuleContext(EnumDeclarationContext.class,0);
		}
		public InterfaceDeclarationContext interfaceDeclaration() {
			return getRuleContext(InterfaceDeclarationContext.class,0);
		}
		public AnnotationTypeDeclarationContext annotationTypeDeclaration() {
			return getRuleContext(AnnotationTypeDeclarationContext.class,0);
		}
		public RecordDeclarationContext recordDeclaration() {
			return getRuleContext(RecordDeclarationContext.class,0);
		}
		public List<ClassOrInterfaceModifierContext> classOrInterfaceModifier() {
			return getRuleContexts(ClassOrInterfaceModifierContext.class);
		}
		public ClassOrInterfaceModifierContext classOrInterfaceModifier(int i) {
			return getRuleContext(ClassOrInterfaceModifierContext.class,i);
		}
		public TypeDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeDeclaration; }
	}

	public final TypeDeclarationContext typeDeclaration() throws RecognitionException {
		TypeDeclarationContext _localctx = new TypeDeclarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_typeDeclaration);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(292);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(289);
					classOrInterfaceModifier();
					}
					} 
				}
				setState(294);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,9,_ctx);
			}
			setState(300);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CLASS:
				{
				setState(295);
				classDeclaration();
				}
				break;
			case ENUM:
				{
				setState(296);
				enumDeclaration();
				}
				break;
			case INTERFACE:
				{
				setState(297);
				interfaceDeclaration();
				}
				break;
			case AT:
				{
				setState(298);
				annotationTypeDeclaration();
				}
				break;
			case RECORD:
				{
				setState(299);
				recordDeclaration();
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
	public static class ModifierContext extends ParserRuleContext {
		public ClassOrInterfaceModifierContext classOrInterfaceModifier() {
			return getRuleContext(ClassOrInterfaceModifierContext.class,0);
		}
		public TerminalNode NATIVE() { return getToken(JavaParser.NATIVE, 0); }
		public TerminalNode SYNCHRONIZED() { return getToken(JavaParser.SYNCHRONIZED, 0); }
		public TerminalNode TRANSIENT() { return getToken(JavaParser.TRANSIENT, 0); }
		public TerminalNode VOLATILE() { return getToken(JavaParser.VOLATILE, 0); }
		public ModifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_modifier; }
	}

	public final ModifierContext modifier() throws RecognitionException {
		ModifierContext _localctx = new ModifierContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_modifier);
		try {
			setState(307);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ABSTRACT:
			case FINAL:
			case PRIVATE:
			case PROTECTED:
			case PUBLIC:
			case STATIC:
			case STRICTFP:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case NON_SEALED:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(302);
				classOrInterfaceModifier();
				}
				break;
			case NATIVE:
				enterOuterAlt(_localctx, 2);
				{
				setState(303);
				match(NATIVE);
				}
				break;
			case SYNCHRONIZED:
				enterOuterAlt(_localctx, 3);
				{
				setState(304);
				match(SYNCHRONIZED);
				}
				break;
			case TRANSIENT:
				enterOuterAlt(_localctx, 4);
				{
				setState(305);
				match(TRANSIENT);
				}
				break;
			case VOLATILE:
				enterOuterAlt(_localctx, 5);
				{
				setState(306);
				match(VOLATILE);
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
	public static class ClassOrInterfaceModifierContext extends ParserRuleContext {
		public AnnotationContext annotation() {
			return getRuleContext(AnnotationContext.class,0);
		}
		public TerminalNode PUBLIC() { return getToken(JavaParser.PUBLIC, 0); }
		public TerminalNode PROTECTED() { return getToken(JavaParser.PROTECTED, 0); }
		public TerminalNode PRIVATE() { return getToken(JavaParser.PRIVATE, 0); }
		public TerminalNode STATIC() { return getToken(JavaParser.STATIC, 0); }
		public TerminalNode ABSTRACT() { return getToken(JavaParser.ABSTRACT, 0); }
		public TerminalNode FINAL() { return getToken(JavaParser.FINAL, 0); }
		public TerminalNode STRICTFP() { return getToken(JavaParser.STRICTFP, 0); }
		public TerminalNode SEALED() { return getToken(JavaParser.SEALED, 0); }
		public TerminalNode NON_SEALED() { return getToken(JavaParser.NON_SEALED, 0); }
		public ClassOrInterfaceModifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classOrInterfaceModifier; }
	}

	public final ClassOrInterfaceModifierContext classOrInterfaceModifier() throws RecognitionException {
		ClassOrInterfaceModifierContext _localctx = new ClassOrInterfaceModifierContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_classOrInterfaceModifier);
		try {
			setState(319);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(309);
				annotation();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(310);
				match(PUBLIC);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(311);
				match(PROTECTED);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(312);
				match(PRIVATE);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(313);
				match(STATIC);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(314);
				match(ABSTRACT);
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(315);
				match(FINAL);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(316);
				match(STRICTFP);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(317);
				match(SEALED);
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(318);
				match(NON_SEALED);
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
	public static class VariableModifierContext extends ParserRuleContext {
		public TerminalNode FINAL() { return getToken(JavaParser.FINAL, 0); }
		public AnnotationContext annotation() {
			return getRuleContext(AnnotationContext.class,0);
		}
		public VariableModifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableModifier; }
	}

	public final VariableModifierContext variableModifier() throws RecognitionException {
		VariableModifierContext _localctx = new VariableModifierContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_variableModifier);
		try {
			setState(323);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case FINAL:
				enterOuterAlt(_localctx, 1);
				{
				setState(321);
				match(FINAL);
				}
				break;
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 2);
				{
				setState(322);
				annotation();
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
	public static class ClassDeclarationContext extends ParserRuleContext {
		public TypeTypeContext super_;
		public TypeListContext interface_;
		public TerminalNode CLASS() { return getToken(JavaParser.CLASS, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ClassBodyContext classBody() {
			return getRuleContext(ClassBodyContext.class,0);
		}
		public TypeParametersContext typeParameters() {
			return getRuleContext(TypeParametersContext.class,0);
		}
		public TerminalNode EXTENDS() { return getToken(JavaParser.EXTENDS, 0); }
		public TerminalNode IMPLEMENTS() { return getToken(JavaParser.IMPLEMENTS, 0); }
		public TerminalNode PERMITS() { return getToken(JavaParser.PERMITS, 0); }
		public List<TypeListContext> typeList() {
			return getRuleContexts(TypeListContext.class);
		}
		public TypeListContext typeList(int i) {
			return getRuleContext(TypeListContext.class,i);
		}
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public ClassDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classDeclaration; }
	}

	public final ClassDeclarationContext classDeclaration() throws RecognitionException {
		ClassDeclarationContext _localctx = new ClassDeclarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_classDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(325);
			match(CLASS);
			setState(326);
			identifier();
			setState(328);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(327);
				typeParameters();
				}
			}

			setState(332);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EXTENDS) {
				{
				setState(330);
				match(EXTENDS);
				setState(331);
				((ClassDeclarationContext)_localctx).super_ = typeType();
				}
			}

			setState(336);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IMPLEMENTS) {
				{
				setState(334);
				match(IMPLEMENTS);
				setState(335);
				((ClassDeclarationContext)_localctx).interface_ = typeList();
				}
			}

			setState(340);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PERMITS) {
				{
				setState(338);
				match(PERMITS);
				setState(339);
				typeList();
				}
			}

			setState(342);
			classBody();
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
	public static class TypeParametersContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(JavaParser.LT, 0); }
		public List<TypeParameterContext> typeParameter() {
			return getRuleContexts(TypeParameterContext.class);
		}
		public TypeParameterContext typeParameter(int i) {
			return getRuleContext(TypeParameterContext.class,i);
		}
		public TerminalNode GT() { return getToken(JavaParser.GT, 0); }
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public TypeParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeParameters; }
	}

	public final TypeParametersContext typeParameters() throws RecognitionException {
		TypeParametersContext _localctx = new TypeParametersContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_typeParameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(344);
			match(LT);
			setState(345);
			typeParameter();
			setState(350);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(346);
				match(COMMA);
				setState(347);
				typeParameter();
				}
				}
				setState(352);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(353);
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
	public static class TypeParameterContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public TerminalNode EXTENDS() { return getToken(JavaParser.EXTENDS, 0); }
		public TypeBoundContext typeBound() {
			return getRuleContext(TypeBoundContext.class,0);
		}
		public TypeParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeParameter; }
	}

	public final TypeParameterContext typeParameter() throws RecognitionException {
		TypeParameterContext _localctx = new TypeParameterContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_typeParameter);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(358);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(355);
					annotation();
					}
					} 
				}
				setState(360);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			setState(361);
			identifier();
			setState(370);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EXTENDS) {
				{
				setState(362);
				match(EXTENDS);
				setState(366);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(363);
						annotation();
						}
						} 
					}
					setState(368);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
				}
				setState(369);
				typeBound();
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
	public static class TypeBoundContext extends ParserRuleContext {
		public List<TypeTypeContext> typeType() {
			return getRuleContexts(TypeTypeContext.class);
		}
		public TypeTypeContext typeType(int i) {
			return getRuleContext(TypeTypeContext.class,i);
		}
		public List<TerminalNode> BITAND() { return getTokens(JavaParser.BITAND); }
		public TerminalNode BITAND(int i) {
			return getToken(JavaParser.BITAND, i);
		}
		public TypeBoundContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeBound; }
	}

	public final TypeBoundContext typeBound() throws RecognitionException {
		TypeBoundContext _localctx = new TypeBoundContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_typeBound);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(372);
			typeType();
			setState(377);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==BITAND) {
				{
				{
				setState(373);
				match(BITAND);
				setState(374);
				typeType();
				}
				}
				setState(379);
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
	public static class EnumDeclarationContext extends ParserRuleContext {
		public TypeListContext interface_;
		public TerminalNode ENUM() { return getToken(JavaParser.ENUM, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public TerminalNode IMPLEMENTS() { return getToken(JavaParser.IMPLEMENTS, 0); }
		public EnumConstantsContext enumConstants() {
			return getRuleContext(EnumConstantsContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(JavaParser.COMMA, 0); }
		public EnumBodyDeclarationsContext enumBodyDeclarations() {
			return getRuleContext(EnumBodyDeclarationsContext.class,0);
		}
		public TypeListContext typeList() {
			return getRuleContext(TypeListContext.class,0);
		}
		public EnumDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumDeclaration; }
	}

	public final EnumDeclarationContext enumDeclaration() throws RecognitionException {
		EnumDeclarationContext _localctx = new EnumDeclarationContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_enumDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(380);
			match(ENUM);
			setState(381);
			identifier();
			setState(384);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IMPLEMENTS) {
				{
				setState(382);
				match(IMPLEMENTS);
				setState(383);
				((EnumDeclarationContext)_localctx).interface_ = typeList();
				}
			}

			setState(386);
			match(LBRACE);
			setState(388);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==AT || _la==IDENTIFIER) {
				{
				setState(387);
				enumConstants();
				}
			}

			setState(391);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(390);
				match(COMMA);
				}
			}

			setState(394);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEMI) {
				{
				setState(393);
				enumBodyDeclarations();
				}
			}

			setState(396);
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
	public static class EnumConstantsContext extends ParserRuleContext {
		public List<EnumConstantContext> enumConstant() {
			return getRuleContexts(EnumConstantContext.class);
		}
		public EnumConstantContext enumConstant(int i) {
			return getRuleContext(EnumConstantContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public EnumConstantsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumConstants; }
	}

	public final EnumConstantsContext enumConstants() throws RecognitionException {
		EnumConstantsContext _localctx = new EnumConstantsContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_enumConstants);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(398);
			enumConstant();
			setState(403);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(399);
					match(COMMA);
					setState(400);
					enumConstant();
					}
					} 
				}
				setState(405);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
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
	public static class EnumConstantContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ClassBodyContext classBody() {
			return getRuleContext(ClassBodyContext.class,0);
		}
		public EnumConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumConstant; }
	}

	public final EnumConstantContext enumConstant() throws RecognitionException {
		EnumConstantContext _localctx = new EnumConstantContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_enumConstant);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(409);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(406);
					annotation();
					}
					} 
				}
				setState(411);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			}
			setState(412);
			identifier();
			setState(414);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(413);
				arguments();
				}
			}

			setState(417);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LBRACE) {
				{
				setState(416);
				classBody();
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
	public static class EnumBodyDeclarationsContext extends ParserRuleContext {
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public List<ClassBodyDeclarationContext> classBodyDeclaration() {
			return getRuleContexts(ClassBodyDeclarationContext.class);
		}
		public ClassBodyDeclarationContext classBodyDeclaration(int i) {
			return getRuleContext(ClassBodyDeclarationContext.class,i);
		}
		public EnumBodyDeclarationsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enumBodyDeclarations; }
	}

	public final EnumBodyDeclarationsContext enumBodyDeclarations() throws RecognitionException {
		EnumBodyDeclarationsContext _localctx = new EnumBodyDeclarationsContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_enumBodyDeclarations);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(419);
			match(SEMI);
			setState(423);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -665791937994347L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141660685729789L) != 0)) {
				{
				{
				setState(420);
				classBodyDeclaration();
				}
				}
				setState(425);
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
	public static class InterfaceDeclarationContext extends ParserRuleContext {
		public TypeListContext super_;
		public TerminalNode INTERFACE() { return getToken(JavaParser.INTERFACE, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public InterfaceBodyContext interfaceBody() {
			return getRuleContext(InterfaceBodyContext.class,0);
		}
		public TypeParametersContext typeParameters() {
			return getRuleContext(TypeParametersContext.class,0);
		}
		public TerminalNode EXTENDS() { return getToken(JavaParser.EXTENDS, 0); }
		public TerminalNode PERMITS() { return getToken(JavaParser.PERMITS, 0); }
		public List<TypeListContext> typeList() {
			return getRuleContexts(TypeListContext.class);
		}
		public TypeListContext typeList(int i) {
			return getRuleContext(TypeListContext.class,i);
		}
		public InterfaceDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interfaceDeclaration; }
	}

	public final InterfaceDeclarationContext interfaceDeclaration() throws RecognitionException {
		InterfaceDeclarationContext _localctx = new InterfaceDeclarationContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_interfaceDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(426);
			match(INTERFACE);
			setState(427);
			identifier();
			setState(429);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(428);
				typeParameters();
				}
			}

			setState(433);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EXTENDS) {
				{
				setState(431);
				match(EXTENDS);
				setState(432);
				((InterfaceDeclarationContext)_localctx).super_ = typeList();
				}
			}

			setState(437);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PERMITS) {
				{
				setState(435);
				match(PERMITS);
				setState(436);
				typeList();
				}
			}

			setState(439);
			interfaceBody();
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
	public static class ClassBodyContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<ClassBodyDeclarationContext> classBodyDeclaration() {
			return getRuleContexts(ClassBodyDeclarationContext.class);
		}
		public ClassBodyDeclarationContext classBodyDeclaration(int i) {
			return getRuleContext(ClassBodyDeclarationContext.class,i);
		}
		public ClassBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classBody; }
	}

	public final ClassBodyContext classBody() throws RecognitionException {
		ClassBodyContext _localctx = new ClassBodyContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_classBody);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(441);
			match(LBRACE);
			setState(445);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -665791937994347L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141660685729789L) != 0)) {
				{
				{
				setState(442);
				classBodyDeclaration();
				}
				}
				setState(447);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(448);
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
	public static class InterfaceBodyContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<InterfaceBodyDeclarationContext> interfaceBodyDeclaration() {
			return getRuleContexts(InterfaceBodyDeclarationContext.class);
		}
		public InterfaceBodyDeclarationContext interfaceBodyDeclaration(int i) {
			return getRuleContext(InterfaceBodyDeclarationContext.class,i);
		}
		public InterfaceBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interfaceBody; }
	}

	public final InterfaceBodyContext interfaceBody() throws RecognitionException {
		InterfaceBodyContext _localctx = new InterfaceBodyContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_interfaceBody);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(450);
			match(LBRACE);
			setState(454);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -665791937992299L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141660685762557L) != 0)) {
				{
				{
				setState(451);
				interfaceBodyDeclaration();
				}
				}
				setState(456);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(457);
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
	public static class ClassBodyDeclarationContext extends ParserRuleContext {
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode STATIC() { return getToken(JavaParser.STATIC, 0); }
		public MemberDeclarationContext memberDeclaration() {
			return getRuleContext(MemberDeclarationContext.class,0);
		}
		public List<ModifierContext> modifier() {
			return getRuleContexts(ModifierContext.class);
		}
		public ModifierContext modifier(int i) {
			return getRuleContext(ModifierContext.class,i);
		}
		public ClassBodyDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classBodyDeclaration; }
	}

	public final ClassBodyDeclarationContext classBodyDeclaration() throws RecognitionException {
		ClassBodyDeclarationContext _localctx = new ClassBodyDeclarationContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_classBodyDeclaration);
		int _la;
		try {
			int _alt;
			setState(471);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,39,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(459);
				match(SEMI);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(461);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==STATIC) {
					{
					setState(460);
					match(STATIC);
					}
				}

				setState(463);
				block();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(467);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(464);
						modifier();
						}
						} 
					}
					setState(469);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,38,_ctx);
				}
				setState(470);
				memberDeclaration();
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
	public static class MemberDeclarationContext extends ParserRuleContext {
		public RecordDeclarationContext recordDeclaration() {
			return getRuleContext(RecordDeclarationContext.class,0);
		}
		public MethodDeclarationContext methodDeclaration() {
			return getRuleContext(MethodDeclarationContext.class,0);
		}
		public FieldDeclarationContext fieldDeclaration() {
			return getRuleContext(FieldDeclarationContext.class,0);
		}
		public ConstructorDeclarationContext constructorDeclaration() {
			return getRuleContext(ConstructorDeclarationContext.class,0);
		}
		public InterfaceDeclarationContext interfaceDeclaration() {
			return getRuleContext(InterfaceDeclarationContext.class,0);
		}
		public AnnotationTypeDeclarationContext annotationTypeDeclaration() {
			return getRuleContext(AnnotationTypeDeclarationContext.class,0);
		}
		public ClassDeclarationContext classDeclaration() {
			return getRuleContext(ClassDeclarationContext.class,0);
		}
		public EnumDeclarationContext enumDeclaration() {
			return getRuleContext(EnumDeclarationContext.class,0);
		}
		public MemberDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_memberDeclaration; }
	}

	public final MemberDeclarationContext memberDeclaration() throws RecognitionException {
		MemberDeclarationContext _localctx = new MemberDeclarationContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_memberDeclaration);
		try {
			setState(481);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,40,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(473);
				recordDeclaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(474);
				methodDeclaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(475);
				fieldDeclaration();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(476);
				constructorDeclaration();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(477);
				interfaceDeclaration();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(478);
				annotationTypeDeclaration();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(479);
				classDeclaration();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(480);
				enumDeclaration();
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
	public static class MethodDeclarationContext extends ParserRuleContext {
		public TypeTypeOrVoidContext typeTypeOrVoid() {
			return getRuleContext(TypeTypeOrVoidContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public FormalParametersContext formalParameters() {
			return getRuleContext(FormalParametersContext.class,0);
		}
		public MethodBodyContext methodBody() {
			return getRuleContext(MethodBodyContext.class,0);
		}
		public TypeParametersContext typeParameters() {
			return getRuleContext(TypeParametersContext.class,0);
		}
		public List<TerminalNode> LBRACK() { return getTokens(JavaParser.LBRACK); }
		public TerminalNode LBRACK(int i) {
			return getToken(JavaParser.LBRACK, i);
		}
		public List<TerminalNode> RBRACK() { return getTokens(JavaParser.RBRACK); }
		public TerminalNode RBRACK(int i) {
			return getToken(JavaParser.RBRACK, i);
		}
		public TerminalNode THROWS() { return getToken(JavaParser.THROWS, 0); }
		public QualifiedNameListContext qualifiedNameList() {
			return getRuleContext(QualifiedNameListContext.class,0);
		}
		public MethodDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_methodDeclaration; }
	}

	public final MethodDeclarationContext methodDeclaration() throws RecognitionException {
		MethodDeclarationContext _localctx = new MethodDeclarationContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_methodDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(484);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(483);
				typeParameters();
				}
			}

			setState(486);
			typeTypeOrVoid();
			setState(487);
			identifier();
			setState(488);
			formalParameters();
			setState(493);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LBRACK) {
				{
				{
				setState(489);
				match(LBRACK);
				setState(490);
				match(RBRACK);
				}
				}
				setState(495);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(498);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==THROWS) {
				{
				setState(496);
				match(THROWS);
				setState(497);
				qualifiedNameList();
				}
			}

			setState(500);
			methodBody();
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
	public static class MethodBodyContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public MethodBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_methodBody; }
	}

	public final MethodBodyContext methodBody() throws RecognitionException {
		MethodBodyContext _localctx = new MethodBodyContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_methodBody);
		try {
			setState(504);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LBRACE:
				enterOuterAlt(_localctx, 1);
				{
				setState(502);
				block();
				}
				break;
			case SEMI:
				enterOuterAlt(_localctx, 2);
				{
				setState(503);
				match(SEMI);
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
	public static class TypeTypeOrVoidContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public TerminalNode VOID() { return getToken(JavaParser.VOID, 0); }
		public TypeTypeOrVoidContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeTypeOrVoid; }
	}

	public final TypeTypeOrVoidContext typeTypeOrVoid() throws RecognitionException {
		TypeTypeOrVoidContext _localctx = new TypeTypeOrVoidContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_typeTypeOrVoid);
		try {
			setState(508);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case SHORT:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(506);
				typeType();
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 2);
				{
				setState(507);
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
	public static class ConstructorDeclarationContext extends ParserRuleContext {
		public BlockContext constructorBody;
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public FormalParametersContext formalParameters() {
			return getRuleContext(FormalParametersContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TypeParametersContext typeParameters() {
			return getRuleContext(TypeParametersContext.class,0);
		}
		public TerminalNode THROWS() { return getToken(JavaParser.THROWS, 0); }
		public QualifiedNameListContext qualifiedNameList() {
			return getRuleContext(QualifiedNameListContext.class,0);
		}
		public ConstructorDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constructorDeclaration; }
	}

	public final ConstructorDeclarationContext constructorDeclaration() throws RecognitionException {
		ConstructorDeclarationContext _localctx = new ConstructorDeclarationContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_constructorDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(511);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(510);
				typeParameters();
				}
			}

			setState(513);
			identifier();
			setState(514);
			formalParameters();
			setState(517);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==THROWS) {
				{
				setState(515);
				match(THROWS);
				setState(516);
				qualifiedNameList();
				}
			}

			setState(519);
			((ConstructorDeclarationContext)_localctx).constructorBody = block();
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
	public static class FieldDeclarationContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public VariableDeclaratorsContext variableDeclarators() {
			return getRuleContext(VariableDeclaratorsContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public FieldDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fieldDeclaration; }
	}

	public final FieldDeclarationContext fieldDeclaration() throws RecognitionException {
		FieldDeclarationContext _localctx = new FieldDeclarationContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_fieldDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(521);
			typeType();
			setState(522);
			variableDeclarators();
			setState(523);
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
	public static class InterfaceBodyDeclarationContext extends ParserRuleContext {
		public InterfaceMemberDeclarationContext interfaceMemberDeclaration() {
			return getRuleContext(InterfaceMemberDeclarationContext.class,0);
		}
		public List<ModifierContext> modifier() {
			return getRuleContexts(ModifierContext.class);
		}
		public ModifierContext modifier(int i) {
			return getRuleContext(ModifierContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public InterfaceBodyDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interfaceBodyDeclaration; }
	}

	public final InterfaceBodyDeclarationContext interfaceBodyDeclaration() throws RecognitionException {
		InterfaceBodyDeclarationContext _localctx = new InterfaceBodyDeclarationContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_interfaceBodyDeclaration);
		try {
			int _alt;
			setState(533);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ABSTRACT:
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case CLASS:
			case DEFAULT:
			case DOUBLE:
			case ENUM:
			case FINAL:
			case FLOAT:
			case INT:
			case INTERFACE:
			case LONG:
			case NATIVE:
			case PRIVATE:
			case PROTECTED:
			case PUBLIC:
			case SHORT:
			case STATIC:
			case STRICTFP:
			case SYNCHRONIZED:
			case TRANSIENT:
			case VOID:
			case VOLATILE:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case NON_SEALED:
			case LT:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(528);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,48,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(525);
						modifier();
						}
						} 
					}
					setState(530);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,48,_ctx);
				}
				setState(531);
				interfaceMemberDeclaration();
				}
				break;
			case SEMI:
				enterOuterAlt(_localctx, 2);
				{
				setState(532);
				match(SEMI);
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
	public static class InterfaceMemberDeclarationContext extends ParserRuleContext {
		public ConstDeclarationContext constDeclaration() {
			return getRuleContext(ConstDeclarationContext.class,0);
		}
		public InterfaceMethodDeclarationContext interfaceMethodDeclaration() {
			return getRuleContext(InterfaceMethodDeclarationContext.class,0);
		}
		public InterfaceDeclarationContext interfaceDeclaration() {
			return getRuleContext(InterfaceDeclarationContext.class,0);
		}
		public AnnotationTypeDeclarationContext annotationTypeDeclaration() {
			return getRuleContext(AnnotationTypeDeclarationContext.class,0);
		}
		public ClassDeclarationContext classDeclaration() {
			return getRuleContext(ClassDeclarationContext.class,0);
		}
		public EnumDeclarationContext enumDeclaration() {
			return getRuleContext(EnumDeclarationContext.class,0);
		}
		public RecordDeclarationContext recordDeclaration() {
			return getRuleContext(RecordDeclarationContext.class,0);
		}
		public InterfaceMemberDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interfaceMemberDeclaration; }
	}

	public final InterfaceMemberDeclarationContext interfaceMemberDeclaration() throws RecognitionException {
		InterfaceMemberDeclarationContext _localctx = new InterfaceMemberDeclarationContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_interfaceMemberDeclaration);
		try {
			setState(542);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,50,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(535);
				constDeclaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(536);
				interfaceMethodDeclaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(537);
				interfaceDeclaration();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(538);
				annotationTypeDeclaration();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(539);
				classDeclaration();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(540);
				enumDeclaration();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(541);
				recordDeclaration();
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
	public static class ConstDeclarationContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public List<ConstantDeclaratorContext> constantDeclarator() {
			return getRuleContexts(ConstantDeclaratorContext.class);
		}
		public ConstantDeclaratorContext constantDeclarator(int i) {
			return getRuleContext(ConstantDeclaratorContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public ConstDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constDeclaration; }
	}

	public final ConstDeclarationContext constDeclaration() throws RecognitionException {
		ConstDeclarationContext _localctx = new ConstDeclarationContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_constDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(544);
			typeType();
			setState(545);
			constantDeclarator();
			setState(550);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(546);
				match(COMMA);
				setState(547);
				constantDeclarator();
				}
				}
				setState(552);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(553);
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
	public static class ConstantDeclaratorContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(JavaParser.ASSIGN, 0); }
		public VariableInitializerContext variableInitializer() {
			return getRuleContext(VariableInitializerContext.class,0);
		}
		public List<TerminalNode> LBRACK() { return getTokens(JavaParser.LBRACK); }
		public TerminalNode LBRACK(int i) {
			return getToken(JavaParser.LBRACK, i);
		}
		public List<TerminalNode> RBRACK() { return getTokens(JavaParser.RBRACK); }
		public TerminalNode RBRACK(int i) {
			return getToken(JavaParser.RBRACK, i);
		}
		public ConstantDeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantDeclarator; }
	}

	public final ConstantDeclaratorContext constantDeclarator() throws RecognitionException {
		ConstantDeclaratorContext _localctx = new ConstantDeclaratorContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_constantDeclarator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(555);
			identifier();
			setState(560);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LBRACK) {
				{
				{
				setState(556);
				match(LBRACK);
				setState(557);
				match(RBRACK);
				}
				}
				setState(562);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(563);
			match(ASSIGN);
			setState(564);
			variableInitializer();
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
	public static class InterfaceMethodDeclarationContext extends ParserRuleContext {
		public InterfaceCommonBodyDeclarationContext interfaceCommonBodyDeclaration() {
			return getRuleContext(InterfaceCommonBodyDeclarationContext.class,0);
		}
		public List<InterfaceMethodModifierContext> interfaceMethodModifier() {
			return getRuleContexts(InterfaceMethodModifierContext.class);
		}
		public InterfaceMethodModifierContext interfaceMethodModifier(int i) {
			return getRuleContext(InterfaceMethodModifierContext.class,i);
		}
		public TypeParametersContext typeParameters() {
			return getRuleContext(TypeParametersContext.class,0);
		}
		public InterfaceMethodDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interfaceMethodDeclaration; }
	}

	public final InterfaceMethodDeclarationContext interfaceMethodDeclaration() throws RecognitionException {
		InterfaceMethodDeclarationContext _localctx = new InterfaceMethodDeclarationContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_interfaceMethodDeclaration);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(569);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,53,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(566);
					interfaceMethodModifier();
					}
					} 
				}
				setState(571);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,53,_ctx);
			}
			setState(573);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(572);
				typeParameters();
				}
			}

			setState(575);
			interfaceCommonBodyDeclaration();
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
	public static class InterfaceMethodModifierContext extends ParserRuleContext {
		public AnnotationContext annotation() {
			return getRuleContext(AnnotationContext.class,0);
		}
		public TerminalNode PUBLIC() { return getToken(JavaParser.PUBLIC, 0); }
		public TerminalNode ABSTRACT() { return getToken(JavaParser.ABSTRACT, 0); }
		public TerminalNode DEFAULT() { return getToken(JavaParser.DEFAULT, 0); }
		public TerminalNode STATIC() { return getToken(JavaParser.STATIC, 0); }
		public TerminalNode STRICTFP() { return getToken(JavaParser.STRICTFP, 0); }
		public InterfaceMethodModifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interfaceMethodModifier; }
	}

	public final InterfaceMethodModifierContext interfaceMethodModifier() throws RecognitionException {
		InterfaceMethodModifierContext _localctx = new InterfaceMethodModifierContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_interfaceMethodModifier);
		try {
			setState(583);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(577);
				annotation();
				}
				break;
			case PUBLIC:
				enterOuterAlt(_localctx, 2);
				{
				setState(578);
				match(PUBLIC);
				}
				break;
			case ABSTRACT:
				enterOuterAlt(_localctx, 3);
				{
				setState(579);
				match(ABSTRACT);
				}
				break;
			case DEFAULT:
				enterOuterAlt(_localctx, 4);
				{
				setState(580);
				match(DEFAULT);
				}
				break;
			case STATIC:
				enterOuterAlt(_localctx, 5);
				{
				setState(581);
				match(STATIC);
				}
				break;
			case STRICTFP:
				enterOuterAlt(_localctx, 6);
				{
				setState(582);
				match(STRICTFP);
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
	public static class InterfaceCommonBodyDeclarationContext extends ParserRuleContext {
		public TypeTypeOrVoidContext typeTypeOrVoid() {
			return getRuleContext(TypeTypeOrVoidContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public FormalParametersContext formalParameters() {
			return getRuleContext(FormalParametersContext.class,0);
		}
		public MethodBodyContext methodBody() {
			return getRuleContext(MethodBodyContext.class,0);
		}
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public List<TerminalNode> LBRACK() { return getTokens(JavaParser.LBRACK); }
		public TerminalNode LBRACK(int i) {
			return getToken(JavaParser.LBRACK, i);
		}
		public List<TerminalNode> RBRACK() { return getTokens(JavaParser.RBRACK); }
		public TerminalNode RBRACK(int i) {
			return getToken(JavaParser.RBRACK, i);
		}
		public TerminalNode THROWS() { return getToken(JavaParser.THROWS, 0); }
		public QualifiedNameListContext qualifiedNameList() {
			return getRuleContext(QualifiedNameListContext.class,0);
		}
		public InterfaceCommonBodyDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interfaceCommonBodyDeclaration; }
	}

	public final InterfaceCommonBodyDeclarationContext interfaceCommonBodyDeclaration() throws RecognitionException {
		InterfaceCommonBodyDeclarationContext _localctx = new InterfaceCommonBodyDeclarationContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_interfaceCommonBodyDeclaration);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(588);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,56,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(585);
					annotation();
					}
					} 
				}
				setState(590);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,56,_ctx);
			}
			setState(591);
			typeTypeOrVoid();
			setState(592);
			identifier();
			setState(593);
			formalParameters();
			setState(598);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LBRACK) {
				{
				{
				setState(594);
				match(LBRACK);
				setState(595);
				match(RBRACK);
				}
				}
				setState(600);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(603);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==THROWS) {
				{
				setState(601);
				match(THROWS);
				setState(602);
				qualifiedNameList();
				}
			}

			setState(605);
			methodBody();
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
	public static class VariableDeclaratorsContext extends ParserRuleContext {
		public List<VariableDeclaratorContext> variableDeclarator() {
			return getRuleContexts(VariableDeclaratorContext.class);
		}
		public VariableDeclaratorContext variableDeclarator(int i) {
			return getRuleContext(VariableDeclaratorContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public VariableDeclaratorsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclarators; }
	}

	public final VariableDeclaratorsContext variableDeclarators() throws RecognitionException {
		VariableDeclaratorsContext _localctx = new VariableDeclaratorsContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_variableDeclarators);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(607);
			variableDeclarator();
			setState(612);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(608);
				match(COMMA);
				setState(609);
				variableDeclarator();
				}
				}
				setState(614);
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
	public static class VariableDeclaratorContext extends ParserRuleContext {
		public VariableDeclaratorIdContext variableDeclaratorId() {
			return getRuleContext(VariableDeclaratorIdContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(JavaParser.ASSIGN, 0); }
		public VariableInitializerContext variableInitializer() {
			return getRuleContext(VariableInitializerContext.class,0);
		}
		public VariableDeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclarator; }
	}

	public final VariableDeclaratorContext variableDeclarator() throws RecognitionException {
		VariableDeclaratorContext _localctx = new VariableDeclaratorContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_variableDeclarator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(615);
			variableDeclaratorId();
			setState(618);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGN) {
				{
				setState(616);
				match(ASSIGN);
				setState(617);
				variableInitializer();
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
	public static class VariableDeclaratorIdContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public List<TerminalNode> LBRACK() { return getTokens(JavaParser.LBRACK); }
		public TerminalNode LBRACK(int i) {
			return getToken(JavaParser.LBRACK, i);
		}
		public List<TerminalNode> RBRACK() { return getTokens(JavaParser.RBRACK); }
		public TerminalNode RBRACK(int i) {
			return getToken(JavaParser.RBRACK, i);
		}
		public VariableDeclaratorIdContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclaratorId; }
	}

	public final VariableDeclaratorIdContext variableDeclaratorId() throws RecognitionException {
		VariableDeclaratorIdContext _localctx = new VariableDeclaratorIdContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_variableDeclaratorId);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(620);
			identifier();
			setState(625);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LBRACK) {
				{
				{
				setState(621);
				match(LBRACK);
				setState(622);
				match(RBRACK);
				}
				}
				setState(627);
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
	public static class VariableInitializerContext extends ParserRuleContext {
		public ArrayInitializerContext arrayInitializer() {
			return getRuleContext(ArrayInitializerContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VariableInitializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableInitializer; }
	}

	public final VariableInitializerContext variableInitializer() throws RecognitionException {
		VariableInitializerContext _localctx = new VariableInitializerContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_variableInitializer);
		try {
			setState(630);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LBRACE:
				enterOuterAlt(_localctx, 1);
				{
				setState(628);
				arrayInitializer();
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case NEW:
			case SHORT:
			case SUPER:
			case SWITCH:
			case THIS:
			case VOID:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case DECIMAL_LITERAL:
			case HEX_LITERAL:
			case OCT_LITERAL:
			case BINARY_LITERAL:
			case FLOAT_LITERAL:
			case HEX_FLOAT_LITERAL:
			case BOOL_LITERAL:
			case CHAR_LITERAL:
			case STRING_LITERAL:
			case TEXT_BLOCK:
			case NULL_LITERAL:
			case LPAREN:
			case LT:
			case BANG:
			case TILDE:
			case INC:
			case DEC:
			case ADD:
			case SUB:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 2);
				{
				setState(629);
				expression(0);
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
	public static class ArrayInitializerContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<VariableInitializerContext> variableInitializer() {
			return getRuleContexts(VariableInitializerContext.class);
		}
		public VariableInitializerContext variableInitializer(int i) {
			return getRuleContext(VariableInitializerContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public ArrayInitializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayInitializer; }
	}

	public final ArrayInitializerContext arrayInitializer() throws RecognitionException {
		ArrayInitializerContext _localctx = new ArrayInitializerContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_arrayInitializer);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(632);
			match(LBRACE);
			setState(644);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130013183L) != 0)) {
				{
				setState(633);
				variableInitializer();
				setState(638);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,63,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(634);
						match(COMMA);
						setState(635);
						variableInitializer();
						}
						} 
					}
					setState(640);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,63,_ctx);
				}
				setState(642);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(641);
					match(COMMA);
					}
				}

				}
			}

			setState(646);
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
	public static class ClassOrInterfaceTypeContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TypeArgumentsContext> typeArguments() {
			return getRuleContexts(TypeArgumentsContext.class);
		}
		public TypeArgumentsContext typeArguments(int i) {
			return getRuleContext(TypeArgumentsContext.class,i);
		}
		public List<TerminalNode> DOT() { return getTokens(JavaParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(JavaParser.DOT, i);
		}
		public ClassOrInterfaceTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classOrInterfaceType; }
	}

	public final ClassOrInterfaceTypeContext classOrInterfaceType() throws RecognitionException {
		ClassOrInterfaceTypeContext _localctx = new ClassOrInterfaceTypeContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_classOrInterfaceType);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(648);
			identifier();
			setState(650);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,66,_ctx) ) {
			case 1:
				{
				setState(649);
				typeArguments();
				}
				break;
			}
			setState(659);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,68,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(652);
					match(DOT);
					setState(653);
					identifier();
					setState(655);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,67,_ctx) ) {
					case 1:
						{
						setState(654);
						typeArguments();
						}
						break;
					}
					}
					} 
				}
				setState(661);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,68,_ctx);
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
	public static class TypeArgumentContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public TerminalNode QUESTION() { return getToken(JavaParser.QUESTION, 0); }
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public TerminalNode EXTENDS() { return getToken(JavaParser.EXTENDS, 0); }
		public TerminalNode SUPER() { return getToken(JavaParser.SUPER, 0); }
		public TypeArgumentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeArgument; }
	}

	public final TypeArgumentContext typeArgument() throws RecognitionException {
		TypeArgumentContext _localctx = new TypeArgumentContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_typeArgument);
		int _la;
		try {
			setState(674);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,71,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(662);
				typeType();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(666);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==AT || _la==IDENTIFIER) {
					{
					{
					setState(663);
					annotation();
					}
					}
					setState(668);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(669);
				match(QUESTION);
				setState(672);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==EXTENDS || _la==SUPER) {
					{
					setState(670);
					_la = _input.LA(1);
					if ( !(_la==EXTENDS || _la==SUPER) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(671);
					typeType();
					}
				}

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
	public static class QualifiedNameListContext extends ParserRuleContext {
		public List<QualifiedNameContext> qualifiedName() {
			return getRuleContexts(QualifiedNameContext.class);
		}
		public QualifiedNameContext qualifiedName(int i) {
			return getRuleContext(QualifiedNameContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public QualifiedNameListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_qualifiedNameList; }
	}

	public final QualifiedNameListContext qualifiedNameList() throws RecognitionException {
		QualifiedNameListContext _localctx = new QualifiedNameListContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_qualifiedNameList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(676);
			qualifiedName();
			setState(681);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(677);
				match(COMMA);
				setState(678);
				qualifiedName();
				}
				}
				setState(683);
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
	public static class FormalParametersContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public ReceiverParameterContext receiverParameter() {
			return getRuleContext(ReceiverParameterContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(JavaParser.COMMA, 0); }
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public FormalParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameters; }
	}

	public final FormalParametersContext formalParameters() throws RecognitionException {
		FormalParametersContext _localctx = new FormalParametersContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_formalParameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(684);
			match(LPAREN);
			setState(696);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,76,_ctx) ) {
			case 1:
				{
				setState(686);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223090579141953573L) != 0) || _la==AT || _la==IDENTIFIER) {
					{
					setState(685);
					receiverParameter();
					}
				}

				}
				break;
			case 2:
				{
				setState(688);
				receiverParameter();
				setState(691);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(689);
					match(COMMA);
					setState(690);
					formalParameterList();
					}
				}

				}
				break;
			case 3:
				{
				setState(694);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223090579141986341L) != 0) || _la==AT || _la==IDENTIFIER) {
					{
					setState(693);
					formalParameterList();
					}
				}

				}
				break;
			}
			setState(698);
			match(RPAREN);
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
	public static class ReceiverParameterContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public TerminalNode THIS() { return getToken(JavaParser.THIS, 0); }
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> DOT() { return getTokens(JavaParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(JavaParser.DOT, i);
		}
		public ReceiverParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_receiverParameter; }
	}

	public final ReceiverParameterContext receiverParameter() throws RecognitionException {
		ReceiverParameterContext _localctx = new ReceiverParameterContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_receiverParameter);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(700);
			typeType();
			setState(706);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==IDENTIFIER) {
				{
				{
				setState(701);
				identifier();
				setState(702);
				match(DOT);
				}
				}
				setState(708);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(709);
			match(THIS);
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
	public static class FormalParameterListContext extends ParserRuleContext {
		public List<FormalParameterContext> formalParameter() {
			return getRuleContexts(FormalParameterContext.class);
		}
		public FormalParameterContext formalParameter(int i) {
			return getRuleContext(FormalParameterContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public LastFormalParameterContext lastFormalParameter() {
			return getRuleContext(LastFormalParameterContext.class,0);
		}
		public FormalParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameterList; }
	}

	public final FormalParameterListContext formalParameterList() throws RecognitionException {
		FormalParameterListContext _localctx = new FormalParameterListContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_formalParameterList);
		int _la;
		try {
			int _alt;
			setState(724);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,80,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(711);
				formalParameter();
				setState(716);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,78,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(712);
						match(COMMA);
						setState(713);
						formalParameter();
						}
						} 
					}
					setState(718);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,78,_ctx);
				}
				setState(721);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COMMA) {
					{
					setState(719);
					match(COMMA);
					setState(720);
					lastFormalParameter();
					}
				}

				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(723);
				lastFormalParameter();
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
	public static class FormalParameterContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public VariableDeclaratorIdContext variableDeclaratorId() {
			return getRuleContext(VariableDeclaratorIdContext.class,0);
		}
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public FormalParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formalParameter; }
	}

	public final FormalParameterContext formalParameter() throws RecognitionException {
		FormalParameterContext _localctx = new FormalParameterContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_formalParameter);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(729);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,81,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(726);
					variableModifier();
					}
					} 
				}
				setState(731);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,81,_ctx);
			}
			setState(732);
			typeType();
			setState(733);
			variableDeclaratorId();
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
	public static class LastFormalParameterContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public TerminalNode ELLIPSIS() { return getToken(JavaParser.ELLIPSIS, 0); }
		public VariableDeclaratorIdContext variableDeclaratorId() {
			return getRuleContext(VariableDeclaratorIdContext.class,0);
		}
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public LastFormalParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lastFormalParameter; }
	}

	public final LastFormalParameterContext lastFormalParameter() throws RecognitionException {
		LastFormalParameterContext _localctx = new LastFormalParameterContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_lastFormalParameter);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(738);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,82,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(735);
					variableModifier();
					}
					} 
				}
				setState(740);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,82,_ctx);
			}
			setState(741);
			typeType();
			setState(745);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==AT || _la==IDENTIFIER) {
				{
				{
				setState(742);
				annotation();
				}
				}
				setState(747);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(748);
			match(ELLIPSIS);
			setState(749);
			variableDeclaratorId();
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
	public static class LambdaLVTIListContext extends ParserRuleContext {
		public List<LambdaLVTIParameterContext> lambdaLVTIParameter() {
			return getRuleContexts(LambdaLVTIParameterContext.class);
		}
		public LambdaLVTIParameterContext lambdaLVTIParameter(int i) {
			return getRuleContext(LambdaLVTIParameterContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public LambdaLVTIListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lambdaLVTIList; }
	}

	public final LambdaLVTIListContext lambdaLVTIList() throws RecognitionException {
		LambdaLVTIListContext _localctx = new LambdaLVTIListContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_lambdaLVTIList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(751);
			lambdaLVTIParameter();
			setState(756);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(752);
				match(COMMA);
				setState(753);
				lambdaLVTIParameter();
				}
				}
				setState(758);
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
	public static class LambdaLVTIParameterContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(JavaParser.VAR, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public LambdaLVTIParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lambdaLVTIParameter; }
	}

	public final LambdaLVTIParameterContext lambdaLVTIParameter() throws RecognitionException {
		LambdaLVTIParameterContext _localctx = new LambdaLVTIParameterContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_lambdaLVTIParameter);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(762);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,85,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(759);
					variableModifier();
					}
					} 
				}
				setState(764);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,85,_ctx);
			}
			setState(765);
			match(VAR);
			setState(766);
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
	public static class QualifiedNameContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> DOT() { return getTokens(JavaParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(JavaParser.DOT, i);
		}
		public QualifiedNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_qualifiedName; }
	}

	public final QualifiedNameContext qualifiedName() throws RecognitionException {
		QualifiedNameContext _localctx = new QualifiedNameContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_qualifiedName);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(768);
			identifier();
			setState(773);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,86,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(769);
					match(DOT);
					setState(770);
					identifier();
					}
					} 
				}
				setState(775);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,86,_ctx);
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
	public static class LiteralContext extends ParserRuleContext {
		public IntegerLiteralContext integerLiteral() {
			return getRuleContext(IntegerLiteralContext.class,0);
		}
		public FloatLiteralContext floatLiteral() {
			return getRuleContext(FloatLiteralContext.class,0);
		}
		public TerminalNode CHAR_LITERAL() { return getToken(JavaParser.CHAR_LITERAL, 0); }
		public TerminalNode STRING_LITERAL() { return getToken(JavaParser.STRING_LITERAL, 0); }
		public TerminalNode BOOL_LITERAL() { return getToken(JavaParser.BOOL_LITERAL, 0); }
		public TerminalNode NULL_LITERAL() { return getToken(JavaParser.NULL_LITERAL, 0); }
		public TerminalNode TEXT_BLOCK() { return getToken(JavaParser.TEXT_BLOCK, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 96, RULE_literal);
		try {
			setState(783);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DECIMAL_LITERAL:
			case HEX_LITERAL:
			case OCT_LITERAL:
			case BINARY_LITERAL:
				enterOuterAlt(_localctx, 1);
				{
				setState(776);
				integerLiteral();
				}
				break;
			case FLOAT_LITERAL:
			case HEX_FLOAT_LITERAL:
				enterOuterAlt(_localctx, 2);
				{
				setState(777);
				floatLiteral();
				}
				break;
			case CHAR_LITERAL:
				enterOuterAlt(_localctx, 3);
				{
				setState(778);
				match(CHAR_LITERAL);
				}
				break;
			case STRING_LITERAL:
				enterOuterAlt(_localctx, 4);
				{
				setState(779);
				match(STRING_LITERAL);
				}
				break;
			case BOOL_LITERAL:
				enterOuterAlt(_localctx, 5);
				{
				setState(780);
				match(BOOL_LITERAL);
				}
				break;
			case NULL_LITERAL:
				enterOuterAlt(_localctx, 6);
				{
				setState(781);
				match(NULL_LITERAL);
				}
				break;
			case TEXT_BLOCK:
				enterOuterAlt(_localctx, 7);
				{
				setState(782);
				match(TEXT_BLOCK);
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
	public static class IntegerLiteralContext extends ParserRuleContext {
		public TerminalNode DECIMAL_LITERAL() { return getToken(JavaParser.DECIMAL_LITERAL, 0); }
		public TerminalNode HEX_LITERAL() { return getToken(JavaParser.HEX_LITERAL, 0); }
		public TerminalNode OCT_LITERAL() { return getToken(JavaParser.OCT_LITERAL, 0); }
		public TerminalNode BINARY_LITERAL() { return getToken(JavaParser.BINARY_LITERAL, 0); }
		public IntegerLiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integerLiteral; }
	}

	public final IntegerLiteralContext integerLiteral() throws RecognitionException {
		IntegerLiteralContext _localctx = new IntegerLiteralContext(_ctx, getState());
		enterRule(_localctx, 98, RULE_integerLiteral);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(785);
			_la = _input.LA(1);
			if ( !(((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 15L) != 0)) ) {
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
	public static class FloatLiteralContext extends ParserRuleContext {
		public TerminalNode FLOAT_LITERAL() { return getToken(JavaParser.FLOAT_LITERAL, 0); }
		public TerminalNode HEX_FLOAT_LITERAL() { return getToken(JavaParser.HEX_FLOAT_LITERAL, 0); }
		public FloatLiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_floatLiteral; }
	}

	public final FloatLiteralContext floatLiteral() throws RecognitionException {
		FloatLiteralContext _localctx = new FloatLiteralContext(_ctx, getState());
		enterRule(_localctx, 100, RULE_floatLiteral);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(787);
			_la = _input.LA(1);
			if ( !(_la==FLOAT_LITERAL || _la==HEX_FLOAT_LITERAL) ) {
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
	public static class AltAnnotationQualifiedNameContext extends ParserRuleContext {
		public TerminalNode AT() { return getToken(JavaParser.AT, 0); }
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TerminalNode> DOT() { return getTokens(JavaParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(JavaParser.DOT, i);
		}
		public AltAnnotationQualifiedNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_altAnnotationQualifiedName; }
	}

	public final AltAnnotationQualifiedNameContext altAnnotationQualifiedName() throws RecognitionException {
		AltAnnotationQualifiedNameContext _localctx = new AltAnnotationQualifiedNameContext(_ctx, getState());
		enterRule(_localctx, 102, RULE_altAnnotationQualifiedName);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(794);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==IDENTIFIER) {
				{
				{
				setState(789);
				identifier();
				setState(790);
				match(DOT);
				}
				}
				setState(796);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(797);
			match(AT);
			setState(798);
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
	public static class AnnotationContext extends ParserRuleContext {
		public TerminalNode AT() { return getToken(JavaParser.AT, 0); }
		public QualifiedNameContext qualifiedName() {
			return getRuleContext(QualifiedNameContext.class,0);
		}
		public AltAnnotationQualifiedNameContext altAnnotationQualifiedName() {
			return getRuleContext(AltAnnotationQualifiedNameContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public ElementValuePairsContext elementValuePairs() {
			return getRuleContext(ElementValuePairsContext.class,0);
		}
		public ElementValueContext elementValue() {
			return getRuleContext(ElementValueContext.class,0);
		}
		public AnnotationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotation; }
	}

	public final AnnotationContext annotation() throws RecognitionException {
		AnnotationContext _localctx = new AnnotationContext(_ctx, getState());
		enterRule(_localctx, 104, RULE_annotation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(803);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,89,_ctx) ) {
			case 1:
				{
				setState(800);
				match(AT);
				setState(801);
				qualifiedName();
				}
				break;
			case 2:
				{
				setState(802);
				altAnnotationQualifiedName();
				}
				break;
			}
			setState(811);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LPAREN) {
				{
				setState(805);
				match(LPAREN);
				setState(808);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,90,_ctx) ) {
				case 1:
					{
					setState(806);
					elementValuePairs();
					}
					break;
				case 2:
					{
					setState(807);
					elementValue();
					}
					break;
				}
				setState(810);
				match(RPAREN);
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
	public static class ElementValuePairsContext extends ParserRuleContext {
		public List<ElementValuePairContext> elementValuePair() {
			return getRuleContexts(ElementValuePairContext.class);
		}
		public ElementValuePairContext elementValuePair(int i) {
			return getRuleContext(ElementValuePairContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public ElementValuePairsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elementValuePairs; }
	}

	public final ElementValuePairsContext elementValuePairs() throws RecognitionException {
		ElementValuePairsContext _localctx = new ElementValuePairsContext(_ctx, getState());
		enterRule(_localctx, 106, RULE_elementValuePairs);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(813);
			elementValuePair();
			setState(818);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(814);
				match(COMMA);
				setState(815);
				elementValuePair();
				}
				}
				setState(820);
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
	public static class ElementValuePairContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(JavaParser.ASSIGN, 0); }
		public ElementValueContext elementValue() {
			return getRuleContext(ElementValueContext.class,0);
		}
		public ElementValuePairContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elementValuePair; }
	}

	public final ElementValuePairContext elementValuePair() throws RecognitionException {
		ElementValuePairContext _localctx = new ElementValuePairContext(_ctx, getState());
		enterRule(_localctx, 108, RULE_elementValuePair);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(821);
			identifier();
			setState(822);
			match(ASSIGN);
			setState(823);
			elementValue();
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
	public static class ElementValueContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public AnnotationContext annotation() {
			return getRuleContext(AnnotationContext.class,0);
		}
		public ElementValueArrayInitializerContext elementValueArrayInitializer() {
			return getRuleContext(ElementValueArrayInitializerContext.class,0);
		}
		public ElementValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elementValue; }
	}

	public final ElementValueContext elementValue() throws RecognitionException {
		ElementValueContext _localctx = new ElementValueContext(_ctx, getState());
		enterRule(_localctx, 110, RULE_elementValue);
		try {
			setState(828);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,93,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(825);
				expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(826);
				annotation();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(827);
				elementValueArrayInitializer();
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
	public static class ElementValueArrayInitializerContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<ElementValueContext> elementValue() {
			return getRuleContexts(ElementValueContext.class);
		}
		public ElementValueContext elementValue(int i) {
			return getRuleContext(ElementValueContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public ElementValueArrayInitializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_elementValueArrayInitializer; }
	}

	public final ElementValueArrayInitializerContext elementValueArrayInitializer() throws RecognitionException {
		ElementValueArrayInitializerContext _localctx = new ElementValueArrayInitializerContext(_ctx, getState());
		enterRule(_localctx, 112, RULE_elementValueArrayInitializer);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(830);
			match(LBRACE);
			setState(839);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130013183L) != 0)) {
				{
				setState(831);
				elementValue();
				setState(836);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,94,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(832);
						match(COMMA);
						setState(833);
						elementValue();
						}
						} 
					}
					setState(838);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,94,_ctx);
				}
				}
			}

			setState(842);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COMMA) {
				{
				setState(841);
				match(COMMA);
				}
			}

			setState(844);
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
	public static class AnnotationTypeDeclarationContext extends ParserRuleContext {
		public TerminalNode AT() { return getToken(JavaParser.AT, 0); }
		public TerminalNode INTERFACE() { return getToken(JavaParser.INTERFACE, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public AnnotationTypeBodyContext annotationTypeBody() {
			return getRuleContext(AnnotationTypeBodyContext.class,0);
		}
		public AnnotationTypeDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotationTypeDeclaration; }
	}

	public final AnnotationTypeDeclarationContext annotationTypeDeclaration() throws RecognitionException {
		AnnotationTypeDeclarationContext _localctx = new AnnotationTypeDeclarationContext(_ctx, getState());
		enterRule(_localctx, 114, RULE_annotationTypeDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(846);
			match(AT);
			setState(847);
			match(INTERFACE);
			setState(848);
			identifier();
			setState(849);
			annotationTypeBody();
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
	public static class AnnotationTypeBodyContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<AnnotationTypeElementDeclarationContext> annotationTypeElementDeclaration() {
			return getRuleContexts(AnnotationTypeElementDeclarationContext.class);
		}
		public AnnotationTypeElementDeclarationContext annotationTypeElementDeclaration(int i) {
			return getRuleContext(AnnotationTypeElementDeclarationContext.class,i);
		}
		public AnnotationTypeBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotationTypeBody; }
	}

	public final AnnotationTypeBodyContext annotationTypeBody() throws RecognitionException {
		AnnotationTypeBodyContext _localctx = new AnnotationTypeBodyContext(_ctx, getState());
		enterRule(_localctx, 116, RULE_annotationTypeBody);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(851);
			match(LBRACE);
			setState(855);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -806529426349675L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141660702539773L) != 0)) {
				{
				{
				setState(852);
				annotationTypeElementDeclaration();
				}
				}
				setState(857);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(858);
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
	public static class AnnotationTypeElementDeclarationContext extends ParserRuleContext {
		public AnnotationTypeElementRestContext annotationTypeElementRest() {
			return getRuleContext(AnnotationTypeElementRestContext.class,0);
		}
		public List<ModifierContext> modifier() {
			return getRuleContexts(ModifierContext.class);
		}
		public ModifierContext modifier(int i) {
			return getRuleContext(ModifierContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public AnnotationTypeElementDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotationTypeElementDeclaration; }
	}

	public final AnnotationTypeElementDeclarationContext annotationTypeElementDeclaration() throws RecognitionException {
		AnnotationTypeElementDeclarationContext _localctx = new AnnotationTypeElementDeclarationContext(_ctx, getState());
		enterRule(_localctx, 118, RULE_annotationTypeElementDeclaration);
		try {
			int _alt;
			setState(868);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ABSTRACT:
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case CLASS:
			case DOUBLE:
			case ENUM:
			case FINAL:
			case FLOAT:
			case INT:
			case INTERFACE:
			case LONG:
			case NATIVE:
			case PRIVATE:
			case PROTECTED:
			case PUBLIC:
			case SHORT:
			case STATIC:
			case STRICTFP:
			case SYNCHRONIZED:
			case TRANSIENT:
			case VOLATILE:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case NON_SEALED:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(863);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,98,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(860);
						modifier();
						}
						} 
					}
					setState(865);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,98,_ctx);
				}
				setState(866);
				annotationTypeElementRest();
				}
				break;
			case SEMI:
				enterOuterAlt(_localctx, 2);
				{
				setState(867);
				match(SEMI);
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
	public static class AnnotationTypeElementRestContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public AnnotationMethodOrConstantRestContext annotationMethodOrConstantRest() {
			return getRuleContext(AnnotationMethodOrConstantRestContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public ClassDeclarationContext classDeclaration() {
			return getRuleContext(ClassDeclarationContext.class,0);
		}
		public InterfaceDeclarationContext interfaceDeclaration() {
			return getRuleContext(InterfaceDeclarationContext.class,0);
		}
		public EnumDeclarationContext enumDeclaration() {
			return getRuleContext(EnumDeclarationContext.class,0);
		}
		public AnnotationTypeDeclarationContext annotationTypeDeclaration() {
			return getRuleContext(AnnotationTypeDeclarationContext.class,0);
		}
		public RecordDeclarationContext recordDeclaration() {
			return getRuleContext(RecordDeclarationContext.class,0);
		}
		public AnnotationTypeElementRestContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotationTypeElementRest; }
	}

	public final AnnotationTypeElementRestContext annotationTypeElementRest() throws RecognitionException {
		AnnotationTypeElementRestContext _localctx = new AnnotationTypeElementRestContext(_ctx, getState());
		enterRule(_localctx, 120, RULE_annotationTypeElementRest);
		try {
			setState(894);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,105,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(870);
				typeType();
				setState(871);
				annotationMethodOrConstantRest();
				setState(872);
				match(SEMI);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(874);
				classDeclaration();
				setState(876);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,100,_ctx) ) {
				case 1:
					{
					setState(875);
					match(SEMI);
					}
					break;
				}
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(878);
				interfaceDeclaration();
				setState(880);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,101,_ctx) ) {
				case 1:
					{
					setState(879);
					match(SEMI);
					}
					break;
				}
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(882);
				enumDeclaration();
				setState(884);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,102,_ctx) ) {
				case 1:
					{
					setState(883);
					match(SEMI);
					}
					break;
				}
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(886);
				annotationTypeDeclaration();
				setState(888);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,103,_ctx) ) {
				case 1:
					{
					setState(887);
					match(SEMI);
					}
					break;
				}
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(890);
				recordDeclaration();
				setState(892);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,104,_ctx) ) {
				case 1:
					{
					setState(891);
					match(SEMI);
					}
					break;
				}
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
	public static class AnnotationMethodOrConstantRestContext extends ParserRuleContext {
		public AnnotationMethodRestContext annotationMethodRest() {
			return getRuleContext(AnnotationMethodRestContext.class,0);
		}
		public AnnotationConstantRestContext annotationConstantRest() {
			return getRuleContext(AnnotationConstantRestContext.class,0);
		}
		public AnnotationMethodOrConstantRestContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotationMethodOrConstantRest; }
	}

	public final AnnotationMethodOrConstantRestContext annotationMethodOrConstantRest() throws RecognitionException {
		AnnotationMethodOrConstantRestContext _localctx = new AnnotationMethodOrConstantRestContext(_ctx, getState());
		enterRule(_localctx, 122, RULE_annotationMethodOrConstantRest);
		try {
			setState(898);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,106,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(896);
				annotationMethodRest();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(897);
				annotationConstantRest();
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
	public static class AnnotationMethodRestContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public DefaultValueContext defaultValue() {
			return getRuleContext(DefaultValueContext.class,0);
		}
		public AnnotationMethodRestContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotationMethodRest; }
	}

	public final AnnotationMethodRestContext annotationMethodRest() throws RecognitionException {
		AnnotationMethodRestContext _localctx = new AnnotationMethodRestContext(_ctx, getState());
		enterRule(_localctx, 124, RULE_annotationMethodRest);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(900);
			identifier();
			setState(901);
			match(LPAREN);
			setState(902);
			match(RPAREN);
			setState(904);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==DEFAULT) {
				{
				setState(903);
				defaultValue();
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
	public static class AnnotationConstantRestContext extends ParserRuleContext {
		public VariableDeclaratorsContext variableDeclarators() {
			return getRuleContext(VariableDeclaratorsContext.class,0);
		}
		public AnnotationConstantRestContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_annotationConstantRest; }
	}

	public final AnnotationConstantRestContext annotationConstantRest() throws RecognitionException {
		AnnotationConstantRestContext _localctx = new AnnotationConstantRestContext(_ctx, getState());
		enterRule(_localctx, 126, RULE_annotationConstantRest);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(906);
			variableDeclarators();
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
	public static class DefaultValueContext extends ParserRuleContext {
		public TerminalNode DEFAULT() { return getToken(JavaParser.DEFAULT, 0); }
		public ElementValueContext elementValue() {
			return getRuleContext(ElementValueContext.class,0);
		}
		public DefaultValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_defaultValue; }
	}

	public final DefaultValueContext defaultValue() throws RecognitionException {
		DefaultValueContext _localctx = new DefaultValueContext(_ctx, getState());
		enterRule(_localctx, 128, RULE_defaultValue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(908);
			match(DEFAULT);
			setState(909);
			elementValue();
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
	public static class ModuleDeclarationContext extends ParserRuleContext {
		public TerminalNode MODULE() { return getToken(JavaParser.MODULE, 0); }
		public QualifiedNameContext qualifiedName() {
			return getRuleContext(QualifiedNameContext.class,0);
		}
		public ModuleBodyContext moduleBody() {
			return getRuleContext(ModuleBodyContext.class,0);
		}
		public TerminalNode OPEN() { return getToken(JavaParser.OPEN, 0); }
		public ModuleDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_moduleDeclaration; }
	}

	public final ModuleDeclarationContext moduleDeclaration() throws RecognitionException {
		ModuleDeclarationContext _localctx = new ModuleDeclarationContext(_ctx, getState());
		enterRule(_localctx, 130, RULE_moduleDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(912);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==OPEN) {
				{
				setState(911);
				match(OPEN);
				}
			}

			setState(914);
			match(MODULE);
			setState(915);
			qualifiedName();
			setState(916);
			moduleBody();
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
	public static class ModuleBodyContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<ModuleDirectiveContext> moduleDirective() {
			return getRuleContexts(ModuleDirectiveContext.class);
		}
		public ModuleDirectiveContext moduleDirective(int i) {
			return getRuleContext(ModuleDirectiveContext.class,i);
		}
		public ModuleBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_moduleBody; }
	}

	public final ModuleBodyContext moduleBody() throws RecognitionException {
		ModuleBodyContext _localctx = new ModuleBodyContext(_ctx, getState());
		enterRule(_localctx, 132, RULE_moduleBody);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(918);
			match(LBRACE);
			setState(922);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 495395959010754560L) != 0)) {
				{
				{
				setState(919);
				moduleDirective();
				}
				}
				setState(924);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(925);
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
	public static class ModuleDirectiveContext extends ParserRuleContext {
		public TerminalNode REQUIRES() { return getToken(JavaParser.REQUIRES, 0); }
		public List<QualifiedNameContext> qualifiedName() {
			return getRuleContexts(QualifiedNameContext.class);
		}
		public QualifiedNameContext qualifiedName(int i) {
			return getRuleContext(QualifiedNameContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public List<RequiresModifierContext> requiresModifier() {
			return getRuleContexts(RequiresModifierContext.class);
		}
		public RequiresModifierContext requiresModifier(int i) {
			return getRuleContext(RequiresModifierContext.class,i);
		}
		public TerminalNode EXPORTS() { return getToken(JavaParser.EXPORTS, 0); }
		public TerminalNode TO() { return getToken(JavaParser.TO, 0); }
		public TerminalNode OPENS() { return getToken(JavaParser.OPENS, 0); }
		public TerminalNode USES() { return getToken(JavaParser.USES, 0); }
		public TerminalNode PROVIDES() { return getToken(JavaParser.PROVIDES, 0); }
		public TerminalNode WITH() { return getToken(JavaParser.WITH, 0); }
		public ModuleDirectiveContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_moduleDirective; }
	}

	public final ModuleDirectiveContext moduleDirective() throws RecognitionException {
		ModuleDirectiveContext _localctx = new ModuleDirectiveContext(_ctx, getState());
		enterRule(_localctx, 134, RULE_moduleDirective);
		int _la;
		try {
			int _alt;
			setState(963);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case REQUIRES:
				enterOuterAlt(_localctx, 1);
				{
				setState(927);
				match(REQUIRES);
				setState(931);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,110,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(928);
						requiresModifier();
						}
						} 
					}
					setState(933);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,110,_ctx);
				}
				setState(934);
				qualifiedName();
				setState(935);
				match(SEMI);
				}
				break;
			case EXPORTS:
				enterOuterAlt(_localctx, 2);
				{
				setState(937);
				match(EXPORTS);
				setState(938);
				qualifiedName();
				setState(941);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==TO) {
					{
					setState(939);
					match(TO);
					setState(940);
					qualifiedName();
					}
				}

				setState(943);
				match(SEMI);
				}
				break;
			case OPENS:
				enterOuterAlt(_localctx, 3);
				{
				setState(945);
				match(OPENS);
				setState(946);
				qualifiedName();
				setState(949);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==TO) {
					{
					setState(947);
					match(TO);
					setState(948);
					qualifiedName();
					}
				}

				setState(951);
				match(SEMI);
				}
				break;
			case USES:
				enterOuterAlt(_localctx, 4);
				{
				setState(953);
				match(USES);
				setState(954);
				qualifiedName();
				setState(955);
				match(SEMI);
				}
				break;
			case PROVIDES:
				enterOuterAlt(_localctx, 5);
				{
				setState(957);
				match(PROVIDES);
				setState(958);
				qualifiedName();
				setState(959);
				match(WITH);
				setState(960);
				qualifiedName();
				setState(961);
				match(SEMI);
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
	public static class RequiresModifierContext extends ParserRuleContext {
		public TerminalNode TRANSITIVE() { return getToken(JavaParser.TRANSITIVE, 0); }
		public TerminalNode STATIC() { return getToken(JavaParser.STATIC, 0); }
		public RequiresModifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_requiresModifier; }
	}

	public final RequiresModifierContext requiresModifier() throws RecognitionException {
		RequiresModifierContext _localctx = new RequiresModifierContext(_ctx, getState());
		enterRule(_localctx, 136, RULE_requiresModifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(965);
			_la = _input.LA(1);
			if ( !(_la==STATIC || _la==TRANSITIVE) ) {
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
	public static class RecordDeclarationContext extends ParserRuleContext {
		public TerminalNode RECORD() { return getToken(JavaParser.RECORD, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public RecordHeaderContext recordHeader() {
			return getRuleContext(RecordHeaderContext.class,0);
		}
		public RecordBodyContext recordBody() {
			return getRuleContext(RecordBodyContext.class,0);
		}
		public TypeParametersContext typeParameters() {
			return getRuleContext(TypeParametersContext.class,0);
		}
		public TerminalNode IMPLEMENTS() { return getToken(JavaParser.IMPLEMENTS, 0); }
		public TypeListContext typeList() {
			return getRuleContext(TypeListContext.class,0);
		}
		public RecordDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordDeclaration; }
	}

	public final RecordDeclarationContext recordDeclaration() throws RecognitionException {
		RecordDeclarationContext _localctx = new RecordDeclarationContext(_ctx, getState());
		enterRule(_localctx, 138, RULE_recordDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(967);
			match(RECORD);
			setState(968);
			identifier();
			setState(970);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(969);
				typeParameters();
				}
			}

			setState(972);
			recordHeader();
			setState(975);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IMPLEMENTS) {
				{
				setState(973);
				match(IMPLEMENTS);
				setState(974);
				typeList();
				}
			}

			setState(977);
			recordBody();
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
	public static class RecordHeaderContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public RecordComponentListContext recordComponentList() {
			return getRuleContext(RecordComponentListContext.class,0);
		}
		public RecordHeaderContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordHeader; }
	}

	public final RecordHeaderContext recordHeader() throws RecognitionException {
		RecordHeaderContext _localctx = new RecordHeaderContext(_ctx, getState());
		enterRule(_localctx, 140, RULE_recordHeader);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(979);
			match(LPAREN);
			setState(981);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223090579141953573L) != 0) || _la==AT || _la==IDENTIFIER) {
				{
				setState(980);
				recordComponentList();
				}
			}

			setState(983);
			match(RPAREN);
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
	public static class RecordComponentListContext extends ParserRuleContext {
		public List<RecordComponentContext> recordComponent() {
			return getRuleContexts(RecordComponentContext.class);
		}
		public RecordComponentContext recordComponent(int i) {
			return getRuleContext(RecordComponentContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public RecordComponentListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordComponentList; }
	}

	public final RecordComponentListContext recordComponentList() throws RecognitionException {
		RecordComponentListContext _localctx = new RecordComponentListContext(_ctx, getState());
		enterRule(_localctx, 142, RULE_recordComponentList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(985);
			recordComponent();
			setState(990);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(986);
				match(COMMA);
				setState(987);
				recordComponent();
				}
				}
				setState(992);
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
	public static class RecordComponentContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public RecordComponentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordComponent; }
	}

	public final RecordComponentContext recordComponent() throws RecognitionException {
		RecordComponentContext _localctx = new RecordComponentContext(_ctx, getState());
		enterRule(_localctx, 144, RULE_recordComponent);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(993);
			typeType();
			setState(994);
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
	public static class RecordBodyContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<ClassBodyDeclarationContext> classBodyDeclaration() {
			return getRuleContexts(ClassBodyDeclarationContext.class);
		}
		public ClassBodyDeclarationContext classBodyDeclaration(int i) {
			return getRuleContext(ClassBodyDeclarationContext.class,i);
		}
		public RecordBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordBody; }
	}

	public final RecordBodyContext recordBody() throws RecognitionException {
		RecordBodyContext _localctx = new RecordBodyContext(_ctx, getState());
		enterRule(_localctx, 146, RULE_recordBody);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(996);
			match(LBRACE);
			setState(1000);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -665791937994347L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141660685729789L) != 0)) {
				{
				{
				setState(997);
				classBodyDeclaration();
				}
				}
				setState(1002);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1003);
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
	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<BlockStatementContext> blockStatement() {
			return getRuleContexts(BlockStatementContext.class);
		}
		public BlockStatementContext blockStatement(int i) {
			return getRuleContext(BlockStatementContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 148, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1005);
			match(LBRACE);
			setState(1009);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -334254282492513L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141145188974593L) != 0)) {
				{
				{
				setState(1006);
				blockStatement();
				}
				}
				setState(1011);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1012);
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
	public static class BlockStatementContext extends ParserRuleContext {
		public LocalVariableDeclarationContext localVariableDeclaration() {
			return getRuleContext(LocalVariableDeclarationContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public LocalTypeDeclarationContext localTypeDeclaration() {
			return getRuleContext(LocalTypeDeclarationContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public BlockStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockStatement; }
	}

	public final BlockStatementContext blockStatement() throws RecognitionException {
		BlockStatementContext _localctx = new BlockStatementContext(_ctx, getState());
		enterRule(_localctx, 150, RULE_blockStatement);
		try {
			setState(1019);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,120,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1014);
				localVariableDeclaration();
				setState(1015);
				match(SEMI);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1017);
				localTypeDeclaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1018);
				statement();
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
	public static class LocalVariableDeclarationContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(JavaParser.VAR, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(JavaParser.ASSIGN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public VariableDeclaratorsContext variableDeclarators() {
			return getRuleContext(VariableDeclaratorsContext.class,0);
		}
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public LocalVariableDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_localVariableDeclaration; }
	}

	public final LocalVariableDeclarationContext localVariableDeclaration() throws RecognitionException {
		LocalVariableDeclarationContext _localctx = new LocalVariableDeclarationContext(_ctx, getState());
		enterRule(_localctx, 152, RULE_localVariableDeclaration);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1024);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,121,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1021);
					variableModifier();
					}
					} 
				}
				setState(1026);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,121,_ctx);
			}
			setState(1035);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,122,_ctx) ) {
			case 1:
				{
				setState(1027);
				match(VAR);
				setState(1028);
				identifier();
				setState(1029);
				match(ASSIGN);
				setState(1030);
				expression(0);
				}
				break;
			case 2:
				{
				setState(1032);
				typeType();
				setState(1033);
				variableDeclarators();
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
	public static class IdentifierContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(JavaParser.IDENTIFIER, 0); }
		public TerminalNode MODULE() { return getToken(JavaParser.MODULE, 0); }
		public TerminalNode OPEN() { return getToken(JavaParser.OPEN, 0); }
		public TerminalNode REQUIRES() { return getToken(JavaParser.REQUIRES, 0); }
		public TerminalNode EXPORTS() { return getToken(JavaParser.EXPORTS, 0); }
		public TerminalNode OPENS() { return getToken(JavaParser.OPENS, 0); }
		public TerminalNode TO() { return getToken(JavaParser.TO, 0); }
		public TerminalNode USES() { return getToken(JavaParser.USES, 0); }
		public TerminalNode PROVIDES() { return getToken(JavaParser.PROVIDES, 0); }
		public TerminalNode WITH() { return getToken(JavaParser.WITH, 0); }
		public TerminalNode TRANSITIVE() { return getToken(JavaParser.TRANSITIVE, 0); }
		public TerminalNode YIELD() { return getToken(JavaParser.YIELD, 0); }
		public TerminalNode SEALED() { return getToken(JavaParser.SEALED, 0); }
		public TerminalNode PERMITS() { return getToken(JavaParser.PERMITS, 0); }
		public TerminalNode RECORD() { return getToken(JavaParser.RECORD, 0); }
		public TerminalNode VAR() { return getToken(JavaParser.VAR, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 154, RULE_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1037);
			_la = _input.LA(1);
			if ( !(((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==IDENTIFIER) ) {
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
	public static class LocalTypeDeclarationContext extends ParserRuleContext {
		public ClassDeclarationContext classDeclaration() {
			return getRuleContext(ClassDeclarationContext.class,0);
		}
		public InterfaceDeclarationContext interfaceDeclaration() {
			return getRuleContext(InterfaceDeclarationContext.class,0);
		}
		public RecordDeclarationContext recordDeclaration() {
			return getRuleContext(RecordDeclarationContext.class,0);
		}
		public List<ClassOrInterfaceModifierContext> classOrInterfaceModifier() {
			return getRuleContexts(ClassOrInterfaceModifierContext.class);
		}
		public ClassOrInterfaceModifierContext classOrInterfaceModifier(int i) {
			return getRuleContext(ClassOrInterfaceModifierContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public LocalTypeDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_localTypeDeclaration; }
	}

	public final LocalTypeDeclarationContext localTypeDeclaration() throws RecognitionException {
		LocalTypeDeclarationContext _localctx = new LocalTypeDeclarationContext(_ctx, getState());
		enterRule(_localctx, 156, RULE_localTypeDeclaration);
		try {
			int _alt;
			setState(1051);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ABSTRACT:
			case CLASS:
			case FINAL:
			case INTERFACE:
			case PRIVATE:
			case PROTECTED:
			case PUBLIC:
			case STATIC:
			case STRICTFP:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case NON_SEALED:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(1042);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,123,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1039);
						classOrInterfaceModifier();
						}
						} 
					}
					setState(1044);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,123,_ctx);
				}
				setState(1048);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case CLASS:
					{
					setState(1045);
					classDeclaration();
					}
					break;
				case INTERFACE:
					{
					setState(1046);
					interfaceDeclaration();
					}
					break;
				case RECORD:
					{
					setState(1047);
					recordDeclaration();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case SEMI:
				enterOuterAlt(_localctx, 2);
				{
				setState(1050);
				match(SEMI);
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
	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementThrowContext extends StatementContext {
		public TerminalNode THROW() { return getToken(JavaParser.THROW, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public StatementThrowContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementContinueContext extends StatementContext {
		public TerminalNode CONTINUE() { return getToken(JavaParser.CONTINUE, 0); }
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public StatementContinueContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementSemiContext extends StatementContext {
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public StatementSemiContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementReturnContext extends StatementContext {
		public TerminalNode RETURN() { return getToken(JavaParser.RETURN, 0); }
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public StatementReturnContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementSwitchExpContext extends StatementContext {
		public SwitchExpressionContext switchExpression() {
			return getRuleContext(SwitchExpressionContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public StatementSwitchExpContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementForContext extends StatementContext {
		public TerminalNode FOR() { return getToken(JavaParser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public ForControlContext forControl() {
			return getRuleContext(ForControlContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementForContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementYieldContext extends StatementContext {
		public TerminalNode YIELD() { return getToken(JavaParser.YIELD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public StatementYieldContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementLabelContext extends StatementContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode COLON() { return getToken(JavaParser.COLON, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementLabelContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementBlockContext extends StatementContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public StatementBlockContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementAssertContext extends StatementContext {
		public TerminalNode ASSERT() { return getToken(JavaParser.ASSERT, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public TerminalNode COLON() { return getToken(JavaParser.COLON, 0); }
		public StatementAssertContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementSwitchContext extends StatementContext {
		public TerminalNode SWITCH() { return getToken(JavaParser.SWITCH, 0); }
		public ParExpressionContext parExpression() {
			return getRuleContext(ParExpressionContext.class,0);
		}
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<SwitchBlockStatementGroupContext> switchBlockStatementGroup() {
			return getRuleContexts(SwitchBlockStatementGroupContext.class);
		}
		public SwitchBlockStatementGroupContext switchBlockStatementGroup(int i) {
			return getRuleContext(SwitchBlockStatementGroupContext.class,i);
		}
		public List<SwitchLabelContext> switchLabel() {
			return getRuleContexts(SwitchLabelContext.class);
		}
		public SwitchLabelContext switchLabel(int i) {
			return getRuleContext(SwitchLabelContext.class,i);
		}
		public StatementSwitchContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementBreakContext extends StatementContext {
		public TerminalNode BREAK() { return getToken(JavaParser.BREAK, 0); }
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public StatementBreakContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementDoWhileContext extends StatementContext {
		public TerminalNode DO() { return getToken(JavaParser.DO, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public TerminalNode WHILE() { return getToken(JavaParser.WHILE, 0); }
		public ParExpressionContext parExpression() {
			return getRuleContext(ParExpressionContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public StatementDoWhileContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementExpContext extends StatementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public StatementExpContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementTryContext extends StatementContext {
		public TerminalNode TRY() { return getToken(JavaParser.TRY, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FinallyBlockContext finallyBlock() {
			return getRuleContext(FinallyBlockContext.class,0);
		}
		public List<CatchClauseContext> catchClause() {
			return getRuleContexts(CatchClauseContext.class);
		}
		public CatchClauseContext catchClause(int i) {
			return getRuleContext(CatchClauseContext.class,i);
		}
		public ResourceSpecificationContext resourceSpecification() {
			return getRuleContext(ResourceSpecificationContext.class,0);
		}
		public StatementTryContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementSyncContext extends StatementContext {
		public TerminalNode SYNCHRONIZED() { return getToken(JavaParser.SYNCHRONIZED, 0); }
		public ParExpressionContext parExpression() {
			return getRuleContext(ParExpressionContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public StatementSyncContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementWhileContext extends StatementContext {
		public TerminalNode WHILE() { return getToken(JavaParser.WHILE, 0); }
		public ParExpressionContext parExpression() {
			return getRuleContext(ParExpressionContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementWhileContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StatementIfContext extends StatementContext {
		public StatementContext ifState;
		public StatementContext elseState;
		public TerminalNode IF() { return getToken(JavaParser.IF, 0); }
		public ParExpressionContext parExpression() {
			return getRuleContext(ParExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(JavaParser.ELSE, 0); }
		public StatementIfContext(StatementContext ctx) { copyFrom(ctx); }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 158, RULE_statement);
		int _la;
		try {
			int _alt;
			setState(1166);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,139,_ctx) ) {
			case 1:
				_localctx = new StatementBlockContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(1053);
				block();
				}
				break;
			case 2:
				_localctx = new StatementAssertContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(1054);
				match(ASSERT);
				setState(1055);
				expression(0);
				setState(1058);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==COLON) {
					{
					setState(1056);
					match(COLON);
					setState(1057);
					expression(0);
					}
				}

				setState(1060);
				match(SEMI);
				}
				break;
			case 3:
				_localctx = new StatementIfContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(1062);
				match(IF);
				setState(1063);
				parExpression();
				setState(1064);
				((StatementIfContext)_localctx).ifState = statement();
				setState(1067);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,127,_ctx) ) {
				case 1:
					{
					setState(1065);
					match(ELSE);
					setState(1066);
					((StatementIfContext)_localctx).elseState = statement();
					}
					break;
				}
				}
				break;
			case 4:
				_localctx = new StatementForContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(1069);
				match(FOR);
				setState(1070);
				match(LPAREN);
				setState(1071);
				forControl();
				setState(1072);
				match(RPAREN);
				setState(1073);
				statement();
				}
				break;
			case 5:
				_localctx = new StatementWhileContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(1075);
				match(WHILE);
				setState(1076);
				parExpression();
				setState(1077);
				statement();
				}
				break;
			case 6:
				_localctx = new StatementDoWhileContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(1079);
				match(DO);
				setState(1080);
				statement();
				setState(1081);
				match(WHILE);
				setState(1082);
				parExpression();
				setState(1083);
				match(SEMI);
				}
				break;
			case 7:
				_localctx = new StatementSwitchContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(1085);
				match(SWITCH);
				setState(1086);
				parExpression();
				setState(1087);
				match(LBRACE);
				setState(1091);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,128,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1088);
						switchBlockStatementGroup();
						}
						} 
					}
					setState(1093);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,128,_ctx);
				}
				setState(1097);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==CASE || _la==DEFAULT) {
					{
					{
					setState(1094);
					switchLabel();
					}
					}
					setState(1099);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1100);
				match(RBRACE);
				}
				break;
			case 8:
				_localctx = new StatementTryContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(1102);
				match(TRY);
				setState(1103);
				block();
				setState(1113);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case CATCH:
					{
					setState(1105); 
					_errHandler.sync(this);
					_la = _input.LA(1);
					do {
						{
						{
						setState(1104);
						catchClause();
						}
						}
						setState(1107); 
						_errHandler.sync(this);
						_la = _input.LA(1);
					} while ( _la==CATCH );
					setState(1110);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==FINALLY) {
						{
						setState(1109);
						finallyBlock();
						}
					}

					}
					break;
				case FINALLY:
					{
					setState(1112);
					finallyBlock();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case 9:
				_localctx = new StatementTryContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(1115);
				match(TRY);
				setState(1116);
				resourceSpecification();
				setState(1117);
				block();
				setState(1121);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==CATCH) {
					{
					{
					setState(1118);
					catchClause();
					}
					}
					setState(1123);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1125);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==FINALLY) {
					{
					setState(1124);
					finallyBlock();
					}
				}

				}
				break;
			case 10:
				_localctx = new StatementSyncContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(1127);
				match(SYNCHRONIZED);
				setState(1128);
				parExpression();
				setState(1129);
				block();
				}
				break;
			case 11:
				_localctx = new StatementReturnContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(1131);
				match(RETURN);
				setState(1133);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130004991L) != 0)) {
					{
					setState(1132);
					expression(0);
					}
				}

				setState(1135);
				match(SEMI);
				}
				break;
			case 12:
				_localctx = new StatementThrowContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(1136);
				match(THROW);
				setState(1137);
				expression(0);
				setState(1138);
				match(SEMI);
				}
				break;
			case 13:
				_localctx = new StatementBreakContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(1140);
				match(BREAK);
				setState(1142);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==IDENTIFIER) {
					{
					setState(1141);
					identifier();
					}
				}

				setState(1144);
				match(SEMI);
				}
				break;
			case 14:
				_localctx = new StatementContinueContext(_localctx);
				enterOuterAlt(_localctx, 14);
				{
				setState(1145);
				match(CONTINUE);
				setState(1147);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==IDENTIFIER) {
					{
					setState(1146);
					identifier();
					}
				}

				setState(1149);
				match(SEMI);
				}
				break;
			case 15:
				_localctx = new StatementYieldContext(_localctx);
				enterOuterAlt(_localctx, 15);
				{
				setState(1150);
				match(YIELD);
				setState(1151);
				expression(0);
				setState(1152);
				match(SEMI);
				}
				break;
			case 16:
				_localctx = new StatementSemiContext(_localctx);
				enterOuterAlt(_localctx, 16);
				{
				setState(1154);
				match(SEMI);
				}
				break;
			case 17:
				_localctx = new StatementExpContext(_localctx);
				enterOuterAlt(_localctx, 17);
				{
				setState(1155);
				expression(0);
				setState(1156);
				match(SEMI);
				}
				break;
			case 18:
				_localctx = new StatementSwitchExpContext(_localctx);
				enterOuterAlt(_localctx, 18);
				{
				setState(1158);
				switchExpression();
				setState(1160);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,138,_ctx) ) {
				case 1:
					{
					setState(1159);
					match(SEMI);
					}
					break;
				}
				}
				break;
			case 19:
				_localctx = new StatementLabelContext(_localctx);
				enterOuterAlt(_localctx, 19);
				{
				setState(1162);
				identifier();
				setState(1163);
				match(COLON);
				setState(1164);
				statement();
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
	public static class CatchClauseContext extends ParserRuleContext {
		public TerminalNode CATCH() { return getToken(JavaParser.CATCH, 0); }
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public CatchTypeContext catchType() {
			return getRuleContext(CatchTypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public CatchClauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_catchClause; }
	}

	public final CatchClauseContext catchClause() throws RecognitionException {
		CatchClauseContext _localctx = new CatchClauseContext(_ctx, getState());
		enterRule(_localctx, 160, RULE_catchClause);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1168);
			match(CATCH);
			setState(1169);
			match(LPAREN);
			setState(1173);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,140,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1170);
					variableModifier();
					}
					} 
				}
				setState(1175);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,140,_ctx);
			}
			setState(1176);
			catchType();
			setState(1177);
			identifier();
			setState(1178);
			match(RPAREN);
			setState(1179);
			block();
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
	public static class CatchTypeContext extends ParserRuleContext {
		public List<QualifiedNameContext> qualifiedName() {
			return getRuleContexts(QualifiedNameContext.class);
		}
		public QualifiedNameContext qualifiedName(int i) {
			return getRuleContext(QualifiedNameContext.class,i);
		}
		public List<TerminalNode> BITOR() { return getTokens(JavaParser.BITOR); }
		public TerminalNode BITOR(int i) {
			return getToken(JavaParser.BITOR, i);
		}
		public CatchTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_catchType; }
	}

	public final CatchTypeContext catchType() throws RecognitionException {
		CatchTypeContext _localctx = new CatchTypeContext(_ctx, getState());
		enterRule(_localctx, 162, RULE_catchType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1181);
			qualifiedName();
			setState(1186);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==BITOR) {
				{
				{
				setState(1182);
				match(BITOR);
				setState(1183);
				qualifiedName();
				}
				}
				setState(1188);
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
	public static class FinallyBlockContext extends ParserRuleContext {
		public TerminalNode FINALLY() { return getToken(JavaParser.FINALLY, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public FinallyBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_finallyBlock; }
	}

	public final FinallyBlockContext finallyBlock() throws RecognitionException {
		FinallyBlockContext _localctx = new FinallyBlockContext(_ctx, getState());
		enterRule(_localctx, 164, RULE_finallyBlock);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1189);
			match(FINALLY);
			setState(1190);
			block();
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
	public static class ResourceSpecificationContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public ResourcesContext resources() {
			return getRuleContext(ResourcesContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public TerminalNode SEMI() { return getToken(JavaParser.SEMI, 0); }
		public ResourceSpecificationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_resourceSpecification; }
	}

	public final ResourceSpecificationContext resourceSpecification() throws RecognitionException {
		ResourceSpecificationContext _localctx = new ResourceSpecificationContext(_ctx, getState());
		enterRule(_localctx, 166, RULE_resourceSpecification);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1192);
			match(LPAREN);
			setState(1193);
			resources();
			setState(1195);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==SEMI) {
				{
				setState(1194);
				match(SEMI);
				}
			}

			setState(1197);
			match(RPAREN);
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
	public static class ResourcesContext extends ParserRuleContext {
		public List<ResourceContext> resource() {
			return getRuleContexts(ResourceContext.class);
		}
		public ResourceContext resource(int i) {
			return getRuleContext(ResourceContext.class,i);
		}
		public List<TerminalNode> SEMI() { return getTokens(JavaParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(JavaParser.SEMI, i);
		}
		public ResourcesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_resources; }
	}

	public final ResourcesContext resources() throws RecognitionException {
		ResourcesContext _localctx = new ResourcesContext(_ctx, getState());
		enterRule(_localctx, 168, RULE_resources);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1199);
			resource();
			setState(1204);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,143,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1200);
					match(SEMI);
					setState(1201);
					resource();
					}
					} 
				}
				setState(1206);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,143,_ctx);
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
	public static class ResourceContext extends ParserRuleContext {
		public TerminalNode ASSIGN() { return getToken(JavaParser.ASSIGN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ClassOrInterfaceTypeContext classOrInterfaceType() {
			return getRuleContext(ClassOrInterfaceTypeContext.class,0);
		}
		public VariableDeclaratorIdContext variableDeclaratorId() {
			return getRuleContext(VariableDeclaratorIdContext.class,0);
		}
		public TerminalNode VAR() { return getToken(JavaParser.VAR, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public ResourceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_resource; }
	}

	public final ResourceContext resource() throws RecognitionException {
		ResourceContext _localctx = new ResourceContext(_ctx, getState());
		enterRule(_localctx, 170, RULE_resource);
		try {
			int _alt;
			setState(1224);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,146,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1210);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,144,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1207);
						variableModifier();
						}
						} 
					}
					setState(1212);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,144,_ctx);
				}
				setState(1218);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,145,_ctx) ) {
				case 1:
					{
					setState(1213);
					classOrInterfaceType();
					setState(1214);
					variableDeclaratorId();
					}
					break;
				case 2:
					{
					setState(1216);
					match(VAR);
					setState(1217);
					identifier();
					}
					break;
				}
				setState(1220);
				match(ASSIGN);
				setState(1221);
				expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1223);
				identifier();
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
	public static class SwitchBlockStatementGroupContext extends ParserRuleContext {
		public List<SwitchLabelContext> switchLabel() {
			return getRuleContexts(SwitchLabelContext.class);
		}
		public SwitchLabelContext switchLabel(int i) {
			return getRuleContext(SwitchLabelContext.class,i);
		}
		public List<BlockStatementContext> blockStatement() {
			return getRuleContexts(BlockStatementContext.class);
		}
		public BlockStatementContext blockStatement(int i) {
			return getRuleContext(BlockStatementContext.class,i);
		}
		public SwitchBlockStatementGroupContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switchBlockStatementGroup; }
	}

	public final SwitchBlockStatementGroupContext switchBlockStatementGroup() throws RecognitionException {
		SwitchBlockStatementGroupContext _localctx = new SwitchBlockStatementGroupContext(_ctx, getState());
		enterRule(_localctx, 172, RULE_switchBlockStatementGroup);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1227); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1226);
				switchLabel();
				}
				}
				setState(1229); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==CASE || _la==DEFAULT );
			setState(1232); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(1231);
				blockStatement();
				}
				}
				setState(1234); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( ((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -334254282492513L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141145188974593L) != 0) );
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
	public static class SwitchLabelContext extends ParserRuleContext {
		public TerminalNode CASE() { return getToken(JavaParser.CASE, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode COLON() { return getToken(JavaParser.COLON, 0); }
		public TerminalNode DEFAULT() { return getToken(JavaParser.DEFAULT, 0); }
		public SwitchLabelContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switchLabel; }
	}

	public final SwitchLabelContext switchLabel() throws RecognitionException {
		SwitchLabelContext _localctx = new SwitchLabelContext(_ctx, getState());
		enterRule(_localctx, 174, RULE_switchLabel);
		try {
			setState(1242);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CASE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1236);
				match(CASE);
				setState(1237);
				expression(0);
				setState(1238);
				match(COLON);
				}
				break;
			case DEFAULT:
				enterOuterAlt(_localctx, 2);
				{
				setState(1240);
				match(DEFAULT);
				setState(1241);
				match(COLON);
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
	public static class ForControlContext extends ParserRuleContext {
		public EnhancedForControlContext enhancedForControl() {
			return getRuleContext(EnhancedForControlContext.class,0);
		}
		public List<TerminalNode> SEMI() { return getTokens(JavaParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(JavaParser.SEMI, i);
		}
		public ForInitContext forInit() {
			return getRuleContext(ForInitContext.class,0);
		}
		public ForConditionContext forCondition() {
			return getRuleContext(ForConditionContext.class,0);
		}
		public ForUpdateContext forUpdate() {
			return getRuleContext(ForUpdateContext.class,0);
		}
		public ForControlContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forControl; }
	}

	public final ForControlContext forControl() throws RecognitionException {
		ForControlContext _localctx = new ForControlContext(_ctx, getState());
		enterRule(_localctx, 176, RULE_forControl);
		int _la;
		try {
			setState(1256);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,153,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1244);
				enhancedForControl();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1246);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610998821L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130004991L) != 0)) {
					{
					setState(1245);
					forInit();
					}
				}

				setState(1248);
				match(SEMI);
				setState(1250);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130004991L) != 0)) {
					{
					setState(1249);
					forCondition();
					}
				}

				setState(1252);
				match(SEMI);
				setState(1254);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130004991L) != 0)) {
					{
					setState(1253);
					forUpdate();
					}
				}

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
	public static class ForInitContext extends ParserRuleContext {
		public LocalVariableDeclarationContext localVariableDeclaration() {
			return getRuleContext(LocalVariableDeclarationContext.class,0);
		}
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public ForInitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forInit; }
	}

	public final ForInitContext forInit() throws RecognitionException {
		ForInitContext _localctx = new ForInitContext(_ctx, getState());
		enterRule(_localctx, 178, RULE_forInit);
		try {
			setState(1260);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,154,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1258);
				localVariableDeclaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1259);
				expressionList();
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
	public static class ForConditionContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ForConditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forCondition; }
	}

	public final ForConditionContext forCondition() throws RecognitionException {
		ForConditionContext _localctx = new ForConditionContext(_ctx, getState());
		enterRule(_localctx, 180, RULE_forCondition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1262);
			expression(0);
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
	public static class ForUpdateContext extends ParserRuleContext {
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public ForUpdateContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forUpdate; }
	}

	public final ForUpdateContext forUpdate() throws RecognitionException {
		ForUpdateContext _localctx = new ForUpdateContext(_ctx, getState());
		enterRule(_localctx, 182, RULE_forUpdate);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1264);
			expressionList();
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
	public static class EnhancedForControlContext extends ParserRuleContext {
		public VariableDeclaratorIdContext variableDeclaratorId() {
			return getRuleContext(VariableDeclaratorIdContext.class,0);
		}
		public TerminalNode COLON() { return getToken(JavaParser.COLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public TerminalNode VAR() { return getToken(JavaParser.VAR, 0); }
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public EnhancedForControlContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_enhancedForControl; }
	}

	public final EnhancedForControlContext enhancedForControl() throws RecognitionException {
		EnhancedForControlContext _localctx = new EnhancedForControlContext(_ctx, getState());
		enterRule(_localctx, 184, RULE_enhancedForControl);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1269);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,155,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1266);
					variableModifier();
					}
					} 
				}
				setState(1271);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,155,_ctx);
			}
			setState(1274);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,156,_ctx) ) {
			case 1:
				{
				setState(1272);
				typeType();
				}
				break;
			case 2:
				{
				setState(1273);
				match(VAR);
				}
				break;
			}
			setState(1276);
			variableDeclaratorId();
			setState(1277);
			match(COLON);
			setState(1278);
			expression(0);
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
	public static class ParExpressionContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public ParExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parExpression; }
	}

	public final ParExpressionContext parExpression() throws RecognitionException {
		ParExpressionContext _localctx = new ParExpressionContext(_ctx, getState());
		enterRule(_localctx, 186, RULE_parExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1280);
			match(LPAREN);
			setState(1281);
			expression(0);
			setState(1282);
			match(RPAREN);
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
	public static class ExpressionListContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public ExpressionListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expressionList; }
	}

	public final ExpressionListContext expressionList() throws RecognitionException {
		ExpressionListContext _localctx = new ExpressionListContext(_ctx, getState());
		enterRule(_localctx, 188, RULE_expressionList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1284);
			expression(0);
			setState(1289);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1285);
				match(COMMA);
				setState(1286);
				expression(0);
				}
				}
				setState(1291);
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
	public static class MethodCallContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public TerminalNode THIS() { return getToken(JavaParser.THIS, 0); }
		public TerminalNode SUPER() { return getToken(JavaParser.SUPER, 0); }
		public MethodCallContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_methodCall; }
	}

	public final MethodCallContext methodCall() throws RecognitionException {
		MethodCallContext _localctx = new MethodCallContext(_ctx, getState());
		enterRule(_localctx, 190, RULE_methodCall);
		int _la;
		try {
			setState(1311);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(1292);
				identifier();
				setState(1293);
				match(LPAREN);
				setState(1295);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130004991L) != 0)) {
					{
					setState(1294);
					expressionList();
					}
				}

				setState(1297);
				match(RPAREN);
				}
				break;
			case THIS:
				enterOuterAlt(_localctx, 2);
				{
				setState(1299);
				match(THIS);
				setState(1300);
				match(LPAREN);
				setState(1302);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130004991L) != 0)) {
					{
					setState(1301);
					expressionList();
					}
				}

				setState(1304);
				match(RPAREN);
				}
				break;
			case SUPER:
				enterOuterAlt(_localctx, 3);
				{
				setState(1305);
				match(SUPER);
				setState(1306);
				match(LPAREN);
				setState(1308);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130004991L) != 0)) {
					{
					setState(1307);
					expressionList();
					}
				}

				setState(1310);
				match(RPAREN);
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
	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionNewContext extends ExpressionContext {
		public TerminalNode NEW() { return getToken(JavaParser.NEW, 0); }
		public CreatorContext creator() {
			return getRuleContext(CreatorContext.class,0);
		}
		public NonWildcardTypeArgumentsContext nonWildcardTypeArguments() {
			return getRuleContext(NonWildcardTypeArgumentsContext.class,0);
		}
		public ExpressionNewContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionPosNegSignContext extends ExpressionContext {
		public Token prefix;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode ADD() { return getToken(JavaParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(JavaParser.SUB, 0); }
		public ExpressionPosNegSignContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionReferenceContext extends ExpressionContext {
		public Token bop;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode DOT() { return getToken(JavaParser.DOT, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public MethodCallContext methodCall() {
			return getRuleContext(MethodCallContext.class,0);
		}
		public TerminalNode THIS() { return getToken(JavaParser.THIS, 0); }
		public TerminalNode NEW() { return getToken(JavaParser.NEW, 0); }
		public InnerCreatorContext innerCreator() {
			return getRuleContext(InnerCreatorContext.class,0);
		}
		public TerminalNode SUPER() { return getToken(JavaParser.SUPER, 0); }
		public SuperSuffixContext superSuffix() {
			return getRuleContext(SuperSuffixContext.class,0);
		}
		public ExplicitGenericInvocationContext explicitGenericInvocation() {
			return getRuleContext(ExplicitGenericInvocationContext.class,0);
		}
		public NonWildcardTypeArgumentsContext nonWildcardTypeArguments() {
			return getRuleContext(NonWildcardTypeArgumentsContext.class,0);
		}
		public ExpressionReferenceContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionMethodReferenceContext extends ExpressionContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public TerminalNode COLONCOLON() { return getToken(JavaParser.COLONCOLON, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode NEW() { return getToken(JavaParser.NEW, 0); }
		public TypeArgumentsContext typeArguments() {
			return getRuleContext(TypeArgumentsContext.class,0);
		}
		public ClassTypeContext classType() {
			return getRuleContext(ClassTypeContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExpressionMethodReferenceContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionInstanceOfContext extends ExpressionContext {
		public Token bop;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode INSTANCEOF() { return getToken(JavaParser.INSTANCEOF, 0); }
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public PatternContext pattern() {
			return getRuleContext(PatternContext.class,0);
		}
		public ExpressionInstanceOfContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionAssignContext extends ExpressionContext {
		public ExpressionContext e1;
		public Token bop;
		public ExpressionContext e2;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode ASSIGN() { return getToken(JavaParser.ASSIGN, 0); }
		public TerminalNode ADD_ASSIGN() { return getToken(JavaParser.ADD_ASSIGN, 0); }
		public TerminalNode SUB_ASSIGN() { return getToken(JavaParser.SUB_ASSIGN, 0); }
		public TerminalNode MUL_ASSIGN() { return getToken(JavaParser.MUL_ASSIGN, 0); }
		public TerminalNode DIV_ASSIGN() { return getToken(JavaParser.DIV_ASSIGN, 0); }
		public TerminalNode AND_ASSIGN() { return getToken(JavaParser.AND_ASSIGN, 0); }
		public TerminalNode OR_ASSIGN() { return getToken(JavaParser.OR_ASSIGN, 0); }
		public TerminalNode XOR_ASSIGN() { return getToken(JavaParser.XOR_ASSIGN, 0); }
		public TerminalNode RSHIFT_ASSIGN() { return getToken(JavaParser.RSHIFT_ASSIGN, 0); }
		public TerminalNode URSHIFT_ASSIGN() { return getToken(JavaParser.URSHIFT_ASSIGN, 0); }
		public TerminalNode LSHIFT_ASSIGN() { return getToken(JavaParser.LSHIFT_ASSIGN, 0); }
		public TerminalNode MOD_ASSIGN() { return getToken(JavaParser.MOD_ASSIGN, 0); }
		public ExpressionAssignContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionUnaryLogicalContext extends ExpressionContext {
		public Token prefix;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode TILDE() { return getToken(JavaParser.TILDE, 0); }
		public TerminalNode BANG() { return getToken(JavaParser.BANG, 0); }
		public ExpressionUnaryLogicalContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionLambdaContext extends ExpressionContext {
		public LambdaExpressionContext lambdaExpression() {
			return getRuleContext(LambdaExpressionContext.class,0);
		}
		public ExpressionLambdaContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionPrimaryContext extends ExpressionContext {
		public PrimaryContext primary() {
			return getRuleContext(PrimaryContext.class,0);
		}
		public ExpressionPrimaryContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionArithmeticalContext extends ExpressionContext {
		public ExpressionContext e1;
		public Token bop;
		public ExpressionContext e2;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode MUL() { return getToken(JavaParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(JavaParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(JavaParser.MOD, 0); }
		public TerminalNode ADD() { return getToken(JavaParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(JavaParser.SUB, 0); }
		public ExpressionArithmeticalContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionSwitchContext extends ExpressionContext {
		public SwitchExpressionContext switchExpression() {
			return getRuleContext(SwitchExpressionContext.class,0);
		}
		public ExpressionSwitchContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionConditionalContext extends ExpressionContext {
		public ExpressionContext e1;
		public Token bop;
		public ExpressionContext e2;
		public ExpressionContext e3;
		public TerminalNode COLON() { return getToken(JavaParser.COLON, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode QUESTION() { return getToken(JavaParser.QUESTION, 0); }
		public ExpressionConditionalContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionCastContext extends ExpressionContext {
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public List<TypeTypeContext> typeType() {
			return getRuleContexts(TypeTypeContext.class);
		}
		public TypeTypeContext typeType(int i) {
			return getRuleContext(TypeTypeContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public List<TerminalNode> BITAND() { return getTokens(JavaParser.BITAND); }
		public TerminalNode BITAND(int i) {
			return getToken(JavaParser.BITAND, i);
		}
		public ExpressionCastContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionShiftContext extends ExpressionContext {
		public ExpressionContext e1;
		public Token bop1;
		public Token bop2;
		public Token bop3;
		public ExpressionContext e2;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> LT() { return getTokens(JavaParser.LT); }
		public TerminalNode LT(int i) {
			return getToken(JavaParser.LT, i);
		}
		public List<TerminalNode> GT() { return getTokens(JavaParser.GT); }
		public TerminalNode GT(int i) {
			return getToken(JavaParser.GT, i);
		}
		public ExpressionShiftContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionRelationalContext extends ExpressionContext {
		public ExpressionContext e1;
		public Token bop;
		public ExpressionContext e2;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode LE() { return getToken(JavaParser.LE, 0); }
		public TerminalNode GE() { return getToken(JavaParser.GE, 0); }
		public TerminalNode GT() { return getToken(JavaParser.GT, 0); }
		public TerminalNode LT() { return getToken(JavaParser.LT, 0); }
		public TerminalNode EQUAL() { return getToken(JavaParser.EQUAL, 0); }
		public TerminalNode NOTEQUAL() { return getToken(JavaParser.NOTEQUAL, 0); }
		public ExpressionRelationalContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionArrayAccessContext extends ExpressionContext {
		public ExpressionContext e1;
		public ExpressionContext e2;
		public TerminalNode LBRACK() { return getToken(JavaParser.LBRACK, 0); }
		public TerminalNode RBRACK() { return getToken(JavaParser.RBRACK, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ExpressionArrayAccessContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionIncDecContext extends ExpressionContext {
		public Token prefix;
		public Token postfix;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode INC() { return getToken(JavaParser.INC, 0); }
		public TerminalNode DEC() { return getToken(JavaParser.DEC, 0); }
		public ExpressionIncDecContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionMethodCallContext extends ExpressionContext {
		public MethodCallContext methodCall() {
			return getRuleContext(MethodCallContext.class,0);
		}
		public ExpressionMethodCallContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionLogicalContext extends ExpressionContext {
		public ExpressionContext e1;
		public Token bop;
		public ExpressionContext e2;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode BITAND() { return getToken(JavaParser.BITAND, 0); }
		public TerminalNode CARET() { return getToken(JavaParser.CARET, 0); }
		public TerminalNode BITOR() { return getToken(JavaParser.BITOR, 0); }
		public TerminalNode AND() { return getToken(JavaParser.AND, 0); }
		public TerminalNode OR() { return getToken(JavaParser.OR, 0); }
		public ExpressionLogicalContext(ExpressionContext ctx) { copyFrom(ctx); }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 192;
		enterRecursionRule(_localctx, 192, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1363);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,168,_ctx) ) {
			case 1:
				{
				_localctx = new ExpressionPrimaryContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(1314);
				primary();
				}
				break;
			case 2:
				{
				_localctx = new ExpressionMethodCallContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1315);
				methodCall();
				}
				break;
			case 3:
				{
				_localctx = new ExpressionNewContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1316);
				match(NEW);
				setState(1318);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LT) {
					{
					setState(1317);
					nonWildcardTypeArguments();
					}
				}

				setState(1320);
				creator();
				}
				break;
			case 4:
				{
				_localctx = new ExpressionCastContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1321);
				match(LPAREN);
				setState(1325);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,163,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1322);
						annotation();
						}
						} 
					}
					setState(1327);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,163,_ctx);
				}
				setState(1328);
				typeType();
				setState(1333);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==BITAND) {
					{
					{
					setState(1329);
					match(BITAND);
					setState(1330);
					typeType();
					}
					}
					setState(1335);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1336);
				match(RPAREN);
				setState(1337);
				expression(23);
				}
				break;
			case 5:
				{
				_localctx = new ExpressionIncDecContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1339);
				((ExpressionIncDecContext)_localctx).prefix = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==INC || _la==DEC) ) {
					((ExpressionIncDecContext)_localctx).prefix = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1340);
				expression(21);
				}
				break;
			case 6:
				{
				_localctx = new ExpressionPosNegSignContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1341);
				((ExpressionPosNegSignContext)_localctx).prefix = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==ADD || _la==SUB) ) {
					((ExpressionPosNegSignContext)_localctx).prefix = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1342);
				expression(20);
				}
				break;
			case 7:
				{
				_localctx = new ExpressionUnaryLogicalContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1343);
				((ExpressionUnaryLogicalContext)_localctx).prefix = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==BANG || _la==TILDE) ) {
					((ExpressionUnaryLogicalContext)_localctx).prefix = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1344);
				expression(19);
				}
				break;
			case 8:
				{
				_localctx = new ExpressionLambdaContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1345);
				lambdaExpression();
				}
				break;
			case 9:
				{
				_localctx = new ExpressionSwitchContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1346);
				switchExpression();
				}
				break;
			case 10:
				{
				_localctx = new ExpressionMethodReferenceContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1347);
				typeType();
				setState(1348);
				match(COLONCOLON);
				setState(1354);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case MODULE:
				case OPEN:
				case REQUIRES:
				case EXPORTS:
				case OPENS:
				case TO:
				case USES:
				case PROVIDES:
				case WITH:
				case TRANSITIVE:
				case VAR:
				case YIELD:
				case RECORD:
				case SEALED:
				case PERMITS:
				case LT:
				case IDENTIFIER:
					{
					setState(1350);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==LT) {
						{
						setState(1349);
						typeArguments();
						}
					}

					setState(1352);
					identifier();
					}
					break;
				case NEW:
					{
					setState(1353);
					match(NEW);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				break;
			case 11:
				{
				_localctx = new ExpressionMethodReferenceContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(1356);
				classType();
				setState(1357);
				match(COLONCOLON);
				setState(1359);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LT) {
					{
					setState(1358);
					typeArguments();
					}
				}

				setState(1361);
				match(NEW);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(1448);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,175,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(1446);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,174,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionArithmeticalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionArithmeticalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1365);
						if (!(precpred(_ctx, 18))) throw new FailedPredicateException(this, "precpred(_ctx, 18)");
						setState(1366);
						((ExpressionArithmeticalContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(((((_la - 104)) & ~0x3f) == 0 && ((1L << (_la - 104)) & 35L) != 0)) ) {
							((ExpressionArithmeticalContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(1367);
						((ExpressionArithmeticalContext)_localctx).e2 = expression(19);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionArithmeticalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionArithmeticalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1368);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(1369);
						((ExpressionArithmeticalContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
							((ExpressionArithmeticalContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(1370);
						((ExpressionArithmeticalContext)_localctx).e2 = expression(18);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionShiftContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionShiftContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1371);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(1379);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,169,_ctx) ) {
						case 1:
							{
							setState(1372);
							((ExpressionShiftContext)_localctx).bop1 = match(LT);
							setState(1373);
							match(LT);
							}
							break;
						case 2:
							{
							setState(1374);
							((ExpressionShiftContext)_localctx).bop2 = match(GT);
							setState(1375);
							match(GT);
							setState(1376);
							match(GT);
							}
							break;
						case 3:
							{
							setState(1377);
							((ExpressionShiftContext)_localctx).bop3 = match(GT);
							setState(1378);
							match(GT);
							}
							break;
						}
						setState(1381);
						((ExpressionShiftContext)_localctx).e2 = expression(17);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionRelationalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionRelationalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1382);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(1383);
						((ExpressionRelationalContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(((((_la - 88)) & ~0x3f) == 0 && ((1L << (_la - 88)) & 387L) != 0)) ) {
							((ExpressionRelationalContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(1384);
						((ExpressionRelationalContext)_localctx).e2 = expression(16);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionRelationalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionRelationalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1385);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(1386);
						((ExpressionRelationalContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==EQUAL || _la==NOTEQUAL) ) {
							((ExpressionRelationalContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(1387);
						((ExpressionRelationalContext)_localctx).e2 = expression(14);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionLogicalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionLogicalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1388);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(1389);
						((ExpressionLogicalContext)_localctx).bop = match(BITAND);
						setState(1390);
						((ExpressionLogicalContext)_localctx).e2 = expression(13);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionLogicalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionLogicalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1391);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(1392);
						((ExpressionLogicalContext)_localctx).bop = match(CARET);
						setState(1393);
						((ExpressionLogicalContext)_localctx).e2 = expression(12);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionLogicalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionLogicalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1394);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(1395);
						((ExpressionLogicalContext)_localctx).bop = match(BITOR);
						setState(1396);
						((ExpressionLogicalContext)_localctx).e2 = expression(11);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionLogicalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionLogicalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1397);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(1398);
						((ExpressionLogicalContext)_localctx).bop = match(AND);
						setState(1399);
						((ExpressionLogicalContext)_localctx).e2 = expression(10);
						}
						break;
					case 10:
						{
						_localctx = new ExpressionLogicalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionLogicalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1400);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(1401);
						((ExpressionLogicalContext)_localctx).bop = match(OR);
						setState(1402);
						((ExpressionLogicalContext)_localctx).e2 = expression(9);
						}
						break;
					case 11:
						{
						_localctx = new ExpressionConditionalContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionConditionalContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1403);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(1404);
						((ExpressionConditionalContext)_localctx).bop = match(QUESTION);
						setState(1405);
						((ExpressionConditionalContext)_localctx).e2 = expression(0);
						setState(1406);
						match(COLON);
						setState(1407);
						((ExpressionConditionalContext)_localctx).e3 = expression(7);
						}
						break;
					case 12:
						{
						_localctx = new ExpressionAssignContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionAssignContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1409);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(1410);
						((ExpressionAssignContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(((((_la - 87)) & ~0x3f) == 0 && ((1L << (_la - 87)) & 17171480577L) != 0)) ) {
							((ExpressionAssignContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(1411);
						((ExpressionAssignContext)_localctx).e2 = expression(6);
						}
						break;
					case 13:
						{
						_localctx = new ExpressionReferenceContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1412);
						if (!(precpred(_ctx, 27))) throw new FailedPredicateException(this, "precpred(_ctx, 27)");
						setState(1413);
						((ExpressionReferenceContext)_localctx).bop = match(DOT);
						setState(1425);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,171,_ctx) ) {
						case 1:
							{
							setState(1414);
							identifier();
							}
							break;
						case 2:
							{
							setState(1415);
							methodCall();
							}
							break;
						case 3:
							{
							setState(1416);
							match(THIS);
							}
							break;
						case 4:
							{
							setState(1417);
							match(NEW);
							setState(1419);
							_errHandler.sync(this);
							_la = _input.LA(1);
							if (_la==LT) {
								{
								setState(1418);
								nonWildcardTypeArguments();
								}
							}

							setState(1421);
							innerCreator();
							}
							break;
						case 5:
							{
							setState(1422);
							match(SUPER);
							setState(1423);
							superSuffix();
							}
							break;
						case 6:
							{
							setState(1424);
							explicitGenericInvocation();
							}
							break;
						}
						}
						break;
					case 14:
						{
						_localctx = new ExpressionArrayAccessContext(new ExpressionContext(_parentctx, _parentState));
						((ExpressionArrayAccessContext)_localctx).e1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1427);
						if (!(precpred(_ctx, 26))) throw new FailedPredicateException(this, "precpred(_ctx, 26)");
						setState(1428);
						match(LBRACK);
						setState(1429);
						((ExpressionArrayAccessContext)_localctx).e2 = expression(0);
						setState(1430);
						match(RBRACK);
						}
						break;
					case 15:
						{
						_localctx = new ExpressionIncDecContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1432);
						if (!(precpred(_ctx, 22))) throw new FailedPredicateException(this, "precpred(_ctx, 22)");
						setState(1433);
						((ExpressionIncDecContext)_localctx).postfix = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==INC || _la==DEC) ) {
							((ExpressionIncDecContext)_localctx).postfix = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						}
						break;
					case 16:
						{
						_localctx = new ExpressionInstanceOfContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1434);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(1435);
						((ExpressionInstanceOfContext)_localctx).bop = match(INSTANCEOF);
						setState(1438);
						_errHandler.sync(this);
						switch ( getInterpreter().adaptivePredict(_input,172,_ctx) ) {
						case 1:
							{
							setState(1436);
							typeType();
							}
							break;
						case 2:
							{
							setState(1437);
							pattern();
							}
							break;
						}
						}
						break;
					case 17:
						{
						_localctx = new ExpressionMethodReferenceContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(1440);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(1441);
						match(COLONCOLON);
						setState(1443);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (_la==LT) {
							{
							setState(1442);
							typeArguments();
							}
						}

						setState(1445);
						identifier();
						}
						break;
					}
					} 
				}
				setState(1450);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,175,_ctx);
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
	public static class PatternContext extends ParserRuleContext {
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public PatternContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pattern; }
	}

	public final PatternContext pattern() throws RecognitionException {
		PatternContext _localctx = new PatternContext(_ctx, getState());
		enterRule(_localctx, 194, RULE_pattern);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1454);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,176,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1451);
					variableModifier();
					}
					} 
				}
				setState(1456);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,176,_ctx);
			}
			setState(1457);
			typeType();
			setState(1461);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,177,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1458);
					annotation();
					}
					} 
				}
				setState(1463);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,177,_ctx);
			}
			setState(1464);
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
	public static class LambdaExpressionContext extends ParserRuleContext {
		public LambdaParametersContext lambdaParameters() {
			return getRuleContext(LambdaParametersContext.class,0);
		}
		public TerminalNode ARROW() { return getToken(JavaParser.ARROW, 0); }
		public LambdaBodyContext lambdaBody() {
			return getRuleContext(LambdaBodyContext.class,0);
		}
		public LambdaExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lambdaExpression; }
	}

	public final LambdaExpressionContext lambdaExpression() throws RecognitionException {
		LambdaExpressionContext _localctx = new LambdaExpressionContext(_ctx, getState());
		enterRule(_localctx, 196, RULE_lambdaExpression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1466);
			lambdaParameters();
			setState(1467);
			match(ARROW);
			setState(1468);
			lambdaBody();
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
	public static class LambdaParametersContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public FormalParameterListContext formalParameterList() {
			return getRuleContext(FormalParameterListContext.class,0);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public LambdaLVTIListContext lambdaLVTIList() {
			return getRuleContext(LambdaLVTIListContext.class,0);
		}
		public LambdaParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lambdaParameters; }
	}

	public final LambdaParametersContext lambdaParameters() throws RecognitionException {
		LambdaParametersContext _localctx = new LambdaParametersContext(_ctx, getState());
		enterRule(_localctx, 198, RULE_lambdaParameters);
		int _la;
		try {
			setState(1492);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,181,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1470);
				identifier();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1471);
				match(LPAREN);
				setState(1473);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223090579141986341L) != 0) || _la==AT || _la==IDENTIFIER) {
					{
					setState(1472);
					formalParameterList();
					}
				}

				setState(1475);
				match(RPAREN);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(1476);
				match(LPAREN);
				setState(1477);
				identifier();
				setState(1482);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(1478);
					match(COMMA);
					setState(1479);
					identifier();
					}
					}
					setState(1484);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1485);
				match(RPAREN);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(1487);
				match(LPAREN);
				setState(1489);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 18)) & ~0x3f) == 0 && ((1L << (_la - 18)) & 281466386776065L) != 0) || _la==AT || _la==IDENTIFIER) {
					{
					setState(1488);
					lambdaLVTIList();
					}
				}

				setState(1491);
				match(RPAREN);
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
	public static class LambdaBodyContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public LambdaBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lambdaBody; }
	}

	public final LambdaBodyContext lambdaBody() throws RecognitionException {
		LambdaBodyContext _localctx = new LambdaBodyContext(_ctx, getState());
		enterRule(_localctx, 200, RULE_lambdaBody);
		try {
			setState(1496);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case NEW:
			case SHORT:
			case SUPER:
			case SWITCH:
			case THIS:
			case VOID:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case DECIMAL_LITERAL:
			case HEX_LITERAL:
			case OCT_LITERAL:
			case BINARY_LITERAL:
			case FLOAT_LITERAL:
			case HEX_FLOAT_LITERAL:
			case BOOL_LITERAL:
			case CHAR_LITERAL:
			case STRING_LITERAL:
			case TEXT_BLOCK:
			case NULL_LITERAL:
			case LPAREN:
			case LT:
			case BANG:
			case TILDE:
			case INC:
			case DEC:
			case ADD:
			case SUB:
			case AT:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(1494);
				expression(0);
				}
				break;
			case LBRACE:
				enterOuterAlt(_localctx, 2);
				{
				setState(1495);
				block();
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
	public static class PrimaryContext extends ParserRuleContext {
		public PrimaryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary; }
	 
		public PrimaryContext() { }
		public void copyFrom(PrimaryContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrimarySuperContext extends PrimaryContext {
		public TerminalNode SUPER() { return getToken(JavaParser.SUPER, 0); }
		public PrimarySuperContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrimaryExpContext extends PrimaryContext {
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public PrimaryExpContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrimaryThisContext extends PrimaryContext {
		public TerminalNode THIS() { return getToken(JavaParser.THIS, 0); }
		public PrimaryThisContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrimaryMethodCallWithExplicitTypeArgumentContext extends PrimaryContext {
		public NonWildcardTypeArgumentsContext nonWildcardTypeArguments() {
			return getRuleContext(NonWildcardTypeArgumentsContext.class,0);
		}
		public ExplicitGenericInvocationSuffixContext explicitGenericInvocationSuffix() {
			return getRuleContext(ExplicitGenericInvocationSuffixContext.class,0);
		}
		public TerminalNode THIS() { return getToken(JavaParser.THIS, 0); }
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public PrimaryMethodCallWithExplicitTypeArgumentContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrimaryIdentifierContext extends PrimaryContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public PrimaryIdentifierContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrimaryClassContext extends PrimaryContext {
		public TypeTypeOrVoidContext typeTypeOrVoid() {
			return getRuleContext(TypeTypeOrVoidContext.class,0);
		}
		public TerminalNode DOT() { return getToken(JavaParser.DOT, 0); }
		public TerminalNode CLASS() { return getToken(JavaParser.CLASS, 0); }
		public PrimaryClassContext(PrimaryContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrimaryLiteralContext extends PrimaryContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public PrimaryLiteralContext(PrimaryContext ctx) { copyFrom(ctx); }
	}

	public final PrimaryContext primary() throws RecognitionException {
		PrimaryContext _localctx = new PrimaryContext(_ctx, getState());
		enterRule(_localctx, 202, RULE_primary);
		try {
			setState(1516);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,184,_ctx) ) {
			case 1:
				_localctx = new PrimaryExpContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(1498);
				match(LPAREN);
				setState(1499);
				expression(0);
				setState(1500);
				match(RPAREN);
				}
				break;
			case 2:
				_localctx = new PrimaryThisContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(1502);
				match(THIS);
				}
				break;
			case 3:
				_localctx = new PrimarySuperContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(1503);
				match(SUPER);
				}
				break;
			case 4:
				_localctx = new PrimaryLiteralContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(1504);
				literal();
				}
				break;
			case 5:
				_localctx = new PrimaryIdentifierContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(1505);
				identifier();
				}
				break;
			case 6:
				_localctx = new PrimaryClassContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(1506);
				typeTypeOrVoid();
				setState(1507);
				match(DOT);
				setState(1508);
				match(CLASS);
				}
				break;
			case 7:
				_localctx = new PrimaryMethodCallWithExplicitTypeArgumentContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(1510);
				nonWildcardTypeArguments();
				setState(1514);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case SUPER:
				case MODULE:
				case OPEN:
				case REQUIRES:
				case EXPORTS:
				case OPENS:
				case TO:
				case USES:
				case PROVIDES:
				case WITH:
				case TRANSITIVE:
				case VAR:
				case YIELD:
				case RECORD:
				case SEALED:
				case PERMITS:
				case IDENTIFIER:
					{
					setState(1511);
					explicitGenericInvocationSuffix();
					}
					break;
				case THIS:
					{
					setState(1512);
					match(THIS);
					setState(1513);
					arguments();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
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
	public static class SwitchExpressionContext extends ParserRuleContext {
		public TerminalNode SWITCH() { return getToken(JavaParser.SWITCH, 0); }
		public ParExpressionContext parExpression() {
			return getRuleContext(ParExpressionContext.class,0);
		}
		public TerminalNode LBRACE() { return getToken(JavaParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(JavaParser.RBRACE, 0); }
		public List<SwitchLabeledRuleContext> switchLabeledRule() {
			return getRuleContexts(SwitchLabeledRuleContext.class);
		}
		public SwitchLabeledRuleContext switchLabeledRule(int i) {
			return getRuleContext(SwitchLabeledRuleContext.class,i);
		}
		public SwitchExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switchExpression; }
	}

	public final SwitchExpressionContext switchExpression() throws RecognitionException {
		SwitchExpressionContext _localctx = new SwitchExpressionContext(_ctx, getState());
		enterRule(_localctx, 204, RULE_switchExpression);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1518);
			match(SWITCH);
			setState(1519);
			parExpression();
			setState(1520);
			match(LBRACE);
			setState(1524);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==CASE || _la==DEFAULT) {
				{
				{
				setState(1521);
				switchLabeledRule();
				}
				}
				setState(1526);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1527);
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
	public static class SwitchLabeledRuleContext extends ParserRuleContext {
		public TerminalNode CASE() { return getToken(JavaParser.CASE, 0); }
		public SwitchRuleOutcomeContext switchRuleOutcome() {
			return getRuleContext(SwitchRuleOutcomeContext.class,0);
		}
		public TerminalNode ARROW() { return getToken(JavaParser.ARROW, 0); }
		public TerminalNode COLON() { return getToken(JavaParser.COLON, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public TerminalNode NULL_LITERAL() { return getToken(JavaParser.NULL_LITERAL, 0); }
		public GuardedPatternContext guardedPattern() {
			return getRuleContext(GuardedPatternContext.class,0);
		}
		public TerminalNode DEFAULT() { return getToken(JavaParser.DEFAULT, 0); }
		public SwitchLabeledRuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switchLabeledRule; }
	}

	public final SwitchLabeledRuleContext switchLabeledRule() throws RecognitionException {
		SwitchLabeledRuleContext _localctx = new SwitchLabeledRuleContext(_ctx, getState());
		enterRule(_localctx, 206, RULE_switchLabeledRule);
		int _la;
		try {
			setState(1540);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CASE:
				enterOuterAlt(_localctx, 1);
				{
				setState(1529);
				match(CASE);
				setState(1533);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,186,_ctx) ) {
				case 1:
					{
					setState(1530);
					expressionList();
					}
					break;
				case 2:
					{
					setState(1531);
					match(NULL_LITERAL);
					}
					break;
				case 3:
					{
					setState(1532);
					guardedPattern(0);
					}
					break;
				}
				setState(1535);
				_la = _input.LA(1);
				if ( !(_la==COLON || _la==ARROW) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1536);
				switchRuleOutcome();
				}
				break;
			case DEFAULT:
				enterOuterAlt(_localctx, 2);
				{
				setState(1537);
				match(DEFAULT);
				setState(1538);
				_la = _input.LA(1);
				if ( !(_la==COLON || _la==ARROW) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(1539);
				switchRuleOutcome();
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
	public static class GuardedPatternContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public GuardedPatternContext guardedPattern() {
			return getRuleContext(GuardedPatternContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public TypeTypeContext typeType() {
			return getRuleContext(TypeTypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public List<VariableModifierContext> variableModifier() {
			return getRuleContexts(VariableModifierContext.class);
		}
		public VariableModifierContext variableModifier(int i) {
			return getRuleContext(VariableModifierContext.class,i);
		}
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public List<TerminalNode> AND() { return getTokens(JavaParser.AND); }
		public TerminalNode AND(int i) {
			return getToken(JavaParser.AND, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public GuardedPatternContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_guardedPattern; }
	}

	public final GuardedPatternContext guardedPattern() throws RecognitionException {
		return guardedPattern(0);
	}

	private GuardedPatternContext guardedPattern(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		GuardedPatternContext _localctx = new GuardedPatternContext(_ctx, _parentState);
		GuardedPatternContext _prevctx = _localctx;
		int _startState = 208;
		enterRecursionRule(_localctx, 208, RULE_guardedPattern, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1568);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
				{
				setState(1543);
				match(LPAREN);
				setState(1544);
				guardedPattern(0);
				setState(1545);
				match(RPAREN);
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FINAL:
			case FLOAT:
			case INT:
			case LONG:
			case SHORT:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case AT:
			case IDENTIFIER:
				{
				setState(1550);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,188,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1547);
						variableModifier();
						}
						} 
					}
					setState(1552);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,188,_ctx);
				}
				setState(1553);
				typeType();
				setState(1557);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,189,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1554);
						annotation();
						}
						} 
					}
					setState(1559);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,189,_ctx);
				}
				setState(1560);
				identifier();
				setState(1565);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,190,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1561);
						match(AND);
						setState(1562);
						expression(0);
						}
						} 
					}
					setState(1567);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,190,_ctx);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(1575);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,192,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new GuardedPatternContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_guardedPattern);
					setState(1570);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(1571);
					match(AND);
					setState(1572);
					expression(0);
					}
					} 
				}
				setState(1577);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,192,_ctx);
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
	public static class SwitchRuleOutcomeContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public List<BlockStatementContext> blockStatement() {
			return getRuleContexts(BlockStatementContext.class);
		}
		public BlockStatementContext blockStatement(int i) {
			return getRuleContext(BlockStatementContext.class,i);
		}
		public SwitchRuleOutcomeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_switchRuleOutcome; }
	}

	public final SwitchRuleOutcomeContext switchRuleOutcome() throws RecognitionException {
		SwitchRuleOutcomeContext _localctx = new SwitchRuleOutcomeContext(_ctx, getState());
		enterRule(_localctx, 210, RULE_switchRuleOutcome);
		int _la;
		try {
			setState(1585);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,194,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1578);
				block();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1582);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (((((_la - 1)) & ~0x3f) == 0 && ((1L << (_la - 1)) & -334254282492513L) != 0) || ((((_la - 65)) & ~0x3f) == 0 && ((1L << (_la - 65)) & -8935141145188974593L) != 0)) {
					{
					{
					setState(1579);
					blockStatement();
					}
					}
					setState(1584);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
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
	public static class ClassTypeContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ClassOrInterfaceTypeContext classOrInterfaceType() {
			return getRuleContext(ClassOrInterfaceTypeContext.class,0);
		}
		public TerminalNode DOT() { return getToken(JavaParser.DOT, 0); }
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public TypeArgumentsContext typeArguments() {
			return getRuleContext(TypeArgumentsContext.class,0);
		}
		public ClassTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classType; }
	}

	public final ClassTypeContext classType() throws RecognitionException {
		ClassTypeContext _localctx = new ClassTypeContext(_ctx, getState());
		enterRule(_localctx, 212, RULE_classType);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1590);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,195,_ctx) ) {
			case 1:
				{
				setState(1587);
				classOrInterfaceType();
				setState(1588);
				match(DOT);
				}
				break;
			}
			setState(1595);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,196,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1592);
					annotation();
					}
					} 
				}
				setState(1597);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,196,_ctx);
			}
			setState(1598);
			identifier();
			setState(1600);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(1599);
				typeArguments();
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
	public static class CreatorContext extends ParserRuleContext {
		public CreatedNameContext createdName() {
			return getRuleContext(CreatedNameContext.class,0);
		}
		public ArrayCreatorRestContext arrayCreatorRest() {
			return getRuleContext(ArrayCreatorRestContext.class,0);
		}
		public ClassCreatorRestContext classCreatorRest() {
			return getRuleContext(ClassCreatorRestContext.class,0);
		}
		public CreatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_creator; }
	}

	public final CreatorContext creator() throws RecognitionException {
		CreatorContext _localctx = new CreatorContext(_ctx, getState());
		enterRule(_localctx, 214, RULE_creator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1602);
			createdName();
			setState(1605);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LBRACK:
				{
				setState(1603);
				arrayCreatorRest();
				}
				break;
			case LPAREN:
				{
				setState(1604);
				classCreatorRest();
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
	public static class CreatedNameContext extends ParserRuleContext {
		public List<IdentifierContext> identifier() {
			return getRuleContexts(IdentifierContext.class);
		}
		public IdentifierContext identifier(int i) {
			return getRuleContext(IdentifierContext.class,i);
		}
		public List<TypeArgumentsOrDiamondContext> typeArgumentsOrDiamond() {
			return getRuleContexts(TypeArgumentsOrDiamondContext.class);
		}
		public TypeArgumentsOrDiamondContext typeArgumentsOrDiamond(int i) {
			return getRuleContext(TypeArgumentsOrDiamondContext.class,i);
		}
		public List<TerminalNode> DOT() { return getTokens(JavaParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(JavaParser.DOT, i);
		}
		public PrimitiveTypeContext primitiveType() {
			return getRuleContext(PrimitiveTypeContext.class,0);
		}
		public CreatedNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_createdName; }
	}

	public final CreatedNameContext createdName() throws RecognitionException {
		CreatedNameContext _localctx = new CreatedNameContext(_ctx, getState());
		enterRule(_localctx, 216, RULE_createdName);
		int _la;
		try {
			setState(1622);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 1);
				{
				setState(1607);
				identifier();
				setState(1609);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LT) {
					{
					setState(1608);
					typeArgumentsOrDiamond();
					}
				}

				setState(1618);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==DOT) {
					{
					{
					setState(1611);
					match(DOT);
					setState(1612);
					identifier();
					setState(1614);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==LT) {
						{
						setState(1613);
						typeArgumentsOrDiamond();
						}
					}

					}
					}
					setState(1620);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case SHORT:
				enterOuterAlt(_localctx, 2);
				{
				setState(1621);
				primitiveType();
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
	public static class InnerCreatorContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ClassCreatorRestContext classCreatorRest() {
			return getRuleContext(ClassCreatorRestContext.class,0);
		}
		public NonWildcardTypeArgumentsOrDiamondContext nonWildcardTypeArgumentsOrDiamond() {
			return getRuleContext(NonWildcardTypeArgumentsOrDiamondContext.class,0);
		}
		public InnerCreatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_innerCreator; }
	}

	public final InnerCreatorContext innerCreator() throws RecognitionException {
		InnerCreatorContext _localctx = new InnerCreatorContext(_ctx, getState());
		enterRule(_localctx, 218, RULE_innerCreator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1624);
			identifier();
			setState(1626);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LT) {
				{
				setState(1625);
				nonWildcardTypeArgumentsOrDiamond();
				}
			}

			setState(1628);
			classCreatorRest();
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
	public static class ArrayCreatorRestContext extends ParserRuleContext {
		public List<TerminalNode> LBRACK() { return getTokens(JavaParser.LBRACK); }
		public TerminalNode LBRACK(int i) {
			return getToken(JavaParser.LBRACK, i);
		}
		public List<TerminalNode> RBRACK() { return getTokens(JavaParser.RBRACK); }
		public TerminalNode RBRACK(int i) {
			return getToken(JavaParser.RBRACK, i);
		}
		public ArrayInitializerContext arrayInitializer() {
			return getRuleContext(ArrayInitializerContext.class,0);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ArrayCreatorRestContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayCreatorRest; }
	}

	public final ArrayCreatorRestContext arrayCreatorRest() throws RecognitionException {
		ArrayCreatorRestContext _localctx = new ArrayCreatorRestContext(_ctx, getState());
		enterRule(_localctx, 220, RULE_arrayCreatorRest);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1630);
			match(LBRACK);
			setState(1658);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case RBRACK:
				{
				setState(1631);
				match(RBRACK);
				setState(1636);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==LBRACK) {
					{
					{
					setState(1632);
					match(LBRACK);
					setState(1633);
					match(RBRACK);
					}
					}
					setState(1638);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(1639);
				arrayInitializer();
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case NEW:
			case SHORT:
			case SUPER:
			case SWITCH:
			case THIS:
			case VOID:
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case DECIMAL_LITERAL:
			case HEX_LITERAL:
			case OCT_LITERAL:
			case BINARY_LITERAL:
			case FLOAT_LITERAL:
			case HEX_FLOAT_LITERAL:
			case BOOL_LITERAL:
			case CHAR_LITERAL:
			case STRING_LITERAL:
			case TEXT_BLOCK:
			case NULL_LITERAL:
			case LPAREN:
			case LT:
			case BANG:
			case TILDE:
			case INC:
			case DEC:
			case ADD:
			case SUB:
			case AT:
			case IDENTIFIER:
				{
				setState(1640);
				expression(0);
				setState(1641);
				match(RBRACK);
				setState(1648);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,205,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1642);
						match(LBRACK);
						setState(1643);
						expression(0);
						setState(1644);
						match(RBRACK);
						}
						} 
					}
					setState(1650);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,205,_ctx);
				}
				setState(1655);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,206,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(1651);
						match(LBRACK);
						setState(1652);
						match(RBRACK);
						}
						} 
					}
					setState(1657);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,206,_ctx);
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
	public static class ClassCreatorRestContext extends ParserRuleContext {
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ClassBodyContext classBody() {
			return getRuleContext(ClassBodyContext.class,0);
		}
		public ClassCreatorRestContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classCreatorRest; }
	}

	public final ClassCreatorRestContext classCreatorRest() throws RecognitionException {
		ClassCreatorRestContext _localctx = new ClassCreatorRestContext(_ctx, getState());
		enterRule(_localctx, 222, RULE_classCreatorRest);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1660);
			arguments();
			setState(1662);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,208,_ctx) ) {
			case 1:
				{
				setState(1661);
				classBody();
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
	public static class ExplicitGenericInvocationContext extends ParserRuleContext {
		public NonWildcardTypeArgumentsContext nonWildcardTypeArguments() {
			return getRuleContext(NonWildcardTypeArgumentsContext.class,0);
		}
		public ExplicitGenericInvocationSuffixContext explicitGenericInvocationSuffix() {
			return getRuleContext(ExplicitGenericInvocationSuffixContext.class,0);
		}
		public ExplicitGenericInvocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_explicitGenericInvocation; }
	}

	public final ExplicitGenericInvocationContext explicitGenericInvocation() throws RecognitionException {
		ExplicitGenericInvocationContext _localctx = new ExplicitGenericInvocationContext(_ctx, getState());
		enterRule(_localctx, 224, RULE_explicitGenericInvocation);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1664);
			nonWildcardTypeArguments();
			setState(1665);
			explicitGenericInvocationSuffix();
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
	public static class TypeArgumentsOrDiamondContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(JavaParser.LT, 0); }
		public TerminalNode GT() { return getToken(JavaParser.GT, 0); }
		public TypeArgumentsContext typeArguments() {
			return getRuleContext(TypeArgumentsContext.class,0);
		}
		public TypeArgumentsOrDiamondContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeArgumentsOrDiamond; }
	}

	public final TypeArgumentsOrDiamondContext typeArgumentsOrDiamond() throws RecognitionException {
		TypeArgumentsOrDiamondContext _localctx = new TypeArgumentsOrDiamondContext(_ctx, getState());
		enterRule(_localctx, 226, RULE_typeArgumentsOrDiamond);
		try {
			setState(1670);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,209,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1667);
				match(LT);
				setState(1668);
				match(GT);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1669);
				typeArguments();
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
	public static class NonWildcardTypeArgumentsOrDiamondContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(JavaParser.LT, 0); }
		public TerminalNode GT() { return getToken(JavaParser.GT, 0); }
		public NonWildcardTypeArgumentsContext nonWildcardTypeArguments() {
			return getRuleContext(NonWildcardTypeArgumentsContext.class,0);
		}
		public NonWildcardTypeArgumentsOrDiamondContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nonWildcardTypeArgumentsOrDiamond; }
	}

	public final NonWildcardTypeArgumentsOrDiamondContext nonWildcardTypeArgumentsOrDiamond() throws RecognitionException {
		NonWildcardTypeArgumentsOrDiamondContext _localctx = new NonWildcardTypeArgumentsOrDiamondContext(_ctx, getState());
		enterRule(_localctx, 228, RULE_nonWildcardTypeArgumentsOrDiamond);
		try {
			setState(1675);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,210,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(1672);
				match(LT);
				setState(1673);
				match(GT);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(1674);
				nonWildcardTypeArguments();
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
	public static class NonWildcardTypeArgumentsContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(JavaParser.LT, 0); }
		public TypeListContext typeList() {
			return getRuleContext(TypeListContext.class,0);
		}
		public TerminalNode GT() { return getToken(JavaParser.GT, 0); }
		public NonWildcardTypeArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nonWildcardTypeArguments; }
	}

	public final NonWildcardTypeArgumentsContext nonWildcardTypeArguments() throws RecognitionException {
		NonWildcardTypeArgumentsContext _localctx = new NonWildcardTypeArgumentsContext(_ctx, getState());
		enterRule(_localctx, 230, RULE_nonWildcardTypeArguments);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1677);
			match(LT);
			setState(1678);
			typeList();
			setState(1679);
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
	public static class TypeListContext extends ParserRuleContext {
		public List<TypeTypeContext> typeType() {
			return getRuleContexts(TypeTypeContext.class);
		}
		public TypeTypeContext typeType(int i) {
			return getRuleContext(TypeTypeContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public TypeListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeList; }
	}

	public final TypeListContext typeList() throws RecognitionException {
		TypeListContext _localctx = new TypeListContext(_ctx, getState());
		enterRule(_localctx, 232, RULE_typeList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1681);
			typeType();
			setState(1686);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1682);
				match(COMMA);
				setState(1683);
				typeType();
				}
				}
				setState(1688);
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
	public static class TypeTypeContext extends ParserRuleContext {
		public ClassOrInterfaceTypeContext classOrInterfaceType() {
			return getRuleContext(ClassOrInterfaceTypeContext.class,0);
		}
		public PrimitiveTypeContext primitiveType() {
			return getRuleContext(PrimitiveTypeContext.class,0);
		}
		public List<AnnotationContext> annotation() {
			return getRuleContexts(AnnotationContext.class);
		}
		public AnnotationContext annotation(int i) {
			return getRuleContext(AnnotationContext.class,i);
		}
		public List<TerminalNode> LBRACK() { return getTokens(JavaParser.LBRACK); }
		public TerminalNode LBRACK(int i) {
			return getToken(JavaParser.LBRACK, i);
		}
		public List<TerminalNode> RBRACK() { return getTokens(JavaParser.RBRACK); }
		public TerminalNode RBRACK(int i) {
			return getToken(JavaParser.RBRACK, i);
		}
		public TypeTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeType; }
	}

	public final TypeTypeContext typeType() throws RecognitionException {
		TypeTypeContext _localctx = new TypeTypeContext(_ctx, getState());
		enterRule(_localctx, 234, RULE_typeType);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(1692);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,212,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1689);
					annotation();
					}
					} 
				}
				setState(1694);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,212,_ctx);
			}
			setState(1697);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case IDENTIFIER:
				{
				setState(1695);
				classOrInterfaceType();
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case SHORT:
				{
				setState(1696);
				primitiveType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(1709);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,215,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(1702);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (((((_la - 51)) & ~0x3f) == 0 && ((1L << (_la - 51)) & 32767L) != 0) || _la==AT || _la==IDENTIFIER) {
						{
						{
						setState(1699);
						annotation();
						}
						}
						setState(1704);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					setState(1705);
					match(LBRACK);
					setState(1706);
					match(RBRACK);
					}
					} 
				}
				setState(1711);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,215,_ctx);
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
	public static class PrimitiveTypeContext extends ParserRuleContext {
		public TerminalNode BOOLEAN() { return getToken(JavaParser.BOOLEAN, 0); }
		public TerminalNode CHAR() { return getToken(JavaParser.CHAR, 0); }
		public TerminalNode BYTE() { return getToken(JavaParser.BYTE, 0); }
		public TerminalNode SHORT() { return getToken(JavaParser.SHORT, 0); }
		public TerminalNode INT() { return getToken(JavaParser.INT, 0); }
		public TerminalNode LONG() { return getToken(JavaParser.LONG, 0); }
		public TerminalNode FLOAT() { return getToken(JavaParser.FLOAT, 0); }
		public TerminalNode DOUBLE() { return getToken(JavaParser.DOUBLE, 0); }
		public PrimitiveTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primitiveType; }
	}

	public final PrimitiveTypeContext primitiveType() throws RecognitionException {
		PrimitiveTypeContext _localctx = new PrimitiveTypeContext(_ctx, getState());
		enterRule(_localctx, 236, RULE_primitiveType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1712);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 138111107368L) != 0)) ) {
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
	public static class TypeArgumentsContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(JavaParser.LT, 0); }
		public List<TypeArgumentContext> typeArgument() {
			return getRuleContexts(TypeArgumentContext.class);
		}
		public TypeArgumentContext typeArgument(int i) {
			return getRuleContext(TypeArgumentContext.class,i);
		}
		public TerminalNode GT() { return getToken(JavaParser.GT, 0); }
		public List<TerminalNode> COMMA() { return getTokens(JavaParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(JavaParser.COMMA, i);
		}
		public TypeArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeArguments; }
	}

	public final TypeArgumentsContext typeArguments() throws RecognitionException {
		TypeArgumentsContext _localctx = new TypeArgumentsContext(_ctx, getState());
		enterRule(_localctx, 238, RULE_typeArguments);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1714);
			match(LT);
			setState(1715);
			typeArgument();
			setState(1720);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(1716);
				match(COMMA);
				setState(1717);
				typeArgument();
				}
				}
				setState(1722);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(1723);
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
	public static class SuperSuffixContext extends ParserRuleContext {
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public TerminalNode DOT() { return getToken(JavaParser.DOT, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TypeArgumentsContext typeArguments() {
			return getRuleContext(TypeArgumentsContext.class,0);
		}
		public SuperSuffixContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_superSuffix; }
	}

	public final SuperSuffixContext superSuffix() throws RecognitionException {
		SuperSuffixContext _localctx = new SuperSuffixContext(_ctx, getState());
		enterRule(_localctx, 240, RULE_superSuffix);
		int _la;
		try {
			setState(1734);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
				enterOuterAlt(_localctx, 1);
				{
				setState(1725);
				arguments();
				}
				break;
			case DOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(1726);
				match(DOT);
				setState(1728);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LT) {
					{
					setState(1727);
					typeArguments();
					}
				}

				setState(1730);
				identifier();
				setState(1732);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,218,_ctx) ) {
				case 1:
					{
					setState(1731);
					arguments();
					}
					break;
				}
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
	public static class ExplicitGenericInvocationSuffixContext extends ParserRuleContext {
		public TerminalNode SUPER() { return getToken(JavaParser.SUPER, 0); }
		public SuperSuffixContext superSuffix() {
			return getRuleContext(SuperSuffixContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ExplicitGenericInvocationSuffixContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_explicitGenericInvocationSuffix; }
	}

	public final ExplicitGenericInvocationSuffixContext explicitGenericInvocationSuffix() throws RecognitionException {
		ExplicitGenericInvocationSuffixContext _localctx = new ExplicitGenericInvocationSuffixContext(_ctx, getState());
		enterRule(_localctx, 242, RULE_explicitGenericInvocationSuffix);
		try {
			setState(1741);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SUPER:
				enterOuterAlt(_localctx, 1);
				{
				setState(1736);
				match(SUPER);
				setState(1737);
				superSuffix();
				}
				break;
			case MODULE:
			case OPEN:
			case REQUIRES:
			case EXPORTS:
			case OPENS:
			case TO:
			case USES:
			case PROVIDES:
			case WITH:
			case TRANSITIVE:
			case VAR:
			case YIELD:
			case RECORD:
			case SEALED:
			case PERMITS:
			case IDENTIFIER:
				enterOuterAlt(_localctx, 2);
				{
				setState(1738);
				identifier();
				setState(1739);
				arguments();
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
	public static class ArgumentsContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(JavaParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(JavaParser.RPAREN, 0); }
		public ExpressionListContext expressionList() {
			return getRuleContext(ExpressionListContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, getState());
		enterRule(_localctx, 244, RULE_arguments);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(1743);
			match(LPAREN);
			setState(1745);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 3)) & ~0x3f) == 0 && ((1L << (_la - 3)) & 9223127275610966053L) != 0) || ((((_la - 67)) & ~0x3f) == 0 && ((1L << (_la - 67)) & 2377900732130004991L) != 0)) {
				{
				setState(1744);
				expressionList();
				}
			}

			setState(1747);
			match(RPAREN);
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
		case 96:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 104:
			return guardedPattern_sempred((GuardedPatternContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 18);
		case 1:
			return precpred(_ctx, 17);
		case 2:
			return precpred(_ctx, 16);
		case 3:
			return precpred(_ctx, 15);
		case 4:
			return precpred(_ctx, 13);
		case 5:
			return precpred(_ctx, 12);
		case 6:
			return precpred(_ctx, 11);
		case 7:
			return precpred(_ctx, 10);
		case 8:
			return precpred(_ctx, 9);
		case 9:
			return precpred(_ctx, 8);
		case 10:
			return precpred(_ctx, 7);
		case 11:
			return precpred(_ctx, 6);
		case 12:
			return precpred(_ctx, 27);
		case 13:
			return precpred(_ctx, 26);
		case 14:
			return precpred(_ctx, 22);
		case 15:
			return precpred(_ctx, 14);
		case 16:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean guardedPattern_sempred(GuardedPatternContext _localctx, int predIndex) {
		switch (predIndex) {
		case 17:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u0080\u06d6\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b"+
		"\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007"+
		"\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007"+
		"\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007"+
		"\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007"+
		"\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007"+
		"\u001b\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002\u001e\u0007"+
		"\u001e\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007!\u0002\"\u0007"+
		"\"\u0002#\u0007#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007&\u0002\'\u0007"+
		"\'\u0002(\u0007(\u0002)\u0007)\u0002*\u0007*\u0002+\u0007+\u0002,\u0007"+
		",\u0002-\u0007-\u0002.\u0007.\u0002/\u0007/\u00020\u00070\u00021\u0007"+
		"1\u00022\u00072\u00023\u00073\u00024\u00074\u00025\u00075\u00026\u0007"+
		"6\u00027\u00077\u00028\u00078\u00029\u00079\u0002:\u0007:\u0002;\u0007"+
		";\u0002<\u0007<\u0002=\u0007=\u0002>\u0007>\u0002?\u0007?\u0002@\u0007"+
		"@\u0002A\u0007A\u0002B\u0007B\u0002C\u0007C\u0002D\u0007D\u0002E\u0007"+
		"E\u0002F\u0007F\u0002G\u0007G\u0002H\u0007H\u0002I\u0007I\u0002J\u0007"+
		"J\u0002K\u0007K\u0002L\u0007L\u0002M\u0007M\u0002N\u0007N\u0002O\u0007"+
		"O\u0002P\u0007P\u0002Q\u0007Q\u0002R\u0007R\u0002S\u0007S\u0002T\u0007"+
		"T\u0002U\u0007U\u0002V\u0007V\u0002W\u0007W\u0002X\u0007X\u0002Y\u0007"+
		"Y\u0002Z\u0007Z\u0002[\u0007[\u0002\\\u0007\\\u0002]\u0007]\u0002^\u0007"+
		"^\u0002_\u0007_\u0002`\u0007`\u0002a\u0007a\u0002b\u0007b\u0002c\u0007"+
		"c\u0002d\u0007d\u0002e\u0007e\u0002f\u0007f\u0002g\u0007g\u0002h\u0007"+
		"h\u0002i\u0007i\u0002j\u0007j\u0002k\u0007k\u0002l\u0007l\u0002m\u0007"+
		"m\u0002n\u0007n\u0002o\u0007o\u0002p\u0007p\u0002q\u0007q\u0002r\u0007"+
		"r\u0002s\u0007s\u0002t\u0007t\u0002u\u0007u\u0002v\u0007v\u0002w\u0007"+
		"w\u0002x\u0007x\u0002y\u0007y\u0002z\u0007z\u0001\u0000\u0003\u0000\u00f8"+
		"\b\u0000\u0001\u0000\u0001\u0000\u0005\u0000\u00fc\b\u0000\n\u0000\f\u0000"+
		"\u00ff\t\u0000\u0001\u0000\u0001\u0000\u0005\u0000\u0103\b\u0000\n\u0000"+
		"\f\u0000\u0106\t\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0003\u0000"+
		"\u010b\b\u0000\u0001\u0001\u0005\u0001\u010e\b\u0001\n\u0001\f\u0001\u0111"+
		"\t\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001"+
		"\u0002\u0003\u0002\u0119\b\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003"+
		"\u0002\u011e\b\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0005\u0003\u0123"+
		"\b\u0003\n\u0003\f\u0003\u0126\t\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0003\u0003\u012d\b\u0003\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004\u0134\b\u0004\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005\u0140\b\u0005\u0001\u0006"+
		"\u0001\u0006\u0003\u0006\u0144\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0003\u0007\u0149\b\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u014d\b"+
		"\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u0151\b\u0007\u0001\u0007\u0001"+
		"\u0007\u0003\u0007\u0155\b\u0007\u0001\u0007\u0001\u0007\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0005\b\u015d\b\b\n\b\f\b\u0160\t\b\u0001\b\u0001\b"+
		"\u0001\t\u0005\t\u0165\b\t\n\t\f\t\u0168\t\t\u0001\t\u0001\t\u0001\t\u0005"+
		"\t\u016d\b\t\n\t\f\t\u0170\t\t\u0001\t\u0003\t\u0173\b\t\u0001\n\u0001"+
		"\n\u0001\n\u0005\n\u0178\b\n\n\n\f\n\u017b\t\n\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0003\u000b\u0181\b\u000b\u0001\u000b\u0001\u000b"+
		"\u0003\u000b\u0185\b\u000b\u0001\u000b\u0003\u000b\u0188\b\u000b\u0001"+
		"\u000b\u0003\u000b\u018b\b\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001"+
		"\f\u0001\f\u0005\f\u0192\b\f\n\f\f\f\u0195\t\f\u0001\r\u0005\r\u0198\b"+
		"\r\n\r\f\r\u019b\t\r\u0001\r\u0001\r\u0003\r\u019f\b\r\u0001\r\u0003\r"+
		"\u01a2\b\r\u0001\u000e\u0001\u000e\u0005\u000e\u01a6\b\u000e\n\u000e\f"+
		"\u000e\u01a9\t\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u01ae"+
		"\b\u000f\u0001\u000f\u0001\u000f\u0003\u000f\u01b2\b\u000f\u0001\u000f"+
		"\u0001\u000f\u0003\u000f\u01b6\b\u000f\u0001\u000f\u0001\u000f\u0001\u0010"+
		"\u0001\u0010\u0005\u0010\u01bc\b\u0010\n\u0010\f\u0010\u01bf\t\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0005\u0011\u01c5\b\u0011\n"+
		"\u0011\f\u0011\u01c8\t\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001"+
		"\u0012\u0003\u0012\u01ce\b\u0012\u0001\u0012\u0001\u0012\u0005\u0012\u01d2"+
		"\b\u0012\n\u0012\f\u0012\u01d5\t\u0012\u0001\u0012\u0003\u0012\u01d8\b"+
		"\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0003\u0013\u01e2\b\u0013\u0001\u0014\u0003"+
		"\u0014\u01e5\b\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0005\u0014\u01ec\b\u0014\n\u0014\f\u0014\u01ef\t\u0014\u0001\u0014"+
		"\u0001\u0014\u0003\u0014\u01f3\b\u0014\u0001\u0014\u0001\u0014\u0001\u0015"+
		"\u0001\u0015\u0003\u0015\u01f9\b\u0015\u0001\u0016\u0001\u0016\u0003\u0016"+
		"\u01fd\b\u0016\u0001\u0017\u0003\u0017\u0200\b\u0017\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0003\u0017\u0206\b\u0017\u0001\u0017\u0001"+
		"\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0019\u0005"+
		"\u0019\u020f\b\u0019\n\u0019\f\u0019\u0212\t\u0019\u0001\u0019\u0001\u0019"+
		"\u0003\u0019\u0216\b\u0019\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0003\u001a\u021f\b\u001a\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0005\u001b\u0225\b\u001b\n\u001b"+
		"\f\u001b\u0228\t\u001b\u0001\u001b\u0001\u001b\u0001\u001c\u0001\u001c"+
		"\u0001\u001c\u0005\u001c\u022f\b\u001c\n\u001c\f\u001c\u0232\t\u001c\u0001"+
		"\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0005\u001d\u0238\b\u001d\n"+
		"\u001d\f\u001d\u023b\t\u001d\u0001\u001d\u0003\u001d\u023e\b\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001"+
		"\u001e\u0001\u001e\u0003\u001e\u0248\b\u001e\u0001\u001f\u0005\u001f\u024b"+
		"\b\u001f\n\u001f\f\u001f\u024e\t\u001f\u0001\u001f\u0001\u001f\u0001\u001f"+
		"\u0001\u001f\u0001\u001f\u0005\u001f\u0255\b\u001f\n\u001f\f\u001f\u0258"+
		"\t\u001f\u0001\u001f\u0001\u001f\u0003\u001f\u025c\b\u001f\u0001\u001f"+
		"\u0001\u001f\u0001 \u0001 \u0001 \u0005 \u0263\b \n \f \u0266\t \u0001"+
		"!\u0001!\u0001!\u0003!\u026b\b!\u0001\"\u0001\"\u0001\"\u0005\"\u0270"+
		"\b\"\n\"\f\"\u0273\t\"\u0001#\u0001#\u0003#\u0277\b#\u0001$\u0001$\u0001"+
		"$\u0001$\u0005$\u027d\b$\n$\f$\u0280\t$\u0001$\u0003$\u0283\b$\u0003$"+
		"\u0285\b$\u0001$\u0001$\u0001%\u0001%\u0003%\u028b\b%\u0001%\u0001%\u0001"+
		"%\u0003%\u0290\b%\u0005%\u0292\b%\n%\f%\u0295\t%\u0001&\u0001&\u0005&"+
		"\u0299\b&\n&\f&\u029c\t&\u0001&\u0001&\u0001&\u0003&\u02a1\b&\u0003&\u02a3"+
		"\b&\u0001\'\u0001\'\u0001\'\u0005\'\u02a8\b\'\n\'\f\'\u02ab\t\'\u0001"+
		"(\u0001(\u0003(\u02af\b(\u0001(\u0001(\u0001(\u0003(\u02b4\b(\u0001(\u0003"+
		"(\u02b7\b(\u0003(\u02b9\b(\u0001(\u0001(\u0001)\u0001)\u0001)\u0001)\u0005"+
		")\u02c1\b)\n)\f)\u02c4\t)\u0001)\u0001)\u0001*\u0001*\u0001*\u0005*\u02cb"+
		"\b*\n*\f*\u02ce\t*\u0001*\u0001*\u0003*\u02d2\b*\u0001*\u0003*\u02d5\b"+
		"*\u0001+\u0005+\u02d8\b+\n+\f+\u02db\t+\u0001+\u0001+\u0001+\u0001,\u0005"+
		",\u02e1\b,\n,\f,\u02e4\t,\u0001,\u0001,\u0005,\u02e8\b,\n,\f,\u02eb\t"+
		",\u0001,\u0001,\u0001,\u0001-\u0001-\u0001-\u0005-\u02f3\b-\n-\f-\u02f6"+
		"\t-\u0001.\u0005.\u02f9\b.\n.\f.\u02fc\t.\u0001.\u0001.\u0001.\u0001/"+
		"\u0001/\u0001/\u0005/\u0304\b/\n/\f/\u0307\t/\u00010\u00010\u00010\u0001"+
		"0\u00010\u00010\u00010\u00030\u0310\b0\u00011\u00011\u00012\u00012\u0001"+
		"3\u00013\u00013\u00053\u0319\b3\n3\f3\u031c\t3\u00013\u00013\u00013\u0001"+
		"4\u00014\u00014\u00034\u0324\b4\u00014\u00014\u00014\u00034\u0329\b4\u0001"+
		"4\u00034\u032c\b4\u00015\u00015\u00015\u00055\u0331\b5\n5\f5\u0334\t5"+
		"\u00016\u00016\u00016\u00016\u00017\u00017\u00017\u00037\u033d\b7\u0001"+
		"8\u00018\u00018\u00018\u00058\u0343\b8\n8\f8\u0346\t8\u00038\u0348\b8"+
		"\u00018\u00038\u034b\b8\u00018\u00018\u00019\u00019\u00019\u00019\u0001"+
		"9\u0001:\u0001:\u0005:\u0356\b:\n:\f:\u0359\t:\u0001:\u0001:\u0001;\u0005"+
		";\u035e\b;\n;\f;\u0361\t;\u0001;\u0001;\u0003;\u0365\b;\u0001<\u0001<"+
		"\u0001<\u0001<\u0001<\u0001<\u0003<\u036d\b<\u0001<\u0001<\u0003<\u0371"+
		"\b<\u0001<\u0001<\u0003<\u0375\b<\u0001<\u0001<\u0003<\u0379\b<\u0001"+
		"<\u0001<\u0003<\u037d\b<\u0003<\u037f\b<\u0001=\u0001=\u0003=\u0383\b"+
		"=\u0001>\u0001>\u0001>\u0001>\u0003>\u0389\b>\u0001?\u0001?\u0001@\u0001"+
		"@\u0001@\u0001A\u0003A\u0391\bA\u0001A\u0001A\u0001A\u0001A\u0001B\u0001"+
		"B\u0005B\u0399\bB\nB\fB\u039c\tB\u0001B\u0001B\u0001C\u0001C\u0005C\u03a2"+
		"\bC\nC\fC\u03a5\tC\u0001C\u0001C\u0001C\u0001C\u0001C\u0001C\u0001C\u0003"+
		"C\u03ae\bC\u0001C\u0001C\u0001C\u0001C\u0001C\u0001C\u0003C\u03b6\bC\u0001"+
		"C\u0001C\u0001C\u0001C\u0001C\u0001C\u0001C\u0001C\u0001C\u0001C\u0001"+
		"C\u0001C\u0003C\u03c4\bC\u0001D\u0001D\u0001E\u0001E\u0001E\u0003E\u03cb"+
		"\bE\u0001E\u0001E\u0001E\u0003E\u03d0\bE\u0001E\u0001E\u0001F\u0001F\u0003"+
		"F\u03d6\bF\u0001F\u0001F\u0001G\u0001G\u0001G\u0005G\u03dd\bG\nG\fG\u03e0"+
		"\tG\u0001H\u0001H\u0001H\u0001I\u0001I\u0005I\u03e7\bI\nI\fI\u03ea\tI"+
		"\u0001I\u0001I\u0001J\u0001J\u0005J\u03f0\bJ\nJ\fJ\u03f3\tJ\u0001J\u0001"+
		"J\u0001K\u0001K\u0001K\u0001K\u0001K\u0003K\u03fc\bK\u0001L\u0005L\u03ff"+
		"\bL\nL\fL\u0402\tL\u0001L\u0001L\u0001L\u0001L\u0001L\u0001L\u0001L\u0001"+
		"L\u0003L\u040c\bL\u0001M\u0001M\u0001N\u0005N\u0411\bN\nN\fN\u0414\tN"+
		"\u0001N\u0001N\u0001N\u0003N\u0419\bN\u0001N\u0003N\u041c\bN\u0001O\u0001"+
		"O\u0001O\u0001O\u0001O\u0003O\u0423\bO\u0001O\u0001O\u0001O\u0001O\u0001"+
		"O\u0001O\u0001O\u0003O\u042c\bO\u0001O\u0001O\u0001O\u0001O\u0001O\u0001"+
		"O\u0001O\u0001O\u0001O\u0001O\u0001O\u0001O\u0001O\u0001O\u0001O\u0001"+
		"O\u0001O\u0001O\u0001O\u0001O\u0005O\u0442\bO\nO\fO\u0445\tO\u0001O\u0005"+
		"O\u0448\bO\nO\fO\u044b\tO\u0001O\u0001O\u0001O\u0001O\u0001O\u0004O\u0452"+
		"\bO\u000bO\fO\u0453\u0001O\u0003O\u0457\bO\u0001O\u0003O\u045a\bO\u0001"+
		"O\u0001O\u0001O\u0001O\u0005O\u0460\bO\nO\fO\u0463\tO\u0001O\u0003O\u0466"+
		"\bO\u0001O\u0001O\u0001O\u0001O\u0001O\u0001O\u0003O\u046e\bO\u0001O\u0001"+
		"O\u0001O\u0001O\u0001O\u0001O\u0001O\u0003O\u0477\bO\u0001O\u0001O\u0001"+
		"O\u0003O\u047c\bO\u0001O\u0001O\u0001O\u0001O\u0001O\u0001O\u0001O\u0001"+
		"O\u0001O\u0001O\u0001O\u0003O\u0489\bO\u0001O\u0001O\u0001O\u0001O\u0003"+
		"O\u048f\bO\u0001P\u0001P\u0001P\u0005P\u0494\bP\nP\fP\u0497\tP\u0001P"+
		"\u0001P\u0001P\u0001P\u0001P\u0001Q\u0001Q\u0001Q\u0005Q\u04a1\bQ\nQ\f"+
		"Q\u04a4\tQ\u0001R\u0001R\u0001R\u0001S\u0001S\u0001S\u0003S\u04ac\bS\u0001"+
		"S\u0001S\u0001T\u0001T\u0001T\u0005T\u04b3\bT\nT\fT\u04b6\tT\u0001U\u0005"+
		"U\u04b9\bU\nU\fU\u04bc\tU\u0001U\u0001U\u0001U\u0001U\u0001U\u0003U\u04c3"+
		"\bU\u0001U\u0001U\u0001U\u0001U\u0003U\u04c9\bU\u0001V\u0004V\u04cc\b"+
		"V\u000bV\fV\u04cd\u0001V\u0004V\u04d1\bV\u000bV\fV\u04d2\u0001W\u0001"+
		"W\u0001W\u0001W\u0001W\u0001W\u0003W\u04db\bW\u0001X\u0001X\u0003X\u04df"+
		"\bX\u0001X\u0001X\u0003X\u04e3\bX\u0001X\u0001X\u0003X\u04e7\bX\u0003"+
		"X\u04e9\bX\u0001Y\u0001Y\u0003Y\u04ed\bY\u0001Z\u0001Z\u0001[\u0001[\u0001"+
		"\\\u0005\\\u04f4\b\\\n\\\f\\\u04f7\t\\\u0001\\\u0001\\\u0003\\\u04fb\b"+
		"\\\u0001\\\u0001\\\u0001\\\u0001\\\u0001]\u0001]\u0001]\u0001]\u0001^"+
		"\u0001^\u0001^\u0005^\u0508\b^\n^\f^\u050b\t^\u0001_\u0001_\u0001_\u0003"+
		"_\u0510\b_\u0001_\u0001_\u0001_\u0001_\u0001_\u0003_\u0517\b_\u0001_\u0001"+
		"_\u0001_\u0001_\u0003_\u051d\b_\u0001_\u0003_\u0520\b_\u0001`\u0001`\u0001"+
		"`\u0001`\u0001`\u0003`\u0527\b`\u0001`\u0001`\u0001`\u0005`\u052c\b`\n"+
		"`\f`\u052f\t`\u0001`\u0001`\u0001`\u0005`\u0534\b`\n`\f`\u0537\t`\u0001"+
		"`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001"+
		"`\u0001`\u0001`\u0001`\u0003`\u0547\b`\u0001`\u0001`\u0003`\u054b\b`\u0001"+
		"`\u0001`\u0001`\u0003`\u0550\b`\u0001`\u0001`\u0003`\u0554\b`\u0001`\u0001"+
		"`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001"+
		"`\u0001`\u0001`\u0003`\u0564\b`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001"+
		"`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001"+
		"`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001"+
		"`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001"+
		"`\u0001`\u0001`\u0003`\u058c\b`\u0001`\u0001`\u0001`\u0001`\u0003`\u0592"+
		"\b`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001`\u0001"+
		"`\u0001`\u0003`\u059f\b`\u0001`\u0001`\u0001`\u0003`\u05a4\b`\u0001`\u0005"+
		"`\u05a7\b`\n`\f`\u05aa\t`\u0001a\u0005a\u05ad\ba\na\fa\u05b0\ta\u0001"+
		"a\u0001a\u0005a\u05b4\ba\na\fa\u05b7\ta\u0001a\u0001a\u0001b\u0001b\u0001"+
		"b\u0001b\u0001c\u0001c\u0001c\u0003c\u05c2\bc\u0001c\u0001c\u0001c\u0001"+
		"c\u0001c\u0005c\u05c9\bc\nc\fc\u05cc\tc\u0001c\u0001c\u0001c\u0001c\u0003"+
		"c\u05d2\bc\u0001c\u0003c\u05d5\bc\u0001d\u0001d\u0003d\u05d9\bd\u0001"+
		"e\u0001e\u0001e\u0001e\u0001e\u0001e\u0001e\u0001e\u0001e\u0001e\u0001"+
		"e\u0001e\u0001e\u0001e\u0001e\u0001e\u0003e\u05eb\be\u0003e\u05ed\be\u0001"+
		"f\u0001f\u0001f\u0001f\u0005f\u05f3\bf\nf\ff\u05f6\tf\u0001f\u0001f\u0001"+
		"g\u0001g\u0001g\u0001g\u0003g\u05fe\bg\u0001g\u0001g\u0001g\u0001g\u0001"+
		"g\u0003g\u0605\bg\u0001h\u0001h\u0001h\u0001h\u0001h\u0001h\u0005h\u060d"+
		"\bh\nh\fh\u0610\th\u0001h\u0001h\u0005h\u0614\bh\nh\fh\u0617\th\u0001"+
		"h\u0001h\u0001h\u0005h\u061c\bh\nh\fh\u061f\th\u0003h\u0621\bh\u0001h"+
		"\u0001h\u0001h\u0005h\u0626\bh\nh\fh\u0629\th\u0001i\u0001i\u0005i\u062d"+
		"\bi\ni\fi\u0630\ti\u0003i\u0632\bi\u0001j\u0001j\u0001j\u0003j\u0637\b"+
		"j\u0001j\u0005j\u063a\bj\nj\fj\u063d\tj\u0001j\u0001j\u0003j\u0641\bj"+
		"\u0001k\u0001k\u0001k\u0003k\u0646\bk\u0001l\u0001l\u0003l\u064a\bl\u0001"+
		"l\u0001l\u0001l\u0003l\u064f\bl\u0005l\u0651\bl\nl\fl\u0654\tl\u0001l"+
		"\u0003l\u0657\bl\u0001m\u0001m\u0003m\u065b\bm\u0001m\u0001m\u0001n\u0001"+
		"n\u0001n\u0001n\u0005n\u0663\bn\nn\fn\u0666\tn\u0001n\u0001n\u0001n\u0001"+
		"n\u0001n\u0001n\u0001n\u0005n\u066f\bn\nn\fn\u0672\tn\u0001n\u0001n\u0005"+
		"n\u0676\bn\nn\fn\u0679\tn\u0003n\u067b\bn\u0001o\u0001o\u0003o\u067f\b"+
		"o\u0001p\u0001p\u0001p\u0001q\u0001q\u0001q\u0003q\u0687\bq\u0001r\u0001"+
		"r\u0001r\u0003r\u068c\br\u0001s\u0001s\u0001s\u0001s\u0001t\u0001t\u0001"+
		"t\u0005t\u0695\bt\nt\ft\u0698\tt\u0001u\u0005u\u069b\bu\nu\fu\u069e\t"+
		"u\u0001u\u0001u\u0003u\u06a2\bu\u0001u\u0005u\u06a5\bu\nu\fu\u06a8\tu"+
		"\u0001u\u0001u\u0005u\u06ac\bu\nu\fu\u06af\tu\u0001v\u0001v\u0001w\u0001"+
		"w\u0001w\u0001w\u0005w\u06b7\bw\nw\fw\u06ba\tw\u0001w\u0001w\u0001x\u0001"+
		"x\u0001x\u0003x\u06c1\bx\u0001x\u0001x\u0003x\u06c5\bx\u0003x\u06c7\b"+
		"x\u0001y\u0001y\u0001y\u0001y\u0001y\u0003y\u06ce\by\u0001z\u0001z\u0003"+
		"z\u06d2\bz\u0001z\u0001z\u0001z\u0000\u0002\u00c0\u00d0{\u0000\u0002\u0004"+
		"\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \""+
		"$&(*,.02468:<>@BDFHJLNPRTVXZ\\^`bdfhjlnprtvxz|~\u0080\u0082\u0084\u0086"+
		"\u0088\u008a\u008c\u008e\u0090\u0092\u0094\u0096\u0098\u009a\u009c\u009e"+
		"\u00a0\u00a2\u00a4\u00a6\u00a8\u00aa\u00ac\u00ae\u00b0\u00b2\u00b4\u00b6"+
		"\u00b8\u00ba\u00bc\u00be\u00c0\u00c2\u00c4\u00c6\u00c8\u00ca\u00cc\u00ce"+
		"\u00d0\u00d2\u00d4\u00d6\u00d8\u00da\u00dc\u00de\u00e0\u00e2\u00e4\u00e6"+
		"\u00e8\u00ea\u00ec\u00ee\u00f0\u00f2\u00f4\u0000\u000e\u0002\u0000\u0011"+
		"\u0011((\u0001\u0000CF\u0001\u0000GH\u0002\u0000&&<<\u0002\u00003A\u0080"+
		"\u0080\u0001\u0000de\u0001\u0000fg\u0001\u0000Z[\u0002\u0000himm\u0002"+
		"\u0000XY_`\u0002\u0000^^aa\u0002\u0000WWnx\u0002\u0000]]yy\b\u0000\u0003"+
		"\u0003\u0005\u0005\b\b\u000e\u000e\u0014\u0014\u001b\u001b\u001d\u001d"+
		"%%\u079e\u0000\u010a\u0001\u0000\u0000\u0000\u0002\u010f\u0001\u0000\u0000"+
		"\u0000\u0004\u0116\u0001\u0000\u0000\u0000\u0006\u0124\u0001\u0000\u0000"+
		"\u0000\b\u0133\u0001\u0000\u0000\u0000\n\u013f\u0001\u0000\u0000\u0000"+
		"\f\u0143\u0001\u0000\u0000\u0000\u000e\u0145\u0001\u0000\u0000\u0000\u0010"+
		"\u0158\u0001\u0000\u0000\u0000\u0012\u0166\u0001\u0000\u0000\u0000\u0014"+
		"\u0174\u0001\u0000\u0000\u0000\u0016\u017c\u0001\u0000\u0000\u0000\u0018"+
		"\u018e\u0001\u0000\u0000\u0000\u001a\u0199\u0001\u0000\u0000\u0000\u001c"+
		"\u01a3\u0001\u0000\u0000\u0000\u001e\u01aa\u0001\u0000\u0000\u0000 \u01b9"+
		"\u0001\u0000\u0000\u0000\"\u01c2\u0001\u0000\u0000\u0000$\u01d7\u0001"+
		"\u0000\u0000\u0000&\u01e1\u0001\u0000\u0000\u0000(\u01e4\u0001\u0000\u0000"+
		"\u0000*\u01f8\u0001\u0000\u0000\u0000,\u01fc\u0001\u0000\u0000\u0000."+
		"\u01ff\u0001\u0000\u0000\u00000\u0209\u0001\u0000\u0000\u00002\u0215\u0001"+
		"\u0000\u0000\u00004\u021e\u0001\u0000\u0000\u00006\u0220\u0001\u0000\u0000"+
		"\u00008\u022b\u0001\u0000\u0000\u0000:\u0239\u0001\u0000\u0000\u0000<"+
		"\u0247\u0001\u0000\u0000\u0000>\u024c\u0001\u0000\u0000\u0000@\u025f\u0001"+
		"\u0000\u0000\u0000B\u0267\u0001\u0000\u0000\u0000D\u026c\u0001\u0000\u0000"+
		"\u0000F\u0276\u0001\u0000\u0000\u0000H\u0278\u0001\u0000\u0000\u0000J"+
		"\u0288\u0001\u0000\u0000\u0000L\u02a2\u0001\u0000\u0000\u0000N\u02a4\u0001"+
		"\u0000\u0000\u0000P\u02ac\u0001\u0000\u0000\u0000R\u02bc\u0001\u0000\u0000"+
		"\u0000T\u02d4\u0001\u0000\u0000\u0000V\u02d9\u0001\u0000\u0000\u0000X"+
		"\u02e2\u0001\u0000\u0000\u0000Z\u02ef\u0001\u0000\u0000\u0000\\\u02fa"+
		"\u0001\u0000\u0000\u0000^\u0300\u0001\u0000\u0000\u0000`\u030f\u0001\u0000"+
		"\u0000\u0000b\u0311\u0001\u0000\u0000\u0000d\u0313\u0001\u0000\u0000\u0000"+
		"f\u031a\u0001\u0000\u0000\u0000h\u0323\u0001\u0000\u0000\u0000j\u032d"+
		"\u0001\u0000\u0000\u0000l\u0335\u0001\u0000\u0000\u0000n\u033c\u0001\u0000"+
		"\u0000\u0000p\u033e\u0001\u0000\u0000\u0000r\u034e\u0001\u0000\u0000\u0000"+
		"t\u0353\u0001\u0000\u0000\u0000v\u0364\u0001\u0000\u0000\u0000x\u037e"+
		"\u0001\u0000\u0000\u0000z\u0382\u0001\u0000\u0000\u0000|\u0384\u0001\u0000"+
		"\u0000\u0000~\u038a\u0001\u0000\u0000\u0000\u0080\u038c\u0001\u0000\u0000"+
		"\u0000\u0082\u0390\u0001\u0000\u0000\u0000\u0084\u0396\u0001\u0000\u0000"+
		"\u0000\u0086\u03c3\u0001\u0000\u0000\u0000\u0088\u03c5\u0001\u0000\u0000"+
		"\u0000\u008a\u03c7\u0001\u0000\u0000\u0000\u008c\u03d3\u0001\u0000\u0000"+
		"\u0000\u008e\u03d9\u0001\u0000\u0000\u0000\u0090\u03e1\u0001\u0000\u0000"+
		"\u0000\u0092\u03e4\u0001\u0000\u0000\u0000\u0094\u03ed\u0001\u0000\u0000"+
		"\u0000\u0096\u03fb\u0001\u0000\u0000\u0000\u0098\u0400\u0001\u0000\u0000"+
		"\u0000\u009a\u040d\u0001\u0000\u0000\u0000\u009c\u041b\u0001\u0000\u0000"+
		"\u0000\u009e\u048e\u0001\u0000\u0000\u0000\u00a0\u0490\u0001\u0000\u0000"+
		"\u0000\u00a2\u049d\u0001\u0000\u0000\u0000\u00a4\u04a5\u0001\u0000\u0000"+
		"\u0000\u00a6\u04a8\u0001\u0000\u0000\u0000\u00a8\u04af\u0001\u0000\u0000"+
		"\u0000\u00aa\u04c8\u0001\u0000\u0000\u0000\u00ac\u04cb\u0001\u0000\u0000"+
		"\u0000\u00ae\u04da\u0001\u0000\u0000\u0000\u00b0\u04e8\u0001\u0000\u0000"+
		"\u0000\u00b2\u04ec\u0001\u0000\u0000\u0000\u00b4\u04ee\u0001\u0000\u0000"+
		"\u0000\u00b6\u04f0\u0001\u0000\u0000\u0000\u00b8\u04f5\u0001\u0000\u0000"+
		"\u0000\u00ba\u0500\u0001\u0000\u0000\u0000\u00bc\u0504\u0001\u0000\u0000"+
		"\u0000\u00be\u051f\u0001\u0000\u0000\u0000\u00c0\u0553\u0001\u0000\u0000"+
		"\u0000\u00c2\u05ae\u0001\u0000\u0000\u0000\u00c4\u05ba\u0001\u0000\u0000"+
		"\u0000\u00c6\u05d4\u0001\u0000\u0000\u0000\u00c8\u05d8\u0001\u0000\u0000"+
		"\u0000\u00ca\u05ec\u0001\u0000\u0000\u0000\u00cc\u05ee\u0001\u0000\u0000"+
		"\u0000\u00ce\u0604\u0001\u0000\u0000\u0000\u00d0\u0620\u0001\u0000\u0000"+
		"\u0000\u00d2\u0631\u0001\u0000\u0000\u0000\u00d4\u0636\u0001\u0000\u0000"+
		"\u0000\u00d6\u0642\u0001\u0000\u0000\u0000\u00d8\u0656\u0001\u0000\u0000"+
		"\u0000\u00da\u0658\u0001\u0000\u0000\u0000\u00dc\u065e\u0001\u0000\u0000"+
		"\u0000\u00de\u067c\u0001\u0000\u0000\u0000\u00e0\u0680\u0001\u0000\u0000"+
		"\u0000\u00e2\u0686\u0001\u0000\u0000\u0000\u00e4\u068b\u0001\u0000\u0000"+
		"\u0000\u00e6\u068d\u0001\u0000\u0000\u0000\u00e8\u0691\u0001\u0000\u0000"+
		"\u0000\u00ea\u069c\u0001\u0000\u0000\u0000\u00ec\u06b0\u0001\u0000\u0000"+
		"\u0000\u00ee\u06b2\u0001\u0000\u0000\u0000\u00f0\u06c6\u0001\u0000\u0000"+
		"\u0000\u00f2\u06cd\u0001\u0000\u0000\u0000\u00f4\u06cf\u0001\u0000\u0000"+
		"\u0000\u00f6\u00f8\u0003\u0002\u0001\u0000\u00f7\u00f6\u0001\u0000\u0000"+
		"\u0000\u00f7\u00f8\u0001\u0000\u0000\u0000\u00f8\u00fd\u0001\u0000\u0000"+
		"\u0000\u00f9\u00fc\u0003\u0004\u0002\u0000\u00fa\u00fc\u0005T\u0000\u0000"+
		"\u00fb\u00f9\u0001\u0000\u0000\u0000\u00fb\u00fa\u0001\u0000\u0000\u0000"+
		"\u00fc\u00ff\u0001\u0000\u0000\u0000\u00fd\u00fb\u0001\u0000\u0000\u0000"+
		"\u00fd\u00fe\u0001\u0000\u0000\u0000\u00fe\u0104\u0001\u0000\u0000\u0000"+
		"\u00ff\u00fd\u0001\u0000\u0000\u0000\u0100\u0103\u0003\u0006\u0003\u0000"+
		"\u0101\u0103\u0005T\u0000\u0000\u0102\u0100\u0001\u0000\u0000\u0000\u0102"+
		"\u0101\u0001\u0000\u0000\u0000\u0103\u0106\u0001\u0000\u0000\u0000\u0104"+
		"\u0102\u0001\u0000\u0000\u0000\u0104\u0105\u0001\u0000\u0000\u0000\u0105"+
		"\u010b\u0001\u0000\u0000\u0000\u0106\u0104\u0001\u0000\u0000\u0000\u0107"+
		"\u0108\u0003\u0082A\u0000\u0108\u0109\u0005\u0000\u0000\u0001\u0109\u010b"+
		"\u0001\u0000\u0000\u0000\u010a\u00f7\u0001\u0000\u0000\u0000\u010a\u0107"+
		"\u0001\u0000\u0000\u0000\u010b\u0001\u0001\u0000\u0000\u0000\u010c\u010e"+
		"\u0003h4\u0000\u010d\u010c\u0001\u0000\u0000\u0000\u010e\u0111\u0001\u0000"+
		"\u0000\u0000\u010f\u010d\u0001\u0000\u0000\u0000\u010f\u0110\u0001\u0000"+
		"\u0000\u0000\u0110\u0112\u0001\u0000\u0000\u0000\u0111\u010f\u0001\u0000"+
		"\u0000\u0000\u0112\u0113\u0005 \u0000\u0000\u0113\u0114\u0003^/\u0000"+
		"\u0114\u0115\u0005T\u0000\u0000\u0115\u0003\u0001\u0000\u0000\u0000\u0116"+
		"\u0118\u0005\u0019\u0000\u0000\u0117\u0119\u0005&\u0000\u0000\u0118\u0117"+
		"\u0001\u0000\u0000\u0000\u0118\u0119\u0001\u0000\u0000\u0000\u0119\u011a"+
		"\u0001\u0000\u0000\u0000\u011a\u011d\u0003^/\u0000\u011b\u011c\u0005V"+
		"\u0000\u0000\u011c\u011e\u0005h\u0000\u0000\u011d\u011b\u0001\u0000\u0000"+
		"\u0000\u011d\u011e\u0001\u0000\u0000\u0000\u011e\u011f\u0001\u0000\u0000"+
		"\u0000\u011f\u0120\u0005T\u0000\u0000\u0120\u0005\u0001\u0000\u0000\u0000"+
		"\u0121\u0123\u0003\n\u0005\u0000\u0122\u0121\u0001\u0000\u0000\u0000\u0123"+
		"\u0126\u0001\u0000\u0000\u0000\u0124\u0122\u0001\u0000\u0000\u0000\u0124"+
		"\u0125\u0001\u0000\u0000\u0000\u0125\u012c\u0001\u0000\u0000\u0000\u0126"+
		"\u0124\u0001\u0000\u0000\u0000\u0127\u012d\u0003\u000e\u0007\u0000\u0128"+
		"\u012d\u0003\u0016\u000b\u0000\u0129\u012d\u0003\u001e\u000f\u0000\u012a"+
		"\u012d\u0003r9\u0000\u012b\u012d\u0003\u008aE\u0000\u012c\u0127\u0001"+
		"\u0000\u0000\u0000\u012c\u0128\u0001\u0000\u0000\u0000\u012c\u0129\u0001"+
		"\u0000\u0000\u0000\u012c\u012a\u0001\u0000\u0000\u0000\u012c\u012b\u0001"+
		"\u0000\u0000\u0000\u012d\u0007\u0001\u0000\u0000\u0000\u012e\u0134\u0003"+
		"\n\u0005\u0000\u012f\u0134\u0005\u001e\u0000\u0000\u0130\u0134\u0005*"+
		"\u0000\u0000\u0131\u0134\u0005.\u0000\u0000\u0132\u0134\u00051\u0000\u0000"+
		"\u0133\u012e\u0001\u0000\u0000\u0000\u0133\u012f\u0001\u0000\u0000\u0000"+
		"\u0133\u0130\u0001\u0000\u0000\u0000\u0133\u0131\u0001\u0000\u0000\u0000"+
		"\u0133\u0132\u0001\u0000\u0000\u0000\u0134\t\u0001\u0000\u0000\u0000\u0135"+
		"\u0140\u0003h4\u0000\u0136\u0140\u0005#\u0000\u0000\u0137\u0140\u0005"+
		"\"\u0000\u0000\u0138\u0140\u0005!\u0000\u0000\u0139\u0140\u0005&\u0000"+
		"\u0000\u013a\u0140\u0005\u0001\u0000\u0000\u013b\u0140\u0005\u0012\u0000"+
		"\u0000\u013c\u0140\u0005\'\u0000\u0000\u013d\u0140\u0005@\u0000\u0000"+
		"\u013e\u0140\u0005B\u0000\u0000\u013f\u0135\u0001\u0000\u0000\u0000\u013f"+
		"\u0136\u0001\u0000\u0000\u0000\u013f\u0137\u0001\u0000\u0000\u0000\u013f"+
		"\u0138\u0001\u0000\u0000\u0000\u013f\u0139\u0001\u0000\u0000\u0000\u013f"+
		"\u013a\u0001\u0000\u0000\u0000\u013f\u013b\u0001\u0000\u0000\u0000\u013f"+
		"\u013c\u0001\u0000\u0000\u0000\u013f\u013d\u0001\u0000\u0000\u0000\u013f"+
		"\u013e\u0001\u0000\u0000\u0000\u0140\u000b\u0001\u0000\u0000\u0000\u0141"+
		"\u0144\u0005\u0012\u0000\u0000\u0142\u0144\u0003h4\u0000\u0143\u0141\u0001"+
		"\u0000\u0000\u0000\u0143\u0142\u0001\u0000\u0000\u0000\u0144\r\u0001\u0000"+
		"\u0000\u0000\u0145\u0146\u0005\t\u0000\u0000\u0146\u0148\u0003\u009aM"+
		"\u0000\u0147\u0149\u0003\u0010\b\u0000\u0148\u0147\u0001\u0000\u0000\u0000"+
		"\u0148\u0149\u0001\u0000\u0000\u0000\u0149\u014c\u0001\u0000\u0000\u0000"+
		"\u014a\u014b\u0005\u0011\u0000\u0000\u014b\u014d\u0003\u00eau\u0000\u014c"+
		"\u014a\u0001\u0000\u0000\u0000\u014c\u014d\u0001\u0000\u0000\u0000\u014d"+
		"\u0150\u0001\u0000\u0000\u0000\u014e\u014f\u0005\u0018\u0000\u0000\u014f"+
		"\u0151\u0003\u00e8t\u0000\u0150\u014e\u0001\u0000\u0000\u0000\u0150\u0151"+
		"\u0001\u0000\u0000\u0000\u0151\u0154\u0001\u0000\u0000\u0000\u0152\u0153"+
		"\u0005A\u0000\u0000\u0153\u0155\u0003\u00e8t\u0000\u0154\u0152\u0001\u0000"+
		"\u0000\u0000\u0154\u0155\u0001\u0000\u0000\u0000\u0155\u0156\u0001\u0000"+
		"\u0000\u0000\u0156\u0157\u0003 \u0010\u0000\u0157\u000f\u0001\u0000\u0000"+
		"\u0000\u0158\u0159\u0005Y\u0000\u0000\u0159\u015e\u0003\u0012\t\u0000"+
		"\u015a\u015b\u0005U\u0000\u0000\u015b\u015d\u0003\u0012\t\u0000\u015c"+
		"\u015a\u0001\u0000\u0000\u0000\u015d\u0160\u0001\u0000\u0000\u0000\u015e"+
		"\u015c\u0001\u0000\u0000\u0000\u015e\u015f\u0001\u0000\u0000\u0000\u015f"+
		"\u0161\u0001\u0000\u0000\u0000\u0160\u015e\u0001\u0000\u0000\u0000\u0161"+
		"\u0162\u0005X\u0000\u0000\u0162\u0011\u0001\u0000\u0000\u0000\u0163\u0165"+
		"\u0003h4\u0000\u0164\u0163\u0001\u0000\u0000\u0000\u0165\u0168\u0001\u0000"+
		"\u0000\u0000\u0166\u0164\u0001\u0000\u0000\u0000\u0166\u0167\u0001\u0000"+
		"\u0000\u0000\u0167\u0169\u0001\u0000\u0000\u0000\u0168\u0166\u0001\u0000"+
		"\u0000\u0000\u0169\u0172\u0003\u009aM\u0000\u016a\u016e\u0005\u0011\u0000"+
		"\u0000\u016b\u016d\u0003h4\u0000\u016c\u016b\u0001\u0000\u0000\u0000\u016d"+
		"\u0170\u0001\u0000\u0000\u0000\u016e\u016c\u0001\u0000\u0000\u0000\u016e"+
		"\u016f\u0001\u0000\u0000\u0000\u016f\u0171\u0001\u0000\u0000\u0000\u0170"+
		"\u016e\u0001\u0000\u0000\u0000\u0171\u0173\u0003\u0014\n\u0000\u0172\u016a"+
		"\u0001\u0000\u0000\u0000\u0172\u0173\u0001\u0000\u0000\u0000\u0173\u0013"+
		"\u0001\u0000\u0000\u0000\u0174\u0179\u0003\u00eau\u0000\u0175\u0176\u0005"+
		"j\u0000\u0000\u0176\u0178\u0003\u00eau\u0000\u0177\u0175\u0001\u0000\u0000"+
		"\u0000\u0178\u017b\u0001\u0000\u0000\u0000\u0179\u0177\u0001\u0000\u0000"+
		"\u0000\u0179\u017a\u0001\u0000\u0000\u0000\u017a\u0015\u0001\u0000\u0000"+
		"\u0000\u017b\u0179\u0001\u0000\u0000\u0000\u017c\u017d\u0005\u0010\u0000"+
		"\u0000\u017d\u0180\u0003\u009aM\u0000\u017e\u017f\u0005\u0018\u0000\u0000"+
		"\u017f\u0181\u0003\u00e8t\u0000\u0180\u017e\u0001\u0000\u0000\u0000\u0180"+
		"\u0181\u0001\u0000\u0000\u0000\u0181\u0182\u0001\u0000\u0000\u0000\u0182"+
		"\u0184\u0005P\u0000\u0000\u0183\u0185\u0003\u0018\f\u0000\u0184\u0183"+
		"\u0001\u0000\u0000\u0000\u0184\u0185\u0001\u0000\u0000\u0000\u0185\u0187"+
		"\u0001\u0000\u0000\u0000\u0186\u0188\u0005U\u0000\u0000\u0187\u0186\u0001"+
		"\u0000\u0000\u0000\u0187\u0188\u0001\u0000\u0000\u0000\u0188\u018a\u0001"+
		"\u0000\u0000\u0000\u0189\u018b\u0003\u001c\u000e\u0000\u018a\u0189\u0001"+
		"\u0000\u0000\u0000\u018a\u018b\u0001\u0000\u0000\u0000\u018b\u018c\u0001"+
		"\u0000\u0000\u0000\u018c\u018d\u0005Q\u0000\u0000\u018d\u0017\u0001\u0000"+
		"\u0000\u0000\u018e\u0193\u0003\u001a\r\u0000\u018f\u0190\u0005U\u0000"+
		"\u0000\u0190\u0192\u0003\u001a\r\u0000\u0191\u018f\u0001\u0000\u0000\u0000"+
		"\u0192\u0195\u0001\u0000\u0000\u0000\u0193\u0191\u0001\u0000\u0000\u0000"+
		"\u0193\u0194\u0001\u0000\u0000\u0000\u0194\u0019\u0001\u0000\u0000\u0000"+
		"\u0195\u0193\u0001\u0000\u0000\u0000\u0196\u0198\u0003h4\u0000\u0197\u0196"+
		"\u0001\u0000\u0000\u0000\u0198\u019b\u0001\u0000\u0000\u0000\u0199\u0197"+
		"\u0001\u0000\u0000\u0000\u0199\u019a\u0001\u0000\u0000\u0000\u019a\u019c"+
		"\u0001\u0000\u0000\u0000\u019b\u0199\u0001\u0000\u0000\u0000\u019c\u019e"+
		"\u0003\u009aM\u0000\u019d\u019f\u0003\u00f4z\u0000\u019e\u019d\u0001\u0000"+
		"\u0000\u0000\u019e\u019f\u0001\u0000\u0000\u0000\u019f\u01a1\u0001\u0000"+
		"\u0000\u0000\u01a0\u01a2\u0003 \u0010\u0000\u01a1\u01a0\u0001\u0000\u0000"+
		"\u0000\u01a1\u01a2\u0001\u0000\u0000\u0000\u01a2\u001b\u0001\u0000\u0000"+
		"\u0000\u01a3\u01a7\u0005T\u0000\u0000\u01a4\u01a6\u0003$\u0012\u0000\u01a5"+
		"\u01a4\u0001\u0000\u0000\u0000\u01a6\u01a9\u0001\u0000\u0000\u0000\u01a7"+
		"\u01a5\u0001\u0000\u0000\u0000\u01a7\u01a8\u0001\u0000\u0000\u0000\u01a8"+
		"\u001d\u0001\u0000\u0000\u0000\u01a9\u01a7\u0001\u0000\u0000\u0000\u01aa"+
		"\u01ab\u0005\u001c\u0000\u0000\u01ab\u01ad\u0003\u009aM\u0000\u01ac\u01ae"+
		"\u0003\u0010\b\u0000\u01ad\u01ac\u0001\u0000\u0000\u0000\u01ad\u01ae\u0001"+
		"\u0000\u0000\u0000\u01ae\u01b1\u0001\u0000\u0000\u0000\u01af\u01b0\u0005"+
		"\u0011\u0000\u0000\u01b0\u01b2\u0003\u00e8t\u0000\u01b1\u01af\u0001\u0000"+
		"\u0000\u0000\u01b1\u01b2\u0001\u0000\u0000\u0000\u01b2\u01b5\u0001\u0000"+
		"\u0000\u0000\u01b3\u01b4\u0005A\u0000\u0000\u01b4\u01b6\u0003\u00e8t\u0000"+
		"\u01b5\u01b3\u0001\u0000\u0000\u0000\u01b5\u01b6\u0001\u0000\u0000\u0000"+
		"\u01b6\u01b7\u0001\u0000\u0000\u0000\u01b7\u01b8\u0003\"\u0011\u0000\u01b8"+
		"\u001f\u0001\u0000\u0000\u0000\u01b9\u01bd\u0005P\u0000\u0000\u01ba\u01bc"+
		"\u0003$\u0012\u0000\u01bb\u01ba\u0001\u0000\u0000\u0000\u01bc\u01bf\u0001"+
		"\u0000\u0000\u0000\u01bd\u01bb\u0001\u0000\u0000\u0000\u01bd\u01be\u0001"+
		"\u0000\u0000\u0000\u01be\u01c0\u0001\u0000\u0000\u0000\u01bf\u01bd\u0001"+
		"\u0000\u0000\u0000\u01c0\u01c1\u0005Q\u0000\u0000\u01c1!\u0001\u0000\u0000"+
		"\u0000\u01c2\u01c6\u0005P\u0000\u0000\u01c3\u01c5\u00032\u0019\u0000\u01c4"+
		"\u01c3\u0001\u0000\u0000\u0000\u01c5\u01c8\u0001\u0000\u0000\u0000\u01c6"+
		"\u01c4\u0001\u0000\u0000\u0000\u01c6\u01c7\u0001\u0000\u0000\u0000\u01c7"+
		"\u01c9\u0001\u0000\u0000\u0000\u01c8\u01c6\u0001\u0000\u0000\u0000\u01c9"+
		"\u01ca\u0005Q\u0000\u0000\u01ca#\u0001\u0000\u0000\u0000\u01cb\u01d8\u0005"+
		"T\u0000\u0000\u01cc\u01ce\u0005&\u0000\u0000\u01cd\u01cc\u0001\u0000\u0000"+
		"\u0000\u01cd\u01ce\u0001\u0000\u0000\u0000\u01ce\u01cf\u0001\u0000\u0000"+
		"\u0000\u01cf\u01d8\u0003\u0094J\u0000\u01d0\u01d2\u0003\b\u0004\u0000"+
		"\u01d1\u01d0\u0001\u0000\u0000\u0000\u01d2\u01d5\u0001\u0000\u0000\u0000"+
		"\u01d3\u01d1\u0001\u0000\u0000\u0000\u01d3\u01d4\u0001\u0000\u0000\u0000"+
		"\u01d4\u01d6\u0001\u0000\u0000\u0000\u01d5\u01d3\u0001\u0000\u0000\u0000"+
		"\u01d6\u01d8\u0003&\u0013\u0000\u01d7\u01cb\u0001\u0000\u0000\u0000\u01d7"+
		"\u01cd\u0001\u0000\u0000\u0000\u01d7\u01d3\u0001\u0000\u0000\u0000\u01d8"+
		"%\u0001\u0000\u0000\u0000\u01d9\u01e2\u0003\u008aE\u0000\u01da\u01e2\u0003"+
		"(\u0014\u0000\u01db\u01e2\u00030\u0018\u0000\u01dc\u01e2\u0003.\u0017"+
		"\u0000\u01dd\u01e2\u0003\u001e\u000f\u0000\u01de\u01e2\u0003r9\u0000\u01df"+
		"\u01e2\u0003\u000e\u0007\u0000\u01e0\u01e2\u0003\u0016\u000b\u0000\u01e1"+
		"\u01d9\u0001\u0000\u0000\u0000\u01e1\u01da\u0001\u0000\u0000\u0000\u01e1"+
		"\u01db\u0001\u0000\u0000\u0000\u01e1\u01dc\u0001\u0000\u0000\u0000\u01e1"+
		"\u01dd\u0001\u0000\u0000\u0000\u01e1\u01de\u0001\u0000\u0000\u0000\u01e1"+
		"\u01df\u0001\u0000\u0000\u0000\u01e1\u01e0\u0001\u0000\u0000\u0000\u01e2"+
		"\'\u0001\u0000\u0000\u0000\u01e3\u01e5\u0003\u0010\b\u0000\u01e4\u01e3"+
		"\u0001\u0000\u0000\u0000\u01e4\u01e5\u0001\u0000\u0000\u0000\u01e5\u01e6"+
		"\u0001\u0000\u0000\u0000\u01e6\u01e7\u0003,\u0016\u0000\u01e7\u01e8\u0003"+
		"\u009aM\u0000\u01e8\u01ed\u0003P(\u0000\u01e9\u01ea\u0005R\u0000\u0000"+
		"\u01ea\u01ec\u0005S\u0000\u0000\u01eb\u01e9\u0001\u0000\u0000\u0000\u01ec"+
		"\u01ef\u0001\u0000\u0000\u0000\u01ed\u01eb\u0001\u0000\u0000\u0000\u01ed"+
		"\u01ee\u0001\u0000\u0000\u0000\u01ee\u01f2\u0001\u0000\u0000\u0000\u01ef"+
		"\u01ed\u0001\u0000\u0000\u0000\u01f0\u01f1\u0005-\u0000\u0000\u01f1\u01f3"+
		"\u0003N\'\u0000\u01f2\u01f0\u0001\u0000\u0000\u0000\u01f2\u01f3\u0001"+
		"\u0000\u0000\u0000\u01f3\u01f4\u0001\u0000\u0000\u0000\u01f4\u01f5\u0003"+
		"*\u0015\u0000\u01f5)\u0001\u0000\u0000\u0000\u01f6\u01f9\u0003\u0094J"+
		"\u0000\u01f7\u01f9\u0005T\u0000\u0000\u01f8\u01f6\u0001\u0000\u0000\u0000"+
		"\u01f8\u01f7\u0001\u0000\u0000\u0000\u01f9+\u0001\u0000\u0000\u0000\u01fa"+
		"\u01fd\u0003\u00eau\u0000\u01fb\u01fd\u00050\u0000\u0000\u01fc\u01fa\u0001"+
		"\u0000\u0000\u0000\u01fc\u01fb\u0001\u0000\u0000\u0000\u01fd-\u0001\u0000"+
		"\u0000\u0000\u01fe\u0200\u0003\u0010\b\u0000\u01ff\u01fe\u0001\u0000\u0000"+
		"\u0000\u01ff\u0200\u0001\u0000\u0000\u0000\u0200\u0201\u0001\u0000\u0000"+
		"\u0000\u0201\u0202\u0003\u009aM\u0000\u0202\u0205\u0003P(\u0000\u0203"+
		"\u0204\u0005-\u0000\u0000\u0204\u0206\u0003N\'\u0000\u0205\u0203\u0001"+
		"\u0000\u0000\u0000\u0205\u0206\u0001\u0000\u0000\u0000\u0206\u0207\u0001"+
		"\u0000\u0000\u0000\u0207\u0208\u0003\u0094J\u0000\u0208/\u0001\u0000\u0000"+
		"\u0000\u0209\u020a\u0003\u00eau\u0000\u020a\u020b\u0003@ \u0000\u020b"+
		"\u020c\u0005T\u0000\u0000\u020c1\u0001\u0000\u0000\u0000\u020d\u020f\u0003"+
		"\b\u0004\u0000\u020e\u020d\u0001\u0000\u0000\u0000\u020f\u0212\u0001\u0000"+
		"\u0000\u0000\u0210\u020e\u0001\u0000\u0000\u0000\u0210\u0211\u0001\u0000"+
		"\u0000\u0000\u0211\u0213\u0001\u0000\u0000\u0000\u0212\u0210\u0001\u0000"+
		"\u0000\u0000\u0213\u0216\u00034\u001a\u0000\u0214\u0216\u0005T\u0000\u0000"+
		"\u0215\u0210\u0001\u0000\u0000\u0000\u0215\u0214\u0001\u0000\u0000\u0000"+
		"\u02163\u0001\u0000\u0000\u0000\u0217\u021f\u00036\u001b\u0000\u0218\u021f"+
		"\u0003:\u001d\u0000\u0219\u021f\u0003\u001e\u000f\u0000\u021a\u021f\u0003"+
		"r9\u0000\u021b\u021f\u0003\u000e\u0007\u0000\u021c\u021f\u0003\u0016\u000b"+
		"\u0000\u021d\u021f\u0003\u008aE\u0000\u021e\u0217\u0001\u0000\u0000\u0000"+
		"\u021e\u0218\u0001\u0000\u0000\u0000\u021e\u0219\u0001\u0000\u0000\u0000"+
		"\u021e\u021a\u0001\u0000\u0000\u0000\u021e\u021b\u0001\u0000\u0000\u0000"+
		"\u021e\u021c\u0001\u0000\u0000\u0000\u021e\u021d\u0001\u0000\u0000\u0000"+
		"\u021f5\u0001\u0000\u0000\u0000\u0220\u0221\u0003\u00eau\u0000\u0221\u0226"+
		"\u00038\u001c\u0000\u0222\u0223\u0005U\u0000\u0000\u0223\u0225\u00038"+
		"\u001c\u0000\u0224\u0222\u0001\u0000\u0000\u0000\u0225\u0228\u0001\u0000"+
		"\u0000\u0000\u0226\u0224\u0001\u0000\u0000\u0000\u0226\u0227\u0001\u0000"+
		"\u0000\u0000\u0227\u0229\u0001\u0000\u0000\u0000\u0228\u0226\u0001\u0000"+
		"\u0000\u0000\u0229\u022a\u0005T\u0000\u0000\u022a7\u0001\u0000\u0000\u0000"+
		"\u022b\u0230\u0003\u009aM\u0000\u022c\u022d\u0005R\u0000\u0000\u022d\u022f"+
		"\u0005S\u0000\u0000\u022e\u022c\u0001\u0000\u0000\u0000\u022f\u0232\u0001"+
		"\u0000\u0000\u0000\u0230\u022e\u0001\u0000\u0000\u0000\u0230\u0231\u0001"+
		"\u0000\u0000\u0000\u0231\u0233\u0001\u0000\u0000\u0000\u0232\u0230\u0001"+
		"\u0000\u0000\u0000\u0233\u0234\u0005W\u0000\u0000\u0234\u0235\u0003F#"+
		"\u0000\u02359\u0001\u0000\u0000\u0000\u0236\u0238\u0003<\u001e\u0000\u0237"+
		"\u0236\u0001\u0000\u0000\u0000\u0238\u023b\u0001\u0000\u0000\u0000\u0239"+
		"\u0237\u0001\u0000\u0000\u0000\u0239\u023a\u0001\u0000\u0000\u0000\u023a"+
		"\u023d\u0001\u0000\u0000\u0000\u023b\u0239\u0001\u0000\u0000\u0000\u023c"+
		"\u023e\u0003\u0010\b\u0000\u023d\u023c\u0001\u0000\u0000\u0000\u023d\u023e"+
		"\u0001\u0000\u0000\u0000\u023e\u023f\u0001\u0000\u0000\u0000\u023f\u0240"+
		"\u0003>\u001f\u0000\u0240;\u0001\u0000\u0000\u0000\u0241\u0248\u0003h"+
		"4\u0000\u0242\u0248\u0005#\u0000\u0000\u0243\u0248\u0005\u0001\u0000\u0000"+
		"\u0244\u0248\u0005\f\u0000\u0000\u0245\u0248\u0005&\u0000\u0000\u0246"+
		"\u0248\u0005\'\u0000\u0000\u0247\u0241\u0001\u0000\u0000\u0000\u0247\u0242"+
		"\u0001\u0000\u0000\u0000\u0247\u0243\u0001\u0000\u0000\u0000\u0247\u0244"+
		"\u0001\u0000\u0000\u0000\u0247\u0245\u0001\u0000\u0000\u0000\u0247\u0246"+
		"\u0001\u0000\u0000\u0000\u0248=\u0001\u0000\u0000\u0000\u0249\u024b\u0003"+
		"h4\u0000\u024a\u0249\u0001\u0000\u0000\u0000\u024b\u024e\u0001\u0000\u0000"+
		"\u0000\u024c\u024a\u0001\u0000\u0000\u0000\u024c\u024d\u0001\u0000\u0000"+
		"\u0000\u024d\u024f\u0001\u0000\u0000\u0000\u024e\u024c\u0001\u0000\u0000"+
		"\u0000\u024f\u0250\u0003,\u0016\u0000\u0250\u0251\u0003\u009aM\u0000\u0251"+
		"\u0256\u0003P(\u0000\u0252\u0253\u0005R\u0000\u0000\u0253\u0255\u0005"+
		"S\u0000\u0000\u0254\u0252\u0001\u0000\u0000\u0000\u0255\u0258\u0001\u0000"+
		"\u0000\u0000\u0256\u0254\u0001\u0000\u0000\u0000\u0256\u0257\u0001\u0000"+
		"\u0000\u0000\u0257\u025b\u0001\u0000\u0000\u0000\u0258\u0256\u0001\u0000"+
		"\u0000\u0000\u0259\u025a\u0005-\u0000\u0000\u025a\u025c\u0003N\'\u0000"+
		"\u025b\u0259\u0001\u0000\u0000\u0000\u025b\u025c\u0001\u0000\u0000\u0000"+
		"\u025c\u025d\u0001\u0000\u0000\u0000\u025d\u025e\u0003*\u0015\u0000\u025e"+
		"?\u0001\u0000\u0000\u0000\u025f\u0264\u0003B!\u0000\u0260\u0261\u0005"+
		"U\u0000\u0000\u0261\u0263\u0003B!\u0000\u0262\u0260\u0001\u0000\u0000"+
		"\u0000\u0263\u0266\u0001\u0000\u0000\u0000\u0264\u0262\u0001\u0000\u0000"+
		"\u0000\u0264\u0265\u0001\u0000\u0000\u0000\u0265A\u0001\u0000\u0000\u0000"+
		"\u0266\u0264\u0001\u0000\u0000\u0000\u0267\u026a\u0003D\"\u0000\u0268"+
		"\u0269\u0005W\u0000\u0000\u0269\u026b\u0003F#\u0000\u026a\u0268\u0001"+
		"\u0000\u0000\u0000\u026a\u026b\u0001\u0000\u0000\u0000\u026bC\u0001\u0000"+
		"\u0000\u0000\u026c\u0271\u0003\u009aM\u0000\u026d\u026e\u0005R\u0000\u0000"+
		"\u026e\u0270\u0005S\u0000\u0000\u026f\u026d\u0001\u0000\u0000\u0000\u0270"+
		"\u0273\u0001\u0000\u0000\u0000\u0271\u026f\u0001\u0000\u0000\u0000\u0271"+
		"\u0272\u0001\u0000\u0000\u0000\u0272E\u0001\u0000\u0000\u0000\u0273\u0271"+
		"\u0001\u0000\u0000\u0000\u0274\u0277\u0003H$\u0000\u0275\u0277\u0003\u00c0"+
		"`\u0000\u0276\u0274\u0001\u0000\u0000\u0000\u0276\u0275\u0001\u0000\u0000"+
		"\u0000\u0277G\u0001\u0000\u0000\u0000\u0278\u0284\u0005P\u0000\u0000\u0279"+
		"\u027e\u0003F#\u0000\u027a\u027b\u0005U\u0000\u0000\u027b\u027d\u0003"+
		"F#\u0000\u027c\u027a\u0001\u0000\u0000\u0000\u027d\u0280\u0001\u0000\u0000"+
		"\u0000\u027e\u027c\u0001\u0000\u0000\u0000\u027e\u027f\u0001\u0000\u0000"+
		"\u0000\u027f\u0282\u0001\u0000\u0000\u0000\u0280\u027e\u0001\u0000\u0000"+
		"\u0000\u0281\u0283\u0005U\u0000\u0000\u0282\u0281\u0001\u0000\u0000\u0000"+
		"\u0282\u0283\u0001\u0000\u0000\u0000\u0283\u0285\u0001\u0000\u0000\u0000"+
		"\u0284\u0279\u0001\u0000\u0000\u0000\u0284\u0285\u0001\u0000\u0000\u0000"+
		"\u0285\u0286\u0001\u0000\u0000\u0000\u0286\u0287\u0005Q\u0000\u0000\u0287"+
		"I\u0001\u0000\u0000\u0000\u0288\u028a\u0003\u009aM\u0000\u0289\u028b\u0003"+
		"\u00eew\u0000\u028a\u0289\u0001\u0000\u0000\u0000\u028a\u028b\u0001\u0000"+
		"\u0000\u0000\u028b\u0293\u0001\u0000\u0000\u0000\u028c\u028d\u0005V\u0000"+
		"\u0000\u028d\u028f\u0003\u009aM\u0000\u028e\u0290\u0003\u00eew\u0000\u028f"+
		"\u028e\u0001\u0000\u0000\u0000\u028f\u0290\u0001\u0000\u0000\u0000\u0290"+
		"\u0292\u0001\u0000\u0000\u0000\u0291\u028c\u0001\u0000\u0000\u0000\u0292"+
		"\u0295\u0001\u0000\u0000\u0000\u0293\u0291\u0001\u0000\u0000\u0000\u0293"+
		"\u0294\u0001\u0000\u0000\u0000\u0294K\u0001\u0000\u0000\u0000\u0295\u0293"+
		"\u0001\u0000\u0000\u0000\u0296\u02a3\u0003\u00eau\u0000\u0297\u0299\u0003"+
		"h4\u0000\u0298\u0297\u0001\u0000\u0000\u0000\u0299\u029c\u0001\u0000\u0000"+
		"\u0000\u029a\u0298\u0001\u0000\u0000\u0000\u029a\u029b\u0001\u0000\u0000"+
		"\u0000\u029b\u029d\u0001\u0000\u0000\u0000\u029c\u029a\u0001\u0000\u0000"+
		"\u0000\u029d\u02a0\u0005\\\u0000\u0000\u029e\u029f\u0007\u0000\u0000\u0000"+
		"\u029f\u02a1\u0003\u00eau\u0000\u02a0\u029e\u0001\u0000\u0000\u0000\u02a0"+
		"\u02a1\u0001\u0000\u0000\u0000\u02a1\u02a3\u0001\u0000\u0000\u0000\u02a2"+
		"\u0296\u0001\u0000\u0000\u0000\u02a2\u029a\u0001\u0000\u0000\u0000\u02a3"+
		"M\u0001\u0000\u0000\u0000\u02a4\u02a9\u0003^/\u0000\u02a5\u02a6\u0005"+
		"U\u0000\u0000\u02a6\u02a8\u0003^/\u0000\u02a7\u02a5\u0001\u0000\u0000"+
		"\u0000\u02a8\u02ab\u0001\u0000\u0000\u0000\u02a9\u02a7\u0001\u0000\u0000"+
		"\u0000\u02a9\u02aa\u0001\u0000\u0000\u0000\u02aaO\u0001\u0000\u0000\u0000"+
		"\u02ab\u02a9\u0001\u0000\u0000\u0000\u02ac\u02b8\u0005N\u0000\u0000\u02ad"+
		"\u02af\u0003R)\u0000\u02ae\u02ad\u0001\u0000\u0000\u0000\u02ae\u02af\u0001"+
		"\u0000\u0000\u0000\u02af\u02b9\u0001\u0000\u0000\u0000\u02b0\u02b3\u0003"+
		"R)\u0000\u02b1\u02b2\u0005U\u0000\u0000\u02b2\u02b4\u0003T*\u0000\u02b3"+
		"\u02b1\u0001\u0000\u0000\u0000\u02b3\u02b4\u0001\u0000\u0000\u0000\u02b4"+
		"\u02b9\u0001\u0000\u0000\u0000\u02b5\u02b7\u0003T*\u0000\u02b6\u02b5\u0001"+
		"\u0000\u0000\u0000\u02b6\u02b7\u0001\u0000\u0000\u0000\u02b7\u02b9\u0001"+
		"\u0000\u0000\u0000\u02b8\u02ae\u0001\u0000\u0000\u0000\u02b8\u02b0\u0001"+
		"\u0000\u0000\u0000\u02b8\u02b6\u0001\u0000\u0000\u0000\u02b9\u02ba\u0001"+
		"\u0000\u0000\u0000\u02ba\u02bb\u0005O\u0000\u0000\u02bbQ\u0001\u0000\u0000"+
		"\u0000\u02bc\u02c2\u0003\u00eau\u0000\u02bd\u02be\u0003\u009aM\u0000\u02be"+
		"\u02bf\u0005V\u0000\u0000\u02bf\u02c1\u0001\u0000\u0000\u0000\u02c0\u02bd"+
		"\u0001\u0000\u0000\u0000\u02c1\u02c4\u0001\u0000\u0000\u0000\u02c2\u02c0"+
		"\u0001\u0000\u0000\u0000\u02c2\u02c3\u0001\u0000\u0000\u0000\u02c3\u02c5"+
		"\u0001\u0000\u0000\u0000\u02c4\u02c2\u0001\u0000\u0000\u0000\u02c5\u02c6"+
		"\u0005+\u0000\u0000\u02c6S\u0001\u0000\u0000\u0000\u02c7\u02cc\u0003V"+
		"+\u0000\u02c8\u02c9\u0005U\u0000\u0000\u02c9\u02cb\u0003V+\u0000\u02ca"+
		"\u02c8\u0001\u0000\u0000\u0000\u02cb\u02ce\u0001\u0000\u0000\u0000\u02cc"+
		"\u02ca\u0001\u0000\u0000\u0000\u02cc\u02cd\u0001\u0000\u0000\u0000\u02cd"+
		"\u02d1\u0001\u0000\u0000\u0000\u02ce\u02cc\u0001\u0000\u0000\u0000\u02cf"+
		"\u02d0\u0005U\u0000\u0000\u02d0\u02d2\u0003X,\u0000\u02d1\u02cf\u0001"+
		"\u0000\u0000\u0000\u02d1\u02d2\u0001\u0000\u0000\u0000\u02d2\u02d5\u0001"+
		"\u0000\u0000\u0000\u02d3\u02d5\u0003X,\u0000\u02d4\u02c7\u0001\u0000\u0000"+
		"\u0000\u02d4\u02d3\u0001\u0000\u0000\u0000\u02d5U\u0001\u0000\u0000\u0000"+
		"\u02d6\u02d8\u0003\f\u0006\u0000\u02d7\u02d6\u0001\u0000\u0000\u0000\u02d8"+
		"\u02db\u0001\u0000\u0000\u0000\u02d9\u02d7\u0001\u0000\u0000\u0000\u02d9"+
		"\u02da\u0001\u0000\u0000\u0000\u02da\u02dc\u0001\u0000\u0000\u0000\u02db"+
		"\u02d9\u0001\u0000\u0000\u0000\u02dc\u02dd\u0003\u00eau\u0000\u02dd\u02de"+
		"\u0003D\"\u0000\u02deW\u0001\u0000\u0000\u0000\u02df\u02e1\u0003\f\u0006"+
		"\u0000\u02e0\u02df\u0001\u0000\u0000\u0000\u02e1\u02e4\u0001\u0000\u0000"+
		"\u0000\u02e2\u02e0\u0001\u0000\u0000\u0000\u02e2\u02e3\u0001\u0000\u0000"+
		"\u0000\u02e3\u02e5\u0001\u0000\u0000\u0000\u02e4\u02e2\u0001\u0000\u0000"+
		"\u0000\u02e5\u02e9\u0003\u00eau\u0000\u02e6\u02e8\u0003h4\u0000\u02e7"+
		"\u02e6\u0001\u0000\u0000\u0000\u02e8\u02eb\u0001\u0000\u0000\u0000\u02e9"+
		"\u02e7\u0001\u0000\u0000\u0000\u02e9\u02ea\u0001\u0000\u0000\u0000\u02ea"+
		"\u02ec\u0001\u0000\u0000\u0000\u02eb\u02e9\u0001\u0000\u0000\u0000\u02ec"+
		"\u02ed\u0005|\u0000\u0000\u02ed\u02ee\u0003D\"\u0000\u02eeY\u0001\u0000"+
		"\u0000\u0000\u02ef\u02f4\u0003\\.\u0000\u02f0\u02f1\u0005U\u0000\u0000"+
		"\u02f1\u02f3\u0003\\.\u0000\u02f2\u02f0\u0001\u0000\u0000\u0000\u02f3"+
		"\u02f6\u0001\u0000\u0000\u0000\u02f4\u02f2\u0001\u0000\u0000\u0000\u02f4"+
		"\u02f5\u0001\u0000\u0000\u0000\u02f5[\u0001\u0000\u0000\u0000\u02f6\u02f4"+
		"\u0001\u0000\u0000\u0000\u02f7\u02f9\u0003\f\u0006\u0000\u02f8\u02f7\u0001"+
		"\u0000\u0000\u0000\u02f9\u02fc\u0001\u0000\u0000\u0000\u02fa\u02f8\u0001"+
		"\u0000\u0000\u0000\u02fa\u02fb\u0001\u0000\u0000\u0000\u02fb\u02fd\u0001"+
		"\u0000\u0000\u0000\u02fc\u02fa\u0001\u0000\u0000\u0000\u02fd\u02fe\u0005"+
		"=\u0000\u0000\u02fe\u02ff\u0003\u009aM\u0000\u02ff]\u0001\u0000\u0000"+
		"\u0000\u0300\u0305\u0003\u009aM\u0000\u0301\u0302\u0005V\u0000\u0000\u0302"+
		"\u0304\u0003\u009aM\u0000\u0303\u0301\u0001\u0000\u0000\u0000\u0304\u0307"+
		"\u0001\u0000\u0000\u0000\u0305\u0303\u0001\u0000\u0000\u0000\u0305\u0306"+
		"\u0001\u0000\u0000\u0000\u0306_\u0001\u0000\u0000\u0000\u0307\u0305\u0001"+
		"\u0000\u0000\u0000\u0308\u0310\u0003b1\u0000\u0309\u0310\u0003d2\u0000"+
		"\u030a\u0310\u0005J\u0000\u0000\u030b\u0310\u0005K\u0000\u0000\u030c\u0310"+
		"\u0005I\u0000\u0000\u030d\u0310\u0005M\u0000\u0000\u030e\u0310\u0005L"+
		"\u0000\u0000\u030f\u0308\u0001\u0000\u0000\u0000\u030f\u0309\u0001\u0000"+
		"\u0000\u0000\u030f\u030a\u0001\u0000\u0000\u0000\u030f\u030b\u0001\u0000"+
		"\u0000\u0000\u030f\u030c\u0001\u0000\u0000\u0000\u030f\u030d\u0001\u0000"+
		"\u0000\u0000\u030f\u030e\u0001\u0000\u0000\u0000\u0310a\u0001\u0000\u0000"+
		"\u0000\u0311\u0312\u0007\u0001\u0000\u0000\u0312c\u0001\u0000\u0000\u0000"+
		"\u0313\u0314\u0007\u0002\u0000\u0000\u0314e\u0001\u0000\u0000\u0000\u0315"+
		"\u0316\u0003\u009aM\u0000\u0316\u0317\u0005V\u0000\u0000\u0317\u0319\u0001"+
		"\u0000\u0000\u0000\u0318\u0315\u0001\u0000\u0000\u0000\u0319\u031c\u0001"+
		"\u0000\u0000\u0000\u031a\u0318\u0001\u0000\u0000\u0000\u031a\u031b\u0001"+
		"\u0000\u0000\u0000\u031b\u031d\u0001\u0000\u0000\u0000\u031c\u031a\u0001"+
		"\u0000\u0000\u0000\u031d\u031e\u0005{\u0000\u0000\u031e\u031f\u0003\u009a"+
		"M\u0000\u031fg\u0001\u0000\u0000\u0000\u0320\u0321\u0005{\u0000\u0000"+
		"\u0321\u0324\u0003^/\u0000\u0322\u0324\u0003f3\u0000\u0323\u0320\u0001"+
		"\u0000\u0000\u0000\u0323\u0322\u0001\u0000\u0000\u0000\u0324\u032b\u0001"+
		"\u0000\u0000\u0000\u0325\u0328\u0005N\u0000\u0000\u0326\u0329\u0003j5"+
		"\u0000\u0327\u0329\u0003n7\u0000\u0328\u0326\u0001\u0000\u0000\u0000\u0328"+
		"\u0327\u0001\u0000\u0000\u0000\u0328\u0329\u0001\u0000\u0000\u0000\u0329"+
		"\u032a\u0001\u0000\u0000\u0000\u032a\u032c\u0005O\u0000\u0000\u032b\u0325"+
		"\u0001\u0000\u0000\u0000\u032b\u032c\u0001\u0000\u0000\u0000\u032ci\u0001"+
		"\u0000\u0000\u0000\u032d\u0332\u0003l6\u0000\u032e\u032f\u0005U\u0000"+
		"\u0000\u032f\u0331\u0003l6\u0000\u0330\u032e\u0001\u0000\u0000\u0000\u0331"+
		"\u0334\u0001\u0000\u0000\u0000\u0332\u0330\u0001\u0000\u0000\u0000\u0332"+
		"\u0333\u0001\u0000\u0000\u0000\u0333k\u0001\u0000\u0000\u0000\u0334\u0332"+
		"\u0001\u0000\u0000\u0000\u0335\u0336\u0003\u009aM\u0000\u0336\u0337\u0005"+
		"W\u0000\u0000\u0337\u0338\u0003n7\u0000\u0338m\u0001\u0000\u0000\u0000"+
		"\u0339\u033d\u0003\u00c0`\u0000\u033a\u033d\u0003h4\u0000\u033b\u033d"+
		"\u0003p8\u0000\u033c\u0339\u0001\u0000\u0000\u0000\u033c\u033a\u0001\u0000"+
		"\u0000\u0000\u033c\u033b\u0001\u0000\u0000\u0000\u033do\u0001\u0000\u0000"+
		"\u0000\u033e\u0347\u0005P\u0000\u0000\u033f\u0344\u0003n7\u0000\u0340"+
		"\u0341\u0005U\u0000\u0000\u0341\u0343\u0003n7\u0000\u0342\u0340\u0001"+
		"\u0000\u0000\u0000\u0343\u0346\u0001\u0000\u0000\u0000\u0344\u0342\u0001"+
		"\u0000\u0000\u0000\u0344\u0345\u0001\u0000\u0000\u0000\u0345\u0348\u0001"+
		"\u0000\u0000\u0000\u0346\u0344\u0001\u0000\u0000\u0000\u0347\u033f\u0001"+
		"\u0000\u0000\u0000\u0347\u0348\u0001\u0000\u0000\u0000\u0348\u034a\u0001"+
		"\u0000\u0000\u0000\u0349\u034b\u0005U\u0000\u0000\u034a\u0349\u0001\u0000"+
		"\u0000\u0000\u034a\u034b\u0001\u0000\u0000\u0000\u034b\u034c\u0001\u0000"+
		"\u0000\u0000\u034c\u034d\u0005Q\u0000\u0000\u034dq\u0001\u0000\u0000\u0000"+
		"\u034e\u034f\u0005{\u0000\u0000\u034f\u0350\u0005\u001c\u0000\u0000\u0350"+
		"\u0351\u0003\u009aM\u0000\u0351\u0352\u0003t:\u0000\u0352s\u0001\u0000"+
		"\u0000\u0000\u0353\u0357\u0005P\u0000\u0000\u0354\u0356\u0003v;\u0000"+
		"\u0355\u0354\u0001\u0000\u0000\u0000\u0356\u0359\u0001\u0000\u0000\u0000"+
		"\u0357\u0355\u0001\u0000\u0000\u0000\u0357\u0358\u0001\u0000\u0000\u0000"+
		"\u0358\u035a\u0001\u0000\u0000\u0000\u0359\u0357\u0001\u0000\u0000\u0000"+
		"\u035a\u035b\u0005Q\u0000\u0000\u035bu\u0001\u0000\u0000\u0000\u035c\u035e"+
		"\u0003\b\u0004\u0000\u035d\u035c\u0001\u0000\u0000\u0000\u035e\u0361\u0001"+
		"\u0000\u0000\u0000\u035f\u035d\u0001\u0000\u0000\u0000\u035f\u0360\u0001"+
		"\u0000\u0000\u0000\u0360\u0362\u0001\u0000\u0000\u0000\u0361\u035f\u0001"+
		"\u0000\u0000\u0000\u0362\u0365\u0003x<\u0000\u0363\u0365\u0005T\u0000"+
		"\u0000\u0364\u035f\u0001\u0000\u0000\u0000\u0364\u0363\u0001\u0000\u0000"+
		"\u0000\u0365w\u0001\u0000\u0000\u0000\u0366\u0367\u0003\u00eau\u0000\u0367"+
		"\u0368\u0003z=\u0000\u0368\u0369\u0005T\u0000\u0000\u0369\u037f\u0001"+
		"\u0000\u0000\u0000\u036a\u036c\u0003\u000e\u0007\u0000\u036b\u036d\u0005"+
		"T\u0000\u0000\u036c\u036b\u0001\u0000\u0000\u0000\u036c\u036d\u0001\u0000"+
		"\u0000\u0000\u036d\u037f\u0001\u0000\u0000\u0000\u036e\u0370\u0003\u001e"+
		"\u000f\u0000\u036f\u0371\u0005T\u0000\u0000\u0370\u036f\u0001\u0000\u0000"+
		"\u0000\u0370\u0371\u0001\u0000\u0000\u0000\u0371\u037f\u0001\u0000\u0000"+
		"\u0000\u0372\u0374\u0003\u0016\u000b\u0000\u0373\u0375\u0005T\u0000\u0000"+
		"\u0374\u0373\u0001\u0000\u0000\u0000\u0374\u0375\u0001\u0000\u0000\u0000"+
		"\u0375\u037f\u0001\u0000\u0000\u0000\u0376\u0378\u0003r9\u0000\u0377\u0379"+
		"\u0005T\u0000\u0000\u0378\u0377\u0001\u0000\u0000\u0000\u0378\u0379\u0001"+
		"\u0000\u0000\u0000\u0379\u037f\u0001\u0000\u0000\u0000\u037a\u037c\u0003"+
		"\u008aE\u0000\u037b\u037d\u0005T\u0000\u0000\u037c\u037b\u0001\u0000\u0000"+
		"\u0000\u037c\u037d\u0001\u0000\u0000\u0000\u037d\u037f\u0001\u0000\u0000"+
		"\u0000\u037e\u0366\u0001\u0000\u0000\u0000\u037e\u036a\u0001\u0000\u0000"+
		"\u0000\u037e\u036e\u0001\u0000\u0000\u0000\u037e\u0372\u0001\u0000\u0000"+
		"\u0000\u037e\u0376\u0001\u0000\u0000\u0000\u037e\u037a\u0001\u0000\u0000"+
		"\u0000\u037fy\u0001\u0000\u0000\u0000\u0380\u0383\u0003|>\u0000\u0381"+
		"\u0383\u0003~?\u0000\u0382\u0380\u0001\u0000\u0000\u0000\u0382\u0381\u0001"+
		"\u0000\u0000\u0000\u0383{\u0001\u0000\u0000\u0000\u0384\u0385\u0003\u009a"+
		"M\u0000\u0385\u0386\u0005N\u0000\u0000\u0386\u0388\u0005O\u0000\u0000"+
		"\u0387\u0389\u0003\u0080@\u0000\u0388\u0387\u0001\u0000\u0000\u0000\u0388"+
		"\u0389\u0001\u0000\u0000\u0000\u0389}\u0001\u0000\u0000\u0000\u038a\u038b"+
		"\u0003@ \u0000\u038b\u007f\u0001\u0000\u0000\u0000\u038c\u038d\u0005\f"+
		"\u0000\u0000\u038d\u038e\u0003n7\u0000\u038e\u0081\u0001\u0000\u0000\u0000"+
		"\u038f\u0391\u00054\u0000\u0000\u0390\u038f\u0001\u0000\u0000\u0000\u0390"+
		"\u0391\u0001\u0000\u0000\u0000\u0391\u0392\u0001\u0000\u0000\u0000\u0392"+
		"\u0393\u00053\u0000\u0000\u0393\u0394\u0003^/\u0000\u0394\u0395\u0003"+
		"\u0084B\u0000\u0395\u0083\u0001\u0000\u0000\u0000\u0396\u039a\u0005P\u0000"+
		"\u0000\u0397\u0399\u0003\u0086C\u0000\u0398\u0397\u0001\u0000\u0000\u0000"+
		"\u0399\u039c\u0001\u0000\u0000\u0000\u039a\u0398\u0001\u0000\u0000\u0000"+
		"\u039a\u039b\u0001\u0000\u0000\u0000\u039b\u039d\u0001\u0000\u0000\u0000"+
		"\u039c\u039a\u0001\u0000\u0000\u0000\u039d\u039e\u0005Q\u0000\u0000\u039e"+
		"\u0085\u0001\u0000\u0000\u0000\u039f\u03a3\u00055\u0000\u0000\u03a0\u03a2"+
		"\u0003\u0088D\u0000\u03a1\u03a0\u0001\u0000\u0000\u0000\u03a2\u03a5\u0001"+
		"\u0000\u0000\u0000\u03a3\u03a1\u0001\u0000\u0000\u0000\u03a3\u03a4\u0001"+
		"\u0000\u0000\u0000\u03a4\u03a6\u0001\u0000\u0000\u0000\u03a5\u03a3\u0001"+
		"\u0000\u0000\u0000\u03a6\u03a7\u0003^/\u0000\u03a7\u03a8\u0005T\u0000"+
		"\u0000\u03a8\u03c4\u0001\u0000\u0000\u0000\u03a9\u03aa\u00056\u0000\u0000"+
		"\u03aa\u03ad\u0003^/\u0000\u03ab\u03ac\u00058\u0000\u0000\u03ac\u03ae"+
		"\u0003^/\u0000\u03ad\u03ab\u0001\u0000\u0000\u0000\u03ad\u03ae\u0001\u0000"+
		"\u0000\u0000\u03ae\u03af\u0001\u0000\u0000\u0000\u03af\u03b0\u0005T\u0000"+
		"\u0000\u03b0\u03c4\u0001\u0000\u0000\u0000\u03b1\u03b2\u00057\u0000\u0000"+
		"\u03b2\u03b5\u0003^/\u0000\u03b3\u03b4\u00058\u0000\u0000\u03b4\u03b6"+
		"\u0003^/\u0000\u03b5\u03b3\u0001\u0000\u0000\u0000\u03b5\u03b6\u0001\u0000"+
		"\u0000\u0000\u03b6\u03b7\u0001\u0000\u0000\u0000\u03b7\u03b8\u0005T\u0000"+
		"\u0000\u03b8\u03c4\u0001\u0000\u0000\u0000\u03b9\u03ba\u00059\u0000\u0000"+
		"\u03ba\u03bb\u0003^/\u0000\u03bb\u03bc\u0005T\u0000\u0000\u03bc\u03c4"+
		"\u0001\u0000\u0000\u0000\u03bd\u03be\u0005:\u0000\u0000\u03be\u03bf\u0003"+
		"^/\u0000\u03bf\u03c0\u0005;\u0000\u0000\u03c0\u03c1\u0003^/\u0000\u03c1"+
		"\u03c2\u0005T\u0000\u0000\u03c2\u03c4\u0001\u0000\u0000\u0000\u03c3\u039f"+
		"\u0001\u0000\u0000\u0000\u03c3\u03a9\u0001\u0000\u0000\u0000\u03c3\u03b1"+
		"\u0001\u0000\u0000\u0000\u03c3\u03b9\u0001\u0000\u0000\u0000\u03c3\u03bd"+
		"\u0001\u0000\u0000\u0000\u03c4\u0087\u0001\u0000\u0000\u0000\u03c5\u03c6"+
		"\u0007\u0003\u0000\u0000\u03c6\u0089\u0001\u0000\u0000\u0000\u03c7\u03c8"+
		"\u0005?\u0000\u0000\u03c8\u03ca\u0003\u009aM\u0000\u03c9\u03cb\u0003\u0010"+
		"\b\u0000\u03ca\u03c9\u0001\u0000\u0000\u0000\u03ca\u03cb\u0001\u0000\u0000"+
		"\u0000\u03cb\u03cc\u0001\u0000\u0000\u0000\u03cc\u03cf\u0003\u008cF\u0000"+
		"\u03cd\u03ce\u0005\u0018\u0000\u0000\u03ce\u03d0\u0003\u00e8t\u0000\u03cf"+
		"\u03cd\u0001\u0000\u0000\u0000\u03cf\u03d0\u0001\u0000\u0000\u0000\u03d0"+
		"\u03d1\u0001\u0000\u0000\u0000\u03d1\u03d2\u0003\u0092I\u0000\u03d2\u008b"+
		"\u0001\u0000\u0000\u0000\u03d3\u03d5\u0005N\u0000\u0000\u03d4\u03d6\u0003"+
		"\u008eG\u0000\u03d5\u03d4\u0001\u0000\u0000\u0000\u03d5\u03d6\u0001\u0000"+
		"\u0000\u0000\u03d6\u03d7\u0001\u0000\u0000\u0000\u03d7\u03d8\u0005O\u0000"+
		"\u0000\u03d8\u008d\u0001\u0000\u0000\u0000\u03d9\u03de\u0003\u0090H\u0000"+
		"\u03da\u03db\u0005U\u0000\u0000\u03db\u03dd\u0003\u0090H\u0000\u03dc\u03da"+
		"\u0001\u0000\u0000\u0000\u03dd\u03e0\u0001\u0000\u0000\u0000\u03de\u03dc"+
		"\u0001\u0000\u0000\u0000\u03de\u03df\u0001\u0000\u0000\u0000\u03df\u008f"+
		"\u0001\u0000\u0000\u0000\u03e0\u03de\u0001\u0000\u0000\u0000\u03e1\u03e2"+
		"\u0003\u00eau\u0000\u03e2\u03e3\u0003\u009aM\u0000\u03e3\u0091\u0001\u0000"+
		"\u0000\u0000\u03e4\u03e8\u0005P\u0000\u0000\u03e5\u03e7\u0003$\u0012\u0000"+
		"\u03e6\u03e5\u0001\u0000\u0000\u0000\u03e7\u03ea\u0001\u0000\u0000\u0000"+
		"\u03e8\u03e6\u0001\u0000\u0000\u0000\u03e8\u03e9\u0001\u0000\u0000\u0000"+
		"\u03e9\u03eb\u0001\u0000\u0000\u0000\u03ea\u03e8\u0001\u0000\u0000\u0000"+
		"\u03eb\u03ec\u0005Q\u0000\u0000\u03ec\u0093\u0001\u0000\u0000\u0000\u03ed"+
		"\u03f1\u0005P\u0000\u0000\u03ee\u03f0\u0003\u0096K\u0000\u03ef\u03ee\u0001"+
		"\u0000\u0000\u0000\u03f0\u03f3\u0001\u0000\u0000\u0000\u03f1\u03ef\u0001"+
		"\u0000\u0000\u0000\u03f1\u03f2\u0001\u0000\u0000\u0000\u03f2\u03f4\u0001"+
		"\u0000\u0000\u0000\u03f3\u03f1\u0001\u0000\u0000\u0000\u03f4\u03f5\u0005"+
		"Q\u0000\u0000\u03f5\u0095\u0001\u0000\u0000\u0000\u03f6\u03f7\u0003\u0098"+
		"L\u0000\u03f7\u03f8\u0005T\u0000\u0000\u03f8\u03fc\u0001\u0000\u0000\u0000"+
		"\u03f9\u03fc\u0003\u009cN\u0000\u03fa\u03fc\u0003\u009eO\u0000\u03fb\u03f6"+
		"\u0001\u0000\u0000\u0000\u03fb\u03f9\u0001\u0000\u0000\u0000\u03fb\u03fa"+
		"\u0001\u0000\u0000\u0000\u03fc\u0097\u0001\u0000\u0000\u0000\u03fd\u03ff"+
		"\u0003\f\u0006\u0000\u03fe\u03fd\u0001\u0000\u0000\u0000\u03ff\u0402\u0001"+
		"\u0000\u0000\u0000\u0400\u03fe\u0001\u0000\u0000\u0000\u0400\u0401\u0001"+
		"\u0000\u0000\u0000\u0401\u040b\u0001\u0000\u0000\u0000\u0402\u0400\u0001"+
		"\u0000\u0000\u0000\u0403\u0404\u0005=\u0000\u0000\u0404\u0405\u0003\u009a"+
		"M\u0000\u0405\u0406\u0005W\u0000\u0000\u0406\u0407\u0003\u00c0`\u0000"+
		"\u0407\u040c\u0001\u0000\u0000\u0000\u0408\u0409\u0003\u00eau\u0000\u0409"+
		"\u040a\u0003@ \u0000\u040a\u040c\u0001\u0000\u0000\u0000\u040b\u0403\u0001"+
		"\u0000\u0000\u0000\u040b\u0408\u0001\u0000\u0000\u0000\u040c\u0099\u0001"+
		"\u0000\u0000\u0000\u040d\u040e\u0007\u0004\u0000\u0000\u040e\u009b\u0001"+
		"\u0000\u0000\u0000\u040f\u0411\u0003\n\u0005\u0000\u0410\u040f\u0001\u0000"+
		"\u0000\u0000\u0411\u0414\u0001\u0000\u0000\u0000\u0412\u0410\u0001\u0000"+
		"\u0000\u0000\u0412\u0413\u0001\u0000\u0000\u0000\u0413\u0418\u0001\u0000"+
		"\u0000\u0000\u0414\u0412\u0001\u0000\u0000\u0000\u0415\u0419\u0003\u000e"+
		"\u0007\u0000\u0416\u0419\u0003\u001e\u000f\u0000\u0417\u0419\u0003\u008a"+
		"E\u0000\u0418\u0415\u0001\u0000\u0000\u0000\u0418\u0416\u0001\u0000\u0000"+
		"\u0000\u0418\u0417\u0001\u0000\u0000\u0000\u0419\u041c\u0001\u0000\u0000"+
		"\u0000\u041a\u041c\u0005T\u0000\u0000\u041b\u0412\u0001\u0000\u0000\u0000"+
		"\u041b\u041a\u0001\u0000\u0000\u0000\u041c\u009d\u0001\u0000\u0000\u0000"+
		"\u041d\u048f\u0003\u0094J\u0000\u041e\u041f\u0005\u0002\u0000\u0000\u041f"+
		"\u0422\u0003\u00c0`\u0000\u0420\u0421\u0005]\u0000\u0000\u0421\u0423\u0003"+
		"\u00c0`\u0000\u0422\u0420\u0001\u0000\u0000\u0000\u0422\u0423\u0001\u0000"+
		"\u0000\u0000\u0423\u0424\u0001\u0000\u0000\u0000\u0424\u0425\u0005T\u0000"+
		"\u0000\u0425\u048f\u0001\u0000\u0000\u0000\u0426\u0427\u0005\u0016\u0000"+
		"\u0000\u0427\u0428\u0003\u00ba]\u0000\u0428\u042b\u0003\u009eO\u0000\u0429"+
		"\u042a\u0005\u000f\u0000\u0000\u042a\u042c\u0003\u009eO\u0000\u042b\u0429"+
		"\u0001\u0000\u0000\u0000\u042b\u042c\u0001\u0000\u0000\u0000\u042c\u048f"+
		"\u0001\u0000\u0000\u0000\u042d\u042e\u0005\u0015\u0000\u0000\u042e\u042f"+
		"\u0005N\u0000\u0000\u042f\u0430\u0003\u00b0X\u0000\u0430\u0431\u0005O"+
		"\u0000\u0000\u0431\u0432\u0003\u009eO\u0000\u0432\u048f\u0001\u0000\u0000"+
		"\u0000\u0433\u0434\u00052\u0000\u0000\u0434\u0435\u0003\u00ba]\u0000\u0435"+
		"\u0436\u0003\u009eO\u0000\u0436\u048f\u0001\u0000\u0000\u0000\u0437\u0438"+
		"\u0005\r\u0000\u0000\u0438\u0439\u0003\u009eO\u0000\u0439\u043a\u0005"+
		"2\u0000\u0000\u043a\u043b\u0003\u00ba]\u0000\u043b\u043c\u0005T\u0000"+
		"\u0000\u043c\u048f\u0001\u0000\u0000\u0000\u043d\u043e\u0005)\u0000\u0000"+
		"\u043e\u043f\u0003\u00ba]\u0000\u043f\u0443\u0005P\u0000\u0000\u0440\u0442"+
		"\u0003\u00acV\u0000\u0441\u0440\u0001\u0000\u0000\u0000\u0442\u0445\u0001"+
		"\u0000\u0000\u0000\u0443\u0441\u0001\u0000\u0000\u0000\u0443\u0444\u0001"+
		"\u0000\u0000\u0000\u0444\u0449\u0001\u0000\u0000\u0000\u0445\u0443\u0001"+
		"\u0000\u0000\u0000\u0446\u0448\u0003\u00aeW\u0000\u0447\u0446\u0001\u0000"+
		"\u0000\u0000\u0448\u044b\u0001\u0000\u0000\u0000\u0449\u0447\u0001\u0000"+
		"\u0000\u0000\u0449\u044a\u0001\u0000\u0000\u0000\u044a\u044c\u0001\u0000"+
		"\u0000\u0000\u044b\u0449\u0001\u0000\u0000\u0000\u044c\u044d\u0005Q\u0000"+
		"\u0000\u044d\u048f\u0001\u0000\u0000\u0000\u044e\u044f\u0005/\u0000\u0000"+
		"\u044f\u0459\u0003\u0094J\u0000\u0450\u0452\u0003\u00a0P\u0000\u0451\u0450"+
		"\u0001\u0000\u0000\u0000\u0452\u0453\u0001\u0000\u0000\u0000\u0453\u0451"+
		"\u0001\u0000\u0000\u0000\u0453\u0454\u0001\u0000\u0000\u0000\u0454\u0456"+
		"\u0001\u0000\u0000\u0000\u0455\u0457\u0003\u00a4R\u0000\u0456\u0455\u0001"+
		"\u0000\u0000\u0000\u0456\u0457\u0001\u0000\u0000\u0000\u0457\u045a\u0001"+
		"\u0000\u0000\u0000\u0458\u045a\u0003\u00a4R\u0000\u0459\u0451\u0001\u0000"+
		"\u0000\u0000\u0459\u0458\u0001\u0000\u0000\u0000\u045a\u048f\u0001\u0000"+
		"\u0000\u0000\u045b\u045c\u0005/\u0000\u0000\u045c\u045d\u0003\u00a6S\u0000"+
		"\u045d\u0461\u0003\u0094J\u0000\u045e\u0460\u0003\u00a0P\u0000\u045f\u045e"+
		"\u0001\u0000\u0000\u0000\u0460\u0463\u0001\u0000\u0000\u0000\u0461\u045f"+
		"\u0001\u0000\u0000\u0000\u0461\u0462\u0001\u0000\u0000\u0000\u0462\u0465"+
		"\u0001\u0000\u0000\u0000\u0463\u0461\u0001\u0000\u0000\u0000\u0464\u0466"+
		"\u0003\u00a4R\u0000\u0465\u0464\u0001\u0000\u0000\u0000\u0465\u0466\u0001"+
		"\u0000\u0000\u0000\u0466\u048f\u0001\u0000\u0000\u0000\u0467\u0468\u0005"+
		"*\u0000\u0000\u0468\u0469\u0003\u00ba]\u0000\u0469\u046a\u0003\u0094J"+
		"\u0000\u046a\u048f\u0001\u0000\u0000\u0000\u046b\u046d\u0005$\u0000\u0000"+
		"\u046c\u046e\u0003\u00c0`\u0000\u046d\u046c\u0001\u0000\u0000\u0000\u046d"+
		"\u046e\u0001\u0000\u0000\u0000\u046e\u046f\u0001\u0000\u0000\u0000\u046f"+
		"\u048f\u0005T\u0000\u0000\u0470\u0471\u0005,\u0000\u0000\u0471\u0472\u0003"+
		"\u00c0`\u0000\u0472\u0473\u0005T\u0000\u0000\u0473\u048f\u0001\u0000\u0000"+
		"\u0000\u0474\u0476\u0005\u0004\u0000\u0000\u0475\u0477\u0003\u009aM\u0000"+
		"\u0476\u0475\u0001\u0000\u0000\u0000\u0476\u0477\u0001\u0000\u0000\u0000"+
		"\u0477\u0478\u0001\u0000\u0000\u0000\u0478\u048f\u0005T\u0000\u0000\u0479"+
		"\u047b\u0005\u000b\u0000\u0000\u047a\u047c\u0003\u009aM\u0000\u047b\u047a"+
		"\u0001\u0000\u0000\u0000\u047b\u047c\u0001\u0000\u0000\u0000\u047c\u047d"+
		"\u0001\u0000\u0000\u0000\u047d\u048f\u0005T\u0000\u0000\u047e\u047f\u0005"+
		">\u0000\u0000\u047f\u0480\u0003\u00c0`\u0000\u0480\u0481\u0005T\u0000"+
		"\u0000\u0481\u048f\u0001\u0000\u0000\u0000\u0482\u048f\u0005T\u0000\u0000"+
		"\u0483\u0484\u0003\u00c0`\u0000\u0484\u0485\u0005T\u0000\u0000\u0485\u048f"+
		"\u0001\u0000\u0000\u0000\u0486\u0488\u0003\u00ccf\u0000\u0487\u0489\u0005"+
		"T\u0000\u0000\u0488\u0487\u0001\u0000\u0000\u0000\u0488\u0489\u0001\u0000"+
		"\u0000\u0000\u0489\u048f\u0001\u0000\u0000\u0000\u048a\u048b\u0003\u009a"+
		"M\u0000\u048b\u048c\u0005]\u0000\u0000\u048c\u048d\u0003\u009eO\u0000"+
		"\u048d\u048f\u0001\u0000\u0000\u0000\u048e\u041d\u0001\u0000\u0000\u0000"+
		"\u048e\u041e\u0001\u0000\u0000\u0000\u048e\u0426\u0001\u0000\u0000\u0000"+
		"\u048e\u042d\u0001\u0000\u0000\u0000\u048e\u0433\u0001\u0000\u0000\u0000"+
		"\u048e\u0437\u0001\u0000\u0000\u0000\u048e\u043d\u0001\u0000\u0000\u0000"+
		"\u048e\u044e\u0001\u0000\u0000\u0000\u048e\u045b\u0001\u0000\u0000\u0000"+
		"\u048e\u0467\u0001\u0000\u0000\u0000\u048e\u046b\u0001\u0000\u0000\u0000"+
		"\u048e\u0470\u0001\u0000\u0000\u0000\u048e\u0474\u0001\u0000\u0000\u0000"+
		"\u048e\u0479\u0001\u0000\u0000\u0000\u048e\u047e\u0001\u0000\u0000\u0000"+
		"\u048e\u0482\u0001\u0000\u0000\u0000\u048e\u0483\u0001\u0000\u0000\u0000"+
		"\u048e\u0486\u0001\u0000\u0000\u0000\u048e\u048a\u0001\u0000\u0000\u0000"+
		"\u048f\u009f\u0001\u0000\u0000\u0000\u0490\u0491\u0005\u0007\u0000\u0000"+
		"\u0491\u0495\u0005N\u0000\u0000\u0492\u0494\u0003\f\u0006\u0000\u0493"+
		"\u0492\u0001\u0000\u0000\u0000\u0494\u0497\u0001\u0000\u0000\u0000\u0495"+
		"\u0493\u0001\u0000\u0000\u0000\u0495\u0496\u0001\u0000\u0000\u0000\u0496"+
		"\u0498\u0001\u0000\u0000\u0000\u0497\u0495\u0001\u0000\u0000\u0000\u0498"+
		"\u0499\u0003\u00a2Q\u0000\u0499\u049a\u0003\u009aM\u0000\u049a\u049b\u0005"+
		"O\u0000\u0000\u049b\u049c\u0003\u0094J\u0000\u049c\u00a1\u0001\u0000\u0000"+
		"\u0000\u049d\u04a2\u0003^/\u0000\u049e\u049f\u0005k\u0000\u0000\u049f"+
		"\u04a1\u0003^/\u0000\u04a0\u049e\u0001\u0000\u0000\u0000\u04a1\u04a4\u0001"+
		"\u0000\u0000\u0000\u04a2\u04a0\u0001\u0000\u0000\u0000\u04a2\u04a3\u0001"+
		"\u0000\u0000\u0000\u04a3\u00a3\u0001\u0000\u0000\u0000\u04a4\u04a2\u0001"+
		"\u0000\u0000\u0000\u04a5\u04a6\u0005\u0013\u0000\u0000\u04a6\u04a7\u0003"+
		"\u0094J\u0000\u04a7\u00a5\u0001\u0000\u0000\u0000\u04a8\u04a9\u0005N\u0000"+
		"\u0000\u04a9\u04ab\u0003\u00a8T\u0000\u04aa\u04ac\u0005T\u0000\u0000\u04ab"+
		"\u04aa\u0001\u0000\u0000\u0000\u04ab\u04ac\u0001\u0000\u0000\u0000\u04ac"+
		"\u04ad\u0001\u0000\u0000\u0000\u04ad\u04ae\u0005O\u0000\u0000\u04ae\u00a7"+
		"\u0001\u0000\u0000\u0000\u04af\u04b4\u0003\u00aaU\u0000\u04b0\u04b1\u0005"+
		"T\u0000\u0000\u04b1\u04b3\u0003\u00aaU\u0000\u04b2\u04b0\u0001\u0000\u0000"+
		"\u0000\u04b3\u04b6\u0001\u0000\u0000\u0000\u04b4\u04b2\u0001\u0000\u0000"+
		"\u0000\u04b4\u04b5\u0001\u0000\u0000\u0000\u04b5\u00a9\u0001\u0000\u0000"+
		"\u0000\u04b6\u04b4\u0001\u0000\u0000\u0000\u04b7\u04b9\u0003\f\u0006\u0000"+
		"\u04b8\u04b7\u0001\u0000\u0000\u0000\u04b9\u04bc\u0001\u0000\u0000\u0000"+
		"\u04ba\u04b8\u0001\u0000\u0000\u0000\u04ba\u04bb\u0001\u0000\u0000\u0000"+
		"\u04bb\u04c2\u0001\u0000\u0000\u0000\u04bc\u04ba\u0001\u0000\u0000\u0000"+
		"\u04bd\u04be\u0003J%\u0000\u04be\u04bf\u0003D\"\u0000\u04bf\u04c3\u0001"+
		"\u0000\u0000\u0000\u04c0\u04c1\u0005=\u0000\u0000\u04c1\u04c3\u0003\u009a"+
		"M\u0000\u04c2\u04bd\u0001\u0000\u0000\u0000\u04c2\u04c0\u0001\u0000\u0000"+
		"\u0000\u04c3\u04c4\u0001\u0000\u0000\u0000\u04c4\u04c5\u0005W\u0000\u0000"+
		"\u04c5\u04c6\u0003\u00c0`\u0000\u04c6\u04c9\u0001\u0000\u0000\u0000\u04c7"+
		"\u04c9\u0003\u009aM\u0000\u04c8\u04ba\u0001\u0000\u0000\u0000\u04c8\u04c7"+
		"\u0001\u0000\u0000\u0000\u04c9\u00ab\u0001\u0000\u0000\u0000\u04ca\u04cc"+
		"\u0003\u00aeW\u0000\u04cb\u04ca\u0001\u0000\u0000\u0000\u04cc\u04cd\u0001"+
		"\u0000\u0000\u0000\u04cd\u04cb\u0001\u0000\u0000\u0000\u04cd\u04ce\u0001"+
		"\u0000\u0000\u0000\u04ce\u04d0\u0001\u0000\u0000\u0000\u04cf\u04d1\u0003"+
		"\u0096K\u0000\u04d0\u04cf\u0001\u0000\u0000\u0000\u04d1\u04d2\u0001\u0000"+
		"\u0000\u0000\u04d2\u04d0\u0001\u0000\u0000\u0000\u04d2\u04d3\u0001\u0000"+
		"\u0000\u0000\u04d3\u00ad\u0001\u0000\u0000\u0000\u04d4\u04d5\u0005\u0006"+
		"\u0000\u0000\u04d5\u04d6\u0003\u00c0`\u0000\u04d6\u04d7\u0005]\u0000\u0000"+
		"\u04d7\u04db\u0001\u0000\u0000\u0000\u04d8\u04d9\u0005\f\u0000\u0000\u04d9"+
		"\u04db\u0005]\u0000\u0000\u04da\u04d4\u0001\u0000\u0000\u0000\u04da\u04d8"+
		"\u0001\u0000\u0000\u0000\u04db\u00af\u0001\u0000\u0000\u0000\u04dc\u04e9"+
		"\u0003\u00b8\\\u0000\u04dd\u04df\u0003\u00b2Y\u0000\u04de\u04dd\u0001"+
		"\u0000\u0000\u0000\u04de\u04df\u0001\u0000\u0000\u0000\u04df\u04e0\u0001"+
		"\u0000\u0000\u0000\u04e0\u04e2\u0005T\u0000\u0000\u04e1\u04e3\u0003\u00b4"+
		"Z\u0000\u04e2\u04e1\u0001\u0000\u0000\u0000\u04e2\u04e3\u0001\u0000\u0000"+
		"\u0000\u04e3\u04e4\u0001\u0000\u0000\u0000\u04e4\u04e6\u0005T\u0000\u0000"+
		"\u04e5\u04e7\u0003\u00b6[\u0000\u04e6\u04e5\u0001\u0000\u0000\u0000\u04e6"+
		"\u04e7\u0001\u0000\u0000\u0000\u04e7\u04e9\u0001\u0000\u0000\u0000\u04e8"+
		"\u04dc\u0001\u0000\u0000\u0000\u04e8\u04de\u0001\u0000\u0000\u0000\u04e9"+
		"\u00b1\u0001\u0000\u0000\u0000\u04ea\u04ed\u0003\u0098L\u0000\u04eb\u04ed"+
		"\u0003\u00bc^\u0000\u04ec\u04ea\u0001\u0000\u0000\u0000\u04ec\u04eb\u0001"+
		"\u0000\u0000\u0000\u04ed\u00b3\u0001\u0000\u0000\u0000\u04ee\u04ef\u0003"+
		"\u00c0`\u0000\u04ef\u00b5\u0001\u0000\u0000\u0000\u04f0\u04f1\u0003\u00bc"+
		"^\u0000\u04f1\u00b7\u0001\u0000\u0000\u0000\u04f2\u04f4\u0003\f\u0006"+
		"\u0000\u04f3\u04f2\u0001\u0000\u0000\u0000\u04f4\u04f7\u0001\u0000\u0000"+
		"\u0000\u04f5\u04f3\u0001\u0000\u0000\u0000\u04f5\u04f6\u0001\u0000\u0000"+
		"\u0000\u04f6\u04fa\u0001\u0000\u0000\u0000\u04f7\u04f5\u0001\u0000\u0000"+
		"\u0000\u04f8\u04fb\u0003\u00eau\u0000\u04f9\u04fb\u0005=\u0000\u0000\u04fa"+
		"\u04f8\u0001\u0000\u0000\u0000\u04fa\u04f9\u0001\u0000\u0000\u0000\u04fb"+
		"\u04fc\u0001\u0000\u0000\u0000\u04fc\u04fd\u0003D\"\u0000\u04fd\u04fe"+
		"\u0005]\u0000\u0000\u04fe\u04ff\u0003\u00c0`\u0000\u04ff\u00b9\u0001\u0000"+
		"\u0000\u0000\u0500\u0501\u0005N\u0000\u0000\u0501\u0502\u0003\u00c0`\u0000"+
		"\u0502\u0503\u0005O\u0000\u0000\u0503\u00bb\u0001\u0000\u0000\u0000\u0504"+
		"\u0509\u0003\u00c0`\u0000\u0505\u0506\u0005U\u0000\u0000\u0506\u0508\u0003"+
		"\u00c0`\u0000\u0507\u0505\u0001\u0000\u0000\u0000\u0508\u050b\u0001\u0000"+
		"\u0000\u0000\u0509\u0507\u0001\u0000\u0000\u0000\u0509\u050a\u0001\u0000"+
		"\u0000\u0000\u050a\u00bd\u0001\u0000\u0000\u0000\u050b\u0509\u0001\u0000"+
		"\u0000\u0000\u050c\u050d\u0003\u009aM\u0000\u050d\u050f\u0005N\u0000\u0000"+
		"\u050e\u0510\u0003\u00bc^\u0000\u050f\u050e\u0001\u0000\u0000\u0000\u050f"+
		"\u0510\u0001\u0000\u0000\u0000\u0510\u0511\u0001\u0000\u0000\u0000\u0511"+
		"\u0512\u0005O\u0000\u0000\u0512\u0520\u0001\u0000\u0000\u0000\u0513\u0514"+
		"\u0005+\u0000\u0000\u0514\u0516\u0005N\u0000\u0000\u0515\u0517\u0003\u00bc"+
		"^\u0000\u0516\u0515\u0001\u0000\u0000\u0000\u0516\u0517\u0001\u0000\u0000"+
		"\u0000\u0517\u0518\u0001\u0000\u0000\u0000\u0518\u0520\u0005O\u0000\u0000"+
		"\u0519\u051a\u0005(\u0000\u0000\u051a\u051c\u0005N\u0000\u0000\u051b\u051d"+
		"\u0003\u00bc^\u0000\u051c\u051b\u0001\u0000\u0000\u0000\u051c\u051d\u0001"+
		"\u0000\u0000\u0000\u051d\u051e\u0001\u0000\u0000\u0000\u051e\u0520\u0005"+
		"O\u0000\u0000\u051f\u050c\u0001\u0000\u0000\u0000\u051f\u0513\u0001\u0000"+
		"\u0000\u0000\u051f\u0519\u0001\u0000\u0000\u0000\u0520\u00bf\u0001\u0000"+
		"\u0000\u0000\u0521\u0522\u0006`\uffff\uffff\u0000\u0522\u0554\u0003\u00ca"+
		"e\u0000\u0523\u0554\u0003\u00be_\u0000\u0524\u0526\u0005\u001f\u0000\u0000"+
		"\u0525\u0527\u0003\u00e6s\u0000\u0526\u0525\u0001\u0000\u0000\u0000\u0526"+
		"\u0527\u0001\u0000\u0000\u0000\u0527\u0528\u0001\u0000\u0000\u0000\u0528"+
		"\u0554\u0003\u00d6k\u0000\u0529\u052d\u0005N\u0000\u0000\u052a\u052c\u0003"+
		"h4\u0000\u052b\u052a\u0001\u0000\u0000\u0000\u052c\u052f\u0001\u0000\u0000"+
		"\u0000\u052d\u052b\u0001\u0000\u0000\u0000\u052d\u052e\u0001\u0000\u0000"+
		"\u0000\u052e\u0530\u0001\u0000\u0000\u0000\u052f\u052d\u0001\u0000\u0000"+
		"\u0000\u0530\u0535\u0003\u00eau\u0000\u0531\u0532\u0005j\u0000\u0000\u0532"+
		"\u0534\u0003\u00eau\u0000\u0533\u0531\u0001\u0000\u0000\u0000\u0534\u0537"+
		"\u0001\u0000\u0000\u0000\u0535\u0533\u0001\u0000\u0000\u0000\u0535\u0536"+
		"\u0001\u0000\u0000\u0000\u0536\u0538\u0001\u0000\u0000\u0000\u0537\u0535"+
		"\u0001\u0000\u0000\u0000\u0538\u0539\u0005O\u0000\u0000\u0539\u053a\u0003"+
		"\u00c0`\u0017\u053a\u0554\u0001\u0000\u0000\u0000\u053b\u053c\u0007\u0005"+
		"\u0000\u0000\u053c\u0554\u0003\u00c0`\u0015\u053d\u053e\u0007\u0006\u0000"+
		"\u0000\u053e\u0554\u0003\u00c0`\u0014\u053f\u0540\u0007\u0007\u0000\u0000"+
		"\u0540\u0554\u0003\u00c0`\u0013\u0541\u0554\u0003\u00c4b\u0000\u0542\u0554"+
		"\u0003\u00ccf\u0000\u0543\u0544\u0003\u00eau\u0000\u0544\u054a\u0005z"+
		"\u0000\u0000\u0545\u0547\u0003\u00eew\u0000\u0546\u0545\u0001\u0000\u0000"+
		"\u0000\u0546\u0547\u0001\u0000\u0000\u0000\u0547\u0548\u0001\u0000\u0000"+
		"\u0000\u0548\u054b\u0003\u009aM\u0000\u0549\u054b\u0005\u001f\u0000\u0000"+
		"\u054a\u0546\u0001\u0000\u0000\u0000\u054a\u0549\u0001\u0000\u0000\u0000"+
		"\u054b\u0554\u0001\u0000\u0000\u0000\u054c\u054d\u0003\u00d4j\u0000\u054d"+
		"\u054f\u0005z\u0000\u0000\u054e\u0550\u0003\u00eew\u0000\u054f\u054e\u0001"+
		"\u0000\u0000\u0000\u054f\u0550\u0001\u0000\u0000\u0000\u0550\u0551\u0001"+
		"\u0000\u0000\u0000\u0551\u0552\u0005\u001f\u0000\u0000\u0552\u0554\u0001"+
		"\u0000\u0000\u0000\u0553\u0521\u0001\u0000\u0000\u0000\u0553\u0523\u0001"+
		"\u0000\u0000\u0000\u0553\u0524\u0001\u0000\u0000\u0000\u0553\u0529\u0001"+
		"\u0000\u0000\u0000\u0553\u053b\u0001\u0000\u0000\u0000\u0553\u053d\u0001"+
		"\u0000\u0000\u0000\u0553\u053f\u0001\u0000\u0000\u0000\u0553\u0541\u0001"+
		"\u0000\u0000\u0000\u0553\u0542\u0001\u0000\u0000\u0000\u0553\u0543\u0001"+
		"\u0000\u0000\u0000\u0553\u054c\u0001\u0000\u0000\u0000\u0554\u05a8\u0001"+
		"\u0000\u0000\u0000\u0555\u0556\n\u0012\u0000\u0000\u0556\u0557\u0007\b"+
		"\u0000\u0000\u0557\u05a7\u0003\u00c0`\u0013\u0558\u0559\n\u0011\u0000"+
		"\u0000\u0559\u055a\u0007\u0006\u0000\u0000\u055a\u05a7\u0003\u00c0`\u0012"+
		"\u055b\u0563\n\u0010\u0000\u0000\u055c\u055d\u0005Y\u0000\u0000\u055d"+
		"\u0564\u0005Y\u0000\u0000\u055e\u055f\u0005X\u0000\u0000\u055f\u0560\u0005"+
		"X\u0000\u0000\u0560\u0564\u0005X\u0000\u0000\u0561\u0562\u0005X\u0000"+
		"\u0000\u0562\u0564\u0005X\u0000\u0000\u0563\u055c\u0001\u0000\u0000\u0000"+
		"\u0563\u055e\u0001\u0000\u0000\u0000\u0563\u0561\u0001\u0000\u0000\u0000"+
		"\u0564\u0565\u0001\u0000\u0000\u0000\u0565\u05a7\u0003\u00c0`\u0011\u0566"+
		"\u0567\n\u000f\u0000\u0000\u0567\u0568\u0007\t\u0000\u0000\u0568\u05a7"+
		"\u0003\u00c0`\u0010\u0569\u056a\n\r\u0000\u0000\u056a\u056b\u0007\n\u0000"+
		"\u0000\u056b\u05a7\u0003\u00c0`\u000e\u056c\u056d\n\f\u0000\u0000\u056d"+
		"\u056e\u0005j\u0000\u0000\u056e\u05a7\u0003\u00c0`\r\u056f\u0570\n\u000b"+
		"\u0000\u0000\u0570\u0571\u0005l\u0000\u0000\u0571\u05a7\u0003\u00c0`\f"+
		"\u0572\u0573\n\n\u0000\u0000\u0573\u0574\u0005k\u0000\u0000\u0574\u05a7"+
		"\u0003\u00c0`\u000b\u0575\u0576\n\t\u0000\u0000\u0576\u0577\u0005b\u0000"+
		"\u0000\u0577\u05a7\u0003\u00c0`\n\u0578\u0579\n\b\u0000\u0000\u0579\u057a"+
		"\u0005c\u0000\u0000\u057a\u05a7\u0003\u00c0`\t\u057b\u057c\n\u0007\u0000"+
		"\u0000\u057c\u057d\u0005\\\u0000\u0000\u057d\u057e\u0003\u00c0`\u0000"+
		"\u057e\u057f\u0005]\u0000\u0000\u057f\u0580\u0003\u00c0`\u0007\u0580\u05a7"+
		"\u0001\u0000\u0000\u0000\u0581\u0582\n\u0006\u0000\u0000\u0582\u0583\u0007"+
		"\u000b\u0000\u0000\u0583\u05a7\u0003\u00c0`\u0006\u0584\u0585\n\u001b"+
		"\u0000\u0000\u0585\u0591\u0005V\u0000\u0000\u0586\u0592\u0003\u009aM\u0000"+
		"\u0587\u0592\u0003\u00be_\u0000\u0588\u0592\u0005+\u0000\u0000\u0589\u058b"+
		"\u0005\u001f\u0000\u0000\u058a\u058c\u0003\u00e6s\u0000\u058b\u058a\u0001"+
		"\u0000\u0000\u0000\u058b\u058c\u0001\u0000\u0000\u0000\u058c\u058d\u0001"+
		"\u0000\u0000\u0000\u058d\u0592\u0003\u00dam\u0000\u058e\u058f\u0005(\u0000"+
		"\u0000\u058f\u0592\u0003\u00f0x\u0000\u0590\u0592\u0003\u00e0p\u0000\u0591"+
		"\u0586\u0001\u0000\u0000\u0000\u0591\u0587\u0001\u0000\u0000\u0000\u0591"+
		"\u0588\u0001\u0000\u0000\u0000\u0591\u0589\u0001\u0000\u0000\u0000\u0591"+
		"\u058e\u0001\u0000\u0000\u0000\u0591\u0590\u0001\u0000\u0000\u0000\u0592"+
		"\u05a7\u0001\u0000\u0000\u0000\u0593\u0594\n\u001a\u0000\u0000\u0594\u0595"+
		"\u0005R\u0000\u0000\u0595\u0596\u0003\u00c0`\u0000\u0596\u0597\u0005S"+
		"\u0000\u0000\u0597\u05a7\u0001\u0000\u0000\u0000\u0598\u0599\n\u0016\u0000"+
		"\u0000\u0599\u05a7\u0007\u0005\u0000\u0000\u059a\u059b\n\u000e\u0000\u0000"+
		"\u059b\u059e\u0005\u001a\u0000\u0000\u059c\u059f\u0003\u00eau\u0000\u059d"+
		"\u059f\u0003\u00c2a\u0000\u059e\u059c\u0001\u0000\u0000\u0000\u059e\u059d"+
		"\u0001\u0000\u0000\u0000\u059f\u05a7\u0001\u0000\u0000\u0000\u05a0\u05a1"+
		"\n\u0003\u0000\u0000\u05a1\u05a3\u0005z\u0000\u0000\u05a2\u05a4\u0003"+
		"\u00eew\u0000\u05a3\u05a2\u0001\u0000\u0000\u0000\u05a3\u05a4\u0001\u0000"+
		"\u0000\u0000\u05a4\u05a5\u0001\u0000\u0000\u0000\u05a5\u05a7\u0003\u009a"+
		"M\u0000\u05a6\u0555\u0001\u0000\u0000\u0000\u05a6\u0558\u0001\u0000\u0000"+
		"\u0000\u05a6\u055b\u0001\u0000\u0000\u0000\u05a6\u0566\u0001\u0000\u0000"+
		"\u0000\u05a6\u0569\u0001\u0000\u0000\u0000\u05a6\u056c\u0001\u0000\u0000"+
		"\u0000\u05a6\u056f\u0001\u0000\u0000\u0000\u05a6\u0572\u0001\u0000\u0000"+
		"\u0000\u05a6\u0575\u0001\u0000\u0000\u0000\u05a6\u0578\u0001\u0000\u0000"+
		"\u0000\u05a6\u057b\u0001\u0000\u0000\u0000\u05a6\u0581\u0001\u0000\u0000"+
		"\u0000\u05a6\u0584\u0001\u0000\u0000\u0000\u05a6\u0593\u0001\u0000\u0000"+
		"\u0000\u05a6\u0598\u0001\u0000\u0000\u0000\u05a6\u059a\u0001\u0000\u0000"+
		"\u0000\u05a6\u05a0\u0001\u0000\u0000\u0000\u05a7\u05aa\u0001\u0000\u0000"+
		"\u0000\u05a8\u05a6\u0001\u0000\u0000\u0000\u05a8\u05a9\u0001\u0000\u0000"+
		"\u0000\u05a9\u00c1\u0001\u0000\u0000\u0000\u05aa\u05a8\u0001\u0000\u0000"+
		"\u0000\u05ab\u05ad\u0003\f\u0006\u0000\u05ac\u05ab\u0001\u0000\u0000\u0000"+
		"\u05ad\u05b0\u0001\u0000\u0000\u0000\u05ae\u05ac\u0001\u0000\u0000\u0000"+
		"\u05ae\u05af\u0001\u0000\u0000\u0000\u05af\u05b1\u0001\u0000\u0000\u0000"+
		"\u05b0\u05ae\u0001\u0000\u0000\u0000\u05b1\u05b5\u0003\u00eau\u0000\u05b2"+
		"\u05b4\u0003h4\u0000\u05b3\u05b2\u0001\u0000\u0000\u0000\u05b4\u05b7\u0001"+
		"\u0000\u0000\u0000\u05b5\u05b3\u0001\u0000\u0000\u0000\u05b5\u05b6\u0001"+
		"\u0000\u0000\u0000\u05b6\u05b8\u0001\u0000\u0000\u0000\u05b7\u05b5\u0001"+
		"\u0000\u0000\u0000\u05b8\u05b9\u0003\u009aM\u0000\u05b9\u00c3\u0001\u0000"+
		"\u0000\u0000\u05ba\u05bb\u0003\u00c6c\u0000\u05bb\u05bc\u0005y\u0000\u0000"+
		"\u05bc\u05bd\u0003\u00c8d\u0000\u05bd\u00c5\u0001\u0000\u0000\u0000\u05be"+
		"\u05d5\u0003\u009aM\u0000\u05bf\u05c1\u0005N\u0000\u0000\u05c0\u05c2\u0003"+
		"T*\u0000\u05c1\u05c0\u0001\u0000\u0000\u0000\u05c1\u05c2\u0001\u0000\u0000"+
		"\u0000\u05c2\u05c3\u0001\u0000\u0000\u0000\u05c3\u05d5\u0005O\u0000\u0000"+
		"\u05c4\u05c5\u0005N\u0000\u0000\u05c5\u05ca\u0003\u009aM\u0000\u05c6\u05c7"+
		"\u0005U\u0000\u0000\u05c7\u05c9\u0003\u009aM\u0000\u05c8\u05c6\u0001\u0000"+
		"\u0000\u0000\u05c9\u05cc\u0001\u0000\u0000\u0000\u05ca\u05c8\u0001\u0000"+
		"\u0000\u0000\u05ca\u05cb\u0001\u0000\u0000\u0000\u05cb\u05cd\u0001\u0000"+
		"\u0000\u0000\u05cc\u05ca\u0001\u0000\u0000\u0000\u05cd\u05ce\u0005O\u0000"+
		"\u0000\u05ce\u05d5\u0001\u0000\u0000\u0000\u05cf\u05d1\u0005N\u0000\u0000"+
		"\u05d0\u05d2\u0003Z-\u0000\u05d1\u05d0\u0001\u0000\u0000\u0000\u05d1\u05d2"+
		"\u0001\u0000\u0000\u0000\u05d2\u05d3\u0001\u0000\u0000\u0000\u05d3\u05d5"+
		"\u0005O\u0000\u0000\u05d4\u05be\u0001\u0000\u0000\u0000\u05d4\u05bf\u0001"+
		"\u0000\u0000\u0000\u05d4\u05c4\u0001\u0000\u0000\u0000\u05d4\u05cf\u0001"+
		"\u0000\u0000\u0000\u05d5\u00c7\u0001\u0000\u0000\u0000\u05d6\u05d9\u0003"+
		"\u00c0`\u0000\u05d7\u05d9\u0003\u0094J\u0000\u05d8\u05d6\u0001\u0000\u0000"+
		"\u0000\u05d8\u05d7\u0001\u0000\u0000\u0000\u05d9\u00c9\u0001\u0000\u0000"+
		"\u0000\u05da\u05db\u0005N\u0000\u0000\u05db\u05dc\u0003\u00c0`\u0000\u05dc"+
		"\u05dd\u0005O\u0000\u0000\u05dd\u05ed\u0001\u0000\u0000\u0000\u05de\u05ed"+
		"\u0005+\u0000\u0000\u05df\u05ed\u0005(\u0000\u0000\u05e0\u05ed\u0003`"+
		"0\u0000\u05e1\u05ed\u0003\u009aM\u0000\u05e2\u05e3\u0003,\u0016\u0000"+
		"\u05e3\u05e4\u0005V\u0000\u0000\u05e4\u05e5\u0005\t\u0000\u0000\u05e5"+
		"\u05ed\u0001\u0000\u0000\u0000\u05e6\u05ea\u0003\u00e6s\u0000\u05e7\u05eb"+
		"\u0003\u00f2y\u0000\u05e8\u05e9\u0005+\u0000\u0000\u05e9\u05eb\u0003\u00f4"+
		"z\u0000\u05ea\u05e7\u0001\u0000\u0000\u0000\u05ea\u05e8\u0001\u0000\u0000"+
		"\u0000\u05eb\u05ed\u0001\u0000\u0000\u0000\u05ec\u05da\u0001\u0000\u0000"+
		"\u0000\u05ec\u05de\u0001\u0000\u0000\u0000\u05ec\u05df\u0001\u0000\u0000"+
		"\u0000\u05ec\u05e0\u0001\u0000\u0000\u0000\u05ec\u05e1\u0001\u0000\u0000"+
		"\u0000\u05ec\u05e2\u0001\u0000\u0000\u0000\u05ec\u05e6\u0001\u0000\u0000"+
		"\u0000\u05ed\u00cb\u0001\u0000\u0000\u0000\u05ee\u05ef\u0005)\u0000\u0000"+
		"\u05ef\u05f0\u0003\u00ba]\u0000\u05f0\u05f4\u0005P\u0000\u0000\u05f1\u05f3"+
		"\u0003\u00ceg\u0000\u05f2\u05f1\u0001\u0000\u0000\u0000\u05f3\u05f6\u0001"+
		"\u0000\u0000\u0000\u05f4\u05f2\u0001\u0000\u0000\u0000\u05f4\u05f5\u0001"+
		"\u0000\u0000\u0000\u05f5\u05f7\u0001\u0000\u0000\u0000\u05f6\u05f4\u0001"+
		"\u0000\u0000\u0000\u05f7\u05f8\u0005Q\u0000\u0000\u05f8\u00cd\u0001\u0000"+
		"\u0000\u0000\u05f9\u05fd\u0005\u0006\u0000\u0000\u05fa\u05fe\u0003\u00bc"+
		"^\u0000\u05fb\u05fe\u0005M\u0000\u0000\u05fc\u05fe\u0003\u00d0h\u0000"+
		"\u05fd\u05fa\u0001\u0000\u0000\u0000\u05fd\u05fb\u0001\u0000\u0000\u0000"+
		"\u05fd\u05fc\u0001\u0000\u0000\u0000\u05fe\u05ff\u0001\u0000\u0000\u0000"+
		"\u05ff\u0600\u0007\f\u0000\u0000\u0600\u0605\u0003\u00d2i\u0000\u0601"+
		"\u0602\u0005\f\u0000\u0000\u0602\u0603\u0007\f\u0000\u0000\u0603\u0605"+
		"\u0003\u00d2i\u0000\u0604\u05f9\u0001\u0000\u0000\u0000\u0604\u0601\u0001"+
		"\u0000\u0000\u0000\u0605\u00cf\u0001\u0000\u0000\u0000\u0606\u0607\u0006"+
		"h\uffff\uffff\u0000\u0607\u0608\u0005N\u0000\u0000\u0608\u0609\u0003\u00d0"+
		"h\u0000\u0609\u060a\u0005O\u0000\u0000\u060a\u0621\u0001\u0000\u0000\u0000"+
		"\u060b\u060d\u0003\f\u0006\u0000\u060c\u060b\u0001\u0000\u0000\u0000\u060d"+
		"\u0610\u0001\u0000\u0000\u0000\u060e\u060c\u0001\u0000\u0000\u0000\u060e"+
		"\u060f\u0001\u0000\u0000\u0000\u060f\u0611\u0001\u0000\u0000\u0000\u0610"+
		"\u060e\u0001\u0000\u0000\u0000\u0611\u0615\u0003\u00eau\u0000\u0612\u0614"+
		"\u0003h4\u0000\u0613\u0612\u0001\u0000\u0000\u0000\u0614\u0617\u0001\u0000"+
		"\u0000\u0000\u0615\u0613\u0001\u0000\u0000\u0000\u0615\u0616\u0001\u0000"+
		"\u0000\u0000\u0616\u0618\u0001\u0000\u0000\u0000\u0617\u0615\u0001\u0000"+
		"\u0000\u0000\u0618\u061d\u0003\u009aM\u0000\u0619\u061a\u0005b\u0000\u0000"+
		"\u061a\u061c\u0003\u00c0`\u0000\u061b\u0619\u0001\u0000\u0000\u0000\u061c"+
		"\u061f\u0001\u0000\u0000\u0000\u061d\u061b\u0001\u0000\u0000\u0000\u061d"+
		"\u061e\u0001\u0000\u0000\u0000\u061e\u0621\u0001\u0000\u0000\u0000\u061f"+
		"\u061d\u0001\u0000\u0000\u0000\u0620\u0606\u0001\u0000\u0000\u0000\u0620"+
		"\u060e\u0001\u0000\u0000\u0000\u0621\u0627\u0001\u0000\u0000\u0000\u0622"+
		"\u0623\n\u0001\u0000\u0000\u0623\u0624\u0005b\u0000\u0000\u0624\u0626"+
		"\u0003\u00c0`\u0000\u0625\u0622\u0001\u0000\u0000\u0000\u0626\u0629\u0001"+
		"\u0000\u0000\u0000\u0627\u0625\u0001\u0000\u0000\u0000\u0627\u0628\u0001"+
		"\u0000\u0000\u0000\u0628\u00d1\u0001\u0000\u0000\u0000\u0629\u0627\u0001"+
		"\u0000\u0000\u0000\u062a\u0632\u0003\u0094J\u0000\u062b\u062d\u0003\u0096"+
		"K\u0000\u062c\u062b\u0001\u0000\u0000\u0000\u062d\u0630\u0001\u0000\u0000"+
		"\u0000\u062e\u062c\u0001\u0000\u0000\u0000\u062e\u062f\u0001\u0000\u0000"+
		"\u0000\u062f\u0632\u0001\u0000\u0000\u0000\u0630\u062e\u0001\u0000\u0000"+
		"\u0000\u0631\u062a\u0001\u0000\u0000\u0000\u0631\u062e\u0001\u0000\u0000"+
		"\u0000\u0632\u00d3\u0001\u0000\u0000\u0000\u0633\u0634\u0003J%\u0000\u0634"+
		"\u0635\u0005V\u0000\u0000\u0635\u0637\u0001\u0000\u0000\u0000\u0636\u0633"+
		"\u0001\u0000\u0000\u0000\u0636\u0637\u0001\u0000\u0000\u0000\u0637\u063b"+
		"\u0001\u0000\u0000\u0000\u0638\u063a\u0003h4\u0000\u0639\u0638\u0001\u0000"+
		"\u0000\u0000\u063a\u063d\u0001\u0000\u0000\u0000\u063b\u0639\u0001\u0000"+
		"\u0000\u0000\u063b\u063c\u0001\u0000\u0000\u0000\u063c\u063e\u0001\u0000"+
		"\u0000\u0000\u063d\u063b\u0001\u0000\u0000\u0000\u063e\u0640\u0003\u009a"+
		"M\u0000\u063f\u0641\u0003\u00eew\u0000\u0640\u063f\u0001\u0000\u0000\u0000"+
		"\u0640\u0641\u0001\u0000\u0000\u0000\u0641\u00d5\u0001\u0000\u0000\u0000"+
		"\u0642\u0645\u0003\u00d8l\u0000\u0643\u0646\u0003\u00dcn\u0000\u0644\u0646"+
		"\u0003\u00deo\u0000\u0645\u0643\u0001\u0000\u0000\u0000\u0645\u0644\u0001"+
		"\u0000\u0000\u0000\u0646\u00d7\u0001\u0000\u0000\u0000\u0647\u0649\u0003"+
		"\u009aM\u0000\u0648\u064a\u0003\u00e2q\u0000\u0649\u0648\u0001\u0000\u0000"+
		"\u0000\u0649\u064a\u0001\u0000\u0000\u0000\u064a\u0652\u0001\u0000\u0000"+
		"\u0000\u064b\u064c\u0005V\u0000\u0000\u064c\u064e\u0003\u009aM\u0000\u064d"+
		"\u064f\u0003\u00e2q\u0000\u064e\u064d\u0001\u0000\u0000\u0000\u064e\u064f"+
		"\u0001\u0000\u0000\u0000\u064f\u0651\u0001\u0000\u0000\u0000\u0650\u064b"+
		"\u0001\u0000\u0000\u0000\u0651\u0654\u0001\u0000\u0000\u0000\u0652\u0650"+
		"\u0001\u0000\u0000\u0000\u0652\u0653\u0001\u0000\u0000\u0000\u0653\u0657"+
		"\u0001\u0000\u0000\u0000\u0654\u0652\u0001\u0000\u0000\u0000\u0655\u0657"+
		"\u0003\u00ecv\u0000\u0656\u0647\u0001\u0000\u0000\u0000\u0656\u0655\u0001"+
		"\u0000\u0000\u0000\u0657\u00d9\u0001\u0000\u0000\u0000\u0658\u065a\u0003"+
		"\u009aM\u0000\u0659\u065b\u0003\u00e4r\u0000\u065a\u0659\u0001\u0000\u0000"+
		"\u0000\u065a\u065b\u0001\u0000\u0000\u0000\u065b\u065c\u0001\u0000\u0000"+
		"\u0000\u065c\u065d\u0003\u00deo\u0000\u065d\u00db\u0001\u0000\u0000\u0000"+
		"\u065e\u067a\u0005R\u0000\u0000\u065f\u0664\u0005S\u0000\u0000\u0660\u0661"+
		"\u0005R\u0000\u0000\u0661\u0663\u0005S\u0000\u0000\u0662\u0660\u0001\u0000"+
		"\u0000\u0000\u0663\u0666\u0001\u0000\u0000\u0000\u0664\u0662\u0001\u0000"+
		"\u0000\u0000\u0664\u0665\u0001\u0000\u0000\u0000\u0665\u0667\u0001\u0000"+
		"\u0000\u0000\u0666\u0664\u0001\u0000\u0000\u0000\u0667\u067b\u0003H$\u0000"+
		"\u0668\u0669\u0003\u00c0`\u0000\u0669\u0670\u0005S\u0000\u0000\u066a\u066b"+
		"\u0005R\u0000\u0000\u066b\u066c\u0003\u00c0`\u0000\u066c\u066d\u0005S"+
		"\u0000\u0000\u066d\u066f\u0001\u0000\u0000\u0000\u066e\u066a\u0001\u0000"+
		"\u0000\u0000\u066f\u0672\u0001\u0000\u0000\u0000\u0670\u066e\u0001\u0000"+
		"\u0000\u0000\u0670\u0671\u0001\u0000\u0000\u0000\u0671\u0677\u0001\u0000"+
		"\u0000\u0000\u0672\u0670\u0001\u0000\u0000\u0000\u0673\u0674\u0005R\u0000"+
		"\u0000\u0674\u0676\u0005S\u0000\u0000\u0675\u0673\u0001\u0000\u0000\u0000"+
		"\u0676\u0679\u0001\u0000\u0000\u0000\u0677\u0675\u0001\u0000\u0000\u0000"+
		"\u0677\u0678\u0001\u0000\u0000\u0000\u0678\u067b\u0001\u0000\u0000\u0000"+
		"\u0679\u0677\u0001\u0000\u0000\u0000\u067a\u065f\u0001\u0000\u0000\u0000"+
		"\u067a\u0668\u0001\u0000\u0000\u0000\u067b\u00dd\u0001\u0000\u0000\u0000"+
		"\u067c\u067e\u0003\u00f4z\u0000\u067d\u067f\u0003 \u0010\u0000\u067e\u067d"+
		"\u0001\u0000\u0000\u0000\u067e\u067f\u0001\u0000\u0000\u0000\u067f\u00df"+
		"\u0001\u0000\u0000\u0000\u0680\u0681\u0003\u00e6s\u0000\u0681\u0682\u0003"+
		"\u00f2y\u0000\u0682\u00e1\u0001\u0000\u0000\u0000\u0683\u0684\u0005Y\u0000"+
		"\u0000\u0684\u0687\u0005X\u0000\u0000\u0685\u0687\u0003\u00eew\u0000\u0686"+
		"\u0683\u0001\u0000\u0000\u0000\u0686\u0685\u0001\u0000\u0000\u0000\u0687"+
		"\u00e3\u0001\u0000\u0000\u0000\u0688\u0689\u0005Y\u0000\u0000\u0689\u068c"+
		"\u0005X\u0000\u0000\u068a\u068c\u0003\u00e6s\u0000\u068b\u0688\u0001\u0000"+
		"\u0000\u0000\u068b\u068a\u0001\u0000\u0000\u0000\u068c\u00e5\u0001\u0000"+
		"\u0000\u0000\u068d\u068e\u0005Y\u0000\u0000\u068e\u068f\u0003\u00e8t\u0000"+
		"\u068f\u0690\u0005X\u0000\u0000\u0690\u00e7\u0001\u0000\u0000\u0000\u0691"+
		"\u0696\u0003\u00eau\u0000\u0692\u0693\u0005U\u0000\u0000\u0693\u0695\u0003"+
		"\u00eau\u0000\u0694\u0692\u0001\u0000\u0000\u0000\u0695\u0698\u0001\u0000"+
		"\u0000\u0000\u0696\u0694\u0001\u0000\u0000\u0000\u0696\u0697\u0001\u0000"+
		"\u0000\u0000\u0697\u00e9\u0001\u0000\u0000\u0000\u0698\u0696\u0001\u0000"+
		"\u0000\u0000\u0699\u069b\u0003h4\u0000\u069a\u0699\u0001\u0000\u0000\u0000"+
		"\u069b\u069e\u0001\u0000\u0000\u0000\u069c\u069a\u0001\u0000\u0000\u0000"+
		"\u069c\u069d\u0001\u0000\u0000\u0000\u069d\u06a1\u0001\u0000\u0000\u0000"+
		"\u069e\u069c\u0001\u0000\u0000\u0000\u069f\u06a2\u0003J%\u0000\u06a0\u06a2"+
		"\u0003\u00ecv\u0000\u06a1\u069f\u0001\u0000\u0000\u0000\u06a1\u06a0\u0001"+
		"\u0000\u0000\u0000\u06a2\u06ad\u0001\u0000\u0000\u0000\u06a3\u06a5\u0003"+
		"h4\u0000\u06a4\u06a3\u0001\u0000\u0000\u0000\u06a5\u06a8\u0001\u0000\u0000"+
		"\u0000\u06a6\u06a4\u0001\u0000\u0000\u0000\u06a6\u06a7\u0001\u0000\u0000"+
		"\u0000\u06a7\u06a9\u0001\u0000\u0000\u0000\u06a8\u06a6\u0001\u0000\u0000"+
		"\u0000\u06a9\u06aa\u0005R\u0000\u0000\u06aa\u06ac\u0005S\u0000\u0000\u06ab"+
		"\u06a6\u0001\u0000\u0000\u0000\u06ac\u06af\u0001\u0000\u0000\u0000\u06ad"+
		"\u06ab\u0001\u0000\u0000\u0000\u06ad\u06ae\u0001\u0000\u0000\u0000\u06ae"+
		"\u00eb\u0001\u0000\u0000\u0000\u06af\u06ad\u0001\u0000\u0000\u0000\u06b0"+
		"\u06b1\u0007\r\u0000\u0000\u06b1\u00ed\u0001\u0000\u0000\u0000\u06b2\u06b3"+
		"\u0005Y\u0000\u0000\u06b3\u06b8\u0003L&\u0000\u06b4\u06b5\u0005U\u0000"+
		"\u0000\u06b5\u06b7\u0003L&\u0000\u06b6\u06b4\u0001\u0000\u0000\u0000\u06b7"+
		"\u06ba\u0001\u0000\u0000\u0000\u06b8\u06b6\u0001\u0000\u0000\u0000\u06b8"+
		"\u06b9\u0001\u0000\u0000\u0000\u06b9\u06bb\u0001\u0000\u0000\u0000\u06ba"+
		"\u06b8\u0001\u0000\u0000\u0000\u06bb\u06bc\u0005X\u0000\u0000\u06bc\u00ef"+
		"\u0001\u0000\u0000\u0000\u06bd\u06c7\u0003\u00f4z\u0000\u06be\u06c0\u0005"+
		"V\u0000\u0000\u06bf\u06c1\u0003\u00eew\u0000\u06c0\u06bf\u0001\u0000\u0000"+
		"\u0000\u06c0\u06c1\u0001\u0000\u0000\u0000\u06c1\u06c2\u0001\u0000\u0000"+
		"\u0000\u06c2\u06c4\u0003\u009aM\u0000\u06c3\u06c5\u0003\u00f4z\u0000\u06c4"+
		"\u06c3\u0001\u0000\u0000\u0000\u06c4\u06c5\u0001\u0000\u0000\u0000\u06c5"+
		"\u06c7\u0001\u0000\u0000\u0000\u06c6\u06bd\u0001\u0000\u0000\u0000\u06c6"+
		"\u06be\u0001\u0000\u0000\u0000\u06c7\u00f1\u0001\u0000\u0000\u0000\u06c8"+
		"\u06c9\u0005(\u0000\u0000\u06c9\u06ce\u0003\u00f0x\u0000\u06ca\u06cb\u0003"+
		"\u009aM\u0000\u06cb\u06cc\u0003\u00f4z\u0000\u06cc\u06ce\u0001\u0000\u0000"+
		"\u0000\u06cd\u06c8\u0001\u0000\u0000\u0000\u06cd\u06ca\u0001\u0000\u0000"+
		"\u0000\u06ce\u00f3\u0001\u0000\u0000\u0000\u06cf\u06d1\u0005N\u0000\u0000"+
		"\u06d0\u06d2\u0003\u00bc^\u0000\u06d1\u06d0\u0001\u0000\u0000\u0000\u06d1"+
		"\u06d2\u0001\u0000\u0000\u0000\u06d2\u06d3\u0001\u0000\u0000\u0000\u06d3"+
		"\u06d4\u0005O\u0000\u0000\u06d4\u00f5\u0001\u0000\u0000\u0000\u00de\u00f7"+
		"\u00fb\u00fd\u0102\u0104\u010a\u010f\u0118\u011d\u0124\u012c\u0133\u013f"+
		"\u0143\u0148\u014c\u0150\u0154\u015e\u0166\u016e\u0172\u0179\u0180\u0184"+
		"\u0187\u018a\u0193\u0199\u019e\u01a1\u01a7\u01ad\u01b1\u01b5\u01bd\u01c6"+
		"\u01cd\u01d3\u01d7\u01e1\u01e4\u01ed\u01f2\u01f8\u01fc\u01ff\u0205\u0210"+
		"\u0215\u021e\u0226\u0230\u0239\u023d\u0247\u024c\u0256\u025b\u0264\u026a"+
		"\u0271\u0276\u027e\u0282\u0284\u028a\u028f\u0293\u029a\u02a0\u02a2\u02a9"+
		"\u02ae\u02b3\u02b6\u02b8\u02c2\u02cc\u02d1\u02d4\u02d9\u02e2\u02e9\u02f4"+
		"\u02fa\u0305\u030f\u031a\u0323\u0328\u032b\u0332\u033c\u0344\u0347\u034a"+
		"\u0357\u035f\u0364\u036c\u0370\u0374\u0378\u037c\u037e\u0382\u0388\u0390"+
		"\u039a\u03a3\u03ad\u03b5\u03c3\u03ca\u03cf\u03d5\u03de\u03e8\u03f1\u03fb"+
		"\u0400\u040b\u0412\u0418\u041b\u0422\u042b\u0443\u0449\u0453\u0456\u0459"+
		"\u0461\u0465\u046d\u0476\u047b\u0488\u048e\u0495\u04a2\u04ab\u04b4\u04ba"+
		"\u04c2\u04c8\u04cd\u04d2\u04da\u04de\u04e2\u04e6\u04e8\u04ec\u04f5\u04fa"+
		"\u0509\u050f\u0516\u051c\u051f\u0526\u052d\u0535\u0546\u054a\u054f\u0553"+
		"\u0563\u058b\u0591\u059e\u05a3\u05a6\u05a8\u05ae\u05b5\u05c1\u05ca\u05d1"+
		"\u05d4\u05d8\u05ea\u05ec\u05f4\u05fd\u0604\u060e\u0615\u061d\u0620\u0627"+
		"\u062e\u0631\u0636\u063b\u0640\u0645\u0649\u064e\u0652\u0656\u065a\u0664"+
		"\u0670\u0677\u067a\u067e\u0686\u068b\u0696\u069c\u06a1\u06a6\u06ad\u06b8"+
		"\u06c0\u06c4\u06c6\u06cd\u06d1";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}