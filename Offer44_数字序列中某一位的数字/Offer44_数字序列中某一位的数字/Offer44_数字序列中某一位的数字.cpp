#include <iostream>
#include <string>

class Solution {
    
public:
    
    int findNthDigit(int n) {
        // [begin, end)
        long long begin = 0, end = 10;
        int cnt = 1;
        while (n > (end - begin) * cnt) {
            n -= (end - begin) * cnt;
            begin = end;
            end = end * 10;
            ++cnt;
        }

        int div = n / cnt, mod = n % cnt;
        return std::to_string(begin + div)[mod] - '0';
    }
    
    int findNthDigit_OutofTimeLimit(int n) {
        int num = 0;
        std::string str_num;
        while (str_num.size() < n + 1) {
            std::cout << num << std::endl;
            str_num.append(std::to_string(num++));
        }
        return str_num[n] - '0';
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::cout << sol.findNthDigit(1000000000);
    
    return 0;
}
