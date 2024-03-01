#include <stack>
#include <vector>

class Solution {

public:

    bool IsPopOrder(std::vector<int>& pushV, std::vector<int>& popV) {
        std::stack<int, std::deque<int>> stk;
        int i = 0;
        for (int val : pushV) {
            stk.push(val);
            while (!stk.empty() && stk.top() == popV[i]) {
                stk.pop();
                ++i;
            }
        }

        return stk.empty();
    }

    bool IsPopOrderInPlace(std::vector<int>& pushV, std::vector<int>& popV) {
        int stack_top = 0, i = 0;
        for (int val : pushV) {
            pushV[stack_top] = val;
            while (stack_top >= 0 && pushV[stack_top] == popV[i]) {
                --stack_top;
                ++i;
            }
            ++stack_top;
        }

        return stack_top == 0;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> pushV{1}, popV{1};
    Solution sol;
    sol.IsPopOrder(pushV, popV);
    
    return 0;
}
