#include "util/util.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "addressableInfo/AddressableInfo.h"
#include "runtime/codestructure/CodeStructure.h"
#include "runtime/codestructure/Relation.h"
#include "runtime/codestructure/Sentence.h"
#include "runtime/codestructure/CodeBlock.h"
#include "runtime/codestructure/SplitCodeBlocks.h"

void SplitCodeBlocks::append_structure(CodeStructure *codeStructure) {
    blocks.push_back(dynamic_cast<CodeBlock *>(codeStructure));
}

SplitCodeBlocks::SplitCodeBlocks(CodeStructure *parent, const string &structureKey, int index) : Sentence(parent, structureKey, index) {
    this->parent = parent;
    structure_type = STRUCTURE_TYPE_SPLIT_CODE_BLOCKS;
}

bool SplitCodeBlocks::isClosed() {
    bool closed = false;
    FOR_EACH_ITEM(blocks, if (item->closed) { return true; });
    return closed;
}

void SplitCodeBlocks::release() {
    for (auto &iter : blocks) {
        iter->release();
        delete iter;
    }
}

Loop::Loop(CodeStructure *parent, const string &structureKey, int index) : SplitCodeBlocks(parent, structureKey, index) {
    structure_type = STRUCTURE_TYPE_LOOP_CODE_BLOCKS;
}
