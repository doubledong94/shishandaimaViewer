
class CodeBlock : public CodeStructure {
public:
    ResolvingItem* conditionItem = nullptr;
    ResolvingItem* elseConditionValue = NULL; // this is lastCodeBlock->conditionItem
    ResolvingItem* elseValue = NULL;
    ResolvingItem* toConditionValue = NULL;
    Sentence* toConditionSentence = NULL;
    string structure_key;
    string blockStartKey;
    string blockEndKey;
    bool closed;
    bool has_return_sentence;
    map<string, set<ResolvingItem*>> lvToLastWrittenKeys;
    set<string> lvKeysUpdatedByThisBlock100Percent;
    CodeStructure* parent = nullptr;
    bool isLoop = false;
    set<ResolvingItem*> unwrittenReadOfThisBlock;

    bool lvUpdatedByBlockStack100Percent(const string& lvKey);

    bool coverScope(CodeBlock* codeBlock);

    CodeBlock(CodeStructure* parent, const string& structureKey, bool closed);

    list<Sentence*> sentences;

    void append_structure(CodeStructure* codeStructure) override;

    void release() override;

    thread_local static map<string, map<string, CodeBlock*>> classKey2methodKey2codeBlock;

    static void releaseMethodCodeBlocks();

    static string makeStructureKey(const string& parentStructureKey, int sentenceIndex, int branchIndex, bool closed);
};


