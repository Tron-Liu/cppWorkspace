#include <stdio.h>
#include <string.h>

int main()
{
    char s[82];
    char c[2];
    char t;
    t = getchar();
    
    int i = 0;
    while(t != '\n') {
    	s[i] = t;
    	i++;
    	t = getchar();
	}
	
	c[0] = getchar();
    
    int count = 0;
    for(i = 0; i < strlen(s); i++) {
        if(s[i] == c[0]) count++;
    }
    
    printf("%d", count);
    
    return 0;
}
