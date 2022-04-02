#pragma once
#include "SearchType.h"

/*
	param1��������
	param2�����Ա��ֳɵĿ���
	param3��������Ԫ�����ڵ����Ա�
	param4�����Ա��е�Ԫ�ظ���
	param5�������ҵ�Ԫ��
*/
int IdxSearch(IdxType I[], int b, RecType R[], int n, KeyType k) {		//�ֿ����
	int s = (n + b - 1) / b;							//s Ϊÿ���Ԫ�ظ�����ӦΪ n/b ����ȡ��
	int low = 0, high = b - 1, mid, i;
	while (low <= high) {							//���������н����۰���ң��ҵ���λ��Ϊ high+1
		mid = (low + high) / 2;
		if (I[mid].key >= k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	//Ӧ����������� high+1 ���в��ң����������ݱ��н���˳�����
	i = I[high + 1].link;
	while (i <= I[high + 1].link + s - 1 && R[i].key != k)
		i++;
	if (i <= I[high + 1].link + s - 1)				//���ҳɹ����ظ�Ԫ�ص��߼����
		return i + 1;
	else
		return 0;											//����ʧ�ܷ��� 0
}