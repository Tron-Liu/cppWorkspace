#pragma once
#include "LinkNode.h"

/*删除数据元素*/
bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
	int j = 0;
	LinkNode *p = L, *s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = p->next; // s指向第 i个结点
		if (s == NULL)
			return false; //若不存在第 i个结点，返回 false
		e = s->data;
		p->next = s->next;
		free(s);	 //释放 s 结点
		return true; //返回 true 表示成功删除第 i 个结点
	}
}