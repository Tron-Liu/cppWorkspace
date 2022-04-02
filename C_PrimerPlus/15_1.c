#include <stdio.h>
#include <limits.h>

char * itobs(int, char *);
void show_bstr(const char *);

int main()
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;

	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	//while(scanf())
}