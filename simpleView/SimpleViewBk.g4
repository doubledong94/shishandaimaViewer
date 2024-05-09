grammar SimpleView;

ANY:'any';
FIELD_OF:'fieldOf';
METHOD_OF:'methodOf';
INSTANCE_OF:'instanceOf';
PARAMETER_OF:'parameterOf';
ARGUMENT_OF:'argumentOf';
RETURN_OF:'returnOf';
FINAL:'final';
LOCAL_VARIABLE:'localVariable';
ARITHMETIC_OPTR:'arithmetic';
RELATIONAL_OPTR:'relational';
LOGICAL_OPTR:'logicalOptr';
INDEX_OPTR:'indexOptr';
ASSIGN : 'assign';
REFERENCE:'reference';
//CONDITION_STRUCTURE : 'conditionStructure';
//VOID_STRUCTURE : 'voidStructure';

NODE_CONFIG_COLOR:'nodeColor';
NODE_CONFIG_SCALE:'nodeScale';
NODE_CONFIG_LABEL_COLOR:'labelColor';
NODE_CONFIG_LABEL_SCALE:'labelScale';
NODE_CONFIG_LABEL_DETAIL_LEVEL:'labelDetailLevel';

GLOBAL_CONFIG_MAX_RECUR_DEPTH:'maxRecurDepth';
GLOBAL_CONFIG_DEFAULT_NODE_COLOR:'defaultNodeColor';
GLOBAL_CONFIG_NODE_BASE_SIZE:'nodeBaseSize';
GLOBAL_CONFIG_DEFAULT_LABEL_COLOR:'defaultLabelColor';
GLOBAL_CONFIG_LABEL_BASE_SIEZ:'labelBaseSize';
GLOBAL_CONFIG_DEFAULT_LABEL_DETAIL_LEVEL:'defaultLabelDetailLevel';

LABEL_DETAIL_LEVEL_SIMPLE:'"simple"';
LABEL_DETAIL_LEVEL_FULL:'"full"';

compilationUnit
    :scope line line* ('[' globalConfig (',' globalConfig)* ']')?
    ;

scope
    : '{' STRING (',' STRING)+ '}'
    ;

line
    :'{' lineSeg (',' lineSeg)+ '}'
    ;

lineSeg
    : relationTypes? nodeTypeWithConfig wildcard=('?'|'*'|'+')?
    ;

nodeTypeWithConfig
    : '(' nodeType (',' nodeType)* ')' ('[' nodeConfig (',' nodeConfig)* ']')?
    ;

nodeType
    : ANY
    | FIELD_OF '(' STRING ')'
    | METHOD_OF '(' STRING ')'
    | INSTANCE_OF '(' STRING ')'
    | PARAMETER_OF '(' STRING ')'
    | ARGUMENT_OF '(' STRING ')'
    | RETURN_OF '(' STRING ')'
    | FINAL
    | LOCAL_VARIABLE
    | ARITHMETIC_OPTR
    | RELATIONAL_OPTR
    | LOGICAL_OPTR
    | INDEX_OPTR
    | nodeID=STRING
    ;

relationTypes
    : '<' relationType  (',' relationType)* '>'
    ;

relationType
    : ANY
    | ASSIGN
    | REFERENCE
//    | INDEX
//    | CONDITION_STRUCTURE
//    | VOID_STRUCTURE
    ;

nodeConfig
    : NODE_CONFIG_COLOR '=' STRING
    | NODE_CONFIG_SCALE '=' FLOAT
    | NODE_CONFIG_LABEL_COLOR '=' STRING
    | NODE_CONFIG_LABEL_SCALE '=' FLOAT
    | NODE_CONFIG_LABEL_DETAIL_LEVEL '=' (LABEL_DETAIL_LEVEL_SIMPLE|LABEL_DETAIL_LEVEL_FULL)
    ;

globalConfig
    : GLOBAL_CONFIG_MAX_RECUR_DEPTH '=' INT
    | GLOBAL_CONFIG_DEFAULT_NODE_COLOR '=' STRING
    | GLOBAL_CONFIG_NODE_BASE_SIZE '=' FLOAT
    | GLOBAL_CONFIG_DEFAULT_LABEL_COLOR '=' STRING
    | GLOBAL_CONFIG_LABEL_BASE_SIEZ '=' FLOAT
    | GLOBAL_CONFIG_DEFAULT_LABEL_DETAIL_LEVEL '=' (LABEL_DETAIL_LEVEL_SIMPLE|LABEL_DETAIL_LEVEL_FULL)
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
