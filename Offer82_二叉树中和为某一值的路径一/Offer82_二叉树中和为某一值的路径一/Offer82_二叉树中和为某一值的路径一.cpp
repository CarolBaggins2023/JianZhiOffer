#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:

    bool PathSum(TreeNode *root, int cur_sum, int sum) {
        if (root->left == nullptr && root->right == nullptr) {
            cur_sum += root->val;
            return cur_sum == sum;
        }

        bool result = false;
        if (root->left != nullptr) {
            result = PathSum(root->left, cur_sum + root->val, sum);
        }
        if (!result && root->right != nullptr) {
            result = PathSum(root->right, cur_sum + root->val, sum);
        }
        return result;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        return PathSum(root, 0, sum);
    }
};

int main() {
    TreeNode a(1), b(2);
    a.left = &b;

    Solution sol;
    std::cout << sol.hasPathSum(&a, 0);
}