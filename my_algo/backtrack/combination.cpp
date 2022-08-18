/**
* @file: combination.cpp
* @author: Tron-Liu (Tron-Liu@foxmail.com)
* @brief: A backtrack demo program about combination 
* @date: 2022-08-09 22:20
**/

#include <iostream>
#include <vector>
#include <algorithm>

void backtrack(std::vector<std::vector<int>>& ans, const std::vector<int>& arr, std::vector<int>& tmp, int start, const int& num);

int main()
{
	std::vector<int> arr({0, 1, 2, 3});
	std::vector<std::vector<int>> ans;
	std::vector<int> tmp;
	int num = 2;
	int start = 1;

	backtrack(ans, arr, tmp, start, num);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[0].size(); j++) {
			std::cout << ans[i][j] << " ";
		}
		std::cout << std::endl;
	}
  return 0;
}

/*
 * num: 组合数的个数
*/
void backtrack(std::vector<std::vector<int>>& ans, const std::vector<int>& arr, std::vector<int>& tmp, int start, const int& num) {
	if (tmp.size() == num) {
		ans.push_back(tmp);
		return ;
	}

	for (int i = start; i < arr.size(); i++) {
//		if (std::find(tmp.begin(), tmp.end(), i) != tmp.end())
//			continue;
//		else
		tmp.push_back(i);

		backtrack(ans, arr, tmp, i + 1, num);
		
		tmp.pop_back();
	}
}
