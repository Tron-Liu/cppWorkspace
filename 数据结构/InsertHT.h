#pragma once
#include "HashType.h"

/*
	param1:��ϣ��
	param2:��ϣ���Ѵ����Ԫ��
	param3:��ϣ���ַ�ռ��С
	param4:�����������еĳ���
	patam5:������ؼ���
*/
void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k) {		//���ؼ��� k ���뵽��ϣ����
	int i, adr;
	adr = k % p;														//�����ϣ����ֵ
	if (ha[adr].key == NULLKEY || ha[adr].key == DELKEY) {
		ha[adr].key = k;											//k ����ֱ�ӷ��ڹ�ϣ����
		ha[adr].count = 1;
	}
	else {																//������ͻʱ��������̽�ⷨ�����ͻ
		i = 1;															// i ��¼ k ������ͻ�Ĵ���
		do {
			adr = (adr + 1) % m;								//����̽��
			i++;
		} while (ha[adr].key != NULLKEY && ha[adr].key != DELKEY);
		ha[adr].key = k;											//�� adr ������ k
		ha[adr].count = i;											//����̽�����
	}
	n++;																	//��ϣ������Ԫ�ظ�����һ
}

//�ɹؼ������� keys[0..n1-1]������ϣ��
void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int n1) {
	int i;
	for (i = 0; i < m; i++) {						//��ϣ���ÿյĳ�ֵ
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}
	n = 0;												//��ϣ������Ԫ�ظ����� 0 ��ʼ����
	for (i = 0; i < n1; i++)
		InsertHT(ha, n, m, p, keys[i]);		//���� n ���ؼ���
}