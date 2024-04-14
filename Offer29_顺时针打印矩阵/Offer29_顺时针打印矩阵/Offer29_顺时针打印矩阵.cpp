#include <iostream>
#include <vector>

class Solution {
    
public:
    
    std::vector<int> printMatrix(std::vector<std::vector<int> > matrix) {
        if (matrix.empty()) {
            return {};
        }
        
        std::vector<int> res;
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        while (top <= bottom && left <= right) {
            if (top <= bottom && left <= right) {
                for (int j = left; j <= right; ++j) {
                    res.push_back(matrix[top][j]);
                }
                ++top;
            }
            if (top <= bottom && left <= right) {
                for (int i = top; i <= bottom; ++i) {
                    res.push_back(matrix[i][right]);
                }
                --right;
            }
            if (top <= bottom && left <= right) {
                for (int j = right; j >= left; --j) {
                    res.push_back(matrix[bottom][j]);
                }
                --bottom;
            }
            if (top <= bottom && left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    // std::vector<std::vector<int> > matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int> > matrix{{1, 2, 3, 1}, {4, 5, 6, 1}, {4, 5, 6, 1}};
    std::vector<int> res = sol.printMatrix(matrix);
    for (int i : res) {
        std::cout << i << " ";
    }
    
    return 0;
}
