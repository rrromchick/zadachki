#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int ans = 1, cur = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == (nums[i-1] + 1)) {
                ++cur;
            } else if (nums[i] == nums[i-1]) {
                continue;
            } else {
                ans = std::max(ans, cur);
                cur = 1;
            }
        }
        ans = std::max(ans, cur);

        return ans;
    }
};