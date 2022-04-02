#include <stdio.h>

int main()
{
	int ip[35] = { 0 };

	int i = 0;
	char c;
	c = getchar();
	while (c != '\n') {
		ip[i] = (int)(c - '0');
		i++;
		c = getchar();
	}

	int result = 0, n = 128;
	int count = 0;

	for (i = 0; i < 32; i++) {
		
		result += ip[i] * n;
		n /= 2;
		
		if ((i + 1) % 8 == 0) {
			n = 128;
			printf("%d", result);
			result = 0;
			count++;
			if (count < 4)printf(".");
		}
	}
	return 0;
}
