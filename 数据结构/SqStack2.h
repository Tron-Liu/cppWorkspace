#pragma once
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50

typedef struct
{
	int i;	//当前方块的行号
	int j;	//当前方块的列号
	int di; // di是下一相邻可走方位的方位号
} Box;		//方块类型

typedef struct
{
	Box data[MaxSize];
	int top; //栈顶指针
} StType;	 //顺序栈类型

typedef Box ElemType2;

//初始化栈
void InitStack(StType *&s)
{
	s = (StType *)malloc(sizeof(StType)); //分配一个顺序栈空间，首地址存放在s中
	s->top = -1;						  //栈顶指针置为-1
}

//销毁栈
void DestroyStack(StType *&s)
{
	free(s);
}

//判断栈是否为空
bool StackEmpty(StType *s)
{
	return (s->top == -1);
}

//进栈
bool Push(StType *&s, ElemType2 e)
{
	if (s->top == MaxSize - 1) //栈满的情况，即上栈上溢
		return false;
	s->top++;			 //栈顶指针增1
	s->data[s->top] = e; //元素e放在栈顶指针处
	return true;
}

//出栈
bool Pop(StType *&s, ElemType2 &e)
{
	if (s->top == -1) //栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top]; //取栈顶元素
	s->top--;			 //栈顶指针减1
	return true;
}

//取栈顶元素
bool GetTop(StType *s, ElemType2 &e)
{
	if (s->top == -1) //栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top]; //取栈顶元素
	return true;
}
