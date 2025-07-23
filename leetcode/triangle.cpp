#include <vector>
#include <climits>
#include <queue>
#define piii std::pair<int, std::pair<int, int>>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int h = triangle.size(), w = triangle.back().size();
        std::vector<int> dp(w, 0);
        for (int i = 0; i < w; ++i) {
            dp[i] = triangle[h-1][i];
        }
        for (int i = h - 2; i >= 0; --i) {
            std::vector<int> temp(w, 0);
            for (int j = 0; j < triangle[i].size(); ++j) {
                temp[j] = std::min(dp[j], dp[j+1]) + triangle[i][j];
            }
            dp = temp;
        }
        return dp[0];
    }
};