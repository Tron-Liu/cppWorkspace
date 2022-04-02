#include <stdio.h>

int main()
{
    int a, i = 0, j = 0;
    scanf("%d", &a);
    char c[4] = {'a', 'b', 'c', 'd'};
    while (i < a)
    {
        j = j % 4;
        printf("%c", c[j]);
        j++; i++;
    }
    return 0;
}