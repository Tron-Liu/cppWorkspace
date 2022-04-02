#include <stdio.h>

int main()
{
	int a1 = 0, a2 = 0;
	double a3 = 0;
	
	int N;
	scanf("%d", &N);
	
	int i, num, m = 0;
	for(i = 0; i < N; i++) {
		scanf("%d", &num);
		if(num % 3 == 0 && a1 < num)
			a1 = num;
		if((num - 1) % 3 == 0)
			a2++;
		if((num - 2) % 3 == 0) {
			a3 += num;
			m++;
		}
	}
	if(!a1) printf("NONE ");
	else printf("%d ", a1);
	
	if(!a2) printf("NONE ");
	else printf("%d ", a2);
	
	if(!a3) printf("NONE");
	else printf("%.1lf", a3 / m);
	
	return 0;
 } 
