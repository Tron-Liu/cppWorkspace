#pragma once
#include "LinkNode.h"

/*按元素值查找*/
int LocateElem(LinkNode *L, ElemType e)
{
	LinkNode *p = L->next;							//p指向首结点，i置 1（即首结点的序号为 1）
	int i = 1;
	while (p->data != e && p != NULL) {		//查找data值为 e的结点，其序号为 i 
		p = p->next;
		i++;
	}
	if (p == NULL)											//不存在值为 e的结点，返回 0 
		return 0;
	else
		return i;												//存在值为 e的结点，返回其逻辑序号 i 
}