#pragma once
#include "BTree.h"

/*
	pre 存放先序序列，in 存放中序序列，n为二叉树的结点个数
	本算法执行后返回构造的二叉链的根节点指针 b
*/
BTNode *CreateBT1(char *pre, char *in, int n)
{
	BTNode *b;
	char *p;
	int k;
	if (n <= 0)
		return NULL;
	b = (BTNode *)malloc(sizeof(BTNode)); //创建二叉树结点 b
	b->data = *pre;
	for (p = in; p < in + n; p++)						  //在中序序列中找到等于 *pre 字符的位置 k
		if (*p == *pre)									  // pre 指向根结点
			break;										  //在 in 中找到后退出循环
	k = p - in;											  //确定根结点在 in 中的位置
	b->lchild = CreateBT1(pre + 1, in, k);				  //递归构造左子树
	b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1); //递归构造右子树
	return b;
}

BTNode *CreateBT2(char *post, char *in, int n)
{
	BTNode *b;
	char r, *p;
	int k;
	if (n <= 0)
		return NULL;
	r = *(post + n - 1);				  //根结点值
	b = (BTNode *)malloc(sizeof(BTNode)); //创建二叉树结点 b
	b->data = r;
	for (p = in; p < in + n; p++) //在 in 中查找根节点
		if (*p == r)
			break;
	k = p - in;										   // k 为根节点在 in 中的下标
	b->lchild = CreateBT2(post, in, k);				   //递归构造左子树
	b->rchild = CreateBT2(post + k, p + 1, n - k - 1); //递归构造右子树
}