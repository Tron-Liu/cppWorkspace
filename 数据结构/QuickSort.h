#pragma once
#include "RecType.h"
#include "swap.h"

int partition(RecType R[], int s, int t)
{						//一趟划分
	int i = s, j = t;	// s 指向无序区的第一个元素，t 指向无序区的最后一个元素
	RecType tmp = R[i]; //以 R[i] 为基准
	while (i < j)
	{ //从两端交替向中间扫描，直至 i=j 为止
		while (j > i && R[j].key >= tmp.key)
			j--;	 //从右向左扫描，找一个小于 tmp.key 的 R[j]
		R[i] = R[j]; //找到这样的 R[j]，放入到R[i]处
		while (j > i && R[i].key <= tmp.key)
			i++;	 //从左向右扫描，找一个大于 tmp.key 的 R[i]
		R[j] = R[i]; //找到这样的 R[i]，放入到R[j]处
	}
	R[i] = tmp;
	return i;
}

void QuickSort(RecType R[], int s, int t)
{ //对 R[s..t] 的元素进行快速排序
	int i;
	if (s < t)
	{ //区间内至少存在两个元素的情况，
	  //若 R[s..t]中没有元素或者只有一个元素，则不做任何事情
		i = partition(R, s, t);
		QuickSort(R, s, i - 1); //对左区间递归排序
		QuickSort(R, i + 1, t); //对右区间递归排序
	}
}

//以当前区间的中间位置的元素为基准
void QuickSort1(RecType R[], int s, int t)
{ //对 R[s..t] 以中间位置元素为基准进行快速排序
	int i, pivot;
	pivot = (s + t) / 2; //用区间中间元素作为基准
	if (s < t)
	{					//区间内至少存在两个元素的情况
		if (pivot != s) //若基准不是区间中的第一个元素，将其与第一个元素互换
			Swap(R[pivot], R[s]);
		i = partition(R, s, t);	 //划分
		QuickSort1(R, s, i - 1); //对左区间递归排序
		QuickSort1(R, i + 1, t); //对右区间递归排序
	}
}
