class Sentence : public CodeStructure {
public:
    int sentence_index = -1;
    string sentenceIndexStr = "";
    string sentenceStartKey;
    string sentenceEndKey;

    list<Relation *> relations;

    Sentence(CodeStructure *parent, const string &structureKey, int index);

    void append_structure(CodeStructure *codeStructure) override;

    void release() override;

};


