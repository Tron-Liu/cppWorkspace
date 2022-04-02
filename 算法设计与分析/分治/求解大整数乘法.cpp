#include <stdio.h>
#include <math.h>
#define MAXN 20

void Left(int A[], int B[], int n)
{
    int i;
    for (i = 0; i < MAXN; i++)
        B[i] = 0;
    for (i = n/2; i <= n; i++)
        B[i - n/2] = A[i];
}

void Right(int A[], int B[], int n)
{
    int i;
    for (i = 0; i < MAXN; i++)
        B[i] = 0;
    for (i = 0; i < n/2; i++)
        B[i] = A[i];
    B[i] = '\0';
}

long Trans2to10(int A[])
{
    int i;
    long s = A[0], x = 1;
    for (i = 1; i < MAXN; i++)
    {
        x = 2 * x;
        s += A[i] * x;
    }
    return s;
}

void Trans10to2(int x, int A[])
{
    int i, j = 0;
    while (x > 0)
    {
        A[j] = x % 2;
        j++;
        x = x / 2;
    }
    for (i = j; i < MAXN; i++)
        A[i] = 0;
}

void disp(int A[])
{
    int i;
    for (i = MAXN - 1; i >= 0; i--)
        printf("%d", A[i]);
    printf("\n");
}

void MULT(int X[], int Y[], int Z[], int n)         // Z = X*Y
{
    int i;
    long e, e1, e2, e3, e4;
    int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
    int m1[MAXN], m2[MAXN], m3[MAXN], m4[MAXN];
    for (i = 0; i < MAXN; i++)
        Z[i] = 0;
    if(n == 1)                      //递归出口
    {
        if(X[0]==1 && Y[0]==1) Z[0] = 1;
        else Z[0] = 0;
    }
    else
    {
        Left(X, A, n);
        Right(X, B, n);
        Left(Y, C, n);
        Right(Y, D, n);
        MULT(A, C, m1, n/2);
        MULT(A, D, m2, n/2);
        MULT(B, C, m3, n/2);
        MULT(B, D, m4, n/2);
        e1 = Trans2to10(m1);
        e2 = Trans2to10(m2);
        e3 = Trans2to10(m3);
        e4 = Trans2to10(m4);
        e = e1 * (int)pow(2, n) + (e2 + e3) *(int)pow(2, n/2) + e4;
        Trans10to2(e, Z);
    }
}

void trans(char a[], int n, int A[])
{
    int i;
    for (i = 0; i < n; i++)
        A[i] = int (a[n - 1 - i]- '0');
    for(i = n; i < MAXN; i++)
        A[i] = 0;
}

int main()
{
    long e;
    char a[] = "10101100";
    char b[] = "10010011";
    int X[MAXN], Y[MAXN], Z[MAXN];
    int n = 8;
    trans(a, n, X);
    trans(b, n, Y);
    printf("X:"); disp(X);
    printf("Y:"); disp(Y);
    printf("Z = X * Y\n");
    MULT(X, Y, Z, n);
    printf("Z:"); disp(Z);
    e = Trans2to10(Z);
    printf("Z, 10: %ld", e);
}