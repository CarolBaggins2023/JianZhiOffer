#include <deque>
#include <queue>

class Solution {
    
public:
    
    void push(int value) {
        nums_.push_back(value);
        if (nums_min_.empty() || value < nums_min_.back()) {
            nums_min_.push_back(value);
        } else {
            nums_min_.push_back(nums_min_.back());
        }
    }
    
    void pop() {
        nums_.pop_back();
        nums_min_.pop_back();
    }
    
    int top() {
        return nums_.back();
    }
    
    int min() {
        return nums_min_.back();
    }

private:

    std::deque<int> nums_ = {}, nums_min_ = {};
};

int main(int argc, char* argv[])
{
    
    return 0;
}
