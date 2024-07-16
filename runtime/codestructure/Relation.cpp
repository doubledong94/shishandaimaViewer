#include "../../util/util.h"
#include "../../addressableInfo/GlobalInfo.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "CodeStructure.h"
#include "Relation.h"

void ResolvingItem::reset() {
    hasReturnValue = false;
    variableKey.clear();
    typeInfo = NULL;
    typeArgs.clear();
    structureKey.clear();
    sentenceIndex.clear();
    indexInsideStatement.clear();
    keyType = -1;
    referencedBy = nullptr;
    calledMethod = nullptr;
    calledReturn = nullptr;
    indexedBy = nullptr;
    extraInfoForOptr.clear();
    runtimeKey.clear();
    referenceKey.clear();
    referenceRuntimeKey.clear();
    extraInfoMethodKey.clear();
    extraInfoParameterKey.clear();
    extraInfoReturnKey.clear();
    runtimeAdded = false;
    runtimeReadAdded = false;
    runtimeWriteAdded = false;
    conditionToAdded = false;
    referenceAdded = false;
    indexAdded = false;
    orderPrologAdded = false;
    readFromLastWriteAdded = false;
    reversedRef = false;
}

void ResolvingItem::set(const string& variableKey, TypeInfo* typeInfo, const string& structureKey, const string& sentenceIndex, const string& indexInsideExp, int keyType, const string& extraInfo) {
    this->variableKey = variableKey;
    this->typeInfo = typeInfo;
    this->structureKey = structureKey;
    this->sentenceIndex = sentenceIndex;
    this->keyType = keyType;
    this->indexInsideStatement = indexInsideExp;
    this->extraInfoForOptr = extraInfo;
    this->runtimeKey = makeRuntimeKey(variableKey, structureKey, sentenceIndex, indexInsideStatement);
    if (typeInfo) {
        this->referenceKey = typeInfo->typeKey + "-reference";
        this->referenceRuntimeKey = makeRuntimeKey(referenceKey, structureKey, sentenceIndex, indexInsideStatement);
    }
}

thread_local list<ResolvingItem*> ResolvingItem::itemsOutOfPool;

ResolvingItem* ResolvingItem::getInstance2() {
    auto ret = getInstance();
    itemsOutOfPool.push_back(ret);
    return ret;
}

static int relationCount = 0;
ResolvingItem* ResolvingItem::getInstance2(const string& variableKey, TypeInfo* typeInfo, const string& structureKey, const string& sentenceIndex, const string& indexInsideExp, int keyType, const string& extraInfo) {
    relationCount++;
    ResolvingItem* ret = getInstance();
    ret->set(variableKey, typeInfo, structureKey, sentenceIndex, indexInsideExp, keyType, extraInfo);
    itemsOutOfPool.push_back(ret);
    return ret;
}

void ResolvingItem::returnAllToPool() {
    for (auto& item : itemsOutOfPool) {
        returnToPool(item);
    }
    itemsOutOfPool.clear();
}

void ResolvingItem::addRuntimeProlog(string(*act)(const string& methodKey, const string& varKey, const string& runtimeKey, int keyType), const string& methodKey, list<string>& prologLines) {
    if (runtimeAdded) {
        return;
    }
    if (GlobalInfo::isOptrKeyType(keyType)) {
        prologLines.emplace_back(act(methodKey, extraInfoForOptr, runtimeKey, keyType));
    } else {
        prologLines.emplace_back(act(methodKey, variableKey, runtimeKey, keyType));
    }
    if (referencedBy != nullptr) {
        prologLines.emplace_back(act(methodKey, referencedBy->referenceKey, referencedBy->referenceRuntimeKey, GlobalInfo::KEY_TYPE_REFERENCE));
        referencedBy->addRuntimeProlog(act, methodKey, prologLines);
    }
    if (indexedBy != nullptr) {
        prologLines.emplace_back(act(methodKey, GlobalInfo::GLOBAL_KEY_OPTR_INDEX_RETURN, makeRuntimeKey(GlobalInfo::GLOBAL_KEY_OPTR_INDEX_RETURN, structureKey, sentenceIndex, indexInsideStatement), GlobalInfo::KEY_TYPE_INDEX));
        indexedBy->addRuntimeProlog(act, methodKey, prologLines);
    }
    runtimeAdded = true;
}

string ResolvingItem::makeRuntimeKey(const string& key, const string& structureKey, const string& sentenceIndex, const string& indexInsideStatement) {
    return key + "(" + structureKey + ";" + sentenceIndex + ";" + indexInsideStatement + ")";
}

ResolvingItem* ResolvingItem::getRefedByRecur() {
    if (referencedBy) {
        return referencedBy->getRefedByRecur();
    } else {
        return this;
    }
}

ResolvingItem* ResolvingItem::getCalledMethodIfExists() {
    if (calledMethod) {
        return calledMethod;
    } else {
        return this;
    }
}

void ResolvingItem::collectRefedCalledReturn(std::set<ResolvingItem*>& refedReturn) {
    if (calledReturn) {
        refedReturn.insert(calledReturn);
    }
    if (referencedBy) {
        referencedBy->collectRefedCalledReturn(refedReturn);
    }
}

void ResolvingItem::setReversedRefRecur(bool reversedRef) {
    this->reversedRef = reversedRef;
    if (referencedBy) {
        referencedBy->setReversedRefRecur(reversedRef);
    }
}

void ResolvingItem::addRuntimeReadProlog(string(*act)(const string&, const string&, const string&), const string& methodKey, list<string>& prologLines) {
    if (runtimeReadAdded) {
        return;
    }
    prologLines.emplace_back(act(methodKey, variableKey, runtimeKey));
    if (referencedBy != nullptr) {
        referencedBy->addRuntimeReadProlog(act, methodKey, prologLines);
    }
    if (indexedBy != nullptr) {
        indexedBy->addRuntimeReadProlog(act, methodKey, prologLines);
    }
    runtimeReadAdded = true;
}

void ResolvingItem::addRuntimeWritenProlog(string(*act)(const string&, const string&, const string&), const string& methodKey, list<string>& prologLines) {
    if (runtimeWriteAdded) {
        return;
    }
    prologLines.emplace_back(act(methodKey, variableKey, runtimeKey));
    runtimeWriteAdded = true;
}

void ResolvingItem::addConditionToProlog(string(*act)(const string&, const string&, const string&), const string& methodKey, const string& conditionRuntimeKey, list<string>& prologLines) {
    if (conditionToAdded) {
        return;
    }
    prologLines.emplace_back(act(methodKey, conditionRuntimeKey, runtimeKey));
    conditionToAdded = true;
}

void ResolvingItem::addReferenceProlog(string(*act)(const string&, const string&, const string&), const string& methodKey, list<string>& prologLines) {
    if (referenceAdded) {
        return;
    }
    if (referencedBy != nullptr) {
        if (reversedRef) {
            prologLines.emplace_back(act(methodKey, runtimeKey, referencedBy->referenceRuntimeKey));
            prologLines.emplace_back(act(methodKey, referencedBy->referenceRuntimeKey, referencedBy->runtimeKey));
        } else {
            prologLines.emplace_back(act(methodKey, referencedBy->runtimeKey, referencedBy->referenceRuntimeKey));
            prologLines.emplace_back(act(methodKey, referencedBy->referenceRuntimeKey, runtimeKey));
        }
        referencedBy->addReferenceProlog(act, methodKey, prologLines);
    }
    referenceAdded = true;
}

void ResolvingItem::addIndexProlog(string(*act)(const string&, const string&, const string&), const string& methodKey, list<string>& prologLines) {
    if (indexAdded) {
        return;
    }
    if (indexedBy != nullptr) {
        string indexRuntimeKey = makeRuntimeKey(GlobalInfo::GLOBAL_KEY_OPTR_INDEX_RETURN, structureKey, sentenceIndex, indexInsideStatement);
        prologLines.emplace_back(act(methodKey, indexedBy->runtimeKey, indexRuntimeKey));
        prologLines.emplace_back(act(methodKey, indexRuntimeKey, runtimeKey));
        indexedBy->addIndexProlog(act, methodKey, prologLines);
    }
    indexAdded = true;
}


Relation::Relation(CodeStructure* parent) {
    if (parent != nullptr) {
        parent->append_structure(this);
    }
    structure_type = STRUCTURE_TYPE_RELATION;
}

Relation::Relation(CodeStructure* parent, ResolvingItem* r, ResolvingItem* w, bool isAssignRelation) {
    if (r->keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD and w->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
        w->calledMethod = r;
        r->calledReturn = w;
    }
    structure_type = STRUCTURE_TYPE_RELATION;
    read = r;
    writen = w;
    this->isAssignRelation = isAssignRelation;
    writen->setReversedRefRecur(isAssignRelation);
    if (parent != nullptr) {
        parent->append_structure(this);
    }
}
