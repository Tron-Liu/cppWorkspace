#include <stdio.h>

int main()
{
	int a;
	int b;
	int c;
	scanf_s("%d %d %d", &a, &b, &c);
	int t = a / b;
	double decimal;
	decimal = (double)a / b - t;
	// printf_s("%f\n", decimal);
	for (int i = 0; i < c; i++)
	{
		decimal *= 10;
	}
	decimal += 0.5;
	int result;
	result = (int)decimal;
	printf_s("%d", t);
	printf_s(".");
	printf_s("%d", result);

	return 0;
}