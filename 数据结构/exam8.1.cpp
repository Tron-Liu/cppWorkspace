#include "Search.h"
#include "Adj.h"
int main() {
	int path[MAXV];
	int u = 1, v = 4, l = 3;
	int n = 5, e = 8;
	int A[MAXV][MAXV] = { {0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0} };
	AdjGraph *G;
	CreateAdj(G, A, n, e);
	for (int i = 0; i < n; i++)						//visited �����ó�ֵ
		visited[i] = 0;
	printf("ͼ G:\n"); DispAdj(G);				//����ڽӱ�
	printf("��%d��%d�����г���Ϊ%d��·����\n", u, v, l);
	PathlenAll(G, u, v, l, path, -1);
	printf("\n");
	DestroyAdj(G);										//�����ڽӱ�
	system("pause");
	return 1;
}