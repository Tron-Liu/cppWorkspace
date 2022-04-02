#include <stdio.h>
#include <string.h>

int main()
{
	char s[102];
	char c;
	c = getchar();
	int a = 0;
	while(c != '\n') {
		s[a] = c;
		a++;
		c = getchar();
	}
	
	int n;
	scanf("%d", &n);
	
	int i, j = 0, k;
	int m = strlen(s);
	for(i = n; j < m; i++, j++) {
		k = (i + m) % m;
		printf("%c", s[k]);
	}
	
	return 0;
}
