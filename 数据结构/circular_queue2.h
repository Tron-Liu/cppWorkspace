#pragma once
//��֪��ͷָ��Ͷ����е�Ԫ�ظ���
#include <stdio.h>
#include <malloc.h>
#define MaxSize 10
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int front;
	int count;
}QuType;

//��ʼ���㷨
void InitQueue(QuType *& qu) {
	qu = (QuType *)malloc(sizeof(QuType));
	qu->front = 0;						//��ͷָ������Ϊ0
	qu->count = 0;					//�����е�Ԫ�ظ�������Ϊ0
}

//�����㷨
bool EnQueue(QuType *&qu, ElemType x)
{
	int rear;																	//��ʱ��Ŷ�βָ��
	if (qu->count == MaxSize)										//���������
		return false;
	else
	{
		rear = (qu->front + qu->count) % MaxSize;		//���βλ��
		rear = (rear + 1) % MaxSize;								//��βָ��ѭ����1
		qu->data[rear] = x;
		qu->count++;														//Ԫ�ظ�����1
		return true;
	}
}

//�����㷨
bool DeQueue(QuType *&qu, ElemType &x)
{
	if (qu->count == 0)											//�ӿ������
		return false;
	else
	{
		qu->front = (qu->front + 1) % MaxSize;	//��ͷԪ��ѭ����1
		x = qu->data[qu->front];
		qu->count--;												//Ԫ�ظ�����1
		return true;
	}
}

//�ж϶��п��㷨
bool QueueEmpty(QuType *qu)
{
	return (qu->count == 0);
}

