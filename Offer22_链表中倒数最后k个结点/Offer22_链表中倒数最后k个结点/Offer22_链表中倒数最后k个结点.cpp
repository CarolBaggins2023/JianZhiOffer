struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    
public:
    
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (pHead == nullptr || k == 0) {
            return nullptr;
        }
        
        ListNode *node1 = pHead, *node2 = pHead;
        for (int i = 0; i < k - 1; ++i) {
            if (node2->next == nullptr) {
                return nullptr;
            }
            node2 = node2->next;
        }

        while (node2->next != nullptr) {
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
