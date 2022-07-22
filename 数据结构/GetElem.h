#pragma once
#include "LinkNode.h"

/*求线性表中的某个数据元素值*/
bool GetElem(LinkNode *L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L; // p指向头结点，j置 0（即头结点的序号为 0）
	if (i <= 0)
		return false; // i错误返回 false
	while (j < i && p != NULL)
	{ //找到第 i个结点 p
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false; //不存在第 i个数据结点，返回 false
	else
	{ //存在第 i个数据结点，返回 true
		e = p->data;
		return true;
	}
}