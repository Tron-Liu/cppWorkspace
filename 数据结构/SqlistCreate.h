#pragma once
#include "Sqlist.h"

//整体建立顺序表
void CreateList(Sqlist *&L, ElemType a[], int n)
{										  //由a中的n个元素建立顺序表
	L = (Sqlist *)malloc(sizeof(Sqlist)); //分配存放线性表的空间
	for (int i = 0; i < n; i++)
	{					   // i扫描数组a中的元素
		L->data[i] = a[i]; //将元素a[i]存放到L中
	}
	L->length = n; //设置L的长度n
}