#pragma once
#include "BTree.h"

/* 
	pre ����������У�in ����������У�nΪ�������Ľ�����
	���㷨ִ�к󷵻ع���Ķ������ĸ��ڵ�ָ�� b
*/
BTNode * CreateBT1(char * pre, char * in, int n) {
	BTNode * b;
	char * p;
	int k;
	if (n <= 0) return NULL;
	b = (BTNode *)malloc(sizeof(BTNode));			//������������� b
	b->data = *pre;
	for (p = in; p < in + n; p++)							//�������������ҵ����� *pre �ַ���λ�� k
		if (*p == *pre)												//pre ָ������
			break;														//�� in ���ҵ����˳�ѭ��
	k = p - in;															//ȷ��������� in �е�λ��
	b->lchild = CreateBT1(pre + 1, in, k);				//�ݹ鹹��������
	b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);		//�ݹ鹹��������
	return b;
}

BTNode * CreateBT2(char * post, char * in, int n) {
	BTNode * b;
	char r, *p;
	int k;
	if (n <= 0) return NULL;
	r = *(post + n - 1);												//�����ֵ
	b = (BTNode*)malloc(sizeof(BTNode));				//������������� b
	b->data = r;
	for (p = in; p < in + n; p++)								//�� in �в��Ҹ��ڵ�
		if (*p == r) break;
	k = p - in;																//k Ϊ���ڵ��� in �е��±�
	b->lchild = CreateBT2(post, in, k);						//�ݹ鹹��������
	b->rchild = CreateBT2(post + k, p + 1, n - k - 1);		//�ݹ鹹��������
}