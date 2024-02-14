#include <algorithm>

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
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return 0;
        }

        int depth_left = TreeDepth(pRoot->left), depth_right = TreeDepth(pRoot->right);
        return std::max(depth_left, depth_right) + 1;
    }
};


int main(int argc, char* argv[])
{
    
    return 0;
}
