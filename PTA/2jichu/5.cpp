#include <iostream>
using namespace std;

int main()
{
	int unhappy = 0;		//不高兴期 
	int sad = 0;			//伤心期 
	int happy = 0;			//兴奋期 
	int money = 0;
	
	string s;
	cin >> s;
	
	for(int i = 0; i < s.length() - 1; i++)
	{
		if(!happy && unhappy) 
		{
			unhappy--;
			cout << '-';
			continue;
		}
		
		if(!happy && sad)
		{
			sad--;
			cout << '-';
			continue;
		}
		
		if(s[i] == 'X')			//什么都没有 
		{
			unhappy = 1;
			cout << 'U';
			if(happy) happy--;
		}
		else if(s[i] == 'T')	//有捕鼠夹 
		{
			sad = 2;
			money += 7;
			cout << 'D';
			if(happy) happy--;
		}
		else					//有奶酪 
		{
			happy = 2;
			money -= 3;
			cout << '!';
		}
	}
	cout << endl << money;
	return 0;
} 
