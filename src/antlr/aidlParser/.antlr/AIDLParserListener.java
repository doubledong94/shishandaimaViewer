// Generated from /home/ydd/shishandaimaViewer/antlr/aidlParser/AIDLParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link AIDLParser}.
 */
public interface AIDLParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link AIDLParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void enterCompilationUnit(AIDLParser.CompilationUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void exitCompilationUnit(AIDLParser.CompilationUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#identifier}.
	 * @param ctx the parse tree
	 */
	void enterIdentifier(AIDLParser.IdentifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#identifier}.
	 * @param ctx the parse tree
	 */
	void exitIdentifier(AIDLParser.IdentifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#optional_package}.
	 * @param ctx the parse tree
	 */
	void enterOptional_package(AIDLParser.Optional_packageContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#optional_package}.
	 * @param ctx the parse tree
	 */
	void exitOptional_package(AIDLParser.Optional_packageContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#imports}.
	 * @param ctx the parse tree
	 */
	void enterImports(AIDLParser.ImportsContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#imports}.
	 * @param ctx the parse tree
	 */
	void exitImports(AIDLParser.ImportsContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#importI}.
	 * @param ctx the parse tree
	 */
	void enterImportI(AIDLParser.ImportIContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#importI}.
	 * @param ctx the parse tree
	 */
	void exitImportI(AIDLParser.ImportIContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#qualified_name}.
	 * @param ctx the parse tree
	 */
	void enterQualified_name(AIDLParser.Qualified_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#qualified_name}.
	 * @param ctx the parse tree
	 */
	void exitQualified_name(AIDLParser.Qualified_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#decls}.
	 * @param ctx the parse tree
	 */
	void enterDecls(AIDLParser.DeclsContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#decls}.
	 * @param ctx the parse tree
	 */
	void exitDecls(AIDLParser.DeclsContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#decl}.
	 * @param ctx the parse tree
	 */
	void enterDecl(AIDLParser.DeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#decl}.
	 * @param ctx the parse tree
	 */
	void exitDecl(AIDLParser.DeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#unannotated_decl}.
	 * @param ctx the parse tree
	 */
	void enterUnannotated_decl(AIDLParser.Unannotated_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#unannotated_decl}.
	 * @param ctx the parse tree
	 */
	void exitUnannotated_decl(AIDLParser.Unannotated_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#type_params}.
	 * @param ctx the parse tree
	 */
	void enterType_params(AIDLParser.Type_paramsContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#type_params}.
	 * @param ctx the parse tree
	 */
	void exitType_params(AIDLParser.Type_paramsContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#optional_type_params}.
	 * @param ctx the parse tree
	 */
	void enterOptional_type_params(AIDLParser.Optional_type_paramsContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#optional_type_params}.
	 * @param ctx the parse tree
	 */
	void exitOptional_type_params(AIDLParser.Optional_type_paramsContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#optional_unstructured_headers}.
	 * @param ctx the parse tree
	 */
	void enterOptional_unstructured_headers(AIDLParser.Optional_unstructured_headersContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#optional_unstructured_headers}.
	 * @param ctx the parse tree
	 */
	void exitOptional_unstructured_headers(AIDLParser.Optional_unstructured_headersContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#parcelable_decl}.
	 * @param ctx the parse tree
	 */
	void enterParcelable_decl(AIDLParser.Parcelable_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#parcelable_decl}.
	 * @param ctx the parse tree
	 */
	void exitParcelable_decl(AIDLParser.Parcelable_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#parcelable_members}.
	 * @param ctx the parse tree
	 */
	void enterParcelable_members(AIDLParser.Parcelable_membersContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#parcelable_members}.
	 * @param ctx the parse tree
	 */
	void exitParcelable_members(AIDLParser.Parcelable_membersContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#variable_decl}.
	 * @param ctx the parse tree
	 */
	void enterVariable_decl(AIDLParser.Variable_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#variable_decl}.
	 * @param ctx the parse tree
	 */
	void exitVariable_decl(AIDLParser.Variable_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#interface_decl}.
	 * @param ctx the parse tree
	 */
	void enterInterface_decl(AIDLParser.Interface_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#interface_decl}.
	 * @param ctx the parse tree
	 */
	void exitInterface_decl(AIDLParser.Interface_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#interface_members}.
	 * @param ctx the parse tree
	 */
	void enterInterface_members(AIDLParser.Interface_membersContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#interface_members}.
	 * @param ctx the parse tree
	 */
	void exitInterface_members(AIDLParser.Interface_membersContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_expr(AIDLParser.Const_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_expr(AIDLParser.Const_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#constant_value_list}.
	 * @param ctx the parse tree
	 */
	void enterConstant_value_list(AIDLParser.Constant_value_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#constant_value_list}.
	 * @param ctx the parse tree
	 */
	void exitConstant_value_list(AIDLParser.Constant_value_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#constant_value_non_empty_list}.
	 * @param ctx the parse tree
	 */
	void enterConstant_value_non_empty_list(AIDLParser.Constant_value_non_empty_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#constant_value_non_empty_list}.
	 * @param ctx the parse tree
	 */
	void exitConstant_value_non_empty_list(AIDLParser.Constant_value_non_empty_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#constant_decl}.
	 * @param ctx the parse tree
	 */
	void enterConstant_decl(AIDLParser.Constant_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#constant_decl}.
	 * @param ctx the parse tree
	 */
	void exitConstant_decl(AIDLParser.Constant_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#enumerator}.
	 * @param ctx the parse tree
	 */
	void enterEnumerator(AIDLParser.EnumeratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#enumerator}.
	 * @param ctx the parse tree
	 */
	void exitEnumerator(AIDLParser.EnumeratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#enumerators}.
	 * @param ctx the parse tree
	 */
	void enterEnumerators(AIDLParser.EnumeratorsContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#enumerators}.
	 * @param ctx the parse tree
	 */
	void exitEnumerators(AIDLParser.EnumeratorsContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#enum_decl_body}.
	 * @param ctx the parse tree
	 */
	void enterEnum_decl_body(AIDLParser.Enum_decl_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#enum_decl_body}.
	 * @param ctx the parse tree
	 */
	void exitEnum_decl_body(AIDLParser.Enum_decl_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#enum_decl}.
	 * @param ctx the parse tree
	 */
	void enterEnum_decl(AIDLParser.Enum_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#enum_decl}.
	 * @param ctx the parse tree
	 */
	void exitEnum_decl(AIDLParser.Enum_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#union_decl}.
	 * @param ctx the parse tree
	 */
	void enterUnion_decl(AIDLParser.Union_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#union_decl}.
	 * @param ctx the parse tree
	 */
	void exitUnion_decl(AIDLParser.Union_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#method_decl}.
	 * @param ctx the parse tree
	 */
	void enterMethod_decl(AIDLParser.Method_declContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#method_decl}.
	 * @param ctx the parse tree
	 */
	void exitMethod_decl(AIDLParser.Method_declContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#arg_non_empty_list}.
	 * @param ctx the parse tree
	 */
	void enterArg_non_empty_list(AIDLParser.Arg_non_empty_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#arg_non_empty_list}.
	 * @param ctx the parse tree
	 */
	void exitArg_non_empty_list(AIDLParser.Arg_non_empty_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#arg_list}.
	 * @param ctx the parse tree
	 */
	void enterArg_list(AIDLParser.Arg_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#arg_list}.
	 * @param ctx the parse tree
	 */
	void exitArg_list(AIDLParser.Arg_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#arg}.
	 * @param ctx the parse tree
	 */
	void enterArg(AIDLParser.ArgContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#arg}.
	 * @param ctx the parse tree
	 */
	void exitArg(AIDLParser.ArgContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#non_array_type}.
	 * @param ctx the parse tree
	 */
	void enterNon_array_type(AIDLParser.Non_array_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#non_array_type}.
	 * @param ctx the parse tree
	 */
	void exitNon_array_type(AIDLParser.Non_array_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(AIDLParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(AIDLParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#type_args}.
	 * @param ctx the parse tree
	 */
	void enterType_args(AIDLParser.Type_argsContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#type_args}.
	 * @param ctx the parse tree
	 */
	void exitType_args(AIDLParser.Type_argsContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#annotation_list}.
	 * @param ctx the parse tree
	 */
	void enterAnnotation_list(AIDLParser.Annotation_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#annotation_list}.
	 * @param ctx the parse tree
	 */
	void exitAnnotation_list(AIDLParser.Annotation_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#parameter}.
	 * @param ctx the parse tree
	 */
	void enterParameter(AIDLParser.ParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#parameter}.
	 * @param ctx the parse tree
	 */
	void exitParameter(AIDLParser.ParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterParameter_list(AIDLParser.Parameter_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitParameter_list(AIDLParser.Parameter_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#parameter_non_empty_list}.
	 * @param ctx the parse tree
	 */
	void enterParameter_non_empty_list(AIDLParser.Parameter_non_empty_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#parameter_non_empty_list}.
	 * @param ctx the parse tree
	 */
	void exitParameter_non_empty_list(AIDLParser.Parameter_non_empty_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#annotation}.
	 * @param ctx the parse tree
	 */
	void enterAnnotation(AIDLParser.AnnotationContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#annotation}.
	 * @param ctx the parse tree
	 */
	void exitAnnotation(AIDLParser.AnnotationContext ctx);
	/**
	 * Enter a parse tree produced by {@link AIDLParser#direction}.
	 * @param ctx the parse tree
	 */
	void enterDirection(AIDLParser.DirectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link AIDLParser#direction}.
	 * @param ctx the parse tree
	 */
	void exitDirection(AIDLParser.DirectionContext ctx);
}