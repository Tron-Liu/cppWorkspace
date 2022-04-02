#pragma once
#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
typedef struct linknode {
	ElemType data;				//������
	struct linknode *next;		//ָ����
}LinkStNode;						//��ջ�������

//��ʼ��ջ
void InitStack(LinkStNode *&s)
{
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

//����ջ
void DestroyStack(LinkStNode *&s)
{
	LinkStNode *pre = s, *p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);			//��ʱpreָ��β��㣬�ͷ���ռ�
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStNode *s)
{
	return(s->next == NULL);
}

//��ջ
void Push(LinkStNode *&s, ElemType e)
{
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));		//�½����
	p->data = e;															//���Ԫ��e
	p->next = s->next;													//��p��������Ϊ�׽��
	s->next = p;
}

//��ջ
bool Pop(LinkStNode *&s, ElemType &e)
{
	LinkStNode *p;
	if (s->next == NULL)		//ջ�յ����
		return false;					//���ؼ�
	p = s->next;						//pָ���׽��
	e = p->data;					//��ȡ�׽��ֵ
	s->next = p->next;			//ɾ���׽��
	free(p);								//�ͷű�ɾ���Ĵ洢�ռ�
	return true;						//������
}

//ȡջ��Ԫ��
bool GetTop(LinkStNode *s, ElemType &e)
{
	if (s->next == NULL)		//ջ�յ����
		return false;					//���ؼ�
	e = s->next->data;			//��ȡ�׽��ֵ
	return true;						//������
}

//��3.5  p86
bool Match(char exp[], int n)
{
	int i = 0;
	char e;
	bool match = true;
	LinkStNode *st;
	InitStack(st);								//��ʼ����ջ
	while (i < n && match)				//ɨ��exp�е������ַ�
	{
		if (exp[i] == '(')					//��ǰ�ַ�Ϊ�����ţ������ջ
			Push(st, exp[i]);
		else if (exp[i] == ')')				//��ǰ�ַ�Ϊ������
		{
			if (GetTop(st, e) == true)	//�ɹ�ȡջ��Ԫ��e
			{
				if (e != '(')						//ջ��Ԫ�ز�Ϊ'('ʱ
					match = false;			//��ʾ��ƥ��
				else								//ջ��Ԫ��Ϊ'('ʱ
					Pop(st, e);					//��ջ��Ԫ�س�ջ
			}
			else match = false;			//�޷�ȡջ��Ԫ��ʱ��ʾ��ƥ��
		}
		i++;										//������������Ԫ��
	}
	if (!StackEmpty(st))					//ջ����ʱ��ʾ��ƥ�� 
		match = false;
	DestroyStack(st);						//����ջ
	return match;
}
