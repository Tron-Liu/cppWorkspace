#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	char c;
	cin >> n >> c; 

	getchar();					//�����һ�л��з� 
	
	string s;
	getline(cin, s);
	
	int len = s.length();		//�����ַ����ĳ��� 
	
	if(len <= n) {				//����ַ�
		int d = n - len;
		while(d) {
			printf("%c", c);
			d--;
		}
		cout << s;
	}
	else {						//�����ַ��� 
		int d = len - n;
		for(; d < len; d++) {
			cout << s[d];
		}
	}
	return 0;
 } 
