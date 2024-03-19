#include <vector>

class Solution {
    
public:
    
    std::vector<int> FindGreatestSumOfSubArray(std::vector<int>& array) {
        std::vector<int> dp(array.size(), 0), dp_size(array.size(), 0);
        dp[0] = array[0];
        dp_size[0] = 1;
        int max_idx = 0;
        for (int i = 1; i < array.size(); ++i) {
            int sum = dp[i-1] + array[i];
            if (sum < array[i]) {
                dp[i] = array[i];
                dp_size[i] = 1;
            } else if (sum >= array[i]) {
                dp[i] = sum;
                dp_size[i] = dp_size[i-1] + 1;
            }

            if (dp[i] > dp[max_idx] || dp[i] == dp[max_idx] && dp_size[i] > dp_size[max_idx]) {
                max_idx = i;
            }
        }

        
        return {array.begin() + max_idx - dp_size[max_idx] + 1, array.begin() + max_idx + 1};
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
