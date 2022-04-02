#pragma once
//适合用稠密图求最小个数
//稀疏图：有很少条边或弧（边的条数 |E| 远小于 |v|的平方）
//稠密图：边的条数 |E| 接近 |v| 的平方

//Prim算法中的候选边是指集合 U 和 V-U 之间的所有边
#include "GraphType.h"
void Prim(MatGraph g, int v) {
	int lowcost[MAXV];							//lowcost[] 存储最小边的权
	int MIN;
	int i, j, k;
	//对于 V-U 中的一个顶点 j，它的最小边对应 U 中的某个顶点，用closet[j]保存 U 中的这个顶点
	int closest[MAXV];
	for (i = 0; i < g.n; i++) {					//给 lowcost[] 和 closest[]置初值
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g.n; i++) {					//找出 n-1 个顶点
		MIN = INF;
		for (j = 0; j < g.n; j++)					//在 （V-U）中找出离 U 最近的顶点 k
			if (lowcost[j] != 0 && lowcost[j] < MIN) {
				MIN = lowcost[j];
				k = j;									//k 记录最近顶点的编号
			}
		printf(" 边（%d,%d）权为：%d\n", closest[k], k, MIN);		//输出最小生成树的一条边
		lowcost[k] = 0;								//标记 k 已经加入 U
		for (j = 0; j < g.n; j++)					//对（V-U）中的顶点 j 进行调整
			if (lowcost[j] != 0 && g.edges[k][j]<lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;						//修该数组 lowcost 和 closest
			}
	}
}

//Prim()算法中有两重for循环，所以时间复杂度为O(n^2),其中 n 为图的顶点个数。
//Prim()算法的执行时间与图中的边数无关，所以适合稠密图求最小生成树