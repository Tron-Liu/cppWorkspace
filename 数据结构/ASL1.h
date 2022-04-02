#pragma once
#include "HashType1.h"

//��ƽ�����ҳ���
void ASL(HashTable ha[], int n, int m) {
	int succ = 0, unsucc = 0, s;
	NodeType *q;
	for (int i = 0; i < m; i++) {					//ɨ�����й�ϣ���ַ�ռ�
		s = 0;
		q = ha[i].firstp;									//q ָ������ i ���׽��
		while (q!=NULL) {							//ɨ�赥���� i �����н��
			q = q->next;
			s++;												//s ��¼��ǰ����Ƕ�Ӧ������ĵڼ������
			succ += s;									//�ۼƳɹ����ܱȽϴ���
		}
		unsucc += s;									//�ۼƲ��ɹ����ܱȽϴ���
	}
	printf(" �ɹ������ASL(%d)=%g\n", n, succ*1.0 / n);
	printf(" ���ɹ������ASL(%d)=%g\n", n, unsucc*1.0 / m);
}