#pragma once
#include "DLinkNode.h"

/*ɾ�����*/
bool ListDelete(DLinkNode *&L, int i, ElemType &e)
{
	int j = 0;
	DLinkNode *p = L, *q;							//pָ��ͷ��㣬j����Ϊ 0 
	if (i <= 0) return false;							//i���󷵻� false
	while (j < i - 1 && p != NULL) {			//���ҵ� i-1����� 
		j++;
		p = p->next;
	}
	if (p == NULL) return false;					//δ�ҵ��� i-1����㷵�� false 
	else {													//�ҵ��� i-1����� (�� pָ������ 
		q = p->next;									// qָ��� i����� 
		if (q == NULL)
			return false;									//�������ڵ� i�����ʱ���� false								
		e = q->data;
		p->next = q->next;							//��˫������ɾ����� p 
		if (p->next != NULL)						//�� p�����ں�̽�㣬�޸���ǰ��ָ�� 
			p->next->prior = p;
		free(q);												//�ͷ� q��� 
		return true;
	}
}