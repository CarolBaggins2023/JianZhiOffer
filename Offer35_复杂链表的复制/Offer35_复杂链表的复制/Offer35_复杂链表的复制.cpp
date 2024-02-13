#include <unordered_map>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
    
public:
    
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }
        
        RandomListNode *fake_head = new RandomListNode(-1);
        RandomListNode *pre = fake_head, *cur = pHead;
        std::unordered_map<RandomListNode*, RandomListNode*> old2new;

        while (cur != nullptr) {
            RandomListNode *new_node = new RandomListNode(cur->label);
            pre->next = new_node;
            old2new.insert({cur, new_node});
            cur = cur->next;
            pre = pre->next;
        }

        for (auto &p : old2new) {
            p.second->random = p.first->random == nullptr ? nullptr : old2new[p.first->random];
        }

        delete fake_head;
        return old2new[pHead];
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
