#ifndef JPARSER_SIMPLEVIEWTOGRAPHCONVERTER_H
#define JPARSER_SIMPLEVIEWTOGRAPHCONVERTER_H

namespace SimpleView {

    const static string ALPHABET_FOR_NODE_ENCODING = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    class SimpleViewToGraphConverter : public SimpleViewBaseVisitor {
    public:
        static map<string, NodeStyle*> valNameToNodeStyle;
        static map<string, BasicStyle*> valNameToBasicNodeStyle;

        static vector<string> classScopeNameOrder;
        static vector<string> nodeNameOrder;
        static vector<string> lineNameOrder;
        static vector<string> graphNameOrder;
        static vector<string> lineInstanceNameOrder;
        static vector<string> graphInstanceNameOrder;
        static map<string, ClassScope*> valNameToClassScope;
        static map<string, Node*> valNameToNode;
        static map<string, LineTemplate*> valNameToLine;
        static map<string, GraphTemplate*> valNameToGraph;
        static map<string, LineInstance*> valNameToLineInstance;
        static map<string, GraphInstance*> valNameToGraphInstance;

        static void addNode(const string& name, const list<pair<string,string>>& key);

        list<string> showingGraph;
        list<ClassScope*> allDistinctClassScope;
        list<Node*> allDistinctNodes;

        any visitCompilationUnit(SimpleViewParser::CompilationUnitContext* ctx) override;

        any visitClassScopeExp(SimpleViewParser::ClassScopeExpContext* ctx) override;

        any visitNodeExp(SimpleViewParser::NodeExpContext* ctx) override;

        any visitClassScopeDeclaration(SimpleViewParser::ClassScopeDeclarationContext* ctx) override;

        any visitNodeDeclaration(SimpleViewParser::NodeDeclarationContext* ctx) override;

        any visitLineSegOrNodeExp(SimpleViewParser::LineSegOrNodeExpContext* ctx) override;

        any visitLineDeclaration(SimpleViewParser::LineDeclarationContext* ctx) override;

        any visitGraphDeclaration(SimpleViewParser::GraphDeclarationContext* ctx) override;

        any visitPointInLine(SimpleViewParser::PointInLineContext* ctx) override;

        any visitLineAndGraphInstance(SimpleViewParser::LineAndGraphInstanceContext* ctx) override;

        any visitShowCommand(SimpleViewParser::ShowCommandContext* ctx) override;

        void release();
    };

    class SimpleViewErrorListener : public antlr4::BaseErrorListener {
        void syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const string& msg, std::exception_ptr e) override;
    };

    void clearAllAddedFacts();

    void clearAllAddedRules();

}


#endif //JPARSER_SIMPLEVIEWTOGRAPHCONVERTER_H
