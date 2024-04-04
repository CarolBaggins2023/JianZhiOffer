#include <iostream>
#include <queue>
#include <vector>

class Solution {
    
public:
    
    void Insert(int num) {
        left_heap.push(num);
        right_heap.push(left_heap.top());
        left_heap.pop();
        if (left_heap.size() < right_heap.size()) {
            left_heap.push(right_heap.top());
            right_heap.pop();
        }
    }

    double GetMedian() {
        if (left_heap.size() > right_heap.size()) {
            return left_heap.top();
        }
        return (left_heap.top()+right_heap.top())/2.0;
    }

private:

    std::priority_queue<int, std::vector<int>, std::less<>> left_heap;
    std::priority_queue<int, std::vector<int>, std::greater<>> right_heap;
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::vector<int> nums{5,2,3,4,1,6,7,0,8};
    for (int num : nums) {
        sol.Insert(num);
        std::cout << sol.GetMedian() << std::endl;
    }
    
    return 0;
}
