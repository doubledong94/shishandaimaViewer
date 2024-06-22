#include "../../util/util.h"
#include "../javaParser/JavaParserBaseVisitor.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../syntaxObject/AntlrNodeToSyntaxObjectConverter.h"
#include "../../addressableInfo/GlobalInfo.h"
#include "antlr4-runtime.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "../../runtime/codestructure/CodeStructure.h"
#include "../../runtime/codestructure/Relation.h"
#include "../../runtime/codestructure/Sentence.h"
#include "../../runtime/codestructure/CodeBlock.h"
#include "../../runtime/codestructure/SplitCodeBlocks.h"
#include "../../runtime/ScopeAndEnv.h"
#include "../../error/ErrorManager.h"
#include "../../runtime/type/TypeCheckAndInference.h"
#include "../../file/FileManager.h"
#include "RuntimeVisitor.h"
#include "../../antlr/syntaxObject/Modifier.h"

void RuntimeVisitor::copyFrom(RuntimeVisitor* copied) {
    classScopeAndEnv = copied->classScopeAndEnv;
    methodScopeAndEnv = copied->methodScopeAndEnv;
    typeUnification.copyFrom(&(copied->typeUnification));
}

void RuntimeVisitor::clearScopeAndEnv() {
    classScopeAndEnv = nullptr;
    methodScopeAndEnv = nullptr;
}

void ClassLevelVisitor::pushTypeStack(const string& typeName) {
    typeNameStack.push_back(typeName);
    typeKeyStack.push_back(package + '.' + joinList(typeNameStack, "."));
}

void ClassLevelVisitor::popTypeStack() {
    typeKeyStack.pop_back();
    typeNameStack.pop_back();
}

void ClassLevelVisitor::reset() {
    clearScopeAndEnv();
}

ClassLevelVisitor* ClassLevelVisitor::getInstanceFromCopy(RuntimeVisitor* copied) {
    auto* ret = ClassLevelVisitor::getInstance();
    ret->copyFrom(copied);
    return ret;
}

ClassLevelVisitor* ClassLevelVisitor::getInstanceFromCopy(ClassLevelVisitor* copied) {
    auto* ret = ClassLevelVisitor::getInstance();
    ret->copyFrom(copied);
    ret->typeNameStack = copied->typeNameStack;
    ret->typeKeyStack = copied->typeKeyStack;
    ret->package = copied->package;
    return ret;
}

any ClassLevelVisitor::visitCompilationUnit(JavaParser::CompilationUnitContext* ctx) {
    if (ctx->packageDeclaration() != nullptr) {
        package = ctx->packageDeclaration()->qualifiedName()->getText();
    }
    return JavaParserBaseVisitor::visitCompilationUnit(ctx);
}

std::any ClassLevelVisitor::visitClassDeclaration(JavaParser::ClassDeclarationContext* ctx) {
    pushTypeStack(ctx->identifier()->getText());

    CodeBlock::classKey2methodKey2codeBlock[typeKeyStack.back()] = map<string, CodeBlock*>();
    auto* initVisitor = InitializerVisitor::getInstance();
    initVisitor->copyFrom(this);
    initVisitor->classScopeAndEnv = AddressableInfo::typeKey2typeInfo[typeKeyStack.back()]->classScopeAndEnv;
    initVisitor->classLevelVisitor = this;
    ctx->classBody()->accept(initVisitor);
    InitializerVisitor::returnToPool(initVisitor);

    auto* classLevelVisitor = ClassLevelVisitor::getInstanceFromCopy(this);
    classLevelVisitor->classScopeAndEnv = AddressableInfo::typeKey2typeInfo[typeKeyStack.back()]->classScopeAndEnv;
    ctx->classBody()->accept(classLevelVisitor);
    ClassLevelVisitor::returnToPool(classLevelVisitor);
    popTypeStack();
    return 0;
}

std::any ClassLevelVisitor::visitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext* ctx) {
    pushTypeStack(ctx->identifier()->getText());
    CodeBlock::classKey2methodKey2codeBlock[typeKeyStack.back()] = map<string, CodeBlock*>();
    auto* classLevelVisitor = ClassLevelVisitor::getInstanceFromCopy(this);
    classLevelVisitor->classScopeAndEnv = AddressableInfo::typeKey2typeInfo[typeKeyStack.back()]->classScopeAndEnv;
    ctx->interfaceBody()->accept(classLevelVisitor);
    ClassLevelVisitor::returnToPool(classLevelVisitor);
    popTypeStack();
    return 0;
}

std::any ClassLevelVisitor::visitEnumDeclaration(JavaParser::EnumDeclarationContext* ctx) {
    if (ctx->enumBodyDeclarations() != nullptr) {
        pushTypeStack(ctx->identifier()->getText());
        CodeBlock::classKey2methodKey2codeBlock[typeKeyStack.back()] = map<string, CodeBlock*>();
        auto* classLevelVisitor = ClassLevelVisitor::getInstanceFromCopy(this);
        classLevelVisitor->classScopeAndEnv = AddressableInfo::typeKey2typeInfo[typeKeyStack.back()]->classScopeAndEnv;
        ctx->enumBodyDeclarations()->accept(classLevelVisitor);
        ClassLevelVisitor::returnToPool(classLevelVisitor);
        popTypeStack();
    }
    return 0;
}

any ClassLevelVisitor::visitClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext* ctx) {
    if (ctx->memberDeclaration() != nullptr) {
        ctx->memberDeclaration()->accept(this);
    }
    return 0;
}

std::any ClassLevelVisitor::visitAnnotationTypeDeclaration(JavaParser::AnnotationTypeDeclarationContext* ctx) {
    return 0;
}

std::any ClassLevelVisitor::visitRecordDeclaration(JavaParser::RecordDeclarationContext* ctx) {
    return 0;
}

std::any ClassLevelVisitor::visitMemberDeclaration(JavaParser::MemberDeclarationContext* ctx) {
    antlr4::tree::ParseTree* node = nullptr;
    if (ctx->classDeclaration() != nullptr) {
        node = ctx->classDeclaration();
    } else if (ctx->interfaceDeclaration() != nullptr) {
        node = ctx->interfaceDeclaration();
    } else if (ctx->enumDeclaration() != nullptr) {
        node = ctx->enumDeclaration();
    }
    if (node != nullptr) {
        auto* visitor = ClassLevelVisitor::getInstanceFromCopy(this);
        node->accept(visitor);
        ClassLevelVisitor::returnToPool(visitor);
        return 0;
    } else {
        return JavaParserBaseVisitor::visitMemberDeclaration(ctx);
    }
}

std::any ClassLevelVisitor::visitConstructorDeclaration(JavaParser::ConstructorDeclarationContext* ctx) {
    return 0;
}

std::any ClassLevelVisitor::visitFieldDeclaration(JavaParser::FieldDeclarationContext* ctx) {
    return 0;
}

any ClassLevelVisitor::visitConstDeclaration(JavaParser::ConstDeclarationContext* ctx) {
    return 0;
}

string ClassLevelVisitor::makeMethodKeyFromMethodInf(Method& method) {
    set<string> typeParameters;
    FOR_EACH_ITEM(method.typeParams, typeParameters.insert(item->name););

    list<string> parameterTypes;
    int paramIndex = 0;
    for (auto& item : method.parameters) {
        TypeInfo* parameterTypeInfo = classScopeAndEnv->getTypeInfoWithFileScope(item->typeName->typeName);
        string paramTypeName;
        int dim = item->typeName->dim;
        if (method.isVariableParameter and paramIndex == method.parameters.size() - 1) {
            dim += 1;
        }
        string arrayPostFix = getArrayPostFix(dim);
        if (parameterTypeInfo) {
            if (parameterTypeInfo->typeKey.size() == joinList(item->typeName->typeName, ".").size()) {
                paramTypeName = parameterTypeInfo->typeKey + arrayPostFix;
            } else {
                paramTypeName = parameterTypeInfo->typeName + arrayPostFix;
            }
        } else if (item->typeName->typeName.size() == 1 and typeParameters.count(item->typeName->typeName.back())) {
            paramTypeName = item->typeName->typeName.back() + arrayPostFix;
        }
        if (paramTypeName.empty()) {
            paramTypeName = joinList(item->typeName->typeName, ".") + arrayPostFix;
            spdlog::get(ErrorManager::DebugTag)->warn("visitMethodDeclaration: did not find param type name: {} for param: {} in method: {} in type: {}", paramTypeName, item->name, method.name, classScopeAndEnv->typeInfo->typeKey);
        }
        parameterTypes.push_back(paramTypeName);
        paramIndex++;
    }
    return AddressableInfo::makeMethodKey(typeKeyStack.back(), method.name, joinList(parameterTypes, ","));
}

any ClassLevelVisitor::visitInterfaceMethodDeclaration(JavaParser::InterfaceMethodDeclarationContext* ctx) {
    // ctx->interfaceCommonBodyDeclaration()->methodBody() == nullptr is parsing error
    if (ctx->interfaceCommonBodyDeclaration()->methodBody() != nullptr && ctx->interfaceCommonBodyDeclaration()->methodBody()->block() != nullptr) {
        Method method;
        AntlrNodeToSyntaxObjectConverter::convertInterfaceMethodDeclaration(ctx, &method);
        string methodKey = makeMethodKeyFromMethodInf(method);
        auto* pStatementVisitor = StatementVisitor::getInstanceFromCopy(this);
        pStatementVisitor->codeBlock = new CodeBlock(nullptr, MethodScopeAndEnv::rootStructureKey, false);
        pStatementVisitor->codeBlock->conditionItem = ResolvingItem::getInstance2(methodKey, NULL, MethodScopeAndEnv::rootStructureKey, "-1", "-1", GlobalInfo::KEY_TYPE_METHOD);
        pStatementVisitor->methodScopeAndEnv = MethodScopeAndEnv::createMethodScopeAndEnv(methodKey, classScopeAndEnv);
        pStatementVisitor->visitBlock(ctx->interfaceCommonBodyDeclaration()->methodBody()->block());
        CodeBlock::classKey2methodKey2codeBlock[classScopeAndEnv->typeInfo->typeKey][methodKey] = pStatementVisitor->codeBlock;
        StatementVisitor::returnToPool(pStatementVisitor);
    }
    return 0;
}

std::any ClassLevelVisitor::visitMethodDeclaration(JavaParser::MethodDeclarationContext* ctx) {
    if (ctx->methodBody()->block() != nullptr) {
        Method method;
        AntlrNodeToSyntaxObjectConverter::convertMethodDeclaration(ctx, &method);
        string methodKey = makeMethodKeyFromMethodInf(method);
        auto* pStatementVisitor = StatementVisitor::getInstanceFromCopy(this);
        pStatementVisitor->codeBlock = new CodeBlock(nullptr, MethodScopeAndEnv::rootStructureKey, false);
        pStatementVisitor->codeBlock->conditionItem = ResolvingItem::getInstance2(methodKey, NULL, MethodScopeAndEnv::rootStructureKey, "-1", "-1", GlobalInfo::KEY_TYPE_METHOD);
        pStatementVisitor->methodScopeAndEnv = MethodScopeAndEnv::createMethodScopeAndEnv(methodKey, classScopeAndEnv);
        pStatementVisitor->visitBlock(ctx->methodBody()->block());
        CodeBlock::classKey2methodKey2codeBlock[classScopeAndEnv->typeInfo->typeKey][methodKey] = pStatementVisitor->codeBlock;
        StatementVisitor::returnToPool(pStatementVisitor);
    }
    return 0;
}

void StructuralVisitor::reset() {
    clearScopeAndEnv();
    outerCodeBlock = nullptr;
    sentenceIndexInOuterCodeBlock = 0;
}

StructuralVisitor* StructuralVisitor::getInstanceFromCopy(RuntimeVisitor* copied) {
    auto* ret = StructuralVisitor::getInstance();
    ret->copyFrom(copied);
    return ret;
}

std::any StructuralVisitor::visitUseStatementVisitor(antlr4::tree::ParseTree* tree, CodeBlock* codeBlock, int sentenceIndex) {
    auto* statementVisitor = StatementVisitor::getInstanceFromCopy(this);
    statementVisitor->codeBlock = codeBlock;
    statementVisitor->sentenceIndex = sentenceIndex;
    std::any ret = tree->accept(statementVisitor);
    StatementVisitor::returnToPool(statementVisitor);
    return ret;
}

std::any StructuralVisitor::visitUseStatementVisitor(antlr4::tree::ParseTree* tree, CodeBlock* codeBlock) {
    auto* statementVisitor = StatementVisitor::getInstanceFromCopy(this);
    statementVisitor->codeBlock = codeBlock;
    std::any ret = tree->accept(statementVisitor);
    StatementVisitor::returnToPool(statementVisitor);
    return ret;
}

std::any StructuralVisitor::visitStatementIf(JavaParser::StatementIfContext* ctx) {
    auto* splitCodeBlocks = new SplitCodeBlocks(outerCodeBlock, outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock);
    splitCodeBlocks->splitType = SplitCodeBlocks::SPLIT_TYP_IF;
    auto* firstCodeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, 1, false), false);
    visitConditionIf(ctx->parExpression()->expression(), firstCodeBlock);
    visitUseStatementVisitor(ctx->ifState, firstCodeBlock, 1);
    auto& lastCodeBlock = firstCodeBlock;
    if (ctx->elseState != nullptr) {
        JavaParser::StatementContext* elseStatement = ctx->elseState;
        int branchIndex = 2;
        while (elseStatement != nullptr && elseStatement->children[0]->getText() == "if") {
            auto* elseIfStatement = dynamic_cast<JavaParser::StatementIfContext*>(elseStatement);
            auto* elseIfCodeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, branchIndex, false), false);
            visitConditionIf(elseIfStatement->parExpression()->expression(), elseIfCodeBlock);
            visitUseStatementVisitor(elseIfStatement->ifState, elseIfCodeBlock, 1);
            elseStatement = elseIfStatement->elseState;

            // else to condition
            elseIfCodeBlock->elseConditionValue = lastCodeBlock->conditionItem;
            elseIfCodeBlock->elseValue = ResolvingItem::getInstance2(methodScopeAndEnv->methodElseKey, NULL, lastCodeBlock->structure_key, "-1", "-1", GlobalInfo::KEY_TYPE_ELSE);
            lastCodeBlock = elseIfCodeBlock;

            branchIndex++;
        }
        if (elseStatement != nullptr) {
            auto* elseCodeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, branchIndex, true), true);
            visitConditionElseWithoutIf(elseCodeBlock);
            visitUseStatementVisitor(elseStatement, elseCodeBlock, 1);
            elseCodeBlock->elseConditionValue = lastCodeBlock->conditionItem;
            elseCodeBlock->elseValue = ResolvingItem::getInstance2(methodScopeAndEnv->methodElseKey, NULL, lastCodeBlock->structure_key, "-1", "-1", GlobalInfo::KEY_TYPE_ELSE);
        }
    }
    return 0;
}

std::any StructuralVisitor::visitStatementFor(JavaParser::StatementForContext* ctx) {
    auto* splitCodeBlocks = new Loop(outerCodeBlock, outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock);
    auto* codeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, 1, false), false);
    if (ctx->forControl()->forInit() != nullptr) {
        visitUseStatementVisitor(ctx->forControl()->forInit(), codeBlock, -1);
    }
    if (ctx->forControl()->enhancedForControl()) {
        auto* statementVisitor = StatementVisitor::getInstanceFromCopy(this);
        statementVisitor->codeBlock = codeBlock;
        statementVisitor->sentenceIndex = -1;
        const any& itemOrNull = ctx->forControl()->enhancedForControl()->expression()->accept(statementVisitor);
        ResolvingItem* arrayLikeItem = NULL;
        if (statementVisitor->abort) {
            arrayLikeItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->forControl()->enhancedForControl()->expression()->getText()),
                AddressableInfo::errorTypeInfo, codeBlock->structure_key, "-1", "-1", GlobalInfo::KEY_TYPE_ERROR);
            statementVisitor->abort = false;
        } else {
            arrayLikeItem = any_cast<ResolvingItem*>(itemOrNull);
        }
        VariableDeclaration variableDeclarator;
        if (ctx->forControl()->enhancedForControl()->typeType()) {
            AntlrNodeToSyntaxObjectConverter::convertTypeType(ctx->forControl()->enhancedForControl()->typeType(), &(variableDeclarator.typeType));
        } else {
            variableDeclarator.typeType.typeName.push_back(ctx->forControl()->enhancedForControl()->VAR()->getText());
        }
        NameAndRelatedExp name;
        name.name.push_back(ctx->forControl()->enhancedForControl()->variableDeclaratorId()->identifier()->getText());
        variableDeclarator.nameAndValueCount.push_back(name);
        statementVisitor->addLocalVariable(variableDeclarator, true, arrayLikeItem);
        StatementVisitor::returnToPool(statementVisitor);
    }
    visitConditionFor(ctx->forControl(), codeBlock);
    visitUseStatementVisitor(ctx->statement(), codeBlock, 1);
    if (ctx->forControl()->forUpdate() != nullptr) {
        visitUseStatementVisitor(ctx->forControl()->forUpdate(), codeBlock, -2);
    }
    return 0;
}

std::any StructuralVisitor::visitStatementWhile(JavaParser::StatementWhileContext* ctx) {
    auto* splitCodeBlocks = new Loop(outerCodeBlock, outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock);
    auto* codeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, 1, false), false);
    visitConditionWhile(ctx->parExpression()->expression(), codeBlock);
    visitUseStatementVisitor(ctx->statement(), codeBlock);
    return 0;
}

std::any StructuralVisitor::visitStatementDoWhile(JavaParser::StatementDoWhileContext* ctx) {
    auto* splitCodeBlocks = new Loop(outerCodeBlock, outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock);
    auto* codeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, 1, false), false);
    visitConditionDoWhile(ctx->parExpression()->expression(), codeBlock);
    visitUseStatementVisitor(ctx->statement(), codeBlock);
    return 0;
}

std::any StructuralVisitor::visitStatementSwitch(JavaParser::StatementSwitchContext* ctx) {
    auto* splitCodeBlocks = new SplitCodeBlocks(outerCodeBlock, outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock);
    splitCodeBlocks->splitType = SplitCodeBlocks::SPLIT_TYPE_SWITCH;
    ResolvingItem* switchItem = NULL;
    auto* statementVisitor = StatementVisitor::getInstanceFromCopy(this);
    statementVisitor->codeBlock = outerCodeBlock;
    statementVisitor->sentenceIndex = sentenceIndexInOuterCodeBlock;
    const any& itemOrNull = ctx->parExpression()->expression()->accept(statementVisitor);
    if (!statementVisitor->abort) {
        switchItem = any_cast<ResolvingItem*>(itemOrNull);
    }
    if (not switchItem) {
        switchItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->parExpression()->expression()->getText()),
            AddressableInfo::errorTypeInfo, outerCodeBlock->structure_key, "0", "0", GlobalInfo::KEY_TYPE_ERROR);
    }
    int branchIndex = 1;
    for (auto* group : ctx->switchBlockStatementGroup()) {
        bool closed = false;
        for (auto* switchLabel : group->switchLabel()) {
            if (switchLabel->DEFAULT() != nullptr) {
                closed = true;
            }
        }
        auto* caseCodeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, branchIndex, closed), closed);
        int caseIndex = 0;
        for (auto* switchLabel : group->switchLabel()) {
            if (switchLabel->CASE() != nullptr) {
                caseIndex--;
                auto switchItemI = ResolvingItem::getInstance2(switchItem->variableKey, switchItem->typeInfo, caseCodeBlock->structure_key, to_string(caseIndex), "-1", switchItem->keyType, switchItem->extraInfoForOptr);
                visitConditionCase(switchLabel->expression(), switchItemI, caseCodeBlock, caseIndex);
            } else if (switchLabel->DEFAULT() != nullptr) {
                visitConditionDefault(caseCodeBlock);
            }
        }
        int sentenceIndex = 0;
        for (auto* blockStatement : group->blockStatement()) {
            sentenceIndex++;
            visitUseStatementVisitor(blockStatement, caseCodeBlock, sentenceIndex);
        }
        branchIndex++;
    }
    StatementVisitor::returnToPool(statementVisitor);
    return 0;
}

std::any StructuralVisitor::visitStatementTry(JavaParser::StatementTryContext* ctx) {
    auto* splitCodeBlocks = new SplitCodeBlocks(outerCodeBlock, outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock);
    splitCodeBlocks->splitType = SplitCodeBlocks::SPLIT_TYPE_TRY;
    auto* firstCodeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, 1, false), false);
    visitConditionTry(firstCodeBlock);
    visitUseStatementVisitor(ctx->block(), firstCodeBlock);
    int branchIndex = 2;
    for (auto* catchClause : ctx->catchClause()) {
        auto* catchCodeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, branchIndex, false), false);
        visitConditionCatch(catchClause, catchCodeBlock);
        visitUseStatementVisitor(catchClause->block(), catchCodeBlock);
        branchIndex++;
    }
    if (ctx->finallyBlock() != nullptr) {
        auto* finallyCodeBlock = new CodeBlock(splitCodeBlocks, CodeBlock::makeStructureKey(outerCodeBlock->structure_key, sentenceIndexInOuterCodeBlock, branchIndex, true), true);
        visitConditionFinally(finallyCodeBlock);
        visitUseStatementVisitor(ctx->finallyBlock(), finallyCodeBlock);
    }
    return 0;
}

void StructuralVisitor::visitCondition(string& conditionKey, JavaParser::ExpressionContext* ctx, CodeBlock* codeBlock) {
    if (codeBlock->conditionItem == nullptr) {
        codeBlock->conditionItem = ResolvingItem::getInstance2(conditionKey, NULL, codeBlock->structure_key, "-1", "-1", GlobalInfo::KEY_TYPE_CONDITION);
    }
    if (ctx != nullptr) {
        auto* statementVisitor = StatementVisitor::getInstanceFromCopy(this);
        statementVisitor->codeBlock = codeBlock;
        statementVisitor->sentenceIndex = -10;
        const any& itemOrNull = ctx->accept(statementVisitor);
        if (!statementVisitor->abort) {
            codeBlock->toConditionValue = any_cast<ResolvingItem*>(itemOrNull);
            codeBlock->toConditionSentence = statementVisitor->getSentence();
        }
        StatementVisitor::returnToPool(statementVisitor);
    }
}

void StructuralVisitor::visitConditionIf(JavaParser::ExpressionContext* ctx, CodeBlock* codeBlock) {
    visitCondition(methodScopeAndEnv->methodIfKey, ctx, codeBlock);
}

void StructuralVisitor::visitConditionElseWithoutIf(CodeBlock* codeBlock) {
    visitCondition(methodScopeAndEnv->methodIfKey, nullptr, codeBlock);
}

void StructuralVisitor::visitConditionFor(JavaParser::ForControlContext* ctx, CodeBlock* codeBlock) {
    if (ctx->enhancedForControl() != nullptr) {
        visitCondition(methodScopeAndEnv->methodForEachKey, NULL, codeBlock);
    } else {
        if (ctx->forCondition() != nullptr) {
            visitCondition(methodScopeAndEnv->methodForKey, ctx->forCondition()->expression(), codeBlock);
        } else {
            visitCondition(methodScopeAndEnv->methodForKey, nullptr, codeBlock);
        }
    }
}

void StructuralVisitor::visitConditionWhile(JavaParser::ExpressionContext* ctx, CodeBlock* codeBlock) {
    visitCondition(methodScopeAndEnv->methodWhileKey, ctx, codeBlock);
}

void StructuralVisitor::visitConditionDoWhile(JavaParser::ExpressionContext* ctx, CodeBlock* codeBlock) {
    visitCondition(methodScopeAndEnv->methodWhileKey, ctx, codeBlock);
}

void StructuralVisitor::visitConditionCase(JavaParser::ExpressionContext* ctx, ResolvingItem* switchItem, CodeBlock* codeBlock, int caseIndex) {
    if (codeBlock->conditionItem == nullptr) {
        codeBlock->conditionItem = ResolvingItem::getInstance2(methodScopeAndEnv->methodCaseKey, NULL, codeBlock->structure_key, "-1", "-1", GlobalInfo::KEY_TYPE_CONDITION);
    }
    if (ctx != nullptr) {
        auto* statementVisitor = StatementVisitor::getInstanceFromCopy(this);
        statementVisitor->codeBlock = codeBlock;
        statementVisitor->sentenceIndex = caseIndex;
        const any& itemOrNull = ctx->accept(statementVisitor);
        ResolvingItem* caseItem = NULL;
        if (!statementVisitor->abort) {
            caseItem = any_cast<ResolvingItem*>(itemOrNull);
        }
        if (not caseItem) {
            caseItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->getText()),
                AddressableInfo::errorTypeInfo, codeBlock->structure_key, "-1", "-1", GlobalInfo::KEY_TYPE_ERROR);
        }
        ResolvingItem* logicItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_RELATION_RETURN, AddressableInfo::primitive_boolTypeInfo, codeBlock->structure_key, to_string(caseIndex), "-1", GlobalInfo::KEY_TYPE_OPTR_RELATION_RETURN, "==");
        new Relation(statementVisitor->getSentence(), switchItem, logicItem);
        new Relation(statementVisitor->getSentence(), caseItem, logicItem);
        codeBlock->toConditionValue = logicItem;
        codeBlock->toConditionSentence = statementVisitor->getSentence();
        StatementVisitor::returnToPool(statementVisitor);
    }
}

void StructuralVisitor::visitConditionDefault(CodeBlock* codeBlock) {
    visitCondition(methodScopeAndEnv->methodCaseKey, nullptr, codeBlock);
}

void StructuralVisitor::visitConditionTry(CodeBlock* codeBlock) {
    visitCondition(methodScopeAndEnv->methodTryKey, nullptr, codeBlock);
}

void StructuralVisitor::visitConditionCatch(JavaParser::CatchClauseContext* ctx, CodeBlock* codeBlock) {
    visitCondition(methodScopeAndEnv->methodCatchKey, nullptr, codeBlock);
}

void StructuralVisitor::visitConditionFinally(CodeBlock* codeBlock) {
    visitCondition(methodScopeAndEnv->methodFinallyKey, nullptr, codeBlock);
}

any StructuralVisitor::visitChildren(antlr4::tree::ParseTree* node) {
    return 0;
}

void StatementVisitor::unhandledError() {
    abort = true;
}

string StatementVisitor::getIncreasedIndexInsideExp() {
    indexInsideStatement++;
    return to_string(indexInsideStatement);
}

Sentence* StatementVisitor::getSentence() {
    if (sentence == nullptr) {
        sentence = new Sentence(codeBlock, codeBlock->structure_key, sentenceIndex);
    }
    return sentence;
}

void StatementVisitor::reset() {
    clearScopeAndEnv();
    indexInsideStatement = 0;
    sentenceIndex = 0;
    abort = false;
    codeBlock = nullptr;
    sentence = nullptr;
    typeUnification.clear();
    expectingTypeInfo.clear();
}

StatementVisitor* StatementVisitor::getInstanceFromCopy(RuntimeVisitor* copied) {
    auto* ret = StatementVisitor::getInstance();
    ret->copyFrom(copied);
    if (dynamic_cast<StatementVisitor*>(copied) != nullptr) {
        ret->statementBlockStateCount = (dynamic_cast<StatementVisitor*>(copied))->statementBlockStateCount;
    } else {
        ret->statementBlockStateCount = new int;
        *(ret->statementBlockStateCount) = 10000;
    }
    return ret;
}

string StatementVisitor::getOptrParam(const string& optr, int paraIndex) {
    return optr + ":" + to_string(paraIndex);
}

any StatementVisitor::visitBlock(JavaParser::BlockContext* ctx) {
    methodScopeAndEnv->codeBlockScopeAndEnvs.push_front(new CodeBlockScopeAndEnv());
    int stateCount = 0;
    for (auto* statement : ctx->blockStatement()) {
        stateCount++;
        StatementVisitor* visitor = StatementVisitor::getInstanceFromCopy(this);
        visitor->codeBlock = codeBlock;
        visitor->sentenceIndex = stateCount;
        statement->accept(visitor);
        StatementVisitor::returnToPool(visitor);
    }
    methodScopeAndEnv->codeBlockScopeAndEnvs.pop_front();
    return 0;
}

std::any StatementVisitor::visitBlockStatement(JavaParser::BlockStatementContext* ctx) {
    if (ctx->localVariableDeclaration()) {
        return visitLocalVariableDeclaration(ctx->localVariableDeclaration());
    } else if (ctx->statement() != nullptr) {
        return ctx->statement()->accept(this);
    } else if (ctx->localTypeDeclaration() != nullptr) {
        return 0;
    }
    return 0;
}

std::any StatementVisitor::visitLocalVariableDeclaration(JavaParser::LocalVariableDeclarationContext* ctx) {
    if (abort) {
        return nullptr;
    }
    VariableDeclaration variableDeclarator;
    AntlrNodeToSyntaxObjectConverter::convertLocalVariableDeclaration(ctx, &variableDeclarator);
    addLocalVariable(variableDeclarator);
    return 0;
}

std::any StatementVisitor::addLocalVariable(VariableDeclaration& variableDeclarator, bool fromFor, ResolvingItem* initValueItem) {
    bool isTypeVar = variableDeclarator.typeType.typeName.front() == "var";
    TypeInfo* typeInfo = NULL;
    if (not isTypeVar) {
        typeInfo = methodScopeAndEnv->getTypeInfoWithFileScope(variableDeclarator.typeType.typeName);
    }
    // todo handle error
    if (not typeInfo) {
        typeInfo = new TypeInfo;
        typeInfo->typeName = joinList(variableDeclarator.typeType.typeName, ".");
        typeInfo->typeKey = typeInfo->typeName;
        if (not isTypeVar) {
            spdlog::get(ErrorManager::DebugTag)->warn("visitLocalVariableDeclaration: did not find type name: {} for lv:{} in method: {}", typeInfo->typeName, variableDeclarator.nameAndValueCount.front().name.front(), methodScopeAndEnv->methodKey);
        }
    }

    vector<TypeInfo*> typeArgs;
    if (not isTypeVar) {
        for (auto& typeArg : variableDeclarator.typeType.typeArgs) {
            typeArgs.push_back(methodScopeAndEnv->getTypeInfoWithFileScope(typeArg->typeName));
        }
    }
    expectingTypeInfo.clear();
    expectingTypeInfo.push_back(typeInfo);
    for (auto& variableDeclaratorI : variableDeclarator.nameAndValueCount) {
        string lvKey = methodScopeAndEnv->putLocalVariable(variableDeclaratorI.name.back(), typeInfo, codeBlock->structure_key);
        if (variableDeclaratorI.dim == 0) {
            if (not isTypeVar and not typeArgs.empty()) {
                auto typeParam2typeArg = map<TypeInfo*, TypeInfo*>();
                for (int i = 0;i < typeInfo->typeParamInfos.size();i++) {
                    if (typeArgs[i]) {
                        typeParam2typeArg[typeInfo->typeParamInfos[i]] = typeArgs[i];
                    }
                }
                methodScopeAndEnv->lv2typeParam2typeArg[lvKey] = typeParam2typeArg;
            }
            if (variableDeclaratorI.initExpression or fromFor) {
                abort = false;
                any itemOrNull = NULL;
                if (variableDeclaratorI.initExpression) {
                    itemOrNull = variableDeclaratorI.initExpression->accept(this);
                }
                ResolvingItem* valueItem = NULL;
                if (fromFor) {
                    valueItem = initValueItem;
                } else if (abort) {
                    valueItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(variableDeclaratorI.initExpression->getText()),
                        AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
                    abort = false;
                } else {
                    valueItem = any_cast<ResolvingItem*>(itemOrNull);
                }
                if (isTypeVar) {
                    if (fromFor) {
                        if (TypeCheckAndInference::isAssignable(valueItem->typeInfo, AddressableInfo::iterableTypeInfo)) {
                            addTypeArgForResolvingItem(valueItem);
                            if (typeUnification.getTypeArgFromTypeParam(AddressableInfo::iterableTypeParamInfo)) {
                                typeInfo = typeUnification.getTypeArgFromTypeParam(AddressableInfo::iterableTypeParamInfo);
                            } else {
                                spdlog::get(ErrorManager::DebugTag)->warn("visitLocalVariableDeclaration: did not find type name: {} for lv:{} in method: {}", typeInfo->typeName, variableDeclaratorI.name.front(), methodScopeAndEnv->methodKey);
                            }
                        } else {
                            typeInfo = valueItem->typeInfo;
                        }
                    } else {
                        typeInfo = valueItem->typeInfo;
                    }
                    methodScopeAndEnv->LVKey2LVTypeInfo[lvKey] = typeInfo;
                }
                // local variable init
                auto* varItem = ResolvingItem::getInstance2(lvKey, typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_LOCAL_VARIABLE);
                new Relation(getSentence(), valueItem, varItem);
            } else {
                // local variable default value
                auto* defaultValueItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_DEFAULT_VALUE, AddressableInfo::defaultValueTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_DEFAULT_VALUE);
                auto* varItem = ResolvingItem::getInstance2(lvKey, typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_LOCAL_VARIABLE);
                new Relation(getSentence(), defaultValueItem, varItem);
            }
        } else {
            auto* varItem = ResolvingItem::getInstance2(lvKey, typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_LOCAL_VARIABLE);
            new Relation(getSentence(), handleNewArray(variableDeclaratorI), varItem);
        }
    }
    expectingTypeInfo.clear();
    return 0;
}

std::any StatementVisitor::visitFieldDeclaration(JavaParser::FieldDeclarationContext* ctx) {
    if (abort) {
        return nullptr;
    }
    VariableDeclaration variableDeclarator;
    AntlrNodeToSyntaxObjectConverter::convertFieldDeclaration(ctx, &variableDeclarator);
    TypeInfo* typeInfo = classScopeAndEnv->getTypeInfoWithFileScope(variableDeclarator.typeType.typeName);
    // todo handle error
    if (typeInfo == nullptr) {
        typeInfo = new TypeInfo;
        typeInfo->typeName = joinList(variableDeclarator.typeType.typeName, ".");
        typeInfo->typeKey = typeInfo->typeName;
        spdlog::get(ErrorManager::DebugTag)->warn("visitFieldDeclaration: did not find type name: {} for field: {} in type: {}", typeInfo->typeName, variableDeclarator.nameAndValueCount.front().name.front(), classScopeAndEnv->typeInfo->typeKey);
    }
    expectingTypeInfo.clear();
    expectingTypeInfo.push_back(typeInfo);
    for (auto& variableDeclaratorI : variableDeclarator.nameAndValueCount) {
        TypeInfo* typeInfoI = typeInfo;
        if (variableDeclaratorI.dim > 0) {
            typeInfoI = AddressableInfo::typeKey2typeInfo[GlobalInfo::type_key_array];
        }
        string& fieldKey = classScopeAndEnv->name2fieldInfo[variableDeclaratorI.name.front()]->fieldKey;
        auto* varItem = ResolvingItem::getInstance2(fieldKey, typeInfoI, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_FIELD);
        if (variableDeclaratorI.dim == 0) {
            if (variableDeclaratorI.initExpression != nullptr) {
                abort = false;
                const any& itemOrNull = variableDeclaratorI.initExpression->accept(this);
                ResolvingItem* valueItem = NULL;
                if (abort) {
                    valueItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(variableDeclaratorI.initExpression->getText()),
                        AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
                    abort = false;
                } else {
                    valueItem = any_cast<ResolvingItem*>(itemOrNull);
                }
                new Relation(getSentence(), valueItem, varItem);
            } else {
                // field default value
                auto* defaultValueItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_DEFAULT_VALUE, AddressableInfo::defaultValueTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_DEFAULT_VALUE);
                new Relation(getSentence(), defaultValueItem, varItem);
            }
        } else {
            new Relation(getSentence(), handleNewArray(variableDeclaratorI), varItem);
        }
    }
    expectingTypeInfo.clear();
    return 0;
}

std::any StatementVisitor::visitStatementBlock(JavaParser::StatementBlockContext* ctx) {
    visitStatementBlock(ctx->block());
    return 0;
}

void StatementVisitor::visitStatementBlock(JavaParser::BlockContext* ctx) {
    methodScopeAndEnv->codeBlockScopeAndEnvs.push_front(new CodeBlockScopeAndEnv());
    for (auto* statement : ctx->blockStatement()) {
        (*statementBlockStateCount)++;
        StatementVisitor* visitor = StatementVisitor::getInstanceFromCopy(this);
        visitor->codeBlock = codeBlock;
        visitor->sentenceIndex = (*statementBlockStateCount);
        statement->accept(visitor);
        StatementVisitor::returnToPool(visitor);
    }
    methodScopeAndEnv->codeBlockScopeAndEnvs.pop_front();
}

int StatementVisitor::visitInitBlockForClass(JavaParser::BlockContext* ctx, int stateCount) {
    methodScopeAndEnv->codeBlockScopeAndEnvs.push_front(new CodeBlockScopeAndEnv());
    for (auto* statement : ctx->blockStatement()) {
        stateCount--;
        StatementVisitor* visitor = StatementVisitor::getInstanceFromCopy(this);
        visitor->codeBlock = codeBlock;
        visitor->sentenceIndex = stateCount;
        statement->accept(visitor);
        StatementVisitor::returnToPool(visitor);
    }
    methodScopeAndEnv->codeBlockScopeAndEnvs.pop_front();
    return stateCount;
}

std::any StatementVisitor::visitStatementAssert(JavaParser::StatementAssertContext* ctx) {
    unhandledError();
    return 0;
}

std::any StatementVisitor::visitStatementIf(JavaParser::StatementIfContext* ctx) {
    auto* codeStructureVisitor = StructuralVisitor::getInstanceFromCopy(this);
    codeStructureVisitor->outerCodeBlock = codeBlock;
    codeStructureVisitor->sentenceIndexInOuterCodeBlock = sentenceIndex;
    codeStructureVisitor->visitStatementIf(ctx);
    StructuralVisitor::returnToPool(codeStructureVisitor);
    return 0;
}

std::any StatementVisitor::visitStatementFor(JavaParser::StatementForContext* ctx) {
    auto* codeStructureVisitor = StructuralVisitor::getInstanceFromCopy(this);
    codeStructureVisitor->outerCodeBlock = codeBlock;
    codeStructureVisitor->sentenceIndexInOuterCodeBlock = sentenceIndex;
    codeStructureVisitor->visitStatementFor(ctx);
    StructuralVisitor::returnToPool(codeStructureVisitor);
    return 0;
}

std::any StatementVisitor::visitStatementWhile(JavaParser::StatementWhileContext* ctx) {
    auto* codeStructureVisitor = StructuralVisitor::getInstanceFromCopy(this);
    codeStructureVisitor->outerCodeBlock = codeBlock;
    codeStructureVisitor->sentenceIndexInOuterCodeBlock = sentenceIndex;
    codeStructureVisitor->visitStatementWhile(ctx);
    StructuralVisitor::returnToPool(codeStructureVisitor);
    return 0;
}

std::any StatementVisitor::visitStatementDoWhile(JavaParser::StatementDoWhileContext* ctx) {
    auto* codeStructureVisitor = StructuralVisitor::getInstanceFromCopy(this);
    codeStructureVisitor->outerCodeBlock = codeBlock;
    codeStructureVisitor->sentenceIndexInOuterCodeBlock = sentenceIndex;
    codeStructureVisitor->visitStatementDoWhile(ctx);
    StructuralVisitor::returnToPool(codeStructureVisitor);
    return 0;
}

std::any StatementVisitor::visitStatementSwitch(JavaParser::StatementSwitchContext* ctx) {
    auto* codeStructureVisitor = StructuralVisitor::getInstanceFromCopy(this);
    codeStructureVisitor->outerCodeBlock = codeBlock;
    codeStructureVisitor->sentenceIndexInOuterCodeBlock = sentenceIndex;
    codeStructureVisitor->visitStatementSwitch(ctx);
    StructuralVisitor::returnToPool(codeStructureVisitor);
    return 0;
}

std::any StatementVisitor::visitStatementTry(JavaParser::StatementTryContext* ctx) {
    auto* codeStructureVisitor = StructuralVisitor::getInstanceFromCopy(this);
    codeStructureVisitor->outerCodeBlock = codeBlock;
    codeStructureVisitor->sentenceIndexInOuterCodeBlock = sentenceIndex;
    codeStructureVisitor->visitStatementTry(ctx);
    StructuralVisitor::returnToPool(codeStructureVisitor);
    return 0;
}

std::any StatementVisitor::visitStatementSync(JavaParser::StatementSyncContext* ctx) {
    visitStatementBlock(ctx->block());
    return 0;
}

std::any StatementVisitor::visitStatementReturn(JavaParser::StatementReturnContext* ctx) {
    if (ctx->expression() != nullptr) {
        const any& itemOrNull = ctx->expression()->accept(this);
        if (abort) {
            return nullptr;
        }
        auto* item = any_cast<ResolvingItem*>(itemOrNull);
        auto* ret = ResolvingItem::getInstance2(methodScopeAndEnv->returnFieldInfo->fieldKey, methodScopeAndEnv->returnFieldInfo->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_METHOD_RETURN);
        // method return
        new Relation(getSentence(), item, ret);
        codeBlock->has_return_sentence = true;
    }
    return 0;
}

std::any StatementVisitor::visitStatementThrow(JavaParser::StatementThrowContext* ctx) {
    return 0;
}

std::any StatementVisitor::visitStatementBreak(JavaParser::StatementBreakContext* ctx) {
    return 0;
}

std::any StatementVisitor::visitStatementContinue(JavaParser::StatementContinueContext* ctx) {
    return 0;
}

std::any StatementVisitor::visitStatementYield(JavaParser::StatementYieldContext* ctx) {
    const any& itemOrNull = ctx->expression()->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* item = any_cast<ResolvingItem*>(itemOrNull);
    auto* ret = ResolvingItem::getInstance2(methodScopeAndEnv->returnFieldInfo->fieldKey, methodScopeAndEnv->returnFieldInfo->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_METHOD_RETURN);
    // method yield
    new Relation(getSentence(), item, ret);
    codeBlock->has_return_sentence = true;
    return 0;
}

any StatementVisitor::visitStatementSemi(JavaParser::StatementSemiContext* ctx) {
    unhandledError();
    return nullptr;
}

std::any StatementVisitor::visitStatementSwitchExp(JavaParser::StatementSwitchExpContext* ctx) {
    unhandledError();
    return nullptr;
}

any StatementVisitor::visitStatementLabel(JavaParser::StatementLabelContext* ctx) {
    return ctx->statement()->accept(this);
}

std::any StatementVisitor::visitPrimaryExp(JavaParser::PrimaryExpContext* ctx) {
    if (abort) {
        return nullptr;
    }
    return ctx->expression()->accept(this);
}

std::any StatementVisitor::visitPrimaryThis(JavaParser::PrimaryThisContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const FieldInfo* fieldInfo = classScopeAndEnv->name2fieldInfo["this"];
    return ResolvingItem::getInstance2(fieldInfo->fieldKey, fieldInfo->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_FIELD);
}

std::any StatementVisitor::visitPrimarySuper(JavaParser::PrimarySuperContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const FieldInfo* fieldInfo = classScopeAndEnv->name2fieldInfo["super"];
    if (fieldInfo == nullptr) {
        spdlog::get(ErrorManager::DebugTag)->warn("visitPrimarySuper: did not find super for {} in method: {}", classScopeAndEnv->typeInfo->typeKey, methodScopeAndEnv->methodKey);
        return ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->getText()), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
    }
    return ResolvingItem::getInstance2(fieldInfo->fieldKey, fieldInfo->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_FIELD);
}

std::any StatementVisitor::visitPrimaryLiteral(JavaParser::PrimaryLiteralContext* ctx) {
    if (abort) {
        return nullptr;
    }
    string key;
    TypeInfo* literalTypeInfo;
    int keyType = GlobalInfo::KEY_TYPE_FINAL;
    if (ctx->literal()->integerLiteral() != nullptr) {
        key = "final:" + ctx->literal()->integerLiteral()->getText();
        literalTypeInfo = AddressableInfo::primitive_intTypeInfo;
    } else if (ctx->literal()->floatLiteral() != nullptr) {
        key = "final:" + ctx->literal()->floatLiteral()->getText();
        literalTypeInfo = AddressableInfo::primitive_floatTypeInfo;
    } else if (ctx->literal()->CHAR_LITERAL() != nullptr) {
        key = "final:" + REPLACE_QUOTATION_MARKS(ctx->literal()->CHAR_LITERAL()->getText());
        literalTypeInfo = AddressableInfo::primitive_charTypeInfo;
    } else if (ctx->literal()->STRING_LITERAL() != nullptr) {
        key = "final:" + REPLACE_QUOTATION_MARKS(ctx->literal()->STRING_LITERAL()->getText());
        literalTypeInfo = AddressableInfo::stringTypeInfo;
    } else if (ctx->literal()->TEXT_BLOCK() != nullptr) {
        key = "final:" + REPLACE_QUOTATION_MARKS(ctx->literal()->TEXT_BLOCK()->getText());
        literalTypeInfo = AddressableInfo::stringTypeInfo;
    } else if (ctx->literal()->BOOL_LITERAL() != nullptr) {
        key = ctx->literal()->BOOL_LITERAL()->getText();
        literalTypeInfo = AddressableInfo::primitive_boolTypeInfo;
        keyType = GlobalInfo::KEY_TYPE_KEY_WORD_VALUE;
    } else if (ctx->literal()->NULL_LITERAL() != nullptr) {
        key = "null";
        literalTypeInfo = AddressableInfo::nullTypeInfo;
        keyType = GlobalInfo::KEY_TYPE_KEY_WORD_VALUE;
    }
    return ResolvingItem::getInstance2(key, literalTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), keyType);
}

std::any StatementVisitor::visitPrimaryIdentifier(JavaParser::PrimaryIdentifierContext* ctx) {
    if (abort) {
        return nullptr;
    }
    string key;
    TypeInfo* typeInfo = NULL;
    int keyType;
    map<TypeInfo*, TypeInfo*> typeArgs;
    if (methodScopeAndEnv->findIdWithFileScope(ctx->identifier()->getText(), key, typeInfo, keyType, &typeArgs)) {
        auto item = ResolvingItem::getInstance2(key, typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), keyType);
        item->typeArgs = typeArgs;
        return item;
    } else {
        return ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->identifier()->getText()), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
    }
}

std::any StatementVisitor::visitPrimaryClass(JavaParser::PrimaryClassContext* ctx) {
    if (abort) {
        return nullptr;
    }
    TypeName typeName;
    AntlrNodeToSyntaxObjectConverter::convertTypeTypeOrVoid(ctx->typeTypeOrVoid(), &typeName);
    TypeInfo* typeInfo = classScopeAndEnv->getTypeInfoWithFileScope(typeName.typeName);
    if (typeInfo == nullptr) {
        spdlog::get(ErrorManager::DebugTag)->warn("visitPrimaryClass: did not find type name: {} in method: {}", joinList(typeName.typeName, "."), methodScopeAndEnv->methodKey);
        return ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->getText()), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
    }
    return ResolvingItem::getInstance2(typeInfo->typeKey + ".class", AddressableInfo::classTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_FIELD);
}

std::any StatementVisitor::visitPrimaryMethodCallWithExplicitTypeArgument(JavaParser::PrimaryMethodCallWithExplicitTypeArgumentContext* ctx) {
    if (abort) {
        return nullptr;
    }
    NameAndRelatedExp methodCall;
    AntlrNodeToSyntaxObjectConverter::convertMethodCallWithExplicitTypeArgument(ctx, &methodCall);
    return resolveMethod(methodCall, classScopeAndEnv);
}

std::any StatementVisitor::visitExpressionReference(JavaParser::ExpressionReferenceContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull = ctx->expression()->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* referencedBy = any_cast<ResolvingItem*>(itemOrNull);
    if (not referencedBy or not referencedBy->typeInfo) {
        return ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->getText()), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
    }
    if (referencedBy->keyType == GlobalInfo::KEY_TYPE_ERROR) {
        unhandledError();
        return NULL;
    }
    addTypeArgForResolvingItem(referencedBy);
    if (referencedBy->typeInfo->isTypeParam and typeUnification.getTypeArgFromTypeParam(referencedBy->typeInfo)) {
        referencedBy->typeInfo = typeUnification.getTypeArgFromTypeParam(referencedBy->typeInfo);
    }
    if (not referencedBy->typeInfo or not referencedBy->typeInfo->classScopeAndEnv) {
        unhandledError();
        return nullptr;
    }
    auto* referencedScope = referencedBy->typeInfo->classScopeAndEnv;
    classScopeAndEnv->addUsage(referencedBy->typeInfo);
    auto* resolvingItem = ResolvingItem::getInstance2();
    if (ctx->identifier() != nullptr) {
        if (!referencedScope->findIdFromSelf(ctx->identifier()->getText(), resolvingItem->variableKey, resolvingItem->typeInfo, resolvingItem->keyType)) {
            spdlog::get(ErrorManager::DebugTag)->warn("visitExpressionReference: did not find id for name: {} referenced by {} in method: {}", ctx->identifier()->getText(), referencedBy->typeInfo->typeKey, methodScopeAndEnv->methodKey);
            return ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->getText()), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
        }
        resolvingItem->referencedBy = referencedBy;
        resolvingItem->set(resolvingItem->variableKey, resolvingItem->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), resolvingItem->keyType);
    } else if (ctx->methodCall() != nullptr) {
        NameAndRelatedExp methodCall;
        AntlrNodeToSyntaxObjectConverter::convertMethodCall(ctx->methodCall(), &methodCall);
        ResolvingItem* calledMethodResolvingItem = ResolvingItem::getInstance2();
        calledMethodResolvingItem->referencedBy = referencedBy;
        resolveMethod(methodCall, referencedScope, resolvingItem, calledMethodResolvingItem);
        if (abort) {
            return nullptr;
        }
    } else if (ctx->THIS() != nullptr) {
        resolvingItem->set(referencedBy->variableKey + ".this", referencedBy->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_FIELD);
        resolvingItem->referencedBy = referencedBy;
    } else if (ctx->NEW() != nullptr) {
        NameAndRelatedExp methodCall;
        AntlrNodeToSyntaxObjectConverter::convertInnerCreator(ctx->innerCreator(), &methodCall);
        ResolvingItem* calledMethodResolvingItem = ResolvingItem::getInstance2();
        calledMethodResolvingItem->referencedBy = referencedBy;
        resolveMethod(methodCall, referencedScope, resolvingItem, calledMethodResolvingItem, true);
        if (abort) {
            return nullptr;
        }
    } else if (ctx->SUPER() != nullptr) {
        NameAndRelatedExp methodCall;
        AntlrNodeToSyntaxObjectConverter::convertSuperSuffix(ctx->superSuffix(), &methodCall);
        ResolvingItem* calledMethodResolvingItem = ResolvingItem::getInstance2();
        calledMethodResolvingItem->referencedBy = referencedBy;
        resolveMethod(methodCall, referencedScope, resolvingItem, calledMethodResolvingItem);
        if (abort) {
            return nullptr;
        }
    } else if (ctx->explicitGenericInvocation() != nullptr) {
        NameAndRelatedExp methodCall;
        AntlrNodeToSyntaxObjectConverter::convertExplicitGenericInvocationSuffix(ctx->explicitGenericInvocation()->explicitGenericInvocationSuffix(), &methodCall);
        ResolvingItem* calledMethodResolvingItem = ResolvingItem::getInstance2();
        calledMethodResolvingItem->referencedBy = referencedBy;
        resolveMethod(methodCall, referencedScope, resolvingItem, calledMethodResolvingItem);
        if (abort) {
            return nullptr;
        }
    }
    if (resolvingItem->typeInfo->isTypeParam and typeUnification.getTypeArgFromTypeParam(resolvingItem->typeInfo)) {
        resolvingItem->typeInfo = typeUnification.getTypeArgFromTypeParam(resolvingItem->typeInfo);
    }
    return resolvingItem;
}

std::any StatementVisitor::visitExpressionArrayAccess(JavaParser::ExpressionArrayAccessContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull1 = ctx->e1->accept(this);
    const any& itemOrNull2 = ctx->e2->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* indexedItem = any_cast<ResolvingItem*>(itemOrNull1);
    auto* indexItem = any_cast<ResolvingItem*>(itemOrNull2);
    indexedItem->indexedBy = indexItem;
    return indexedItem;
}

std::any StatementVisitor::visitExpressionMethodCall(JavaParser::ExpressionMethodCallContext* ctx) {
    if (abort) {
        return nullptr;
    }
    if (ctx->methodCall()->THIS() or ctx->methodCall()->SUPER()) {
        return 0;
    }
    NameAndRelatedExp methodCall;
    AntlrNodeToSyntaxObjectConverter::convertMethodCall(ctx->methodCall(), &methodCall);
    return resolveMethod(methodCall, classScopeAndEnv);
}

std::any StatementVisitor::visitExpressionNew(JavaParser::ExpressionNewContext* ctx) {
    if (abort) {
        return nullptr;
    }
    NameAndRelatedExp methodCall;
    AntlrNodeToSyntaxObjectConverter::convertCreator(ctx->creator(), &methodCall);
    if (methodCall.dim > 0) {
        return handleNewArray(methodCall);
    } else {
        if (ctx->creator()->classCreatorRest() and ctx->creator()->classCreatorRest()->classBody()) {
            TypeInfo* typeInfo = classScopeAndEnv->getTypeInfoWithFileScope(methodCall.name);
            if (typeInfo) {
                AnonymousVisitor* anonymousVisitor = AnonymousVisitor::getInstance();
                anonymousVisitor->copyFrom(this);
                anonymousVisitor->outerMethodScopeAndEnv = methodScopeAndEnv;
                anonymousVisitor->superTypeInfo = typeInfo;
                anonymousVisitor->positionKey = methodScopeAndEnv->methodKey + codeBlock->structure_key + ";" + to_string(sentenceIndex) + ";" + getIncreasedIndexInsideExp();
                anonymousVisitor->makeTypeInfo();
                anonymousVisitor->makeClassScopeEnv();
                anonymousVisitor->visitForMembers(ctx->creator()->classCreatorRest()->classBody());
                anonymousVisitor->visitClassBody(ctx->creator()->classCreatorRest()->classBody());
                auto calledReturnItem = resolveMethod(methodCall, classScopeAndEnv, true);
                auto anonymousItem = ResolvingItem::getInstance2(anonymousVisitor->typeInfo->typeKey, anonymousVisitor->typeInfo,
                    codeBlock->structure_key, getSentence()->sentenceIndexStr,
                    getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ANONYMOUS_CLASS
                );
                new Relation(getSentence(), calledReturnItem, anonymousItem);
                AnonymousVisitor::returnToPool(anonymousVisitor);
                return anonymousItem;
            } else {
                unhandledError();
                return NULL;
            }
        } else {
            return resolveMethod(methodCall, classScopeAndEnv, true);
        }
    }
}

std::any StatementVisitor::visitExpressionCast(JavaParser::ExpressionCastContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull = ctx->expression()->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* itemToBeCast = any_cast<ResolvingItem*>(itemOrNull);
    TypeName typeName;
    AntlrNodeToSyntaxObjectConverter::convertTypeType(ctx->typeType().front(), &typeName);
    TypeInfo* pTypeInfo = methodScopeAndEnv->getTypeInfoWithFileScope(typeName.typeName);
    if (pTypeInfo == nullptr) {
        spdlog::get(ErrorManager::DebugTag)->warn("visitExpressionCast: did not find cast type name: {} in method: {}", joinList(typeName.typeName, "."), methodScopeAndEnv->methodKey);
        return ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(ctx->typeType().front()->getText()), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
    }
    itemToBeCast->typeInfo = pTypeInfo;
    if (pTypeInfo->typeParamInfos.size() == typeName.typeArgs.size()) {
        for (int i = 0;i < typeName.typeArgs.size();i++) {
            TypeInfo* typeArg = classScopeAndEnv->getTypeInfoWithFileScope(typeName.typeArgs[i]->typeName);
            if (typeArg) {
                typeUnification.addTypeMap(pTypeInfo->typeParamInfos[i], typeArg);
            }
        }
    }
    return itemToBeCast;
}

std::any StatementVisitor::visitExpressionIncDec(JavaParser::ExpressionIncDecContext* ctx) {
    if (abort) {
        return nullptr;
    }
    string optr;
    if (ctx->postfix != nullptr) {
        optr = ctx->postfix->getText();
    } else if (ctx->prefix != nullptr) {
        optr = ctx->prefix->getText();
    }
    const any& itemOrNull = ctx->expression()->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* increasedItem1 = any_cast<ResolvingItem*>(itemOrNull);
    auto* increasedItem2 = ResolvingItem::getInstance2(
        increasedItem1->variableKey,
        increasedItem1->typeInfo,
        increasedItem1->structureKey,
        increasedItem1->sentenceIndex,
        getIncreasedIndexInsideExp(),
        increasedItem1->keyType
    );
    auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_SELF_ASSIGN_RETURN, increasedItem1->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_SELF_ASSIGN_RETURN, optr);
    new Relation(getSentence(), increasedItem1, returnItem);
    new Relation(getSentence(), returnItem, increasedItem2);
    return increasedItem2;
}

std::any StatementVisitor::visitExpressionPosNegSign(JavaParser::ExpressionPosNegSignContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull = ctx->expression()->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* arg = any_cast<ResolvingItem*>(itemOrNull);
    auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_UNARY_RETURN, arg->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_UNARY_RETURN, ctx->prefix->getText());
    new Relation(getSentence(), arg, returnItem);
    return returnItem;
}

std::any StatementVisitor::visitExpressionUnaryLogical(JavaParser::ExpressionUnaryLogicalContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull = ctx->expression()->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* arg = any_cast<ResolvingItem*>(itemOrNull);
    auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_UNARY_RETURN, arg->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_UNARY_RETURN, ctx->prefix->getText());
    new Relation(getSentence(), arg, returnItem);
    return returnItem;
}

std::any StatementVisitor::visitExpressionArithmetical(JavaParser::ExpressionArithmeticalContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull1 = ctx->e1->accept(this);
    const any& itemOrNull2 = ctx->e2->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* arg1 = any_cast<ResolvingItem*>(itemOrNull1);
    auto* arg2 = any_cast<ResolvingItem*>(itemOrNull2);
    const string& optrStr = ctx->bop->getText();
    TypeInfo* returnTypeInfo = arg1->typeInfo;
    if (arg2->typeInfo == AddressableInfo::stringTypeInfo) {
        returnTypeInfo = AddressableInfo::stringTypeInfo;
    }
    auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_RETURN, returnTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_RETURN, optrStr);
    if (optrStr == "*" or optrStr == "+") {
        new Relation(getSentence(), arg1, returnItem);
        new Relation(getSentence(), arg2, returnItem);
    } else {
        auto* param1 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_PARAMETER1, arg1->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_PARAMETER1, getOptrParam(optrStr, 1));
        auto* param2 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_PARAMETER2, arg2->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_PARAMETER2, getOptrParam(optrStr, 2));
        new Relation(getSentence(), arg1, param1);
        new Relation(getSentence(), arg2, param2);
        new Relation(getSentence(), param1, returnItem);
        new Relation(getSentence(), param2, returnItem);
    }
    return returnItem;
}

std::any StatementVisitor::visitExpressionShift(JavaParser::ExpressionShiftContext* ctx) {
    if (abort) {
        return nullptr;
    }
    string optrString;
    if (ctx->bop1 != nullptr) {
        optrString = "<<";
    } else if (ctx->bop2 != nullptr) {
        optrString = ">>>";
    } else if (ctx->bop3 != nullptr) {
        optrString = ">>";
    }
    const any& itemOrNull1 = ctx->e1->accept(this);
    const any& itemOrNull2 = ctx->e2->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* arg1 = any_cast<ResolvingItem*>(itemOrNull1);
    auto* arg2 = any_cast<ResolvingItem*>(itemOrNull2);
    auto* param1 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_PARAMETER1, arg1->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_PARAMETER1, getOptrParam(optrString, 1));
    auto* param2 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_PARAMETER2, arg2->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_PARAMETER2, getOptrParam(optrString, 2));
    auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_ARITHMETIC_RETURN, arg1->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_RETURN, optrString);
    new Relation(getSentence(), arg1, param1);
    new Relation(getSentence(), arg2, param2);
    new Relation(getSentence(), param1, returnItem);
    new Relation(getSentence(), param2, returnItem);
    return returnItem;
}

std::any StatementVisitor::visitExpressionRelational(JavaParser::ExpressionRelationalContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull1 = ctx->e1->accept(this);
    const any& itemOrNull2 = ctx->e2->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* arg1 = any_cast<ResolvingItem*>(itemOrNull1);
    auto* arg2 = any_cast<ResolvingItem*>(itemOrNull2);
    const string& optrStr = ctx->bop->getText();
    auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_RELATION_RETURN, AddressableInfo::primitive_boolTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_RELATION_RETURN, optrStr);
    if (optrStr == "==" or optrStr == "!=") {
        new Relation(getSentence(), arg1, returnItem);
        new Relation(getSentence(), arg2, returnItem);
    } else {
        auto* param1 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_RELATION_PARAMETER1, arg1->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_RELATION_PARAMETER1, getOptrParam(optrStr, 1));
        auto* param2 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_RELATION_PARAMETER2, arg2->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_RELATION_PARAMETER2, getOptrParam(optrStr, 2));
        new Relation(getSentence(), arg1, param1);
        new Relation(getSentence(), arg2, param2);
        new Relation(getSentence(), param1, returnItem);
        new Relation(getSentence(), param2, returnItem);
    }
    return returnItem;
}

std::any StatementVisitor::visitExpressionInstanceOf(JavaParser::ExpressionInstanceOfContext* ctx) {
    if (abort) {
        return nullptr;
    }
    if (ctx->pattern() != nullptr) {
        unhandledError();
        return nullptr;
    } else if (ctx->typeType() != nullptr) {
        const any& itemOrNull = ctx->expression()->accept(this);
        if (abort) {
            return nullptr;
        }
        auto* arg1 = any_cast<ResolvingItem*>(itemOrNull);
        TypeName typeName;
        AntlrNodeToSyntaxObjectConverter::convertTypeType(ctx->typeType(), &typeName);
        TypeInfo* pInfo = methodScopeAndEnv->getTypeInfoWithFileScope(typeName.typeName);
        // handle error
        if (pInfo == nullptr) {
            pInfo = new TypeInfo;
            pInfo->typeName = joinList(typeName.typeName, ".");
            pInfo->typeKey = pInfo->typeName;
            spdlog::get(ErrorManager::DebugTag)->warn("visitExpressionInstanceOf: did not find type name: {} in method: {}", pInfo->typeName, methodScopeAndEnv->methodKey);
        }
        auto* arg2 = ResolvingItem::getInstance2(pInfo->typeKey, pInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_CLASS);
        auto* param1 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_INSTANCE_OF_PARAMETER1, arg1->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_PARAMETER1, getOptrParam(ctx->bop->getText(), 1));
        auto* param2 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_INSTANCE_OF_PARAMETER2, arg2->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_PARAMETER2, getOptrParam(ctx->bop->getText(), 2));
        auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_INSTANCE_OF_RETURN, AddressableInfo::primitive_boolTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_RETURN, ctx->bop->getText());
        new Relation(getSentence(), arg1, param1);
        new Relation(getSentence(), arg2, param2);
        new Relation(getSentence(), param1, returnItem);
        new Relation(getSentence(), param2, returnItem);
        return returnItem;
    }
    return nullptr;
}

std::any StatementVisitor::visitExpressionLogical(JavaParser::ExpressionLogicalContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull1 = ctx->e1->accept(this);
    const any& itemOrNull2 = ctx->e2->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* arg1 = any_cast<ResolvingItem*>(itemOrNull1);
    auto* arg2 = any_cast<ResolvingItem*>(itemOrNull2);
    auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_LOGIC_RETURN, AddressableInfo::primitive_boolTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_LOGIC_RETURN, ctx->bop->getText());
    new Relation(getSentence(), arg1, returnItem);
    new Relation(getSentence(), arg2, returnItem);
    return returnItem;
}

std::any StatementVisitor::visitExpressionConditional(JavaParser::ExpressionConditionalContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull1 = ctx->e1->accept(this);
    const any& itemOrNull2 = ctx->e2->accept(this);
    const any& itemOrNull3 = ctx->e3->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* arg1 = any_cast<ResolvingItem*>(itemOrNull1);
    auto* arg2 = any_cast<ResolvingItem*>(itemOrNull2);
    auto* arg3 = any_cast<ResolvingItem*>(itemOrNull3);
    auto* param1 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER1, arg1->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER1, getOptrParam(ctx->bop->getText(), 1));
    auto* param2 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER2, arg2->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER2, getOptrParam(ctx->bop->getText(), 2));
    auto* param3 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_CONDITIONAL_PARAMETER3, arg3->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER3, getOptrParam(ctx->bop->getText(), 3));
    auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_CONDITIONAL_RETURN, arg3->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_RETURN, ctx->bop->getText());
    new Relation(getSentence(), arg1, param1);
    new Relation(getSentence(), arg2, param2);
    new Relation(getSentence(), arg3, param3);
    new Relation(getSentence(), param1, returnItem);
    new Relation(getSentence(), param2, returnItem);
    new Relation(getSentence(), param3, returnItem);
    return returnItem;
}

std::any StatementVisitor::visitExpressionAssign(JavaParser::ExpressionAssignContext* ctx) {
    if (abort) {
        return nullptr;
    }
    const any& itemOrNull1 = ctx->e1->accept(this);
    if (abort) {
        return nullptr;
    }
    auto* assignedItem1 = any_cast<ResolvingItem*>(itemOrNull1);
    auto* assignedItem2 = ResolvingItem::getInstance2(
        assignedItem1->variableKey,
        assignedItem1->typeInfo,
        assignedItem1->structureKey,
        assignedItem1->sentenceIndex,
        getIncreasedIndexInsideExp(),
        assignedItem1->keyType
    );
    expectingTypeInfo.clear();
    expectingTypeInfo.push_back(assignedItem1->typeInfo);
    const any& itemOrNull2 = ctx->e2->accept(this);
    expectingTypeInfo.clear();
    if (abort) {
        return nullptr;
    }
    auto* item2 = any_cast<ResolvingItem*>(itemOrNull2);
    if (ctx->bop->getText().size() > 1) {
        auto* param1 = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_SELF_ASSIGN_PARAMETER1, item2->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_SELF_ASSIGN_PARAMETER1, getOptrParam(ctx->bop->getText(), 1));
        auto* returnItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_OPTR_SELF_ASSIGN_RETURN, assignedItem1->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_OPTR_SELF_ASSIGN_RETURN, ctx->bop->getText());
        new Relation(getSentence(), item2, param1);
        new Relation(getSentence(), param1, returnItem);
        new Relation(getSentence(), assignedItem1, returnItem);
        new Relation(getSentence(), returnItem, assignedItem2);
    } else {
        new Relation(getSentence(), item2, assignedItem1);
    }
    return item2;
}

any StatementVisitor::visitExpressionLambda(JavaParser::ExpressionLambdaContext* ctx) {
    if (abort) {
        return nullptr;
    }
    list<string> paramNames;
    AntlrNodeToSyntaxObjectConverter::convertLambdaParameters(ctx->lambdaExpression()->lambdaParameters(), paramNames);
    for (auto& interfaceType : expectingTypeInfo) {
        if (Modifier::isInterfaceType(interfaceType->flag)) {
            MethodInfo* m = NULL;
            MethodInfo* constructor = NULL;
            list<TypeInfo*> interfaceInfos;
            getAllInterfaceRecurSuper(interfaceType, interfaceInfos);
            for (auto& interfaceI : interfaceInfos) {
                m = interfaceI->getOnlyMethodFromInterface();
                if (m and m->parameterInfos.size() != paramNames.size()) {
                    m = NULL;
                }
                if (m) {
                    auto constructors = interfaceI->getConstructor(0);
                    if (constructors.size()) {
                        constructor = constructors.front();
                    }
                    break;
                }
            }
            // found the right interface and method
            if (m and constructor) {
                AnonymousVisitor* anonymousVisitor = AnonymousVisitor::getInstance();
                anonymousVisitor->copyFrom(this);
                anonymousVisitor->outerMethodScopeAndEnv = methodScopeAndEnv;
                anonymousVisitor->superTypeInfo = interfaceType;
                anonymousVisitor->positionKey = methodScopeAndEnv->methodKey + codeBlock->structure_key + ";" + to_string(sentenceIndex) + ";" + getIncreasedIndexInsideExp();
                anonymousVisitor->makeTypeInfo();
                anonymousVisitor->makeClassScopeEnv();
                anonymousVisitor->visitLambda(ctx->lambdaExpression(), m, paramNames);

                ResolvingItem* calledReturnResolvingItem = ResolvingItem::getInstance2();
                ResolvingItem* calledMethodResolvingItem = ResolvingItem::getInstance2();
                handleMethodInfo(constructor, {}, calledReturnResolvingItem, calledMethodResolvingItem);

                auto anonymousItem = ResolvingItem::getInstance2(anonymousVisitor->typeInfo->typeKey, anonymousVisitor->typeInfo,
                    codeBlock->structure_key, getSentence()->sentenceIndexStr,
                    getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ANONYMOUS_CLASS
                );
                new Relation(getSentence(), calledReturnResolvingItem, anonymousItem);
                AnonymousVisitor::returnToPool(anonymousVisitor);
                return anonymousItem;
            }
        }
    }
    unhandledError();
    return nullptr;
}

any StatementVisitor::visitExpressionSwitch(JavaParser::ExpressionSwitchContext* ctx) {
    if (abort) {
        return nullptr;
    }
    unhandledError();
    return nullptr;
}

any StatementVisitor::visitExpressionMethodReference(JavaParser::ExpressionMethodReferenceContext* ctx) {
    if (abort) {
        return nullptr;
    }
    if (expectingTypeInfo.empty()) {
        unhandledError();
        return NULL;
    }
    TypeInfo* typeInfo = NULL;
    string methodName = "";
    if (ctx->expression()) {
        const any& itemOrNull = ctx->expression()->accept(this);
        if (abort) {
            return nullptr;
        }
        auto* item = any_cast<ResolvingItem*>(itemOrNull);
        typeInfo = item->typeInfo;
        if (ctx->identifier()) {
            methodName = ctx->identifier()->getText();
        }
    } else if (ctx->typeType()) {
        TypeName typeName;
        AntlrNodeToSyntaxObjectConverter::convertTypeType(ctx->typeType(), &typeName);
        typeInfo = classScopeAndEnv->getTypeInfoWithFileScope(typeName.typeName);
        if (ctx->identifier()) {
            methodName = ctx->identifier()->getText();
        }
    } else if (ctx->classType()) {
        TypeName typeName;
        AntlrNodeToSyntaxObjectConverter::convertClassOrInterfaceType(ctx->classType()->classOrInterfaceType(), &typeName);
        if (ctx->classType()->identifier()) {
            typeName.typeName.push_back(ctx->classType()->identifier()->getText());
        }
        typeInfo = classScopeAndEnv->getTypeInfoWithFileScope(typeName.typeName);
    }
    bool isConstructor = ctx->NEW() != NULL;
    if (typeInfo and typeInfo->classScopeAndEnv) {
        for (auto& expectedInterface : expectingTypeInfo) {
            list<TypeInfo*> interfaceInfos;
            getAllInterfaceRecurSuper(expectedInterface, interfaceInfos);
            for (auto* interaceI : interfaceInfos) {
                MethodInfo* expectedMethod = interaceI->getOnlyMethodFromInterface();
                if (not expectedMethod) {
                    continue;
                }
                int paramCount = expectedMethod->parameterInfos.size();
                list<MethodInfo*> methods;
                if (isConstructor) {
                    typeInfo->classScopeAndEnv->getMethodInfoFromSelf(typeInfo->simpletypeName, paramCount, methods);
                } else {
                    typeInfo->classScopeAndEnv->getMethodInfoFromSelf(methodName, paramCount, methods);
                }
                if (not methods.empty()) {
                    return ResolvingItem::getInstance2(methods.front()->methodKey, interaceI, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_METHOD_REFERENCE);
                }
            }
        }
    }
    unhandledError();
    return nullptr;
}

ResolvingItem* StatementVisitor::handleNewArray(NameAndRelatedExp& methodCall) {
    // todo init array
    auto* typeInfo = classScopeAndEnv->getTypeInfoWithFileScope(methodCall.name);
    auto* ret = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ARRAY_INIT, typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ARRAY_INIT, GlobalInfo::GLOBAL_KEY_ARRAY_INIT);
    if (methodCall.arrayInitValues) {
        iterNDimArrayRecur(ret, methodCall.arrayInitValues, methodCall.dim, GlobalInfo::GLOBAL_KEY_ARRAY_INIT);
    }
    if (methodCall.initExpression) {
        const any& itemOrNull = methodCall.initExpression->accept(this);
        ResolvingItem* valueItem = NULL;
        if (abort) {
            valueItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(methodCall.initExpression->getText()),
                AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
            abort = false;
        } else {
            valueItem = any_cast<ResolvingItem*>(itemOrNull);
        }
        new Relation(getSentence(), valueItem, ret);
    }
    return ret;
}


void StatementVisitor::iterNDimArrayRecur(ResolvingItem* superDimItem, JavaParser::ArrayInitializerContext* ctx, int dim, const string& key) {
    // ctx->variableInitializer().empty()
    // private int[][] mIndexMatrix = {};
    // private float[][] mDistanceMatrix = {};      
    if (dim == 1 or (not ctx->variableInitializer().empty() and ctx->variableInitializer(0)->arrayInitializer() == nullptr)) {
        for (auto* varInit : ctx->variableInitializer()) {
            const any& itemOrNull = varInit->expression()->accept(this);
            ResolvingItem* valueItem = NULL;
            if (abort) {
                valueItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(varInit->expression()->getText()),
                    AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
                abort = false;
            } else {
                valueItem = any_cast<ResolvingItem*>(itemOrNull);
            }
            new Relation(getSentence(), valueItem, superDimItem);
        }
    } else {
        for (int i = 0;i < ctx->variableInitializer().size();i++) {
            string key2 = key + "_" + to_string(i);
            auto* initItem = ResolvingItem::getInstance2(key2, superDimItem->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ARRAY_INIT, key2);
            new Relation(getSentence(), initItem, superDimItem);
            iterNDimArrayRecur(initItem, ctx->variableInitializer(i)->arrayInitializer(), dim - 1, key2);
        }
    }
}

ResolvingItem* StatementVisitor::resolveMethod(NameAndRelatedExp& methodCall, ClassScopeAndEnv* scopeAndEnv, bool creator) {
    ResolvingItem* calledReturnResolvingItem = ResolvingItem::getInstance2();
    ResolvingItem* calledMethodResolvingItem = ResolvingItem::getInstance2();
    resolveMethod(methodCall, scopeAndEnv, calledReturnResolvingItem, calledMethodResolvingItem, creator);
    return calledReturnResolvingItem;
}

void StatementVisitor::resolveMethod(NameAndRelatedExp& methodCall, ClassScopeAndEnv* scopeAndEnv, ResolvingItem* returnResolvingItem, ResolvingItem* calledMethodResolvingItem, bool creator) {
    if (abort) {
        return;
    }
    list<MethodInfo*> methodInfos;
    int paramCount = methodCall.arguments == nullptr ? 0 : methodCall.arguments->expression().size();
    scopeAndEnv->getMethodInfoWithFileScope(methodCall.name, paramCount, methodInfos, creator);
    vector<ResolvingItem*> argValueResolvingItems;
    if (methodCall.arguments != nullptr) {
        int paramIndex = 0;
        for (auto* expression : methodCall.arguments->expression()) {
            expectingTypeInfo.clear();
            for (auto& methodInfo : methodInfos) {
                if (not methodInfo->isVariableParameter) {
                    expectingTypeInfo.push_back(methodInfo->parameterInfos[paramIndex]->typeInfo);
                    for (auto& typeArg : methodInfo->parameterInfos[paramIndex]->typeParam2typeArg) {
                        typeUnification.addTypeMap(typeArg.first, typeArg.second);
                    }
                }
            }
            const any& itemOrNull = expression->accept(this);
            expectingTypeInfo.clear();
            ResolvingItem* argResolvingItem = NULL;
            if (abort) {
                argResolvingItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(expression->getText()),
                    AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
                abort = false;
            } else {
                argResolvingItem = any_cast<ResolvingItem*>(itemOrNull);
            }
            for (auto& methodInfo : methodInfos) {
                if (not methodInfo->isVariableParameter) {
                    if (methodInfo->parameterInfos[paramIndex]->typeInfo->isTypeParam) {
                        typeUnification.addTypeMap(methodInfo->parameterInfos[paramIndex]->typeInfo, argResolvingItem->typeInfo);
                    } else {
                        addTypeArgForResolvingItem(argResolvingItem);
                    }
                }
            }
            argValueResolvingItems.push_back(argResolvingItem);
            paramIndex++;
        }
    }
    // error handling
    if (methodInfos.empty()) {
        string errorMethodName = joinList(methodCall.name, ".");
        string errorMethodReturn = AddressableInfo::makeReturnKey(errorMethodName);
        returnResolvingItem->set(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(errorMethodName), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
        calledMethodResolvingItem->set(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(errorMethodReturn), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
        int argCount = 1;
        for (auto& arg : argValueResolvingItems) {
            ResolvingItem* calledParamResolvingItem = ResolvingItem::getInstance2(GlobalInfo::GLOBAL_KEY_ERROR + REPLACE_QUOTATION_MARKS(errorMethodName) + ":::P" + to_string(argCount), AddressableInfo::errorTypeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_ERROR);
            new Relation(getSentence(), arg, calledParamResolvingItem);
            new Relation(getSentence(), calledParamResolvingItem, calledMethodResolvingItem);
            argCount++;
        }
        new Relation(getSentence(), calledMethodResolvingItem, returnResolvingItem);
        spdlog::get(ErrorManager::DebugTag)->warn("did not find method name: {} with {} params in method:{}", joinList(methodCall.name, "."), paramCount, methodScopeAndEnv->methodKey);
        return;
    }
    MethodInfo* methodInfo;
    if (argValueResolvingItems.empty()) {
        methodInfo = methodInfos.front();
    } else {
        methodInfo = TypeCheckAndInference::findBestMethod(methodInfos, argValueResolvingItems);
    }
    handleMethodInfo(methodInfo, argValueResolvingItems, returnResolvingItem, calledMethodResolvingItem);
}

void StatementVisitor::handleMethodInfo(MethodInfo* methodInfo, const vector<ResolvingItem*>& argValueResolvingItems, ResolvingItem* returnResolvingItem, ResolvingItem* calledMethodResolvingItem) {
    string indexInsideExpForMethod = getIncreasedIndexInsideExp();
    string& returnKey = methodInfo->returnInfo->fieldKey;
    string& calledReturnKey = methodInfo->calledReturnInfo->fieldKey;
    returnResolvingItem->set(calledReturnKey, methodInfo->returnInfo->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, indexInsideExpForMethod, GlobalInfo::KEY_TYPE_CALLED_RETURN);
    returnResolvingItem->extraInfoMethodKey = methodInfo->methodKey;
    returnResolvingItem->extraInfoReturnKey = returnKey;
    calledMethodResolvingItem->set(methodInfo->calledMethodKey, methodInfo->returnInfo->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, indexInsideExpForMethod, GlobalInfo::KEY_TYPE_CALLED_METHOD);
    calledMethodResolvingItem->extraInfoMethodKey = methodInfo->methodKey;
    if (not argValueResolvingItems.empty()) {
        int paramIndex = 0;
        ResolvingItem* lastCalledParamResolvingItem = NULL;
        for (auto& arg : argValueResolvingItems) {
            bool variableParameter = false;
            if (paramIndex >= methodInfo->parameterInfos.size()) {
                paramIndex--;
                variableParameter = true;
            }
            const string& paramKey = methodInfo->parameterInfos[paramIndex]->fieldKey;
            FieldInfo*& calledParam = methodInfo->calledParamInfos[paramIndex];
            ResolvingItem* calledParamResolvingItem = variableParameter ? lastCalledParamResolvingItem : ResolvingItem::getInstance2(calledParam->fieldKey, calledParam->typeInfo, codeBlock->structure_key, getSentence()->sentenceIndexStr, indexInsideExpForMethod, GlobalInfo::KEY_TYPE_CALLED_PARAMETER);
            calledParamResolvingItem->extraInfoMethodKey = methodInfo->methodKey;
            calledParamResolvingItem->extraInfoParameterKey = paramKey;
            // value to called parameter
            new Relation(getSentence(), arg, calledParamResolvingItem);
            if (not variableParameter) {
                // called parameter to called method
                new Relation(getSentence(), calledParamResolvingItem, calledMethodResolvingItem);
            }
            paramIndex++;
            lastCalledParamResolvingItem = calledParamResolvingItem;
        }
    }
    // called method to called return
    new Relation(getSentence(), calledMethodResolvingItem, returnResolvingItem);
}

void StatementVisitor::getAllInterfaceRecurSuper(TypeInfo* interfaceInfo, list<TypeInfo*>& interfaceInfos) {
    if (Modifier::isInterfaceType(interfaceInfo->flag)) {
        interfaceInfos.push_back(interfaceInfo);
        for (auto& s : interfaceInfo->superTypeInfos) {
            if (Modifier::isInterfaceType(s->flag)) {
                getAllInterfaceRecurSuper(s, interfaceInfos);
            }
        }
        for (auto& s : interfaceInfo->interfaceInfos) {
            if (Modifier::isInterfaceType(s->flag)) {
                getAllInterfaceRecurSuper(s, interfaceInfos);
            }
        }
    }
}

std::any InitializerVisitor::visitClassBody(JavaParser::ClassBodyContext* ctx) {
    classBody = ctx;
    for (JavaParser::ClassBodyDeclarationContext* ctxI : ctx->classBodyDeclaration()) {
        if (ctxI->memberDeclaration() and ctxI->memberDeclaration()->constructorDeclaration()) {
            ctxI->memberDeclaration()->constructorDeclaration()->accept(this);
        }
    }
    return 0;
}

std::any InitializerVisitor::visitConstructorDeclaration(JavaParser::ConstructorDeclarationContext* ctx) {
    if (ctx->constructorBody) {
        if (ctx->constructorBody->blockStatement().size() > 0) {
            Method method;
            AntlrNodeToSyntaxObjectConverter::convertConstructorDeclaration(ctx, &method);
            set<string> typeParameters;
            FOR_EACH_ITEM(method.typeParams, typeParameters.insert(item->name););

            list<string> parameterTypes;
            int paramIndex = 0;
            for (auto& item : method.parameters) {
                TypeInfo* parameterTypeInfo = classScopeAndEnv->getTypeInfoWithFileScope(item->typeName->typeName);
                string paramTypeName;
                int dim = item->typeName->dim;
                if (method.isVariableParameter and paramIndex == method.parameters.size() - 1) {
                    dim += 1;
                }
                string arrayPostFix = getArrayPostFix(dim);
                if (parameterTypeInfo) {
                    if (parameterTypeInfo->typeKey.size() == joinList(item->typeName->typeName, ".").size()) {
                        paramTypeName = parameterTypeInfo->typeKey + arrayPostFix;
                    } else {
                        paramTypeName = parameterTypeInfo->typeName + arrayPostFix;
                    }
                } else if (item->typeName->typeName.size() == 1 and typeParameters.count(item->typeName->typeName.back())) {
                    paramTypeName = item->typeName->typeName.back() + arrayPostFix;
                }
                if (paramTypeName.empty()) {
                    paramTypeName = joinList(item->typeName->typeName, ".") + arrayPostFix;
                    spdlog::get(ErrorManager::DebugTag)->warn("visitConstructorDeclaration: did not find param type name: {} for param: {} in method: {} in type: {}", paramTypeName, item->name, method.name, classScopeAndEnv->typeInfo->typeKey);
                }
                parameterTypes.push_back(paramTypeName);
                paramIndex++;
            }
            const string& methodKey = AddressableInfo::makeMethodKey(
                classLevelVisitor->typeKeyStack.back(), ctx->identifier()->getText(), joinList(parameterTypes, ","));
            auto* pStatementVisitor = StatementVisitor::getInstanceFromCopy(this);
            pStatementVisitor->codeBlock = new CodeBlock(nullptr, MethodScopeAndEnv::rootStructureKey, false);
            pStatementVisitor->codeBlock->conditionItem = ResolvingItem::getInstance2(methodKey, NULL, MethodScopeAndEnv::rootStructureKey, "-1", "-1", GlobalInfo::KEY_TYPE_CONSTRUCTOR);
            pStatementVisitor->methodScopeAndEnv = MethodScopeAndEnv::createMethodScopeAndEnv(methodKey, classScopeAndEnv);
            stateVisitorForCurrentMethod = pStatementVisitor;

            // default super constructor
            auto* firstStatement = ctx->constructorBody->blockStatement(0);
            if (firstStatement->statement()) {
                JavaParser::StatementExpContext* firstExpState = dynamic_cast<JavaParser::StatementExpContext*>(firstStatement->statement());
                JavaParser::MethodCallContext* superCall = NULL;
                JavaParser::MethodCallContext* thisCall = NULL;
                if (firstExpState) {
                    JavaParser::ExpressionMethodCallContext* methodCall = dynamic_cast<JavaParser::ExpressionMethodCallContext*>(firstExpState->expression());
                    if (methodCall and methodCall->methodCall()->SUPER()) {
                        superCall = methodCall->methodCall();
                    }
                    if (methodCall and methodCall->methodCall()->THIS()) {
                        thisCall = methodCall->methodCall();
                    }
                }
                pStatementVisitor->sentenceIndex = 1;
                if (superCall) {
                    NameAndRelatedExp methodCall;
                    AntlrNodeToSyntaxObjectConverter::convertMethodCall(superCall, &methodCall);
                    const FieldInfo* superFieldInfo = classScopeAndEnv->name2fieldInfo["super"];
                    if (superFieldInfo) {
                        const TypeInfo* superTypeInfo = superFieldInfo->typeInfo;
                        methodCall.name.clear();
                        splitStr(superTypeInfo->typeName, ".", methodCall.name);
                        pStatementVisitor->resolveMethod(methodCall, superTypeInfo->classScopeAndEnv, true);
                        classScopeAndEnv->addUsage(superFieldInfo->typeInfo);
                    } else {
                        spdlog::get(ErrorManager::DebugTag)->warn("visitConstructorDeclaration: did not find super for {}", classScopeAndEnv->typeInfo->typeKey);
                    }
                }
                if (thisCall) {
                    NameAndRelatedExp methodCall;
                    AntlrNodeToSyntaxObjectConverter::convertMethodCall(thisCall, &methodCall);
                    methodCall.name.clear();
                    methodCall.name.emplace_back(classScopeAndEnv->typeInfo->simpletypeName);
                    pStatementVisitor->resolveMethod(methodCall, classScopeAndEnv, true);
                }
                if (not superCall and not thisCall) {
                    // call super constructor without parameter
                    NameAndRelatedExp methodCall;
                    const FieldInfo* superFieldInfo = classScopeAndEnv->name2fieldInfo["super"];
                    if (superFieldInfo) {
                        const TypeInfo* superTypeInfo = superFieldInfo->typeInfo;
                        splitStr(superTypeInfo->typeName, ".", methodCall.name);
                        pStatementVisitor->resolveMethod(methodCall, superTypeInfo->classScopeAndEnv, true);
                        classScopeAndEnv->addUsage(superFieldInfo->typeInfo);
                    } else {
                        spdlog::get(ErrorManager::DebugTag)->warn("visitConstructorDeclaration: did not find default super for {}", classScopeAndEnv->typeInfo->typeKey);
                    }
                }
            }
            // initiaze block
            visitFieldDeclarationOfClassBody(classBody);
            // code block
            pStatementVisitor->visitBlock(ctx->constructorBody);
            CodeBlock::classKey2methodKey2codeBlock[classScopeAndEnv->typeInfo->typeKey][methodKey] = pStatementVisitor->codeBlock;
            StatementVisitor::returnToPool(pStatementVisitor);
        }
    }
    return 0;
}

std::any InitializerVisitor::visitFieldDeclarationOfClassBody(JavaParser::ClassBodyContext* ctx) {
    int stateCount = 0;
    for (JavaParser::ClassBodyDeclarationContext* ctxI : ctx->classBodyDeclaration()) {
        stateCount--;
        if (ctxI->block() and not ctxI->STATIC()) {
            stateCount = stateVisitorForCurrentMethod->visitInitBlockForClass(ctxI->block(), stateCount);
        }
        if (ctxI->memberDeclaration() and ctxI->memberDeclaration()->fieldDeclaration()) {
            bool isStatic = false;
            for (auto& m : ctxI->modifier()) {
                if (m->classOrInterfaceModifier() and m->classOrInterfaceModifier()->STATIC()) {
                    isStatic = true;
                }
            }
            if (not isStatic) {
                StatementVisitor* visitor = StatementVisitor::getInstanceFromCopy(stateVisitorForCurrentMethod);
                visitor->codeBlock = stateVisitorForCurrentMethod->codeBlock;
                visitor->sentenceIndex = stateCount;
                visitor->visitFieldDeclaration(ctxI->memberDeclaration()->fieldDeclaration());
                StatementVisitor::returnToPool(visitor);
            }
        }
    }
    return 0;
}

void InitializerVisitor::reset() {
    classLevelVisitor = NULL;
    classBody = NULL;
    stateVisitorForCurrentMethod = NULL;
}

void AnonymousVisitor::makeTypeInfo() {
    typeInfo = new TypeInfo;
    typeInfo->typeKey = AddressableInfo::makeAnonymousKey(superTypeInfo->typeKey, positionKey);
    typeInfo->simpletypeName = superTypeInfo->simpletypeName;
    typeInfo->typeName = superTypeInfo->typeName;
    if (Modifier::isClassType(superTypeInfo->flag)) {
        typeInfo->superTypeInfos.insert(superTypeInfo);
    } else if (Modifier::isInterfaceType(superTypeInfo->flag)) {
        typeInfo->interfaceInfos.insert(superTypeInfo);
    } else {
        spdlog::get(ErrorManager::DebugTag)->warn("did not insert super type: {} cause flag problem", superTypeInfo->typeKey);
    }
    typeInfo->package = outerMethodScopeAndEnv->getPackageScope()->package;
    typeInfo->filePath = outerMethodScopeAndEnv->getFileScope()->filePath;
    GlobalInfo::filePath2package2typeKeys[typeInfo->filePath][typeInfo->package].insert(typeInfo->typeKey);
    if (not GlobalInfo::filePath2typeKey2subTypeKeys[typeInfo->filePath].count(superTypeInfo->typeKey)) {
        GlobalInfo::filePath2typeKey2subTypeKeys[typeInfo->filePath][superTypeInfo->typeKey] = set<string>();
    }
    GlobalInfo::filePath2typeKey2subTypeKeys[typeInfo->filePath][superTypeInfo->typeKey].insert(typeInfo->typeKey);
    GlobalInfo::filePath2typeKey2filePath[typeInfo->filePath][typeInfo->typeKey] = typeInfo->filePath;
    GlobalInfo::filePath2typeInfos[typeInfo->filePath].push_back(typeInfo);
    AddressableInfo::typeKey2typeInfo[typeInfo->typeKey] = typeInfo;
    CodeBlock::classKey2methodKey2codeBlock[typeInfo->typeKey] = map<string, CodeBlock*>();
}

void AnonymousVisitor::makeClassScopeEnv() {
    typeInfo->classScopeAndEnv = new ClassScopeAndEnv(typeInfo);
    classScopeAndEnv = typeInfo->classScopeAndEnv;
    classScopeAndEnv->typeInfo = typeInfo;
    classScopeAndEnv->langPackageScopeAndEnv = PackageScopeAndEnv::package2scopeAndEnv[PackageScopeAndEnv::langPackage];
    classScopeAndEnv->packageScopeAndEnv = outerMethodScopeAndEnv->getPackageScope();
    classScopeAndEnv->fileScopeAndEnv = outerMethodScopeAndEnv->getFileScope();
    classScopeAndEnv->outerScopeAndEnv = outerMethodScopeAndEnv;
    classScopeAndEnv->superScopeAndEnvs.push_back(superTypeInfo->classScopeAndEnv);
    auto* thisFieldInfo = new FieldInfo;
    thisFieldInfo->name = "this";
    thisFieldInfo->fieldKey = typeInfo->typeKey + ".this";
    thisFieldInfo->typeInfo = typeInfo;
    classScopeAndEnv->name2fieldInfo["this"] = thisFieldInfo;
    typeInfo->fieldInfos.insert(thisFieldInfo);
    AddressableInfo::fieldKey2fieldInfo[thisFieldInfo->fieldKey] = thisFieldInfo;
    auto* superFieldInfo = new FieldInfo;
    superFieldInfo->name = "super";
    superFieldInfo->fieldKey = typeInfo->typeKey + ".super";
    superFieldInfo->typeInfo = superTypeInfo;
    classScopeAndEnv->name2fieldInfo["super"] = superFieldInfo;
    typeInfo->fieldInfos.insert(superFieldInfo);
    AddressableInfo::fieldKey2fieldInfo[superFieldInfo->fieldKey] = superFieldInfo;
}

void AnonymousVisitor::visitForMembers(JavaParser::ClassBodyContext* ctx) {
    for (auto& classBodyDeclaration : ctx->classBodyDeclaration()) {
        if (classBodyDeclaration->memberDeclaration()) {
            if (classBodyDeclaration->memberDeclaration()->fieldDeclaration()) {
                VariableDeclaration variableDeclaration;
                AntlrNodeToSyntaxObjectConverter::convertClassBodyDeclarationField(classBodyDeclaration, &variableDeclaration);
                TypeInfo* fieldTypeInfo = typeInfo->classScopeAndEnv->getTypeInfoWithFileScope(variableDeclaration.typeType.typeName);
                if (not fieldTypeInfo) {
                    fieldTypeInfo = new TypeInfo;
                    fieldTypeInfo->typeName = joinList(variableDeclaration.typeType.typeName, ".");
                    fieldTypeInfo->typeKey = fieldTypeInfo->typeName;
                    spdlog::get(ErrorManager::DebugTag)->warn("AnonymousVisitor::visitForMembers: did not find field type name: {} for field: {} in type: {}", fieldTypeInfo->typeName, variableDeclaration.nameAndValueCount.front().name.front(), typeInfo->typeKey);
                }
                for (auto& fieldName : variableDeclaration.nameAndValueCount) {
                    auto* fieldInfo = new FieldInfo();
                    fieldInfo->dim = fieldName.dim;
                    fieldInfo->name = fieldName.name.front();
                    fieldInfo->fieldKey = typeInfo->typeKey + "." + fieldName.name.front();
                    fieldInfo->typeInfo = fieldTypeInfo;
                    classScopeAndEnv->name2fieldInfo[fieldName.name.front()] = fieldInfo;
                    AddressableInfo::fieldKey2fieldInfo[fieldInfo->fieldKey] = fieldInfo;
                    typeInfo->fieldInfos.insert(fieldInfo);
                }
            }
            if (classBodyDeclaration->memberDeclaration()->methodDeclaration()) {
                auto method = new Method();
                AntlrNodeToSyntaxObjectConverter::convertClassBodyDeclarationMethod(classBodyDeclaration, method);
                auto* methodInfo = new MethodInfo();
                methodInfo->isVariableParameter = method->isVariableParameter;
                TypeInfo* returnTypeInfo = classScopeAndEnv->getTypeInfoWithFileScope(method->returnTypeName->typeName);
                if (not returnTypeInfo) {
                    returnTypeInfo = new TypeInfo;
                    returnTypeInfo->typeName = joinList(method->returnTypeName->typeName, ".");
                    returnTypeInfo->typeKey = returnTypeInfo->typeName;
                    spdlog::get(ErrorManager::DebugTag)->warn("AnonymousVisitor::visitForMembers: did not find return type name: {} for method: {} in type: {}", returnTypeInfo->typeName, method->name, typeInfo->typeKey);
                }
                map<string, FieldInfo*> paramName2paramInfo;
                for (auto& parameter : method->parameters) {
                    TypeInfo* parameterTypeInfo = classScopeAndEnv->getTypeInfoWithFileScope(parameter->typeName->typeName);
                    if (not parameterTypeInfo) {
                        parameterTypeInfo = new TypeInfo;
                        parameterTypeInfo->typeName = joinList(parameter->typeName->typeName, ".");
                        parameterTypeInfo->typeKey = parameterTypeInfo->typeName;
                        spdlog::get(ErrorManager::DebugTag)->warn("AnonymousVisitor::visitForMembers: did not find param type name: {} for param: {} for method: {} in type: {}", parameterTypeInfo->typeName, parameter->name, method->name, typeInfo->typeKey);
                    }
                    FieldInfo* paramInfo = new FieldInfo();
                    paramInfo->dim = parameter->typeName->dim;
                    paramInfo->name = parameter->name;
                    paramInfo->typeInfo = parameterTypeInfo;
                    methodInfo->parameterInfos.push_back(paramInfo);
                    paramName2paramInfo[parameter->name] = paramInfo;
                }
                methodInfo->name = method->name;
                methodInfo->methodKey = AddressableInfo::makeMethodKey(typeInfo->typeKey, method->name, methodInfo->getParamPartOfKey());
                methodInfo->calledMethodKey = AddressableInfo::makeCalledKey(methodInfo->methodKey);
                if (not classScopeAndEnv->name2method.count(method->name)) {
                    classScopeAndEnv->name2method[method->name] = list<MethodInfo*>();
                }
                classScopeAndEnv->name2method[method->name].push_back(methodInfo);
                typeInfo->methodInfos.insert(methodInfo);
                auto methodScopeAndEnv = new MethodScopeAndEnv();
                methodScopeAndEnv->methodKey = methodInfo->methodKey;
                methodScopeAndEnv->methodIfKey = AddressableInfo::makeMethodIfKey(methodInfo->methodKey);
                methodScopeAndEnv->methodElseKey = AddressableInfo::makeMethodElseKey(methodInfo->methodKey);
                methodScopeAndEnv->methodForKey = AddressableInfo::makeMethodForKey(methodInfo->methodKey);
                methodScopeAndEnv->methodWhileKey = AddressableInfo::makeMethodWhileKey(methodInfo->methodKey);
                methodScopeAndEnv->methodCaseKey = AddressableInfo::makeMethodCaseKey(methodInfo->methodKey);
                methodScopeAndEnv->methodForEachKey = AddressableInfo::makeMethodForEachKey(methodInfo->methodKey);
                methodScopeAndEnv->methodTryKey = AddressableInfo::makeMethodTryKey(methodInfo->methodKey);
                methodScopeAndEnv->methodCatchKey = AddressableInfo::makeMethodCatchKey(methodInfo->methodKey);
                methodScopeAndEnv->methodFinallyKey = AddressableInfo::makeMethodFinallyKey(methodInfo->methodKey);
                methodScopeAndEnv->outerScopeAndEnv = classScopeAndEnv;
                auto* returnInfo = new FieldInfo();
                returnInfo->dim = method->returnTypeName->dim;
                methodInfo->returnInfo = returnInfo;
                returnInfo->name = "return";
                returnInfo->fieldKey = AddressableInfo::makeReturnKey(methodInfo->methodKey);
                returnInfo->typeInfo = returnTypeInfo;
                methodScopeAndEnv->returnFieldInfo = returnInfo;
                AddressableInfo::fieldKey2fieldInfo[returnInfo->fieldKey] = returnInfo;

                auto* calledReturnFieldInfo = new FieldInfo();
                calledReturnFieldInfo->dim = method->returnTypeName->dim;
                methodInfo->calledReturnInfo = calledReturnFieldInfo;
                calledReturnFieldInfo->name = AddressableInfo::makeCalledKey("return");
                calledReturnFieldInfo->fieldKey = AddressableInfo::makeCalledKey(returnInfo->fieldKey);
                calledReturnFieldInfo->typeInfo = returnTypeInfo;
                AddressableInfo::fieldKey2fieldInfo[calledReturnFieldInfo->fieldKey] = calledReturnFieldInfo;

                for (auto& paramNameAndParamInfo : paramName2paramInfo) {
                    FieldInfo* paramInfo = paramNameAndParamInfo.second;
                    paramInfo->fieldKey = AddressableInfo::makeParamKey(methodInfo->methodKey, paramNameAndParamInfo.first);
                    methodScopeAndEnv->name2paramInfo[paramNameAndParamInfo.first] = paramInfo;
                    AddressableInfo::fieldKey2fieldInfo[paramInfo->fieldKey] = paramInfo;

                    auto* calledParamInfo = new FieldInfo();
                    calledParamInfo->dim = paramInfo->dim;
                    methodInfo->calledParamInfos.push_back(calledParamInfo);
                    calledParamInfo->name = AddressableInfo::makeCalledKey(paramInfo->name);
                    calledParamInfo->fieldKey = AddressableInfo::makeCalledKey(paramInfo->fieldKey);
                    calledParamInfo->typeInfo = paramInfo->typeInfo;
                    AddressableInfo::fieldKey2fieldInfo[calledParamInfo->fieldKey] = calledParamInfo;
                }
                ctx2methodScopeAndEnv[classBodyDeclaration->memberDeclaration()->methodDeclaration()] = methodScopeAndEnv;
                AddressableInfo::methodKey2MethodInfo[methodInfo->methodKey] = methodInfo;
            }
        }
    }
}

std::any AnonymousVisitor::visitClassBody(JavaParser::ClassBodyContext* ctx) {
    for (auto& classBodyDeclaration : ctx->classBodyDeclaration()) {
        if (classBodyDeclaration->memberDeclaration()) {
            if (classBodyDeclaration->memberDeclaration()->methodDeclaration()) {
                visitMethodDeclaration(classBodyDeclaration->memberDeclaration()->methodDeclaration());
            }
        }
    }
    return NULL;
}

std::any AnonymousVisitor::visitLambda(JavaParser::LambdaExpressionContext* ctx, MethodInfo* superMethodInfo, list<string>& paramNames) {
    MethodInfo* methodInfo = new MethodInfo();
    map<string, FieldInfo*> paramName2paramInfo;
    int paramIndex = 0;
    for (auto& paramName : paramNames) {
        FieldInfo* paramInfo = new FieldInfo();
        paramInfo->name = paramName;
        paramInfo->typeInfo = superMethodInfo->parameterInfos[paramIndex]->typeInfo;
        if (paramInfo->typeInfo->isTypeParam and typeUnification.getTypeArgFromTypeParam(paramInfo->typeInfo)) {
            paramInfo->typeInfo = typeUnification.getTypeArgFromTypeParam(paramInfo->typeInfo);
        }
        methodInfo->parameterInfos.push_back(paramInfo);
        paramName2paramInfo[paramInfo->name] = paramInfo;
        paramIndex++;
    }
    methodInfo->name = superMethodInfo->name;
    methodInfo->methodKey = AddressableInfo::makeMethodKey(typeInfo->typeKey, methodInfo->name, methodInfo->getParamPartOfKey());
    methodInfo->calledMethodKey = AddressableInfo::makeCalledKey(methodInfo->methodKey);
    typeInfo->methodInfos.insert(methodInfo);
    auto methodScopeAndEnv = new MethodScopeAndEnv();
    methodScopeAndEnv->methodKey = methodInfo->methodKey;
    methodScopeAndEnv->methodIfKey = AddressableInfo::makeMethodIfKey(methodInfo->methodKey);
    methodScopeAndEnv->methodElseKey = AddressableInfo::makeMethodElseKey(methodInfo->methodKey);
    methodScopeAndEnv->methodForKey = AddressableInfo::makeMethodForKey(methodInfo->methodKey);
    methodScopeAndEnv->methodWhileKey = AddressableInfo::makeMethodWhileKey(methodInfo->methodKey);
    methodScopeAndEnv->methodCaseKey = AddressableInfo::makeMethodCaseKey(methodInfo->methodKey);
    methodScopeAndEnv->methodForEachKey = AddressableInfo::makeMethodForEachKey(methodInfo->methodKey);
    methodScopeAndEnv->methodTryKey = AddressableInfo::makeMethodTryKey(methodInfo->methodKey);
    methodScopeAndEnv->methodCatchKey = AddressableInfo::makeMethodCatchKey(methodInfo->methodKey);
    methodScopeAndEnv->methodFinallyKey = AddressableInfo::makeMethodFinallyKey(methodInfo->methodKey);
    methodScopeAndEnv->outerScopeAndEnv = classScopeAndEnv;
    auto* returnInfo = new FieldInfo();
    methodInfo->returnInfo = returnInfo;
    returnInfo->name = "return";
    returnInfo->fieldKey = AddressableInfo::makeReturnKey(methodInfo->methodKey);
    returnInfo->typeInfo = superMethodInfo->returnInfo->typeInfo;
    methodScopeAndEnv->returnFieldInfo = returnInfo;
    AddressableInfo::fieldKey2fieldInfo[returnInfo->fieldKey] = returnInfo;

    auto* calledReturnFieldInfo = new FieldInfo();
    methodInfo->calledReturnInfo = calledReturnFieldInfo;
    calledReturnFieldInfo->name = AddressableInfo::makeCalledKey("return");
    calledReturnFieldInfo->fieldKey = AddressableInfo::makeCalledKey(returnInfo->fieldKey);
    calledReturnFieldInfo->typeInfo = returnInfo->typeInfo;
    AddressableInfo::fieldKey2fieldInfo[calledReturnFieldInfo->fieldKey] = calledReturnFieldInfo;

    for (auto& paramNameAndParamInfo : paramName2paramInfo) {
        FieldInfo* paramInfo = paramNameAndParamInfo.second;
        paramInfo->fieldKey = AddressableInfo::makeParamKey(methodInfo->methodKey, paramNameAndParamInfo.first);
        methodScopeAndEnv->name2paramInfo[paramNameAndParamInfo.first] = paramInfo;
        AddressableInfo::fieldKey2fieldInfo[paramInfo->fieldKey] = paramInfo;

        auto* calledParamInfo = new FieldInfo();
        methodInfo->calledParamInfos.push_back(calledParamInfo);
        calledParamInfo->name = AddressableInfo::makeCalledKey(paramInfo->name);
        calledParamInfo->fieldKey = AddressableInfo::makeCalledKey(paramInfo->fieldKey);
        calledParamInfo->typeInfo = paramInfo->typeInfo;
        AddressableInfo::fieldKey2fieldInfo[calledParamInfo->fieldKey] = calledParamInfo;
    }
    AddressableInfo::methodKey2MethodInfo[methodInfo->methodKey] = methodInfo;

    auto* pStatementVisitor = StatementVisitor::getInstanceFromCopy(this);
    pStatementVisitor->methodScopeAndEnv = methodScopeAndEnv;
    pStatementVisitor->codeBlock = new CodeBlock(nullptr, MethodScopeAndEnv::rootStructureKey, false);
    pStatementVisitor->codeBlock->conditionItem = ResolvingItem::getInstance2(pStatementVisitor->methodScopeAndEnv->methodKey, NULL, MethodScopeAndEnv::rootStructureKey, "-1", "-1", GlobalInfo::KEY_TYPE_METHOD);
    if (ctx->lambdaBody()->block()) {
        pStatementVisitor->visitBlock(ctx->lambdaBody()->block());
    } else {
        std::any itemOrNull = ctx->lambdaBody()->expression()->accept(pStatementVisitor);
        if (not pStatementVisitor->abort and superMethodInfo->returnInfo->typeInfo->typeKey != "void") {
            auto* item = any_cast<ResolvingItem*>(itemOrNull);
            new Relation(pStatementVisitor->getSentence(), item, ResolvingItem::getInstance2(
                returnInfo->fieldKey, returnInfo->typeInfo,
                pStatementVisitor->codeBlock->structure_key,
                pStatementVisitor->getSentence()->sentenceIndexStr,
                pStatementVisitor->getIncreasedIndexInsideExp(), GlobalInfo::KEY_TYPE_METHOD_RETURN
            ));
        }
    }
    CodeBlock::classKey2methodKey2codeBlock[typeInfo->typeKey][pStatementVisitor->methodScopeAndEnv->methodKey] = pStatementVisitor->codeBlock;
    StatementVisitor::returnToPool(pStatementVisitor);

    return NULL;
}

std::any AnonymousVisitor::visitMethodDeclaration(JavaParser::MethodDeclarationContext* ctx) {
    if (ctx->methodBody()->block() != nullptr) {
        auto* pStatementVisitor = StatementVisitor::getInstanceFromCopy(this);
        pStatementVisitor->methodScopeAndEnv = ctx2methodScopeAndEnv[ctx];
        pStatementVisitor->codeBlock = new CodeBlock(nullptr, MethodScopeAndEnv::rootStructureKey, false);
        pStatementVisitor->codeBlock->conditionItem = ResolvingItem::getInstance2(pStatementVisitor->methodScopeAndEnv->methodKey, NULL, MethodScopeAndEnv::rootStructureKey, "-1", "-1", GlobalInfo::KEY_TYPE_METHOD);
        pStatementVisitor->visitBlock(ctx->methodBody()->block());
        CodeBlock::classKey2methodKey2codeBlock[classScopeAndEnv->typeInfo->typeKey][pStatementVisitor->methodScopeAndEnv->methodKey] = pStatementVisitor->codeBlock;
        StatementVisitor::returnToPool(pStatementVisitor);
    }
    return NULL;
}

void AnonymousVisitor::reset() {
    clearScopeAndEnv();
    outerMethodScopeAndEnv = NULL;
    superTypeInfo = NULL;
    typeInfo = NULL;
    positionKey.clear();
    name2calledInfo.clear();
}

void RuntimeVisitor::addTypeArgForResolvingItem(ResolvingItem* item) {
    if (item->keyType == GlobalInfo::KEY_TYPE_FIELD or
        item->keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER or
        item->keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE or
        item->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
        if (AddressableInfo::fieldKey2fieldInfo.count(item->variableKey)) {
            FieldInfo* fieldInfo = AddressableInfo::fieldKey2fieldInfo[item->variableKey];
            for (auto& typeArg : fieldInfo->typeParam2typeArg) {
                typeUnification.addTypeMap(typeArg.first, typeArg.second);
            }
        }
    }
    for (auto& typeArg : item->typeArgs) {
        typeUnification.addTypeMap(typeArg.first, typeArg.second);
    }
}
