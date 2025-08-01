#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m + n != l) return false;

        if (m < n) return isInterleave(s2, s1, s3);

        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= n; ++j) {
            dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
        }

        for (int i = 1; i <= m; ++i) {
            dp[0] = dp[0] && s1[i-1] == s3[i-1];
            for (int j = 1; j <= n; ++j) {
                dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return dp[n];
    }
};