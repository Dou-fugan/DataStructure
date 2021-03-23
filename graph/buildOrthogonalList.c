//验证图的十字链表存储
#include <stdio.h>
#include <windows.h>
#define vexNum 10

typedef struct ArcNode
{
    //索引
    int tailVex;
    int headVex;

    //地址,按照tlink，可以一路遍历完正邻接表
    struct ArcNode *tlink;
    struct ArcNode *hlink;

    //info代表弧的权重
    int info;

} ArcNode;

typedef struct VexNode
{
    char data;
    ArcNode *last1End; //正邻接表的最后一个弧节点
    ArcNode *last2End; //逆邻接表的最后一个弧节点
    ArcNode *second1;  //正、第一个弧节点
    ArcNode *second2;  //逆、第一个弧节点
} VexNode;

typedef struct graph
{
    int vexN;
    int edgeN;
    VexNode adjList[vexNum];
} graph;

//寻找顶点在图中的位置
int locatVex(char vex, graph g)
{
    int i = 0;
    for (i; i < g.vexN; i++)
    {
        if (vex == g.adjList[i].data)
        {
            return i;
        }
    }
    return -1;
}
void creatOLGraph(graph *g)
{
    printf("请输入节点数和边数：\n");
    scanf("%d %d", &g->vexN, &g->edgeN);
    getchar();
    printf("请输入节点数组，不带空格\n");
    int i = 0;
    for (i; i < g->vexN; i++)
    {
        scanf("%c", &g->adjList[i].data);
        g->adjList[i].second1 = NULL;
        g->adjList[i].second2 = NULL;
        g->adjList[i].last1End = NULL;
        g->adjList[i].last2End = NULL;
    }
    getchar();
    printf("请输入边:\n");

    int v1, v2;
    char vv1, vv2;
    for (i = 0; i < g->edgeN; i++)
    {
        scanf("%c %c", &vv1, &vv2);
        getchar();
        v1 = locatVex(vv1, *g);
        v2 = locatVex(vv2, *g);
        ArcNode *p;
        p = (ArcNode *)malloc(sizeof(ArcNode));

        //同一个弧节点，先对正邻接表操作，再对逆邻接表操作

        //弧节点的弧尾是v1
        p->tailVex = v1;
        if (g->adjList[v1].last1End == NULL)
        {
            //顶点的第一个弧节点是p，该顶点正邻接表的最后一个弧节点也是p
            g->adjList[v1].second1 = p;
            g->adjList[v1].last1End = p;
        }
        else
        {
            //向正邻接表中添加一个元素，
            g->adjList[v1].last1End->tlink = p;
            g->adjList[v1].last1End = p;
        }

        p->headVex = v2;
        if (g->adjList[v2].last2End == NULL)
        {
            g->adjList[v2].second2 = p;
            g->adjList[v2].last2End = p;
        }
        else
        {
            g->adjList[v2].last1End->hlink = p;
            g->adjList[v2].last1End = p;
        }
    }
}

