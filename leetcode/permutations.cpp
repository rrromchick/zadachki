#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if (nums.size() == 1) {
            std::vector<int> singleList;
            singleList.push_back(nums[0]);
            res.push_back(singleList);
            return res;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            std::vector<int> remainingNums;
            for (int j = 0; j < nums.size(); ++j) {
                if (j != i) {
                    remainingNums.push_back(nums[j]);
                }
            }

            std::vector<std::vector<int>> perms = permute(remainingNums);
            for (std::vector<int> p : perms) {
                p.insert(p.begin(), n);
                res.push_back(p);
            }
        }

        return res;
    }
};