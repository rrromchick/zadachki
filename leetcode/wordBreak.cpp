#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<int> dp(s.length() + 1, 0);
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 1; j <= i; ++j) {
                if (std::find(wordDict.begin(), wordDict.end(), s.substr(j-1, i-j+1)) != wordDict.end()) {
                    dp[i] |= dp[j-1];
                }
            }
        }
        return dp[s.length()];
    }
};