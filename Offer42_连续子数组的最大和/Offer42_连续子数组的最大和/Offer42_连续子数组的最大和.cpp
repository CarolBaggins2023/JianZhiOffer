#include <iostream>
#include <vector>

class Solution {
    
public:

    // 用LeetCode53.最大子数组和代替
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int max_dp = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            max_dp = std::max(max_dp, dp[i]);
        }
        return max_dp;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    std::cout << sol.maxSubArray(nums);
    
    return 0;
}
