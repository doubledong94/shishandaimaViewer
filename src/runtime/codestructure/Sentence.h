class Sentence : public CodeStructure {
public:
    static int FOR_INIT_SENT_INDEX;
    static string FOR_INIT_SENT_INDEX_STR;
    static int FOR_UPDATE_SENT_INDEX;
    int sentence_index = -1;
    string sentenceIndexStr = "";
    string sentenceStartKey;
    string sentenceEndKey;
    CodeStructure* parent;

    list<Relation *> relations;

    Sentence(CodeStructure *parent, const string &structureKey, int index);

    void markUnreadReturn(int calledReturnKeyType);

    void append_structure(CodeStructure *codeStructure) override;

    void release() override;

};


