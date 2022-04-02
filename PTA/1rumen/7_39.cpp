#include <stdio.h>

int main()
{
	char letter[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
	char c;
	c = getchar();
	int i;
	while(c != '\n') {
		i = (int)(c - 'A');
		if(i >= 0 && i <= 25) printf("%c", letter[i]);
		else printf("%c", c);
		c = getchar();
	}
	
	return 0;
}
