#pragma once
#include "HashType1.h"

void InsertHT(HashTable ha[], int  &n, int p, KeyType k) {		//���ؼ��� k ���뵽��ϣ����
	int adr;
	adr = k % p;															//�����ϣ����ֵ
	NodeType *q;
	q = (NodeType *)malloc(sizeof(NodeType));
	q->key = k;															//����һ����� q����Źؼ��� k
	q->next = NULL;
	if (ha[adr].firstp == NULL)									//�������� adr Ϊ��
		ha[adr].firstp = q;
	else {																	//�������� adr ����
		q->next = ha[adr].firstp;									//����ͷ�巨���뵽 ha[adr] �ĵ�������
		ha[adr].firstp = q;
	}
	n++;																		//��ϣ������ܸ�����1
}

//�ɹؼ������� keys[0..n1-1]������ϣ��
void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int n1) {
	int i;
	for (i = 0; i < m; i++)					//��ϣ���ó�ֵ
		ha[i].firstp = NULL;
	n = 0;
	for (i = 0; i < n1; i++)
		InsertHT(ha, n, p, keys[i]);		//���� n ���ؼ���
}