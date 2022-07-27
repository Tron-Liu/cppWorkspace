#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	char c;
	cin >> n >> c; 

	getchar();					//清除第一行换行符 
	
	string s;
	getline(cin, s);
	
	int len = s.length();		//输入字符串的长度 
	
	if(len <= n) {				//填充字符
		int d = n - len;
		while(d) {
			printf("%c", c);
			d--;
		}
		cout << s;
	}
	else {						//剪切字符串 
		int d = len - n;
		for(; d < len; d++) {
			cout << s[d];
		}
	}
	return 0;
 } 
