#pragma once
#include "BTree.h"

BTNode *FindNode(BTNode *b, ElemType x) {
	BTNode *p;
	if (b == NULL) return NULL;
	else if (b->data == x)
		return b;
	else {
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}
