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

void pset(int n, PSetType &p)
{
    int i, j, m;
    int a[Maxn];
    p.data[0][0] = 0;
    p.n = 1;
    for (i = 1; i <= n; i++)
    {
        m = p.n;
        for(j = 0; j < m; j++)
        {
            copy(p.data[j],a,p.data[j][0]);
            a[0]++;
            a[a[0]] = i;
            copy(a, p.data[p.n], a[0]);
            p.n++;
        }
    }
}

void knap(PSetType p, int w[], int v[], int W)
{
    int i, j;
    int sumw, sumv;
    int maxi, maxsumw = 0, maxsumv = 0;
    printf(" ���\tѡ����Ʒ\t������\t����ֵ\t�ܷ�װ��\n");
    for (i = 0; i < p.n; i++)
    {
        printf(" %d\t", i+1);
        sumw = sumv = 0;
        printf("{");
        for (j = 1; j <= p.data[i][0]; j++)
        {
            printf("%d", p.data[i][j]);
            sumw += w[p.data[i][j] - 1];
            sumv += v[p.data[i][j] - 1];
        }
        printf("}\t\t%d\t%d\t", sumw, sumv);
        if(sumw <= W)
        {
            printf("��\n");
            if(sumv > maxsumv)
            {
                maxsumw = sumw;
                maxsumv = sumv;
                maxi = i;
            }
        }
        else printf("��\n");
    }
    printf("��ѷ���Ϊ ");
    printf("ѡ����Ʒ: ");
    printf("{ ");
    for(j=1; j<=p.data[maxi][0]; j++)
        printf("%d ", p.data[maxi][j]);
    printf("},");
    printf("������: %d, �ܼ�ֵ: %d\n", maxsumw, maxsumv);
}

int main()
{
    int n = 4, W = 7;
    int w[] = {5, 3, 2, 1};
    int v[] = {4, 4, 3, 1};
    PSetType p;
    pset(n, p);
    printf("0/1��������ⷽ��\n", n);
    knap(p, w, v, W);
    printf("\n");
}