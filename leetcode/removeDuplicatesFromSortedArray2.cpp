#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int cnt = 0, ind = 0, cur = -1;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != cur) {
                cur = nums[i];
                cnt = 1;
                nums[ind] = nums[i];
                ++ind;
                continue;
            } else if (cnt >= 2) continue;
            ++cnt;
            nums[ind] = nums[i];
            ++ind;
        }
        for (int i = ind; i < (int)nums.size(); ++i) {
            nums[i] = 0;
        }
        return ind;
    }
};