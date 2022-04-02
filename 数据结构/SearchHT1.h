#pragma once
#include "HashType1.h"

//在哈希表中查找关键字 k
void SearchHT(HashTable ha[], int p, KeyType k) {
	int i = 0, adr;
	adr = k % p;						//计算哈希函数值
	NodeType *q;
	q = ha[adr].firstp;				//q 指向对应单链表的首结点
	while (q != NULL) {			//扫描单链表 adr 的所有结点
		i++;								//记录比较次数
		if (q->key == k)			//查找成功
			break;						//退出循环
		q = q->next;
	}
	if (q != NULL)					//查找成功
		printf("成功：关键字%d,比较%d次\n", k, i);
	else									//查找失败
		printf("失败：关键字%d,比较%d次\n", k, i);
}