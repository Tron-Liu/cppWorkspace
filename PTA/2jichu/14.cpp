#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int count[12] = {0};
	char c;
	int i;
	
	getchar();
	while((c = getchar()) != '\n') {	//统计 
		if(c == ' ') continue;			//丢弃空格字符 
		else {
			i = (c - '0');
			count[i]++;
		}
	}
	
	int max = 0;
	for(i = 0; i < 10; i++)				//找到最大次数 
		if(count[i] > max) max = count[i];
	
	printf("%d:", max);				//输出 
	for(i = 0; i < 10; i++) {
		if(count[i] == max) printf(" %d", i);
	} 
	return 0; 
}
