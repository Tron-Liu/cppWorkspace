#include <stdio.h>
#include <ctype.h>

int main()
{
	int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int M[] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};
	
	char id[20];
	int flag = 1;
	int N;
	scanf("%d", &N);
	int i, j;
	while(N) {
		scanf("%s", id);
		int sum = 0;
		for(i = 0; i < 17; i++) {
			j = (int)(id[i] - '0');
			if(isdigit(id[i])) sum += j * weight[i];
			else sum += 10 * weight[i];
		}
		
		int a = sum % 11;
		int b = (int)(id[17] - '0');
		if(!isdigit(id[17])) b = 10;
		 
		if(M[a] != b) {
			printf("%s\n", id);
			flag = 0;
		}
		N--;
	}
	if(flag) printf("All passed");
	
	return 0;
}
