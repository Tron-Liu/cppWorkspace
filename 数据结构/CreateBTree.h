#pragma once
#include "BTree.h"												//�����������Ĵ洢�ṹ����

void CreateBTree(BTNode *&b, const char *str) {
	BTNode *St[MaxSize], *p;								//St������Ϊ˳��ջ
	int top = -1, k, j = 0;										//top��Ϊջ��ָ��
	char ch;
	b = NULL;														//��ʼʱ������Ϊ��
	ch = str[j];
	while (ch != '\0') {											//ѭ��ɨ�� str �е�ÿ���ַ�
		switch (ch) {
		case '(':top++; St[top] = p; k = 1; break;		//��ʼ�������ӽ��
		case ')':top--; break;										//ջ�����������������
		case ',':k = 2; break;										//��ʼ�����Һ��ӽڵ�
		default: p = (BTNode *)malloc(sizeof(BTNode));			//����һ����㣬�� p ָ����
			p->data = ch;											//��Ž��ֵ
			p->lchild = p->rchild = NULL;				//����ָ�붼����Ϊ��
			if (b == NULL)											//����δ�������ڵ�
				b = p;													//p��ָ������Ϊ���ڵ�
			else {														//�ѽ������������ڵ�
				switch (k) {
				case 1: St[top]->lchild = p; break;		//�½������Ϊջ����������
				case 2:St[top]->rchild = p; break;		//�½������Ϊջ�������Һ���
				}
			}
		}
		j++;																//����ɨ�� str
		ch = str[j];
	}
}