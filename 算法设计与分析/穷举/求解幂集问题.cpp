#include <stdio.h>
#include <math.h>
#define MaxN 10

void change(int b[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        if(b[i]) b[i] = 0;
        else 
        {
            b[i] = 1;
            break;
        }
    }
}

//增量穷举法
void pset(int a[], int b[], int n)
{
    int i, k;
    int pw = pow(2, n);
    printf("集合 a 的所有子集: ");
    for ( i = 0; i < pw; i++)
    {
        printf("{ ");
        for(k = 0; k < n; k++)
            if(b[k])
                printf("%d", a[k]);
        printf(" } ");
        change(b, n);
    }
    printf("\n");
}

int main()
{
    int n = 3, i;
    int a[MaxN], b[MaxN];
    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
        b[i] = 0;
    }
    pset(a, b, n);
}