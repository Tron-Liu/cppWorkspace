#include <stdio.h>

void change(int *a, int *b);

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int a[102] = {0};
	int i, j, p;
	
	for(i = 0; i < n; i++) 		//输入 
		scanf("%d", a + i);
		 
	for(j = 0; j < k; j++) {	//排序
		for(p = 1; p < n; p++) {
			if(a[p-1] > a[p]) change(a+p-1, a+p);
		}
	}
	
	int flag = 1;				//输出 
	for (i = 0; i < n; i++) {
		if (flag) {
			printf("%d", a[i]);
			flag = 0;
		}
		else printf(" %d", a[i]);
	}
	return 0;
 }
 
void change(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
