#include <stdio.h>

int gcd(int a, int b);

int main()
{
	int a, b, c, d;
	scanf("%d/%d %d/%d", &a, &b, &c, &d);
	
	int m, n;
	m = a * d + b * c;
	n = b * d;
	
	int g = gcd(m, n);
	m /= g;
	n /= g;
	
	if(n == 1) printf("%d", m);
	else printf("%d/%d", m, n);
	
	return 0;
}

int gcd(int a, int b) {
	int temp;
	while(b) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
