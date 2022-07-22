#pragma once
#include "BTree.h"
#include "tree_SqStack.h"

void PreOrder(BTNode *b)
{ //先序遍历递归算法
	if (b != NULL)
	{
		printf("%c", b->data); //访问根节点
		PreOrder(b->lchild);   //先序遍历左子树
		PreOrder(b->rchild);   //先序遍历右子树
	}
}

void PreOrder1(BTNode *b) //先序非递归遍历算法 1
{
	BTNode *p;
	SqStack *st;   //定义栈指针 st
	InitStack(st); //初始化栈 st
	if (b != NULL)
	{
		Push(st, b); //根结点进栈
		while (!StackEmpty(st))
		{				//栈不空时循环
			Pop(st, p); //退栈结点 p 并访问它
			printf("%c", p->data);
			if (p->rchild != NULL) //有右孩子时将其进栈
				Push(st, p->rchild);
			if (p->lchild != NULL) //有左孩子时将其进栈
				Push(st, p->lchild);
		}
		printf("\n");
	}
	DestroyStack(st); //销毁栈
}

void PreOrder2(BTNode *b)
{ //先序遍历非递归算法 2
	BTNode *p;
	SqStack *st;   //定义一个顺序栈指针 st
	InitStack(st); //初始化栈 st
	p = b;
	while (!StackEmpty(st) || p != NULL)
	{
		while (p != NULL)
		{						   //访问结点 p 及其左下结点并进栈
			printf("%c", p->data); //访问结点 p
			Push(st, p);		   //结点 p 进栈
			p = p->lchild;		   //移动到左孩子
		}
		if (!StackEmpty(st))
		{				   //若栈不空
			Pop(st, p);	   //除栈结点 p
			p = p->rchild; //转向处理其右子树
		}
	}
	printf("\n");
	DestroyStack(st); //销毁栈
}