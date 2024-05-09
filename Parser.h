#ifndef JPARSER_PARSER_H
#define JPARSER_PARSER_H

class ErrorListener : public antlr4::BaseErrorListener {
public:
    const char* filePath1;
    const char* filePath2;

    ErrorListener(const char* filePath1, const char* filePath2);

    void syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const string& msg, std::exception_ptr e) override;
};

namespace app {
    class Parser {
    public:
        bool parsing = false;
        std::mutex counterLock;
        int currentCountPass1 = 0;
        int currentCountPass2 = 0;
        int totalCountPass = 0;
        int parseTime = 0;

        void visit(const char* originSrcFilePath, JavaParser* parser, ParseTreeToHeaderObjVisitor* visitor);

        void visit(const char* originSrcFilePath, JavaParser* parser, ClassLevelVisitor* visitor);

        template<class LexerType, class ParserType, class VisitorType>
        void parseFile(const char* originSrcFilePath, const char* filePathToParse) {
            // setup parser
            std::ifstream stream(filePathToParse);
            antlr4::ANTLRInputStream inputStream(stream);
            LexerType lexer(&inputStream);
            antlr4::CommonTokenStream tokenStream(&lexer);
            ParserType parser(&tokenStream);
            // add error listener
            ErrorListener e(originSrcFilePath, filePathToParse);
            parser.removeErrorListeners();
            parser.addErrorListener(&e);
            // consume parser with visitor
            VisitorType visitor;
            visit(originSrcFilePath, &parser, &visitor);
            // clean up
            parser.reset();
            tokenStream.reset();
            lexer.reset();
            inputStream.reset();
            stream.close();
        };

        void parse(const string& path);

        void release();

        float getProgressPass1();

        string getProgressTextPass1();

        float getProgressPass2();

        string getProgressTextPass2();

        string getParseTime();
    };
}


#endif //JPARSER_PARSER_H
