int MaxSubseqSum1(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for (i = 0; i < N; i++)
	{ // i是子列左端位置
		for (j = i; j < N; j++)
		{ // j是子列右端位置
			ThisSum = 0;
			for (k = i; k <= j; k++)
			{ // ThisSum是从A[i]到A[j]的子列和
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum) //如果刚得到的这个子列和更大
				MaxSum = ThisSum; //更新结果
		}
	}
	return MaxSum
}

int MaxSubseqSum2(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j;
	for (i = 0; i < N; i++)
	{				 // i是子列左端
		ThisSum = 0; // ThisSum是从A[i]到A[j]的子列和
		for (j = i; j < N; j++)
		{						  // j是子列右端
			ThisSum += A[j];	  //对于相同的i，不同的j，只要在j-1次循环的基础上累加一项即可
			if (ThisSum > MaxSum) //如果刚得到的这个子列和更大
				MaxSum = ThisSum; //则更新结果
		}
	}
	return MaxSum;
}

//在线处理
int MaxSubseqSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum += A[i]; //向右累加
		if (ThisSum > MaxSum)
			MaxSum = ThisSum; //发现更大和则更新当前结果
		else if (ThisSum < 0) //如果当前子列和为负
			ThisSum = 0;	  //则不可能使后面的部分和增大，抛弃
	}
	return MaxSum;
}
