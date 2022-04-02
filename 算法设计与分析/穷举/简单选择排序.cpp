#include <stdio.h>

void disp(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void SelectSort(int a[], int n)
{
    int i, j, k;
    int tmp;
    for ( i = 0; i < n-1; i++)
    {
        k = i;
        for ( j = i + 1; j < n; j++)
        {
            if(a[j] < a[k])
                k = j;
        }
        if(k != i)
        {
            tmp = a[k];
            a[k] = a[i];
            a[i] = tmp;
        }
    }
}

int main()
{
    int n = 10;
    int a[] = {2,5,1,7,10,6,9,4,3,8};
    printf("排序前: ");
    disp(a,n);
    printf("排序后: ");
    SelectSort(a,n);
    disp(a,n);
}