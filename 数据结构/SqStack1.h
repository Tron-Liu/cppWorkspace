#pragma once
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef double ElemType1;

typedef struct
{
	ElemType1 data[MaxSize];
	int top;
} SqStack1;

//初始化栈
void InitStack1(SqStack1 *&s)
{
	s = (SqStack1 *)malloc(sizeof(SqStack1)); //分配一个顺序栈空间，首地址存放在s中
	s->top = -1;							  //栈顶指针置为-1
}

//销毁栈
void DestroyStack1(SqStack1 *&s)
{
	free(s);
}

//判断栈是否为空
bool StackEmpty1(SqStack1 *s)
{
	return (s->top == -1);
}

//进栈
bool Push1(SqStack1 *&s, ElemType1 e)
{
	if (s->top == MaxSize - 1) //栈满的情况，即上栈上溢
		return false;
	s->top++;			 //栈顶指针增1
	s->data[s->top] = e; //元素e放在栈顶指针处
	return true;
}

//出栈
bool Pop1(SqStack1 *&s, ElemType1 &e)
{
	if (s->top == -1) //栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top]; //取栈顶元素
	s->top--;			 //栈顶指针减1
	return true;
}

//取栈顶元素
bool GetTop1(SqStack1 *s, ElemType1 &e)
{
	if (s->top == -1) //栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top]; //取栈顶元素
	return true;
}

//例3.4  p82
bool symmetry(ElemType1 str[]) //判断str是否为对称串
{
	int i;
	ElemType1 e;
	SqStack1 *st;					 //定义顺序栈指针
	InitStack1(st);					 //初始化
	for (i = 0; str[i] != '\0'; i++) //将str的所有元素进栈
		Push1(st, str[i]);
	for (i = 0; str[i] != '\0'; i++) //处理str的所有字符
	{
		Pop1(st, e);	 //退栈元素e
		if (str[i] != e) //若e与当前串字符不同表示不是对称串
		{
			DestroyStack1(st); //销毁栈
			return false;	   //返回假
		}
	}
	DestroyStack1(st); //销毁栈
	return true;	   //返回真
}