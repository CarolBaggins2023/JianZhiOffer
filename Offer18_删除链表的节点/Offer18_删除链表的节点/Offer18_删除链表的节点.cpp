struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    
public:

    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *cur = fake_head;
        while (cur->next != nullptr && cur->next->val != val) {
            cur = cur->next;
        }
        if (cur->next != nullptr) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }

        return fake_head->next;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
