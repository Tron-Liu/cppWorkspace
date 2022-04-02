#include <stdio.h>

int main()
{
	int num = 0;
	int flag = 1;
	char c;
	c = getchar();
	while(c != '\n') {
		if(c != ' ' && flag) {
			num++;
			flag = 0;
		}
		if(c == ' ') {
			if(!num) {
				c = getchar();
				continue;
			}
			else {
				flag = 1;
			}
		}
		c = getchar();
	}
	
	printf("%d", num);
	return 0;
}
