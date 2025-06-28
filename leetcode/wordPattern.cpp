#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        int n = pattern.length();
        std::unordered_map<char, std::vector<int>> mp;
        std::unordered_map<std::string, std::vector<int>> mp2;

        for (int i = 0; i < n; ++i) {
            mp[pattern[i]].push_back(i);
        }
        
        std::stringstream keystream(s);
        std::vector<std::string> strs;
        std::string str;
        int m = 0;
        while (std::getline(keystream, str, ' ')) {
            mp2[str].push_back(m);
            strs.push_back(str);
            ++m;
        }

        std::vector<char> first;
        std::vector<std::string> second;

        for (const auto& ch : pattern) {
            first.push_back(ch);
        }
        for (const auto& ss : strs) {
            second.push_back(ss);
        }

        std::sort(first.begin(), first.end(), [&mp](const char& a, const char& b) {
            if (mp[a].size() == mp[b].size()) {
                return mp[a][0] < mp[b][0];
            }
            return mp[a].size() < mp[b].size();
        });
        std::sort(second.begin(), second.end(), [&mp2](const std::string& a, const std::string& b) {
            if (mp2[a].size() == mp2[b].size()) {
                return mp2[a][0] < mp2[b][0];
            }
            return mp2[a].size() < mp2[b].size();
        });

        if (first.size() != second.size()) return false;

        for (int i = 0; i < first.size(); ++i) {
            if (mp[first[i]] != mp2[second[i]]) {
                return false;
            }
        }

        return true;
    }
};