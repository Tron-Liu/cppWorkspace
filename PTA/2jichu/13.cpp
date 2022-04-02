#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, n;
	vector<int> v1, v2;

	cin >> n;		//第一行的第一个数字 
	for(int i = 0; i < n; i++) {	//第一行数据存入 v1
		cin >> a;
		if(find(v1.begin(), v1.end(), a) == v1.end())
			v1.push_back(a);
	}
	cin >> n;		//第二行的第一个数字
	for(int i = 0; i < n; i++) {	//第二行数据存入 v1 
		cin >> a;
		if(find(v2.begin(), v2.end(), a) == v2.end())
			v2.push_back(a);
	}
	
	int flag = 0;					//标记第一行数据是否有输出 
	vector<int>::iterator it1;
	for(it1 = v1.begin(); it1 != v1.end(); it1++) {
		if(find(v2.begin(), v2.end(), *it1) == v2.end()) {
			if(it1 == v1.begin()) cout << *it1;
			else cout << " " << *it1;
			flag = 1; 
		} 
	}
	
	vector<int>::iterator it2;
	for(it2 = v2.begin(); it2 != v2.end(); it2++) {
		if(find(v1.begin(), v1.end(), *it2) == v1.end()) {
			if(flag) cout << " " << *it2;
			else cout << *it2;
		} 
	}
	
	return 0; 
}
