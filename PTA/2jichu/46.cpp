#include <stdio.h>

void change(int *a, int *b);

int main()
{
	int n;
	scanf("%d", &n);
	
	int a[12] = {0};
	int i, j;
	for(i = 0; i < n; i++)		//���� 
		scanf("%d", a[i]);
	for(i = 0; i < n; i++) {	//����
		int max = a[i];
		for(j = i + 1; j < n; j++) {
			if(max < a[j]) max = a[j];
		}
		change(&max, &a[i]);	//���� 
	}
	
	int flag = 1;
	for(i = 0; i < n; i++) {
		if(flag) {
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
