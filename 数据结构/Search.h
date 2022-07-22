#pragma once
#include "GraphType.h"

int visited[MAXV] = {0}; //全局数组
void DFS(AdjGraph *G, int v)
{ //以邻接表为存储结构的深度优先遍历算法
	ArcNode *p;
	visited[v] = 1;				//置已访问的标记
	printf("%d", v);			//输出被访问顶点的编号
	p = G->adjlist[v].firstarc; // p 指向顶点 v 的第一个邻接点
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0) //若 p->adjvex顶点未被访问，递归访问它
			DFS(G, p->adjvex);
		p = p->nextarc; // p 指向顶点 v 的下一个邻接点
	}
}

#include "circular_queue1.h"
void BFS(AdjGraph *G, int v)
{
	int w, i;
	ArcNode *p;
	SqQueue *qu;		//定义环形队列指针
	InitQueue(qu);		//初始化队列
	int visited1[MAXV]; //定义顶点访问标记数组
	for (i = 0; i < G->n; i++)
		visited1[i] = 0; //访问标记数组初始化
	printf("%2d", v);	 //输出被访问顶点的编号
	visited1[v] = 1;	 //置已访问标记
	enQueue(qu, v);
	while (!QueueEmpty(qu))
	{								//队不空循环
		deQueue(qu, w);				//出队一个顶点 w
		p = G->adjlist[w].firstarc; //指向 w 的第一个邻接点
		while (p != NULL)
		{ //查找 w 的所有邻接点
			if (visited1[p->adjvex] == 0)
			{							  //若当前邻接点未被访问
				printf("%2d", p->adjvex); //访问该邻接点
				visited1[p->adjvex] = 1;  //置已访问标记
				enQueue(qu, p->adjvex);	  //该顶点进队
			}
			p = p->nextarc; //找下一个邻接点
		}
	}
	printf("\n");
}

//采用深度优先遍历非连通图的算法
void DFS1(AdjGraph *G)
{
	int i;
	for (i = 0; i < G->n; i++)
		if (visited[i] == 0)
			DFS(G, i);
}

//采用广度优先遍历非连通图的算法
void BFS1(AdjGraph *G)
{
	int i;
	for (i = 0; i < G->n; i++)
		if (visited[i] == 0)
			BFS(G, i);
}

//例8.3 假设图 G 采用邻接表存储，设计一个算法，判断无向图 G 是否连通
bool Connect(AdjGraph *G)
{ //判断无向图的连通性
	int i;
	bool flag = true;
	for (i = 0; i < G->n; i++) // visited数组置初值
		visited[i] = 0;
	DFS(G, 0); //调用 DFS 算法，从顶点 0 开始深度优先遍历
	for (i = 0; i < G->n; i++)
		if (visited[i] == 0)
		{ //若有顶点没有被访问到，说明是不连通的
			flag = false;
			break;
		}
	return flag;
}

//例8.4 假设图 G 采用邻接表存储，设计一个算法判断图 G 中从顶点 u 到 v 是否存在简单路径。
//简单路径：路径上的顶点不重复

void ExistPath(AdjGraph *G, int u, int v, bool &has)
{
	// has 表示 u 到 v 是否有路径，初值为 false
	int w;
	ArcNode *p;
	visited[u] = 1; //置已访问标记
	if (u == v)
	{				//找到一条路径
		has = true; //置 has 为 true并返回
		return;
	}
	p = G->adjlist[u].firstarc; // p 指向顶点 u 的第一个邻接点
	while (p != NULL)
	{
		w = p->adjvex; // w 为顶点 u 的邻接点
		if (visited[w] == 0)
			ExistPath(G, w, v, has);
		p = p->nextarc; // p 指向顶点 u 的下一个邻接点
	}
}
//此算法中若没有简单路径，则程序运行至结束时 has 仍为 false

//例 8.5 假设图 G 采用邻接表存储，设计一个算法输出图 G中从顶点 u 到 v 的一条简单路径
//假设简单路径存在
void FindaPath(AdjGraph *G, int u, int v, int path[], int d)
{
	// d 表示 path 中的路径长度，初始为 -1
	int w, i;
	ArcNode *p;
	visited[u] = 1;
	d++;
	path[d] = u; //路径长度 d 增 1，顶点 u 加入到路径中
	if (u == v)
	{ //找到一条路径后输出并返回
		for (i = 0; i <= d; i++)
			printf("%d", path[i]);
		printf("\n");
		return;
	}
	p = G->adjlist[u].firstarc; // p 指向顶点 u 的第一个邻接点
	while (p != NULL)
	{
		w = p->adjvex; //邻接点的编号为 w
		if (visited[w] == 0)
			FindaPath(G, w, v, path, d);
		p = p->nextarc; // p 指向顶点 u 的下一个邻接点
	}
}

//例 8.6 假设图采用邻接表 G 存储，设计一个算法输出图 G 中从顶点 u 到 v 的所有简单路径
//假设图 G 中从顶点 u 到 v 至少存在一条简单路径
void FindAllPath(AdjGraph *G, int u, int v, int path[], int d)
{
	// d 表示 path 中的路径长度，初始为 -1
	int w, i;
	ArcNode *p;
	d++;		 //路径长度 d 增 1
	path[d] = u; //顶点 u 加入到路径中
	visited[u] = 1;
	if (u == v && d >= 0)
	{ //若找到一条路径则输出
		for (i = 0; i <= d; i++)
			printf("%2d", path[i]);
		printf("\n");
	}
	p = G->adjlist[u].firstarc; // p 指向顶点 u 的第一个邻接点
	while (p != NULL)
	{
		w = p->adjvex;		 // w 为顶点 u 的邻接点
		if (visited[w] == 0) //若 w 顶点未被访问，递归访问它
			FindAllPath(G, w, v, path, d);
		p = p->nextarc; // p 指向顶点 u 的下一个邻接点
	}
	visited[u] = 0; //恢复环境，使该顶点可重新使用
}

//例 8.7 假设图 G 采用邻接表存储，设计一个算法，输出图 G 中从顶点u 到 v 的长度为 l 的所有简单路径
void PathlenAll(AdjGraph *G, int u, int v, int l, int path[], int d)
{
	// d 表示 path 中的路径长度，初始为 -1
	int w, i;
	ArcNode *p;
	d++;		 //路径长度 d 增 1
	path[d] = u; //顶点 u 加入到路径中
	visited[u] = 1;
	if (u == v && d == l)
	{ //若找到一条路径则输出
		for (i = 0; i <= d; i++)
			printf(" %d", path[i]);
		printf("\n");
	}
	p = G->adjlist[u].firstarc; // p 指向顶点 u 的第一个邻接点
	while (p != NULL)
	{
		w = p->adjvex;		 // w 为顶点 u 的邻接点
		if (visited[w] == 0) //若 w 顶点未被访问，递归访问它
			PathlenAll(G, w, v, l, path, d);
		p = p->nextarc; // p 指向顶点 u 的下一个邻接点
	}
	visited[u] = 0; //恢复环境，使该顶点可重新使用
}