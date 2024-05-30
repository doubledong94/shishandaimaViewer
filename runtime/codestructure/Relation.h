class ResolvingItem : public PooledItem<ResolvingItem> {
public:
    bool hasReturnValue = false;
    string variableKey;
    TypeInfo* typeInfo = NULL;
    map<TypeInfo*, TypeInfo*> typeArgs;
    string structureKey;
    string sentenceIndex;
    string indexInsideStatement;
    int keyType = -1;
    ResolvingItem* referencedBy = nullptr;
    string extraInfoForOptr = "";
    string runtimeKey = "";
    string referenceKey = "";
    string referenceRuntimeKey = "";
    string extraInfoMethodKey;
    string extraInfoParameterKey;
    string extraInfoReturnKey;
    bool runtimeAdded = false;
    bool runtimeReadAdded = false;
    bool runtimeWriteAdded = false;
    bool conditionToAdded = false;
    bool referenceAdded = false;
    bool orderPrologAdded = false;
    bool readFromLastWriteAdded = false;

    void reset() override;

    void set(const string& variableKey, TypeInfo* typeInfo, const string& structureKey, const string& sentenceIndex, const string& indexInsideExp, int keyType, const string& extraInfo = "");

    static ResolvingItem* getInstance2(const string& variableKey, TypeInfo* typeInfo, const string& structureKey, const string& sentenceIndex, const string& indexInsideExp, int keyType, const string& extraInfo = "");

    void addRuntimeProlog(string(*act)(const string& methodKey, const string& varKey, const string& runtimeKey, int keyType), const string& methodKey, list<string>& prologLines);

    void addRuntimeReadProlog(string(*act)(const string& methodKey, const string& varKey, const string& runtimeKey), const string& methodKey, list<string>& prologLines);

    void addRuntimeWritenProlog(string(*act)(const string& methodKey, const string& varKey, const string& runtimeKey), const string& methodKey, list<string>& prologLines);

    void addConditionToProlog(string(*act)(const string& methodKey, const string& conditionRuntimeKey, const string& runtimeKey), const string& methodKey, const string& conditionRuntimeKey, list<string>& prologLines);

    void addReferenceProlog(string(*act)(const string& methodKey, const string& runtime1, const string& runtime2), const string& methodKey, list<string>& prologLines);

    static string makeRuntimeKey(const string& key, const string& structureKey, const string& sentenceIndex, const string& indexInsideStatement);
};


class Relation : public CodeStructure {
public:
    ResolvingItem* read;
    ResolvingItem* writen;

    Relation(CodeStructure* parent);

    Relation(CodeStructure* parent, ResolvingItem* r, ResolvingItem* w);

};


