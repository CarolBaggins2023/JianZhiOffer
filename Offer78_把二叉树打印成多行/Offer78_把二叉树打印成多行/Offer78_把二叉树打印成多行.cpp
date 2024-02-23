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
    
    std::vector<std::vector<int>> Print(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return {};
        }
        
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> res;
        que.push(pRoot);
        while (!que.empty()) {
            int layer_size = que.size();
            std::vector<int> layer_res;
            while (layer_size--) {
                TreeNode *node = que.front();
                que.pop();

                layer_res.push_back(node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            res.push_back(layer_res);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
