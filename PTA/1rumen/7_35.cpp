#include <stdio.h>

int main()
{
	int sum = 0;
	int numOfTwo = 0;
	int flag = 0;			//标记是否是负数
	char before;			//记录N之前的一位数 
	char N;
	scanf("%c", &N);
	while(N != '\n') {
		if(N == '-') flag = 1;
		if(N == '2') numOfTwo++;
		sum++;
		before = N;
		scanf("%c", &N);
	}
	double result;
	if(flag) {
		sum--;
		result = (double)numOfTwo / sum * 1.5;
	}
	else result = (double)numOfTwo / sum;
	int t = (int)(before-'0');
	if(t % 2 == 0) result = result * 2 * 100;
	else result = result * 100;
	
	printf("%.2lf%%", result);
	
	return 0;
}
