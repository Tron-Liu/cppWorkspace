#include <stdio.h>
#define MaxSize 10

typedef struct 
{
    int start;
    int end;
} IntervalType;

int Partition(IntervalType a[], int s, int t)
{
    int i = s, j = t;
    IntervalType tmp = a[s];
    while (i != j)
    {
        while (j > i && a[j].end >= tmp.end)
            j--;
        a[i] = a[j];
        while (i < j && a[i].end <= tmp.end)
            i++;
        a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}

void QuickSort(IntervalType a[], int s, int t)
{
    int i;
    if (s < t)
    {
        i = Partition(a, s, t);
        QuickSort(a, s, i-1);
        QuickSort(a, i+1, t);
    }
}

int maxCover(IntervalType x[], int n, IntervalType y[])
{
    int i, m = 0;
    int j = 0;
    y[0] = x[0];
    for(i=1; i<n; i++)
    {
        if (x[i].start >= x[j].end)
        {
            m++;
            y[m] = x[i];
            j = i;
        }
    }
    return m + 1;
}

void disp(IntervalType a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("[ %d, %d]", a[i].start, a[i].end);
    }
    printf("\n");
}

int main()
{
    int n, m;
    IntervalType y[MaxSize];
    IntervalType x[] = {{2,6}, {1,4}, {3,6}, {3,7}, {6,8}, {2,4}, {3,5}};
    n = 7;
    printf("before: "); disp(x, n);
    QuickSort(x, 0, n-1);
    printf("after: "); disp(x, n);
    m = maxCover(x, n, y);
    printf("result: \n");
    printf("%d\n", m);
    printf("range: "); disp(y, m);
}