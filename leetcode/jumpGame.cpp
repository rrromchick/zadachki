#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> dp(n);
        dp[n-1] = true;
        for (int i = n - 2; i >= 0; --i) {
            bool canJump = false;
            for (int k = 1; k <= nums[i]; ++k) {
                if (i + k < n && dp[i + k]) {
                    canJump = true;
                    break;
                }
            }
            dp[i] = canJump;
        }
        return dp[0];
    }
};