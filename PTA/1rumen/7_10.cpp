#include <stdio.h>
#include <math.h>
 
int main()
{
	int s[12] = {0};
	char c;
	int flag = 0;		//第一位是负号置1，不是负号置1 
	scanf("%c", &c);
	int i = 0;
	while(c != '#') {
		if(c >= '0' && c <= '9') {
			s[i] = (int)(c - '0');
			i++;
		}
		else if(c >= 'a' && c <= 'f') {
			s[i] = (int)(c - 'a' + 10);
			i++;
		}
		else if(c >= 'A' && c <= 'F') {
			s[i] = (int)(c - 'A' + 10);
			i++;
		}
		if(c == '-' && !flag && !i) {
			flag = 1;
		}
		scanf("%c", &c);
	}
	
	int j, k = 1;
	long sum = 0;
	if(i > 0) sum = s[i-1];
	for(j = i-2; j >= 0; j--) {
		sum += s[j] * pow(16, k);
		k++;
	}
	
    if(flag) sum = -sum;
	printf("%ld", sum);
	return 0;
 } 
