#pragma once
#include "Sqlist.h"

//初始化顺序表
void InitList(Sqlist *&L) {
	L = (Sqlist *)malloc(sizeof(Sqlist));		//分配存放线性表的空间
	L->length = 0;										//置空线性表的长度为0
}