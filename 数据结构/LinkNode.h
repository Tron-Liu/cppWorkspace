#pragma once
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;				//存放元素值
	struct LNode *next;			//指向后继结点
}LinkNode;							//单链表结点类型