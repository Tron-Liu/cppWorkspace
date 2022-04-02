#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s;
	getline(cin, s);
	string x;
	getline(cin, x);
	//string y;
	for (int j = 0; j < s.length(); j++) {		
		int i = 0;
		while(x[i] != s[j] && i<x.length()) {   //aeiou
			i++;
		}
		if (i==x.length()) {
			cout << s[j];
		}
	}
	return 0;
}
