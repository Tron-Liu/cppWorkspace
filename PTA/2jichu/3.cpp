#include <stdio.h>

int main()
{
	int result[12] = {0};
	
	int a, n;	
	scanf("%d %d", &a, &n);
	
	int carry = 0;
	int j = n;
	
	while(n) {
		int temp = a * n + carry;
		result[n] = temp % 10;
		carry = temp / 10;
		n--;
	}
	printf("s = ");
	if(carry) printf("%d", carry);
	
	int i;
	for(i = 1; i<=j; i++)
		printf("%d", result[i]);
		
	return 0;
 } 
