#include <stdio.h>

int main()
{
	int five, two, one;
	
	int n;
	scanf("%d", &n);
	
	int count = 0;
	for(five = 1; five < 30; five++) {
		for(two = 1; two < 73; two++) {
				one = 100 - five - two;
				if(five*5 + two*2 + one == 150) {
					printf("%d %d %d\n", five, two, one);
					count++;
				}
				if(count == n) return 0;
		}
	}
	return 0;	
 } 
