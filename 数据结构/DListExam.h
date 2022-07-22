#pragma once
#include "DLinkNode.h"

//例2.9 双链表中的元素逆置 p58
void reverse(DLinkNode *&L) //双链表结点逆置算法
{
	DLinkNode *p = L->next, *q; // p指向首结点
	L->next = NULL;				//构造只有头结点的双链表L
	while (p != NULL)			//扫描L的所有数据结点
	{
		q = p->next;			//头插法会改变p的next域，用q临时保存其后继结点
		p->next = L->next;		//采用头插法将p插入到双链表中
		if (L->next != NULL)	//若L中存在数据结点
			L->next->prior = p; //修改原来首结点的前驱指针
		L->next = p;			//将新结点作为首结点
		p->prior = L;
		p = q; //让p重新指向其后继结点
	}
}

//例2.10 双链表中的元素有序递增 p58
void sort(DLinkNode *&L)
{
	DLinkNode *p, *pre, *q;
	p = L->next->next;	  // p指向L的第二个数据结点
	L->next->next = NULL; //构造只含一个数据结点的有序表
	while (p != NULL)
	{
		q = p->next; // q保存p结点的后继结点
		pre = L;	 //从有序表开头进行比较，pre指向插入结点p的前驱结点
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next; //在有序表中找插入结点的前驱结点
		p->next = pre->next; //在pre结点之后插入结点p
		if (pre->next != NULL)
			pre->next->prior = p;
		pre->next = p;
		p->prior = pre;
		p = q; //扫描原双链表余下的结点
	}
}