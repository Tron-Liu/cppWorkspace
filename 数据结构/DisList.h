#pragma once
#include "LinkNode.h"

/*������Ա�*/
void DisList(LinkNode *L)
{
	LinkNode *p = L->next;		//pָ���׽�� 
	while (p != NULL) {				//p��Ϊ NULL 
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}