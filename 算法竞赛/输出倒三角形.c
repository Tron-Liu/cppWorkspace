#include <stdio.h>

int main()
{
	char c = "#";
	int n;
	int j;
	int num = 0;
	scanf_s("%d", &n);
	for (int i = n; i > 0; i--)
	{
		for (int h = num; h > 0; h--)
		{
			printf_s(" ");
		}
		num++;
		for (j = 2 * i - 1; j > 0; j--)
		{
			printf_s("#");
		}
		printf_s("\n");
	}

	return 0;
}