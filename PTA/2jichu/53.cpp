#include <iostream>

int main()
{
	int a[12] = {0};
	int i;
	for(i = 0; i < 10; i++)		//���� 
		scanf("%d", &a[i]);
	
	i = 1;
	while(i < 10) {
		if(a[i]) {
			printf("%d", i);		//�����һ������ 
			a[i]--;					//������һ 
			break; 
		}
		i++;
	}
	
	for(i = 0; i < 10; i++) {		//����������� 
		while(a[i]) {
			printf("%d", i);
			a[i]--;
		}
	}
	
	return 0;
 } 
