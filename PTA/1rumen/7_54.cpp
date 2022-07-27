#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int judge(char *num);

int main()
{
	char c;
	c = getchar();
	
	int flag = 0;
	int i = 0;
	char A[10] = {'0'}, B[10] = {'0'};
	
	while(c != '\n') {
		if(c == ' ' && !flag) {
			flag = 1;
			A[i] = '\0';
			i = 0;
			c = getchar();
			continue;
		}
		
		if(!flag) {
			A[i] = c;
			i++;
			if(i > 5) {
				A[0] = '\0';
				flag = 1;
				c = getchar();
				continue;
			}
		}
		
		if(flag) {
			B[i] = c;
			i++;
			if(i > 5) {
				B[0] = '\0';
				i = 0;
				break;
			}
		}
		
		c = getchar();
	}
	
	B[i] = '\0';
	int a;
	int b;
	
	flag = 0;
	if(!judge(A) || A[0] == '\0') {
		printf("?");
		flag = 1;
	}
	else {
		a = atoi(A);
		if(a <= 1000 && a > 0) printf("%d", a);
		else {
			printf("?");
			flag = 1;	
		}	
	}
	
	printf(" + ");
	
	if(!judge(B)|| B[0] == '\0') {
		printf("?");
		flag = 1;
	}
	else {
		b = atoi(B);
		if(b <= 1000 && b > 0) {
			printf("%d", b);
		}
		else {
			printf("?"); 
			flag = 1;	
		}
	}
	
	printf(" = ");
	
	
	if(flag) printf("?");
	else {
		a = atoi(A);
		b = atoi(B);
		printf("%d", a + b);
	}
	
	return 0;
}

int judge(char *num) {
	int i;
	
	if(strlen(num) > 4) return 0;	//超出范围 
	for(i = 0; i < strlen(num); i++) {
		if(!isdigit(num[i])) return 0; 
	} 
	return 1;
}
