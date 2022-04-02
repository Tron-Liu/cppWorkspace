#pragma once
#include "RecType.h"

void BubbleSort(RecType R[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {			//�� R[i] Ԫ�ع�λ
			if (R[j].key < R[j - 1].key)		//���ڵ�����Ԫ�ط���ʱ
				Swap(R[j], R[j - 1]);			//�� R[j] �� R[j-1] ����Ԫ�ؽ��� 
		}
	}
}

//�Ľ�
//һ���㷨�е�ĳһ�˱Ƚ�ʱ�������κ�Ԫ�ؽ�����˵���Ѿ��ź����򣬾Ϳ��Խ������㷨
void BubbleSort1(RecType R[], int n)
{
	int i, j;
	bool exchange;
	for (i = 0; i < n - 1; i++) {
		exchange = false;
		for (j = n - 1; j > i; j--) {
			if (R[j].key < R[j - 1].key) {
				Swap(R[j], R[j - 1]);
				exchange = true;
			}
		}
		if (!exchange)
			return;
	}
}