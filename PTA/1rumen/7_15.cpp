#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	double c = (double)a;
	
	printf("%d + %d = %d\n", a, b, a+b);
	printf("%d - %d = %d\n", a, b, a-b);
	printf("%d * %d = %d\n", a, b, a*b);
	if(c/b == a/b)
		printf("%d / %d = %d", a, b, a/b);
	else
		printf("%d / %d = %.2lf", a, b, c/b);
	
	return 0;
}
