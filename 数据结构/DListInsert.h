#pragma once
#include "DLinkNode.h"

/*������*/
bool ListInsert(DLinkNode *&L, int i, ElemType e)
{
	int j = 0;
	DLinkNode *p = L, *s;								//pָ��ͷ��㣬j����Ϊ 0 
	if (i <= 0) return false;								//i���󷵻� false 
	while (j < i - 1 && p != NULL) {				//���ҵ� i-1����� 
		p = p->next;
		j++;
	}
	if (p == NULL) return false;						//δ�ҵ��� i-1����㷵�� false 
	else {														//�ҵ��� i-1����� p 
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = e;											//�����½�� s 
		s->next = p->next;								//�� p���֮����� s��� 
		if (p->next != NULL)							//�� p�����ں�̽�㣬�޸���ǰ��ָ�� 
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}