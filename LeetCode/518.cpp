#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	int n = coins.size();
    	//dp[i][j] : 前 i 个硬币在金额为 j 时的方案数
        int dp[301][5001] = {0};
        //base case
        for (int i = 0; i <= n; i++) {
        	dp[i][0] = 1;
		}
        
        for (int i = 1; i <= n; i++) {
        	for (int j = 1; j <= amount; j++) {
        		if (j - coins[i-1] >= 0)
        			dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
			}
		}
		return dp[n][amount];
    }
};

int main()
{
	
} 
