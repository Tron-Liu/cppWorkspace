/**
 * @file 235.cpp
 * @author Tron-Liu (Tron-Liu@foxmail.com)
 * @brief 二叉搜索树的最近公共祖先
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

int main()
{

    return 0;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr)
        return;

    stack<TreeNode*> st;

    TreeNode* node = root;
    TreeNode* pre = nullptr;

    while (node != nullptr || !st.empty()) {
        while (node != nullptr) {
            if (node->val == p->val || node->val == q->val)
                return node;

            st.push(node);
            node = node->left;
        }

        node = st.top();
        st.pop();

        if (node->right != nullptr && node->right != pre) {
            st.push(node);
            node = node->right;
        } else {
            pre = node;
            node = nullptr;
        }
    }
}