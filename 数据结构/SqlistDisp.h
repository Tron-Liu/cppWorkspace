#pragma once
#include "Sqlist.h"

//输出线性表长度
void DispList(Sqlist *L)
{
	for (int i = 0; i < L->length; i++)
	{ //扫描顺序表输出各元素值
		printf("%c ", L->data[i]);
	}
	printf("\n");
}