#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();			//清除第一行末尾的换行符 
	
	string s;
	getline(cin, s);
	
	int len = s.length();
	int m = len % n;
	
	if(m == 0) m = n;
	//往 s 后面填充空格，使长度刚好整除 n
	for(int i = 1; i <= n-m; i++) 
		s[len++] = ' ';
	
	len--;	
	for(int i = n - 1; i >= 0; i--)
	{
		int a = len - i;
		while(a >= 0)
		{
			cout << s[a];
			a = a - n;
		}
		cout << endl;
	}
	return 0;
}
