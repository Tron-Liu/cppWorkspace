#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int x[5] = {0};
	int i;
	for(i = 0; i < 4; i++) {
		x[i] = (n % 10 + 9) % 10;
		n /= 10; 
	}
	int temp;
	temp = x[0];
	x[0] = x[2];
	x[2] = temp;
	
	temp = x[1];
	x[1] = x[3];
	x[3] = temp;
	
	int result = x[0] + x[1]*10 + x[2]*100 + x[3]*1000;
	printf("The encrypted number is %04d", result);
	return 0;
}
