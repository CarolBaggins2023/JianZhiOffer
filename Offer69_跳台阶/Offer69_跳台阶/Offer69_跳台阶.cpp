#include <vector>

class Solution {
    
public:
    
    int jumpFloor(int number) {
        std::vector<int> dp(number + 1, 1);
        dp[1] = 1;
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
