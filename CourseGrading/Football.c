#include <stdio.h>

int main()
{
    char s[102];
    scanf("%s", s);
    int i = 1, pos = 0;
    int flag = 1;
    while (s[i] != '\0')
    {
        if(s[i] == s[pos]) flag++;
        else {
            pos = i;
            flag = 1;
        }
        if(flag == 7) {
            printf("YES");
            return 0;
        }
        i++;
    }
    printf("NO");
    return 0;
}