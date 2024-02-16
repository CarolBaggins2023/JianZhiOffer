#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:

    void TraversalInorder(TreeNode *root, std::vector<int> &inorder) {
        if (root == nullptr) {
            return;
        }

        TraversalInorder(root->left, inorder);
        inorder.push_back(root->val);
        TraversalInorder(root->right, inorder);
    }
    
    int KthNode(TreeNode* proot, int k) {
        std::vector<int> inorder;
        TraversalInorder(proot, inorder);

        if (inorder.size() == 0 || k == 0 || inorder.size() < k) {
            return -1;
        }
        return inorder[k - 1];
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
