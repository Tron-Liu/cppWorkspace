#include <stdio.h>

int gcd(int x, int y);
int lcm(int x, int y);

int main()
{
	int a, b, c, d;
	scanf("%d/%d %d/%d", &a, &b, &c, &d);
	
	int n = lcm(b, d);
	int first = a * n / b;
	int last = c * n / d;
	
	if(first < last) printf("%d/%d < %d/%d", a, b, c, d);
	else if(first > last) printf("%d/%d > %d/%d", a, b, c, d);
	else printf("%d/%d = %d/%d", a, b, c, d);
	
	return 0;
 } 
 
int gcd(int x, int y) {
	int r;
	while(y) {
		r = y;
		y = x % y;
		x = r;
	}
	return x;
}

int lcm(int x, int y) {
	int a = gcd(x, y);
	return x * y / a;
}
