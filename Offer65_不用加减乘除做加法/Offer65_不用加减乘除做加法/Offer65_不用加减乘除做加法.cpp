class Solution {
    
public:
    
    int Add(int num1, int num2) {
        int sum = num1, add =num2;
        while (add != 0) {
            int sum_temp = sum, add_temp = add;
            sum = sum_temp^add_temp;
            add = (sum_temp&add_temp)<<1;
        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    sol.Add(1, 2);
    
    return 0;
}
