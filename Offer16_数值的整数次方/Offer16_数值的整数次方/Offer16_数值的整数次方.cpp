class Solution {
    
public:
    
    double Power(double base, int exponent) {
        int cnt = exponent > 0 ? exponent : -exponent;
        double res = 1;
        while (cnt-- > 0) {
            res *= base;
        }
        return exponent > 0 ? res : 1/res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
