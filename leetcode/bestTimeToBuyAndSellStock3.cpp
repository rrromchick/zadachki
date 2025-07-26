#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(3, std::vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; --i) {
            for (int count = 1; count >= 0; --count) {
                dp[i][count][0] = std::max(-prices[i] + dp[i+1][count][1], dp[i+1][count][0]);
                dp[i][count][1] = std::max(prices[i] + dp[i+1][count+1][0], dp[i+1][count][1]);
            }
        }
        return dp[0][0][0];
    }
};