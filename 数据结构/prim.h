#pragma once
//�ʺ��ó���ͼ����С����
//ϡ��ͼ���к������߻򻡣��ߵ����� |E| ԶС�� |v|��ƽ����
//����ͼ���ߵ����� |E| �ӽ� |v| ��ƽ��

//Prim�㷨�еĺ�ѡ����ָ���� U �� V-U ֮������б�
#include "GraphType.h"
void Prim(MatGraph g, int v) {
	int lowcost[MAXV];							//lowcost[] �洢��С�ߵ�Ȩ
	int MIN;
	int i, j, k;
	//���� V-U �е�һ������ j��������С�߶�Ӧ U �е�ĳ�����㣬��closet[j]���� U �е��������
	int closest[MAXV];
	for (i = 0; i < g.n; i++) {					//�� lowcost[] �� closest[]�ó�ֵ
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g.n; i++) {					//�ҳ� n-1 ������
		MIN = INF;
		for (j = 0; j < g.n; j++)					//�� ��V-U�����ҳ��� U ����Ķ��� k
			if (lowcost[j] != 0 && lowcost[j] < MIN) {
				MIN = lowcost[j];
				k = j;									//k ��¼�������ı��
			}
		printf(" �ߣ�%d,%d��ȨΪ��%d\n", closest[k], k, MIN);		//�����С��������һ����
		lowcost[k] = 0;								//��� k �Ѿ����� U
		for (j = 0; j < g.n; j++)					//�ԣ�V-U���еĶ��� j ���е���
			if (lowcost[j] != 0 && g.edges[k][j]<lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;						//�޸����� lowcost �� closest
			}
	}
}

//Prim()�㷨��������forѭ��������ʱ�临�Ӷ�ΪO(n^2),���� n Ϊͼ�Ķ��������
//Prim()�㷨��ִ��ʱ����ͼ�еı����޹أ������ʺϳ���ͼ����С������