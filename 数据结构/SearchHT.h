#include "HashType.h"

//�ڹ�ϣ���в��ҹؼ��� k
void SearchHT(HashTable ha[], int m, int p, KeyType k) {
	int i = 1, adr;
	adr = k % p;															//�����ϣ����ֵ
	while (ha[adr].key != NULLKEY && ha[adr].key != k) {
		i++;																	//�ۼƹؼ��ֵıȽϴ���
		adr = (adr + 1) % m;										//����̽��
	}
	if (ha[adr].key == k)												//���ҳɹ�
		printf("�ɹ����ؼ���%d,�Ƚ�%d��\n", k, i);
	else																		//����ʧ��
		printf("ʧ�ܣ��ؼ���%d,�Ƚ�%d��\n", k, i);
}