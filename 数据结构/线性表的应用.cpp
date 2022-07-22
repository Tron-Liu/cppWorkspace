#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
#define MaxCol 10 //最大列数

typedef struct Node1 //定义数据结点类型
{
	ElemType data[MaxCol]; //存放一行的数据
	struct Node1 *next;	   //指向后继数据结点
} DList;				   //行结点类型

typedef struct Node2
{
	int Row, Col; //行数和列数
	DList *next;  //指向第一个数据结点
} HList;		  //头结点类型

//采用交互方式建立单链表的算法
void CreateTable(HList *&h)
{
	int i, j;
	DList *r, *s;
	h = (HList *)malloc(sizeof(HList)); //创建头节点
	h->next = NULL;
	printf("表的行数，列数：");
	scanf("%d%d", &h->Row, &h->Col); //输入表的列数和行数
	for (i = 0; i < h->Row; i++)	 //输入所有行的数据
	{
		printf("第%d行：", i + 1);
		s = (DList *)malloc(sizeof(DList)); //创建数据结点s
		for (j = 0; j < h->Col; j++)		//输入一行的数据
			scanf("%d", &s->data[j]);
		if (h->next == NULL) //插入第一个数据结点的情况
			h->next = s;
		else			 //插入其他数据结点的情况
			r->next = s; //将s结点插入到r结点之后
		r = s;			 // r始终指向尾结点
	}
	r->next = NULL; //尾结点的next域置空
}

//销毁单链表的算法
void DestroyTable(HList *&h)
{
	DList *pre = h->next, *p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(h);
}

//输出单链表的算法
void DispTable(HList *h)
{
	int j;
	DList *p = h->next; // p指向开始行结点
	while (p != NULL)	//扫描所有行
	{
		for (j = 0; j < h->Col; j++) //输出一行的数据
			printf("%4d", p->data[j]);
		printf("\n");
		p = p->next; // p指向下一个行结点
	}
}

//表连接运算算法
void LinkTable(HList *h1, HList *h2, HList *&h)
{
	int i, j, k;
	DList *p = h1->next, *q, *s, *r;
	printf("连接字段是：第1个表序号，第2个表序号：");
	scanf("%d%d", &i, &j);
	h = (HList *)malloc(sizeof(HList)); //创建结果表头结点
	h->Row = 0;							//置行数为0
	h->Col = h1->Col + h2->Col;			//置列数为表1和表2的列数和
	h->next = NULL;						//置next域为NULL；
	while (p != NULL)					//扫描表1
	{
		q = h2->next;	  // q指向表2的首结点
		while (q != NULL) //扫描表2
		{
			if (p->data[i - 1] == q->data[j - 1]) //对应字段值相等
			{
				s = (DList *)malloc(sizeof(DList)); //创建一个数据结点s
				for (k = 0; k < h1->Col; k++)		//复制表1的当前行
					s->data[k] = p->data[k];
				for (k = 0; k < h2->Col; k++) //复制表2的当前行
					s->data[h1->Col + k] = q->data[k];
				if (h->next == NULL) //若插入的是第一个数据结点
					h->next = s;	 //将s结点插入到头结点之后
				else				 //若插入其他数据结点
					r->next = s;	 //将s结点插入到结点r之后
				r = s;				 // r始终指向尾结点
				h->Row++;			 //表行数增1
			}
			q = q->next; //表2后移一个结点
		}
		p = p->next; //表1后移一个结点
	}
	r->next = NULL; //表尾结点的next域置空
}

int main()
{
	HList *h1, *h2, *h;
	printf("表1：\n");
	CreateTable(h1);
	printf("表2：\n");
	CreateTable(h2);
	LinkTable(h1, h2, h);
	printf("连接结果表：\n");
	DispTable(h);
	DestroyTable(h1);
	DestroyTable(h2);
	DestroyTable(h);
	system("pause");
	return 1;
}