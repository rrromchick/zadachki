#include <vector>
#include <algorithm>
#define ll long long
const ll inf = 1e5+5;

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(m + 1, inf));
        dp[0][0] = 0;
        dp[1][1] = grid[0][0];
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= m; ++j) {
                dp[i][j] = std::min({dp[i][j], dp[i-1][j] + grid[i-1][j-1], dp[i][j-1] + grid[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};