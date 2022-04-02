#pragma once
#include "Sqlist.h"

//按元素值查找
int LocateElem(Sqlist *L, ElemType e) {
	int i = 0;
	while (i < L->length && L->data[i] != e) {		//查找元素 e
		i++;
	}
	if (i >= L->length) return 0;								//未找到时返回 0
	else return i + 1;												//找到后返回其逻辑序号
}