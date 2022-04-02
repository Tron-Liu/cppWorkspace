#pragma once
#include "LinkNode.h"

/*��������Ԫ�����彨������������ַ���*/
/*ͷ�巨*/
void CreateListF(LinkNode *&L, ElemType a[], int n) {
	LinkNode *s;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;													//����ͷ��㣬�� next����Ϊ NULL 
	for (int i = 0; i < n; i++) {										//ѭ���������ݽ�� s
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;											//����� s���뵽ԭ�׽��֮ǰ��ͷ���֮�� 
		L->next = s;
	}
}

/*β�巨*/
void  CreateListR(LinkNode *&L, ElemType a[], int n) {
	LinkNode *s, *r;
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;													//����ͷ��� 
	r = L;																	//rʼ��ָ��β�ڵ㣬��ʼʱָ��ͷ��� 
	for (int i = 0; i < n; i++) {										//ѭ���������ݽ�� s
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = a[i];													//�������ݽ�� s 
		r->next = s;														//�����s���뵽��� r֮�� 
		r = s;
	}
	r->next = NULL;													//β�ڵ�� next����Ϊ NULL
}