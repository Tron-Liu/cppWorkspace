#pragma once
#include <iostream>
typedef char ElemType;

#define MaxSize 100
typedef struct {
	ElemType data;				//��Ž���ֵ
	int parent;						//���˫�׵�λ��
}PTree[MaxSize];					//PTreeΪ˫�״洢�ṹ����

#define MaxSons 10
typedef struct node{
	ElemType data;							//����ֵ
	struct node *sons[MaxSons];		//ָ���ӽ��
}TSonNode;										//�������洢�ṹ�еĽ������

typedef struct tnode {
	ElemType data;				//����ֵ
	struct tnode *hp;				//ָ���ֵ�
	struct tnode *vp;				//ָ���ӽ��
}TSBNode;							//�����ֵ����洢�ṹ�еĽ������