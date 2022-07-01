#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<vector<int>> res;
  if (root == nullptr)
    return res;

  queue<TreeNode*> qu;
  qu.push(root);

  int sz = 0;
  TreeNode* node = nullptr;
  vector<int> temp;
  bool tag = false;
  while (!qu.empty()) {
    sz = qu.size();
    node = qu.front();
    qu.pop();

    for (int i = 0; i < sz; i++) {
        temp.push_back();
        temp.re
    }
    temp.clear();

  }
}

int main() {
  return 0;
}