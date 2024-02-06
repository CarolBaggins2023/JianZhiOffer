#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
        auto cmp = [](std::string a, std::string b) -> bool {return a.size() < b.size();};
        std::sort(dictionary.begin(), dictionary.end(), cmp);

        std::vector<std::string> words;
        std::istringstream iss(sentence);
        std::string word;
        while (iss >> word) {
            words.emplace_back(word);
        }

        std::string res;
        for (std::string &word : words) {
            for (std::string root : dictionary) {
                if (word.find(root) == 0) {
                    word = root;
                    break;
                }
            }
            res.append(word);
            res.append(" ");
        }
        res.erase(res.size() - 1);
        
        return res;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::string> dictionary = {"catt","cat","bat","rat"};
    Solution sol;
    sol.replaceWords(dictionary, "the cattle was rattled by the battery");
    
    return 0;
}
