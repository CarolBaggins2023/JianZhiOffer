#include <iostream>
#include <string>
#include <vector>

class Solution {
    
public:

    int solve(std::string nums) {
        if (nums.empty() || nums[0] == '0') {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        std::vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int combine = std::stoi(std::string(nums.begin(), nums.begin()+2));
        dp[1] = (nums[1] == '0' ? 0 : 1) + (combine <= 26 && combine > 0 ? 1 : 0);
        for (int i = 2; i < dp.size(); ++i) {
            combine = nums[i-1] == '0' ? 0 : std::stoi(std::string(nums.begin()+i-1, nums.begin()+i+1));
            dp[i] = (nums[i] == '0' ? 0 : dp[i-1]) + (combine <= 26 && combine > 0 ? dp[i-2] : 0);
        }
        return dp.back();
    }
};

int main(int argc, char* argv[])
{
    std::string nums{"72910721221427251718216239162221131917242"};
    Solution sol;
    std::cout << sol.solve(nums);
    
    return 0;
}
