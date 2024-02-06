// LeetCode 442, LCR 120
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::unordered_map<int, int> cnt;
        for (int num : nums) {
            if (cnt.find(num) == cnt.end()) {
                cnt.insert({num, 0});
            }
            ++cnt[num];
        }

        std::vector<int> res;
        for (std::pair<int, int> p : cnt) {
            if (p.second == 2) {
                res.emplace_back(p.first);
            }
        }

        return res;
    }

    int findRepeatDocument(std::vector<int>& documents) {
        std::unordered_set<int> exist;
        for (int id : documents) {
            if (exist.find(id) != exist.end()) {
                return id;
            }
            exist.insert(id);
        }
        return 0;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
