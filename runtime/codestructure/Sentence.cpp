#include "../../util/util.h"
#include "CodeStructure.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "Relation.h"
#include "Sentence.h"

void Sentence::append_structure(CodeStructure* codeStructure) {
    relations.push_back(dynamic_cast<Relation*> (codeStructure));
}

Sentence::Sentence(CodeStructure* parent, const string& structureKey, int index) {
    sentence_index = index;
    sentenceIndexStr = to_string(index);
    sentenceStartKey = structureKey + ";sent" + sentenceIndexStr + "start";
    sentenceEndKey = structureKey + ";sent" + sentenceIndexStr + "end";
    structure_type = STRUCTURE_TYPE_SENTENCE;
    if (parent != nullptr) {
        parent->append_structure(this);
    }
}

void Sentence::markUnreadReturn(int calledReturnKeyType) {
    set<Relation*> writtenReturnRelation;
    set<Relation*> readReturnRelation;
    for (auto& relation : relations) {
        if (relation->writen->keyType == calledReturnKeyType) {
            writtenReturnRelation.insert(relation);
        }
        if (relation->read->keyType == calledReturnKeyType) {
            readReturnRelation.insert(relation);
        }
    }
    for (auto& relation : writtenReturnRelation) {
        if (not readReturnRelation.count(relation)) {
            relation->read->reversedRef = true;
        }
    }
}

void Sentence::release() {
    FOR_EACH_ITEM(relations, item->release();delete item;);
    relations.clear();
}
