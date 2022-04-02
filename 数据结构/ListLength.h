#pragma once
#include "LinkNode.h"

/*求线性表的长度*/
int ListLength(LinkNode *L)
{
	LinkNode *p = L;						//p指向头结点，n置0（即头结点的序号为 0） 
	int length = 0;
	while (p->next != NULL) {
		length++;
		p = p->next;
	}
	return length;							//循环结束，p指向尾节点，其序号 n为结点个数 
}