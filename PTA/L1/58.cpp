#include <stdio.h>

int main()
{
	char c[1002];
	int i = 0;
	int j = 0;		//标记 6 出现的次数 
	char a;
	
	while((a = getchar()) != '\n')
		c[i++] = a;
	
	c[i] = '#';
	
	for(int k = 0; k <= i; k++) {
		if(c[k] == '6') {
			if(j) j++;
			else j = 1;
		}
		else {
			if(j <= 3) {
				for(int n = 0; n < j; n++)
					printf("6");
			}
			else if(j > 3 && j <= 9) {
				printf("9");
			}
			else{
				printf("27");
			}
			j = 0;
			if(c[k] != '#') printf("%c", c[k]);
		}
	} 
	return 0;
}
