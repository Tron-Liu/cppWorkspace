#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
	int n;
	cin >> n;
	
	int a, b;
	scanf("%d/%d", &a, &b);
	
	int c, d, g, l;
	for(int i = 1; i < n; i++) {
		scanf("%d/%d", &c, &d);
		
		l = lcm(b, d);
		a = l/b*a + l/d*c;
		b = l;
		
		g = gcd(a, b);
		a /= g;
		b /= g;
	}
	
	//求平均值 
	g = gcd(a, n);
	a /= g;
	b = n/g * b;
	
	if(b == 1) cout << a;
	else cout << a << "/" << b;

	//cout << gcd(2,6);

	return 0;
}

int gcd(int a, int b)
{
	int temp;
	while(a > 0) {
		temp = b % a;
		b = a;
		a = temp;
	}
	return b;
}

int lcm(int a, int b)
{
	return a*b / gcd(a, b);
}
