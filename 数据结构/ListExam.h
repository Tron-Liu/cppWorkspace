#pragma once
#include "LinkNode.h"

//�� 2.6  p52
void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2)		//L1β�巨 L2ͷ�巨 
{
	LinkNode *p = L->next, *r, *q;								// pָ���һ�����ݽ�� 
	L1 = L;																		// L1����ԭ�� L��ͷ��� 
	r = L;																		// rʼ��ָ�� L1��β��� 
	L2 = (LinkNode *)malloc(sizeof(LinkNode));			//���� L2��ͷ��� 
	L2->next = NULL;													//�� L2��ָ����Ϊ NULL 
	while (p != NULL) {
		r->next = p;															//����β�巨��p��dataֵΪ a[i]������L1�� 
		r = p;
		p = p->next;														//p�Ƶ���һ����㣨dataֵΪ b[i]�� 
		q = p->next;														//ͷ�巨��ı� p��ָ������ q���洢��� p�ĺ�̽�� 
		p->next = L2->next; 											//����ͷ�巨�� p���뵽 L2�� 
		L2->next = p;
		p = q;                													//p����ָ�� a[i+1] 
	}
	r->next = NULL;           											//L1β���next�ÿ� 
}

//�� 2.7 ɾ�������� L ��Ԫ��ֵ���Ľ��
void delMaxNode(LinkNode *&L)
{
	LinkNode *p = L->next, *pre = L, *maxp = p, *maxpre = pre;
	while (p != NULL) {									//�� pɨ������������  preʼ��ָ����ǰ����� 
		if (maxp->data < p->data) {				// ���ҵ�һ������Ľ�� 
			maxp = p;										//���� maxp 
			maxpre = pre;									//���� maxpre 
		}
		pre = p;												// preͬʱ����һ����� 
		p = p->next;
	}
	maxpre->next = maxp->next;					//ɾ�� maxp��� 
	free(maxp);												//�ͷ� maxp���ռ� 
}

//�� 2.8 ���һ���㷨ʹ��һ����ͷ���ĵ����� L ������������
void sort(LinkNode *&L)
{
	LinkNode *p, *pre, *q;
	p = L->next->next;								//pָ�� L�ĵڶ������ݽ�� 
	L->next->next = NULL;						//����ֻ��һ�����ݽ����������� 
	while (p != NULL) {
		q = p->next;									//q���� p����һ����� 
		pre = L;											//����������ͷ���бȽϣ�preָ��������ǰ����� 
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;							//�������������Ҳ��� p��ָ����ǰ����㣨pre��ָ�� 
		p->next = pre->next;						//�� pre��ָ���֮����� p��ָ��� 
		pre->next = p;
		p = q;												//ɨ��ԭ���������µĽ�� 
	}
}