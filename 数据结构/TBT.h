#pragma once
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;

typedef struct node {
	ElemType data;				//结点数据域
	int ltag, rtag;					//增加的线索标记
	struct node * lchild;			//左孩子或线索指针
	struct node * rchild;			//右孩子或线索指针
}TBTNode;							//线索二叉树的结点类型

/*
	ltag=0:  表示 lchild 指向左孩子结点
	ltag=1:  表示 lchild 指向前驱结点
	rtag=0:	  表示 rchild 指向右孩子结点
	rtag=1:	  表示 rchild 指向后继结点
*/

//在整个算法中 p 总是指向当前被线索化的结点，而 pre 作为全局变量，指向刚访问过的结点
//结点 pre 是结点 p 的前驱结点，结点 p 是结点 pre 的前驱结点

TBTNode *pre;									//全局变量
void Thread(TBTNode *&p) {			//对二叉树 p 进行中序线索化
	if (p != NULL) {
		Thread(p->lchild);					//左子树线索化
		if (p->lchild == NULL) {			//左子树不存在，进行前驱结点线索化
			p->lchild = pre;					//建立当前结点的前驱结点线索
			p->ltag = 1;
		}
		else p->ltag = 0;						//p 结点的左子树已线索化
		if (pre->rchild == NULL) {		//对 pre 的后继结点线索化
			p->rchild = p;						//建立前驱结点的后继结点线索
			pre->rtag = 1;
		}
		else p->rtag = 0;
		pre = p;
		Thread(p->rchild);					//右子树线索化
	}
}

TBTNode * CreateThread(TBTNode *b) {						//中序线索化二叉树
	TBTNode *root;
	root = (TBTNode *)malloc(sizeof(TBTNode));			//创建头结点
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = b;
	if (b == NULL)															//空二叉树
		root->lchild = root;
	else {
		root->lchild = b;
		pre = root;								//pre 是结点 p 的前驱结点，供加线索用
		Thread(b);								//中序遍历线索化二叉树
		pre->rchild = root;					//最后处理，加入指向头结点的线索
		pre->rtag = 1;
		root->rchild = pre;					//头结点右线索化
	}
	return root;
}

//遍历线索化二叉树
void ThInOrder(TBTNode * tb) {
	TBTNode *p = tb->lchild;									//p 指向根结点
	while (p != tb) {
		while (p->ltag == 0) p = p->lchild;					//找开始结点
		printf("%c", p->data);										//访问开始结点
		while (p->rtag == 1 && p->rchild != tb) {
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
}