#pragma once
#include <iostream>
#define MaxSize 100
typedef char ElemType;

//二叉树的顺序存储结构
typedef ElemType SqBinTree[MaxSize];

//二叉树的链式存储结构
typedef struct node
{
	ElemType data;		 //数据元素
	struct node *lchild; //指向左孩子结点
	struct node *rchild; //指向右孩子结点
} BTNode;