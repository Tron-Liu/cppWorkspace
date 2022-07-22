#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MaxSize 50
typedef char ElemType;

// void swap(ElemType &x, ElemType &y) {
//	ElemType temp;
//	temp = x;
//	x = y;
//	y = temp;
// }

typedef struct
{
	ElemType data[MaxSize]; //存放线性表中的元素
	int length;				//存放线性表的长度
} Sqlist;					//顺序表类型