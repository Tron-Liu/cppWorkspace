/**
 * @file test.cpp
 * @author Tron-Liu (Tron-Liu@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

int main()
{
  std::unordered_map<int, int> hash;
  hash[5] = 10;
  hash[1] = 3;
  hash[3] = 4;
  for (auto it = hash.begin(); it != hash.end(); it++) {
    std::cout << it->first << " " << it->second << std::endl;
  }

  return 0;
}
