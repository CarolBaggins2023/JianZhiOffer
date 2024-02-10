
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *new_head = head;
        while (head->next != nullptr) {
            ListNode *insert_node = head->next;
            head->next = insert_node->next;
            insert_node->next = new_head;
            new_head = insert_node;
        }
        return new_head;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
