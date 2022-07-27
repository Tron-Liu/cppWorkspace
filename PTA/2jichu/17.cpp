#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int a;
	multiset<int> mt; 
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++) {
			cin >> a;
			mt.insert(a);
		}
	}
	
	int max_count = 0;
	int max = 0;
	int c;
	
	multiset<int>::iterator it; 
	for(it = mt.begin(); it != mt.end(); it++) {
		c = mt.count(*it);
		if(c >= max_count) {		//set会从小到大排序，所以加等号 
			max_count = c;
			max = *it;
		}
	}
	
	cout << max << " " << max_count;
	return 0;
}
