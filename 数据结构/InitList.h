#pragma once
#include "LinkNode.h"

/*初始化线性表*/
void InitList(LinkNode *&L)
{
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL; //创建头节点
}