#pragma once
#include "SearchType.h"

int BinSearch(RecType R[], int n, KeyType k) {		//�۰�����㷨
	int low = 0, high = n - 1, mid;
	while (low <= high) {					//��ǰ�������Ԫ��ʱѭ��
		mid = (low + high) / 2;
		if (k == R[mid].key)					//���ҳɹ��������߼���� mid+1
			return mid + 1;
		if (k < R[mid].key)					//������ R[low..mid-1] �в���
			high = mid - 1;
		else											// k>R[mid].key
			low = mid + 1;						//������ R[mid+1..high] �в���
	}
	return 0;										//δ�ҵ�ʱ����0������ʧ�ܣ�
}