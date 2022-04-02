#include <stdio.h>
#include <stdlib.h>
#include "circular_queue1.h"

void number(int n) {
	int i;
	ElemType e;
	SqQueue *q;						//环形队列指针q
	InitQueue(q);						//初始化队列q
	for (i = 1; i <= n; i++)			//构建初始序列
		enQueue(q, i);
	printf("报数出列顺序：");
	while (!QueueEmpty(q)) {	//队列不空循环
		deQueue(q, e);					//出队一个元素e
		printf("%d ", e);					//输出元素编号
		if (!QueueEmpty(q)) {		//队列不空
			deQueue(q, e);				//出队一个元素e
			enQueue(q, e);				//将刚出队的元素进队
		}
	}
	printf("\n");
	DestroyQueue(q);				//销毁队列
}

int main()
{
	int i, n = 8;
	printf("初始序列:");
	for (i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");
	number(n);
	system("pause");
	return 1;
}