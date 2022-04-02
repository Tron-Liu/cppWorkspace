#pragma once
#include "RecType.h"
#include "swap.h"

void SelectSort(RecType R[], int n) {
	int i, j, k;
	for (i = 0; i < n - 1; i++) {			//���� i ������
		k = i;
		for (j = i + 1; j < n; j++)		//�ڵ�ǰ������R[i..n-1]��ѡ key ��С�� R[k]
			if (R[j].key < R[k].key)
				k = j;							//k����Ŀǰ�ҵ�����С�ؼ������ڵ�λ��
		if (k != i)								//R[i] �� R[k] ����Ԫ�ؽ���
			Swap(R[i], R[k]);
	}
}