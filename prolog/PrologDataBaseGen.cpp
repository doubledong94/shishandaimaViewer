#include "../util/util.h"
#include "../../addressableInfo/GlobalInfo.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "../runtime/codestructure/CodeStructure.h"
#include "../runtime/codestructure/Relation.h"
#include "../runtime/codestructure/Sentence.h"
#include "../runtime/codestructure/CodeBlock.h"
#include "../runtime/codestructure/SplitCodeBlocks.h"
#include "SWI-cpp2.h"
#include "../../error/ErrorManager.h"
#include "PrologConstructor.h"
#include "PrologDataBaseGen.h"

static DataFlowVisitor* dataFlowVisitor = NULL;
static LogicFlowVisitor* logicFlowVisitor = NULL;
static TimingFlowVisitor* timingFlowVisitor = NULL;
static ScopeFlowVisitor* scopeFlowVisitor = NULL;
static CodeOrderVisitor* codeOrderVisitor = NULL;
static RuntimeKeyVisitor* runtimeKeyVisitor = NULL;
static RuntimeReadVisitor* runtimeReadVisitor = NULL;
static RuntimeWriteVisitor* runtimeWriteVisitor = NULL;

thread_local map<string, list<pair<string, string>>> DataFlowVisitor::dataStepRuntimes;
thread_local map<string, list<pair<string, string>>> TimingFlowVisitor::timingStepRuntimes;
thread_local map<string, list<pair<string, string>>> DataFlowVisitor::dataOverrideRuntimes;
thread_local map<string, list<pair<string, string>>> TimingFlowVisitor::timingOverrideRuntimes;
thread_local map<string, list<ResolvingItem*>> DataFlowVisitor::methodToWritenItem;

#define ITER_ALL_METHOD(RAW_DATA,METHOD,PROLOG_LINES) for(auto &classIter: RAW_DATA){ for(auto &methodIter: classIter.second) {METHOD->visitMethod(methodIter.first, methodIter.second, PROLOG_LINES);}}

void PrologDataBaseGen::init() {
    dataFlowVisitor = new DataFlowVisitor();
    logicFlowVisitor = new LogicFlowVisitor();
    timingFlowVisitor = new TimingFlowVisitor();
    scopeFlowVisitor = new ScopeFlowVisitor();
    codeOrderVisitor = new CodeOrderVisitor();
    runtimeKeyVisitor = new RuntimeKeyVisitor();
    runtimeReadVisitor = new RuntimeReadVisitor();
    runtimeWriteVisitor = new RuntimeWriteVisitor();
}

void PrologDataBaseGen::genPrologDataBase(list<string>& prologLines) {
    prologLines.emplace_back("\% data flow start");
    ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, dataFlowVisitor, prologLines);
    prologLines.emplace_back("\% logic flow start");
    ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, logicFlowVisitor, prologLines);
    prologLines.emplace_back("\% timing flow start");
    ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, timingFlowVisitor, prologLines);
    prologLines.emplace_back("\% scope flow start");
    ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, scopeFlowVisitor, prologLines);
    // prologLines.emplace_back("\% code order start");
    // ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, codeOrderVisitor, prologLines);
    prologLines.emplace_back("\% runtime key start");
    for (auto& mkAndStep : dataFlowVisitor->dataStepRuntimes) {
        for (auto& step : mkAndStep.second) {
            prologLines.emplace_back(CompoundTerm::getRuntimeFact(mkAndStep.first, step.first, step.second, GlobalInfo::KEY_TYPE_DATA_STEP));
        }
    }
    dataFlowVisitor->dataStepRuntimes.clear();
    for (auto& mkAndStep : dataFlowVisitor->dataOverrideRuntimes) {
        for (auto& step : mkAndStep.second) {
            prologLines.emplace_back(CompoundTerm::getRuntimeFact(mkAndStep.first, step.first, step.second, GlobalInfo::KEY_TYPE_DATA_OVERRIDE));
        }
    }
    dataFlowVisitor->dataOverrideRuntimes.clear();
    for (auto& mkAndStep : timingFlowVisitor->timingStepRuntimes) {
        for (auto& step : mkAndStep.second) {
            prologLines.emplace_back(CompoundTerm::getRuntimeFact(mkAndStep.first, step.first, step.second, GlobalInfo::KEY_TYPE_TIMING_STEP));
        }
    }
    timingFlowVisitor->timingStepRuntimes.clear();
    for (auto& mkAndStep : timingFlowVisitor->timingOverrideRuntimes) {
        for (auto& step : mkAndStep.second) {
            prologLines.emplace_back(CompoundTerm::getRuntimeFact(mkAndStep.first, step.first, step.second, GlobalInfo::KEY_TYPE_TIMING_OVERRIDE));
        }
    }
    timingFlowVisitor->timingOverrideRuntimes.clear();
    ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, runtimeKeyVisitor, prologLines);
    prologLines.emplace_back("\% is write start");
    for (auto& mkAndWriten : dataFlowVisitor->methodToWritenItem) {
        for (auto& writen : mkAndWriten.second) {
            prologLines.emplace_back(CompoundTerm::getIsWriteFact(mkAndWriten.first, writen->runtimeKey));
        }
    }
    dataFlowVisitor->methodToWritenItem.clear();
    // prologLines.emplace_back("\% runtime read start");
    // ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, runtimeReadVisitor, prologLines);
    // prologLines.emplace_back("\% runtime write start");
    // ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, runtimeWriteVisitor, prologLines);
    ResolvingItem::returnAllToPool();
}

void DataFlowVisitor::visitMethod(const string& methodKey, CodeBlock* methodBody, list<string>& prologLines) {
    dataStepRuntimes[methodKey] = list<pair<string, string>>();
    dataOverrideRuntimes[methodKey] = list<pair<string, string>>();
    methodToWritenItem[methodKey] = list<ResolvingItem*>();
    GenDataVisitor::visitMethod(methodKey, methodBody, prologLines);
}

void DataFlowVisitor::beforeRunSplitCodeBlock(CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks) {
    FOR_EACH_ITEM(splitCodeBlocks->blocks, item->lvToLastWrittenKeys = superCodeBlock->lvToLastWrittenKeys;);
}

void DataFlowVisitor::afterRunSplitCodeBlock(CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks) {
    if (splitCodeBlocks->isClosed()) {
        for (auto& lv2lastWriteKeys : superCodeBlock->lvToLastWrittenKeys) {
            bool lvIsUpdatedByEveryBranch = splitCodeBlocks->blocks.size() > 0;
            FOR_EACH_ITEM(splitCodeBlocks->blocks, if (!item->lvKeysUpdatedByThisBlock100Percent.count(lv2lastWriteKeys.first) and not item->has_return_sentence) { lvIsUpdatedByEveryBranch = false; });
            if (lvIsUpdatedByEveryBranch) {
                superCodeBlock->lvToLastWrittenKeys[lv2lastWriteKeys.first].clear();
                superCodeBlock->lvKeysUpdatedByThisBlock100Percent.insert(lv2lastWriteKeys.first);
            }
        }
    }
    for (CodeBlock* subCodeBlock : splitCodeBlocks->blocks) {
        if (subCodeBlock->has_return_sentence) {
            continue;
        }
        for (auto& lv2lastWriteKeys : subCodeBlock->lvToLastWrittenKeys) {
            if (superCodeBlock->lvToLastWrittenKeys.count(lv2lastWriteKeys.first) > 0) {
                FOR_EACH_ITEM(lv2lastWriteKeys.second, superCodeBlock->lvToLastWrittenKeys[lv2lastWriteKeys.first].insert(item););
            }
        }
        for (auto& unwrittenRead : subCodeBlock->unwrittenReadOfThisBlock) {
            superCodeBlock->unwrittenReadOfThisBlock.insert(unwrittenRead);
        }
    }
}

void DataFlowVisitor::visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines) {
    beforeRunSplitCodeBlock(superCodeBlock, splitCodeBlocks);
    GenDataVisitor::visitSplitCodeBlock(methodKey, superCodeBlock, splitCodeBlocks, prologLines);
    afterRunSplitCodeBlock(superCodeBlock, splitCodeBlocks);
}

void DataFlowVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    auto& read = relation->read;
    auto& writen = relation->writen;
    // data flow from lvToLastWrittenKeys
    genDataFlowFromLastWrittenLvs(methodKey, read, codeBlock, prologLines);
    if (writen->referencedBy and writen->reversedRef and writen->getRefedByRecur()->keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER) {
        addStepToParam(methodKey, writen->getRefedByRecur(), prologLines);
    }
    // data flow of this relation
    prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, read->runtimeKey, writen->runtimeKey));
    if (writen->keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE or writen->keyType == GlobalInfo::KEY_TYPE_FIELD) {
        methodToWritenItem[methodKey].push_back(writen);
    }
    // data flow of step
    // called param -> step/override
    if (read->keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER) {
        string stepKey = AddressableInfo::makeStepKey(read->variableKey);
        string stepRuntime = ResolvingItem::makeRuntimeKey(stepKey, read->structureKey, read->sentenceIndex, read->indexInsideStatement);
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, read->runtimeKey, stepRuntime));
        dataStepRuntimes[methodKey].push_back({ stepKey,stepRuntime });

        string overrideKey = AddressableInfo::makeOverrideKey(read->variableKey);
        string overrideRuntime = ResolvingItem::makeRuntimeKey(overrideKey, read->structureKey, read->sentenceIndex, read->indexInsideStatement);
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, read->runtimeKey, overrideRuntime));
        dataOverrideRuntimes[methodKey].push_back({ overrideKey,overrideRuntime });
    }
    // step/override -> called return
    if (writen->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
        string stepKey = AddressableInfo::makeStepKey(writen->variableKey);
        string stepRuntime = ResolvingItem::makeRuntimeKey(stepKey, writen->structureKey, writen->sentenceIndex, writen->indexInsideStatement);
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, stepRuntime, writen->runtimeKey));
        dataStepRuntimes[methodKey].push_back({ stepKey,stepRuntime });

        string overrideKey = AddressableInfo::makeOverrideKey(writen->variableKey);
        string overrideRuntime = ResolvingItem::makeRuntimeKey(overrideKey, writen->structureKey, writen->sentenceIndex, writen->indexInsideStatement);
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, overrideRuntime, writen->runtimeKey));
        dataOverrideRuntimes[methodKey].push_back({ overrideKey,overrideRuntime });
    }
    // ... -> return -> step/override
    if (writen->keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN) {
        string stepKey = AddressableInfo::makeStepKey(writen->variableKey);
        string stepRuntime = ResolvingItem::makeRuntimeKey(stepKey, writen->structureKey, writen->sentenceIndex, writen->indexInsideStatement);
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, writen->runtimeKey, stepRuntime));
        dataStepRuntimes[methodKey].push_back({ stepKey,stepRuntime });

        string overrideKey = AddressableInfo::makeOverrideKey(writen->variableKey);
        string overrideRuntime = ResolvingItem::makeRuntimeKey(overrideKey, writen->structureKey, writen->sentenceIndex, writen->indexInsideStatement);
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, writen->runtimeKey, overrideRuntime));
        dataOverrideRuntimes[methodKey].push_back({ overrideKey,overrideRuntime });
    }
    // mark local variable and make written history
    if (writen->allowWrittenHistory()) {
        if (writen->indexedBy) {
            if (not codeBlock->lvToLastWrittenKeys.count(writen->variableKey)) {
                codeBlock->lvToLastWrittenKeys[writen->variableKey] = set<ResolvingItem*>();
            }
            codeBlock->lvToLastWrittenKeys[writen->variableKey].insert(writen);
        } else {
            codeBlock->lvToLastWrittenKeys[writen->variableKey] = set<ResolvingItem*>();
            codeBlock->lvToLastWrittenKeys[writen->variableKey].insert(writen);
            codeBlock->lvKeysUpdatedByThisBlock100Percent.insert(writen->variableKey);
        }
    }
}

void DataFlowVisitor::genDataFlowFromLastWrittenLvs(const string& methodKey, ResolvingItem* read, CodeBlock* codeBlock, list<string>& prologLines) {
    if (read->readFromLastWriteAdded or (read->reversedRef and read->referencedBy)) {
        return;
    }
    read->readFromLastWriteAdded = true;
    bool isReadParam = read->keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER;
    if (read->allowWrittenHistory()) {
        if (codeBlock->lvToLastWrittenKeys.count(read->variableKey)) {
            FOR_EACH_ITEM(codeBlock->lvToLastWrittenKeys[read->variableKey], prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, item->runtimeKey, read->runtimeKey)););
            if (isReadParam and not codeBlock->lvUpdatedByBlockStack100Percent(read->variableKey)) {
                // step -> param -> ...
                addStepToParam(methodKey, read, prologLines);
            }
            bool writtenAllFromOuterScope = true;
            for (auto& written : codeBlock->lvToLastWrittenKeys[read->variableKey]) {
                if (read->coverScope(written) and written->sentenceIndex != Sentence::FOR_INIT_SENT_INDEX_STR) {
                    writtenAllFromOuterScope = false;
                    break;
                }
            }
            if (writtenAllFromOuterScope) {
                codeBlock->unwrittenReadOfThisBlock.insert(read);
            }
        } else {
            if (isReadParam) {
                // step -> param -> ...
                addStepToParam(methodKey, read, prologLines);
            } else if (read->keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE) {
                spdlog::get(ErrorManager::DebugTag)->warn("local variable {} read before write in {}", read->variableKey, methodKey);
            }
            codeBlock->unwrittenReadOfThisBlock.insert(read);
        }
    }
    if (read->referencedBy) {
        genDataFlowFromLastWrittenLvs(methodKey, read->referencedBy, codeBlock, prologLines);
    }
    if (read->indexedBy) {
        genDataFlowFromLastWrittenLvs(methodKey, read->indexedBy, codeBlock, prologLines);
    }
}

void DataFlowVisitor::visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    if (codeBlock->toConditionValue) {
        genDataFlowFromLastWrittenLvs(methodKey, codeBlock->toConditionValue, codeBlock, prologLines);
    }
    GenDataVisitor::visitCodeBlock(methodKey, codeBlock, prologLines);
    // add feedback data flow for loops
    if (codeBlock->isLoop) {
        for (auto* read : codeBlock->unwrittenReadOfThisBlock) {
            if (codeBlock->lvToLastWrittenKeys.count(read->variableKey)) {
                for (auto* written : codeBlock->lvToLastWrittenKeys[read->variableKey]) {
                    if (written->happenLaterThan(read)) {
                        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, written->runtimeKey, read->runtimeKey));
                    }
                }
            }
        }
    }
}

void DataFlowVisitor::visitSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) {
    sentence->markUnreadReturn(GlobalInfo::KEY_TYPE_CALLED_RETURN);
    GenDataVisitor::visitSentence(methodKey, codeBlock, sentence, prologLines);
    for (auto& relation : sentence->relations) {
        auto& writen = relation->writen;
        if (writen->reversedRef and writen->referencedBy) {
            auto referencedBy = writen->getRefedByRecur();
            if (referencedBy->allowWrittenHistory()) {
                genDataFlowFromLastWrittenLvs(methodKey, referencedBy, codeBlock, prologLines);
                codeBlock->lvToLastWrittenKeys[referencedBy->variableKey] = set<ResolvingItem*>();
                codeBlock->lvToLastWrittenKeys[referencedBy->variableKey].insert(referencedBy);
            }
        }
    }
}

void DataFlowVisitor::addStepToParam(const string& methodKey, ResolvingItem* paramItem, list<string>& prologLines) {
    string stepKey = AddressableInfo::makeStepKey(paramItem->variableKey);
    string stepRuntimeKey = ResolvingItem::makeRuntimeKey(stepKey, paramItem->structureKey, paramItem->sentenceIndex, paramItem->indexInsideStatement);
    prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, stepRuntimeKey, paramItem->runtimeKey));
    dataStepRuntimes[methodKey].push_back({ stepKey,stepRuntimeKey });

    string overrideKey = AddressableInfo::makeOverrideKey(paramItem->variableKey);
    string overrideRuntimeKey = ResolvingItem::makeRuntimeKey(overrideKey, paramItem->structureKey, paramItem->sentenceIndex, paramItem->indexInsideStatement);
    prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, overrideRuntimeKey, paramItem->runtimeKey));
    dataOverrideRuntimes[methodKey].push_back({ overrideKey,overrideRuntimeKey });
}

void LogicFlowVisitor::genToCondition(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    // variable to condition
    if (codeBlock->toConditionValue) {
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, codeBlock->toConditionValue->runtimeKey, codeBlock->conditionItem->runtimeKey));
    }
    // else to condition
    if (codeBlock->elseConditionValue) {
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, codeBlock->elseConditionValue->runtimeKey, codeBlock->elseValue->runtimeKey));
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, codeBlock->elseValue->runtimeKey, codeBlock->conditionItem->runtimeKey));
    }
}

void LogicFlowVisitor::visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    genToCondition(methodKey, codeBlock, prologLines);
    for (auto* sentence : codeBlock->sentences) {
        int structureType = sentence->structure_type;
        if (structureType == CodeStructure::STRUCTURE_TYPE_SPLIT_CODE_BLOCKS or structureType == CodeStructure::STRUCTURE_TYPE_LOOP_CODE_BLOCKS) {
            visitSplitCodeBlock(methodKey, codeBlock, dynamic_cast<SplitCodeBlocks*>(sentence), prologLines);
        }
    }
}

void TimingFlowVisitor::visitMethod(const string& methodKey, CodeBlock* methodBody, list<string>& prologLines) {
    timingStepRuntimes[methodKey] = list<pair<string, string>>();
    // step -> method
    string stepKey = AddressableInfo::makeStepKey(methodBody->conditionItem->variableKey);
    string stepRuntimeKey = ResolvingItem::makeRuntimeKey(stepKey, methodBody->conditionItem->structureKey, "-1", "-1");
    prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, stepRuntimeKey, methodBody->conditionItem->runtimeKey));
    timingStepRuntimes[methodKey].push_back({ stepKey,stepRuntimeKey });

    timingOverrideRuntimes[methodKey] = list<pair<string, string>>();
    // override -> method
    string overrideKey = AddressableInfo::makeOverrideKey(methodBody->conditionItem->variableKey);
    string overrideRuntimeKey = ResolvingItem::makeRuntimeKey(overrideKey, methodBody->conditionItem->structureKey, "-1", "-1");
    prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, overrideRuntimeKey, methodBody->conditionItem->runtimeKey));
    timingOverrideRuntimes[methodKey].push_back({ overrideKey,overrideRuntimeKey });

    GenDataVisitor::visitMethod(methodKey, methodBody, prologLines);
}

void TimingFlowVisitor::visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines) {
    for (auto* subCodeBlock : splitCodeBlocks->blocks) {
        // super condition to sub condition
        subCodeBlock->conditionItem->addConditionToProlog(CompoundTerm::getFlowFact, methodKey, superCodeBlock->conditionItem->runtimeKey, prologLines);
        visitCodeBlock(methodKey, subCodeBlock, prologLines);
    }
}

void TimingFlowVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    // called method -> step/override
    if (relation->read->keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD) {
        string stepKey = AddressableInfo::makeStepKey(relation->read->variableKey);
        string stepRuntimeKey = ResolvingItem::makeRuntimeKey(stepKey, relation->read->structureKey, relation->read->sentenceIndex, relation->read->indexInsideStatement);
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, relation->read->runtimeKey, stepRuntimeKey));
        timingStepRuntimes[methodKey].push_back({ stepKey,stepRuntimeKey });

        string overrideKey = AddressableInfo::makeOverrideKey(relation->read->variableKey);
        string overrideRuntimeKey = ResolvingItem::makeRuntimeKey(overrideKey, relation->read->structureKey, relation->read->sentenceIndex, relation->read->indexInsideStatement);
        prologLines.emplace_back(CompoundTerm::getFlowFact(methodKey, relation->read->runtimeKey, overrideRuntimeKey));
        timingOverrideRuntimes[methodKey].push_back({ overrideKey,overrideRuntimeKey });
    }
    addTimingFlow(methodKey, codeBlock, relation->read, prologLines);
    addTimingFlow(methodKey, codeBlock, relation->writen, prologLines);
}

void TimingFlowVisitor::visitToConditionSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) {
}

void TimingFlowVisitor::addTimingFlow(const string& methodKey, CodeBlock* codeBlock, ResolvingItem* item, list<string>& prologLines) {
    if (
        item->keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE or
        item->keyType == GlobalInfo::KEY_TYPE_FIELD or
        item->keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER or
        item->keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN or
        item->keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD or
        item->keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER or
        item->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN or
        item->keyType == GlobalInfo::KEY_TYPE_ERROR
        ) {
        item->addConditionToProlog(CompoundTerm::getFlowFact, methodKey, codeBlock->conditionItem->runtimeKey, prologLines);
    }
    if (item->referencedBy) {
        addTimingFlow(methodKey, codeBlock, item->referencedBy, prologLines);
    }
    if (item->indexedBy) {
        addTimingFlow(methodKey, codeBlock, item->indexedBy, prologLines);
    }
}

void ScopeFlowVisitor::visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    if (codeBlock->toConditionValue) {
        codeBlock->toConditionValue->addReferenceProlog(CompoundTerm::getFlowFact, methodKey, prologLines);
        codeBlock->toConditionValue->addIndexProlog(CompoundTerm::getFlowFact, methodKey, prologLines);
    }
    GenDataVisitor::visitCodeBlock(methodKey, codeBlock, prologLines);
}

void ScopeFlowVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    relation->read->addReferenceProlog(CompoundTerm::getFlowFact, methodKey, prologLines);
    relation->writen->addReferenceProlog(CompoundTerm::getFlowFact, methodKey, prologLines);
    relation->read->addIndexProlog(CompoundTerm::getFlowFact, methodKey, prologLines);
    relation->writen->addIndexProlog(CompoundTerm::getFlowFact, methodKey, prologLines);
}

void CodeOrderVisitor::visitMethod(const string& methodKey, CodeBlock* methodBody, list<string>& prologLines) {
    prologLines.emplace_back(CompoundTerm::getCodeOrderFact(methodKey, methodKey, methodBody->blockStartKey));
    GenDataVisitor::visitMethod(methodKey, methodBody, prologLines);
}

void CodeOrderVisitor::visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    string lastKey = codeBlock->blockStartKey;
    for (auto* sentence : codeBlock->sentences) {
        prologLines.emplace_back(CompoundTerm::getCodeOrderFact(methodKey, lastKey, sentence->sentenceStartKey));
        if (sentence->structure_type == CodeStructure::STRUCTURE_TYPE_SENTENCE) {
            visitSentence(methodKey, codeBlock, sentence, prologLines);
        } else if (sentence->structure_type == CodeStructure::STRUCTURE_TYPE_SPLIT_CODE_BLOCKS or sentence->structure_type == CodeStructure::STRUCTURE_TYPE_LOOP_CODE_BLOCKS) {
            visitSplitCodeBlock(methodKey, codeBlock, dynamic_cast<SplitCodeBlocks*>(sentence), prologLines);
        }
        lastKey = sentence->sentenceEndKey;
    }
    prologLines.emplace_back(CompoundTerm::getCodeOrderFact(methodKey, lastKey, codeBlock->blockEndKey));
}

void CodeOrderVisitor::visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines) {
    for (auto* subCodeBlock : splitCodeBlocks->blocks) {
        prologLines.emplace_back(CompoundTerm::getCodeOrderFact(methodKey, splitCodeBlocks->sentenceStartKey, subCodeBlock->blockStartKey));
        visitCodeBlock(methodKey, subCodeBlock, prologLines);
        prologLines.emplace_back(CompoundTerm::getCodeOrderFact(methodKey, subCodeBlock->blockEndKey, splitCodeBlocks->sentenceEndKey));
    }
}

void CodeOrderVisitor::visitSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) {
    string lastRuntimeKey = sentence->sentenceStartKey;
    for (Relation* relation : sentence->relations) {
        if (!GlobalInfo::isOptrKeyType(relation->read->keyType) and not relation->read->orderPrologAdded) {
            relation->read->orderPrologAdded = true;
            prologLines.emplace_back(CompoundTerm::getCodeOrderFact(methodKey, lastRuntimeKey, relation->read->runtimeKey));
            lastRuntimeKey = relation->read->runtimeKey;
        }
        if (!GlobalInfo::isOptrKeyType(relation->writen->keyType) and not relation->writen->orderPrologAdded) {
            relation->writen->orderPrologAdded = true;
            prologLines.emplace_back(CompoundTerm::getCodeOrderFact(methodKey, lastRuntimeKey, relation->writen->runtimeKey));
            lastRuntimeKey = relation->writen->runtimeKey;
        }
    }
    prologLines.emplace_back(CompoundTerm::getCodeOrderFact(methodKey, lastRuntimeKey, sentence->sentenceEndKey));
}

void RuntimeKeyVisitor::visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    codeBlock->conditionItem->addRuntimeProlog(CompoundTerm::getRuntimeFact, methodKey, prologLines);
    if (codeBlock->toConditionValue) {
        codeBlock->toConditionValue->addRuntimeProlog(CompoundTerm::getRuntimeFact, methodKey, prologLines);
    }
    if (codeBlock->elseValue) {
        codeBlock->elseValue->addRuntimeProlog(CompoundTerm::getRuntimeFact, methodKey, prologLines);
    }
    GenDataVisitor::visitCodeBlock(methodKey, codeBlock, prologLines);
}

void RuntimeKeyVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    relation->read->addRuntimeProlog(CompoundTerm::getRuntimeFact, methodKey, prologLines);
    relation->writen->addRuntimeProlog(CompoundTerm::getRuntimeFact, methodKey, prologLines);
}

void RuntimeReadVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    if (!GlobalInfo::isOptrKeyType(relation->read->keyType)) {
        relation->read->addRuntimeReadProlog(CompoundTerm::getRuntimeReadFact, methodKey, prologLines);
    }
}

void RuntimeWriteVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    if (!GlobalInfo::isOptrKeyType(relation->writen->keyType)) {
        relation->writen->addRuntimeWritenProlog(CompoundTerm::getRuntimeWriteFact, methodKey, prologLines);
    }
}

void GenDataVisitor::visitMethod(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    visitCodeBlock(methodKey, codeBlock, prologLines);
}

void GenDataVisitor::visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    for (auto* sentence : codeBlock->sentences) {
        int structureType = sentence->structure_type;
        if (structureType == CodeStructure::STRUCTURE_TYPE_SENTENCE) {
            if (sentence == codeBlock->toConditionSentence) {
                visitToConditionSentence(methodKey, codeBlock, codeBlock->toConditionSentence, prologLines);
            } else {
                visitSentence(methodKey, codeBlock, sentence, prologLines);
            }
        } else if (structureType == CodeStructure::STRUCTURE_TYPE_SPLIT_CODE_BLOCKS or structureType == CodeStructure::STRUCTURE_TYPE_LOOP_CODE_BLOCKS) {
            visitSplitCodeBlock(methodKey, codeBlock, dynamic_cast<SplitCodeBlocks*>(sentence), prologLines);
        }
    }
}

void GenDataVisitor::visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines) {
    for (auto* subCodeBlock : splitCodeBlocks->blocks) {
        visitCodeBlock(methodKey, subCodeBlock, prologLines);
    }
}

void GenDataVisitor::visitToConditionSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) {
    for (Relation*& relation : sentence->relations) {
        visitRelation(methodKey, codeBlock, relation, prologLines);
    }
}

void GenDataVisitor::visitSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) {
    for (Relation*& relation : sentence->relations) {
        visitRelation(methodKey, codeBlock, relation, prologLines);
    }
}

void GenDataVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    spdlog::get(ErrorManager::DebugTag)->error("default method called: visitRelation");
}

