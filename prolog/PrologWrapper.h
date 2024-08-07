class PrologWrapper {
public:
    static PlEngine *e;

    static bool init();

    static Term *query(CompoundTerm *term);

    static PlQuery* makeQuery(CompoundTerm *term, PlTermv* &result, int &outputIndex);

    static void queryList(CompoundTerm *term, const std::function<void(vector<Term*>&)>& consumer);

    static int queryCount(CompoundTerm *term);

    static void declareFun(const string &functorName, int arity);

    static void addFact(const string &factStr);

    static void retractSingleFact(const string &factStr);

    static string makeUnderScoreArguments(int arity);

    static void retractAllFact(const string &functorName, int arity);

    static void addRule(const string &ruleStr);

    static void retractSingleRule(const string &ruleStr);

    static void retractAllRule(const string &header, int arity);

    static void compileFile(const string &filePath);

    static bool loadFileIfExist(const string &filePath);

    static void unLoadFile(const string &filePath);

    static void plCall(const string& clause);

    static void loadTypeKeyAddressable(const string &typeKey);
    static void loadTypeKeyUnaddressable(const string &typeKey);
};

