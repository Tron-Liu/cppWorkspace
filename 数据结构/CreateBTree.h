#pragma once
#include "BTree.h"												//包含二叉树的存储结构声明

void CreateBTree(BTNode *&b, const char *str) {
	BTNode *St[MaxSize], *p;								//St数组作为顺序栈
	int top = -1, k, j = 0;										//top作为栈顶指针
	char ch;
	b = NULL;														//初始时二叉链为空
	ch = str[j];
	while (ch != '\0') {											//循环扫描 str 中的每个字符
		switch (ch) {
		case '(':top++; St[top] = p; k = 1; break;		//开始处理左孩子结点
		case ')':top--; break;										//栈顶结点的子树处理完毕
		case ',':k = 2; break;										//开始处理右孩子节点
		default: p = (BTNode *)malloc(sizeof(BTNode));			//创建一个结点，由 p 指向它
			p->data = ch;											//存放结点值
			p->lchild = p->rchild = NULL;				//左右指针都设置为空
			if (b == NULL)											//若尚未建立根节点
				b = p;													//p所指结点就作为根节点
			else {														//已建立二叉树根节点
				switch (k) {
				case 1: St[top]->lchild = p; break;		//新建结点作为栈顶结点的左孩子
				case 2:St[top]->rchild = p; break;		//新建结点作为栈顶结点的右孩子
				}
			}
		}
		j++;																//继续扫描 str
		ch = str[j];
	}
}