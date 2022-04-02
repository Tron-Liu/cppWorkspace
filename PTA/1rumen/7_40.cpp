#include <stdio.h>

int main()
{
	char s[10][6] = {"ling", "yi", "er", "san", "si", "wu", "liu","qi","ba","jiu"};
	int i;
	char c;
	int flag = 0;
	scanf("%c", &c);
	while(c != '\n') {
		if(c == '-') {
			flag = 1; 
			printf("fu");
			scanf("%c", &c);
			continue;
		}
		i = (int)(c - '0');
		if(!flag) {
			printf("%s", s[i]);
			flag = 1;	
		}
		else printf(" %s", s[i]); 
		scanf("%c", &c);
	}
	return 0;
}
