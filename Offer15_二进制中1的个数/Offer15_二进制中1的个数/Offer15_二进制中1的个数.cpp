#include <iostream>

class Solution {
    
public:
    
    int NumberOf1(int n) {
        int sum = 0;
        int cnt = 0;
        while ((cnt++) < 32)
        {
            sum += (n&1)|0;
            n >>= 1;
        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    int n = -1;
    std::cout << sol.NumberOf1(n);
    
    return 0;
}
