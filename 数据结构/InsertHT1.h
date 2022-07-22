#pragma once
#include "HashType1.h"

void InsertHT(HashTable ha[], int &n, int p, KeyType k)
{ //将关键字 k 插入到哈希表中
	int adr;
	adr = k % p; //计算哈希函数值
	NodeType *q;
	q = (NodeType *)malloc(sizeof(NodeType));
	q->key = k; //创建一个结点 q，存放关键字 k
	q->next = NULL;
	if (ha[adr].firstp == NULL) //若单链表 adr 为空
		ha[adr].firstp = q;
	else
	{							  //若单链表 adr 不空
		q->next = ha[adr].firstp; //采用头插法插入到 ha[adr] 的单链表中
		ha[adr].firstp = q;
	}
	n++; //哈希表结点的总个数加1
}

//由关键字序列 keys[0..n1-1]创建哈希表
void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int n1)
{
	int i;
	for (i = 0; i < m; i++) //哈希表置初值
		ha[i].firstp = NULL;
	n = 0;
	for (i = 0; i < n1; i++)
		InsertHT(ha, n, p, keys[i]); //插入 n 个关键字
}