#pragma once
#include "BTree.h"
void DispBTree(BTNode *b) {
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");												//�к��ӽ��ʱ����� "("
			DispBTree(b->lchild);							//�ݹ鴦��������
			if (b->rchild != NULL) printf(",");			//���Һ��ӽ��ʱ����� ","
			DispBTree(b->rchild);							//�ݹ鴦��������
			printf(")");												//�к��ӽ��ʱ����� ")"
		}
	}
}