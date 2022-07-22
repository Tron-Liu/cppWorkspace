#pragma once
#include "链串.h"
//例4.3
void Repl(LinkStrNode *&s)
{
	LinkStrNode *p = s->next, *q;
	bool find = false;
	while (p != NULL && p->next != NULL && !find)
	{ //查找'ab'子串
		if (p->data == 'a' && p->next->data == 'b')
		{				   //找到时
			p->data = 'x'; //替换
			p->next->data = 'z';
			q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
			q->data = 'y';
			q->next = p->next;
			p->next = q;
			find = true;
		}
		else //尚未找到时继续查找
			p = p->next;
	}
}
