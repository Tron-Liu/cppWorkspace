#pragma once
#include "RecType.h"
#include "swap.h"

void SelectSort(RecType R[], int n)
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{ //做第 i 趟排序
		k = i;
		for (j = i + 1; j < n; j++) //在当前无序区R[i..n-1]中选 key 最小的 R[k]
			if (R[j].key < R[k].key)
				k = j; // k记下目前找到的最小关键字所在的位置
		if (k != i)	   // R[i] 和 R[k] 两个元素交换
			Swap(R[i], R[k]);
	}
}