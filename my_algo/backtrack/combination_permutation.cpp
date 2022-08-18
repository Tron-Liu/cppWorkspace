#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void combination(int start, vector<int> &nums, vector<int> &res);
void permutation(vector<int> &nums, vector<int> &res, int &max_len);

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums(a, a + 7);
    vector<int> res;
    cout << "combination: ";
    combination(0, nums, res);

    int max_len = 7;
	res.clear();
    cout << "permutation: " << endl;
    permutation(nums, res, max_len);
    return 0;
}

// 回溯算法解决组合问题
// 元素选择不相同

int res_len = 3;

// 输出组合
void combination(int start, vector<int> &nums, vector<int> &res) {
    if (res.size() == res_len) {
        for (int i = 0; i < res_len; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        res.empty();
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        // 做出选择
        res.push_back(nums[i]);
        combination(i + 1, nums, res);
        // 撤销选择
        res.pop_back();
    }
}

// 输出排列
void permutation(vector<int> &nums, vector<int> &res, int &max_len) {
    if (res.size() == max_len) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < max_len; i++) {
        if (find(res.begin(), res.end(), nums[i]) != res.end()) continue;
        // 做出选择
        res.push_back(nums[i]);
        permutation(nums, res, max_len);
        // 撤销选择
        res.pop_back();
    }
}