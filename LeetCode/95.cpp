// 不同的二叉搜索树 II
#include <iostream>
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

vector<TreeNode*> build(int lo, int hi) {
  vector<TreeNode*> res;

  if (lo > hi) {
    res.push_back(nullptr);
    return res;
  }

  // 穷举 root 所有的可能
  for (int mid = lo; mid <= hi; mid++) {
    // 2. 递归构造出左右子树的所有合法 BST
    vector<TreeNode*> left = build(lo, mid - 1);
    vector<TreeNode*> right = build(mid + 1, hi);

    // 3. 给 root 结点穷举所有左右子树的组合
    for(TreeNode* lf : left) {
        for (TreeNode* rt: right) {
            TreeNode* root = new TreeNode(mid);
            root->left = lf;
            root->right = rt;

            res.push_back(root);
        }
    }
  }
  return res;
}

vector<TreeNode*> generateTrees(int n) {
  vector<TreeNode*> res;
  if (n == 0) return res;

  return build(1, n);
}

int main() {
  vector<TreeNode*> res = generateTrees(1);
  for (TreeNode* node : res) {
    cout << node->val << " ";
  }
  return 0;
}