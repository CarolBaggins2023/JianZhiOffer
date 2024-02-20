#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution_Spacial_O1 {

public:

	void InTraversal(TreeNode *root, std::vector<TreeNode*> &inorder) {
		if (root == nullptr) {
			return;
		}

		InTraversal(root->left, inorder);
		inorder.push_back(root);
		InTraversal(root->right, inorder);
	}

	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (pRootOfTree == nullptr) {
			return nullptr;
		}
		
		std::vector<TreeNode*> inorder;
		InTraversal(pRootOfTree, inorder);

		for (int i = 0; i < inorder.size() - 1; ++i) {
			inorder[i]->right = inorder[i + 1];
			inorder[i + 1]->left = inorder[i];
		}
		return inorder[0];
    }
};

class Solution {

public:

	Solution() : pre(nullptr), head(nullptr) {}

	void InorderTraversal(TreeNode *root) {
		if (root == nullptr) {
			return;
		}

		InorderTraversal(root->left);
		if (pre == nullptr) {
			head = root;
			pre = root;
		} else {
			pre->right = root;
			root->left = pre;
			pre = root;
		}
		InorderTraversal(root->right);
	}
	
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (pRootOfTree == nullptr) {
			return nullptr;
		}

		InorderTraversal(pRootOfTree);
		return head;
	}

	TreeNode *pre, *head;
};

int main(int argc, char* argv[])
{
	TreeNode a(1), b(2), c(3), d(4);
	a.left = &b; a.right = &c; b.right = &d;

	Solution sol;
	sol.Convert(&a);
    
    return 0;
}
