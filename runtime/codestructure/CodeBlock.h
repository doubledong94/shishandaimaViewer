
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
    map<string, set<string>> lvToLastWrittenKeys;
    set<string> updatedLvKeys;
    CodeStructure* parent = nullptr;

    CodeBlock(CodeStructure* parent, const string& structureKey, bool closed);

    list<Sentence*> sentences;

    void append_structure(CodeStructure* codeStructure) override;

    void release() override;

    thread_local static map<string, map<string, CodeBlock*>> classKey2methodKey2codeBlock;

    static void releaseMethodCodeBlocks();

    static string makeStructureKey(const string& parentStructureKey, int sentenceIndex, int branchIndex, bool closed);
};


