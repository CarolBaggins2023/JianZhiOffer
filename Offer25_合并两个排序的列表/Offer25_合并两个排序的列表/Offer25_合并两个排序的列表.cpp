struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {

public:
    
    ListNode* Merge_WithOneList(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) {
            if (pHead1 != nullptr) {
                return pHead1;
            }
            if (pHead2 != nullptr) {
                return pHead2;
            }
            return nullptr;
        }
        
        ListNode *node1 = pHead1, *node2 = pHead2, *pre_node1 = nullptr, *new_head = pHead1;
        if (node1->val > node2->val) {
            new_head = new ListNode(node2->val);
            ListNode *in_node = new_head;
            node2 = node2->next;
            while (node2 != nullptr && node1->val > node2->val) {
                in_node->next = new ListNode(node2->val);
                in_node = in_node->next;
                node2 = node2->next;
            }
            in_node->next = node1;
        }
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val > node2->val) {
                ListNode *in_node = new ListNode(node2->val);
                in_node->next = node1;
                pre_node1->next = in_node;
                pre_node1 = in_node;
                node2 = node2->next;
            } else {
                pre_node1 = node1;
                node1 = node1->next;
            }
        }

        if (node1 == nullptr && node2 != nullptr) {
            pre_node1->next = node2;
        }
        return new_head;
    }

    ListNode* Merge_CreateNewList(ListNode* pHead1, ListNode* pHead2) {
        ListNode *fake_head = new ListNode(-1);
        ListNode *pre_node = fake_head, *node1 = pHead1, *node2 = pHead2;
        while (node1 != nullptr && node2 != nullptr) {
            bool node1_smaller = node1->val < node2->val ? true : false;
            pre_node->next = new ListNode(node1_smaller ? node1->val : node2->val);
            pre_node = pre_node->next;
            if (node1_smaller) {
                node1 = node1->next;
            } else {
                node2 = node2->next;
            }
        }
        
        ListNode *node = node1 != nullptr ? node1 : node2;
        while (node != nullptr) {
            pre_node->next = new ListNode(node->val);
            pre_node = pre_node->next;
            node = node->next;
        }

        return fake_head->next;
    }

    // the in-place method is preferred
    ListNode* Merge_InPlace(ListNode* pHead1, ListNode* pHead2) {
        ListNode *fake_head = new ListNode(-1);
        ListNode *pre = fake_head, *node1 = pHead1, *node2 = pHead2;
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val < node2->val) {
                pre->next = node1;
                node1 = node1->next;
            } else {
                pre->next = node2;
                node2 = node2->next;
            }
            pre = pre->next;
        }

        ListNode *node = node1 != nullptr ? node1 : node2;
        pre->next = node;

        return fake_head->next;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
