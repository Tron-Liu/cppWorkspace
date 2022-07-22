#pragma once
#include "SearchType.h"

//在二叉排序树bt中插入一个关键字为 k 的结点，若插入成功返回真，否则返回假
bool InsertBST(BSTNode *&bt, KeyType k)
{
	if (bt == NULL)
	{ //原树为空，新插入的结点为根结点
		bt = (BSTNode *)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key) //树中存在相同关键字的结点，返回假
		return false;
	else if (k < bt->key)
		return InsertBST(bt->lchild, k); //插入到左子树中
	else
		return InsertBST(bt->rchild, k); //插入到右子树中
}