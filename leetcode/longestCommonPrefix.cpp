#include <vector>
#include <string>
#include <climits>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int mn = INT_MAX;
        
        for (int i = 0; i < strs.size(); ++i) {
            mn = std::min(mn, (int)strs[i].length());
        }

        for (int i = 0; i < mn; ++i) {
            char c = ' ';
            for (int j = 0; j < strs.size(); ++j) {
                if (c == ' ') {
                    c = strs[j][i];
                    continue;
                } else if (strs[j][i] != c) {
                    return strs[j].substr(0, i);
                }
            }
        }
        return strs[0].substr(0, mn);
    }
};