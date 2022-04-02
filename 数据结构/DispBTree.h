#pragma once
#include "BTree.h"
void DispBTree(BTNode *b) {
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");												//有孩子结点时才输出 "("
			DispBTree(b->lchild);							//递归处理左子树
			if (b->rchild != NULL) printf(",");			//有右孩子结点时才输出 ","
			DispBTree(b->rchild);							//递归处理右子树
			printf(")");												//有孩子结点时才输出 ")"
		}
	}
}