#pragma once
#include "LinkNode.h"

/*��������Ԫ��*/
bool ListInsert(LinkNode *&L, int i, ElemType e)
{
	int j = 0;
	LinkNode *p = L, *s;							//pָ��ͷ��㣬j��Ϊ0 ��ͷ�������Ϊ 1
	if (i <= 0) return false;							//i���󷵻� false 
	while (j < i - 1 && p != NULL) {			//���ҵ� i-1����� p 
		j++;
		p = p->next;
	}
	if (p == NULL) return false;					//δ�ҵ��� i-1����㣬����false 
	else {													//�ҵ��� i-1����� p�������½�㲢���� true
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;										//�����½��s���� data����Ϊ e 
		s->next = p->next;							//�������뵽 p֮�� 
		p->next = s;
		return true;
	}
}