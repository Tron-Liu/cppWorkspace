#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int> dp(nums.size() + 1, 1);
       int maxLen = 1;
       for (int i = 1; i <= nums.size(); i++) {
           for (int j = 1; j < i; j++) {
               if (nums[i-1] > nums[j-1]) {
                   dp[i] = max(dp[i], dp[j] + 1);
                   maxLen = max(maxLen, dp[i]);
               }
           }
       }
       for (int i = 1; i <= nums.size(); i++) {
           cout << dp[i] << " ";
       }
       cout << endl;
       return maxLen;
    }
};

int main()
{
    Solution solution;
    int a[] = {7, 7, 7, 7, 7, 7};
    vector<int> nums(a, a+6);

    cout << solution.lengthOfLIS(nums);

    return 0;
}