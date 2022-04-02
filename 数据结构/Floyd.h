#pragma once
#include "GraphType.h"
void Floyd(MatGraph g) {
	int A[MAXV][MAXV], path[MAXV][MAXV];
	int i, j, k;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++) {
			A[i][j] = g.edges[i][j];
			if (i != j && g.edges[i][j] < INF)
				path[i][j] = i;										//���� i �� j �б�ʱ
			else
				path[i][j] = -1;									//���� i �� j û�б�ʱ
		}
	for (k = 0; k < g.n; k++) {							//���ο������ж���
		for (i = 0; i < g.n; i++)
			for (j = 0; j < g.n; j++)
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];				//�޸����·������
					path[i][j] = path[k][j];					//�޸����·��
				}
	}
	Dispath(g, A, path);										//������·��
}

void Dispath(MatGraph g, int A[][MAXV], int path[][MAXV]) {
	int i, j, k, s;
	int apath[MAXV], d;								//���һ�����·���м䶥�㣨���򣩼��䶥�����
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++) {
			if (A[i][j] != INF && i != j) {			//������ i �� j ֮�����·��
				printf("��%d��%d��·��Ϊ��", i, j);
				k = path[i][j];
				d = 0; apath[d] = j;					//·��������յ�
				while (k != -1 && k != i) {		//·��������м��
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i;					//·����������
				printf("%d", apath[d]);				//������
				for (s = d - 1; s >= 0; s--)		//���·���ϵ��м䶥��
					printf(",%d", apath[s]);
				printf("\t·������Ϊ��%d\n", A[i][j]);
			}
		}
}