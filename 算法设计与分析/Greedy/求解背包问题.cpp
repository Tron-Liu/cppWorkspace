#include <stdio.h>
#define MaxSize 20

void disp(double a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %g\t", a[i]);
    }
    printf("\n");
}

int Partition(double w[], double v[], int s, int t)
{
    int i = s, j = t;
    double tmp1 = w[s], tmp2 = v[s];
    while (i != j)
    {
        while (j > i && v[j]/w[j] <= tmp2/tmp1)
            j--;
        w[i] = w[j]; v[i] = v[j];
        while (i < j && v[i]/w[i] >= tmp2/tmp1)
            i++;
        w[j] = w[i]; v[j] = v[i];
    }
    w[i] = tmp1; v[i] = tmp2;
    return i;
}

void QuickSort(double w[], double v[], int s, int t)
{
    int i;
    if (s < t)
    {
        i = Partition(w, v, s, t);
        QuickSort(w, v, s, i-1);
        QuickSort(w, v, i+1, t);
    }
}

double knap(double W, double w[], double v[], int n, double x[])
{
    int i;
    double V = 0;
    double weight = W;
    for (i = 0; i < n; i++)
        x[i] = 0;
    i = 0;
    while (w[i] < weight)
    {
        x[i] = 1;
        weight -= w[i];
        V += v[i];
        i++;
    }
    if (weight > 0)
    {
        x[i] = weight / w[i];
        V += x[i] * v[i];
    }
    return V;
}

int main()
{
    int n = 5, i;
    double x[MaxSize];
    double W = 100, V;
    double w[] = {10, 20, 30, 40, 50};
    double v[] = {20, 30, 66, 40, 60};
    QuickSort(w, v, 0, n-1);
    printf("按 v/w 递减排序并求解：\n");
    printf("i: ");
    for (i = 0; i < n; i++)
        printf("%d\t", i);
    printf("\n");
    printf("v: "); disp(v, n);
    printf("w: "); disp(w, n);
    V = knap(W, w, v, n, x);
    printf("x: "); disp(x, n);
    printf("总价值 = %g\n", V);
}