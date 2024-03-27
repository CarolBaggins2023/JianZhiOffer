#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
    
public:

    int lengthOfLongestSubstringRaw(std::string s) {
        std::vector<int> res(s.size(), 0);
        std::vector<std::unordered_set<char>> exist(s.size());
        int max_res = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (exist[i].find(s[j]) != exist[i].end()) {
                    break;
                }
                exist[i].insert(s[j]);
                ++res[i];
            }
            max_res = std::max(max_res, res[i]);
        }
        return max_res;
    }

    int lengthOfLongestSubstringTwoPointer(std::string s) {
        int res = 0;
        int ss_begin = 0, ss_end = 0;
        std::unordered_set<char> exist;
        for (ss_end = 0; ss_end < s.size(); ++ss_end) {
            while (exist.find(s[ss_end]) != exist.end()) {
                exist.erase(s[ss_begin]);
                ++ss_begin;
            }
            exist.insert(s[ss_end]);
            res = std::max(res, ss_end - ss_begin + 1);
        }
        return res;
    }

    int lengthOfLongestSubstringDP(std::string s) {
        std::vector<int> dp(s.size(), 0);
        std::unordered_map<char, int> exist;
        dp[0] = 1;
        exist.insert({s[0], 0});
        int res = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (exist.find(s[i]) == exist.end()) {
                dp[i] = dp[i-1] + 1;
                exist.insert({s[i], i});
            } else {
                int last_appear = exist[s[i]];
                dp[i] = std::min(dp[i-1] + 1, i - last_appear);
                exist[s[i]] = i;
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    std::string s{"pwwkew"};
    Solution sol;
    std::cout << sol.lengthOfLongestSubstringDP(s);
    
    return 0;
}
