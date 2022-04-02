#include <stdio.h>
#define MaxSize 10

void disp(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int Partition(int a[], int s, int t)
{
    int i = s, j = t;
    int tmp = a[s];
    while (i != j)
    {
        while (j > i && a[j] >= tmp)
            j--;
        a[i] = a[j];
        while (i < j && a[i] <= tmp)
            i++;
        a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}

void QuickSort(int a[], int s, int t)
{
    int i;
    if (s < t)
    {
        i = Partition(a, s, t);
        QuickSort(a, s, i-1);
        QuickSort(a, i+1, t);
    }
}

int minSegment(int x[], int n, int k, int y[])
{
    int i, m = 0, tmp;
    QuickSort(x, 0, n-1);
    tmp = x[0];
    y[0] = x[0];
    for (i = 1; i < n; i++)
    {
        if(x[i] - tmp > k)
        {
            tmp = x[i];
            m++;
            y[m] = x[i];
        }
    }
    return m+1;
}

int main()
{
    int x[] = {2, 4, 1, 6, -2, 5, 3};
    int y[MaxSize];
    int n = 7, k = 3, m;
    printf("before: "); disp(x, n);
    QuickSort(x, 0, n - 1);
    printf("after: "); disp(x, n);
    m = minSegment(x, n, k, y);
    printf("result: ");
    printf("%d\n", m);
    disp(y, m);
}