#include <windows.h>
#include <stdio.h>
#include "main.h"

int main(){
    //声明一个图woc
    ALGraph woc;

    //建立邻接表
    creatAdjList(&woc);

    printf("%d\n",woc.vexNum);
    //打印邻接表
    ArcNode *show;
    int i=0;
    for(i;i<woc.vexNum;i++){
        printf("%c ",woc.adjList[i].adjvex);
        show=woc.adjList[i].secendNode;
        while(show!=NULL){
            printf("%c ",woc.adjList[show->adjvex].adjvex);
            show=show->nextarc;
        }
        printf("\n");
    }
    putchar('\n');

	printf("深度优先遍历的顺序是：\n");
	dfs(&woc,0);
	clean(&woc);

	putchar('\n');

	printf("广度优先遍历的顺序是：\n");
	bfs(&woc,0);
    return 0;
}
