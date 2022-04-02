#pragma once
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef double ElemType1;

typedef struct
{
	ElemType1 data[MaxSize];
	int top;
}SqStack1;

//��ʼ��ջ
void InitStack1(SqStack1 *&s)
{
	s = (SqStack1 *)malloc(sizeof(SqStack1));  //����һ��˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;												//ջ��ָ����Ϊ-1
}

//����ջ
void DestroyStack1(SqStack1 *&s)
{
	free(s);
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty1(SqStack1 *s)
{
	return (s->top == -1);
}

//��ջ
bool Push1(SqStack1 *&s, ElemType1 e)
{
	if (s->top == MaxSize - 1)				//ջ�������������ջ����
		return false;
	s->top++;										//ջ��ָ����1
	s->data[s->top] = e;						//Ԫ��e����ջ��ָ�봦
	return true;
}

//��ջ
bool Pop1(SqStack1 *&s, ElemType1 &e)
{
	if (s->top == -1)									//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];							//ȡջ��Ԫ��
	s->top--;												//ջ��ָ���1
	return true;
}

//ȡջ��Ԫ��
bool GetTop1(SqStack1 *s, ElemType1 &e)
{
	if (s->top == -1)									//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];							//ȡջ��Ԫ��
	return true;
}

//��3.4  p82
bool symmetry(ElemType1 str[])		//�ж�str�Ƿ�Ϊ�Գƴ�
{
	int i;
	ElemType1 e;
	SqStack1 *st;									//����˳��ջָ��
	InitStack1(st);									//��ʼ��
	for (i = 0; str[i] != '\0'; i++)			//��str������Ԫ�ؽ�ջ
		Push1(st, str[i]);
	for (i = 0; str[i] != '\0'; i++)			//����str�������ַ�
	{
		Pop1(st, e);									//��ջԪ��e
		if (str[i] != e)								//��e�뵱ǰ���ַ���ͬ��ʾ���ǶԳƴ�
		{
			DestroyStack1(st);					//����ջ
			return false;							//���ؼ�
		}
	}
	DestroyStack1(st);							//����ջ
	return true;									//������
}