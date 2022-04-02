#pragma once

#include <stdio.h>
#include <malloc.h>
typedef int Elemtype;
typedef struct qnode
{
	Elemtype data;				//���Ԫ��
	struct qnode* next;		//��һ�����ָ��
}DataNode;						//�������ݽ�������

typedef struct
{
	DataNode *front;		//ָ����׽��
	DataNode *rear;		//ָ���β���
}LinkQuNode;				//���ӽ�������

//��ʼ������
void InitQueue(LinkQuNode *&q) {
	q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

//���ٶ���
void DestroyQueue(LinkQuNode *&q) {
	DataNode *pre = q->front, *p;				//preָ����׽��
	if (pre != NULL) {
		p = pre->next;										//pָ����pre�ĺ�̽��
		while (p != NULL) {								//p����ѭ��
			free(pre);											//�ͷ�pre���
			pre = p;											//pre��pͬ������
			p = p->next;
		}
		free(pre);												//�ͷ����һ�����ݽ��
	}
	free(q);														//�ͷ����ӽ��
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(LinkQuNode *q) {
	return(q->front == NULL);
}

//������
void enQueue(LinkQuNode *&q, Elemtype e) {
	DataNode *p;
	p = (DataNode *)malloc(sizeof(DataNode));		//�����½��
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)											//������Ϊ�գ����½����Ƕ��׽�����Ƕ�β���
		q->front = q->rear = p;
	else {																	//�����Ӳ���
		q->rear->next = p;											//�����p������β������rearָ����
		q->rear = p;
	}
}

//������
bool deQueue(LinkQuNode *&q, Elemtype &e) {
	DataNode *t;
	if (q->rear == NULL)						//ԭ������Ϊ��
		return false;
	t = q->front;									//tָ���׽��
	if (q->front == q->rear)					//ԭ��������ֻ��һ�����ݽ��ʱ
		q->front = q->rear = NULL;
	else													//ԭ�����������������������Ͻ��ʱ
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}