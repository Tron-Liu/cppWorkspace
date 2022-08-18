#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
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

void preorder(TreeNode* root);
void preorder_non_recur(TreeNode* root);
void inorder(TreeNode* root);
void inorder_non_recur(TreeNode* root);
void postorder(TreeNode* root);
void postorder(TreeNode* root);

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

    inorder(node1);

    return 0;
}

//递归前序遍历
void preorder(TreeNode* root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// 非递归前序遍历
void preorder_non_recur(TreeNode* root, string& ans)
{
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        cout << node->val << " ";

        if (node->right != nullptr) {
            st.push(node->left);
        }

        if (node->left != nullptr) {
            st.push(node->right);
        }
    }
}

void inorder(TreeNode* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 非递归中序遍历  (左、根、右)
void inorder_non_recur(TreeNode* root)
{
    if (root == nullptr)
        return;
    stack<TreeNode*> st;
    TreeNode* node = root;

    while (node != nullptr || !st.empty()) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }

        TreeNode* tmp = st.top();
        cout << tmp->val << " ";
        st.pop();

        node = tmp->right;
    }
}

void postorder(TreeNode* root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->val << " ";
}

// 非递归后序遍历 (左、根、右)
void postorder_non_recur(TreeNode* root)
{
    if (root == nullptr)
        return;

    stack<TreeNode*> st;
    TreeNode* node = root;
    TreeNode* pre = nullptr;
    while (node != nullptr || !st.empty()) {
        while (node != nullptr) {
            st.emplace(node);
            node = node->left;
        }

        node = st.top();
        st.pop();

        if (node->right == nullptr || node->right == pre) {
            cout << node->val << " ";
            pre = node;
            node = nullptr;
        } else {
            st.emplace(node);   //右子树不为空，再次入栈
            node = node->right;
        }
    }
}