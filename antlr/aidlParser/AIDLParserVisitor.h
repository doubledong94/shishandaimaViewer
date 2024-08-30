
// Generated from AIDLParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "AIDLParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AIDLParser.
 */
class  AIDLParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AIDLParser.
   */
    virtual std::any visitCompilationUnit(AIDLParser::CompilationUnitContext *context) = 0;

    virtual std::any visitIdentifier(AIDLParser::IdentifierContext *context) = 0;

    virtual std::any visitOptional_package(AIDLParser::Optional_packageContext *context) = 0;

    virtual std::any visitImports(AIDLParser::ImportsContext *context) = 0;

    virtual std::any visitImportI(AIDLParser::ImportIContext *context) = 0;

    virtual std::any visitQualified_name(AIDLParser::Qualified_nameContext *context) = 0;

    virtual std::any visitDecls(AIDLParser::DeclsContext *context) = 0;

    virtual std::any visitDecl(AIDLParser::DeclContext *context) = 0;

    virtual std::any visitUnannotated_decl(AIDLParser::Unannotated_declContext *context) = 0;

    virtual std::any visitType_params(AIDLParser::Type_paramsContext *context) = 0;

    virtual std::any visitOptional_type_params(AIDLParser::Optional_type_paramsContext *context) = 0;

    virtual std::any visitOptional_unstructured_headers(AIDLParser::Optional_unstructured_headersContext *context) = 0;

    virtual std::any visitParcelable_decl(AIDLParser::Parcelable_declContext *context) = 0;

    virtual std::any visitParcelable_members(AIDLParser::Parcelable_membersContext *context) = 0;

    virtual std::any visitVariable_decl(AIDLParser::Variable_declContext *context) = 0;

    virtual std::any visitInterface_decl(AIDLParser::Interface_declContext *context) = 0;

    virtual std::any visitInterface_members(AIDLParser::Interface_membersContext *context) = 0;

    virtual std::any visitConst_expr(AIDLParser::Const_exprContext *context) = 0;

    virtual std::any visitConstant_value_list(AIDLParser::Constant_value_listContext *context) = 0;

    virtual std::any visitConstant_value_non_empty_list(AIDLParser::Constant_value_non_empty_listContext *context) = 0;

    virtual std::any visitConstant_decl(AIDLParser::Constant_declContext *context) = 0;

    virtual std::any visitEnumerator(AIDLParser::EnumeratorContext *context) = 0;

    virtual std::any visitEnumerators(AIDLParser::EnumeratorsContext *context) = 0;

    virtual std::any visitEnum_decl_body(AIDLParser::Enum_decl_bodyContext *context) = 0;

    virtual std::any visitEnum_decl(AIDLParser::Enum_declContext *context) = 0;

    virtual std::any visitUnion_decl(AIDLParser::Union_declContext *context) = 0;

    virtual std::any visitMethod_decl(AIDLParser::Method_declContext *context) = 0;

    virtual std::any visitArg_non_empty_list(AIDLParser::Arg_non_empty_listContext *context) = 0;

    virtual std::any visitArg(AIDLParser::ArgContext *context) = 0;

    virtual std::any visitNon_array_type(AIDLParser::Non_array_typeContext *context) = 0;

    virtual std::any visitType(AIDLParser::TypeContext *context) = 0;

    virtual std::any visitType_args(AIDLParser::Type_argsContext *context) = 0;

    virtual std::any visitAnnotation_list(AIDLParser::Annotation_listContext *context) = 0;

    virtual std::any visitParameter(AIDLParser::ParameterContext *context) = 0;

    virtual std::any visitParameter_non_empty_list(AIDLParser::Parameter_non_empty_listContext *context) = 0;

    virtual std::any visitAnnotation(AIDLParser::AnnotationContext *context) = 0;

    virtual std::any visitDirection(AIDLParser::DirectionContext *context) = 0;


};

