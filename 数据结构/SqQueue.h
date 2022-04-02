#pragma once
/*ADT Queue
	{
		���ݶ���
			D={a[i] | 1<=i<=n, n>=0, a[i]ΪElemType����}
		���ݹ�ϵ��
			R={<a[i],a[i+1]> | a[i],a[i+1]����D��i=1 ,..., n-1}
		�������㣺
			InitQueue(&q):��ʼ�����У�����һ���ն���q��
			DestroyQueue(&q):���ٶ��У��ͷŶ���qռ�õĴ洢�ռ䡣
			QueueEmpty(q):�ж϶����Ƿ�Ϊ�գ�������qΪ�գ��򷵻��棻���򷵻ؼ١�
			enQueue(&q,e):�����У���Ԫ��e��������Ϊ��βԪ�ء�
			deQueue(&q,&e);�����У��Ӷ���q�г���һ��Ԫ�أ�������ֵ����e��
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
bool enQueue(SqQueue *&q, ElemType e)
{
	if (q->rear == MaxSize - 1)			//���������
		return false;								//���ؼ�
	q->rear++;									//��β��1
	q->data[q->rear] = e;					//rearλ�ò���Ԫ��e
	return true;									//������
}

//������
bool deQueue(SqQueue *&q, ElemType &e)
{
	if (q->front == q->rear)				//�ӿ������
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}