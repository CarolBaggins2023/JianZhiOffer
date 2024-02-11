#include <regex>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution {
    
public:
    
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = 0, len2 = 0;
        ListNode *cnt_node = pHead1;
        while (cnt_node != nullptr) {
            ++len1;
            cnt_node = cnt_node->next;
        }
        cnt_node = pHead2;
        while (cnt_node != nullptr) {
            ++len2;
            cnt_node = cnt_node->next;
        }

        ListNode *node1 = pHead1, *node2 = pHead2;
        int dis = std::abs(len1 - len2);
        if (len1 > len2) {
            while (dis > 0) {
                node1 = node1->next;
                --dis;
            }
        } else {
            while (dis > 0) {
                node2 = node2->next;
                --dis;
            }
        }

        while (node1 != nullptr && node2 != nullptr) {
            if (node1 == node2) {
                return node1;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return nullptr;
    }
};


int main(int argc, char* argv[])
{
    
    return 0;
}
