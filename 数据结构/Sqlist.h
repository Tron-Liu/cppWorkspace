#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MaxSize 50
typedef char ElemType;

//void swap(ElemType &x, ElemType &y) {
//	ElemType temp;
//	temp = x;
//	x = y;
//	y = temp;
//}

typedef struct {
	ElemType data[MaxSize];			//������Ա��е�Ԫ��
	int length;								//������Ա�ĳ���
}Sqlist;											//˳�������