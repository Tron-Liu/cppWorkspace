#pragma once
#include "Sqlist.h"
//��������Ԫ��,��λ��i�ϲ���e
bool ListInsert(Sqlist *&L, int i, ElemType e) {
	int j;
	if (i<1 || i>L->length + 1) {				//����i����ʱ����false
		return false;
	}
	i--;													//��˳����߼����ת��Ϊ�������
	for (j = L->length; j > i; j--) {			//��data[i]��֮���Ԫ��������һ��λ��
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;									//����Ԫ��e
	L->length++;
	return true;
}