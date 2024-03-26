#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class Solution {
    
public:
    
    int maxValue2Dimension(std::vector<std::vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> dp(grid);
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

    int maxValue(std::vector<std::vector<int> >& grid) {
        std::vector<int> dp(grid[0]);
        int pre = dp[0];
        std::function<void(int&)> func1 = [&pre](int &i) {
            i += pre;
            pre = i;
        };
        std::for_each(dp.begin() + 1, dp.end(), func1);

        int m = grid.size();
        std::vector<int> grid_row;
        int idx;
        std::function<void(int&)> func2 = [&grid_row, &idx, &pre](int &i) {
            if (idx == 0) {
                i += grid_row[idx++];
            } else {
                i = std::max(i, pre) + grid_row[idx++];
            }
            pre = i;
        };
        for(int i = 1; i < m; ++i) {
            grid_row = grid[i];
            idx = 0;
            pre = dp[0];
            std::for_each(dp.begin(), dp.end(), func2);
        }
        return dp.back();
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::vector<std::vector<int>> grid{{9, 1, 4, 8}};
    std::cout << sol.maxValue(grid);
    
    return 0;
}
