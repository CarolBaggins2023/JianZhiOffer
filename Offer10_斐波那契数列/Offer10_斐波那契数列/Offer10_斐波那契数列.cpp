#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class Solution {
    
public:
    
    int Fibonacci(int n) {
        std::vector<int> dp(n + 1, 1);
        for (int i = 3; i < dp.size(); ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        std::for_each(dp.begin() + 3, dp.end(), [](int i) {
            std::cout << i << " ";
        });
        return dp.back();
    }

    int FibonacciLambda(int n) {
        std::vector<int> dp(n + 1, 1);
        int a = 1, b = 1;
        std::for_each(dp.begin() + 3, dp.end(), [&a, &b](int &i) {
            i = a + b;
            a = std::exchange(b, a + b);
            std::cout << i << " ";
        });
        return dp.back();
    }

    int FibonacciFunction(int n) {
        std::vector<int> dp(n + 1, 1);
        auto func_lambda = [a = 1, b = 1] (int &i) mutable {
            i = a + b;
            a = std::exchange(b, a + b);
        };
        std::function<void(int&)> func = func_lambda;
        std::for_each(dp.begin()+3, dp.end(), func);
        return dp.back();
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    sol.Fibonacci(10);
    std::cout << std::endl;
    sol.FibonacciLambda(10);
    std::cout << std::endl;

    // lambda表达式实际上就是函数类对象，这里用它来研究内存对齐
    int a = 0, b = 0, c = 0;
    auto lambda1 = [a, b, c] () {}; // 12 = (a:4)+(b:4)+(c:4)，4字节对齐
    std::cout << sizeof(lambda1) << std::endl;
    auto lambda2 = [a, b, &c] () {}; // 16 = (a+b:4+4->8)+(c:8)，8字节对齐
    std::cout << sizeof(lambda2) << std::endl;
    auto lambda3 = [a, &b, c] () {}; // 24 = (a+对齐:4+4->8)+(b:8)+(c+对齐:4+4->8)，8字节对齐
    std::cout << sizeof(lambda3) << std::endl;
    
    return 0;
}
