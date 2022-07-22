#pragma once
#include "RecType.h"
#include "swap.h"

void sift(RecType R[], int low, int high)
{
	int i = low, j = 2 * i; // R[j] 是 R[i] 的左孩子
	RecType tmp = R[i];
	while (j <= high)
	{
		if (j < high && R[j].key < R[j + 1].key) //若右孩子较大，把 j 指向右孩子
			j++;
		if (tmp.key < R[j].key)
		{				 //若根结点小于最大孩子的关键字
			R[i] = R[j]; //将 R[j] 调整到双亲结点位置上
			i = j;		 //修改 i 和 j 的值，以便继续向下筛选
			j = 2 * i;
		}
		else
			break; //若根节点大于等于最大孩子关键字，筛选结束
	}
	R[i] = tmp; //被筛选结点放入最终位置上
}

void HeapSort(RecType R[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--) //循环建立初始堆，调用 sift 算法 ceil(n/2) 次  ceil:下取整函数
		sift(R, i, n);
	for (i = n; i >= 2; i--)
	{					   //进行 n-1趟完成堆排序，每趟堆中元素个数减1
		Swap(R[1], R[i]);  //将最后一个元素与根R[1]交换
		sift(R, 1, i - 1); //对R[1..i-1]进行筛选，得到 i-1 个结点的堆
	}
}