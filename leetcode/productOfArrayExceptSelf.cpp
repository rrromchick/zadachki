#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> pref(n, 1), suff(n, 1);
        
        for (int i = 0; i < n; ++i) {
            pref[i] = (i ? pref[i-1] : 1) * nums[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = (i < (n - 1) ? suff[i+1] : 1) * nums[i];
        }

        std::vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int x = 1;
            if (i > 0) x *= pref[i-1];
            if (i < n - 1) x *= suff[i+1];
            ans[i] = x;
        }

        return ans;
    }
};