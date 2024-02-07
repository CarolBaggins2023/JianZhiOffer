// LCR 123. 图书整理 I

class Solution {
public:
    vector<int> reverseBookList(ListNode* head) {
        std::deque<int> res_deque;
        while (head != nullptr) {
            res_deque.push_front(head->val);
            head = head->next;
        }

        std::vector<int> res(res_deque.begin(), res_deque.end());
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
