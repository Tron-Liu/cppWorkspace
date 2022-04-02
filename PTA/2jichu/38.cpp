#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Book{
	string name;
	double price;
};

bool comparison(Book a, Book b);
int main()
{
	int n;
	cin >> n;
	getchar();			//清除第一行末尾的换行符 
	
	Book b;
	vector<Book> v;
	
	for(int i = 0; i < n; i++) {
		getline(cin, b.name);
		//getchar();		//清除对应行末尾的换行符 
		cin >> b.price;
		getchar(); 		//清除对应行末尾的换行符 
		v.push_back(b);
	}
	
	sort(v.begin(), v.end(), comparison);
	
	vector<Book>::iterator it;
	
	it = v.begin();		//指向第一个元素 
	cout << fixed << setprecision(2) << setfill('0') << it->price 
		 << ", " << it->name << endl;
	
	it = v.end();
	it--;				//指向最后一个元素 
	cout << setprecision(2) << setfill('0') << it->price 
		 << ", " << it->name << endl;
	
	return 0;
}

bool comparison(Book a, Book b) {			//定义比较规则 
	return a.price > b.price;
}
