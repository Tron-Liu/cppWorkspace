#include <stdio.h>

void my_print(float a1, float b1, float a2, float b2, char symbol, float *result);

void my_add(float a1, float b1, float a2, float b2, float *result);
void my_sub(float a1, float b1, float a2, float b2, float *result);
void my_mul(float a1, float b1, float a2, float b2, float *result);
void my_div(float a1, float b1, float a2, float b2, float *result);

void my_round(float *result);

int main()
{
	float a1, b1, a2, b2;
	float result[2] = { 0 };			//result[0]:实部，result[1]:虚部
	char add = '+', sub = '-', mul = '*', div = '/';

	scanf("%f %f %f %f", &a1, &b1, &a2, &b2);

	my_add(a1, b1, a2, b2, result);
	my_print(a1, b1, a2, b2, add, result);

	my_sub(a1, b1, a2, b2, result);
	my_print(a1, b1, a2, b2, sub, result);

	my_mul(a1, b1, a2, b2, result);
	my_print(a1, b1, a2, b2, mul, result);

	my_div(a1, b1, a2, b2, result);
	my_print(a1, b1, a2, b2, div, result);

	return 0;
}

//输出
void my_print(float a1, float b1, float a2, float b2, char symbol, float *result) {
	if (result[0] == 0 && result[1] == 0)
		printf("(%.1f%+.1fi) %c (%.1f%+.1fi) = 0.0\n", a1, b1, symbol, a2, b2);
	else if (result[0] == 0 && result[1] != 0)
		printf("(%.1f%+.1fi) %c (%.1f%+.1fi) = %.1fi\n", a1, b1, symbol, a2, b2, result[1]);
	else if (result[0] != 0 && result[1] == 0)
		printf("(%.1f%+.1fi) %c (%.1f%+.1fi) = %.1f\n", a1, b1, symbol, a2, b2, result[0]);
	else
		printf("(%.1f%+.1fi) %c (%.1f%+.1fi) = %.1f%+.1fi\n", a1, b1, symbol, a2, b2, result[0], result[1]);
}

//四舍五入函数
void my_round(float *result)
{
	int i;

	for (i = 0; i < 2; i++) {
		if (result[i] < 0)
			result[i] = (int)((result[i] - 0.05) * 10) / 10.0;
		else
			result[i] = (int)((result[i] + 0.05) * 10) / 10.0;
	}
}
//加法
void my_add(float a1, float b1, float a2, float b2, float *result) {
	result[0] = a1 + a2;
	result[1] = b1 + b2;

	my_round(result);
}

//减法
void my_sub(float a1, float b1, float a2, float b2, float *result) {
	result[0] = a1 - a2;
	result[1] = b1 - b2;

	my_round(result);
}

//乘法
void my_mul(float a1, float b1, float a2, float b2, float *result) {
	result[0] = a1 * a2 - b1 * b2;
	result[1] = a1 * b2 + b1 * a2;

	my_round(result);
}

//除法
void my_div(float a1, float b1, float a2, float b2, float *result) {
	float temp = a2 * a2 + b2 * b2;

	result[0] = (a1 * a2 + b1 * b2) / temp;
	result[1] = (b1 * a2 - a1 * b2) / temp;

	my_round(result);
}