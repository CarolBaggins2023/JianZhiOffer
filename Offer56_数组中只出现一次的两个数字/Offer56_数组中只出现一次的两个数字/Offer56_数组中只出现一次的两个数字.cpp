#include <vector>

class Solution {
    
public:
    
    std::vector<int> FindNumsAppearOnce(std::vector<int>& nums) {
        int all_xor = 0;
        for (int num : nums) {
            all_xor ^= num;
        }

        int div = 1;
        while ((all_xor&div) == 0) {
            div <<= 1;
        }

        int a = 0, b = 0;
        for (int num : nums) {
            if ((num&div) == 0) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        if (a < b) {
            return {a, b};
        } else {
            return {b, a};
        }
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::vector<int> nums{1, 4, 1, 6};
    sol.FindNumsAppearOnce(nums);
    
    return 0;
}
