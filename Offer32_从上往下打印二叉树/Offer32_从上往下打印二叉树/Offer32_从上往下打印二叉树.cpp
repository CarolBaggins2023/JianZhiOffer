#include <queue>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
    
public:
    
    std::vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        std::vector<int> res;
        std::queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            res.push_back(node->val);

            if(node->left != nullptr) {
                que.push(node->left);
            }
            if (node->right != nullptr) {
                que.push(node->right);
            }
        }

        return res;
    }
};


int main(int argc, char* argv[])
{
    
    return 0;
}
