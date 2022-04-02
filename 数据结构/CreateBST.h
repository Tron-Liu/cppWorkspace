#pragma once
#include "SearchType.h"
#include "InsertBST.h"

//返回BST树根节点指针
BSTNode *CreateBST(KeyType A[], int n) {		//创建二叉排序树
	BSTNode *bt = NULL;			//初始时 bt 为空树
	int i = 0;
	while (i < n) {
		InsertBST(bt, A[i]);			//将关键字A[i]插入二叉排序树 bt 中
		i++;
	}
	return bt;								//返回建立的二叉排序树的根指针
}