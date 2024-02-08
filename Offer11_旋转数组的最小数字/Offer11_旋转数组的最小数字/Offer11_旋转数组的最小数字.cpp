#include <iostream>
#include <vector>

class Solution {
public:
    // LeetCode LCR 128
    int stockManagement(std::vector<int>& stock) {
        if (stock.front() < stock.back()) {
            return stock.front();
        }
        
        int l = 0, r = stock.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (stock[mid] < stock[r]) {
                r = mid;
            } else if (stock[mid] > stock[r]) {
                l = mid + 1;
            } else {
                --r;
            }
        }
        return stock[l];
    }

    // LeetCode 153
    int findMin_153(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // 可以进行优化，先判断单调递增序列
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }

    // LeetCode 154
    int findMin(std::vector<int>& nums) {
        if (nums.front() < nums.back()) {
            return nums.front();
        }
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                --r;
            }
        }
        return nums[l];
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::vector<int> nums{3,3,1,3};
    std::cout << sol.findMin(nums);
    
    return 0;
}
