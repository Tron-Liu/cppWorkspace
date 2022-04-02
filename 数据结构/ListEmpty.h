#pragma once
#include "LinkNode.h"

/*判断线性表是否为空表*/
bool ListEmpty(LinkNode *L)
{
	return(L->next == NULL);
}