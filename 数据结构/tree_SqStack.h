#pragma once
#include <stdio.h>
#include <malloc.h>
#include <typeinfo>
#include "BTree.h"
#define MaxSize 50
typedef BTNode * ElemType;

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

//��7.17 ������������ö������洢�ṹ�����һ���㷨����Ӹ���㵽ÿ��Ҷ�ӽ���·��
//				�����У�Ҫ����ú�������ǵݹ��㷨ʵ��
void AllPath1(BTNode * b) {
	BTNode *p, *r;
	bool flag;
	SqStack *st;													//����һ��˳��ջָ��
	InitStack(st);													//��ʼ��ջ st
	p = b;
	do {
		while (p != NULL) {									//ɨ�� p ���������½�㲢��ջ
			Push(st, p);											//��� p ��ջ
			p = p->lchild;										//p �ƶ�������
		}
		r = NULL;													//r ָ��շ��ʵĽ�㣬��ʼʱΪ��
		flag = true;												//flag Ϊ���ʾ���ڴ���ջ�����
		while (!StackEmpty(st) && flag) {
			GetTop(st, p);										//ȡ����ǰ��ջ����� p
			if (p->rchild == r) {								//����� p ������Ϊ�ջ���Ϊ�շ��ʵĽ��
				if (p->lchild == NULL && p->rchild == NULL) {			//��ΪҶ�ӽ��
					for (int i = st->top; i > 0; i--)		//���ջ�е����н��ֵ
						printf("%c->", st->data[i]->data);
					printf("%c\n", st->data[0]->data);
				}
				Pop(st, p);
				r = p;												//r ָ��շ��ʹ��Ľ��
			}
			else {
				p = p->rchild;									//ת�����������
				flag = false;										//��ʾ��ǰ���Ǵ���ջ�����
			}
		}
	} while (!StackEmpty(st));								//ջ����ѭ��
}