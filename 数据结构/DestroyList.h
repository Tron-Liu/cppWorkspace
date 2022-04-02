#pragma once
#include "LinkNode.h"

/*销毁线性表*/
void DestroyList(LinkNode *&L)
{
	LinkNode *pre = L, *p = L->next;		//pre指向 p的前一个结点 
	while (p != NULL) {								//扫描单链表 
		free(pre);											//释放 pre 结点 
		pre = p;											//pre, p 同时后移一个结点 
		p = pre->next;
	}
	free(pre);												//循环结束时 p为 NULL，pre指向尾结点，释放它 
}