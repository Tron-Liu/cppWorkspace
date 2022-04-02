#pragma once
#include "HashType.h"

/*
	�ڲ��ÿ��ŵ�ַ�������ͻ�Ĺ�ϣ����ִ��ɾ������ʱ���ܼ򵥵ؽ���ɾ��Ԫ�صؿռ���Ϊ�գ�
	���򽫽ض�����֮�������ϣ���ͬ���Ԫ�صĲ���·����������Ϊ�ڸ��ֿ��ŵ�ַ���У��յ�ַ��Ԫ
	���ǲ���ʧ�����������ֻ���ڱ�ɾ��Ԫ������ɾ����ǣ�������������ɾ��Ԫ�ء�
*/
bool DeleteHT(HashTable ha[], int &n, int m, int p, KeyType k) {		//ɾ����ϣ���еĹؼ��� k��
	int adr;
	adr = k % p;																		//�����ϣֵ
	while (ha[adr].key != NULLKEY && ha[adr].key != k)
		adr = (adr + 1) % m;													//����̽��
	if (ha[adr].key == k) {														//���ҳɹ�
		ha[adr].key = DELKEY;													//ɾ���ؼ���
		return true;
	}
	else																					//����ʧ��
		return false;																	//���ؼ�
}