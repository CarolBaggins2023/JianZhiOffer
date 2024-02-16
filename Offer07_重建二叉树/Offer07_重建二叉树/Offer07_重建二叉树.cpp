#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {

public:

    TreeNode* reConstructBinaryTree(std::vector<int>& preOrder, std::vector<int>& vinOrder) {
        if (preOrder.empty()) {
            return nullptr;
        }

        int root_val = preOrder.front();
        TreeNode *root = new TreeNode(root_val);
        
        std::vector<int>::iterator root_iter = std::find(vinOrder.begin(), vinOrder.end(), root_val);
        std::vector<int> vinOrder_left(vinOrder.begin(), root_iter), vinOrder_right(root_iter + 1, vinOrder.end());
        std::vector<int> preOrder_left(preOrder.begin() + 1, preOrder.begin() + 1 + vinOrder_left.size()), preOrder_right(preOrder.begin() + 1 + vinOrder_left.size(), preOrder.end());
        root->left = reConstructBinaryTree(preOrder_left, vinOrder_left);
        root->right = reConstructBinaryTree(preOrder_right, vinOrder_right);

        return root;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
