#include <stdio.h>

int main()
{
	int hour, minute, second;
	int n;
	scanf("%d:%d:%d", &hour, &minute, &second);
	scanf("%d", &n);
	
	int carry = 0;
	int temp = second + n;
	second = temp % 60;
	carry = temp / 60;
	
	temp = minute + carry;
	minute = temp % 60;
	carry = temp / 60;
	
	temp = hour + carry;
	hour = temp % 24;
	
	printf("%02d:%02d:%02d", hour, minute, second);
	
	return 0;
 } 
