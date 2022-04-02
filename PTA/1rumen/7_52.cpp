#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	int x, y;
	int x2, y2;
	int mid = N / 2;
	int flag = 0;
	x2 = x * x;
	for(x = 1; x2 <= mid+1; x++) {
		x2 = x * x;
		y2 = N - x2;
		y = sqrt(y2);
		if(y * y == y2) {
			printf("%d %d\n", x, y);
			flag = 1;
		}
		if(x >= y) break;
	}
	if(!flag) printf("No Solution");
	
	return 0;
}
