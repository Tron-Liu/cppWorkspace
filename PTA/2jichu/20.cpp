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
		int len = strlen(s);	//获取输入字符串的长度 
		
		r[j++] = s[len - 2];	//句尾汉字组成的字符数组 
		r[j++] = s[len - 1];
		r[j] = '\0';
		printf("%s", r);
		
		n--;
	}
	return 0;
 } 
