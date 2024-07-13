#ifndef JPARSER_PROLOGDATABASEGEN_H
#define JPARSER_PROLOGDATABASEGEN_H

class GenDataVisitor {
public:
    virtual void visitMethod(const string& methodKey, CodeBlock* methodBody, list<string>& prologLines);
    virtual void visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines);
    virtual void visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines);
    virtual void visitToConditionSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines);
    virtual void visitSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines);
    virtual void visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines);
};
class DataFlowVisitor : public GenDataVisitor {
public:
    thread_local static map<string, list<pair<string, string>>> dataStepRuntimes;
    thread_local static map<string, list<pair<string, string>>> dataOverrideRuntimes;

    void visitMethod(const string& methodKey, CodeBlock* methodBody, list<string>& prologLines) override;

    void beforeRunSplitCodeBlock(CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks);

    void afterRunSplitCodeBlock(CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks);

    void genDataFlowFromLastWrittenLvs(const string& methodKey, ResolvingItem* read, CodeBlock* codeBlock, list<string>& prologLines);

    void visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines) override;

    void visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) override;

    void visitSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) override;

    void visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) override;

    void addStepToParam(const string& methodKey, ResolvingItem* paramItem, list<string>& prologLines);
};
class LogicFlowVisitor : public GenDataVisitor {
public:
    void genToCondition(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines);

    void visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) override;

};
class TimingFlowVisitor : public GenDataVisitor {
public:
    thread_local static map<string, list<pair<string, string>>> timingStepRuntimes;
    thread_local static map<string, list<pair<string, string>>> timingOverrideRuntimes;

    void visitMethod(const string& methodKey, CodeBlock* methodBody, list<string>& prologLines) override;

    void visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines) override;

    void visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) override;

    void visitToConditionSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) override;

    void addTimingFlow(const string& methodKey, CodeBlock* codeBlock, ResolvingItem* item, list<string>& prologLines);
};
class ScopeFlowVisitor : public GenDataVisitor {
public:
    void visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) override;
    void visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) override;
};
class CodeOrderVisitor : public GenDataVisitor {
public:
    void visitMethod(const string& methodKey, CodeBlock* methodBody, list<string>& prologLines) override;
    void visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) override;
    void visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines) override;
    void visitSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) override;
};
class RuntimeKeyVisitor :public GenDataVisitor {
public:
    void visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) override;
    void visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) override;

};
class RuntimeReadVisitor :public GenDataVisitor {
public:
    void visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) override;

};
class RuntimeWriteVisitor :public GenDataVisitor {
public:
    void visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) override;

};

class PrologDataBaseGen {
public:
    static void init();

    static void genPrologDataBase(list<string>& prologLines);
};


#endif //JPARSER_PROLOGDATABASEGEN_H
