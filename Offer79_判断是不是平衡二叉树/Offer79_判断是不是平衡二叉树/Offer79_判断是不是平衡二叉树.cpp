#include <valarray>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:

    struct BalanceHeight {
        BalanceHeight(bool balance_, int height_) : balance(balance_), height(height_) {}
        bool balance;
        int height;
    };

    BalanceHeight IsBalance(TreeNode *root) {
        if (root == nullptr) {
            return {true, 0};
        }

        BalanceHeight left = IsBalance(root->left), right = IsBalance(root->right);
        int delta = std::abs(left.height - right.height);
        int height = std::max(left.height, right.height) + 1;
        return {delta <= 1 && left.balance && right.balance, height};
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        return IsBalance(pRoot).balance;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
