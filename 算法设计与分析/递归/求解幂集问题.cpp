#include <stdio.h>
#define Maxn 10
#define MaxSize 1000

typedef struct
{
    int data[MaxSize][Maxn];
    int n;
}PSetType;

void copy(int a[], int b[], int m)
{
    int i;
    for (i = 0; i <= m; i++)
    {
        b[i] = a[i];
    }
}

void addi(PSetType &p, int i)
{
    int j, m;
    int a[Maxn];
    m = p.n;
    for (j = 0; j < m; j++)
    {
        copy(p.data[j], a, p.data[j][0]);
        a[0]++;
        a[a[0]] = i;
        copy(a, p.data[p.n], a[0]);
        p.n++;
    }
}

void pset(int i, int n, PSetType &p)
{
    if(i > n)
    {
        printf("1 ~ %d：", n);
        disp(p);
        printf("\n");
    }
    else
    {
        addi(p, i);
        pset(i + 1, n, p);
    }
}

void disp(PSetType p)
{
    int i, j;
    for (i = 0; i < p.n; i++)
    {
        printf("{ ");
        for (j = 1; j <= p.data[i][0]; j++)
            printf(" %d ", p.data[i][j]);
        printf(" }");
    }
}

int main()
{
    int n = 3;
    PSetType p;
    p.data[0][0] = 0;
    p.n = 1;
    pset(1, n, p);
}