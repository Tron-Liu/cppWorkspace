#include <stdio.h>

int main()
{
	int a, b;
	char c;
	scanf("%d", &a);
	c = getchar();
	
	while(c != '=') {
		scanf("%d", &b);
		if(c == '/' && b == 0) {
			printf("ERROR");
			return 0;
		}
		
		switch(c) {
			case '+':
				a = a + b;
				break;
			case '-':
				a = a - b;
				break;
			case '*':
				a = a * b;
				break;
			case '/':
				a = a / b;
				break;
			default: 
				printf("ERROR");
				return 0;
		}
		c = getchar();
	}
	printf("%d", a);
	return 0;
}
