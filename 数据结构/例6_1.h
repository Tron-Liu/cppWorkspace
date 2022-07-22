#pragma once
#include <stdio.h>
#define MaxSize 30
void josephus(int n, int m)
{
	int p[MaxSize];
	int i, j, t;
	for (i = 0; i < n; i++) //构建初始序列（1，2，...，n）
		p[i] = i + 1;
	t = 0; //首次报数的起始位置
	printf("出列顺序：");
	for (i = n; i > 0; i--)
	{								// i为数组p中当前的人数，出列一次，人数减1
		t = (t + m - 1) % i;		// t为出列者的编号
		printf("%d", p[t]);			//编号为t的元素出列
		for (j = t + 1; j < i; j++) //后面的元素前移一个位置
			p[j - 1] = p[j];
	}
	printf("\n");
}
