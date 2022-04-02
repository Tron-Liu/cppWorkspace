#include <stdio.h>

void disp(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void BubbleSort(int a[], int n)
{
    int i, j;
    int tmp;
    bool exchange;
    for(i = 0; i < n - 1; i++)
    {
        exchange = false;
        for ( j = n; j > i; j--)
        {
            if(a[j] < a[j-1])
            {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = a[j];
                exchange = true;
            }
        }
        if(exchange == false) return ;
    }
}

int main()
{
    int n = 10;
    int a[] = {1,2,5,5,7,10,6,9,4,3,8};
    printf("排序前: ");
    disp(a,n);
    printf("排序后: ");
    BubbleSort(a, n);
    disp(a,n);
}