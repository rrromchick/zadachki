#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        for (const auto& it : nums) {
            ++mp[it];
        }
        int ans = 0;
        for (const auto& [x, y] : mp) {
            ans += std::max(x, 0);
        }
        if (ans == 0 && !mp.count(0)) {
            return *std::max_element(nums.begin(), nums.end());
        }
        return ans;
    }
};