#pragma once
#include "BTree.h"
int BTHeight(BTNode *b) {
	int lchildh, rchildh;
	if (b == NULL) return 0;						//空树的高度为 0
	else {
		lchildh = BTHeight(b->lchild);			//求左子树的高度为 lchildh
		rchildh = BTHeight(b->rchild);		//求右子树的高度为 rchildh
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}