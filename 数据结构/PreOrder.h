#pragma once
#include "BTree.h"
#include "tree_SqStack.h"

void PreOrder(BTNode *b) {		//��������ݹ��㷨
	if (b != NULL) {
		printf("%c", b->data);			//���ʸ��ڵ�
		PreOrder(b->lchild);			//�������������
		PreOrder(b->rchild);			//�������������
	}
}

void PreOrder1(BTNode * b)			//����ǵݹ�����㷨 1
{
	BTNode * p;
	SqStack * st;									//����ջָ�� st
	InitStack(st);									//��ʼ��ջ st
	if (b != NULL) {
		Push(st, b);								//������ջ
		while (!StackEmpty(st)) {			//ջ����ʱѭ��
			Pop(st, p);							//��ջ��� p ��������
			printf("%c", p->data);
			if (p->rchild != NULL)			//���Һ���ʱ�����ջ
				Push(st, p->rchild);
			if (p->lchild != NULL)			//������ʱ�����ջ
				Push(st, p->lchild);
		}
		printf("\n");
	}
	DestroyStack(st);							//����ջ
}

void PreOrder2(BTNode *b) {					//��������ǵݹ��㷨 2
	BTNode * p;
	SqStack * st;											//����һ��˳��ջָ�� st
	InitStack(st);											//��ʼ��ջ st
	p = b;
	while (!StackEmpty(st) || p != NULL) {
		while (p != NULL) {							//���ʽ�� p �������½�㲢��ջ
			printf("%c", p->data);					//���ʽ�� p
			Push(st, p);									//��� p ��ջ
			p = p->lchild;								//�ƶ�������
		}
		if (!StackEmpty(st)) {						//��ջ����
			Pop(st, p);									//��ջ��� p
			p = p->rchild;								//ת������������
		}
	}
	printf("\n");
	DestroyStack(st);									//����ջ
}