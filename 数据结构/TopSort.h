#pragma once
#include <stdio.h>
//图的邻接矩阵存储方法
#define MAXV 25	  //最大顶点个数
#define INF 32767 //定义为 无穷
typedef int InfoType;
typedef struct
{
	int no;		   //顶点的编号
	InfoType info; //顶点的其他信息
} VertexType;	   //顶点的类型

//图的邻接表存储方法
typedef struct ANode
{
	int adjvex;			   //该边的邻接点编号
	struct ANode *nextarc; //指向下一条边的指针
	int weight;			   //该边的相关信息，如权值（这里用整型表示）
} ArcNode;				   //边结点的类型

typedef struct
{
	VertexType data;   //顶点信息
	int count;		   //增加数据域：存放顶点入度
	ArcNode *firstarc; //指向第一个邻接点
} VNode;			   //头结点类型

typedef struct
{
	VNode adjlist[MAXV]; //邻接表的头结点数组
	int n, e;			 //图中的顶点数 n 和边数 e
} AdjGraph;				 //完整的图邻接表类型

/*
	拓扑排序方法如下：
	（1）从有向图中选择一个没有前驱（即入度为 0 ）的顶点并且输出它
	（2）从图中删去该顶点，并且删去从该顶点发出的全部有向边
	（3）重复上述两步，直到剩余的图中不再存在没有前驱的顶点为止
*/

void TopSort(AdjGraph *G)
{
	int i, j;
	int St[MAXV], top = -1; //栈 St 的指针为 top
	ArcNode *p;
	for (i = 0; i < G->n; i++) //入度置初值 0
		G->adjlist[i].count = 0;
	for (i = 0; i < G->n; i++)
	{ //求所有顶点的入度
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			G->adjlist[p->adjvex].count++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++) //将入度为 0 的顶点进栈
		if (G->adjlist[i].count == 0)
		{
			top++;
			St[top] = i;
		}
	while (top > -1)
	{				 //栈不空循环
		i = St[top]; //出栈一个顶点
		top--;
		printf("%d", i);			//输出该顶点
		p = G->adjlist[i].firstarc; //找第一个邻接点
		while (p != NULL)
		{ //将顶点 i 的出边邻接点的入度减 1
			j = p->adjvex;
			G->adjlist[j].count--;
			if (G->adjlist[j].count == 0)
			{ //将入度为 0 的邻接点进栈
				top++;
				St[top] = j;
			}
			p = p->nextarc; //找下一个邻接点
		}
	}
}