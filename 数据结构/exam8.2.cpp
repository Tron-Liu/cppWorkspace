//例 8.8 假设图 G 采用邻接表存储，设计一个算法。求图中通过某顶点 k 的所有简单回路（若存在）
//并输出有向图的邻接表和通过顶点 0 的所有回路
#include "Adj.h"
int visited[MAXV];
void DFSPath(AdjGraph *G, int u, int v, int path[], int d)
{
	int w, i;
	ArcNode *p;
	d++;		 //路径长度 d 增 1
	path[d] = u; //顶点 u 加入到路径中
	visited[u] = 1;
	p = G->adjlist[u].firstarc; // p 指向顶点 u 的第一个邻接点
	while (p != NULL)
	{
		w = p->adjvex; // w 为顶点 u 的邻接点
		if (w == v && d > 0)
		{ //找到一个回路，则输出之
			printf(" ");
			for (i = 0; i <= d; i++)
				printf(" %d", path[i]);
			printf(" %d \n", v);
		}
		if (visited[w] == 0) //若 w 顶点未被访问，递归访问它
			DFSPath(G, w, v, path, d);
		p = p->nextarc; // p 指向顶点 u 的下一个邻接点
	}
	visited[u] = 0; //恢复环境，使该顶点可重新使用
}

void FindCyclePath(AdjGraph *G, int k)
{ //输出经过顶点 k 的所有回路
	int path[MAXV];
	DFSPath(G, k, k, path, -1);
}

int main()
{
	int n = 5, e = 7;
	int A[MAXV][MAXV] = {
		{0, 1, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {1, 0, 0, 0, 0}};
	AdjGraph *G;
	CreateAdj(G, A, n, e);
	for (int i = 0; i < n; i++)
		visited[0];
	printf("图 G ：\n");
	DispAdj(G);
	int k = 0;
	printf("图中经过顶点 %d 的所有回路：\n", k);
	FindCyclePath(G, k);
	printf("\n");
	DestroyAdj(G);
	system("pause");
	return 1;
}