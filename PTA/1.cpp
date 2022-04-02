#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	map<int, int> couple;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		couple[x] = y;
		couple[y] = x;
	}
	
	int m, tmp;
	cin >> m;
	set<int> single;
	for(int i = 0; i < m; i++) {
		cin >> tmp;
		single.insert(tmp);
	}
	
	set<int> result;
	set<int>::iterator it;
	
	for(it = single.begin(); it != single.end(); it++) {
		if(couple.find(*it) != couple.end()) {
			if(single.find(couple.find(*it)->second) != single.end())
				continue;
			else result.insert(*it);
		}
		else {
			result.insert(*it);
		}
	}
	
	cout << result.size() << endl;
	int i = 0;
	for(it = result.begin(); it != result.end(); it++) {
		printf("%05d", *it);
		if(i < result.size()-1) printf(" ");
		i++;
	}
	return 0;
} 
