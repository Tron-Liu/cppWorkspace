#pragma once
#include "Sqlist.h"

//������Ա���
void DispList(Sqlist *L) {
	for (int i = 0; i < L->length; i++) {		//ɨ��˳��������Ԫ��ֵ
		printf("%c ", L->data[i]);
	}
	printf("\n");
}