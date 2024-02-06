// LeetCode LCR 121
#include <vector>

class Solution {
public:
    bool findTargetIn2DPlants(std::vector<std::vector<int>>& plants, int target) {
        if (plants.empty() || plants[0].empty()) {
            return false;
        }
        
        int i = plants.size() - 1, j = 0;
        while (i >= 0 && j < plants[0].size()) {
            if (plants[i][j] == target) {
                return true;
            }
            if (plants[i][j] < target) {
                ++j;
            } else {
                --i;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
