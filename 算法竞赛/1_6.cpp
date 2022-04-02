#include <stdio.h>

void change(int *x, int *y);

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	if(a > b) change(&a, &b);
	if(a > c) change(&a, &c);
	if(b > c) change(&b, &c);
	
	if(a + b <= c) {
		printf("not a triangle");
		return 0;
	}
	if(a * a + b * b == c * c) {
		printf("yes");
	}
	else {
		printf("no");
	}
	return 0;
 }
 
void change(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
