class StringRes {
public:
    static StringRes* singleton;
    virtual char* getAppName();
    virtual char* getString_close();
    virtual char* getHotkeyEditor();
    virtual char* getRadioText_SingleClick();
    virtual char* getRadioText_DoubleClick();
    virtual char* getRadioText_LongPress();
    virtual char* getSearchClass();
    virtual char* getSearchNodeInGraph();
    virtual char* getSearchExisting();
    virtual char* getHotKeyTitle_cate_prepare1() { return NULL; };
    virtual char* getHotKeyTitle_cate_prepare2() { return NULL; };
    virtual char* getHotKeyTitle_cate_add_and_delete_node() { return NULL; };
    virtual char* getHotKeyTitle_cate_select_node() { return NULL; };
    virtual char* getHotKeyTitle_cate_layout() { return NULL; };
    virtual char* getHotKeyTitle_cate_style() { return NULL; };
    virtual char* getHotKeyTitle_cate_next_round() { return NULL; };
    virtual char* getHotKeyTitle_cate_explore() { return NULL; };

    virtual char* getHotKeyTitle_parseSrc() { return NULL; };
    virtual char* getHotKeyTitle_editLineAndGraph() { return NULL; };
    virtual char* getHotKeyTitle_chooseClass() { return NULL; };
    virtual char* getHotKeyTitle_chooseLine() { return NULL; };
    virtual char* getHotKeyTitle_chooseGraph() { return NULL; };
    virtual char* getHotKeyTitle_startSearch() { return NULL; };
    virtual char* getHotKeyTitle_deleteNode() { return NULL; };
    virtual char* getHotKeyTitle_deleteAllNode() { return NULL; };
    virtual char* getHotKeyTitle_transitiveReduction() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeByPosition() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeByKeyType() { return NULL; };
    virtual char* getHotKeyTitle_selectAllNode() { return NULL; };
    virtual char* getHotKeyTitle_unselectAllNode() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeUpward() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeDownward() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeBackward() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeInBetween() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeByInDegree() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeByOutDegree() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeByDegree() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeByComponent() { return NULL; };
    virtual char* getHotKeyTitle_selectNodeByGroup() { return NULL; };
    virtual char* getHotKeyTitle_2DLayout() { return NULL; };
    virtual char* getHotKeyTitle_3DLayout() { return NULL; };
    virtual char* getHotKeyTitle_LayoutOnAndOff() { return NULL; };
    virtual char* getHotKeyTitle_LayoutTempIncr() { return NULL; };
    virtual char* getHotKeyTitle_LayoutTempDecr() { return NULL; };
    virtual char* getHotKeyTitle_FixedPositionOfSelected() { return NULL; };
    virtual char* getHotKeyTitle_unFixedPositionOfSelected() { return NULL; };
    virtual char* getHotKeyTitle_unFixedPositionOfAllNode() { return NULL; };
    virtual char* getHotKeyTitle_LayoutWeightOfSelectedIncr() { return NULL; };
    virtual char* getHotKeyTitle_LayoutWeightOfSelectedDecr() { return NULL; };
    virtual char* getHotKeyTitle_ResetLayoutWeightOfAllNode() { return NULL; };
    virtual char* getHotKeyTitle_GroupSelected() { return NULL; };
    virtual char* getHotKeyTitle_unGroupSelected() { return NULL; };
    virtual char* getHotKeyTitle_unGroupAllNode() { return NULL; };
    virtual char* getHotKeyTitle_NodeSizeIncr() { return NULL; };
    virtual char* getHotKeyTitle_NodeSizeDecr() { return NULL; };
    virtual char* getHotKeyTitle_LineWidthIncr() { return NULL; };
    virtual char* getHotKeyTitle_LineWidthDecr() { return NULL; };
    virtual char* getHotKeyTitle_UnselectedNodeAlphaIncr() { return NULL; };
    virtual char* getHotKeyTitle_UnselectedNodeAlphaDecr() { return NULL; };
    virtual char* getHotKeyTitle_SelectedNodeAlphaIncr() { return NULL; };
    virtual char* getHotKeyTitle_SelectedNodeAlphaDecr() { return NULL; };
    virtual char* getHotKeyTitle_ColorNodeByFlow() { return NULL; };
    virtual char* getHotKeyTitle_ClearAllNodeColor() { return NULL; };
    virtual char* getHotKeyTitle_ShowAndHideTooltip() { return NULL; };
    virtual char* getHotKeyTitle_ChooseColorForSelectedNode() { return NULL; };
    virtual char* getHotKeyTitle_NodeTextOnAndOff() { return NULL; };
    virtual char* getHotKeyTitle_NodeTextSizeIncr() { return NULL; };
    virtual char* getHotKeyTitle_NodeTextSizeDecr() { return NULL; };
    virtual char* getHotKeyTitle_GUITextSizeIncr() { return NULL; };
    virtual char* getHotKeyTitle_GUITextSizeDecr() { return NULL; };
    virtual char* getHotKeyTitle_SaveSelectedNode() { return NULL; };
    virtual char* getHotKeyTitle_searchUpward() { return NULL; };
    virtual char* getHotKeyTitle_searchDownward() { return NULL; };

    virtual char* getHint_press1ToShowHotkey() { return NULL; };

};

class ChineseStringRes :public StringRes {
private:
    string appName = "矢山代码阅读器";
    string string_close = "关闭";
    string hotkeyEditor = "快捷键查看/修改";
    string radioText_SingleClick = "单击";
    string radioText_DoubleClick = "双击";
    string radioText_LongPress = "长按";
    string searchClassText = "长按";
    string searchNodeText = "长按";
    string searchExistingText = "长按";

    string hotKeyTitle_cate_prepare1 = "准备1";
    string hotKeyTitle_cate_prepare2 = "准备2";
    string hotKeyTitle_cate_add_and_delete_node = "添加删除节点和边";
    string hotKeyTitle_cate_select_node = "选择节点";
    string hotKeyTitle_cate_layout = "布局";
    string hotKeyTitle_cate_style = "样式";
    string hotKeyTitle_cate_next_round = "保存到下一轮";
    string hotKeyTitle_cate_explore = "探索模式";

    string hotKeyTitle_parseSrc = "解析源码";
    string hotKeyTitle_editLineAndGraph = "修改line与graph";
    string hotKeyTitle_chooseClass = "选择class";
    string hotKeyTitle_chooseLine = "选择line";
    string hotKeyTitle_chooseGraph = "选择graph";
    string hotKeyTitle_startSearch = "开始搜索（添加节点）";
    string hotKeyTitle_deleteNode = "删除选中的节点";
    string hotKeyTitle_deleteAllNode = "删除所有未选中的节点";
    string hotKeyTitle_transitiveReduction = "Transitive Reduction";
    string hotKeyTitle_selectNodeByPosition = "按照在line中的位置选择节点";
    string hotKeyTitle_selectByKeyType = "按照节点类型选择";
    string hotKeyTitle_selectAllNode = "选择所有节点";
    string hotKeyTitle_unselectAllNode = "取消选择所有节点";
    string hotKeyTitle_selectNodeUpward = "向上选择";
    string hotKeyTitle_selectNodeDownward = "向下选择";
    string hotKeyTitle_selectNodeBackward = "反向选择";
    string hotKeyTitle_selectNodeInBetween = "选择连线";
    string hotKeyTitle_selectNodeByInDegree = "按入度选择";
    string hotKeyTitle_selectNodeByOutDegree = "按出度选择";
    string hotKeyTitle_selectNodeByDegree = "按度选择";
    string hotKeyTitle_selectNodeByComponent = "按联通子图选择";
    string hotKeyTitle_selectNodeByGroup = "按照聚合选择";
    string hotKeyTitle_2DLayout = "2d布局";
    string hotKeyTitle_3DLayout = "3d布局";
    string hotKeyTitle_LayoutOnAndOff = "布局动画开关";
    string hotKeyTitle_LayoutTempIncr = "布局温度+";
    string hotKeyTitle_LayoutTempDecr = "布局温度－";
    string hotKeyTitle_FixedPositionOfSelected = "固定选中的节点的位置";
    string hotKeyTitle_unFixedPositionOfSelected = "取消固定选中的节点的位置";
    string hotKeyTitle_unFixedPositionOfAllNode = "取消固定所有未选中的节点的位置";
    string hotKeyTitle_LayoutWeightOfSelectedIncr = "选中的子图的布局权重+";
    string hotKeyTitle_LayoutWeightOfSelectedDecr = "选中的子图的布局权重－";
    string hotKeyTitle_ResetLayoutWeightOfAllNode = "恢复所有未选中的节点的布局权重";
    string hotKeyTitle_GroupSelected = "聚合选中的节点";
    string hotKeyTitle_unGroupSelected = "取消聚合选中的节点";
    string hotKeyTitle_unGroupAllNode = "取消聚合所有未选中的节点";
    string hotKeyTitle_NodeSizeIncr = "节点变大";
    string hotKeyTitle_NodeSizeDecr = "节点变小";
    string hotKeyTitle_LineWidthIncr = "连线变粗";
    string hotKeyTitle_LineWidthDecr = "连线变细";
    string hotKeyTitle_UnselectedNodeAlphaIncr = "未选中的节点透明度+";
    string hotKeyTitle_UnselectedNodeAlphaDecr = "未选中的节点透明度－";
    string hotKeyTitle_SelectedNodeAlphaIncr = "选中的节点透明度+";
    string hotKeyTitle_SelectedNodeAlphaDecr = "选中的节点透明度－";
    string hotKeyTitle_ColorNodeByFlow = "给所有节点自动上色";
    string hotKeyTitle_ClearAllNodeColor = "清除所有未选中的节点颜色";
    string hotKeyTitle_ShowAndHideTooltip = "显示隐藏节点详细信息";
    string hotKeyTitle_ChooseColorForSelectedNode = "给选中的节点选择颜色";
    string hotKeyTitle_NodeTextSizeIncr = "节点文字变大";
    string hotKeyTitle_NodeTextSizeDecr = "节点文字变小";
    string hotKeyTitle_GUITextSizeIncr = "Gui文字变大";
    string hotKeyTitle_GUITextSizeDecr = "Gui文字变小";
    string hotKeyTitle_NodeTextOnAndOff = "显示隐藏节点文字";
    string hotKeyTitle_SaveSelectedNode = "保存选中的节点";
    string hotKeyTitle_ExploreDownward = "以选中的节点为始端进行搜索";
    string hotKeyTitle_ExploreUpward = "以选中的节点为末端进行搜索";

    string hint_press1ToShowHotkey = "[按1显示快捷键]";

public:
    char* getAppName() override;
    char* getString_close() override;
    char* getHotkeyEditor() override;
    char* getRadioText_SingleClick() override;
    char* getRadioText_DoubleClick() override;
    char* getRadioText_LongPress()  override;
    char* getSearchClass()  override;
    char* getSearchNodeInGraph()  override;
    char* getSearchExisting()  override;

    char* getHotKeyTitle_cate_prepare1() override;
    char* getHotKeyTitle_cate_prepare2() override;
    char* getHotKeyTitle_cate_add_and_delete_node() override;
    char* getHotKeyTitle_cate_select_node() override;
    char* getHotKeyTitle_cate_layout() override;
    char* getHotKeyTitle_cate_style() override;
    char* getHotKeyTitle_cate_next_round() override;
    char* getHotKeyTitle_cate_explore() override;

    char* getHotKeyTitle_parseSrc() override;
    char* getHotKeyTitle_editLineAndGraph() override;
    char* getHotKeyTitle_chooseClass() override;
    char* getHotKeyTitle_chooseLine() override;
    char* getHotKeyTitle_chooseGraph() override;
    char* getHotKeyTitle_startSearch() override;
    char* getHotKeyTitle_deleteNode() override;
    char* getHotKeyTitle_deleteAllNode() override;
    char* getHotKeyTitle_transitiveReduction() override;
    char* getHotKeyTitle_selectNodeByPosition() override;
    char* getHotKeyTitle_selectNodeByKeyType() override;
    char* getHotKeyTitle_selectAllNode() override;
    char* getHotKeyTitle_unselectAllNode() override;
    char* getHotKeyTitle_selectNodeUpward() override;
    char* getHotKeyTitle_selectNodeDownward() override;
    char* getHotKeyTitle_selectNodeBackward() override;
    char* getHotKeyTitle_selectNodeInBetween() override;
    char* getHotKeyTitle_selectNodeByInDegree() override;
    char* getHotKeyTitle_selectNodeByOutDegree() override;
    char* getHotKeyTitle_selectNodeByDegree() override;
    char* getHotKeyTitle_selectNodeByComponent() override;
    char* getHotKeyTitle_selectNodeByGroup() override;
    char* getHotKeyTitle_2DLayout() override;
    char* getHotKeyTitle_3DLayout() override;
    char* getHotKeyTitle_LayoutOnAndOff() override;
    char* getHotKeyTitle_LayoutTempIncr() override;
    char* getHotKeyTitle_LayoutTempDecr() override;
    char* getHotKeyTitle_FixedPositionOfSelected() override;
    char* getHotKeyTitle_unFixedPositionOfSelected() override;
    char* getHotKeyTitle_unFixedPositionOfAllNode() override;
    char* getHotKeyTitle_LayoutWeightOfSelectedIncr() override;
    char* getHotKeyTitle_LayoutWeightOfSelectedDecr() override;
    char* getHotKeyTitle_ResetLayoutWeightOfAllNode() override;
    char* getHotKeyTitle_GroupSelected() override;
    char* getHotKeyTitle_unGroupSelected() override;
    char* getHotKeyTitle_unGroupAllNode() override;
    char* getHotKeyTitle_NodeSizeIncr() override;
    char* getHotKeyTitle_NodeSizeDecr() override;
    char* getHotKeyTitle_LineWidthIncr() override;
    char* getHotKeyTitle_LineWidthDecr() override;
    char* getHotKeyTitle_UnselectedNodeAlphaIncr() override;
    char* getHotKeyTitle_UnselectedNodeAlphaDecr() override;
    char* getHotKeyTitle_SelectedNodeAlphaIncr() override;
    char* getHotKeyTitle_SelectedNodeAlphaDecr() override;
    char* getHotKeyTitle_ColorNodeByFlow() override;
    char* getHotKeyTitle_ClearAllNodeColor() override;
    char* getHotKeyTitle_ShowAndHideTooltip() override;
    char* getHotKeyTitle_ChooseColorForSelectedNode() override;
    char* getHotKeyTitle_NodeTextOnAndOff() override;
    char* getHotKeyTitle_NodeTextSizeIncr() override;
    char* getHotKeyTitle_NodeTextSizeDecr() override;
    char* getHotKeyTitle_GUITextSizeIncr() override;
    char* getHotKeyTitle_GUITextSizeDecr() override;
    char* getHotKeyTitle_SaveSelectedNode() override;
    char* getHotKeyTitle_searchUpward() override;
    char* getHotKeyTitle_searchDownward() override;

    char* getHint_press1ToShowHotkey() override;
};

class EnglishStringRes :public StringRes {
private:
    string appName = "ShishanCodeViewer";
    string string_close = "Close";
    string hotkeyEditor = "Hotkeys Viewer/Editor";
    string radioText_SingleClick = "Single Click";
    string radioText_DoubleClick = "Double Click";
    string radioText_LongPress = "Long Press";
    string searchClassText = "search class by regex, case ignored";
    string searchNodeText = "search node in graph, case ignored";
    string searchExistingText = "search text in below, case ignored";

    string hotKeyTitle_cate_prepare1 = "准备1";
    string hotKeyTitle_cate_prepare2 = "准备2";
    string hotKeyTitle_cate_add_and_delete_node = "添加删除节点和边";
    string hotKeyTitle_cate_select_node = "选择节点";
    string hotKeyTitle_cate_layout = "布局";
    string hotKeyTitle_cate_style = "样式";
    string hotKeyTitle_cate_next_round = "保存到下一轮";
    string hotKeyTitle_cate_explore = "探索模式";

    string hotKeyTitle_parseSrc = "解析源码";
    string hotKeyTitle_editLineAndGraph = "修改line与graph";
    string hotKeyTitle_chooseClass = "选择class";
    string hotKeyTitle_chooseLine = "选择line";
    string hotKeyTitle_chooseGraph = "选择graph";
    string hotKeyTitle_startSearch = "开始搜索（添加节点）";
    string hotKeyTitle_deleteNode = "删除选中的节点";
    string hotKeyTitle_deleteAllNode = "删除所有未选中的节点";
    string hotKeyTitle_transitiveReduction = "Transitive Reduction";
    string hotKeyTitle_selectNodeByPosition = "按照在line中的位置选择节点";
    string hotKeyTitle_selectByKeyType = "按照节点类型选择";
    string hotKeyTitle_selectAllNode = "选择所有节点";
    string hotKeyTitle_unselectAllNode = "取消选择所有节点";
    string hotKeyTitle_selectNodeUpward = "向上选择";
    string hotKeyTitle_selectNodeDownward = "向下选择";
    string hotKeyTitle_selectNodeBackward = "反向选择";
    string hotKeyTitle_selectNodeInBetween = "选择连线";
    string hotKeyTitle_selectNodeByInDegree = "按入度选择";
    string hotKeyTitle_selectNodeByOutDegree = "按出度选择";
    string hotKeyTitle_selectNodeByDegree = "按度选择";
    string hotKeyTitle_selectNodeByComponent = "按联通子图选择";
    string hotKeyTitle_selectNodeByGroup = "按照聚合选择";
    string hotKeyTitle_2DLayout = "2d布局";
    string hotKeyTitle_3DLayout = "3d布局";
    string hotKeyTitle_LayoutOnAndOff = "布局动画开关";
    string hotKeyTitle_LayoutTempIncr = "布局温度+";
    string hotKeyTitle_LayoutTempDecr = "布局温度－";
    string hotKeyTitle_FixedPositionOfSelected = "固定选中的节点的位置";
    string hotKeyTitle_unFixedPositionOfSelected = "取消固定选中的节点的位置";
    string hotKeyTitle_unFixedPositionOfAllNode = "取消固定所有未选中的节点的位置";
    string hotKeyTitle_LayoutWeightOfSelectedIncr = "选中的子图的布局权重+";
    string hotKeyTitle_LayoutWeightOfSelectedDecr = "选中的子图的布局权重－";
    string hotKeyTitle_ResetLayoutWeightOfAllNode = "恢复所有未选中的节点的布局权重";
    string hotKeyTitle_GroupSelected = "聚合选中的节点";
    string hotKeyTitle_unGroupSelected = "取消聚合选中的节点";
    string hotKeyTitle_unGroupAllNode = "取消聚合所有未选中的节点";
    string hotKeyTitle_NodeSizeIncr = "节点变大";
    string hotKeyTitle_NodeSizeDecr = "节点变小";
    string hotKeyTitle_LineWidthIncr = "连线变粗";
    string hotKeyTitle_LineWidthDecr = "连线变细";
    string hotKeyTitle_UnselectedNodeAlphaIncr = "未选中的节点透明度+";
    string hotKeyTitle_UnselectedNodeAlphaDecr = "未选中的节点透明度－";
    string hotKeyTitle_SelectedNodeAlphaIncr = "选中的节点透明度+";
    string hotKeyTitle_SelectedNodeAlphaDecr = "选中的节点透明度－";
    string hotKeyTitle_ColorNodeByFlow = "给所有节点自动上色";
    string hotKeyTitle_ClearAllNodeColor = "清除所有未选中的节点颜色";
    string hotKeyTitle_ShowAndHideTooltip = "显示隐藏节点详细信息";
    string hotKeyTitle_ChooseColorForSelectedNode = "给选中的节点选择颜色";
    string hotKeyTitle_NodeTextSizeIncr = "节点文字变大";
    string hotKeyTitle_NodeTextSizeDecr = "节点文字变小";
    string hotKeyTitle_GUITextSizeIncr = "Gui文字变大";
    string hotKeyTitle_GUITextSizeDecr = "Gui文字变小";
    string hotKeyTitle_NodeTextOnAndOff = "显示隐藏节点文字";
    string hotKeyTitle_SaveSelectedNode = "保存选中的节点";
    string hotKeyTitle_ExploreDownward = "以选中的节点为始端进行搜索";
    string hotKeyTitle_ExploreUpward = "以选中的节点为末端进行搜索";

    string hint_press1ToShowHotkey = "[按1显示快捷键]";

public:
    char* getAppName() override;
    char* getString_close() override;
    char* getHotkeyEditor() override;
    char* getRadioText_SingleClick() override;
    char* getRadioText_DoubleClick() override;
    char* getRadioText_LongPress() override;
    char* getSearchClass()  override;
    char* getSearchNodeInGraph()  override;
    char* getSearchExisting()  override;

    char* getHotKeyTitle_cate_prepare1() override;
    char* getHotKeyTitle_cate_prepare2() override;
    char* getHotKeyTitle_cate_add_and_delete_node() override;
    char* getHotKeyTitle_cate_select_node() override;
    char* getHotKeyTitle_cate_layout() override;
    char* getHotKeyTitle_cate_style() override;
    char* getHotKeyTitle_cate_next_round() override;
    char* getHotKeyTitle_cate_explore() override;

    char* getHotKeyTitle_parseSrc() override;
    char* getHotKeyTitle_editLineAndGraph() override;
    char* getHotKeyTitle_chooseClass() override;
    char* getHotKeyTitle_chooseLine() override;
    char* getHotKeyTitle_chooseGraph() override;
    char* getHotKeyTitle_startSearch() override;
    char* getHotKeyTitle_deleteNode() override;
    char* getHotKeyTitle_deleteAllNode() override;
    char* getHotKeyTitle_transitiveReduction() override;
    char* getHotKeyTitle_selectNodeByPosition() override;
    char* getHotKeyTitle_selectNodeByKeyType() override;
    char* getHotKeyTitle_selectAllNode() override;
    char* getHotKeyTitle_unselectAllNode() override;
    char* getHotKeyTitle_selectNodeUpward() override;
    char* getHotKeyTitle_selectNodeDownward() override;
    char* getHotKeyTitle_selectNodeBackward() override;
    char* getHotKeyTitle_selectNodeInBetween() override;
    char* getHotKeyTitle_selectNodeByInDegree() override;
    char* getHotKeyTitle_selectNodeByOutDegree() override;
    char* getHotKeyTitle_selectNodeByDegree() override;
    char* getHotKeyTitle_selectNodeByComponent() override;
    char* getHotKeyTitle_selectNodeByGroup() override;
    char* getHotKeyTitle_2DLayout() override;
    char* getHotKeyTitle_3DLayout() override;
    char* getHotKeyTitle_LayoutOnAndOff() override;
    char* getHotKeyTitle_LayoutTempIncr() override;
    char* getHotKeyTitle_LayoutTempDecr() override;
    char* getHotKeyTitle_FixedPositionOfSelected() override;
    char* getHotKeyTitle_unFixedPositionOfSelected() override;
    char* getHotKeyTitle_unFixedPositionOfAllNode() override;
    char* getHotKeyTitle_LayoutWeightOfSelectedIncr() override;
    char* getHotKeyTitle_LayoutWeightOfSelectedDecr() override;
    char* getHotKeyTitle_ResetLayoutWeightOfAllNode() override;
    char* getHotKeyTitle_GroupSelected() override;
    char* getHotKeyTitle_unGroupSelected() override;
    char* getHotKeyTitle_unGroupAllNode() override;
    char* getHotKeyTitle_NodeSizeIncr() override;
    char* getHotKeyTitle_NodeSizeDecr() override;
    char* getHotKeyTitle_LineWidthIncr() override;
    char* getHotKeyTitle_LineWidthDecr() override;
    char* getHotKeyTitle_UnselectedNodeAlphaIncr() override;
    char* getHotKeyTitle_UnselectedNodeAlphaDecr() override;
    char* getHotKeyTitle_SelectedNodeAlphaIncr() override;
    char* getHotKeyTitle_SelectedNodeAlphaDecr() override;
    char* getHotKeyTitle_ColorNodeByFlow() override;
    char* getHotKeyTitle_ClearAllNodeColor() override;
    char* getHotKeyTitle_ShowAndHideTooltip() override;
    char* getHotKeyTitle_ChooseColorForSelectedNode() override;
    char* getHotKeyTitle_NodeTextOnAndOff() override;
    char* getHotKeyTitle_NodeTextSizeIncr() override;
    char* getHotKeyTitle_NodeTextSizeDecr() override;
    char* getHotKeyTitle_GUITextSizeIncr() override;
    char* getHotKeyTitle_GUITextSizeDecr() override;
    char* getHotKeyTitle_SaveSelectedNode() override;
    char* getHotKeyTitle_searchUpward() override;
    char* getHotKeyTitle_searchDownward() override;

    char* getHint_press1ToShowHotkey() override;

};

