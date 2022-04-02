#pragma once
#include <stdio.h>
#include <malloc.h>
#include "BTree.h"
#define MaxSize 10

typedef struct snode {
	BTNode * pt;					//��ŵ�ǰ���ָ��
	int parent;						//���˫�׽���ڶ����е�λ��
}NodeType;							//�ǻ��ζ���Ԫ������

typedef  NodeType ElemType;

typedef struct {
	ElemType data[MaxSize];		//��Ŷ���Ԫ��
	int front, rear;						//��ͷָ��Ͷ�βָ��
}QuType;									//˳�������

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

//��7.18 ���ò�α���������� ��7.17 ���㷨
void AllPath2(BTNode * b) {
	int k;
	BTNode *p;
	NodeType qelem;
	QuType *qu;											//����ǻ��ζ���ָ��
	InitQueue(qu);											//��ʼ������
	qelem.pt = b; qelem.parent = -1;			//�������ڵ��Ӧ�Ķ���Ԫ��
	enQueue(qu, qelem);								//��������
	while (!QueueEmpty(qu)) {						//�Ӳ���ѭ��
		deQueue(qu, qelem);							//����Ԫ��qelem�����ڶ��е��±�Ϊ qu->front
		p = qelem.pt;										//ȡԪ�� qelem ��Ӧ�Ľ��
		if (p->lchild == NULL && p->rchild == NULL) {		//��� p ΪҶ�ӽ��
			k = qu->front;									//������ p �����ڵ��·����������
			while (qu->data[k].parent != -1) {
				printf("%c->", qu->data[k].pt->data);
				k = qu->data[k].parent;
			}
			printf("%c\n", qu->data[k].pt->data);
		}
		if (p->lchild != NULL) {						//��� p ������
			qelem.pt = p->lchild;						//������� p �����Ӷ�Ӧ�Ķ���Ԫ��
			qelem.parent = qu->front;				//��� p �����ӵ�˫��λ��Ϊ qu->front
			enQueue(qu, qelem);						//��� p �����ӽ���
		}
		if (p->rchild != NULL) {						//��� p ���Һ���
			qelem.pt = p->rchild;						//������� p ���Һ��Ӷ�Ӧ�Ķ���Ԫ��
			qelem.parent = qu->front;				//��� p ���Һ��ӵ�˫��λ��Ϊ qu->front
			enQueue(qu, qelem);						//��� p ���Һ��ӽ���
		}
	}
}