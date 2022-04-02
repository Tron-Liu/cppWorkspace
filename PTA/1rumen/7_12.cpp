#include <stdio.h>

int main()
{
	int level[6] = {0};
	int N, i;
	scanf("%d", &N);
	
	int num[1002];
	for(i = 0; i < N; i++)
		scanf("%d", &num[i]);
		
	for(i = 0; i < N; i++) {
		if(num[i] >= 90) level[0]++;
		else if(num[i] >= 80) level[1]++;
		else if(num[i] >= 70) level[2]++;
		else if(num[i] >= 60) level[3]++;
		else level[4]++;
	}
	
	for(i = 0; i < 5; i++) {
		printf("%d", level[i]);
		if(i != 4) printf(" ");	
	}
	return 0;
 } 
