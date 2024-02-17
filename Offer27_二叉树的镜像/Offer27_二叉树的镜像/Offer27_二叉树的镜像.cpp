#include <valarray>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:

    void PreorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        std::swap(root->left, root->right);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
    
    TreeNode* Mirror(TreeNode* pRoot) {
        PreorderTraversal(pRoot);
        return pRoot;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
