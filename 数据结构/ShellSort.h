#pragma once
#include "RecType.h"
void ShellSort(RecType R[], int n)
{
	int i, j, d;
	RecType tmp;
	d = n / 2;								//�����ó�ֵ
	while (d > 0) {
		for (i = d; i < n; i++) {		//�����������ֱ�Ӳ�������
			tmp = R[i];					//�����d��λ��һ�����ֱ�Ӳ�������
			j = i - d;
			while (j >= 0 && tmp.key < R[j].key) {
				R[i + d] = R[j];
				j = j - d;
			}
			R[j + d] = tmp;
		}
		d = d / 2;							//��С����
	}
}
