#pragma once
#include "LinkNode.h"

/*�����Ա�ĳ���*/
int ListLength(LinkNode *L)
{
	LinkNode *p = L;						//pָ��ͷ��㣬n��0����ͷ�������Ϊ 0�� 
	int length = 0;
	while (p->next != NULL) {
		length++;
		p = p->next;
	}
	return length;							//ѭ��������pָ��β�ڵ㣬����� nΪ������ 
}