#include <stdio.h>

int main()
{
	int letter[27] = {0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0};
	int temp, sum = 0;
	char c;
	while(1) {
		scanf("%c", &c);
		if(c == '\r' || c == '\n') break;
		temp = (int)(c - 'A');
		if(temp < 0 || temp > 26) continue;
		if(letter[temp]) sum++;
	}
	printf("%d", sum);
	return 0;
}
