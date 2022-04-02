#pragma once
//�ʺ���ϡ��ͼ����С��
//ϡ��ͼ���к������߻򻡣��ߵ����� |E| ԶС�� |v|��ƽ����
//����ͼ���ߵ����� |E| �ӽ� |v|��ƽ��

#include "GraphType.h"
#define MaxSize 10
typedef struct {
	int u;				//�ߵ���ʼ����
	int v;					//�ߵ���ֹ����
	int w;				//�ߵ�Ȩֵ
}Edge;

void Kruskal(MatGraph g) {
	int i, j, u1, v1, sn1, sn2, k;
	int vset[MAXV];						//vset[i]���������飬���ڼ�¼һ������ i ���ڵ���ͨ�������
	Edge E[MaxSize];						//���ͼ�е����б�
	k = 0;										//E ������±�� 0 ��ʼ��
	for (i = 0; i < g.n; i++)				//�� g �����߼� E �����ظ�ѡȡͬһ����
		for (j = 0; j <= i; j++)			//����ͼ���������Խ��߶Գ�
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
	InsertSort(E, g.e);						//����ֱ�Ӳ�������� E ���鰴Ȩֵ��������
	for (i = 0; i < g.n; i++)				//��ʼ����������
		vset[i] = i;
	k = 1;										//k ��ʾ��ǰ�����������ĵڼ����ߣ���ֵΪ 1
	j = 0;										//E �бߵ��±꣬��ֵΪ 0
	while (k < g.n) {						//���ɵı���С�� n ʱѭ��
		u1 = E[j].u;							//ȡһ���ߵ���������
		v1 = E[j].v;
		sn1 = vset[u1];
		sn2 = vset[v1];						//�ֱ�õ��������������ļ��ϱ��
		if (sn1 != sn2) {					//���������ڲ�ͬ�ļ��ϣ��ñ�����С��������һ����
			printf("��%d,%d����%d\n", u1, v1, E[j].w);		//�����С��������һ����
			k++;									//���ɱ����� 1
			for (i = 0; i < g.n; i++)		//��������ͳһ���
				if (vset[i] == sn2)			//���ϱ��Ϊ sn2 �ĸ�Ϊ sn1
					vset[i] = sn1;
		}
		j++;										//ɨ����һ����
	}
}

void InsertSort(Edge E[], int n) {			//
	int i, j;
	Edge tmp;
	for (i = 1; i < n; i++) {
		if (E[i].w < E[i - 1].w) {
			tmp = E[i];
			j = i - 1;
			do {
				E[j + 1] = E[j];
				j--;
			} while (j >= 0 && E[j].w > tmp.w);
			E[j + 1] = tmp;
		}
	}
}

