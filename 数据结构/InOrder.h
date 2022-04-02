#pragma once
#include "BTree.h"
#include "tree_SqStack.h"

void InOrder(BTNode *b) {			//��������ݹ��㷨
	if (b != NULL) {
		InOrder(b->lchild);				//�������������
		printf("%c", b->data);			//���ʸ����
		InOrder(b->rchild);				//�������������
	}
}

void InOrder1(BTNode *b) {		//��������ǵݹ��㷨
	BTNode *p;
	SqStack * st;								//����һ��˳��ջָ�� st
	InitStack(st);								//��ʼ��ջ st
	p = b;
	while (!StackEmpty(st) || p != NULL) {
		while (p != NULL) {				//ɨ���� p ���������½�㲢��ջ
			Push(st, p);						//��� p ��ջ
			p = p->lchild;					//�ƶ�������
		}
		if (!StackEmpty(st)) {			//��ջ����
			Pop(st, p);						//��ջ��� p
			printf("%c", p->data);		//���ʽ�� p
			p = p->rchild;					//ת������������
		}
	}
	printf("\n");
	DestroyStack(st);						//����ջ
}