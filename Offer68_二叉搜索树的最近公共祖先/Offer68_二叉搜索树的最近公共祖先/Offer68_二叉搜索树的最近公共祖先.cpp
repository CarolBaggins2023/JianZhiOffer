#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:

    void FindPath(TreeNode *node, std::vector<int> &path, int val) {
        while (node) {
            path.push_back(node->val);
            if (node->val == val) {
                return;
            }
            if (node->val > val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }
    
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        std::vector<int> path_p, path_q;
        FindPath(root, path_p, p);
        FindPath(root, path_q, q);
        int common_parent = 0;
        for (int i = 0, j = 0; i < path_p.size() && j < path_q.size(); ++i, ++j) {
            if (path_p[i] == path_q[j]) {
                common_parent = path_p[i];
            } else {
                break;
            }
        }
        return common_parent;
    }
};

class Solution_Once {
    
public:

    int FindCommonParent(TreeNode *node, int p, int q) {
        if (node == nullptr) {
            return 0;
        }

        if (node->val < p && node->val < q) {
            return FindCommonParent(node->right, p, q);
        } else if (node->val > p && node->val > q) {
            return FindCommonParent(node->left, p, q);
        } else {
            return node->val;
        }
    }
    
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        return FindCommonParent(root, p, q);
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
