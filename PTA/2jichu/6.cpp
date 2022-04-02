#include <iostream>
#include <set>
using namespace std;

int get_max_num(int n);
int get_min_num(int n);
int sort(int *a, int *b, int *c);
int change(int *x, int *y);

int main()
{
	int n;
	scanf("%d", &n);
	
	int m = n, i = 1;		//记录差值
	do{
		int max = get_max_num(m);
		int min = get_min_num(m);
		m = max - min;
		printf("%d: %d - %d = %d\n", i, max, min, m);
		
		i++;
	}while(m != 495);
	
	return 0;
}

int get_max_num(int n) {
	int a, b, c;
	a = n % 10;
	n = n / 10;
	
	b = n % 10;
	n = n / 10;
	
	c = n;
	
	int max;
	sort(&a, &b, &c);
	max = c * 100 + b * 10 + a;
	return max;

}

int get_min_num(int n) {
	int a, b, c;
	a = n % 10;
	n = n / 10;
	
	b = n % 10;
	n = n / 10;
	
	c = n;
	
	int min;
	sort(&a, &b, &c);
	min = a * 100 + b * 10 + c;
	return min;
}

int sort(int *a, int *b, int *c) {		//a 最小，b 其次，c 最大 
	if(*a > *b) change(a, b);
	if(*a > *c) change(a, c);
	if(*b > *c) change(b, c);
}

int change(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
