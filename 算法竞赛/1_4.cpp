#include <stdio.h>
#include <math.h>

int main()
{
	const double pi = acos(-1.0);
	double n;
	scanf("%lf", &n);
	double s = sin(n * pi / 180), c = cos(n * pi / 180);
	
	printf("%lf %lf", s, c);
	return 0;
}
