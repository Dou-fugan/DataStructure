#include "bfsAdjList.h"
int bfs(ALGraph *g,int v){

    int queue[g->edgeNum];

    int i=0;
    for(i=0;i<=g->edgeNum;i++){
        queue[i]=-1;
    }

    int front=0;
    int rear=0;

    queue[front]=v;

    ArcNode *p;
    p=g->adjList[v].secendNode;

    while(front<=rear){
        while(p!=NULL){
            //如果还没有进过队列，就进队列，进队列的顺序和被访问的顺序是一样的；
            if(g->adjList[p->adjvex].flag==0){
                rear++;
                queue[rear]=p->adjvex;
                g->adjList[p->adjvex].flag=1;
            }

            p=p->nextarc;
        }
        p=g->adjList[queue[front]].secendNode;
        printf("%c ",g->adjList[queue[front]].adjvex);
        queue[front]=-1;
        front++;
    }
    printf("\n");

    int k=0;
    for(k=0;k++;k<=g->edgeNum){
        g->adjList[k].flag=0;
    }

}
