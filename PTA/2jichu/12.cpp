#include <stdio.h>
#include <math.h>

int is_prime(int m);

int main()
{
	int n;
	scanf("%d", &n);
	
	int i = 1, m = 2;
	int count = 0;
	while(i < n) {
		m *= 2;
		if(is_prime(m - 1)) {
			printf("%d\n", m - 1);
			count++;
		}
		i++;
	}
	if(!count) printf("None");
	
	return 0;
}

int is_prime(int m) {		//判断一个数是否是素数 
	int a = sqrt(m);
	if(!(m % 2)) {			//单独判断 2 
		return 0;			//返回 0 表示不是素数	
	}
	
	for(int i = 3; i <= a; i+=2) {
		if(m % i) continue;
		else return 0;
	}
	return 1;
}
