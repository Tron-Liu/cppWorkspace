#include <stdio.h>
#define Maxn 10
#define MaxSize 1000

typedef struct
{
    struct
    {
        int a[Maxn];
        int m;
    }data[MaxSize];
    int top;
}StackType;

void insert(int a[], int m, int j, int k)
{
    int i;
    for(i = m + 1; i > j; i--)
        a[i] = a[i - 1];
    a[j] = k;
}

void disp(int a[], int m)
{
    int i;
    for(i = 1; i <= m; i++)
        printf("%d", a[i]);
    printf(" ");
}

void copy(int a[], int b[], int m)
{
    int i;
    for(i = 1; i <= m; i++)
        b[i] = a[i];
}

void perm(int n)
{
    int j, m;
    int b[Maxn], c[Maxn];
    StackType st;
    st.top = -1;
    st.top++;
    st.data[st.top].a[1] = 1;
    st.data[st.top].m = 1;
    while (st.top != -1)
    {
        m = st.data[st.top].m;
        if(m == n)
        {
            disp(st.data[st.top].a, n);
			st.top--;
        }
        else
        {
            copy(st.data[st.top].a, c, m);
            st.top--;
            for ( j = 1; j <= m + 1; j++)
            {
                copy(c, b, m);
                insert(b, m, j, m+1);
                st.top++;
                copy(b, st.data[st.top].a, m+1);
                st.data[st.top].m = m + 1;
            }       
        }
    }
}

int main()
{
    int n = 3;
    printf("1 ~ %d ",n);
    perm(n);
    printf("\n");
}