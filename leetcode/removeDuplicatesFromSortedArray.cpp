#include <vector>
#include <unordered_map>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::unordered_map<int, int> cnt;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (cnt.count(nums[i])) continue;
            nums[(size_t)cnt.size()] = nums[i];
            ++cnt[nums[i]];
        }
        for (int i = cnt.size(); i < nums.size(); ++i) {
            nums[i] = 0;
        }
        return (int)cnt.size();
    }
};