#include <iostream>
using namespace std;



int main()
{
	string a = "abcdefghij";	//�洢���� 
	string b = "SBQWSBQY";		//�洢��λ 
	
	string s;					//�������� 
	cin >> s;
	
	if(s[0] == '0')				//ֻ��һλ�� 
	{
		cout << 'a';
		return 0;
	}
	
	int l = s.length();
	int flag = 0;					//������ 
	
	for(int i = 0; i < l; i++)
	{
		if(s[i] == '0')				//������ 
		{
			flag = 1;				//��ʾ������ 
			
			if((l-i-2) == 7)
				cout << b[7];
				
			if((l-i-2) == 3)
				cout << b[3];
			continue; 
		}
		else
		{
			if(flag)				//����� 
				cout << a[0];
				 
			cout << a[s[i]-'0'];	//����������� 
			if((l-i-2) >= 0)		//��ֹ���� b ��� 
				cout << b[l-i-2];
			flag = 0;				//���� 
		}
	}
	return 0;
}
