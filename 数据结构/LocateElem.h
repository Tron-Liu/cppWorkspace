#pragma once
#include "LinkNode.h"

/*��Ԫ��ֵ����*/
int LocateElem(LinkNode *L, ElemType e)
{
	LinkNode *p = L->next;							//pָ���׽�㣬i�� 1�����׽������Ϊ 1��
	int i = 1;
	while (p->data != e && p != NULL) {		//����dataֵΪ e�Ľ�㣬�����Ϊ i 
		p = p->next;
		i++;
	}
	if (p == NULL)											//������ֵΪ e�Ľ�㣬���� 0 
		return 0;
	else
		return i;												//����ֵΪ e�Ľ�㣬�������߼���� i 
}