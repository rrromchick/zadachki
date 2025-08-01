#include <vector>
#include <algorithm>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), m = grid.back().size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 1) break;
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (grid[i][j] == 1) continue;
                dp[i][j] = std::max(dp[i-1][j], 0) + std::max(dp[i][j-1], 0);
            }
        }

        return dp[n-1][m-1]; 
    }
};