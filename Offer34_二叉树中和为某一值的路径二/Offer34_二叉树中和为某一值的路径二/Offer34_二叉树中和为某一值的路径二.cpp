#include <vector>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:

    Solution() : res(std::vector<std::vector<int>>()) {}

    void PreTraversal(TreeNode *root, int target, int sum, std::vector<int> &path) {
        if (root->left == nullptr && root->right == nullptr && sum == target) {
            res.push_back(path);
            return;
        }

        
        if (root->left != nullptr) {
            path.push_back(root->left->val);
            PreTraversal(root->left, target, sum + root->left->val, path);
            path.pop_back();
        }
        if (root->right != nullptr) {
            path.push_back(root->right->val);
            PreTraversal(root->right, target, sum + root->right->val, path);
            path.pop_back();
        }
    }
    
    std::vector<std::vector<int>> FindPath(TreeNode* root, int target) {
        if (root == nullptr) {
            return res;
        }
        std::vector<int> path{root->val};
        PreTraversal(root, target, root->val, path);
        return res;
    }

    std::vector<std::vector<int>> res;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
