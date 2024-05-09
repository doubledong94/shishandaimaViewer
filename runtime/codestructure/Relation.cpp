#include "../../util/util.h"
#include "../../addressableInfo/GlobalInfo.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "../../GraphAttributes.h"
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
    orderPrologAdded = false;
}

void ResolvingItem::set(const string& variableKey, TypeInfo* typeInfo, const string& structureKey, const string& sentenceIndex, const string& indexInsideExp, int keyType, const string& extraInfo) {
    this->variableKey = variableKey;
    this->typeInfo = typeInfo;
    this->structureKey = structureKey;
    this->sentenceIndex = sentenceIndex;
    this->keyType = keyType;
    this->indexInsideStatement = indexInsideExp;
    this->extraInfoForOptr = extraInfo;
    this->runtimeKey = variableKey;
    this->runtimeKey += '(';
    this->runtimeKey += structureKey;
    this->runtimeKey += ';';
    this->runtimeKey += sentenceIndex;
    this->runtimeKey += ';';
    this->runtimeKey += indexInsideStatement;
    this->runtimeKey += ')';
    if (typeInfo and (keyType == GlobalInfo::KEY_TYPE_CLASS or
        keyType == GlobalInfo::KEY_TYPE_FIELD or
        keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN or
        keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER
        )) {
        this->referenceKey = typeInfo->typeKey + "-reference";
    }
    this->referenceRuntimeKey = referenceKey;
    this->referenceRuntimeKey += '(';
    this->referenceRuntimeKey += structureKey;
    this->referenceRuntimeKey += ';';
    this->referenceRuntimeKey += sentenceIndex;
    this->referenceRuntimeKey += ';';
    this->referenceRuntimeKey += indexInsideStatement;
    this->referenceRuntimeKey += ')';
}

static int relationCount = 0;
ResolvingItem* ResolvingItem::getInstance2(const string& variableKey, TypeInfo* typeInfo, const string& structureKey, const string& sentenceIndex, const string& indexInsideExp, int keyType, const string& extraInfo) {
    relationCount++;
    ResolvingItem* ret = getInstance();
    ret->set(variableKey, typeInfo, structureKey, sentenceIndex, indexInsideExp, keyType, extraInfo);
    return ret;
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
    runtimeAdded = true;
}

void ResolvingItem::addRuntimeReadProlog(string(*act)(const string&, const string&, const string&), const string& methodKey, list<string>& prologLines) {
    if (runtimeReadAdded) {
        return;
    }
    prologLines.emplace_back(act(methodKey, variableKey, runtimeKey));
    if (referencedBy != nullptr) {
        referencedBy->addRuntimeReadProlog(act, methodKey, prologLines);
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
        prologLines.emplace_back(act(methodKey, referencedBy->runtimeKey, referencedBy->referenceRuntimeKey));
        prologLines.emplace_back(act(methodKey, referencedBy->referenceRuntimeKey, runtimeKey));
        referencedBy->addReferenceProlog(act, methodKey, prologLines);
    }
    referenceAdded = true;
}

Relation::Relation(CodeStructure* parent) {
    if (parent != nullptr) {
        parent->append_structure(this);
    }
    structure_type = STRUCTURE_TYPE_RELATION;
}

Relation::Relation(CodeStructure* parent, ResolvingItem* r, ResolvingItem* w) {
    structure_type = STRUCTURE_TYPE_RELATION;
    read = r;
    writen = w;
    if (parent != nullptr) {
        parent->append_structure(this);
    }
}
