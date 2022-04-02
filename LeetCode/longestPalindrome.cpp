#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() < 2) return s;
        int begin = 0;
        int maxLen = 1;

        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

        // 边界条件
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
        }

        for (int L = 2; L <= s.length(); L++) {
            for (int i = 0; i < s.length(); i++) {
                int j = i + L -1;
                if (j >= s.length()) break;

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                }

                if(dp[i][j] && L > maxLen) {
                    maxLen = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

int main()
{
    Solution solution;
    string s = "cbbd";
    cout << solution.longestPalindrome(s);
    return 0;
}