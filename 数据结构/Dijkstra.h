#pragma once
#include "GraphType.h"

void Dijkstra(MatGraph g, int v)
{					// v：源点
	int dist[MAXV]; // dist[i]:存放 v-> i 的最短路径长度
	int path[MAXV]; // path[j]:存放 v -> j 的最短路径上顶点 j 的前一个顶点编号
	int S[MAXV];	// S[i]=1表示顶点 i 在 S 中，S[i] = 0表示 i 在 U 中
	int MINdis, i, j, u;
	for (i = 0; i < g.n; i++)
	{
		dist[i] = g.edges[v][i]; //距离初始化
		S[i] = 0;				 // S[]置空
		if (g.edges[v][i] < INF) //路径初始化
			path[i] = v;		 //顶点 v 到 顶点 i 有边时，置顶点 i 的前一个顶点为 v
		else
			path[i] = -1; //顶点 v 到 顶点 i 有边时，置顶点 i 的前一个顶点为 -1
	}
	S[v] = 1;
	path[v] = 0; //源点编号 v 放入 S 中
	for (i = 0; i < g.n; i++)
	{							  //循环直到所有顶点的最短路径都求出
		MINdis = INF;			  // MINdis置最大长度初值
		for (j = 0; j < g.n; j++) //选取不在 S 中（即 U 中）且具有最小路径长度的顶点 u
			if (S[j] == 0 && dist[j] < MINdis)
			{
				u = j;
				MINdis = dist[j];
			}
		S[u] = 1;				  //顶点 u 加入 S 中
		for (j = 0; j < g.n; j++) //修改不在 S 中（即 U 中）的顶点的最短路径
			if (S[j] == 0)
				if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
				{
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
	}
	Dispath(g, dist, path, S, v); //输出最短路径
}

//输出从顶点 v 出发的所有最短路径
void Dispath(MatGraph g, int dist[], int path[], int S[], int v)
{
	int i, j, k;
	int apath[MAXV], d;		  //存放一条最短路径（逆向）及其顶点个数
	for (i = 0; i < g.n; i++) //循环输出从顶点 v 到 i 的路径
		if (S[i] == 1 && i != v)
		{
			printf(" 从顶点%d到顶点%d的路径长度为：%d\t路径为：", v, i, dist[i]);
			d = 0; //添加路径上的终点
			apath[d] = i;
			k = path[i];
			if (k == -1) //没有路径的情况
				printf("无路径\n");
			else
			{ //存在路径时输出该路径
				while (k != v)
				{
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++;
				apath[d] = k;				 //添加路径上的起点
				printf("%d", apath[d]);		 //先输出起点
				for (j = d - 1; j >= 0; j--) //再输出其他顶点
					printf(",%d", apath[j]);
				printf("\n");
			}
		}
}