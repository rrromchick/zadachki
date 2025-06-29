#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        int n = (int)nums.size();
        std::unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
                return true;
            }
            mp[nums[i]] = i;
        }

        return false;
    }
};