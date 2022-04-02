#pragma once
#include "RecType.h"
#include "swap.h"

int partition(RecType R[], int s, int t) {			//һ�˻���
	int i = s, j = t;											// s ָ���������ĵ�һ��Ԫ�أ�t ָ�������������һ��Ԫ��
	RecType tmp = R[i];									//�� R[i] Ϊ��׼
	while (i < j) {											//�����˽������м�ɨ�裬ֱ�� i=j Ϊֹ
		while (j > i&&R[j].key >= tmp.key)
			j--;													//��������ɨ�裬��һ��С�� tmp.key �� R[j]
		R[i] = R[j];												//�ҵ������� R[j]�����뵽R[i]��
		while (j > i&&R[i].key <= tmp.key)
			i++;													//��������ɨ�裬��һ������ tmp.key �� R[i]
		R[j] = R[i];												//�ҵ������� R[i]�����뵽R[j]��
	}
	R[i] = tmp;
	return i;
}

void QuickSort(RecType R[], int s, int t) {		//�� R[s..t] ��Ԫ�ؽ��п�������
	int i;
	if (s < t) {								//���������ٴ�������Ԫ�ص������
												//�� R[s..t]��û��Ԫ�ػ���ֻ��һ��Ԫ�أ������κ�����
		i = partition(R, s, t);
		QuickSort(R, s, i - 1);		//��������ݹ�����
		QuickSort(R, i + 1, t);		//��������ݹ�����
	}
}

//�Ե�ǰ������м�λ�õ�Ԫ��Ϊ��׼
void QuickSort1(RecType R[], int s, int t) {		//�� R[s..t] ���м�λ��Ԫ��Ϊ��׼���п�������
	int i, pivot;
	pivot = (s + t) / 2;					//�������м�Ԫ����Ϊ��׼
	if (s < t) {									//���������ٴ�������Ԫ�ص����
		if (pivot != s)						//����׼���������еĵ�һ��Ԫ�أ��������һ��Ԫ�ػ���
			Swap(R[pivot], R[s]);	
		i = partition(R, s, t);				//����
		QuickSort1(R, s, i - 1);			//��������ݹ�����
		QuickSort1(R, i + 1, t);			//��������ݹ�����
	}
}
