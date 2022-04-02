#include <iostream>

template <typename T>
void Swap(T &a, T &b);

int main()
{
    using namespace std;
    int i = 10;
    int j = 20;
    Swap(i,j);
    cout << "i j = " << i << " " << j << endl;

    double x = 30.0;
    double y = 40.0;
    Swap(x,y);
    cout << "x y = " << x << " " << y << endl;

    return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}