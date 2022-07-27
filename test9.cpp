#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int a = 128;
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum = sum + (int)(s[i] - '0') * a;

		if (a == 1)
		{
			a = 128;
			if (i < 8)
				cout << sum;
			else
				cout << "." << sum;
			sum = 0;
			continue;
		}

		a /= 2;
	}
	return 0;
}
