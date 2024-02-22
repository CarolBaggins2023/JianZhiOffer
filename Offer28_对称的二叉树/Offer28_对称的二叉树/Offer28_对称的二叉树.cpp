#include <bitset>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
    
public:

    bool PreorderTraversal (TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            return false;
        }
        return PreorderTraversal(root1->left, root2->right) && PreorderTraversal(root1->right, root2->left);
    }
    
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return true;
        }
        return PreorderTraversal(pRoot->left, pRoot->right);
    }
};

int main(int argc, char* argv[])
{
    TreeNode a(1), b(2), c(2);
    a.left = &b; a.right = &c;
    Solution sol;
    std::cout << sol.isSymmetrical(&a);
    
    return 0;
}
