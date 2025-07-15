#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int res = nums[0];
        int total = 0;

        for (int n : nums) {
            if (total < 0) {
                total = 0;
            }

            total += n;
            res = std::max(res, total);
        }

        return res;
    }
};