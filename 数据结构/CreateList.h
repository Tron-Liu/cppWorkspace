#pragma once
#include "LinkNode.h"

/*利用数组元素整体建立单链表的两种方法*/
/*头插法*/
void CreateListF(LinkNode *&L, ElemType a[], int n)
{
	LinkNode *s;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL; //创建头结点，其 next域置为 NULL
	for (int i = 0; i < n; i++)
	{ //循环建立数据结点 s
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next; //将结点 s插入到原首结点之前、头结点之后
		L->next = s;
	}
}

/*尾插法*/
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
	LinkNode *s, *r;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL; //创建头结点
	r = L;			// r始终指向尾节点，初始时指向头结点
	for (int i = 0; i < n; i++)
	{ //循环建立数据结点 s
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i]; //创建数据结点 s
		r->next = s;	//将结点s插入到结点 r之后
		r = s;
	}
	r->next = NULL; //尾节点的 next域置为 NULL
}