#include <stdio.h>
#include <math.h>

int is_prime(int m);

int main()
{
	int n;
	scanf("%d", &n);
	
	int i = 1, m = 2;
	int count = 0;
	while(i < n) {
		m *= 2;
		if(is_prime(m - 1)) {
			printf("%d\n", m - 1);
			count++;
		}
		i++;
	}
	if(!count) printf("None");
	
	return 0;
}

int is_prime(int m) {		//�ж�һ�����Ƿ������� 
	int a = sqrt(m);
	if(!(m % 2)) {			//�����ж� 2 
		return 0;			//���� 0 ��ʾ��������	
	}
	
	for(int i = 3; i <= a; i+=2) {
		if(m % i) continue;
		else return 0;
	}
	return 1;
}
