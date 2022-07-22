#include <iostream>
typedef char ElemType;

typedef struct lnode
{
	int tag; //结点类型标识
	union
	{
		ElemType data;		   //存放原子值
		struct lnode *sublist; //指向子表的指针
	} val;
	struct lnode *link; //指向下一个元素
} GLNode;				//广义表的结点类型

//广义表的算法设计方法1
//方法1先处理一个元素，再处理后继元素
void fun1(GLNode *g)
{								 // g为广义表头结点
	GLNode *g1 = g->val.sublist; // g1指向第一个元素
	while (g1 != NULL)
	{					  //元素未处理完时循环
		if (g1->tag == 1) //为子表时
			fun1(g1);	  //递归处理子表
		else
			//原子处理语句;						//实现原子操作
			g1 = g1->link; //处理兄弟
	}
}

//广义表的算法设计方法2
//方法2先处理data/sublist域，即元素部分；再处理link域，即兄弟部分
void fun2(GLNode *g)
{ // g为广义表结点指针
	if (g != NULL)
	{
		if (g->tag == 1)		  //为子表时
			fun2(g->val.sublist); //递归处理其元素
		else					  //为原子时
								  //原子处理语句;				//实现原子操作
			fun2(g->link);		  //递归处理其兄弟
	}
}

//求广义表的长度
int GLLength(GLNode *g)
{			   //求广义表g的长度
	int n = 0; //累计元素个数，初始值为0
	GLNode *g1;
	g1 = g->val.sublist; // g1指向广义表的第一个元素
	while (g1 != NULL)
	{		 //扫描所有元素结点
		n++; //元素个数增1
		g1 = g1->link;
	}
	return n; //返回元素个数
}

//求广义表的深度
int GLDepth(GLNode *g)
{
	GLNode *g1;
	int maxed = 0, dep;
	if (g->tag == 0) //为原子时返回0
		return 0;
	g1 = g->val.sublist; // g1指向第一个元素
	if (g1 == NULL)		 //为空表时返回1
		return 1;
	while (g1 != NULL)
	{ //遍历表中的每一个元素
		if (g1->tag == 1)
		{					   //元素为子表的情况
			dep = GLDepth(g1); //递归调用求出子表的深度
			if (dep > maxed)   // maxed为同一层的子表中深度的最大值
				maxed = dep;
		}
		g1 = g1->link; //使g1指向下一个元素
	}
	return maxed + 1; //返回表的深度
}

//输出广义表
void DispGL(GLNode *g)
{
	if (g != NULL)
	{								   //表不为空判断
		if (g->tag == 0)			   // g的元素为原子时
			printf("%c", g->val.data); //输出原子值
		else
		{								// g的元素为子表时
			printf("(");				//输出  ' ( '
			if (g->val.sublist == NULL) //为空表时
				printf("#");
			else						//为非空表时
				DispGL(g->val.sublist); //递归输出子表
			printf(")");				//输出  ' ) '
		}
		if (g->link != NULL)
		{
			printf(",");
			DispGL(g->link); //递归输出g的兄弟
		}
	}
}