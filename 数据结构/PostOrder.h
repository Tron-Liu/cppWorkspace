#pragma once
#include "BTree.h"
#include "tree_SqStack.h"

void PostOrder(BTNode *b) {		//��������ݹ��㷨
	if (b != NULL) {
		PostOrder(b->lchild);			//�������������
		PostOrder(b->rchild);			//�������������
		printf("%c", b->data);			//���ʸ��ڵ�
	}
}

void PostOrder1(BTNode * b) {		//��������ǵݹ��㷨
	BTNode *p, *r;
	bool flag;
	SqStack * st;									//����һ��˳��ջָ�� st
	InitStack(st);									//��ʼ�� st
	p = b;
	do {
		while (p != NULL) {					//ɨ���� p ���������½�㲢��ջ
			Push(st, p);							//��� p ��ջ
			p = p->lchild;						//�ƶ�������
		}
		r = NULL;									//r ָ��շ��ʵĽ�㣬��ʼʱΪ��
		flag = true;								//flag Ϊ��ʱ��ʾ���ڴ���ջ����� 
		while (!StackEmpty(st) && flag) {
			GetTop(st, p);						//ȡ����ǰ��ջ����� p
			if (p->rchild == r) {				//����� p ���Һ���Ϊ�ջ���Ϊ�ոշ��ʹ��Ľ��
				printf("%c", p->data);		//���ʽ�� p
				Pop(st, p);
				r = p;								// r ָ��շ��ʹ��Ľ��
			}
			else {
				p = p->rchild;					//ת������������
				flag = false;						//��ʾ��ǰ���Ǵ���ջ�����
			}
		}
	} while (!StackEmpty(st));				//ջ����ѭ��
	printf("\n");
	DestroyStack(st);							//����ջ
}