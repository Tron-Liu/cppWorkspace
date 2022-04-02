//�� 8.8 ����ͼ G �����ڽӱ�洢�����һ���㷨����ͼ��ͨ��ĳ���� k �����м򵥻�·�������ڣ�
//���������ͼ���ڽӱ��ͨ������ 0 �����л�·
#include "Adj.h"
int visited[MAXV];
void DFSPath(AdjGraph *G, int u, int v, int path[], int d) {
	int w, i;
	ArcNode *p;
	d++;											//·������ d �� 1
	path[d] = u;								//���� u ���뵽·����
	visited[u] = 1;
	p = G->adjlist[u].firstarc;			//p ָ�򶥵� u �ĵ�һ���ڽӵ�
	while (p != NULL) {
		w = p->adjvex;					//w Ϊ���� u ���ڽӵ�
		if (w == v && d > 0) {			//�ҵ�һ����·�������֮
			printf(" ");
			for (i = 0; i <= d; i++)
				printf(" %d", path[i]);
			printf(" %d \n", v);
		}
		if (visited[w] == 0)				//�� w ����δ�����ʣ��ݹ������
			DFSPath(G, w, v, path, d);
		p = p->nextarc;					//p ָ�򶥵� u ����һ���ڽӵ�
	}
	visited[u] = 0;							//�ָ�������ʹ�ö��������ʹ��
}

void FindCyclePath(AdjGraph*G, int k) {		//����������� k �����л�·
	int path[MAXV];
	DFSPath(G, k, k, path, -1);
}

int main()
{
	int n = 5, e = 7;
	int A[MAXV][MAXV] = {
		{0,1,1,0,0},{0,0,1,0,0},{0,0,0,1,1},{0,0,0,0,1},{1,0,0,0,0} };
	AdjGraph *G;
	CreateAdj(G, A, n, e);
	for (int i = 0; i < n; i++)
		visited[0];
	printf("ͼ G ��\n"); DispAdj(G);
	int k = 0;
	printf("ͼ�о������� %d �����л�·��\n", k);
	FindCyclePath(G, k);
	printf("\n");
	DestroyAdj(G);
	system("pause");
	return 1;
}