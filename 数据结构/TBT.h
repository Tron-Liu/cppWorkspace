#pragma once
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;

typedef struct node {
	ElemType data;				//���������
	int ltag, rtag;					//���ӵ��������
	struct node * lchild;			//���ӻ�����ָ��
	struct node * rchild;			//�Һ��ӻ�����ָ��
}TBTNode;							//�����������Ľ������

/*
	ltag=0:  ��ʾ lchild ָ�����ӽ��
	ltag=1:  ��ʾ lchild ָ��ǰ�����
	rtag=0:	  ��ʾ rchild ָ���Һ��ӽ��
	rtag=1:	  ��ʾ rchild ָ���̽��
*/

//�������㷨�� p ����ָ��ǰ���������Ľ�㣬�� pre ��Ϊȫ�ֱ�����ָ��շ��ʹ��Ľ��
//��� pre �ǽ�� p ��ǰ����㣬��� p �ǽ�� pre ��ǰ�����

TBTNode *pre;									//ȫ�ֱ���
void Thread(TBTNode *&p) {			//�Զ����� p ��������������
	if (p != NULL) {
		Thread(p->lchild);					//������������
		if (p->lchild == NULL) {			//�����������ڣ�����ǰ�����������
			p->lchild = pre;					//������ǰ����ǰ���������
			p->ltag = 1;
		}
		else p->ltag = 0;						//p ������������������
		if (pre->rchild == NULL) {		//�� pre �ĺ�̽��������
			p->rchild = p;						//����ǰ�����ĺ�̽������
			pre->rtag = 1;
		}
		else p->rtag = 0;
		pre = p;
		Thread(p->rchild);					//������������
	}
}

TBTNode * CreateThread(TBTNode *b) {						//����������������
	TBTNode *root;
	root = (TBTNode *)malloc(sizeof(TBTNode));			//����ͷ���
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = b;
	if (b == NULL)															//�ն�����
		root->lchild = root;
	else {
		root->lchild = b;
		pre = root;								//pre �ǽ�� p ��ǰ����㣬����������
		Thread(b);								//�������������������
		pre->rchild = root;					//���������ָ��ͷ��������
		pre->rtag = 1;
		root->rchild = pre;					//ͷ�����������
	}
	return root;
}

//����������������
void ThInOrder(TBTNode * tb) {
	TBTNode *p = tb->lchild;									//p ָ������
	while (p != tb) {
		while (p->ltag == 0) p = p->lchild;					//�ҿ�ʼ���
		printf("%c", p->data);										//���ʿ�ʼ���
		while (p->rtag == 1 && p->rchild != tb) {
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
}