class Solution {

public:

    int Sum_Solution(int n) {
        n && (n += Sum_Solution(n-1));
        return n;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
