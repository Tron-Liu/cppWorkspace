#pragma once
#include "SearchType.h"
int SeqSearch(RecType R[], int n, KeyType k)
{
	int i = 0;
	while (i < n && R[i].key != k) //从表头往后找
		i++;
	if (i >= n) //未找到返回0
		return 0;
	else //找到返回逻辑序号 i+1
		return i + 1;
}

//在 R 的末尾增加一个关键字为 k的记录，称之为哨兵
//这样查找过程不再需要判断 i 是否超界，从而提高查找速度
int SeqSearch1(RecType R[], int n, KeyType k)
{
	int i = 0;
	R[n].key = k;
	while (R[i].key != k) //从表头往后找
		i++;
	if (i == n) //未找到返回0
		return 0;
	else //找到返回逻辑序号 i+1
		return i + 1;
}