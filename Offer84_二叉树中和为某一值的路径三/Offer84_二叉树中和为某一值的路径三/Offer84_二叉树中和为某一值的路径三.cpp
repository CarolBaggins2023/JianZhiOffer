#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:

    void CheckPathSum(const std::vector<int> &pre_sum) {
        for (int i = 0; i < pre_sum.size() - 1; ++i) {
            if (pre_sum.back() - pre_sum[i] == sum) {
                ++path_cnt;
            }
        }
    }

    void PreorderTraversal(TreeNode *root, std::vector<int> &pre_sum) {
        if (root == nullptr) {
            return;
        }
        
        pre_sum.push_back(pre_sum.back() + root->val);
        CheckPathSum(pre_sum);
        PreorderTraversal(root->left, pre_sum);
        PreorderTraversal(root->right, pre_sum);
        pre_sum.pop_back();
    }

    int FindPath(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }

        this->sum = sum;
        std::vector<int> pre_sum{0};
        PreorderTraversal(root, pre_sum);

        return path_cnt;
    }

    int path_cnt = 0; // assign before construction function
    int sum = 0;
};

int main(int argc, char* argv[])
{
    TreeNode a(0), b(1);
    a.left = &b;

    Solution sol;
    sol.FindPath(&a, 1);
    
    return 0;
}
