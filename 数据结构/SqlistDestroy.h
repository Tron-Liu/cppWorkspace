#pragma once
#include "Sqlist.h"

//�������Ա�
void DestroyList(Sqlist *&L) {
	free(L);										//�ͷ� L ��ָ��˳���ռ�
}