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
	
	sort(p.begin(), p.end(), comparison);		//对结构体进行排序 
	
	vector<People>::iterator it;
	it = p.begin();
	
	for(it; it != p.end(); it++) {				//输出排序结果 
		cout << it->name << " " << it->birthday << " "
			 << it->tel << endl;
	}
	
	return 0;
}

bool comparison(People a, People b) {			//定义比较规则 
	return a.birthday < b.birthday;
}
