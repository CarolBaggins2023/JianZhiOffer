#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    
public:

    bool VerifySequenceOfBSTRecursion(std::vector<int> sequence) {
        if (sequence.empty()) {
            return true;
        }
        
        auto iter_first_right = std::find_if(sequence.begin(), sequence.end() - 1,
            [sequence](int num) -> bool { return num > sequence.back(); });

        auto iter_judge = std::find_if(iter_first_right, sequence.end() - 1,
                        [sequence](int num) -> bool { return num < sequence.back(); });
        if (iter_judge != sequence.end() - 1) {
            return false;
        }
        
        bool verify_left = VerifySequenceOfBSTRecursion(std::vector<int>(sequence.begin(), iter_first_right));
        bool verify_right = VerifySequenceOfBSTRecursion(std::vector<int>(iter_first_right, sequence.end() - 1));
        return verify_left && verify_right;
    }
    
    bool VerifySquenceOfBST(std::vector<int> sequence) {
        if (sequence.empty()) {
            return false;
        }
        return VerifySequenceOfBSTRecursion(sequence);
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> v{5, 4, 3, 2, 1};
    Solution sol;
    std::cout << sol.VerifySquenceOfBST(v);
    
    return 0;
}
