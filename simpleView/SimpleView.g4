grammar SimpleView;

LABEL_DETAIL_LEVEL_SIMPLE:'"simple"';
LABEL_DETAIL_LEVEL_FULL:'"full"';

NODE_COLOR : 'nodeColor';
NODE_SCALE : 'nodeScale';
LABEL_COLOR : 'labelColor';
LABEL_SCALE : 'labelScale';
LABEL_DETAIL_LEVEL : 'labelDetailLevel';
POSITION_Z : 'positionZ';

BASIC_NODE_SIZE : 'basicNodeSize';
BASIC_LABEL_SIZE : 'basicLabelSize';
BASIC_POSITION_Z : 'basicPositionZ';

ANY:'Any';
FINAL:'Final';
CLASS:'Class';
FIELD_OF:'FieldOf';
INSTANCE_OF:'InstanceOf';
METHOD_OF:'MethodOf';
CREATOR : 'CreatorOf';
PARAMETER_OF:'ParameterOf';
RETURN_OF:'ReturnOf';
CALLED_PARAM_OF :'CalledParamOf';
CALLED_RETURN_OF : 'CalledReturnOf';
CALLED_METHOD_OF : 'CalledMethodOf';
METHOD_USED_BY :'methodUsedBy';
FIELD_USED_BY :'fieldUsedBy';
METHOD_USE :'methodUse';
READ : 'read';
WRITE : 'write';

IN_PACKAGE :'inPackage';
CLASS_OF: 'classOf';
SUPER : 'superOf';
SUB : 'subOf';

STYLE : 'Style';
DEFAULT_STYLE : 'DefaultStyle';
BASIC_STYLE : 'BasicStyle';
CLASS_SCOPE : 'ClassScope';
NODE : 'Node';
REFERENCE : 'Reference';
VOID_REF : 'VoidRef';
CONDITION : 'Condition';
ELSE : 'Else';
DATA_STEP : 'DataStep';
TIMING_STEP : 'TimingStep';
DATA_OVERRIDE: 'DataOverride';
TIMING_OVERRIDE: 'TimingOverride';
LV: 'LV';
FIELD: 'Field';
METHOD: 'Method';
CONSTRUCTOR: 'Constructor';
CALLED_METHOD: 'CalledMethod';
PARAMETER: 'Parameter';
CALLED_PARAMETER: 'CalledParameter';
RETURN: 'Return';
CALLED_RETURN: 'CalledReturn';
INDEX: 'Index';
ERROR: 'Error';
FIELD_CONNECTION: 'FieldConnection';
SEGMENT : 'Seg';
LINE : 'Line';
LINE_INSTANCE: 'LineInstance';
GRAPH : 'Graph';
GRAPH_INSTANCE : 'GraphInstance';
CODE_ORDER : 'CodeOrder';
NULL: 'NULL';

SHOW : 'show';

compilationUnit
    : (declaration ';')+ (showCommand ';')*
    ;

classScopeExp
    : classKey=STRING
    | classKeyList='[' STRING (',' STRING)* ']'
    | IN_PACKAGE '(' packageStr=STRING ')'
    | SUPER '(' classScopeExp ')'
    | SUB '(' classScopeExp ')'
    | classScopeExp union='|' classScopeExp
    | classScopeExp intersection='&' classScopeExp
    | classScopeExp difference='-' classScopeExp
    | '(' bracket=classScopeExp ')'
    | refOtherScope=IDENTIFIER
    | varClass='{' IDENTIFIER '}'
    ;

nodeExp
    : nodeKey=STRING '(' typeKey=STRING ')'
    | nodeKeyList='[' STRING '(' STRING ')' (',' STRING '(' STRING ')')* ']'
    | FIELD_OF '(' classScopeExp ')'
    | METHOD_OF '(' classScopeExp ')'
    | PARAMETER_OF '(' methodNode=nodeExp ')'
    | RETURN_OF '(' methodNode=nodeExp ')'
    | INSTANCE_OF '(' classScopeExp ',' classScopeExp ')'
    | CREATOR '(' classScopeExp ')'
    | SUPER '(' node=nodeExp ')'
    | SUB '(' node=nodeExp ')'
    // called method/parameter/return can only be the outermost layer
    | CALLED_METHOD_OF '(' methodNode=nodeExp ')'
    | CALLED_PARAM_OF '(' paramNode=nodeExp ')'
    | CALLED_RETURN_OF '(' returnNode=nodeExp ')'
    | METHOD_USED_BY '(' node=nodeExp ')'
    | FIELD_USED_BY '(' node=nodeExp ')'
    | METHOD_USE '(' node=nodeExp ')'
    | nodeExp intersection='&' nodeExp
    | nodeExp union='|' nodeExp
    | nodeExp difference='-' nodeExp
    // read and write key word can only be the outermost layer
    | READ '(' read=nodeExp ')'
    | WRITE '(' write=nodeExp ')'
    | ANY
    | FINAL
    | CLASS
    | REFERENCE
    | VOID_REF
    | CONDITION
    | ELSE
    | DATA_STEP
    | TIMING_STEP
    | DATA_OVERRIDE
    | TIMING_OVERRIDE
    | LV
    | FIELD
    | METHOD
    | CONSTRUCTOR
    | CALLED_METHOD
    | PARAMETER
    | CALLED_PARAMETER
    | RETURN
    | CALLED_RETURN
    | INDEX
    | ERROR
    | FIELD_CONNECTION
    | '(' bracket=nodeExp ')'
    | refOtherNode=IDENTIFIER
    | varNode='{' IDENTIFIER '}'
    ;

// line
paramList
    : '(' IDENTIFIER (',' IDENTIFIER)* ')'
    ;

lineExp
    : lineSegOrNodeExp (seq='->' lineSegOrNodeExp)+
    | lineSegOrNodeExp (alt='||' lineSegOrNodeExp)+
    ;

idOrNull: NULL | IDENTIFIER;

lineSegOrNodeExp
    : (('[' segName=IDENTIFIER ']')| (nodeExp ('{' backward=idOrNull forward=idOrNull '}')?) ) wildcard=('?'|'*'|'+')?
    ;

// graph
lineArgumentList
    : '(' IDENTIFIER (',' IDENTIFIER)* ')'
    ;

graphElement
    : lineName=IDENTIFIER lineArgumentList?
    ;

graphBody
    : graphElement (',' graphElement)*
    ;

pointInLine
    : '[' pointInLine (',' pointInLine)* ']'
    | INT
    ;

intersectionPoint
    : '<' pointInLine (',' pointInLine)* '>'
    ;

declaration
    : CLASS_SCOPE               IDENTIFIER '=' classScopeExp                                #classScopeDeclaration
    | NODE                      IDENTIFIER '=' nodeExp                                      #nodeDeclaration
    | (LINE|CODE_ORDER|SEGMENT) IDENTIFIER paramList? '=' lineExp                           #lineDeclaration
    | GRAPH           graphName=IDENTIFIER paramList? '=' graphBody  intersectionPoint+     #graphDeclaration
    | (LINE_INSTANCE|GRAPH_INSTANCE)    IDENTIFIER '=' IDENTIFIER lineArgumentList          #lineAndGraphInstance
    ;

showCommand
    : SHOW '(' graphName=IDENTIFIER ',' defaultStyleName=IDENTIFIER ',' basicStyleName=IDENTIFIER ')'
    ;

STRING
   : '"' (ESC | SAFECODEPOINT)* '"'
   ;


fragment ESC
   : '\\' (["\\/bfnrt] | UNICODE)
   ;


fragment UNICODE
   : 'u' HEX HEX HEX HEX
   ;


fragment HEX
   : [0-9a-fA-F]
   ;

IDENTIFIER
    : Letter LetterOrDigit*;

fragment LetterOrDigit
    : Letter
    | [0-9]
    ;

fragment Letter
    : [a-zA-Z$_] // these are the "java letters" below 0x7F
    | ~[\u0000-\u007F\uD800-\uDBFF] // covers all characters above 0x7F which are not a surrogate
    | [\uD800-\uDBFF] [\uDC00-\uDFFF] // covers UTF-16 surrogate pairs encodings for U+10000 to U+10FFFF
    ;

fragment SAFECODEPOINT
   : ~ ["\\\u0000-\u001F]
   ;


FLOAT
    : [0-9]+ '.' [0-9]+
    ;

INT
   : '0' | [1-9] [0-9]*
   ;

WS
   : [ \t\n\r] + -> skip
   ;

LINE_COMMENT
    : '//' ~[\r\n]* -> skip
    ;