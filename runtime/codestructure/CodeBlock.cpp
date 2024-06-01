#include "../../util/util.h"
#include "CodeStructure.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "Relation.h"
#include "Sentence.h"
#include "CodeBlock.h"
#include "SplitCodeBlocks.h"


thread_local map<string, map<string, CodeBlock *>> CodeBlock::classKey2methodKey2codeBlock;

void CodeBlock::append_structure(CodeStructure *codeStructure) {
    sentences.push_back(dynamic_cast<Sentence *>(codeStructure));
}

CodeBlock::CodeBlock(CodeStructure *parent, const string &structureKey, bool closed) {
    if (parent != nullptr) {
        parent->append_structure(this);
        this->parent = parent;
    }
    structure_type = STRUCTURE_TYPE_CODE_BLOCK;
    structure_key = structureKey;
    blockStartKey = structureKey + ";blockStart";
    blockEndKey = structureKey + ";blockEnd";
    this->closed = closed;
    has_return_sentence = false;
}

void CodeBlock::release() {
    lvToLastWrittenKeys.clear();
    updatedLvKeys.clear();
    for (auto &iter : sentences) {
        iter->release();
        delete iter;
    }
}

void CodeBlock::releaseMethodCodeBlocks() {
    for (auto &classIter :CodeBlock::classKey2methodKey2codeBlock) {
        for (auto &methodIter:classIter.second) {
            methodIter.second->release();
            delete methodIter.second;
        }
    }
    CodeBlock::classKey2methodKey2codeBlock.clear();
}

string CodeBlock::makeStructureKey(const string &parentStructureKey, int sentenceIndex, int branchIndex, bool closed) {
    return parentStructureKey + ":" + to_string(sentenceIndex) + "," + to_string(branchIndex) + "," + to_string(closed ? 1 : 0);
}
