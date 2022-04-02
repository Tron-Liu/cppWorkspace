#include <stdio.h>

int fun(double p);

int main()
{
	double speed, limit;
	scanf("%lf %lf", &speed, &limit);
	double p = (speed-limit) / limit * 100;
	if(p >= 50) printf("Exceed %d%%. License Revoked", fun(p));
	else if(p >= 10) printf("Exceed %d%%. Ticket 200", fun(p));
	else printf("OK");
	
	return 0;
}

int fun(double p) {
	return (int)(p+0.5);
}
