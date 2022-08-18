#include <iostream>
#include <stack>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

void postorder(TreeNode* root);

int main()
{

	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);

	node1->left = node2; node1->right = node3;
	node2->left = node4; node2->right = node5;
	node3->right = node6;

	postorder(node1);

	return 0;
}

void postorder(TreeNode* root) {
	if (root == nullptr) return ;

	std::stack<TreeNode*> st; 
	TreeNode* node = root;
	TreeNode* pre = nullptr;

	while (!st.empty() || node != nullptr) {
		while(node != nullptr) {
			st.push(node);
			node = node->left;
		}

		node = st.top();
		st.pop();

		if (node->right != nullptr && pre != node->right) {
			st.push(node);
			node = node->right;
		}
		else {
			std::cout << node->val << " ";
			pre = node;
			node = nullptr;
		}
	}
}
