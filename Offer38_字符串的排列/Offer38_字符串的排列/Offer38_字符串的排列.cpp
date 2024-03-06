#include <string>
#include <unordered_set>
#include <vector>

class Solution {
    
public:

    void PreorderTraversal(const std::string &str, std::string &res_str, std::vector<bool> &selected) {
        if (res_str.size() == str.size()) {
            res_set.insert(res_str);
            return;
        }

        for (int i = 0; i < selected.size(); ++i) {
            if (selected[i]) {
                continue;
            }
            res_str.push_back(str[i]);
            selected[i] = true;
            PreorderTraversal(str, res_str, selected);
            res_str.pop_back();
            selected[i] = false;
        }
    }
    
    std::vector<std::string> Permutation(std::string str) {
        std::vector<bool> selected(str.size(), false);
        std::string res_str;
        PreorderTraversal(str, res_str, selected);

        std::vector<std::string> res;
        for (std::string s : res_set) {
            res.push_back(s);
        }
        return res;
    }

    std::unordered_set<std::string> res_set = {};
};

int main(int argc, char* argv[])
{
    
    return 0;
}
