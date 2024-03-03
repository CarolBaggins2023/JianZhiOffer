#include <iostream>
#include <vector>

class Solution {
    
public:

    int BinarySearchBegin(const std::vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        if (nums[l] != k) {
            return -1;
        }
        
        return l;
    }

    int BinarySearchEnd(const std::vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (nums[m] <= k) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        if (nums[l] != k) {
            return -1;
        }

        return l;
    }
    
    int GetNumberOfK(std::vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        
        int begin = BinarySearchBegin(nums, k);
        if (begin == -1) {
            return 0;
        }
        
        int end = BinarySearchEnd(nums, k);
        return end - begin + 1;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums{3, 3, 3, 3};
    int k = 3;
    
    Solution sol;
    sol.GetNumberOfK(nums, k);
    
    return 0;
}
