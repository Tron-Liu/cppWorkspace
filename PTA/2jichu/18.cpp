#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();			//�����һ��ĩβ�Ļ��з� 
	
	string s;
	getline(cin, s);
	
	int len = s.length();
	int m = len % n;
	
	if(m == 0) m = n;
	//�� s �������ո�ʹ���ȸպ����� n
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
