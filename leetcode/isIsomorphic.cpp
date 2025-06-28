#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int n = s.length();
        int m = t.length();
        std::unordered_map<char, std::vector<int>> mp, mp2;

        for (int i = 0; i < n; ++i) {
            mp[s[i]].push_back(i);
        }
        for (int i = 0; i < m; ++i) {
            mp2[t[i]].push_back(i);
        }

        std::vector<char> first, second;

        for (const auto& ch : s) {
            first.push_back(ch);
        }
        for (const auto& ch : t) {
            second.push_back(ch);
        }

        std::sort(first.begin(), first.end(), [&mp](const char& a, const char& b) {
            if (mp[a].size() == mp[b].size()) {
                return mp[a][0] < mp[b][0];
            }
            return mp[a].size() < mp[b].size();
        });
        std::sort(second.begin(), second.end(), [&mp2](const char& a, const char& b) {
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