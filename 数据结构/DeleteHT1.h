#pragma once
#include "HashType1.h"

//删除哈希表中的关键字 k
bool DeleteHT(HashTable ha[], int &n, int m, int p, KeyType k) {
	int adr;
	adr = k % p;									//计算哈希函数值
	NodeType *q, *preq;
	q = ha[adr].firstp;							// q 指向对应单链表的首结点
	if (q == NULL)
		return false;								//对应单链表为空
	if (q->key == k) {							//首结点为 k
		ha[adr].firstp = q->next;			//删除结点 q
		free(q);
		n--;											//结点总个数减 1
		return true;								//返回真
	}
	preq = q;										//首结点不为 k 时
	q = q->next;
	while (q != NULL) {
		if (q->key == k)						//查找成功
			break;									//退出循环
		q = q->next;
	}
	if (q != NULL) {								//查找成功
		preq->next = q->next;			//删除结点 q
		free(q);
		n--;											//结点总个数减一
		return true;								//返回真
	}
	else
		return false;								//未找到 k 返回假
}