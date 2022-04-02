#pragma once
#include "DLinkNode.h"

/*头插法*/
void CreateListF(DLinkNode *&L, ElemType a[], int n)	//由含有n个元素的数组 a创建带头结点的双链表 L 
{
	DLinkNode *s;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));			//创建头结点 
	L->prior = L->next = NULL;										//前后指针域置尾 NULL
	for (int i = 0; i < n; i++) {												//循环建立数据结点 
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];															//创建数据结点 s 
		s->next = L->next;													//将 s结点插入到头结点之后 
		if (L->next != NULL) L->next->prior = s;				//若 L存在数据结点，修改L->next的前驱结点 
		L->next = s;
		s->prior = L;
	}
}

/*尾插法*/
void CreateListR(DLinkNode *&L, ElemType a[], int n)	//由含有n个元素的数组 a创建带头结点的双链表 L
{
	DLinkNode *s, *r;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));			//建立头结点 
	L->prior = NULL;
	r = L;																			//r始终指向尾结点，开始时指向头结点 
	for (int i = 0; i < n; i++) {												//循环建立数据结点 
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];															//创建数据结点 s 
		r->next = s;																//将 s结点插入到 r结点之后 
		s->prior = r;
		r = s;																		// r指向尾结点 
	}
	r->next = NULL;															//尾结点的指针域置为 NULL 
}