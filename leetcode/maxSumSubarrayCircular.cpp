#include <vector>
#include <climits>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int total_sum = 0, cur_sum1 = 0, cur_sum2 = 0, mxsum_subary = INT_MIN, minsum_subary = INT_MAX;

        for (auto i : nums) {
            total_sum += i; cur_sum1 += i; cur_sum2 += i;
            mxsum_subary = std::max(mxsum_subary, cur_sum1);
            if (cur_sum1 < 0) cur_sum1 = 0;
            minsum_subary = std::min(cur_sum2, minsum_subary);
            if (cur_sum2 > 0) cur_sum2 = 0;
        }
        return (total_sum == minsum_subary) ? mxsum_subary : std::max(mxsum_subary, total_sum - minsum_subary);
    }
};