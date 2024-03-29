#include <iostream>
#include <string>
#include <vector>

class Solution {
    
public:
    
    bool hasPath(std::vector<std::vector<char> >& matrix, std::string word) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));
                visited[i][j] = true;
                if (ConstructPath(visited, i, j, 1, matrix, word)) {
                    return true;
                }
            }
        }
        return false;
    }

private:

    bool IsValidIdx(int idx, int bound) {
        return (idx >= 0 && idx < bound) ? true : false;
    }

    bool ConstructPath(std::vector<std::vector<bool>> &visited, int idx_i, int idx_j, int cnt,
                       const std::vector<std::vector<char>> &matrix, const std::string &target_word) {
        if (matrix[idx_i][idx_j] != target_word[cnt - 1]) {
            return false;
        }
        if (cnt == target_word.size()) {
            return true;
        }

        int n = matrix.size(), m = matrix[0].size();
        for (auto step : steps) {
            int next_idx_i = idx_i + step[0], next_idx_j = idx_j + step[1];
            if (!IsValidIdx(next_idx_i, n) || !IsValidIdx(next_idx_j, m) || visited[next_idx_i][next_idx_j]) {
                continue;
            }

            visited[next_idx_i][next_idx_j] = true;
            if (ConstructPath(visited, next_idx_i, next_idx_j, cnt+1, matrix, target_word)) {
                return true;
            }
            visited[next_idx_i][next_idx_j] = false;
        }
        return false;
    }

    std::vector<std::vector<int>> steps{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::vector<std::vector<char>> matrix{{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
    std::string word{"see"};
    std::cout << sol.hasPath(matrix, word);
    
    return 0;
}
