#pragma once
#include <iostream>
#define MaxSize 100
typedef char ElemType;

//��������˳��洢�ṹ
typedef ElemType SqBinTree[MaxSize];

//����������ʽ�洢�ṹ
typedef struct node {
	ElemType data;			//����Ԫ��
	struct node *lchild;		//ָ�����ӽ��
	struct node *rchild;		//ָ���Һ��ӽ��
}BTNode;