#include <iostream>
#include <vector>
using namespace std;

/*
* res: 二维数组，存储最终结果
* temp: 一维数组，存储中间结果
* nums: 给定的数组
* n: 数字个数 
*/

int selected[4] = {0};

void func(vector< vector<int> >& res, vector<int>& temp, vector<int>& nums) {
	// 结束条件
	if (temp.size() == nums.size()) {
		res.push_back(temp);
		return;
	}
	
	for (int i = 0; i < nums.size(); i++) {
		// 做出选择
		if (selected[i] == 0) {
			temp.push_back(nums[i]);
			selected[i] = 1;
		}
		else
			continue;
		// 递归调用
		func(res, temp, nums);
		// 撤销选择 
		temp.pop_back();
		selected[i] = 0;
	}
}

int main() {
	int a[] = {1, 2, 3, 4};
	int n = 4;
	int start = 0;
	vector<int> nums(a, a + 4);
	vector<int> temp;
	vector< vector<int> > res;
	
	func(res, temp, nums);
	
	vector< vector<int> >::iterator it1;
	vector<int>::iterator it2;
	for (it1 = res.begin(); it1 != res.end(); it1++) {
		for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}
}
