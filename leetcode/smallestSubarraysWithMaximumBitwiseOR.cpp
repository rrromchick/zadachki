#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> smallestSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> lastSeen(30, 0), res(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 30; ++bit) {
                if ((nums[i] & (1 << bit)) > 0) {
                    lastSeen[bit] = i;
                }
                res[i] = std::max(res[i], lastSeen[bit] - i + 1);
            }
        }
        return res;
    }
};