#pragma once
#include "BTree.h"

BTNode *LchildNode(BTNode *p) {			//���ؽ�� p�����ӽ��
	return p->lchild;
}

BTNode *RchildNode(BTNode *p) {		//���ؽ�� p���Һ��ӽ��
	return p->rchild;
}