#pragma once
#include <malloc.h>
#include <stdio.h>

typedef struct snode
{
	char data;			//存放字符
	struct snode *next; //指向下一个结点指针
} LinkStrNode;			//链串的结点类型

//生成串
void StrAssign(LinkStrNode *&s, char cstr[])
{
	int i;
	LinkStrNode *r, *p;
	s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	r = s; // r始终指向尾结点
	for (i = 0; cstr[i] != '/0'; i++)
	{
		p = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		p->data = cstr[i];
		r->next = p;
		r = p;
	}
	r->next = NULL; //尾结点的next域置为空
}

//销毁串
void DestroyStr(LinkStrNode *&s)
{
	LinkStrNode *pre = s, *p = s->next; // pre指向结点p的前驱结点
	while (p != NULL)
	{			   //扫描链串
		free(pre); //释放pre结点
		pre = p;   // pre，p同步后移一个结点
		p = pre->next;
	}
	free(pre); //循环结束时p为NULL，pre指向尾结点，释放它
}

//串的复制
void StrCopy(LinkStrNode *&s, LinkStrNode *t)
{
	LinkStrNode *p = t->next, *q, *r;
	s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	r = s; // r始终指向尾结点
	while (p != NULL)
	{ //扫描链串t的所有结点
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data; //将p结点复制到q结点
		r->next = q;	   //将q结点链接到链串s的末尾
		r = q;
		p = p->next;
	}
	r->next = NULL; //尾结点的next域置为空
}

//判断串相等
bool StrEqual(LinkStrNode *s, LinkStrNode *t)
{
	LinkStrNode *p = s->next, *q = t->next; // p,q分别扫描链串s和t的数据结点
	while (p != NULL && q != NULL && p->data == q->data)
	{
		p = p->next;
		q = q->next;
	}
	if (p == NULL && q == NULL) // s和t的长度相等且对应位置的字符均相等
		return true;
	else
		return false;
}

//求串长
int StrLength(LinkStrNode *s)
{
	int i = 0;				  // i用于累计数据结点的个数
	LinkStrNode *p = s->next; // p指向链串s的首结点
	while (p != NULL)
	{ //扫描所有数据结点
		i++;
		p = p->next;
	}
	return i;
}

//串的连接
LinkStrNode *Concat(LinkStrNode *s, LinkStrNode *t)
{
	LinkStrNode *str, *p = s->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	r = str; // r指向结果串的尾结点
	while (p != NULL)
	{ // p用于扫描s的所有数据结点
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data; //将p结点复制到q结点中
		r->next = q;	   //将q结点链接到str的末尾
		r = q;
		p = p->next;
	}
	p = t->next;
	while (p != NULL)
	{ // p用于扫描t的所有数据结点
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data; //将p结点复制到q结点中
		r->next = q;	   //将q结点链接到str的末尾
		r = q;
		p = p->next;
	}
	r->next = NULL; //尾结点的next域置为空
	return str;		//返回结果串
}

//求子串
LinkStrNode *SubStr(LinkStrNode *s, int i, int j)
{
	int k;
	LinkStrNode *str, *p = s->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next = NULL; //置结果串str为空串
	r = str;		  // r指向str的尾结点
	if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s))
		return str;			//参数不正确时返回空串
	for (k = 1; k < i; k++) // p指向链串s的第i个数据结点
		p = p->next;
	for (k = 1; k <= j; k++)
	{ //将s的从第i个结点开始的j个结点复制到str
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL; //尾结点的next域置空
	return str;
}

//子串的插入
LinkStrNode *InsStr(LinkStrNode *s, int i, LinkStrNode *t)
{
	int k;
	LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next = NULL;					  //置结果串str为空串
	r = str;							  // r指向str的尾结点
	if (i <= 0 || i > (StrLength(s) + 1)) //参数不正确时返回空串
		return str;
	for (k = 1; k < i; k++)
	{ //将s的前i个结点复制到结果串str中
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	while (p1 != NULL)
	{ //将t的所有结点复制到str中
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p1->data;
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	while (p != NULL)
	{ //将s中剩下的结点复制到str中
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL; //尾结点的next域置为空
	return str;
}

//子串的删除
LinkStrNode *DelStr(LinkStrNode *s, int i, int j)
{
	int k;
	LinkStrNode *str, *p = s->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next = NULL; //置结果串str为空串
	r = str;		  // r指向结果串的尾结点
	if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s))
		return str; //参数错误返回空串
	for (k = 1; k < i - 1; k++)
	{ //将s的前i-1个结点复制到str
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++) //让p沿next跳j个结点
		p = p->next;
	while (p != NULL)
	{ //将p结点及其后的结点复制到str中
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL; //尾结点的next域置空
	return str;
}

//子串的替代
LinkStrNode *RepStr(LinkStrNode *s, int i, int j, LinkStrNode *t)
{
	int k;
	LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
	str = (LinkStrNode *)malloc(sizeof(LinkStrNode));
	str->next = NULL; //设置str为空串
	r = str;		  // r指向结果串str的尾结点
	if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s))
		return str; //参数不正确时返回空串
	for (k = 0; k < i - 1; i++)
	{ //将s的前i-1个数据结点复制到str
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++) //让p沿next跳j个结点
		p = p->next;
	while (p1 != NULL)
	{ //将t的所有结点复制到str中
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p1->data;
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	while (p != NULL)
	{ //将s中剩下的结点复制到str中
		q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL; //尾结点的next域置为空
	return str;
}

//输出串
void DisStr(LinkStrNode *s)
{
	LinkStrNode *p = s->next; // p指向s的首结点
	while (p != NULL)
	{						   //用p扫描链串s的所有数据结点
		printf("%c", p->data); //输出p结点值
		p = p->next;
	}
	printf("\n");
}