#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        std::vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); ++i) {
            dp[i] = (i - 2 >= 0 ? dp[i-2] : 0) + nums[i-1];
            dp[i] = std::max(dp[i], dp[i-1]);
        }
        int ans = 0;
        for (const auto& it : dp) {
            ans = std::max(ans, it);
        }
        return ans;
    }
};