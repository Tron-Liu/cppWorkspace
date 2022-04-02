#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool solution(string& s, set<string>& strs);

int main()
{
	string s = "leetcode";
	set<string> strs;
	strs.insert("leet");
	strs.insert("code");
	
	cout << solution(s, strs);
	return 0;
}

bool solution(string& s, set<string>& strs) {
	vector<bool> dp(s.length()+1);
	dp[0] = true;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j < i; j++) {
			bool tmp = false;
			if (strs.find(s.substr(j, i)) != strs.end())
				tmp = true;
			dp[i] = dp[j] && tmp;
			if (dp[i]) break; 
		}
	}
	for(int i = 0; i <= s.length(); i++)
		cout << dp[i] << " ";
	cout << endl;
	return dp[s.length()];
}
