#include <stdio.h>
#include <math.h>

int is_prime(int m);

int main()
{
	int n;
	scanf("%d", &n);
	
	int count = 0;			//��¼����
	while(count < 10) {
		n--;
		if(is_prime(n)) {	//������ 
			printf("%6d", n);
			count++; 
		}
		else continue;
	}
	
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
