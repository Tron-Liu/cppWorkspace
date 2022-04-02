#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"
#include "SqStack1.h"

void  trans(char *exp, char postexp[])		//将算术表达式exp转换成后缀表达式postexp
{
	char e;
	SqStack *Optr;										//定义运算符栈指针
	InitStack(Optr);									//初始化运算符栈
	int i = 0;												//i作为postexp的下标
	while (* exp!='\0')								//exp表达式未扫描完时循环
	{
		switch (*exp)
		{
		case '(':												//判定为左括号
			Push(Optr, '(');								//左括号进栈
			exp++;											//继续扫描其他元素
			break;
		case ')':												//判定为右括号
			Pop(Optr, e);								//出栈元素e
			while (e != '(')								//不为右括号时循环
			{
				postexp[i++] = e;					//将e存放到postexp中
				Pop(Optr, e);							//继续出栈元素e
			}
			exp++;											//继续扫描其他元素
			break;
		case '+':
		case '-':												//判定为加或减号
			while (!StackEmpty(Optr))			//栈不空时循环
			{
				GetTop(Optr, e);						//取栈顶元素
				if (e != '(')									//e不是右括号
				{
					postexp[i++] = e;				//将e存放到postexp中
					Pop(Optr, e);						//出栈元素
				}
				else											//是右括号时退出循环
					break;
			}
			Push(Optr, *exp);							//将'+'或'-'进栈
			exp++;											//继续扫描其他字符
			break;
		case '*':
		case '/':												//判断为'*'或'/'号
			while (!StackEmpty(Optr))			//栈不空时循环
			{
				GetTop(Optr, e);						//取栈顶元素
				if (e == '*' || e == '/')				//将栈顶元素'*'或'/'运算符出栈并存放到postexp中
				{
					postexp[i++] = e;				//将e存放到postexp中
					Pop(Optr, e);						//出栈e元素
				}
				else											//e为非'*'或'/'运算符时退出循环
					break;
			}
			Push(Optr, *exp);							//将'*'或'/'进栈
			exp++;											//继续扫描其他元素
			break;
		default:											//处理数字字符
			while (*exp>='0'&&*exp<='9')	//判断为数字字符
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';						//用#标识一个数字串结束
		}
	}
	while (!StackEmpty(Optr))					//此时exp扫描完毕，栈不空时循环
	{
		Pop(Optr, e);									//出栈元素e
		postexp[i++] = e;							//将e存放到postexp中
	}
	postexp[i] = '\0';									//给postexp表达式添加结束标识
	DestroyStack(Optr);								//销毁栈
}

double compavalue(char *postexp)		//计算后缀表达式的值
{
	double d, a, b, c, e;
	SqStack1 *Opnd;									//定义操作数栈
	InitStack1(Opnd);									//初始化操作数栈
	while (*postexp != '\0')						//postexp字符串未扫描完毕
	{
		switch (*postexp)
		{
		case '+':											//判定为'+'号
			Pop1(Opnd, a);							//出栈元素a
			Pop1(Opnd, b);							//出栈元素b
			c = b + a;										//计算c
			Push1(Opnd, c);							//将计算结果c进栈
			break;
		case '-':												//判断为'-'号
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			c = b - a;
			Push1(Opnd, c);
			break;
		case '*':											//判断为'*'号
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			c = b * a;
			Push1(Opnd, c);
			break;
		case '/':												//判断为'/'号
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			if (a != 0)
			{
				c = b / a;
				Push1(Opnd, c);
				break;
			}
			else
			{
				printf("\n\t除零错误！\n");
				exit(0);										//异常退出
			}
			break;
		default:											//处理数字字符
			d = 0;											//将连续的数字字符转换成对应的数值存放到d中
			while (*postexp>='0' && *postexp<='9')		//判定为数字字符
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			Push1(Opnd, d);							//将数值d进栈
			break;
		}
		postexp++;										//继续处理其他字符
	}
	GetTop1(Opnd, e);								//取栈顶元素e
	DestroyStack1(Opnd);							//销毁栈
	return e;												//返回e
}

int main()
{
	char exp[] = "(56-20)/(4+2)";									//可将exp改为键盘输入
	char postexp[MaxSize];
	trans(exp, postexp);													//将exp转换为postexp
	printf("中缀表达式:%s\n", exp);									//输出exp
	printf("后缀表达式:%s\n", postexp);							//输出postexp
	printf("表达式的值:%g\n", compavalue(postexp));	//求postexp的值并输出
	system("pause");
	return 1;
}