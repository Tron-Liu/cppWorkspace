#pragma once
#include <iostream>

//图的邻接矩阵存储方法
#define MAXV 25	  //最大顶点个数
#define INF 32767 //定义为 无穷

typedef int InfoType;

typedef struct
{
	int no;		   //顶点的编号
	InfoType info; //顶点的其他信息
} VertexType;	   //顶点的类型

typedef struct
{
	int edges[MAXV][MAXV]; //邻接矩阵数组
	int n, e;			   //顶点数，边数
	VertexType vexs[MAXV]; //存放顶点信息
} MatGraph;				   //完整的图邻接矩阵类型

//图的邻接表存储方法
typedef struct ANode
{
	int adjvex;			   //该边的邻接点编号
	struct ANode *nextarc; //指向下一条边的指针
	int weight;			   //该边的相关信息，如权值（这里用整型表示）
} ArcNode;				   //边结点的类型

typedef struct Vnode
{
	InfoType info;	   //顶点的其他信息
	ArcNode *firstarc; //指向第一个边结点
} VNode;			   //邻接表的头结点类型

typedef struct
{
	VNode adjlist[MAXV]; //邻接表的头结点数组
	int n, e;			 //图中的顶点数 n 和边数 e
} AdjGraph;				 //完整的图邻接表类型