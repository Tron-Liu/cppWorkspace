#include <iostream>
using namespace std;

int main()
{
	int k;
	cin >> k;
	
	string s;
	cin >> s;
	
	int count = 1;
	char c = s[0];
	for(int i = 1; i < s.length(); i++)
	{
		if(count == k)
		{
			cout << c;
			return 0;
		}
		if(s[i] == c)			//����������� 
			count++;
		else
			count = 1;
		c = s[i];
	}
	cout << "No";
	return 0;
}
