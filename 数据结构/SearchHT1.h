#pragma once
#include "HashType1.h"

//�ڹ�ϣ���в��ҹؼ��� k
void SearchHT(HashTable ha[], int p, KeyType k) {
	int i = 0, adr;
	adr = k % p;						//�����ϣ����ֵ
	NodeType *q;
	q = ha[adr].firstp;				//q ָ���Ӧ��������׽��
	while (q != NULL) {			//ɨ�赥���� adr �����н��
		i++;								//��¼�Ƚϴ���
		if (q->key == k)			//���ҳɹ�
			break;						//�˳�ѭ��
		q = q->next;
	}
	if (q != NULL)					//���ҳɹ�
		printf("�ɹ����ؼ���%d,�Ƚ�%d��\n", k, i);
	else									//����ʧ��
		printf("ʧ�ܣ��ؼ���%d,�Ƚ�%d��\n", k, i);
}