#include <vector>

class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int maxOR = 0;
        for (const auto& num : nums) {
            maxOR |= num;
        }
        return backtrack(nums, maxOR, 0, 0);
    }
private:
    int backtrack(std::vector<int>& nums, int maxOR, int index, int currentOR) {
        if (index == nums.size()) {
            return currentOR == maxOR ? 1 : 0;
        }
        
        if (currentOR == maxOR) {
            return 1 << (nums.size() - index);
        }

        return backtrack(nums, maxOR, index + 1, currentOR | nums[index]) +
            backtrack(nums, maxOR, index + 1, currentOR);
    }
};