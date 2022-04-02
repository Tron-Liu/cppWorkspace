#include <stdio.h>

void disp(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void SelectSort(int a[], int n, int i)
{
    int j, k, tmp;
    if(i == n-1) return;
    else{
        k = i;
        for(j=i+1; j<n; j++) {
            if(a[k] > a[j]) {
                k = j;
            }
        }
        if(k != i) {
            tmp = a[k];
            a[k] = a[i];
            a[i] = tmp;
        }
        SelectSort(a, n, i+1);
    }
}

int main()
{
    int n = 10;
    int a[] = {2,5,1,7,10,6,9,4,3,8};
    printf("≈≈–Ú«∞: ");
    disp(a,n);
    printf("≈≈–Ú∫Û: ");
    SelectSort(a, n, 0);
    disp(a,n);
}