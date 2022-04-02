#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int findTargetSumWays(vector<int>& nums, int target) {
			int count = nums.size();
			int sum = 0;
			for (int i = 0; i < count; i++)
				sum += nums[i];
			if ((sum < target) || ((sum + target) & 1) != 0) return 0;
			
			int capacity = (sum - target) >> 1;
			
			// dp[i][j]: 前 i 个数字在目标数是 j 时的 方案个数  
			vector< vector<int> > dp(count + 1, vector<int>(capacity + 1));
			dp[0][0] = 1; 
			for (int i = 1; i <= count; i++) {
				for (int j = 0; j <= capacity; j++) {
					if(j >= nums[i-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
					else dp[i][j] = dp[i-1][j];
				}
			}
			return dp[count][capacity];
		}
		
		int findTargetSumWays1 (vector<int>& nums, int target) {
			int count = nums.size();
			int sum = 0;
			for (int i = 0; i < count; i++)
				sum += nums[i];
			if ((sum < target) || ((sum + target) & 1) != 0) return 0;
			
			int capacity = (sum - target) >> 1;
			
			vector<int> dp(capacity + 1);
			dp[0] = 1;
			
			for (int i = 1; i <= count; i++) {
				for (int j = capacity; j >= 0; j--) {
					if (j >= nums[i-1]) dp[j] += dp[j - nums[i-1]];
				}
			}
			return dp[capacity];
		}
};

int main() {
	Solution so;
	int target = 3;
	vector<int> nums(5, 1);
	cout << so.findTargetSumWays(nums, target) << endl;
	cout << so.findTargetSumWays1(nums, target) << endl;
	return 0;
}
