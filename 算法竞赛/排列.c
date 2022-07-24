#include <stdio.h>
int main()
{
	int min = 123;
	int max = 329;
	int a, b, c, d, e, f, g, h, j;
	for (int i = min; i < max; i++)
	{
		a = i % 10;
		b = i / 10 % 10;
		c = i / 10 / 10 % 10;
		int x = i * 2;
		d = x % 10;
		e = x / 10 % 10;
		f = x / 10 / 10 % 10;
		int y = i * 3;
		g = y % 10;
		h = y / 10 % 10;
		j = y / 10 / 10 % 10;
		if ((a + b + c + d + e + f + g + h + j == 45) && (a * b * c * d * e * f * g * h * j == 362880))
		{
			printf_s("%d %d %d\n", i, x, y);
		}
	}

	return 0;
}