#pragma once
#include "RecType.h"
#include "swap.h"

void sift(RecType R[], int low, int high) {
	int i = low, j = 2 * i;										//R[j] �� R[i] ������
	RecType tmp = R[i];
	while (j <= high) {
		if (j < high&&R[j].key < R[j + 1].key)		//���Һ��ӽϴ󣬰� j ָ���Һ���
			j++;
		if (tmp.key < R[j].key) {							//�������С������ӵĹؼ���
			R[i] = R[j];												//�� R[j] ������˫�׽��λ����
			i = j;														//�޸� i �� j ��ֵ���Ա��������ɸѡ
			j = 2 * i;
		}
		else break;								//�����ڵ���ڵ�������ӹؼ��֣�ɸѡ����
	}
	R[i] = tmp;											//��ɸѡ����������λ����
}

void HeapSort(RecType R[], int n) {
	int i;
	for (i = n / 2; i >= 1; i--)					//ѭ��������ʼ�ѣ����� sift �㷨 ceil(n/2) ��  ceil:��ȡ������
		sift(R, i, n);
	for (i = n; i >= 2; i--) {						//���� n-1����ɶ�����ÿ�˶���Ԫ�ظ�����1
		Swap(R[1], R[i]);							//�����һ��Ԫ�����R[1]����
		sift(R, 1, i - 1);								//��R[1..i-1]����ɸѡ���õ� i-1 �����Ķ�
	}
}