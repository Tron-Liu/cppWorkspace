#pragma once
#include "DLinkNode.h"

/*插入结点*/
bool ListInsert(DLinkNode *&L, int i, ElemType e)
{
	int j = 0;
	DLinkNode *p = L, *s; // p指向头结点，j设置为 0
	if (i <= 0)
		return false; // i错误返回 false
	while (j < i - 1 && p != NULL)
	{ //查找第 i-1个结点
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false; //未找到第 i-1个结点返回 false
	else
	{ //找到第 i-1个结点 p
		s = (DLinkNode *)malloc(sizeof(DLinkNode));
		s->data = e;		 //创建新结点 s
		s->next = p->next;	 //在 p结点之后插入 s结点
		if (p->next != NULL) //若 p结点存在后继结点，修改其前驱指针
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}