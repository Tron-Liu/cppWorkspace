#pragma once
#include <stdio.h>
#include <malloc.h>
#define MaxSize 60

typedef struct {
	int i, j;				//�����λ��
	int pre;				//��·������һ�������ڶ����е��±�
}Box;						//��������

typedef Box ElemType;

typedef struct {
	Box data[MaxSize];
	int front, rear;				//��ͷָ��Ͷ�βָ��
}QuType;							//˳�������

//��ʼ������
void InitQueue(QuType *&q)
{
	q = (QuType *)malloc(sizeof(QuType));
	q->front = q->rear = -1;
}

//���ٶ���
void DestroyQueue(QuType *&q)
{
	free(q);
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(QuType *q)
{
	return(q->front == q->rear);
}

//������
bool enQueue(QuType *&q, ElemType e)
{
	if (q->rear == MaxSize - 1)			//���������
		return false;								//���ؼ�
	q->rear++;									//��β��1
	q->data[q->rear] = e;					//rearλ�ò���Ԫ��e
	return true;									//������
}

//������
bool deQueue(QuType *&q, ElemType &e)
{
	if (q->front == q->rear)				//�ӿ������
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
