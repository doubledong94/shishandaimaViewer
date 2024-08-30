lexer grammar AIDLLexer;

// Keywords

ABSTRACT: 'abstract';
CONST: 'const';
ENUM: 'enum';
EXTENDS: 'extends';
IMPLEMENTS: 'implements';
IMPORT: 'import';
INTERFACE: 'interface';
PACKAGE: 'package';
PRIVATE: 'private';
PROTECTED: 'protected';
PUBLIC: 'public';
RETURN: 'return';
STATIC: 'static';
VOID: 'void';

// Module related keywords
PARCELABLE: 'parcelable';
IN: 'in';
OUT: 'out';
INOUT: 'inout';
ONEWAY: 'oneway';
CPP_HEADER: 'cpp_header';
NDK_HEADER: 'ndk_header';
RUST_TYPE: 'rust_type';
ANNOTATION: '@' IDENTIFIER;
UNION: 'union';

// Local Variable Type Inference
VAR: 'var'; // reserved type name

// Switch Expressions
YIELD: 'yield';

// Records
RECORD: 'record';

// Sealed Classes
SEALED: 'sealed';
PERMITS: 'permits';
NON_SEALED: 'non-sealed';

// Literals

INTVALUE: ('0' | [1-9] (Digits? | '_'+ Digits)) [lL]?;
HEXVALUE:
	'0' [xX] [0-9a-fA-F] ([0-9a-fA-F_]* [0-9a-fA-F])? [lL]?;
OCT_LITERAL: '0' '_'* [0-7] ([0-7_]* [0-7])? [lL]?;
BINARY_LITERAL: '0' [bB] [01] ([01_]* [01])? [lL]?;

FLOATVALUE: (Digits '.' Digits? | '.' Digits) ExponentPart? [fFdD]?
	| Digits (ExponentPart [fFdD]? | [fFdD]);

HEX_FLOAT_LITERAL:
	'0' [xX] (HexDigits '.'? | HexDigits? '.' HexDigits) [pP] [+-]? Digits [fFdD]?;

TRUE_LITERAL: 'true';
FALSE_LITERAL: 'false';

CHARVALUE: '\'' (~['\\\r\n] | EscapeSequence) '\'';

C_STR: '"' (~["\\\r\n] | EscapeSequence)* '"';

TEXT_BLOCK: '"""' [ \t]* [\r\n] (. | EscapeSequence)*? '"""';

NULL_LITERAL: 'null';

// Separators

LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';
SEMI: ';';
COMMA: ',';
DOT: '.';

// Operators

ASSIGN: '=';
GT: '>';
LT: '<';
BANG: '!';
TILDE: '~';
QUESTION: '?';
COLON: ':';
EQUALITY: '==';
LEQ: '<=';
GEQ: '>=';
NEQ: '!=';
LOGICAL_AND: '&&';
LOGICAL_OR: '||';
UNARY_PLUS: '++';
UNARY_MINUS: '--';
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
BITAND: '&';
BITOR: '|';
CARET: '^';
MOD: '%';

LSHIFT: '<<';
RSHIFT: '>>';

ADD_ASSIGN: '+=';
SUB_ASSIGN: '-=';
MUL_ASSIGN: '*=';
DIV_ASSIGN: '/=';
AND_ASSIGN: '&=';
OR_ASSIGN: '|=';
XOR_ASSIGN: '^=';
MOD_ASSIGN: '%=';
LSHIFT_ASSIGN: '<<=';
RSHIFT_ASSIGN: '>>=';
URSHIFT_ASSIGN: '>>>=';

// Java 8 tokens

ARROW: '->';
COLONCOLON: '::';

// Additional symbols not defined in the lexical specification

ELLIPSIS: '...';

// Whitespace and comments

WS:                 [ \t\r\n\u000C]+ -> channel(HIDDEN);
COMMENT:            '/*' .*? '*/'    -> channel(HIDDEN);
LINE_COMMENT:       '//' ~[\r\n]*    -> channel(HIDDEN);

// Identifiers

IDENTIFIER: [_a-zA-Z][_a-zA-Z0-9]*;

// Fragment rules

fragment ExponentPart: [eE] [+-]? Digits;

fragment EscapeSequence:
	'\\' [btnfr"'\\]
	| '\\' ([0-3]? [0-7])? [0-7]
	| '\\' 'u'+ HexDigit HexDigit HexDigit HexDigit;

fragment HexDigits: HexDigit ((HexDigit | '_')* HexDigit)?;

fragment HexDigit: [0-9a-fA-F];

fragment Digits: [0-9] ([0-9_]* [0-9])?;

fragment LetterOrDigit: Letter | [0-9];

fragment Letter:
	[a-zA-Z$_] // these are the "java letters" below 0x7F
	| ~[\u0000-\u007F\uD800-\uDBFF] // covers all characters above 0x7F which are not a surrogate
	| [\uD800-\uDBFF] [\uDC00-\uDFFF];
	// covers UTF-16 surrogate pairs encodings for U+10000 to U+10FFFF