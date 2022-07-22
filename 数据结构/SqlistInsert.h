#pragma once
#include "Sqlist.h"
//插入数据元素,在位置i上插入e
bool ListInsert(Sqlist *&L, int i, ElemType e)
{
	int j;
	if (i < 1 || i > L->length + 1)
	{ //参数i错误时返回false
		return false;
	}
	i--; //将顺序表逻辑序号转换为物理序号
	for (j = L->length; j > i; j--)
	{ //将data[i]及之后的元素往后移一个位置
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e; //插入元素e
	L->length++;
	return true;
}