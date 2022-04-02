#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	int sum = 0;
    	int length = nums.size();
    	for (int i = 0; i < length; i++)
    		sum += nums[i];
    	if (sum & 1 == 1) return false;
    	
    	int capacity = sum / 2;
    	
		vector<int> dp(capacity + 1);
    	for (int i = 1; i <= length; i++) {
    		for (int j = capacity; j >= 1; j--) {
    			if (j >= nums[i - 1]) {
					dp[j] = max(dp[j], dp[j - nums[i-1]] + nums[i-1]);
				}
			}
		}
		for (int i = 0; i <= capacity; i++)
			cout << dp[i] << " ";
		if (dp[capacity] == capacity) return true; 
		else return false;
    }
};

int main()
{
	int a[4] = {2, 2, 1, 1};
	vector<int> nums(a, a + 4);
	Solution so;
	cout << so.canPartition(nums) << endl;
	return 0;
}
