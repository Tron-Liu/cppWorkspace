#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int mem[20][20] = {0};

inline int count(int left, int right) {
  if (left > right) return 1;

  if (mem[left][right] != 0) return mem[left][right];

  int res = 0;
  for (int mid = left; mid <= right; mid++) {
    int left_count = count(left, mid-1);
    int right_count = count(mid+1, right);

    res += left_count * right_count;
  }

  mem[left][right] = res;

  return res;
}

int main() {
  int n = 5;

  int res = count(1, n);
  cout << res << endl;
  return 0;
}