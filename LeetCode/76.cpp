/**
 * @file 76.cpp
 * @author Tron-Liu (Tron-Liu@foxmail.com)
 * @brief LeetCode 第76题 最小覆盖串
 * @version 0.1
 * @date 2022-08-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> need;
    std::unordered_map<char, int> window;

    // 初始化 need
    for (char c : t) {
      need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;

    int start = 0, len = INT_MAX;
    while (right < s.length()) {
      char c = s[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) valid++;
      }

      while (valid == need.size()) {
        if (right - left < len) {
          len   = right - left;
          start = left;
        }

        char d = s[left];
        left++;

        if (need.count(d)) {
          if (window[d] == need[d]) valid--;
          window[d]--;
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
}

int main() {
  return 0;
}