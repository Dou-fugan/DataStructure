
//-------------------------------------------------------------------------------------------------------------
//弧节点结构体
typedef struct ArcNode1{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

//顶点节点结构体
typedef struct VexNode1{
    char adjvex; //头节点内容
    ArcNode *secendNode;
    int flag;
}VexNode;

//图的结构体
typedef struct ALGraph1{
    VexNode adjList[emm];
    int vexNum;
    int edgeNum;
}ALGraph;
