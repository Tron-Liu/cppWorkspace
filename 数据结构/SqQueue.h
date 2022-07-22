#pragma once
/*ADT Queue
	{
		数据对象：
			D={a[i] | 1<=i<=n, n>=0, a[i]为ElemType类型}
		数据关系：
			R={<a[i],a[i+1]> | a[i],a[i+1]属于D，i=1 ,..., n-1}
		基本运算：
			InitQueue(&q):初始化队列，构造一个空队列q。
			DestroyQueue(&q):销毁队列，释放队列q占用的存储空间。
			QueueEmpty(q):判断队列是否为空，若队列q为空，则返回真；否则返回假。
			enQueue(&q,e):进队列，将元素e进队列作为队尾元素。
			deQueue(&q,&e);出队列，从队列q中出队一个元素，并将其值赋给e。
	}
*/

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
bool enQueue(SqQueue *&q, ElemType e)
{
	if (q->rear == MaxSize - 1) //队满上溢出
		return false;			//返回假
	q->rear++;					//队尾增1
	q->data[q->rear] = e;		// rear位置插入元素e
	return true;				//返回真
}

//出队列
bool deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear) //队空下溢出
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}