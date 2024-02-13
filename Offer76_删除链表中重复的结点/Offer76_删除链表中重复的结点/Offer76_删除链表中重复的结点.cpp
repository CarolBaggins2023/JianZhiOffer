#include <iostream>
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
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }

        ListNode *fake_head = new ListNode(-1);
        fake_head->next = pHead;
        ListNode *pre = fake_head, *cur = pHead;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            while (next != nullptr && cur->val == next->val) {
                    next = next->next;
            }
            
            if (next != cur->next) {
                if (next == nullptr) {
                    pre->next = next;
                    break;
                }
                pre->next = next;
                ListNode *tmp = cur;
                while (cur != next) {
                    cur = cur->next;
                    delete tmp;
                    tmp = cur;
                }
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        
        return fake_head->next;
    }

    ListNode* deleteDuplication_OneNode(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }

        ListNode *fake_head = new ListNode(-1);
        fake_head->next = pHead;
        ListNode *cur = fake_head;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            if (cur->next->val == cur->next->next->val) {
                int value = cur->next->val;
                while (cur->next != nullptr && cur->next->val == value) {
                    ListNode *tmp = cur->next;
                    cur->next = tmp->next;
                    delete tmp;
                }
            } else {
                cur = cur->next;
            }
        }

        return fake_head->next;
    }
};

ListNode* ConstructList(const std::vector<int> &v) {
    ListNode *head = new ListNode(v[0]), *pre = head;
    for (int i = 1; i < v.size(); ++i) {
        ListNode *node = new ListNode(v[i]);
        pre->next = node;
        pre = node;
    }
    return head;
}

void PrintList(ListNode *head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
}

int main(int argc, char* argv[])
{
    std::vector<int> v{1, 2, 3, 3, 4, 4, 5};
    Solution sol;
    ListNode *head = sol.deleteDuplication(ConstructList(v));
    PrintList(head);
    
    return 0;
}
