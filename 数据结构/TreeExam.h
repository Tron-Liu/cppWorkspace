#pragma once
#include "tree.h"
#include "BTree.h"

//例7.3 以孩子链作为树的存储结构，设计一个求树 t 高度的递归算法
int TreeHeight1(TSonNode *t)
{
	TSonNode *p;
	int i, h, maxh = 0;
	if (t == NULL)
		return 0; //空树返回高度 0
	else
	{ //处理非空树
		for (i = 0; i < MaxSons; i++)
		{
			p = t->sons[i]; // p 指向 t 的第 i+1 个孩子结点
			if (p != NULL)
			{						//若存在第 i+1 个孩子
				h = TreeHeight1(p); //求除对应子树的高度
				if (maxh < h)
					maxh = h; //求所有子树的最大高度
			}
		}
		return (maxh + 1); //返回 maxh+1
	}
}

//例7.4 以孩子兄弟链作为树的存储结构，设计一个求树 t 高度的递归算法
int TreeHeight2(TSBNode *t)
{
	TSBNode *p;
	int h, maxh = 0;
	if (t == NULL)
		return 0; //空树返回 0
	else
	{
		p = t->vp; // p指向第一个孩子结点
		while (p != NULL)
		{						//扫描 t 的所有子树
			h = TreeHeight2(p); //求出 p 子树的高度
			if (maxh < h)
				maxh = h; //求所有子树的最大高度
			p = p->hp;	  //继续处理 t 的其他子树
		}
		return (maxh + 1); //返回 maxh+1
	}
}

//例 7.11 二叉树采用二叉链存储结构，计算一颗给定二叉树的所有结点的个数
int Nodes(BTNode *b)
{
	int num1, num2;
	if (b == NULL)
		return 0;
	else
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;
}

//例 7.12 假设二叉树采用二叉链存储结构，输出一颗给定二叉树的所有叶子结点
void DispLeaf(BTNode *b)
{
	if (b != NULL)
	{
		if (b->lchild != NULL && b->rchild != NULL)
			printf("%c", b->data); //访问叶子结点
		DispLeaf(b->lchild);	   //输出左子树中的叶子结点
		DispLeaf(b->rchild);	   //输出右子树中的叶子结点
	}
}

//例 7.14 假设二叉树采用二叉链存储结构，设计一个算法求二叉树 b 中第 k 层的结点个数
void Lnodenum(BTNode *b, int h, int k, int &n)
{
	if (b == NULL) //空树直接返回
		return;
	else
	{ //处理非空树
		if (h == k)
			n++; //当前访问的结点在第 k 层时 n 增 1
		else if (h < k)
		{ //若当前结点层次小于 k，递归处理左、右子树
			Lnodenum(b->lchild, h + 1, k, n);
			Lnodenum(b->rchild, h + 1, k, n);
		}
	}
}

//例 7.15 假设二叉树采用二叉链存储结构，设计一个算法判断两颗二叉树是否相似
bool Like(BTNode *b1, BTNode *b2)
{ // b1 和 b2 两颗二叉树相似时返回 true，否则返回 false
	bool like1, like2;
	if (b1 == NULL && b2 == NULL)
		return true;
	else if (b1 == NULL || b2 == NULL)
		return false;
	else
	{
		like1 = Like(b1->lchild, b2->lchild);
		like2 = Like(b1->rchild, b2->rchild);
		return (like1 && like2); //返回 like1 和 like2 的运算结果
	}
}

//例 7.16 假设二叉树采用二叉链存储结构，设计一个算法输出值为 x 的结点的所有祖先
bool ancestor(BTNode *b, ElemType x)
{
	if (b == NULL)
		return false;
	else if (b->lchild != NULL && b->lchild->data == x || b->rchild != NULL && b->rchild->data == x)
	{
		printf("%c", b->data);
		return true;
	}
	else if (ancestor(b->lchild, x) || ancestor(b->rchild, x))
	{
		printf("%c", b->data);
		return true;
	}
	else
		return false;
}

//例 7.19 将二叉树的顺序存储结构转换成二叉链存储结构
BTNode *trans(SqBinTree a, int i)
{
	BTNode *b;
	if (i > MaxSize)
		return NULL;
	if (a[i] == '#')
		return NULL;					  //空结点返回 NULL
	b = (BTNode *)malloc(sizeof(BTNode)); //创建根结点 b
	b->data = a[i];
	b->lchild = trans(a, 2 * i);	 //递归创建左子树
	b->rchild = trans(a, 2 * i + 1); //递归创建右子树
	return b;
}