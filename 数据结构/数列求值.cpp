#include <iostream>
using namespace std;

int main()
{
	int a=1, b=1, c=1;
	int n;
	cin >> n;
	int d;
	while(--n) {
		d = (a + b + c) % 10000;
		a = b; b = c; c = d;
	} 
	cout << a;
} 
