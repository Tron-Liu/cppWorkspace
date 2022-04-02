#include <stdio.h>
#include <stdlib.h>
#include "SqStack2.h"
#define M 8
#define N 8

int mg[M+2][N+2] =
{
	{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
};

bool mgpath(int xi, int yi, int xe, int ye)		//���·��Ϊ��xi��yi��->��xe��ye��
{
	Box path[MaxSize], e;
	int i, j, di, i1, j1, k;
	bool find;
	StType *st;												//����ջst
	InitStack(st);												//��ʼ��ջ��ָ��
	e.i = xi; e.j = yi; e.di = -1;							//����eΪ���
	Push(st, e);												//����e��ջ
	mg[xi][yi] = -1;											//����ڵ��Թ�ֵ��Ϊ-1�������ظ��ߵ��÷���
	while (!StackEmpty(st))							//ջ����ʱѭ��
	{
		GetTop(st, e);										//ȡջ��Ԫ��
		i = e.i; j = e.j; di = e.di;
		if (i == xe && j == ye)						//�ҵ��˳��ڣ������·��
		{
			printf("һ���Թ�·�����£�\n");
			k = 0;
			while (!StackEmpty(st))
			{
				Pop(st, e);										//��ջ����e
				path[k++] = e;								//��e��ӵ�path������
			}
			while (k>=1)
			{
				k--;
				printf("\t(%d,%d)", path[k].i, path[k].j);
				if ((k + 2) % 5 == 0)						//ÿ���5�������һ��
					printf("\n");
			}
			printf("\n");
			DestroyStack(st);								//����ջ
			return true;										//���һ���Թ�·���󷵻�true
		}
		find = false;
		while (di<4 && !find)							//�ҷ��飨i��j������һ�����ڿ��߷��飨i1��j1��
		{
			di++;
			switch (di)
			{
				case 0:i1 = i - 1; j1 = j; break;
				case 1:i1 = i; j1 = j+1; break;
				case 2:i1 = i + 1; j1 = j; break;
				case 3:i1 = i; j1 = j-1; break;
			}
			if (mg[i1][j1] == 0) find = true;	//�ҵ�һ�����ڿ��߷��飬����findΪ��
		}
		if (find)												//�ҵ���һ�����ڿ��߷��飨i1��j1��
		{
			st->data[st->top].di = di;			//�޸�ԭջ��Ԫ�ص�diֵ
			e.i = i1; e.j = j1; e.di = -1;
			Push(st, e);									//���ڿ��߷���e��ջ
			mg[i1][j1] = -1;							//����i1��j1���Թ�ֵ��Ϊ-1�������ظ��ߵ��÷���
		}
		else													//û��·�����ߣ�����ջ
		{
			Pop(st, e);										//��ջ��������ջ
			mg[e.i][e.j] = 0;							//����ջ�����λ�ñ�Ϊ����·�����߷���
		}
	}
	DestroyStack(st);									//����ջ
	return false;											//��ʾû��·�������ߣ�����false
}

int main()
{
	if (!mgpath(1, 1, M, N))
		printf("���Թ�����û�н⣡");
	system("pause");
	return 1;
}