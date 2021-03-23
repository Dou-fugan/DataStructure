#include "dfsAdjList.h"

//深度优先遍历
int dfs(ALGraph *g,int v){
	g->adjList[v].flag=1;
	printf("%c ",g->adjList[v].adjvex);
	ArcNode *p;
	p=g->adjList[v].secendNode;
	while(p!=NULL){
		if(g->adjList[p->adjvex].flag==0){
			dfs(g,p->adjvex);
		}
		p=p->nextarc;
	}
	return 0;
}

int clean(ALGraph* g){
    int k=0;
    for(k=0;k<g->edgeNum;k++){
        g->adjList[k].flag=0;
    }
}

