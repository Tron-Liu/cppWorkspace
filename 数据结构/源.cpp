#include <iostream>
#include <stdlib.h>
using namespace std;

class A
{
	int i;

public:
	A(int a = 5)
	{
		i = a;
		cout << "ctor : i = " << i << endl;
	}
	~A()
	{
		cout << "dtor : i = " << i << endl;
	}
};

int main()
{
	A a, b(10);
	system("pause");
	return 0;
}