#include <stdio.h>

int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	int i, j = 1;
	for(i = A; i <= B; i++) {
		printf("%5d", i);
		if(j % 5 == 0) printf("\n");
		j++;
	}
	if(j % 6 != 0) printf("\n");
	int sum = 0;
	if(A*B > 0) {
		for(i = A; i <= B;i++)
			sum += i;
	}
	else {
		if(A+B < 0) {
			B = -B-1;
			for(i = A; i <= B;i++)
				sum += i;
		}
		else {
			A = -A+1;
			for(i = A; i <= B;i++)
				sum += i;
		}
	}
	printf("Sum = %d", sum);
	return 0;
 } 
