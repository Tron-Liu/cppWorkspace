#pragma once
#include "Sqlist.h"

//��ʼ��˳���
void InitList(Sqlist *&L) {
	L = (Sqlist *)malloc(sizeof(Sqlist));		//���������Ա�Ŀռ�
	L->length = 0;										//�ÿ����Ա�ĳ���Ϊ0
}