#include <stdio.h>

int main()
{
	int A_Max, B_Max;
	scanf("%d %d", &A_Max, &B_Max);
	
	int N;
	scanf("%d", &N);
	
	int A_han, A_hua, B_han, B_hua;
	int Adrink = 0, Bdrink = 0;
	while(N) {
		scanf("%d %d %d %d", &A_han, &A_hua, &B_han, &B_hua);
		if((A_hua == A_han + B_han) && (A_hua == A_han + B_han)) {
			N--;
			continue;
		}
		
		if(A_hua == A_han + B_han) {
			Adrink++;
			if(Adrink > A_Max) {
				printf("A\n");
				printf("%d", Bdrink);
				return 0;
			}
		}
		
		if(B_hua == A_han + B_han) {
			Bdrink++;
			if(Bdrink > B_Max) {
				printf("B\n");
				printf("%d", Adrink);
				return 0;
			}
		}
		N--;
	}
	return 0;
}
