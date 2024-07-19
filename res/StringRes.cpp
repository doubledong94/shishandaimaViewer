#include "../util/util.h"
#include "StringRes.h"

char* StringRes::getAppName() { return NULL; };
char* StringRes::getString_close() { return NULL; };
char* StringRes::getHotkeyEditor() { return NULL; };
char* StringRes::getRadioText_SingleClick() { return NULL; };
char* StringRes::getRadioText_DoubleClick() { return NULL; };
char* StringRes::getRadioText_LongPress() { return NULL; }
char* StringRes::getSearchClass() {
    return nullptr;
}
char* StringRes::getSearchNodeInGraph() {
    return nullptr;
}
char* StringRes::getSearchExisting() {
    return nullptr;
}
;

StringRes* StringRes::singleton = NULL;

char* ChineseStringRes::getAppName() { return appName.data(); }
char* ChineseStringRes::getString_close() { return string_close.data(); }
char* ChineseStringRes::getHotkeyEditor() { return hotkeyEditor.data(); }
char* ChineseStringRes::getRadioText_SingleClick() { return radioText_SingleClick.data(); }
char* ChineseStringRes::getRadioText_DoubleClick() { return radioText_DoubleClick.data(); }
char* ChineseStringRes::getRadioText_LongPress() { return radioText_LongPress.data(); }

char* ChineseStringRes::getSearchClass() {
    return searchClassText.data();
}

char* ChineseStringRes::getSearchNodeInGraph() {
    return searchNodeText.data();
}

char* ChineseStringRes::getSearchExisting() {
    return searchExistingText.data();
}

char* ChineseStringRes::getHotKeyTitle_cate_prepare1() {
    return hotKeyTitle_cate_prepare1.data();
}

char* ChineseStringRes::getHotKeyTitle_cate_prepare2() {
    return hotKeyTitle_cate_prepare2.data();
}

char* ChineseStringRes::getHotKeyTitle_cate_add_and_delete_node() {
    return hotKeyTitle_cate_add_and_delete_node.data();
}

char* ChineseStringRes::getHotKeyTitle_cate_select_node() {
    return hotKeyTitle_cate_select_node.data();
}

char* ChineseStringRes::getHotKeyTitle_cate_layout() {
    return hotKeyTitle_cate_layout.data();
}

char* ChineseStringRes::getHotKeyTitle_cate_style() {
    return hotKeyTitle_cate_style.data();
}

char* ChineseStringRes::getHotKeyTitle_cate_next_round() {
    return hotKeyTitle_cate_next_round.data();
}

char* ChineseStringRes::getHotKeyTitle_cate_explore() {
    return hotKeyTitle_cate_explore.data();
}

char* ChineseStringRes::getHotKeyTitle_parseSrc() { return hotKeyTitle_parseSrc.data(); }
char* ChineseStringRes::getHotKeyTitle_editLineAndGraph() { return hotKeyTitle_editLineAndGraph.data(); }
char* ChineseStringRes::getHotKeyTitle_changeMaxSearchDepth() { return hotKeyTitle_changeMaxSearchDepth.data(); }
char* ChineseStringRes::getHotKeyTitle_chooseClass() { return hotKeyTitle_chooseClass.data(); }
char* ChineseStringRes::getHotKeyTitle_chooseLine() { return hotKeyTitle_chooseLine.data(); }
char* ChineseStringRes::getHotKeyTitle_chooseGraph() { return hotKeyTitle_chooseGraph.data(); }
char* ChineseStringRes::getHotKeyTitle_unchooseClass() { return hotKeyTitle_unchooseClass.data(); }
char* ChineseStringRes::getHotKeyTitle_unchooseLine() { return hotKeyTitle_unchooseLine.data(); }
char* ChineseStringRes::getHotKeyTitle_unchooseGraph() { return hotKeyTitle_unchooseGraph.data(); }
char* ChineseStringRes::getHotKeyTitle_startSearch() { return hotKeyTitle_startSearch.data(); }
char* ChineseStringRes::getHotKeyTitle_deleteNode() { return hotKeyTitle_deleteNode.data(); }
char* ChineseStringRes::getHotKeyTitle_deleteAllNode() { return hotKeyTitle_deleteAllNode.data(); }
char* ChineseStringRes::getHotKeyTitle_transitiveReduction() { return hotKeyTitle_transitiveReduction.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeByPosition() { return hotKeyTitle_selectNodeByPosition.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeByKeyType() { return hotKeyTitle_selectByKeyType.data(); }
char* ChineseStringRes::getHotKeyTitle_selectFromAll() { return hotKeyTitle_selectFromAll.data(); }
char* ChineseStringRes::getHotKeyTitle_selectAllNode() { return hotKeyTitle_selectAllNode.data(); }
char* ChineseStringRes::getHotKeyTitle_unselectAllNode() { return hotKeyTitle_unselectAllNode.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeUpward() { return hotKeyTitle_selectNodeUpward.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeDownward() { return hotKeyTitle_selectNodeDownward.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeUpwardToTheTop() { return hotKeyTitle_selectNodeUpwardToTheTop.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeDownwardToTheBottom() { return hotKeyTitle_selectNodeDownwardToTheBottom.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeBackward() { return hotKeyTitle_selectNodeBackward.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeInBetween() { return hotKeyTitle_selectNodeInBetween.data(); }
char* ChineseStringRes::getHotKeyTitle_selectPathUpward() { return hotKeyTitle_selectPathUpward.data(); }
char* ChineseStringRes::getHotKeyTitle_selectPathDownward() { return hotKeyTitle_selectPathDownward.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeByInDegree() { return hotKeyTitle_selectNodeByInDegree.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeByOutDegree() { return hotKeyTitle_selectNodeByOutDegree.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeByDegree() { return hotKeyTitle_selectNodeByDegree.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeByMethodStackSize() { return hotKeyTitle_selectNodeByMethodStackSize.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeByComponent() { return hotKeyTitle_selectNodeByComponent.data(); }
char* ChineseStringRes::getHotKeyTitle_selectNodeByGroup() { return hotKeyTitle_selectNodeByGroup.data(); }
char* ChineseStringRes::getHotKeyTitle_dimControlEditor() { return hotKeyTitle_dimControlEditor.data(); }
char* ChineseStringRes::getHotKeyTitle_2DLayout() { return hotKeyTitle_2DLayout.data(); }
char* ChineseStringRes::getHotKeyTitle_3DLayout() { return hotKeyTitle_3DLayout.data(); }
char* ChineseStringRes::getHotKeyTitle_LayoutOnAndOff() { return hotKeyTitle_LayoutOnAndOff.data(); }
char* ChineseStringRes::getHotKeyTitle_LayoutTempIncr() { return hotKeyTitle_LayoutTempIncr.data(); }
char* ChineseStringRes::getHotKeyTitle_LayoutTempDecr() { return hotKeyTitle_LayoutTempDecr.data(); }
char* ChineseStringRes::getHotKeyTitle_FixedPositionOfSelected() { return hotKeyTitle_FixedPositionOfSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unFixedPositionOfSelected() { return hotKeyTitle_unFixedPositionOfSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unFixedPositionOfAllNode() { return hotKeyTitle_unFixedPositionOfAllNode.data(); }
char* ChineseStringRes::getHotKeyTitle_FixedXCoordOfSelected() { return hotKeyTitle_FixedXCoordOfSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unFixedXCoordOfSelected() { return hotKeyTitle_unFixedXCoordOfSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unFixedXCoordOfAllNode() { return hotKeyTitle_unFixedXCoordOfAllNode.data(); }
char* ChineseStringRes::getHotKeyTitle_FixedYCoordOfSelected() { return hotKeyTitle_FixedYCoordOfSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unFixedYCoordOfOfSelected() { return hotKeyTitle_unFixedYCoordOfOfSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unFixedYCoordOfOfAllNode() { return hotKeyTitle_unFixedYCoordOfOfAllNode.data(); }
char* ChineseStringRes::getHotKeyTitle_autoGroupX() { return hotKeyTitle_autoGroupX.data(); }
char* ChineseStringRes::getHotKeyTitle_autoGroupY() { return hotKeyTitle_autoGroupY.data(); }
char* ChineseStringRes::getHotKeyTitle_autoGroupXY() { return hotKeyTitle_autoGroupXY.data(); }
char* ChineseStringRes::getHotKeyTitle_LayoutWeightOfSelectedIncr() { return hotKeyTitle_LayoutWeightOfSelectedIncr.data(); }
char* ChineseStringRes::getHotKeyTitle_LayoutWeightOfSelectedDecr() { return hotKeyTitle_LayoutWeightOfSelectedDecr.data(); }
char* ChineseStringRes::getHotKeyTitle_ResetLayoutWeightOfAllNode() { return hotKeyTitle_ResetLayoutWeightOfAllNode.data(); }
char* ChineseStringRes::getHotKeyTitle_GroupSelected() { return hotKeyTitle_GroupSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unGroupSelected() { return hotKeyTitle_unGroupSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unGroupAllNode() { return hotKeyTitle_unGroupAllNode.data(); }
char* ChineseStringRes::getHotKeyTitle_NodeSizeIncr() { return hotKeyTitle_NodeSizeIncr.data(); }
char* ChineseStringRes::getHotKeyTitle_NodeSizeDecr() { return hotKeyTitle_NodeSizeDecr.data(); }
char* ChineseStringRes::getHotKeyTitle_LineWidthIncr() { return hotKeyTitle_LineWidthIncr.data(); }
char* ChineseStringRes::getHotKeyTitle_LineWidthDecr() { return hotKeyTitle_LineWidthDecr.data(); }
char* ChineseStringRes::getHotKeyTitle_UnselectedNodeAlphaIncr() { return hotKeyTitle_UnselectedNodeAlphaIncr.data(); }
char* ChineseStringRes::getHotKeyTitle_UnselectedNodeAlphaDecr() { return hotKeyTitle_UnselectedNodeAlphaDecr.data(); }
char* ChineseStringRes::getHotKeyTitle_SelectedNodeAlphaIncr() { return hotKeyTitle_SelectedNodeAlphaIncr.data(); }
char* ChineseStringRes::getHotKeyTitle_SelectedNodeAlphaDecr() { return hotKeyTitle_SelectedNodeAlphaDecr.data(); }
char* ChineseStringRes::getHotKeyTitle_ColorNodeByFlow() { return hotKeyTitle_ColorNodeByFlow.data(); }
char* ChineseStringRes::getHotKeyTitle_ClearAllNodeColor() { return hotKeyTitle_ClearAllNodeColor.data(); }
char* ChineseStringRes::getHotKeyTitle_ShowAndHideTooltip() { return hotKeyTitle_ShowAndHideTooltip.data(); }
char* ChineseStringRes::getHotKeyTitle_ShowAndHideBoundFrame() { return hotKeyTitle_ShowAndHideBoundFrame.data(); }
char* ChineseStringRes::getHotKeyTitle_ChooseColorForSelectedNode() { return hotKeyTitle_ChooseColorForSelectedNode.data(); }
char* ChineseStringRes::getHotKeyTitle_NodeTextOnAndOff() { return hotKeyTitle_NodeTextOnAndOff.data(); }
char* ChineseStringRes::getHotKeyTitle_NodeTextSizeIncr() { return hotKeyTitle_NodeTextSizeIncr.data(); }
char* ChineseStringRes::getHotKeyTitle_NodeTextSizeDecr() { return hotKeyTitle_NodeTextSizeDecr.data(); }
char* ChineseStringRes::getHotKeyTitle_GUITextSizeIncr() { return hotKeyTitle_GUITextSizeIncr.data(); }
char* ChineseStringRes::getHotKeyTitle_GUITextSizeDecr() { return hotKeyTitle_GUITextSizeDecr.data(); }
char* ChineseStringRes::getHotKeyTitle_SaveSelectedNode() { return hotKeyTitle_SaveSelectedNode.data(); }

char* ChineseStringRes::getHotKeyTitle_searchUpward() {
    return hotKeyTitle_ExploreUpward.data();
}

char* ChineseStringRes::getHotKeyTitle_searchDownward() {
    return hotKeyTitle_ExploreDownward.data();
}

char* ChineseStringRes::getHotKeyTitle_boundSelected() { return hotKeyTitle_boundSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unboundSelected() { return hotKeyTitle_unboundSelected.data(); }
char* ChineseStringRes::getHotKeyTitle_unboundUnselected() { return hotKeyTitle_unboundUnselected.data(); }
char* ChineseStringRes::getHotKeyTitle_boundByClass() { return hotKeyTitle_boundByClass.data(); }
char* ChineseStringRes::getHotKeyTitle_boundByMethod() { return hotKeyTitle_boundByMethod.data(); }
char* ChineseStringRes::getHotKeyTitle_treeUp() { return hotKeyTitle_treeUp.data(); }
char* ChineseStringRes::getHotKeyTitle_treeDown() { return hotKeyTitle_treeDown.data(); }
char* ChineseStringRes::getHotKeyTitle_cat_saveAndRestoreGraph() { return hotKeyTitle_cat_saveAndRestoreGraph.data(); }
char* ChineseStringRes::getHotKeyTitle_saveGraph() { return hotKeyTitle_saveGraph.data(); }
char* ChineseStringRes::getHotKeyTitle_restoreGraph() { return hotKeyTitle_restoreGraph.data(); }
char* ChineseStringRes::getHotKeyTitle_deleteSavedGraph() { return hotKeyTitle_deleteSavedGraph.data(); }

char* ChineseStringRes::getHint_press1ToShowHotkey() {
    return hint_press1ToShowHotkey.data();
}

char* EnglishStringRes::getAppName() { return appName.data(); }
char* EnglishStringRes::getString_close() { return string_close.data(); }
char* EnglishStringRes::getHotkeyEditor() { return hotkeyEditor.data(); }
char* EnglishStringRes::getRadioText_SingleClick() { return radioText_SingleClick.data(); }
char* EnglishStringRes::getRadioText_DoubleClick() { return radioText_DoubleClick.data(); }
char* EnglishStringRes::getRadioText_LongPress() { return radioText_LongPress.data(); }

char* EnglishStringRes::getSearchClass() {
    return searchClassText.data();
}

char* EnglishStringRes::getSearchNodeInGraph() {
    return searchNodeText.data();
}

char* EnglishStringRes::getSearchExisting() {
    return searchExistingText.data();
}

char* EnglishStringRes::getHotKeyTitle_cate_prepare1() {
    return hotKeyTitle_cate_prepare1.data();
}

char* EnglishStringRes::getHotKeyTitle_cate_prepare2() {
    return hotKeyTitle_cate_prepare2.data();
}

char* EnglishStringRes::getHotKeyTitle_cate_add_and_delete_node() {
    return hotKeyTitle_cate_add_and_delete_node.data();
}

char* EnglishStringRes::getHotKeyTitle_cate_select_node() {
    return hotKeyTitle_cate_select_node.data();
}

char* EnglishStringRes::getHotKeyTitle_cate_layout() {
    return hotKeyTitle_cate_layout.data();
}

char* EnglishStringRes::getHotKeyTitle_cate_style() {
    return hotKeyTitle_cate_style.data();
}

char* EnglishStringRes::getHotKeyTitle_cate_next_round() {
    return hotKeyTitle_cate_next_round.data();
}

char* EnglishStringRes::getHotKeyTitle_cate_explore() {
    return hotKeyTitle_cate_explore.data();
}

char* EnglishStringRes::getHotKeyTitle_parseSrc() { return hotKeyTitle_parseSrc.data(); }
char* EnglishStringRes::getHotKeyTitle_editLineAndGraph() { return hotKeyTitle_editLineAndGraph.data(); }
char* EnglishStringRes::getHotKeyTitle_changeMaxSearchDepth() { return hotKeyTitle_changeMaxSearchDepth.data(); }
char* EnglishStringRes::getHotKeyTitle_chooseClass() { return hotKeyTitle_chooseClass.data(); }
char* EnglishStringRes::getHotKeyTitle_chooseLine() { return hotKeyTitle_chooseLine.data(); }
char* EnglishStringRes::getHotKeyTitle_chooseGraph() { return hotKeyTitle_chooseGraph.data(); }
char* EnglishStringRes::getHotKeyTitle_unchooseClass() { return hotKeyTitle_unchooseClass.data(); }
char* EnglishStringRes::getHotKeyTitle_unchooseLine() { return hotKeyTitle_unchooseLine.data(); }
char* EnglishStringRes::getHotKeyTitle_unchooseGraph() { return hotKeyTitle_unchooseGraph.data(); }
char* EnglishStringRes::getHotKeyTitle_startSearch() { return hotKeyTitle_startSearch.data(); }
char* EnglishStringRes::getHotKeyTitle_deleteNode() { return hotKeyTitle_deleteNode.data(); }
char* EnglishStringRes::getHotKeyTitle_deleteAllNode() { return hotKeyTitle_deleteAllNode.data(); }
char* EnglishStringRes::getHotKeyTitle_transitiveReduction() { return hotKeyTitle_transitiveReduction.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeByPosition() { return hotKeyTitle_selectNodeByPosition.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeByKeyType() { return hotKeyTitle_selectByKeyType.data(); }
char* EnglishStringRes::getHotKeyTitle_selectFromAll() { return hotKeyTitle_selectFromAll.data(); }
char* EnglishStringRes::getHotKeyTitle_selectAllNode() { return hotKeyTitle_selectAllNode.data(); }
char* EnglishStringRes::getHotKeyTitle_unselectAllNode() { return hotKeyTitle_unselectAllNode.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeUpward() { return hotKeyTitle_selectNodeUpward.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeDownward() { return hotKeyTitle_selectNodeDownward.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeUpwardToTheTop() { return hotKeyTitle_selectNodeUpwardToTheTop.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeDownwardToTheBottom() { return hotKeyTitle_selectNodeDownwardToTheBottom.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeBackward() { return hotKeyTitle_selectNodeBackward.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeInBetween() { return hotKeyTitle_selectNodeInBetween.data(); }
char* EnglishStringRes::getHotKeyTitle_selectPathUpward() { return hotKeyTitle_selectPathUpward.data(); }
char* EnglishStringRes::getHotKeyTitle_selectPathDownward() { return hotKeyTitle_selectPathDownward.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeByInDegree() { return hotKeyTitle_selectNodeByInDegree.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeByOutDegree() { return hotKeyTitle_selectNodeByOutDegree.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeByDegree() { return hotKeyTitle_selectNodeByDegree.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeByMethodStackSize() { return hotKeyTitle_selectNodeByMethodStackSize.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeByComponent() { return hotKeyTitle_selectNodeByComponent.data(); }
char* EnglishStringRes::getHotKeyTitle_selectNodeByGroup() { return hotKeyTitle_selectNodeByGroup.data(); }
char* EnglishStringRes::getHotKeyTitle_dimControlEditor() { return hotKeyTitle_dimControlEditor.data(); }
char* EnglishStringRes::getHotKeyTitle_2DLayout() { return hotKeyTitle_2DLayout.data(); }
char* EnglishStringRes::getHotKeyTitle_3DLayout() { return hotKeyTitle_3DLayout.data(); }
char* EnglishStringRes::getHotKeyTitle_LayoutOnAndOff() { return hotKeyTitle_LayoutOnAndOff.data(); }
char* EnglishStringRes::getHotKeyTitle_LayoutTempIncr() { return hotKeyTitle_LayoutTempIncr.data(); }
char* EnglishStringRes::getHotKeyTitle_LayoutTempDecr() { return hotKeyTitle_LayoutTempDecr.data(); }
char* EnglishStringRes::getHotKeyTitle_FixedPositionOfSelected() { return hotKeyTitle_FixedPositionOfSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unFixedPositionOfSelected() { return hotKeyTitle_unFixedPositionOfSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unFixedPositionOfAllNode() { return hotKeyTitle_unFixedPositionOfAllNode.data(); }
char* EnglishStringRes::getHotKeyTitle_FixedXCoordOfSelected() { return hotKeyTitle_FixedXCoordOfSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unFixedXCoordOfSelected() { return hotKeyTitle_unFixedXCoordOfSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unFixedXCoordOfAllNode() { return hotKeyTitle_unFixedXCoordOfAllNode.data(); }
char* EnglishStringRes::getHotKeyTitle_FixedYCoordOfSelected() { return hotKeyTitle_FixedYCoordOfSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unFixedYCoordOfOfSelected() { return hotKeyTitle_unFixedYCoordOfOfSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unFixedYCoordOfOfAllNode() { return hotKeyTitle_unFixedYCoordOfOfAllNode.data(); }
char* EnglishStringRes::getHotKeyTitle_autoGroupX() { return hotKeyTitle_autoGroupX.data(); }
char* EnglishStringRes::getHotKeyTitle_autoGroupY() { return hotKeyTitle_autoGroupY.data(); }
char* EnglishStringRes::getHotKeyTitle_autoGroupXY() { return hotKeyTitle_autoGroupXY.data(); }
char* EnglishStringRes::getHotKeyTitle_LayoutWeightOfSelectedIncr() { return hotKeyTitle_LayoutWeightOfSelectedIncr.data(); }
char* EnglishStringRes::getHotKeyTitle_LayoutWeightOfSelectedDecr() { return hotKeyTitle_LayoutWeightOfSelectedDecr.data(); }
char* EnglishStringRes::getHotKeyTitle_ResetLayoutWeightOfAllNode() { return hotKeyTitle_ResetLayoutWeightOfAllNode.data(); }
char* EnglishStringRes::getHotKeyTitle_GroupSelected() { return hotKeyTitle_GroupSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unGroupSelected() { return hotKeyTitle_unGroupSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unGroupAllNode() { return hotKeyTitle_unGroupAllNode.data(); }
char* EnglishStringRes::getHotKeyTitle_NodeSizeIncr() { return hotKeyTitle_NodeSizeIncr.data(); }
char* EnglishStringRes::getHotKeyTitle_NodeSizeDecr() { return hotKeyTitle_NodeSizeDecr.data(); }
char* EnglishStringRes::getHotKeyTitle_LineWidthIncr() { return hotKeyTitle_LineWidthIncr.data(); }
char* EnglishStringRes::getHotKeyTitle_LineWidthDecr() { return hotKeyTitle_LineWidthDecr.data(); }
char* EnglishStringRes::getHotKeyTitle_UnselectedNodeAlphaIncr() { return hotKeyTitle_UnselectedNodeAlphaIncr.data(); }
char* EnglishStringRes::getHotKeyTitle_UnselectedNodeAlphaDecr() { return hotKeyTitle_UnselectedNodeAlphaDecr.data(); }
char* EnglishStringRes::getHotKeyTitle_SelectedNodeAlphaIncr() { return hotKeyTitle_SelectedNodeAlphaIncr.data(); }
char* EnglishStringRes::getHotKeyTitle_SelectedNodeAlphaDecr() { return hotKeyTitle_SelectedNodeAlphaDecr.data(); }
char* EnglishStringRes::getHotKeyTitle_ColorNodeByFlow() { return hotKeyTitle_ColorNodeByFlow.data(); }
char* EnglishStringRes::getHotKeyTitle_ClearAllNodeColor() { return hotKeyTitle_ClearAllNodeColor.data(); }
char* EnglishStringRes::getHotKeyTitle_ShowAndHideTooltip() { return hotKeyTitle_ShowAndHideTooltip.data(); }
char* EnglishStringRes::getHotKeyTitle_ShowAndHideBoundFrame() { return hotKeyTitle_ShowAndHideBoundFrame.data(); }
char* EnglishStringRes::getHotKeyTitle_ChooseColorForSelectedNode() { return hotKeyTitle_ChooseColorForSelectedNode.data(); }
char* EnglishStringRes::getHotKeyTitle_NodeTextOnAndOff() { return hotKeyTitle_NodeTextOnAndOff.data(); }
char* EnglishStringRes::getHotKeyTitle_NodeTextSizeIncr() { return hotKeyTitle_NodeTextSizeIncr.data(); }
char* EnglishStringRes::getHotKeyTitle_NodeTextSizeDecr() { return hotKeyTitle_NodeTextSizeDecr.data(); }
char* EnglishStringRes::getHotKeyTitle_GUITextSizeIncr() { return hotKeyTitle_GUITextSizeIncr.data(); }
char* EnglishStringRes::getHotKeyTitle_GUITextSizeDecr() { return hotKeyTitle_GUITextSizeDecr.data(); }
char* EnglishStringRes::getHotKeyTitle_SaveSelectedNode() { return hotKeyTitle_SaveSelectedNode.data(); }

char* EnglishStringRes::getHotKeyTitle_searchUpward() {
    return hotKeyTitle_ExploreUpward.data();
}

char* EnglishStringRes::getHotKeyTitle_searchDownward() {
    return hotKeyTitle_ExploreDownward.data();
}

char* EnglishStringRes::getHint_press1ToShowHotkey() {
    return hint_press1ToShowHotkey.data();
}

char* EnglishStringRes::getHotKeyTitle_boundSelected() { return hotKeyTitle_boundSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unboundSelected() { return hotKeyTitle_unboundSelected.data(); }
char* EnglishStringRes::getHotKeyTitle_unboundUnselected() { return hotKeyTitle_unboundUnselected.data(); }
char* EnglishStringRes::getHotKeyTitle_boundByClass() { return hotKeyTitle_boundByClass.data(); }
char* EnglishStringRes::getHotKeyTitle_boundByMethod() { return hotKeyTitle_boundByMethod.data(); }
char* EnglishStringRes::getHotKeyTitle_treeUp() { return hotKeyTitle_treeUp.data(); }
char* EnglishStringRes::getHotKeyTitle_treeDown() { return hotKeyTitle_treeDown.data(); }
char* EnglishStringRes::getHotKeyTitle_cat_saveAndRestoreGraph() { return hotKeyTitle_cat_saveAndRestoreGraph.data(); }
char* EnglishStringRes::getHotKeyTitle_saveGraph() { return hotKeyTitle_saveGraph.data(); }
char* EnglishStringRes::getHotKeyTitle_restoreGraph() { return hotKeyTitle_restoreGraph.data(); }
char* EnglishStringRes::getHotKeyTitle_deleteSavedGraph() { return hotKeyTitle_deleteSavedGraph.data(); }

