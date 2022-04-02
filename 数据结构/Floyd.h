#pragma once
#include "GraphType.h"
void Floyd(MatGraph g) {
	int A[MAXV][MAXV], path[MAXV][MAXV];
	int i, j, k;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++) {
			A[i][j] = g.edges[i][j];
			if (i != j && g.edges[i][j] < INF)
				path[i][j] = i;										//顶点 i 到 j 有边时
			else
				path[i][j] = -1;									//顶点 i 到 j 没有边时
		}
	for (k = 0; k < g.n; k++) {							//依次考查所有顶点
		for (i = 0; i < g.n; i++)
			for (j = 0; j < g.n; j++)
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];				//修改最短路径长度
					path[i][j] = path[k][j];					//修改最短路径
				}
	}
	Dispath(g, A, path);										//输出最短路径
}

void Dispath(MatGraph g, int A[][MAXV], int path[][MAXV]) {
	int i, j, k, s;
	int apath[MAXV], d;								//存放一条最短路径中间顶点（反向）及其顶点个数
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++) {
			if (A[i][j] != INF && i != j) {			//若顶点 i 和 j 之间存在路径
				printf("从%d到%d的路径为：", i, j);
				k = path[i][j];
				d = 0; apath[d] = j;					//路径上添加终点
				while (k != -1 && k != i) {		//路径上添加中间点
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i;					//路径上添加起点
				printf("%d", apath[d]);				//输出起点
				for (s = d - 1; s >= 0; s--)		//输出路径上的中间顶点
					printf(",%d", apath[s]);
				printf("\t路径长度为：%d\n", A[i][j]);
			}
		}
}