#pragma once
//例 8.2 对于具有 n 个顶点的图 G
//（1）设计一个将邻接矩阵转换为邻接表的算法
//（2）设计一个将邻接表转换为邻接矩阵的算法
#include "GraphType.h"

void MatToList(MatGraph g, AdjGraph *&G)
{ //将邻接矩阵 g 转换成邻接表 G
	int i, j;
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (i = 0; i < g.n; i++) //将邻接表中所有头结点的指针域置初值
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < g.n; i++) //检查邻接矩阵中的每个元素
		for (j = g.n - 1; j >= 0; j--)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{											//存在一条边
				p = (ArcNode *)malloc(sizeof(ArcNode)); //创建一个边结点 p
				p->adjvex = j;
				p->weight = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc; //采用头插法插入结点 p
				G->adjlist[i].firstarc = p;
			}
	G->n = g.n;
	G->e = g.e;
}

void ListToMat(AdjGraph *G, MatGraph &g)
{ //将邻接表 G 转换成邻接矩阵
	int i;
	ArcNode *p;
	for (i = 0; i < G->n; i++)
	{								//扫描所有懂得单链表
		p = G->adjlist[i].firstarc; // p 指向第 i 个单链表的头结点
		while (p != NULL)
		{ //扫描第 i 个单链表
			g.edges[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	}
	g.n = G->n;
	g.e = G->e;
}