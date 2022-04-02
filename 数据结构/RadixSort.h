#pragma once
#include <iostream>
#define MAXD 10
#define MAXR 10			//MAXR 为最大基数

typedef struct node
{
	char data[MAXD];		//MAXD 为最大关键字位数
	struct node *next;		//指向下一结点
}NodeType;						//基数排序数据的结点类型

/*
	param1：存储的待排序序列的单链表的指针
	param2：基数
	param3：关键字位数
*/
void RadixSort(NodeType *&p, int r, int d) {		//LSD（最低位优先排序）基数排序算法
	NodeType *head[MAXR], *tail[MAXR], *t;		//定义各链队的首尾指针
	int i, j, k;
	for (i = 0; i <= d - 1; i++) {				//从低位到高位循环
		for (j = 0; j < r; j++)						//初始化各链队的首、尾结点
			head[j] = tail[j] = NULL;
		while (p != NULL) {						//分配：对于原链表中的每个结点循环
			k = p->data[i] - '0';					//找第 k 个链队
			if (head[k] == NULL) {				//第 k 个链队空时，队头、队尾均指向结点p
				head[k] = p;
				tail[k] = p;
			}
			else {										//第 k 个链队非空时结点p进队
				tail[k]->next = p;
				tail[k] = p;
			}
			p = p->next;							//取下一个待排序的元素
		}
		p = NULL;									//重新用p来收集所有结点
		for(j = 0; j < r; j++)						//收集：对于每一个链队循环
			if (head[j] != NULL) {				//若第 j 个结点是第一个非空链队
				if (p == NULL) {
					p = head[j];
					t = tail[j];
				}
				else {									//若 p 非空
					t->next = head[j];
					t = tail[j];
				}
			}
		t->next = NULL;							//最后一个结点的 next 域置NULL
	}
}