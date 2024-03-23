#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class Solution {
    
public:
    
    int jumpFloorII(int number) {
        std::vector<int> dp(number + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        int res = dp[0] + dp[1];
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = res;
            res += dp[i];
        }
        return dp.back();
    }

    int jumpFloorIILambda(int number) {
        std::vector<int> dp(number + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        int res = dp[0] + dp[1];
        std::function<void(int&)> func = [&res](int &i) { i = res; res += i; };
        std::for_each(dp.begin() + 2, dp.end(), func);
        return dp.back();
    }
};

int main(int argc, char* argv[])
{
    int number = 3;
    Solution sol;
    std::cout << sol.jumpFloorIILambda(number);
    
    return 0;
}
