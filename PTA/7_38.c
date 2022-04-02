#include <stdio.h>
#define MaxSize 100010

int main()
{
	int result[MaxSize] = {0}; 
	int A, N;
	scanf("%d %d", &A, &N);

	if(N == 0) {
		printf("%d", A);
		return 0;
	}

	int i = N;

	int carry = 0;
	while(i > 0) {
		int temp = A * i + carry;
		result[i - 1] = temp % 10;
		carry = temp / 10;
		i--;
	}

	if(carry != 0) printf("%d", carry);

	for(i = 0; i < N; i++) {
		printf("%d", result[i]);
	}
	return 0;
}
