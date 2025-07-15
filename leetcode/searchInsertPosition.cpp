#include <vector>
#include <algorithm>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        auto it = std::find(nums.begin(), nums.end(), target);
        if (it != nums.end()) return (it - nums.begin());
        auto lb = std::lower_bound(nums.begin(), nums.end(), target);
        if (lb == nums.end()) return nums.size();
        else return lb - nums.begin();
    }
};