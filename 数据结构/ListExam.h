#pragma once
#include "LinkNode.h"

//例 2.6  p52
void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2) // L1尾插法 L2头插法
{
	LinkNode *p = L->next, *r, *q;			   // p指向第一个数据结点
	L1 = L;									   // L1利用原来 L的头结点
	r = L;									   // r始终指向 L1的尾结点
	L2 = (LinkNode *)malloc(sizeof(LinkNode)); //创建 L2的头结点
	L2->next = NULL;						   //置 L2的指针域为 NULL
	while (p != NULL)
	{
		r->next = p; //采用尾插法将p（data值为 a[i]）插入L1中
		r = p;
		p = p->next;		// p移到下一个结点（data值为 b[i]）
		q = p->next;		//头插法会改变 p的指针域，用 q来存储结点 p的后继结点
		p->next = L2->next; //采用头插法将 p插入到 L2中
		L2->next = p;
		p = q; // p重新指向 a[i+1]
	}
	r->next = NULL; // L1尾结点next置空
}

//例 2.7 删除单链表 L 中元素值最大的结点
void delMaxNode(LinkNode *&L)
{
	LinkNode *p = L->next, *pre = L, *maxp = p, *maxpre = pre;
	while (p != NULL)
	{ //用 p扫描整个单链表  pre始终指向其前驱结点
		if (maxp->data < p->data)
		{				  // 若找到一个更大的结点
			maxp = p;	  //更新 maxp
			maxpre = pre; //更新 maxpre
		}
		pre = p; // pre同时后移一个结点
		p = p->next;
	}
	maxpre->next = maxp->next; //删除 maxp结点
	free(maxp);				   //释放 maxp结点空间
}

//例 2.8 设计一个算法使有一个带头结点的单链表 L 递增有序排列
void sort(LinkNode *&L)
{
	LinkNode *p, *pre, *q;
	p = L->next->next;	  // p指向 L的第二个数据结点
	L->next->next = NULL; //构造只含一个数据结点的有序单链表
	while (p != NULL)
	{
		q = p->next; // q保存 p的下一个结点
		pre = L;	 //从有序单链表开头进行比较，pre指向插入结点的前驱结点
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next; //在有序单链表中找插入 p所指结点的前驱结点（pre所指向）
		p->next = pre->next; //在 pre所指结点之后插入 p所指结点
		pre->next = p;
		p = q; //扫描原单链表余下的结点
	}
}