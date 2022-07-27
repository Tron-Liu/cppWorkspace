#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	int count = 0;
	
	int f5;		
	int f2;		
	int f1;		
	
	f5 = x / 5;								//5分硬币的数量
	for(int i = f5; i > 0; i--) {
		f2 = (x - i*5) / 2;					//2分硬币的数量
		for(int j = f2; j > 0; j--) {
			f1 = x - i*5 - j*2;				//1分硬币的数量
			for(int k = f1; k > 0; k--) {
				if((5*i+2*j+k) == 13) {
					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i, j, k, i+j+k);
					count++;
				}
			}
		}
	}
	printf("count = %d", count);
	
	return 0;
} 
