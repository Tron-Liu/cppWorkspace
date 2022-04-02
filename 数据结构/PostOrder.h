#pragma once
#include "BTree.h"
#include "tree_SqStack.h"

void PostOrder(BTNode *b) {		//后序遍历递归算法
	if (b != NULL) {
		PostOrder(b->lchild);			//后序遍历左子树
		PostOrder(b->rchild);			//后序遍历右子树
		printf("%c", b->data);			//访问根节点
	}
}

void PostOrder1(BTNode * b) {		//后序遍历非递归算法
	BTNode *p, *r;
	bool flag;
	SqStack * st;									//定义一个顺序栈指针 st
	InitStack(st);									//初始化 st
	p = b;
	do {
		while (p != NULL) {					//扫描结点 p 的所有左下结点并进栈
			Push(st, p);							//结点 p 进栈
			p = p->lchild;						//移动到左孩子
		}
		r = NULL;									//r 指向刚访问的结点，初始时为空
		flag = true;								//flag 为真时表示正在处理栈顶结点 
		while (!StackEmpty(st) && flag) {
			GetTop(st, p);						//取出当前的栈顶结点 p
			if (p->rchild == r) {				//若结点 p 的右孩子为空或者为刚刚访问过的结点
				printf("%c", p->data);		//访问结点 p
				Pop(st, p);
				r = p;								// r 指向刚访问过的结点
			}
			else {
				p = p->rchild;					//转向处理其右子树
				flag = false;						//表示当前不是处理栈顶结点
			}
		}
	} while (!StackEmpty(st));				//栈不空循环
	printf("\n");
	DestroyStack(st);							//销毁栈
}