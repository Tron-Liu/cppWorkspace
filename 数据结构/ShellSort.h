#pragma once
#include "RecType.h"
void ShellSort(RecType R[], int n)
{
	int i, j, d;
	RecType tmp;
	d = n / 2; //增量置初值
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{				//对所有组采用直接插入排序
			tmp = R[i]; //对相隔d个位置一组采用直接插入排序
			j = i - d;
			while (j >= 0 && tmp.key < R[j].key)
			{
				R[i + d] = R[j];
				j = j - d;
			}
			R[j + d] = tmp;
		}
		d = d / 2; //减小增量
	}
}
