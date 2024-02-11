#include <vector>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop_Native(ListNode* pHead) {
        std::vector<ListNode*> nodes;
        ListNode *cur = pHead;
        while (cur != nullptr) {
            for (ListNode *node : nodes) {
                if (cur == node) {
                    return cur;
                }
            }
            nodes.emplace_back(cur);
            cur = cur->next;
        }

        return nullptr;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *fast_ptr = pHead, *slow_ptr = pHead, *meet_ptr = nullptr;
        while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if (slow_ptr == fast_ptr) {
                meet_ptr = fast_ptr;
                break;
            }
        }

        if (meet_ptr == nullptr) {
            return nullptr;
        }

        ListNode *node1 = pHead, *node2 = meet_ptr;
        while (node1 != node2) {
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
