#include <functional>
#include <iostream>
#include <vector>

// 用LeetCode121代替
class Solution {
    
public:
    
    int maxProfit(std::vector<int>& prices) {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(-prices[i], dp[i - 1][1]);
        }
        return dp.back()[0];
    }

    // 补充LeetCode122
    int maxProfit2(std::vector<int>& prices) {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        return dp.back()[0];
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> prices{7,1,5,3,6,4};
    Solution sol;
    std::cout << sol.maxProfit(prices);
    
    return 0;
}
