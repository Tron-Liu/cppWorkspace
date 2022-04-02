#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		printf("%c", s[i]);
		if(isdigit(s[i])) {
			if(ispunct(s[i+1])) {
				if(s[i+1] != '.')
					printf("\n"); 
			}
		}
		else if(s[i] == '-' || s[i] == '+') {
			if(i != 0 && s[i-1] != '(')
				printf("\n");
		}
		else if(s[i] == '.') continue;
		else printf("\n");
	}
	return 0;
} 
