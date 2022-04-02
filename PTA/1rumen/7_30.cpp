#include <stdio.h>

int main()
{
	double Open, High, Low, Close;
	scanf("%lf %lf %lf %lf", &Open, &High, &Low, &Close);
	if(Close < Open) printf("BW-Solid");
	else if(Close > Open) printf("R-Hollow");
	else printf("R-Cross");
	
	int flag = 0;
	if(Low < Open && Low < Close) {
		printf(" with Lower Shadow");
		flag = 1;
	}
	if(High > Open && High > Close) {
		if(flag) printf(" and Upper Shadow");
		else printf(" with Upper Shadow");
	}
	
	return 0;
 } 
