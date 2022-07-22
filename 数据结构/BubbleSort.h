#pragma once
#include "RecType.h"

void BubbleSort(RecType R[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{								 //将 R[i] 元素归位
			if (R[j].key < R[j - 1].key) //相邻的两个元素反序时
				Swap(R[j], R[j - 1]);	 //将 R[j] 和 R[j-1] 两个元素交换
		}
	}
}

//改进
//一旦算法中的某一趟比较时不出现任何元素交换，说明已经排好了序，就可以结束本算法
void BubbleSort1(RecType R[], int n)
{
	int i, j;
	bool exchange;
	for (i = 0; i < n - 1; i++)
	{
		exchange = false;
		for (j = n - 1; j > i; j--)
		{
			if (R[j].key < R[j - 1].key)
			{
				Swap(R[j], R[j - 1]);
				exchange = true;
			}
		}
		if (!exchange)
			return;
	}
}