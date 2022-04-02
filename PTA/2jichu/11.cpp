#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int a);

int main()
{
	int n;
	cin >> n;
	
	int a = 2;
	int count = 0;		//统计 
	for(int i = 3; i <= n; i += 2)
	{
		if(isprime(i))
		{
			if(i - a == 2)	count++;
			a = i;
		}
	}
	cout << count;
	return 0;
}

bool isprime(int a)
{
	int b = sqrt(a);
	for(int i = 2; i <= b; i++)
	{
		if(a % i == 0)				//非素数
			return false; 
	}
	return true;
} 
