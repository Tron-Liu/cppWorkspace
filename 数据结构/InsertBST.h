#pragma once
#include "SearchType.h"

//�ڶ���������bt�в���һ���ؼ���Ϊ k �Ľ�㣬������ɹ������棬���򷵻ؼ�
bool InsertBST(BSTNode *&bt, KeyType k) {
	if (bt == NULL) {														//ԭ��Ϊ�գ��²���Ľ��Ϊ�����
		bt = (BSTNode *)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key)							//���д�����ͬ�ؼ��ֵĽ�㣬���ؼ�
		return false;
	else if (k < bt->key)
		return InsertBST(bt->lchild, k);		//���뵽��������
	else
		return InsertBST(bt->rchild, k);		//���뵽��������
}