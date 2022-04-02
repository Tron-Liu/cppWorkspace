#pragma once
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	LNode *next;
}LinkNode;

//初始化算法
void initQueue(LinkNode *&rear) {
	rear = NULL;
}

//进队算法
void enQueue(LinkNode *&rear, ElemType e) {
	LinkNode *p;
	p = (LinkNode *)malloc(sizeof(LinkNode));			//创建新结点
	p->data = e;
	if (rear == NULL) {												//原链队为空
		p->next = p;													//改为循环链表
		rear = p;															//rear指向新结点
	}
	else {																	//原队列不空
		p->next = rear->next;										//将p结点插入到rear结点之后
		rear->next = p;												//改为循环链表
		rear = p;															//rear指向新结点p
	}
}

//出队算法
bool deQueue(LinkNode *&rear, ElemType &e) {
	LinkNode *t;
	if (rear == NULL)													//队空
		return false;
	else if (rear->next == rear) {								//原队列只有一个结点
		e = rear->data;
		free(rear);
		rear == NULL;													//让rear为空链表
	}
	else {																	//原队中有两个或两个以上的结点
		t = rear->next;													//t指向队头结点
		e = t->data;
		rear->next = t->next;										//删除t结点
		free(t);																//释放结点空间
	}
	return true;
}

//判队空算法
bool queueEmpty(LinkNode *rear) {
	return (rear == NULL);
}

