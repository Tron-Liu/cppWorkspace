#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
bool solution(string& s, vector<string>& wordDict);

int main()
{
	string s = "applepenapple";
	vector<string> wordDict;
	wordDict.push_back("apple");
	wordDict.push_back("pen");
	
	cout << solution(s, wordDict);
	
	return 0;
}

bool solution(string& s, vector<string>& wordDict) {
	vector<bool> dp(s.length() + 1, false);
	dp[0] = true;
    for (int i = 1; i < s.length() + 1; i++) {
        for (int k = 0; k < i; k++) {
            bool tmp = false;
            cout << s.substr(k, i) << endl;
            if (find(wordDict.begin(), wordDict.end(), s.substr(k, i-k)) != wordDict.end()) {
                tmp = true;
            }
            dp[i] = dp[k] && tmp;
            if (dp[i]) break;
        }
    }
    for (int i = 0; i < s.length() + 1; i++)
    	cout << dp[i] << " ";
    cout << endl;
    return dp[s.length()];
}
