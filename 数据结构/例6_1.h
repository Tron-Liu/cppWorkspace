#pragma once
#include <stdio.h>
#define MaxSize 30
void josephus(int n, int m) {
	int p[MaxSize];
	int i, j, t;
	for (i = 0; i < n; i++)			//������ʼ���У�1��2��...��n��
		p[i] = i + 1;
	t = 0;									//�״α�������ʼλ��
	printf("����˳��");
	for (i = n; i > 0; i--) {			//iΪ����p�е�ǰ������������һ�Σ�������1
		t = (t+m-1) % i;				//tΪ�����ߵı��
		printf("%d", p[t]);				//���Ϊt��Ԫ�س���
		for (j = t+1; j < i; j++)		//�����Ԫ��ǰ��һ��λ��
			p[j-1] = p[j];
	}
	printf("\n");
}
