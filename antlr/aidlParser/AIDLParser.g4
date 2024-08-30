parser grammar AIDLParser;

options {
	tokenVocab = AIDLLexer;
}

compilationUnit: optional_package? imports? decls;

identifier: IDENTIFIER | CPP_HEADER | NDK_HEADER | RUST_TYPE;

optional_package: PACKAGE qualified_name ';';

imports: importI+;

importI: IMPORT qualified_name ';';

qualified_name: identifier ( '.' identifier)*;

decls: decl+;

decl: annotation_list unannotated_decl;

unannotated_decl:
	parcelable_decl
	| interface_decl
	| enum_decl
	| union_decl;

type_params: identifier ( ',' identifier)*;

optional_type_params: '<' type_params '>';

optional_unstructured_headers:
	((CPP_HEADER C_STR) | (NDK_HEADER C_STR) | (RUST_TYPE C_STR))*;

parcelable_decl:
	PARCELABLE qualified_name optional_type_params? (
		(optional_unstructured_headers ';')
		| ('{' parcelable_members '}')
	);

parcelable_members: ( variable_decl | constant_decl | decl)*;

variable_decl: type identifier ('=' const_expr)? ';';

interface_decl:
	ONEWAY? INTERFACE qualified_name (
		(';')
		| ('{' interface_members '}')
	);

interface_members: (method_decl | constant_decl | decl)*;

const_expr:
	TRUE_LITERAL
	| FALSE_LITERAL
	| CHARVALUE
	| INTVALUE
	| FLOATVALUE
	| HEXVALUE
	| C_STR
	| qualified_name
	| '{' constant_value_list? '}'
	| const_expr LOGICAL_OR const_expr
	| const_expr LOGICAL_AND const_expr
	| const_expr '|' const_expr
	| const_expr '^' const_expr
	| const_expr '&' const_expr
	| const_expr EQUALITY const_expr
	| const_expr NEQ const_expr
	| const_expr '<' const_expr
	| const_expr '>' const_expr
	| const_expr LEQ const_expr
	| const_expr GEQ const_expr
	| const_expr LSHIFT const_expr
	| const_expr RSHIFT const_expr
	| const_expr '+' const_expr
	| const_expr '-' const_expr
	| const_expr '*' const_expr
	| const_expr '/' const_expr
	| const_expr '%' const_expr
	| '+' const_expr
	| '-' const_expr
	| '!' const_expr
	| '~' const_expr
	| '(' const_expr ')';

constant_value_list: constant_value_non_empty_list ','?;

constant_value_non_empty_list: const_expr (',' const_expr)*;

constant_decl:
	annotation_list CONST type identifier '=' const_expr ';';

enumerator: identifier ('=' const_expr)?;

enumerators: enumerator (',' enumerator)*;

enum_decl_body: '{' enumerators ','? '}';

enum_decl: ENUM qualified_name enum_decl_body;

union_decl:
	UNION qualified_name optional_type_params? '{' parcelable_members '}';

method_decl:
	annotation_list ONEWAY? type identifier '(' arg_non_empty_list? ')' (
		'=' INTVALUE
	)? ';';

arg_non_empty_list: arg (',' arg)*;

arg: direction? type identifier;

non_array_type:
	annotation_list qualified_name (
		('<' type_args '>')
		| ('<' non_array_type '<' type_args RSHIFT)
		| ('<' type_args ',' non_array_type '<' type_args RSHIFT)
	)*;

type:
	non_array_type (
		(annotation_list '[' ']')
		| (annotation_list '[' const_expr ']')
	)*
	| VOID;

type_args: type ( ',' type)*;

annotation_list: annotation*;

parameter: identifier '=' const_expr;

parameter_non_empty_list: parameter (',' parameter)*;

annotation:
	ANNOTATION (
		('(' const_expr ')')
		| ('(' parameter_non_empty_list? ')')
	)?;

direction: IN | OUT | INOUT;