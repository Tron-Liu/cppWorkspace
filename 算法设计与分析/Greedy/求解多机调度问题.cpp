#include <stdio.h>
#define M 20
#define N 20

typedef struct
{
    int seq[N];
    int sumt;
    int num;
}PlanType;

int Partition(int T[], int P[], int s, int t)
{
    int i = s, j = t;
    int tmpt = T[s], tmpp = P[s];
    while (i != j)
    {
        while (j > i && T[j] <= tmpt)
            j--;
        T[i] = T[j];
        P[i] = P[j];
        while (i < j && T[i] >= tmpt)
            i++;
        T[j] = T[i];
        P[j] = P[j];
    }
    T[i] = tmpt;
    P[i] = tmpp;
    return i;
}

void QuickSort(int T[], int P[], int s, int t)
{
    int i;
    if (s < t)
    {
        i = Partition(T, P, s, t);
        QuickSort(T, P, s, i-1);
        QuickSort(T, P, i+1, t);
    }
}

void disp(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%3d", a[i]);
    printf("\n");
}

void dispschedule(PlanType S[], int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        printf("机器 %d 分配的作业序列：", i + 1);
        for (j = 0; j < S[i].num; j++) {
            printf("%d ", S[i].seq[j]);
        }
        printf(",加功总时间为 %d\n",S[i].sumt);
    }
}

void Mscheduling(int P[], int T[], PlanType S[], int n, int m) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        S[i].num = S[i].sumt = 0;
        S[i].seq[S[i].num] = P[i];
        S[i].sumt = T[i];
        S[i].num++;
    }
    for (i = m; i < n; i++) {
        j = 0;
        for(k = 1; k < m; k++)
            if(S[k].sumt < S[j].sumt) j = k;
        S[j].seq[S[j].num] = P[i];
        S[j].sumt += T[i];
        S[j].num++;
    }   
}

int main()
{
    int n = 7, m = 3;
    int P[M] = {1, 2, 3, 4, 5, 6, 7};
    int T[M] = {2, 14, 4, 16, 6, 5, 3};
    PlanType S[M];
    printf("排序前：\n");
    printf("T: "); disp(T, n);
    printf("P: "); disp(P, n);
    QuickSort(T, P, 0, n-1);
    printf("排序后：\n");
    printf("T: "); disp(T, n);
    printf("P: "); disp(P, n);
    printf("调度方案如下：\n");
    Mscheduling(P, T, S, n, m);
    dispschedule(S, m, n);

    return 0;
}