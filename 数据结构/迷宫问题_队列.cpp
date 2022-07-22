#include <stdio.h>
#include <stdlib.h>
#include "SqQueue1.h"
#define M 8
#define N 8
int mg[M + 2][N + 2] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void print(QuType *qu, int front)
{ //从队列qu中输出一条迷宫路径
	int k = front, j, ns = 0;
	printf("\n");
	do
	{ //反向找到最短路径，将该路径上的方块的pre成员设置成-1
		j = k;
		k = qu->data[k].pre;
		qu->data[j].pre = -1;
	} while (k != 0);
	printf("一条迷宫路径如下：\n");
	k = 0;
	while (k < MaxSize)
	{ //正向搜索到pre为-1的方块，即构成正向的路径
		if (qu->data[k].pre == -1)
		{
			ns++;
			printf("\t(%d,%d)", qu->data[k].i, qu->data[k].j);
			if (ns % 5 == 0)
				printf("\n");
		}
		k++;
	}
	printf("\n");
}

bool mgpath1(int xi, int yi, int xe, int ye)
{ //搜索路径为(xi,yi)->(xe,ye)
	Box e;
	int i, j, di, i1, j1;
	QuType *qu;	   //定义顺序栈
	InitQueue(qu); //初始化队列qu
	e.i = xi;
	e.j = yi;
	e.pre = -1;
	enQueue(qu, e);	 //(xi,yi)进队
	mg[xi][yi] = -1; //将其值赋为-1，以避免回过来重复搜索
	while (!QueueEmpty(qu))
	{					//队不空循环
		deQueue(qu, e); //出队方块e，由于不是环形队列，该出队元素仍在队列中
		i = e.i;
		j = e.j;
		if (i == xe && j == ye)
		{						  //找到了出口，输出路径
			print(qu, qu->front); //调用print函数输出路径
			DestroyQueue(qu);	  //销毁队列
			return true;		  //找到一条路径时返回真
		}
		for (di = 0; di < 4; di++)
		{ //循环扫描每个方位，把每个可走的方块插入到队列中
			switch (di)
			{
			case 0:
				i1 = i - 1;
				j1 = j;
				break;
			case 1:
				i1 = i;
				j1 = j + 1;
				break;
			case 2:
				i1 = i + 1;
				j1 = j;
				break;
			case 3:
				i1 = i;
				j1 = j - 1;
				break;
			}
			if (mg[i1][j1] == 0)
			{
				e.i = i1;
				e.j = j1;
				e.pre = qu->front; //指向路径中上一个方块
				enQueue(qu, e);	   //(i1,j1)方块进队
				mg[i1][j1] = -1;   //将其赋值为-1，以避免回过来重复搜索
			}
		}
	}
	DestroyQueue(qu); //销毁队列
	return false;	  //未找到任何路径时返回假
}

int main()
{
	if (!mgpath1(1, 1, M, N))
		printf("该迷宫问题没有解！");
	system("pause");
	return 1;
}