#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int a, b;
	int A = 0, B = 0;
	while(n) {
		scanf("%d/%d", &a, &b);
		
		A += a;
		B += b;
		
		int g = gcd(A, B);
		
		A /= g;
		B /= g;
		
		n--;
	}
}

int gcd(int a, int b)
{
	
}
