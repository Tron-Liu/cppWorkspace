#include <stdio.h>
#include <string.h>

int main()
{
    int c[26] = {0};
    char s1[100002], s2[100002];
    scanf("%s %s", s1, s2);

    if(strlen(s1) != strlen(s2)) {      //字符串长度不等
        printf("NO");
        return 0;
    }
    
    int i = 0;                          //字符串长度相等
    while (s1[i] != '\0') {
        c[s1[i]-'a']++;
        c[s2[i]-'a']--;
        i++;
    }
    for(i = 0; i < 26; i++) {
        if(c[i] != 0) {                 //字符个数不等
            printf("NO");
            return 0;
        }
    }

    i = 0;                              //只交换一次等价于两个地方不等
    int flag = 0;

    while(s1[i] != '\0') {
        if(s1[i] != s2[i]) flag++;
        i++;
    }
    if(flag == 2) printf("YES");
    else printf("NO");
    return 0;
}