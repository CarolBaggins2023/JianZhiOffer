#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
    
public:
    
    std::string ReverseSentence(std::string str) {
        std::vector<std::string> words;
        std::string::const_iterator it1 = str.begin(), it2 = str.begin();
        while ((it2 = std::find(it1, str.cend(), ' ')) != str.end()) {
            words.emplace_back(it1, it2);
            it1 = it2 + 1;
        }
        words.emplace_back(it1, str.cend());

        std::string res;
        std::for_each(words.rbegin(), words.rend(), [&res](const std::string &word) -> void {
            res.append(word).append(" ");
        });
        res.pop_back();

        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::string str = "nowcoder. a am I";
    std::cout << sol.ReverseSentence(str);
    
    return 0;
}
