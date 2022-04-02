#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        int mProfit = 0;
        int min_price = prices[0];
        for (int i = 0; i < len; i++) {
            int pro = prices[i] - min_price;
            if (mProfit < pro) mProfit = pro;
            if (prices[i] < min_price) min_price = prices[i];
        }
        return mProfit;
    }
};

int main()
{
    Solution so;
    int a[] = {7, 6, 4, 3, 1};
    vector<int> prices(a, a + 5);
    cout << so.maxProfit(prices);

    return 0;
}
