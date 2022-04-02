#include <iostream>
#include <algorithm>
#define SIZE 102
using namespace std;

int solution(string& s1, string& s2);
int solution1(string& s1, string& s2);

int main()
{
	string s1 = "people";
	string s2 = "eplm";
	
	cout << solution1(s1, s2);
	return 0; 
}

// 最长公共子串 
int solution(string& s1, string& s2) {
	int dp[SIZE][SIZE] = {0};
	int max_len = 0;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1.at(i-1) == s2.at(j-1)) {
				dp[i][j] = dp[i-1][j-1] + 1;
				max_len = max(max_len, dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
		}
	}
	return max_len;
}

// 最长公共子序列
int solution1(string& s1, string& s2) {
	int dp[SIZE][SIZE] = {0};
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1.at(i-1) == s2.at(j-1)) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[s1.length()][s2.length()];
}
