#pragma once
#include <stdio.h>
#include <malloc.h>
#define MaxSize 60

typedef struct
{
	int i, j; //方块的位置
	int pre;  //本路径中上一个方块在队列中的下标
} Box;		  //方块类型

typedef Box ElemType;

typedef struct
{
	Box data[MaxSize];
	int front, rear; //队头指针和队尾指针
} QuType;			 //顺序队类型

//初始化队列
void InitQueue(QuType *&q)
{
	q = (QuType *)malloc(sizeof(QuType));
	q->front = q->rear = -1;
}

//销毁队列
void DestroyQueue(QuType *&q)
{
	free(q);
}

//判断队列是否为空
bool QueueEmpty(QuType *q)
{
	return (q->front == q->rear);
}

//进队列
bool enQueue(QuType *&q, ElemType e)
{
	if (q->rear == MaxSize - 1) //队满上溢出
		return false;			//返回假
	q->rear++;					//队尾增1
	q->data[q->rear] = e;		// rear位置插入元素e
	return true;				//返回真
}

//出队列
bool deQueue(QuType *&q, ElemType &e)
{
	if (q->front == q->rear) //队空下溢出
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
