#pragma once
#include "Sqlist.h"

//销毁线性表
void DestroyList(Sqlist *&L) {
	free(L);										//释放 L 所指的顺序表空间
}