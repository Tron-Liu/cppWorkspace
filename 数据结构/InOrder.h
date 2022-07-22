#pragma once
#include "BTree.h"
#include "tree_SqStack.h"

void InOrder(BTNode *b)
{ //中序遍历递归算法
	if (b != NULL)
	{
		InOrder(b->lchild);	   //中序遍历左子树
		printf("%c", b->data); //访问根结点
		InOrder(b->rchild);	   //中序遍历右子树
	}
}

void InOrder1(BTNode *b)
{ //中序遍历非递归算法
	BTNode *p;
	SqStack *st;   //定义一个顺序栈指针 st
	InitStack(st); //初始化栈 st
	p = b;
	while (!StackEmpty(st) || p != NULL)
	{
		while (p != NULL)
		{				   //扫描结点 p 的所有左下结点并进栈
			Push(st, p);   //结点 p 进栈
			p = p->lchild; //移动到左孩子
		}
		if (!StackEmpty(st))
		{						   //若栈不空
			Pop(st, p);			   //出栈结点 p
			printf("%c", p->data); //访问结点 p
			p = p->rchild;		   //转向处理其右子树
		}
	}
	printf("\n");
	DestroyStack(st); //销毁栈
}