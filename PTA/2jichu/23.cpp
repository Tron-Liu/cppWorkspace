#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	
	int len1 = s1.length();
	int len2 = s2.length();
	
	int pos = s1.find(s2);
	while(pos != -1) { 			//删除后，可能会重新组合出待删除字符子串 
		s1.replace(pos, len2, "");
		pos = s1.find(s2);
	} 
	cout << s1;		//输出结果字符串 
    return 0;
}
