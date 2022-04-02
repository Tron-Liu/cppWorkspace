#include <stdio.h>

long maxSubSum1(int a[], int n)
{
    int i, j, k;
    long maxSum = a[0], thisSum;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            thisSum = 0;
            for (k = i; k <= j; k++)
                thisSum += a[k];
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

long maxSubSum2(int a[], int n)
{
    int i, j;
    long maxSum = a[0], thisSum;
    for(i = 0; i < n; i++)
    {
        thisSum = 0;
        for (i = 0; i < n; j++)
        {
            thisSum += a[j];
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

int maxSubSum4(int a[], int n)
{
    int i, maxSum = 0, thisSum = 0;
    for(i = 0; i < n; i++)
    {
        thisSum += a[i];
        if(thisSum < 0)
            thisSum = 0;
        if(maxSum < thisSum)
            maxSum = thisSum;
    }
    return maxSum;
}

int main()
{
    int a[] = {-2, 11, -4, 13, -5, -2}, n = 6;
    int b[] = {-6, 2, 4, -7, 5, 3, 2, -1, 6, -9, 10, -2}, m = 12;
    printf("%d\n", maxSubSum4(a, n));
    printf("%d\n", maxSubSum4(b, m));
}