#include <stdio.h>

int isLeap(int year);

int main()
{
	int D1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int D2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int year, month, day;
	scanf("%d/%d/%d", &year, &month, &day);
	
	int i, sum = 0;
	if(isLeap(year)) {
		for(i = 0; i < month - 1; i++) sum += D2[i];
		printf("%d", sum + day);
	}
	else{
		for(i = 0; i < month - 1; i++) sum += D1[i];
		printf("%d", sum + day);
	}
	
	return 0;
}

int isLeap(int year) {
	if((year%4 == 0 && year%100 != 0) || year%400 == 0) return 1;
	else return 0;
}
