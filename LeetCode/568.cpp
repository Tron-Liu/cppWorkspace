#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& stones);
int main()
{
	vector<int> stones;
	stones.push_back(31);
	stones.push_back(26);
	stones.push_back(33);
	stones.push_back(21);
	stones.push_back(40);
	cout << solution(stones);
	return 0;
}

int solution(vector<int>& stones) {
	int sum = 0;
	int length = stones.size();
	for (int i = 0; i < length; i++)
		sum = sum + stones[i];
	int target = sum >> 1;
	
	// 前 i 件物品在背包容量为 j 时的最大价值 
	int dp[102][102] = {0};
	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= target; j++) {
			if (stones[i-1] <= j) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - stones[i-1]] + stones[i-1]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return sum - dp[length][target] - dp[length][target];
}
