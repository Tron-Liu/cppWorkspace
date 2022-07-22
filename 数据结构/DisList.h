#pragma once
#include "LinkNode.h"

/*输出线性表*/
void DisList(LinkNode *L)
{
	LinkNode *p = L->next; // p指向首结点
	while (p != NULL)
	{ // p不为 NULL
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}