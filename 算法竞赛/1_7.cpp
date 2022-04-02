#include <stdio.h>

int isleap(int year);

int main()
{
	int year;
	scanf("%d", &year);
	
	if(isleap(year)) printf("yes");
	else printf("no");
	
	return 0;
}

int isleap(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) return 1;
	else return 0;
}
