class RuntimeVisitor : public JavaParserBaseVisitor {
public:
    void copyFrom(RuntimeVisitor* copied);

    void clearScopeAndEnv();

    ClassScopeAndEnv* classScopeAndEnv = nullptr;
    MethodScopeAndEnv* methodScopeAndEnv = nullptr;

    TypeUnification typeUnification;

    void addTypeArgForResolvingItem(ResolvingItem* item);
};

class ClassLevelVisitor : public RuntimeVisitor, public PooledItem<ClassLevelVisitor> {
public:
    string package = "";
    list<string> typeNameStack;
    list<string> typeKeyStack;

    void pushTypeStack(const string& typeName);

    void popTypeStack();

    void reset() override;

    static ClassLevelVisitor* getInstanceFromCopy(RuntimeVisitor* copied);

    static ClassLevelVisitor* getInstanceFromCopy(ClassLevelVisitor* copied);

    any visitCompilationUnit(JavaParser::CompilationUnitContext* ctx) override;

    std::any visitClassDeclaration(JavaParser::ClassDeclarationContext* ctx) override;

    std::any visitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext* ctx) override;

    std::any visitEnumDeclaration(JavaParser::EnumDeclarationContext* ctx) override;

    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ignored for class level visitor start^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    std::any visitAnnotationTypeDeclaration(JavaParser::AnnotationTypeDeclarationContext* ctx) override;

    std::any visitRecordDeclaration(JavaParser::RecordDeclarationContext* ctx) override;

    // implemented in initializer visitor
    std::any visitFieldDeclaration(JavaParser::FieldDeclarationContext* ctx) override;
    // implemented in initializer visitor
    std::any visitConstructorDeclaration(JavaParser::ConstructorDeclarationContext* ctx) override;
    //----------------------------------------ignored for class level visitor end-------------------------------------------------------

    std::any visitMemberDeclaration(JavaParser::MemberDeclarationContext* ctx) override;

    std::any visitMethodDeclaration(JavaParser::MethodDeclarationContext* ctx) override;

    any visitConstDeclaration(JavaParser::ConstDeclarationContext* ctx) override;

    any visitClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext* ctx) override;

    any visitInterfaceMethodDeclaration(JavaParser::InterfaceMethodDeclarationContext* ctx) override;

    string makeMethodKeyFromMethodInf(Method& methodInfo);
};

class StructuralVisitor : public RuntimeVisitor, public PooledItem<StructuralVisitor> {
public:
    CodeBlock* outerCodeBlock = nullptr;

    int sentenceIndexInOuterCodeBlock = 0;

    void reset() override;

    static StructuralVisitor* getInstanceFromCopy(RuntimeVisitor* copied);

    any visitChildren(antlr4::tree::ParseTree* node) override;

    std::any visitUseStatementVisitor(antlr4::tree::ParseTree* tree, CodeBlock* codeBlock, int sentenceIndex);

    std::any visitUseStatementVisitor(antlr4::tree::ParseTree* tree, CodeBlock* codeBlock);

    std::any visitStatementIf(JavaParser::StatementIfContext* ctx) override;

    std::any visitStatementFor(JavaParser::StatementForContext* ctx) override;

    std::any visitStatementWhile(JavaParser::StatementWhileContext* ctx) override;

    std::any visitStatementDoWhile(JavaParser::StatementDoWhileContext* ctx) override;

    std::any visitStatementSwitch(JavaParser::StatementSwitchContext* ctx) override;

    std::any visitStatementTry(JavaParser::StatementTryContext* ctx) override;

    void visitCondition(string& conditionKey, JavaParser::ExpressionContext* ctx, CodeBlock* codeBlock);

    void visitConditionIf(JavaParser::ExpressionContext* ctx, CodeBlock* codeBlock);

    void visitConditionElseWithoutIf(CodeBlock* codeBlock);

    void visitConditionFor(JavaParser::ForControlContext* ctx, CodeBlock* codeBlock);

    void visitConditionWhile(JavaParser::ExpressionContext* ctx, CodeBlock* codeBlock);

    void visitConditionDoWhile(JavaParser::ExpressionContext* ctx, CodeBlock* codeBlock);

    void visitConditionCase(JavaParser::ExpressionContext* ctx, ResolvingItem* switchItem, CodeBlock* codeBlock, int caseIndex);

    void visitConditionDefault(CodeBlock* codeBlock);

    void visitConditionTry(CodeBlock* codeBlock);

    void visitConditionCatch(JavaParser::CatchClauseContext* ctx, CodeBlock* codeBlock);

    void visitConditionFinally(CodeBlock* codeBlock);
};

class StatementVisitor : public RuntimeVisitor, public PooledItem<StatementVisitor> {
public:

    CodeBlock* codeBlock = nullptr;

    int sentenceIndex = 0;

    int* statementBlockStateCount = NULL;

    int indexInsideStatement = 0;

    list<TypeInfo*> expectingTypeInfo;

    bool abort = false;

    // do not use this field directly, delay initialization in function: getSentence
    Sentence* sentence = nullptr;

    void unhandledError();

    string getIncreasedIndexInsideExp();

    Sentence* getSentence();

    void reset() override;

    static StatementVisitor* getInstanceFromCopy(RuntimeVisitor* copied);

    static string getOptrParam(const string& optr, int paraIndex);

    //  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^block^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    std::any visitBlock(JavaParser::BlockContext* ctx) override;

    std::any visitBlockStatement(JavaParser::BlockStatementContext* ctx) override;

    std::any visitLocalVariableDeclaration(JavaParser::LocalVariableDeclarationContext* ctx) override;

    std::any addLocalVariable(VariableDeclaration& variableDeclarator, bool fromFor = false, ResolvingItem* initValueItem = NULL);

    std::any visitFieldDeclaration(JavaParser::FieldDeclarationContext* ctx) override;

    //  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^statement^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    std::any visitStatementBlock(JavaParser::StatementBlockContext* ctx) override;

    void visitStatementBlock(JavaParser::BlockContext* ctx);

    int visitInitBlockForClass(JavaParser::BlockContext* ctx, int stateCount);

    std::any visitStatementAssert(JavaParser::StatementAssertContext* ctx) override;

    std::any visitStatementIf(JavaParser::StatementIfContext* ctx) override;

    std::any visitStatementFor(JavaParser::StatementForContext* ctx) override;

    std::any visitStatementWhile(JavaParser::StatementWhileContext* ctx) override;

    std::any visitStatementDoWhile(JavaParser::StatementDoWhileContext* ctx) override;

    std::any visitStatementSwitch(JavaParser::StatementSwitchContext* ctx) override;

    std::any visitStatementTry(JavaParser::StatementTryContext* ctx) override;

    std::any visitStatementSync(JavaParser::StatementSyncContext* ctx) override;

    std::any visitStatementReturn(JavaParser::StatementReturnContext* ctx) override;

    std::any visitStatementThrow(JavaParser::StatementThrowContext* ctx) override;

    std::any visitStatementBreak(JavaParser::StatementBreakContext* ctx) override;

    std::any visitStatementContinue(JavaParser::StatementContinueContext* ctx) override;

    std::any visitStatementYield(JavaParser::StatementYieldContext* ctx) override;

    any visitStatementSemi(JavaParser::StatementSemiContext* ctx) override;

    std::any visitStatementSwitchExp(JavaParser::StatementSwitchExpContext* ctx) override;

    any visitStatementLabel(JavaParser::StatementLabelContext* ctx) override;

    //  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^expression^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    std::any visitPrimaryExp(JavaParser::PrimaryExpContext* ctx) override;

    std::any visitPrimaryThis(JavaParser::PrimaryThisContext* ctx) override;

    std::any visitPrimarySuper(JavaParser::PrimarySuperContext* ctx) override;

    std::any visitPrimaryLiteral(JavaParser::PrimaryLiteralContext* ctx) override;

    std::any visitPrimaryIdentifier(JavaParser::PrimaryIdentifierContext* ctx) override;

    std::any visitPrimaryClass(JavaParser::PrimaryClassContext* ctx) override;

    std::any visitPrimaryMethodCallWithExplicitTypeArgument(JavaParser::PrimaryMethodCallWithExplicitTypeArgumentContext* ctx) override;

    std::any visitExpressionReference(JavaParser::ExpressionReferenceContext* ctx) override;

    std::any visitExpressionArrayAccess(JavaParser::ExpressionArrayAccessContext* ctx) override;

    std::any visitExpressionMethodCall(JavaParser::ExpressionMethodCallContext* ctx) override;

    std::any visitExpressionNew(JavaParser::ExpressionNewContext* ctx) override;

    std::any visitExpressionCast(JavaParser::ExpressionCastContext* ctx) override;

    std::any visitExpressionIncDec(JavaParser::ExpressionIncDecContext* ctx) override;

    std::any visitExpressionPosNegSign(JavaParser::ExpressionPosNegSignContext* ctx) override;

    std::any visitExpressionUnaryLogical(JavaParser::ExpressionUnaryLogicalContext* ctx) override;

    std::any visitExpressionArithmetical(JavaParser::ExpressionArithmeticalContext* ctx) override;

    std::any visitExpressionShift(JavaParser::ExpressionShiftContext* ctx) override;

    std::any visitExpressionRelational(JavaParser::ExpressionRelationalContext* ctx) override;

    std::any visitExpressionInstanceOf(JavaParser::ExpressionInstanceOfContext* ctx) override;

    std::any visitExpressionLogical(JavaParser::ExpressionLogicalContext* ctx) override;

    std::any visitExpressionConditional(JavaParser::ExpressionConditionalContext* ctx) override;

    std::any visitExpressionAssign(JavaParser::ExpressionAssignContext* ctx) override;

    any visitExpressionLambda(JavaParser::ExpressionLambdaContext* ctx) override;

    any visitExpressionSwitch(JavaParser::ExpressionSwitchContext* ctx) override;

    any visitExpressionMethodReference(JavaParser::ExpressionMethodReferenceContext* ctx) override;

    //  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^other^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    ResolvingItem* handleNewArray(NameAndRelatedExp& methodCall);

    void iterNDimArrayRecur(ResolvingItem* superDimItem, JavaParser::ArrayInitializerContext* ctx, int dim, const string& key);

    ResolvingItem* resolveMethod(NameAndRelatedExp& methodCall, ClassScopeAndEnv* scopeAndEnv, bool creator = false);

    void resolveMethod(NameAndRelatedExp& methodCall, ClassScopeAndEnv* scopeAndEnv, ResolvingItem* returnResolvingItem, ResolvingItem* calledMethodResolvingItem, bool creator = false);

    void resolveArgument(NameAndRelatedExp& methodCall, const list<MethodInfo*>& methodInfos, vector<ResolvingItem*>& argValueResolvingItems);

    void hanldeEmptyMethod(NameAndRelatedExp& methodCall, ResolvingItem* returnResolvingItem, ResolvingItem* calledMethodResolvingItem);

    void hanldeEmptyMethod(NameAndRelatedExp& methodCall, vector<ResolvingItem*>& argValueResolvingItems, ResolvingItem* returnResolvingItem, ResolvingItem* calledMethodResolvingItem);

    void handleMethodInfo(MethodInfo* methodInfo, const vector<ResolvingItem*>& argValueResolvingItems,
        ResolvingItem* returnResolvingItem, ResolvingItem* calledMethodResolvingItem);

    void getAllInterfaceRecurSuper(TypeInfo* interfaceInfo, list<TypeInfo*>& interfaceInfos);
};

// todo add class initializer(static initializer) to (i dont know where yet)
// todo add instance initializer(none static initializer) to constructor
//The order of calls is the following:
//      Non-static blocks* of the superclass
//      Constructor of the superclass
//      Non-static blocks* of the class
//      Constructor of the class
class InitializerVisitor : public RuntimeVisitor, public PooledItem<InitializerVisitor> {
public:
    ClassLevelVisitor* classLevelVisitor = NULL;
    JavaParser::ClassBodyContext* classBody = NULL;
    StatementVisitor* stateVisitorForCurrentMethod = NULL;

    std::any visitClassBody(JavaParser::ClassBodyContext* ctx) override;
    std::any visitConstructorDeclaration(JavaParser::ConstructorDeclarationContext* ctx) override;
    std::any visitFieldDeclarationOfClassBody(JavaParser::ClassBodyContext* ctx);

    void reset() override;

};

class AnonymousVisitor : public RuntimeVisitor, public PooledItem<AnonymousVisitor> {
public:

    MethodScopeAndEnv* outerMethodScopeAndEnv = NULL;
    TypeInfo* superTypeInfo = NULL;
    string positionKey;
    TypeInfo* typeInfo = NULL;
    map<string, FieldInfo*> name2calledInfo;
    map<JavaParser::MethodDeclarationContext*, MethodScopeAndEnv*> ctx2methodScopeAndEnv;

    void makeTypeInfo();

    void makeClassScopeEnv();

    void visitForMembers(JavaParser::ClassBodyContext* ctx);

    std::any visitClassBody(JavaParser::ClassBodyContext* ctx) override;

    std::any visitLambda(JavaParser::LambdaExpressionContext* ctx, MethodInfo* superMethodInfo, list<string>& paramNames);

    std::any visitMethodDeclaration(JavaParser::MethodDeclarationContext* ctx) override;

    void reset() override;

};