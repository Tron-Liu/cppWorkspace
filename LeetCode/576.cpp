#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string& s1, string& s2);

int main()
{
	string s1 = "1AB2345CD";
	string s2 = "12345EF";
	cout << solution(s1, s2);
	
	return 0;
}

string solution(string& s1, string& s2) {
	int len1 = s1.length();
	int len2 = s2.length();
	int max_len = 0;
	int index = 0;
	vector< vector<int> > dp(len1+2, vector<int>(len2+2, 0));
	int i, j;
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			if (s1.at(i-1) == s2.at(j-1)) {
				dp[i][j] = dp[i-1][j-1] + 1;
				max_len = max(dp[i][j], max_len);
				index = j;
			}
			else dp[i][j] = 0;
		}
	}
	cout << "index = " << index << endl;
	cout << "max_len = " << max_len << endl;
	return s2.substr(index-max_len, index-1);
}
