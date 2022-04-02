#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char s1[10002], s2[10002];
    int sum1 = 0, sum2 = 0;
    scanf("%s", s1);
    scanf("%s", s2);
    
    if(strcmp(s1, s2) == 0) {
        printf("0");
        return 0;
    }

    int i = 0;
    while(s1[i] != '\0') {
        if(s1[i] == '4') sum1++;
        
        if(s2[i] == '4') sum2++;
        i++;
    }

    printf("%d\n", i);
    int a = sum1 - sum2;


    if(a == 0) {
        sum1 = fabs(sum1);
    }
    else if(a > 0) printf("%d", a);
    else printf("%d", -a);
    return 0;
}