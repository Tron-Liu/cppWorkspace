#include <stdio.h>

int main()
{
	char c;
	char sum[20] = {'0'};
	int i = 0;

	c = getchar();
	while(c != '\n') {
		if(c == '0' && !i) {
			c = getchar();
			continue;	
		}
		if(c >= '0' && c <= '9') sum[i++] = c;
		c = getchar();
	}
	
	int j;
	if(i) {
		for(j = 0; j < i; j++) printf("%c", sum[j]);
	}
	else {
		printf("0");
	}
	return 0;
 } 
