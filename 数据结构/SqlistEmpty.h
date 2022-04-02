#pragma once
#include "Sqlist.h"

//判断线性表是否是空表
bool ListEmpty(Sqlist *&L) {
	return (L->length == 0);
}