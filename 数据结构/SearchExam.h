#pragma once
#include "SearchType.h"

//��9.4 �ҳ�������������������������С���
void maxminnode(BSTNode *p) {
	if (p != NULL) {
		if (p->lchild != NULL)
			printf("�������������Ϊ��%d\n", maxnode(p->lchild));
		if (p->rchild != NULL)
			printf("�������������Ϊ��%d\n", maxnode(p->lchild));
	}
}

KeyType maxnode(BSTNode *p) {		//����һ�ö����������������ؼ���
	while (p->rchild != NULL)
		p = p->rchild;
	return (p->data);
}

KeyType minnode(BSTNode *p) {		//����һ�ö�������������С���ؼ���
	while (p->lchild != NULL)
		p = p->lchild;
	return (p->data);
}