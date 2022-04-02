#pragma once
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50

typedef struct
{
	int i;					//��ǰ������к�
	int j;					//��ǰ������к�
	int di;				//di����һ���ڿ��߷�λ�ķ�λ��
}Box;						//��������

typedef struct
{
	Box data[MaxSize];
	int top;							//ջ��ָ��
}StType;							//˳��ջ����

typedef Box ElemType2;

//��ʼ��ջ
void InitStack(StType *&s)
{
	s = (StType *)malloc(sizeof(StType));  //����һ��˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;												//ջ��ָ����Ϊ-1
}

//����ջ
void DestroyStack(StType *&s)
{
	free(s);
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(StType *s)
{
	return (s->top == -1);
}

//��ջ
bool Push(StType *&s, ElemType2 e)
{
	if (s->top == MaxSize - 1)				//ջ�������������ջ����
		return false;
	s->top++;										//ջ��ָ����1
	s->data[s->top] = e;						//Ԫ��e����ջ��ָ�봦
	return true;
}

//��ջ
bool Pop(StType *&s, ElemType2 &e)
{
	if (s->top == -1)									//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];							//ȡջ��Ԫ��
	s->top--;												//ջ��ָ���1
	return true;
}

//ȡջ��Ԫ��
bool GetTop(StType *s, ElemType2 &e)
{
	if (s->top == -1)									//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];							//ȡջ��Ԫ��
	return true;
}
