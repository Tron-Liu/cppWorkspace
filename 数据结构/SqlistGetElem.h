#pragma once
#include "Sqlist.h"

//求线性表中的某个数据元素值
bool GetElem(Sqlist *L, int i, ElemType &e) {
	if (i<1 || i>L->length) {			//参数 i 错误使返回false
		return false;
	}
	e = L->data[i - 1];				//取元素值
	return true;							//成功找到元素时返回true
}