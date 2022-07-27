#include <stdio.h>
#include <stdlib.h>

const int N = 20;
int q[N];

void dispasolution(int n)
{
    static int count = 0;
    int i;
    printf("第 %d 个解: ", ++count);
    for (i = 1; i <= n; i++)
    {
        printf(" ( %d, %d ) ", i, q[i]);
    }
    printf("\n");
}

int place(int k, int j)
{
    int i = 1;
    while (i < k)
    {
        if((q[i] == j) || (abs(q[i] - j)) == abs(k - i))
            return 0;
        i++;
    }
    return 1;
}

//递归
void queen(int k, int n)
{
    int j;
    if(k > n)
        dispasolution(n);
    else {
        for ( j = 1; j <= n; j++) {
            if(place(k, j)) {
                q[k] = j;
                queen(k + 1, n);
            }
        }     
    }
}

int main()
{
    int n;
    printf(" 皇后问题 ( n < 20 ) n = ");
    scanf(" %d", &n);
    if(n > 20)
        printf("n值太大，不能求解\n");
    else {
        printf(" %d 皇后问题求解如下: \n", n);
        queen(1, n);
        printf("\n");
    }
}