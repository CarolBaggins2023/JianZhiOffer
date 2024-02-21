#include <iostream>
#include <vector>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {

public:

    Solution() : nodes({}) {}

    void InorderTraversal(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }

        InorderTraversal(root->left);
        nodes.push_back(root);
        InorderTraversal(root->right);
    }
    
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode *root = pNode;
        while (root->next != nullptr) {
            root = root->next;
        }
        
        InorderTraversal(root);
        for (int i = 0; i < nodes.size() - 1; ++i) {
            if (nodes[i] == pNode) {
                return nodes[i + 1];
            }
        }
        return nullptr;
    }

    std::vector<TreeLinkNode*> nodes;
};


int main(int argc, char* argv[])
{
    
    return 0;
}
