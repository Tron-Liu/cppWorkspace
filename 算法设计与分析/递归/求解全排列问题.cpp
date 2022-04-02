#include <stdio.h>
#define MaxSize 10

void disp(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
    printf(" ");
}

void perm(int a[], int n, int k)
{
    int i, j;
    if(k == n)
        disp(a, n);
    else
    {
        for (i = 1; i <= n; i++)
        {
            bool has = false;
            for (j = 0; j < k; j++)
                if(a[j] == i) has = true;
            if(!has)
            {
                a[k] = i;
                perm(a, n, k+1);
            }
        }
    }    
}

int main()
{
    int n = 3;
    int a[MaxSize];
    printf(" 1~%d : ", n);
    perm(a, n, 0);
    printf("\n");
}