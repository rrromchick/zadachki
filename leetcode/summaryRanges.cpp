#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.size() == 0) return {};
        int n = nums.size();
        std::vector<std::string> res;

        int cur = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == (nums[i-1] + 1)) {
                continue;
            } else {
                if (cur != nums[i-1]) 
                    res.push_back(std::to_string(cur) + "->" + std::to_string(nums[i-1]));
                else 
                    res.push_back(std::to_string(cur));
                cur = nums[i];
            }
        }
        if (cur != nums[n-1]) {
            res.push_back(std::to_string(cur) + "->" + std::to_string(nums[n-1]));
        } else {
            res.push_back(std::to_string(cur));
        }
        return res;
    }
};