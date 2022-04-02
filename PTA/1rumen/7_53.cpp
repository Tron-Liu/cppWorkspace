#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	int M;				//记录上一个数字
	int sum = 0;
	int i = 1;
	while(1) {
		M = N;
		sum = 0;
		while(N) {
			sum = sum + N % 10;
			N = N / 10;
		}
		sum = sum * 3 + 1;
		if(sum == M) {
			printf("%d:%d", i, sum);
			return 0;
		}
		else {
			printf("%d:%d\n", i, sum);
			i++;
			N = sum;
		}
	}
	return 0;
}
