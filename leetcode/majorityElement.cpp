#include <vector>
#include <unordered_map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> cnt;
        for (int i = 0; i < (int)nums.size(); ++i) {
            ++cnt[nums[i]];
            if (cnt[nums[i]] > nums.size() / 2) {
                return nums[i];
            }
        }
        return 0;
    }
};