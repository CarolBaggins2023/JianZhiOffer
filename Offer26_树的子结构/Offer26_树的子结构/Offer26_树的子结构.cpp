#include <iostream>
#include <string>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
    
public:
    
    bool IsSame(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == nullptr) {
            return true;
        }
        if (pRoot1 == nullptr) {
            return false;
        }
        if (pRoot1->val != pRoot2->val) {
            return false;
        }
        return IsSame(pRoot1->left, pRoot2->left) && IsSame(pRoot1->right, pRoot2->right);
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }

        bool res = IsSame(pRoot1, pRoot2);
        if (!res) {
            res = HasSubtree(pRoot1->left, pRoot2);
        }
        if (!res) {
            res = HasSubtree(pRoot1->right, pRoot2);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
