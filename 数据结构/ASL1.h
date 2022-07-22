#pragma once
#include "HashType1.h"

//求平均查找长度
void ASL(HashTable ha[], int n, int m)
{
	int succ = 0, unsucc = 0, s;
	NodeType *q;
	for (int i = 0; i < m; i++)
	{ //扫描所有哈希表地址空间
		s = 0;
		q = ha[i].firstp; // q 指向单链表 i 的首结点
		while (q != NULL)
		{ //扫描单链表 i 的所有结点
			q = q->next;
			s++;	   // s 记录当前结点是对应单链表的第几个结点
			succ += s; //累计成功的总比较次数
		}
		unsucc += s; //累计不成功的总比较次数
	}
	printf(" 成功情况下ASL(%d)=%g\n", n, succ * 1.0 / n);
	printf(" 不成功情况下ASL(%d)=%g\n", n, unsucc * 1.0 / m);
}