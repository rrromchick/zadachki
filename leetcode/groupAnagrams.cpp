#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> ans;

        for (const auto& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            ans[key].push_back(s);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& itr : ans) {
            result.push_back(itr.second);
        }

        return result;
    }
};