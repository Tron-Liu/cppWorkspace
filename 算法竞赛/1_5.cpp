#include <stdio.h>

int main()
{
	const double price = 95;
	
	int n;
	scanf("%d", &n);
	
	double money = price * n;
	if(money >= 300) printf("%.2lf", money * 0.85);
	else printf("%.2lf", money);
	
	return 0;
}
