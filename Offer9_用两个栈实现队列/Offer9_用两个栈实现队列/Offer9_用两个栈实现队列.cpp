#include <stack>

class Solution{
    
public:
    
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int front = stack2.top();
        stack2.pop();
        return front;
    }

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
