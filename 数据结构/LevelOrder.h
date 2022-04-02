#pragma once

#include <stdio.h>
#include <malloc.h>
#include "BTree.h"

typedef  BTNode* elemType;

typedef struct
{
	elemType data[MaxSize];
	int front, rear;
}SqQueue;

//��ʼ������
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
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
bool enQueue(SqQueue *&q, elemType e)
{
	if (q->rear == MaxSize - 1)			//���������
		return false;								//���ؼ�
	q->rear++;									//��β��1
	q->data[q->rear] = e;					//rearλ�ò���Ԫ��e
	return true;									//������
}

//������
bool deQueue(SqQueue *&q, elemType &e)
{
	if (q->front == q->rear)				//�ӿ������
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

void LevelOrder(BTNode * b) {
	BTNode *p;
	SqQueue * qu;								//���廷�ζ���ָ��
	InitQueue(qu);								//��ʼ������
	enQueue(qu, b);							//���ڵ�ָ��������
	while (!QueueEmpty(qu)) {			//�Ӳ�Ϊ��ѭ��
		deQueue(qu, p);						//���ӽ�� p
		printf("%c", p->data);				//���ʽ�� p
		if (p->lchild != NULL)				//������ʱ�������
			enQueue(qu, p->lchild);
		if (p->rchild != NULL)				//���Һ���ʱ�������
			enQueue(qu, p->rchild);
	}
}