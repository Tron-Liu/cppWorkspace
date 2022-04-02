#include <iostream>
using namespace std;



int main()
{
	string a = "abcdefghij";	//存储数字 
	string b = "SBQWSBQY";		//存储单位 
	
	string s;					//输入数字 
	cin >> s;
	
	if(s[0] == '0')				//只有一位零 
	{
		cout << 'a';
		return 0;
	}
	
	int l = s.length();
	int flag = 0;					//保存零 
	
	for(int i = 0; i < l; i++)
	{
		if(s[i] == '0')				//处理零 
		{
			flag = 1;				//表示出现零 
			
			if((l-i-2) == 7)
				cout << b[7];
				
			if((l-i-2) == 3)
				cout << b[3];
			continue; 
		}
		else
		{
			if(flag)				//输出零 
				cout << a[0];
				 
			cout << a[s[i]-'0'];	//输出非零数字 
			if((l-i-2) >= 0)		//防止数组 b 溢出 
				cout << b[l-i-2];
			flag = 0;				//重置 
		}
	}
	return 0;
}
