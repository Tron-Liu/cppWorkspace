#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> num;
	int N;
	cin >> N;
	int i, t;
	for(i = 0; i < N; i++) {
		cin >> t;
		num.insert(t);
	}
	cin >> t;
	num.insert(t);
	multiset<int>::iterator it;
	for(it = num.begin(); it != num.end(); it++)
		cout << *it << " ";
	
	return 0;
}
