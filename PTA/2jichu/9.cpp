#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	int count = 0;
	
	int f5;		
	int f2;		
	int f1;		
	
	f5 = x / 5;								//5��Ӳ�ҵ�����
	for(int i = f5; i > 0; i--) {
		f2 = (x - i*5) / 2;					//2��Ӳ�ҵ�����
		for(int j = f2; j > 0; j--) {
			f1 = x - i*5 - j*2;				//1��Ӳ�ҵ�����
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
