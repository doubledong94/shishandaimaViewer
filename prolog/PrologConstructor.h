static int prolog_debug_flags = 0;
const static int prolog_debug_flag_transition = 1;

class Term : public PooledItem<Term> {
public:
    const static int TERM_TYPE_VAR = 1;
    const static int TERM_TYPE_ATOM = 2;
    const static int TERM_TYPE_STRING = 3;
    const static int TERM_TYPE_INTEGER = 4;

    string atomOrVar;
    int integer = 0;
    int termType = 0;

    Term();

    Term(const string& s, int termType);

    static Term* getIgnoredVar();

    static Term* getVar(const string& s);

    static Term* getStr(const string& s);

    static Term* getStrByChar(const char& c);

    static Term* getAtom(const string& s);

    static Term* getInt(int integer);

    virtual string toString(bool returnToPool = false);

    virtual PlTerm* toPlTerm();

    virtual void returnThisToPool();

    void reset() override;
};

string termToString(Term* term);

string getMultiFileDirective(const string& functorName, const string& arityCount);

class MinusTerm : public Term {
public:
    Term* remainderTerm;
    Term* minuendTerm;
    Term* subtrahend;

    MinusTerm(Term* remainderTerm, Term* minuendTerm, Term* subtrahend);

    string toString(bool returnToPool = false) override;

    void returnThisToPool() override;
};

class NegationTerm : public Term, public PooledItem<NegationTerm> {
public:
    using PooledItem<NegationTerm>::isInPool;

    Term* term;

    static NegationTerm* getNegInstance(Term* t);

    string toString(bool returnToPool = false) override;

    void reset() override;

    void returnThisToPool() override;
};

class DisjunctionTerm : public Term, public PooledItem<DisjunctionTerm> {
public:
    using PooledItem<DisjunctionTerm>::isInPool;

    vector<Term*> terms;

    static DisjunctionTerm* getDisjunctionInstance(Term* t1, Term* t2);

    static DisjunctionTerm* getDisjunctionInstance(const vector<Term*>& terms);

    void reset() override;

    string toString(bool returnToPool = false) override;

    void returnThisToPool() override;
};

class ConjunctionTerm : public Term, public PooledItem<ConjunctionTerm> {
public:
    using PooledItem<ConjunctionTerm>::isInPool;

    vector<Term*> terms;

    static ConjunctionTerm* getConjunctionInstance(const vector<Term*>& terms);

    void reset() override;

    string toString(bool returnToPool = false) override;

    void returnThisToPool() override;
};

static Term* HEAD_TYPE_TO_PL_FILE = new Term("typeToPlFile", Term::TERM_TYPE_ATOM);
static Term* HEAD_PACKAGE = new Term("package", Term::TERM_TYPE_ATOM);
static Term* HEAD_SUB_TYPE = new Term("subType", Term::TERM_TYPE_ATOM);
static Term* HEAD_SUB_TYPE_DOWN_RECUR = new Term("subTypeDownRecur", Term::TERM_TYPE_ATOM);
static Term* HEAD_SUB_TYPE_UP_RECUR = new Term("subTypeUpRecur", Term::TERM_TYPE_ATOM);
static Term* HEAD_OVERRIDE = new Term("override", Term::TERM_TYPE_ATOM);
static Term* HEAD_OVERRIDE_IN_RECUR = new Term("overrideInRecur", Term::TERM_TYPE_ATOM);
static Term* HEAD_OVERRIDE_OUT_RECUR = new Term("overrideOutRecur", Term::TERM_TYPE_ATOM);
static Term* HEAD_METHOD_USE_METHOD = new Term("methodUseMethod", Term::TERM_TYPE_ATOM);
static Term* HEAD_METHOD_USE_FIELD = new Term("methodUseField", Term::TERM_TYPE_ATOM);
static Term* HEAD_METHOD = new Term("method", Term::TERM_TYPE_ATOM);
static Term* HEAD_CONSTRUCTOR = new Term("constructor", Term::TERM_TYPE_ATOM);
static Term* HEAD_PARAMETER = new Term("parameter", Term::TERM_TYPE_ATOM);
static Term* HEAD_RETURN = new Term("return", Term::TERM_TYPE_ATOM);
static Term* HEAD_PARAMETER_OF_CLASS = new Term("parameterOfClass", Term::TERM_TYPE_ATOM);
static Term* HEAD_RETURN_OF_CLASS = new Term("returnOfClass", Term::TERM_TYPE_ATOM);
static Term* HEAD_VAR = new Term("var", Term::TERM_TYPE_ATOM);
static Term* HEAD_FIELD = new Term("field", Term::TERM_TYPE_ATOM);
static Term* HEAD_INSTANCE_OF = new Term("instanceOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_SIMPLE_NAME = new Term("simpleName", Term::TERM_TYPE_ATOM);
static Term* HEAD_IS_FINAL = new Term("isFinal", Term::TERM_TYPE_ATOM);
static Term* HEAD_IS_WRITE = new Term("isWrite", Term::TERM_TYPE_ATOM);

static Term* HEAD_FLOW = new Term("flow", Term::TERM_TYPE_ATOM);
static Term* HEAD_CODE_ORDER = new Term("codeOrder", Term::TERM_TYPE_ATOM);
static Term* HEAD_CALLED_KEY = new Term("calledKey", Term::TERM_TYPE_ATOM);
static Term* HEAD_STEP_KEY = new Term("stepKey", Term::TERM_TYPE_ATOM);
static Term* HEAD_OVERRIDE_KEY = new Term("overrideKey", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_DATA_STEP = new Term("forwardDataStep", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_DATA_STEP = new Term("backwardDataStep", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_TIMING_STEP = new Term("forwardTimingStep", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_TIMING_STEP = new Term("backwardTimingStep", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_DATA_OVERRIDE = new Term("forwardDataOverride", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_DATA_OVERRIDE = new Term("backwardDataOverride", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_TIMING_OVERRIDE = new Term("forwardTimingOverride", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_TIMING_OVERRIDE = new Term("backwardTimingOverride", Term::TERM_TYPE_ATOM);
static Term* HEAD_CALLED_PARAM_TO_CALLED_RETURN = new Term("calledParamToCalledReturn", Term::TERM_TYPE_ATOM);
static Term* HEAD_CALLED_METHOD_TO_CALLED_RETURN = new Term("calledMethodToCalledReturn", Term::TERM_TYPE_ATOM);
static Term* HEAD_CALLED_RETURN_TO_CALLED_PARAM = new Term("calledReturnToCalledParam", Term::TERM_TYPE_ATOM);
static Term* HEAD_CALLED_RETURN_TO_CALLED_METHOD = new Term("calledReturnToCalledMethod", Term::TERM_TYPE_ATOM);

static Term* HEAD_RUNTIME_READ = new Term("runtimeRead", Term::TERM_TYPE_ATOM);
static Term* HEAD_RUNTIME_WRITE = new Term("runtimeWrite", Term::TERM_TYPE_ATOM);
static Term* HEAD_RUNTIME_KEY = new Term("runtimeKey", Term::TERM_TYPE_ATOM);

static Term* HEAD_LINE = new Term("line", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_HALF_LINE = new Term("forwardHalfLine", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_FA = new Term("forwardFa", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_FA_IMPL = new Term("forwardFaImpl", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_FA_SUCC = new Term("forwardFaSucc", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_FA_DONE = new Term("forwardFaDone", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_HALF_LINE = new Term("backwardHalfLine", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_FA = new Term("backwardFa", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_FA_IMPL = new Term("backwardFaImpl", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_FA_SUCC = new Term("backwardFaSucc", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_FA_DONE = new Term("backwardFaDone", Term::TERM_TYPE_ATOM);
static Term* HEAD_GRAPH = new Term("graph", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_TRANSITION = new Term("forwardTransition", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_TRANSITION = new Term("backwardTransition", Term::TERM_TYPE_ATOM);
static Term* HEAD_FORWARD_ENDING_TRANSITION = new Term("forwardEndingTransition", Term::TERM_TYPE_ATOM);
static Term* HEAD_BACKWARD_ENDING_TRANSITION = new Term("backwardEndingTransition", Term::TERM_TYPE_ATOM);
static Term* HEAD_RESOLVE = new Term("resolve", Term::TERM_TYPE_ATOM);
static Term* HEAD_RESOLVE_RUNTIME = new Term("resolveRuntime", Term::TERM_TYPE_ATOM);
static Term* HEAD_RESOLVE_RUNTIME_CHECK = new Term("resolveRuntimeCheck", Term::TERM_TYPE_ATOM);
static Term* HEAD_CLASS_SCOPE_SUPER = new Term("classScopeSuper", Term::TERM_TYPE_ATOM);
static Term* HEAD_CLASS_SCOPE_SUB = new Term("classScopeSub", Term::TERM_TYPE_ATOM);
static Term* HEAD_CLASS_SCOPE_UNION = new Term("classScopeUnion", Term::TERM_TYPE_ATOM);
static Term* HEAD_CLASS_SCOPE_INTERSECTION = new Term("classScopeIntersection", Term::TERM_TYPE_ATOM);
static Term* HEAD_CLASS_SCOPE_DIFFERENCE = new Term("classScopeDifference", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_FIELD_OF = new Term("nodeFieldOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_METHOD_OF = new Term("nodeMethodOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_CONSTRUCTOR_OF = new Term("nodeConstructorOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_INSTANCE_OF = new Term("nodeInstanceOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_PARAMETER_OF = new Term("nodeParameterOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_RETURN_OF = new Term("nodeReturnOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_CALLED_METHOD_OF = new Term("nodeCalledMethodOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_CALLED_PARAMETER_OF = new Term("nodeCalledParameterOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_CALLED_RETURN_OF = new Term("nodeCalledReturnOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_METHOD_USED_BY = new Term("nodeMethodUsedBy", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_FIELD_USED_BY = new Term("nodeFieldUsedBy", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_METHOD_USE = new Term("nodeMethodUse", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_SUPER_OF = new Term("nodeSuperOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_SUB_OF = new Term("nodeSubOf", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_READ = new Term("nodeRead", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_WRITE = new Term("nodeWrite", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_CREATOR = new Term("nodeCreator", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_UNION = new Term("nodeUnion", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_INTERSECTION = new Term("nodeIntersection", Term::TERM_TYPE_ATOM);
static Term* HEAD_NODE_DIFFERENCE = new Term("nodeDifference", Term::TERM_TYPE_ATOM);
static Term* HEAD_PRINT = new Term("print", Term::TERM_TYPE_ATOM);
static Term* HEAD_TO_FILE = new Term("toFile", Term::TERM_TYPE_ATOM);
static Term* HEAD_STATISTICS = new Term("statistics", Term::TERM_TYPE_ATOM);
static Term* HEAD_ASSERTZ = new Term("assertz", Term::TERM_TYPE_ATOM);
static Term* TERM_NEXT_LINE = new Term("nl", Term::TERM_TYPE_ATOM);

static Term* HEAD_MEMBER = new Term("member", Term::TERM_TYPE_ATOM);
static Term* HEAD_LENGTH = new Term("length", Term::TERM_TYPE_ATOM);
static Term* HEAD_COUNT = new Term("count", Term::TERM_TYPE_ATOM);

static Term* HEAD_LOAD_STEP_IN_RUNTIME = new Term("loadStepInRuntime", Term::TERM_TYPE_ATOM);
static Term* HEAD_LOAD_OVERRIDE_IN_RUNTIME = new Term("loadOverrideInRuntime", Term::TERM_TYPE_ATOM);
static Term* HEAD_LOAD_USE_METHOD_RUNTIME = new Term("loadUseMethodRuntime", Term::TERM_TYPE_ATOM);
static Term* HEAD_LOAD_USE_OVERRIDE_METHOD_RUNTIME = new Term("loadUseOverrideMethodRuntime", Term::TERM_TYPE_ATOM);
static Term* HEAD_LOAD_METHOD_USE_ADDRESSABLE = new Term("loadMethodUseAddressable", Term::TERM_TYPE_ATOM);
static Term* HEAD_LOAD_RUNTIME = new Term("load_unaddressable", Term::TERM_TYPE_ATOM);
static Term* HEAD_LOAD_ADDRESSABLE = new Term("load_addressable", Term::TERM_TYPE_ATOM);
static Term* HEAD_ADDRESSABLE_LOADED = new Term("addressableLoaded", Term::TERM_TYPE_ATOM);
static Term* HEAD_UNADDRESSABLE_LOADED = new Term("unaddressableLoaded", Term::TERM_TYPE_ATOM);
static Term* HEAD_STRING_CONCAT = new Term("string_concat", Term::TERM_TYPE_ATOM);
static Term* HEAD_CLASS_THAT_USE_METHOD_AND_FIELD = new Term("classThatUseMethodAndField", Term::TERM_TYPE_ATOM);
static Term* HEAD_LOOP_MORE_THAN_ONCE = new Term("loopMoreThanOnce", Term::TERM_TYPE_ATOM);
static Term* HEAD_EXCLUDE_PACKAGE = new Term("excludePackage", Term::TERM_TYPE_ATOM);
static Term* HEAD_EXCLUDE_METHOD = new Term("excludeMethod", Term::TERM_TYPE_ATOM);

class CompoundTerm : public Term, public PooledItem<CompoundTerm> {
public:

    using PooledItem<CompoundTerm>::isInPool;

    Term* head = nullptr;
    vector<Term*> args;

    void reset() override;

    void addArg(Term* arg);

    void addVarTermArg();

    static CompoundTerm* makeTerm(Term* head, Term* arg1);

    static CompoundTerm* makeTerm(Term* head, Term* arg1, Term* arg2);

    static CompoundTerm* makeTerm(Term* head, Term* arg1, Term* arg2, Term* arg3);

    static CompoundTerm* makeTerm(Term* head, Term* arg1, Term* arg2, Term* arg3, Term* arg4);

    static CompoundTerm* makeTerm(Term* head, Term* arg1, Term* arg2, Term* arg3, Term* arg4, Term* arg5);

    static CompoundTerm* makeTerm(Term* head, Term* arg1, Term* arg2, Term* arg3, Term* arg4, Term* arg5, Term* arg6);

    static CompoundTerm* getExcludePackageTerm(Term* pkg);

    static CompoundTerm* getExcludeMethodTerm(Term* method);

    static CompoundTerm* getLoopMoreThanOnceTerm(Term* l, Term* e);

    static CompoundTerm* getClassThatUseMethodAndFieldTerm(Term* methodOrField, Term* classKey);

    static CompoundTerm* getAddressableLoadedTerm(Term* addressable);

    static CompoundTerm* getUnaddressableLoadedTerm(Term* unaddressable);

    static CompoundTerm* getStringConcatTerm(Term* term1, Term* term2, Term* term);

    static CompoundTerm* getLoadStepInRuntimeTerm(Term* addressable);

    static CompoundTerm* getLoadOverrideInRuntimeTerm(Term* addressable);

    static CompoundTerm* getCalledKeyTerm(Term* key, Term* calledKey);

    static CompoundTerm* getLoadMethodUseAddressableTerm(Term* method);

    static CompoundTerm* getLoadUseMethodRuntimeTerm(Term* method);

    static CompoundTerm* getLoadUseOverrideMethodRuntimeTerm(Term* method);

    static CompoundTerm* getLoadRuntimeTerm(Term* classKey);

    static CompoundTerm* getLoadAddressableTerm(Term* classKey);

    static CompoundTerm* getMemberTerm(Term* m, Term* l);

    static CompoundTerm* getLengthTerm(Term* list_, Term* length);

    static CompoundTerm* getFlowTerm(Term* mk, Term* src, Term* dst);

    static string getFlowFact(const string& mk, const string& src, const string& dst);

    static CompoundTerm* getIsWriteTerm(Term* mk, Term* runtimeNode);

    static string getIsWriteFact(const string& mk, const string& runtimeNode);

    static CompoundTerm* getCodeOrderTerm(Term* mk, Term* src, Term* dst);

    static string getCodeOrderFact(const string& mk, const string& src, const string& dst);

    static CompoundTerm* getRuntimeReadTerm(Term* mk, Term* variable, Term* runtimeReadKey);

    static string getRuntimeReadFact(const string& mk, const string& variable, const string& runtimeReadKey);

    static CompoundTerm* getRuntimeWriteTerm(Term* mk, Term* variable, Term* runtimeWriteKey);

    static string getRuntimeWriteFact(const string& mk, const string& variable, const string& runtimeWriteKey);

    static string getTypeToPLFileFact(const string& typeKey, const string& filePath);

    static CompoundTerm* getTypeToPLFileTerm(Term* typeKey, Term* filePath);

    static string getPackageFact(const string& package, const string& typeKey);

    static CompoundTerm* getPackageTerm(Term* package, Term* typeKey);

    static CompoundTerm* getSubTypeTerm(Term* typeKey, Term* subTypeKey);

    static CompoundTerm* getSubTypeDownRecurTerm(Term* typeKey, Term* subTypeKey);

    static CompoundTerm* getSubTypeUpRecurTerm(Term* typeKey, Term* subTypeKey);

    static string getSubTypeFact(const string& typeKey, const string& subTypeKey);

    static CompoundTerm* getOverrideTerm(Term* key, Term* subKey);

    static CompoundTerm* getOverrideInRecurTerm(Term* key, Term* subKey);

    static CompoundTerm* getOverrideOutRecurTerm(Term* superKey, Term* key);

    static string getOverrideFact(const string& key, const string& subKey);

    static string getMethodUseMethodFact(const string& mk, const string& usedMk);

    static CompoundTerm* getMethodUseMethodTerm(Term* mk, Term* usedMk);

    static string getMethodUseFieldFact(const string& mk, const string& usedF);

    static CompoundTerm* getMethodUseFieldTerm(Term* mk, Term* usedF);

    static string getMethodFact(const string& typeKey, const string& methodKey);

    static CompoundTerm* getMethodTerm(Term* typeKey, Term* methodKey);

    static string getConstructorFact(const string& typeKey, const string& constructorKey);

    static CompoundTerm* getConstructorTerm(Term* typeKey, Term* constructorKey);

    static string getParameterFact(const string& methodKey, const string& parameterKey);

    static CompoundTerm* getParameterTerm(Term* methodKey, Term* parameterKey);

    static string getReturnFact(const string& methodKey, const string& returnKey);

    static CompoundTerm* getReturnTerm(Term* methodKey, Term* returnKey);

    static CompoundTerm* getParameterOfClassTerm(Term* classKey, Term* paramter);

    static CompoundTerm* getReturnOfClassTerm(Term* classKey, Term* returnKey);

    static CompoundTerm* getStepKeyTerm(Term* key, Term* stepKey);

    static CompoundTerm* getOverrideKeyTerm(Term* key, Term* overrideKey);

    static CompoundTerm* getForwardDataStepTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextStepKey, Term* currentSetps, Term* nextSetps);

    static CompoundTerm* getBackwardDataStepTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextStepKey, Term* currentSetps, Term* nextSetps);

    static CompoundTerm* getForwardTimingStepTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextStepKey, Term* currentSetps, Term* nextSetps);

    static CompoundTerm* getBackwardTimingStepTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextStepKey, Term* currentSetps, Term* nextSetps);

    static CompoundTerm* getForwardDataOverrideTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextOverrideKey, Term* currentSetps, Term* nextSetps);

    static CompoundTerm* getBackwardDataOverrideTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextOverrideKey, Term* currentSetps, Term* nextSetps);

    static CompoundTerm* getForwardTimingOverrideTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextOverrideKey, Term* currentSetps, Term* nextSetps);

    static CompoundTerm* getBackwardTimingOverrideTerm(Term* runtimeMethod, Term* point, Term* nextRuntimeMethod, Term* nextOverrideKey, Term* currentSetps, Term* nextSetps);

    static CompoundTerm* getCalledParamToCalledReturnTerm(Term* runtimeMethodKey, Term* calledParam, Term* calledReturn);

    static CompoundTerm* getCalledMethodToCalledReturnTerm(Term* runtimeMethodKey, Term* calledMethod, Term* calledReturn);

    static CompoundTerm* getCalledReturnToCalledParam(Term* runtimeMethodKey, Term* calledReturn, Term* calledParam);

    static CompoundTerm* getCalledReturnToCalledMethod(Term* runtimeMethodKey, Term* calledReturn, Term* calledMethod);

    static CompoundTerm* getVarTerm(Term* t);

    static string getFieldFact(const string& typeKey, const string& fieldKey);

    static CompoundTerm* getFieldTerm(Term* typeKey, Term* fieldKey);

    static string getInstanceOfFact(const string& instanceKey, const string& typeKey);

    static CompoundTerm* getInstanceOfTerm(Term* instanceKey, Term* typeKey);

    static string getSimpleNameFact(const string& key, const string& simpleName);

    static CompoundTerm* getSimpleNameTerm(Term* key, Term* simpleName);

    static string getIsFinalFact(const string& key);

    static Term* getIsFinalTerm(Term* key);

    static string getRuntimeFact(const string& methodKey, const string& key, const string& runtimeKey, int keyType);

    static CompoundTerm* getRuntimeTerm(Term* methodKey, Term* key, Term* runtimeKey, Term* keyType);

    static CompoundTerm* getGraphTerm(Term* graphValName, Term* classScopeValName, Term* output);

    static CompoundTerm* getCountTerm(Term* term, Term* count);

    static void retractAllGraphTerm();

    static CompoundTerm* getLineTerm(Term* lineInstanceValName, Term* classScopeValName, const vector<Term*>& intersections, Term* output);

    static void retractAllLineTerm(int intersectionCount);

    static Term* getHalfLineTerm(
        Term* lineInstanceValName,
        Term* classScopeValName,
        Term* splitTerm,
        const vector<Term*>& intersections,
        Term* output,
        bool isBackward);

    static void retractAllHalfLineTerm(bool isBackward, int intersectionCount);

    static Term* getFaTerm(
        Term* lineInstanceValName,
        Term* classScopeValName,
        Term* currentState,
        Term* currentPoint,
        Term* currentSteps,
        const vector<Term*>& intersections,
        Term* output,
        Term* history,
        bool isBackward);

    static Term* getFaImplTerm(
        Term* lineInstanceValName,
        Term* classScopeValName,
        Term* currentState,
        Term* currentPoint,
        Term* currentSteps,
        const vector<Term*>& intersections,
        Term* output,
        Term* history,
        bool isBackward);

    static Term* getFaSuccTerm(
        Term* lineInstanceValName,
        Term* classScopeValName,
        Term* currentState,
        Term* currentPoint,
        bool isBackward);

    static Term* getFaDoneTerm(
        Term* lineInstanceValName,
        Term* classScopeValName,
        Term* currentState,
        Term* currentPoint,
        bool isBackward);

    static void retractAllFaTerm(bool isBackward, int intersectionCount);

    static void retractAllFaImplTerm(bool isBackward, int intersectionCount);

    static void retractAllFaSuccTerm(bool isBackward);

    static void retractAllFaDoneTerm(bool isBackward);

    static Term* getTransitionTerm(
        Term* lineInstanceValName,
        Term* classScopeValName,
        Term* currentState,
        Term* nextState,
        Term* regexChar,
        Term* currentPoint,
        Term* currentSteps,
        Term* expectingNextKey,
        Term* nextPoint,
        Term* nextSteps,
        const vector<Term*>& intersections,
        Term* outputItem,
        bool isBackward);

    static CompoundTerm* getEndingTransitionTerm(
        Term* lineInstanceValName,
        Term* classScopeValName,
        Term* currentState, Term* endState,
        bool isBackward);

    static void retractAllTransitionTerm(bool isBackward, int intersectionCount);

    static CompoundTerm* getClassScopeSuper(Term* typeKey, Term* superTypeKey);

    static CompoundTerm* getClassScopeSub(Term* typeKey, Term* subTypeKey);

    static CompoundTerm* getClassScopeUnionTerm(Term* Class1, Term* Class2, Term* UnionClass);

    static CompoundTerm* getClassScopeIntersectionTerm(Term* Class1, Term* Class2, Term* IntersectClass);

    static CompoundTerm* getClassScopeDifferenceTerm(Term* Class1, Term* Class2, Term* DifferenceClass);

    static CompoundTerm* getNodeFieldOfTerm(Term* ClassScopeValName, Term* Field);

    static CompoundTerm* getNodeMethodOfTerm(Term* ClassScopeValName, Term* Method);

    static CompoundTerm* getNodeConstructorOfTerm(Term* ClassScopeValName, Term* Constructor);

    static CompoundTerm* getNodeInstanceOf(Term* ClassScopeValName, Term* ClassValName, Term* Instance);

    static CompoundTerm* getNodeParameterOf(Term* MethodNodeValName, Term* Param);

    static CompoundTerm* getNodeReturnOf(Term* MethodNodeValName, Term* Return);

    static CompoundTerm* getNodeCalledMethodOf(Term* MethodNodeValName, Term* CalledMethod);

    static CompoundTerm* getNodeCalledParameterOf(Term* ParamNodeValName, Term* CalledParam);

    static CompoundTerm* getNodeCalledReturnOf(Term* ReturnNodeValName, Term* CalledReturn);

    static CompoundTerm* getNodeMethodUsedBy(Term* MethodNodeValName, Term* MethodUsedBy);

    static CompoundTerm* getNodeFieldUsedBy(Term* MethodNodeValName, Term* FieldUsedBy);

    static CompoundTerm* getNodeMethodUse(Term* MethodNodeValName, Term* MethodUse);

    static CompoundTerm* getNodeSuperOf(Term* superNode, Term* subNode);

    static CompoundTerm* getNodeSubOf(Term* superNode, Term* subNode);

    static CompoundTerm* getNodeUnion(Term* Node1, Term* Node2, Term* Node);

    static CompoundTerm* getNodeIntersection(Term* Node1, Term* Node2, Term* Node);

    static CompoundTerm* getNodeDifference(Term* Node1, Term* Node2, Term* Node);

    static CompoundTerm* getResolveTerm(Term* valName, Term* key);

    static void retractAllResolveTerm();

    static CompoundTerm* getResolveRuntimeTerm(Term* nodeValName, Term* classValName, Term* methodKey, Term* runtimeNode, Term* key, Term* keyType);

    static CompoundTerm* getResolveRuntimeCheckTerm(Term* nodeValName, Term* methodKey, Term* runtimeNode, Term* key, Term* keyType);

    static CompoundTerm* getPrintTerm(Term* p);

    static CompoundTerm* getToFileTerm(Term* content, Term* fileTerm);

    static CompoundTerm* getStatisticsTerm(Term* startOrStop);

    string toString(bool returnToPool = false) override;

    PlTerm* toPlTerm() override;

    void returnThisToPool() override;
};

class Unification : public Term, public PooledItem<Unification> {
public:
    using PooledItem<Unification>::isInPool;

    Term* firstTerm = nullptr;
    Term* secondTerm = nullptr;

    static Unification* getUnificationInstance(Term* first, Term* second);

    string toString(bool returnToPool = false) override;

    void reset() override;

    void returnThisToPool() override;
};

class Tail : public Term, public PooledItem<Tail> {
public:
    using PooledItem<Tail>::isInPool;

    vector<Term*> headElements;
    Term* tail = nullptr;

    static Tail* getTailInstance(Term* h, Term* tail);

    static Tail* getTailInstance(Term* h1, Term* h2, Term* tail);

    static Tail* getInstanceByElements(const vector<Term*>& elements);

    static Tail* getFaOutputList(Term* regexChar, Term* methodKeyVar, Term* runtimeKeyVar);

    static Tail* getCompleteOutputList(Term* regexChar, Term* nodeType, Term* nodeLabel, Term* keyVar, Term* runtimeKeyVar, Term* methodKeyVar, Term* classKeyVar, Term* packageKeyVar);

    string toString(bool returnToPool = false) override;

    PlTerm* toPlTerm() override;

    void returnThisToPool() override;

    void addElement(Term* term);

    void reset() override;

    void reverse();
};

class AssertTerm : public Term, public PooledItem<AssertTerm> {
public:
    using PooledItem<AssertTerm>::isInPool;

    Term* term = NULL;
    static AssertTerm* getAssertInstance(Term* term);
    void reset() override;
    string toString(bool returnToPool = false) override;

    void returnThisToPool() override;
};

class EnsureLoadedTerm : public Term, public PooledItem<EnsureLoadedTerm> {
public:
    using PooledItem<EnsureLoadedTerm>::isInPool;
    Term* term = NULL;
    static EnsureLoadedTerm* getEnsureLoadedInstance(Term* term);
    void reset() override;
    string toString(bool returnToPool = false) override;
    void returnThisToPool() override;
};

class Rule : public PooledItem<Rule> {
public:
    Term* head = nullptr;
    vector<Term*> conditions;

    static Rule* getRuleInstance(Term* head, const vector<Term*>& conditions);

    string toString(bool returnToPool = false);

    void reset() override;

    void returnThisToPool();
};

void addTimeCountToRuleBody(vector<Term*>& ruleBody, const string& ruleName);

Term* convertPlTermToTerm(PlTerm* plTerm);

namespace PrologConstructor {

    void init();

    void writeToPrologFile(const string& filePath, list<string>& lines);

    void saveAddressableInfo(const string& filePath, const list<TypeInfo*>& typeInfos);
};

