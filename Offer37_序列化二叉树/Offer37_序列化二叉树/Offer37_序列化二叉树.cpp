#include <cctype>
#include <queue>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution_HierarchicalTraversal {
    
public:
    
    char* Serialize(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        // pay attention to numbers > 9, which needs to be stored by more than one char
        std::string series;
        std::queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int layer_size = que.size();
            bool last_layer = true;
            while (layer_size--) {
                TreeNode *node = que.front();
                que.pop();

                if (node != nullptr) {
                    series += std::to_string(node->val);
                    series += "!";
                    que.push(node->left);
                    que.push(node->right);
                    last_layer = last_layer && !node->left && !node->right;
                } else {
                    series += "#!";
                    que.push(nullptr);
                    que.push(nullptr);
                }
            }

            if (last_layer) {
                break;
            }
        }

        char *res = new char[series.size() + 1];
        strcpy_s(res, series.size() + 1, series.c_str());
        res[series.size()] = '\0';
        return res;
    }
    
    TreeNode* Deserialize(char *str) {
        if (str == nullptr) {
            return nullptr;
        }
        
        std::vector<char> series;
        int idx = 0;
        while (str[idx] != '\0') {
            series.push_back(str[idx++]);
        }

        std::vector<TreeNode*> nodes;
        for (int i = 0; i < series.size(); ++i) {
            if (series[i] == '#') {
                nodes.push_back(nullptr);
                ++i; // skip '!'
                continue;
            }
            
            int val = 0;
            while (series[i] != '!') {
                val = val * 10 + (series[i++] - '0');
            }
            nodes.push_back(new TreeNode(val));
        }

        for (int i = 0; i < nodes.size(); ++i) {
            if (!nodes[i]) {
                continue;
            }
            if (2 * i + 1 < nodes.size()) {
                nodes[i]->left = nodes[2 * i + 1];
                if (2 * i + 2 < nodes.size()) {
                    nodes[i]->right = nodes[2 * i + 2];
                }
            }
        }

        return nodes[0];
    }
};

class Solution {

public:

    void SerializeFunc(TreeNode *root, std::string &serires) {
        if (root == nullptr) {
            serires += "#!";
            return;
        }

        serires += std::to_string(root->val) + "!";
        SerializeFunc(root->left, serires);
        SerializeFunc(root->right, serires);
    }

    char* Serialize(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        std::string series;
        SerializeFunc(root, series);

        char *res = new char[series.size() + 1];
        strcpy_s(res, series.size() + 1, series.c_str());
        res[series.size()] = '\0';
        return res;
    }

    TreeNode* DeserializeFunc(char **series_begin) {
        if (**series_begin == '#') {
            ++(++(*series_begin));
            return nullptr;
        }

        int val = 0;
        while (**series_begin != '!') {
            val = val * 10 + (**series_begin - '0');
            ++(*series_begin);
        }
        TreeNode *root = new TreeNode(val);

        ++(*series_begin);
        if (**series_begin == '\0') {
            return root;
        }
        
        root->left = DeserializeFunc(series_begin);
        root->right = DeserializeFunc(series_begin);
        return root;
    }

    TreeNode* Deserialize(char *str) {
        if (str == nullptr) {
            return nullptr;
        }

        return DeserializeFunc(&str);
    }
};

int main(int argc, char* argv[])
{
    TreeNode a(1), b(2), c(3), d(6), e(7), f(8);
    a.left = &b; a.right = &c;
    c.left = &d; c.right = &e;
    e.left = &f;

    TreeNode A(100), B(50), C(150);
    A.left = &B;
    B.right = &C;

    Solution sol;
    sol.Serialize(sol.Deserialize(sol.Serialize(&A)));
    
    return 0;
}
