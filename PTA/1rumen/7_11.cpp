#include <stdio.h>

int main()
{
	int letter = 0, blank = 0, digit = 0, other = 0;
	char c;
	int i = 10;
	
	while(i) {
		c = getchar();
		
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			letter++;
		else if(c == ' ' || c == '\r' || c == '\n')
			blank++;	
		else if(c >= '1' && c <= '9')
			digit++;
		else other++;
		
		i--;
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
	return 0;
}
