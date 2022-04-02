#include <stdio.h>
#define MaxSize 100

struct 
{
    int n;
    int f;
    int tag;
}St[MaxSize];

int top = -1;

int fun2(int n)
{
    top++;
    St[top].n = n; St[top].tag = 1;
    while (top > -1)
    {
        if (St[top].tag == 1)
        {
            if (St[top].n == 1)
            {
                St[top].f = 1;
                St[top].tag = 0;
            }
            else
            {
                top++;
                St[top].n = St[top - 1].n - 1;
                St[top].tag = 1;
            }
        }
        else if (St[top].tag == 0)
        {
            St[top - 1].f = St[top].n * St[top].f;
            St[top - 1].tag = 0;
            top--;
        }
        if(top == 0 && St[top].tag == 0)
            break;
    }
    return(St[top].f);
}