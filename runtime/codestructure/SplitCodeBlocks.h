class SplitCodeBlocks : public Sentence {
public:
    list<CodeBlock *> blocks;
    int splitType;
    const static int SPLIT_TYP_IF = 1;
    const static int SPLIT_TYPE_SWITCH = 2;
    const static int SPLIT_TYPE_TRY = 3;
    CodeStructure *parent = nullptr;

    SplitCodeBlocks(CodeStructure *parent, const string &structureKey, int index);

    void append_structure(CodeStructure *codeStructure) override;

    bool isClosed();

    void release() override;
};


class Loop : public SplitCodeBlocks {
public:
    Loop(CodeStructure *parent, const string &structureKey, int index);
};
