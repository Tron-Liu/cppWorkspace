#include <iostream>

template <typename T>
void Swap(T &a, T &b);

struct job
{
    char name[40];
    double salary;
    int floor;
};

template <> void Swap<job>(job &j1, job &j2);

void Show(job &j);


int main()
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << endl;
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << endl;

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job"; 

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

template <typename T>
void Swap(T a[], T b[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }   
}

// void Show(int a[])
// {
//     using namespace std;
//     cout << a[0] << a[1] << "/";
//     cout << a[2] << a[3] << "/";
//     for(int i = 4; i < Lim; i++)
//         cout << a[i];
//     cout << endl;
// }