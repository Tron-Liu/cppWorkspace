#pragma once
#include <iostream>
#include "RecType.h"

//�����������鲢Ϊһ�������
//��R[low..mid]Ϊ��һ�Σ�R[mid+1..high]Ϊ�ڶ��Σ�
void Merge(RecType R[], int low, int mid, int high) {
	RecType *R1;
	int i = low, j = mid + 1, k = 0;				// k ��R1���±꣬i��j�ֱ�Ϊ��1��2�ε��±�
	R1 = (RecType*)malloc((high - low + 1) * sizeof(RecType));		//��̬����ռ�
	while(i<=mid&&j<=high)					//�ڵ�һ�κ͵ڶ��ξ�δɨ����ʱѭ��
		if (R[i].key <= R[j].key)	 {					//����һ���е�Ԫ�ط���R1��
			R1[k] = R[i];
			i++; k++;
		}
		else {												//���ڶ����е�Ԫ�ط���R1��
			R1[k] = R[j];
			i++; k++;
		}
	while (i <= mid) {									//����һ�����µĲ��ָ��Ƶ�R1��
		R1[k] = R[i];
		i++; k++;
	}
	while (j <= high) {								//���ڶ������µĲ��ָ��Ƶ�R1��
		R1[k] = R[j];
		j++; k++;
	}
	for (k = 0, i = low; i < high; k++, i++)		//��R1���Ƶ�R[low..high]��
		R[i] = R1[k];
	free(R1);
}

void MergePass(RecType R[], int length, int n) {				//�������������н���һ�˹鲢
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)		//�鲢 length �����������ӱ�
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n - 1)												//���������ӱ����ߵĳ���С�� length
		Merge(R, i, i + length - 1, n - 1);								//�鲢�������ӱ�
}

void MergeSort(RecType R[], int n) {								//��·�鲢����
	int length;
	for (length = 1; length < n; length = 2 * length)			//���� floor(n/2) ������floor : ��ȡ������
		MergePass(R, length, n);
}

void MergeSortDC(RecType R[], int low, int high) {		//��R[low..high]���ж�·�鲢����
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		MergeSortDC(R, low, mid);
		MergeSortDC(R, mid + 1, high);
		Merge(R, low, mid, high);
	}
}

void MergeSort1(RecType R[], int n) {			//�Զ����µĶ�·�鲢�㷨
	MergeSortDC(R, 0, n - 1);
}