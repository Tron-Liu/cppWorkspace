#include <stdio.h>

bool loading(int W, int w[], int i)
{
    int r;
    r = W -w[i];                                //ȡ w[i] �����µ�����
    if (r == 0)
        return true;
    else if(r > 0)
    {
        if (i > 0)
        {
            if(loading(r, w, i-1))
                return true;
            else
                return loading(W, w, i-1);
        }
        else
            return false;
    }
    else
    {
        if(i > 0)
            return loading(W, w, i-1);
        else
            return false;
    }
}

int main()
{
    int w[] = {2, 9, 5, 6, 3};
    int n = 5, W;
    W = 4;
    printf("W = %d ʱ %s\n", W, (loading(W, w, n-1) ? "���ڽ�":"û�н�"));
    W = 10;
    printf("W = %d ʱ %s\n", W, (loading(W, w, n-1) ? "���ڽ�":"û�н�"));
    W = 12;
    printf("W = %d ʱ %s\n", W, (loading(W, w, n-1) ? "���ڽ�":"û�н�"));
    W = 21;
    printf("W = %d ʱ %s\n", W, (loading(W, w, n-1) ? "���ڽ�":"û�н�"));
}