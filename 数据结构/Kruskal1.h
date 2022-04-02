#pragma once
#include "DisSet.h"
#include "GraphType.h"
#include "Swap.h"
#define MaxSize 10

typedef struct {
	int u;				//�ߵ���ʼ����
	int v;					//�ߵ���ֹ����
	int w;				//�ߵ�Ȩֵ
}Edge;

//�Ľ��� Kruskal �㷨��
void Kruskal1(MatGraph g) {
	int i, j, k, u1, v1, sn1, sn2;
	UFSTree t[MaxSize];
	Edge E[MaxSize];
	k = 1;									//E ������±�� 1 ��ʼ��
	for (i = 0; i < g.n; i++)			//�� g �����ı߼� E
		for (i = 0; j <= i; j++)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
	HeapSort(E, g.e);						//���ö������ E ���鰴Ȩֵ��������
	MAKE_SET(t, g.n);						//��ʼ�����鼯��
	k = 1;										//k ��ʾ��ǰ�����������ĵڼ����ߣ���ֵΪ 1
	j = 1;										//E �бߵ��±�� 1 ��ʼ
	while (k < g.n) {						//���ɵı���С�� n ʱѭ��
		u1 = E[j].u;
		v1 = E[j].v;							//ȡһ���ߵ�ͷβ������ u1 �� v2
		sn1 = FIND_SET(t, u1);
		sn2 = FIND_SET(t, v1);			//�ֱ�õ��������������ļ��ϱ��
		if (sn1 != sn2) {					//���������ڲ�ͬ�ļ��ϣ��ñ�����С��������һ����
			printf("��%d,%d����%d\n", u1, v1, E[j].w);
			k++;									//���ɱ����� 1
			UNION(t, u1, v1);				//�� u1 �� v2 ��������ϲ�
		}
		j++;										//ɨ����һ����
	}
}

void sift(Edge E[], int low, int high) {
	int i = low, j = 2 * i;										//R[j] �� R[i] ������
	Edge tmp = E[i];
	while (j <= high) {
		if (j < high&&E[j].w < E[j + 1].w)		//���Һ��ӽϴ󣬰� j ָ���Һ���
			j++;
		if (tmp.w < E[j].w) {							//�������С������ӵĹؼ���
			E[i] = E[j];												//�� R[j] ������˫�׽��λ����
			i = j;														//�޸� i �� j ��ֵ���Ա��������ɸѡ
			j = 2 * i;
		}
		else break;								//�����ڵ���ڵ�������ӹؼ��֣�ɸѡ����
	}
	E[i] = tmp;											//��ɸѡ����������λ����
}

void HeapSort(Edge E[], int n) {
	int i;
	for (i = n / 2; i >= 1; i--)					//ѭ��������ʼ�ѣ����� sift �㷨 ceil(n/2) ��  ceil:��ȡ������
		sift(E, i, n);
	for (i = n; i >= 2; i--) {						//���� n-1����ɶ�����ÿ�˶���Ԫ�ظ�����1
		Swap(E[1], E[i]);							//�����һ��Ԫ�����R[1]����
		sift(E, 1, i - 1);								//��R[1..i-1]����ɸѡ���õ� i-1 �����Ķ�
	}
}