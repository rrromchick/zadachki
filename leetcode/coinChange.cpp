#include <vector>
#include <climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (const auto& coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = std::min(dp[i], dp[i-coin] + 1);
            }
        }
        return (dp[amount] == INT_MAX - 1 ? -1 : dp[amount]);
    }
};