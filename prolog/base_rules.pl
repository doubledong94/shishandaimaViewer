:- dynamic addressableLoaded/1.
:- dynamic unaddressableLoaded/1.

toFile(Str):-
    open("a.txt",append,S),write(S,Str),nl(S),close(S).

toFile(Str,FilePath):-
    open(FilePath,append,S),write(S,Str),nl(S),close(S).

retractRules(R):- clause(R, B),B \== true,retract(:-(R, B)),fail.

load_addressable(ClassKey):-
    \+addressableLoaded(ClassKey),
    addressableFile(ClassKey,AddressableFile),ensure_loaded([AddressableFile]),
    addressableFile(AllClassKey,AddressableFile),
    assertz(addressableLoaded(AllClassKey)),fail.

load_unaddressable(ClassKey):-
    \+unaddressableLoaded(ClassKey),
    unaddressableFile(ClassKey,UnaddressableFile),ensure_loaded([UnaddressableFile]),
    unaddressableFile(AllClassKey,UnaddressableFile),
    assertz(unaddressableLoaded(AllClassKey)),fail.

parameterOfClass(ClassKey,ParameterKey):-
    (method(ClassKey,Method);constructor(ClassKey,Method)),parameter(Method,ParameterKey).

returnOfClass(ClassKey,ReturnKey):-
    (method(ClassKey,Method);constructor(ClassKey,Method)),return(Method,ReturnKey).

instanceOf(ClassKey1,ClassKey2,InstanceKey):-
    field(ClassKey1,InstanceKey),instanceOf(InstanceKey,ClassKey2).
instanceOf(ClassKey1,ClassKey2,InstanceKey):-
    parameterOfClass(ClassKey1,InstanceKey),instanceOf(InstanceKey,ClassKey2).
instanceOf(ClassKey1,ClassKey2,InstanceKey):-
    returnOfClass(ClassKey1,InstanceKey),instanceOf(InstanceKey,ClassKey2).

count(P,Count):-
    findall(1,P,L),length(L,Count).

isCalledMethodReturnVoid(MethodScope,CalledMethodRuntime):-
    runtimeKey(MethodScope,CalledMethod,CalledMethodRuntime,_),calledMethod(Method,CalledMethod),return(Method,ReturnKey),instanceOf(ReturnKey,"void").
    