#include <stdio.h>

#define MAXK 10
int n, k;

void dispcomb(int a[])
{
    int j;
    for (j = 0; j < k; j++)
        printf("%3d", a[j]);
    printf("\n");
}

void comb(int a[], int n, int k)
{
    int i;
    if (k == 0)
        dispcomb(a);
    else
    {
        for (i = k; i <= n; i++)
        {
            a[k - 1] = i;
            comb(a, i-1, k-1);
        }   
    }
}

int main()
{
    int a[MAXK];
    n = 5;
    k = 3;
    comb(a, n, k);
}