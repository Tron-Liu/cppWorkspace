#include <iostream>
#include <array>
using namespace std;

const int SIZE = 10;

int main()
{
    array<double, SIZE> a;
    int i;
    double sum = 0;
    
    for ( i = 0; i < SIZE; i++)
    {
        while(!(cin >> a[i])) {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please enter a number:";
        }
    }
    
    int j;
    for(j = 0; j < a.size(); j++) {
        sum += a[j];
    }

    double average = 0;
    average = sum / a.size();

    int count = 0;

    for(j = 0; j < a.size(); j++) {
        if(a[j] > average) count++;
    }

    cout << "average is: " << average << endl;
    cout << "count is: " << count << endl;
    return 0;
}