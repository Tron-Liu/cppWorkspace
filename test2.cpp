#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();

        int offset = 0;
        bool tag = true;

        for ( ; ;offset++) {
            for (int i = 1; i < sz; i++) {
                if (offset >= min(strs[i].length(), strs[i-1].length()) && strs[i][offset] != strs[i-1][offset]) {
                    tag = false;
                    break;
                }
                
            }
            if ( !tag ) break;
        }

        return strs[0].substr(0, offset-1);
    }
};

int main() {
	Solution so;
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");
	
	cout << so.longestCommonPrefix(strs);
	
	return 0;
}
