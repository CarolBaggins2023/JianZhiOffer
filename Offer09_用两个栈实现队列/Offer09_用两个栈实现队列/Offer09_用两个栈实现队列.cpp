// LeetCode 232. 用栈实现队列

class MyQueue {
public:
    MyQueue() : in_stk(std::stack<int, std::deque<int>>{}), out_stk(std::stack<int, std::deque<int>>{}) {}
    
    void push(int x) {
        in_stk.push(x);
    }
    
    int pop() {
        AdaptStk();

        int ret = out_stk.top();
        out_stk.pop();
        return ret;
    }
    
    int peek() {
        AdaptStk();

        int ret = out_stk.top();
        return ret;
    }
    
    bool empty() {
        return in_stk.empty() && out_stk.empty();
    }

private:

    void AdaptStk() {
        if (out_stk.empty()) {
            while (!in_stk.empty()) {
                out_stk.push(in_stk.top());
                in_stk.pop();
            }
        }
    }

    std::stack<int, std::deque<int>> in_stk, out_stk;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
