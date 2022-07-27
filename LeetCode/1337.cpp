#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
  vector<string> vec;
  

  return 0;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    priority_queue < pair<int, int>, vector<pair<int, int>>,
      greater<pair<int, int>>> heap;

    vector<int> ans;
    int first = INT_MAX;
    int second = INT_MAX;
    int third = INT_MAX;

    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) count++;
        }
        pair<int, int> tmp(count, i);
        heap.push(tmp);
    }

    for(int i = 0; i < k; i++) {
        int t = heap.top().first;
        ans.push_back(t);
        heap.pop();
    }
    return ans;
}