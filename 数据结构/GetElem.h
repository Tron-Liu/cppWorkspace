#pragma once
#include "LinkNode.h"

/*�����Ա��е�ĳ������Ԫ��ֵ*/
bool GetElem(LinkNode *L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L;								//pָ��ͷ��㣬j�� 0����ͷ�������Ϊ 0�� 
	if (i <= 0) return false;						// i���󷵻� false 
	while (j < i && p != NULL) {			//�ҵ��� i����� p 
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;									//�����ڵ� i�����ݽ�㣬���� false 
	else {												//���ڵ� i�����ݽ�㣬���� true 
		e = p->data;
		return true;
	}
}