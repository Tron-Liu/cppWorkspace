#pragma once

#include <stdio.h>
#include <malloc.h>
#include "BTree.h"

typedef BTNode *elemType;

typedef struct
{
	elemType data[MaxSize];
	int front, rear;
} SqQueue;

//初始化队列
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

//销毁队列
void DestroyQueue(SqQueue *&q)
{
	free(q);
}

//判断队列是否为空
bool QueueEmpty(SqQueue *q)
{
	return (q->front == q->rear);
}

//进队列
bool enQueue(SqQueue *&q, elemType e)
{
	if (q->rear == MaxSize - 1) //队满上溢出
		return false;			//返回假
	q->rear++;					//队尾增1
	q->data[q->rear] = e;		// rear位置插入元素e
	return true;				//返回真
}

//出队列
bool deQueue(SqQueue *&q, elemType &e)
{
	if (q->front == q->rear) //队空下溢出
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

void LevelOrder(BTNode *b)
{
	BTNode *p;
	SqQueue *qu;	//定义环形队列指针
	InitQueue(qu);	//初始化队列
	enQueue(qu, b); //根节点指针进入队列
	while (!QueueEmpty(qu))
	{						   //队不为空循环
		deQueue(qu, p);		   //出队结点 p
		printf("%c", p->data); //访问结点 p
		if (p->lchild != NULL) //有左孩子时将其进队
			enQueue(qu, p->lchild);
		if (p->rchild != NULL) //有右孩子时将其进队
			enQueue(qu, p->rchild);
	}
}