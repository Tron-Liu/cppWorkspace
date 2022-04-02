#include <iostream>
using namespace std;

int main()
{
	int unhappy = 0;		//�������� 
	int sad = 0;			//������ 
	int happy = 0;			//�˷��� 
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
		
		if(s[i] == 'X')			//ʲô��û�� 
		{
			unhappy = 1;
			cout << 'U';
			if(happy) happy--;
		}
		else if(s[i] == 'T')	//�в���� 
		{
			sad = 2;
			money += 7;
			cout << 'D';
			if(happy) happy--;
		}
		else					//������ 
		{
			happy = 2;
			money -= 3;
			cout << '!';
		}
	}
	cout << endl << money;
	return 0;
} 
