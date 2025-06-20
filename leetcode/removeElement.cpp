#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int cur = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == val) continue;
            nums[cur] = nums[i];
            ++cur;
        }
        for (int i = cur; i < (int)nums.size(); ++i) {
            nums[i] = 0;
        }
        return cur;
    }
};