#pragma once
#include "Sqlist.h"

//�����Ա��е�ĳ������Ԫ��ֵ
bool GetElem(Sqlist *L, int i, ElemType &e) {
	if (i<1 || i>L->length) {			//���� i ����ʹ����false
		return false;
	}
	e = L->data[i - 1];				//ȡԪ��ֵ
	return true;							//�ɹ��ҵ�Ԫ��ʱ����true
}