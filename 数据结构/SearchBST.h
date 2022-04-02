#pragma once
#include "SearchType.h"

BSTNode *SearchBST(BSTNode *bt, KeyType k) {		//二叉排序树查找
	if (bt == NULL || bt->key == k)			//递归结束条件，当查找失败或者查找成功时，递归结束
		return bt;											//返回 bt 的值
	if (k < bt->key)									//在左子树中递归查找
		return SearchBST(bt->lchild, k);
	else
		return SearchBST(bt->rchild, k);		//在右子树中递归查找
}

/*
	在二叉排序树 bt 中查找关键字为 k 的结点，若查找成功，该函数返回该结点的指针，f返回其双亲结点
	否则，该函数返回 NULL，其调用方法如下：
			SearchBST1( bt, x, NULL, f );
	这里的第三个参数 f1 仅作为中间参数，用于求 f，初始值设为 NULL
*/
/*
	param3：f1：记录当前结点的双亲结点的指针，在查找成功时将该值赋给 f
*/
BSTNode *SearchBST1(BSTNode *bt, KeyType k, BSTNode *f1, BSTNode *&f) {
	if (bt == NULL) {												//查找失败
		f = NULL;														// f 赋值为空
		return(NULL);												//函数返回 NULL
	}
	else if (k == bt->key) {									//查找成功
		f = f1;															// f 值赋为 f1，即当前结点的双亲结点的指针，另外，f 为引用型指针变量，所以不需return
		return(bt);													//返回该结点的指针
	}
	else if (k < bt->key)											//在左子树中递归查找
		return SearchBST1(bt->lchild, k, bt, f);
	else
		return SearchBST1(bt->rchild, k, bt, f);		//在右子树中递归查找
}