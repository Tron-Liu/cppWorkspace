#pragma once
#include "LinkNode.h"

/*插入数据元素*/
bool ListInsert(LinkNode *&L, int i, ElemType e)
{
	int j = 0;
	LinkNode *p = L, *s;							//p指向头结点，j置为0 即头结点的序号为 1
	if (i <= 0) return false;							//i错误返回 false 
	while (j < i - 1 && p != NULL) {			//查找第 i-1个结点 p 
		j++;
		p = p->next;
	}
	if (p == NULL) return false;					//未找到第 i-1个结点，返回false 
	else {													//找到第 i-1个结点 p，插入新结点并返回 true
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;										//创建新结点s，其 data域置为 e 
		s->next = p->next;							//将结点插入到 p之后 
		p->next = s;
		return true;
	}
}