#include "Search.h"
#include "Adj.h"
int main()
{
	int path[MAXV];
	int u = 1, v = 4, l = 3;
	int n = 5, e = 8;
	int A[MAXV][MAXV] = {{0, 1, 0, 1, 1}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 1, 0, 1}, {1, 0, 1, 1, 0}};
	AdjGraph *G;
	CreateAdj(G, A, n, e);
	for (int i = 0; i < n; i++) // visited 数组置初值
		visited[i] = 0;
	printf("图 G:\n");
	DispAdj(G); //输出邻接表
	printf("从%d到%d的所有长度为%d的路径: \n", u, v, l);
	PathlenAll(G, u, v, l, path, -1);
	printf("\n");
	DestroyAdj(G); //销毁邻接表
	system("pause");
	return 1;
}