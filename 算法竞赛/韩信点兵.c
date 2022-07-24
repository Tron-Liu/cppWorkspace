#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int n = 0;

	scanf_s("%d%d%d", &a, &b, &c);
	n = 70 * a + 21 * b + 15 * c;

	while (n > 105)
		n -= 105;

	if (n < 100)
		printf_s("%d", n);
	else
		printf_s("No answer");

	return 0;
}