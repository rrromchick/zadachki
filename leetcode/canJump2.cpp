#include <vector>
#include <climits>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int k = 1; k <= nums[i]; ++k) {
                if (i + k < n && dp[i+k] != INT_MAX) {
                    dp[i] = std::min(dp[i], dp[i+k] + 1);
                }
            }
        }

        return dp[0];
    }
};