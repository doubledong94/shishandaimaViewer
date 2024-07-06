:- multifile simpleName/2.
:- dynamic forwardFaCache/6.
:- dynamic backwardFaCache/6.
:- dynamic forwardFaDone/5.
:- dynamic backwardFaDone/5.

toFile(Str):-
    open("a.txt",append,S),write(S,Str),nl(S),close(S).

toFile(Str,FilePath):-
    open(FilePath,append,S),write(S,Str),nl(S),close(S).

retractRules(R):- clause(R, B),B \== true,retract(:-(R, B)),fail.

parameterOfClass(ClassKey,ParameterKey):-
    method(ClassKey,Method),parameter(Method,ParameterKey).

returnOfClass(ClassKey,ReturnKey):-
    method(ClassKey,Method),return(Method,ReturnKey).

instanceOf(ClassKey1,ClassKey2,InstanceKey):-
    field(ClassKey1,InstanceKey),instanceOf(InstanceKey,ClassKey2).
instanceOf(ClassKey1,ClassKey2,InstanceKey):-
    parameterOfClass(ClassKey1,InstanceKey),instanceOf(InstanceKey,ClassKey2).
instanceOf(ClassKey1,ClassKey2,InstanceKey):-
    returnOfClass(ClassKey1,InstanceKey),instanceOf(InstanceKey,ClassKey2).

count(P,Count):-
    findall(1,P,L),length(L,Count).

simpleName("[Array].length","length").

calledParamterInstanceOf(CalledParam, TypeKey):-
    calledParam(P,CalledParam),instanceOf(P,TypeKey).
calledReturnInstanceOf(CalledReturn, TypeKey):-
    calledReturn(R,CalledReturn),instanceOf(R,TypeKey).
