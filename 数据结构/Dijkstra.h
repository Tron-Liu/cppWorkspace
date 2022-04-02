#pragma once
#include "GraphType.h"

void Dijkstra(MatGraph g, int v) {		//v��Դ��
	int dist[MAXV];								//dist[i]:��� v-> i �����·������
	int path[MAXV];								//path[j]:��� v -> j �����·���϶��� j ��ǰһ��������
	int S[MAXV];									//S[i]=1��ʾ���� i �� S �У�S[i] = 0��ʾ i �� U ��
	int MINdis, i, j, u;
	for (i = 0; i < g.n; i++) {
		dist[i] = g.edges[v][i];					//�����ʼ��
		S[i] = 0;										//S[]�ÿ�
		if (g.edges[v][i] < INF)					//·����ʼ��
			path[i] = v;								//���� v �� ���� i �б�ʱ���ö��� i ��ǰһ������Ϊ v
		else
			path[i] = -1;								//���� v �� ���� i �б�ʱ���ö��� i ��ǰһ������Ϊ -1
	}
	S[v] = 1; path[v] = 0;						//Դ���� v ���� S ��
	for (i = 0; i < g.n; i++) {					//ѭ��ֱ�����ж�������·�������
		MINdis = INF;								//MINdis����󳤶ȳ�ֵ
		for (j = 0; j < g.n; j++)					//ѡȡ���� S �У��� U �У��Ҿ�����С·�����ȵĶ��� u
			if (S[j] == 0 && dist[j] < MINdis) {
				u = j;
				MINdis = dist[j];
			}
		S[u] = 1;										//���� u ���� S ��
		for (j = 0; j < g.n; j++)					//�޸Ĳ��� S �У��� U �У��Ķ�������·��
			if(S[j]==0)
				if (g.edges[u][j] < INF&&dist[u] + g.edges[u][j] < dist[j]) {
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
	}
	Dispath(g, dist, path, S, v);				//������·��
}

//����Ӷ��� v �������������·��
void Dispath(MatGraph g, int dist[], int path[], int S[], int v) {
	int i, j, k;
	int apath[MAXV], d;									//���һ�����·�������򣩼��䶥�����
	for (i = 0; i < g.n; i++)								//ѭ������Ӷ��� v �� i ��·��
		if (S[i] == 1 && i != v) {
			printf(" �Ӷ���%d������%d��·������Ϊ��%d\t·��Ϊ��", v, i, dist[i]);
			d = 0;												//���·���ϵ��յ�
			apath[d] = i;
			k = path[i];
			if (k == -1)										//û��·�������
				printf("��·��\n");
			else {												//����·��ʱ�����·��
				while (k != v) {
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++; apath[d] = k;						//���·���ϵ����
				printf("%d", apath[d]);					//��������
				for (j = d - 1; j >= 0; j--)				//�������������
					printf(",%d", apath[j]);
				printf("\n");
			}
		}
}