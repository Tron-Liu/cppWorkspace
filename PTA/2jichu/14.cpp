#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int count[12] = {0};
	char c;
	int i;
	
	getchar();
	while((c = getchar()) != '\n') {	//ͳ�� 
		if(c == ' ') continue;			//�����ո��ַ� 
		else {
			i = (c - '0');
			count[i]++;
		}
	}
	
	int max = 0;
	for(i = 0; i < 10; i++)				//�ҵ������� 
		if(count[i] > max) max = count[i];
	
	printf("%d:", max);				//��� 
	for(i = 0; i < 10; i++) {
		if(count[i] == max) printf(" %d", i);
	} 
	return 0; 
}
