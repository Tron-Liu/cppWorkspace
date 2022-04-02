#include <stdio.h>
#define Maxn 10
#define MaxSize 1000

typedef struct                          //�����ݼ�����
{
    int data[MaxSize][Maxn];            //data[i][0]��ʾ���Ӽ��ĳ���
    int n;                              //�Ӽ�����
}PSetType;

void copy(int a[], int b[], int m)      //�� a[0..m] ���Ƶ� b[0..m]
{
    int i;
    for (i = 0; i <= m; i++)
    {
        b[i] = a[i];
    }
}

//������ٷ�
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

void disp(PSetType p)
{
    int i, j;
    for (i = 0; i < p.n; i++)
    {
        printf(" { ");
        for (j = 1; j <= p.data[i][0]; j++)
            printf(" %d ", p.data[i][j]);
        printf(" } ");
    }
}

int main()
{
    int n = 3;
    PSetType p;
    pset(n, p);
    printf("1 ~ %d ���ݼ�����: ", n);
    disp(p);
    printf("\n");
}