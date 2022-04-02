#include <stdio.h>

int main()
{
	int A[22][22] = {0};
	int M, N, i, j;
	int flag = 0;						//标记局部极大值 
	scanf("%d %d", &M, &N); 
	
	for(i = 0; i < M; i++) {			//输入矩阵 
		for(j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	for(i = 1; i < M-1; i++) {
		for(j = 1; j < N-1; j++) {
			//上、下、左、右 
			if(A[i][j] > A[i][j-1] && A[i][j] > A[i][j+1] && A[i][j] > A[i-1][j] && A[i][j] > A[i+1][j]) {
				printf("%d %d %d\n", A[i][j], i+1, j+1);
				flag = 1;
			}	
		}
	}
	if(!flag) printf("None %d %d", M, N);
	return 0;
 } 
