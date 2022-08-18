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

TreeNode* post_order(TreeNode* root);

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;

    post_order(node1);

    return 0;
}

TreeNode* post_order(TreeNode* root)
{
    if (root == nullptr)
        return;

    stack<TreeNode*> st;

    TreeNode* node = root;
    TreeNode* pre = nullptr;

    while (node != nullptr || !st.empty()) {
        while (node != nullptr) {
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
            if ()
            node = nullptr;
        }
    }
}