#pragma once
#include <stdio.h>

#define MaxSize 10
typedef int ElemType;
typedef struct MyStruct
{
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

//普通循环队列是：队尾插入，队头删除
//从队尾删除
bool deQueue1(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear) //队空时返回假
		return false;
	e = q->data[q->rear];						 //提取队尾元素
	q->rear = (q->rear - 1 + MaxSize) % MaxSize; //修改队尾指针
	return true;
}

//从队头插入
bool enQueue1(SqQueue *&q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front) //队满返回假
		return false;
	q->data[q->front] = e;						   //元素e进队
	q->front = (q->front - 1 + MaxSize) % MaxSize; //修改队头指针
	return true;
}