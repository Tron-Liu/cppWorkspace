#include <stdio.h>

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

int main()
{
    int n = 10;
    int a[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    printf("before: ");  disp(a, n);
    QuickSort(a, 0, n-1);
    printf("after: ");  disp(a, n);
}