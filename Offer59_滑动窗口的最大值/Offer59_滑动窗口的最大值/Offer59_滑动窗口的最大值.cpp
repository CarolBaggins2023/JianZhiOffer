#include <iostream>
#include <queue>
#include <vector>

class Solution {
    
public:
    
    std::vector<int> maxInWindows(std::vector<int>& num, int size) {
        if (num.size() == 0 || size == 0 || num.size() < size) {
            return {};
        }
        
        std::vector<int> res;
        std::deque<int> que; // use deque to store index but not value
        for (int i = 0; i < num.size(); ++i) {
            while (!que.empty() && num[que.back()] < num[i]) {
                que.pop_back();
            }
            que.push_back(i);
            if (i - size + 1 > que.front()) {
                que.pop_front();
            }
            if (i >= size - 1) {
                res.push_back(num[que.front()]);
            }
        }
        
        return res;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> num{10, 14, 12, 11};
    int size = 1;

    Solution sol;
    std::vector<int> res = sol.maxInWindows(num, size);
    for (int i : res) {
        std::cout << i << " ";
    }
    
    return 0;
}
