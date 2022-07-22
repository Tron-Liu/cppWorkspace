#pragma once
typedef struct
{
	char data;	   //结点值
	double weight; //权重
	int parent;	   //双亲结点
	int lchild;	   //左孩子结点
	int rchild;	   //右孩子结点
} HTNode;

//构造哈夫曼树
void CreateHT(HTNode ht[], int n0)
{
	int i, k, lnode, rnode;
	double min1, min2;
	for (i = 0; i < 2 * n0 - 1; i++) //所有结点的相关域置初值 -1
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	for (i = n0; i <= 2 * n0 - 2; i++)
	{						 //构造哈夫曼树的 n0-1 个分支结点
		min1 = min2 = 32767; // lnode 和 rnode 为最小权重的两个结点位置
		lnode = rnode = -1;
		for (k = 0; k <= i - 1; k++) //在 ht[0...i-1]中找权值最小的两个结点
			if (ht[k].parent == -1)
			{ //只在尚未构造二叉树的结点中查找
				if (ht[k].weight < min1)
				{
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2)
				{
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode; // ht[i]作为双亲结点
		ht[i].rchild = rnode;
		ht[lnode].parent = i;
		ht[rnode].parent = i;
	}
}

#define N 10
//存放每个结点的哈夫曼编码的类型
typedef struct
{
	char cd[N]; //存放当前结点的哈夫曼码
	int start;	//表示 cd[start...n0]部分是哈夫曼码
} HCode;

void CreateHCode(HTNode ht[], HCode hcd[], int n0)
{
	int i, f, c;
	HCode hc;
	for (i = 0; i < n0; i++)
	{ //根据哈夫曼树求哈夫曼编码
		hc.start = n0;
		c = i;
		f = ht[i].parent;
		while (f != -1)
		{						   //循环直到无双亲结点，即到达根结点
			if (ht[f].lchild == c) //当前结点是双亲结点的左孩子
				hc.cd[hc.start--] = '0';
			else //当前结点是双亲结点的右孩子
				hc.cd[hc.start--] = '1';
			c = f;
			f = ht[f].parent; //再对双亲结点进行同样的操作
		}
		hc.start++; //哈夫曼指向最开始的字符
		hcd[i] = hc;
	}
}