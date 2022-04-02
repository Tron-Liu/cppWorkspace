#pragma once
#include "LinkNode.h"

/*�������Ա�*/
void DestroyList(LinkNode *&L)
{
	LinkNode *pre = L, *p = L->next;		//preָ�� p��ǰһ����� 
	while (p != NULL) {								//ɨ�赥���� 
		free(pre);											//�ͷ� pre ��� 
		pre = p;											//pre, p ͬʱ����һ����� 
		p = pre->next;
	}
	free(pre);												//ѭ������ʱ pΪ NULL��preָ��β��㣬�ͷ��� 
}