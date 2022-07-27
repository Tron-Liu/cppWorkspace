#include <stdio.h>
#include <math.h>

int is_prime(int m);

int main()
{
	int n;
	scanf("%d", &n);
	
	int count = 0;			//记录个数
	while(count < 10) {
		n--;
		if(is_prime(n)) {	//是素数 
			printf("%6d", n);
			count++; 
		}
		else continue;
	}
	
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
