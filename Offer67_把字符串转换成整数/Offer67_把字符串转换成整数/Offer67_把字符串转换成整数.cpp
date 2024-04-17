#include <string>

// LCR 192
class Solution {
    
public:
    
    int myAtoi(std::string str) {
        int i = 0;
        while (str[i] == ' ') {
            ++i;
        }

        int sym = 1;
        if (str[i] == '-') {
            sym = -1;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }

        int res = 0;
        while (isdigit(str[i])) {
            if (res > 0 && (res > INT32_MAX/10 || res*10 > INT32_MAX-(str[i]-'0'))) {
                return INT32_MAX;
            }
            if (res < 0 && (res < INT32_MIN/10 || res*10 < INT32_MIN+(str[i]-'0'))) {
                return INT_MIN;
            }
            res = res*10+sym*(str[i]-'0');
            ++i;
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    sol.myAtoi("42");
    
    return 0;
}
