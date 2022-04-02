#include <stdio.h>

void prepart(int &s, int &t)
{
    int m = (s + t) / 2;
    t = m;
}

void postpart(int &s, int &t)
{
    int m = (s + t) / 2;
    if((s + t) % 2 == 0)
        s = m;
    else
        s = m + 1;
}

int midnum(int a[], int s1, int t1, int b[], int s2, int t2)
{
    int m1, m2;
    if(s1 == t1 && s2 == t2)
        return a[s1] < b[s2] ? a[s1] : b[s2];
    else {
        m1 = (s1 + t1) / 2;
        m2 = (s2 + t2) / 2;
        if (a[m1] == b[m2])
            return a[m1];
        if (a[m1] < a[m2])
        {
            postpart(s1, t1);
            prepart(s2, t2);
            return midnum(a, s1, t1, b, s2, t2);
        }
        else
        {
            prepart(s1, t1);
            postpart(s2, t2);
            return midnum(a, s1, t1, b, s2, t2);
        }   
    }
}

int main()
{
    int a[] = {11, 13, 15, 17, 19};
    int b[] = {2, 4, 6, 8, 20};
    printf("midnum: %d", midnum(a, 0, 4, b, 0, 4));
}