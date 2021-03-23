//图的邻接表储存验证，为了简单起见，我们使用有向图
#include <stdio.h>
#include <stdlib.h>
#include"buildAdjacencyList.h"

//-------------------------------------------------------------------------------------------------------------
//在图中查找顶点在顶点数组中的索引
int LocateVex(ALGraph g,char v){
    int i;
    for(i=0;i<g.vexNum;i++){
        if(g.adjList[i].adjvex==v){
            return i;
        }
    }
    return -1;
}

//-------------------------------------------------------------------------------------------------------------
//建立邻接表
void creatAdjList(ALGraph *g){

    //建立节点数组
    printf("请输入节点数和边数\n");
    scanf("%d %d",&g->vexNum,&g->edgeNum);
    getchar();
    int i;//不知道哪个版本C语言不支持在for中声明变量了
    printf("请输入节点，不要空格\n");
    for(i=0;i<g->vexNum;i++){
        scanf("%c",&g->adjList[i].adjvex);
        g->adjList[i].secendNode=NULL;
        g->adjList[i].flag=0;
    }
    getchar();//此时\n也被吸收了

    //建立邻接表主要内容
    char v1,v2;

    printf("请输入对应的边\n");
    int k=0;
    for(k;k<g->edgeNum;k++){
        scanf("%c %c",&v1,&v2);
        getchar();
        int m=LocateVex(*g,v1);
        int n=LocateVex(*g,v2);
        ArcNode *temp;
        temp=(ArcNode*)malloc(sizeof(ArcNode));
        temp->adjvex=n;
        //首插法插入节点
        temp->nextarc=g->adjList[m].secendNode;
        g->adjList[m].secendNode=temp;
    }
    return ;
}
