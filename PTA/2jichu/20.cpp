#include <stdio.h>
#include <string.h>

int main()
{
	char s[20];
	int n = 4;
	while(n) {
		int j = 0;
		char r[4] = {0};
		
		scanf("%s", s);
		int len = strlen(s);	//��ȡ�����ַ����ĳ��� 
		
		r[j++] = s[len - 2];	//��β������ɵ��ַ����� 
		r[j++] = s[len - 1];
		r[j] = '\0';
		printf("%s", r);
		
		n--;
	}
	return 0;
 } 
