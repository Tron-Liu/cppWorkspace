#pragma once
#include "LinkNode.h"

/*ɾ������Ԫ��*/
bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L, *s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) return false;
	else {
		s = p->next;								//sָ��� i����� 
		if (s == NULL) return false;		//�������ڵ� i����㣬���� false 
		e = s->data;
		p->next = s->next;
		free(s);										//�ͷ� s ��� 
		return true;								//���� true ��ʾ�ɹ�ɾ���� i ����� 
	}
}