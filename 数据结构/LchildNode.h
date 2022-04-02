#pragma once
#include "BTree.h"

BTNode *LchildNode(BTNode *p) {			//返回结点 p的左孩子结点
	return p->lchild;
}

BTNode *RchildNode(BTNode *p) {		//返回结点 p的右孩子结点
	return p->rchild;
}