#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
    
public:
    
    bool IsContinuous(std::vector<int>& numbers) {
        std::sort(numbers.begin(), numbers.end());
        int cnt_zero = 0;
        for (int num : numbers) {
            if (num != 0) {
                break;
            }
            ++cnt_zero;
        }
        for (int i = cnt_zero+1; i < numbers.size(); ++i) {
            int delta = numbers[i]-numbers[i-1]-1;
            if (delta < 0) {
                return false;
            }
            cnt_zero -= numbers[i]-numbers[i-1]-1;
            if (cnt_zero < 0) {
                return false;
            }
        }
        return true;
    }
    
    bool IsContinuousSet(std::vector<int>& numbers) {
        std::unordered_set<int> s;
        int min = 14, max = 0;
        for (int num : numbers) {
            if (s.find(num) != s.end() && num != 0) {
                return false;
            }
            s.insert(num);
            if (num != 0) {
                min = std::min(min, num);
            }
            max = std::max(max, num);
        }
        return max-min < 5;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::vector<int> numbers{1, 2, 3, 4, 5};
    sol.IsContinuous(numbers);
    
    return 0;
}
