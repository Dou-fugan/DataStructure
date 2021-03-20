#pragma once
#define emm 10
//弧节点结构体
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;

//顶点节点结构体
typedef struct VexNode{
    char adjvex; //说明了顶点是谁
    ArcNode *secendNode;//最近一个插入的弧节点
    int flag;
}VexNode;

//图的结构体
typedef struct ALGraph{
    VexNode adjList[emm];
    int vexNum;
    int edgeNum;
}ALGraph;

