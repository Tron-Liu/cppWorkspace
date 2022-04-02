#include <iostream>
#define MaxSize 12
using namespace std;

struct People{
    char gender;
    float height;
};

int main()
{
    People p[MaxSize];
    int N;
    cin >> N; 
    int i;
    for(i = 0; i < N; i++)
        cin >> p[i].gender >> p[i].height;
    for(i = 0; i < N; i++) {
        if(p[i].gender == 'F') printf("%.2f\n", p[i].height * 1.09);
        else printf("%.2f\n", p[i].height / 1.09);
    }
    
    return 0;
}
