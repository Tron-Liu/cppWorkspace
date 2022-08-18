/**
* @file: permutation.cpp
* @author: Tron-Liu (Tron-Liu@foxmail.com)
* @brief: A backtrack demo program about permutation
* @date: 2022-08-09 17:01
**/

#include <iostream>
#include <vector>
#include <algorithm>

void backtrack(std::vector<int>& nums, std::vector<int>& tmp);

int main()
{
	std::vector<int> nums({ 1, 2, 3, 4 });
	std::vector<int> tmp;
	int start = 0;

	backtrack(nums, tmp);
	
  return 0;
}

void backtrack(std::vector<int>& nums, std::vector<int>& tmp) {
	int sz = nums.size();

	if (tmp.size() == sz) {
		for(int num : tmp) std::cout << num << " ";
		std::cout << std::endl;

		return ;
	}
	
	for (int i = 0; i < sz; i++) {
		if (find(tmp.begin(), tmp.end(), nums[i]) != tmp.end())
			continue;
		tmp.push_back(nums[i]);

		backtrack(nums, tmp); 
		tmp.pop_back();
	}
}
