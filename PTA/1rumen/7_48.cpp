#include <stdio.h>
#include <string.h>

int main()
{
	char s[40], r[20];
    int j = 0;
	for(int i = 0; i < 4; i++) {
		scanf("%s", s);
        r[j++] = s[0];
        r[j++] = s[1];
	}
    r[j] = '\0';
    printf("%s", r);
	return 0;
}
