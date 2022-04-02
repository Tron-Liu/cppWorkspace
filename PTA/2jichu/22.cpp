#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<char> s;
	char c;
	cin.get(c);
	while(c != '\n') {
		s.insert(c);
		cin.get(c);
	}
	
	set<char>::iterator it;

	for(it = s.begin(); it != s.end(); it++) {
		c = *it;
		cout.put(c);
	}
	
	return 0;
}
