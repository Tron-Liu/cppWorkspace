#include <stdio.h>
#define MaxSize 100

struct {
    int n;
    char x, y, z;
    int tag;
}St[MaxSize];

int top = -1;

//非递归
void Hanoi1(int n, char x, char y, char z)
{
    int n1, x1, y1, z1;
    if(n <= 0)
    {
        printf("��������n");
        return;
    }
    else if(n == 1)
    {
        printf("�� %c �ϵ� 1 ����Ƭֱ���ƶ��� %c \n", x, z);
        return;
    }
    top++;
    St[top].n = n;
    St[top].x = x; St[top].y = y; St[top].z = z;
    St[top].tag = 1;
    while (top > -1)
    {
        if (St[top].tag == 1 && St[top].n > 1)
        {
            n1 = St[top].n;
            x1 = St[top].x; y1 = St[top].y; z1 = St[top].z;
            top--;
            top++;
            St[top].n = n1 - 1; St[top].x = y1; St[top].y = x1; St[top].z = z1;
            if(n1 - 1 == 1)
                St[top].tag = 0;
            else
                St[top].tag = 1;
            top++;
            St[top].n = n1; St[top].x = x1; St[top].z = z1; St[top].tag = 0;
            top++;
            St[top].n = n1 - 1; St[top].x = x1; St[top].y = z1; St[top].z = y1;
            if(n1 - 1 == 1)
                St[top].tag = 0;
            else
                St[top].tag = 1;
        }
        else if (St[top].tag == 0)
        {
            printf("\t���� %d ����Ƭ�� %c �ƶ��� %c \n", St[top].n, St[top].x, St[top].z);
            top--;
        }   
    }
}

int main()
{
    Hanoi1(5,'X','Y','Z');
}