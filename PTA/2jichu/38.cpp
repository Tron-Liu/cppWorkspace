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
	getchar();			//�����һ��ĩβ�Ļ��з� 
	
	Book b;
	vector<Book> v;
	
	for(int i = 0; i < n; i++) {
		getline(cin, b.name);
		//getchar();		//�����Ӧ��ĩβ�Ļ��з� 
		cin >> b.price;
		getchar(); 		//�����Ӧ��ĩβ�Ļ��з� 
		v.push_back(b);
	}
	
	sort(v.begin(), v.end(), comparison);
	
	vector<Book>::iterator it;
	
	it = v.begin();		//ָ���һ��Ԫ�� 
	cout << fixed << setprecision(2) << setfill('0') << it->price 
		 << ", " << it->name << endl;
	
	it = v.end();
	it--;				//ָ�����һ��Ԫ�� 
	cout << setprecision(2) << setfill('0') << it->price 
		 << ", " << it->name << endl;
	
	return 0;
}

bool comparison(Book a, Book b) {			//����ȽϹ��� 
	return a.price > b.price;
}
