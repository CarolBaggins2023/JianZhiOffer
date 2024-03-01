#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:

    void FindNode(TreeNode *root, int o, std::vector<int> &path, bool &is_find) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);
        if (root->val == o) {
            is_find = true;
            return;
        }
        if (!is_find) {
            FindNode(root->left, o, path, is_find);
        }
        if (!is_find) {
            FindNode(root->right, o, path, is_find);
        }
        if (!is_find) {
            path.pop_back();
        }
    }

    // int FindCommonParent(const std::vector<int> &path1, const std::vector<int> &path2) {
    //     int i = 0, j = 0;
    //     if (path1.size() > path2.size()) {
    //         i += path1.size() - path2.size();
    //     } else {
    //         j += path2.size() - path1.size();
    //     }
    //     while (i < path1.size() && j < path2.size()) {
    //         if (path1[i] == path2[j]) {
    //             return path1[i];
    //         }
    //         ++i;
    //         ++j;
    //     }
    //     return 0;
    // }

    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        std::vector<int> path1, path2;
        bool is_find1 = false, is_find2 = false;
        FindNode(root, o1, path1, is_find1);
        FindNode(root, o2, path2, is_find2);

        // 不需要反向，直接从树的根节点开始比较即可
        // 和那道寻找两个链表连接点的题区分
        // std::reverse(path1.begin(), path1.end());
        // std::reverse(path2.begin(), path2.end());

        int res = 0;
        for(int i = 0; i < path1.size() && i < path2.size(); ++i) {
            if (path1[i] == path2[i]) {
                res = path1[i];
            } else {
                break;
            }
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
