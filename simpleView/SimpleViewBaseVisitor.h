
// Generated from SimpleView.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "SimpleViewVisitor.h"


/**
 * This class provides an empty implementation of SimpleViewVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SimpleViewBaseVisitor : public SimpleViewVisitor {
public:

  virtual std::any visitCompilationUnit(SimpleViewParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlueAttr(SimpleViewParser::GlueAttrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassScopeExp(SimpleViewParser::ClassScopeExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeExp(SimpleViewParser::NodeExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamList(SimpleViewParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLineExp(SimpleViewParser::LineExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLineSegOrNodeExp(SimpleViewParser::LineSegOrNodeExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLineArgumentList(SimpleViewParser::LineArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphElement(SimpleViewParser::GraphElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphBody(SimpleViewParser::GraphBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPointInLine(SimpleViewParser::PointInLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntersectionPoint(SimpleViewParser::IntersectionPointContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassScopeDeclaration(SimpleViewParser::ClassScopeDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeDeclaration(SimpleViewParser::NodeDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLineDeclaration(SimpleViewParser::LineDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlueDeclaration(SimpleViewParser::GlueDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphDeclaration(SimpleViewParser::GraphDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLineAndGraphInstance(SimpleViewParser::LineAndGraphInstanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShowCommand(SimpleViewParser::ShowCommandContext *ctx) override {
    return visitChildren(ctx);
  }


};

