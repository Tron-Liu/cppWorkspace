#pragma once
#include <stdio.h>
#include <malloc.h>
#include "BTree.h"
#define MaxSize 10

typedef struct snode {
	BTNode * pt;					//存放当前结点指针
	int parent;						//存放双亲结点在队列中的位置
}NodeType;							//非环形队列元素类型

typedef  NodeType ElemType;

typedef struct {
	ElemType data[MaxSize];		//存放队列元素
	int front, rear;						//队头指针和队尾指针
}QuType;									//顺序队类型

//初始化队列
void InitQueue(QuType *&q)
{
	q = (QuType *)malloc(sizeof(QuType));
	q->front = q->rear = -1;
}

//销毁队列
void DestroyQueue(QuType *&q)
{
	free(q);
}

//判断队列是否为空
bool QueueEmpty(QuType *q)
{
	return(q->front == q->rear);
}

//进队列
bool enQueue(QuType *&q, ElemType e)
{
	if (q->rear == MaxSize - 1)			//队满上溢出
		return false;								//返回假
	q->rear++;									//队尾增1
	q->data[q->rear] = e;					//rear位置插入元素e
	return true;									//返回真
}

//出队列
bool deQueue(QuType *&q, ElemType &e)
{
	if (q->front == q->rear)				//队空下溢出
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

//例7.18 采用层次遍历方法设计 例7.17 的算法
void AllPath2(BTNode * b) {
	int k;
	BTNode *p;
	NodeType qelem;
	QuType *qu;											//定义非环形队列指针
	InitQueue(qu);											//初始化队列
	qelem.pt = b; qelem.parent = -1;			//创建根节点对应的队列元素
	enQueue(qu, qelem);								//根结点进队
	while (!QueueEmpty(qu)) {						//队不空循环
		deQueue(qu, qelem);							//出队元素qelem，它在队中的下标为 qu->front
		p = qelem.pt;										//取元素 qelem 对应的结点
		if (p->lchild == NULL && p->rchild == NULL) {		//结点 p 为叶子结点
			k = qu->front;									//输出结点 p 到根节点的路径的逆序列
			while (qu->data[k].parent != -1) {
				printf("%c->", qu->data[k].pt->data);
				k = qu->data[k].parent;
			}
			printf("%c\n", qu->data[k].pt->data);
		}
		if (p->lchild != NULL) {						//结点 p 有左孩子
			qelem.pt = p->lchild;						//创建结点 p 的左孩子对应的队列元素
			qelem.parent = qu->front;				//结点 p 的左孩子的双亲位置为 qu->front
			enQueue(qu, qelem);						//结点 p 的左孩子进队
		}
		if (p->rchild != NULL) {						//结点 p 有右孩子
			qelem.pt = p->rchild;						//创建结点 p 的右孩子对应的队列元素
			qelem.parent = qu->front;				//结点 p 的右孩子的双亲位置为 qu->front
			enQueue(qu, qelem);						//结点 p 的右孩子进队
		}
	}
}