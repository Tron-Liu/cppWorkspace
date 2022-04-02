#pragma once
#include <stdio.h>
#include <malloc.h>
#include <typeinfo>
#include "BTree.h"
#define MaxSize 50
typedef BTNode * ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizeof(SqStack));  //分配一个顺序栈空间，首地址存放在s中
	s->top = -1;												//栈顶指针置为-1
}

//销毁栈
void DestroyStack(SqStack *&s)
{
	free(s);
}

//判断栈是否为空
bool StackEmpty(SqStack *s)
{
	return (s->top == -1);
}

//进栈
bool Push(SqStack *&s, ElemType e)
{
	if (s->top == MaxSize - 1)				//栈满的情况，即上栈上溢
		return false;
	s->top++;										//栈顶指针增1
	s->data[s->top] = e;						//元素e放在栈顶指针处
	return true;
}

//出栈
bool Pop(SqStack *&s, ElemType &e)
{
	if (s->top == -1)									//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];							//取栈顶元素
	s->top--;												//栈顶指针减1
	return true;
}

//取栈顶元素
bool GetTop(SqStack *s, ElemType &e)
{
	if (s->top == -1)									//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];							//取栈顶元素
	return true;
}

//例3.4  p82
bool symmetry(ElemType str[])		//判断str是否为对称串
{
	int i;
	ElemType e;
	SqStack *st;									//定义顺序栈指针
	InitStack(st);									//初始化
	for (i = 0; str[i] != '\0'; i++)			//将str的所有元素进栈
		Push(st, str[i]);
	for (i = 0; str[i] != '\0'; i++)			//处理str的所有字符
	{
		Pop(st, e);									//退栈元素e
		if (str[i] != e)								//若e与当前串字符不同表示不是对称串
		{
			DestroyStack(st);					//销毁栈
			return false;							//返回假
		}
	}
	DestroyStack(st);							//销毁栈
	return true;									//返回真
}

//例7.17 假设二叉树采用二叉链存储结构，设计一个算法输出从根结点到每个叶子结点的路径
//				逆序列，要求采用后序遍历非递归算法实现
void AllPath1(BTNode * b) {
	BTNode *p, *r;
	bool flag;
	SqStack *st;													//定义一个顺序栈指针
	InitStack(st);													//初始化栈 st
	p = b;
	do {
		while (p != NULL) {									//扫描 p 的所有左下结点并进栈
			Push(st, p);											//结点 p 进栈
			p = p->lchild;										//p 移动到左孩子
		}
		r = NULL;													//r 指向刚访问的结点，初始时为空
		flag = true;												//flag 为真表示正在处理栈顶结点
		while (!StackEmpty(st) && flag) {
			GetTop(st, p);										//取出当前的栈顶结点 p
			if (p->rchild == r) {								//若结点 p 的左孩子为空或者为刚访问的结点
				if (p->lchild == NULL && p->rchild == NULL) {			//若为叶子结点
					for (int i = st->top; i > 0; i--)		//输出栈中的所有结点值
						printf("%c->", st->data[i]->data);
					printf("%c\n", st->data[0]->data);
				}
				Pop(st, p);
				r = p;												//r 指向刚访问过的结点
			}
			else {
				p = p->rchild;									//转向处理其他结点
				flag = false;										//表示当前不是处理栈顶结点
			}
		}
	} while (!StackEmpty(st));								//栈不空循环
}