class CodeStructure {
public:
    static const int STRUCTURE_TYPE_RELATION;
    static const int STRUCTURE_TYPE_SENTENCE;
    static const int STRUCTURE_TYPE_CODE_BLOCK;
    static const int STRUCTURE_TYPE_SPLIT_CODE_BLOCKS;
    static const int STRUCTURE_TYPE_LOOP_CODE_BLOCKS;
    int structure_type;

    virtual void append_structure(CodeStructure *codeStructure);

    virtual void release();
};


