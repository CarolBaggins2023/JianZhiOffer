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

    std::vector<std::vector<int> > Print(TreeNode* pRoot) {
        std::vector<std::vector<int>> res;
        if (pRoot == nullptr) {
            return res;
        }

        std::queue<std::pair<TreeNode*, int>> que;
        que.emplace(pRoot, 0);
        std::vector<int> nodes;
        int cur_layer = 0;
        bool rev = false;
        while (!que.empty()) {
            std::pair<TreeNode*, int> node_layer = que.front();
            TreeNode *node = node_layer.first;
            int layer = node_layer.second;
            que.pop();

            if (cur_layer != layer) {
                if (rev) {
                    std::reverse(nodes.begin(), nodes.end());
                }
                res.push_back(nodes);
                nodes.clear();
                rev = !rev;
                cur_layer = layer;
            }
            nodes.push_back(node->val);

            if (node->left != nullptr) {
                que.emplace(node->left, layer + 1);
            }
            if (node->right != nullptr) {
                que.emplace(node->right, layer + 1);
            }
        }

        if (!nodes.empty()) {
            if (rev) {
                std::reverse(nodes.begin(), nodes.end());
            }
            res.push_back(nodes);
        }

        return res;
    }

    std::vector<std::vector<int> > Print_2(TreeNode* pRoot) {
        std::vector<std::vector<int>> res;
        if (pRoot == nullptr) {
            return res;
        }

        std::queue<TreeNode*> que;
        bool rev = false;
        que.push(pRoot);
        while (!que.empty()) {
            decltype(que.size()) que_size = que.size();
            std::vector<int> layer_res;
            while (que_size-- > 0) {
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

            if (rev) {
                std::reverse(layer_res.begin(), layer_res.end());
            }
            res.push_back(layer_res);
            rev = !rev;
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    TreeNode *a = new TreeNode(1), *b = new TreeNode(2), *c = new TreeNode(3), *d = new TreeNode(4), *e = new TreeNode(5);
    a->left = b; a->right = c; b->left = d; b->right = e;

    Solution sol;
    auto res = sol.Print_2(a);
    for (auto layer_res : res) {
        for (auto val : layer_res) {
            std::cout << val << " ";
        }
    }
    
    return 0;
}
