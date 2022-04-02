#pragma once

#include <stdio.h>
#include <malloc.h>
typedef int Elemtype;
typedef struct qnode
{
	Elemtype data;				//存放元素
	struct qnode* next;		//下一个结点指针
}DataNode;						//链队数据结点的类型

typedef struct
{
	DataNode *front;		//指向队首结点
	DataNode *rear;		//指向队尾结点
}LinkQuNode;				//链队结点的类型

//初始化队列
void InitQueue(LinkQuNode *&q) {
	q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

//销毁队列
void DestroyQueue(LinkQuNode *&q) {
	DataNode *pre = q->front, *p;				//pre指向队首结点
	if (pre != NULL) {
		p = pre->next;										//p指向结点pre的后继结点
		while (p != NULL) {								//p不空循环
			free(pre);											//释放pre结点
			pre = p;											//pre、p同步后移
			p = p->next;
		}
		free(pre);												//释放最后一个数据结点
	}
	free(q);														//释放链队结点
}

//判断队列是否为空
bool QueueEmpty(LinkQuNode *q) {
	return(q->front == NULL);
}

//进队列
void enQueue(LinkQuNode *&q, Elemtype e) {
	DataNode *p;
	p = (DataNode *)malloc(sizeof(DataNode));		//创建新结点
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)											//若链队为空，则新结点既是队首结点又是队尾结点
		q->front = q->rear = p;
	else {																	//若链队不空
		q->rear->next = p;											//将结点p链到队尾，并将rear指向它
		q->rear = p;
	}
}

//出队列
bool deQueue(LinkQuNode *&q, Elemtype &e) {
	DataNode *t;
	if (q->rear == NULL)						//原来队列为空
		return false;
	t = q->front;									//t指向首结点
	if (q->front == q->rear)					//原来队列中只有一个数据结点时
		q->front = q->rear = NULL;
	else													//原来队列中有两个或两个以上结点时
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}