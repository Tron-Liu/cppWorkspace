#pragma once
//适合用稀疏图求最小树
//稀疏图：有很少条边或弧（边的条数 |E| 远小于 |v|的平方）
//稠密图：边的条数 |E| 接近 |v|的平方

#include "GraphType.h"
#define MaxSize 10
typedef struct {
	int u;				//边的起始顶点
	int v;					//边的终止顶点
	int w;				//边的权值
}Edge;

void Kruskal(MatGraph g) {
	int i, j, u1, v1, sn1, sn2, k;
	int vset[MAXV];						//vset[i]：辅助数组，用于记录一个顶点 i 所在的连通分量编号
	Edge E[MaxSize];						//存放图中的所有边
	k = 0;										//E 数组的下标从 0 开始计
	for (i = 0; i < g.n; i++)				//由 g 产生边集 E ，不重复选取同一条边
		for (j = 0; j <= i; j++)			//无向图，关于主对角线对称
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
	InsertSort(E, g.e);						//采用直接插入排序对 E 数组按权值递增排序
	for (i = 0; i < g.n; i++)				//初始化辅助数组
		vset[i] = i;
	k = 1;										//k 表示当前构造生成树的第几条边，初值为 1
	j = 0;										//E 中边的下标，初值为 0
	while (k < g.n) {						//生成的边数小于 n 时循环
		u1 = E[j].u;							//取一条边的两个顶点
		v1 = E[j].v;
		sn1 = vset[u1];
		sn2 = vset[v1];						//分别得到两个顶点所属的集合编号
		if (sn1 != sn2) {					//两顶点属于不同的集合，该边是最小生成树的一条边
			printf("（%d,%d）：%d\n", u1, v1, E[j].w);		//输出最小生成树的一条边
			k++;									//生成边数增 1
			for (i = 0; i < g.n; i++)		//两个集合统一编号
				if (vset[i] == sn2)			//集合编号为 sn2 的改为 sn1
					vset[i] = sn1;
		}
		j++;										//扫描下一条边
	}
}

void InsertSort(Edge E[], int n) {			//
	int i, j;
	Edge tmp;
	for (i = 1; i < n; i++) {
		if (E[i].w < E[i - 1].w) {
			tmp = E[i];
			j = i - 1;
			do {
				E[j + 1] = E[j];
				j--;
			} while (j >= 0 && E[j].w > tmp.w);
			E[j + 1] = tmp;
		}
	}
}

