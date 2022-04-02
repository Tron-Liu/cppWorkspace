#include<stdio.h>

int main()
{
	int N = 10;
	while(1) {
		if(!((N-1)%5) && !((N-5)%6) && !((N-4)%7) && !((N-10)%11)) {
			printf("%d", N);
			break; 
		} 
		N++;
	}
	return 0;
 } 
