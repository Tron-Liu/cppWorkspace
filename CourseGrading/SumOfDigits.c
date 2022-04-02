#include <stdio.h>

int main()
{
	int n = 0;
	char a;

	while (1)
	{
		scanf("%c", &a);
		if (a == '\n') break;
		else n += a - '0';
	}

	if (n < 10) {
		printf("0");
		return 0;
	}

	int sum, temp;
	int count = 1;						//求和次数
	while ( n >= 10)
	{
		sum = 0;
		temp = n;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		count++;
		n = sum;
	}
	printf("%d", count);
	return 0;
}