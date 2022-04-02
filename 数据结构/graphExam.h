#pragma once
//�� 8.2 ���ھ��� n �������ͼ G
//��1�����һ�����ڽӾ���ת��Ϊ�ڽӱ���㷨
//��2�����һ�����ڽӱ�ת��Ϊ�ڽӾ�����㷨
#include "GraphType.h"

void MatToList(MatGraph g, AdjGraph *&G) {			//���ڽӾ��� g ת�����ڽӱ� G
	int i, j;
	ArcNode *p;
	G = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (i = 0; i < g.n; i++)												//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < g.n; i++)														//����ڽӾ����е�ÿ��Ԫ��
		for (j = g.n - 1; j >= 0; j--)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {			//����һ����
				p = (ArcNode *)malloc(sizeof(ArcNode));			//����һ���߽�� p
				p->adjvex = j;
				p->weight = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;						//����ͷ�巨������ p
				G->adjlist[i].firstarc = p;
			}
	G->n = g.n;
	G->e = g.e;
}

void ListToMat(AdjGraph *G, MatGraph &g) {		//���ڽӱ� G ת�����ڽӾ���
	int i;
	ArcNode *p;
	for (i = 0; i < G->n; i++) {									//ɨ�����ж��õ�����
		p = G->adjlist[i].firstarc;									//p ָ��� i ���������ͷ���
		while (p != NULL) {											//ɨ��� i ��������
			g.edges[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	}
	g.n = G->n;
	g.e = G->e;
}