#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct People {
	string name;
	int birthday;
	string tel;
};

bool comparison(People a, People b);

int main()
{
	int n;
	cin >> n;
	
	People t;
	vector<People> p;	
	for(int i = 0; i < n; i++) {
		cin >> t.name >> t.birthday >> t.tel;
		p.push_back(t);
	}
	
	sort(p.begin(), p.end(), comparison);		//�Խṹ��������� 
	
	vector<People>::iterator it;
	it = p.begin();
	
	for(it; it != p.end(); it++) {				//��������� 
		cout << it->name << " " << it->birthday << " "
			 << it->tel << endl;
	}
	
	return 0;
}

bool comparison(People a, People b) {			//����ȽϹ��� 
	return a.birthday < b.birthday;
}
