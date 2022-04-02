#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int a = N % 16;
	int b = N / 16;
	int c = b*10 + a;
	printf("%d", c);
}
