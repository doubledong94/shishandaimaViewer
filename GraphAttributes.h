#ifndef JPARSER_GRAPHATTRIBUTES_H
#define JPARSER_GRAPHATTRIBUTES_H

// todo delete this class
static string NODE_ATTR_LABEL = "label";
static string NODE_ATTR_NODE_COLOR = "nodecolor";
static string NODE_ATTR_NODE_SIZE = "nodesize";
static string NODE_ATTR_LABEL_COLOR = "labelcolor";
static string NODE_ATTR_LABEL_SIZE = "labelsize";
static string EDGE_ATTR_COLOR = "edgecolor";
static string EDGE_ATTR_WIDTH = "edgewidth";

enum {
    NODE_ATTR_INDEX_CHAR,
    NODE_ATTR_INDEX_NODE_TYPE,
    NODE_ATTR_INDEX_NODE_LABEL,
    NODE_ATTR_INDEX_NODE_KEY,
    NODE_ATTR_INDEX_NODE_RUNTIME_KEY,
    NODE_ATTR_INDEX_METHOD_KEY,
    NODE_ATTR_INDEX_CLASS_KEY,
    NODE_ATTR_INDEX_PACKAGE,
    LABEL_DETAIL_LEVEL_SIMPLE,
    LABEL_DETAIL_LEVEL_FULL
};

class NodeAttr : public PooledItem<NodeAttr> {
public:
    int nodeId = -1;
    string regexChar = "";
    int nodeType = 0;
    string nodeLabel = "";
    string nodeKey = "";
    string nodeRuntimeKey = "";
    string methodKey;
    string classKey;
    string packageKey;

    int labelDetailLevel = 0;
    string nodeColor;
    string labelColor;
    float nodeSize = 1;
    float labelSize = 1;

    string getLabel() {
        return nodeKey;
    }

    void reset() {
        nodeId = -1;
        regexChar.clear();
        nodeType = 0;
        nodeLabel.clear();
        nodeKey.clear();
        nodeRuntimeKey.clear();
        methodKey.clear();
        classKey.clear();
        packageKey.clear();
        labelDetailLevel = 0;
        nodeColor.clear();
        labelColor.clear();
        nodeSize = 1;
        labelSize = 1;
    }

    bool equal(NodeAttr* a) {
        return methodKey.compare(a->methodKey) == 0 and nodeRuntimeKey.compare(a->nodeRuntimeKey) == 0;
    }
};

#endif //JPARSER_GRAPHATTRIBUTES_H
