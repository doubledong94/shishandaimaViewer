#include "../util/util.h"
#include "../../GraphAttributes.h"
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
static StepVisitor* stepVisitor = NULL;
static CodeOrderVisitor* codeOrderVisitor = NULL;
static RuntimeKeyVisitor* runtimeKeyVisitor = NULL;
static RuntimeReadVisitor* runtimeReadVisitor = NULL;
static RuntimeWriteVisitor* runtimeWriteVisitor = NULL;

#define ITER_ALL_METHOD(RAW_DATA,METHOD,PROLOG_LINES) for(auto &classIter: RAW_DATA){ for(auto &methodIter: classIter.second) {METHOD->visitMethod(methodIter.first, methodIter.second, PROLOG_LINES);}}

void PrologDataBaseGen::init() {
    dataFlowVisitor = new DataFlowVisitor();
    logicFlowVisitor = new LogicFlowVisitor();
    timingFlowVisitor = new TimingFlowVisitor();
    scopeFlowVisitor = new ScopeFlowVisitor();
    stepVisitor = new StepVisitor();
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
    prologLines.emplace_back("\% step start");
    ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, stepVisitor, prologLines);
    // prologLines.emplace_back("\% code order start");
    // ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, codeOrderVisitor, prologLines);
    prologLines.emplace_back("\% runtime key start");
    ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, runtimeKeyVisitor, prologLines);
    // prologLines.emplace_back("\% runtime read start");
    // ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, runtimeReadVisitor, prologLines);
    // prologLines.emplace_back("\% runtime write start");
    // ITER_ALL_METHOD(CodeBlock::classKey2methodKey2codeBlock, runtimeWriteVisitor, prologLines);
}

void DataFlowVisitor::visitMethod(const string& methodKey, CodeBlock* methodBody, list<string>& prologLines) {
    // step -> param -> ...
    for (auto& paramInfo : AddressableInfo::methodKey2MethodInfo[methodKey]->parameterInfos) {
        string paramKey = AddressableInfo::makeParamKey(methodKey, paramInfo->name);
        string stepKey = AddressableInfo::makeStepKey(AddressableInfo::makeCalledKey(paramKey));
        methodBody->lvToLastWrittenKeys[paramKey] = set<string>();
        methodBody->lvToLastWrittenKeys[paramKey].insert(stepKey);
    }
    GenDataVisitor::visitMethod(methodKey, methodBody, prologLines);
}

void DataFlowVisitor::beforeRunSplitCodeBlock(CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks) {
    FOR_EACH_ITEM(splitCodeBlocks->blocks, item->lvToLastWrittenKeys = superCodeBlock->lvToLastWrittenKeys;);
}

void DataFlowVisitor::afterRunSplitCodeBlock(CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks) {
    if (splitCodeBlocks->isClosed()) {
        for (auto& lv2lastWriteKeys : superCodeBlock->lvToLastWrittenKeys) {
            bool lvIsUpdatedByEveryBranch = splitCodeBlocks->blocks.size() > 0;
            FOR_EACH_ITEM(splitCodeBlocks->blocks, if (!item->updatedLvKeys.count(lv2lastWriteKeys.first)) { lvIsUpdatedByEveryBranch = false; });
            if (lvIsUpdatedByEveryBranch) {
                superCodeBlock->lvToLastWrittenKeys[lv2lastWriteKeys.first].clear();
            }
        }
    }
    for (CodeBlock* subCodeBlock : splitCodeBlocks->blocks) {
        for (auto& lv2lastWriteKeys : subCodeBlock->lvToLastWrittenKeys) {
            if (superCodeBlock->lvToLastWrittenKeys.count(lv2lastWriteKeys.first) > 0) {
                FOR_EACH_ITEM(lv2lastWriteKeys.second, superCodeBlock->lvToLastWrittenKeys[lv2lastWriteKeys.first].insert(item););
            }
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
    // data flow of step
    // ... -> return -> step
    if (writen->keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN) {
        string stepKey = AddressableInfo::makeStepKey(AddressableInfo::makeCalledKey(writen->variableKey));
        prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, writen->runtimeKey, stepKey));
    }
    // called param -> step
    if (read->keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER) {
        string stepKey = AddressableInfo::makeStepKey(read->variableKey);
        prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, read->runtimeKey, stepKey));
    }
    // step -> called return
    if (writen->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
        string stepKey = AddressableInfo::makeStepKey(writen->variableKey);
        prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, stepKey, writen->runtimeKey));
    }
    // data flow of this relation
    if (not (writen->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN and writen->typeInfo == AddressableInfo::voidTypeInfo)) {
        prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, read->runtimeKey, writen->runtimeKey));
    }
    // use lvToLastWrittenKeys to generate data flow
    genDataFlowForLastWrittenLvs(methodKey, read, codeBlock, prologLines);
    // mark local variable
    if (writen->keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE or writen->keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER) {
        codeBlock->lvToLastWrittenKeys[writen->variableKey] = set<string>();
        codeBlock->lvToLastWrittenKeys[writen->variableKey].insert(writen->runtimeKey);
        codeBlock->updatedLvKeys.insert(writen->variableKey);
    }
}

void DataFlowVisitor::genDataFlowForLastWrittenLvs(const string& methodKey, ResolvingItem* read, CodeBlock* codeBlock, list<string>& prologLines) {
    if (read->keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE or read->keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER) {
        if (codeBlock->lvToLastWrittenKeys.count(read->variableKey) > 0) {
            FOR_EACH_ITEM(codeBlock->lvToLastWrittenKeys[read->variableKey], prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, item, read->runtimeKey)););
        } else {
            if (read->keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE) {
                spdlog::get(ErrorManager::DebugTag)->warn("local variable {} read before write in {}", read->variableKey, methodKey);
            }
        }
    }
    if (read->referencedBy) {
        genDataFlowForLastWrittenLvs(methodKey, read->referencedBy, codeBlock, prologLines);
    }
}

void DataFlowVisitor::visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    if (codeBlock->toConditionValue) {
        genDataFlowForLastWrittenLvs(methodKey, codeBlock->toConditionValue, codeBlock, prologLines);
    }
    GenDataVisitor::visitCodeBlock(methodKey, codeBlock, prologLines);
}

void LogicFlowVisitor::genToCondition(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    // variable to condition
    if (codeBlock->toConditionValue) {
        prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, codeBlock->toConditionValue->runtimeKey, codeBlock->conditionItem->runtimeKey));
    }
    // else to condition
    if (codeBlock->elseConditionValue) {
        prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, codeBlock->elseConditionValue->runtimeKey, codeBlock->elseValue->runtimeKey));
        prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, codeBlock->elseValue->runtimeKey, codeBlock->conditionItem->runtimeKey));
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
    string stepKey = AddressableInfo::makeStepKey(AddressableInfo::makeCalledKey(methodBody->conditionItem->variableKey));
    prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, stepKey, methodBody->conditionItem->runtimeKey));
    GenDataVisitor::visitMethod(methodKey, methodBody, prologLines);
}

void TimingFlowVisitor::visitSplitCodeBlock(const string& methodKey, CodeBlock* superCodeBlock, SplitCodeBlocks* splitCodeBlocks, list<string>& prologLines) {
    for (auto* subCodeBlock : splitCodeBlocks->blocks) {
        // super condition to sub condition
        subCodeBlock->conditionItem->addConditionToProlog(CompoundTerm::getDataFlowFact, methodKey, superCodeBlock->conditionItem->runtimeKey, prologLines);
        if (subCodeBlock->toConditionValue) {
            addTimingFlow(methodKey, superCodeBlock, subCodeBlock->toConditionValue, prologLines);
        }
        visitCodeBlock(methodKey, subCodeBlock, prologLines);
    }
}

void TimingFlowVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    // called method -> step
    if (relation->read->keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD) {
        string stepKey = AddressableInfo::makeStepKey(relation->read->variableKey);
        prologLines.emplace_back(CompoundTerm::getDataFlowFact(methodKey, relation->read->runtimeKey, stepKey));
    }
    addTimingFlow(methodKey, codeBlock, relation->read, prologLines);
    addTimingFlow(methodKey, codeBlock, relation->writen, prologLines);
}

void TimingFlowVisitor::addTimingFlow(const string& methodKey, CodeBlock* codeBlock, ResolvingItem* item, list<string>& prologLines) {
    if (item->keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD or item->keyType == GlobalInfo::KEY_TYPE_FIELD) {
        item->addConditionToProlog(CompoundTerm::getDataFlowFact, methodKey, codeBlock->conditionItem->runtimeKey, prologLines);
    }
    if (item->referencedBy) {
        addTimingFlow(methodKey, codeBlock, item->referencedBy, prologLines);
    }
}

void ScopeFlowVisitor::visitCodeBlock(const string& methodKey, CodeBlock* codeBlock, list<string>& prologLines) {
    if (codeBlock->toConditionValue) {
        codeBlock->toConditionValue->addReferenceProlog(CompoundTerm::getDataFlowFact, methodKey, prologLines);
    }
    GenDataVisitor::visitCodeBlock(methodKey, codeBlock, prologLines);
}

void ScopeFlowVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    relation->read->addReferenceProlog(CompoundTerm::getDataFlowFact, methodKey, prologLines);
    relation->writen->addReferenceProlog(CompoundTerm::getDataFlowFact, methodKey, prologLines);
}

void StepVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    auto* read = relation->read;
    auto* writen = relation->writen;
    // called parameter/called method/called return
    if (read->keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER) {
        string stepKey = AddressableInfo::makeStepKey(read->variableKey);
        // called param -> step
        prologLines.emplace_back(Rule::getStepInRule(methodKey, read->extraInfoMethodKey, read->runtimeKey, stepKey, read->extraInfoParameterKey, true));
        prologLines.emplace_back(Rule::getStepInRuleOutOfSteps(methodKey, read->extraInfoMethodKey, read->runtimeKey, stepKey, read->extraInfoParameterKey, true));
    }
    if (read->keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD) {
        string stepKey = AddressableInfo::makeStepKey(read->variableKey);
        // called method -> step
        prologLines.emplace_back(Rule::getStepInRule(methodKey, read->extraInfoMethodKey, read->runtimeKey, stepKey, read->extraInfoMethodKey, false));
        prologLines.emplace_back(Rule::getStepInRuleOutOfSteps(methodKey, read->extraInfoMethodKey, read->runtimeKey, stepKey, read->extraInfoMethodKey, false));
    }
    if (writen->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
        string stepKey = AddressableInfo::makeStepKey(writen->variableKey);
        // step -> called return
        prologLines.emplace_back(Rule::getStepOutRule(writen->extraInfoMethodKey, methodKey, writen->extraInfoReturnKey, stepKey, writen->runtimeKey));
        prologLines.emplace_back(Rule::getStepOutRuleOutOfSteps(writen->extraInfoMethodKey, methodKey, writen->extraInfoReturnKey, stepKey, writen->runtimeKey));
    }
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
            visitSentence(methodKey, codeBlock, sentence, prologLines);
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

void GenDataVisitor::visitSentence(const string& methodKey, CodeBlock* codeBlock, Sentence* sentence, list<string>& prologLines) {
    for (Relation*& relation : sentence->relations) {
        visitRelation(methodKey, codeBlock, relation, prologLines);
    }
}

void GenDataVisitor::visitRelation(const string& methodKey, CodeBlock* codeBlock, Relation* relation, list<string>& prologLines) {
    spdlog::get(ErrorManager::DebugTag)->error("default method called: visitRelation");
}

