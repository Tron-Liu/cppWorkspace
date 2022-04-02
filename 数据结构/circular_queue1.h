#pragma once
//��֪��ͷָ��Ͷ�βָ��
#include <stdio.h>
#include <malloc.h>
#define MaxSize 10
typedef int ElemType;
typedef struct MyStruct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

//��ʼ������
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

//���ٶ���
void DestroyQueue(SqQueue *&q)
{
	free(q);
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue *q)
{
	return(q->front == q->rear);
}

//������
bool enQueue(SqQueue *&q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front)		//���������
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}

//������
bool deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear)			//�ӿ������
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}