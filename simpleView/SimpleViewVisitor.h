
// Generated from SimpleView.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleViewParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SimpleViewParser.
 */
class  SimpleViewVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SimpleViewParser.
   */
    virtual std::any visitCompilationUnit(SimpleViewParser::CompilationUnitContext *context) = 0;

    virtual std::any visitGlueAttr(SimpleViewParser::GlueAttrContext *context) = 0;

    virtual std::any visitClassScopeExp(SimpleViewParser::ClassScopeExpContext *context) = 0;

    virtual std::any visitNodeExp(SimpleViewParser::NodeExpContext *context) = 0;

    virtual std::any visitParamList(SimpleViewParser::ParamListContext *context) = 0;

    virtual std::any visitLineExp(SimpleViewParser::LineExpContext *context) = 0;

    virtual std::any visitLineSegOrNodeExp(SimpleViewParser::LineSegOrNodeExpContext *context) = 0;

    virtual std::any visitLineArgumentList(SimpleViewParser::LineArgumentListContext *context) = 0;

    virtual std::any visitGraphElement(SimpleViewParser::GraphElementContext *context) = 0;

    virtual std::any visitGraphBody(SimpleViewParser::GraphBodyContext *context) = 0;

    virtual std::any visitPointInLine(SimpleViewParser::PointInLineContext *context) = 0;

    virtual std::any visitIntersectionPoint(SimpleViewParser::IntersectionPointContext *context) = 0;

    virtual std::any visitClassScopeDeclaration(SimpleViewParser::ClassScopeDeclarationContext *context) = 0;

    virtual std::any visitNodeDeclaration(SimpleViewParser::NodeDeclarationContext *context) = 0;

    virtual std::any visitLineDeclaration(SimpleViewParser::LineDeclarationContext *context) = 0;

    virtual std::any visitGlueDeclaration(SimpleViewParser::GlueDeclarationContext *context) = 0;

    virtual std::any visitGraphDeclaration(SimpleViewParser::GraphDeclarationContext *context) = 0;

    virtual std::any visitLineAndGraphInstance(SimpleViewParser::LineAndGraphInstanceContext *context) = 0;

    virtual std::any visitShowCommand(SimpleViewParser::ShowCommandContext *context) = 0;


};

