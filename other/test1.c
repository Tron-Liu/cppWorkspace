#include <stdio.h>

int solution(int n) {
    int result;
    if(n < 0) {
        result = 0;
    }
    else {
        int a[12] = {0};
        int i = 0;
        while(n > 0) {
            a[i] = n % 10;
            n = n / 10;
            i++;
        }
        for(int j = 0, k = i; j != k; j++, k--) {
            if(a[j] == a[k]) continue;
            else {
                result = 0;
                return result;
            }
        }
        result = 1;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", solution(n));

    return 0;
}