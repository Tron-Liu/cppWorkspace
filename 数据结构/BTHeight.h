#pragma once
#include "BTree.h"
int BTHeight(BTNode *b) {
	int lchildh, rchildh;
	if (b == NULL) return 0;						//�����ĸ߶�Ϊ 0
	else {
		lchildh = BTHeight(b->lchild);			//���������ĸ߶�Ϊ lchildh
		rchildh = BTHeight(b->rchild);		//���������ĸ߶�Ϊ rchildh
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}