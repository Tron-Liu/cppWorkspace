#pragma once
#include "Sqlist.h"

//删除数据元素
bool ListDelete(Sqlist*&L, int i, ElemType &e) {
	int j;
	if (i<1 || i>L->length) {						//参数 i 错误时返回false
		return false;
	}
	i--;													//将顺序表逻辑序号转化为物理序号
	e = L->data[i];									//返回删除数据元素的值
	for (j = i; j < L->length; j++) {			//将 data[i] 之后的元素前移一个位置
		L->data[j] = L->data[j + 1];
	}
	L->length--;										//顺序表长度减一
	return true;										//成功删除返回 true
}