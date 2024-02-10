#include <vector>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
public:
    std::vector<int> printListFromTailToHead(ListNode* head) {
        std::vector<int> res;
        ListNode *node = head;
        while (node != nullptr) {
            res.emplace_back(node->val);
            node = node->next;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char* argv[])
{
    
    
    return 0;
}
