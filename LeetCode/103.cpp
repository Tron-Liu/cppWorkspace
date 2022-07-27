#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>

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
  bool tag = false;  // 记录换行
  while (!qu.empty()) {
    sz = qu.size();

    for (int i = 0; i < sz; i++) {
      node = qu.front();
      qu.pop();
      temp.push_back(node->val);
      if (node->left != nullptr)
        qu.push(node->left);
      if (node->right != nullptr)
        qu.push(node->right);
    }
    if (tag) {
      tag = !tag;
    } else {
      reverse(temp.begin(), temp.end());
      tag = !tag;
    }
    res.push_back(temp);
    temp.clear();
  }
  return res;
}

int main() {

  set<int> vals;
  vals.insert(1);
  vals.insert(2);
  vals.insert(3);
  vals.insert(4);

  INT_MAX
  cout << vals.size();
  return 0;
}