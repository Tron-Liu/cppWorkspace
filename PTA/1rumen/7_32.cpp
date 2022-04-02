#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i, j, k;
	int s = 0;
	for(i = n; i <= n+3; i++) {
		for(j = n; j <= n+3; j++) {
			if(j == i) continue;
			
			for(k = n; k <= n+3; k++) {
				if(k == j || k == i) continue;
				
				printf("%d%d%d", i, j, k);
				s++;
				if(s % 6 == 0) printf("\n");
				else printf(" ");	
			}
		}
	}
	
	return 0;
 } 
