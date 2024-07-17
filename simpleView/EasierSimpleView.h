namespace SimpleView {
    class BasicStyle {
    public:
        float basicNodeSize;
        float basicLabelSize;
        float basicPositionZ;

        string toString(map<int, string>& voc) const;
    };

    class NodeStyle {
    public:
        string displayName;
        string nodeColor = "";
        float nodeScale = 1.0f;
        string labelColor = "";
        float labelScale = 1.0f;
        float positionZ = 0;

        string toString(map<int, string>& voc) const;
    };

    class ToBeResolved {
    public:
        const static int CLASS_TYPE_CLASS_SCOPE = 1;
        const static int CLASS_TYPE_NODE = 2;
        const static int CLASS_TYPE_GRAPH = 3;
        static int nameCount;

        string innerValName;
        bool resolved = false;
        // todo implement loading runtime
        bool runtimeLoaded = false;

        unsigned int iconId = 0;
        string displayText = "?";
        string displayName = "";
        bool editingNew = false;

        ToBeResolved();

        virtual int getClassType() { return -1; };

        virtual void resolve(std::function<void(int, int, const char*)>* updateAddressable) { spdlog::get(ErrorManager::DebugTag)->error("default resolve function called for {}", innerValName); };
        virtual void unResolve(bool retract = false) {};
    };

    class ClassScope : public ToBeResolved {
    public:
        enum {
            CLASS_SCOPE_TYPE_KEY,
            CLASS_SCOPE_TYPE_LIST,
            CLASS_SCOPE_TYPE_IN_PACKAGE,
            CLASS_SCOPE_TYPE_USED_BY,
            CLASS_SCOPE_TYPE_USE,
            CLASS_SCOPE_TYPE_SUPER,
            CLASS_SCOPE_TYPE_SUB,
            CLASS_SCOPE_TYPE_INTERSECTION,
            CLASS_SCOPE_TYPE_UNION,
            CLASS_SCOPE_TYPE_DIFFERENCE,
            CLASS_SCOPE_TYPE_VAR,
        };
        static map<int, int> classTypeToIconId;
        int classScopeType = -1;
        string extraStr;
        ClassScope* referenceClassScope = nullptr;
        pair<ClassScope*, ClassScope*> operandForSetOperation;
        list<string> classList;

        set<string> resolvedList;

        string toString(map<int, string>& voc) const;

        void resolve(std::function<void(int, int, const char*)>* update) override;

        void unResolve(bool retract = false) override;

        int getClassType() override;

        void listTerm(vector<const char*>& ret);

        void loadValueToUI(vector<const char*>& values);

        void resetValue(const char* name, int type, vector<const char*>& values);

        void updateDisplayText();

        void loadRuntime(std::function<void(int, int, const char*)>* loadRuntimeUpdate);
    };

    class Node : public ToBeResolved {
    public:
        enum {
            NODE_TYPE_KEY = 0,
            NODE_TYPE_LIST,
            NODE_TYPE_FIELD_OF,
            NODE_TYPE_INSTANCE_OF,
            NODE_TYPE_METHOD_OF,
            NODE_TYPE_CREATOR,
            NODE_TYPE_PARAMETER_OF,
            NODE_TYPE_RETURN_OF,
            NODE_TYPE_SUPER,
            NODE_TYPE_SUB,
            NODE_TYPE_CALLED_METHOD_OF,
            NODE_TYPE_CALLED_PARAMETER_OF,
            NODE_TYPE_CALLED_RETURN_OF,
            NODE_TYPE_INTERSECTION,
            NODE_TYPE_UNION,
            NODE_TYPE_DIFFERENCE,
            NODE_TYPE_VAR,

            NODE_TYPE_READ,
            NODE_TYPE_WRITE,

            NODE_TYPE_ANY,
            NODE_TYPE_FINAL,
            NODE_TYPE_CLASS,
            NODE_TYPE_REFERENCE,
            NODE_TYPE_CONDITION,
            NODE_TYPE_DATA_STEP,
            NODE_TYPE_TIMING_STEP,
            NODE_TYPE_DATA_OVERRIDE,
            NODE_TYPE_TIMING_OVERRIDE,
            NODE_TYPE_ELSE,
            NODE_TYPE_FIELD,
            NODE_TYPE_METHOD,
            NODE_TYPE_CONSTRUCTOR,
            NODE_TYPE_CALLED_METHOD,
            NODE_TYPE_PARAMETER,
            NODE_TYPE_CALLED_PARAMETER,
            NODE_TYPE_RETURN,
            NODE_TYPE_CALLED_RETURN,
            NODE_TYPE_INDEX,

            NODE_TYPE_PARAM_OF_LINE_AND_GRAPH,
            NODE_TYPE_RUNTIME,
        };

        static map<int, int> nodeTypeToIconId;

        static Node* getSpecialNode(int nodeType);

        static Node* NODE_ANY;
        static Node* NODE_FINAL;
        static Node* NODE_CLASS;
        static Node* NODE_REFERENCE;
        static Node* NODE_CONDITION;
        static Node* NODE_ELSE;
        static Node* NODE_DATA_STEP;
        static Node* NODE_TIMING_STEP;

        static Node* NODE_FIELD;
        static Node* NODE_METHOD;
        static Node* NODE_CONSTRUCTOR;
        static Node* NODE_CALLED_METHOD;
        static Node* NODE_PARAMETER;
        static Node* NODE_CALLED_PARAMETER;
        static Node* NODE_RETURN;
        static Node* NODE_CALLED_RETURN;
        static Node* NODE_INDEX;
        static Node* NODE_DATA_OVERRIDE;
        static Node* NODE_TIMING_OVERRIDE;

        int nodeType = -1;
        string extraStr;
        pair<string, string> nodeKey;
        list<pair<string, string>> nodeList;
        list<tuple<string, string, string, int, string>> runtimeNodeList;
        ClassScope* classScope = nullptr;
        ClassScope* classScope2 = NULL;
        Node* referenceNode = nullptr;
        pair<Node*, Node*> operandForSetOperation;
        set<string> resolvedList;

        string toString(map<int, string>& voc);

        bool isLimitedCount();

        void release();

        void resolve(std::function<void(int, int, const char*)>* update) override;

        void unResolve(bool retract = false) override;

        int getClassType() override;

        void listTerm(vector<const char*>& ret);

        void loadValueToUI(vector<const char*>& values, vector<const char*>& typeKeyForNodeKey);

        void resetValue(const char* name, int type, vector<const char*>& values, vector<const char*>& typeKeyForNodeKey);

        void updateDisplayText();

        ClassScope* runtimeScopeThatUseIt();
    };

    class RegexTree {
    public:
        static int maxRecurDepth;
        static string maxRecurDepthStr;
        static void changeMaxRecurDepth();

        // if encodeChar != 0, it is a leaf node/char, otherwise it has a subStructure
        char encodeChar = 0;
        int repeatType;
        vector<RegexTree*> subStructure;
        string getRegex(bool isBackward, int* charCount);
        bool isBackward = false; // this field is only used in split point
        bool isSplitPosition = false; // this field is only used in split point
        bool isAlt = false;
        RegexTree* copy();
        string getRepeatTypeString();
    };

    class IntersectionPointInLine {
    public:
        bool isSeg = false;
        bool isIntersection = false;
        vector<IntersectionPointInLine*> seg;
        string toString();
        bool findIntersection();
        void markSplitByIntersection(RegexTree* splitPoint, int backwardFlg);
        int countPointInLineOfIntersection();
        IntersectionPointInLine* copy();
        IntersectionPointInLine* editingItem = NULL;
        void applyEditing();
        void clearEditingRecursively();
    };

    class LineTemplate;

    // nodes in segment have different encoding and different regex position in different usage, 
    // and that's why I attach the field: regex to LineTemplate binding with line, not to this class binding with the node.
    // the nodes in line have a fixed encoding and fix regex position
    class NodeAndRepeatType : public ToBeResolved {
    public:
        LineTemplate* seg = NULL;
        Node* node = nullptr;
        int repeatType;
        NodeStyle* nodeStyleSpec;

        void resolve(std::function<void(int, int, const char*)>* updateAddressable) override;

        void unResolve(bool retract = false) override;

        int countForMin(map<Node*, int>& nodeToRuntimeCount, map<string, string>& paramNameToArgName);

        bool isParamNode();

        int encode(int charIndex, map<char, NodeAndRepeatType*>& charToNode, RegexTree* outputRegex, bool isRepeatTypeOne, map<Node*, char>& nodeToChar);

        void markSplitByRuntimeCount(RegexTree* splitPoint, int backwardFlg, map<string, string>& paramNameToArgName);

        Node* getSplitPoint(RegexTree* splitPoint, map<string, string>& paramNameToArgName);
    };

    class LineInstance;

    class LineTemplate : public ToBeResolved {
    public:
        enum {
            LINE_TYPE_SEGMENT,
            LINE_TYPE_DATA_FLOW,
            LINE_TYPE_CODE_ORDER,
        };

        enum {
            REPEAT_TYPE_ONE,
            REPEAT_TYPE_ZERO_OR_ONE, //?
            REPEAT_TYPE_ZERO_OR_MORE, //*
            REPEAT_TYPE_ONE_OR_MORE, //+            
        };

        LineInstance* noneParamInstance = NULL;
        LineInstance* getNoneParamInstance();

        int lineType = -1;
        bool isAlternation = false;;
        string name;
        vector<string> orderedParamName;
        // tree structure
        vector<NodeAndRepeatType*> nodeAndRepeatType;
        RegexTree* regexTree = nullptr;
        // key value structure
        map<char, NodeAndRepeatType*> charToNodeTemplate;

        LineTemplate(const string& name, int lineType);

        bool containNode(Node* node);

        bool containLineName(string& lineName);

        bool containLineNameRecursive(string& lineName);

        void encode();

        void resolve(std::function<void(int, int, const char*)>* updateAddressable) override;

        void unResolve(bool retract = false) override;

        int getClassType() override;

        string toString(map<int, string>& voc);

        void updateDisplayText();

        void updateIconId();

        static int getIconId(int type);

        bool hasRepeatOnceNodeExceptFor(const string& exceptionSegName);

        bool checkValidation(vector<const char*>& values, vector<int>& repeatTypes);

        bool resetValue(const char* name, int type, vector<const char*>& values, vector<int>& repeatTypes, bool isAlt);

        void loadValueToUI(vector<const char*>& values, vector<int>& repeatTypes);

        IntersectionPointInLine* getPointInLine();
    };

    class Searcher {
    public:
        PlQuery* plQuerie;
        PlTermv* result = NULL;
        int outputIndex = -1;
        virtual void prepareQuery(std::function<void(int, int, const char*)>* updateAddressable, std::function<void(int, int, const char*)>* updateUnaddressable, ClassScope* classScope) {};
        virtual void onQueryFinished() {};
        virtual CompoundTerm* getQueryTerm(ClassScope* classScope) { return NULL; };
        virtual vector<Tail*> flatenResult(Term* result) { return {}; };
        void startSearching(ClassScope* classScope, std::function<void(int, int, const char*)>* updateAddressable, std::function<void(int, int, const char*)>* updateUnaddressable);
        vector<Tail*> queryNext(ClassScope* classScope);
        void endSearching(ClassScope* classScope);
    };

    class HalfLineTheFA;

    // the only difference between line instance and line template is that 
    // parameter node in line template will be replaced by argument in line instance
    class LineInstance : public ToBeResolved, public Searcher {
    public:
        bool isLineDownOrLineUp = false;
        int indexInsideGraph = 0;
        string valName;
        LineTemplate* lineTemplate = nullptr;

        map<string, string> paramNameToArgName;

        vector<IntersectionPointInLine*> intersectionInfo; // from graph tempalte
        // first point mean that it is not specified by other points in this intersection
        // also mean it is a value generating point in intersection
        // otherwise it is a value cosuming point in intersection
        map<IntersectionPointInLine*, bool> intersectionInfoIsFirstPoint;
        RegexTree* splitPoint = NULL;
        vector<Term*> intersectionTerms;

        HalfLineTheFA* forwardLine = nullptr;
        HalfLineTheFA* backwardLine = nullptr;
        // style
        NodeStyle* defaultStyle = nullptr;
        BasicStyle* basicStyle = nullptr;

        LineInstance(LineTemplate* templateLine, const vector<string>& argumentNameForEachParam);

        void findSplitPoint();

        Node* getSplitPoint();

        void resolve(std::function<void(int, int, const char*)>* updateAddressable) override;

        void unResolve(bool retract = false) override;

        void updateDisplayName();

        LineInstance* copy();

        void prepareQuery(std::function<void(int, int, const char*)>* updateAddressable, std::function<void(int, int, const char*)>* updateUnaddressable, ClassScope* classScope) override;

        void onQueryFinished() override;

        static void retractAllLineInstanceRule(int intersectionCount);

        CompoundTerm* getQueryTerm(ClassScope* classScope);
        vector<Tail*> flatenResult(Term* result) override;

        CompoundTerm* getTerm(Term* classScopeTerm, const vector<Term*>& intersections, Term* output);

        Node* turnParamNodeToArgNode(Node* param);

        int findIntersectionIndexByChar(char c);

        bool findIntersectionIndexByChar(IntersectionPointInLine* intersection, RegexTree* regexTree, char c);

        void addRuntimeNode(list<tuple<string, string, string, int, string>>& runtimeNodes, bool downward);

        void removeRuntimeNode(bool downward);
    };

    class HalfLineTheFA {
    public:
        const static char GROUP_SEPARATOR = '|';
        const static int HALF_LINE_TYPE_FORWARD = 1;
        const static int HALF_LINE_TYPE_BACKWARD = 2;
        int halfLineType = 0;
        bool isBackward;
        bool isEmpty = false;
        Term* splitTerm = nullptr;
        LineInstance* lineInstance;
        LineTemplate* lineTemplate;
        // for fa
        set<int> acceptingStates;
        map<int, list<pair<int, int>>> charCodeToStateTransition;
        map<string, int> charToCharCode;
        map<int, list<string>> charCodeToChars;
        // style
        NodeStyle* defaultStyle = nullptr;
        BasicStyle* basicStyle = nullptr;

        HalfLineTheFA(LineInstance* line, int halfLineType);

        void declareHalfLineAndFaRules();

        void declareHalfLine();

        void declareHalfLineI(int initState, int theNextState, string& regexChar);

        void makeFa();

        void declareFaRules();

        void declareTransitionRules();

        void declareStartingTransitionRuleI(int currentState, int nextState, string& regexChar);

        void declareTransitionRuleI(int currentState, int nextState, string& regexChar, bool lastTransition);

        void printCharToCharCode(const string& regex);

        Tail* getOutputItem(Term* regexCharTerm, Term* nextMethodKeyTerm, Term* nextKeyTerm, Term* outputAddressableKey, Term* keyType, Term* depth);
    };

    class GraphInstance;

    class GraphTemplate : public ToBeResolved {
    public:
        GraphInstance* noneParamInstance = NULL;
        GraphInstance* getNoneParamInstance();
        NodeStyle* defaultStyle = nullptr;
        BasicStyle* basicStyle = nullptr;
        string valName;
        vector<LineInstance*> lineInstances;
        vector<vector<IntersectionPointInLine*>> intersectionPointsInLine;
        vector<string> orderedParamName;

        void reorderLineInstance(int i, int j);

        GraphTemplate(const string& valName);

        void setDefaultAndBasicStyle(NodeStyle* defaultStyle, BasicStyle* basicStyle);

        void resolve(std::function<void(int, int, const char*)>* updateAddressable) override;

        void unResolve(bool retract = false) override;

        string toString(map<int, string>& voc);

        int countPointInLineOfIntersection(int intersectionIndex);

        void resetLineInstanceArgument(int lineIndex, vector<const char*>& args);

        void updateOrderedParam();

        void updateDisplayName();

        bool hasLineAsLineInstance(string& lineName);

        bool hasNodeAsArgument(Node* node);

        void swapIntersectionForLineTemplate(const char* lineName, int i, int j);

        void swapIntersectionForLineTemplateRecursively(const char* lineName, int i, int j, LineTemplate* lineTemplate, IntersectionPointInLine* pointsInline);

        void insertPointInLineTemplate(const char* lineName, const char* insertedName, bool isInsertedSeg, int i);

        void insertPointInLineTemplateRecursively(const char* lineName, const char* insertedName, bool isInsertedSeg, int i, LineTemplate* lineTemplate, IntersectionPointInLine* pointsInline);

        bool removePointInLineTemplate(const char* lineName, int i);

        bool removePointInLineTemplateRecursively(const char* lineName, int i, LineTemplate* lineTemplate, IntersectionPointInLine* pointsInline);

        void applyIntersectionEditing();

        void clearIntersectionEditing();

        void addNewLine(LineTemplate* lineTemplate, int index);

        void addNewLine(LineInstance* lineInstance, int index);

        GraphTemplate* copy(const string& name);
    };

    class GraphInstance : public ToBeResolved, public Searcher {
    public:
        string valName;
        GraphTemplate* graphTemplate;
        map<string, string> paramNameToArgName;
        vector<LineInstance*> lineInstances;

        GraphInstance(GraphTemplate* templateGraph, const vector<string>& argumentNameForEachParam);
        void updateDisplayName();
        void resolve(std::function<void(int, int, const char*)>* updateAddressable) override;
        void unResolve(bool retract = false) override;
        void prepareQuery(std::function<void(int, int, const char*)>* updateAddressable, std::function<void(int, int, const char*)>* updateUnaddressable, ClassScope* classScope) override;
        void onQueryFinished() override;
        CompoundTerm* getQueryTerm(ClassScope* classScope);
        vector<Tail*> flatenResult(Term* result) override;
        CompoundTerm* getTerm(Term* classScopeValName, Term* output);
    };
}

class EasierSimpleView {
public:
    static list<string> typeKeyInOrder;
    static map<string, string> typeToPackage;
    static map<string, list<string>> classToField;
    static map<string, list<string>> classToMethod;
    static map<string, list<string>> classToParameter;
    static map<string, list<string>> classToReturn;
    static map<int, string> vocabularySymbolToLiteral;
    static void saveVocabulary(SimpleViewLexer& lexer, int symbol);
    static void saveVocabulary(SimpleViewLexer& lexer);
    static void init();
    static void declareKeyConvertion();
    static void declareClassResolveRules();
    static void declareNodeResolveRules();
    static void declareStepRules();
    static void declareOverrideRules();
    static void declareLoadWhileSearching();
    static void searchClass(char* searchStr, vector<const char*>& searchResult);
    static void searchNode(const char* classKey, vector<const char*>& searchResult);
    static void filterSearchResults(char* searchStr, vector<const char*>& searchResult);
    static void getDependencyBoundsForClassScope(int classScopeIndex,
        list<int>& classScopeDependencyLower,
        list<int>& classScopeDependencyHigher,
        list<int>& nodeDependencyHigher
    );
    static void getDependencyBoundsForNode(int nodeIndex,
        list<int>& classScopeDependencyLower,
        list<int>& nodeDependencyLower,
        list<int>& nodeDependencyHigher,
        list<int>& lineDependencyHigher,
        list<int>& graphDependencyHigher,
        list<int>& lineFinalInstanceDependencyHigher,
        list<int>& graphInstanceDependencyHigher
    );

    static void getDependencyBoundsForLine(int lineIndex,
        list<int>& nodeDependencyLower,
        list<int>& lineDependencyLower,
        list<int>& lineDependencyHigher,
        list<int>& graphDependencyHigher,
        list<int>& lineFinalInstanceDependencyHigher
    );

    static void getDependencyBoundsForGraph(int graphIndex,
        list<int>& nodeDependencyLower,
        list<int>& lineDependencyLower,
        list<int>& graphInstanceDependencyHigher
    );

    static void getDependencyBoundsForLineInstance(int lineInstanceIndex,
        list<int>& nodeDependencyLower,
        list<int>& lineDependencyLower
    );

    static void getDependencyBoundsForGraphInstance(int graphInstanceIndex,
        list<int>& nodeDependencyLower,
        list<int>& graphDependencyLower
    );

    static void saveToFile();
};
