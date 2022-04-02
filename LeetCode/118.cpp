#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector< vector<int> > generate(int numRows) {
			vector< vector<int> > res;

			vector<int> first(1, 1);
			res.push_back(first);
			
			vector<int> pre = first;
			for (int i = 2; i <= numRows; i++) {
		    	vector<int> temp(i);
		    	temp[0] = temp[i-1] = 1;
		    	for (int j = 1; j < i-1; j++) {
		    		temp[j] = pre[j] + pre[j-1];
				}
				res.push_back(temp);
				pre = temp;
			}
			return res;
		}
};

int main() {
	int numRows = 2;
	Solution so;
	vector< vector<int> > res = so.generate(numRows);
	vector< vector<int> >::iterator it1;
	vector<int>::iterator it2;
	
	for (it1 = res.begin(); it1 != res.end(); it1++) {
		for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}
	return 0;
}
