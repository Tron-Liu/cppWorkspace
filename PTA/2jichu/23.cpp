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
	while(pos != -1) { 			//ɾ���󣬿��ܻ�������ϳ���ɾ���ַ��Ӵ� 
		s1.replace(pos, len2, "");
		pos = s1.find(s2);
	} 
	cout << s1;		//�������ַ��� 
    return 0;
}
