#include <vector>

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i-1]) {
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n, 0));

        for (int t = 1; t <= k; ++t) {
            int maxDiff = -prices[0];
            for (int d = 1; d < n; ++d) {
                dp[t][d] = std::max(dp[t][d-1], prices[d] + maxDiff);
                maxDiff = std::max(maxDiff, dp[t-1][d] - prices[d]);
            }
        }

        return dp[k][n-1];
    }
};