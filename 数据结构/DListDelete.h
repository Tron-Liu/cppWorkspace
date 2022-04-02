#pragma once
#include "DLinkNode.h"

/*删除结点*/
bool ListDelete(DLinkNode *&L, int i, ElemType &e)
{
	int j = 0;
	DLinkNode *p = L, *q;							//p指向头结点，j设置为 0 
	if (i <= 0) return false;							//i错误返回 false
	while (j < i - 1 && p != NULL) {			//查找第 i-1个结点 
		j++;
		p = p->next;
	}
	if (p == NULL) return false;					//未找到第 i-1个结点返回 false 
	else {													//找到第 i-1个结点 (由 p指向它） 
		q = p->next;									// q指向第 i个结点 
		if (q == NULL)
			return false;									//当不存在第 i个结点时返回 false								
		e = q->data;
		p->next = q->next;							//从双链表中删除结点 p 
		if (p->next != NULL)						//若 p结点存在后继结点，修改其前驱指针 
			p->next->prior = p;
		free(q);												//释放 q结点 
		return true;
	}
}