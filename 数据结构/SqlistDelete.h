#pragma once
#include "Sqlist.h"

//ɾ������Ԫ��
bool ListDelete(Sqlist*&L, int i, ElemType &e) {
	int j;
	if (i<1 || i>L->length) {						//���� i ����ʱ����false
		return false;
	}
	i--;													//��˳����߼����ת��Ϊ�������
	e = L->data[i];									//����ɾ������Ԫ�ص�ֵ
	for (j = i; j < L->length; j++) {			//�� data[i] ֮���Ԫ��ǰ��һ��λ��
		L->data[j] = L->data[j + 1];
	}
	L->length--;										//˳����ȼ�һ
	return true;										//�ɹ�ɾ������ true
}