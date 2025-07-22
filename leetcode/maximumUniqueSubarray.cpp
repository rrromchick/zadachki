#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> seen;
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;

        for (int right = 0; right < n; ++right) {
            while (seen.find(nums[right]) != seen.end()) {
                currentSum -= nums[left];
                seen.erase(nums[left]);
                ++left;
            }
            currentSum += nums[right];
            seen.insert(nums[right]);
            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;
    }
};