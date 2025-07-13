#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        backtrack(0, std::vector<int>{}, target, candidates, ans);
        return ans;
    }
private:
    void backtrack(int cur, std::vector<int> comb, int target, std::vector<int>& candidates, std::vector<std::vector<int>>& res)
    {
        if (cur == target) {
            std::sort(comb.begin(), comb.end());
            if (std::find(res.begin(), res.end(), comb) == res.end()) res.push_back(comb);
            return;
        }

        for (const auto& x : candidates) {
            if (cur + x <= target) {
                comb.push_back(x);
                backtrack(cur + x, comb, target, candidates, res);
                comb.pop_back();
            }
        }
    }
};