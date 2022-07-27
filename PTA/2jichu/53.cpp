#include <iostream>

int main()
{
	int a[12] = {0};
	int i;
	for(i = 0; i < 10; i++)		//输入 
		scanf("%d", &a[i]);
	
	i = 1;
	while(i < 10) {
		if(a[i]) {
			printf("%d", i);		//输出第一个数字 
			a[i]--;					//个数减一 
			break; 
		}
		i++;
	}
	
	for(i = 0; i < 10; i++) {		//输出其他数字 
		while(a[i]) {
			printf("%d", i);
			a[i]--;
		}
	}
	
	return 0;
 } 
