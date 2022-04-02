#pragma once
#include <stdio.h>

#define MaxSize 10
typedef int ElemType;
typedef struct MyStruct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

//��ͨѭ�������ǣ���β���룬��ͷɾ��
//�Ӷ�βɾ��
bool deQueue1(SqQueue *&q, ElemType &e) {
	if (q->front == q->rear)											//�ӿ�ʱ���ؼ�
		return false;
	e = q->data[q->rear];												//��ȡ��βԪ��
	q->rear = (q->rear - 1 + MaxSize) % MaxSize;		//�޸Ķ�βָ��
	return true;
}

//�Ӷ�ͷ����
bool enQueue1(SqQueue *&q, ElemType e) {
	if ((q->rear + 1) % MaxSize == q->front)				//�������ؼ�
		return false;
	q->data[q->front] = e;											//Ԫ��e����
	q->front = (q->front - 1 + MaxSize) % MaxSize;	//�޸Ķ�ͷָ��
	return true;
}