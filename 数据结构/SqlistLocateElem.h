#pragma once
#include "Sqlist.h"

//��Ԫ��ֵ����
int LocateElem(Sqlist *L, ElemType e) {
	int i = 0;
	while (i < L->length && L->data[i] != e) {		//����Ԫ�� e
		i++;
	}
	if (i >= L->length) return 0;								//δ�ҵ�ʱ���� 0
	else return i + 1;												//�ҵ��󷵻����߼����
}