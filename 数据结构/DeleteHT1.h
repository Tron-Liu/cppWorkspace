#pragma once
#include "HashType1.h"

//ɾ����ϣ���еĹؼ��� k
bool DeleteHT(HashTable ha[], int &n, int m, int p, KeyType k) {
	int adr;
	adr = k % p;									//�����ϣ����ֵ
	NodeType *q, *preq;
	q = ha[adr].firstp;							// q ָ���Ӧ��������׽��
	if (q == NULL)
		return false;								//��Ӧ������Ϊ��
	if (q->key == k) {							//�׽��Ϊ k
		ha[adr].firstp = q->next;			//ɾ����� q
		free(q);
		n--;											//����ܸ����� 1
		return true;								//������
	}
	preq = q;										//�׽�㲻Ϊ k ʱ
	q = q->next;
	while (q != NULL) {
		if (q->key == k)						//���ҳɹ�
			break;									//�˳�ѭ��
		q = q->next;
	}
	if (q != NULL) {								//���ҳɹ�
		preq->next = q->next;			//ɾ����� q
		free(q);
		n--;											//����ܸ�����һ
		return true;								//������
	}
	else
		return false;								//δ�ҵ� k ���ؼ�
}