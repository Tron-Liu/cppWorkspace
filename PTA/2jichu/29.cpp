#include <stdio.h>

int main()
{
    int num[4] = {0};       //num[0]:G num[1]:P num[2]:L num[3]:T
    char c = getchar();
    while(c != '\n') {
        switch (c) {
            case 'G': num[0]++; break;
            case 'g': num[0]++; break;
            case 'P': num[1]++; break;
            case 'p': num[1]++; break;
            case 'L': num[2]++; break;
            case 'l': num[2]++; break;
            case 'T': num[3]++; break;
            case 't': num[3]++; break;
        }
        c = getchar();
    }
    while(num[0] || num[1] || num[2] || num[3]) {
        if(num[0]) {
            printf("G");
            num[0]--;
        }
        if(num[1]) {
            printf("P");
            num[1]--;
        }
        if(num[2]) {
            printf("L");
            num[2]--;
        }
        if(num[3]) {
            printf("T");
            num[3]--;
        }
    }
    return 0;
}
