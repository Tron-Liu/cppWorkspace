#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int a, n;	
	scanf("%d %d", &a, &n);
	
	if(n == 0) {
		printf("0");
		return 0;
	}
	
	int *result = (int *)malloc((n+1) * sizeof(int));
	
	int carry = 0;
	int j = n;
    
	while(n) {
		int temp = a * n + carry;
		result[n] = temp % 10;
		carry = temp / 10;
		n--;
	}
	if(carry) printf("%d", carry);
	
	int i;
	for(i = 1; i<=j; i++)
		printf("%d", result[i]);
	
	free(result);
	return 0;
 } 
