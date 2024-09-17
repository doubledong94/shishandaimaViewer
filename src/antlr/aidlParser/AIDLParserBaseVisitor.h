
// Generated from AIDLParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "AIDLParserVisitor.h"


/**
 * This class provides an empty implementation of AIDLParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AIDLParserBaseVisitor : public AIDLParserVisitor {
public:

  virtual std::any visitCompilationUnit(AIDLParser::CompilationUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(AIDLParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptional_package(AIDLParser::Optional_packageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImports(AIDLParser::ImportsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportI(AIDLParser::ImportIContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQualified_name(AIDLParser::Qualified_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecls(AIDLParser::DeclsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(AIDLParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnannotated_decl(AIDLParser::Unannotated_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_params(AIDLParser::Type_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptional_type_params(AIDLParser::Optional_type_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptional_unstructured_headers(AIDLParser::Optional_unstructured_headersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParcelable_decl(AIDLParser::Parcelable_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParcelable_members(AIDLParser::Parcelable_membersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable_decl(AIDLParser::Variable_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterface_decl(AIDLParser::Interface_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterface_members(AIDLParser::Interface_membersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_expr(AIDLParser::Const_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_value_list(AIDLParser::Constant_value_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_value_non_empty_list(AIDLParser::Constant_value_non_empty_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_decl(AIDLParser::Constant_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumerator(AIDLParser::EnumeratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumerators(AIDLParser::EnumeratorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnum_decl_body(AIDLParser::Enum_decl_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnum_decl(AIDLParser::Enum_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnion_decl(AIDLParser::Union_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethod_decl(AIDLParser::Method_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg_non_empty_list(AIDLParser::Arg_non_empty_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg(AIDLParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNon_array_type(AIDLParser::Non_array_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(AIDLParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_args(AIDLParser::Type_argsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotation_list(AIDLParser::Annotation_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(AIDLParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_non_empty_list(AIDLParser::Parameter_non_empty_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnotation(AIDLParser::AnnotationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDirection(AIDLParser::DirectionContext *ctx) override {
    return visitChildren(ctx);
  }


};

