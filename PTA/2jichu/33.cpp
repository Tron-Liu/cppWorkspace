#include <stdio.h>

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	
	int a[8][8] = {0};
	int i, j;
	for(i = 0; i < n; i++) 			//���� 
		for(j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
			
	m %= n;
	if(!m) {			//ȡ��Ϊ�㣬�����ƶ� 
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		return 0;
	} 
	
	for(int i = 0; i < n; i++) {		//��� 
		int k = n - m;
		for(int j = 0; j < n; j++) {
			int p = (k + j) % n;
			printf("%d ", a[i][p]);
		}
		printf("\n"); 
	}
	
	return 0;
 } 
