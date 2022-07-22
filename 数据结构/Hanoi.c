#include <stdio.h>
#include <stdlib.h>

void Hanoi1(int n, char X, char Y, char Z)
{
	if (n == 1)
		printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);
	else
	{
		Hanoi1(n - 1, X, Z, Y);
		printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);
		Hanoi1(n - 1, Y, X, Z);
	}
}

#define MaxSize 100
typedef struct
{
	int n;
	char x, y, z;
	bool flag;
} ElemType;

typedef struct
{
	ElemType data[MaxSize];
};

int main()
{
	int n = 3;
	char a = 'a', b = 'b', c = 'c';
	Hanoi1(n, a, b, c);
	system("pause");
	return 0;
}
