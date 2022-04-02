#include <stdio.h>
#include <string.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    char str[100002];
    scanf("%s", str);

    int i = 0, j = 1;
    int flag = 0;

    while (i < k) {
        j = j % n;      //循环处理字符串
        if(j == 0) {
            j++;        //j 从 1 开始
            flag = i;
        }
        //找到 x
        if(str[j-1] == '4' && str[j] == '7') {
            if(j % 2 == 1) {
                str[j] = '4';
                printf("\n%s\n", str);
            }       //奇数情况
            else {
                str[j-1] = '7';
                printf("\n%s\n", str);
            }
            i++;
        }
        //整个字符串都找不到 x 时
        if(j == n - 1 && flag == i) break;

        j++;
    }

    printf("\n%s\n", str);
    return 0;
}