#pragma once
//已知队头指针和队列中的元素个数
#include <stdio.h>
#include <malloc.h>
#define MaxSize 10
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int front;
	int count;
}QuType;

//初始化算法
void InitQueue(QuType *& qu) {
	qu = (QuType *)malloc(sizeof(QuType));
	qu->front = 0;						//队头指针设置为0
	qu->count = 0;					//队列中的元素个数设置为0
}

//进队算法
bool EnQueue(QuType *&qu, ElemType x)
{
	int rear;																	//临时存放队尾指针
	if (qu->count == MaxSize)										//队满上溢出
		return false;
	else
	{
		rear = (qu->front + qu->count) % MaxSize;		//求队尾位置
		rear = (rear + 1) % MaxSize;								//队尾指针循环增1
		qu->data[rear] = x;
		qu->count++;														//元素个数增1
		return true;
	}
}

//出队算法
bool DeQueue(QuType *&qu, ElemType &x)
{
	if (qu->count == 0)											//队空下溢出
		return false;
	else
	{
		qu->front = (qu->front + 1) % MaxSize;	//队头元素循环增1
		x = qu->data[qu->front];
		qu->count--;												//元素个数减1
		return true;
	}
}

//判断队列空算法
bool QueueEmpty(QuType *qu)
{
	return (qu->count == 0);
}

