#pragma once
#include "DisSet.h"
#include "GraphType.h"
#include "Swap.h"
#define MaxSize 10

typedef struct
{
	int u; //边的起始顶点
	int v; //边的终止顶点
	int w; //边的权值
} Edge;

//改进的 Kruskal 算法：
void Kruskal1(MatGraph g)
{
	int i, j, k, u1, v1, sn1, sn2;
	UFSTree t[MaxSize];
	Edge E[MaxSize];
	k = 1;					  // E 数组的下标从 1 开始计
	for (i = 0; i < g.n; i++) //由 g 产生的边集 E
		for (i = 0; j <= i; j++)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
	HeapSort(E, g.e); //采用堆排序对 E 数组按权值递增排序
	MAKE_SET(t, g.n); //初始化并查集树
	k = 1;			  // k 表示当前构造生成树的第几条边，初值为 1
	j = 1;			  // E 中边的下标从 1 开始
	while (k < g.n)
	{ //生成的边数小于 n 时循环
		u1 = E[j].u;
		v1 = E[j].v; //取一条边的头尾顶点编号 u1 和 v2
		sn1 = FIND_SET(t, u1);
		sn2 = FIND_SET(t, v1); //分别得到两个顶点所属的集合编号
		if (sn1 != sn2)
		{ //两顶点属于不同的集合，该边是最小生成树的一条边
			printf("（%d,%d）：%d\n", u1, v1, E[j].w);
			k++;			  //生成边数增 1
			UNION(t, u1, v1); //将 u1 和 v2 两个顶点合并
		}
		j++; //扫描下一条边
	}
}

void sift(Edge E[], int low, int high)
{
	int i = low, j = 2 * i; // R[j] 是 R[i] 的左孩子
	Edge tmp = E[i];
	while (j <= high)
	{
		if (j < high && E[j].w < E[j + 1].w) //若右孩子较大，把 j 指向右孩子
			j++;
		if (tmp.w < E[j].w)
		{				 //若根结点小于最大孩子的关键字
			E[i] = E[j]; //将 R[j] 调整到双亲结点位置上
			i = j;		 //修改 i 和 j 的值，以便继续向下筛选
			j = 2 * i;
		}
		else
			break; //若根节点大于等于最大孩子关键字，筛选结束
	}
	E[i] = tmp; //被筛选结点放入最终位置上
}

void HeapSort(Edge E[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--) //循环建立初始堆，调用 sift 算法 ceil(n/2) 次  ceil:下取整函数
		sift(E, i, n);
	for (i = n; i >= 2; i--)
	{					   //进行 n-1趟完成堆排序，每趟堆中元素个数减1
		Swap(E[1], E[i]);  //将最后一个元素与根R[1]交换
		sift(E, 1, i - 1); //对R[1..i-1]进行筛选，得到 i-1 个结点的堆
	}
}