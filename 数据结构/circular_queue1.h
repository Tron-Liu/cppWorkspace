#pragma once
//已知队头指针和队尾指针
#include <stdio.h>
#include <malloc.h>
#define MaxSize 10
typedef int ElemType;
typedef struct MyStruct
{
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

//初始化队列
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
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
bool enQueue(SqQueue *&q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front) //对满上溢出
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}

//出队列
bool deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear) //队空下溢出
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}