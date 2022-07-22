#pragma once
#define M 100
#define N 100
#define MaxSize 20
#define ElmeType int
#include <iostream>
typedef struct
{
	int r;		//行号
	int c;		//列号
	ElmeType d; //元素值
} TupNode;		//三元组类型
typedef struct
{
	int rows; //行数
	int cols; //列数
	int nums; //非零元素个数
	TupNode data[MaxSize];
} TSMatrix; //三元组顺序表的类型

//从一个二维稀疏矩阵创建其三元组表示
void CreateMat(TSMatrix &t, ElmeType A[M][N])
{
	int i, j;
	t.rows = M;
	t.cols = N;
	t.nums = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (A[i][j] != 0)
			{ //在存储非零元素
				t.data[t.nums].r = i;
				t.data[t.nums].c = j;
				t.data[t.nums].d = A[i][j];
				t.nums++;
			}
		}
	}
}

//三元组元素的赋值
bool Value(TSMatrix &t, ElmeType x, int i, int j)
{
	int k = 0, k1;
	if (i >= t.rows || j >= t.cols)		  // i, j参数超界
		return false;					  //返回假
	while (k < t.nums && i > t.data[k].r) //查找到第i行的第一个非0元素
		k++;
	while (k < t.nums && i == t.data[k].r && j > t.data[k].c)
		k++;								  //在第i行的非0元素中查找第j列
	if (t.data[k].r == i && t.data[k].c == j) //若存在这样的非零元素
		t.data[k].d = x;					  //修改非零元素值
	else
	{ //若不存在这样的非0元素
		for (k1 = t.nums - 1; k1 >= k; k1--)
		{ //若干元素均后移一个位置
			t.data[k1 + 1].r = t.data[k1].r;
			t.data[k1 + 1].c = t.data[k1].c;
			t.data[k1 + 1].d = t.data[k1].d;
		}
		t.data[k].r = i;
		t.data[k].c = j;
		t.data[k].d = x; //插入非0元素x
		t.nums++;		 //非0元素个数增1
	}
	return true; //成功操作后返回真
}

//将指定位置的元素赋值给变量
bool Assign(TSMatrix t, ElmeType &x, int i, int j)
{
	int k = 0;
	if (i >= t.rows || j >= t.cols)		  //参数超界
		return false;					  //返回true
	while (k < t.nums && i > t.data[k].r) //查找第i行
		k++;
	while (k < t.nums && i == t.data[k].r && j > t.data[k].c)
		k++;								  //在第i行的非0元素中查找第j列
	if (t.data[k].r == i && t.data[k].c == j) //若存在这样的非0元素
		x = t.data[k].d;					  //提取元素值
	else									  //若不存在这样的非0元素
		x = 0;								  //置x为0
	return true;							  //操作成功后返回真
}

//输出三元组
void DispMat(TSMatrix t)
{
	int k;
	if (t.nums <= 0) //没有非0元素时直接返回
		return;
	printf("\t%d\t%d\t%d\n", t.rows, t.cols, t.nums);
	printf("\t----------------------\n");
	for (k = 0; k < t.nums; k++) //输出所有非0元素
		printf("\t%d\t%d\t%d\n", t.data[k].r, t.data[k].c, t.data[k].d);
}

//稀疏矩阵转置
void TranTat(TSMatrix t, TSMatrix &tb)
{
	int k, k1 = 0, v; // k1记录tb中的元素个数
	tb.rows = t.cols;
	tb.cols = t.rows;
	tb.nums = t.nums;
	if (t.nums != 0)
	{									 //当存在非零元素时执行转置
		for (v = 0; v < t.cols; v++)	 //按v=0、1、... 、t.cols循环
			for (k = 0; k < t.nums; k++) // k用于扫描t.data的所有元素
				if (t.data[k].c == v)
				{ //找到一个列号为v的元素
					tb.data[k1].r = t.data[k].c;
					tb.data[k1].c = t.data[k].r;
					tb.data[k1].d = t.data[k].d;
					k++; // tb中元素的个数增1
				}
	}
}