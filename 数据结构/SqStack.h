#pragma once
/*
ADT Stack
{
	���ݶ���
		D = {a[i] | 1<=i<=n, n>=0, a[i]ΪElemType����}
	���ݹ�ϵ:
		R = {<a[i], a[i+1]> | a[i]��a[i + 1]����D��i=1��... , n-1}
	��������:
		InitStack(&s):��ʼ��ջ������һ����ջs��
		DestroyStack(&s):����ջ���ͷ�ջsռ�õ��ڴ�ռ䡣
		StackEmpty(s):�ж�ջ�Ƿ�Ϊ�գ���ջΪ�գ��򷵻��棬���򷵻ؼ١�
		Push(&s, e):��ջ����Ԫ��e���뵽ջs����Ϊջ��Ԫ�ء�
		Pop(&s, &e):��ջ����ջs��ɾ��ջ��Ԫ�أ�������ֵ����e��
		GetTop(s, &e):ȡջ��Ԫ�أ����ᵱǰ��ջ��Ԫ�أ������丳��e��
}
*/

#include <stdio.h>
#include <malloc.h>
#include <typeinfo>
#define MaxSize 50
typedef char ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

//��ʼ��ջ
void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizeof(SqStack));  //����һ��˳��ջ�ռ䣬�׵�ַ�����s��
	s->top = -1;												//ջ��ָ����Ϊ-1
}

//����ջ
void DestroyStack(SqStack *&s)
{
	free(s);
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack *s)
{
	return (s->top == -1);
}

//��ջ
bool Push(SqStack *&s, ElemType e)
{
	if (s->top == MaxSize - 1)				//ջ�������������ջ����
		return false;
	s->top++;										//ջ��ָ����1
	s->data[s->top] = e;						//Ԫ��e����ջ��ָ�봦
	return true;
}

//��ջ
bool Pop(SqStack *&s, ElemType &e)
{
	if (s->top == -1)									//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];							//ȡջ��Ԫ��
	s->top--;												//ջ��ָ���1
	return true;
}

//ȡջ��Ԫ��
bool GetTop(SqStack *s, ElemType &e)
{
	if (s->top == -1)									//ջΪ�յ��������ջ�����
		return false;
	e = s->data[s->top];							//ȡջ��Ԫ��
	return true;
}

//��3.4  p82
bool symmetry(ElemType str[])		//�ж�str�Ƿ�Ϊ�Գƴ�
{
	int i;
	ElemType e;
	SqStack *st;									//����˳��ջָ��
	InitStack(st);									//��ʼ��
	for (i = 0; str[i] != '\0'; i++)			//��str������Ԫ�ؽ�ջ
		Push(st, str[i]);
	for (i = 0; str[i] != '\0'; i++)			//����str�������ַ�
	{
		Pop(st, e);									//��ջԪ��e
		if (str[i] != e)								//��e�뵱ǰ���ַ���ͬ��ʾ���ǶԳƴ�
		{
			DestroyStack(st);					//����ջ
			return false;							//���ؼ�
		}
	}
	DestroyStack(st);							//����ջ
	return true;									//������
}
