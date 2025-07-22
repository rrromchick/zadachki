#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 0; i <= n; ++i) {
            if (i < n) {
                dp[i+1] += dp[i];
            }
            if (i < n - 1) {
                dp[i+2] += dp[i];
            }
        }

        return dp[n];
    }
};