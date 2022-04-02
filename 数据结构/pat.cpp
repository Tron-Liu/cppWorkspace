#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string s = "asdafj";
	cout << s.find('s')<<endl;
	int i = s.find('s');
	s.erase(i, 1);
	cout << s << endl;
	string s1 = "%20";
	s.insert(i, s1);
	cout << s << endl;
	system("pause");
	return 0;
}