#include <vector>

class Solution {
public:
    
    int movingCount(int threshold, int rows, int cols) {
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        visited[0][0] = true;
        Moving(0, 0, visited, threshold, rows, cols);
        return cnt;
    }

private:

    bool IsValid(int idx_row, int idx_col, int threshold, int rows, int cols) {
        if (idx_row < 0 || idx_row >= rows || idx_col < 0 || idx_col >= cols) {
            return false;
        }

        int sum = 0;
        while (idx_row > 0) {
            sum += idx_row % 10;
            idx_row /= 10;
        }
        while (idx_col > 0) {
            sum += idx_col % 10;
            idx_col /= 10;
        }
        return sum <= threshold;
    }

    void Moving(int idx_row, int idx_col, std::vector<std::vector<bool>> &visited, int threshold, int rows, int cols) {
        for (auto step : dirs) {
            int next_idx_row = idx_row+step[0], next_idx_col = idx_col+step[1];
            if (!IsValid(next_idx_row, next_idx_col, threshold, rows, cols) || visited[next_idx_row][next_idx_col]) {
                continue;
            }

            ++cnt;
            visited[next_idx_row][next_idx_col] = true;
            Moving(next_idx_row, next_idx_col, visited, threshold, rows, cols);
        }
    }

    std::vector<std::vector<int>> dirs{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    int cnt = 1;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
