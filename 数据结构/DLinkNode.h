#pragma once

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct DNode
{
	ElemType data;		 //存放元素值
	struct DNode *prior; //指向前驱结点
	struct DNode *next;	 //指向后继结点
} DLinkNode;			 //双链表的结点类型