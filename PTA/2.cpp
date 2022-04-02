#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int len = s.length();
	int maxl = 0;
	
	for(int i = 0; i < len; i++) {
		for(int j = 0; i-j >= 0 && i+j < len; j++) {
			if(s[i-j] != s[i+j]) break;
			if(2*j+1 > maxl) maxl = 2*j+1;
		}
		for(int j = 0; i-j >= 0 && i+j+1 < len; j++) {
			if(s[i-j] != s[i+j+1]) break;
			if(2*j+2 > maxl) maxl = 2*j+2;
		}
	}
	cout << maxl;
	return 0;
}
