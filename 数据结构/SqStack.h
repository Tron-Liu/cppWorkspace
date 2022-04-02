#pragma once
/*
ADT Stack
{
	数据对象：
		D = {a[i] | 1<=i<=n, n>=0, a[i]为ElemType类型}
	数据关系:
		R = {<a[i], a[i+1]> | a[i]、a[i + 1]属于D，i=1，... , n-1}
	基本运算:
		InitStack(&s):初始化栈，构造一个空栈s。
		DestroyStack(&s):销毁栈，释放栈s占用的内存空间。
		StackEmpty(s):判断栈是否为空，若栈为空，则返回真，否则返回假。
		Push(&s, e):进栈，将元素e插入到栈s中作为栈顶元素。
		Pop(&s, &e):出栈，从栈s中删除栈顶元素，并将其值赋给e。
		GetTop(s, &e):取栈顶元素，返会当前的栈顶元素，并将其赋给e。
}
*/

#include <stdio.h>
#include <malloc.h>
#include <typeinfo>
#define MaxSize 50
typedef char ElemType;

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
