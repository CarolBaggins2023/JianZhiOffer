#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class Solution {
    
public:
    
    int rectCover(int number) {
        if (number == 0 || number == 1 || number == 2) {
            return number;
        }

        // dp[i] = dp[i - 1] + dp[i - 2]
        std::vector<int> dp(number + 1, 0);
        int a = dp[1] = 1;
        int b = dp[2] = 2;
        std::cout << a << " " << b << " ";
        std::function<void(int&)> func = [&a, &b](int &i) {
            i = b + a;
            a = std::exchange(b, b + a);
            std::cout << i << " ";
        };
        std::for_each(dp.begin() + 3, dp.end(), func);
        return dp.back();
    }
};

int main(int argc, char* argv[])
{
    int number = 4;
    Solution sol;
    sol.rectCover(number);
    
    return 0;
}
