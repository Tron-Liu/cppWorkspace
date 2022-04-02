#pragma once
#include "DLinkNode.h"

/*ͷ�巨*/
void CreateListF(DLinkNode *&L, ElemType a[], int n)	//�ɺ���n��Ԫ�ص����� a������ͷ����˫���� L 
{
	DLinkNode *s;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));			//����ͷ��� 
	L->prior = L->next = NULL;										//ǰ��ָ������β NULL
	for (int i = 0; i < n; i++) {												//ѭ���������ݽ�� 
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];															//�������ݽ�� s 
		s->next = L->next;													//�� s�����뵽ͷ���֮�� 
		if (L->next != NULL) L->next->prior = s;				//�� L�������ݽ�㣬�޸�L->next��ǰ����� 
		L->next = s;
		s->prior = L;
	}
}

/*β�巨*/
void CreateListR(DLinkNode *&L, ElemType a[], int n)	//�ɺ���n��Ԫ�ص����� a������ͷ����˫���� L
{
	DLinkNode *s, *r;
	L = (DLinkNode *)malloc(sizeof(DLinkNode));			//����ͷ��� 
	L->prior = NULL;
	r = L;																			//rʼ��ָ��β��㣬��ʼʱָ��ͷ��� 
	for (int i = 0; i < n; i++) {												//ѭ���������ݽ�� 
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = a[i];															//�������ݽ�� s 
		r->next = s;																//�� s�����뵽 r���֮�� 
		s->prior = r;
		r = s;																		// rָ��β��� 
	}
	r->next = NULL;															//β����ָ������Ϊ NULL 
}