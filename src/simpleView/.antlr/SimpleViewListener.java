// Generated from /home/ydd/shishandaimaViewer/simpleView/SimpleView.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link SimpleViewParser}.
 */
public interface SimpleViewListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void enterCompilationUnit(SimpleViewParser.CompilationUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void exitCompilationUnit(SimpleViewParser.CompilationUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#glueAttr}.
	 * @param ctx the parse tree
	 */
	void enterGlueAttr(SimpleViewParser.GlueAttrContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#glueAttr}.
	 * @param ctx the parse tree
	 */
	void exitGlueAttr(SimpleViewParser.GlueAttrContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#classScopeExp}.
	 * @param ctx the parse tree
	 */
	void enterClassScopeExp(SimpleViewParser.ClassScopeExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#classScopeExp}.
	 * @param ctx the parse tree
	 */
	void exitClassScopeExp(SimpleViewParser.ClassScopeExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#nodeExp}.
	 * @param ctx the parse tree
	 */
	void enterNodeExp(SimpleViewParser.NodeExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#nodeExp}.
	 * @param ctx the parse tree
	 */
	void exitNodeExp(SimpleViewParser.NodeExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#paramList}.
	 * @param ctx the parse tree
	 */
	void enterParamList(SimpleViewParser.ParamListContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#paramList}.
	 * @param ctx the parse tree
	 */
	void exitParamList(SimpleViewParser.ParamListContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#lineExp}.
	 * @param ctx the parse tree
	 */
	void enterLineExp(SimpleViewParser.LineExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#lineExp}.
	 * @param ctx the parse tree
	 */
	void exitLineExp(SimpleViewParser.LineExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#lineSegOrNodeExp}.
	 * @param ctx the parse tree
	 */
	void enterLineSegOrNodeExp(SimpleViewParser.LineSegOrNodeExpContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#lineSegOrNodeExp}.
	 * @param ctx the parse tree
	 */
	void exitLineSegOrNodeExp(SimpleViewParser.LineSegOrNodeExpContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#lineArgumentList}.
	 * @param ctx the parse tree
	 */
	void enterLineArgumentList(SimpleViewParser.LineArgumentListContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#lineArgumentList}.
	 * @param ctx the parse tree
	 */
	void exitLineArgumentList(SimpleViewParser.LineArgumentListContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#graphElement}.
	 * @param ctx the parse tree
	 */
	void enterGraphElement(SimpleViewParser.GraphElementContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#graphElement}.
	 * @param ctx the parse tree
	 */
	void exitGraphElement(SimpleViewParser.GraphElementContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#graphBody}.
	 * @param ctx the parse tree
	 */
	void enterGraphBody(SimpleViewParser.GraphBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#graphBody}.
	 * @param ctx the parse tree
	 */
	void exitGraphBody(SimpleViewParser.GraphBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#pointInLine}.
	 * @param ctx the parse tree
	 */
	void enterPointInLine(SimpleViewParser.PointInLineContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#pointInLine}.
	 * @param ctx the parse tree
	 */
	void exitPointInLine(SimpleViewParser.PointInLineContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#intersectionPoint}.
	 * @param ctx the parse tree
	 */
	void enterIntersectionPoint(SimpleViewParser.IntersectionPointContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#intersectionPoint}.
	 * @param ctx the parse tree
	 */
	void exitIntersectionPoint(SimpleViewParser.IntersectionPointContext ctx);
	/**
	 * Enter a parse tree produced by the {@code classScopeDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterClassScopeDeclaration(SimpleViewParser.ClassScopeDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code classScopeDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitClassScopeDeclaration(SimpleViewParser.ClassScopeDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code nodeDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterNodeDeclaration(SimpleViewParser.NodeDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code nodeDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitNodeDeclaration(SimpleViewParser.NodeDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code lineDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterLineDeclaration(SimpleViewParser.LineDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code lineDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitLineDeclaration(SimpleViewParser.LineDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code glueDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterGlueDeclaration(SimpleViewParser.GlueDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code glueDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitGlueDeclaration(SimpleViewParser.GlueDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code graphDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterGraphDeclaration(SimpleViewParser.GraphDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code graphDeclaration}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitGraphDeclaration(SimpleViewParser.GraphDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code lineAndGraphInstance}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterLineAndGraphInstance(SimpleViewParser.LineAndGraphInstanceContext ctx);
	/**
	 * Exit a parse tree produced by the {@code lineAndGraphInstance}
	 * labeled alternative in {@link SimpleViewParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitLineAndGraphInstance(SimpleViewParser.LineAndGraphInstanceContext ctx);
	/**
	 * Enter a parse tree produced by {@link SimpleViewParser#showCommand}.
	 * @param ctx the parse tree
	 */
	void enterShowCommand(SimpleViewParser.ShowCommandContext ctx);
	/**
	 * Exit a parse tree produced by {@link SimpleViewParser#showCommand}.
	 * @param ctx the parse tree
	 */
	void exitShowCommand(SimpleViewParser.ShowCommandContext ctx);
}