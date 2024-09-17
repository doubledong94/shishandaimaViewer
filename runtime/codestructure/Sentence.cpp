#include "util/util.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "addressableInfo/AddressableInfo.h"
#include "runtime/codestructure/CodeStructure.h"
#include "runtime/codestructure/Relation.h"
#include "runtime/codestructure/Sentence.h"

int Sentence::FOR_INIT_SENT_INDEX = -1000000;
string Sentence::FOR_INIT_SENT_INDEX_STR = "-1000000";
int Sentence::FOR_UPDATE_SENT_INDEX = 1000000;

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
    this->parent = parent;
}

void Sentence::markUnreadReturn(int calledReturnKeyType) {
    set<ResolvingItem*> allWrittenItems;
    set<ResolvingItem*> allReadItems;
    for (auto& relation : relations) {
        allWrittenItems.insert(relation->writen);
        allReadItems.insert(relation->read);
        relation->read->collectRefedByAndIndexedBy(allReadItems);
    }
    for (auto& writtenItem : allWrittenItems) {
        if (not allReadItems.count(writtenItem)) {
            writtenItem->setReversedRefRecur(true);
        }
    }
}

void Sentence::release() {
    FOR_EACH_ITEM(relations, item->release();delete item;);
    relations.clear();
}
