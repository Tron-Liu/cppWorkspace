#pragma once
#include "GraphType.h"

//例8.9 假设图G采用邻接表存储，设计一个算法，
//求不带权无向连通图G中从顶点 u 到 v 的一条最短路径
typedef struct {
	int data;			//顶点编号
	int parent;		//前一个顶点的位置
}QUERE;				//非环形队列类型

void ShortPath(AdjGraph *G, int u, int v) {
	//输出从顶点 u 到顶点 v 的最短路径
	ArcNode *p;
	int w, i;
	QUERE qu[MAXV];					//非环形队列
	int front = -1, rear = -1;			//队列的头尾指针
	int visited[MAXV];
	for (i = 0; i < G->n; i++)			//访问标记置初值 0
		visited[i] = 0;
	rear++;									//顶点 u 进队
	qu[rear].data = u;
	qu[rear].parent = -1;
	visited[u] = 1;
	while (front != rear) {				//对不空循环
		front++;								//出队顶点 w
		w = qu[front].data;
		if (w == v) {										//找到 v 时输出路径之逆并退出
			i = front;										//通过队列输出逆路径
			while (qu[i].parent != -1) {
				printf("%2d", qu[i].data);
				i = qu[i].parent;
			}
			printf("%2d", qu[i].data);
			break;
		}
		p = G->adjlist[w].firstarc;			//找 w 的第一个邻接点
		while (p != NULL) {
			if (visited[p->adjvex] = 0) {		//将 w 未访问过的邻接点进队
				visited[p->adjvex] = 1;
				rear++;
				qu[rear].data = p->adjvex;
				qu[rear].parent = front;
			}
			p = p->nextarc;						//找 w 的下一个邻接点
		}
	}
}

//例8.10 假设图G采用邻接表存储，设计一个算法，求不带权无向连通图G中距离顶点 v 最远的一个顶点
int Maxdist(AdjGraph *G, int v) {
	ArcNode *p;
	int Qu[MAXV];							//环形队列数组
	int front = 0, rear = 0;				//队列的头尾指针
	int visited[MAXV];					//访问标记数组
	int i, j, k;
	for (i = 0; i < G->n; i++)			//初始化访问标记数组
		visited[0];
	rear++;									//顶点 v 进队
	Qu[rear] = v;
	visited[v] = 1;							//标记 v 已访问
	while (rear != front) { 
		front = (front + 1) % MAXV;
		k = Qu[front];									//顶点 k 出队
		p = G->adjlist[k].firstarc;					//找第一个邻接点
		while (p!=NULL) {							//所有未被访问过的邻接点进队
			j = p->adjvex;								//邻接点为顶点 j
			if (visited[j] == 0) {						//若 j 未被访问过
				visited[j] = 1;
				rear = (rear + 1) % MAXV;
				Qu[rear] = j;								//顶点 j 进队
			}
			p = p->nextarc;							//找下一个邻接点
		}
	}
	return k;
}