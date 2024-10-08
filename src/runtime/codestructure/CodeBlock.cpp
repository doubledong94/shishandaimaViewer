#include "util/util.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "addressableInfo/AddressableInfo.h"
#include "runtime/codestructure/CodeStructure.h"
#include "runtime/codestructure/Relation.h"
#include "runtime/codestructure/Sentence.h"
#include "runtime/codestructure/CodeBlock.h"
#include "runtime/codestructure/SplitCodeBlocks.h"


thread_local map<string, map<string, CodeBlock*>> CodeBlock::classKey2methodKey2codeBlock;

void CodeBlock::append_structure(CodeStructure* codeStructure) {
    sentences.push_back(dynamic_cast<Sentence*>(codeStructure));
}

CodeBlock::CodeBlock(CodeStructure* parent, const string& structureKey, bool closed) {
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
    lvKeysUpdatedByThisBlock100Percent.clear();
    for (auto& iter : sentences) {
        iter->release();
        delete iter;
    }
}

void CodeBlock::releaseMethodCodeBlocks() {
    for (auto& classIter : CodeBlock::classKey2methodKey2codeBlock) {
        for (auto& methodIter : classIter.second) {
            methodIter.second->release();
            delete methodIter.second;
        }
    }
    CodeBlock::classKey2methodKey2codeBlock.clear();
}

string CodeBlock::makeStructureKey(const string& parentStructureKey, int sentenceIndex, int branchIndex, bool closed) {
    return parentStructureKey + ":" + to_string(sentenceIndex) + "," + to_string(branchIndex) + "," + to_string(closed ? 1 : 0);
}

bool CodeBlock::lvUpdatedByBlockStack100Percent(const string& lvKey) {
    if (lvKeysUpdatedByThisBlock100Percent.count(lvKey)) {
        return true;
    }
    if (parent) {
        SplitCodeBlocks* p = dynamic_cast<SplitCodeBlocks*> (parent);
        if (p->parent) {
            CodeBlock* pp = dynamic_cast<CodeBlock*> (p->parent);
            if (pp->lvUpdatedByBlockStack100Percent(lvKey)) {
                return true;
            }
        }
    }
    return false;
}

bool CodeBlock::coverScope(CodeBlock* codeBlock) {
    if (codeBlock == this) {
        return true;
    }
    for (auto& sentence : sentences) {
        if (sentence->structure_type == CodeStructure::STRUCTURE_TYPE_SPLIT_CODE_BLOCKS or sentence->structure_type == CodeStructure::STRUCTURE_TYPE_LOOP_CODE_BLOCKS) {
            auto splits = dynamic_cast<SplitCodeBlocks*>(sentence);
            for (auto& splitI : splits->blocks) {
                if (splitI->coverScope(codeBlock)) {
                    return true;
                }
            }
        }
    }
    return false;
}
