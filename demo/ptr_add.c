#include <stdio.h>

int* add(int a, int b)
{
    static int* c = a + b;
    printf("%p\n", &c);
    return &c;
}

int main()
{
    int a = 1;
    int b = 2;

    int* d = add(a, b);
    printf("%p\n", d);

    return 0;
}