#pragma once
#include "LinkNode.h"

/*��ʼ�����Ա�*/
void InitList(LinkNode *&L)
{
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;												//����ͷ�ڵ� 
}