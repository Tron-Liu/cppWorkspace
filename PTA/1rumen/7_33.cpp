#include <stdio.h>

int main()
{
	int cm, foot, inch;
	scanf("%d", &cm);
	inch = cm * 100 * 12 / 3048;
	foot = inch / 12;
	inch = inch % 12;
	printf("%d %d", foot, inch);
	return 0;
}
