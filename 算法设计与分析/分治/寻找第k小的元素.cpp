#include <stdio.h>

int QuickSelect(int a[], int s, int t, int k)
{
    int i = s, j = t;
    int tmp;
    if (s < t)
    {
        tmp = a[s];
        while (i != j)
        {
            while (j > i && a[j] >= tmp)
                j--;
            a[i] = a[j];
            while(i < j && a[i] <= tmp)
                i++;
            a[j] = a[i];
        }
        a[i] = tmp;
        if(k - 1 == i) return a[i];
        else if(k-1 < i) return QuickSelect(a, s, i-1, k);
        else return QuickSelect(a, i+1, t, k);
    }
    else if (s == t && s == k-1) 
        return a[k-1];
}

int main()
{
    int n = 10, k;
    int e;
    int a[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    for (k = 1; k <= n; k++)
    {
        e = QuickSelect(a, 0, n-1, k);
        printf("%d %d\n", k, e);
    }
    
}