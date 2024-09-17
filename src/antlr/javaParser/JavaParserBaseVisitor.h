
// Generated from JavaParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "JavaParserVisitor.h"


/**
 * This class provides an empty implementation of JavaParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  JavaParserBaseVisitor : public JavaParserVisitor {
public:

  virtual std::any visitCompilationUnit(JavaParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPackageDeclaration(JavaParser::PackageDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportDeclaration(JavaParser::ImportDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeDeclaration(JavaParser::TypeDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModifier(JavaParser::ModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassOrInterfaceModifier(JavaParser::ClassOrInterfaceModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableModifier(JavaParser::VariableModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDeclaration(JavaParser::ClassDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeParameters(JavaParser::TypeParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeParameter(JavaParser::TypeParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeBound(JavaParser::TypeBoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumDeclaration(JavaParser::EnumDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumConstants(JavaParser::EnumConstantsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumConstant(JavaParser::EnumConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumBodyDeclarations(JavaParser::EnumBodyDeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassBody(JavaParser::ClassBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceBody(JavaParser::InterfaceBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberDeclaration(JavaParser::MemberDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodDeclaration(JavaParser::MethodDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodBody(JavaParser::MethodBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeTypeOrVoid(JavaParser::TypeTypeOrVoidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstructorDeclaration(JavaParser::ConstructorDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldDeclaration(JavaParser::FieldDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceMemberDeclaration(JavaParser::InterfaceMemberDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDeclaration(JavaParser::ConstDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantDeclarator(JavaParser::ConstantDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceMethodDeclaration(JavaParser::InterfaceMethodDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceMethodModifier(JavaParser::InterfaceMethodModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceCommonBodyDeclaration(JavaParser::InterfaceCommonBodyDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarators(JavaParser::VariableDeclaratorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarator(JavaParser::VariableDeclaratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclaratorId(JavaParser::VariableDeclaratorIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableInitializer(JavaParser::VariableInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayInitializer(JavaParser::ArrayInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassOrInterfaceType(JavaParser::ClassOrInterfaceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeArgument(JavaParser::TypeArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQualifiedNameList(JavaParser::QualifiedNameListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormalParameters(JavaParser::FormalParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReceiverParameter(JavaParser::ReceiverParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormalParameterList(JavaParser::FormalParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormalParameter(JavaParser::FormalParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLastFormalParameter(JavaParser::LastFormalParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaLVTIList(JavaParser::LambdaLVTIListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaLVTIParameter(JavaParser::LambdaLVTIParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQualifiedName(JavaParser::QualifiedNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(JavaParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerLiteral(JavaParser::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatLiteral(JavaParser::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAltAnnotationQualifiedName(JavaParser::AltAnnotationQualifiedNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotation(JavaParser::AnnotationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementValuePairs(JavaParser::ElementValuePairsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementValuePair(JavaParser::ElementValuePairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementValue(JavaParser::ElementValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementValueArrayInitializer(JavaParser::ElementValueArrayInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotationTypeDeclaration(JavaParser::AnnotationTypeDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotationTypeBody(JavaParser::AnnotationTypeBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotationTypeElementDeclaration(JavaParser::AnnotationTypeElementDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotationTypeElementRest(JavaParser::AnnotationTypeElementRestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotationMethodOrConstantRest(JavaParser::AnnotationMethodOrConstantRestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotationMethodRest(JavaParser::AnnotationMethodRestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotationConstantRest(JavaParser::AnnotationConstantRestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefaultValue(JavaParser::DefaultValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModuleDeclaration(JavaParser::ModuleDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModuleBody(JavaParser::ModuleBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModuleDirective(JavaParser::ModuleDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRequiresModifier(JavaParser::RequiresModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordDeclaration(JavaParser::RecordDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordHeader(JavaParser::RecordHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordComponentList(JavaParser::RecordComponentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordComponent(JavaParser::RecordComponentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordBody(JavaParser::RecordBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(JavaParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockStatement(JavaParser::BlockStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocalVariableDeclaration(JavaParser::LocalVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(JavaParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocalTypeDeclaration(JavaParser::LocalTypeDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementBlock(JavaParser::StatementBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementAssert(JavaParser::StatementAssertContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementIf(JavaParser::StatementIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementFor(JavaParser::StatementForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementWhile(JavaParser::StatementWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementDoWhile(JavaParser::StatementDoWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementSwitch(JavaParser::StatementSwitchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementTry(JavaParser::StatementTryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementSync(JavaParser::StatementSyncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementReturn(JavaParser::StatementReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementThrow(JavaParser::StatementThrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementBreak(JavaParser::StatementBreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementContinue(JavaParser::StatementContinueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementYield(JavaParser::StatementYieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementSemi(JavaParser::StatementSemiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementExp(JavaParser::StatementExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementSwitchExp(JavaParser::StatementSwitchExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementLabel(JavaParser::StatementLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatchClause(JavaParser::CatchClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatchType(JavaParser::CatchTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFinallyBlock(JavaParser::FinallyBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResourceSpecification(JavaParser::ResourceSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResources(JavaParser::ResourcesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResource(JavaParser::ResourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchBlockStatementGroup(JavaParser::SwitchBlockStatementGroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchLabel(JavaParser::SwitchLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForControl(JavaParser::ForControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForInit(JavaParser::ForInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForCondition(JavaParser::ForConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForUpdate(JavaParser::ForUpdateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnhancedForControl(JavaParser::EnhancedForControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParExpression(JavaParser::ParExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionList(JavaParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethodCall(JavaParser::MethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionNew(JavaParser::ExpressionNewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionPosNegSign(JavaParser::ExpressionPosNegSignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionReference(JavaParser::ExpressionReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionMethodReference(JavaParser::ExpressionMethodReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionInstanceOf(JavaParser::ExpressionInstanceOfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionAssign(JavaParser::ExpressionAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionUnaryLogical(JavaParser::ExpressionUnaryLogicalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionLambda(JavaParser::ExpressionLambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionPrimary(JavaParser::ExpressionPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionArithmetical(JavaParser::ExpressionArithmeticalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionSwitch(JavaParser::ExpressionSwitchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionConditional(JavaParser::ExpressionConditionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionCast(JavaParser::ExpressionCastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionShift(JavaParser::ExpressionShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionRelational(JavaParser::ExpressionRelationalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionArrayAccess(JavaParser::ExpressionArrayAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionIncDec(JavaParser::ExpressionIncDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionMethodCall(JavaParser::ExpressionMethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionLogical(JavaParser::ExpressionLogicalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPattern(JavaParser::PatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaExpression(JavaParser::LambdaExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaParameters(JavaParser::LambdaParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaBody(JavaParser::LambdaBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExp(JavaParser::PrimaryExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryThis(JavaParser::PrimaryThisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimarySuper(JavaParser::PrimarySuperContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryLiteral(JavaParser::PrimaryLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryIdentifier(JavaParser::PrimaryIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryClass(JavaParser::PrimaryClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryMethodCallWithExplicitTypeArgument(JavaParser::PrimaryMethodCallWithExplicitTypeArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchExpression(JavaParser::SwitchExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchLabeledRule(JavaParser::SwitchLabeledRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGuardedPattern(JavaParser::GuardedPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchRuleOutcome(JavaParser::SwitchRuleOutcomeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassType(JavaParser::ClassTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreator(JavaParser::CreatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreatedName(JavaParser::CreatedNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInnerCreator(JavaParser::InnerCreatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayCreatorRest(JavaParser::ArrayCreatorRestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassCreatorRest(JavaParser::ClassCreatorRestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExplicitGenericInvocation(JavaParser::ExplicitGenericInvocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeArgumentsOrDiamond(JavaParser::TypeArgumentsOrDiamondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonWildcardTypeArgumentsOrDiamond(JavaParser::NonWildcardTypeArgumentsOrDiamondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonWildcardTypeArguments(JavaParser::NonWildcardTypeArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeList(JavaParser::TypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeType(JavaParser::TypeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveType(JavaParser::PrimitiveTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeArguments(JavaParser::TypeArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuperSuffix(JavaParser::SuperSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExplicitGenericInvocationSuffix(JavaParser::ExplicitGenericInvocationSuffixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(JavaParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }


};

